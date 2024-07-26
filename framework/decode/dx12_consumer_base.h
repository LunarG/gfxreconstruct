/*
** Copyright (c) 2023 Valve Corporation
** Copyright (c) 2021, 2023 LunarG, Inc.
** Copyright (c) 2025 Advanced Micro Devices, Inc. All rights reserved.
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#ifndef GFXRECON_DECODE_DX12_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_CONSUMER_BASE_H

#include "decode/metadata_consumer_base.h"
#include "decode/marker_consumer_base.h"
#include "decode/api_decoder.h"
#include "decode/dx_feature_data_decoder.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "format/api_call_id.h"

#include <d3d12.h>
#include <d3d11.h>
#include <d3d11_3.h>
#include <dxgi1_5.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12ConsumerBase : public MetadataConsumerBase, public MarkerConsumerBase
{
  public:
    Dx12ConsumerBase() {}
    virtual ~Dx12ConsumerBase() {}

    virtual void Process_DriverInfo(const char* info_record) {}

    virtual bool IsComplete(uint64_t block_index) { return false; }

    virtual void ProcessInitDx12AccelerationStructureCommand(
        const format::InitDx12AccelerationStructureCommandHeader&       command_header,
        std::vector<format::InitDx12AccelerationStructureGeometryDesc>& geometry_descs,
        const uint8_t*                                                  build_inputs_data)
    {}

    virtual void ProcessDxgiAdapterInfo(const format::DxgiAdapterInfoCommandHeader& adapter_info_header) {}

    virtual void ProcessDx12RuntimeInfo(const format::Dx12RuntimeInfoCommandHeader& runtime_info_header) {}

    virtual void Process_ID3D12Device_CheckFeatureSupport(format::HandleId      object_id,
                                                          HRESULT               original_result,
                                                          D3D12_FEATURE         feature,
                                                          DxFeatureDataDecoder* feature_data,
                                                          UINT                  feature_data_size)
    {}

    virtual void Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId      object_id,
                                                           HRESULT               original_result,
                                                           DXGI_FEATURE          feature,
                                                           DxFeatureDataDecoder* feature_data,
                                                           UINT                  feature_data_size)
    {}

    virtual void Process_ID3D12Resource_WriteToSubresource(format::HandleId                         object_id,
                                                           HRESULT                                  original_result,
                                                           UINT                                     DstSubresource,
                                                           StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                           void*                                    pSrcData,
                                                           UINT                                     SrcRowPitch,
                                                           UINT                                     SrcDepthPitch)
    {}

    virtual void ProcessSetEnvironmentVariablesCommand(format::SetEnvironmentVariablesCommand& header,
                                                       const char*                             env_string) {};

    virtual void ProcessInitializeMetaCommand(const format::InitializeMetaCommand& command_header,
                                              const uint8_t*                       parameters_data)
    {}

    virtual void Process_ID3D11Device_CheckFeatureSupport(const ApiCallInfo&    call_info,
                                                          format::HandleId      object_id,
                                                          HRESULT               return_value,
                                                          D3D11_FEATURE         feature,
                                                          DxFeatureDataDecoder* feature_data,
                                                          UINT                  feature_data_size)
    {}

    virtual void Process_ID3D11Device_CreateBuffer(const ApiCallInfo&                                    call_info,
                                                   format::HandleId                                      object_id,
                                                   HRESULT                                               return_value,
                                                   StructPointerDecoder<Decoded_D3D11_BUFFER_DESC>*      pDesc,
                                                   StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                                   HandlePointerDecoder<ID3D11Buffer*>*                  ppBuffer)
    {}

    virtual void
    Process_ID3D11Device_CreateTexture1D(const ApiCallInfo&                                    call_info,
                                         format::HandleId                                      object_id,
                                         HRESULT                                               return_value,
                                         StructPointerDecoder<Decoded_D3D11_TEXTURE1D_DESC>*   pDesc,
                                         StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                         HandlePointerDecoder<ID3D11Texture1D*>*               ppTexture1D)
    {}

    virtual void
    Process_ID3D11Device_CreateTexture2D(const ApiCallInfo&                                    call_info,
                                         format::HandleId                                      object_id,
                                         HRESULT                                               return_value,
                                         StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC>*   pDesc,
                                         StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                         HandlePointerDecoder<ID3D11Texture2D*>*               ppTexture2D)
    {}

    virtual void
    Process_ID3D11Device_CreateTexture3D(const ApiCallInfo&                                    call_info,
                                         format::HandleId                                      object_id,
                                         HRESULT                                               return_value,
                                         StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC>*   pDesc,
                                         StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                         HandlePointerDecoder<ID3D11Texture3D*>*               ppTexture3D)
    {}

    virtual void Process_ID3D11DeviceContext_UpdateSubresource(const ApiCallInfo&                       call_info,
                                                               format::HandleId                         object_id,
                                                               format::HandleId                         pDstResource,
                                                               UINT                                     DstSubresource,
                                                               StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                               PointerDecoder<uint8_t>*                 pSrcData,
                                                               UINT                                     SrcRowPitch,
                                                               UINT                                     SrcDepthPitch)
    {}

    virtual void Process_ID3D11DeviceContext1_UpdateSubresource1(const ApiCallInfo& call_info,
                                                                 format::HandleId   object_id,
                                                                 format::HandleId   pDstResource,
                                                                 UINT               DstSubresource,
                                                                 StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                                 PointerDecoder<uint8_t>*                 pSrcData,
                                                                 UINT                                     SrcRowPitch,
                                                                 UINT                                     SrcDepthPitch,
                                                                 UINT                                     CopyFlags)
    {}

    virtual void
    Process_ID3D11Device3_CreateTexture2D1(const ApiCallInfo&                                    call_info,
                                           format::HandleId                                      object_id,
                                           HRESULT                                               return_value,
                                           StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC1>*  pDesc,
                                           StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                           HandlePointerDecoder<ID3D11Texture2D1*>*              ppTexture2D)
    {}

    virtual void
    Process_ID3D11Device3_CreateTexture3D1(const ApiCallInfo&                                    call_info,
                                           format::HandleId                                      object_id,
                                           HRESULT                                               return_value,
                                           StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC1>*  pDesc,
                                           StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                           HandlePointerDecoder<ID3D11Texture3D1*>*              ppTexture3D)
    {}

    virtual void Process_ID3D11Device3_WriteToSubresource(const ApiCallInfo&                       call_info,
                                                          format::HandleId                         object_id,
                                                          format::HandleId                         pDstResource,
                                                          UINT                                     DstSubresource,
                                                          StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                          PointerDecoder<uint8_t>*                 pSrcData,
                                                          UINT                                     SrcRowPitch,
                                                          UINT                                     SrcDepthPitch)
    {}

    virtual void SetCurrentBlockIndex(uint64_t block_index) override { block_index_ = block_index; }

    void SetCurrentApiCallId(format::ApiCallId api_call_id) { current_api_call_id_ = api_call_id; }

    bool ContainsDxrWorkload() const { return dxr_workload_; }

    bool ContainsEiWorkload() const { return ei_workload_; }

    bool ContainsOptFillMem() const { return opt_fillmem_; }

    uint32_t GetDXGITestPresentCount() const { return dxgi_present_test_; }

  protected:
    auto GetCurrentBlockIndex() { return block_index_; }
    auto GetCurrentApiCallId() { return current_api_call_id_; }

    bool     dxr_workload_{ false };
    bool     ei_workload_{ false };
    bool     opt_fillmem_{ false };
    uint32_t dxgi_present_test_{ 0 };

  private:
    format::ApiCallId current_api_call_id_{ format::ApiCall_Unknown };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_CONSUMER_BASE_H
