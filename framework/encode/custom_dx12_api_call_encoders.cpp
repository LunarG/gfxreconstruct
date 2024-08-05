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

#include "generated/generated_dx12_api_call_encoders.h"
#include "encode/custom_dx12_api_call_encoders.h"

#include "encode/custom_dx12_struct_encoders.h"
#include "encode/d3d12_capture_manager.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void Encode_ID3D12Device_CheckFeatureSupport(ID3D12Device_Wrapper* wrapper,
                                             HRESULT               result,
                                             D3D12_FEATURE         Feature,
                                             void*                 pFeatureSupportData,
                                             UINT                  FeatureSupportDataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(
        format::ApiCallId::ApiCall_ID3D12Device_CheckFeatureSupport, wrapper->GetCaptureId());
    if (encoder)
    {
        encoder->EncodeEnumValue(Feature);
        EncodeD3D12FeatureStruct(encoder, pFeatureSupportData, Feature);
        encoder->EncodeUInt32Value(FeatureSupportDataSize);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory5_CheckFeatureSupport(IDXGIFactory5_Wrapper* wrapper,
                                              HRESULT                result,
                                              DXGI_FEATURE           Feature,
                                              void*                  pFeatureSupportData,
                                              UINT                   FeatureSupportDataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(
        format::ApiCallId::ApiCall_IDXGIFactory5_CheckFeatureSupport, wrapper->GetCaptureId());
    if (encoder)
    {
        encoder->EncodeEnumValue(Feature);
        EncodeDXGIFeatureStruct(encoder, pFeatureSupportData, Feature);
        encoder->EncodeUInt32Value(FeatureSupportDataSize);
        encoder->EncodeInt32Value(result);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource_WriteToSubresource(ID3D12Resource_Wrapper* wrapper,
                                              HRESULT                 return_value,
                                              UINT                    DstSubresource,
                                              const D3D12_BOX*        pDstBox,
                                              const void*             pSrcData,
                                              UINT                    SrcRowPitch,
                                              UINT                    SrcDepthPitch)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(
        format::ApiCallId::ApiCall_ID3D12Resource_WriteToSubresource, wrapper->GetCaptureId());
    if (encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(DstSubresource);
        EncodeStructPtr(encoder, pDstBox);
        encoder->EncodeVoidArray(
            pSrcData,
            static_cast<size_t>(gfxrecon::graphics::dx12::GetSubresourceWriteDataSize(
                wrapper->GetWrappedObjectAs<ID3D12Resource>(), DstSubresource, pDstBox, SrcRowPitch, SrcDepthPitch)));
        encoder->EncodeUInt32Value(SrcRowPitch);
        encoder->EncodeUInt32Value(SrcDepthPitch);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_ExecuteCommandLists(ID3D12CommandQueue_Wrapper* wrapper,
                                                   UINT                        NumCommandLists,
                                                   ID3D12CommandList* const*   ppCommandLists)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(
        format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists, wrapper->GetCaptureId());
    if (encoder)
    {
        auto trim_boundary = D3D12CaptureManager::Get()->GetTrimBundary();
        if (trim_boundary == CaptureSettings::TrimBoundary::kDrawcalls)
        {
            auto trim_drawcalls   = D3D12CaptureManager::Get()->GetTrimDrawcalls();
            GFXRECON_ASSERT(NumCommandLists >= trim_drawcalls.command_index);

            encoder->EncodeUInt32Value(trim_drawcalls.command_index);

            std::vector<ID3D12CommandList*> commandLists;
            commandLists.resize(trim_drawcalls.command_index);
            util::platform::MemoryCopy(commandLists.data(),
                                       trim_drawcalls.command_index * sizeof (ID3D12CommandList*),
                                       ppCommandLists,
                                       trim_drawcalls.command_index * sizeof(ID3D12CommandList*));

            encoder->EncodeObjectArray(commandLists.data(), trim_drawcalls.command_index);
            D3D12CaptureManager::Get()->EndMethodCallCapture();
        }
        else
        {
            encoder->EncodeUInt32Value(NumCommandLists);
            encoder->EncodeObjectArray(ppCommandLists, NumCommandLists);
            D3D12CaptureManager::Get()->EndMethodCallCapture();
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
