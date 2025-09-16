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
** This file is generated from dx12_call_id_to_string_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_CALL_ID_TO_STRING_H
#define  GFXRECON_GENERATED_DX12_CALL_ID_TO_STRING_H


#include "format/api_call_id.h"
#include <string>


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

inline std::wstring GetDx12CallIdString(format::ApiCallId call_id)
{
    std::wstring out = L"Unknown_ApiCallId";
    switch (call_id)
    {
    case format::ApiCallId::ApiCall_D3D12SerializeRootSignature:
        out = L"D3D12SerializeRootSignature";
        break;
    case format::ApiCallId::ApiCall_D3D12CreateRootSignatureDeserializer:
        out = L"D3D12CreateRootSignatureDeserializer";
        break;
    case format::ApiCallId::ApiCall_D3D12SerializeVersionedRootSignature:
        out = L"D3D12SerializeVersionedRootSignature";
        break;
    case format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializer:
        out = L"D3D12CreateVersionedRootSignatureDeserializer";
        break;
    case format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary:
        out = L"D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary";
        break;
    case format::ApiCallId::ApiCall_D3D12CreateDevice:
        out = L"D3D12CreateDevice";
        break;
    case format::ApiCallId::ApiCall_D3D12GetDebugInterface:
        out = L"D3D12GetDebugInterface";
        break;
    case format::ApiCallId::ApiCall_D3D12EnableExperimentalFeatures:
        out = L"D3D12EnableExperimentalFeatures";
        break;
    case format::ApiCallId::ApiCall_D3D12GetInterface:
        out = L"D3D12GetInterface";
        break;
    case format::ApiCallId::ApiCall_ID3D12Object_GetPrivateData:
        out = L"ID3D12Object_GetPrivateData";
        break;
    case format::ApiCallId::ApiCall_ID3D12Object_SetPrivateData:
        out = L"ID3D12Object_SetPrivateData";
        break;
    case format::ApiCallId::ApiCall_ID3D12Object_SetPrivateDataInterface:
        out = L"ID3D12Object_SetPrivateDataInterface";
        break;
    case format::ApiCallId::ApiCall_ID3D12Object_SetName:
        out = L"ID3D12Object_SetName";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceChild_GetDevice:
        out = L"ID3D12DeviceChild_GetDevice";
        break;
    case format::ApiCallId::ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc:
        out = L"ID3D12RootSignatureDeserializer_GetRootSignatureDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion:
        out = L"ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion";
        break;
    case format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc:
        out = L"ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12Heap_GetDesc:
        out = L"ID3D12Heap_GetDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_Map:
        out = L"ID3D12Resource_Map";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_Unmap:
        out = L"ID3D12Resource_Unmap";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_GetDesc:
        out = L"ID3D12Resource_GetDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress:
        out = L"ID3D12Resource_GetGPUVirtualAddress";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_WriteToSubresource:
        out = L"ID3D12Resource_WriteToSubresource";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_ReadFromSubresource:
        out = L"ID3D12Resource_ReadFromSubresource";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_GetHeapProperties:
        out = L"ID3D12Resource_GetHeapProperties";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandAllocator_Reset:
        out = L"ID3D12CommandAllocator_Reset";
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence_GetCompletedValue:
        out = L"ID3D12Fence_GetCompletedValue";
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion:
        out = L"ID3D12Fence_SetEventOnCompletion";
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence_Signal:
        out = L"ID3D12Fence_Signal";
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence1_GetCreationFlags:
        out = L"ID3D12Fence1_GetCreationFlags";
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineState_GetCachedBlob:
        out = L"ID3D12PipelineState_GetCachedBlob";
        break;
    case format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetDesc:
        out = L"ID3D12DescriptorHeap_GetDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart:
        out = L"ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart";
        break;
    case format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart:
        out = L"ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandList_GetType:
        out = L"ID3D12CommandList_GetType";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close:
        out = L"ID3D12GraphicsCommandList_Close";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset:
        out = L"ID3D12GraphicsCommandList_Reset";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearState:
        out = L"ID3D12GraphicsCommandList_ClearState";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced:
        out = L"ID3D12GraphicsCommandList_DrawInstanced";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced:
        out = L"ID3D12GraphicsCommandList_DrawIndexedInstanced";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch:
        out = L"ID3D12GraphicsCommandList_Dispatch";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion:
        out = L"ID3D12GraphicsCommandList_CopyBufferRegion";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion:
        out = L"ID3D12GraphicsCommandList_CopyTextureRegion";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyResource:
        out = L"ID3D12GraphicsCommandList_CopyResource";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTiles:
        out = L"ID3D12GraphicsCommandList_CopyTiles";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveSubresource:
        out = L"ID3D12GraphicsCommandList_ResolveSubresource";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology:
        out = L"ID3D12GraphicsCommandList_IASetPrimitiveTopology";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetViewports:
        out = L"ID3D12GraphicsCommandList_RSSetViewports";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects:
        out = L"ID3D12GraphicsCommandList_RSSetScissorRects";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor:
        out = L"ID3D12GraphicsCommandList_OMSetBlendFactor";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef:
        out = L"ID3D12GraphicsCommandList_OMSetStencilRef";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPipelineState:
        out = L"ID3D12GraphicsCommandList_SetPipelineState";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier:
        out = L"ID3D12GraphicsCommandList_ResourceBarrier";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle:
        out = L"ID3D12GraphicsCommandList_ExecuteBundle";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps:
        out = L"ID3D12GraphicsCommandList_SetDescriptorHeaps";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature:
        out = L"ID3D12GraphicsCommandList_SetComputeRootSignature";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature:
        out = L"ID3D12GraphicsCommandList_SetGraphicsRootSignature";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable:
        out = L"ID3D12GraphicsCommandList_SetComputeRootDescriptorTable";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable:
        out = L"ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant:
        out = L"ID3D12GraphicsCommandList_SetComputeRoot32BitConstant";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant:
        out = L"ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants:
        out = L"ID3D12GraphicsCommandList_SetComputeRoot32BitConstants";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants:
        out = L"ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView:
        out = L"ID3D12GraphicsCommandList_SetComputeRootConstantBufferView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView:
        out = L"ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView:
        out = L"ID3D12GraphicsCommandList_SetComputeRootShaderResourceView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView:
        out = L"ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView:
        out = L"ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView:
        out = L"ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer:
        out = L"ID3D12GraphicsCommandList_IASetIndexBuffer";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers:
        out = L"ID3D12GraphicsCommandList_IASetVertexBuffers";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SOSetTargets:
        out = L"ID3D12GraphicsCommandList_SOSetTargets";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets:
        out = L"ID3D12GraphicsCommandList_OMSetRenderTargets";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView:
        out = L"ID3D12GraphicsCommandList_ClearDepthStencilView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView:
        out = L"ID3D12GraphicsCommandList_ClearRenderTargetView";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint:
        out = L"ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat:
        out = L"ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DiscardResource:
        out = L"ID3D12GraphicsCommandList_DiscardResource";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginQuery:
        out = L"ID3D12GraphicsCommandList_BeginQuery";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndQuery:
        out = L"ID3D12GraphicsCommandList_EndQuery";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveQueryData:
        out = L"ID3D12GraphicsCommandList_ResolveQueryData";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPredication:
        out = L"ID3D12GraphicsCommandList_SetPredication";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetMarker:
        out = L"ID3D12GraphicsCommandList_SetMarker";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginEvent:
        out = L"ID3D12GraphicsCommandList_BeginEvent";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndEvent:
        out = L"ID3D12GraphicsCommandList_EndEvent";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect:
        out = L"ID3D12GraphicsCommandList_ExecuteIndirect";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT:
        out = L"ID3D12GraphicsCommandList1_AtomicCopyBufferUINT";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64:
        out = L"ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds:
        out = L"ID3D12GraphicsCommandList1_OMSetDepthBounds";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions:
        out = L"ID3D12GraphicsCommandList1_SetSamplePositions";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion:
        out = L"ID3D12GraphicsCommandList1_ResolveSubresourceRegion";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask:
        out = L"ID3D12GraphicsCommandList1_SetViewInstanceMask";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate:
        out = L"ID3D12GraphicsCommandList2_WriteBufferImmediate";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_UpdateTileMappings:
        out = L"ID3D12CommandQueue_UpdateTileMappings";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_CopyTileMappings:
        out = L"ID3D12CommandQueue_CopyTileMappings";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists:
        out = L"ID3D12CommandQueue_ExecuteCommandLists";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_SetMarker:
        out = L"ID3D12CommandQueue_SetMarker";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_BeginEvent:
        out = L"ID3D12CommandQueue_BeginEvent";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_EndEvent:
        out = L"ID3D12CommandQueue_EndEvent";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal:
        out = L"ID3D12CommandQueue_Signal";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_Wait:
        out = L"ID3D12CommandQueue_Wait";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_GetTimestampFrequency:
        out = L"ID3D12CommandQueue_GetTimestampFrequency";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_GetClockCalibration:
        out = L"ID3D12CommandQueue_GetClockCalibration";
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_GetDesc:
        out = L"ID3D12CommandQueue_GetDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetNodeCount:
        out = L"ID3D12Device_GetNodeCount";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue:
        out = L"ID3D12Device_CreateCommandQueue";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandAllocator:
        out = L"ID3D12Device_CreateCommandAllocator";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState:
        out = L"ID3D12Device_CreateGraphicsPipelineState";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState:
        out = L"ID3D12Device_CreateComputePipelineState";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandList:
        out = L"ID3D12Device_CreateCommandList";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CheckFeatureSupport:
        out = L"ID3D12Device_CheckFeatureSupport";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateDescriptorHeap:
        out = L"ID3D12Device_CreateDescriptorHeap";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize:
        out = L"ID3D12Device_GetDescriptorHandleIncrementSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateRootSignature:
        out = L"ID3D12Device_CreateRootSignature";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateConstantBufferView:
        out = L"ID3D12Device_CreateConstantBufferView";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateShaderResourceView:
        out = L"ID3D12Device_CreateShaderResourceView";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateUnorderedAccessView:
        out = L"ID3D12Device_CreateUnorderedAccessView";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateRenderTargetView:
        out = L"ID3D12Device_CreateRenderTargetView";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateDepthStencilView:
        out = L"ID3D12Device_CreateDepthStencilView";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateSampler:
        out = L"ID3D12Device_CreateSampler";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptors:
        out = L"ID3D12Device_CopyDescriptors";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptorsSimple:
        out = L"ID3D12Device_CopyDescriptorsSimple";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetResourceAllocationInfo:
        out = L"ID3D12Device_GetResourceAllocationInfo";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetCustomHeapProperties:
        out = L"ID3D12Device_GetCustomHeapProperties";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommittedResource:
        out = L"ID3D12Device_CreateCommittedResource";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateHeap:
        out = L"ID3D12Device_CreateHeap";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreatePlacedResource:
        out = L"ID3D12Device_CreatePlacedResource";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateReservedResource:
        out = L"ID3D12Device_CreateReservedResource";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle:
        out = L"ID3D12Device_CreateSharedHandle";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle:
        out = L"ID3D12Device_OpenSharedHandle";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName:
        out = L"ID3D12Device_OpenSharedHandleByName";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_MakeResident:
        out = L"ID3D12Device_MakeResident";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_Evict:
        out = L"ID3D12Device_Evict";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateFence:
        out = L"ID3D12Device_CreateFence";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetDeviceRemovedReason:
        out = L"ID3D12Device_GetDeviceRemovedReason";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetCopyableFootprints:
        out = L"ID3D12Device_GetCopyableFootprints";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateQueryHeap:
        out = L"ID3D12Device_CreateQueryHeap";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_SetStablePowerState:
        out = L"ID3D12Device_SetStablePowerState";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandSignature:
        out = L"ID3D12Device_CreateCommandSignature";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetResourceTiling:
        out = L"ID3D12Device_GetResourceTiling";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetAdapterLuid:
        out = L"ID3D12Device_GetAdapterLuid";
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline:
        out = L"ID3D12PipelineLibrary_StorePipeline";
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline:
        out = L"ID3D12PipelineLibrary_LoadGraphicsPipeline";
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline:
        out = L"ID3D12PipelineLibrary_LoadComputePipeline";
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_GetSerializedSize:
        out = L"ID3D12PipelineLibrary_GetSerializedSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_Serialize:
        out = L"ID3D12PipelineLibrary_Serialize";
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary1_LoadPipeline:
        out = L"ID3D12PipelineLibrary1_LoadPipeline";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device1_CreatePipelineLibrary:
        out = L"ID3D12Device1_CreatePipelineLibrary";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion:
        out = L"ID3D12Device1_SetEventOnMultipleFenceCompletion";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device1_SetResidencyPriority:
        out = L"ID3D12Device1_SetResidencyPriority";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device2_CreatePipelineState:
        out = L"ID3D12Device2_CreatePipelineState";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress:
        out = L"ID3D12Device3_OpenExistingHeapFromAddress";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping:
        out = L"ID3D12Device3_OpenExistingHeapFromFileMapping";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device3_EnqueueMakeResident:
        out = L"ID3D12Device3_EnqueueMakeResident";
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetStatusFence:
        out = L"ID3D12ProtectedSession_GetStatusFence";
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetSessionStatus:
        out = L"ID3D12ProtectedSession_GetSessionStatus";
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession_GetDesc:
        out = L"ID3D12ProtectedResourceSession_GetDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateCommandList1:
        out = L"ID3D12Device4_CreateCommandList1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateProtectedResourceSession:
        out = L"ID3D12Device4_CreateProtectedResourceSession";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateCommittedResource1:
        out = L"ID3D12Device4_CreateCommittedResource1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateHeap1:
        out = L"ID3D12Device4_CreateHeap1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateReservedResource1:
        out = L"ID3D12Device4_CreateReservedResource1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_GetResourceAllocationInfo1:
        out = L"ID3D12Device4_GetResourceAllocationInfo1";
        break;
    case format::ApiCallId::ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated:
        out = L"ID3D12LifetimeOwner_LifetimeStateUpdated";
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetLUID:
        out = L"ID3D12SwapChainAssistant_GetLUID";
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject:
        out = L"ID3D12SwapChainAssistant_GetSwapChainObject";
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue:
        out = L"ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue";
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync:
        out = L"ID3D12SwapChainAssistant_InsertImplicitSync";
        break;
    case format::ApiCallId::ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject:
        out = L"ID3D12LifetimeTracker_DestroyOwnedObject";
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier:
        out = L"ID3D12StateObjectProperties_GetShaderIdentifier";
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderStackSize:
        out = L"ID3D12StateObjectProperties_GetShaderStackSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize:
        out = L"ID3D12StateObjectProperties_GetPipelineStackSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize:
        out = L"ID3D12StateObjectProperties_SetPipelineStackSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties1_GetProgramIdentifier:
        out = L"ID3D12StateObjectProperties1_GetProgramIdentifier";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNumWorkGraphs:
        out = L"ID3D12WorkGraphProperties_GetNumWorkGraphs";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetProgramName:
        out = L"ID3D12WorkGraphProperties_GetProgramName";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetWorkGraphIndex:
        out = L"ID3D12WorkGraphProperties_GetWorkGraphIndex";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNumNodes:
        out = L"ID3D12WorkGraphProperties_GetNumNodes";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNodeID:
        out = L"ID3D12WorkGraphProperties_GetNodeID";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNodeIndex:
        out = L"ID3D12WorkGraphProperties_GetNodeIndex";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex:
        out = L"ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNumEntrypoints:
        out = L"ID3D12WorkGraphProperties_GetNumEntrypoints";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointID:
        out = L"ID3D12WorkGraphProperties_GetEntrypointID";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointIndex:
        out = L"ID3D12WorkGraphProperties_GetEntrypointIndex";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes:
        out = L"ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements:
        out = L"ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements";
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes:
        out = L"ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CreateLifetimeTracker:
        out = L"ID3D12Device5_CreateLifetimeTracker";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_RemoveDevice:
        out = L"ID3D12Device5_RemoveDevice";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommands:
        out = L"ID3D12Device5_EnumerateMetaCommands";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommandParameters:
        out = L"ID3D12Device5_EnumerateMetaCommandParameters";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CreateMetaCommand:
        out = L"ID3D12Device5_CreateMetaCommand";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CreateStateObject:
        out = L"ID3D12Device5_CreateStateObject";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo:
        out = L"ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier:
        out = L"ID3D12Device5_CheckDriverMatchingIdentifier";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement:
        out = L"ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement:
        out = L"ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement:
        out = L"ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement:
        out = L"ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs:
        out = L"ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput:
        out = L"ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput:
        out = L"ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1:
        out = L"ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1:
        out = L"ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2:
        out = L"ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetDeviceState:
        out = L"ID3D12DeviceRemovedExtendedData2_GetDeviceState";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode:
        out = L"ID3D12Device6_SetBackgroundProcessingMode";
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession1_GetDesc1:
        out = L"ID3D12ProtectedResourceSession1_GetDesc1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device7_AddToStateObject:
        out = L"ID3D12Device7_AddToStateObject";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device7_CreateProtectedResourceSession1:
        out = L"ID3D12Device7_CreateProtectedResourceSession1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_GetResourceAllocationInfo2:
        out = L"ID3D12Device8_GetResourceAllocationInfo2";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_CreateCommittedResource2:
        out = L"ID3D12Device8_CreateCommittedResource2";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_CreatePlacedResource1:
        out = L"ID3D12Device8_CreatePlacedResource1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView:
        out = L"ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_GetCopyableFootprints1:
        out = L"ID3D12Device8_GetCopyableFootprints1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource1_GetProtectedResourceSession:
        out = L"ID3D12Resource1_GetProtectedResourceSession";
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource2_GetDesc1:
        out = L"ID3D12Resource2_GetDesc1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Heap1_GetProtectedResourceSession:
        out = L"ID3D12Heap1_GetProtectedResourceSession";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession:
        out = L"ID3D12GraphicsCommandList3_SetProtectedResourceSession";
        break;
    case format::ApiCallId::ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize:
        out = L"ID3D12MetaCommand_GetRequiredParameterResourceSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass:
        out = L"ID3D12GraphicsCommandList4_BeginRenderPass";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass:
        out = L"ID3D12GraphicsCommandList4_EndRenderPass";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand:
        out = L"ID3D12GraphicsCommandList4_InitializeMetaCommand";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand:
        out = L"ID3D12GraphicsCommandList4_ExecuteMetaCommand";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure:
        out = L"ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo:
        out = L"ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure:
        out = L"ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1:
        out = L"ID3D12GraphicsCommandList4_SetPipelineState1";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_DispatchRays:
        out = L"ID3D12GraphicsCommandList4_DispatchRays";
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_FindValue:
        out = L"ID3D12ShaderCacheSession_FindValue";
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_StoreValue:
        out = L"ID3D12ShaderCacheSession_StoreValue";
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_SetDeleteOnDestroy:
        out = L"ID3D12ShaderCacheSession_SetDeleteOnDestroy";
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_GetDesc:
        out = L"ID3D12ShaderCacheSession_GetDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device9_CreateShaderCacheSession:
        out = L"ID3D12Device9_CreateShaderCacheSession";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device9_ShaderCacheControl:
        out = L"ID3D12Device9_ShaderCacheControl";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device9_CreateCommandQueue1:
        out = L"ID3D12Device9_CreateCommandQueue1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device10_CreateCommittedResource3:
        out = L"ID3D12Device10_CreateCommittedResource3";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device10_CreatePlacedResource2:
        out = L"ID3D12Device10_CreatePlacedResource2";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device10_CreateReservedResource2:
        out = L"ID3D12Device10_CreateReservedResource2";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device11_CreateSampler2:
        out = L"ID3D12Device11_CreateSampler2";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device12_GetResourceAllocationInfo3:
        out = L"ID3D12Device12_GetResourceAllocationInfo3";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device13_OpenExistingHeapFromAddress1:
        out = L"ID3D12Device13_OpenExistingHeapFromAddress1";
        break;
    case format::ApiCallId::ApiCall_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary:
        out = L"ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary";
        break;
    case format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost:
        out = L"ID3D12VirtualizationGuestDevice_ShareWithHost";
        break;
    case format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_CreateFenceFd:
        out = L"ID3D12VirtualizationGuestDevice_CreateFenceFd";
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools_EnableShaderInstrumentation:
        out = L"ID3D12Tools_EnableShaderInstrumentation";
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools_ShaderInstrumentationEnabled:
        out = L"ID3D12Tools_ShaderInstrumentationEnabled";
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools1_ReserveGPUVARangesAtCreate:
        out = L"ID3D12Tools1_ReserveGPUVARangesAtCreate";
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools1_ClearReservedGPUVARangesList:
        out = L"ID3D12Tools1_ClearReservedGPUVARangesList";
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools2_SetApplicationSpecificDriverState:
        out = L"ID3D12Tools2_SetApplicationSpecificDriverState";
        break;
    case format::ApiCallId::ApiCall_ID3D12PageableTools_GetAllocation:
        out = L"ID3D12PageableTools_GetAllocation";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceTools_SetNextAllocationAddress:
        out = L"ID3D12DeviceTools_SetNextAllocationAddress";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceTools1_GetApplicationSpecificDriverState:
        out = L"ID3D12DeviceTools1_GetApplicationSpecificDriverState";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceTools1_GetApplicationSpecificDriverBlobStatus:
        out = L"ID3D12DeviceTools1_GetApplicationSpecificDriverBlobStatus";
        break;
    case format::ApiCallId::ApiCall_ID3D12SDKConfiguration_SetSDKVersion:
        out = L"ID3D12SDKConfiguration_SetSDKVersion";
        break;
    case format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory:
        out = L"ID3D12SDKConfiguration1_CreateDeviceFactory";
        break;
    case format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_FreeUnusedSDKs:
        out = L"ID3D12SDKConfiguration1_FreeUnusedSDKs";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_InitializeFromGlobalState:
        out = L"ID3D12DeviceFactory_InitializeFromGlobalState";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_ApplyToGlobalState:
        out = L"ID3D12DeviceFactory_ApplyToGlobalState";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_SetFlags:
        out = L"ID3D12DeviceFactory_SetFlags";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetFlags:
        out = L"ID3D12DeviceFactory_GetFlags";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface:
        out = L"ID3D12DeviceFactory_GetConfigurationInterface";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_EnableExperimentalFeatures:
        out = L"ID3D12DeviceFactory_EnableExperimentalFeatures";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_CreateDevice:
        out = L"ID3D12DeviceFactory_CreateDevice";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetDesc:
        out = L"ID3D12DeviceConfiguration_GetDesc";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures:
        out = L"ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature:
        out = L"ID3D12DeviceConfiguration_SerializeVersionedRootSignature";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer:
        out = L"ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer";
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary:
        out = L"ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate:
        out = L"ID3D12GraphicsCommandList5_RSSetShadingRate";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage:
        out = L"ID3D12GraphicsCommandList5_RSSetShadingRateImage";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList6_DispatchMesh:
        out = L"ID3D12GraphicsCommandList6_DispatchMesh";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList7_Barrier:
        out = L"ID3D12GraphicsCommandList7_Barrier";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef:
        out = L"ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_RSSetDepthBias:
        out = L"ID3D12GraphicsCommandList9_RSSetDepthBias";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue:
        out = L"ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList10_SetProgram:
        out = L"ID3D12GraphicsCommandList10_SetProgram";
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList10_DispatchGraph:
        out = L"ID3D12GraphicsCommandList10_DispatchGraph";
        break;
    case format::ApiCallId::ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice:
        out = L"ID3D12DSRDeviceFactory_CreateDSRDevice";
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData:
        out = L"ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData";
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVSubresourceState:
        out = L"ID3D12GBVDiagnostics_GetGBVSubresourceState";
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVResourceUniformState:
        out = L"ID3D12GBVDiagnostics_GetGBVResourceUniformState";
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVResourceInfo:
        out = L"ID3D12GBVDiagnostics_GetGBVResourceInfo";
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GBVReserved0:
        out = L"ID3D12GBVDiagnostics_GBVReserved0";
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GBVReserved1:
        out = L"ID3D12GBVDiagnostics_GBVReserved1";
        break;
    case format::ApiCallId::ApiCall_ID3D10Blob_GetBufferPointer:
        out = L"ID3D10Blob_GetBufferPointer";
        break;
    case format::ApiCallId::ApiCall_ID3D10Blob_GetBufferSize:
        out = L"ID3D10Blob_GetBufferSize";
        break;
    case format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback:
        out = L"ID3DDestructionNotifier_RegisterDestructionCallback";
        break;
    case format::ApiCallId::ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback:
        out = L"ID3DDestructionNotifier_UnregisterDestructionCallback";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug_EnableDebugLayer:
        out = L"ID3D12Debug_EnableDebugLayer";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug1_EnableDebugLayer:
        out = L"ID3D12Debug1_EnableDebugLayer";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableGPUBasedValidation:
        out = L"ID3D12Debug1_SetEnableGPUBasedValidation";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation:
        out = L"ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug2_SetGPUBasedValidationFlags:
        out = L"ID3D12Debug2_SetGPUBasedValidationFlags";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableGPUBasedValidation:
        out = L"ID3D12Debug3_SetEnableGPUBasedValidation";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation:
        out = L"ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug3_SetGPUBasedValidationFlags:
        out = L"ID3D12Debug3_SetGPUBasedValidationFlags";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug4_DisableDebugLayer:
        out = L"ID3D12Debug4_DisableDebugLayer";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug5_SetEnableAutoName:
        out = L"ID3D12Debug5_SetEnableAutoName";
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug6_SetForceLegacyBarrierValidation:
        out = L"ID3D12Debug6_SetForceLegacyBarrierValidation";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice1_SetDebugParameter:
        out = L"ID3D12DebugDevice1_SetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice1_GetDebugParameter:
        out = L"ID3D12DebugDevice1_GetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice1_ReportLiveDeviceObjects:
        out = L"ID3D12DebugDevice1_ReportLiveDeviceObjects";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice_SetFeatureMask:
        out = L"ID3D12DebugDevice_SetFeatureMask";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice_GetFeatureMask:
        out = L"ID3D12DebugDevice_GetFeatureMask";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice_ReportLiveDeviceObjects:
        out = L"ID3D12DebugDevice_ReportLiveDeviceObjects";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice2_SetDebugParameter:
        out = L"ID3D12DebugDevice2_SetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice2_GetDebugParameter:
        out = L"ID3D12DebugDevice2_GetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandQueue_AssertResourceState:
        out = L"ID3D12DebugCommandQueue_AssertResourceState";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertResourceAccess:
        out = L"ID3D12DebugCommandQueue1_AssertResourceAccess";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertTextureLayout:
        out = L"ID3D12DebugCommandQueue1_AssertTextureLayout";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList1_AssertResourceState:
        out = L"ID3D12DebugCommandList1_AssertResourceState";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList1_SetDebugParameter:
        out = L"ID3D12DebugCommandList1_SetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList1_GetDebugParameter:
        out = L"ID3D12DebugCommandList1_GetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList_AssertResourceState:
        out = L"ID3D12DebugCommandList_AssertResourceState";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList_SetFeatureMask:
        out = L"ID3D12DebugCommandList_SetFeatureMask";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList_GetFeatureMask:
        out = L"ID3D12DebugCommandList_GetFeatureMask";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList2_SetDebugParameter:
        out = L"ID3D12DebugCommandList2_SetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList2_GetDebugParameter:
        out = L"ID3D12DebugCommandList2_GetDebugParameter";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertResourceAccess:
        out = L"ID3D12DebugCommandList3_AssertResourceAccess";
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertTextureLayout:
        out = L"ID3D12DebugCommandList3_AssertTextureLayout";
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_Present:
        out = L"ID3D12SharingContract_Present";
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_SharedFenceSignal:
        out = L"ID3D12SharingContract_SharedFenceSignal";
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_BeginCapturableWork:
        out = L"ID3D12SharingContract_BeginCapturableWork";
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_EndCapturableWork:
        out = L"ID3D12SharingContract_EndCapturableWork";
        break;
    case format::ApiCallId::ApiCall_ID3D12ManualWriteTrackingResource_TrackWrite:
        out = L"ID3D12ManualWriteTrackingResource_TrackWrite";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMessageCountLimit:
        out = L"ID3D12InfoQueue_SetMessageCountLimit";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStoredMessages:
        out = L"ID3D12InfoQueue_ClearStoredMessages";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessage:
        out = L"ID3D12InfoQueue_GetMessage";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter:
        out = L"ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter:
        out = L"ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessages:
        out = L"ID3D12InfoQueue_GetNumStoredMessages";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter:
        out = L"ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit:
        out = L"ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessageCountLimit:
        out = L"ID3D12InfoQueue_GetMessageCountLimit";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddStorageFilterEntries:
        out = L"ID3D12InfoQueue_AddStorageFilterEntries";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilter:
        out = L"ID3D12InfoQueue_GetStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStorageFilter:
        out = L"ID3D12InfoQueue_ClearStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyStorageFilter:
        out = L"ID3D12InfoQueue_PushEmptyStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfStorageFilter:
        out = L"ID3D12InfoQueue_PushCopyOfStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushStorageFilter:
        out = L"ID3D12InfoQueue_PushStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PopStorageFilter:
        out = L"ID3D12InfoQueue_PopStorageFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilterStackSize:
        out = L"ID3D12InfoQueue_GetStorageFilterStackSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddRetrievalFilterEntries:
        out = L"ID3D12InfoQueue_AddRetrievalFilterEntries";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilter:
        out = L"ID3D12InfoQueue_GetRetrievalFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearRetrievalFilter:
        out = L"ID3D12InfoQueue_ClearRetrievalFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyRetrievalFilter:
        out = L"ID3D12InfoQueue_PushEmptyRetrievalFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfRetrievalFilter:
        out = L"ID3D12InfoQueue_PushCopyOfRetrievalFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushRetrievalFilter:
        out = L"ID3D12InfoQueue_PushRetrievalFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PopRetrievalFilter:
        out = L"ID3D12InfoQueue_PopRetrievalFilter";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilterStackSize:
        out = L"ID3D12InfoQueue_GetRetrievalFilterStackSize";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddMessage:
        out = L"ID3D12InfoQueue_AddMessage";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddApplicationMessage:
        out = L"ID3D12InfoQueue_AddApplicationMessage";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnCategory:
        out = L"ID3D12InfoQueue_SetBreakOnCategory";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnSeverity:
        out = L"ID3D12InfoQueue_SetBreakOnSeverity";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnID:
        out = L"ID3D12InfoQueue_SetBreakOnID";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnCategory:
        out = L"ID3D12InfoQueue_GetBreakOnCategory";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnSeverity:
        out = L"ID3D12InfoQueue_GetBreakOnSeverity";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnID:
        out = L"ID3D12InfoQueue_GetBreakOnID";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMuteDebugOutput:
        out = L"ID3D12InfoQueue_SetMuteDebugOutput";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMuteDebugOutput:
        out = L"ID3D12InfoQueue_GetMuteDebugOutput";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback:
        out = L"ID3D12InfoQueue1_RegisterMessageCallback";
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue1_UnregisterMessageCallback:
        out = L"ID3D12InfoQueue1_UnregisterMessageCallback";
        break;
    case format::ApiCallId::ApiCall_CreateDXGIFactory:
        out = L"CreateDXGIFactory";
        break;
    case format::ApiCallId::ApiCall_CreateDXGIFactory1:
        out = L"CreateDXGIFactory1";
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_SetPrivateData:
        out = L"IDXGIObject_SetPrivateData";
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_SetPrivateDataInterface:
        out = L"IDXGIObject_SetPrivateDataInterface";
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_GetPrivateData:
        out = L"IDXGIObject_GetPrivateData";
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_GetParent:
        out = L"IDXGIObject_GetParent";
        break;
    case format::ApiCallId::ApiCall_IDXGIDeviceSubObject_GetDevice:
        out = L"IDXGIDeviceSubObject_GetDevice";
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle:
        out = L"IDXGIResource_GetSharedHandle";
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_GetUsage:
        out = L"IDXGIResource_GetUsage";
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_SetEvictionPriority:
        out = L"IDXGIResource_SetEvictionPriority";
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_GetEvictionPriority:
        out = L"IDXGIResource_GetEvictionPriority";
        break;
    case format::ApiCallId::ApiCall_IDXGIKeyedMutex_AcquireSync:
        out = L"IDXGIKeyedMutex_AcquireSync";
        break;
    case format::ApiCallId::ApiCall_IDXGIKeyedMutex_ReleaseSync:
        out = L"IDXGIKeyedMutex_ReleaseSync";
        break;
    case format::ApiCallId::ApiCall_IDXGISurface_GetDesc:
        out = L"IDXGISurface_GetDesc";
        break;
    case format::ApiCallId::ApiCall_IDXGISurface_Map:
        out = L"IDXGISurface_Map";
        break;
    case format::ApiCallId::ApiCall_IDXGISurface_Unmap:
        out = L"IDXGISurface_Unmap";
        break;
    case format::ApiCallId::ApiCall_IDXGISurface1_GetDC:
        out = L"IDXGISurface1_GetDC";
        break;
    case format::ApiCallId::ApiCall_IDXGISurface1_ReleaseDC:
        out = L"IDXGISurface1_ReleaseDC";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter_EnumOutputs:
        out = L"IDXGIAdapter_EnumOutputs";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter_GetDesc:
        out = L"IDXGIAdapter_GetDesc";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter_CheckInterfaceSupport:
        out = L"IDXGIAdapter_CheckInterfaceSupport";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetDesc:
        out = L"IDXGIOutput_GetDesc";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetDisplayModeList:
        out = L"IDXGIOutput_GetDisplayModeList";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_FindClosestMatchingMode:
        out = L"IDXGIOutput_FindClosestMatchingMode";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_WaitForVBlank:
        out = L"IDXGIOutput_WaitForVBlank";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_TakeOwnership:
        out = L"IDXGIOutput_TakeOwnership";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_ReleaseOwnership:
        out = L"IDXGIOutput_ReleaseOwnership";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControlCapabilities:
        out = L"IDXGIOutput_GetGammaControlCapabilities";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_SetGammaControl:
        out = L"IDXGIOutput_SetGammaControl";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControl:
        out = L"IDXGIOutput_GetGammaControl";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_SetDisplaySurface:
        out = L"IDXGIOutput_SetDisplaySurface";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetDisplaySurfaceData:
        out = L"IDXGIOutput_GetDisplaySurfaceData";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetFrameStatistics:
        out = L"IDXGIOutput_GetFrameStatistics";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_Present:
        out = L"IDXGISwapChain_Present";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetBuffer:
        out = L"IDXGISwapChain_GetBuffer";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_SetFullscreenState:
        out = L"IDXGISwapChain_SetFullscreenState";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetFullscreenState:
        out = L"IDXGISwapChain_GetFullscreenState";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetDesc:
        out = L"IDXGISwapChain_GetDesc";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_ResizeBuffers:
        out = L"IDXGISwapChain_ResizeBuffers";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_ResizeTarget:
        out = L"IDXGISwapChain_ResizeTarget";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetContainingOutput:
        out = L"IDXGISwapChain_GetContainingOutput";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetFrameStatistics:
        out = L"IDXGISwapChain_GetFrameStatistics";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetLastPresentCount:
        out = L"IDXGISwapChain_GetLastPresentCount";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_EnumAdapters:
        out = L"IDXGIFactory_EnumAdapters";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation:
        out = L"IDXGIFactory_MakeWindowAssociation";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation:
        out = L"IDXGIFactory_GetWindowAssociation";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_CreateSwapChain:
        out = L"IDXGIFactory_CreateSwapChain";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter:
        out = L"IDXGIFactory_CreateSoftwareAdapter";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_GetAdapter:
        out = L"IDXGIDevice_GetAdapter";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_CreateSurface:
        out = L"IDXGIDevice_CreateSurface";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_QueryResourceResidency:
        out = L"IDXGIDevice_QueryResourceResidency";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_SetGPUThreadPriority:
        out = L"IDXGIDevice_SetGPUThreadPriority";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_GetGPUThreadPriority:
        out = L"IDXGIDevice_GetGPUThreadPriority";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory1_EnumAdapters1:
        out = L"IDXGIFactory1_EnumAdapters1";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory1_IsCurrent:
        out = L"IDXGIFactory1_IsCurrent";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter1_GetDesc1:
        out = L"IDXGIAdapter1_GetDesc1";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice1_SetMaximumFrameLatency:
        out = L"IDXGIDevice1_SetMaximumFrameLatency";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice1_GetMaximumFrameLatency:
        out = L"IDXGIDevice1_GetMaximumFrameLatency";
        break;
    case format::ApiCallId::ApiCall_IDXGIDisplayControl_IsStereoEnabled:
        out = L"IDXGIDisplayControl_IsStereoEnabled";
        break;
    case format::ApiCallId::ApiCall_IDXGIDisplayControl_SetStereoEnabled:
        out = L"IDXGIDisplayControl_SetStereoEnabled";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetDesc:
        out = L"IDXGIOutputDuplication_GetDesc";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_AcquireNextFrame:
        out = L"IDXGIOutputDuplication_AcquireNextFrame";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects:
        out = L"IDXGIOutputDuplication_GetFrameDirtyRects";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameMoveRects:
        out = L"IDXGIOutputDuplication_GetFrameMoveRects";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFramePointerShape:
        out = L"IDXGIOutputDuplication_GetFramePointerShape";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_MapDesktopSurface:
        out = L"IDXGIOutputDuplication_MapDesktopSurface";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface:
        out = L"IDXGIOutputDuplication_UnMapDesktopSurface";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_ReleaseFrame:
        out = L"IDXGIOutputDuplication_ReleaseFrame";
        break;
    case format::ApiCallId::ApiCall_IDXGISurface2_GetResource:
        out = L"IDXGISurface2_GetResource";
        break;
    case format::ApiCallId::ApiCall_IDXGIResource1_CreateSubresourceSurface:
        out = L"IDXGIResource1_CreateSubresourceSurface";
        break;
    case format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle:
        out = L"IDXGIResource1_CreateSharedHandle";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice2_OfferResources:
        out = L"IDXGIDevice2_OfferResources";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice2_ReclaimResources:
        out = L"IDXGIDevice2_ReclaimResources";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent:
        out = L"IDXGIDevice2_EnqueueSetEvent";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetDesc1:
        out = L"IDXGISwapChain1_GetDesc1";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetFullscreenDesc:
        out = L"IDXGISwapChain1_GetFullscreenDesc";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd:
        out = L"IDXGISwapChain1_GetHwnd";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetCoreWindow:
        out = L"IDXGISwapChain1_GetCoreWindow";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_Present1:
        out = L"IDXGISwapChain1_Present1";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported:
        out = L"IDXGISwapChain1_IsTemporaryMonoSupported";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetRestrictToOutput:
        out = L"IDXGISwapChain1_GetRestrictToOutput";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_SetBackgroundColor:
        out = L"IDXGISwapChain1_SetBackgroundColor";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetBackgroundColor:
        out = L"IDXGISwapChain1_GetBackgroundColor";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_SetRotation:
        out = L"IDXGISwapChain1_SetRotation";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetRotation:
        out = L"IDXGISwapChain1_GetRotation";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_IsWindowedStereoEnabled:
        out = L"IDXGIFactory2_IsWindowedStereoEnabled";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd:
        out = L"IDXGIFactory2_CreateSwapChainForHwnd";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow:
        out = L"IDXGIFactory2_CreateSwapChainForCoreWindow";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid:
        out = L"IDXGIFactory2_GetSharedResourceAdapterLuid";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow:
        out = L"IDXGIFactory2_RegisterStereoStatusWindow";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent:
        out = L"IDXGIFactory2_RegisterStereoStatusEvent";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterStereoStatus:
        out = L"IDXGIFactory2_UnregisterStereoStatus";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow:
        out = L"IDXGIFactory2_RegisterOcclusionStatusWindow";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent:
        out = L"IDXGIFactory2_RegisterOcclusionStatusEvent";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterOcclusionStatus:
        out = L"IDXGIFactory2_UnregisterOcclusionStatus";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForComposition:
        out = L"IDXGIFactory2_CreateSwapChainForComposition";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter2_GetDesc2:
        out = L"IDXGIAdapter2_GetDesc2";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplayModeList1:
        out = L"IDXGIOutput1_GetDisplayModeList1";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_FindClosestMatchingMode1:
        out = L"IDXGIOutput1_FindClosestMatchingMode1";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplaySurfaceData1:
        out = L"IDXGIOutput1_GetDisplaySurfaceData1";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_DuplicateOutput:
        out = L"IDXGIOutput1_DuplicateOutput";
        break;
    case format::ApiCallId::ApiCall_CreateDXGIFactory2:
        out = L"CreateDXGIFactory2";
        break;
    case format::ApiCallId::ApiCall_DXGIGetDebugInterface1:
        out = L"DXGIGetDebugInterface1";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice3_Trim:
        out = L"IDXGIDevice3_Trim";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_SetSourceSize:
        out = L"IDXGISwapChain2_SetSourceSize";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetSourceSize:
        out = L"IDXGISwapChain2_GetSourceSize";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_SetMaximumFrameLatency:
        out = L"IDXGISwapChain2_SetMaximumFrameLatency";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetMaximumFrameLatency:
        out = L"IDXGISwapChain2_GetMaximumFrameLatency";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject:
        out = L"IDXGISwapChain2_GetFrameLatencyWaitableObject";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_SetMatrixTransform:
        out = L"IDXGISwapChain2_SetMatrixTransform";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetMatrixTransform:
        out = L"IDXGISwapChain2_GetMatrixTransform";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput2_SupportsOverlays:
        out = L"IDXGIOutput2_SupportsOverlays";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory3_GetCreationFlags:
        out = L"IDXGIFactory3_GetCreationFlags";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_PresentBuffer:
        out = L"IDXGIDecodeSwapChain_PresentBuffer";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetSourceRect:
        out = L"IDXGIDecodeSwapChain_SetSourceRect";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetTargetRect:
        out = L"IDXGIDecodeSwapChain_SetTargetRect";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetDestSize:
        out = L"IDXGIDecodeSwapChain_SetDestSize";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetSourceRect:
        out = L"IDXGIDecodeSwapChain_GetSourceRect";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetTargetRect:
        out = L"IDXGIDecodeSwapChain_GetTargetRect";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetDestSize:
        out = L"IDXGIDecodeSwapChain_GetDestSize";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetColorSpace:
        out = L"IDXGIDecodeSwapChain_SetColorSpace";
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetColorSpace:
        out = L"IDXGIDecodeSwapChain_GetColorSpace";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle:
        out = L"IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle:
        out = L"IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia:
        out = L"IDXGISwapChainMedia_GetFrameStatisticsMedia";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChainMedia_SetPresentDuration:
        out = L"IDXGISwapChainMedia_SetPresentDuration";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport:
        out = L"IDXGISwapChainMedia_CheckPresentDurationSupport";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput3_CheckOverlaySupport:
        out = L"IDXGIOutput3_CheckOverlaySupport";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex:
        out = L"IDXGISwapChain3_GetCurrentBackBufferIndex";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_CheckColorSpaceSupport:
        out = L"IDXGISwapChain3_CheckColorSpaceSupport";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_SetColorSpace1:
        out = L"IDXGISwapChain3_SetColorSpace1";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_ResizeBuffers1:
        out = L"IDXGISwapChain3_ResizeBuffers1";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport:
        out = L"IDXGIOutput4_CheckOverlayColorSpaceSupport";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory4_EnumAdapterByLuid:
        out = L"IDXGIFactory4_EnumAdapterByLuid";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory4_EnumWarpAdapter:
        out = L"IDXGIFactory4_EnumWarpAdapter";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent:
        out = L"IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus:
        out = L"IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo:
        out = L"IDXGIAdapter3_QueryVideoMemoryInfo";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_SetVideoMemoryReservation:
        out = L"IDXGIAdapter3_SetVideoMemoryReservation";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent:
        out = L"IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification:
        out = L"IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput5_DuplicateOutput1:
        out = L"IDXGIOutput5_DuplicateOutput1";
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain4_SetHDRMetaData:
        out = L"IDXGISwapChain4_SetHDRMetaData";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice4_OfferResources1:
        out = L"IDXGIDevice4_OfferResources1";
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice4_ReclaimResources1:
        out = L"IDXGIDevice4_ReclaimResources1";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory5_CheckFeatureSupport:
        out = L"IDXGIFactory5_CheckFeatureSupport";
        break;
    case format::ApiCallId::ApiCall_DXGIDeclareAdapterRemovalSupport:
        out = L"DXGIDeclareAdapterRemovalSupport";
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter4_GetDesc3:
        out = L"IDXGIAdapter4_GetDesc3";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput6_GetDesc1:
        out = L"IDXGIOutput6_GetDesc1";
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport:
        out = L"IDXGIOutput6_CheckHardwareCompositionSupport";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference:
        out = L"IDXGIFactory6_EnumAdapterByGpuPreference";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent:
        out = L"IDXGIFactory7_RegisterAdaptersChangedEvent";
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent:
        out = L"IDXGIFactory7_UnregisterAdaptersChangedEvent";
        break;
    case format::ApiCallId::ApiCall_IUnknown_QueryInterface:
        out = L"IUnknown_QueryInterface";
        break;
    case format::ApiCallId::ApiCall_IUnknown_AddRef:
        out = L"IUnknown_AddRef";
        break;
    case format::ApiCallId::ApiCall_IUnknown_Release:
        out = L"IUnknown_Release";
        break;
    default:
        break;
    }
    return out;
}


GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
