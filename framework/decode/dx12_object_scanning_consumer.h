/*
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef GFXRECON_DX12_OBJECT_SCANNING_CONSUMER_H
#define GFXRECON_DX12_OBJECT_SCANNING_CONSUMER_H

#include "decode/dx12_object_scanning_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ObjectScanningConsumer : public Dx12ObjectScanningConsumerBase
{
  public:
    Dx12ObjectScanningConsumer() {}
    virtual ~Dx12ObjectScanningConsumer() override {}

    virtual void Process_ID3D12PipelineState_GetCachedBlob(const ApiCallInfo&                 call_info,
                                                           format::HandleId                   object_id,
                                                           HRESULT                            return_value,
                                                           HandlePointerDecoder<ID3D10Blob*>* ppBlob);

    virtual void Process_ID3D12GraphicsCommandList_ClearState(const ApiCallInfo& call_info,
                                                              format::HandleId   object_id,
                                                              format::HandleId   pPipelineState);

    virtual void Process_ID3D12GraphicsCommandList_Reset(const ApiCallInfo& call_info,
                                                         format::HandleId   object_id,
                                                         HRESULT            return_value,
                                                         format::HandleId   pAllocator,
                                                         format::HandleId   pInitialState);

    virtual void Process_ID3D12Device_CreateCommandList(const ApiCallInfo&           call_info,
                                                        format::HandleId             object_id,
                                                        HRESULT                      return_value,
                                                        UINT                         nodeMask,
                                                        D3D12_COMMAND_LIST_TYPE      type,
                                                        format::HandleId             pCommandAllocator,
                                                        format::HandleId             pInitialState,
                                                        Decoded_GUID                 riid,
                                                        HandlePointerDecoder<void*>* ppCommandList);

    virtual void Process_ID3D12GraphicsCommandList_SetPipelineState(const ApiCallInfo& call_info,
                                                                    format::HandleId   object_id,
                                                                    format::HandleId   pPipelineState);

    virtual void Process_ID3D12GraphicsCommandList4_SetPipelineState1(const ApiCallInfo& call_info,
                                                                      format::HandleId   object_id,
                                                                      format::HandleId   pStateObject);

    virtual void Process_ID3D12Device_CreateGraphicsPipelineState(
        const ApiCallInfo&                                                call_info,
        format::HandleId                                                  object_id,
        HRESULT                                                           return_value,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID                                                      riid,
        HandlePointerDecoder<void*>*                                      ppPipelineState);

    virtual void Process_ID3D12Device_CreateComputePipelineState(
        const ApiCallInfo&                                               call_info,
        format::HandleId                                                 object_id,
        HRESULT                                                          return_value,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID                                                     riid,
        HandlePointerDecoder<void*>*                                     ppPipelineState);

    virtual void Process_ID3D12PipelineLibrary_StorePipeline(const ApiCallInfo& call_info,
                                                             format::HandleId   object_id,
                                                             HRESULT            return_value,
                                                             WStringDecoder*    pName,
                                                             format::HandleId   pPipeline);

    virtual void Process_ID3D12Device_Evict(const ApiCallInfo&                     call_info,
                                            format::HandleId                       object_id,
                                            HRESULT                                return_value,
                                            UINT                                   NumObjects,
                                            HandlePointerDecoder<ID3D12Pageable*>* ppObjects);

    virtual void Process_ID3D12Device_MakeResident(const ApiCallInfo&                     call_info,
                                                   format::HandleId                       object_id,
                                                   HRESULT                                return_value,
                                                   UINT                                   NumObjects,
                                                   HandlePointerDecoder<ID3D12Pageable*>* ppObjects);

    virtual void Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        const ApiCallInfo&                                                                call_info,
        format::HandleId                                                                  object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT                                                                              NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs);

    virtual void
    ProcessFillMemoryResourceValueCommand(const format::FillMemoryResourceValueCommandHeader& command_header,
                                          const uint8_t*                                      data);

    virtual void ProcessInitDx12AccelerationStructureCommand(
        const format::InitDx12AccelerationStructureCommandHeader&             command_header,
        const std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
        const uint8_t*                                                        build_inputs_data);

    void Process_ID3D12GraphicsCommandList_ExecuteIndirect(const ApiCallInfo& call_info,
                                                           format::HandleId   object_id,
                                                           format::HandleId   pCommandSignature,
                                                           UINT               MaxCommandCount,
                                                           format::HandleId   pArgumentBuffer,
                                                           UINT64             ArgumentBufferOffset,
                                                           format::HandleId   pCountBuffer,
                                                           UINT64             CountBufferOffset) override;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DX12_OBJECT_SCANNING_CONSUMER_H
