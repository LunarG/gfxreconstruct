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
** This file is generated from dx12_decoder_body_generator.py.
**
*/


#include "generated_dx12_decoder.h"
#include "generated_dx12_struct_decoders_forward.h"
#include "decode/custom_dx12_struct_decoders_forward.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12Decoder::DecodeFunctionCall(format::ApiCallId  call_id,
                                     const ApiCallInfo& call_info,
                                     const uint8_t*     parameter_buffer,
                                     size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    switch (call_id)
    {
    case format::ApiCallId::ApiCall_D3D12SerializeRootSignature:
        Decode_D3D12SerializeRootSignature(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12CreateRootSignatureDeserializer:
        Decode_D3D12CreateRootSignatureDeserializer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12SerializeVersionedRootSignature:
        Decode_D3D12SerializeVersionedRootSignature(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializer:
        Decode_D3D12CreateVersionedRootSignatureDeserializer(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary:
        Decode_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12CreateDevice:
        Decode_D3D12CreateDevice(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12GetDebugInterface:
        Decode_D3D12GetDebugInterface(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12EnableExperimentalFeatures:
        Decode_D3D12EnableExperimentalFeatures(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_D3D12GetInterface:
        Decode_D3D12GetInterface(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_CreateDXGIFactory:
        Decode_CreateDXGIFactory(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_CreateDXGIFactory1:
        Decode_CreateDXGIFactory1(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_CreateDXGIFactory2:
        Decode_CreateDXGIFactory2(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_DXGIGetDebugInterface1:
        Decode_DXGIGetDebugInterface1(call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_DXGIDeclareAdapterRemovalSupport:
        Decode_DXGIDeclareAdapterRemovalSupport(call_info, parameter_buffer, buffer_size);
        break;
    default:
        Dx12DecoderBase::DecodeFunctionCall(call_id, call_info, parameter_buffer, buffer_size);
        break;
    }
}


void Dx12Decoder::DecodeMethodCall(format::ApiCallId  call_id,
                                   format::HandleId   object_id,
                                   const ApiCallInfo& call_info,
                                   const uint8_t*     parameter_buffer,
                                   size_t             buffer_size)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    switch (call_id)
    {
    case format::ApiCallId::ApiCall_ID3D12Object_GetPrivateData:
        Decode_ID3D12Object_GetPrivateData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Object_SetPrivateData:
        Decode_ID3D12Object_SetPrivateData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Object_SetPrivateDataInterface:
        Decode_ID3D12Object_SetPrivateDataInterface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Object_SetName:
        Decode_ID3D12Object_SetName(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceChild_GetDevice:
        Decode_ID3D12DeviceChild_GetDevice(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc:
        Decode_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion:
        Decode_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc:
        Decode_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Heap_GetDesc:
        Decode_ID3D12Heap_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_Map:
        Decode_ID3D12Resource_Map(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_Unmap:
        Decode_ID3D12Resource_Unmap(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_GetDesc:
        Decode_ID3D12Resource_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress:
        Decode_ID3D12Resource_GetGPUVirtualAddress(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_ReadFromSubresource:
        Decode_ID3D12Resource_ReadFromSubresource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource_GetHeapProperties:
        Decode_ID3D12Resource_GetHeapProperties(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandAllocator_Reset:
        Decode_ID3D12CommandAllocator_Reset(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence_GetCompletedValue:
        Decode_ID3D12Fence_GetCompletedValue(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion:
        Decode_ID3D12Fence_SetEventOnCompletion(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence_Signal:
        Decode_ID3D12Fence_Signal(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Fence1_GetCreationFlags:
        Decode_ID3D12Fence1_GetCreationFlags(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineState_GetCachedBlob:
        Decode_ID3D12PipelineState_GetCachedBlob(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetDesc:
        Decode_ID3D12DescriptorHeap_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart:
        Decode_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart:
        Decode_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandList_GetType:
        Decode_ID3D12CommandList_GetType(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close:
        Decode_ID3D12GraphicsCommandList_Close(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset:
        Decode_ID3D12GraphicsCommandList_Reset(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearState:
        Decode_ID3D12GraphicsCommandList_ClearState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced:
        Decode_ID3D12GraphicsCommandList_DrawInstanced(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced:
        Decode_ID3D12GraphicsCommandList_DrawIndexedInstanced(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch:
        Decode_ID3D12GraphicsCommandList_Dispatch(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion:
        Decode_ID3D12GraphicsCommandList_CopyBufferRegion(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion:
        Decode_ID3D12GraphicsCommandList_CopyTextureRegion(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyResource:
        Decode_ID3D12GraphicsCommandList_CopyResource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTiles:
        Decode_ID3D12GraphicsCommandList_CopyTiles(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveSubresource:
        Decode_ID3D12GraphicsCommandList_ResolveSubresource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology:
        Decode_ID3D12GraphicsCommandList_IASetPrimitiveTopology(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetViewports:
        Decode_ID3D12GraphicsCommandList_RSSetViewports(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects:
        Decode_ID3D12GraphicsCommandList_RSSetScissorRects(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor:
        Decode_ID3D12GraphicsCommandList_OMSetBlendFactor(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef:
        Decode_ID3D12GraphicsCommandList_OMSetStencilRef(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPipelineState:
        Decode_ID3D12GraphicsCommandList_SetPipelineState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier:
        Decode_ID3D12GraphicsCommandList_ResourceBarrier(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle:
        Decode_ID3D12GraphicsCommandList_ExecuteBundle(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps:
        Decode_ID3D12GraphicsCommandList_SetDescriptorHeaps(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature:
        Decode_ID3D12GraphicsCommandList_SetComputeRootSignature(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature:
        Decode_ID3D12GraphicsCommandList_SetGraphicsRootSignature(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable:
        Decode_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable:
        Decode_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant:
        Decode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant:
        Decode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants:
        Decode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants:
        Decode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView:
        Decode_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView:
        Decode_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView:
        Decode_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView:
        Decode_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView:
        Decode_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView:
        Decode_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer:
        Decode_ID3D12GraphicsCommandList_IASetIndexBuffer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers:
        Decode_ID3D12GraphicsCommandList_IASetVertexBuffers(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SOSetTargets:
        Decode_ID3D12GraphicsCommandList_SOSetTargets(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets:
        Decode_ID3D12GraphicsCommandList_OMSetRenderTargets(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView:
        Decode_ID3D12GraphicsCommandList_ClearDepthStencilView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView:
        Decode_ID3D12GraphicsCommandList_ClearRenderTargetView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint:
        Decode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat:
        Decode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DiscardResource:
        Decode_ID3D12GraphicsCommandList_DiscardResource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginQuery:
        Decode_ID3D12GraphicsCommandList_BeginQuery(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndQuery:
        Decode_ID3D12GraphicsCommandList_EndQuery(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveQueryData:
        Decode_ID3D12GraphicsCommandList_ResolveQueryData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPredication:
        Decode_ID3D12GraphicsCommandList_SetPredication(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetMarker:
        Decode_ID3D12GraphicsCommandList_SetMarker(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginEvent:
        Decode_ID3D12GraphicsCommandList_BeginEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndEvent:
        Decode_ID3D12GraphicsCommandList_EndEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect:
        Decode_ID3D12GraphicsCommandList_ExecuteIndirect(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT:
        Decode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64:
        Decode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds:
        Decode_ID3D12GraphicsCommandList1_OMSetDepthBounds(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions:
        Decode_ID3D12GraphicsCommandList1_SetSamplePositions(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion:
        Decode_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask:
        Decode_ID3D12GraphicsCommandList1_SetViewInstanceMask(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate:
        Decode_ID3D12GraphicsCommandList2_WriteBufferImmediate(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_UpdateTileMappings:
        Decode_ID3D12CommandQueue_UpdateTileMappings(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_CopyTileMappings:
        Decode_ID3D12CommandQueue_CopyTileMappings(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists:
        Decode_ID3D12CommandQueue_ExecuteCommandLists(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_SetMarker:
        Decode_ID3D12CommandQueue_SetMarker(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_BeginEvent:
        Decode_ID3D12CommandQueue_BeginEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_EndEvent:
        Decode_ID3D12CommandQueue_EndEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal:
        Decode_ID3D12CommandQueue_Signal(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_Wait:
        Decode_ID3D12CommandQueue_Wait(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_GetTimestampFrequency:
        Decode_ID3D12CommandQueue_GetTimestampFrequency(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_GetClockCalibration:
        Decode_ID3D12CommandQueue_GetClockCalibration(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12CommandQueue_GetDesc:
        Decode_ID3D12CommandQueue_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetNodeCount:
        Decode_ID3D12Device_GetNodeCount(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue:
        Decode_ID3D12Device_CreateCommandQueue(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandAllocator:
        Decode_ID3D12Device_CreateCommandAllocator(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState:
        Decode_ID3D12Device_CreateGraphicsPipelineState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState:
        Decode_ID3D12Device_CreateComputePipelineState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandList:
        Decode_ID3D12Device_CreateCommandList(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateDescriptorHeap:
        Decode_ID3D12Device_CreateDescriptorHeap(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize:
        Decode_ID3D12Device_GetDescriptorHandleIncrementSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateRootSignature:
        Decode_ID3D12Device_CreateRootSignature(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateConstantBufferView:
        Decode_ID3D12Device_CreateConstantBufferView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateShaderResourceView:
        Decode_ID3D12Device_CreateShaderResourceView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateUnorderedAccessView:
        Decode_ID3D12Device_CreateUnorderedAccessView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateRenderTargetView:
        Decode_ID3D12Device_CreateRenderTargetView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateDepthStencilView:
        Decode_ID3D12Device_CreateDepthStencilView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateSampler:
        Decode_ID3D12Device_CreateSampler(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptors:
        Decode_ID3D12Device_CopyDescriptors(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptorsSimple:
        Decode_ID3D12Device_CopyDescriptorsSimple(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetResourceAllocationInfo:
        Decode_ID3D12Device_GetResourceAllocationInfo(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetCustomHeapProperties:
        Decode_ID3D12Device_GetCustomHeapProperties(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommittedResource:
        Decode_ID3D12Device_CreateCommittedResource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateHeap:
        Decode_ID3D12Device_CreateHeap(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreatePlacedResource:
        Decode_ID3D12Device_CreatePlacedResource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateReservedResource:
        Decode_ID3D12Device_CreateReservedResource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle:
        Decode_ID3D12Device_CreateSharedHandle(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle:
        Decode_ID3D12Device_OpenSharedHandle(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName:
        Decode_ID3D12Device_OpenSharedHandleByName(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_MakeResident:
        Decode_ID3D12Device_MakeResident(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_Evict:
        Decode_ID3D12Device_Evict(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateFence:
        Decode_ID3D12Device_CreateFence(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetDeviceRemovedReason:
        Decode_ID3D12Device_GetDeviceRemovedReason(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetCopyableFootprints:
        Decode_ID3D12Device_GetCopyableFootprints(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateQueryHeap:
        Decode_ID3D12Device_CreateQueryHeap(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_SetStablePowerState:
        Decode_ID3D12Device_SetStablePowerState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_CreateCommandSignature:
        Decode_ID3D12Device_CreateCommandSignature(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetResourceTiling:
        Decode_ID3D12Device_GetResourceTiling(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device_GetAdapterLuid:
        Decode_ID3D12Device_GetAdapterLuid(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline:
        Decode_ID3D12PipelineLibrary_StorePipeline(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline:
        Decode_ID3D12PipelineLibrary_LoadGraphicsPipeline(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline:
        Decode_ID3D12PipelineLibrary_LoadComputePipeline(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_GetSerializedSize:
        Decode_ID3D12PipelineLibrary_GetSerializedSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary_Serialize:
        Decode_ID3D12PipelineLibrary_Serialize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PipelineLibrary1_LoadPipeline:
        Decode_ID3D12PipelineLibrary1_LoadPipeline(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device1_CreatePipelineLibrary:
        Decode_ID3D12Device1_CreatePipelineLibrary(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion:
        Decode_ID3D12Device1_SetEventOnMultipleFenceCompletion(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device1_SetResidencyPriority:
        Decode_ID3D12Device1_SetResidencyPriority(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device2_CreatePipelineState:
        Decode_ID3D12Device2_CreatePipelineState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress:
        Decode_ID3D12Device3_OpenExistingHeapFromAddress(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping:
        Decode_ID3D12Device3_OpenExistingHeapFromFileMapping(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device3_EnqueueMakeResident:
        Decode_ID3D12Device3_EnqueueMakeResident(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetStatusFence:
        Decode_ID3D12ProtectedSession_GetStatusFence(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetSessionStatus:
        Decode_ID3D12ProtectedSession_GetSessionStatus(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession_GetDesc:
        Decode_ID3D12ProtectedResourceSession_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateCommandList1:
        Decode_ID3D12Device4_CreateCommandList1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateProtectedResourceSession:
        Decode_ID3D12Device4_CreateProtectedResourceSession(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateCommittedResource1:
        Decode_ID3D12Device4_CreateCommittedResource1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateHeap1:
        Decode_ID3D12Device4_CreateHeap1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_CreateReservedResource1:
        Decode_ID3D12Device4_CreateReservedResource1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device4_GetResourceAllocationInfo1:
        Decode_ID3D12Device4_GetResourceAllocationInfo1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated:
        Decode_ID3D12LifetimeOwner_LifetimeStateUpdated(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetLUID:
        Decode_ID3D12SwapChainAssistant_GetLUID(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject:
        Decode_ID3D12SwapChainAssistant_GetSwapChainObject(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue:
        Decode_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync:
        Decode_ID3D12SwapChainAssistant_InsertImplicitSync(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject:
        Decode_ID3D12LifetimeTracker_DestroyOwnedObject(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier:
        Decode_ID3D12StateObjectProperties_GetShaderIdentifier(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderStackSize:
        Decode_ID3D12StateObjectProperties_GetShaderStackSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize:
        Decode_ID3D12StateObjectProperties_GetPipelineStackSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize:
        Decode_ID3D12StateObjectProperties_SetPipelineStackSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12StateObjectProperties1_GetProgramIdentifier:
        Decode_ID3D12StateObjectProperties1_GetProgramIdentifier(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNumWorkGraphs:
        Decode_ID3D12WorkGraphProperties_GetNumWorkGraphs(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetProgramName:
        Decode_ID3D12WorkGraphProperties_GetProgramName(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetWorkGraphIndex:
        Decode_ID3D12WorkGraphProperties_GetWorkGraphIndex(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNumNodes:
        Decode_ID3D12WorkGraphProperties_GetNumNodes(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNodeID:
        Decode_ID3D12WorkGraphProperties_GetNodeID(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNodeIndex:
        Decode_ID3D12WorkGraphProperties_GetNodeIndex(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex:
        Decode_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetNumEntrypoints:
        Decode_ID3D12WorkGraphProperties_GetNumEntrypoints(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointID:
        Decode_ID3D12WorkGraphProperties_GetEntrypointID(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointIndex:
        Decode_ID3D12WorkGraphProperties_GetEntrypointIndex(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes:
        Decode_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements:
        Decode_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes:
        Decode_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CreateLifetimeTracker:
        Decode_ID3D12Device5_CreateLifetimeTracker(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_RemoveDevice:
        Decode_ID3D12Device5_RemoveDevice(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommands:
        Decode_ID3D12Device5_EnumerateMetaCommands(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommandParameters:
        Decode_ID3D12Device5_EnumerateMetaCommandParameters(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CreateMetaCommand:
        Decode_ID3D12Device5_CreateMetaCommand(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CreateStateObject:
        Decode_ID3D12Device5_CreateStateObject(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo:
        Decode_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier:
        Decode_ID3D12Device5_CheckDriverMatchingIdentifier(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement:
        Decode_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement:
        Decode_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement:
        Decode_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement:
        Decode_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs:
        Decode_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput:
        Decode_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput:
        Decode_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1:
        Decode_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1:
        Decode_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2:
        Decode_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetDeviceState:
        Decode_ID3D12DeviceRemovedExtendedData2_GetDeviceState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode:
        Decode_ID3D12Device6_SetBackgroundProcessingMode(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession1_GetDesc1:
        Decode_ID3D12ProtectedResourceSession1_GetDesc1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device7_AddToStateObject:
        Decode_ID3D12Device7_AddToStateObject(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device7_CreateProtectedResourceSession1:
        Decode_ID3D12Device7_CreateProtectedResourceSession1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_GetResourceAllocationInfo2:
        Decode_ID3D12Device8_GetResourceAllocationInfo2(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_CreateCommittedResource2:
        Decode_ID3D12Device8_CreateCommittedResource2(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_CreatePlacedResource1:
        Decode_ID3D12Device8_CreatePlacedResource1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView:
        Decode_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device8_GetCopyableFootprints1:
        Decode_ID3D12Device8_GetCopyableFootprints1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource1_GetProtectedResourceSession:
        Decode_ID3D12Resource1_GetProtectedResourceSession(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Resource2_GetDesc1:
        Decode_ID3D12Resource2_GetDesc1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Heap1_GetProtectedResourceSession:
        Decode_ID3D12Heap1_GetProtectedResourceSession(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession:
        Decode_ID3D12GraphicsCommandList3_SetProtectedResourceSession(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize:
        Decode_ID3D12MetaCommand_GetRequiredParameterResourceSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass:
        Decode_ID3D12GraphicsCommandList4_BeginRenderPass(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass:
        Decode_ID3D12GraphicsCommandList4_EndRenderPass(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand:
        Decode_ID3D12GraphicsCommandList4_InitializeMetaCommand(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand:
        Decode_ID3D12GraphicsCommandList4_ExecuteMetaCommand(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure:
        Decode_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo:
        Decode_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure:
        Decode_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1:
        Decode_ID3D12GraphicsCommandList4_SetPipelineState1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_DispatchRays:
        Decode_ID3D12GraphicsCommandList4_DispatchRays(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_FindValue:
        Decode_ID3D12ShaderCacheSession_FindValue(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_StoreValue:
        Decode_ID3D12ShaderCacheSession_StoreValue(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_SetDeleteOnDestroy:
        Decode_ID3D12ShaderCacheSession_SetDeleteOnDestroy(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_GetDesc:
        Decode_ID3D12ShaderCacheSession_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device9_CreateShaderCacheSession:
        Decode_ID3D12Device9_CreateShaderCacheSession(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device9_ShaderCacheControl:
        Decode_ID3D12Device9_ShaderCacheControl(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device9_CreateCommandQueue1:
        Decode_ID3D12Device9_CreateCommandQueue1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device10_CreateCommittedResource3:
        Decode_ID3D12Device10_CreateCommittedResource3(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device10_CreatePlacedResource2:
        Decode_ID3D12Device10_CreatePlacedResource2(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device10_CreateReservedResource2:
        Decode_ID3D12Device10_CreateReservedResource2(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device11_CreateSampler2:
        Decode_ID3D12Device11_CreateSampler2(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device12_GetResourceAllocationInfo3:
        Decode_ID3D12Device12_GetResourceAllocationInfo3(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device13_OpenExistingHeapFromAddress1:
        Decode_ID3D12Device13_OpenExistingHeapFromAddress1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary:
        Decode_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost:
        Decode_ID3D12VirtualizationGuestDevice_ShareWithHost(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_CreateFenceFd:
        Decode_ID3D12VirtualizationGuestDevice_CreateFenceFd(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools_EnableShaderInstrumentation:
        Decode_ID3D12Tools_EnableShaderInstrumentation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools_ShaderInstrumentationEnabled:
        Decode_ID3D12Tools_ShaderInstrumentationEnabled(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools1_ReserveGPUVARangesAtCreate:
        Decode_ID3D12Tools1_ReserveGPUVARangesAtCreate(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools1_ClearReservedGPUVARangesList:
        Decode_ID3D12Tools1_ClearReservedGPUVARangesList(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Tools2_SetApplicationSpecificDriverState:
        Decode_ID3D12Tools2_SetApplicationSpecificDriverState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12PageableTools_GetAllocation:
        Decode_ID3D12PageableTools_GetAllocation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceTools_SetNextAllocationAddress:
        Decode_ID3D12DeviceTools_SetNextAllocationAddress(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceTools1_GetApplicationSpecificDriverState:
        Decode_ID3D12DeviceTools1_GetApplicationSpecificDriverState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceTools1_GetApplicationSpecificDriverBlobStatus:
        Decode_ID3D12DeviceTools1_GetApplicationSpecificDriverBlobStatus(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SDKConfiguration_SetSDKVersion:
        Decode_ID3D12SDKConfiguration_SetSDKVersion(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory:
        Decode_ID3D12SDKConfiguration1_CreateDeviceFactory(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_FreeUnusedSDKs:
        Decode_ID3D12SDKConfiguration1_FreeUnusedSDKs(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_InitializeFromGlobalState:
        Decode_ID3D12DeviceFactory_InitializeFromGlobalState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_ApplyToGlobalState:
        Decode_ID3D12DeviceFactory_ApplyToGlobalState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_SetFlags:
        Decode_ID3D12DeviceFactory_SetFlags(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetFlags:
        Decode_ID3D12DeviceFactory_GetFlags(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface:
        Decode_ID3D12DeviceFactory_GetConfigurationInterface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_EnableExperimentalFeatures:
        Decode_ID3D12DeviceFactory_EnableExperimentalFeatures(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceFactory_CreateDevice:
        Decode_ID3D12DeviceFactory_CreateDevice(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetDesc:
        Decode_ID3D12DeviceConfiguration_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures:
        Decode_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature:
        Decode_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer:
        Decode_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary:
        Decode_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate:
        Decode_ID3D12GraphicsCommandList5_RSSetShadingRate(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage:
        Decode_ID3D12GraphicsCommandList5_RSSetShadingRateImage(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList6_DispatchMesh:
        Decode_ID3D12GraphicsCommandList6_DispatchMesh(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList7_Barrier:
        Decode_ID3D12GraphicsCommandList7_Barrier(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef:
        Decode_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_RSSetDepthBias:
        Decode_ID3D12GraphicsCommandList9_RSSetDepthBias(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue:
        Decode_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList10_SetProgram:
        Decode_ID3D12GraphicsCommandList10_SetProgram(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GraphicsCommandList10_DispatchGraph:
        Decode_ID3D12GraphicsCommandList10_DispatchGraph(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice:
        Decode_ID3D12DSRDeviceFactory_CreateDSRDevice(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData:
        Decode_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVSubresourceState:
        Decode_ID3D12GBVDiagnostics_GetGBVSubresourceState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVResourceUniformState:
        Decode_ID3D12GBVDiagnostics_GetGBVResourceUniformState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GetGBVResourceInfo:
        Decode_ID3D12GBVDiagnostics_GetGBVResourceInfo(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GBVReserved0:
        Decode_ID3D12GBVDiagnostics_GBVReserved0(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12GBVDiagnostics_GBVReserved1:
        Decode_ID3D12GBVDiagnostics_GBVReserved1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D10Blob_GetBufferPointer:
        Decode_ID3D10Blob_GetBufferPointer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D10Blob_GetBufferSize:
        Decode_ID3D10Blob_GetBufferSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback:
        Decode_ID3DDestructionNotifier_RegisterDestructionCallback(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback:
        Decode_ID3DDestructionNotifier_UnregisterDestructionCallback(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug_EnableDebugLayer:
        Decode_ID3D12Debug_EnableDebugLayer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug1_EnableDebugLayer:
        Decode_ID3D12Debug1_EnableDebugLayer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableGPUBasedValidation:
        Decode_ID3D12Debug1_SetEnableGPUBasedValidation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation:
        Decode_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug2_SetGPUBasedValidationFlags:
        Decode_ID3D12Debug2_SetGPUBasedValidationFlags(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableGPUBasedValidation:
        Decode_ID3D12Debug3_SetEnableGPUBasedValidation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation:
        Decode_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug3_SetGPUBasedValidationFlags:
        Decode_ID3D12Debug3_SetGPUBasedValidationFlags(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug4_DisableDebugLayer:
        Decode_ID3D12Debug4_DisableDebugLayer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug5_SetEnableAutoName:
        Decode_ID3D12Debug5_SetEnableAutoName(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12Debug6_SetForceLegacyBarrierValidation:
        Decode_ID3D12Debug6_SetForceLegacyBarrierValidation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice1_SetDebugParameter:
        Decode_ID3D12DebugDevice1_SetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice1_GetDebugParameter:
        Decode_ID3D12DebugDevice1_GetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice1_ReportLiveDeviceObjects:
        Decode_ID3D12DebugDevice1_ReportLiveDeviceObjects(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice_SetFeatureMask:
        Decode_ID3D12DebugDevice_SetFeatureMask(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice_GetFeatureMask:
        Decode_ID3D12DebugDevice_GetFeatureMask(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice_ReportLiveDeviceObjects:
        Decode_ID3D12DebugDevice_ReportLiveDeviceObjects(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice2_SetDebugParameter:
        Decode_ID3D12DebugDevice2_SetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugDevice2_GetDebugParameter:
        Decode_ID3D12DebugDevice2_GetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandQueue_AssertResourceState:
        Decode_ID3D12DebugCommandQueue_AssertResourceState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertResourceAccess:
        Decode_ID3D12DebugCommandQueue1_AssertResourceAccess(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertTextureLayout:
        Decode_ID3D12DebugCommandQueue1_AssertTextureLayout(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList1_AssertResourceState:
        Decode_ID3D12DebugCommandList1_AssertResourceState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList1_SetDebugParameter:
        Decode_ID3D12DebugCommandList1_SetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList1_GetDebugParameter:
        Decode_ID3D12DebugCommandList1_GetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList_AssertResourceState:
        Decode_ID3D12DebugCommandList_AssertResourceState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList_SetFeatureMask:
        Decode_ID3D12DebugCommandList_SetFeatureMask(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList_GetFeatureMask:
        Decode_ID3D12DebugCommandList_GetFeatureMask(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList2_SetDebugParameter:
        Decode_ID3D12DebugCommandList2_SetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList2_GetDebugParameter:
        Decode_ID3D12DebugCommandList2_GetDebugParameter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertResourceAccess:
        Decode_ID3D12DebugCommandList3_AssertResourceAccess(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertTextureLayout:
        Decode_ID3D12DebugCommandList3_AssertTextureLayout(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_Present:
        Decode_ID3D12SharingContract_Present(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_SharedFenceSignal:
        Decode_ID3D12SharingContract_SharedFenceSignal(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_BeginCapturableWork:
        Decode_ID3D12SharingContract_BeginCapturableWork(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12SharingContract_EndCapturableWork:
        Decode_ID3D12SharingContract_EndCapturableWork(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12ManualWriteTrackingResource_TrackWrite:
        Decode_ID3D12ManualWriteTrackingResource_TrackWrite(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMessageCountLimit:
        Decode_ID3D12InfoQueue_SetMessageCountLimit(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStoredMessages:
        Decode_ID3D12InfoQueue_ClearStoredMessages(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessage:
        Decode_ID3D12InfoQueue_GetMessage(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter:
        Decode_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter:
        Decode_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessages:
        Decode_ID3D12InfoQueue_GetNumStoredMessages(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter:
        Decode_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit:
        Decode_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessageCountLimit:
        Decode_ID3D12InfoQueue_GetMessageCountLimit(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddStorageFilterEntries:
        Decode_ID3D12InfoQueue_AddStorageFilterEntries(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilter:
        Decode_ID3D12InfoQueue_GetStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStorageFilter:
        Decode_ID3D12InfoQueue_ClearStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyStorageFilter:
        Decode_ID3D12InfoQueue_PushEmptyStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfStorageFilter:
        Decode_ID3D12InfoQueue_PushCopyOfStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushStorageFilter:
        Decode_ID3D12InfoQueue_PushStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PopStorageFilter:
        Decode_ID3D12InfoQueue_PopStorageFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilterStackSize:
        Decode_ID3D12InfoQueue_GetStorageFilterStackSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddRetrievalFilterEntries:
        Decode_ID3D12InfoQueue_AddRetrievalFilterEntries(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilter:
        Decode_ID3D12InfoQueue_GetRetrievalFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearRetrievalFilter:
        Decode_ID3D12InfoQueue_ClearRetrievalFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyRetrievalFilter:
        Decode_ID3D12InfoQueue_PushEmptyRetrievalFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfRetrievalFilter:
        Decode_ID3D12InfoQueue_PushCopyOfRetrievalFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PushRetrievalFilter:
        Decode_ID3D12InfoQueue_PushRetrievalFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_PopRetrievalFilter:
        Decode_ID3D12InfoQueue_PopRetrievalFilter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilterStackSize:
        Decode_ID3D12InfoQueue_GetRetrievalFilterStackSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddMessage:
        Decode_ID3D12InfoQueue_AddMessage(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_AddApplicationMessage:
        Decode_ID3D12InfoQueue_AddApplicationMessage(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnCategory:
        Decode_ID3D12InfoQueue_SetBreakOnCategory(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnSeverity:
        Decode_ID3D12InfoQueue_SetBreakOnSeverity(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnID:
        Decode_ID3D12InfoQueue_SetBreakOnID(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnCategory:
        Decode_ID3D12InfoQueue_GetBreakOnCategory(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnSeverity:
        Decode_ID3D12InfoQueue_GetBreakOnSeverity(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnID:
        Decode_ID3D12InfoQueue_GetBreakOnID(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMuteDebugOutput:
        Decode_ID3D12InfoQueue_SetMuteDebugOutput(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMuteDebugOutput:
        Decode_ID3D12InfoQueue_GetMuteDebugOutput(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback:
        Decode_ID3D12InfoQueue1_RegisterMessageCallback(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_ID3D12InfoQueue1_UnregisterMessageCallback:
        Decode_ID3D12InfoQueue1_UnregisterMessageCallback(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_SetPrivateData:
        Decode_IDXGIObject_SetPrivateData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_SetPrivateDataInterface:
        Decode_IDXGIObject_SetPrivateDataInterface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_GetPrivateData:
        Decode_IDXGIObject_GetPrivateData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIObject_GetParent:
        Decode_IDXGIObject_GetParent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDeviceSubObject_GetDevice:
        Decode_IDXGIDeviceSubObject_GetDevice(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle:
        Decode_IDXGIResource_GetSharedHandle(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_GetUsage:
        Decode_IDXGIResource_GetUsage(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_SetEvictionPriority:
        Decode_IDXGIResource_SetEvictionPriority(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIResource_GetEvictionPriority:
        Decode_IDXGIResource_GetEvictionPriority(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIKeyedMutex_AcquireSync:
        Decode_IDXGIKeyedMutex_AcquireSync(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIKeyedMutex_ReleaseSync:
        Decode_IDXGIKeyedMutex_ReleaseSync(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISurface_GetDesc:
        Decode_IDXGISurface_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISurface_Map:
        Decode_IDXGISurface_Map(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISurface_Unmap:
        Decode_IDXGISurface_Unmap(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISurface1_GetDC:
        Decode_IDXGISurface1_GetDC(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISurface1_ReleaseDC:
        Decode_IDXGISurface1_ReleaseDC(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter_EnumOutputs:
        Decode_IDXGIAdapter_EnumOutputs(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter_GetDesc:
        Decode_IDXGIAdapter_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter_CheckInterfaceSupport:
        Decode_IDXGIAdapter_CheckInterfaceSupport(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetDesc:
        Decode_IDXGIOutput_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetDisplayModeList:
        Decode_IDXGIOutput_GetDisplayModeList(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_FindClosestMatchingMode:
        Decode_IDXGIOutput_FindClosestMatchingMode(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_WaitForVBlank:
        Decode_IDXGIOutput_WaitForVBlank(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_TakeOwnership:
        Decode_IDXGIOutput_TakeOwnership(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_ReleaseOwnership:
        Decode_IDXGIOutput_ReleaseOwnership(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControlCapabilities:
        Decode_IDXGIOutput_GetGammaControlCapabilities(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_SetGammaControl:
        Decode_IDXGIOutput_SetGammaControl(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControl:
        Decode_IDXGIOutput_GetGammaControl(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_SetDisplaySurface:
        Decode_IDXGIOutput_SetDisplaySurface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetDisplaySurfaceData:
        Decode_IDXGIOutput_GetDisplaySurfaceData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput_GetFrameStatistics:
        Decode_IDXGIOutput_GetFrameStatistics(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_Present:
        Decode_IDXGISwapChain_Present(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetBuffer:
        Decode_IDXGISwapChain_GetBuffer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_SetFullscreenState:
        Decode_IDXGISwapChain_SetFullscreenState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetFullscreenState:
        Decode_IDXGISwapChain_GetFullscreenState(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetDesc:
        Decode_IDXGISwapChain_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_ResizeBuffers:
        Decode_IDXGISwapChain_ResizeBuffers(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_ResizeTarget:
        Decode_IDXGISwapChain_ResizeTarget(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetContainingOutput:
        Decode_IDXGISwapChain_GetContainingOutput(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetFrameStatistics:
        Decode_IDXGISwapChain_GetFrameStatistics(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain_GetLastPresentCount:
        Decode_IDXGISwapChain_GetLastPresentCount(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_EnumAdapters:
        Decode_IDXGIFactory_EnumAdapters(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation:
        Decode_IDXGIFactory_MakeWindowAssociation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation:
        Decode_IDXGIFactory_GetWindowAssociation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_CreateSwapChain:
        Decode_IDXGIFactory_CreateSwapChain(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter:
        Decode_IDXGIFactory_CreateSoftwareAdapter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_GetAdapter:
        Decode_IDXGIDevice_GetAdapter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_CreateSurface:
        Decode_IDXGIDevice_CreateSurface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_QueryResourceResidency:
        Decode_IDXGIDevice_QueryResourceResidency(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_SetGPUThreadPriority:
        Decode_IDXGIDevice_SetGPUThreadPriority(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice_GetGPUThreadPriority:
        Decode_IDXGIDevice_GetGPUThreadPriority(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory1_EnumAdapters1:
        Decode_IDXGIFactory1_EnumAdapters1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory1_IsCurrent:
        Decode_IDXGIFactory1_IsCurrent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter1_GetDesc1:
        Decode_IDXGIAdapter1_GetDesc1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice1_SetMaximumFrameLatency:
        Decode_IDXGIDevice1_SetMaximumFrameLatency(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice1_GetMaximumFrameLatency:
        Decode_IDXGIDevice1_GetMaximumFrameLatency(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDisplayControl_IsStereoEnabled:
        Decode_IDXGIDisplayControl_IsStereoEnabled(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDisplayControl_SetStereoEnabled:
        Decode_IDXGIDisplayControl_SetStereoEnabled(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetDesc:
        Decode_IDXGIOutputDuplication_GetDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_AcquireNextFrame:
        Decode_IDXGIOutputDuplication_AcquireNextFrame(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects:
        Decode_IDXGIOutputDuplication_GetFrameDirtyRects(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameMoveRects:
        Decode_IDXGIOutputDuplication_GetFrameMoveRects(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFramePointerShape:
        Decode_IDXGIOutputDuplication_GetFramePointerShape(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_MapDesktopSurface:
        Decode_IDXGIOutputDuplication_MapDesktopSurface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface:
        Decode_IDXGIOutputDuplication_UnMapDesktopSurface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutputDuplication_ReleaseFrame:
        Decode_IDXGIOutputDuplication_ReleaseFrame(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISurface2_GetResource:
        Decode_IDXGISurface2_GetResource(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIResource1_CreateSubresourceSurface:
        Decode_IDXGIResource1_CreateSubresourceSurface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle:
        Decode_IDXGIResource1_CreateSharedHandle(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice2_OfferResources:
        Decode_IDXGIDevice2_OfferResources(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice2_ReclaimResources:
        Decode_IDXGIDevice2_ReclaimResources(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent:
        Decode_IDXGIDevice2_EnqueueSetEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetDesc1:
        Decode_IDXGISwapChain1_GetDesc1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetFullscreenDesc:
        Decode_IDXGISwapChain1_GetFullscreenDesc(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd:
        Decode_IDXGISwapChain1_GetHwnd(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetCoreWindow:
        Decode_IDXGISwapChain1_GetCoreWindow(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_Present1:
        Decode_IDXGISwapChain1_Present1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported:
        Decode_IDXGISwapChain1_IsTemporaryMonoSupported(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetRestrictToOutput:
        Decode_IDXGISwapChain1_GetRestrictToOutput(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_SetBackgroundColor:
        Decode_IDXGISwapChain1_SetBackgroundColor(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetBackgroundColor:
        Decode_IDXGISwapChain1_GetBackgroundColor(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_SetRotation:
        Decode_IDXGISwapChain1_SetRotation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain1_GetRotation:
        Decode_IDXGISwapChain1_GetRotation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_IsWindowedStereoEnabled:
        Decode_IDXGIFactory2_IsWindowedStereoEnabled(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd:
        Decode_IDXGIFactory2_CreateSwapChainForHwnd(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow:
        Decode_IDXGIFactory2_CreateSwapChainForCoreWindow(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid:
        Decode_IDXGIFactory2_GetSharedResourceAdapterLuid(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow:
        Decode_IDXGIFactory2_RegisterStereoStatusWindow(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent:
        Decode_IDXGIFactory2_RegisterStereoStatusEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterStereoStatus:
        Decode_IDXGIFactory2_UnregisterStereoStatus(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow:
        Decode_IDXGIFactory2_RegisterOcclusionStatusWindow(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent:
        Decode_IDXGIFactory2_RegisterOcclusionStatusEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterOcclusionStatus:
        Decode_IDXGIFactory2_UnregisterOcclusionStatus(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForComposition:
        Decode_IDXGIFactory2_CreateSwapChainForComposition(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter2_GetDesc2:
        Decode_IDXGIAdapter2_GetDesc2(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplayModeList1:
        Decode_IDXGIOutput1_GetDisplayModeList1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_FindClosestMatchingMode1:
        Decode_IDXGIOutput1_FindClosestMatchingMode1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplaySurfaceData1:
        Decode_IDXGIOutput1_GetDisplaySurfaceData1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput1_DuplicateOutput:
        Decode_IDXGIOutput1_DuplicateOutput(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice3_Trim:
        Decode_IDXGIDevice3_Trim(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_SetSourceSize:
        Decode_IDXGISwapChain2_SetSourceSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetSourceSize:
        Decode_IDXGISwapChain2_GetSourceSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_SetMaximumFrameLatency:
        Decode_IDXGISwapChain2_SetMaximumFrameLatency(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetMaximumFrameLatency:
        Decode_IDXGISwapChain2_GetMaximumFrameLatency(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject:
        Decode_IDXGISwapChain2_GetFrameLatencyWaitableObject(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_SetMatrixTransform:
        Decode_IDXGISwapChain2_SetMatrixTransform(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain2_GetMatrixTransform:
        Decode_IDXGISwapChain2_GetMatrixTransform(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput2_SupportsOverlays:
        Decode_IDXGIOutput2_SupportsOverlays(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory3_GetCreationFlags:
        Decode_IDXGIFactory3_GetCreationFlags(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_PresentBuffer:
        Decode_IDXGIDecodeSwapChain_PresentBuffer(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetSourceRect:
        Decode_IDXGIDecodeSwapChain_SetSourceRect(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetTargetRect:
        Decode_IDXGIDecodeSwapChain_SetTargetRect(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetDestSize:
        Decode_IDXGIDecodeSwapChain_SetDestSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetSourceRect:
        Decode_IDXGIDecodeSwapChain_GetSourceRect(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetTargetRect:
        Decode_IDXGIDecodeSwapChain_GetTargetRect(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetDestSize:
        Decode_IDXGIDecodeSwapChain_GetDestSize(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetColorSpace:
        Decode_IDXGIDecodeSwapChain_SetColorSpace(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetColorSpace:
        Decode_IDXGIDecodeSwapChain_GetColorSpace(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle:
        Decode_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle:
        Decode_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia:
        Decode_IDXGISwapChainMedia_GetFrameStatisticsMedia(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChainMedia_SetPresentDuration:
        Decode_IDXGISwapChainMedia_SetPresentDuration(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport:
        Decode_IDXGISwapChainMedia_CheckPresentDurationSupport(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput3_CheckOverlaySupport:
        Decode_IDXGIOutput3_CheckOverlaySupport(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex:
        Decode_IDXGISwapChain3_GetCurrentBackBufferIndex(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_CheckColorSpaceSupport:
        Decode_IDXGISwapChain3_CheckColorSpaceSupport(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_SetColorSpace1:
        Decode_IDXGISwapChain3_SetColorSpace1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain3_ResizeBuffers1:
        Decode_IDXGISwapChain3_ResizeBuffers1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport:
        Decode_IDXGIOutput4_CheckOverlayColorSpaceSupport(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory4_EnumAdapterByLuid:
        Decode_IDXGIFactory4_EnumAdapterByLuid(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory4_EnumWarpAdapter:
        Decode_IDXGIFactory4_EnumWarpAdapter(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent:
        Decode_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus:
        Decode_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo:
        Decode_IDXGIAdapter3_QueryVideoMemoryInfo(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_SetVideoMemoryReservation:
        Decode_IDXGIAdapter3_SetVideoMemoryReservation(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent:
        Decode_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification:
        Decode_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput5_DuplicateOutput1:
        Decode_IDXGIOutput5_DuplicateOutput1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGISwapChain4_SetHDRMetaData:
        Decode_IDXGISwapChain4_SetHDRMetaData(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice4_OfferResources1:
        Decode_IDXGIDevice4_OfferResources1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIDevice4_ReclaimResources1:
        Decode_IDXGIDevice4_ReclaimResources1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIAdapter4_GetDesc3:
        Decode_IDXGIAdapter4_GetDesc3(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput6_GetDesc1:
        Decode_IDXGIOutput6_GetDesc1(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport:
        Decode_IDXGIOutput6_CheckHardwareCompositionSupport(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference:
        Decode_IDXGIFactory6_EnumAdapterByGpuPreference(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent:
        Decode_IDXGIFactory7_RegisterAdaptersChangedEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent:
        Decode_IDXGIFactory7_UnregisterAdaptersChangedEvent(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IUnknown_QueryInterface:
        Decode_IUnknown_QueryInterface(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IUnknown_AddRef:
        Decode_IUnknown_AddRef(object_id, call_info, parameter_buffer, buffer_size);
        break;
    case format::ApiCallId::ApiCall_IUnknown_Release:
        Decode_IUnknown_Release(object_id, call_info, parameter_buffer, buffer_size);
        break;
    default:
        Dx12DecoderBase::DecodeMethodCall(call_id, object_id, call_info, parameter_buffer, buffer_size);
        break;
    }
}


size_t Dx12Decoder::Decode_D3D12SerializeRootSignature(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC> pRootSignature;
    D3D_ROOT_SIGNATURE_VERSION Version;
    HandlePointerDecoder<ID3D10Blob*> ppBlob;
    HandlePointerDecoder<ID3D10Blob*> ppErrorBlob;
    HRESULT return_value;

    bytes_read += pRootSignature.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Version);
    bytes_read += ppBlob.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppErrorBlob.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12SerializeRootSignature(call_info, return_value, &pRootSignature, Version, &ppBlob, &ppErrorBlob);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12CreateRootSignatureDeserializer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pSrcData;
    SIZE_T SrcDataSizeInBytes;
    Decoded_GUID pRootSignatureDeserializerInterface;
    GUID value_pRootSignatureDeserializerInterface;
    pRootSignatureDeserializerInterface.decoded_value = &value_pRootSignatureDeserializerInterface;
    HandlePointerDecoder<void*> ppRootSignatureDeserializer;
    HRESULT return_value;

    bytes_read += pSrcData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcDataSizeInBytes);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRootSignatureDeserializerInterface);
    bytes_read += ppRootSignatureDeserializer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12CreateRootSignatureDeserializer(call_info, return_value, &pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, &ppRootSignatureDeserializer);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12SerializeVersionedRootSignature(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC> pRootSignature;
    HandlePointerDecoder<ID3D10Blob*> ppBlob;
    HandlePointerDecoder<ID3D10Blob*> ppErrorBlob;
    HRESULT return_value;

    bytes_read += pRootSignature.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppBlob.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppErrorBlob.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12SerializeVersionedRootSignature(call_info, return_value, &pRootSignature, &ppBlob, &ppErrorBlob);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12CreateVersionedRootSignatureDeserializer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pSrcData;
    SIZE_T SrcDataSizeInBytes;
    Decoded_GUID pRootSignatureDeserializerInterface;
    GUID value_pRootSignatureDeserializerInterface;
    pRootSignatureDeserializerInterface.decoded_value = &value_pRootSignatureDeserializerInterface;
    HandlePointerDecoder<void*> ppRootSignatureDeserializer;
    HRESULT return_value;

    bytes_read += pSrcData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcDataSizeInBytes);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRootSignatureDeserializerInterface);
    bytes_read += ppRootSignatureDeserializer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12CreateVersionedRootSignatureDeserializer(call_info, return_value, &pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, &ppRootSignatureDeserializer);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pSrcData;
    SIZE_T SrcDataSizeInBytes;
    WStringDecoder RootSignatureSubobjectName;
    Decoded_GUID pRootSignatureDeserializerInterface;
    GUID value_pRootSignatureDeserializerInterface;
    pRootSignatureDeserializerInterface.decoded_value = &value_pRootSignatureDeserializerInterface;
    PointerDecoder<uint64_t, void*> ppRootSignatureDeserializer;
    HRESULT return_value;

    bytes_read += pSrcData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcDataSizeInBytes);
    bytes_read += RootSignatureSubobjectName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRootSignatureDeserializerInterface);
    bytes_read += ppRootSignatureDeserializer.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(call_info, return_value, &pSrcData, SrcDataSizeInBytes, &RootSignatureSubobjectName, pRootSignatureDeserializerInterface, &ppRootSignatureDeserializer);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12CreateDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pAdapter;
    D3D_FEATURE_LEVEL MinimumFeatureLevel;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppDevice;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pAdapter);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MinimumFeatureLevel);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12CreateDevice(call_info, return_value, pAdapter, MinimumFeatureLevel, riid, &ppDevice);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12GetDebugInterface(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvDebug;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvDebug.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12GetDebugInterface(call_info, return_value, riid, &ppvDebug);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12EnableExperimentalFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumFeatures;
    StructPointerDecoder<Decoded_GUID> pIIDs;
    PointerDecoder<uint8_t> pConfigurationStructs;
    PointerDecoder<UINT> pConfigurationStructSizes;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumFeatures);
    bytes_read += pIIDs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pConfigurationStructs.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pConfigurationStructSizes.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12EnableExperimentalFeatures(call_info, return_value, NumFeatures, &pIIDs, &pConfigurationStructs, &pConfigurationStructSizes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_D3D12GetInterface(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID rclsid;
    GUID value_rclsid;
    rclsid.decoded_value = &value_rclsid;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvDebug;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &rclsid);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvDebug.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_D3D12GetInterface(call_info, return_value, rclsid, riid, &ppvDebug);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_CreateDXGIFactory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppFactory;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppFactory.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_CreateDXGIFactory(call_info, return_value, riid, &ppFactory);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_CreateDXGIFactory1(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppFactory;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppFactory.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_CreateDXGIFactory1(call_info, return_value, riid, &ppFactory);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_CreateDXGIFactory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Flags;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppFactory;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppFactory.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_CreateDXGIFactory2(call_info, return_value, Flags, riid, &ppFactory);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_DXGIGetDebugInterface1(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Flags;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> pDebug;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += pDebug.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_DXGIGetDebugInterface1(call_info, return_value, Flags, riid, &pDebug);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_DXGIDeclareAdapterRemovalSupport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_DXGIDeclareAdapterRemovalSupport(call_info, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Object_GetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID guid;
    GUID value_guid;
    guid.decoded_value = &value_guid;
    PointerDecoder<UINT> pDataSize;
    PointerDecoder<uint8_t> pData;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &guid);
    bytes_read += pDataSize.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Object_GetPrivateData(call_info, object_id, return_value, guid, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Object_SetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID guid;
    GUID value_guid;
    guid.decoded_value = &value_guid;
    UINT DataSize;
    PointerDecoder<uint8_t> pData;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &guid);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Object_SetPrivateData(call_info, object_id, return_value, guid, DataSize, &pData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Object_SetPrivateDataInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID guid;
    GUID value_guid;
    guid.decoded_value = &value_guid;
    format::HandleId pData;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &guid);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pData);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Object_SetPrivateDataInterface(call_info, object_id, return_value, guid, pData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Object_SetName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder Name;
    HRESULT return_value;

    bytes_read += Name.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Object_SetName(call_info, object_id, return_value, &Name);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceChild_GetDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvDevice;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceChild_GetDevice(call_info, object_id, return_value, riid, &ppvDevice);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC> return_value;

    bytes_read += return_value.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(call_info, object_id, &return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D_ROOT_SIGNATURE_VERSION convertToVersion;
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC> ppDesc;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &convertToVersion);
    bytes_read += ppDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(call_info, object_id, return_value, convertToVersion, &ppDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC> return_value;

    bytes_read += return_value.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(call_info, object_id, &return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Heap_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_HEAP_DESC return_value;
    D3D12_HEAP_DESC value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Heap_GetDesc(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource_Map(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Subresource;
    StructPointerDecoder<Decoded_D3D12_RANGE> pReadRange;
    PointerDecoder<uint64_t, void*> ppData;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += pReadRange.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppData.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource_Map(call_info, object_id, return_value, Subresource, &pReadRange, &ppData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource_Unmap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Subresource;
    StructPointerDecoder<Decoded_D3D12_RANGE> pWrittenRange;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += pWrittenRange.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource_Unmap(call_info, object_id, Subresource, &pWrittenRange);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_RESOURCE_DESC return_value;
    D3D12_RESOURCE_DESC value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource_GetDesc(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource_GetGPUVirtualAddress(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_GPU_VIRTUAL_ADDRESS return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource_GetGPUVirtualAddress(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource_ReadFromSubresource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t pDstData;
    UINT DstRowPitch;
    UINT DstDepthPitch;
    UINT SrcSubresource;
    StructPointerDecoder<Decoded_D3D12_BOX> pSrcBox;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstData);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstRowPitch);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstDepthPitch);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcSubresource);
    bytes_read += pSrcBox.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource_ReadFromSubresource(call_info, object_id, return_value, pDstData, DstRowPitch, DstDepthPitch, SrcSubresource, &pSrcBox);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource_GetHeapProperties(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES> pHeapProperties;
    PointerDecoder<D3D12_HEAP_FLAGS> pHeapFlags;
    HRESULT return_value;

    bytes_read += pHeapProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHeapFlags.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource_GetHeapProperties(call_info, object_id, return_value, &pHeapProperties, &pHeapFlags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandAllocator_Reset(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandAllocator_Reset(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Fence_GetCompletedValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Fence_GetCompletedValue(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Fence_SetEventOnCompletion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 Value;
    uint64_t hEvent;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Value);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Fence_SetEventOnCompletion(call_info, object_id, return_value, Value, hEvent);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Fence_Signal(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 Value;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Value);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Fence_Signal(call_info, object_id, return_value, Value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Fence1_GetCreationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_FENCE_FLAGS return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Fence1_GetCreationFlags(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PipelineState_GetCachedBlob(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandlePointerDecoder<ID3D10Blob*> ppBlob;
    HRESULT return_value;

    bytes_read += ppBlob.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PipelineState_GetCachedBlob(call_info, object_id, return_value, &ppBlob);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DescriptorHeap_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_DESCRIPTOR_HEAP_DESC return_value;
    D3D12_DESCRIPTOR_HEAP_DESC value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DescriptorHeap_GetDesc(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE return_value;
    D3D12_CPU_DESCRIPTOR_HANDLE value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE return_value;
    D3D12_GPU_DESCRIPTOR_HANDLE value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandList_GetType(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_COMMAND_LIST_TYPE return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandList_GetType(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_Close(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_Close(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_Reset(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pAllocator;
    format::HandleId pInitialState;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pAllocator);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pInitialState);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_Reset(call_info, object_id, return_value, pAllocator, pInitialState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ClearState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pPipelineState;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pPipelineState);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ClearState(call_info, object_id, pPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_DrawInstanced(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT VertexCountPerInstance;
    UINT InstanceCount;
    UINT StartVertexLocation;
    UINT StartInstanceLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &VertexCountPerInstance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InstanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StartVertexLocation);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StartInstanceLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_DrawInstanced(call_info, object_id, VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_DrawIndexedInstanced(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT IndexCountPerInstance;
    UINT InstanceCount;
    UINT StartIndexLocation;
    INT BaseVertexLocation;
    UINT StartInstanceLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &IndexCountPerInstance);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InstanceCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StartIndexLocation);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BaseVertexLocation);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StartInstanceLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(call_info, object_id, IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_Dispatch(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT ThreadGroupCountX;
    UINT ThreadGroupCountY;
    UINT ThreadGroupCountZ;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ThreadGroupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ThreadGroupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ThreadGroupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_Dispatch(call_info, object_id, ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_CopyBufferRegion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDstBuffer;
    UINT64 DstOffset;
    format::HandleId pSrcBuffer;
    UINT64 SrcOffset;
    UINT64 NumBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pSrcBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcOffset);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumBytes);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_CopyBufferRegion(call_info, object_id, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, NumBytes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_CopyTextureRegion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION> pDst;
    UINT DstX;
    UINT DstY;
    UINT DstZ;
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION> pSrc;
    StructPointerDecoder<Decoded_D3D12_BOX> pSrcBox;

    bytes_read += pDst.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstZ);
    bytes_read += pSrc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSrcBox.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_CopyTextureRegion(call_info, object_id, &pDst, DstX, DstY, DstZ, &pSrc, &pSrcBox);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_CopyResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDstResource;
    format::HandleId pSrcResource;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstResource);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pSrcResource);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_CopyResource(call_info, object_id, pDstResource, pSrcResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_CopyTiles(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pTiledResource;
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE> pTileRegionStartCoordinate;
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE> pTileRegionSize;
    format::HandleId pBuffer;
    UINT64 BufferStartOffsetInBytes;
    D3D12_TILE_COPY_FLAGS Flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pTiledResource);
    bytes_read += pTileRegionStartCoordinate.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTileRegionSize.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferStartOffsetInBytes);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_CopyTiles(call_info, object_id, pTiledResource, &pTileRegionStartCoordinate, &pTileRegionSize, pBuffer, BufferStartOffsetInBytes, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ResolveSubresource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDstResource;
    UINT DstSubresource;
    format::HandleId pSrcResource;
    UINT SrcSubresource;
    DXGI_FORMAT Format;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstSubresource);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pSrcResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcSubresource);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Format);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ResolveSubresource(call_info, object_id, pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_IASetPrimitiveTopology(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D_PRIMITIVE_TOPOLOGY PrimitiveTopology;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &PrimitiveTopology);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(call_info, object_id, PrimitiveTopology);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_RSSetViewports(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumViewports;
    StructPointerDecoder<Decoded_D3D12_VIEWPORT> pViewports;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumViewports);
    bytes_read += pViewports.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_RSSetViewports(call_info, object_id, NumViewports, &pViewports);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_RSSetScissorRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumRects;
    StructPointerDecoder<Decoded_tagRECT> pRects;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRects);
    bytes_read += pRects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_RSSetScissorRects(call_info, object_id, NumRects, &pRects);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_OMSetBlendFactor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<FLOAT> BlendFactor;

    bytes_read += BlendFactor.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_OMSetBlendFactor(call_info, object_id, &BlendFactor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_OMSetStencilRef(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT StencilRef;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StencilRef);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_OMSetStencilRef(call_info, object_id, StencilRef);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetPipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pPipelineState;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pPipelineState);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetPipelineState(call_info, object_id, pPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ResourceBarrier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumBarriers;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER> pBarriers;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumBarriers);
    bytes_read += pBarriers.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ResourceBarrier(call_info, object_id, NumBarriers, &pBarriers);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ExecuteBundle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pCommandList;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCommandList);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ExecuteBundle(call_info, object_id, pCommandList);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetDescriptorHeaps(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumDescriptorHeaps;
    HandlePointerDecoder<ID3D12DescriptorHeap*> ppDescriptorHeaps;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumDescriptorHeaps);
    bytes_read += ppDescriptorHeaps.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(call_info, object_id, NumDescriptorHeaps, &ppDescriptorHeaps);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetComputeRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pRootSignature;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRootSignature);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetComputeRootSignature(call_info, object_id, pRootSignature);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetGraphicsRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pRootSignature;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRootSignature);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(call_info, object_id, pRootSignature);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor;
    D3D12_GPU_DESCRIPTOR_HANDLE value_BaseDescriptor;
    BaseDescriptor.decoded_value = &value_BaseDescriptor;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BaseDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(call_info, object_id, RootParameterIndex, BaseDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor;
    D3D12_GPU_DESCRIPTOR_HANDLE value_BaseDescriptor;
    BaseDescriptor.decoded_value = &value_BaseDescriptor;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BaseDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(call_info, object_id, RootParameterIndex, BaseDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    UINT SrcData;
    UINT DestOffsetIn32BitValues;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcData);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestOffsetIn32BitValues);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(call_info, object_id, RootParameterIndex, SrcData, DestOffsetIn32BitValues);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    UINT SrcData;
    UINT DestOffsetIn32BitValues;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcData);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestOffsetIn32BitValues);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(call_info, object_id, RootParameterIndex, SrcData, DestOffsetIn32BitValues);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    UINT Num32BitValuesToSet;
    PointerDecoder<uint8_t> pSrcData;
    UINT DestOffsetIn32BitValues;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Num32BitValuesToSet);
    bytes_read += pSrcData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestOffsetIn32BitValues);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(call_info, object_id, RootParameterIndex, Num32BitValuesToSet, &pSrcData, DestOffsetIn32BitValues);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    UINT Num32BitValuesToSet;
    PointerDecoder<uint8_t> pSrcData;
    UINT DestOffsetIn32BitValues;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Num32BitValuesToSet);
    bytes_read += pSrcData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestOffsetIn32BitValues);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(call_info, object_id, RootParameterIndex, Num32BitValuesToSet, &pSrcData, DestOffsetIn32BitValues);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(call_info, object_id, RootParameterIndex, BufferLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(call_info, object_id, RootParameterIndex, BufferLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(call_info, object_id, RootParameterIndex, BufferLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(call_info, object_id, RootParameterIndex, BufferLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(call_info, object_id, RootParameterIndex, BufferLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT RootParameterIndex;
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RootParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferLocation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(call_info, object_id, RootParameterIndex, BufferLocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_IASetIndexBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW> pView;

    bytes_read += pView.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_IASetIndexBuffer(call_info, object_id, &pView);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_IASetVertexBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT StartSlot;
    UINT NumViews;
    StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW> pViews;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StartSlot);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumViews);
    bytes_read += pViews.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_IASetVertexBuffers(call_info, object_id, StartSlot, NumViews, &pViews);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SOSetTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT StartSlot;
    UINT NumViews;
    StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW> pViews;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StartSlot);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumViews);
    bytes_read += pViews.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SOSetTargets(call_info, object_id, StartSlot, NumViews, &pViews);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_OMSetRenderTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumRenderTargetDescriptors;
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE> pRenderTargetDescriptors;
    BOOL RTsSingleHandleToDescriptorRange;
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE> pDepthStencilDescriptor;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRenderTargetDescriptors);
    bytes_read += pRenderTargetDescriptors.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RTsSingleHandleToDescriptorRange);
    bytes_read += pDepthStencilDescriptor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_OMSetRenderTargets(call_info, object_id, NumRenderTargetDescriptors, &pRenderTargetDescriptors, RTsSingleHandleToDescriptorRange, &pDepthStencilDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ClearDepthStencilView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DepthStencilView;
    DepthStencilView.decoded_value = &value_DepthStencilView;
    D3D12_CLEAR_FLAGS ClearFlags;
    FLOAT Depth;
    UINT8 Stencil;
    UINT NumRects;
    StructPointerDecoder<Decoded_tagRECT> pRects;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DepthStencilView);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ClearFlags);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Depth);
    bytes_read += ValueDecoder::DecodeUInt8Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Stencil);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRects);
    bytes_read += pRects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ClearDepthStencilView(call_info, object_id, DepthStencilView, ClearFlags, Depth, Stencil, NumRects, &pRects);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ClearRenderTargetView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView;
    D3D12_CPU_DESCRIPTOR_HANDLE value_RenderTargetView;
    RenderTargetView.decoded_value = &value_RenderTargetView;
    PointerDecoder<FLOAT> ColorRGBA;
    UINT NumRects;
    StructPointerDecoder<Decoded_tagRECT> pRects;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &RenderTargetView);
    bytes_read += ColorRGBA.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRects);
    bytes_read += pRects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ClearRenderTargetView(call_info, object_id, RenderTargetView, &ColorRGBA, NumRects, &pRects);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap;
    D3D12_GPU_DESCRIPTOR_HANDLE value_ViewGPUHandleInCurrentHeap;
    ViewGPUHandleInCurrentHeap.decoded_value = &value_ViewGPUHandleInCurrentHeap;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle;
    D3D12_CPU_DESCRIPTOR_HANDLE value_ViewCPUHandle;
    ViewCPUHandle.decoded_value = &value_ViewCPUHandle;
    format::HandleId pResource;
    PointerDecoder<UINT> Values;
    UINT NumRects;
    StructPointerDecoder<Decoded_tagRECT> pRects;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ViewGPUHandleInCurrentHeap);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ViewCPUHandle);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += Values.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRects);
    bytes_read += pRects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(call_info, object_id, ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, &Values, NumRects, &pRects);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap;
    D3D12_GPU_DESCRIPTOR_HANDLE value_ViewGPUHandleInCurrentHeap;
    ViewGPUHandleInCurrentHeap.decoded_value = &value_ViewGPUHandleInCurrentHeap;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle;
    D3D12_CPU_DESCRIPTOR_HANDLE value_ViewCPUHandle;
    ViewCPUHandle.decoded_value = &value_ViewCPUHandle;
    format::HandleId pResource;
    PointerDecoder<FLOAT> Values;
    UINT NumRects;
    StructPointerDecoder<Decoded_tagRECT> pRects;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ViewGPUHandleInCurrentHeap);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ViewCPUHandle);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += Values.DecodeFloat((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRects);
    bytes_read += pRects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(call_info, object_id, ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, &Values, NumRects, &pRects);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_DiscardResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    StructPointerDecoder<Decoded_D3D12_DISCARD_REGION> pRegion;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += pRegion.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_DiscardResource(call_info, object_id, pResource, &pRegion);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_BeginQuery(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pQueryHeap;
    D3D12_QUERY_TYPE Type;
    UINT Index;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pQueryHeap);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Index);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_BeginQuery(call_info, object_id, pQueryHeap, Type, Index);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_EndQuery(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pQueryHeap;
    D3D12_QUERY_TYPE Type;
    UINT Index;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pQueryHeap);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Index);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_EndQuery(call_info, object_id, pQueryHeap, Type, Index);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ResolveQueryData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pQueryHeap;
    D3D12_QUERY_TYPE Type;
    UINT StartIndex;
    UINT NumQueries;
    format::HandleId pDestinationBuffer;
    UINT64 AlignedDestinationBufferOffset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pQueryHeap);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &StartIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumQueries);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDestinationBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &AlignedDestinationBufferOffset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ResolveQueryData(call_info, object_id, pQueryHeap, Type, StartIndex, NumQueries, pDestinationBuffer, AlignedDestinationBufferOffset);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetPredication(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pBuffer;
    UINT64 AlignedBufferOffset;
    D3D12_PREDICATION_OP Operation;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &AlignedBufferOffset);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Operation);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetPredication(call_info, object_id, pBuffer, AlignedBufferOffset, Operation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_SetMarker(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Metadata;
    PointerDecoder<uint8_t> pData;
    UINT Size;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Metadata);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Size);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_SetMarker(call_info, object_id, Metadata, &pData, Size);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_BeginEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Metadata;
    PointerDecoder<uint8_t> pData;
    UINT Size;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Metadata);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Size);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_BeginEvent(call_info, object_id, Metadata, &pData, Size);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_EndEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_EndEvent(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList_ExecuteIndirect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pCommandSignature;
    UINT MaxCommandCount;
    format::HandleId pArgumentBuffer;
    UINT64 ArgumentBufferOffset;
    format::HandleId pCountBuffer;
    UINT64 CountBufferOffset;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCommandSignature);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MaxCommandCount);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pArgumentBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ArgumentBufferOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCountBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CountBufferOffset);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList_ExecuteIndirect(call_info, object_id, pCommandSignature, MaxCommandCount, pArgumentBuffer, ArgumentBufferOffset, pCountBuffer, CountBufferOffset);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDstBuffer;
    UINT64 DstOffset;
    format::HandleId pSrcBuffer;
    UINT64 SrcOffset;
    UINT Dependencies;
    HandlePointerDecoder<ID3D12Resource*> ppDependentResources;
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64> pDependentSubresourceRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pSrcBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Dependencies);
    bytes_read += ppDependentResources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDependentSubresourceRanges.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(call_info, object_id, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, &ppDependentResources, &pDependentSubresourceRanges);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDstBuffer;
    UINT64 DstOffset;
    format::HandleId pSrcBuffer;
    UINT64 SrcOffset;
    UINT Dependencies;
    HandlePointerDecoder<ID3D12Resource*> ppDependentResources;
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64> pDependentSubresourceRanges;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstOffset);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pSrcBuffer);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcOffset);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Dependencies);
    bytes_read += ppDependentResources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDependentSubresourceRanges.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(call_info, object_id, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, &ppDependentResources, &pDependentSubresourceRanges);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList1_OMSetDepthBounds(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    FLOAT Min;
    FLOAT Max;

    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Min);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Max);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(call_info, object_id, Min, Max);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList1_SetSamplePositions(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumSamplesPerPixel;
    UINT NumPixels;
    StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION> pSamplePositions;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumSamplesPerPixel);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumPixels);
    bytes_read += pSamplePositions.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList1_SetSamplePositions(call_info, object_id, NumSamplesPerPixel, NumPixels, &pSamplePositions);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDstResource;
    UINT DstSubresource;
    UINT DstX;
    UINT DstY;
    format::HandleId pSrcResource;
    UINT SrcSubresource;
    StructPointerDecoder<Decoded_tagRECT> pSrcRect;
    DXGI_FORMAT Format;
    D3D12_RESOLVE_MODE ResolveMode;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstSubresource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DstY);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pSrcResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcSubresource);
    bytes_read += pSrcRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ResolveMode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(call_info, object_id, pDstResource, DstSubresource, DstX, DstY, pSrcResource, SrcSubresource, &pSrcRect, Format, ResolveMode);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList1_SetViewInstanceMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Mask;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Mask);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(call_info, object_id, Mask);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList2_WriteBufferImmediate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Count;
    StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER> pParams;
    PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE> pModes;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Count);
    bytes_read += pParams.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pModes.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(call_info, object_id, Count, &pParams, &pModes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_UpdateTileMappings(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT NumResourceRegions;
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE> pResourceRegionStartCoordinates;
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE> pResourceRegionSizes;
    format::HandleId pHeap;
    UINT NumRanges;
    PointerDecoder<D3D12_TILE_RANGE_FLAGS> pRangeFlags;
    PointerDecoder<UINT> pHeapRangeStartOffsets;
    PointerDecoder<UINT> pRangeTileCounts;
    D3D12_TILE_MAPPING_FLAGS Flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumResourceRegions);
    bytes_read += pResourceRegionStartCoordinates.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pResourceRegionSizes.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pHeap);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRanges);
    bytes_read += pRangeFlags.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHeapRangeStartOffsets.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRangeTileCounts.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_UpdateTileMappings(call_info, object_id, pResource, NumResourceRegions, &pResourceRegionStartCoordinates, &pResourceRegionSizes, pHeap, NumRanges, &pRangeFlags, &pHeapRangeStartOffsets, &pRangeTileCounts, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_CopyTileMappings(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDstResource;
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE> pDstRegionStartCoordinate;
    format::HandleId pSrcResource;
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE> pSrcRegionStartCoordinate;
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE> pRegionSize;
    D3D12_TILE_MAPPING_FLAGS Flags;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDstResource);
    bytes_read += pDstRegionStartCoordinate.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pSrcResource);
    bytes_read += pSrcRegionStartCoordinate.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRegionSize.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_CopyTileMappings(call_info, object_id, pDstResource, &pDstRegionStartCoordinate, pSrcResource, &pSrcRegionStartCoordinate, &pRegionSize, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_ExecuteCommandLists(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumCommandLists;
    HandlePointerDecoder<ID3D12CommandList*> ppCommandLists;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumCommandLists);
    bytes_read += ppCommandLists.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_ExecuteCommandLists(call_info, object_id, NumCommandLists, &ppCommandLists);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_SetMarker(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Metadata;
    PointerDecoder<uint8_t> pData;
    UINT Size;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Metadata);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Size);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_SetMarker(call_info, object_id, Metadata, &pData, Size);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_BeginEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Metadata;
    PointerDecoder<uint8_t> pData;
    UINT Size;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Metadata);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Size);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_BeginEvent(call_info, object_id, Metadata, &pData, Size);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_EndEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_EndEvent(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_Signal(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pFence;
    UINT64 Value;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pFence);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Value);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_Signal(call_info, object_id, return_value, pFence, Value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_Wait(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pFence;
    UINT64 Value;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pFence);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Value);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_Wait(call_info, object_id, return_value, pFence, Value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_GetTimestampFrequency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT64> pFrequency;
    HRESULT return_value;

    bytes_read += pFrequency.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_GetTimestampFrequency(call_info, object_id, return_value, &pFrequency);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_GetClockCalibration(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT64> pGpuTimestamp;
    PointerDecoder<UINT64> pCpuTimestamp;
    HRESULT return_value;

    bytes_read += pGpuTimestamp.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pCpuTimestamp.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_GetClockCalibration(call_info, object_id, return_value, &pGpuTimestamp, &pCpuTimestamp);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12CommandQueue_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_COMMAND_QUEUE_DESC return_value;
    D3D12_COMMAND_QUEUE_DESC value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12CommandQueue_GetDesc(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetNodeCount(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetNodeCount(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateCommandQueue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppCommandQueue;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppCommandQueue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateCommandQueue(call_info, object_id, return_value, &pDesc, riid, &ppCommandQueue);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateCommandAllocator(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_COMMAND_LIST_TYPE type;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppCommandAllocator;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppCommandAllocator.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateCommandAllocator(call_info, object_id, return_value, type, riid, &ppCommandAllocator);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateGraphicsPipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppPipelineState;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppPipelineState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateGraphicsPipelineState(call_info, object_id, return_value, &pDesc, riid, &ppPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateComputePipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppPipelineState;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppPipelineState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateComputePipelineState(call_info, object_id, return_value, &pDesc, riid, &ppPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateCommandList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT nodeMask;
    D3D12_COMMAND_LIST_TYPE type;
    format::HandleId pCommandAllocator;
    format::HandleId pInitialState;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppCommandList;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nodeMask);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCommandAllocator);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pInitialState);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppCommandList.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateCommandList(call_info, object_id, return_value, nodeMask, type, pCommandAllocator, pInitialState, riid, &ppCommandList);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateDescriptorHeap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC> pDescriptorHeapDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvHeap;
    HRESULT return_value;

    bytes_read += pDescriptorHeapDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvHeap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateDescriptorHeap(call_info, object_id, return_value, &pDescriptorHeapDesc, riid, &ppvHeap);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetDescriptorHandleIncrementSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DescriptorHeapType);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetDescriptorHandleIncrementSize(call_info, object_id, return_value, DescriptorHeapType);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT nodeMask;
    PointerDecoder<uint8_t> pBlobWithRootSignature;
    SIZE_T blobLengthInBytes;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvRootSignature;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nodeMask);
    bytes_read += pBlobWithRootSignature.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &blobLengthInBytes);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvRootSignature.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateRootSignature(call_info, object_id, return_value, nodeMask, &pBlobWithRootSignature, blobLengthInBytes, riid, &ppvRootSignature);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateConstantBufferView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC> pDesc;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateConstantBufferView(call_info, object_id, &pDesc, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateShaderResourceView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC> pDesc;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateShaderResourceView(call_info, object_id, pResource, &pDesc, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    format::HandleId pCounterResource;
    StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC> pDesc;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pCounterResource);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateUnorderedAccessView(call_info, object_id, pResource, pCounterResource, &pDesc, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateRenderTargetView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC> pDesc;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateRenderTargetView(call_info, object_id, pResource, &pDesc, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateDepthStencilView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC> pDesc;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateDepthStencilView(call_info, object_id, pResource, &pDesc, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateSampler(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC> pDesc;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateSampler(call_info, object_id, &pDesc, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CopyDescriptors(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumDestDescriptorRanges;
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE> pDestDescriptorRangeStarts;
    PointerDecoder<UINT> pDestDescriptorRangeSizes;
    UINT NumSrcDescriptorRanges;
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE> pSrcDescriptorRangeStarts;
    PointerDecoder<UINT> pSrcDescriptorRangeSizes;
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumDestDescriptorRanges);
    bytes_read += pDestDescriptorRangeStarts.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDestDescriptorRangeSizes.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumSrcDescriptorRanges);
    bytes_read += pSrcDescriptorRangeStarts.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSrcDescriptorRangeSizes.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DescriptorHeapsType);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CopyDescriptors(call_info, object_id, NumDestDescriptorRanges, &pDestDescriptorRangeStarts, &pDestDescriptorRangeSizes, NumSrcDescriptorRanges, &pSrcDescriptorRangeStarts, &pSrcDescriptorRangeSizes, DescriptorHeapsType);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CopyDescriptorsSimple(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumDescriptors;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptorRangeStart;
    DestDescriptorRangeStart.decoded_value = &value_DestDescriptorRangeStart;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart;
    D3D12_CPU_DESCRIPTOR_HANDLE value_SrcDescriptorRangeStart;
    SrcDescriptorRangeStart.decoded_value = &value_SrcDescriptorRangeStart;
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumDescriptors);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptorRangeStart);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SrcDescriptorRangeStart);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DescriptorHeapsType);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CopyDescriptorsSimple(call_info, object_id, NumDescriptors, DestDescriptorRangeStart, SrcDescriptorRangeStart, DescriptorHeapsType);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetResourceAllocationInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT visibleMask;
    UINT numResourceDescs;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pResourceDescs;
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value;
    D3D12_RESOURCE_ALLOCATION_INFO value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visibleMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &numResourceDescs);
    bytes_read += pResourceDescs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetResourceAllocationInfo(call_info, object_id, return_value, visibleMask, numResourceDescs, &pResourceDescs);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetCustomHeapProperties(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT nodeMask;
    D3D12_HEAP_TYPE heapType;
    Decoded_D3D12_HEAP_PROPERTIES return_value;
    D3D12_HEAP_PROPERTIES value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nodeMask);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &heapType);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetCustomHeapProperties(call_info, object_id, return_value, nodeMask, heapType);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateCommittedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES> pHeapProperties;
    D3D12_HEAP_FLAGS HeapFlags;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pDesc;
    D3D12_RESOURCE_STATES InitialResourceState;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    Decoded_GUID riidResource;
    GUID value_riidResource;
    riidResource.decoded_value = &value_riidResource;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += pHeapProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &HeapFlags);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialResourceState);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riidResource);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateCommittedResource(call_info, object_id, return_value, &pHeapProperties, HeapFlags, &pDesc, InitialResourceState, &pOptimizedClearValue, riidResource, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateHeap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_HEAP_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvHeap;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvHeap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateHeap(call_info, object_id, return_value, &pDesc, riid, &ppvHeap);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreatePlacedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pHeap;
    UINT64 HeapOffset;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pDesc;
    D3D12_RESOURCE_STATES InitialState;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pHeap);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &HeapOffset);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialState);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreatePlacedResource(call_info, object_id, return_value, pHeap, HeapOffset, &pDesc, InitialState, &pOptimizedClearValue, riid, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateReservedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pDesc;
    D3D12_RESOURCE_STATES InitialState;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialState);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateReservedResource(call_info, object_id, return_value, &pDesc, InitialState, &pOptimizedClearValue, riid, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pObject;
    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES> pAttributes;
    DWORD Access;
    WStringDecoder Name;
    PointerDecoder<uint64_t, void*> pHandle;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pObject);
    bytes_read += pAttributes.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Access);
    bytes_read += Name.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateSharedHandle(call_info, object_id, return_value, pObject, &pAttributes, Access, &Name, &pHandle);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_OpenSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t NTHandle;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvObj;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NTHandle);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvObj.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_OpenSharedHandle(call_info, object_id, return_value, NTHandle, riid, &ppvObj);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_OpenSharedHandleByName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder Name;
    DWORD Access;
    PointerDecoder<uint64_t, void*> pNTHandle;
    HRESULT return_value;

    bytes_read += Name.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Access);
    bytes_read += pNTHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_OpenSharedHandleByName(call_info, object_id, return_value, &Name, Access, &pNTHandle);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_MakeResident(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumObjects;
    HandlePointerDecoder<ID3D12Pageable*> ppObjects;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumObjects);
    bytes_read += ppObjects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_MakeResident(call_info, object_id, return_value, NumObjects, &ppObjects);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_Evict(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumObjects;
    HandlePointerDecoder<ID3D12Pageable*> ppObjects;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumObjects);
    bytes_read += ppObjects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_Evict(call_info, object_id, return_value, NumObjects, &ppObjects);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateFence(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 InitialValue;
    D3D12_FENCE_FLAGS Flags;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppFence;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialValue);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppFence.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateFence(call_info, object_id, return_value, InitialValue, Flags, riid, &ppFence);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetDeviceRemovedReason(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetDeviceRemovedReason(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetCopyableFootprints(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pResourceDesc;
    UINT FirstSubresource;
    UINT NumSubresources;
    UINT64 BaseOffset;
    StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT> pLayouts;
    PointerDecoder<UINT> pNumRows;
    PointerDecoder<UINT64> pRowSizeInBytes;
    PointerDecoder<UINT64> pTotalBytes;

    bytes_read += pResourceDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FirstSubresource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumSubresources);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BaseOffset);
    bytes_read += pLayouts.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pNumRows.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRowSizeInBytes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTotalBytes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetCopyableFootprints(call_info, object_id, &pResourceDesc, FirstSubresource, NumSubresources, BaseOffset, &pLayouts, &pNumRows, &pRowSizeInBytes, &pTotalBytes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateQueryHeap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvHeap;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvHeap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateQueryHeap(call_info, object_id, return_value, &pDesc, riid, &ppvHeap);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_SetStablePowerState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Enable;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enable);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_SetStablePowerState(call_info, object_id, return_value, Enable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_CreateCommandSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC> pDesc;
    format::HandleId pRootSignature;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvCommandSignature;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRootSignature);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvCommandSignature.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_CreateCommandSignature(call_info, object_id, return_value, &pDesc, pRootSignature, riid, &ppvCommandSignature);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetResourceTiling(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pTiledResource;
    PointerDecoder<UINT> pNumTilesForEntireResource;
    StructPointerDecoder<Decoded_D3D12_PACKED_MIP_INFO> pPackedMipDesc;
    StructPointerDecoder<Decoded_D3D12_TILE_SHAPE> pStandardTileShapeForNonPackedMips;
    PointerDecoder<UINT> pNumSubresourceTilings;
    UINT FirstSubresourceTilingToGet;
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_TILING> pSubresourceTilingsForNonPackedMips;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pTiledResource);
    bytes_read += pNumTilesForEntireResource.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPackedMipDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pStandardTileShapeForNonPackedMips.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pNumSubresourceTilings.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FirstSubresourceTilingToGet);
    bytes_read += pSubresourceTilingsForNonPackedMips.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetResourceTiling(call_info, object_id, pTiledResource, &pNumTilesForEntireResource, &pPackedMipDesc, &pStandardTileShapeForNonPackedMips, &pNumSubresourceTilings, FirstSubresourceTilingToGet, &pSubresourceTilingsForNonPackedMips);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device_GetAdapterLuid(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_LUID return_value;
    LUID value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device_GetAdapterLuid(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PipelineLibrary_StorePipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pName;
    format::HandleId pPipeline;
    HRESULT return_value;

    bytes_read += pName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pPipeline);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PipelineLibrary_StorePipeline(call_info, object_id, return_value, &pName, pPipeline);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PipelineLibrary_LoadGraphicsPipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pName;
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppPipelineState;
    HRESULT return_value;

    bytes_read += pName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppPipelineState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(call_info, object_id, return_value, &pName, &pDesc, riid, &ppPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PipelineLibrary_LoadComputePipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pName;
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppPipelineState;
    HRESULT return_value;

    bytes_read += pName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppPipelineState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PipelineLibrary_LoadComputePipeline(call_info, object_id, return_value, &pName, &pDesc, riid, &ppPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PipelineLibrary_GetSerializedSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    SIZE_T return_value;

    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PipelineLibrary_GetSerializedSize(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PipelineLibrary_Serialize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pData;
    SIZE_T DataSizeInBytes;
    HRESULT return_value;

    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSizeInBytes);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PipelineLibrary_Serialize(call_info, object_id, return_value, &pData, DataSizeInBytes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PipelineLibrary1_LoadPipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pName;
    StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppPipelineState;
    HRESULT return_value;

    bytes_read += pName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppPipelineState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PipelineLibrary1_LoadPipeline(call_info, object_id, return_value, &pName, &pDesc, riid, &ppPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device1_CreatePipelineLibrary(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pLibraryBlob;
    SIZE_T BlobLength;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppPipelineLibrary;
    HRESULT return_value;

    bytes_read += pLibraryBlob.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BlobLength);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppPipelineLibrary.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device1_CreatePipelineLibrary(call_info, object_id, return_value, &pLibraryBlob, BlobLength, riid, &ppPipelineLibrary);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device1_SetEventOnMultipleFenceCompletion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandlePointerDecoder<ID3D12Fence*> ppFences;
    PointerDecoder<UINT64> pFenceValues;
    UINT NumFences;
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags;
    uint64_t hEvent;
    HRESULT return_value;

    bytes_read += ppFences.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFenceValues.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumFences);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(call_info, object_id, return_value, &ppFences, &pFenceValues, NumFences, Flags, hEvent);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device1_SetResidencyPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumObjects;
    HandlePointerDecoder<ID3D12Pageable*> ppObjects;
    PointerDecoder<D3D12_RESIDENCY_PRIORITY> pPriorities;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumObjects);
    bytes_read += ppObjects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPriorities.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device1_SetResidencyPriority(call_info, object_id, return_value, NumObjects, &ppObjects, &pPriorities);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device2_CreatePipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppPipelineState;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppPipelineState.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device2_CreatePipelineState(call_info, object_id, return_value, &pDesc, riid, &ppPipelineState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device3_OpenExistingHeapFromAddress(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t pAddress;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvHeap;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pAddress);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvHeap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device3_OpenExistingHeapFromAddress(call_info, object_id, return_value, pAddress, riid, &ppvHeap);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device3_OpenExistingHeapFromFileMapping(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hFileMapping;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvHeap;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hFileMapping);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvHeap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device3_OpenExistingHeapFromFileMapping(call_info, object_id, return_value, hFileMapping, riid, &ppvHeap);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device3_EnqueueMakeResident(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_RESIDENCY_FLAGS Flags;
    UINT NumObjects;
    HandlePointerDecoder<ID3D12Pageable*> ppObjects;
    format::HandleId pFenceToSignal;
    UINT64 FenceValueToSignal;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumObjects);
    bytes_read += ppObjects.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pFenceToSignal);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FenceValueToSignal);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device3_EnqueueMakeResident(call_info, object_id, return_value, Flags, NumObjects, &ppObjects, pFenceToSignal, FenceValueToSignal);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ProtectedSession_GetStatusFence(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppFence;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppFence.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ProtectedSession_GetStatusFence(call_info, object_id, return_value, riid, &ppFence);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ProtectedSession_GetSessionStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_PROTECTED_SESSION_STATUS return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ProtectedSession_GetSessionStatus(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ProtectedResourceSession_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value;
    D3D12_PROTECTED_RESOURCE_SESSION_DESC value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ProtectedResourceSession_GetDesc(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device4_CreateCommandList1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT nodeMask;
    D3D12_COMMAND_LIST_TYPE type;
    D3D12_COMMAND_LIST_FLAGS flags;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppCommandList;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nodeMask);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &type);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppCommandList.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device4_CreateCommandList1(call_info, object_id, return_value, nodeMask, type, flags, riid, &ppCommandList);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device4_CreateProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppSession;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppSession.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device4_CreateProtectedResourceSession(call_info, object_id, return_value, &pDesc, riid, &ppSession);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device4_CreateCommittedResource1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES> pHeapProperties;
    D3D12_HEAP_FLAGS HeapFlags;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pDesc;
    D3D12_RESOURCE_STATES InitialResourceState;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    format::HandleId pProtectedSession;
    Decoded_GUID riidResource;
    GUID value_riidResource;
    riidResource.decoded_value = &value_riidResource;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += pHeapProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &HeapFlags);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialResourceState);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pProtectedSession);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riidResource);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device4_CreateCommittedResource1(call_info, object_id, return_value, &pHeapProperties, HeapFlags, &pDesc, InitialResourceState, &pOptimizedClearValue, pProtectedSession, riidResource, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device4_CreateHeap1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_HEAP_DESC> pDesc;
    format::HandleId pProtectedSession;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvHeap;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pProtectedSession);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvHeap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device4_CreateHeap1(call_info, object_id, return_value, &pDesc, pProtectedSession, riid, &ppvHeap);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device4_CreateReservedResource1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pDesc;
    D3D12_RESOURCE_STATES InitialState;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    format::HandleId pProtectedSession;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialState);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pProtectedSession);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device4_CreateReservedResource1(call_info, object_id, return_value, &pDesc, InitialState, &pOptimizedClearValue, pProtectedSession, riid, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device4_GetResourceAllocationInfo1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT visibleMask;
    UINT numResourceDescs;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pResourceDescs;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1> pResourceAllocationInfo1;
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value;
    D3D12_RESOURCE_ALLOCATION_INFO value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visibleMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &numResourceDescs);
    bytes_read += pResourceDescs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pResourceAllocationInfo1.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device4_GetResourceAllocationInfo1(call_info, object_id, return_value, visibleMask, numResourceDescs, &pResourceDescs, &pResourceAllocationInfo1);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12LifetimeOwner_LifetimeStateUpdated(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_LIFETIME_STATE NewState;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NewState);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12LifetimeOwner_LifetimeStateUpdated(call_info, object_id, NewState);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SwapChainAssistant_GetLUID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_LUID return_value;
    LUID value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SwapChainAssistant_GetLUID(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SwapChainAssistant_GetSwapChainObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppv;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppv.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SwapChainAssistant_GetSwapChainObject(call_info, object_id, return_value, riid, &ppv);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riidResource;
    GUID value_riidResource;
    riidResource.decoded_value = &value_riidResource;
    HandlePointerDecoder<void*> ppvResource;
    Decoded_GUID riidQueue;
    GUID value_riidQueue;
    riidQueue.decoded_value = &value_riidQueue;
    HandlePointerDecoder<void*> ppvQueue;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riidResource);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riidQueue);
    bytes_read += ppvQueue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(call_info, object_id, return_value, riidResource, &ppvResource, riidQueue, &ppvQueue);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SwapChainAssistant_InsertImplicitSync(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SwapChainAssistant_InsertImplicitSync(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12LifetimeTracker_DestroyOwnedObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pObject;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pObject);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12LifetimeTracker_DestroyOwnedObject(call_info, object_id, return_value, pObject);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12StateObjectProperties_GetShaderIdentifier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pExportName;
    PointerDecoder<uint8_t> return_value;

    bytes_read += pExportName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += return_value.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12StateObjectProperties_GetShaderIdentifier(call_info, object_id, &return_value, &pExportName);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12StateObjectProperties_GetShaderStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pExportName;
    UINT64 return_value;

    bytes_read += pExportName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12StateObjectProperties_GetShaderStackSize(call_info, object_id, return_value, &pExportName);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12StateObjectProperties_GetPipelineStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12StateObjectProperties_GetPipelineStackSize(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12StateObjectProperties_SetPipelineStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 PipelineStackSizeInBytes;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &PipelineStackSizeInBytes);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12StateObjectProperties_SetPipelineStackSize(call_info, object_id, PipelineStackSizeInBytes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12StateObjectProperties1_GetProgramIdentifier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pProgramName;
    Decoded_D3D12_PROGRAM_IDENTIFIER return_value;
    D3D12_PROGRAM_IDENTIFIER value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += pProgramName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12StateObjectProperties1_GetProgramIdentifier(call_info, object_id, return_value, &pProgramName);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetNumWorkGraphs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetNumWorkGraphs(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetProgramName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    WStringDecoder return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += return_value.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetProgramName(call_info, object_id, &return_value, WorkGraphIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetWorkGraphIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    WStringDecoder pProgramName;
    UINT return_value;

    bytes_read += pProgramName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetWorkGraphIndex(call_info, object_id, return_value, &pProgramName);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetNumNodes(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetNumNodes(call_info, object_id, return_value, WorkGraphIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetNodeID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    UINT NodeIndex;
    Decoded_D3D12_NODE_ID return_value;
    D3D12_NODE_ID value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeIndex);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetNodeID(call_info, object_id, return_value, WorkGraphIndex, NodeIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetNodeIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    Decoded_D3D12_NODE_ID NodeID;
    D3D12_NODE_ID value_NodeID;
    NodeID.decoded_value = &value_NodeID;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeID);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetNodeIndex(call_info, object_id, return_value, WorkGraphIndex, NodeID);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    UINT NodeIndex;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex(call_info, object_id, return_value, WorkGraphIndex, NodeIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetNumEntrypoints(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetNumEntrypoints(call_info, object_id, return_value, WorkGraphIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetEntrypointID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    UINT EntrypointIndex;
    Decoded_D3D12_NODE_ID return_value;
    D3D12_NODE_ID value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &EntrypointIndex);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetEntrypointID(call_info, object_id, return_value, WorkGraphIndex, EntrypointIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetEntrypointIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    Decoded_D3D12_NODE_ID NodeID;
    D3D12_NODE_ID value_NodeID;
    NodeID.decoded_value = &value_NodeID;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeID);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetEntrypointIndex(call_info, object_id, return_value, WorkGraphIndex, NodeID);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    UINT EntrypointIndex;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &EntrypointIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes(call_info, object_id, return_value, WorkGraphIndex, EntrypointIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    StructPointerDecoder<Decoded_D3D12_WORK_GRAPH_MEMORY_REQUIREMENTS> pWorkGraphMemoryRequirements;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += pWorkGraphMemoryRequirements.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements(call_info, object_id, WorkGraphIndex, &pWorkGraphMemoryRequirements);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT WorkGraphIndex;
    UINT EntrypointIndex;
    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WorkGraphIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &EntrypointIndex);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes(call_info, object_id, return_value, WorkGraphIndex, EntrypointIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_CreateLifetimeTracker(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pOwner;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvTracker;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pOwner);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvTracker.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_CreateLifetimeTracker(call_info, object_id, return_value, pOwner, riid, &ppvTracker);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_RemoveDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_RemoveDevice(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_EnumerateMetaCommands(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pNumMetaCommands;
    StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC> pDescs;
    HRESULT return_value;

    bytes_read += pNumMetaCommands.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDescs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_EnumerateMetaCommands(call_info, object_id, return_value, &pNumMetaCommands, &pDescs);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_EnumerateMetaCommandParameters(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID CommandId;
    GUID value_CommandId;
    CommandId.decoded_value = &value_CommandId;
    D3D12_META_COMMAND_PARAMETER_STAGE Stage;
    PointerDecoder<UINT> pTotalStructureSizeInBytes;
    PointerDecoder<UINT> pParameterCount;
    StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC> pParameterDescs;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CommandId);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Stage);
    bytes_read += pTotalStructureSizeInBytes.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pParameterCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pParameterDescs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_EnumerateMetaCommandParameters(call_info, object_id, return_value, CommandId, Stage, &pTotalStructureSizeInBytes, &pParameterCount, &pParameterDescs);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_CreateMetaCommand(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID CommandId;
    GUID value_CommandId;
    CommandId.decoded_value = &value_CommandId;
    UINT NodeMask;
    PointerDecoder<uint8_t> pCreationParametersData;
    SIZE_T CreationParametersDataSizeInBytes;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppMetaCommand;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CommandId);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeMask);
    bytes_read += pCreationParametersData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CreationParametersDataSizeInBytes);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppMetaCommand.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_CreateMetaCommand(call_info, object_id, return_value, CommandId, NodeMask, &pCreationParametersData, CreationParametersDataSizeInBytes, riid, &ppMetaCommand);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_CreateStateObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppStateObject;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppStateObject.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_CreateStateObject(call_info, object_id, return_value, &pDesc, riid, &ppStateObject);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS> pDesc;
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO> pInfo;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(call_info, object_id, &pDesc, &pInfo);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device5_CheckDriverMatchingIdentifier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_SERIALIZED_DATA_TYPE SerializedDataType;
    StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER> pIdentifierToCheck;
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SerializedDataType);
    bytes_read += pIdentifierToCheck.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device5_CheckDriverMatchingIdentifier(call_info, object_id, return_value, SerializedDataType, &pIdentifierToCheck);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DRED_ENABLEMENT Enablement;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enablement);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(call_info, object_id, Enablement);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DRED_ENABLEMENT Enablement;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enablement);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(call_info, object_id, Enablement);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DRED_ENABLEMENT Enablement;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enablement);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(call_info, object_id, Enablement);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DRED_ENABLEMENT Enablement;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enablement);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(call_info, object_id, Enablement);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL MarkersOnly;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MarkersOnly);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(call_info, object_id, MarkersOnly);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT> pOutput;
    HRESULT return_value;

    bytes_read += pOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(call_info, object_id, return_value, &pOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT> pOutput;
    HRESULT return_value;

    bytes_read += pOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(call_info, object_id, return_value, &pOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1> pOutput;
    HRESULT return_value;

    bytes_read += pOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(call_info, object_id, return_value, &pOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1> pOutput;
    HRESULT return_value;

    bytes_read += pOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(call_info, object_id, return_value, &pOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2> pOutput;
    HRESULT return_value;

    bytes_read += pOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(call_info, object_id, return_value, &pOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceRemovedExtendedData2_GetDeviceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DRED_DEVICE_STATE return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceRemovedExtendedData2_GetDeviceState(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device6_SetBackgroundProcessingMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_BACKGROUND_PROCESSING_MODE Mode;
    D3D12_MEASUREMENTS_ACTION MeasurementsAction;
    uint64_t hEventToSignalUponCompletion;
    PointerDecoder<BOOL> pbFurtherMeasurementsDesired;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Mode);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MeasurementsAction);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEventToSignalUponCompletion);
    bytes_read += pbFurtherMeasurementsDesired.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device6_SetBackgroundProcessingMode(call_info, object_id, return_value, Mode, MeasurementsAction, hEventToSignalUponCompletion, &pbFurtherMeasurementsDesired);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ProtectedResourceSession1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value;
    D3D12_PROTECTED_RESOURCE_SESSION_DESC1 value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ProtectedResourceSession1_GetDesc1(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device7_AddToStateObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC> pAddition;
    format::HandleId pStateObjectToGrowFrom;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppNewStateObject;
    HRESULT return_value;

    bytes_read += pAddition.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pStateObjectToGrowFrom);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppNewStateObject.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device7_AddToStateObject(call_info, object_id, return_value, &pAddition, pStateObjectToGrowFrom, riid, &ppNewStateObject);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device7_CreateProtectedResourceSession1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppSession;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppSession.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device7_CreateProtectedResourceSession1(call_info, object_id, return_value, &pDesc, riid, &ppSession);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device8_GetResourceAllocationInfo2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT visibleMask;
    UINT numResourceDescs;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1> pResourceDescs;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1> pResourceAllocationInfo1;
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value;
    D3D12_RESOURCE_ALLOCATION_INFO value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visibleMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &numResourceDescs);
    bytes_read += pResourceDescs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pResourceAllocationInfo1.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device8_GetResourceAllocationInfo2(call_info, object_id, return_value, visibleMask, numResourceDescs, &pResourceDescs, &pResourceAllocationInfo1);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device8_CreateCommittedResource2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES> pHeapProperties;
    D3D12_HEAP_FLAGS HeapFlags;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1> pDesc;
    D3D12_RESOURCE_STATES InitialResourceState;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    format::HandleId pProtectedSession;
    Decoded_GUID riidResource;
    GUID value_riidResource;
    riidResource.decoded_value = &value_riidResource;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += pHeapProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &HeapFlags);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialResourceState);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pProtectedSession);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riidResource);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device8_CreateCommittedResource2(call_info, object_id, return_value, &pHeapProperties, HeapFlags, &pDesc, InitialResourceState, &pOptimizedClearValue, pProtectedSession, riidResource, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device8_CreatePlacedResource1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pHeap;
    UINT64 HeapOffset;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1> pDesc;
    D3D12_RESOURCE_STATES InitialState;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pHeap);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &HeapOffset);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialState);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device8_CreatePlacedResource1(call_info, object_id, return_value, pHeap, HeapOffset, &pDesc, InitialState, &pOptimizedClearValue, riid, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pTargetedResource;
    format::HandleId pFeedbackResource;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pTargetedResource);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pFeedbackResource);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(call_info, object_id, pTargetedResource, pFeedbackResource, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device8_GetCopyableFootprints1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1> pResourceDesc;
    UINT FirstSubresource;
    UINT NumSubresources;
    UINT64 BaseOffset;
    StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT> pLayouts;
    PointerDecoder<UINT> pNumRows;
    PointerDecoder<UINT64> pRowSizeInBytes;
    PointerDecoder<UINT64> pTotalBytes;

    bytes_read += pResourceDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FirstSubresource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumSubresources);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BaseOffset);
    bytes_read += pLayouts.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pNumRows.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pRowSizeInBytes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pTotalBytes.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device8_GetCopyableFootprints1(call_info, object_id, &pResourceDesc, FirstSubresource, NumSubresources, BaseOffset, &pLayouts, &pNumRows, &pRowSizeInBytes, &pTotalBytes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource1_GetProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppProtectedSession;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppProtectedSession.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource1_GetProtectedResourceSession(call_info, object_id, return_value, riid, &ppProtectedSession);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Resource2_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_RESOURCE_DESC1 return_value;
    D3D12_RESOURCE_DESC1 value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Resource2_GetDesc1(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Heap1_GetProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppProtectedSession;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppProtectedSession.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Heap1_GetProtectedResourceSession(call_info, object_id, return_value, riid, &ppProtectedSession);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList3_SetProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pProtectedResourceSession;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pProtectedResourceSession);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(call_info, object_id, pProtectedResourceSession);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12MetaCommand_GetRequiredParameterResourceSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_META_COMMAND_PARAMETER_STAGE Stage;
    UINT ParameterIndex;
    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Stage);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ParameterIndex);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(call_info, object_id, return_value, Stage, ParameterIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_BeginRenderPass(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumRenderTargets;
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC> pRenderTargets;
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC> pDepthStencil;
    D3D12_RENDER_PASS_FLAGS Flags;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumRenderTargets);
    bytes_read += pRenderTargets.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDepthStencil.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_BeginRenderPass(call_info, object_id, NumRenderTargets, &pRenderTargets, &pDepthStencil, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_EndRenderPass(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_EndRenderPass(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_InitializeMetaCommand(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pMetaCommand;
    PointerDecoder<uint8_t> pInitializationParametersData;
    SIZE_T InitializationParametersDataSizeInBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pMetaCommand);
    bytes_read += pInitializationParametersData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitializationParametersDataSizeInBytes);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(call_info, object_id, pMetaCommand, &pInitializationParametersData, InitializationParametersDataSizeInBytes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_ExecuteMetaCommand(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pMetaCommand;
    PointerDecoder<uint8_t> pExecutionParametersData;
    SIZE_T ExecutionParametersDataSizeInBytes;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pMetaCommand);
    bytes_read += pExecutionParametersData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ExecutionParametersDataSizeInBytes);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(call_info, object_id, pMetaCommand, &pExecutionParametersData, ExecutionParametersDataSizeInBytes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC> pDesc;
    UINT NumPostbuildInfoDescs;
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC> pPostbuildInfoDescs;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumPostbuildInfoDescs);
    bytes_read += pPostbuildInfoDescs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(call_info, object_id, &pDesc, NumPostbuildInfoDescs, &pPostbuildInfoDescs);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC> pDesc;
    UINT NumSourceAccelerationStructures;
    PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS> pSourceAccelerationStructureData;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumSourceAccelerationStructures);
    bytes_read += pSourceAccelerationStructureData.DecodeUInt64((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(call_info, object_id, &pDesc, NumSourceAccelerationStructures, &pSourceAccelerationStructureData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData;
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData;
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestAccelerationStructureData);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SourceAccelerationStructureData);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Mode);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(call_info, object_id, DestAccelerationStructureData, SourceAccelerationStructureData, Mode);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_SetPipelineState1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pStateObject;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pStateObject);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_SetPipelineState1(call_info, object_id, pStateObject);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList4_DispatchRays(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC> pDesc;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList4_DispatchRays(call_info, object_id, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ShaderCacheSession_FindValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pKey;
    UINT KeySize;
    PointerDecoder<uint8_t> pValue;
    PointerDecoder<UINT> pValueSize;
    HRESULT return_value;

    bytes_read += pKey.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &KeySize);
    bytes_read += pValue.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pValueSize.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ShaderCacheSession_FindValue(call_info, object_id, return_value, &pKey, KeySize, &pValue, &pValueSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ShaderCacheSession_StoreValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pKey;
    UINT KeySize;
    PointerDecoder<uint8_t> pValue;
    UINT ValueSize;
    HRESULT return_value;

    bytes_read += pKey.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &KeySize);
    bytes_read += pValue.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ValueSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ShaderCacheSession_StoreValue(call_info, object_id, return_value, &pKey, KeySize, &pValue, ValueSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ShaderCacheSession_SetDeleteOnDestroy(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ShaderCacheSession_SetDeleteOnDestroy(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ShaderCacheSession_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_SHADER_CACHE_SESSION_DESC return_value;
    D3D12_SHADER_CACHE_SESSION_DESC value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ShaderCacheSession_GetDesc(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device9_CreateShaderCacheSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_SHADER_CACHE_SESSION_DESC> pDesc;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvSession;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvSession.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device9_CreateShaderCacheSession(call_info, object_id, return_value, &pDesc, riid, &ppvSession);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device9_ShaderCacheControl(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_SHADER_CACHE_KIND_FLAGS Kinds;
    D3D12_SHADER_CACHE_CONTROL_FLAGS Control;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Kinds);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Control);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device9_ShaderCacheControl(call_info, object_id, return_value, Kinds, Control);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device9_CreateCommandQueue1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC> pDesc;
    Decoded_GUID CreatorID;
    GUID value_CreatorID;
    CreatorID.decoded_value = &value_CreatorID;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppCommandQueue;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CreatorID);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppCommandQueue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device9_CreateCommandQueue1(call_info, object_id, return_value, &pDesc, CreatorID, riid, &ppCommandQueue);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device10_CreateCommittedResource3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES> pHeapProperties;
    D3D12_HEAP_FLAGS HeapFlags;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1> pDesc;
    D3D12_BARRIER_LAYOUT InitialLayout;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    format::HandleId pProtectedSession;
    UINT32 NumCastableFormats;
    PointerDecoder<DXGI_FORMAT> pCastableFormats;
    Decoded_GUID riidResource;
    GUID value_riidResource;
    riidResource.decoded_value = &value_riidResource;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += pHeapProperties.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &HeapFlags);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialLayout);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pProtectedSession);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumCastableFormats);
    bytes_read += pCastableFormats.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riidResource);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device10_CreateCommittedResource3(call_info, object_id, return_value, &pHeapProperties, HeapFlags, &pDesc, InitialLayout, &pOptimizedClearValue, pProtectedSession, NumCastableFormats, &pCastableFormats, riidResource, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device10_CreatePlacedResource2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pHeap;
    UINT64 HeapOffset;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1> pDesc;
    D3D12_BARRIER_LAYOUT InitialLayout;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    UINT32 NumCastableFormats;
    PointerDecoder<DXGI_FORMAT> pCastableFormats;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pHeap);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &HeapOffset);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialLayout);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumCastableFormats);
    bytes_read += pCastableFormats.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device10_CreatePlacedResource2(call_info, object_id, return_value, pHeap, HeapOffset, &pDesc, InitialLayout, &pOptimizedClearValue, NumCastableFormats, &pCastableFormats, riid, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device10_CreateReservedResource2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pDesc;
    D3D12_BARRIER_LAYOUT InitialLayout;
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE> pOptimizedClearValue;
    format::HandleId pProtectedSession;
    UINT32 NumCastableFormats;
    PointerDecoder<DXGI_FORMAT> pCastableFormats;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvResource;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InitialLayout);
    bytes_read += pOptimizedClearValue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pProtectedSession);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumCastableFormats);
    bytes_read += pCastableFormats.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device10_CreateReservedResource2(call_info, object_id, return_value, &pDesc, InitialLayout, &pOptimizedClearValue, pProtectedSession, NumCastableFormats, &pCastableFormats, riid, &ppvResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device11_CreateSampler2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC2> pDesc;
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor;
    D3D12_CPU_DESCRIPTOR_HANDLE value_DestDescriptor;
    DestDescriptor.decoded_value = &value_DestDescriptor;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DestDescriptor);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device11_CreateSampler2(call_info, object_id, &pDesc, DestDescriptor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device12_GetResourceAllocationInfo3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT visibleMask;
    UINT numResourceDescs;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1> pResourceDescs;
    PointerDecoder<UINT32> pNumCastableFormats;
    PointerDecoder<DXGI_FORMAT*> ppCastableFormats;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1> pResourceAllocationInfo1;
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO return_value;
    D3D12_RESOURCE_ALLOCATION_INFO value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &visibleMask);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &numResourceDescs);
    bytes_read += pResourceDescs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pNumCastableFormats.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppCastableFormats.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pResourceAllocationInfo1.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device12_GetResourceAllocationInfo3(call_info, object_id, return_value, visibleMask, numResourceDescs, &pResourceDescs, &pNumCastableFormats, &ppCastableFormats, &pResourceAllocationInfo1);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device13_OpenExistingHeapFromAddress1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t pAddress;
    SIZE_T size;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvHeap;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pAddress);
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &size);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvHeap.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device13_OpenExistingHeapFromAddress1(call_info, object_id, return_value, pAddress, size, riid, &ppvHeap);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT nodeMask;
    PointerDecoder<uint8_t> pLibraryBlob;
    SIZE_T blobLengthInBytes;
    WStringDecoder subobjectName;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvRootSignature;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nodeMask);
    bytes_read += pLibraryBlob.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &blobLengthInBytes);
    bytes_read += subobjectName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvRootSignature.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary(call_info, object_id, return_value, nodeMask, &pLibraryBlob, blobLengthInBytes, &subobjectName, riid, &ppvRootSignature);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12VirtualizationGuestDevice_ShareWithHost(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pObject;
    PointerDecoder<uint64_t, void*> pHandle;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pObject);
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12VirtualizationGuestDevice_ShareWithHost(call_info, object_id, return_value, pObject, &pHandle);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12VirtualizationGuestDevice_CreateFenceFd(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pFence;
    UINT64 FenceValue;
    PointerDecoder<int> pFenceFd;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pFence);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FenceValue);
    bytes_read += pFenceFd.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12VirtualizationGuestDevice_CreateFenceFd(call_info, object_id, return_value, pFence, FenceValue, &pFenceFd);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Tools_EnableShaderInstrumentation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL bEnable;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bEnable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Tools_EnableShaderInstrumentation(call_info, object_id, bEnable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Tools_ShaderInstrumentationEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Tools_ShaderInstrumentationEnabled(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Tools1_ReserveGPUVARangesAtCreate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE> pRanges;
    UINT uiNumRanges;
    HRESULT return_value;

    bytes_read += pRanges.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &uiNumRanges);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Tools1_ReserveGPUVARangesAtCreate(call_info, object_id, return_value, &pRanges, uiNumRanges);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Tools1_ClearReservedGPUVARangesList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Tools1_ClearReservedGPUVARangesList(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Tools2_SetApplicationSpecificDriverState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pAdapter;
    format::HandleId pBlob;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pAdapter);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pBlob);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Tools2_SetApplicationSpecificDriverState(call_info, object_id, return_value, pAdapter, pBlob);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12PageableTools_GetAllocation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_GPU_VIRTUAL_ADDRESS_RANGE> pAllocation;
    HRESULT return_value;

    bytes_read += pAllocation.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12PageableTools_GetAllocation(call_info, object_id, return_value, &pAllocation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceTools_SetNextAllocationAddress(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_GPU_VIRTUAL_ADDRESS nextAllocationVirtualAddress;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &nextAllocationVirtualAddress);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceTools_SetNextAllocationAddress(call_info, object_id, nextAllocationVirtualAddress);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceTools1_GetApplicationSpecificDriverState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandlePointerDecoder<ID3D10Blob*> ppBlob;
    HRESULT return_value;

    bytes_read += ppBlob.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceTools1_GetApplicationSpecificDriverState(call_info, object_id, return_value, &ppBlob);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceTools1_GetApplicationSpecificDriverBlobStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_APPLICATION_SPECIFIC_DRIVER_BLOB_STATUS return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceTools1_GetApplicationSpecificDriverBlobStatus(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SDKConfiguration_SetSDKVersion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT SDKVersion;
    StringDecoder SDKPath;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SDKVersion);
    bytes_read += SDKPath.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SDKConfiguration_SetSDKVersion(call_info, object_id, return_value, SDKVersion, &SDKPath);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SDKConfiguration1_CreateDeviceFactory(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT SDKVersion;
    StringDecoder SDKPath;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvFactory;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SDKVersion);
    bytes_read += SDKPath.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvFactory.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SDKConfiguration1_CreateDeviceFactory(call_info, object_id, return_value, SDKVersion, &SDKPath, riid, &ppvFactory);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SDKConfiguration1_FreeUnusedSDKs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SDKConfiguration1_FreeUnusedSDKs(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceFactory_InitializeFromGlobalState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceFactory_InitializeFromGlobalState(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceFactory_ApplyToGlobalState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceFactory_ApplyToGlobalState(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceFactory_SetFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEVICE_FACTORY_FLAGS flags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &flags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceFactory_SetFlags(call_info, object_id, return_value, flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceFactory_GetFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEVICE_FACTORY_FLAGS return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceFactory_GetFlags(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceFactory_GetConfigurationInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID clsid;
    GUID value_clsid;
    clsid.decoded_value = &value_clsid;
    Decoded_GUID iid;
    GUID value_iid;
    iid.decoded_value = &value_iid;
    HandlePointerDecoder<void*> ppv;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &clsid);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &iid);
    bytes_read += ppv.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceFactory_GetConfigurationInterface(call_info, object_id, return_value, clsid, iid, &ppv);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceFactory_EnableExperimentalFeatures(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumFeatures;
    StructPointerDecoder<Decoded_GUID> pIIDs;
    PointerDecoder<uint8_t> pConfigurationStructs;
    PointerDecoder<UINT> pConfigurationStructSizes;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumFeatures);
    bytes_read += pIIDs.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pConfigurationStructs.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pConfigurationStructSizes.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceFactory_EnableExperimentalFeatures(call_info, object_id, return_value, NumFeatures, &pIIDs, &pConfigurationStructs, &pConfigurationStructSizes);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceFactory_CreateDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId adapter;
    D3D_FEATURE_LEVEL FeatureLevel;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvDevice;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &adapter);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FeatureLevel);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceFactory_CreateDevice(call_info, object_id, return_value, adapter, FeatureLevel, riid, &ppvDevice);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceConfiguration_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_D3D12_DEVICE_CONFIGURATION_DESC return_value;
    D3D12_DEVICE_CONFIGURATION_DESC value_returned;
    return_value.decoded_value = &value_returned;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceConfiguration_GetDesc(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_GUID> pGuids;
    UINT NumGuids;
    HRESULT return_value;

    bytes_read += pGuids.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumGuids);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(call_info, object_id, return_value, &pGuids, NumGuids);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC> pDesc;
    HandlePointerDecoder<ID3D10Blob*> ppResult;
    HandlePointerDecoder<ID3D10Blob*> ppError;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppResult.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppError.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(call_info, object_id, return_value, &pDesc, &ppResult, &ppError);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pBlob;
    SIZE_T Size;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvDeserializer;
    HRESULT return_value;

    bytes_read += pBlob.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Size);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvDeserializer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(call_info, object_id, return_value, &pBlob, Size, riid, &ppvDeserializer);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint8_t> pLibraryBlob;
    SIZE_T Size;
    WStringDecoder RootSignatureSubobjectName;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvDeserializer;
    HRESULT return_value;

    bytes_read += pLibraryBlob.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Size);
    bytes_read += RootSignatureSubobjectName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvDeserializer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(call_info, object_id, return_value, &pLibraryBlob, Size, &RootSignatureSubobjectName, riid, &ppvDeserializer);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList5_RSSetShadingRate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_SHADING_RATE baseShadingRate;
    PointerDecoder<D3D12_SHADING_RATE_COMBINER> combiners;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &baseShadingRate);
    bytes_read += combiners.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList5_RSSetShadingRate(call_info, object_id, baseShadingRate, &combiners);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList5_RSSetShadingRateImage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId shadingRateImage;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &shadingRateImage);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(call_info, object_id, shadingRateImage);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList6_DispatchMesh(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT ThreadGroupCountX;
    UINT ThreadGroupCountY;
    UINT ThreadGroupCountZ;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ThreadGroupCountX);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ThreadGroupCountY);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ThreadGroupCountZ);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList6_DispatchMesh(call_info, object_id, ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList7_Barrier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT32 NumBarrierGroups;
    StructPointerDecoder<Decoded_D3D12_BARRIER_GROUP> pBarrierGroups;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumBarrierGroups);
    bytes_read += pBarrierGroups.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList7_Barrier(call_info, object_id, NumBarrierGroups, &pBarrierGroups);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT FrontStencilRef;
    UINT BackStencilRef;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FrontStencilRef);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BackStencilRef);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(call_info, object_id, FrontStencilRef, BackStencilRef);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList9_RSSetDepthBias(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    FLOAT DepthBias;
    FLOAT DepthBiasClamp;
    FLOAT SlopeScaledDepthBias;

    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DepthBias);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DepthBiasClamp);
    bytes_read += ValueDecoder::DecodeFloatValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SlopeScaledDepthBias);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList9_RSSetDepthBias(call_info, object_id, DepthBias, DepthBiasClamp, SlopeScaledDepthBias);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &IBStripCutValue);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(call_info, object_id, IBStripCutValue);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList10_SetProgram(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_SET_PROGRAM_DESC> pDesc;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList10_SetProgram(call_info, object_id, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GraphicsCommandList10_DispatchGraph(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_DISPATCH_GRAPH_DESC> pDesc;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GraphicsCommandList10_DispatchGraph(call_info, object_id, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DSRDeviceFactory_CreateDSRDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pD3D12Device;
    UINT NodeMask;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvDSRDevice;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pD3D12Device);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeMask);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvDSRDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DSRDeviceFactory_CreateDSRDevice(call_info, object_id, return_value, pD3D12Device, NodeMask, riid, &ppvDSRDevice);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    PointerDecoder<int> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += pData.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData(call_info, object_id, return_value, pResource, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GBVDiagnostics_GetGBVSubresourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    PointerDecoder<int> pData;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += pData.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GBVDiagnostics_GetGBVSubresourceState(call_info, object_id, return_value, pResource, Subresource, &pData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GBVDiagnostics_GetGBVResourceUniformState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    PointerDecoder<int> pData;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += pData.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GBVDiagnostics_GetGBVResourceUniformState(call_info, object_id, return_value, pResource, &pData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GBVDiagnostics_GetGBVResourceInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC> pResourceDesc;
    PointerDecoder<UINT32> pResourceHash;
    PointerDecoder<UINT32> pSubresourceStatesByteOffset;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += pResourceDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pResourceHash.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubresourceStatesByteOffset.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GBVDiagnostics_GetGBVResourceInfo(call_info, object_id, return_value, pResource, &pResourceDesc, &pResourceHash, &pSubresourceStatesByteOffset);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GBVDiagnostics_GBVReserved0(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GBVDiagnostics_GBVReserved0(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12GBVDiagnostics_GBVReserved1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12GBVDiagnostics_GBVReserved1(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D10Blob_GetBufferPointer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D10Blob_GetBufferPointer(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D10Blob_GetBufferSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    SIZE_T return_value;

    bytes_read += ValueDecoder::DecodeSizeTValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D10Blob_GetBufferSize(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3DDestructionNotifier_RegisterDestructionCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t callbackFn;
    uint64_t pData;
    PointerDecoder<UINT> pCallbackID;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callbackFn);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pData);
    bytes_read += pCallbackID.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3DDestructionNotifier_RegisterDestructionCallback(call_info, object_id, return_value, callbackFn, pData, &pCallbackID);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3DDestructionNotifier_UnregisterDestructionCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT callbackID;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &callbackID);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3DDestructionNotifier_UnregisterDestructionCallback(call_info, object_id, return_value, callbackID);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug_EnableDebugLayer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug_EnableDebugLayer(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug1_EnableDebugLayer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug1_EnableDebugLayer(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug1_SetEnableGPUBasedValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Enable;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug1_SetEnableGPUBasedValidation(call_info, object_id, Enable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Enable;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(call_info, object_id, Enable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug2_SetGPUBasedValidationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_GPU_BASED_VALIDATION_FLAGS Flags;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug2_SetGPUBasedValidationFlags(call_info, object_id, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug3_SetEnableGPUBasedValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Enable;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug3_SetEnableGPUBasedValidation(call_info, object_id, Enable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Enable;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(call_info, object_id, Enable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug3_SetGPUBasedValidationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_GPU_BASED_VALIDATION_FLAGS Flags;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug3_SetGPUBasedValidationFlags(call_info, object_id, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug4_DisableDebugLayer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug4_DisableDebugLayer(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug5_SetEnableAutoName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Enable;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug5_SetEnableAutoName(call_info, object_id, Enable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12Debug6_SetForceLegacyBarrierValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Enable;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Enable);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12Debug6_SetForceLegacyBarrierValidation(call_info, object_id, Enable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice1_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice1_SetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice1_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice1_GetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice1_ReportLiveDeviceObjects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_RLDO_FLAGS Flags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(call_info, object_id, return_value, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice_SetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_FEATURE Mask;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Mask);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice_SetFeatureMask(call_info, object_id, return_value, Mask);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice_GetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_FEATURE return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice_GetFeatureMask(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice_ReportLiveDeviceObjects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_RLDO_FLAGS Flags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice_ReportLiveDeviceObjects(call_info, object_id, return_value, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice2_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice2_SetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugDevice2_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugDevice2_GetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandQueue_AssertResourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    UINT State;
    BOOL return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &State);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandQueue_AssertResourceState(call_info, object_id, return_value, pResource, Subresource, State);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandQueue1_AssertResourceAccess(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    D3D12_BARRIER_ACCESS Access;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Access);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandQueue1_AssertResourceAccess(call_info, object_id, pResource, Subresource, Access);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandQueue1_AssertTextureLayout(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    D3D12_BARRIER_LAYOUT Layout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Layout);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandQueue1_AssertTextureLayout(call_info, object_id, pResource, Subresource, Layout);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList1_AssertResourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    UINT State;
    BOOL return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &State);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList1_AssertResourceState(call_info, object_id, return_value, pResource, Subresource, State);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList1_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList1_SetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList1_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList1_GetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList_AssertResourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    UINT State;
    BOOL return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &State);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList_AssertResourceState(call_info, object_id, return_value, pResource, Subresource, State);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList_SetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_FEATURE Mask;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Mask);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList_SetFeatureMask(call_info, object_id, return_value, Mask);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList_GetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_FEATURE return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList_GetFeatureMask(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList2_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList2_SetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList2_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type;
    PointerDecoder<uint8_t> pData;
    UINT DataSize;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList2_GetDebugParameter(call_info, object_id, return_value, Type, &pData, DataSize);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList3_AssertResourceAccess(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    D3D12_BARRIER_ACCESS Access;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Access);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList3_AssertResourceAccess(call_info, object_id, pResource, Subresource, Access);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12DebugCommandList3_AssertTextureLayout(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    D3D12_BARRIER_LAYOUT Layout;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Layout);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12DebugCommandList3_AssertTextureLayout(call_info, object_id, pResource, Subresource, Layout);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SharingContract_Present(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pResource;
    UINT Subresource;
    uint64_t window;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pResource);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &window);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SharingContract_Present(call_info, object_id, pResource, Subresource, window);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SharingContract_SharedFenceSignal(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pFence;
    UINT64 FenceValue;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pFence);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &FenceValue);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SharingContract_SharedFenceSignal(call_info, object_id, pFence, FenceValue);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SharingContract_BeginCapturableWork(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID guid;
    GUID value_guid;
    guid.decoded_value = &value_guid;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &guid);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SharingContract_BeginCapturableWork(call_info, object_id, guid);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12SharingContract_EndCapturableWork(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID guid;
    GUID value_guid;
    guid.decoded_value = &value_guid;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &guid);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12SharingContract_EndCapturableWork(call_info, object_id, guid);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12ManualWriteTrackingResource_TrackWrite(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Subresource;
    StructPointerDecoder<Decoded_D3D12_RANGE> pWrittenRange;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Subresource);
    bytes_read += pWrittenRange.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12ManualWriteTrackingResource_TrackWrite(call_info, object_id, Subresource, &pWrittenRange);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_SetMessageCountLimit(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 MessageCountLimit;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MessageCountLimit);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_SetMessageCountLimit(call_info, object_id, return_value, MessageCountLimit);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_ClearStoredMessages(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_ClearStoredMessages(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetMessage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 MessageIndex;
    StructPointerDecoder<Decoded_D3D12_MESSAGE> pMessage;
    PointerDecoder<SIZE_T> pMessageByteLength;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MessageIndex);
    bytes_read += pMessage.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMessageByteLength.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetMessage(call_info, object_id, return_value, MessageIndex, &pMessage, &pMessageByteLength);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetNumStoredMessages(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetNumStoredMessages(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetMessageCountLimit(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetMessageCountLimit(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_AddStorageFilterEntries(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER> pFilter;
    HRESULT return_value;

    bytes_read += pFilter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_AddStorageFilterEntries(call_info, object_id, return_value, &pFilter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER> pFilter;
    PointerDecoder<SIZE_T> pFilterByteLength;
    HRESULT return_value;

    bytes_read += pFilter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFilterByteLength.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetStorageFilter(call_info, object_id, return_value, &pFilter, &pFilterByteLength);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_ClearStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_ClearStorageFilter(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PushEmptyStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PushEmptyStorageFilter(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PushCopyOfStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PushCopyOfStorageFilter(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PushStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER> pFilter;
    HRESULT return_value;

    bytes_read += pFilter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PushStorageFilter(call_info, object_id, return_value, &pFilter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PopStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PopStorageFilter(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetStorageFilterStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetStorageFilterStackSize(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_AddRetrievalFilterEntries(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER> pFilter;
    HRESULT return_value;

    bytes_read += pFilter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_AddRetrievalFilterEntries(call_info, object_id, return_value, &pFilter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER> pFilter;
    PointerDecoder<SIZE_T> pFilterByteLength;
    HRESULT return_value;

    bytes_read += pFilter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFilterByteLength.DecodeSizeT((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetRetrievalFilter(call_info, object_id, return_value, &pFilter, &pFilterByteLength);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_ClearRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_ClearRetrievalFilter(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PushEmptyRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PushCopyOfRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PushRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER> pFilter;
    HRESULT return_value;

    bytes_read += pFilter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PushRetrievalFilter(call_info, object_id, return_value, &pFilter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_PopRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_PopRetrievalFilter(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetRetrievalFilterStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_AddMessage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_CATEGORY Category;
    D3D12_MESSAGE_SEVERITY Severity;
    D3D12_MESSAGE_ID ID;
    StringDecoder pDescription;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Category);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Severity);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ID);
    bytes_read += pDescription.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_AddMessage(call_info, object_id, return_value, Category, Severity, ID, &pDescription);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_AddApplicationMessage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_SEVERITY Severity;
    StringDecoder pDescription;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Severity);
    bytes_read += pDescription.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_AddApplicationMessage(call_info, object_id, return_value, Severity, &pDescription);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_SetBreakOnCategory(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_CATEGORY Category;
    BOOL bEnable;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Category);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bEnable);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_SetBreakOnCategory(call_info, object_id, return_value, Category, bEnable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_SetBreakOnSeverity(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_SEVERITY Severity;
    BOOL bEnable;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Severity);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bEnable);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_SetBreakOnSeverity(call_info, object_id, return_value, Severity, bEnable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_SetBreakOnID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_ID ID;
    BOOL bEnable;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ID);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bEnable);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_SetBreakOnID(call_info, object_id, return_value, ID, bEnable);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetBreakOnCategory(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_CATEGORY Category;
    BOOL return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Category);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetBreakOnCategory(call_info, object_id, return_value, Category);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetBreakOnSeverity(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_SEVERITY Severity;
    BOOL return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Severity);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetBreakOnSeverity(call_info, object_id, return_value, Severity);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetBreakOnID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    D3D12_MESSAGE_ID ID;
    BOOL return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ID);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetBreakOnID(call_info, object_id, return_value, ID);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_SetMuteDebugOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL bMute;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &bMute);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_SetMuteDebugOutput(call_info, object_id, bMute);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue_GetMuteDebugOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue_GetMuteDebugOutput(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue1_RegisterMessageCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t CallbackFunc;
    D3D12_MESSAGE_CALLBACK_FLAGS CallbackFilterFlags;
    uint64_t pContext;
    PointerDecoder<DWORD> pCallbackCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CallbackFunc);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CallbackFilterFlags);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pContext);
    bytes_read += pCallbackCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue1_RegisterMessageCallback(call_info, object_id, return_value, CallbackFunc, CallbackFilterFlags, pContext, &pCallbackCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_ID3D12InfoQueue1_UnregisterMessageCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DWORD CallbackCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &CallbackCookie);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_ID3D12InfoQueue1_UnregisterMessageCallback(call_info, object_id, return_value, CallbackCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIObject_SetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID Name;
    GUID value_Name;
    Name.decoded_value = &value_Name;
    UINT DataSize;
    PointerDecoder<uint8_t> pData;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Name);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DataSize);
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIObject_SetPrivateData(call_info, object_id, return_value, Name, DataSize, &pData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIObject_SetPrivateDataInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID Name;
    GUID value_Name;
    Name.decoded_value = &value_Name;
    format::HandleId pUnknown;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Name);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pUnknown);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIObject_SetPrivateDataInterface(call_info, object_id, return_value, Name, pUnknown);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIObject_GetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID Name;
    GUID value_Name;
    Name.decoded_value = &value_Name;
    PointerDecoder<UINT> pDataSize;
    PointerDecoder<uint8_t> pData;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Name);
    bytes_read += pDataSize.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIObject_GetPrivateData(call_info, object_id, return_value, Name, &pDataSize, &pData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIObject_GetParent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppParent;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppParent.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIObject_GetParent(call_info, object_id, return_value, riid, &ppParent);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDeviceSubObject_GetDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppDevice;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppDevice.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDeviceSubObject_GetDevice(call_info, object_id, return_value, riid, &ppDevice);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIResource_GetSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint64_t, void*> pSharedHandle;
    HRESULT return_value;

    bytes_read += pSharedHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIResource_GetSharedHandle(call_info, object_id, return_value, &pSharedHandle);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIResource_GetUsage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<DXGI_USAGE> pUsage;
    HRESULT return_value;

    bytes_read += pUsage.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIResource_GetUsage(call_info, object_id, return_value, &pUsage);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIResource_SetEvictionPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT EvictionPriority;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &EvictionPriority);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIResource_SetEvictionPriority(call_info, object_id, return_value, EvictionPriority);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIResource_GetEvictionPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pEvictionPriority;
    HRESULT return_value;

    bytes_read += pEvictionPriority.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIResource_GetEvictionPriority(call_info, object_id, return_value, &pEvictionPriority);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIKeyedMutex_AcquireSync(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 Key;
    DWORD dwMilliseconds;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Key);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dwMilliseconds);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIKeyedMutex_AcquireSync(call_info, object_id, return_value, Key, dwMilliseconds);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIKeyedMutex_ReleaseSync(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT64 Key;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Key);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIKeyedMutex_ReleaseSync(call_info, object_id, return_value, Key);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISurface_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISurface_GetDesc(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISurface_Map(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT> pLockedRect;
    UINT MapFlags;
    HRESULT return_value;

    bytes_read += pLockedRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MapFlags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISurface_Map(call_info, object_id, return_value, &pLockedRect, MapFlags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISurface_Unmap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISurface_Unmap(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISurface1_GetDC(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Discard;
    PointerDecoder<uint64_t, void*> phdc;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Discard);
    bytes_read += phdc.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISurface1_GetDC(call_info, object_id, return_value, Discard, &phdc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISurface1_ReleaseDC(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_tagRECT> pDirtyRect;
    HRESULT return_value;

    bytes_read += pDirtyRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISurface1_ReleaseDC(call_info, object_id, return_value, &pDirtyRect);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter_EnumOutputs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Output;
    HandlePointerDecoder<IDXGIOutput*> ppOutput;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Output);
    bytes_read += ppOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter_EnumOutputs(call_info, object_id, return_value, Output, &ppOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter_GetDesc(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter_CheckInterfaceSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID InterfaceName;
    GUID value_InterfaceName;
    InterfaceName.decoded_value = &value_InterfaceName;
    StructPointerDecoder<Decoded_LARGE_INTEGER> pUMDVersion;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &InterfaceName);
    bytes_read += pUMDVersion.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter_CheckInterfaceSupport(call_info, object_id, return_value, InterfaceName, &pUMDVersion);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_GetDesc(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_GetDisplayModeList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_FORMAT EnumFormat;
    UINT Flags;
    PointerDecoder<UINT> pNumModes;
    StructPointerDecoder<Decoded_DXGI_MODE_DESC> pDesc;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &EnumFormat);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += pNumModes.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_GetDisplayModeList(call_info, object_id, return_value, EnumFormat, Flags, &pNumModes, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_FindClosestMatchingMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_MODE_DESC> pModeToMatch;
    StructPointerDecoder<Decoded_DXGI_MODE_DESC> pClosestMatch;
    format::HandleId pConcernedDevice;
    HRESULT return_value;

    bytes_read += pModeToMatch.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pClosestMatch.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pConcernedDevice);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_FindClosestMatchingMode(call_info, object_id, return_value, &pModeToMatch, &pClosestMatch, pConcernedDevice);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_WaitForVBlank(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_WaitForVBlank(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_TakeOwnership(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    BOOL Exclusive;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Exclusive);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_TakeOwnership(call_info, object_id, return_value, pDevice, Exclusive);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_ReleaseOwnership(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_ReleaseOwnership(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_GetGammaControlCapabilities(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES> pGammaCaps;
    HRESULT return_value;

    bytes_read += pGammaCaps.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_GetGammaControlCapabilities(call_info, object_id, return_value, &pGammaCaps);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_SetGammaControl(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL> pArray;
    HRESULT return_value;

    bytes_read += pArray.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_SetGammaControl(call_info, object_id, return_value, &pArray);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_GetGammaControl(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL> pArray;
    HRESULT return_value;

    bytes_read += pArray.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_GetGammaControl(call_info, object_id, return_value, &pArray);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_SetDisplaySurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pScanoutSurface;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pScanoutSurface);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_SetDisplaySurface(call_info, object_id, return_value, pScanoutSurface);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_GetDisplaySurfaceData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDestination;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDestination);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_GetDisplaySurfaceData(call_info, object_id, return_value, pDestination);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput_GetFrameStatistics(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS> pStats;
    HRESULT return_value;

    bytes_read += pStats.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput_GetFrameStatistics(call_info, object_id, return_value, &pStats);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_Present(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT SyncInterval;
    UINT Flags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SyncInterval);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_Present(call_info, object_id, return_value, SyncInterval, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_GetBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Buffer;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppSurface;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Buffer);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_GetBuffer(call_info, object_id, return_value, Buffer, riid, &ppSurface);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_SetFullscreenState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL Fullscreen;
    format::HandleId pTarget;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Fullscreen);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pTarget);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_SetFullscreenState(call_info, object_id, return_value, Fullscreen, pTarget);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_GetFullscreenState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<BOOL> pFullscreen;
    HandlePointerDecoder<IDXGIOutput*> ppTarget;
    HRESULT return_value;

    bytes_read += pFullscreen.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppTarget.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_GetFullscreenState(call_info, object_id, return_value, &pFullscreen, &ppTarget);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_GetDesc(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_ResizeBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT BufferCount;
    UINT Width;
    UINT Height;
    DXGI_FORMAT NewFormat;
    UINT SwapChainFlags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Height);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NewFormat);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SwapChainFlags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_ResizeBuffers(call_info, object_id, return_value, BufferCount, Width, Height, NewFormat, SwapChainFlags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_ResizeTarget(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_MODE_DESC> pNewTargetParameters;
    HRESULT return_value;

    bytes_read += pNewTargetParameters.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_ResizeTarget(call_info, object_id, return_value, &pNewTargetParameters);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_GetContainingOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandlePointerDecoder<IDXGIOutput*> ppOutput;
    HRESULT return_value;

    bytes_read += ppOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_GetContainingOutput(call_info, object_id, return_value, &ppOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_GetFrameStatistics(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS> pStats;
    HRESULT return_value;

    bytes_read += pStats.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_GetFrameStatistics(call_info, object_id, return_value, &pStats);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain_GetLastPresentCount(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pLastPresentCount;
    HRESULT return_value;

    bytes_read += pLastPresentCount.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain_GetLastPresentCount(call_info, object_id, return_value, &pLastPresentCount);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory_EnumAdapters(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Adapter;
    HandlePointerDecoder<IDXGIAdapter*> ppAdapter;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Adapter);
    bytes_read += ppAdapter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory_EnumAdapters(call_info, object_id, return_value, Adapter, &ppAdapter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory_MakeWindowAssociation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t WindowHandle;
    UINT Flags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WindowHandle);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory_MakeWindowAssociation(call_info, object_id, return_value, WindowHandle, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory_GetWindowAssociation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint64_t, void*> pWindowHandle;
    HRESULT return_value;

    bytes_read += pWindowHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory_GetWindowAssociation(call_info, object_id, return_value, &pWindowHandle);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory_CreateSwapChain(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC> pDesc;
    HandlePointerDecoder<IDXGISwapChain*> ppSwapChain;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppSwapChain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory_CreateSwapChain(call_info, object_id, return_value, pDevice, &pDesc, &ppSwapChain);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory_CreateSoftwareAdapter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t Module;
    HandlePointerDecoder<IDXGIAdapter*> ppAdapter;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Module);
    bytes_read += ppAdapter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory_CreateSoftwareAdapter(call_info, object_id, return_value, Module, &ppAdapter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice_GetAdapter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandlePointerDecoder<IDXGIAdapter*> pAdapter;
    HRESULT return_value;

    bytes_read += pAdapter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice_GetAdapter(call_info, object_id, return_value, &pAdapter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice_CreateSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC> pDesc;
    UINT NumSurfaces;
    DXGI_USAGE Usage;
    StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE> pSharedResource;
    HandlePointerDecoder<IDXGISurface*> ppSurface;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumSurfaces);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Usage);
    bytes_read += pSharedResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice_CreateSurface(call_info, object_id, return_value, &pDesc, NumSurfaces, Usage, &pSharedResource, &ppSurface);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice_QueryResourceResidency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandlePointerDecoder<IUnknown*> ppResources;
    PointerDecoder<DXGI_RESIDENCY> pResidencyStatus;
    UINT NumResources;
    HRESULT return_value;

    bytes_read += ppResources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pResidencyStatus.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumResources);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice_QueryResourceResidency(call_info, object_id, return_value, &ppResources, &pResidencyStatus, NumResources);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice_SetGPUThreadPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    INT Priority;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Priority);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice_SetGPUThreadPriority(call_info, object_id, return_value, Priority);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice_GetGPUThreadPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<INT> pPriority;
    HRESULT return_value;

    bytes_read += pPriority.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice_GetGPUThreadPriority(call_info, object_id, return_value, &pPriority);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory1_EnumAdapters1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Adapter;
    HandlePointerDecoder<IDXGIAdapter1*> ppAdapter;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Adapter);
    bytes_read += ppAdapter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory1_EnumAdapters1(call_info, object_id, return_value, Adapter, &ppAdapter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory1_IsCurrent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory1_IsCurrent(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter1_GetDesc1(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice1_SetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT MaxLatency;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MaxLatency);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice1_SetMaximumFrameLatency(call_info, object_id, return_value, MaxLatency);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice1_GetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pMaxLatency;
    HRESULT return_value;

    bytes_read += pMaxLatency.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice1_GetMaximumFrameLatency(call_info, object_id, return_value, &pMaxLatency);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDisplayControl_IsStereoEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDisplayControl_IsStereoEnabled(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDisplayControl_SetStereoEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL enabled;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &enabled);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDisplayControl_SetStereoEnabled(call_info, object_id, enabled);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC> pDesc;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_GetDesc(call_info, object_id, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_AcquireNextFrame(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT TimeoutInMilliseconds;
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO> pFrameInfo;
    HandlePointerDecoder<IDXGIResource*> ppDesktopResource;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &TimeoutInMilliseconds);
    bytes_read += pFrameInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppDesktopResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_AcquireNextFrame(call_info, object_id, return_value, TimeoutInMilliseconds, &pFrameInfo, &ppDesktopResource);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_GetFrameDirtyRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT DirtyRectsBufferSize;
    StructPointerDecoder<Decoded_tagRECT> pDirtyRectsBuffer;
    PointerDecoder<UINT> pDirtyRectsBufferSizeRequired;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DirtyRectsBufferSize);
    bytes_read += pDirtyRectsBuffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDirtyRectsBufferSizeRequired.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_GetFrameDirtyRects(call_info, object_id, return_value, DirtyRectsBufferSize, &pDirtyRectsBuffer, &pDirtyRectsBufferSizeRequired);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_GetFrameMoveRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT MoveRectsBufferSize;
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT> pMoveRectBuffer;
    PointerDecoder<UINT> pMoveRectsBufferSizeRequired;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MoveRectsBufferSize);
    bytes_read += pMoveRectBuffer.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pMoveRectsBufferSizeRequired.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_GetFrameMoveRects(call_info, object_id, return_value, MoveRectsBufferSize, &pMoveRectBuffer, &pMoveRectsBufferSizeRequired);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_GetFramePointerShape(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT PointerShapeBufferSize;
    PointerDecoder<uint8_t> pPointerShapeBuffer;
    PointerDecoder<UINT> pPointerShapeBufferSizeRequired;
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO> pPointerShapeInfo;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &PointerShapeBufferSize);
    bytes_read += pPointerShapeBuffer.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPointerShapeBufferSizeRequired.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pPointerShapeInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_GetFramePointerShape(call_info, object_id, return_value, PointerShapeBufferSize, &pPointerShapeBuffer, &pPointerShapeBufferSizeRequired, &pPointerShapeInfo);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_MapDesktopSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT> pLockedRect;
    HRESULT return_value;

    bytes_read += pLockedRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_MapDesktopSurface(call_info, object_id, return_value, &pLockedRect);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_UnMapDesktopSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_UnMapDesktopSurface(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutputDuplication_ReleaseFrame(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutputDuplication_ReleaseFrame(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISurface2_GetResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppParentResource;
    PointerDecoder<UINT> pSubresourceIndex;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppParentResource.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pSubresourceIndex.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISurface2_GetResource(call_info, object_id, return_value, riid, &ppParentResource, &pSubresourceIndex);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIResource1_CreateSubresourceSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT index;
    HandlePointerDecoder<IDXGISurface2*> ppSurface;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &index);
    bytes_read += ppSurface.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIResource1_CreateSubresourceSurface(call_info, object_id, return_value, index, &ppSurface);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIResource1_CreateSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES> pAttributes;
    DWORD dwAccess;
    WStringDecoder lpName;
    PointerDecoder<uint64_t, void*> pHandle;
    HRESULT return_value;

    bytes_read += pAttributes.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dwAccess);
    bytes_read += lpName.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHandle.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIResource1_CreateSharedHandle(call_info, object_id, return_value, &pAttributes, dwAccess, &lpName, &pHandle);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice2_OfferResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumResources;
    HandlePointerDecoder<IDXGIResource*> ppResources;
    DXGI_OFFER_RESOURCE_PRIORITY Priority;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumResources);
    bytes_read += ppResources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Priority);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice2_OfferResources(call_info, object_id, return_value, NumResources, &ppResources, Priority);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice2_ReclaimResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumResources;
    HandlePointerDecoder<IDXGIResource*> ppResources;
    PointerDecoder<BOOL> pDiscarded;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumResources);
    bytes_read += ppResources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDiscarded.DecodeInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice2_ReclaimResources(call_info, object_id, return_value, NumResources, &ppResources, &pDiscarded);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice2_EnqueueSetEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hEvent;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice2_EnqueueSetEvent(call_info, object_id, return_value, hEvent);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_GetDesc1(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_GetFullscreenDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_GetFullscreenDesc(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_GetHwnd(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<uint64_t, void*> pHwnd;
    HRESULT return_value;

    bytes_read += pHwnd.DecodeVoidPtr((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_GetHwnd(call_info, object_id, return_value, &pHwnd);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_GetCoreWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID refiid;
    GUID value_refiid;
    refiid.decoded_value = &value_refiid;
    HandlePointerDecoder<void*> ppUnk;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &refiid);
    bytes_read += ppUnk.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_GetCoreWindow(call_info, object_id, return_value, refiid, &ppUnk);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_Present1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT SyncInterval;
    UINT PresentFlags;
    StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS> pPresentParameters;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SyncInterval);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &PresentFlags);
    bytes_read += pPresentParameters.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_Present1(call_info, object_id, return_value, SyncInterval, PresentFlags, &pPresentParameters);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_IsTemporaryMonoSupported(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_IsTemporaryMonoSupported(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_GetRestrictToOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    HandlePointerDecoder<IDXGIOutput*> ppRestrictToOutput;
    HRESULT return_value;

    bytes_read += ppRestrictToOutput.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_GetRestrictToOutput(call_info, object_id, return_value, &ppRestrictToOutput);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_SetBackgroundColor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3DCOLORVALUE> pColor;
    HRESULT return_value;

    bytes_read += pColor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_SetBackgroundColor(call_info, object_id, return_value, &pColor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_GetBackgroundColor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_D3DCOLORVALUE> pColor;
    HRESULT return_value;

    bytes_read += pColor.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_GetBackgroundColor(call_info, object_id, return_value, &pColor);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_SetRotation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_MODE_ROTATION Rotation;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Rotation);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_SetRotation(call_info, object_id, return_value, Rotation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain1_GetRotation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<DXGI_MODE_ROTATION> pRotation;
    HRESULT return_value;

    bytes_read += pRotation.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain1_GetRotation(call_info, object_id, return_value, &pRotation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_IsWindowedStereoEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_IsWindowedStereoEnabled(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_CreateSwapChainForHwnd(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    uint64_t hWnd;
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1> pDesc;
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC> pFullscreenDesc;
    format::HandleId pRestrictToOutput;
    HandlePointerDecoder<IDXGISwapChain1*> ppSwapChain;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hWnd);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pFullscreenDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRestrictToOutput);
    bytes_read += ppSwapChain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_CreateSwapChainForHwnd(call_info, object_id, return_value, pDevice, hWnd, &pDesc, &pFullscreenDesc, pRestrictToOutput, &ppSwapChain);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_CreateSwapChainForCoreWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    format::HandleId pWindow;
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1> pDesc;
    format::HandleId pRestrictToOutput;
    HandlePointerDecoder<IDXGISwapChain1*> ppSwapChain;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pWindow);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRestrictToOutput);
    bytes_read += ppSwapChain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_CreateSwapChainForCoreWindow(call_info, object_id, return_value, pDevice, pWindow, &pDesc, pRestrictToOutput, &ppSwapChain);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_GetSharedResourceAdapterLuid(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hResource;
    StructPointerDecoder<Decoded_LUID> pLuid;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hResource);
    bytes_read += pLuid.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_GetSharedResourceAdapterLuid(call_info, object_id, return_value, hResource, &pLuid);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_RegisterStereoStatusWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t WindowHandle;
    UINT wMsg;
    PointerDecoder<DWORD> pdwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WindowHandle);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &wMsg);
    bytes_read += pdwCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_RegisterStereoStatusWindow(call_info, object_id, return_value, WindowHandle, wMsg, &pdwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_RegisterStereoStatusEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hEvent;
    PointerDecoder<DWORD> pdwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += pdwCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_RegisterStereoStatusEvent(call_info, object_id, return_value, hEvent, &pdwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_UnregisterStereoStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DWORD dwCookie;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dwCookie);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_UnregisterStereoStatus(call_info, object_id, dwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_RegisterOcclusionStatusWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t WindowHandle;
    UINT wMsg;
    PointerDecoder<DWORD> pdwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &WindowHandle);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &wMsg);
    bytes_read += pdwCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_RegisterOcclusionStatusWindow(call_info, object_id, return_value, WindowHandle, wMsg, &pdwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_RegisterOcclusionStatusEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hEvent;
    PointerDecoder<DWORD> pdwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += pdwCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_RegisterOcclusionStatusEvent(call_info, object_id, return_value, hEvent, &pdwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_UnregisterOcclusionStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DWORD dwCookie;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dwCookie);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_UnregisterOcclusionStatus(call_info, object_id, dwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory2_CreateSwapChainForComposition(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1> pDesc;
    format::HandleId pRestrictToOutput;
    HandlePointerDecoder<IDXGISwapChain1*> ppSwapChain;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRestrictToOutput);
    bytes_read += ppSwapChain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory2_CreateSwapChainForComposition(call_info, object_id, return_value, pDevice, &pDesc, pRestrictToOutput, &ppSwapChain);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter2_GetDesc2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter2_GetDesc2(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput1_GetDisplayModeList1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_FORMAT EnumFormat;
    UINT Flags;
    PointerDecoder<UINT> pNumModes;
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1> pDesc;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &EnumFormat);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += pNumModes.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput1_GetDisplayModeList1(call_info, object_id, return_value, EnumFormat, Flags, &pNumModes, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput1_FindClosestMatchingMode1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_MODE_DESC1> pModeToMatch;
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1> pClosestMatch;
    format::HandleId pConcernedDevice;
    HRESULT return_value;

    bytes_read += pModeToMatch.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pClosestMatch.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pConcernedDevice);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput1_FindClosestMatchingMode1(call_info, object_id, return_value, &pModeToMatch, &pClosestMatch, pConcernedDevice);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput1_GetDisplaySurfaceData1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDestination;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDestination);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput1_GetDisplaySurfaceData1(call_info, object_id, return_value, pDestination);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput1_DuplicateOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    HandlePointerDecoder<IDXGIOutputDuplication*> ppOutputDuplication;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += ppOutputDuplication.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput1_DuplicateOutput(call_info, object_id, return_value, pDevice, &ppOutputDuplication);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice3_Trim(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;



    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice3_Trim(call_info, object_id);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain2_SetSourceSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Width;
    UINT Height;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Height);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain2_SetSourceSize(call_info, object_id, return_value, Width, Height);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain2_GetSourceSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pWidth;
    PointerDecoder<UINT> pHeight;
    HRESULT return_value;

    bytes_read += pWidth.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHeight.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain2_GetSourceSize(call_info, object_id, return_value, &pWidth, &pHeight);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain2_SetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT MaxLatency;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MaxLatency);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain2_SetMaximumFrameLatency(call_info, object_id, return_value, MaxLatency);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain2_GetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pMaxLatency;
    HRESULT return_value;

    bytes_read += pMaxLatency.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain2_GetMaximumFrameLatency(call_info, object_id, return_value, &pMaxLatency);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain2_GetFrameLatencyWaitableObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain2_SetMatrixTransform(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F> pMatrix;
    HRESULT return_value;

    bytes_read += pMatrix.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain2_SetMatrixTransform(call_info, object_id, return_value, &pMatrix);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain2_GetMatrixTransform(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F> pMatrix;
    HRESULT return_value;

    bytes_read += pMatrix.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain2_GetMatrixTransform(call_info, object_id, return_value, &pMatrix);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput2_SupportsOverlays(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    BOOL return_value;

    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput2_SupportsOverlays(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory3_GetCreationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory3_GetCreationFlags(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_PresentBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT BufferToPresent;
    UINT SyncInterval;
    UINT Flags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferToPresent);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SyncInterval);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_PresentBuffer(call_info, object_id, return_value, BufferToPresent, SyncInterval, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_SetSourceRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_tagRECT> pRect;
    HRESULT return_value;

    bytes_read += pRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_SetSourceRect(call_info, object_id, return_value, &pRect);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_SetTargetRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_tagRECT> pRect;
    HRESULT return_value;

    bytes_read += pRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_SetTargetRect(call_info, object_id, return_value, &pRect);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_SetDestSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Width;
    UINT Height;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Height);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_SetDestSize(call_info, object_id, return_value, Width, Height);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_GetSourceRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_tagRECT> pRect;
    HRESULT return_value;

    bytes_read += pRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_GetSourceRect(call_info, object_id, return_value, &pRect);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_GetTargetRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_tagRECT> pRect;
    HRESULT return_value;

    bytes_read += pRect.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_GetTargetRect(call_info, object_id, return_value, &pRect);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_GetDestSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pWidth;
    PointerDecoder<UINT> pHeight;
    HRESULT return_value;

    bytes_read += pWidth.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pHeight.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_GetDestSize(call_info, object_id, return_value, &pWidth, &pHeight);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_SetColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ColorSpace);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_SetColorSpace(call_info, object_id, return_value, ColorSpace);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDecodeSwapChain_GetColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDecodeSwapChain_GetColorSpace(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    uint64_t hSurface;
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1> pDesc;
    format::HandleId pRestrictToOutput;
    HandlePointerDecoder<IDXGISwapChain1*> ppSwapChain;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hSurface);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRestrictToOutput);
    bytes_read += ppSwapChain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(call_info, object_id, return_value, pDevice, hSurface, &pDesc, pRestrictToOutput, &ppSwapChain);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    uint64_t hSurface;
    StructPointerDecoder<Decoded_DXGI_DECODE_SWAP_CHAIN_DESC> pDesc;
    format::HandleId pYuvDecodeBuffers;
    format::HandleId pRestrictToOutput;
    HandlePointerDecoder<IDXGIDecodeSwapChain*> ppSwapChain;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hSurface);
    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pYuvDecodeBuffers);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pRestrictToOutput);
    bytes_read += ppSwapChain.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(call_info, object_id, return_value, pDevice, hSurface, &pDesc, pYuvDecodeBuffers, pRestrictToOutput, &ppSwapChain);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChainMedia_GetFrameStatisticsMedia(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA> pStats;
    HRESULT return_value;

    bytes_read += pStats.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(call_info, object_id, return_value, &pStats);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChainMedia_SetPresentDuration(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Duration;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Duration);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChainMedia_SetPresentDuration(call_info, object_id, return_value, Duration);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChainMedia_CheckPresentDurationSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT DesiredPresentDuration;
    PointerDecoder<UINT> pClosestSmallerPresentDuration;
    PointerDecoder<UINT> pClosestLargerPresentDuration;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &DesiredPresentDuration);
    bytes_read += pClosestSmallerPresentDuration.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pClosestLargerPresentDuration.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChainMedia_CheckPresentDurationSupport(call_info, object_id, return_value, DesiredPresentDuration, &pClosestSmallerPresentDuration, &pClosestLargerPresentDuration);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput3_CheckOverlaySupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_FORMAT EnumFormat;
    format::HandleId pConcernedDevice;
    PointerDecoder<UINT> pFlags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &EnumFormat);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pConcernedDevice);
    bytes_read += pFlags.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput3_CheckOverlaySupport(call_info, object_id, return_value, EnumFormat, pConcernedDevice, &pFlags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain3_GetCurrentBackBufferIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain3_GetCurrentBackBufferIndex(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain3_CheckColorSpaceSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_COLOR_SPACE_TYPE ColorSpace;
    PointerDecoder<UINT> pColorSpaceSupport;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ColorSpace);
    bytes_read += pColorSpaceSupport.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain3_CheckColorSpaceSupport(call_info, object_id, return_value, ColorSpace, &pColorSpaceSupport);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain3_SetColorSpace1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_COLOR_SPACE_TYPE ColorSpace;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ColorSpace);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain3_SetColorSpace1(call_info, object_id, return_value, ColorSpace);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain3_ResizeBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT BufferCount;
    UINT Width;
    UINT Height;
    DXGI_FORMAT Format;
    UINT SwapChainFlags;
    PointerDecoder<UINT> pCreationNodeMask;
    HandlePointerDecoder<IUnknown*> ppPresentQueue;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &BufferCount);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Width);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Height);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Format);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SwapChainFlags);
    bytes_read += pCreationNodeMask.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppPresentQueue.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain3_ResizeBuffers1(call_info, object_id, return_value, BufferCount, Width, Height, Format, SwapChainFlags, &pCreationNodeMask, &ppPresentQueue);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput4_CheckOverlayColorSpaceSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_FORMAT Format;
    DXGI_COLOR_SPACE_TYPE ColorSpace;
    format::HandleId pConcernedDevice;
    PointerDecoder<UINT> pFlags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Format);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &ColorSpace);
    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pConcernedDevice);
    bytes_read += pFlags.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(call_info, object_id, return_value, Format, ColorSpace, pConcernedDevice, &pFlags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory4_EnumAdapterByLuid(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_LUID AdapterLuid;
    LUID value_AdapterLuid;
    AdapterLuid.decoded_value = &value_AdapterLuid;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvAdapter;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &AdapterLuid);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvAdapter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory4_EnumAdapterByLuid(call_info, object_id, return_value, AdapterLuid, riid, &ppvAdapter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory4_EnumWarpAdapter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvAdapter;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvAdapter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory4_EnumWarpAdapter(call_info, object_id, return_value, riid, &ppvAdapter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hEvent;
    PointerDecoder<DWORD> pdwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += pdwCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(call_info, object_id, return_value, hEvent, &pdwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DWORD dwCookie;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dwCookie);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(call_info, object_id, dwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter3_QueryVideoMemoryInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NodeIndex;
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup;
    StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO> pVideoMemoryInfo;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeIndex);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MemorySegmentGroup);
    bytes_read += pVideoMemoryInfo.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter3_QueryVideoMemoryInfo(call_info, object_id, return_value, NodeIndex, MemorySegmentGroup, &pVideoMemoryInfo);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter3_SetVideoMemoryReservation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NodeIndex;
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup;
    UINT64 Reservation;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NodeIndex);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &MemorySegmentGroup);
    bytes_read += ValueDecoder::DecodeUInt64Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Reservation);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter3_SetVideoMemoryReservation(call_info, object_id, return_value, NodeIndex, MemorySegmentGroup, Reservation);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hEvent;
    PointerDecoder<DWORD> pdwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += pdwCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(call_info, object_id, return_value, hEvent, &pdwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DWORD dwCookie;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dwCookie);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(call_info, object_id, dwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput5_DuplicateOutput1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    format::HandleId pDevice;
    UINT Flags;
    UINT SupportedFormatsCount;
    PointerDecoder<DXGI_FORMAT> pSupportedFormats;
    HandlePointerDecoder<IDXGIOutputDuplication*> ppOutputDuplication;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeHandleIdValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &pDevice);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &SupportedFormatsCount);
    bytes_read += pSupportedFormats.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ppOutputDuplication.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput5_DuplicateOutput1(call_info, object_id, return_value, pDevice, Flags, SupportedFormatsCount, &pSupportedFormats, &ppOutputDuplication);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGISwapChain4_SetHDRMetaData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DXGI_HDR_METADATA_TYPE Type;
    UINT Size;
    PointerDecoder<uint8_t> pMetaData;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Type);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Size);
    bytes_read += pMetaData.DecodeVoid((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGISwapChain4_SetHDRMetaData(call_info, object_id, return_value, Type, Size, &pMetaData);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice4_OfferResources1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumResources;
    HandlePointerDecoder<IDXGIResource*> ppResources;
    DXGI_OFFER_RESOURCE_PRIORITY Priority;
    UINT Flags;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumResources);
    bytes_read += ppResources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Priority);
    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Flags);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice4_OfferResources1(call_info, object_id, return_value, NumResources, &ppResources, Priority, Flags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIDevice4_ReclaimResources1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT NumResources;
    HandlePointerDecoder<IDXGIResource*> ppResources;
    PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS> pResults;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &NumResources);
    bytes_read += ppResources.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += pResults.DecodeEnum((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIDevice4_ReclaimResources1(call_info, object_id, return_value, NumResources, &ppResources, &pResults);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIAdapter4_GetDesc3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIAdapter4_GetDesc3(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput6_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1> pDesc;
    HRESULT return_value;

    bytes_read += pDesc.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput6_GetDesc1(call_info, object_id, return_value, &pDesc);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIOutput6_CheckHardwareCompositionSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    PointerDecoder<UINT> pFlags;
    HRESULT return_value;

    bytes_read += pFlags.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIOutput6_CheckHardwareCompositionSupport(call_info, object_id, return_value, &pFlags);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory6_EnumAdapterByGpuPreference(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    UINT Adapter;
    DXGI_GPU_PREFERENCE GpuPreference;
    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvAdapter;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &Adapter);
    bytes_read += ValueDecoder::DecodeEnumValue((parameter_buffer + bytes_read), (buffer_size - bytes_read), &GpuPreference);
    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvAdapter.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory6_EnumAdapterByGpuPreference(call_info, object_id, return_value, Adapter, GpuPreference, riid, &ppvAdapter);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory7_RegisterAdaptersChangedEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    uint64_t hEvent;
    PointerDecoder<DWORD> pdwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeAddress((parameter_buffer + bytes_read), (buffer_size - bytes_read), &hEvent);
    bytes_read += pdwCookie.DecodeUInt32((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory7_RegisterAdaptersChangedEvent(call_info, object_id, return_value, hEvent, &pdwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IDXGIFactory7_UnregisterAdaptersChangedEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    DWORD dwCookie;
    HRESULT return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &dwCookie);
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(call_info, object_id, return_value, dwCookie);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IUnknown_QueryInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    Decoded_GUID riid;
    GUID value_riid;
    riid.decoded_value = &value_riid;
    HandlePointerDecoder<void*> ppvObject;
    HRESULT return_value;

    bytes_read += DecodeStruct((parameter_buffer + bytes_read), (buffer_size - bytes_read), &riid);
    bytes_read += ppvObject.Decode((parameter_buffer + bytes_read), (buffer_size - bytes_read));
    bytes_read += ValueDecoder::DecodeInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IUnknown_QueryInterface(call_info, object_id, return_value, riid, &ppvObject);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IUnknown_AddRef(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    ULONG return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IUnknown_AddRef(call_info, object_id, return_value);
    }

    return bytes_read;
}

size_t Dx12Decoder::Decode_IUnknown_Release(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size)
{
    size_t bytes_read = 0;

    ULONG return_value;

    bytes_read += ValueDecoder::DecodeUInt32Value((parameter_buffer + bytes_read), (buffer_size - bytes_read), &return_value);

    for (auto consumer : GetConsumers())
    {
        consumer->Process_IUnknown_Release(call_info, object_id, return_value);
    }

    return bytes_read;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
