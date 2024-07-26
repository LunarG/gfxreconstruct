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
** This file is generated from dx12_decoder_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_DECODER_H
#define  GFXRECON_GENERATED_DX12_DECODER_H


#include "decode/dx12_decoder_base.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12Decoder : public Dx12DecoderBase
{
  public:
    Dx12Decoder(){}
    virtual ~Dx12Decoder() override {}

    virtual void DecodeFunctionCall(format::ApiCallId  call_id,
                                    const ApiCallInfo& call_options,
                                    const uint8_t*     parameter_buffer,
                                    size_t             buffer_size) override;

    virtual void DecodeMethodCall(format::ApiCallId  call_id,
                                  format::HandleId   object_id,
                                  const ApiCallInfo& call_options,
                                  const uint8_t*     parameter_buffer,
                                  size_t             buffer_size) override;
  private:

/*
** This part is generated from d3d12.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_D3D12SerializeRootSignature(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12CreateRootSignatureDeserializer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12SerializeVersionedRootSignature(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12CreateVersionedRootSignatureDeserializer(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12CreateDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12GetDebugInterface(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12EnableExperimentalFeatures(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D12GetInterface(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Object_GetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Object_SetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Object_SetPrivateDataInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Object_SetName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceChild_GetDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Heap_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource_Map(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource_Unmap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource_GetGPUVirtualAddress(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource_ReadFromSubresource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource_GetHeapProperties(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandAllocator_Reset(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Fence_GetCompletedValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Fence_SetEventOnCompletion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Fence_Signal(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Fence1_GetCreationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PipelineState_GetCachedBlob(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DescriptorHeap_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandList_GetType(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_Close(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_Reset(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ClearState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_DrawInstanced(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_DrawIndexedInstanced(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_Dispatch(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_CopyBufferRegion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_CopyTextureRegion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_CopyResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_CopyTiles(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ResolveSubresource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_IASetPrimitiveTopology(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_RSSetViewports(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_RSSetScissorRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_OMSetBlendFactor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_OMSetStencilRef(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetPipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ResourceBarrier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ExecuteBundle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetDescriptorHeaps(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetComputeRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetGraphicsRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_IASetIndexBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_IASetVertexBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SOSetTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_OMSetRenderTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ClearDepthStencilView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ClearRenderTargetView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_DiscardResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_BeginQuery(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_EndQuery(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ResolveQueryData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetPredication(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_SetMarker(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_BeginEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_EndEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList_ExecuteIndirect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList1_OMSetDepthBounds(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList1_SetSamplePositions(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList1_SetViewInstanceMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList2_WriteBufferImmediate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_UpdateTileMappings(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_CopyTileMappings(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_ExecuteCommandLists(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_SetMarker(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_BeginEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_EndEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_Signal(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_Wait(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_GetTimestampFrequency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_GetClockCalibration(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12CommandQueue_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetNodeCount(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateCommandQueue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateCommandAllocator(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateGraphicsPipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateComputePipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateCommandList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateDescriptorHeap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetDescriptorHandleIncrementSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateConstantBufferView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateShaderResourceView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateRenderTargetView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateDepthStencilView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateSampler(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CopyDescriptors(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CopyDescriptorsSimple(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetResourceAllocationInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetCustomHeapProperties(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateCommittedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateHeap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreatePlacedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateReservedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_OpenSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_OpenSharedHandleByName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_MakeResident(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_Evict(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateFence(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetDeviceRemovedReason(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetCopyableFootprints(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateQueryHeap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_SetStablePowerState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_CreateCommandSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetResourceTiling(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device_GetAdapterLuid(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PipelineLibrary_StorePipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PipelineLibrary_LoadGraphicsPipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PipelineLibrary_LoadComputePipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PipelineLibrary_GetSerializedSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PipelineLibrary_Serialize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PipelineLibrary1_LoadPipeline(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device1_CreatePipelineLibrary(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device1_SetEventOnMultipleFenceCompletion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device1_SetResidencyPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device2_CreatePipelineState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device3_OpenExistingHeapFromAddress(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device3_OpenExistingHeapFromFileMapping(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device3_EnqueueMakeResident(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ProtectedSession_GetStatusFence(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ProtectedSession_GetSessionStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ProtectedResourceSession_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device4_CreateCommandList1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device4_CreateProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device4_CreateCommittedResource1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device4_CreateHeap1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device4_CreateReservedResource1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device4_GetResourceAllocationInfo1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12LifetimeOwner_LifetimeStateUpdated(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SwapChainAssistant_GetLUID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SwapChainAssistant_GetSwapChainObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SwapChainAssistant_InsertImplicitSync(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12LifetimeTracker_DestroyOwnedObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12StateObjectProperties_GetShaderIdentifier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12StateObjectProperties_GetShaderStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12StateObjectProperties_GetPipelineStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12StateObjectProperties_SetPipelineStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12StateObjectProperties1_GetProgramIdentifier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetNumWorkGraphs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetProgramName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetWorkGraphIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetNumNodes(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetNodeID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetNodeIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetNodeLocalRootArgumentsTableIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetNumEntrypoints(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetEntrypointID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetEntrypointIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetEntrypointRecordSizeInBytes(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetWorkGraphMemoryRequirements(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12WorkGraphProperties_GetEntrypointRecordAlignmentInBytes(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_CreateLifetimeTracker(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_RemoveDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_EnumerateMetaCommands(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_EnumerateMetaCommandParameters(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_CreateMetaCommand(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_CreateStateObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device5_CheckDriverMatchingIdentifier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceRemovedExtendedData2_GetDeviceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device6_SetBackgroundProcessingMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ProtectedResourceSession1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device7_AddToStateObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device7_CreateProtectedResourceSession1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device8_GetResourceAllocationInfo2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device8_CreateCommittedResource2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device8_CreatePlacedResource1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device8_GetCopyableFootprints1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource1_GetProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Resource2_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Heap1_GetProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList3_SetProtectedResourceSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12MetaCommand_GetRequiredParameterResourceSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_BeginRenderPass(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_EndRenderPass(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_InitializeMetaCommand(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_ExecuteMetaCommand(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_SetPipelineState1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList4_DispatchRays(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ShaderCacheSession_FindValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ShaderCacheSession_StoreValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ShaderCacheSession_SetDeleteOnDestroy(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ShaderCacheSession_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device9_CreateShaderCacheSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device9_ShaderCacheControl(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device9_CreateCommandQueue1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device10_CreateCommittedResource3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device10_CreatePlacedResource2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device10_CreateReservedResource2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device11_CreateSampler2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device12_GetResourceAllocationInfo3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device13_OpenExistingHeapFromAddress1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Device14_CreateRootSignatureFromSubobjectInLibrary(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12VirtualizationGuestDevice_ShareWithHost(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12VirtualizationGuestDevice_CreateFenceFd(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Tools_EnableShaderInstrumentation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Tools_ShaderInstrumentationEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Tools1_ReserveGPUVARangesAtCreate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Tools1_ClearReservedGPUVARangesList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12PageableTools_GetAllocation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceTools_SetNextAllocationAddress(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SDKConfiguration_SetSDKVersion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SDKConfiguration1_CreateDeviceFactory(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SDKConfiguration1_FreeUnusedSDKs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceFactory_InitializeFromGlobalState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceFactory_ApplyToGlobalState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceFactory_SetFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceFactory_GetFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceFactory_GetConfigurationInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceFactory_EnableExperimentalFeatures(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceFactory_CreateDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceConfiguration_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DeviceConfiguration1_CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList5_RSSetShadingRate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList5_RSSetShadingRateImage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList6_DispatchMesh(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList7_Barrier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList9_RSSetDepthBias(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList10_SetProgram(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GraphicsCommandList10_DispatchGraph(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DSRDeviceFactory_CreateDSRDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GBVDiagnostics_GetGBVEntireSubresourceStatesData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GBVDiagnostics_GetGBVSubresourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GBVDiagnostics_GetGBVResourceUniformState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GBVDiagnostics_GetGBVResourceInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GBVDiagnostics_GBVReserved0(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12GBVDiagnostics_GBVReserved1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_ID3D10Blob_GetBufferPointer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D10Blob_GetBufferSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3DDestructionNotifier_RegisterDestructionCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3DDestructionNotifier_UnregisterDestructionCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_ID3D12Debug_EnableDebugLayer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug1_EnableDebugLayer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug1_SetEnableGPUBasedValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug2_SetGPUBasedValidationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug3_SetEnableGPUBasedValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug3_SetGPUBasedValidationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug4_DisableDebugLayer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug5_SetEnableAutoName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12Debug6_SetForceLegacyBarrierValidation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice1_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice1_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice1_ReportLiveDeviceObjects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice_SetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice_GetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice_ReportLiveDeviceObjects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice2_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugDevice2_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandQueue_AssertResourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandQueue1_AssertResourceAccess(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandQueue1_AssertTextureLayout(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList1_AssertResourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList1_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList1_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList_AssertResourceState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList_SetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList_GetFeatureMask(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList2_SetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList2_GetDebugParameter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList3_AssertResourceAccess(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12DebugCommandList3_AssertTextureLayout(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SharingContract_Present(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SharingContract_SharedFenceSignal(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SharingContract_BeginCapturableWork(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12SharingContract_EndCapturableWork(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12ManualWriteTrackingResource_TrackWrite(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_SetMessageCountLimit(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_ClearStoredMessages(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetMessage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetNumStoredMessages(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetMessageCountLimit(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_AddStorageFilterEntries(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_ClearStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PushEmptyStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PushCopyOfStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PushStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PopStorageFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetStorageFilterStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_AddRetrievalFilterEntries(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_ClearRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PushEmptyRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PushCopyOfRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PushRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_PopRetrievalFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetRetrievalFilterStackSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_AddMessage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_AddApplicationMessage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_SetBreakOnCategory(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_SetBreakOnSeverity(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_SetBreakOnID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetBreakOnCategory(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetBreakOnSeverity(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetBreakOnID(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_SetMuteDebugOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue_GetMuteDebugOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue1_RegisterMessageCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D12InfoQueue1_UnregisterMessageCallback(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3d11.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_D3D11CreateDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_D3D11CreateDeviceAndSwapChain(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceChild_GetDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceChild_GetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceChild_SetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceChild_SetPrivateDataInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DepthStencilState_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11BlendState_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11RasterizerState_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Resource_GetType(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Resource_SetEvictionPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Resource_GetEvictionPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Buffer_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Texture1D_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Texture2D_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Texture3D_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11View_GetResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ShaderResourceView_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11RenderTargetView_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DepthStencilView_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11UnorderedAccessView_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11SamplerState_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Asynchronous_GetDataSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Query_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Counter_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ClassInstance_GetClassLinkage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ClassInstance_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ClassInstance_GetInstanceName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ClassInstance_GetTypeName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ClassLinkage_GetClassInstance(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ClassLinkage_CreateClassInstance(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11CommandList_GetContextFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSSetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSSetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSSetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSSetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSSetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DrawIndexed(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_Draw(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_Map(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_Unmap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSSetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IASetInputLayout(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IASetVertexBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IASetIndexBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DrawIndexedInstanced(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DrawInstanced(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSSetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSSetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IASetPrimitiveTopology(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSSetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSSetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_Begin(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_End(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GetData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_SetPredication(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSSetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSSetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMSetRenderTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMSetRenderTargetsAndUnorderedAccessViews(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMSetBlendState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMSetDepthStencilState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_SOSetTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DrawAuto(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DrawIndexedInstancedIndirect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DrawInstancedIndirect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_Dispatch(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DispatchIndirect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_RSSetState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_RSSetViewports(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_RSSetScissorRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CopySubresourceRegion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CopyResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CopyStructureCount(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_ClearRenderTargetView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_ClearUnorderedAccessViewUint(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_ClearUnorderedAccessViewFloat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_ClearDepthStencilView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GenerateMips(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_SetResourceMinLOD(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GetResourceMinLOD(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_ResolveSubresource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_ExecuteCommandList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSSetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSSetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSSetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSSetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSSetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSSetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSSetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSSetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSSetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSSetUnorderedAccessViews(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSSetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSSetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSSetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSGetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSGetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSGetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSGetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSGetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_PSGetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IAGetInputLayout(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IAGetVertexBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IAGetIndexBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSGetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSGetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_IAGetPrimitiveTopology(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSGetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_VSGetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GetPredication(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSGetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GSGetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMGetRenderTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMGetRenderTargetsAndUnorderedAccessViews(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMGetBlendState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_OMGetDepthStencilState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_SOGetTargets(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_RSGetState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_RSGetViewports(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_RSGetScissorRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSGetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSGetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSGetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_HSGetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSGetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSGetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSGetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_DSGetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSGetShaderResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSGetUnorderedAccessViews(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSGetShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSGetSamplers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_CSGetConstantBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_ClearState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_Flush(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GetType(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_GetContextFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext_FinishCommandList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDecoder_GetCreationParameters(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDecoder_GetDriverHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorEnumerator_GetVideoProcessorContentDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorEnumerator_CheckVideoProcessorFormat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorEnumerator_GetVideoProcessorCaps(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorEnumerator_GetVideoProcessorRateConversionCaps(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorEnumerator_GetVideoProcessorCustomRate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorEnumerator_GetVideoProcessorFilterRange(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessor_GetContentDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessor_GetRateConversionCaps(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11AuthenticatedChannel_GetCertificateSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11AuthenticatedChannel_GetCertificate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11AuthenticatedChannel_GetChannelHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11CryptoSession_GetCryptoType(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11CryptoSession_GetDecoderProfile(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11CryptoSession_GetCertificateSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11CryptoSession_GetCertificate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11CryptoSession_GetCryptoSessionHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDecoderOutputView_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorInputView_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorOutputView_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_GetDecoderBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_ReleaseDecoderBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_DecoderBeginFrame(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_DecoderEndFrame(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_SubmitDecoderBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_DecoderExtension(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetOutputTargetRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetOutputBackgroundColor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetOutputColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetOutputAlphaFillMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetOutputConstriction(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetOutputStereoMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetOutputExtension(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetOutputTargetRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetOutputBackgroundColor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetOutputColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetOutputAlphaFillMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetOutputConstriction(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetOutputStereoMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetOutputExtension(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamFrameFormat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamOutputRate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamSourceRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamDestRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamAlpha(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamPalette(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamPixelAspectRatio(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamLumaKey(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamStereoFormat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamAutoProcessingMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamExtension(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamFrameFormat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamOutputRate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamSourceRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamDestRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamAlpha(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamPalette(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamPixelAspectRatio(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamLumaKey(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamStereoFormat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamAutoProcessingMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamFilter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamExtension(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorBlt(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_NegotiateCryptoSessionKeyExchange(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_EncryptionBlt(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_DecryptionBlt(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_StartSessionKeyRefresh(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_FinishSessionKeyRefresh(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_GetEncryptionBltKey(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_NegotiateAuthenticatedChannelKeyExchange(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_QueryAuthenticatedChannel(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_ConfigureAuthenticatedChannel(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorSetStreamRotation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext_VideoProcessorGetStreamRotation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateVideoDecoder(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateVideoProcessor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateAuthenticatedChannel(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateCryptoSession(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateVideoDecoderOutputView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateVideoProcessorInputView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateVideoProcessorOutputView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CreateVideoProcessorEnumerator(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_GetVideoDecoderProfileCount(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_GetVideoDecoderProfile(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CheckVideoDecoderFormat(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_GetVideoDecoderConfigCount(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_GetVideoDecoderConfig(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_GetContentProtectionCaps(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_CheckCryptoKeyExchange(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_SetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice_SetPrivateDataInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateShaderResourceView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateUnorderedAccessView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateRenderTargetView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateDepthStencilView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateInputLayout(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateVertexShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateGeometryShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateGeometryShaderWithStreamOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreatePixelShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateHullShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateDomainShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateComputeShader(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateClassLinkage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateBlendState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateDepthStencilState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateRasterizerState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateSamplerState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateQuery(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreatePredicate(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateCounter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CreateDeferredContext(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_OpenSharedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CheckFormatSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CheckMultisampleQualityLevels(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CheckCounterInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_CheckCounter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_GetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_SetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_SetPrivateDataInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_GetFeatureLevel(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_GetCreationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_GetDeviceRemovedReason(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_GetImmediateContext(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_SetExceptionMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device_GetExceptionMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3d11_1.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_ID3D11BlendState1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11RasterizerState1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_CopySubresourceRegion1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_DiscardResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_DiscardView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_VSSetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_HSSetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_DSSetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_GSSetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_PSSetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_CSSetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_VSGetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_HSGetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_DSGetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_GSGetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_PSGetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_CSGetConstantBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_SwapDeviceContextState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_ClearView(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext1_DiscardView1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_SubmitDecoderBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_GetDataForNewHardwareKey(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_CheckCryptoSessionStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_DecoderEnableDownsampling(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_DecoderUpdateDownsampling(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorSetOutputColorSpace1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorSetOutputShaderUsage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorGetOutputColorSpace1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorGetOutputShaderUsage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorSetStreamColorSpace1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorSetStreamMirror(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorGetStreamColorSpace1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorGetStreamMirror(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext1_VideoProcessorGetBehaviorHints(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice1_GetCryptoSessionPrivateDataSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice1_GetVideoDecoderCaps(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice1_CheckVideoDecoderDownsampling(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice1_RecommendVideoDecoderDownsampleParameters(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoProcessorEnumerator1_CheckVideoProcessorFormatConversion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device1_GetImmediateContext1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device1_CreateDeferredContext1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device1_CreateBlendState1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device1_CreateRasterizerState1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device1_CreateDeviceContextState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device1_OpenSharedResource1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device1_OpenSharedResourceByName(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3DUserDefinedAnnotation_BeginEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3DUserDefinedAnnotation_EndEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3DUserDefinedAnnotation_SetMarker(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3DUserDefinedAnnotation_GetStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3d11_2.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_ID3D11DeviceContext2_UpdateTileMappings(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_CopyTileMappings(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_CopyTiles(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_UpdateTiles(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_ResizeTilePool(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_TiledResourceBarrier(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_IsAnnotationEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_SetMarkerInt(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_BeginEventInt(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext2_EndEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device2_GetImmediateContext2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device2_CreateDeferredContext2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device2_GetResourceTiling(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device2_CheckMultisampleQualityLevels1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3d11_3.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_ID3D11Texture2D1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Texture3D1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11RasterizerState2_GetDesc2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11ShaderResourceView1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11RenderTargetView1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11UnorderedAccessView1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Query1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext3_Flush1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext3_SetHardwareProtectionState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext3_GetHardwareProtectionState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Fence_CreateSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Fence_GetCompletedValue(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Fence_SetEventOnCompletion(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext4_Signal(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11DeviceContext4_Wait(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_CreateRasterizerState2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_CreateShaderResourceView1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_CreateUnorderedAccessView1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_CreateRenderTargetView1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_CreateQuery1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_GetImmediateContext3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_CreateDeferredContext3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device3_ReadFromSubresource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3d11_4.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_ID3D11Device4_RegisterDeviceRemovedEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device4_UnregisterDeviceRemoved(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device5_OpenSharedFence(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Device5_CreateFence(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Multithread_Enter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Multithread_Leave(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Multithread_SetMultithreadProtected(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11Multithread_GetMultithreadProtected(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext2_VideoProcessorSetOutputHDRMetaData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext2_VideoProcessorGetOutputHDRMetaData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext2_VideoProcessorSetStreamHDRMetaData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext2_VideoProcessorGetStreamHDRMetaData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice2_CheckFeatureSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoDevice2_NegotiateCryptoSessionKeyExchangeMT(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext3_DecoderBeginFrame1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11VideoContext3_SubmitDecoderBuffers2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from d3d11on12.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_D3D11On12CreateDevice(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11On12Device_CreateWrappedResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11On12Device_ReleaseWrappedResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11On12Device_AcquireWrappedResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11On12Device1_GetD3D12Device(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11On12Device2_UnwrapUnderlyingResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_ID3D11On12Device2_ReturnUnderlyingResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from dxgi.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_CreateDXGIFactory(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_CreateDXGIFactory1(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIObject_SetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIObject_SetPrivateDataInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIObject_GetPrivateData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIObject_GetParent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDeviceSubObject_GetDevice(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIResource_GetSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIResource_GetUsage(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIResource_SetEvictionPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIResource_GetEvictionPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIKeyedMutex_AcquireSync(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIKeyedMutex_ReleaseSync(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISurface_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISurface_Map(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISurface_Unmap(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISurface1_GetDC(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISurface1_ReleaseDC(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter_EnumOutputs(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter_CheckInterfaceSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_GetDisplayModeList(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_FindClosestMatchingMode(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_WaitForVBlank(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_TakeOwnership(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_ReleaseOwnership(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_GetGammaControlCapabilities(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_SetGammaControl(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_GetGammaControl(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_SetDisplaySurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_GetDisplaySurfaceData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput_GetFrameStatistics(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_Present(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_GetBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_SetFullscreenState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_GetFullscreenState(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_ResizeBuffers(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_ResizeTarget(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_GetContainingOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_GetFrameStatistics(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain_GetLastPresentCount(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory_EnumAdapters(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory_MakeWindowAssociation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory_GetWindowAssociation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory_CreateSwapChain(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory_CreateSoftwareAdapter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice_GetAdapter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice_CreateSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice_QueryResourceResidency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice_SetGPUThreadPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice_GetGPUThreadPriority(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory1_EnumAdapters1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory1_IsCurrent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice1_SetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice1_GetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_IDXGIDisplayControl_IsStereoEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDisplayControl_SetStereoEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_GetDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_AcquireNextFrame(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_GetFrameDirtyRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_GetFrameMoveRects(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_GetFramePointerShape(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_MapDesktopSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_UnMapDesktopSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutputDuplication_ReleaseFrame(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISurface2_GetResource(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIResource1_CreateSubresourceSurface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIResource1_CreateSharedHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice2_OfferResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice2_ReclaimResources(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice2_EnqueueSetEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_GetFullscreenDesc(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_GetHwnd(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_GetCoreWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_Present1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_IsTemporaryMonoSupported(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_GetRestrictToOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_SetBackgroundColor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_GetBackgroundColor(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_SetRotation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain1_GetRotation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_IsWindowedStereoEnabled(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_CreateSwapChainForHwnd(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_CreateSwapChainForCoreWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_GetSharedResourceAdapterLuid(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_RegisterStereoStatusWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_RegisterStereoStatusEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_UnregisterStereoStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_RegisterOcclusionStatusWindow(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_RegisterOcclusionStatusEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_UnregisterOcclusionStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory2_CreateSwapChainForComposition(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter2_GetDesc2(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput1_GetDisplayModeList1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput1_FindClosestMatchingMode1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput1_GetDisplaySurfaceData1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput1_DuplicateOutput(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_CreateDXGIFactory2(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_DXGIGetDebugInterface1(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice3_Trim(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain2_SetSourceSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain2_GetSourceSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain2_SetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain2_GetMaximumFrameLatency(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain2_GetFrameLatencyWaitableObject(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain2_SetMatrixTransform(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain2_GetMatrixTransform(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput2_SupportsOverlays(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory3_GetCreationFlags(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_PresentBuffer(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_SetSourceRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_SetTargetRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_SetDestSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_GetSourceRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_GetTargetRect(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_GetDestSize(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_SetColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDecodeSwapChain_GetColorSpace(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChainMedia_GetFrameStatisticsMedia(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChainMedia_SetPresentDuration(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChainMedia_CheckPresentDurationSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput3_CheckOverlaySupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_IDXGISwapChain3_GetCurrentBackBufferIndex(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain3_CheckColorSpaceSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain3_SetColorSpace1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain3_ResizeBuffers1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput4_CheckOverlayColorSpaceSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory4_EnumAdapterByLuid(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory4_EnumWarpAdapter(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter3_QueryVideoMemoryInfo(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter3_SetVideoMemoryReservation(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_IDXGIOutput5_DuplicateOutput1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGISwapChain4_SetHDRMetaData(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice4_OfferResources1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIDevice4_ReclaimResources1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_DXGIDeclareAdapterRemovalSupport(const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIAdapter4_GetDesc3(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput6_GetDesc1(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIOutput6_CheckHardwareCompositionSupport(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory6_EnumAdapterByGpuPreference(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory7_RegisterAdaptersChangedEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IDXGIFactory7_UnregisterAdaptersChangedEvent(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);

/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.20348.0
**
*/
    size_t Decode_IUnknown_QueryInterface(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IUnknown_AddRef(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
    size_t Decode_IUnknown_Release(format::HandleId object_id, const ApiCallInfo& call_info, const uint8_t* parameter_buffer, size_t buffer_size);
};


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
