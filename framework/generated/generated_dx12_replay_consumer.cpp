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
** This file is generated from dx12_replay_consumer_body_generator.py.
**
*/

#include "generated/generated_dx12_replay_consumer.h"

#include "decode/custom_dx12_struct_object_mappers.h"
#include "generated/generated_dx12_struct_object_mappers.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12ReplayConsumer::Process_CreateDXGIFactory(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    if(!ppFactory->IsNull()) ppFactory->SetHandleLength(1);
    auto out_p_ppFactory    = ppFactory->GetPointer();
    auto out_hp_ppFactory   = ppFactory->GetHandlePointer();
    auto replay_result = CreateDXGIFactory(*riid.decoded_value,
                                           out_hp_ppFactory);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppFactory, out_hp_ppFactory, format::ApiCall_CreateDXGIFactory);
    }
    CheckReplayResult("CreateDXGIFactory", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_CreateDXGIFactory1(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    if(!ppFactory->IsNull()) ppFactory->SetHandleLength(1);
    auto out_p_ppFactory    = ppFactory->GetPointer();
    auto out_hp_ppFactory   = ppFactory->GetHandlePointer();
    auto replay_result = CreateDXGIFactory1(*riid.decoded_value,
                                            out_hp_ppFactory);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppFactory, out_hp_ppFactory, format::ApiCall_CreateDXGIFactory1);
    }
    CheckReplayResult("CreateDXGIFactory1", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_CreateDXGIFactory2(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    UINT                                        Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    DxObjectInfo object_info_ppFactory{};
    if(!ppFactory->IsNull())
    {
        ppFactory->SetHandleLength(1);
        ppFactory->SetConsumerData(0, &object_info_ppFactory);
    }
    auto replay_result = OverrideCreateDXGIFactory2(return_value,
                                                    Flags,
                                                    riid,
                                                    ppFactory);
    if (SUCCEEDED(replay_result))
    {
        AddObject(ppFactory->GetPointer(), ppFactory->GetHandlePointer(), std::move(object_info_ppFactory), format::ApiCall_CreateDXGIFactory2);
    }
    CheckReplayResult("CreateDXGIFactory2", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_DXGIGetDebugInterface1(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    UINT                                        Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                pDebug)
{
    if(!pDebug->IsNull()) pDebug->SetHandleLength(1);
    auto out_p_pDebug    = pDebug->GetPointer();
    auto out_hp_pDebug   = pDebug->GetHandlePointer();
    auto replay_result = DXGIGetDebugInterface1(Flags,
                                                *riid.decoded_value,
                                                out_hp_pDebug);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_pDebug, out_hp_pDebug, format::ApiCall_DXGIGetDebugInterface1);
    }
    CheckReplayResult("DXGIGetDebugInterface1", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_DXGIDeclareAdapterRemovalSupport(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value)
{
    auto replay_result = DXGIDeclareAdapterRemovalSupport();
    CheckReplayResult("DXGIDeclareAdapterRemovalSupport", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12SerializeRootSignature(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION                  Version,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob,
    HandlePointerDecoder<ID3D10Blob*>*          ppErrorBlob)
{
    if(!ppBlob->IsNull()) ppBlob->SetHandleLength(1);
    auto out_p_ppBlob    = ppBlob->GetPointer();
    auto out_hp_ppBlob   = ppBlob->GetHandlePointer();
    if(!ppErrorBlob->IsNull()) ppErrorBlob->SetHandleLength(1);
    auto out_p_ppErrorBlob    = ppErrorBlob->GetPointer();
    auto out_hp_ppErrorBlob   = ppErrorBlob->GetHandlePointer();
    auto replay_result = D3D12SerializeRootSignature(pRootSignature->GetPointer(),
                                                     Version,
                                                     out_hp_ppBlob,
                                                     out_hp_ppErrorBlob);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppBlob, out_hp_ppBlob, format::ApiCall_D3D12SerializeRootSignature);
        AddObject(out_p_ppErrorBlob, out_hp_ppErrorBlob, format::ApiCall_D3D12SerializeRootSignature);
    }
    CheckReplayResult("D3D12SerializeRootSignature", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12CreateRootSignatureDeserializer(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pSrcData,
    SIZE_T                                      SrcDataSizeInBytes,
    Decoded_GUID                                pRootSignatureDeserializerInterface,
    HandlePointerDecoder<void*>*                ppRootSignatureDeserializer)
{
    if(!ppRootSignatureDeserializer->IsNull()) ppRootSignatureDeserializer->SetHandleLength(1);
    auto out_p_ppRootSignatureDeserializer    = ppRootSignatureDeserializer->GetPointer();
    auto out_hp_ppRootSignatureDeserializer   = ppRootSignatureDeserializer->GetHandlePointer();
    auto replay_result = D3D12CreateRootSignatureDeserializer(pSrcData->GetPointer(),
                                                              SrcDataSizeInBytes,
                                                              *pRootSignatureDeserializerInterface.decoded_value,
                                                              out_hp_ppRootSignatureDeserializer);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppRootSignatureDeserializer, out_hp_ppRootSignatureDeserializer, format::ApiCall_D3D12CreateRootSignatureDeserializer);
    }
    CheckReplayResult("D3D12CreateRootSignatureDeserializer", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12SerializeVersionedRootSignature(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob,
    HandlePointerDecoder<ID3D10Blob*>*          ppErrorBlob)
{
    if(!ppBlob->IsNull()) ppBlob->SetHandleLength(1);
    auto out_p_ppBlob    = ppBlob->GetPointer();
    auto out_hp_ppBlob   = ppBlob->GetHandlePointer();
    if(!ppErrorBlob->IsNull()) ppErrorBlob->SetHandleLength(1);
    auto out_p_ppErrorBlob    = ppErrorBlob->GetPointer();
    auto out_hp_ppErrorBlob   = ppErrorBlob->GetHandlePointer();
    auto replay_result = D3D12SerializeVersionedRootSignature(pRootSignature->GetPointer(),
                                                              out_hp_ppBlob,
                                                              out_hp_ppErrorBlob);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppBlob, out_hp_ppBlob, format::ApiCall_D3D12SerializeVersionedRootSignature);
        AddObject(out_p_ppErrorBlob, out_hp_ppErrorBlob, format::ApiCall_D3D12SerializeVersionedRootSignature);
    }
    CheckReplayResult("D3D12SerializeVersionedRootSignature", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pSrcData,
    SIZE_T                                      SrcDataSizeInBytes,
    Decoded_GUID                                pRootSignatureDeserializerInterface,
    HandlePointerDecoder<void*>*                ppRootSignatureDeserializer)
{
    if(!ppRootSignatureDeserializer->IsNull()) ppRootSignatureDeserializer->SetHandleLength(1);
    auto out_p_ppRootSignatureDeserializer    = ppRootSignatureDeserializer->GetPointer();
    auto out_hp_ppRootSignatureDeserializer   = ppRootSignatureDeserializer->GetHandlePointer();
    auto replay_result = D3D12CreateVersionedRootSignatureDeserializer(pSrcData->GetPointer(),
                                                                       SrcDataSizeInBytes,
                                                                       *pRootSignatureDeserializerInterface.decoded_value,
                                                                       out_hp_ppRootSignatureDeserializer);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppRootSignatureDeserializer, out_hp_ppRootSignatureDeserializer, format::ApiCall_D3D12CreateVersionedRootSignatureDeserializer);
    }
    CheckReplayResult("D3D12CreateVersionedRootSignatureDeserializer", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12CreateDevice(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    format::HandleId                            pAdapter,
    D3D_FEATURE_LEVEL                           MinimumFeatureLevel,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppDevice)
{
    auto in_pAdapter = GetObjectInfo(pAdapter);
    DxObjectInfo object_info_ppDevice{};
    if(!ppDevice->IsNull())
    {
        ppDevice->SetHandleLength(1);
        ppDevice->SetConsumerData(0, &object_info_ppDevice);
    }
    auto replay_result = OverrideD3D12CreateDevice(return_value,
                                                   in_pAdapter,
                                                   MinimumFeatureLevel,
                                                   riid,
                                                   ppDevice);
    if (SUCCEEDED(replay_result))
    {
        AddObject(ppDevice->GetPointer(), ppDevice->GetHandlePointer(), std::move(object_info_ppDevice), format::ApiCall_D3D12CreateDevice);
    }
    CheckReplayResult("D3D12CreateDevice", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12GetDebugInterface(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDebug)
{
    if(!ppvDebug->IsNull()) ppvDebug->SetHandleLength(1);
    auto out_p_ppvDebug    = ppvDebug->GetPointer();
    auto out_hp_ppvDebug   = ppvDebug->GetHandlePointer();
    auto replay_result = D3D12GetDebugInterface(*riid.decoded_value,
                                                out_hp_ppvDebug);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppvDebug, out_hp_ppvDebug, format::ApiCall_D3D12GetDebugInterface);
    }
    CheckReplayResult("D3D12GetDebugInterface", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12EnableExperimentalFeatures(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    UINT                                        NumFeatures,
    StructPointerDecoder<Decoded_GUID>*         pIIDs,
    PointerDecoder<uint8_t>*                    pConfigurationStructs,
    PointerDecoder<UINT>*                       pConfigurationStructSizes)
{
    auto replay_result = D3D12EnableExperimentalFeatures(NumFeatures,
                                                         pIIDs->GetPointer(),
                                                         pConfigurationStructs->GetPointer(),
                                                         pConfigurationStructSizes->GetPointer());
    CheckReplayResult("D3D12EnableExperimentalFeatures", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12GetInterface(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                rclsid,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDebug)
{
    if(!ppvDebug->IsNull()) ppvDebug->SetHandleLength(1);
    auto out_p_ppvDebug    = ppvDebug->GetPointer();
    auto out_hp_ppvDebug   = ppvDebug->GetHandlePointer();
    auto replay_result = D3D12GetInterface(*rclsid.decoded_value,
                                           *riid.decoded_value,
                                           out_hp_ppvDebug);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppvDebug, out_hp_ppvDebug, format::ApiCall_D3D12GetInterface);
    }
    CheckReplayResult("D3D12GetInterface", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D11CreateDevice(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    format::HandleId                            pAdapter,
    D3D_DRIVER_TYPE                             DriverType,
    uint64_t                                    Software,
    UINT                                        Flags,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pFeatureLevels,
    UINT                                        FeatureLevels,
    UINT                                        SDKVersion,
    HandlePointerDecoder<ID3D11Device*>*        ppDevice,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pFeatureLevel,
    HandlePointerDecoder<ID3D11DeviceContext*>* ppImmediateContext)
{
    auto in_pAdapter = GetObjectInfo(pAdapter);
    DxObjectInfo object_info_ppDevice{};
    if(!ppDevice->IsNull())
    {
        ppDevice->SetHandleLength(1);
        ppDevice->SetConsumerData(0, &object_info_ppDevice);
    }
    if(!pFeatureLevel->IsNull())
    {
        pFeatureLevel->AllocateOutputData(1);
    }
    DxObjectInfo object_info_ppImmediateContext{};
    if(!ppImmediateContext->IsNull())
    {
        ppImmediateContext->SetHandleLength(1);
        ppImmediateContext->SetConsumerData(0, &object_info_ppImmediateContext);
    }
    auto replay_result = OverrideD3D11CreateDevice(return_value,
                                                   in_pAdapter,
                                                   DriverType,
                                                   Software,
                                                   Flags,
                                                   pFeatureLevels,
                                                   FeatureLevels,
                                                   SDKVersion,
                                                   ppDevice,
                                                   pFeatureLevel,
                                                   ppImmediateContext);
    if (SUCCEEDED(replay_result))
    {
        AddObject(ppDevice->GetPointer(), ppDevice->GetHandlePointer(), std::move(object_info_ppDevice), format::ApiCall_D3D11CreateDevice);
        AddObject(ppImmediateContext->GetPointer(), ppImmediateContext->GetHandlePointer(), std::move(object_info_ppImmediateContext), format::ApiCall_D3D11CreateDevice);
    }
    CheckReplayResult("D3D11CreateDevice", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D11CreateDeviceAndSwapChain(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    format::HandleId                            pAdapter,
    D3D_DRIVER_TYPE                             DriverType,
    uint64_t                                    Software,
    UINT                                        Flags,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pFeatureLevels,
    UINT                                        FeatureLevels,
    UINT                                        SDKVersion,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pSwapChainDesc,
    HandlePointerDecoder<IDXGISwapChain*>*      ppSwapChain,
    HandlePointerDecoder<ID3D11Device*>*        ppDevice,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pFeatureLevel,
    HandlePointerDecoder<ID3D11DeviceContext*>* ppImmediateContext)
{
    auto in_pAdapter = GetObjectInfo(pAdapter);
    DxObjectInfo object_info_ppSwapChain{};
    if(!ppSwapChain->IsNull())
    {
        ppSwapChain->SetHandleLength(1);
        ppSwapChain->SetConsumerData(0, &object_info_ppSwapChain);
    }
    DxObjectInfo object_info_ppDevice{};
    if(!ppDevice->IsNull())
    {
        ppDevice->SetHandleLength(1);
        ppDevice->SetConsumerData(0, &object_info_ppDevice);
    }
    if(!pFeatureLevel->IsNull())
    {
        pFeatureLevel->AllocateOutputData(1);
    }
    DxObjectInfo object_info_ppImmediateContext{};
    if(!ppImmediateContext->IsNull())
    {
        ppImmediateContext->SetHandleLength(1);
        ppImmediateContext->SetConsumerData(0, &object_info_ppImmediateContext);
    }
    auto replay_result = OverrideD3D11CreateDeviceAndSwapChain(return_value,
                                                               in_pAdapter,
                                                               DriverType,
                                                               Software,
                                                               Flags,
                                                               pFeatureLevels,
                                                               FeatureLevels,
                                                               SDKVersion,
                                                               pSwapChainDesc,
                                                               ppSwapChain,
                                                               ppDevice,
                                                               pFeatureLevel,
                                                               ppImmediateContext);
    if (SUCCEEDED(replay_result))
    {
        AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info_ppSwapChain), format::ApiCall_D3D11CreateDeviceAndSwapChain);
        AddObject(ppDevice->GetPointer(), ppDevice->GetHandlePointer(), std::move(object_info_ppDevice), format::ApiCall_D3D11CreateDeviceAndSwapChain);
        AddObject(ppImmediateContext->GetPointer(), ppImmediateContext->GetHandlePointer(), std::move(object_info_ppImmediateContext), format::ApiCall_D3D11CreateDeviceAndSwapChain);
    }
    CheckReplayResult("D3D11CreateDeviceAndSwapChain", return_value, replay_result);
}

void Dx12ReplayConsumer::Process_D3D11On12CreateDevice(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    UINT                                        Flags,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pFeatureLevels,
    UINT                                        FeatureLevels,
    HandlePointerDecoder<IUnknown*>*            ppCommandQueues,
    UINT                                        NumQueues,
    UINT                                        NodeMask,
    HandlePointerDecoder<ID3D11Device*>*        ppDevice,
    HandlePointerDecoder<ID3D11DeviceContext*>* ppImmediateContext,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pChosenFeatureLevel)
{
    auto in_pDevice = MapObject<IUnknown>(pDevice);
    auto in_ppCommandQueues = MapObjects<IUnknown>(ppCommandQueues, NumQueues);
    if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
    auto out_p_ppDevice    = ppDevice->GetPointer();
    auto out_hp_ppDevice   = ppDevice->GetHandlePointer();
    if(!ppImmediateContext->IsNull()) ppImmediateContext->SetHandleLength(1);
    auto out_p_ppImmediateContext    = ppImmediateContext->GetPointer();
    auto out_hp_ppImmediateContext   = ppImmediateContext->GetHandlePointer();
    if(!pChosenFeatureLevel->IsNull())
    {
        pChosenFeatureLevel->AllocateOutputData(1);
    }
    auto replay_result = D3D11On12CreateDevice(in_pDevice,
                                               Flags,
                                               pFeatureLevels->GetPointer(),
                                               FeatureLevels,
                                               in_ppCommandQueues,
                                               NumQueues,
                                               NodeMask,
                                               out_hp_ppDevice,
                                               out_hp_ppImmediateContext,
                                               pChosenFeatureLevel->GetOutputPointer());
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppDevice, out_hp_ppDevice, format::ApiCall_D3D11On12CreateDevice);
        AddObject(out_p_ppImmediateContext, out_hp_ppImmediateContext, format::ApiCall_D3D11On12CreateDevice);
    }
    CheckReplayResult("D3D11On12CreateDevice", return_value, replay_result);
}
void Dx12ReplayConsumer::Process_IDXGIObject_SetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                Name,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPrivateData(*Name.decoded_value,
                                                           DataSize,
                                                           pData->GetPointer());
        CheckReplayResult("IDXGIObject_SetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_SetPrivateDataInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                Name,
    format::HandleId                            pUnknown)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pUnknown = MapObject<IUnknown>(pUnknown);
        auto replay_result = replay_object->SetPrivateDataInterface(*Name.decoded_value,
                                                                    in_pUnknown);
        CheckReplayResult("IDXGIObject_SetPrivateDataInterface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_GetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                Name,
    PointerDecoder<UINT>*                       pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDataSize->IsNull())
        {
            pDataSize->AllocateOutputData(1, GetOutputArrayCount("IDXGIObject::GetPrivateData", return_value, object_id, VariableLengthArrayIndices::kDxgiObjectArrayGetPrivateData, pDataSize, pData));
        }
        if(!pData->IsNull() && !pDataSize->IsNull())
        {
            pData->AllocateOutputData(*pDataSize->GetOutputPointer());
        }
        auto replay_result = replay_object->GetPrivateData(*Name.decoded_value,
                                                           pDataSize->GetOutputPointer(),
                                                           pData->GetOutputPointer());
        if (pData->IsNull() && !pDataSize->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kDxgiObjectArrayGetPrivateData, *pDataSize->GetOutputPointer()); }
        CheckReplayResult("IDXGIObject_GetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_GetParent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppParent)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppParent->IsNull()) ppParent->SetHandleLength(1);
        auto out_p_ppParent    = ppParent->GetPointer();
        auto out_hp_ppParent   = ppParent->GetHandlePointer();
        auto replay_result = replay_object->GetParent(*riid.decoded_value,
                                                      out_hp_ppParent);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppParent, out_hp_ppParent, format::ApiCall_IDXGIObject_GetParent);
        }
        CheckReplayResult("IDXGIObject_GetParent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDeviceSubObject_GetDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppDevice)
{
    auto replay_object = MapObject<IDXGIDeviceSubObject>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
        auto out_p_ppDevice    = ppDevice->GetPointer();
        auto out_hp_ppDevice   = ppDevice->GetHandlePointer();
        auto replay_result = replay_object->GetDevice(*riid.decoded_value,
                                                      out_hp_ppDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDevice, out_hp_ppDevice, format::ApiCall_IDXGIDeviceSubObject_GetDevice);
        }
        CheckReplayResult("IDXGIDeviceSubObject_GetDevice", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetSharedHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint64_t, void*>*            pSharedHandle)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        if(!pSharedHandle->IsNull())
        {
            pSharedHandle->AllocateOutputData(1);
        }
        auto out_p_pSharedHandle    = pSharedHandle->GetPointer();
        auto out_op_pSharedHandle   = reinterpret_cast<HANDLE*>(pSharedHandle->GetOutputPointer());
        auto replay_result = replay_object->GetSharedHandle(out_op_pSharedHandle);
        CheckReplayResult("IDXGIResource_GetSharedHandle", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pSharedHandle, out_p_pSharedHandle, format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle, "IDXGIResource_GetSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetUsage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<DXGI_USAGE>*                 pUsage)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetUsage(pUsage->GetPointer());
        CheckReplayResult("IDXGIResource_GetUsage", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_SetEvictionPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        EvictionPriority)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetEvictionPriority(EvictionPriority);
        CheckReplayResult("IDXGIResource_SetEvictionPriority", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetEvictionPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pEvictionPriority)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        if(!pEvictionPriority->IsNull())
        {
            pEvictionPriority->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetEvictionPriority(pEvictionPriority->GetOutputPointer());
        CheckReplayResult("IDXGIResource_GetEvictionPriority", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIKeyedMutex_AcquireSync(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      Key,
    DWORD                                       dwMilliseconds)
{
    auto replay_object = MapObject<IDXGIKeyedMutex>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->AcquireSync(Key,
                                                        dwMilliseconds);
        CheckReplayResult("IDXGIKeyedMutex_AcquireSync", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      Key)
{
    auto replay_object = MapObject<IDXGIKeyedMutex>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseSync(Key);
        CheckReplayResult("IDXGIKeyedMutex_ReleaseSync", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGISurface_GetDesc", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_Map(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
    UINT                                        MapFlags)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        if(!pLockedRect->IsNull())
        {
            pLockedRect->AllocateOutputData(1);
        }
        auto replay_result = replay_object->Map(pLockedRect->GetOutputPointer(),
                                                MapFlags);
        CheckReplayResult("IDXGISurface_Map", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_Unmap(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Unmap();
        CheckReplayResult("IDXGISurface_Unmap", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface1_GetDC(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    BOOL                                        Discard,
    PointerDecoder<uint64_t, void*>*            phdc)
{
    auto replay_object = MapObject<IDXGISurface1>(object_id);
    if (replay_object != nullptr)
    {
        if(!phdc->IsNull())
        {
            phdc->AllocateOutputData(1);
        }
        auto out_p_phdc    = phdc->GetPointer();
        auto out_op_phdc   = reinterpret_cast<HDC*>(phdc->GetOutputPointer());
        auto replay_result = replay_object->GetDC(Discard,
                                                  out_op_phdc);
        CheckReplayResult("IDXGISurface1_GetDC", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_phdc, out_p_phdc, format::ApiCallId::ApiCall_IDXGISurface1_GetDC, "IDXGISurface1_GetDC");
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface1_ReleaseDC(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pDirtyRect)
{
    auto replay_object = MapObject<IDXGISurface1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseDC(pDirtyRect->GetPointer());
        CheckReplayResult("IDXGISurface1_ReleaseDC", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_EnumOutputs(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Output,
    HandlePointerDecoder<IDXGIOutput*>*         ppOutput)
{
    auto replay_object = MapObject<IDXGIAdapter>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppOutput->IsNull()) ppOutput->SetHandleLength(1);
        auto out_p_ppOutput    = ppOutput->GetPointer();
        auto out_hp_ppOutput   = ppOutput->GetHandlePointer();
        auto replay_result = replay_object->EnumOutputs(Output,
                                                        out_hp_ppOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutput, out_hp_ppOutput, format::ApiCall_IDXGIAdapter_EnumOutputs);
        }
        CheckReplayResult("IDXGIAdapter_EnumOutputs", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter_GetDesc", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                InterfaceName,
    StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    auto replay_object = MapObject<IDXGIAdapter>(object_id);
    if (replay_object != nullptr)
    {
        if(!pUMDVersion->IsNull())
        {
            pUMDVersion->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckInterfaceSupport(*InterfaceName.decoded_value,
                                                                  pUMDVersion->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter_CheckInterfaceSupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGIOutput_GetDesc", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDisplayModeList(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 EnumFormat,
    UINT                                        Flags,
    PointerDecoder<UINT>*                       pNumModes,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNumModes->IsNull())
        {
            pNumModes->AllocateOutputData(1, GetOutputArrayCount("IDXGIOutput::GetDisplayModeList", return_value, object_id, VariableLengthArrayIndices::kDxgiOutputArrayGetDisplayModeList, pNumModes, pDesc));
        }
        if(!pDesc->IsNull() && !pNumModes->IsNull())
        {
            pDesc->AllocateOutputData(*pNumModes->GetOutputPointer());
        }
        auto replay_result = replay_object->GetDisplayModeList(EnumFormat,
                                                               Flags,
                                                               pNumModes->GetOutputPointer(),
                                                               pDesc->GetOutputPointer());
        if (pDesc->IsNull() && !pNumModes->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kDxgiOutputArrayGetDisplayModeList, *pNumModes->GetOutputPointer()); }
        CheckReplayResult("IDXGIOutput_GetDisplayModeList", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
    format::HandleId                            pConcernedDevice)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        if(!pClosestMatch->IsNull())
        {
            pClosestMatch->AllocateOutputData(1);
        }
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = replay_object->FindClosestMatchingMode(pModeToMatch->GetPointer(),
                                                                    pClosestMatch->GetOutputPointer(),
                                                                    in_pConcernedDevice);
        CheckReplayResult("IDXGIOutput_FindClosestMatchingMode", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_WaitForVBlank(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->WaitForVBlank();
        CheckReplayResult("IDXGIOutput_WaitForVBlank", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_TakeOwnership(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    BOOL                                        Exclusive)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        auto replay_result = replay_object->TakeOwnership(in_pDevice,
                                                          Exclusive);
        CheckReplayResult("IDXGIOutput_TakeOwnership", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_ReleaseOwnership(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ReleaseOwnership();
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        if(!pGammaCaps->IsNull())
        {
            pGammaCaps->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetGammaControlCapabilities(pGammaCaps->GetOutputPointer());
        CheckReplayResult("IDXGIOutput_GetGammaControlCapabilities", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_SetGammaControl(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetGammaControl(pArray->GetPointer());
        CheckReplayResult("IDXGIOutput_SetGammaControl", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetGammaControl(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        if(!pArray->IsNull())
        {
            pArray->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetGammaControl(pArray->GetOutputPointer());
        CheckReplayResult("IDXGIOutput_GetGammaControl", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_SetDisplaySurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pScanoutSurface)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pScanoutSurface = MapObject<IDXGISurface>(pScanoutSurface);
        auto replay_result = replay_object->SetDisplaySurface(in_pScanoutSurface);
        CheckReplayResult("IDXGIOutput_SetDisplaySurface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDestination)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDestination = MapObject<IDXGISurface>(pDestination);
        auto replay_result = replay_object->GetDisplaySurfaceData(in_pDestination);
        CheckReplayResult("IDXGIOutput_GetDisplaySurfaceData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetFrameStatistics(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        if(!pStats->IsNull())
        {
            pStats->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetFrameStatistics(pStats->GetOutputPointer());
        CheckReplayResult("IDXGIOutput_GetFrameStatistics", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_Present(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        SyncInterval,
    UINT                                        Flags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverridePresent(replay_object,
                                             return_value,
                                             SyncInterval,
                                             Flags);
        CheckReplayResult("IDXGISwapChain_Present", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Buffer,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppSurface)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppSurface{};
        if(!ppSurface->IsNull())
        {
            ppSurface->SetHandleLength(1);
            ppSurface->SetConsumerData(0, &object_info_ppSurface);
        }
        auto replay_result = OverrideGetBuffer(replay_object,
                                               return_value,
                                               Buffer,
                                               riid,
                                               ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSurface->GetPointer(), ppSurface->GetHandlePointer(), std::move(object_info_ppSurface), format::ApiCall_IDXGISwapChain_GetBuffer);
        }
        CheckReplayResult("IDXGISwapChain_GetBuffer", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_SetFullscreenState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    BOOL                                        Fullscreen,
    format::HandleId                            pTarget)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pTarget = GetObjectInfo(pTarget);
        auto replay_result = OverrideSetFullscreenState(replay_object,
                                                        return_value,
                                                        Fullscreen,
                                                        in_pTarget);
        CheckReplayResult("IDXGISwapChain_SetFullscreenState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetFullscreenState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<BOOL>*                       pFullscreen,
    HandlePointerDecoder<IDXGIOutput*>*         ppTarget)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFullscreen->IsNull())
        {
            pFullscreen->AllocateOutputData(1);
        }
        if(!ppTarget->IsNull()) ppTarget->SetHandleLength(1);
        auto out_p_ppTarget    = ppTarget->GetPointer();
        auto out_hp_ppTarget   = ppTarget->GetHandlePointer();
        auto replay_result = replay_object->GetFullscreenState(pFullscreen->GetOutputPointer(),
                                                               out_hp_ppTarget);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppTarget, out_hp_ppTarget, format::ApiCall_IDXGISwapChain_GetFullscreenState);
        }
        CheckReplayResult("IDXGISwapChain_GetFullscreenState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain_GetDesc", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_ResizeBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        BufferCount,
    UINT                                        Width,
    UINT                                        Height,
    DXGI_FORMAT                                 NewFormat,
    UINT                                        SwapChainFlags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideResizeBuffers(replay_object,
                                                   return_value,
                                                   BufferCount,
                                                   Width,
                                                   Height,
                                                   NewFormat,
                                                   SwapChainFlags);
        CheckReplayResult("IDXGISwapChain_ResizeBuffers", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_ResizeTarget(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ResizeTarget(pNewTargetParameters->GetPointer());
        CheckReplayResult("IDXGISwapChain_ResizeTarget", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetContainingOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<IDXGIOutput*>*         ppOutput)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppOutput->IsNull()) ppOutput->SetHandleLength(1);
        auto out_p_ppOutput    = ppOutput->GetPointer();
        auto out_hp_ppOutput   = ppOutput->GetHandlePointer();
        auto replay_result = replay_object->GetContainingOutput(out_hp_ppOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutput, out_hp_ppOutput, format::ApiCall_IDXGISwapChain_GetContainingOutput);
        }
        CheckReplayResult("IDXGISwapChain_GetContainingOutput", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetFrameStatistics(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!pStats->IsNull())
        {
            pStats->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetFrameStatistics(pStats->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain_GetFrameStatistics", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetLastPresentCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pLastPresentCount)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!pLastPresentCount->IsNull())
        {
            pLastPresentCount->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetLastPresentCount(pLastPresentCount->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain_GetLastPresentCount", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_EnumAdapters(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Adapter,
    HandlePointerDecoder<IDXGIAdapter*>*        ppAdapter)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto out_p_ppAdapter    = ppAdapter->GetPointer();
        auto out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapters(Adapter,
                                                         out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppAdapter, out_hp_ppAdapter, format::ApiCall_IDXGIFactory_EnumAdapters);
        }
        CheckReplayResult("IDXGIFactory_EnumAdapters", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_MakeWindowAssociation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    WindowHandle,
    UINT                                        Flags)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation, "IDXGIFactory_MakeWindowAssociation"));
        auto replay_result = replay_object->MakeWindowAssociation(in_WindowHandle,
                                                                  Flags);
        CheckReplayResult("IDXGIFactory_MakeWindowAssociation", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_GetWindowAssociation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint64_t, void*>*            pWindowHandle)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        if(!pWindowHandle->IsNull())
        {
            pWindowHandle->AllocateOutputData(1);
        }
        auto out_p_pWindowHandle    = pWindowHandle->GetPointer();
        auto out_op_pWindowHandle   = reinterpret_cast<HWND*>(pWindowHandle->GetOutputPointer());
        auto replay_result = replay_object->GetWindowAssociation(out_op_pWindowHandle);
        CheckReplayResult("IDXGIFactory_GetWindowAssociation", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pWindowHandle, out_p_pWindowHandle, format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation, "IDXGIFactory_GetWindowAssociation");
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_CreateSwapChain(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
    HandlePointerDecoder<IDXGISwapChain*>*      ppSwapChain)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pDevice = GetObjectInfo(pDevice);
        DxObjectInfo object_info_ppSwapChain{};
        if(!ppSwapChain->IsNull())
        {
            ppSwapChain->SetHandleLength(1);
            ppSwapChain->SetConsumerData(0, &object_info_ppSwapChain);
        }
        auto replay_result = OverrideCreateSwapChain(replay_object,
                                                     return_value,
                                                     in_pDevice,
                                                     pDesc,
                                                     ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info_ppSwapChain), format::ApiCall_IDXGIFactory_CreateSwapChain);
        }
        CheckReplayResult("IDXGIFactory_CreateSwapChain", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    Module,
    HandlePointerDecoder<IDXGIAdapter*>*        ppAdapter)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto in_Module = static_cast<HMODULE>(PreProcessExternalObject(Module, format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter, "IDXGIFactory_CreateSoftwareAdapter"));
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto out_p_ppAdapter    = ppAdapter->GetPointer();
        auto out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = replay_object->CreateSoftwareAdapter(in_Module,
                                                                  out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppAdapter, out_hp_ppAdapter, format::ApiCall_IDXGIFactory_CreateSoftwareAdapter);
        }
        CheckReplayResult("IDXGIFactory_CreateSoftwareAdapter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_GetAdapter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<IDXGIAdapter*>*        pAdapter)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pAdapter->IsNull()) pAdapter->SetHandleLength(1);
        auto out_p_pAdapter    = pAdapter->GetPointer();
        auto out_hp_pAdapter   = pAdapter->GetHandlePointer();
        auto replay_result = replay_object->GetAdapter(out_hp_pAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_pAdapter, out_hp_pAdapter, format::ApiCall_IDXGIDevice_GetAdapter);
        }
        CheckReplayResult("IDXGIDevice_GetAdapter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_CreateSurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc,
    UINT                                        NumSurfaces,
    DXGI_USAGE                                  Usage,
    StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE>* pSharedResource,
    HandlePointerDecoder<IDXGISurface*>*        ppSurface)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(NumSurfaces);
        auto out_p_ppSurface    = ppSurface->GetPointer();
        auto out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = replay_object->CreateSurface(pDesc->GetPointer(),
                                                          NumSurfaces,
                                                          Usage,
                                                          pSharedResource->GetPointer(),
                                                          out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObjects(out_p_ppSurface, ppSurface->GetLength(), out_hp_ppSurface, NumSurfaces, format::ApiCall_IDXGIDevice_CreateSurface);
        }
        CheckReplayResult("IDXGIDevice_CreateSurface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_QueryResourceResidency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<IUnknown*>*            ppResources,
    PointerDecoder<DXGI_RESIDENCY>*             pResidencyStatus,
    UINT                                        NumResources)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IUnknown>(ppResources, NumResources);
        if(!pResidencyStatus->IsNull())
        {
            pResidencyStatus->AllocateOutputData(NumResources);
        }
        auto replay_result = replay_object->QueryResourceResidency(in_ppResources,
                                                                   pResidencyStatus->GetOutputPointer(),
                                                                   NumResources);
        CheckReplayResult("IDXGIDevice_QueryResourceResidency", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    INT                                         Priority)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetGPUThreadPriority(Priority);
        CheckReplayResult("IDXGIDevice_SetGPUThreadPriority", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<INT>*                        pPriority)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pPriority->IsNull())
        {
            pPriority->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetGPUThreadPriority(pPriority->GetOutputPointer());
        CheckReplayResult("IDXGIDevice_GetGPUThreadPriority", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory1_EnumAdapters1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Adapter,
    HandlePointerDecoder<IDXGIAdapter1*>*       ppAdapter)
{
    auto replay_object = MapObject<IDXGIFactory1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto out_p_ppAdapter    = ppAdapter->GetPointer();
        auto out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapters1(Adapter,
                                                          out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppAdapter, out_hp_ppAdapter, format::ApiCall_IDXGIFactory1_EnumAdapters1);
        }
        CheckReplayResult("IDXGIFactory1_EnumAdapters1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory1_IsCurrent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<IDXGIFactory1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsCurrent();
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc1(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter1_GetDesc1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        MaxLatency)
{
    auto replay_object = MapObject<IDXGIDevice1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMaximumFrameLatency(MaxLatency);
        CheckReplayResult("IDXGIDevice1_SetMaximumFrameLatency", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = MapObject<IDXGIDevice1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pMaxLatency->IsNull())
        {
            pMaxLatency->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetMaximumFrameLatency(pMaxLatency->GetOutputPointer());
        CheckReplayResult("IDXGIDevice1_GetMaximumFrameLatency", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<IDXGIDisplayControl>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsStereoEnabled();
    }
}

void Dx12ReplayConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        enabled)
{
    auto replay_object = MapObject<IDXGIDisplayControl>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetStereoEnabled(enabled);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_AcquireNextFrame(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        TimeoutInMilliseconds,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
    HandlePointerDecoder<IDXGIResource*>*       ppDesktopResource)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFrameInfo->IsNull())
        {
            pFrameInfo->AllocateOutputData(1);
        }
        if(!ppDesktopResource->IsNull()) ppDesktopResource->SetHandleLength(1);
        auto out_p_ppDesktopResource    = ppDesktopResource->GetPointer();
        auto out_hp_ppDesktopResource   = ppDesktopResource->GetHandlePointer();
        auto replay_result = replay_object->AcquireNextFrame(TimeoutInMilliseconds,
                                                             pFrameInfo->GetOutputPointer(),
                                                             out_hp_ppDesktopResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDesktopResource, out_hp_ppDesktopResource, format::ApiCall_IDXGIOutputDuplication_AcquireNextFrame);
        }
        CheckReplayResult("IDXGIOutputDuplication_AcquireNextFrame", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        DirtyRectsBufferSize,
    StructPointerDecoder<Decoded_tagRECT>*      pDirtyRectsBuffer,
    PointerDecoder<UINT>*                       pDirtyRectsBufferSizeRequired)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDirtyRectsBuffer->IsNull())
        {
            pDirtyRectsBuffer->AllocateOutputData(DirtyRectsBufferSize/sizeof tagRECT);
        }
        if(!pDirtyRectsBufferSizeRequired->IsNull())
        {
            pDirtyRectsBufferSizeRequired->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetFrameDirtyRects(DirtyRectsBufferSize,
                                                               pDirtyRectsBuffer->GetOutputPointer(),
                                                               pDirtyRectsBufferSizeRequired->GetOutputPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFrameDirtyRects", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        MoveRectsBufferSize,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
    PointerDecoder<UINT>*                       pMoveRectsBufferSizeRequired)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        if(!pMoveRectBuffer->IsNull())
        {
            pMoveRectBuffer->AllocateOutputData(MoveRectsBufferSize/sizeof DXGI_OUTDUPL_MOVE_RECT);
        }
        if(!pMoveRectsBufferSizeRequired->IsNull())
        {
            pMoveRectsBufferSizeRequired->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetFrameMoveRects(MoveRectsBufferSize,
                                                              pMoveRectBuffer->GetOutputPointer(),
                                                              pMoveRectsBufferSizeRequired->GetOutputPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFrameMoveRects", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        PointerShapeBufferSize,
    PointerDecoder<uint8_t>*                    pPointerShapeBuffer,
    PointerDecoder<UINT>*                       pPointerShapeBufferSizeRequired,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        if(!pPointerShapeBuffer->IsNull())
        {
            pPointerShapeBuffer->AllocateOutputData(PointerShapeBufferSize);
        }
        if(!pPointerShapeBufferSizeRequired->IsNull())
        {
            pPointerShapeBufferSizeRequired->AllocateOutputData(1);
        }
        if(!pPointerShapeInfo->IsNull())
        {
            pPointerShapeInfo->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetFramePointerShape(PointerShapeBufferSize,
                                                                 pPointerShapeBuffer->GetOutputPointer(),
                                                                 pPointerShapeBufferSizeRequired->GetOutputPointer(),
                                                                 pPointerShapeInfo->GetOutputPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFramePointerShape", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        if(!pLockedRect->IsNull())
        {
            pLockedRect->AllocateOutputData(1);
        }
        auto replay_result = replay_object->MapDesktopSurface(pLockedRect->GetOutputPointer());
        CheckReplayResult("IDXGIOutputDuplication_MapDesktopSurface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnMapDesktopSurface();
        CheckReplayResult("IDXGIOutputDuplication_UnMapDesktopSurface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseFrame();
        CheckReplayResult("IDXGIOutputDuplication_ReleaseFrame", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface2_GetResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppParentResource,
    PointerDecoder<UINT>*                       pSubresourceIndex)
{
    auto replay_object = MapObject<IDXGISurface2>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppParentResource->IsNull()) ppParentResource->SetHandleLength(1);
        auto out_p_ppParentResource    = ppParentResource->GetPointer();
        auto out_hp_ppParentResource   = ppParentResource->GetHandlePointer();
        if(!pSubresourceIndex->IsNull())
        {
            pSubresourceIndex->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetResource(*riid.decoded_value,
                                                        out_hp_ppParentResource,
                                                        pSubresourceIndex->GetOutputPointer());
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppParentResource, out_hp_ppParentResource, format::ApiCall_IDXGISurface2_GetResource);
        }
        CheckReplayResult("IDXGISurface2_GetResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        index,
    HandlePointerDecoder<IDXGISurface2*>*       ppSurface)
{
    auto replay_object = MapObject<IDXGIResource1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(1);
        auto out_p_ppSurface    = ppSurface->GetPointer();
        auto out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = replay_object->CreateSubresourceSurface(index,
                                                                     out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSurface, out_hp_ppSurface, format::ApiCall_IDXGIResource1_CreateSubresourceSurface);
        }
        CheckReplayResult("IDXGIResource1_CreateSubresourceSurface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource1_CreateSharedHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
    DWORD                                       dwAccess,
    WStringDecoder*                             lpName,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto replay_object = MapObject<IDXGIResource1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHandle->IsNull())
        {
            pHandle->AllocateOutputData(1);
        }
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = replay_object->CreateSharedHandle(pAttributes->GetPointer(),
                                                               dwAccess,
                                                               lpName->GetPointer(),
                                                               out_op_pHandle);
        CheckReplayResult("IDXGIResource1_CreateSharedHandle", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHandle, out_p_pHandle, format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle, "IDXGIResource1_CreateSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice2_OfferResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY                Priority)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        auto replay_result = replay_object->OfferResources(NumResources,
                                                           in_ppResources,
                                                           Priority);
        CheckReplayResult("IDXGIDevice2_OfferResources", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice2_ReclaimResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    PointerDecoder<BOOL>*                       pDiscarded)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        if(!pDiscarded->IsNull())
        {
            pDiscarded->AllocateOutputData(NumResources);
        }
        auto replay_result = replay_object->ReclaimResources(NumResources,
                                                             in_ppResources,
                                                             pDiscarded->GetOutputPointer());
        CheckReplayResult("IDXGIDevice2_ReclaimResources", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent, "IDXGIDevice2_EnqueueSetEvent"));
        auto replay_result = replay_object->EnqueueSetEvent(in_hEvent);
        CheckReplayResult("IDXGIDevice2_EnqueueSetEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc1(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain1_GetDesc1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetFullscreenDesc(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain1_GetFullscreenDesc", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetHwnd(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint64_t, void*>*            pHwnd)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHwnd->IsNull())
        {
            pHwnd->AllocateOutputData(1);
        }
        auto out_p_pHwnd    = pHwnd->GetPointer();
        auto out_op_pHwnd   = reinterpret_cast<HWND*>(pHwnd->GetOutputPointer());
        auto replay_result = replay_object->GetHwnd(out_op_pHwnd);
        CheckReplayResult("IDXGISwapChain1_GetHwnd", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHwnd, out_p_pHwnd, format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd, "IDXGISwapChain1_GetHwnd");
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetCoreWindow(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                refiid,
    HandlePointerDecoder<void*>*                ppUnk)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppUnk->IsNull()) ppUnk->SetHandleLength(1);
        auto out_p_ppUnk    = ppUnk->GetPointer();
        auto out_hp_ppUnk   = ppUnk->GetHandlePointer();
        auto replay_result = replay_object->GetCoreWindow(*refiid.decoded_value,
                                                          out_hp_ppUnk);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppUnk, out_hp_ppUnk, format::ApiCall_IDXGISwapChain1_GetCoreWindow);
        }
        CheckReplayResult("IDXGISwapChain1_GetCoreWindow", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_Present1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        SyncInterval,
    UINT                                        PresentFlags,
    StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverridePresent1(replay_object,
                                              return_value,
                                              SyncInterval,
                                              PresentFlags,
                                              pPresentParameters);
        CheckReplayResult("IDXGISwapChain1_Present1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsTemporaryMonoSupported();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<IDXGIOutput*>*         ppRestrictToOutput)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRestrictToOutput->IsNull()) ppRestrictToOutput->SetHandleLength(1);
        auto out_p_ppRestrictToOutput    = ppRestrictToOutput->GetPointer();
        auto out_hp_ppRestrictToOutput   = ppRestrictToOutput->GetHandlePointer();
        auto replay_result = replay_object->GetRestrictToOutput(out_hp_ppRestrictToOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppRestrictToOutput, out_hp_ppRestrictToOutput, format::ApiCall_IDXGISwapChain1_GetRestrictToOutput);
        }
        CheckReplayResult("IDXGISwapChain1_GetRestrictToOutput", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetBackgroundColor(pColor->GetPointer());
        CheckReplayResult("IDXGISwapChain1_SetBackgroundColor", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pColor->IsNull())
        {
            pColor->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetBackgroundColor(pColor->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain1_GetBackgroundColor", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_SetRotation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_MODE_ROTATION                          Rotation)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetRotation(Rotation);
        CheckReplayResult("IDXGISwapChain1_SetRotation", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetRotation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<DXGI_MODE_ROTATION>*         pRotation)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pRotation->IsNull())
        {
            pRotation->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetRotation(pRotation->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain1_GetRotation", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsWindowedStereoEnabled();
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    uint64_t                                    hWnd,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
    format::HandleId                            pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pDevice = GetObjectInfo(pDevice);
        auto in_pRestrictToOutput = GetObjectInfo(pRestrictToOutput);
        DxObjectInfo object_info_ppSwapChain{};
        if(!ppSwapChain->IsNull())
        {
            ppSwapChain->SetHandleLength(1);
            ppSwapChain->SetConsumerData(0, &object_info_ppSwapChain);
        }
        auto replay_result = OverrideCreateSwapChainForHwnd(replay_object,
                                                            return_value,
                                                            in_pDevice,
                                                            hWnd,
                                                            pDesc,
                                                            pFullscreenDesc,
                                                            in_pRestrictToOutput,
                                                            ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info_ppSwapChain), format::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForHwnd", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    format::HandleId                            pWindow,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    format::HandleId                            pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pDevice = GetObjectInfo(pDevice);
        auto in_pWindow = GetObjectInfo(pWindow);
        auto in_pRestrictToOutput = GetObjectInfo(pRestrictToOutput);
        DxObjectInfo object_info_ppSwapChain{};
        if(!ppSwapChain->IsNull())
        {
            ppSwapChain->SetHandleLength(1);
            ppSwapChain->SetConsumerData(0, &object_info_ppSwapChain);
        }
        auto replay_result = OverrideCreateSwapChainForCoreWindow(replay_object,
                                                                  return_value,
                                                                  in_pDevice,
                                                                  in_pWindow,
                                                                  pDesc,
                                                                  in_pRestrictToOutput,
                                                                  ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info_ppSwapChain), format::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForCoreWindow", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hResource,
    StructPointerDecoder<Decoded_LUID>*         pLuid)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hResource = static_cast<HANDLE>(PreProcessExternalObject(hResource, format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid, "IDXGIFactory2_GetSharedResourceAdapterLuid"));
        if(!pLuid->IsNull())
        {
            pLuid->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetSharedResourceAdapterLuid(in_hResource,
                                                                         pLuid->GetOutputPointer());
        CheckReplayResult("IDXGIFactory2_GetSharedResourceAdapterLuid", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    WindowHandle,
    UINT                                        wMsg,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow, "IDXGIFactory2_RegisterStereoStatusWindow"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterStereoStatusWindow(in_WindowHandle,
                                                                       wMsg,
                                                                       pdwCookie->GetOutputPointer());
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusWindow", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent, "IDXGIFactory2_RegisterStereoStatusEvent"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterStereoStatusEvent(in_hEvent,
                                                                      pdwCookie->GetOutputPointer());
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterStereoStatus(dwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    WindowHandle,
    UINT                                        wMsg,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow, "IDXGIFactory2_RegisterOcclusionStatusWindow"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterOcclusionStatusWindow(in_WindowHandle,
                                                                          wMsg,
                                                                          pdwCookie->GetOutputPointer());
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusWindow", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent, "IDXGIFactory2_RegisterOcclusionStatusEvent"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterOcclusionStatusEvent(in_hEvent,
                                                                         pdwCookie->GetOutputPointer());
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterOcclusionStatus(dwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForComposition(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    format::HandleId                            pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pDevice = GetObjectInfo(pDevice);
        auto in_pRestrictToOutput = GetObjectInfo(pRestrictToOutput);
        DxObjectInfo object_info_ppSwapChain{};
        if(!ppSwapChain->IsNull())
        {
            ppSwapChain->SetHandleLength(1);
            ppSwapChain->SetConsumerData(0, &object_info_ppSwapChain);
        }
        auto replay_result = OverrideCreateSwapChainForComposition(replay_object,
                                                                   return_value,
                                                                   in_pDevice,
                                                                   pDesc,
                                                                   in_pRestrictToOutput,
                                                                   ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info_ppSwapChain), format::ApiCall_IDXGIFactory2_CreateSwapChainForComposition);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForComposition", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter2_GetDesc2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc2(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter2_GetDesc2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 EnumFormat,
    UINT                                        Flags,
    PointerDecoder<UINT>*                       pNumModes,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNumModes->IsNull())
        {
            pNumModes->AllocateOutputData(1, GetOutputArrayCount("IDXGIOutput1::GetDisplayModeList1", return_value, object_id, VariableLengthArrayIndices::kDxgiOutput1ArrayGetDisplayModeList1, pNumModes, pDesc));
        }
        if(!pDesc->IsNull() && !pNumModes->IsNull())
        {
            pDesc->AllocateOutputData(*pNumModes->GetOutputPointer());
        }
        auto replay_result = replay_object->GetDisplayModeList1(EnumFormat,
                                                                Flags,
                                                                pNumModes->GetOutputPointer(),
                                                                pDesc->GetOutputPointer());
        if (pDesc->IsNull() && !pNumModes->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kDxgiOutput1ArrayGetDisplayModeList1, *pNumModes->GetOutputPointer()); }
        CheckReplayResult("IDXGIOutput1_GetDisplayModeList1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
    format::HandleId                            pConcernedDevice)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pClosestMatch->IsNull())
        {
            pClosestMatch->AllocateOutputData(1);
        }
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = replay_object->FindClosestMatchingMode1(pModeToMatch->GetPointer(),
                                                                     pClosestMatch->GetOutputPointer(),
                                                                     in_pConcernedDevice);
        CheckReplayResult("IDXGIOutput1_FindClosestMatchingMode1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDestination)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDestination = MapObject<IDXGIResource>(pDestination);
        auto replay_result = replay_object->GetDisplaySurfaceData1(in_pDestination);
        CheckReplayResult("IDXGIOutput1_GetDisplaySurfaceData1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_DuplicateOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        if(!ppOutputDuplication->IsNull()) ppOutputDuplication->SetHandleLength(1);
        auto out_p_ppOutputDuplication    = ppOutputDuplication->GetPointer();
        auto out_hp_ppOutputDuplication   = ppOutputDuplication->GetHandlePointer();
        auto replay_result = replay_object->DuplicateOutput(in_pDevice,
                                                            out_hp_ppOutputDuplication);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutputDuplication, out_hp_ppOutputDuplication, format::ApiCall_IDXGIOutput1_DuplicateOutput);
        }
        CheckReplayResult("IDXGIOutput1_DuplicateOutput", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice3_Trim(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<IDXGIDevice3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Trim();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetSourceSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Width,
    UINT                                        Height)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetSourceSize(Width,
                                                          Height);
        CheckReplayResult("IDXGISwapChain2_SetSourceSize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetSourceSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pWidth,
    PointerDecoder<UINT>*                       pHeight)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pWidth->IsNull())
        {
            pWidth->AllocateOutputData(1);
        }
        if(!pHeight->IsNull())
        {
            pHeight->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetSourceSize(pWidth->GetOutputPointer(),
                                                          pHeight->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain2_GetSourceSize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        MaxLatency)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMaximumFrameLatency(MaxLatency);
        CheckReplayResult("IDXGISwapChain2_SetMaximumFrameLatency", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pMaxLatency->IsNull())
        {
            pMaxLatency->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetMaximumFrameLatency(pMaxLatency->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain2_GetMaximumFrameLatency", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    uint64_t                                    return_value)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameLatencyWaitableObject();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMatrixTransform(pMatrix->GetPointer());
        CheckReplayResult("IDXGISwapChain2_SetMatrixTransform", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pMatrix->IsNull())
        {
            pMatrix->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetMatrixTransform(pMatrix->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain2_GetMatrixTransform", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput2_SupportsOverlays(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<IDXGIOutput2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SupportsOverlays();
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory3_GetCreationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<IDXGIFactory3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCreationFlags();
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        BufferToPresent,
    UINT                                        SyncInterval,
    UINT                                        Flags)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->PresentBuffer(BufferToPresent,
                                                          SyncInterval,
                                                          Flags);
        CheckReplayResult("IDXGIDecodeSwapChain_PresentBuffer", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetSourceRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_SetSourceRect", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetTargetRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_SetTargetRect", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Width,
    UINT                                        Height)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetDestSize(Width,
                                                        Height);
        CheckReplayResult("IDXGIDecodeSwapChain_SetDestSize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!pRect->IsNull())
        {
            pRect->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetSourceRect(pRect->GetOutputPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetSourceRect", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!pRect->IsNull())
        {
            pRect->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetTargetRect(pRect->GetOutputPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetTargetRect", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pWidth,
    PointerDecoder<UINT>*                       pHeight)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!pWidth->IsNull())
        {
            pWidth->AllocateOutputData(1);
        }
        if(!pHeight->IsNull())
        {
            pHeight->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDestSize(pWidth->GetOutputPointer(),
                                                        pHeight->GetOutputPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetDestSize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         ColorSpace)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetColorSpace(ColorSpace);
        CheckReplayResult("IDXGIDecodeSwapChain_SetColorSpace", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         return_value)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetColorSpace();
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    uint64_t                                    hSurface,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    format::HandleId                            pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactoryMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        auto in_hSurface = static_cast<HANDLE>(PreProcessExternalObject(hSurface, format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle, "IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle"));
        auto in_pRestrictToOutput = MapObject<IDXGIOutput>(pRestrictToOutput);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateSwapChainForCompositionSurfaceHandle(in_pDevice,
                                                                                       in_hSurface,
                                                                                       pDesc->GetPointer(),
                                                                                       in_pRestrictToOutput,
                                                                                       out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSwapChain, out_hp_ppSwapChain, format::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle);
        }
        CheckReplayResult("IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    uint64_t                                    hSurface,
    StructPointerDecoder<Decoded_DXGI_DECODE_SWAP_CHAIN_DESC>* pDesc,
    format::HandleId                            pYuvDecodeBuffers,
    format::HandleId                            pRestrictToOutput,
    HandlePointerDecoder<IDXGIDecodeSwapChain*>* ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactoryMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        auto in_hSurface = static_cast<HANDLE>(PreProcessExternalObject(hSurface, format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle, "IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle"));
        auto in_pYuvDecodeBuffers = MapObject<IDXGIResource>(pYuvDecodeBuffers);
        auto in_pRestrictToOutput = MapObject<IDXGIOutput>(pRestrictToOutput);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateDecodeSwapChainForCompositionSurfaceHandle(in_pDevice,
                                                                                             in_hSurface,
                                                                                             pDesc->GetPointer(),
                                                                                             in_pYuvDecodeBuffers,
                                                                                             in_pRestrictToOutput,
                                                                                             out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSwapChain, out_hp_ppSwapChain, format::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle);
        }
        CheckReplayResult("IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        if(!pStats->IsNull())
        {
            pStats->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetFrameStatisticsMedia(pStats->GetOutputPointer());
        CheckReplayResult("IDXGISwapChainMedia_GetFrameStatisticsMedia", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Duration)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPresentDuration(Duration);
        CheckReplayResult("IDXGISwapChainMedia_SetPresentDuration", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        DesiredPresentDuration,
    PointerDecoder<UINT>*                       pClosestSmallerPresentDuration,
    PointerDecoder<UINT>*                       pClosestLargerPresentDuration)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        if(!pClosestSmallerPresentDuration->IsNull())
        {
            pClosestSmallerPresentDuration->AllocateOutputData(1);
        }
        if(!pClosestLargerPresentDuration->IsNull())
        {
            pClosestLargerPresentDuration->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckPresentDurationSupport(DesiredPresentDuration,
                                                                        pClosestSmallerPresentDuration->GetOutputPointer(),
                                                                        pClosestLargerPresentDuration->GetOutputPointer());
        CheckReplayResult("IDXGISwapChainMedia_CheckPresentDurationSupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 EnumFormat,
    format::HandleId                            pConcernedDevice,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        if(!pFlags->IsNull())
        {
            pFlags->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckOverlaySupport(EnumFormat,
                                                                in_pConcernedDevice,
                                                                pFlags->GetOutputPointer());
        CheckReplayResult("IDXGIOutput3_CheckOverlaySupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCurrentBackBufferIndex();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace,
    PointerDecoder<UINT>*                       pColorSpaceSupport)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        if(!pColorSpaceSupport->IsNull())
        {
            pColorSpaceSupport->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckColorSpaceSupport(ColorSpace,
                                                                   pColorSpaceSupport->GetOutputPointer());
        CheckReplayResult("IDXGISwapChain3_CheckColorSpaceSupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_SetColorSpace1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetColorSpace1(ColorSpace);
        CheckReplayResult("IDXGISwapChain3_SetColorSpace1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        BufferCount,
    UINT                                        Width,
    UINT                                        Height,
    DXGI_FORMAT                                 Format,
    UINT                                        SwapChainFlags,
    PointerDecoder<UINT>*                       pCreationNodeMask,
    HandlePointerDecoder<IUnknown*>*            ppPresentQueue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapObjects<IUnknown>(ppPresentQueue, BufferCount);
        auto replay_result = OverrideResizeBuffers1(replay_object,
                                                    return_value,
                                                    BufferCount,
                                                    Width,
                                                    Height,
                                                    Format,
                                                    SwapChainFlags,
                                                    pCreationNodeMask,
                                                    ppPresentQueue);
        CheckReplayResult("IDXGISwapChain3_ResizeBuffers1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 Format,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace,
    format::HandleId                            pConcernedDevice,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        if(!pFlags->IsNull())
        {
            pFlags->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckOverlayColorSpaceSupport(Format,
                                                                          ColorSpace,
                                                                          in_pConcernedDevice,
                                                                          pFlags->GetOutputPointer());
        CheckReplayResult("IDXGIOutput4_CheckOverlayColorSpaceSupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_LUID                                AdapterLuid,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvAdapter)
{
    auto replay_object = MapObject<IDXGIFactory4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvAdapter->IsNull()) ppvAdapter->SetHandleLength(1);
        auto out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapterByLuid(*AdapterLuid.decoded_value,
                                                              *riid.decoded_value,
                                                              out_hp_ppvAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter, format::ApiCall_IDXGIFactory4_EnumAdapterByLuid);
        }
        CheckReplayResult("IDXGIFactory4_EnumAdapterByLuid", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvAdapter)
{
    auto replay_object = MapObject<IDXGIFactory4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvAdapter->IsNull()) ppvAdapter->SetHandleLength(1);
        auto out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumWarpAdapter(*riid.decoded_value,
                                                            out_hp_ppvAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter, format::ApiCall_IDXGIFactory4_EnumWarpAdapter);
        }
        CheckReplayResult("IDXGIFactory4_EnumWarpAdapter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent, "IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterHardwareContentProtectionTeardownStatusEvent(in_hEvent,
                                                                                                 pdwCookie->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterHardwareContentProtectionTeardownStatus(dwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_QueryVideoMemoryInfo(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP                   MemorySegmentGroup,
    StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        if(!pVideoMemoryInfo->IsNull())
        {
            pVideoMemoryInfo->AllocateOutputData(1);
        }
        auto replay_result = replay_object->QueryVideoMemoryInfo(NodeIndex,
                                                                 MemorySegmentGroup,
                                                                 pVideoMemoryInfo->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter3_QueryVideoMemoryInfo", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP                   MemorySegmentGroup,
    UINT64                                      Reservation)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetVideoMemoryReservation(NodeIndex,
                                                                      MemorySegmentGroup,
                                                                      Reservation);
        CheckReplayResult("IDXGIAdapter3_SetVideoMemoryReservation", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent, "IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterVideoMemoryBudgetChangeNotificationEvent(in_hEvent,
                                                                                             pdwCookie->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterVideoMemoryBudgetChangeNotification(dwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput5_DuplicateOutput1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    UINT                                        Flags,
    UINT                                        SupportedFormatsCount,
    PointerDecoder<DXGI_FORMAT>*                pSupportedFormats,
    HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    auto replay_object = MapObject<IDXGIOutput5>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        if(!ppOutputDuplication->IsNull()) ppOutputDuplication->SetHandleLength(1);
        auto out_p_ppOutputDuplication    = ppOutputDuplication->GetPointer();
        auto out_hp_ppOutputDuplication   = ppOutputDuplication->GetHandlePointer();
        auto replay_result = replay_object->DuplicateOutput1(in_pDevice,
                                                             Flags,
                                                             SupportedFormatsCount,
                                                             pSupportedFormats->GetPointer(),
                                                             out_hp_ppOutputDuplication);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutputDuplication, out_hp_ppOutputDuplication, format::ApiCall_IDXGIOutput5_DuplicateOutput1);
        }
        CheckReplayResult("IDXGIOutput5_DuplicateOutput1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_HDR_METADATA_TYPE                      Type,
    UINT                                        Size,
    PointerDecoder<uint8_t>*                    pMetaData)
{
    auto replay_object = MapObject<IDXGISwapChain4>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetHDRMetaData(Type,
                                                           Size,
                                                           pMetaData->GetPointer());
        CheckReplayResult("IDXGISwapChain4_SetHDRMetaData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice4_OfferResources1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY                Priority,
    UINT                                        Flags)
{
    auto replay_object = MapObject<IDXGIDevice4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        auto replay_result = replay_object->OfferResources1(NumResources,
                                                            in_ppResources,
                                                            Priority,
                                                            Flags);
        CheckReplayResult("IDXGIDevice4_OfferResources1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice4_ReclaimResources1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    auto replay_object = MapObject<IDXGIDevice4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        if(!pResults->IsNull())
        {
            pResults->AllocateOutputData(NumResources);
        }
        auto replay_result = replay_object->ReclaimResources1(NumResources,
                                                              in_ppResources,
                                                              pResults->GetOutputPointer());
        CheckReplayResult("IDXGIDevice4_ReclaimResources1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter4_GetDesc3(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter4>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc3(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGIAdapter4_GetDesc3", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput6_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput6>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDesc1(pDesc->GetOutputPointer());
        CheckReplayResult("IDXGIOutput6_GetDesc1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput6>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFlags->IsNull())
        {
            pFlags->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckHardwareCompositionSupport(pFlags->GetOutputPointer());
        CheckReplayResult("IDXGIOutput6_CheckHardwareCompositionSupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Adapter,
    DXGI_GPU_PREFERENCE                         GpuPreference,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvAdapter)
{
    auto replay_object = MapObject<IDXGIFactory6>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvAdapter->IsNull()) ppvAdapter->SetHandleLength(1);
        auto out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapterByGpuPreference(Adapter,
                                                                       GpuPreference,
                                                                       *riid.decoded_value,
                                                                       out_hp_ppvAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter, format::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference);
        }
        CheckReplayResult("IDXGIFactory6_EnumAdapterByGpuPreference", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory7>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent, "IDXGIFactory7_RegisterAdaptersChangedEvent"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterAdaptersChangedEvent(in_hEvent,
                                                                         pdwCookie->GetOutputPointer());
        CheckReplayResult("IDXGIFactory7_RegisterAdaptersChangedEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIFactory7>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnregisterAdaptersChangedEvent(dwCookie);
        CheckReplayResult("IDXGIFactory7_UnregisterAdaptersChangedEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_GetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    PointerDecoder<UINT>*                       pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDataSize->IsNull())
        {
            pDataSize->AllocateOutputData(1, GetOutputArrayCount("ID3D12Object::GetPrivateData", return_value, object_id, VariableLengthArrayIndices::kD3D12ObjectArrayGetPrivateData, pDataSize, pData));
        }
        if(!pData->IsNull() && !pDataSize->IsNull())
        {
            pData->AllocateOutputData(*pDataSize->GetOutputPointer());
        }
        auto replay_result = replay_object->GetPrivateData(*guid.decoded_value,
                                                           pDataSize->GetOutputPointer(),
                                                           pData->GetOutputPointer());
        if (pData->IsNull() && !pDataSize->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D12ObjectArrayGetPrivateData, *pDataSize->GetOutputPointer()); }
        CheckReplayResult("ID3D12Object_GetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_SetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPrivateData(*guid.decoded_value,
                                                           DataSize,
                                                           pData->GetPointer());
        CheckReplayResult("ID3D12Object_SetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_SetPrivateDataInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    format::HandleId                            pData)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pData = MapObject<IUnknown>(pData);
        auto replay_result = replay_object->SetPrivateDataInterface(*guid.decoded_value,
                                                                    in_pData);
        CheckReplayResult("ID3D12Object_SetPrivateDataInterface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_SetName(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             Name)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideSetName(replay_object,
                                             return_value,
                                             Name);
        CheckReplayResult("ID3D12Object_SetName", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceChild_GetDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDevice)
{
    auto replay_object = MapObject<ID3D12DeviceChild>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvDevice->IsNull()) ppvDevice->SetHandleLength(1);
        auto out_p_ppvDevice    = ppvDevice->GetPointer();
        auto out_hp_ppvDevice   = ppvDevice->GetHandlePointer();
        auto replay_result = replay_object->GetDevice(*riid.decoded_value,
                                                      out_hp_ppvDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDevice, out_hp_ppvDevice, format::ApiCall_ID3D12DeviceChild_GetDevice);
        }
        CheckReplayResult("ID3D12DeviceChild_GetDevice", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* return_value)
{
    auto replay_object = MapObject<ID3D12RootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRootSignatureDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D_ROOT_SIGNATURE_VERSION                  convertToVersion,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* ppDesc)
{
    auto replay_object = MapObject<ID3D12VersionedRootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDesc->IsNull())
        {
            ppDesc->AllocateOutputData(1);
        }
        auto in_ppDesc    = ppDesc->GetOutputPointer();
        auto replay_result = replay_object->GetRootSignatureDescAtVersion(convertToVersion,
                                                                          const_cast<const D3D12_VERSIONED_ROOT_SIGNATURE_DESC**>(&in_ppDesc));
        CheckReplayResult("ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* return_value)
{
    auto replay_object = MapObject<ID3D12VersionedRootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetUnconvertedRootSignatureDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Heap_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_HEAP_DESC                     return_value)
{
    auto replay_object = MapObject<ID3D12Heap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_Map(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Subresource,
    StructPointerDecoder<Decoded_D3D12_RANGE>*  pReadRange,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        if(!ppData->IsNull())
        {
            ppData->AllocateOutputData(1);
        }
        auto replay_result = OverrideResourceMap(replay_object,
                                                 return_value,
                                                 Subresource,
                                                 pReadRange,
                                                 ppData);
        CheckReplayResult("ID3D12Resource_Map", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_Unmap(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Subresource,
    StructPointerDecoder<Decoded_D3D12_RANGE>*  pWrittenRange)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        OverrideResourceUnmap(replay_object,
                              Subresource,
                              pWrittenRange);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC                 return_value)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_GPU_VIRTUAL_ADDRESS                   return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetGpuVirtualAddress(replay_object,
                                                          return_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_ReadFromSubresource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    pDstData,
    UINT                                        DstRowPitch,
    UINT                                        DstDepthPitch,
    UINT                                        SrcSubresource,
    StructPointerDecoder<Decoded_D3D12_BOX>*    pSrcBox)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideReadFromSubresource(replay_object,
                                                         return_value,
                                                         pDstData,
                                                         DstRowPitch,
                                                         DstDepthPitch,
                                                         SrcSubresource,
                                                         pSrcBox);
        CheckReplayResult("ID3D12Resource_ReadFromSubresource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_GetHeapProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    PointerDecoder<D3D12_HEAP_FLAGS>*           pHeapFlags)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHeapProperties->IsNull())
        {
            pHeapProperties->AllocateOutputData(1);
        }
        if(!pHeapFlags->IsNull())
        {
            pHeapFlags->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetHeapProperties(pHeapProperties->GetOutputPointer(),
                                                              pHeapFlags->GetOutputPointer());
        CheckReplayResult("ID3D12Resource_GetHeapProperties", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandAllocator_Reset(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12CommandAllocator>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Reset();
        CheckReplayResult("ID3D12CommandAllocator_Reset", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence_GetCompletedValue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetCompletedValue(replay_object,
                                                       return_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence_SetEventOnCompletion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      Value,
    uint64_t                                    hEvent)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideSetEventOnCompletion(replay_object,
                                                          return_value,
                                                          Value,
                                                          hEvent);
        CheckReplayResult("ID3D12Fence_SetEventOnCompletion", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence_Signal(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      Value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideFenceSignal(replay_object,
                                                 return_value,
                                                 Value);
        CheckReplayResult("ID3D12Fence_Signal", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence1_GetCreationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_FENCE_FLAGS                           return_value)
{
    auto replay_object = MapObject<ID3D12Fence1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCreationFlags();
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineState_GetCachedBlob(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob)
{
    auto replay_object = MapObject<ID3D12PipelineState>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppBlob->IsNull()) ppBlob->SetHandleLength(1);
        auto out_p_ppBlob    = ppBlob->GetPointer();
        auto out_hp_ppBlob   = ppBlob->GetHandlePointer();
        auto replay_result = replay_object->GetCachedBlob(out_hp_ppBlob);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppBlob, out_hp_ppBlob, format::ApiCall_ID3D12PipelineState_GetCachedBlob);
        }
        CheckReplayResult("ID3D12PipelineState_GetCachedBlob", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DescriptorHeap_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_DESCRIPTOR_HEAP_DESC          return_value)
{
    auto replay_object = MapObject<ID3D12DescriptorHeap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetCPUDescriptorHandleForHeapStart(replay_object,
                                                                        return_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetGPUDescriptorHandleForHeapStart(replay_object,
                                                                        return_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandList_GetType(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_COMMAND_LIST_TYPE                     return_value)
{
    auto replay_object = MapObject<ID3D12CommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetType();
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_Close(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Close();
        CheckReplayResult("ID3D12GraphicsCommandList_Close", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_Reset(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pAllocator,
    format::HandleId                            pInitialState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pAllocator = GetObjectInfo(pAllocator);
        auto in_pInitialState = GetObjectInfo(pInitialState);
        auto replay_result = OverrideCommandListReset(replay_object,
                                                      return_value,
                                                      in_pAllocator,
                                                      in_pInitialState);
        CheckReplayResult("ID3D12GraphicsCommandList_Reset", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pPipelineState)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pPipelineState = MapObject<ID3D12PipelineState>(pPipelineState);
        replay_object->ClearState(in_pPipelineState);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        VertexCountPerInstance,
    UINT                                        InstanceCount,
    UINT                                        StartVertexLocation,
    UINT                                        StartInstanceLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DrawInstanced(VertexCountPerInstance,
                                     InstanceCount,
                                     StartVertexLocation,
                                     StartInstanceLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        IndexCountPerInstance,
    UINT                                        InstanceCount,
    UINT                                        StartIndexLocation,
    INT                                         BaseVertexLocation,
    UINT                                        StartInstanceLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DrawIndexedInstanced(IndexCountPerInstance,
                                            InstanceCount,
                                            StartIndexLocation,
                                            BaseVertexLocation,
                                            StartInstanceLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_Dispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        ThreadGroupCountX,
    UINT                                        ThreadGroupCountY,
    UINT                                        ThreadGroupCountZ)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Dispatch(ThreadGroupCountX,
                                ThreadGroupCountY,
                                ThreadGroupCountZ);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstBuffer,
    UINT64                                      DstOffset,
    format::HandleId                            pSrcBuffer,
    UINT64                                      SrcOffset,
    UINT64                                      NumBytes)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pDstBuffer = GetObjectInfo(pDstBuffer);
        auto in_pSrcBuffer = GetObjectInfo(pSrcBuffer);
        OverrideCopyBufferRegion(replay_object,
                                 in_pDstBuffer,
                                 DstOffset,
                                 in_pSrcBuffer,
                                 SrcOffset,
                                 NumBytes);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
    UINT                                        DstX,
    UINT                                        DstY,
    UINT                                        DstZ,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
    StructPointerDecoder<Decoded_D3D12_BOX>*    pSrcBox)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDst->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(pSrc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideCopyTextureRegion(replay_object,
                                  pDst,
                                  DstX,
                                  DstY,
                                  DstZ,
                                  pSrc,
                                  pSrcBox);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    format::HandleId                            pSrcResource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pDstResource = GetObjectInfo(pDstResource);
        auto in_pSrcResource = GetObjectInfo(pSrcResource);
        OverrideCopyResource(replay_object,
                             in_pDstResource,
                             in_pSrcResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pTiledResource,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pTileRegionSize,
    format::HandleId                            pBuffer,
    UINT64                                      BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS                       Flags)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTiledResource = MapObject<ID3D12Resource>(pTiledResource);
        auto in_pBuffer = MapObject<ID3D12Resource>(pBuffer);
        replay_object->CopyTiles(in_pTiledResource,
                                 pTileRegionStartCoordinate->GetPointer(),
                                 pTileRegionSize->GetPointer(),
                                 in_pBuffer,
                                 BufferStartOffsetInBytes,
                                 Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ResolveSubresource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    UINT                                        DstSubresource,
    format::HandleId                            pSrcResource,
    UINT                                        SrcSubresource,
    DXGI_FORMAT                                 Format)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D12Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D12Resource>(pSrcResource);
        replay_object->ResolveSubresource(in_pDstResource,
                                          DstSubresource,
                                          in_pSrcResource,
                                          SrcSubresource,
                                          Format);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D_PRIMITIVE_TOPOLOGY                      PrimitiveTopology)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->IASetPrimitiveTopology(PrimitiveTopology);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumViewports,
    StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RSSetViewports(NumViewports,
                                      pViewports->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RSSetScissorRects(NumRects,
                                         pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<FLOAT>*                      BlendFactor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->OMSetBlendFactor(BlendFactor->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetStencilRef(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StencilRef)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->OMSetStencilRef(StencilRef);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pPipelineState)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pPipelineState = MapObject<ID3D12PipelineState>(pPipelineState);
        replay_object->SetPipelineState(in_pPipelineState);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumBarriers,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pBarriers->GetMetaStructPointer(), pBarriers->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        replay_object->ResourceBarrier(NumBarriers,
                                       pBarriers->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCommandList)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCommandList = MapObject<ID3D12GraphicsCommandList>(pCommandList);
        replay_object->ExecuteBundle(in_pCommandList);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumDescriptorHeaps,
    HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppDescriptorHeaps = MapObjects<ID3D12DescriptorHeap>(ppDescriptorHeaps, NumDescriptorHeaps);
        replay_object->SetDescriptorHeaps(NumDescriptorHeaps,
                                          in_ppDescriptorHeaps);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pRootSignature)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pRootSignature = MapObject<ID3D12RootSignature>(pRootSignature);
        replay_object->SetComputeRootSignature(in_pRootSignature);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pRootSignature)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pRootSignature = MapObject<ID3D12RootSignature>(pRootSignature);
        replay_object->SetGraphicsRootSignature(in_pRootSignature);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         BaseDescriptor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuDescriptorHandle(*BaseDescriptor.decoded_value);
        replay_object->SetComputeRootDescriptorTable(RootParameterIndex,
                                                     *BaseDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         BaseDescriptor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuDescriptorHandle(*BaseDescriptor.decoded_value);
        replay_object->SetGraphicsRootDescriptorTable(RootParameterIndex,
                                                      *BaseDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    UINT                                        SrcData,
    UINT                                        DestOffsetIn32BitValues)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetComputeRoot32BitConstant(RootParameterIndex,
                                                   SrcData,
                                                   DestOffsetIn32BitValues);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    UINT                                        SrcData,
    UINT                                        DestOffsetIn32BitValues)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGraphicsRoot32BitConstant(RootParameterIndex,
                                                    SrcData,
                                                    DestOffsetIn32BitValues);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    UINT                                        Num32BitValuesToSet,
    PointerDecoder<uint8_t>*                    pSrcData,
    UINT                                        DestOffsetIn32BitValues)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetComputeRoot32BitConstants(RootParameterIndex,
                                                    Num32BitValuesToSet,
                                                    pSrcData->GetPointer(),
                                                    DestOffsetIn32BitValues);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    UINT                                        Num32BitValuesToSet,
    PointerDecoder<uint8_t>*                    pSrcData,
    UINT                                        DestOffsetIn32BitValues)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGraphicsRoot32BitConstants(RootParameterIndex,
                                                     Num32BitValuesToSet,
                                                     pSrcData->GetPointer(),
                                                     DestOffsetIn32BitValues);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuVirtualAddress(BufferLocation);
        replay_object->SetComputeRootConstantBufferView(RootParameterIndex,
                                                        BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuVirtualAddress(BufferLocation);
        replay_object->SetGraphicsRootConstantBufferView(RootParameterIndex,
                                                         BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuVirtualAddress(BufferLocation);
        replay_object->SetComputeRootShaderResourceView(RootParameterIndex,
                                                        BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuVirtualAddress(BufferLocation);
        replay_object->SetGraphicsRootShaderResourceView(RootParameterIndex,
                                                         BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuVirtualAddress(BufferLocation);
        replay_object->SetComputeRootUnorderedAccessView(RootParameterIndex,
                                                         BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuVirtualAddress(BufferLocation);
        replay_object->SetGraphicsRootUnorderedAccessView(RootParameterIndex,
                                                          BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pView->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideIASetIndexBuffer(replay_object,
                                 pView);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructArrayObjects(pViews->GetMetaStructPointer(), pViews->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideIASetVertexBuffers(replay_object,
                                   StartSlot,
                                   NumViews,
                                   pViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pViews->GetMetaStructPointer(), pViews->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        replay_object->SOSetTargets(StartSlot,
                                    NumViews,
                                    pViews->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumRenderTargetDescriptors,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
    BOOL                                        RTsSingleHandleToDescriptorRange,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pRenderTargetDescriptors->GetMetaStructPointer(), pRenderTargetDescriptors->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(pDepthStencilDescriptor->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        replay_object->OMSetRenderTargets(NumRenderTargetDescriptors,
                                          pRenderTargetDescriptors->GetPointer(),
                                          RTsSingleHandleToDescriptorRange,
                                          pDepthStencilDescriptor->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DepthStencilView,
    D3D12_CLEAR_FLAGS                           ClearFlags,
    FLOAT                                       Depth,
    UINT8                                       Stencil,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(&DepthStencilView, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->ClearDepthStencilView(*DepthStencilView.decoded_value,
                                             ClearFlags,
                                             Depth,
                                             Stencil,
                                             NumRects,
                                             pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         RenderTargetView,
    PointerDecoder<FLOAT>*                      ColorRGBA,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(&RenderTargetView, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->ClearRenderTargetView(*RenderTargetView.decoded_value,
                                             ColorRGBA->GetPointer(),
                                             NumRects,
                                             pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         ViewGPUHandleInCurrentHeap,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         ViewCPUHandle,
    format::HandleId                            pResource,
    PointerDecoder<UINT>*                       Values,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuDescriptorHandle(*ViewGPUHandleInCurrentHeap.decoded_value);
        MapStructObjects(&ViewCPUHandle, GetObjectInfoTable(), GetGpuVaTable());
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->ClearUnorderedAccessViewUint(*ViewGPUHandleInCurrentHeap.decoded_value,
                                                    *ViewCPUHandle.decoded_value,
                                                    in_pResource,
                                                    Values->GetPointer(),
                                                    NumRects,
                                                    pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         ViewGPUHandleInCurrentHeap,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         ViewCPUHandle,
    format::HandleId                            pResource,
    PointerDecoder<FLOAT>*                      Values,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuDescriptorHandle(*ViewGPUHandleInCurrentHeap.decoded_value);
        MapStructObjects(&ViewCPUHandle, GetObjectInfoTable(), GetGpuVaTable());
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->ClearUnorderedAccessViewFloat(*ViewGPUHandleInCurrentHeap.decoded_value,
                                                     *ViewCPUHandle.decoded_value,
                                                     in_pResource,
                                                     Values->GetPointer(),
                                                     NumRects,
                                                     pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->DiscardResource(in_pResource,
                                       pRegion->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pQueryHeap,
    D3D12_QUERY_TYPE                            Type,
    UINT                                        Index)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pQueryHeap = MapObject<ID3D12QueryHeap>(pQueryHeap);
        replay_object->BeginQuery(in_pQueryHeap,
                                  Type,
                                  Index);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_EndQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pQueryHeap,
    D3D12_QUERY_TYPE                            Type,
    UINT                                        Index)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pQueryHeap = MapObject<ID3D12QueryHeap>(pQueryHeap);
        replay_object->EndQuery(in_pQueryHeap,
                                Type,
                                Index);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ResolveQueryData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pQueryHeap,
    D3D12_QUERY_TYPE                            Type,
    UINT                                        StartIndex,
    UINT                                        NumQueries,
    format::HandleId                            pDestinationBuffer,
    UINT64                                      AlignedDestinationBufferOffset)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pQueryHeap = MapObject<ID3D12QueryHeap>(pQueryHeap);
        auto in_pDestinationBuffer = MapObject<ID3D12Resource>(pDestinationBuffer);
        replay_object->ResolveQueryData(in_pQueryHeap,
                                        Type,
                                        StartIndex,
                                        NumQueries,
                                        in_pDestinationBuffer,
                                        AlignedDestinationBufferOffset);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetPredication(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pBuffer,
    UINT64                                      AlignedBufferOffset,
    D3D12_PREDICATION_OP                        Operation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pBuffer = MapObject<ID3D12Resource>(pBuffer);
        replay_object->SetPredication(in_pBuffer,
                                      AlignedBufferOffset,
                                      Operation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetMarker(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetMarker(Metadata,
                                 pData->GetPointer(),
                                 Size);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_BeginEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginEvent(Metadata,
                                  pData->GetPointer(),
                                  Size);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndEvent();
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCommandSignature,
    UINT                                        MaxCommandCount,
    format::HandleId                            pArgumentBuffer,
    UINT64                                      ArgumentBufferOffset,
    format::HandleId                            pCountBuffer,
    UINT64                                      CountBufferOffset)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pCommandSignature = GetObjectInfo(pCommandSignature);
        auto in_pArgumentBuffer = GetObjectInfo(pArgumentBuffer);
        auto in_pCountBuffer = GetObjectInfo(pCountBuffer);
        OverrideExecuteIndirect(replay_object,
                                in_pCommandSignature,
                                MaxCommandCount,
                                in_pArgumentBuffer,
                                ArgumentBufferOffset,
                                in_pCountBuffer,
                                CountBufferOffset);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstBuffer,
    UINT64                                      DstOffset,
    format::HandleId                            pSrcBuffer,
    UINT64                                      SrcOffset,
    UINT                                        Dependencies,
    HandlePointerDecoder<ID3D12Resource*>*      ppDependentResources,
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstBuffer = MapObject<ID3D12Resource>(pDstBuffer);
        auto in_pSrcBuffer = MapObject<ID3D12Resource>(pSrcBuffer);
        auto in_ppDependentResources = MapObjects<ID3D12Resource>(ppDependentResources, Dependencies);
        replay_object->AtomicCopyBufferUINT(in_pDstBuffer,
                                            DstOffset,
                                            in_pSrcBuffer,
                                            SrcOffset,
                                            Dependencies,
                                            in_ppDependentResources,
                                            pDependentSubresourceRanges->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstBuffer,
    UINT64                                      DstOffset,
    format::HandleId                            pSrcBuffer,
    UINT64                                      SrcOffset,
    UINT                                        Dependencies,
    HandlePointerDecoder<ID3D12Resource*>*      ppDependentResources,
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstBuffer = MapObject<ID3D12Resource>(pDstBuffer);
        auto in_pSrcBuffer = MapObject<ID3D12Resource>(pSrcBuffer);
        auto in_ppDependentResources = MapObjects<ID3D12Resource>(ppDependentResources, Dependencies);
        replay_object->AtomicCopyBufferUINT64(in_pDstBuffer,
                                              DstOffset,
                                              in_pSrcBuffer,
                                              SrcOffset,
                                              Dependencies,
                                              in_ppDependentResources,
                                              pDependentSubresourceRanges->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    FLOAT                                       Min,
    FLOAT                                       Max)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->OMSetDepthBounds(Min,
                                        Max);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_SetSamplePositions(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumSamplesPerPixel,
    UINT                                        NumPixels,
    StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION>* pSamplePositions)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetSamplePositions(NumSamplesPerPixel,
                                          NumPixels,
                                          pSamplePositions->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    UINT                                        DstSubresource,
    UINT                                        DstX,
    UINT                                        DstY,
    format::HandleId                            pSrcResource,
    UINT                                        SrcSubresource,
    StructPointerDecoder<Decoded_tagRECT>*      pSrcRect,
    DXGI_FORMAT                                 Format,
    D3D12_RESOLVE_MODE                          ResolveMode)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D12Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D12Resource>(pSrcResource);
        replay_object->ResolveSubresourceRegion(in_pDstResource,
                                                DstSubresource,
                                                DstX,
                                                DstY,
                                                in_pSrcResource,
                                                SrcSubresource,
                                                pSrcRect->GetPointer(),
                                                Format,
                                                ResolveMode);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Mask)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetViewInstanceMask(Mask);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Count,
    StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
    PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList2>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pParams->GetMetaStructPointer(), pParams->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        replay_object->WriteBufferImmediate(Count,
                                            pParams->GetPointer(),
                                            pModes->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_UpdateTileMappings(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        NumResourceRegions,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pResourceRegionStartCoordinates,
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pResourceRegionSizes,
    format::HandleId                            pHeap,
    UINT                                        NumRanges,
    PointerDecoder<D3D12_TILE_RANGE_FLAGS>*     pRangeFlags,
    PointerDecoder<UINT>*                       pHeapRangeStartOffsets,
    PointerDecoder<UINT>*                       pRangeTileCounts,
    D3D12_TILE_MAPPING_FLAGS                    Flags)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        replay_object->UpdateTileMappings(in_pResource,
                                          NumResourceRegions,
                                          pResourceRegionStartCoordinates->GetPointer(),
                                          pResourceRegionSizes->GetPointer(),
                                          in_pHeap,
                                          NumRanges,
                                          pRangeFlags->GetPointer(),
                                          pHeapRangeStartOffsets->GetPointer(),
                                          pRangeTileCounts->GetPointer(),
                                          Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_CopyTileMappings(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pDstRegionStartCoordinate,
    format::HandleId                            pSrcResource,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pSrcRegionStartCoordinate,
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS                    Flags)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D12Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D12Resource>(pSrcResource);
        replay_object->CopyTileMappings(in_pDstResource,
                                        pDstRegionStartCoordinate->GetPointer(),
                                        in_pSrcResource,
                                        pSrcRegionStartCoordinate->GetPointer(),
                                        pRegionSize->GetPointer(),
                                        Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumCommandLists,
    HandlePointerDecoder<ID3D12CommandList*>*   ppCommandLists)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapObjects<ID3D12CommandList>(ppCommandLists, NumCommandLists);
        OverrideExecuteCommandLists(replay_object,
                                    NumCommandLists,
                                    ppCommandLists);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_SetMarker(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetMarker(Metadata,
                                 pData->GetPointer(),
                                 Size);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_BeginEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginEvent(Metadata,
                                  pData->GetPointer(),
                                  Size);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_EndEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndEvent();
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_Signal(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pFence,
    UINT64                                      Value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pFence = GetObjectInfo(pFence);
        auto replay_result = OverrideCommandQueueSignal(replay_object,
                                                        return_value,
                                                        in_pFence,
                                                        Value);
        CheckReplayResult("ID3D12CommandQueue_Signal", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_Wait(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pFence,
    UINT64                                      Value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pFence = GetObjectInfo(pFence);
        auto replay_result = OverrideCommandQueueWait(replay_object,
                                                      return_value,
                                                      in_pFence,
                                                      Value);
        CheckReplayResult("ID3D12CommandQueue_Wait", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT64>*                     pFrequency)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFrequency->IsNull())
        {
            pFrequency->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetTimestampFrequency(pFrequency->GetOutputPointer());
        CheckReplayResult("ID3D12CommandQueue_GetTimestampFrequency", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT64>*                     pGpuTimestamp,
    PointerDecoder<UINT64>*                     pCpuTimestamp)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        if(!pGpuTimestamp->IsNull())
        {
            pGpuTimestamp->AllocateOutputData(1);
        }
        if(!pCpuTimestamp->IsNull())
        {
            pCpuTimestamp->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetClockCalibration(pGpuTimestamp->GetOutputPointer(),
                                                                pCpuTimestamp->GetOutputPointer());
        CheckReplayResult("ID3D12CommandQueue_GetClockCalibration", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_COMMAND_QUEUE_DESC            return_value)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetNodeCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNodeCount();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandQueue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppCommandQueue{};
        if(!ppCommandQueue->IsNull())
        {
            ppCommandQueue->SetHandleLength(1);
            ppCommandQueue->SetConsumerData(0, &object_info_ppCommandQueue);
        }
        auto replay_result = OverrideCreateCommandQueue(replay_object,
                                                        return_value,
                                                        pDesc,
                                                        riid,
                                                        ppCommandQueue);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppCommandQueue->GetPointer(), ppCommandQueue->GetHandlePointer(), std::move(object_info_ppCommandQueue), format::ApiCall_ID3D12Device_CreateCommandQueue);
        }
        CheckReplayResult("ID3D12Device_CreateCommandQueue", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandAllocator(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_COMMAND_LIST_TYPE                     type,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandAllocator)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppCommandAllocator->IsNull()) ppCommandAllocator->SetHandleLength(1);
        auto out_p_ppCommandAllocator    = ppCommandAllocator->GetPointer();
        auto out_hp_ppCommandAllocator   = ppCommandAllocator->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandAllocator(type,
                                                                   *riid.decoded_value,
                                                                   out_hp_ppCommandAllocator);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCommandAllocator, out_hp_ppCommandAllocator, format::ApiCall_ID3D12Device_CreateCommandAllocator);
        }
        CheckReplayResult("ID3D12Device_CreateCommandAllocator", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        DxObjectInfo object_info_ppPipelineState{};
        if(!ppPipelineState->IsNull())
        {
            ppPipelineState->SetHandleLength(1);
            ppPipelineState->SetConsumerData(0, &object_info_ppPipelineState);
        }
        auto replay_result = OverrideCreateGraphicsPipelineState(replay_object,
                                                                 return_value,
                                                                 pDesc,
                                                                 riid,
                                                                 ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info_ppPipelineState), format::ApiCall_ID3D12Device_CreateGraphicsPipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateGraphicsPipelineState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateComputePipelineState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        DxObjectInfo object_info_ppPipelineState{};
        if(!ppPipelineState->IsNull())
        {
            ppPipelineState->SetHandleLength(1);
            ppPipelineState->SetConsumerData(0, &object_info_ppPipelineState);
        }
        auto replay_result = OverrideCreateComputePipelineState(replay_object,
                                                                return_value,
                                                                pDesc,
                                                                riid,
                                                                ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info_ppPipelineState), format::ApiCall_ID3D12Device_CreateComputePipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateComputePipelineState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandList(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        nodeMask,
    D3D12_COMMAND_LIST_TYPE                     type,
    format::HandleId                            pCommandAllocator,
    format::HandleId                            pInitialState,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandList)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pCommandAllocator = GetObjectInfo(pCommandAllocator);
        auto in_pInitialState = GetObjectInfo(pInitialState);
        DxObjectInfo object_info_ppCommandList{};
        if(!ppCommandList->IsNull())
        {
            ppCommandList->SetHandleLength(1);
            ppCommandList->SetConsumerData(0, &object_info_ppCommandList);
        }
        auto replay_result = OverrideCreateCommandList(replay_object,
                                                       return_value,
                                                       nodeMask,
                                                       type,
                                                       in_pCommandAllocator,
                                                       in_pInitialState,
                                                       riid,
                                                       ppCommandList);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppCommandList->GetPointer(), ppCommandList->GetHandlePointer(), std::move(object_info_ppCommandList), format::ApiCall_ID3D12Device_CreateCommandList);
        }
        CheckReplayResult("ID3D12Device_CreateCommandList", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateDescriptorHeap(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppvHeap{};
        if(!ppvHeap->IsNull())
        {
            ppvHeap->SetHandleLength(1);
            ppvHeap->SetConsumerData(0, &object_info_ppvHeap);
        }
        auto replay_result = OverrideCreateDescriptorHeap(replay_object,
                                                          return_value,
                                                          pDescriptorHeapDesc,
                                                          riid,
                                                          ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info_ppvHeap), format::ApiCall_ID3D12Device_CreateDescriptorHeap);
        }
        CheckReplayResult("ID3D12Device_CreateDescriptorHeap", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value,
    D3D12_DESCRIPTOR_HEAP_TYPE                  DescriptorHeapType)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetDescriptorHandleIncrementSize(replay_object,
                                                                      return_value,
                                                                      DescriptorHeapType);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateRootSignature(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        nodeMask,
    PointerDecoder<uint8_t>*                    pBlobWithRootSignature,
    SIZE_T                                      blobLengthInBytes,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvRootSignature)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppvRootSignature{};
        if(!ppvRootSignature->IsNull())
        {
            ppvRootSignature->SetHandleLength(1);
            ppvRootSignature->SetConsumerData(0, &object_info_ppvRootSignature);
        }
        auto replay_result = OverrideCreateRootSignature(replay_object,
                                                         return_value,
                                                         nodeMask,
                                                         pBlobWithRootSignature,
                                                         blobLengthInBytes,
                                                         riid,
                                                         ppvRootSignature);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvRootSignature->GetPointer(), ppvRootSignature->GetHandlePointer(), std::move(object_info_ppvRootSignature), format::ApiCall_ID3D12Device_CreateRootSignature);
        }
        CheckReplayResult("ID3D12Device_CreateRootSignature", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateConstantBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateConstantBufferView(pDesc->GetPointer(),
                                                *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateShaderResourceView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateShaderResourceView(in_pResource,
                                                pDesc->GetPointer(),
                                                *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    format::HandleId                            pCounterResource,
    StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto in_pCounterResource = MapObject<ID3D12Resource>(pCounterResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateUnorderedAccessView(in_pResource,
                                                 in_pCounterResource,
                                                 pDesc->GetPointer(),
                                                 *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateRenderTargetView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateRenderTargetView(in_pResource,
                                              pDesc->GetPointer(),
                                              *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateDepthStencilView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateDepthStencilView(in_pResource,
                                              pDesc->GetPointer(),
                                              *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateSampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateSampler(pDesc->GetPointer(),
                                     *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CopyDescriptors(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumDestDescriptorRanges,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDestDescriptorRangeStarts,
    PointerDecoder<UINT>*                       pDestDescriptorRangeSizes,
    UINT                                        NumSrcDescriptorRanges,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pSrcDescriptorRangeStarts,
    PointerDecoder<UINT>*                       pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE                  DescriptorHeapsType)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pDestDescriptorRangeStarts->GetMetaStructPointer(), pDestDescriptorRangeStarts->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructArrayObjects(pSrcDescriptorRangeStarts->GetMetaStructPointer(), pSrcDescriptorRangeStarts->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CopyDescriptors(NumDestDescriptorRanges,
                                       pDestDescriptorRangeStarts->GetPointer(),
                                       pDestDescriptorRangeSizes->GetPointer(),
                                       NumSrcDescriptorRanges,
                                       pSrcDescriptorRangeStarts->GetPointer(),
                                       pSrcDescriptorRangeSizes->GetPointer(),
                                       DescriptorHeapsType);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumDescriptors,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptorRangeStart,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE                  DescriptorHeapsType)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(&DestDescriptorRangeStart, GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(&SrcDescriptorRangeStart, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CopyDescriptorsSimple(NumDescriptors,
                                             *DestDescriptorRangeStart.decoded_value,
                                             *SrcDescriptorRangeStart.decoded_value,
                                             DescriptorHeapsType);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO      return_value,
    UINT                                        visibleMask,
    UINT                                        numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetResourceAllocationInfo(visibleMask,
                                                                      numResourceDescs,
                                                                      pResourceDescs->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetCustomHeapProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_HEAP_PROPERTIES               return_value,
    UINT                                        nodeMask,
    D3D12_HEAP_TYPE                             heapType)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCustomHeapProperties(nodeMask,
                                                                    heapType);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommittedResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppvResource{};
        if(!ppvResource->IsNull())
        {
            ppvResource->SetHandleLength(1);
            ppvResource->SetConsumerData(0, &object_info_ppvResource);
        }
        auto replay_result = OverrideCreateCommittedResource(replay_object,
                                                             return_value,
                                                             pHeapProperties,
                                                             HeapFlags,
                                                             pDesc,
                                                             InitialResourceState,
                                                             pOptimizedClearValue,
                                                             riidResource,
                                                             ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info_ppvResource), format::ApiCall_ID3D12Device_CreateCommittedResource);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device_CreateCommittedResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateHeap(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppvHeap{};
        if(!ppvHeap->IsNull())
        {
            ppvHeap->SetHandleLength(1);
            ppvHeap->SetConsumerData(0, &object_info_ppvHeap);
        }
        auto replay_result = OverrideCreateHeap(replay_object,
                                                return_value,
                                                pDesc,
                                                riid,
                                                ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info_ppvHeap), format::ApiCall_ID3D12Device_CreateHeap);
        }
        CheckReplayResult("ID3D12Device_CreateHeap", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreatePlacedResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pHeap,
    UINT64                                      HeapOffset,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreatePlacedResource(in_pHeap,
                                                                 HeapOffset,
                                                                 pDesc->GetPointer(),
                                                                 InitialState,
                                                                 pOptimizedClearValue->GetPointer(),
                                                                 *riid.decoded_value,
                                                                 out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource, format::ApiCall_ID3D12Device_CreatePlacedResource);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device_CreatePlacedResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateReservedResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppvResource{};
        if(!ppvResource->IsNull())
        {
            ppvResource->SetHandleLength(1);
            ppvResource->SetConsumerData(0, &object_info_ppvResource);
        }
        auto replay_result = OverrideCreateReservedResource(replay_object,
                                                            return_value,
                                                            pDesc,
                                                            InitialState,
                                                            pOptimizedClearValue,
                                                            riid,
                                                            ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info_ppvResource), format::ApiCall_ID3D12Device_CreateReservedResource);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device_CreateReservedResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateSharedHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pObject,
    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
    DWORD                                       Access,
    WStringDecoder*                             Name,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pObject = MapObject<ID3D12DeviceChild>(pObject);
        if(!pHandle->IsNull())
        {
            pHandle->AllocateOutputData(1);
        }
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = replay_object->CreateSharedHandle(in_pObject,
                                                               pAttributes->GetPointer(),
                                                               Access,
                                                               Name->GetPointer(),
                                                               out_op_pHandle);
        CheckReplayResult("ID3D12Device_CreateSharedHandle", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHandle, out_p_pHandle, format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle, "ID3D12Device_CreateSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_OpenSharedHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    NTHandle,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvObj)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_NTHandle = static_cast<HANDLE>(PreProcessExternalObject(NTHandle, format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle, "ID3D12Device_OpenSharedHandle"));
        if(!ppvObj->IsNull()) ppvObj->SetHandleLength(1);
        auto out_p_ppvObj    = ppvObj->GetPointer();
        auto out_hp_ppvObj   = ppvObj->GetHandlePointer();
        auto replay_result = replay_object->OpenSharedHandle(in_NTHandle,
                                                             *riid.decoded_value,
                                                             out_hp_ppvObj);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvObj, out_hp_ppvObj, format::ApiCall_ID3D12Device_OpenSharedHandle);
        }
        CheckReplayResult("ID3D12Device_OpenSharedHandle", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_OpenSharedHandleByName(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             Name,
    DWORD                                       Access,
    PointerDecoder<uint64_t, void*>*            pNTHandle)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNTHandle->IsNull())
        {
            pNTHandle->AllocateOutputData(1);
        }
        auto out_p_pNTHandle    = pNTHandle->GetPointer();
        auto out_op_pNTHandle   = reinterpret_cast<HANDLE*>(pNTHandle->GetOutputPointer());
        auto replay_result = replay_object->OpenSharedHandleByName(Name->GetPointer(),
                                                                   Access,
                                                                   out_op_pNTHandle);
        CheckReplayResult("ID3D12Device_OpenSharedHandleByName", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pNTHandle, out_p_pNTHandle, format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName, "ID3D12Device_OpenSharedHandleByName");
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_MakeResident(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects, NumObjects);
        auto replay_result = replay_object->MakeResident(NumObjects,
                                                         in_ppObjects);
        CheckReplayResult("ID3D12Device_MakeResident", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_Evict(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects, NumObjects);
        auto replay_result = replay_object->Evict(NumObjects,
                                                  in_ppObjects);
        CheckReplayResult("ID3D12Device_Evict", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      InitialValue,
    D3D12_FENCE_FLAGS                           Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFence)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppFence{};
        if(!ppFence->IsNull())
        {
            ppFence->SetHandleLength(1);
            ppFence->SetConsumerData(0, &object_info_ppFence);
        }
        auto replay_result = OverrideCreateFence(replay_object,
                                                 return_value,
                                                 InitialValue,
                                                 Flags,
                                                 riid,
                                                 ppFence);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppFence->GetPointer(), ppFence->GetHandlePointer(), std::move(object_info_ppFence), format::ApiCall_ID3D12Device_CreateFence);
        }
        CheckReplayResult("ID3D12Device_CreateFence", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDeviceRemovedReason();
        CheckReplayResult("ID3D12Device_GetDeviceRemovedReason", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetCopyableFootprints(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDesc,
    UINT                                        FirstSubresource,
    UINT                                        NumSubresources,
    UINT64                                      BaseOffset,
    StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
    PointerDecoder<UINT>*                       pNumRows,
    PointerDecoder<UINT64>*                     pRowSizeInBytes,
    PointerDecoder<UINT64>*                     pTotalBytes)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pLayouts->IsNull())
        {
            pLayouts->AllocateOutputData(NumSubresources);
        }
        if(!pNumRows->IsNull())
        {
            pNumRows->AllocateOutputData(NumSubresources);
        }
        if(!pRowSizeInBytes->IsNull())
        {
            pRowSizeInBytes->AllocateOutputData(NumSubresources);
        }
        if(!pTotalBytes->IsNull())
        {
            pTotalBytes->AllocateOutputData(1);
        }
        replay_object->GetCopyableFootprints(pResourceDesc->GetPointer(),
                                             FirstSubresource,
                                             NumSubresources,
                                             BaseOffset,
                                             pLayouts->GetOutputPointer(),
                                             pNumRows->GetOutputPointer(),
                                             pRowSizeInBytes->GetOutputPointer(),
                                             pTotalBytes->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateQueryHeap(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto out_p_ppvHeap    = ppvHeap->GetPointer();
        auto out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->CreateQueryHeap(pDesc->GetPointer(),
                                                            *riid.decoded_value,
                                                            out_hp_ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvHeap, out_hp_ppvHeap, format::ApiCall_ID3D12Device_CreateQueryHeap);
        }
        CheckReplayResult("ID3D12Device_CreateQueryHeap", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_SetStablePowerState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetStablePowerState(Enable);
        CheckReplayResult("ID3D12Device_SetStablePowerState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandSignature(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
    format::HandleId                            pRootSignature,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvCommandSignature)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pRootSignature = GetObjectInfo(pRootSignature);
        DxObjectInfo object_info_ppvCommandSignature{};
        if(!ppvCommandSignature->IsNull())
        {
            ppvCommandSignature->SetHandleLength(1);
            ppvCommandSignature->SetConsumerData(0, &object_info_ppvCommandSignature);
        }
        auto replay_result = OverrideCreateCommandSignature(replay_object,
                                                            return_value,
                                                            pDesc,
                                                            in_pRootSignature,
                                                            riid,
                                                            ppvCommandSignature);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvCommandSignature->GetPointer(), ppvCommandSignature->GetHandlePointer(), std::move(object_info_ppvCommandSignature), format::ApiCall_ID3D12Device_CreateCommandSignature);
        }
        CheckReplayResult("ID3D12Device_CreateCommandSignature", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetResourceTiling(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pTiledResource,
    PointerDecoder<UINT>*                       pNumTilesForEntireResource,
    StructPointerDecoder<Decoded_D3D12_PACKED_MIP_INFO>* pPackedMipDesc,
    StructPointerDecoder<Decoded_D3D12_TILE_SHAPE>* pStandardTileShapeForNonPackedMips,
    PointerDecoder<UINT>*                       pNumSubresourceTilings,
    UINT                                        FirstSubresourceTilingToGet,
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_TILING>* pSubresourceTilingsForNonPackedMips)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTiledResource = MapObject<ID3D12Resource>(pTiledResource);
        if(!pNumTilesForEntireResource->IsNull())
        {
            pNumTilesForEntireResource->AllocateOutputData(1);
        }
        if(!pPackedMipDesc->IsNull())
        {
            pPackedMipDesc->AllocateOutputData(1);
        }
        if(!pStandardTileShapeForNonPackedMips->IsNull())
        {
            pStandardTileShapeForNonPackedMips->AllocateOutputData(1);
        }
        if(!pNumSubresourceTilings->IsNull())
        {
            pNumSubresourceTilings->AllocateOutputData(1);
        }
        if(!pSubresourceTilingsForNonPackedMips->IsNull())
        {
            pSubresourceTilingsForNonPackedMips->AllocateOutputData(!pNumSubresourceTilings->IsNull() ? *pNumSubresourceTilings->GetPointer() : 0);
        }
        replay_object->GetResourceTiling(in_pTiledResource,
                                         pNumTilesForEntireResource->GetOutputPointer(),
                                         pPackedMipDesc->GetOutputPointer(),
                                         pStandardTileShapeForNonPackedMips->GetOutputPointer(),
                                         pNumSubresourceTilings->GetOutputPointer(),
                                         FirstSubresourceTilingToGet,
                                         pSubresourceTilingsForNonPackedMips->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetAdapterLuid(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_LUID                                return_value)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetAdapterLuid();
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             pName,
    format::HandleId                            pPipeline)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pPipeline = MapObject<ID3D12PipelineState>(pPipeline);
        auto replay_result = replay_object->StorePipeline(pName->GetPointer(),
                                                          in_pPipeline);
        CheckReplayResult("ID3D12PipelineLibrary_StorePipeline", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             pName,
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        DxObjectInfo object_info_ppPipelineState{};
        if(!ppPipelineState->IsNull())
        {
            ppPipelineState->SetHandleLength(1);
            ppPipelineState->SetConsumerData(0, &object_info_ppPipelineState);
        }
        auto replay_result = OverrideLoadGraphicsPipeline(replay_object,
                                                          return_value,
                                                          pName,
                                                          pDesc,
                                                          riid,
                                                          ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info_ppPipelineState), format::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadGraphicsPipeline", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             pName,
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        DxObjectInfo object_info_ppPipelineState{};
        if(!ppPipelineState->IsNull())
        {
            ppPipelineState->SetHandleLength(1);
            ppPipelineState->SetConsumerData(0, &object_info_ppPipelineState);
        }
        auto replay_result = OverrideLoadComputePipeline(replay_object,
                                                         return_value,
                                                         pName,
                                                         pDesc,
                                                         riid,
                                                         ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info_ppPipelineState), format::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadComputePipeline", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    SIZE_T                                      return_value)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSerializedSize();
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_Serialize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pData,
    SIZE_T                                      DataSizeInBytes)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSizeInBytes);
        }
        auto replay_result = replay_object->Serialize(pData->GetOutputPointer(),
                                                      DataSizeInBytes);
        CheckReplayResult("ID3D12PipelineLibrary_Serialize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             pName,
    StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        DxObjectInfo object_info_ppPipelineState{};
        if(!ppPipelineState->IsNull())
        {
            ppPipelineState->SetHandleLength(1);
            ppPipelineState->SetConsumerData(0, &object_info_ppPipelineState);
        }
        auto replay_result = OverrideLoadPipeline(replay_object,
                                                  return_value,
                                                  pName,
                                                  pDesc,
                                                  riid,
                                                  ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info_ppPipelineState), format::ApiCall_ID3D12PipelineLibrary1_LoadPipeline);
        }
        CheckReplayResult("ID3D12PipelineLibrary1_LoadPipeline", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device1_CreatePipelineLibrary(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pLibraryBlob,
    SIZE_T                                      BlobLength,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineLibrary)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppPipelineLibrary{};
        if(!ppPipelineLibrary->IsNull())
        {
            ppPipelineLibrary->SetHandleLength(1);
            ppPipelineLibrary->SetConsumerData(0, &object_info_ppPipelineLibrary);
        }
        auto replay_result = OverrideCreatePipelineLibrary(replay_object,
                                                           return_value,
                                                           pLibraryBlob,
                                                           BlobLength,
                                                           riid,
                                                           ppPipelineLibrary);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineLibrary->GetPointer(), ppPipelineLibrary->GetHandlePointer(), std::move(object_info_ppPipelineLibrary), format::ApiCall_ID3D12Device1_CreatePipelineLibrary);
        }
        CheckReplayResult("ID3D12Device1_CreatePipelineLibrary", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<ID3D12Fence*>*         ppFences,
    PointerDecoder<UINT64>*                     pFenceValues,
    UINT                                        NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS             Flags,
    uint64_t                                    hEvent)
{
    auto replay_object = MapObject<ID3D12Device1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppFences = MapObjects<ID3D12Fence>(ppFences, NumFences);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion, "ID3D12Device1_SetEventOnMultipleFenceCompletion"));
        auto replay_result = replay_object->SetEventOnMultipleFenceCompletion(in_ppFences,
                                                                              pFenceValues->GetPointer(),
                                                                              NumFences,
                                                                              Flags,
                                                                              in_hEvent);
        CheckReplayResult("ID3D12Device1_SetEventOnMultipleFenceCompletion", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device1_SetResidencyPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects,
    PointerDecoder<D3D12_RESIDENCY_PRIORITY>*   pPriorities)
{
    auto replay_object = MapObject<ID3D12Device1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects, NumObjects);
        auto replay_result = replay_object->SetResidencyPriority(NumObjects,
                                                                 in_ppObjects,
                                                                 pPriorities->GetPointer());
        CheckReplayResult("ID3D12Device1_SetResidencyPriority", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device2_CreatePipelineState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12Device2>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->CreatePipelineState(pDesc->GetPointer(),
                                                                *riid.decoded_value,
                                                                out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState, format::ApiCall_ID3D12Device2_CreatePipelineState);
        }
        CheckReplayResult("ID3D12Device2_CreatePipelineState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    pAddress,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppvHeap{};
        if(!ppvHeap->IsNull())
        {
            ppvHeap->SetHandleLength(1);
            ppvHeap->SetConsumerData(0, &object_info_ppvHeap);
        }
        auto replay_result = OverrideOpenExistingHeapFromAddress(replay_object,
                                                                 return_value,
                                                                 pAddress,
                                                                 riid,
                                                                 ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info_ppvHeap), format::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromAddress", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hFileMapping,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hFileMapping = static_cast<HANDLE>(PreProcessExternalObject(hFileMapping, format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping, "ID3D12Device3_OpenExistingHeapFromFileMapping"));
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto out_p_ppvHeap    = ppvHeap->GetPointer();
        auto out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->OpenExistingHeapFromFileMapping(in_hFileMapping,
                                                                            *riid.decoded_value,
                                                                            out_hp_ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvHeap, out_hp_ppvHeap, format::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromFileMapping", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device3_EnqueueMakeResident(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_RESIDENCY_FLAGS                       Flags,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects,
    format::HandleId                            pFenceToSignal,
    UINT64                                      FenceValueToSignal)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapObjects<ID3D12Pageable>(ppObjects, NumObjects);
        auto in_pFenceToSignal = GetObjectInfo(pFenceToSignal);
        auto replay_result = OverrideEnqueueMakeResident(replay_object,
                                                         return_value,
                                                         Flags,
                                                         NumObjects,
                                                         ppObjects,
                                                         in_pFenceToSignal,
                                                         FenceValueToSignal);
        CheckReplayResult("ID3D12Device3_EnqueueMakeResident", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFence)
{
    auto replay_object = MapObject<ID3D12ProtectedSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppFence->IsNull()) ppFence->SetHandleLength(1);
        auto out_p_ppFence    = ppFence->GetPointer();
        auto out_hp_ppFence   = ppFence->GetHandlePointer();
        auto replay_result = replay_object->GetStatusFence(*riid.decoded_value,
                                                           out_hp_ppFence);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppFence, out_hp_ppFence, format::ApiCall_ID3D12ProtectedSession_GetStatusFence);
        }
        CheckReplayResult("ID3D12ProtectedSession_GetStatusFence", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_PROTECTED_SESSION_STATUS              return_value)
{
    auto replay_object = MapObject<ID3D12ProtectedSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSessionStatus();
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    auto replay_object = MapObject<ID3D12ProtectedResourceSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateCommandList1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        nodeMask,
    D3D12_COMMAND_LIST_TYPE                     type,
    D3D12_COMMAND_LIST_FLAGS                    flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandList)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppCommandList{};
        if(!ppCommandList->IsNull())
        {
            ppCommandList->SetHandleLength(1);
            ppCommandList->SetConsumerData(0, &object_info_ppCommandList);
        }
        auto replay_result = OverrideCreateCommandList1(replay_object,
                                                        return_value,
                                                        nodeMask,
                                                        type,
                                                        flags,
                                                        riid,
                                                        ppCommandList);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppCommandList->GetPointer(), ppCommandList->GetHandlePointer(), std::move(object_info_ppCommandList), format::ApiCall_ID3D12Device4_CreateCommandList1);
        }
        CheckReplayResult("ID3D12Device4_CreateCommandList1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppSession)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSession->IsNull()) ppSession->SetHandleLength(1);
        auto out_p_ppSession    = ppSession->GetPointer();
        auto out_hp_ppSession   = ppSession->GetHandlePointer();
        auto replay_result = replay_object->CreateProtectedResourceSession(pDesc->GetPointer(),
                                                                           *riid.decoded_value,
                                                                           out_hp_ppSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSession, out_hp_ppSession, format::ApiCall_ID3D12Device4_CreateProtectedResourceSession);
        }
        CheckReplayResult("ID3D12Device4_CreateProtectedResourceSession", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateCommittedResource1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        DxObjectInfo object_info_ppvResource{};
        if(!ppvResource->IsNull())
        {
            ppvResource->SetHandleLength(1);
            ppvResource->SetConsumerData(0, &object_info_ppvResource);
        }
        auto replay_result = OverrideCreateCommittedResource1(replay_object,
                                                              return_value,
                                                              pHeapProperties,
                                                              HeapFlags,
                                                              pDesc,
                                                              InitialResourceState,
                                                              pOptimizedClearValue,
                                                              in_pProtectedSession,
                                                              riidResource,
                                                              ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info_ppvResource), format::ApiCall_ID3D12Device4_CreateCommittedResource1);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device4_CreateCommittedResource1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateHeap1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        DxObjectInfo object_info_ppvHeap{};
        if(!ppvHeap->IsNull())
        {
            ppvHeap->SetHandleLength(1);
            ppvHeap->SetConsumerData(0, &object_info_ppvHeap);
        }
        auto replay_result = OverrideCreateHeap1(replay_object,
                                                 return_value,
                                                 pDesc,
                                                 in_pProtectedSession,
                                                 riid,
                                                 ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info_ppvHeap), format::ApiCall_ID3D12Device4_CreateHeap1);
        }
        CheckReplayResult("ID3D12Device4_CreateHeap1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateReservedResource1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        DxObjectInfo object_info_ppvResource{};
        if(!ppvResource->IsNull())
        {
            ppvResource->SetHandleLength(1);
            ppvResource->SetConsumerData(0, &object_info_ppvResource);
        }
        auto replay_result = OverrideCreateReservedResource1(replay_object,
                                                             return_value,
                                                             pDesc,
                                                             InitialState,
                                                             pOptimizedClearValue,
                                                             in_pProtectedSession,
                                                             riid,
                                                             ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info_ppvResource), format::ApiCall_ID3D12Device4_CreateReservedResource1);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device4_CreateReservedResource1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO      return_value,
    UINT                                        visibleMask,
    UINT                                        numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        if(!pResourceAllocationInfo1->IsNull())
        {
            pResourceAllocationInfo1->AllocateOutputData(numResourceDescs);
        }
        auto replay_result = replay_object->GetResourceAllocationInfo1(visibleMask,
                                                                       numResourceDescs,
                                                                       pResourceDescs->GetPointer(),
                                                                       pResourceAllocationInfo1->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_LIFETIME_STATE                        NewState)
{
    auto replay_object = MapObject<ID3D12LifetimeOwner>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->LifetimeStateUpdated(NewState);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_LUID                                return_value)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetLUID();
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppv)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppv->IsNull()) ppv->SetHandleLength(1);
        auto out_p_ppv    = ppv->GetPointer();
        auto out_hp_ppv   = ppv->GetHandlePointer();
        auto replay_result = replay_object->GetSwapChainObject(*riid.decoded_value,
                                                               out_hp_ppv);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppv, out_hp_ppv, format::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetSwapChainObject", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource,
    Decoded_GUID                                riidQueue,
    HandlePointerDecoder<void*>*                ppvQueue)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        if(!ppvQueue->IsNull()) ppvQueue->SetHandleLength(1);
        auto out_p_ppvQueue    = ppvQueue->GetPointer();
        auto out_hp_ppvQueue   = ppvQueue->GetHandlePointer();
        auto replay_result = replay_object->GetCurrentResourceAndCommandQueue(*riidResource.decoded_value,
                                                                              out_hp_ppvResource,
                                                                              *riidQueue.decoded_value,
                                                                              out_hp_ppvQueue);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource, format::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue);
            AddObject(out_p_ppvQueue, out_hp_ppvQueue, format::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->InsertImplicitSync();
        CheckReplayResult("ID3D12SwapChainAssistant_InsertImplicitSync", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pObject)
{
    auto replay_object = MapObject<ID3D12LifetimeTracker>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pObject = MapObject<ID3D12DeviceChild>(pObject);
        auto replay_result = replay_object->DestroyOwnedObject(in_pObject);
        CheckReplayResult("ID3D12LifetimeTracker_DestroyOwnedObject", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<uint8_t>*                    return_value,
    WStringDecoder*                             pExportName)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetShaderIdentifier(replay_object,
                                                         return_value,
                                                         pExportName);
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value,
    WStringDecoder*                             pExportName)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetShaderStackSize(pExportName->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPipelineStackSize();
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      PipelineStackSizeInBytes)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetPipelineStackSize(PipelineStackSizeInBytes);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_CreateLifetimeTracker(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pOwner,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvTracker)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pOwner = MapObject<ID3D12LifetimeOwner>(pOwner);
        if(!ppvTracker->IsNull()) ppvTracker->SetHandleLength(1);
        auto out_p_ppvTracker    = ppvTracker->GetPointer();
        auto out_hp_ppvTracker   = ppvTracker->GetHandlePointer();
        auto replay_result = replay_object->CreateLifetimeTracker(in_pOwner,
                                                                  *riid.decoded_value,
                                                                  out_hp_ppvTracker);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvTracker, out_hp_ppvTracker, format::ApiCall_ID3D12Device5_CreateLifetimeTracker);
        }
        CheckReplayResult("ID3D12Device5_CreateLifetimeTracker", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_RemoveDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RemoveDevice();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pNumMetaCommands,
    StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNumMetaCommands->IsNull())
        {
            pNumMetaCommands->AllocateOutputData(1, GetOutputArrayCount("ID3D12Device5::EnumerateMetaCommands", return_value, object_id, VariableLengthArrayIndices::kD3D12Device5ArrayEnumerateMetaCommands, pNumMetaCommands, pDescs));
        }
        if(!pDescs->IsNull() && !pNumMetaCommands->IsNull())
        {
            pDescs->AllocateOutputData(*pNumMetaCommands->GetOutputPointer());
        }
        auto replay_result = replay_object->EnumerateMetaCommands(pNumMetaCommands->GetOutputPointer(),
                                                                  pDescs->GetOutputPointer());
        if (pDescs->IsNull() && !pNumMetaCommands->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D12Device5ArrayEnumerateMetaCommands, *pNumMetaCommands->GetOutputPointer()); }
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommands", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE          Stage,
    PointerDecoder<UINT>*                       pTotalStructureSizeInBytes,
    PointerDecoder<UINT>*                       pParameterCount,
    StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC>* pParameterDescs)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        if(!pTotalStructureSizeInBytes->IsNull())
        {
            pTotalStructureSizeInBytes->AllocateOutputData(1);
        }
        if(!pParameterCount->IsNull())
        {
            pParameterCount->AllocateOutputData(1, GetOutputArrayCount("ID3D12Device5::EnumerateMetaCommandParameters", return_value, object_id, VariableLengthArrayIndices::kD3D12Device5ArrayEnumerateMetaCommandParameters, pParameterCount, pParameterDescs));
        }
        if(!pParameterDescs->IsNull() && !pParameterCount->IsNull())
        {
            pParameterDescs->AllocateOutputData(*pParameterCount->GetOutputPointer());
        }
        auto replay_result = replay_object->EnumerateMetaCommandParameters(*CommandId.decoded_value,
                                                                           Stage,
                                                                           pTotalStructureSizeInBytes->GetOutputPointer(),
                                                                           pParameterCount->GetOutputPointer(),
                                                                           pParameterDescs->GetOutputPointer());
        if (pParameterDescs->IsNull() && !pParameterCount->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D12Device5ArrayEnumerateMetaCommandParameters, *pParameterCount->GetOutputPointer()); }
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommandParameters", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_CreateMetaCommand(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                CommandId,
    UINT                                        NodeMask,
    PointerDecoder<uint8_t>*                    pCreationParametersData,
    SIZE_T                                      CreationParametersDataSizeInBytes,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppMetaCommand)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppMetaCommand->IsNull()) ppMetaCommand->SetHandleLength(1);
        auto out_p_ppMetaCommand    = ppMetaCommand->GetPointer();
        auto out_hp_ppMetaCommand   = ppMetaCommand->GetHandlePointer();
        auto replay_result = replay_object->CreateMetaCommand(*CommandId.decoded_value,
                                                              NodeMask,
                                                              pCreationParametersData->GetPointer(),
                                                              CreationParametersDataSizeInBytes,
                                                              *riid.decoded_value,
                                                              out_hp_ppMetaCommand);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppMetaCommand, out_hp_ppMetaCommand, format::ApiCall_ID3D12Device5_CreateMetaCommand);
        }
        CheckReplayResult("ID3D12Device5_CreateMetaCommand", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_CreateStateObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppStateObject)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        DxObjectInfo object_info_ppStateObject{};
        if(!ppStateObject->IsNull())
        {
            ppStateObject->SetHandleLength(1);
            ppStateObject->SetConsumerData(0, &object_info_ppStateObject);
        }
        auto replay_result = OverrideCreateStateObject(replay_object,
                                                       return_value,
                                                       pDesc,
                                                       riid,
                                                       ppStateObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppStateObject->GetPointer(), ppStateObject->GetHandlePointer(), std::move(object_info_ppStateObject), format::ApiCall_ID3D12Device5_CreateStateObject);
        }
        CheckReplayResult("ID3D12Device5_CreateStateObject", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!pInfo->IsNull())
        {
            pInfo->AllocateOutputData(1);
        }
        OverrideGetRaytracingAccelerationStructurePrebuildInfo(replay_object,
                                                               pDesc,
                                                               pInfo);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_CheckDriverMatchingIdentifier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS     return_value,
    D3D12_SERIALIZED_DATA_TYPE                  SerializedDataType,
    StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>* pIdentifierToCheck)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckDriverMatchingIdentifier(SerializedDataType,
                                                                          pIdentifierToCheck->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        OverrideSetAutoBreadcrumbsEnablement(replay_object,
                                             Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        OverrideSetPageFaultEnablement(replay_object,
                                       Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetWatsonDumpEnablement(Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        OverrideSetBreadcrumbContextEnablement(replay_object,
                                               Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        MarkersOnly)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UseMarkersOnlyAutoBreadcrumbs(MarkersOnly);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData>(object_id);
    if (replay_object != nullptr)
    {
        if(!pOutput->IsNull())
        {
            pOutput->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetAutoBreadcrumbsOutput(pOutput->GetOutputPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pOutput->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = replay_object->GetPageFaultAllocationOutput(pOutput->GetPointer());
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pOutput->IsNull())
        {
            pOutput->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetAutoBreadcrumbsOutput1(pOutput->GetOutputPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData1>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pOutput->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = replay_object->GetPageFaultAllocationOutput1(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData2>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pOutput->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = replay_object->GetPageFaultAllocationOutput2(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetDeviceState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRED_DEVICE_STATE                     return_value)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDeviceState();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_BACKGROUND_PROCESSING_MODE            Mode,
    D3D12_MEASUREMENTS_ACTION                   MeasurementsAction,
    uint64_t                                    hEventToSignalUponCompletion,
    PointerDecoder<BOOL>*                       pbFurtherMeasurementsDesired)
{
    auto replay_object = MapObject<ID3D12Device6>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEventToSignalUponCompletion = static_cast<HANDLE>(PreProcessExternalObject(hEventToSignalUponCompletion, format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode, "ID3D12Device6_SetBackgroundProcessingMode"));
        if(!pbFurtherMeasurementsDesired->IsNull())
        {
            pbFurtherMeasurementsDesired->AllocateOutputData(1);
        }
        auto replay_result = replay_object->SetBackgroundProcessingMode(Mode,
                                                                        MeasurementsAction,
                                                                        in_hEventToSignalUponCompletion,
                                                                        pbFurtherMeasurementsDesired->GetOutputPointer());
        CheckReplayResult("ID3D12Device6_SetBackgroundProcessingMode", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value)
{
    auto replay_object = MapObject<ID3D12ProtectedResourceSession1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device7_AddToStateObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
    format::HandleId                            pStateObjectToGrowFrom,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppNewStateObject)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pAddition->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto in_pStateObjectToGrowFrom = GetObjectInfo(pStateObjectToGrowFrom);
        DxObjectInfo object_info_ppNewStateObject{};
        if(!ppNewStateObject->IsNull())
        {
            ppNewStateObject->SetHandleLength(1);
            ppNewStateObject->SetConsumerData(0, &object_info_ppNewStateObject);
        }
        auto replay_result = OverrideAddToStateObject(replay_object,
                                                      return_value,
                                                      pAddition,
                                                      in_pStateObjectToGrowFrom,
                                                      riid,
                                                      ppNewStateObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppNewStateObject->GetPointer(), ppNewStateObject->GetHandlePointer(), std::move(object_info_ppNewStateObject), format::ApiCall_ID3D12Device7_AddToStateObject);
        }
        CheckReplayResult("ID3D12Device7_AddToStateObject", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppSession)
{
    auto replay_object = MapObject<ID3D12Device7>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSession->IsNull()) ppSession->SetHandleLength(1);
        auto out_p_ppSession    = ppSession->GetPointer();
        auto out_hp_ppSession   = ppSession->GetHandlePointer();
        auto replay_result = replay_object->CreateProtectedResourceSession1(pDesc->GetPointer(),
                                                                            *riid.decoded_value,
                                                                            out_hp_ppSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSession, out_hp_ppSession, format::ApiCall_ID3D12Device7_CreateProtectedResourceSession1);
        }
        CheckReplayResult("ID3D12Device7_CreateProtectedResourceSession1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO      return_value,
    UINT                                        visibleMask,
    UINT                                        numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        if(!pResourceAllocationInfo1->IsNull())
        {
            pResourceAllocationInfo1->AllocateOutputData(numResourceDescs);
        }
        auto replay_result = replay_object->GetResourceAllocationInfo2(visibleMask,
                                                                       numResourceDescs,
                                                                       pResourceDescs->GetPointer(),
                                                                       pResourceAllocationInfo1->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_CreateCommittedResource2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        DxObjectInfo object_info_ppvResource{};
        if(!ppvResource->IsNull())
        {
            ppvResource->SetHandleLength(1);
            ppvResource->SetConsumerData(0, &object_info_ppvResource);
        }
        auto replay_result = OverrideCreateCommittedResource2(replay_object,
                                                              return_value,
                                                              pHeapProperties,
                                                              HeapFlags,
                                                              pDesc,
                                                              InitialResourceState,
                                                              pOptimizedClearValue,
                                                              in_pProtectedSession,
                                                              riidResource,
                                                              ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info_ppvResource), format::ApiCall_ID3D12Device8_CreateCommittedResource2);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device8_CreateCommittedResource2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_CreatePlacedResource1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pHeap,
    UINT64                                      HeapOffset,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
    D3D12_RESOURCE_STATES                       InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreatePlacedResource1(in_pHeap,
                                                                  HeapOffset,
                                                                  pDesc->GetPointer(),
                                                                  InitialState,
                                                                  pOptimizedClearValue->GetPointer(),
                                                                  *riid.decoded_value,
                                                                  out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource, format::ApiCall_ID3D12Device8_CreatePlacedResource1);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device8_CreatePlacedResource1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pTargetedResource,
    format::HandleId                            pFeedbackResource,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTargetedResource = MapObject<ID3D12Resource>(pTargetedResource);
        auto in_pFeedbackResource = MapObject<ID3D12Resource>(pFeedbackResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateSamplerFeedbackUnorderedAccessView(in_pTargetedResource,
                                                                in_pFeedbackResource,
                                                                *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDesc,
    UINT                                        FirstSubresource,
    UINT                                        NumSubresources,
    UINT64                                      BaseOffset,
    StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
    PointerDecoder<UINT>*                       pNumRows,
    PointerDecoder<UINT64>*                     pRowSizeInBytes,
    PointerDecoder<UINT64>*                     pTotalBytes)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        if(!pLayouts->IsNull())
        {
            pLayouts->AllocateOutputData(NumSubresources);
        }
        if(!pNumRows->IsNull())
        {
            pNumRows->AllocateOutputData(NumSubresources);
        }
        if(!pRowSizeInBytes->IsNull())
        {
            pRowSizeInBytes->AllocateOutputData(NumSubresources);
        }
        if(!pTotalBytes->IsNull())
        {
            pTotalBytes->AllocateOutputData(1);
        }
        replay_object->GetCopyableFootprints1(pResourceDesc->GetPointer(),
                                              FirstSubresource,
                                              NumSubresources,
                                              BaseOffset,
                                              pLayouts->GetOutputPointer(),
                                              pNumRows->GetOutputPointer(),
                                              pRowSizeInBytes->GetOutputPointer(),
                                              pTotalBytes->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppProtectedSession)
{
    auto replay_object = MapObject<ID3D12Resource1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppProtectedSession->IsNull()) ppProtectedSession->SetHandleLength(1);
        auto out_p_ppProtectedSession    = ppProtectedSession->GetPointer();
        auto out_hp_ppProtectedSession   = ppProtectedSession->GetHandlePointer();
        auto replay_result = replay_object->GetProtectedResourceSession(*riid.decoded_value,
                                                                        out_hp_ppProtectedSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppProtectedSession, out_hp_ppProtectedSession, format::ApiCall_ID3D12Resource1_GetProtectedResourceSession);
        }
        CheckReplayResult("ID3D12Resource1_GetProtectedResourceSession", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource2_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC1                return_value)
{
    auto replay_object = MapObject<ID3D12Resource2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppProtectedSession)
{
    auto replay_object = MapObject<ID3D12Heap1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppProtectedSession->IsNull()) ppProtectedSession->SetHandleLength(1);
        auto out_p_ppProtectedSession    = ppProtectedSession->GetPointer();
        auto out_hp_ppProtectedSession   = ppProtectedSession->GetHandlePointer();
        auto replay_result = replay_object->GetProtectedResourceSession(*riid.decoded_value,
                                                                        out_hp_ppProtectedSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppProtectedSession, out_hp_ppProtectedSession, format::ApiCall_ID3D12Heap1_GetProtectedResourceSession);
        }
        CheckReplayResult("ID3D12Heap1_GetProtectedResourceSession", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pProtectedResourceSession)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pProtectedResourceSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedResourceSession);
        replay_object->SetProtectedResourceSession(in_pProtectedResourceSession);
    }
}

void Dx12ReplayConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value,
    D3D12_META_COMMAND_PARAMETER_STAGE          Stage,
    UINT                                        ParameterIndex)
{
    auto replay_object = MapObject<ID3D12MetaCommand>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRequiredParameterResourceSize(Stage,
                                                                             ParameterIndex);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_BeginRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS                     Flags)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pRenderTargets->GetMetaStructPointer(), pRenderTargets->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(pDepthStencil->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        replay_object->BeginRenderPass(NumRenderTargets,
                                       pRenderTargets->GetPointer(),
                                       pDepthStencil->GetPointer(),
                                       Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndRenderPass();
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pMetaCommand,
    PointerDecoder<uint8_t>*                    pInitializationParametersData,
    SIZE_T                                      InitializationParametersDataSizeInBytes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pMetaCommand = MapObject<ID3D12MetaCommand>(pMetaCommand);
        replay_object->InitializeMetaCommand(in_pMetaCommand,
                                             pInitializationParametersData->GetPointer(),
                                             InitializationParametersDataSizeInBytes);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pMetaCommand,
    PointerDecoder<uint8_t>*                    pExecutionParametersData,
    SIZE_T                                      ExecutionParametersDataSizeInBytes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pMetaCommand = MapObject<ID3D12MetaCommand>(pMetaCommand);
        replay_object->ExecuteMetaCommand(in_pMetaCommand,
                                          pExecutionParametersData->GetPointer(),
                                          ExecutionParametersDataSizeInBytes);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
    UINT                                        NumPostbuildInfoDescs,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructArrayObjects(pPostbuildInfoDescs->GetMetaStructPointer(), pPostbuildInfoDescs->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideBuildRaytracingAccelerationStructure(replay_object,
                                                     pDesc,
                                                     NumPostbuildInfoDescs,
                                                     pPostbuildInfoDescs);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
    UINT                                        NumSourceAccelerationStructures,
    PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>*  pSourceAccelerationStructureData)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if (pSourceAccelerationStructureData && !pSourceAccelerationStructureData->IsNull())
        {
            MapGpuVirtualAddresses(pSourceAccelerationStructureData->GetPointer(), NumSourceAccelerationStructures);
        }
        replay_object->EmitRaytracingAccelerationStructurePostbuildInfo(pDesc->GetPointer(),
                                                                        NumSourceAccelerationStructures,
                                                                        pSourceAccelerationStructureData->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_GPU_VIRTUAL_ADDRESS                   DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS                   SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        MapGpuVirtualAddress(DestAccelerationStructureData);
        MapGpuVirtualAddress(SourceAccelerationStructureData);
        replay_object->CopyRaytracingAccelerationStructure(DestAccelerationStructureData,
                                                           SourceAccelerationStructureData,
                                                           Mode);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pStateObject)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pStateObject = GetObjectInfo(pStateObject);
        OverrideSetPipelineState1(replay_object,
                                  in_pStateObject);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideDispatchRays(replay_object,
                             pDesc);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ShaderCacheSession_FindValue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pKey,
    UINT                                        KeySize,
    PointerDecoder<uint8_t>*                    pValue,
    PointerDecoder<UINT>*                       pValueSize)
{
    auto replay_object = MapObject<ID3D12ShaderCacheSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!pValueSize->IsNull())
        {
            pValueSize->AllocateOutputData(1, GetOutputArrayCount("ID3D12ShaderCacheSession::FindValue", return_value, object_id, VariableLengthArrayIndices::kD3D12ShaderCacheSessionArrayFindValue, pValueSize, pValue));
        }
        if(!pValue->IsNull() && !pValueSize->IsNull())
        {
            pValue->AllocateOutputData(*pValueSize->GetOutputPointer());
        }
        auto replay_result = replay_object->FindValue(pKey->GetPointer(),
                                                      KeySize,
                                                      pValue->GetOutputPointer(),
                                                      pValueSize->GetOutputPointer());
        if (pValue->IsNull() && !pValueSize->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D12ShaderCacheSessionArrayFindValue, *pValueSize->GetOutputPointer()); }
        CheckReplayResult("ID3D12ShaderCacheSession_FindValue", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ShaderCacheSession_StoreValue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pKey,
    UINT                                        KeySize,
    PointerDecoder<uint8_t>*                    pValue,
    UINT                                        ValueSize)
{
    auto replay_object = MapObject<ID3D12ShaderCacheSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->StoreValue(pKey->GetPointer(),
                                                       KeySize,
                                                       pValue->GetPointer(),
                                                       ValueSize);
        CheckReplayResult("ID3D12ShaderCacheSession_StoreValue", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ShaderCacheSession_SetDeleteOnDestroy(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12ShaderCacheSession>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetDeleteOnDestroy();
    }
}

void Dx12ReplayConsumer::Process_ID3D12ShaderCacheSession_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_SHADER_CACHE_SESSION_DESC     return_value)
{
    auto replay_object = MapObject<ID3D12ShaderCacheSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device9_CreateShaderCacheSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_SHADER_CACHE_SESSION_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvSession)
{
    auto replay_object = MapObject<ID3D12Device9>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvSession->IsNull()) ppvSession->SetHandleLength(1);
        auto out_p_ppvSession    = ppvSession->GetPointer();
        auto out_hp_ppvSession   = ppvSession->GetHandlePointer();
        auto replay_result = replay_object->CreateShaderCacheSession(pDesc->GetPointer(),
                                                                     *riid.decoded_value,
                                                                     out_hp_ppvSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvSession, out_hp_ppvSession, format::ApiCall_ID3D12Device9_CreateShaderCacheSession);
        }
        CheckReplayResult("ID3D12Device9_CreateShaderCacheSession", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device9_ShaderCacheControl(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_SHADER_CACHE_KIND_FLAGS               Kinds,
    D3D12_SHADER_CACHE_CONTROL_FLAGS            Control)
{
    auto replay_object = MapObject<ID3D12Device9>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ShaderCacheControl(Kinds,
                                                               Control);
        CheckReplayResult("ID3D12Device9_ShaderCacheControl", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device9_CreateCommandQueue1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
    Decoded_GUID                                CreatorID,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandQueue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        DxObjectInfo object_info_ppCommandQueue{};
        if(!ppCommandQueue->IsNull())
        {
            ppCommandQueue->SetHandleLength(1);
            ppCommandQueue->SetConsumerData(0, &object_info_ppCommandQueue);
        }
        auto replay_result = OverrideCreateCommandQueue1(replay_object,
                                                         return_value,
                                                         pDesc,
                                                         CreatorID,
                                                         riid,
                                                         ppCommandQueue);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppCommandQueue->GetPointer(), ppCommandQueue->GetHandlePointer(), std::move(object_info_ppCommandQueue), format::ApiCall_ID3D12Device9_CreateCommandQueue1);
        }
        CheckReplayResult("ID3D12Device9_CreateCommandQueue1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device10_CreateCommittedResource3(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
    D3D12_BARRIER_LAYOUT                        InitialLayout,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    UINT32                                      NumCastableFormats,
    PointerDecoder<DXGI_FORMAT>*                pCastableFormats,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device10>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateCommittedResource3(pHeapProperties->GetPointer(),
                                                                     HeapFlags,
                                                                     pDesc->GetPointer(),
                                                                     InitialLayout,
                                                                     pOptimizedClearValue->GetPointer(),
                                                                     in_pProtectedSession,
                                                                     NumCastableFormats,
                                                                     pCastableFormats->GetPointer(),
                                                                     *riidResource.decoded_value,
                                                                     out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource, format::ApiCall_ID3D12Device10_CreateCommittedResource3);
        }
        CheckReplayResult("ID3D12Device10_CreateCommittedResource3", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device10_CreatePlacedResource2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pHeap,
    UINT64                                      HeapOffset,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
    D3D12_BARRIER_LAYOUT                        InitialLayout,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    UINT32                                      NumCastableFormats,
    PointerDecoder<DXGI_FORMAT>*                pCastableFormats,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device10>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreatePlacedResource2(in_pHeap,
                                                                  HeapOffset,
                                                                  pDesc->GetPointer(),
                                                                  InitialLayout,
                                                                  pOptimizedClearValue->GetPointer(),
                                                                  NumCastableFormats,
                                                                  pCastableFormats->GetPointer(),
                                                                  *riid.decoded_value,
                                                                  out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource, format::ApiCall_ID3D12Device10_CreatePlacedResource2);
        }
        CheckReplayResult("ID3D12Device10_CreatePlacedResource2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device10_CreateReservedResource2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_BARRIER_LAYOUT                        InitialLayout,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    UINT32                                      NumCastableFormats,
    PointerDecoder<DXGI_FORMAT>*                pCastableFormats,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device10>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateReservedResource2(pDesc->GetPointer(),
                                                                    InitialLayout,
                                                                    pOptimizedClearValue->GetPointer(),
                                                                    in_pProtectedSession,
                                                                    NumCastableFormats,
                                                                    pCastableFormats->GetPointer(),
                                                                    *riid.decoded_value,
                                                                    out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource, format::ApiCall_ID3D12Device10_CreateReservedResource2);
        }
        CheckReplayResult("ID3D12Device10_CreateReservedResource2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device11_CreateSampler2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC2>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device11>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        replay_object->CreateSampler2(pDesc->GetPointer(),
                                      *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12VirtualizationGuestDevice_ShareWithHost(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pObject,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto replay_object = MapObject<ID3D12VirtualizationGuestDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pObject = MapObject<ID3D12DeviceChild>(pObject);
        if(!pHandle->IsNull())
        {
            pHandle->AllocateOutputData(1);
        }
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = replay_object->ShareWithHost(in_pObject,
                                                          out_op_pHandle);
        CheckReplayResult("ID3D12VirtualizationGuestDevice_ShareWithHost", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHandle, out_p_pHandle, format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost, "ID3D12VirtualizationGuestDevice_ShareWithHost");
    }
}

void Dx12ReplayConsumer::Process_ID3D12VirtualizationGuestDevice_CreateFenceFd(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pFence,
    UINT64                                      FenceValue,
    PointerDecoder<int>*                        pFenceFd)
{
    auto replay_object = MapObject<ID3D12VirtualizationGuestDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pFence = MapObject<ID3D12Fence>(pFence);
        if(!pFenceFd->IsNull())
        {
            pFenceFd->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CreateFenceFd(in_pFence,
                                                          FenceValue,
                                                          pFenceFd->GetOutputPointer());
        CheckReplayResult("ID3D12VirtualizationGuestDevice_CreateFenceFd", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        bEnable)
{
    auto replay_object = MapObject<ID3D12Tools>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EnableShaderInstrumentation(bEnable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<ID3D12Tools>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ShaderInstrumentationEnabled();
    }
}

void Dx12ReplayConsumer::Process_ID3D12SDKConfiguration_SetSDKVersion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        SDKVersion,
    StringDecoder*                              SDKPath)
{
    auto replay_object = MapObject<ID3D12SDKConfiguration>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetSDKVersion(SDKVersion,
                                                          SDKPath->GetPointer());
        CheckReplayResult("ID3D12SDKConfiguration_SetSDKVersion", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SDKConfiguration1_CreateDeviceFactory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        SDKVersion,
    StringDecoder*                              SDKPath,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvFactory)
{
    auto replay_object = MapObject<ID3D12SDKConfiguration1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvFactory->IsNull()) ppvFactory->SetHandleLength(1);
        auto out_p_ppvFactory    = ppvFactory->GetPointer();
        auto out_hp_ppvFactory   = ppvFactory->GetHandlePointer();
        auto replay_result = replay_object->CreateDeviceFactory(SDKVersion,
                                                                SDKPath->GetPointer(),
                                                                *riid.decoded_value,
                                                                out_hp_ppvFactory);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvFactory, out_hp_ppvFactory, format::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory);
        }
        CheckReplayResult("ID3D12SDKConfiguration1_CreateDeviceFactory", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SDKConfiguration1_FreeUnusedSDKs(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12SDKConfiguration1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->FreeUnusedSDKs();
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_InitializeFromGlobalState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12DeviceFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->InitializeFromGlobalState();
        CheckReplayResult("ID3D12DeviceFactory_InitializeFromGlobalState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_ApplyToGlobalState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12DeviceFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ApplyToGlobalState();
        CheckReplayResult("ID3D12DeviceFactory_ApplyToGlobalState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_SetFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEVICE_FACTORY_FLAGS                  flags)
{
    auto replay_object = MapObject<ID3D12DeviceFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetFlags(flags);
        CheckReplayResult("ID3D12DeviceFactory_SetFlags", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_GetFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DEVICE_FACTORY_FLAGS                  return_value)
{
    auto replay_object = MapObject<ID3D12DeviceFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFlags();
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_GetConfigurationInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                clsid,
    Decoded_GUID                                iid,
    HandlePointerDecoder<void*>*                ppv)
{
    auto replay_object = MapObject<ID3D12DeviceFactory>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppv->IsNull()) ppv->SetHandleLength(1);
        auto out_p_ppv    = ppv->GetPointer();
        auto out_hp_ppv   = ppv->GetHandlePointer();
        auto replay_result = replay_object->GetConfigurationInterface(*clsid.decoded_value,
                                                                      *iid.decoded_value,
                                                                      out_hp_ppv);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppv, out_hp_ppv, format::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface);
        }
        CheckReplayResult("ID3D12DeviceFactory_GetConfigurationInterface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_EnableExperimentalFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumFeatures,
    StructPointerDecoder<Decoded_GUID>*         pIIDs,
    PointerDecoder<uint8_t>*                    pConfigurationStructs,
    PointerDecoder<UINT>*                       pConfigurationStructSizes)
{
    auto replay_object = MapObject<ID3D12DeviceFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->EnableExperimentalFeatures(NumFeatures,
                                                                       pIIDs->GetPointer(),
                                                                       pConfigurationStructs->GetPointer(),
                                                                       pConfigurationStructSizes->GetPointer());
        CheckReplayResult("ID3D12DeviceFactory_EnableExperimentalFeatures", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_CreateDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            adapter,
    D3D_FEATURE_LEVEL                           FeatureLevel,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDevice)
{
    auto replay_object = MapObject<ID3D12DeviceFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto in_adapter = MapObject<IUnknown>(adapter);
        if(!ppvDevice->IsNull()) ppvDevice->SetHandleLength(1);
        auto out_p_ppvDevice    = ppvDevice->GetPointer();
        auto out_hp_ppvDevice   = ppvDevice->GetHandlePointer();
        auto replay_result = replay_object->CreateDevice(in_adapter,
                                                         FeatureLevel,
                                                         *riid.decoded_value,
                                                         out_hp_ppvDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDevice, out_hp_ppvDevice, format::ApiCall_ID3D12DeviceFactory_CreateDevice);
        }
        CheckReplayResult("ID3D12DeviceFactory_CreateDevice", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceConfiguration_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_DEVICE_CONFIGURATION_DESC     return_value)
{
    auto replay_object = MapObject<ID3D12DeviceConfiguration>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pGuids,
    UINT                                        NumGuids)
{
    auto replay_object = MapObject<ID3D12DeviceConfiguration>(object_id);
    if (replay_object != nullptr)
    {
        if(!pGuids->IsNull())
        {
            pGuids->AllocateOutputData(NumGuids);
        }
        auto replay_result = replay_object->GetEnabledExperimentalFeatures(pGuids->GetOutputPointer(),
                                                                           NumGuids);
        CheckReplayResult("ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pDesc,
    HandlePointerDecoder<ID3D10Blob*>*          ppResult,
    HandlePointerDecoder<ID3D10Blob*>*          ppError)
{
    auto replay_object = MapObject<ID3D12DeviceConfiguration>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppResult->IsNull()) ppResult->SetHandleLength(1);
        auto out_p_ppResult    = ppResult->GetPointer();
        auto out_hp_ppResult   = ppResult->GetHandlePointer();
        if(!ppError->IsNull()) ppError->SetHandleLength(1);
        auto out_p_ppError    = ppError->GetPointer();
        auto out_hp_ppError   = ppError->GetHandlePointer();
        auto replay_result = replay_object->SerializeVersionedRootSignature(pDesc->GetPointer(),
                                                                            out_hp_ppResult,
                                                                            out_hp_ppError);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppResult, out_hp_ppResult, format::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature);
            AddObject(out_p_ppError, out_hp_ppError, format::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature);
        }
        CheckReplayResult("ID3D12DeviceConfiguration_SerializeVersionedRootSignature", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pBlob,
    SIZE_T                                      Size,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDeserializer)
{
    auto replay_object = MapObject<ID3D12DeviceConfiguration>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvDeserializer->IsNull()) ppvDeserializer->SetHandleLength(1);
        auto out_p_ppvDeserializer    = ppvDeserializer->GetPointer();
        auto out_hp_ppvDeserializer   = ppvDeserializer->GetHandlePointer();
        auto replay_result = replay_object->CreateVersionedRootSignatureDeserializer(pBlob->GetPointer(),
                                                                                     Size,
                                                                                     *riid.decoded_value,
                                                                                     out_hp_ppvDeserializer);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDeserializer, out_hp_ppvDeserializer, format::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer);
        }
        CheckReplayResult("ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_SHADING_RATE                          baseShadingRate,
    PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList5>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RSSetShadingRate(baseShadingRate,
                                        combiners->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            shadingRateImage)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList5>(object_id);
    if (replay_object != nullptr)
    {
        auto in_shadingRateImage = MapObject<ID3D12Resource>(shadingRateImage);
        replay_object->RSSetShadingRateImage(in_shadingRateImage);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        ThreadGroupCountX,
    UINT                                        ThreadGroupCountY,
    UINT                                        ThreadGroupCountZ)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList6>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DispatchMesh(ThreadGroupCountX,
                                    ThreadGroupCountY,
                                    ThreadGroupCountZ);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList7_Barrier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT32                                      NumBarrierGroups,
    StructPointerDecoder<Decoded_D3D12_BARRIER_GROUP>* pBarrierGroups)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList7>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pBarrierGroups->GetMetaStructPointer(), pBarrierGroups->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        replay_object->Barrier(NumBarrierGroups,
                               pBarrierGroups->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        FrontStencilRef,
    UINT                                        BackStencilRef)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList8>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->OMSetFrontAndBackStencilRef(FrontStencilRef,
                                                   BackStencilRef);
    }
}

void Dx12ReplayConsumer::Process_ID3D10Blob_GetBufferPointer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    uint64_t                                    return_value)
{
    auto replay_object = MapObject<ID3D10Blob>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBufferPointer();
    }
}

void Dx12ReplayConsumer::Process_ID3D10Blob_GetBufferSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    SIZE_T                                      return_value)
{
    auto replay_object = MapObject<ID3D10Blob>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBufferSize();
    }
}

void Dx12ReplayConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    callbackFn,
    uint64_t                                    pData,
    PointerDecoder<UINT>*                       pCallbackID)
{
    auto replay_object = MapObject<ID3DDestructionNotifier>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pData = PreProcessExternalObject(pData, format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback, "ID3DDestructionNotifier_RegisterDestructionCallback");
        if(!pCallbackID->IsNull())
        {
            pCallbackID->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterDestructionCallback(reinterpret_cast<PFN_DESTRUCTION_CALLBACK>(callbackFn),
                                                                        in_pData,
                                                                        pCallbackID->GetOutputPointer());
        CheckReplayResult("ID3DDestructionNotifier_RegisterDestructionCallback", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        callbackID)
{
    auto replay_object = MapObject<ID3DDestructionNotifier>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnregisterDestructionCallback(callbackID);
        CheckReplayResult("ID3DDestructionNotifier_UnregisterDestructionCallback", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug_EnableDebugLayer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        OverrideEnableDebugLayer(replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug1_EnableDebugLayer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12Debug1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EnableDebugLayer();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Debug1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetEnableGPUBasedValidation(Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Debug1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetEnableSynchronizedCommandQueueValidation(Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug2_SetGPUBasedValidationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_GPU_BASED_VALIDATION_FLAGS            Flags)
{
    auto replay_object = MapObject<ID3D12Debug2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGPUBasedValidationFlags(Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug3_SetEnableGPUBasedValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Debug3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetEnableGPUBasedValidation(Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Debug3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetEnableSynchronizedCommandQueueValidation(Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug3_SetGPUBasedValidationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_GPU_BASED_VALIDATION_FLAGS            Flags)
{
    auto replay_object = MapObject<ID3D12Debug3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGPUBasedValidationFlags(Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug4_DisableDebugLayer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12Debug4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DisableDebugLayer();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug5_SetEnableAutoName(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Debug5>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetEnableAutoName(Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug6_SetForceLegacyBarrierValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Debug6>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetForceLegacyBarrierValidation(Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice1_SetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE           Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugDevice1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetDebugParameter(Type,
                                                              pData->GetPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugDevice1_SetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice1_GetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE           Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugDevice1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->GetDebugParameter(Type,
                                                              pData->GetOutputPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugDevice1_GetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_RLDO_FLAGS                            Flags)
{
    auto replay_object = MapObject<ID3D12DebugDevice1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReportLiveDeviceObjects(Flags);
        CheckReplayResult("ID3D12DebugDevice1_ReportLiveDeviceObjects", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice_SetFeatureMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_FEATURE                         Mask)
{
    auto replay_object = MapObject<ID3D12DebugDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetFeatureMask(Mask);
        CheckReplayResult("ID3D12DebugDevice_SetFeatureMask", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice_GetFeatureMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DEBUG_FEATURE                         return_value)
{
    auto replay_object = MapObject<ID3D12DebugDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFeatureMask();
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice_ReportLiveDeviceObjects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_RLDO_FLAGS                            Flags)
{
    auto replay_object = MapObject<ID3D12DebugDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReportLiveDeviceObjects(Flags);
        CheckReplayResult("ID3D12DebugDevice_ReportLiveDeviceObjects", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice2_SetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE           Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetDebugParameter(Type,
                                                              pData->GetPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugDevice2_SetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice2_GetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE           Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugDevice2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->GetDebugParameter(Type,
                                                              pData->GetOutputPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugDevice2_GetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandQueue_AssertResourceState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    UINT                                        State)
{
    auto replay_object = MapObject<ID3D12DebugCommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto replay_result = replay_object->AssertResourceState(in_pResource,
                                                                Subresource,
                                                                State);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandQueue1_AssertResourceAccess(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    D3D12_BARRIER_ACCESS                        Access)
{
    auto replay_object = MapObject<ID3D12DebugCommandQueue1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->AssertResourceAccess(in_pResource,
                                            Subresource,
                                            Access);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandQueue1_AssertTextureLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    D3D12_BARRIER_LAYOUT                        Layout)
{
    auto replay_object = MapObject<ID3D12DebugCommandQueue1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->AssertTextureLayout(in_pResource,
                                           Subresource,
                                           Layout);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList1_AssertResourceState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    UINT                                        State)
{
    auto replay_object = MapObject<ID3D12DebugCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto replay_result = replay_object->AssertResourceState(in_pResource,
                                                                Subresource,
                                                                State);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList1_SetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE     Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetDebugParameter(Type,
                                                              pData->GetPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugCommandList1_SetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList1_GetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE     Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->GetDebugParameter(Type,
                                                              pData->GetOutputPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugCommandList1_GetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList_AssertResourceState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    UINT                                        State)
{
    auto replay_object = MapObject<ID3D12DebugCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto replay_result = replay_object->AssertResourceState(in_pResource,
                                                                Subresource,
                                                                State);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList_SetFeatureMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_FEATURE                         Mask)
{
    auto replay_object = MapObject<ID3D12DebugCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetFeatureMask(Mask);
        CheckReplayResult("ID3D12DebugCommandList_SetFeatureMask", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList_GetFeatureMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DEBUG_FEATURE                         return_value)
{
    auto replay_object = MapObject<ID3D12DebugCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFeatureMask();
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList2_SetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE     Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugCommandList2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetDebugParameter(Type,
                                                              pData->GetPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugCommandList2_SetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList2_GetDebugParameter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE     Type,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize)
{
    auto replay_object = MapObject<ID3D12DebugCommandList2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->GetDebugParameter(Type,
                                                              pData->GetOutputPointer(),
                                                              DataSize);
        CheckReplayResult("ID3D12DebugCommandList2_GetDebugParameter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList3_AssertResourceAccess(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    D3D12_BARRIER_ACCESS                        Access)
{
    auto replay_object = MapObject<ID3D12DebugCommandList3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->AssertResourceAccess(in_pResource,
                                            Subresource,
                                            Access);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList3_AssertTextureLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    D3D12_BARRIER_LAYOUT                        Layout)
{
    auto replay_object = MapObject<ID3D12DebugCommandList3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->AssertTextureLayout(in_pResource,
                                           Subresource,
                                           Layout);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SharingContract_Present(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    uint64_t                                    window)
{
    auto replay_object = MapObject<ID3D12SharingContract>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto in_window = static_cast<HWND>(PreProcessExternalObject(window, format::ApiCallId::ApiCall_ID3D12SharingContract_Present, "ID3D12SharingContract_Present"));
        replay_object->Present(in_pResource,
                               Subresource,
                               in_window);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SharingContract_SharedFenceSignal(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pFence,
    UINT64                                      FenceValue)
{
    auto replay_object = MapObject<ID3D12SharingContract>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pFence = MapObject<ID3D12Fence>(pFence);
        replay_object->SharedFenceSignal(in_pFence,
                                         FenceValue);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SharingContract_BeginCapturableWork(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_GUID                                guid)
{
    auto replay_object = MapObject<ID3D12SharingContract>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginCapturableWork(*guid.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SharingContract_EndCapturableWork(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_GUID                                guid)
{
    auto replay_object = MapObject<ID3D12SharingContract>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndCapturableWork(*guid.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetMessageCountLimit(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      MessageCountLimit)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMessageCountLimit(MessageCountLimit);
        CheckReplayResult("ID3D12InfoQueue_SetMessageCountLimit", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearStoredMessages();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetMessage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      MessageIndex,
    StructPointerDecoder<Decoded_D3D12_MESSAGE>* pMessage,
    PointerDecoder<SIZE_T>*                     pMessageByteLength)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        if(!pMessageByteLength->IsNull())
        {
            pMessageByteLength->AllocateOutputData(1, GetOutputArrayCount("ID3D12InfoQueue::GetMessage", return_value, object_id, VariableLengthArrayIndices::kD3D12InfoQueueArrayGetMessage, pMessageByteLength, pMessage));
        }
        if(!pMessage->IsNull() && !pMessageByteLength->IsNull())
        {
            pMessage->AllocateOutputData(*pMessageByteLength->GetOutputPointer());
        }
        auto replay_result = replay_object->GetMessage(MessageIndex,
                                                       pMessage->GetOutputPointer(),
                                                       pMessageByteLength->GetOutputPointer());
        if (pMessage->IsNull() && !pMessageByteLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D12InfoQueueArrayGetMessage, *pMessageByteLength->GetOutputPointer()); }
        CheckReplayResult("ID3D12InfoQueue_GetMessage", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNumMessagesAllowedByStorageFilter();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNumMessagesDeniedByStorageFilter();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNumStoredMessages();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNumStoredMessagesAllowedByRetrievalFilter();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNumMessagesDiscardedByMessageCountLimit();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMessageCountLimit();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_AddStorageFilterEntries(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->AddStorageFilterEntries(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddStorageFilterEntries", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                     pFilterByteLength)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFilterByteLength->IsNull())
        {
            pFilterByteLength->AllocateOutputData(1, GetOutputArrayCount("ID3D12InfoQueue::GetStorageFilter", return_value, object_id, VariableLengthArrayIndices::kD3D12InfoQueueArrayGetStorageFilter, pFilterByteLength, pFilter));
        }
        if(!pFilter->IsNull() && !pFilterByteLength->IsNull())
        {
            pFilter->AllocateOutputData(*pFilterByteLength->GetOutputPointer());
        }
        auto replay_result = replay_object->GetStorageFilter(pFilter->GetOutputPointer(),
                                                             pFilterByteLength->GetOutputPointer());
        if (pFilter->IsNull() && !pFilterByteLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D12InfoQueueArrayGetStorageFilter, *pFilterByteLength->GetOutputPointer()); }
        CheckReplayResult("ID3D12InfoQueue_GetStorageFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearStorageFilter();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->PushEmptyStorageFilter();
        CheckReplayResult("ID3D12InfoQueue_PushEmptyStorageFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->PushCopyOfStorageFilter();
        CheckReplayResult("ID3D12InfoQueue_PushCopyOfStorageFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->PushStorageFilter(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_PushStorageFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PopStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->PopStorageFilter();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetStorageFilterStackSize();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_AddRetrievalFilterEntries(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->AddRetrievalFilterEntries(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddRetrievalFilterEntries", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                     pFilterByteLength)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFilterByteLength->IsNull())
        {
            pFilterByteLength->AllocateOutputData(1, GetOutputArrayCount("ID3D12InfoQueue::GetRetrievalFilter", return_value, object_id, VariableLengthArrayIndices::kD3D12InfoQueueArrayGetRetrievalFilter, pFilterByteLength, pFilter));
        }
        if(!pFilter->IsNull() && !pFilterByteLength->IsNull())
        {
            pFilter->AllocateOutputData(*pFilterByteLength->GetOutputPointer());
        }
        auto replay_result = replay_object->GetRetrievalFilter(pFilter->GetOutputPointer(),
                                                               pFilterByteLength->GetOutputPointer());
        if (pFilter->IsNull() && !pFilterByteLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D12InfoQueueArrayGetRetrievalFilter, *pFilterByteLength->GetOutputPointer()); }
        CheckReplayResult("ID3D12InfoQueue_GetRetrievalFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearRetrievalFilter();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->PushEmptyRetrievalFilter();
        CheckReplayResult("ID3D12InfoQueue_PushEmptyRetrievalFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->PushCopyOfRetrievalFilter();
        CheckReplayResult("ID3D12InfoQueue_PushCopyOfRetrievalFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->PushRetrievalFilter(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_PushRetrievalFilter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PopRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->PopRetrievalFilter();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRetrievalFilterStackSize();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_AddMessage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_CATEGORY                      Category,
    D3D12_MESSAGE_SEVERITY                      Severity,
    D3D12_MESSAGE_ID                            ID,
    StringDecoder*                              pDescription)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->AddMessage(Category,
                                                       Severity,
                                                       ID,
                                                       pDescription->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddMessage", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_AddApplicationMessage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_SEVERITY                      Severity,
    StringDecoder*                              pDescription)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->AddApplicationMessage(Severity,
                                                                  pDescription->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddApplicationMessage", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetBreakOnCategory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_CATEGORY                      Category,
    BOOL                                        bEnable)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetBreakOnCategory(Category,
                                                               bEnable);
        CheckReplayResult("ID3D12InfoQueue_SetBreakOnCategory", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetBreakOnSeverity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_SEVERITY                      Severity,
    BOOL                                        bEnable)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetBreakOnSeverity(Severity,
                                                               bEnable);
        CheckReplayResult("ID3D12InfoQueue_SetBreakOnSeverity", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetBreakOnID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_ID                            ID,
    BOOL                                        bEnable)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetBreakOnID(ID,
                                                         bEnable);
        CheckReplayResult("ID3D12InfoQueue_SetBreakOnID", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetBreakOnCategory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    D3D12_MESSAGE_CATEGORY                      Category)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBreakOnCategory(Category);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetBreakOnSeverity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    D3D12_MESSAGE_SEVERITY                      Severity)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBreakOnSeverity(Severity);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetBreakOnID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    D3D12_MESSAGE_ID                            ID)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBreakOnID(ID);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetMuteDebugOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        bMute)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetMuteDebugOutput(bMute);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetMuteDebugOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<ID3D12InfoQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMuteDebugOutput();
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue1_RegisterMessageCallback(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    CallbackFunc,
    D3D12_MESSAGE_CALLBACK_FLAGS                CallbackFilterFlags,
    uint64_t                                    pContext,
    PointerDecoder<DWORD>*                      pCallbackCookie)
{
    auto replay_object = MapObject<ID3D12InfoQueue1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pContext = PreProcessExternalObject(pContext, format::ApiCallId::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback, "ID3D12InfoQueue1_RegisterMessageCallback");
        if(!pCallbackCookie->IsNull())
        {
            pCallbackCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterMessageCallback(reinterpret_cast<D3D12MessageFunc>(CallbackFunc),
                                                                    CallbackFilterFlags,
                                                                    in_pContext,
                                                                    pCallbackCookie->GetOutputPointer());
        CheckReplayResult("ID3D12InfoQueue1_RegisterMessageCallback", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue1_UnregisterMessageCallback(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DWORD                                       CallbackCookie)
{
    auto replay_object = MapObject<ID3D12InfoQueue1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnregisterMessageCallback(CallbackCookie);
        CheckReplayResult("ID3D12InfoQueue1_UnregisterMessageCallback", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceChild_GetDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11Device*>*        ppDevice)
{
    auto replay_object = MapObject<ID3D11DeviceChild>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
        auto out_p_ppDevice    = ppDevice->GetPointer();
        auto out_hp_ppDevice   = ppDevice->GetHandlePointer();
        replay_object->GetDevice(out_hp_ppDevice);
        AddObject(out_p_ppDevice, out_hp_ppDevice, format::ApiCall_ID3D11DeviceChild_GetDevice);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceChild_GetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    PointerDecoder<UINT>*                       pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11DeviceChild>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDataSize->IsNull())
        {
            pDataSize->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceChild::GetPrivateData", return_value, object_id, VariableLengthArrayIndices::kD3D11DeviceChildArrayGetPrivateData, pDataSize, pData));
        }
        if(!pData->IsNull() && !pDataSize->IsNull())
        {
            pData->AllocateOutputData(*pDataSize->GetOutputPointer());
        }
        auto replay_result = replay_object->GetPrivateData(*guid.decoded_value,
                                                           pDataSize->GetOutputPointer(),
                                                           pData->GetOutputPointer());
        if (pData->IsNull() && !pDataSize->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceChildArrayGetPrivateData, *pDataSize->GetOutputPointer()); }
        CheckReplayResult("ID3D11DeviceChild_GetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceChild_SetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11DeviceChild>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPrivateData(*guid.decoded_value,
                                                           DataSize,
                                                           pData->GetPointer());
        CheckReplayResult("ID3D11DeviceChild_SetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceChild_SetPrivateDataInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    format::HandleId                            pData)
{
    auto replay_object = MapObject<ID3D11DeviceChild>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pData = MapObject<IUnknown>(pData);
        auto replay_result = replay_object->SetPrivateDataInterface(*guid.decoded_value,
                                                                    in_pData);
        CheckReplayResult("ID3D11DeviceChild_SetPrivateDataInterface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DepthStencilState_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_DEPTH_STENCIL_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11DepthStencilState>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11BlendState_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_BLEND_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11BlendState>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11RasterizerState_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_RASTERIZER_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11RasterizerState>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Resource_GetType(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<D3D11_RESOURCE_DIMENSION>*   pResourceDimension)
{
    auto replay_object = MapObject<ID3D11Resource>(object_id);
    if (replay_object != nullptr)
    {
        if(!pResourceDimension->IsNull())
        {
            pResourceDimension->AllocateOutputData(1);
        }
        replay_object->GetType(pResourceDimension->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Resource_SetEvictionPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        EvictionPriority)
{
    auto replay_object = MapObject<ID3D11Resource>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetEvictionPriority(EvictionPriority);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Resource_GetEvictionPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D11Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetEvictionPriority();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Buffer_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_BUFFER_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11Buffer>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Texture1D_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_TEXTURE1D_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11Texture1D>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Texture2D_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11Texture2D>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Texture3D_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11Texture3D>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11View_GetResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11Resource*>*      ppResource)
{
    auto replay_object = MapObject<ID3D11View>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppResource->IsNull()) ppResource->SetHandleLength(1);
        auto out_p_ppResource    = ppResource->GetPointer();
        auto out_hp_ppResource   = ppResource->GetHandlePointer();
        replay_object->GetResource(out_hp_ppResource);
        AddObject(out_p_ppResource, out_hp_ppResource, format::ApiCall_ID3D11View_GetResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D11ShaderResourceView_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11ShaderResourceView>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11RenderTargetView_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_RENDER_TARGET_VIEW_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11RenderTargetView>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DepthStencilView_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_DEPTH_STENCIL_VIEW_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11DepthStencilView>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11UnorderedAccessView_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11UnorderedAccessView>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11SamplerState_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_SAMPLER_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11SamplerState>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Asynchronous_GetDataSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D11Asynchronous>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDataSize();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Query_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_QUERY_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11Query>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Counter_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_COUNTER_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11Counter>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11ClassInstance_GetClassLinkage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11ClassLinkage*>*  ppLinkage)
{
    auto replay_object = MapObject<ID3D11ClassInstance>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppLinkage->IsNull()) ppLinkage->SetHandleLength(1);
        auto out_p_ppLinkage    = ppLinkage->GetPointer();
        auto out_hp_ppLinkage   = ppLinkage->GetHandlePointer();
        replay_object->GetClassLinkage(out_hp_ppLinkage);
        AddObject(out_p_ppLinkage, out_hp_ppLinkage, format::ApiCall_ID3D11ClassInstance_GetClassLinkage);
    }
}

void Dx12ReplayConsumer::Process_ID3D11ClassInstance_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_CLASS_INSTANCE_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11ClassInstance>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11ClassInstance_GetInstanceName(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StringDecoder*                              pInstanceName,
    PointerDecoder<SIZE_T>*                     pBufferLength)
{
    auto replay_object = MapObject<ID3D11ClassInstance>(object_id);
    if (replay_object != nullptr)
    {
        if(!pBufferLength->IsNull())
        {
            pBufferLength->AllocateOutputData(1, GetOutputArrayCount("ID3D11ClassInstance::GetInstanceName", S_OK, object_id, VariableLengthArrayIndices::kD3D11ClassInstanceArrayGetInstanceName, pBufferLength, pInstanceName));
        }
        if(!pInstanceName->IsNull() && !pBufferLength->IsNull())
        {
            pInstanceName->AllocateOutputData(*pBufferLength->GetOutputPointer());
        }
        replay_object->GetInstanceName(pInstanceName->GetOutputPointer(),
                                       pBufferLength->GetOutputPointer());
        if (pInstanceName->IsNull() && !pBufferLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11ClassInstanceArrayGetInstanceName, *pBufferLength->GetOutputPointer()); }
    }
}

void Dx12ReplayConsumer::Process_ID3D11ClassInstance_GetTypeName(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StringDecoder*                              pTypeName,
    PointerDecoder<SIZE_T>*                     pBufferLength)
{
    auto replay_object = MapObject<ID3D11ClassInstance>(object_id);
    if (replay_object != nullptr)
    {
        if(!pBufferLength->IsNull())
        {
            pBufferLength->AllocateOutputData(1, GetOutputArrayCount("ID3D11ClassInstance::GetTypeName", S_OK, object_id, VariableLengthArrayIndices::kD3D11ClassInstanceArrayGetTypeName, pBufferLength, pTypeName));
        }
        if(!pTypeName->IsNull() && !pBufferLength->IsNull())
        {
            pTypeName->AllocateOutputData(*pBufferLength->GetOutputPointer());
        }
        replay_object->GetTypeName(pTypeName->GetOutputPointer(),
                                   pBufferLength->GetOutputPointer());
        if (pTypeName->IsNull() && !pBufferLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11ClassInstanceArrayGetTypeName, *pBufferLength->GetOutputPointer()); }
    }
}

void Dx12ReplayConsumer::Process_ID3D11ClassLinkage_GetClassInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StringDecoder*                              pClassInstanceName,
    UINT                                        InstanceIndex,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppInstance)
{
    auto replay_object = MapObject<ID3D11ClassLinkage>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppInstance->IsNull()) ppInstance->SetHandleLength(1);
        auto out_p_ppInstance    = ppInstance->GetPointer();
        auto out_hp_ppInstance   = ppInstance->GetHandlePointer();
        auto replay_result = replay_object->GetClassInstance(pClassInstanceName->GetPointer(),
                                                             InstanceIndex,
                                                             out_hp_ppInstance);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppInstance, out_hp_ppInstance, format::ApiCall_ID3D11ClassLinkage_GetClassInstance);
        }
        CheckReplayResult("ID3D11ClassLinkage_GetClassInstance", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11ClassLinkage_CreateClassInstance(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StringDecoder*                              pClassTypeName,
    UINT                                        ConstantBufferOffset,
    UINT                                        ConstantVectorOffset,
    UINT                                        TextureOffset,
    UINT                                        SamplerOffset,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppInstance)
{
    auto replay_object = MapObject<ID3D11ClassLinkage>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppInstance->IsNull()) ppInstance->SetHandleLength(1);
        auto out_p_ppInstance    = ppInstance->GetPointer();
        auto out_hp_ppInstance   = ppInstance->GetHandlePointer();
        auto replay_result = replay_object->CreateClassInstance(pClassTypeName->GetPointer(),
                                                                ConstantBufferOffset,
                                                                ConstantVectorOffset,
                                                                TextureOffset,
                                                                SamplerOffset,
                                                                out_hp_ppInstance);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppInstance, out_hp_ppInstance, format::ApiCall_ID3D11ClassLinkage_CreateClassInstance);
        }
        CheckReplayResult("ID3D11ClassLinkage_CreateClassInstance", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11CommandList_GetContextFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D11CommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetContextFlags();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSSetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->VSSetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            in_ppConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSSetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppShaderResourceViews = MapObjects<ID3D11ShaderResourceView>(ppShaderResourceViews, NumViews);
        replay_object->PSSetShaderResources(StartSlot,
                                            NumViews,
                                            in_ppShaderResourceViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSSetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pPixelShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    UINT                                        NumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pPixelShader = MapObject<ID3D11PixelShader>(pPixelShader);
        auto in_ppClassInstances = MapObjects<ID3D11ClassInstance>(ppClassInstances, NumClassInstances);
        replay_object->PSSetShader(in_pPixelShader,
                                   in_ppClassInstances,
                                   NumClassInstances);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSSetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppSamplers = MapObjects<ID3D11SamplerState>(ppSamplers, NumSamplers);
        replay_object->PSSetSamplers(StartSlot,
                                     NumSamplers,
                                     in_ppSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSSetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVertexShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    UINT                                        NumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVertexShader = MapObject<ID3D11VertexShader>(pVertexShader);
        auto in_ppClassInstances = MapObjects<ID3D11ClassInstance>(ppClassInstances, NumClassInstances);
        replay_object->VSSetShader(in_pVertexShader,
                                   in_ppClassInstances,
                                   NumClassInstances);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DrawIndexed(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        IndexCount,
    UINT                                        StartIndexLocation,
    INT                                         BaseVertexLocation)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DrawIndexed(IndexCount,
                                   StartIndexLocation,
                                   BaseVertexLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_Draw(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        VertexCount,
    UINT                                        StartVertexLocation)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Draw(VertexCount,
                            StartVertexLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_Map(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    D3D11_MAP                                   MapType,
    UINT                                        MapFlags,
    StructPointerDecoder<Decoded_D3D11_MAPPED_SUBRESOURCE>* pMappedResource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pResource = GetObjectInfo(pResource);
        if(!pMappedResource->IsNull())
        {
            pMappedResource->AllocateOutputData(1);
        }
        auto replay_result = OverrideDeviceContextMap(replay_object,
                                                      return_value,
                                                      in_pResource,
                                                      Subresource,
                                                      MapType,
                                                      MapFlags,
                                                      pMappedResource);
        CheckReplayResult("ID3D11DeviceContext_Map", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_Unmap(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        Subresource)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pResource = GetObjectInfo(pResource);
        OverrideDeviceContextUnmap(replay_object,
                                   in_pResource,
                                   Subresource);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSSetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->PSSetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            in_ppConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IASetInputLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pInputLayout)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pInputLayout = MapObject<ID3D11InputLayout>(pInputLayout);
        replay_object->IASetInputLayout(in_pInputLayout);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IASetVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppVertexBuffers,
    PointerDecoder<UINT>*                       pStrides,
    PointerDecoder<UINT>*                       pOffsets)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppVertexBuffers = MapObjects<ID3D11Buffer>(ppVertexBuffers, NumBuffers);
        replay_object->IASetVertexBuffers(StartSlot,
                                          NumBuffers,
                                          in_ppVertexBuffers,
                                          pStrides->GetPointer(),
                                          pOffsets->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IASetIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pIndexBuffer,
    DXGI_FORMAT                                 Format,
    UINT                                        Offset)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pIndexBuffer = MapObject<ID3D11Buffer>(pIndexBuffer);
        replay_object->IASetIndexBuffer(in_pIndexBuffer,
                                        Format,
                                        Offset);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DrawIndexedInstanced(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        IndexCountPerInstance,
    UINT                                        InstanceCount,
    UINT                                        StartIndexLocation,
    INT                                         BaseVertexLocation,
    UINT                                        StartInstanceLocation)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DrawIndexedInstanced(IndexCountPerInstance,
                                            InstanceCount,
                                            StartIndexLocation,
                                            BaseVertexLocation,
                                            StartInstanceLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DrawInstanced(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        VertexCountPerInstance,
    UINT                                        InstanceCount,
    UINT                                        StartVertexLocation,
    UINT                                        StartInstanceLocation)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DrawInstanced(VertexCountPerInstance,
                                     InstanceCount,
                                     StartVertexLocation,
                                     StartInstanceLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSSetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->GSSetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            in_ppConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSSetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    UINT                                        NumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pShader = MapObject<ID3D11GeometryShader>(pShader);
        auto in_ppClassInstances = MapObjects<ID3D11ClassInstance>(ppClassInstances, NumClassInstances);
        replay_object->GSSetShader(in_pShader,
                                   in_ppClassInstances,
                                   NumClassInstances);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IASetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D_PRIMITIVE_TOPOLOGY                      Topology)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->IASetPrimitiveTopology(Topology);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSSetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppShaderResourceViews = MapObjects<ID3D11ShaderResourceView>(ppShaderResourceViews, NumViews);
        replay_object->VSSetShaderResources(StartSlot,
                                            NumViews,
                                            in_ppShaderResourceViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSSetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppSamplers = MapObjects<ID3D11SamplerState>(ppSamplers, NumSamplers);
        replay_object->VSSetSamplers(StartSlot,
                                     NumSamplers,
                                     in_ppSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_Begin(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pAsync)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pAsync = MapObject<ID3D11Asynchronous>(pAsync);
        replay_object->Begin(in_pAsync);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_End(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pAsync)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pAsync = MapObject<ID3D11Asynchronous>(pAsync);
        replay_object->End(in_pAsync);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GetData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pAsync,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        DataSize,
    UINT                                        GetDataFlags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pAsync = GetObjectInfo(pAsync);
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = OverrideDeviceContextGetData(replay_object,
                                                          return_value,
                                                          in_pAsync,
                                                          pData,
                                                          DataSize,
                                                          GetDataFlags);
        CheckReplayResult("ID3D11DeviceContext_GetData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_SetPredication(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pPredicate,
    BOOL                                        PredicateValue)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pPredicate = MapObject<ID3D11Predicate>(pPredicate);
        replay_object->SetPredication(in_pPredicate,
                                      PredicateValue);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSSetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppShaderResourceViews = MapObjects<ID3D11ShaderResourceView>(ppShaderResourceViews, NumViews);
        replay_object->GSSetShaderResources(StartSlot,
                                            NumViews,
                                            in_ppShaderResourceViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSSetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppSamplers = MapObjects<ID3D11SamplerState>(ppSamplers, NumSamplers);
        replay_object->GSSetSamplers(StartSlot,
                                     NumSamplers,
                                     in_ppSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMSetRenderTargets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11RenderTargetView*>* ppRenderTargetViews,
    format::HandleId                            pDepthStencilView)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppRenderTargetViews = MapObjects<ID3D11RenderTargetView>(ppRenderTargetViews, NumViews);
        auto in_pDepthStencilView = MapObject<ID3D11DepthStencilView>(pDepthStencilView);
        replay_object->OMSetRenderTargets(NumViews,
                                          in_ppRenderTargetViews,
                                          in_pDepthStencilView);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMSetRenderTargetsAndUnorderedAccessViews(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumRTVs,
    HandlePointerDecoder<ID3D11RenderTargetView*>* ppRenderTargetViews,
    format::HandleId                            pDepthStencilView,
    UINT                                        UAVStartSlot,
    UINT                                        NumUAVs,
    HandlePointerDecoder<ID3D11UnorderedAccessView*>* ppUnorderedAccessViews,
    PointerDecoder<UINT>*                       pUAVInitialCounts)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppRenderTargetViews = MapObjects<ID3D11RenderTargetView>(ppRenderTargetViews, NumRTVs);
        auto in_pDepthStencilView = MapObject<ID3D11DepthStencilView>(pDepthStencilView);
        auto in_ppUnorderedAccessViews = MapObjects<ID3D11UnorderedAccessView>(ppUnorderedAccessViews, NumUAVs);
        replay_object->OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs,
                                                                 in_ppRenderTargetViews,
                                                                 in_pDepthStencilView,
                                                                 UAVStartSlot,
                                                                 NumUAVs,
                                                                 in_ppUnorderedAccessViews,
                                                                 pUAVInitialCounts->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMSetBlendState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pBlendState,
    PointerDecoder<FLOAT>*                      BlendFactor,
    UINT                                        SampleMask)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pBlendState = MapObject<ID3D11BlendState>(pBlendState);
        replay_object->OMSetBlendState(in_pBlendState,
                                       BlendFactor->GetPointer(),
                                       SampleMask);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMSetDepthStencilState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDepthStencilState,
    UINT                                        StencilRef)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDepthStencilState = MapObject<ID3D11DepthStencilState>(pDepthStencilState);
        replay_object->OMSetDepthStencilState(in_pDepthStencilState,
                                              StencilRef);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_SOSetTargets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppSOTargets,
    PointerDecoder<UINT>*                       pOffsets)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppSOTargets = MapObjects<ID3D11Buffer>(ppSOTargets, NumBuffers);
        replay_object->SOSetTargets(NumBuffers,
                                    in_ppSOTargets,
                                    pOffsets->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DrawAuto(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DrawAuto();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DrawIndexedInstancedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pBufferForArgs,
    UINT                                        AlignedByteOffsetForArgs)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pBufferForArgs = MapObject<ID3D11Buffer>(pBufferForArgs);
        replay_object->DrawIndexedInstancedIndirect(in_pBufferForArgs,
                                                    AlignedByteOffsetForArgs);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DrawInstancedIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pBufferForArgs,
    UINT                                        AlignedByteOffsetForArgs)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pBufferForArgs = MapObject<ID3D11Buffer>(pBufferForArgs);
        replay_object->DrawInstancedIndirect(in_pBufferForArgs,
                                             AlignedByteOffsetForArgs);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_Dispatch(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        ThreadGroupCountX,
    UINT                                        ThreadGroupCountY,
    UINT                                        ThreadGroupCountZ)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Dispatch(ThreadGroupCountX,
                                ThreadGroupCountY,
                                ThreadGroupCountZ);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DispatchIndirect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pBufferForArgs,
    UINT                                        AlignedByteOffsetForArgs)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pBufferForArgs = MapObject<ID3D11Buffer>(pBufferForArgs);
        replay_object->DispatchIndirect(in_pBufferForArgs,
                                        AlignedByteOffsetForArgs);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_RSSetState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pRasterizerState)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pRasterizerState = MapObject<ID3D11RasterizerState>(pRasterizerState);
        replay_object->RSSetState(in_pRasterizerState);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_RSSetViewports(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumViewports,
    StructPointerDecoder<Decoded_D3D11_VIEWPORT>* pViewports)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RSSetViewports(NumViewports,
                                      pViewports->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_RSSetScissorRects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RSSetScissorRects(NumRects,
                                         pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CopySubresourceRegion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    UINT                                        DstSubresource,
    UINT                                        DstX,
    UINT                                        DstY,
    UINT                                        DstZ,
    format::HandleId                            pSrcResource,
    UINT                                        SrcSubresource,
    StructPointerDecoder<Decoded_D3D11_BOX>*    pSrcBox)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D11Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D11Resource>(pSrcResource);
        replay_object->CopySubresourceRegion(in_pDstResource,
                                             DstSubresource,
                                             DstX,
                                             DstY,
                                             DstZ,
                                             in_pSrcResource,
                                             SrcSubresource,
                                             pSrcBox->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CopyResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    format::HandleId                            pSrcResource)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D11Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D11Resource>(pSrcResource);
        replay_object->CopyResource(in_pDstResource,
                                    in_pSrcResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CopyStructureCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstBuffer,
    UINT                                        DstAlignedByteOffset,
    format::HandleId                            pSrcView)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstBuffer = MapObject<ID3D11Buffer>(pDstBuffer);
        auto in_pSrcView = MapObject<ID3D11UnorderedAccessView>(pSrcView);
        replay_object->CopyStructureCount(in_pDstBuffer,
                                          DstAlignedByteOffset,
                                          in_pSrcView);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_ClearRenderTargetView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pRenderTargetView,
    PointerDecoder<FLOAT>*                      ColorRGBA)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pRenderTargetView = MapObject<ID3D11RenderTargetView>(pRenderTargetView);
        replay_object->ClearRenderTargetView(in_pRenderTargetView,
                                             ColorRGBA->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_ClearUnorderedAccessViewUint(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pUnorderedAccessView,
    PointerDecoder<UINT>*                       Values)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pUnorderedAccessView = MapObject<ID3D11UnorderedAccessView>(pUnorderedAccessView);
        replay_object->ClearUnorderedAccessViewUint(in_pUnorderedAccessView,
                                                    Values->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_ClearUnorderedAccessViewFloat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pUnorderedAccessView,
    PointerDecoder<FLOAT>*                      Values)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pUnorderedAccessView = MapObject<ID3D11UnorderedAccessView>(pUnorderedAccessView);
        replay_object->ClearUnorderedAccessViewFloat(in_pUnorderedAccessView,
                                                     Values->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_ClearDepthStencilView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDepthStencilView,
    UINT                                        ClearFlags,
    FLOAT                                       Depth,
    UINT8                                       Stencil)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDepthStencilView = MapObject<ID3D11DepthStencilView>(pDepthStencilView);
        replay_object->ClearDepthStencilView(in_pDepthStencilView,
                                             ClearFlags,
                                             Depth,
                                             Stencil);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GenerateMips(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pShaderResourceView)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pShaderResourceView = MapObject<ID3D11ShaderResourceView>(pShaderResourceView);
        replay_object->GenerateMips(in_pShaderResourceView);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_SetResourceMinLOD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    FLOAT                                       MinLOD)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        replay_object->SetResourceMinLOD(in_pResource,
                                         MinLOD);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GetResourceMinLOD(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    FLOAT                                       return_value,
    format::HandleId                            pResource)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        auto replay_result = replay_object->GetResourceMinLOD(in_pResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_ResolveSubresource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    UINT                                        DstSubresource,
    format::HandleId                            pSrcResource,
    UINT                                        SrcSubresource,
    DXGI_FORMAT                                 Format)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D11Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D11Resource>(pSrcResource);
        replay_object->ResolveSubresource(in_pDstResource,
                                          DstSubresource,
                                          in_pSrcResource,
                                          SrcSubresource,
                                          Format);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_ExecuteCommandList(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCommandList,
    BOOL                                        RestoreContextState)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCommandList = MapObject<ID3D11CommandList>(pCommandList);
        replay_object->ExecuteCommandList(in_pCommandList,
                                          RestoreContextState);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSSetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppShaderResourceViews = MapObjects<ID3D11ShaderResourceView>(ppShaderResourceViews, NumViews);
        replay_object->HSSetShaderResources(StartSlot,
                                            NumViews,
                                            in_ppShaderResourceViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSSetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pHullShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    UINT                                        NumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pHullShader = MapObject<ID3D11HullShader>(pHullShader);
        auto in_ppClassInstances = MapObjects<ID3D11ClassInstance>(ppClassInstances, NumClassInstances);
        replay_object->HSSetShader(in_pHullShader,
                                   in_ppClassInstances,
                                   NumClassInstances);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSSetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppSamplers = MapObjects<ID3D11SamplerState>(ppSamplers, NumSamplers);
        replay_object->HSSetSamplers(StartSlot,
                                     NumSamplers,
                                     in_ppSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSSetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->HSSetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            in_ppConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSSetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppShaderResourceViews = MapObjects<ID3D11ShaderResourceView>(ppShaderResourceViews, NumViews);
        replay_object->DSSetShaderResources(StartSlot,
                                            NumViews,
                                            in_ppShaderResourceViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSSetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDomainShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    UINT                                        NumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDomainShader = MapObject<ID3D11DomainShader>(pDomainShader);
        auto in_ppClassInstances = MapObjects<ID3D11ClassInstance>(ppClassInstances, NumClassInstances);
        replay_object->DSSetShader(in_pDomainShader,
                                   in_ppClassInstances,
                                   NumClassInstances);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSSetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppSamplers = MapObjects<ID3D11SamplerState>(ppSamplers, NumSamplers);
        replay_object->DSSetSamplers(StartSlot,
                                     NumSamplers,
                                     in_ppSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSSetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->DSSetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            in_ppConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSSetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppShaderResourceViews = MapObjects<ID3D11ShaderResourceView>(ppShaderResourceViews, NumViews);
        replay_object->CSSetShaderResources(StartSlot,
                                            NumViews,
                                            in_ppShaderResourceViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSSetUnorderedAccessViews(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumUAVs,
    HandlePointerDecoder<ID3D11UnorderedAccessView*>* ppUnorderedAccessViews,
    PointerDecoder<UINT>*                       pUAVInitialCounts)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppUnorderedAccessViews = MapObjects<ID3D11UnorderedAccessView>(ppUnorderedAccessViews, NumUAVs);
        replay_object->CSSetUnorderedAccessViews(StartSlot,
                                                 NumUAVs,
                                                 in_ppUnorderedAccessViews,
                                                 pUAVInitialCounts->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSSetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pComputeShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    UINT                                        NumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pComputeShader = MapObject<ID3D11ComputeShader>(pComputeShader);
        auto in_ppClassInstances = MapObjects<ID3D11ClassInstance>(ppClassInstances, NumClassInstances);
        replay_object->CSSetShader(in_pComputeShader,
                                   in_ppClassInstances,
                                   NumClassInstances);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSSetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppSamplers = MapObjects<ID3D11SamplerState>(ppSamplers, NumSamplers);
        replay_object->CSSetSamplers(StartSlot,
                                     NumSamplers,
                                     in_ppSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSSetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->CSSetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            in_ppConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSGetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        replay_object->VSGetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            out_hp_ppConstantBuffers);
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext_VSGetConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSGetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppShaderResourceViews->IsNull()) ppShaderResourceViews->SetHandleLength(NumViews);
        auto out_p_ppShaderResourceViews    = ppShaderResourceViews->GetPointer();
        auto out_hp_ppShaderResourceViews   = ppShaderResourceViews->GetHandlePointer();
        replay_object->PSGetShaderResources(StartSlot,
                                            NumViews,
                                            out_hp_ppShaderResourceViews);
        AddObjects(out_p_ppShaderResourceViews, ppShaderResourceViews->GetLength(), out_hp_ppShaderResourceViews, NumViews, format::ApiCall_ID3D11DeviceContext_PSGetShaderResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSGetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11PixelShader*>*   ppPixelShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    PointerDecoder<UINT>*                       pNumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPixelShader->IsNull()) ppPixelShader->SetHandleLength(1);
        auto out_p_ppPixelShader    = ppPixelShader->GetPointer();
        auto out_hp_ppPixelShader   = ppPixelShader->GetHandlePointer();
        if(!pNumClassInstances->IsNull())
        {
            pNumClassInstances->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::PSGetShader", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayPSGetShader, pNumClassInstances, ppClassInstances));
        }
        if(!ppClassInstances->IsNull() && !pNumClassInstances->IsNull())
        {
            ppClassInstances->SetHandleLength(*pNumClassInstances->GetOutputPointer());
        }
        auto out_p_ppClassInstances    = ppClassInstances->GetPointer();
        auto out_hp_ppClassInstances   = ppClassInstances->GetHandlePointer();
        replay_object->PSGetShader(out_hp_ppPixelShader,
                                   out_hp_ppClassInstances,
                                   pNumClassInstances->GetOutputPointer());
        if (ppClassInstances->IsNull() && !pNumClassInstances->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayPSGetShader, *pNumClassInstances->GetOutputPointer()); }
        AddObject(out_p_ppPixelShader, out_hp_ppPixelShader, format::ApiCall_ID3D11DeviceContext_PSGetShader);
        AddObjects(out_p_ppClassInstances, ppClassInstances->GetLength(), out_hp_ppClassInstances, !pNumClassInstances->IsNull() ? *pNumClassInstances->GetOutputPointer() : 0, format::ApiCall_ID3D11DeviceContext_PSGetShader);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSGetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSamplers->IsNull()) ppSamplers->SetHandleLength(NumSamplers);
        auto out_p_ppSamplers    = ppSamplers->GetPointer();
        auto out_hp_ppSamplers   = ppSamplers->GetHandlePointer();
        replay_object->PSGetSamplers(StartSlot,
                                     NumSamplers,
                                     out_hp_ppSamplers);
        AddObjects(out_p_ppSamplers, ppSamplers->GetLength(), out_hp_ppSamplers, NumSamplers, format::ApiCall_ID3D11DeviceContext_PSGetSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSGetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11VertexShader*>*  ppVertexShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    PointerDecoder<UINT>*                       pNumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppVertexShader->IsNull()) ppVertexShader->SetHandleLength(1);
        auto out_p_ppVertexShader    = ppVertexShader->GetPointer();
        auto out_hp_ppVertexShader   = ppVertexShader->GetHandlePointer();
        if(!pNumClassInstances->IsNull())
        {
            pNumClassInstances->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::VSGetShader", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayVSGetShader, pNumClassInstances, ppClassInstances));
        }
        if(!ppClassInstances->IsNull() && !pNumClassInstances->IsNull())
        {
            ppClassInstances->SetHandleLength(*pNumClassInstances->GetOutputPointer());
        }
        auto out_p_ppClassInstances    = ppClassInstances->GetPointer();
        auto out_hp_ppClassInstances   = ppClassInstances->GetHandlePointer();
        replay_object->VSGetShader(out_hp_ppVertexShader,
                                   out_hp_ppClassInstances,
                                   pNumClassInstances->GetOutputPointer());
        if (ppClassInstances->IsNull() && !pNumClassInstances->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayVSGetShader, *pNumClassInstances->GetOutputPointer()); }
        AddObject(out_p_ppVertexShader, out_hp_ppVertexShader, format::ApiCall_ID3D11DeviceContext_VSGetShader);
        AddObjects(out_p_ppClassInstances, ppClassInstances->GetLength(), out_hp_ppClassInstances, !pNumClassInstances->IsNull() ? *pNumClassInstances->GetOutputPointer() : 0, format::ApiCall_ID3D11DeviceContext_VSGetShader);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_PSGetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        replay_object->PSGetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            out_hp_ppConstantBuffers);
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext_PSGetConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IAGetInputLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11InputLayout*>*   ppInputLayout)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppInputLayout->IsNull()) ppInputLayout->SetHandleLength(1);
        auto out_p_ppInputLayout    = ppInputLayout->GetPointer();
        auto out_hp_ppInputLayout   = ppInputLayout->GetHandlePointer();
        replay_object->IAGetInputLayout(out_hp_ppInputLayout);
        AddObject(out_p_ppInputLayout, out_hp_ppInputLayout, format::ApiCall_ID3D11DeviceContext_IAGetInputLayout);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IAGetVertexBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppVertexBuffers,
    PointerDecoder<UINT>*                       pStrides,
    PointerDecoder<UINT>*                       pOffsets)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppVertexBuffers->IsNull()) ppVertexBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppVertexBuffers    = ppVertexBuffers->GetPointer();
        auto out_hp_ppVertexBuffers   = ppVertexBuffers->GetHandlePointer();
        if(!pStrides->IsNull())
        {
            pStrides->AllocateOutputData(NumBuffers);
        }
        if(!pOffsets->IsNull())
        {
            pOffsets->AllocateOutputData(NumBuffers);
        }
        replay_object->IAGetVertexBuffers(StartSlot,
                                          NumBuffers,
                                          out_hp_ppVertexBuffers,
                                          pStrides->GetOutputPointer(),
                                          pOffsets->GetOutputPointer());
        AddObjects(out_p_ppVertexBuffers, ppVertexBuffers->GetLength(), out_hp_ppVertexBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext_IAGetVertexBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IAGetIndexBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11Buffer*>*        pIndexBuffer,
    PointerDecoder<DXGI_FORMAT>*                Format,
    PointerDecoder<UINT>*                       Offset)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!pIndexBuffer->IsNull()) pIndexBuffer->SetHandleLength(1);
        auto out_p_pIndexBuffer    = pIndexBuffer->GetPointer();
        auto out_hp_pIndexBuffer   = pIndexBuffer->GetHandlePointer();
        if(!Format->IsNull())
        {
            Format->AllocateOutputData(1);
        }
        if(!Offset->IsNull())
        {
            Offset->AllocateOutputData(1);
        }
        replay_object->IAGetIndexBuffer(out_hp_pIndexBuffer,
                                        Format->GetOutputPointer(),
                                        Offset->GetOutputPointer());
        AddObject(out_p_pIndexBuffer, out_hp_pIndexBuffer, format::ApiCall_ID3D11DeviceContext_IAGetIndexBuffer);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSGetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        replay_object->GSGetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            out_hp_ppConstantBuffers);
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext_GSGetConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSGetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11GeometryShader*>* ppGeometryShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    PointerDecoder<UINT>*                       pNumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppGeometryShader->IsNull()) ppGeometryShader->SetHandleLength(1);
        auto out_p_ppGeometryShader    = ppGeometryShader->GetPointer();
        auto out_hp_ppGeometryShader   = ppGeometryShader->GetHandlePointer();
        if(!pNumClassInstances->IsNull())
        {
            pNumClassInstances->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::GSGetShader", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayGSGetShader, pNumClassInstances, ppClassInstances));
        }
        if(!ppClassInstances->IsNull() && !pNumClassInstances->IsNull())
        {
            ppClassInstances->SetHandleLength(*pNumClassInstances->GetOutputPointer());
        }
        auto out_p_ppClassInstances    = ppClassInstances->GetPointer();
        auto out_hp_ppClassInstances   = ppClassInstances->GetHandlePointer();
        replay_object->GSGetShader(out_hp_ppGeometryShader,
                                   out_hp_ppClassInstances,
                                   pNumClassInstances->GetOutputPointer());
        if (ppClassInstances->IsNull() && !pNumClassInstances->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayGSGetShader, *pNumClassInstances->GetOutputPointer()); }
        AddObject(out_p_ppGeometryShader, out_hp_ppGeometryShader, format::ApiCall_ID3D11DeviceContext_GSGetShader);
        AddObjects(out_p_ppClassInstances, ppClassInstances->GetLength(), out_hp_ppClassInstances, !pNumClassInstances->IsNull() ? *pNumClassInstances->GetOutputPointer() : 0, format::ApiCall_ID3D11DeviceContext_GSGetShader);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_IAGetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<D3D_PRIMITIVE_TOPOLOGY>*     pTopology)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!pTopology->IsNull())
        {
            pTopology->AllocateOutputData(1);
        }
        replay_object->IAGetPrimitiveTopology(pTopology->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSGetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppShaderResourceViews->IsNull()) ppShaderResourceViews->SetHandleLength(NumViews);
        auto out_p_ppShaderResourceViews    = ppShaderResourceViews->GetPointer();
        auto out_hp_ppShaderResourceViews   = ppShaderResourceViews->GetHandlePointer();
        replay_object->VSGetShaderResources(StartSlot,
                                            NumViews,
                                            out_hp_ppShaderResourceViews);
        AddObjects(out_p_ppShaderResourceViews, ppShaderResourceViews->GetLength(), out_hp_ppShaderResourceViews, NumViews, format::ApiCall_ID3D11DeviceContext_VSGetShaderResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_VSGetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSamplers->IsNull()) ppSamplers->SetHandleLength(NumSamplers);
        auto out_p_ppSamplers    = ppSamplers->GetPointer();
        auto out_hp_ppSamplers   = ppSamplers->GetHandlePointer();
        replay_object->VSGetSamplers(StartSlot,
                                     NumSamplers,
                                     out_hp_ppSamplers);
        AddObjects(out_p_ppSamplers, ppSamplers->GetLength(), out_hp_ppSamplers, NumSamplers, format::ApiCall_ID3D11DeviceContext_VSGetSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GetPredication(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11Predicate*>*     ppPredicate,
    PointerDecoder<BOOL>*                       pPredicateValue)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPredicate->IsNull()) ppPredicate->SetHandleLength(1);
        auto out_p_ppPredicate    = ppPredicate->GetPointer();
        auto out_hp_ppPredicate   = ppPredicate->GetHandlePointer();
        if(!pPredicateValue->IsNull())
        {
            pPredicateValue->AllocateOutputData(1);
        }
        replay_object->GetPredication(out_hp_ppPredicate,
                                      pPredicateValue->GetOutputPointer());
        AddObject(out_p_ppPredicate, out_hp_ppPredicate, format::ApiCall_ID3D11DeviceContext_GetPredication);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSGetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppShaderResourceViews->IsNull()) ppShaderResourceViews->SetHandleLength(NumViews);
        auto out_p_ppShaderResourceViews    = ppShaderResourceViews->GetPointer();
        auto out_hp_ppShaderResourceViews   = ppShaderResourceViews->GetHandlePointer();
        replay_object->GSGetShaderResources(StartSlot,
                                            NumViews,
                                            out_hp_ppShaderResourceViews);
        AddObjects(out_p_ppShaderResourceViews, ppShaderResourceViews->GetLength(), out_hp_ppShaderResourceViews, NumViews, format::ApiCall_ID3D11DeviceContext_GSGetShaderResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GSGetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSamplers->IsNull()) ppSamplers->SetHandleLength(NumSamplers);
        auto out_p_ppSamplers    = ppSamplers->GetPointer();
        auto out_hp_ppSamplers   = ppSamplers->GetHandlePointer();
        replay_object->GSGetSamplers(StartSlot,
                                     NumSamplers,
                                     out_hp_ppSamplers);
        AddObjects(out_p_ppSamplers, ppSamplers->GetLength(), out_hp_ppSamplers, NumSamplers, format::ApiCall_ID3D11DeviceContext_GSGetSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMGetRenderTargets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11RenderTargetView*>* ppRenderTargetViews,
    HandlePointerDecoder<ID3D11DepthStencilView*>* ppDepthStencilView)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRenderTargetViews->IsNull()) ppRenderTargetViews->SetHandleLength(NumViews);
        auto out_p_ppRenderTargetViews    = ppRenderTargetViews->GetPointer();
        auto out_hp_ppRenderTargetViews   = ppRenderTargetViews->GetHandlePointer();
        if(!ppDepthStencilView->IsNull()) ppDepthStencilView->SetHandleLength(1);
        auto out_p_ppDepthStencilView    = ppDepthStencilView->GetPointer();
        auto out_hp_ppDepthStencilView   = ppDepthStencilView->GetHandlePointer();
        replay_object->OMGetRenderTargets(NumViews,
                                          out_hp_ppRenderTargetViews,
                                          out_hp_ppDepthStencilView);
        AddObjects(out_p_ppRenderTargetViews, ppRenderTargetViews->GetLength(), out_hp_ppRenderTargetViews, NumViews, format::ApiCall_ID3D11DeviceContext_OMGetRenderTargets);
        AddObject(out_p_ppDepthStencilView, out_hp_ppDepthStencilView, format::ApiCall_ID3D11DeviceContext_OMGetRenderTargets);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMGetRenderTargetsAndUnorderedAccessViews(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumRTVs,
    HandlePointerDecoder<ID3D11RenderTargetView*>* ppRenderTargetViews,
    HandlePointerDecoder<ID3D11DepthStencilView*>* ppDepthStencilView,
    UINT                                        UAVStartSlot,
    UINT                                        NumUAVs,
    HandlePointerDecoder<ID3D11UnorderedAccessView*>* ppUnorderedAccessViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRenderTargetViews->IsNull()) ppRenderTargetViews->SetHandleLength(NumRTVs);
        auto out_p_ppRenderTargetViews    = ppRenderTargetViews->GetPointer();
        auto out_hp_ppRenderTargetViews   = ppRenderTargetViews->GetHandlePointer();
        if(!ppDepthStencilView->IsNull()) ppDepthStencilView->SetHandleLength(1);
        auto out_p_ppDepthStencilView    = ppDepthStencilView->GetPointer();
        auto out_hp_ppDepthStencilView   = ppDepthStencilView->GetHandlePointer();
        if(!ppUnorderedAccessViews->IsNull()) ppUnorderedAccessViews->SetHandleLength(NumUAVs);
        auto out_p_ppUnorderedAccessViews    = ppUnorderedAccessViews->GetPointer();
        auto out_hp_ppUnorderedAccessViews   = ppUnorderedAccessViews->GetHandlePointer();
        replay_object->OMGetRenderTargetsAndUnorderedAccessViews(NumRTVs,
                                                                 out_hp_ppRenderTargetViews,
                                                                 out_hp_ppDepthStencilView,
                                                                 UAVStartSlot,
                                                                 NumUAVs,
                                                                 out_hp_ppUnorderedAccessViews);
        AddObjects(out_p_ppRenderTargetViews, ppRenderTargetViews->GetLength(), out_hp_ppRenderTargetViews, NumRTVs, format::ApiCall_ID3D11DeviceContext_OMGetRenderTargetsAndUnorderedAccessViews);
        AddObject(out_p_ppDepthStencilView, out_hp_ppDepthStencilView, format::ApiCall_ID3D11DeviceContext_OMGetRenderTargetsAndUnorderedAccessViews);
        AddObjects(out_p_ppUnorderedAccessViews, ppUnorderedAccessViews->GetLength(), out_hp_ppUnorderedAccessViews, NumUAVs, format::ApiCall_ID3D11DeviceContext_OMGetRenderTargetsAndUnorderedAccessViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMGetBlendState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11BlendState*>*    ppBlendState,
    PointerDecoder<FLOAT>*                      BlendFactor,
    PointerDecoder<UINT>*                       pSampleMask)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppBlendState->IsNull()) ppBlendState->SetHandleLength(1);
        auto out_p_ppBlendState    = ppBlendState->GetPointer();
        auto out_hp_ppBlendState   = ppBlendState->GetHandlePointer();
        if(!BlendFactor->IsNull())
        {
            BlendFactor->AllocateOutputData(4);
        }
        if(!pSampleMask->IsNull())
        {
            pSampleMask->AllocateOutputData(1);
        }
        replay_object->OMGetBlendState(out_hp_ppBlendState,
                                       BlendFactor->GetOutputPointer(),
                                       pSampleMask->GetOutputPointer());
        AddObject(out_p_ppBlendState, out_hp_ppBlendState, format::ApiCall_ID3D11DeviceContext_OMGetBlendState);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_OMGetDepthStencilState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11DepthStencilState*>* ppDepthStencilState,
    PointerDecoder<UINT>*                       pStencilRef)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDepthStencilState->IsNull()) ppDepthStencilState->SetHandleLength(1);
        auto out_p_ppDepthStencilState    = ppDepthStencilState->GetPointer();
        auto out_hp_ppDepthStencilState   = ppDepthStencilState->GetHandlePointer();
        if(!pStencilRef->IsNull())
        {
            pStencilRef->AllocateOutputData(1);
        }
        replay_object->OMGetDepthStencilState(out_hp_ppDepthStencilState,
                                              pStencilRef->GetOutputPointer());
        AddObject(out_p_ppDepthStencilState, out_hp_ppDepthStencilState, format::ApiCall_ID3D11DeviceContext_OMGetDepthStencilState);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_SOGetTargets(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppSOTargets)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSOTargets->IsNull()) ppSOTargets->SetHandleLength(NumBuffers);
        auto out_p_ppSOTargets    = ppSOTargets->GetPointer();
        auto out_hp_ppSOTargets   = ppSOTargets->GetHandlePointer();
        replay_object->SOGetTargets(NumBuffers,
                                    out_hp_ppSOTargets);
        AddObjects(out_p_ppSOTargets, ppSOTargets->GetLength(), out_hp_ppSOTargets, NumBuffers, format::ApiCall_ID3D11DeviceContext_SOGetTargets);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_RSGetState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11RasterizerState*>* ppRasterizerState)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRasterizerState->IsNull()) ppRasterizerState->SetHandleLength(1);
        auto out_p_ppRasterizerState    = ppRasterizerState->GetPointer();
        auto out_hp_ppRasterizerState   = ppRasterizerState->GetHandlePointer();
        replay_object->RSGetState(out_hp_ppRasterizerState);
        AddObject(out_p_ppRasterizerState, out_hp_ppRasterizerState, format::ApiCall_ID3D11DeviceContext_RSGetState);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_RSGetViewports(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<UINT>*                       pNumViewports,
    StructPointerDecoder<Decoded_D3D11_VIEWPORT>* pViewports)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNumViewports->IsNull())
        {
            pNumViewports->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::RSGetViewports", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayRSGetViewports, pNumViewports, pViewports));
        }
        if(!pViewports->IsNull() && !pNumViewports->IsNull())
        {
            pViewports->AllocateOutputData(*pNumViewports->GetOutputPointer());
        }
        replay_object->RSGetViewports(pNumViewports->GetOutputPointer(),
                                      pViewports->GetOutputPointer());
        if (pViewports->IsNull() && !pNumViewports->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayRSGetViewports, *pNumViewports->GetOutputPointer()); }
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_RSGetScissorRects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<UINT>*                       pNumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNumRects->IsNull())
        {
            pNumRects->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::RSGetScissorRects", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayRSGetScissorRects, pNumRects, pRects));
        }
        if(!pRects->IsNull() && !pNumRects->IsNull())
        {
            pRects->AllocateOutputData(*pNumRects->GetOutputPointer());
        }
        replay_object->RSGetScissorRects(pNumRects->GetOutputPointer(),
                                         pRects->GetOutputPointer());
        if (pRects->IsNull() && !pNumRects->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayRSGetScissorRects, *pNumRects->GetOutputPointer()); }
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSGetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppShaderResourceViews->IsNull()) ppShaderResourceViews->SetHandleLength(NumViews);
        auto out_p_ppShaderResourceViews    = ppShaderResourceViews->GetPointer();
        auto out_hp_ppShaderResourceViews   = ppShaderResourceViews->GetHandlePointer();
        replay_object->HSGetShaderResources(StartSlot,
                                            NumViews,
                                            out_hp_ppShaderResourceViews);
        AddObjects(out_p_ppShaderResourceViews, ppShaderResourceViews->GetLength(), out_hp_ppShaderResourceViews, NumViews, format::ApiCall_ID3D11DeviceContext_HSGetShaderResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSGetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11HullShader*>*    ppHullShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    PointerDecoder<UINT>*                       pNumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppHullShader->IsNull()) ppHullShader->SetHandleLength(1);
        auto out_p_ppHullShader    = ppHullShader->GetPointer();
        auto out_hp_ppHullShader   = ppHullShader->GetHandlePointer();
        if(!pNumClassInstances->IsNull())
        {
            pNumClassInstances->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::HSGetShader", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayHSGetShader, pNumClassInstances, ppClassInstances));
        }
        if(!ppClassInstances->IsNull() && !pNumClassInstances->IsNull())
        {
            ppClassInstances->SetHandleLength(*pNumClassInstances->GetOutputPointer());
        }
        auto out_p_ppClassInstances    = ppClassInstances->GetPointer();
        auto out_hp_ppClassInstances   = ppClassInstances->GetHandlePointer();
        replay_object->HSGetShader(out_hp_ppHullShader,
                                   out_hp_ppClassInstances,
                                   pNumClassInstances->GetOutputPointer());
        if (ppClassInstances->IsNull() && !pNumClassInstances->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayHSGetShader, *pNumClassInstances->GetOutputPointer()); }
        AddObject(out_p_ppHullShader, out_hp_ppHullShader, format::ApiCall_ID3D11DeviceContext_HSGetShader);
        AddObjects(out_p_ppClassInstances, ppClassInstances->GetLength(), out_hp_ppClassInstances, !pNumClassInstances->IsNull() ? *pNumClassInstances->GetOutputPointer() : 0, format::ApiCall_ID3D11DeviceContext_HSGetShader);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSGetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSamplers->IsNull()) ppSamplers->SetHandleLength(NumSamplers);
        auto out_p_ppSamplers    = ppSamplers->GetPointer();
        auto out_hp_ppSamplers   = ppSamplers->GetHandlePointer();
        replay_object->HSGetSamplers(StartSlot,
                                     NumSamplers,
                                     out_hp_ppSamplers);
        AddObjects(out_p_ppSamplers, ppSamplers->GetLength(), out_hp_ppSamplers, NumSamplers, format::ApiCall_ID3D11DeviceContext_HSGetSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_HSGetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        replay_object->HSGetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            out_hp_ppConstantBuffers);
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext_HSGetConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSGetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppShaderResourceViews->IsNull()) ppShaderResourceViews->SetHandleLength(NumViews);
        auto out_p_ppShaderResourceViews    = ppShaderResourceViews->GetPointer();
        auto out_hp_ppShaderResourceViews   = ppShaderResourceViews->GetHandlePointer();
        replay_object->DSGetShaderResources(StartSlot,
                                            NumViews,
                                            out_hp_ppShaderResourceViews);
        AddObjects(out_p_ppShaderResourceViews, ppShaderResourceViews->GetLength(), out_hp_ppShaderResourceViews, NumViews, format::ApiCall_ID3D11DeviceContext_DSGetShaderResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSGetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11DomainShader*>*  ppDomainShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    PointerDecoder<UINT>*                       pNumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDomainShader->IsNull()) ppDomainShader->SetHandleLength(1);
        auto out_p_ppDomainShader    = ppDomainShader->GetPointer();
        auto out_hp_ppDomainShader   = ppDomainShader->GetHandlePointer();
        if(!pNumClassInstances->IsNull())
        {
            pNumClassInstances->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::DSGetShader", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayDSGetShader, pNumClassInstances, ppClassInstances));
        }
        if(!ppClassInstances->IsNull() && !pNumClassInstances->IsNull())
        {
            ppClassInstances->SetHandleLength(*pNumClassInstances->GetOutputPointer());
        }
        auto out_p_ppClassInstances    = ppClassInstances->GetPointer();
        auto out_hp_ppClassInstances   = ppClassInstances->GetHandlePointer();
        replay_object->DSGetShader(out_hp_ppDomainShader,
                                   out_hp_ppClassInstances,
                                   pNumClassInstances->GetOutputPointer());
        if (ppClassInstances->IsNull() && !pNumClassInstances->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayDSGetShader, *pNumClassInstances->GetOutputPointer()); }
        AddObject(out_p_ppDomainShader, out_hp_ppDomainShader, format::ApiCall_ID3D11DeviceContext_DSGetShader);
        AddObjects(out_p_ppClassInstances, ppClassInstances->GetLength(), out_hp_ppClassInstances, !pNumClassInstances->IsNull() ? *pNumClassInstances->GetOutputPointer() : 0, format::ApiCall_ID3D11DeviceContext_DSGetShader);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSGetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSamplers->IsNull()) ppSamplers->SetHandleLength(NumSamplers);
        auto out_p_ppSamplers    = ppSamplers->GetPointer();
        auto out_hp_ppSamplers   = ppSamplers->GetHandlePointer();
        replay_object->DSGetSamplers(StartSlot,
                                     NumSamplers,
                                     out_hp_ppSamplers);
        AddObjects(out_p_ppSamplers, ppSamplers->GetLength(), out_hp_ppSamplers, NumSamplers, format::ApiCall_ID3D11DeviceContext_DSGetSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_DSGetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        replay_object->DSGetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            out_hp_ppConstantBuffers);
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext_DSGetConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSGetShaderResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppShaderResourceViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppShaderResourceViews->IsNull()) ppShaderResourceViews->SetHandleLength(NumViews);
        auto out_p_ppShaderResourceViews    = ppShaderResourceViews->GetPointer();
        auto out_hp_ppShaderResourceViews   = ppShaderResourceViews->GetHandlePointer();
        replay_object->CSGetShaderResources(StartSlot,
                                            NumViews,
                                            out_hp_ppShaderResourceViews);
        AddObjects(out_p_ppShaderResourceViews, ppShaderResourceViews->GetLength(), out_hp_ppShaderResourceViews, NumViews, format::ApiCall_ID3D11DeviceContext_CSGetShaderResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSGetUnorderedAccessViews(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumUAVs,
    HandlePointerDecoder<ID3D11UnorderedAccessView*>* ppUnorderedAccessViews)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppUnorderedAccessViews->IsNull()) ppUnorderedAccessViews->SetHandleLength(NumUAVs);
        auto out_p_ppUnorderedAccessViews    = ppUnorderedAccessViews->GetPointer();
        auto out_hp_ppUnorderedAccessViews   = ppUnorderedAccessViews->GetHandlePointer();
        replay_object->CSGetUnorderedAccessViews(StartSlot,
                                                 NumUAVs,
                                                 out_hp_ppUnorderedAccessViews);
        AddObjects(out_p_ppUnorderedAccessViews, ppUnorderedAccessViews->GetLength(), out_hp_ppUnorderedAccessViews, NumUAVs, format::ApiCall_ID3D11DeviceContext_CSGetUnorderedAccessViews);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSGetShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11ComputeShader*>* ppComputeShader,
    HandlePointerDecoder<ID3D11ClassInstance*>* ppClassInstances,
    PointerDecoder<UINT>*                       pNumClassInstances)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppComputeShader->IsNull()) ppComputeShader->SetHandleLength(1);
        auto out_p_ppComputeShader    = ppComputeShader->GetPointer();
        auto out_hp_ppComputeShader   = ppComputeShader->GetHandlePointer();
        if(!pNumClassInstances->IsNull())
        {
            pNumClassInstances->AllocateOutputData(1, GetOutputArrayCount("ID3D11DeviceContext::CSGetShader", S_OK, object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayCSGetShader, pNumClassInstances, ppClassInstances));
        }
        if(!ppClassInstances->IsNull() && !pNumClassInstances->IsNull())
        {
            ppClassInstances->SetHandleLength(*pNumClassInstances->GetOutputPointer());
        }
        auto out_p_ppClassInstances    = ppClassInstances->GetPointer();
        auto out_hp_ppClassInstances   = ppClassInstances->GetHandlePointer();
        replay_object->CSGetShader(out_hp_ppComputeShader,
                                   out_hp_ppClassInstances,
                                   pNumClassInstances->GetOutputPointer());
        if (ppClassInstances->IsNull() && !pNumClassInstances->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceContextArrayCSGetShader, *pNumClassInstances->GetOutputPointer()); }
        AddObject(out_p_ppComputeShader, out_hp_ppComputeShader, format::ApiCall_ID3D11DeviceContext_CSGetShader);
        AddObjects(out_p_ppClassInstances, ppClassInstances->GetLength(), out_hp_ppClassInstances, !pNumClassInstances->IsNull() ? *pNumClassInstances->GetOutputPointer() : 0, format::ApiCall_ID3D11DeviceContext_CSGetShader);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSGetSamplers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumSamplers,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSamplers->IsNull()) ppSamplers->SetHandleLength(NumSamplers);
        auto out_p_ppSamplers    = ppSamplers->GetPointer();
        auto out_hp_ppSamplers   = ppSamplers->GetHandlePointer();
        replay_object->CSGetSamplers(StartSlot,
                                     NumSamplers,
                                     out_hp_ppSamplers);
        AddObjects(out_p_ppSamplers, ppSamplers->GetLength(), out_hp_ppSamplers, NumSamplers, format::ApiCall_ID3D11DeviceContext_CSGetSamplers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_CSGetConstantBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        replay_object->CSGetConstantBuffers(StartSlot,
                                            NumBuffers,
                                            out_hp_ppConstantBuffers);
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext_CSGetConstantBuffers);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_ClearState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearState();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_Flush(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Flush();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GetType(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D11_DEVICE_CONTEXT_TYPE                   return_value)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetType();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_GetContextFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetContextFlags();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext_FinishCommandList(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    BOOL                                        RestoreDeferredContextState,
    HandlePointerDecoder<ID3D11CommandList*>*   ppCommandList)
{
    auto replay_object = MapObject<ID3D11DeviceContext>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppCommandList->IsNull()) ppCommandList->SetHandleLength(1);
        auto out_p_ppCommandList    = ppCommandList->GetPointer();
        auto out_hp_ppCommandList   = ppCommandList->GetHandlePointer();
        auto replay_result = replay_object->FinishCommandList(RestoreDeferredContextState,
                                                              out_hp_ppCommandList);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCommandList, out_hp_ppCommandList, format::ApiCall_ID3D11DeviceContext_FinishCommandList);
        }
        CheckReplayResult("ID3D11DeviceContext_FinishCommandList", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDecoder_GetCreationParameters(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_DESC>* pVideoDesc,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_CONFIG>* pConfig)
{
    auto replay_object = MapObject<ID3D11VideoDecoder>(object_id);
    if (replay_object != nullptr)
    {
        if(!pVideoDesc->IsNull())
        {
            pVideoDesc->AllocateOutputData(1);
        }
        if(!pConfig->IsNull())
        {
            pConfig->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetCreationParameters(pVideoDesc->GetOutputPointer(),
                                                                  pConfig->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDecoder_GetCreationParameters", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDecoder_GetDriverHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint64_t, void*>*            pDriverHandle)
{
    auto replay_object = MapObject<ID3D11VideoDecoder>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDriverHandle->IsNull())
        {
            pDriverHandle->AllocateOutputData(1);
        }
        auto out_p_pDriverHandle    = pDriverHandle->GetPointer();
        auto out_op_pDriverHandle   = reinterpret_cast<HANDLE*>(pDriverHandle->GetOutputPointer());
        auto replay_result = replay_object->GetDriverHandle(out_op_pDriverHandle);
        CheckReplayResult("ID3D11VideoDecoder_GetDriverHandle", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pDriverHandle, out_p_pDriverHandle, format::ApiCallId::ApiCall_ID3D11VideoDecoder_GetDriverHandle, "ID3D11VideoDecoder_GetDriverHandle");
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorEnumerator_GetVideoProcessorContentDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_CONTENT_DESC>* pContentDesc)
{
    auto replay_object = MapObject<ID3D11VideoProcessorEnumerator>(object_id);
    if (replay_object != nullptr)
    {
        if(!pContentDesc->IsNull())
        {
            pContentDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoProcessorContentDesc(pContentDesc->GetOutputPointer());
        CheckReplayResult("ID3D11VideoProcessorEnumerator_GetVideoProcessorContentDesc", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorEnumerator_CheckVideoProcessorFormat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 Format,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<ID3D11VideoProcessorEnumerator>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFlags->IsNull())
        {
            pFlags->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckVideoProcessorFormat(Format,
                                                                      pFlags->GetOutputPointer());
        CheckReplayResult("ID3D11VideoProcessorEnumerator_CheckVideoProcessorFormat", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorEnumerator_GetVideoProcessorCaps(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_CAPS>* pCaps)
{
    auto replay_object = MapObject<ID3D11VideoProcessorEnumerator>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCaps->IsNull())
        {
            pCaps->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoProcessorCaps(pCaps->GetOutputPointer());
        CheckReplayResult("ID3D11VideoProcessorEnumerator_GetVideoProcessorCaps", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorEnumerator_GetVideoProcessorRateConversionCaps(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        TypeIndex,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS>* pCaps)
{
    auto replay_object = MapObject<ID3D11VideoProcessorEnumerator>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCaps->IsNull())
        {
            pCaps->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoProcessorRateConversionCaps(TypeIndex,
                                                                                pCaps->GetOutputPointer());
        CheckReplayResult("ID3D11VideoProcessorEnumerator_GetVideoProcessorRateConversionCaps", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorEnumerator_GetVideoProcessorCustomRate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        TypeIndex,
    UINT                                        CustomRateIndex,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_CUSTOM_RATE>* pRate)
{
    auto replay_object = MapObject<ID3D11VideoProcessorEnumerator>(object_id);
    if (replay_object != nullptr)
    {
        if(!pRate->IsNull())
        {
            pRate->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoProcessorCustomRate(TypeIndex,
                                                                        CustomRateIndex,
                                                                        pRate->GetOutputPointer());
        CheckReplayResult("ID3D11VideoProcessorEnumerator_GetVideoProcessorCustomRate", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorEnumerator_GetVideoProcessorFilterRange(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D11_VIDEO_PROCESSOR_FILTER                Filter,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_FILTER_RANGE>* pRange)
{
    auto replay_object = MapObject<ID3D11VideoProcessorEnumerator>(object_id);
    if (replay_object != nullptr)
    {
        if(!pRange->IsNull())
        {
            pRange->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoProcessorFilterRange(Filter,
                                                                         pRange->GetOutputPointer());
        CheckReplayResult("ID3D11VideoProcessorEnumerator_GetVideoProcessorFilterRange", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessor_GetContentDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_CONTENT_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11VideoProcessor>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetContentDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessor_GetRateConversionCaps(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_RATE_CONVERSION_CAPS>* pCaps)
{
    auto replay_object = MapObject<ID3D11VideoProcessor>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCaps->IsNull())
        {
            pCaps->AllocateOutputData(1);
        }
        replay_object->GetRateConversionCaps(pCaps->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11AuthenticatedChannel_GetCertificateSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pCertificateSize)
{
    auto replay_object = MapObject<ID3D11AuthenticatedChannel>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCertificateSize->IsNull())
        {
            pCertificateSize->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetCertificateSize(pCertificateSize->GetOutputPointer());
        CheckReplayResult("ID3D11AuthenticatedChannel_GetCertificateSize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11AuthenticatedChannel_GetCertificate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        CertificateSize,
    PointerDecoder<BYTE>*                       pCertificate)
{
    auto replay_object = MapObject<ID3D11AuthenticatedChannel>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCertificate->IsNull())
        {
            pCertificate->AllocateOutputData(CertificateSize /sizeof BYTE);
        }
        auto replay_result = replay_object->GetCertificate(CertificateSize,
                                                           pCertificate->GetOutputPointer());
        CheckReplayResult("ID3D11AuthenticatedChannel_GetCertificate", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11AuthenticatedChannel_GetChannelHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<uint64_t, void*>*            pChannelHandle)
{
    auto replay_object = MapObject<ID3D11AuthenticatedChannel>(object_id);
    if (replay_object != nullptr)
    {
        if(!pChannelHandle->IsNull())
        {
            pChannelHandle->AllocateOutputData(1);
        }
        auto out_p_pChannelHandle    = pChannelHandle->GetPointer();
        auto out_op_pChannelHandle   = reinterpret_cast<HANDLE*>(pChannelHandle->GetOutputPointer());
        replay_object->GetChannelHandle(out_op_pChannelHandle);
        PostProcessExternalObject(S_OK, out_op_pChannelHandle, out_p_pChannelHandle, format::ApiCallId::ApiCall_ID3D11AuthenticatedChannel_GetChannelHandle, "ID3D11AuthenticatedChannel_GetChannelHandle");
    }
}

void Dx12ReplayConsumer::Process_ID3D11CryptoSession_GetCryptoType(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_GUID>*         pCryptoType)
{
    auto replay_object = MapObject<ID3D11CryptoSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCryptoType->IsNull())
        {
            pCryptoType->AllocateOutputData(1);
        }
        replay_object->GetCryptoType(pCryptoType->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11CryptoSession_GetDecoderProfile(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile)
{
    auto replay_object = MapObject<ID3D11CryptoSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDecoderProfile->IsNull())
        {
            pDecoderProfile->AllocateOutputData(1);
        }
        replay_object->GetDecoderProfile(pDecoderProfile->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11CryptoSession_GetCertificateSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pCertificateSize)
{
    auto replay_object = MapObject<ID3D11CryptoSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCertificateSize->IsNull())
        {
            pCertificateSize->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetCertificateSize(pCertificateSize->GetOutputPointer());
        CheckReplayResult("ID3D11CryptoSession_GetCertificateSize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11CryptoSession_GetCertificate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        CertificateSize,
    PointerDecoder<BYTE>*                       pCertificate)
{
    auto replay_object = MapObject<ID3D11CryptoSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCertificate->IsNull())
        {
            pCertificate->AllocateOutputData(CertificateSize /sizeof BYTE);
        }
        auto replay_result = replay_object->GetCertificate(CertificateSize,
                                                           pCertificate->GetOutputPointer());
        CheckReplayResult("ID3D11CryptoSession_GetCertificate", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11CryptoSession_GetCryptoSessionHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<uint64_t, void*>*            pCryptoSessionHandle)
{
    auto replay_object = MapObject<ID3D11CryptoSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCryptoSessionHandle->IsNull())
        {
            pCryptoSessionHandle->AllocateOutputData(1);
        }
        auto out_p_pCryptoSessionHandle    = pCryptoSessionHandle->GetPointer();
        auto out_op_pCryptoSessionHandle   = reinterpret_cast<HANDLE*>(pCryptoSessionHandle->GetOutputPointer());
        replay_object->GetCryptoSessionHandle(out_op_pCryptoSessionHandle);
        PostProcessExternalObject(S_OK, out_op_pCryptoSessionHandle, out_p_pCryptoSessionHandle, format::ApiCallId::ApiCall_ID3D11CryptoSession_GetCryptoSessionHandle, "ID3D11CryptoSession_GetCryptoSessionHandle");
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDecoderOutputView_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11VideoDecoderOutputView>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorInputView_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11VideoProcessorInputView>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorOutputView_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D11VideoProcessorOutputView>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_GetDecoderBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    D3D11_VIDEO_DECODER_BUFFER_TYPE             Type,
    PointerDecoder<UINT>*                       pBufferSize,
    PointerDecoder<uint8_t, void*>*             ppBuffer)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        if(!pBufferSize->IsNull())
        {
            pBufferSize->AllocateOutputData(1);
        }
        if(!ppBuffer->IsNull())
        {
            ppBuffer->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDecoderBuffer(in_pDecoder,
                                                             Type,
                                                             pBufferSize->GetOutputPointer(),
                                                             ppBuffer->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext_GetDecoderBuffer", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_ReleaseDecoderBuffer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    D3D11_VIDEO_DECODER_BUFFER_TYPE             Type)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto replay_result = replay_object->ReleaseDecoderBuffer(in_pDecoder,
                                                                 Type);
        CheckReplayResult("ID3D11VideoContext_ReleaseDecoderBuffer", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_DecoderBeginFrame(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    format::HandleId                            pView,
    UINT                                        ContentKeySize,
    PointerDecoder<uint8_t>*                    pContentKey)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto in_pView = MapObject<ID3D11VideoDecoderOutputView>(pView);
        auto replay_result = replay_object->DecoderBeginFrame(in_pDecoder,
                                                              in_pView,
                                                              ContentKeySize,
                                                              pContentKey->GetPointer());
        CheckReplayResult("ID3D11VideoContext_DecoderBeginFrame", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_DecoderEndFrame(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto replay_result = replay_object->DecoderEndFrame(in_pDecoder);
        CheckReplayResult("ID3D11VideoContext_DecoderEndFrame", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_SubmitDecoderBuffers(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    UINT                                        NumBuffers,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC>* pBufferDesc)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto replay_result = replay_object->SubmitDecoderBuffers(in_pDecoder,
                                                                 NumBuffers,
                                                                 pBufferDesc->GetPointer());
        CheckReplayResult("ID3D11VideoContext_SubmitDecoderBuffers", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_DecoderExtension(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_EXTENSION>* pExtensionData)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        MapStructObjects(pExtensionData->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = replay_object->DecoderExtension(in_pDecoder,
                                                             pExtensionData->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetOutputTargetRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    BOOL                                        Enable,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputTargetRect(in_pVideoProcessor,
                                                         Enable,
                                                         pRect->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetOutputBackgroundColor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    BOOL                                        YCbCr,
    StructPointerDecoder<Decoded_D3D11_VIDEO_COLOR>* pColor)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputBackgroundColor(in_pVideoProcessor,
                                                              YCbCr,
                                                              pColor->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetOutputColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_COLOR_SPACE>* pColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputColorSpace(in_pVideoProcessor,
                                                         pColorSpace->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetOutputAlphaFillMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE       AlphaFillMode,
    UINT                                        StreamIndex)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputAlphaFillMode(in_pVideoProcessor,
                                                            AlphaFillMode,
                                                            StreamIndex);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetOutputConstriction(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    BOOL                                        Enable,
    Decoded_tagSIZE                             Size)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputConstriction(in_pVideoProcessor,
                                                           Enable,
                                                           *Size.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetOutputStereoMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputStereoMode(in_pVideoProcessor,
                                                         Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetOutputExtension(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pVideoProcessor,
    StructPointerDecoder<Decoded_GUID>*         pExtensionGuid,
    UINT                                        DataSize,
    uint64_t                                    pData)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        auto in_pData = PreProcessExternalObject(pData, format::ApiCallId::ApiCall_ID3D11VideoContext_VideoProcessorSetOutputExtension, "ID3D11VideoContext_VideoProcessorSetOutputExtension");
        auto replay_result = replay_object->VideoProcessorSetOutputExtension(in_pVideoProcessor,
                                                                             pExtensionGuid->GetPointer(),
                                                                             DataSize,
                                                                             in_pData);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetOutputTargetRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<BOOL>*                       Enabled,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!Enabled->IsNull())
        {
            Enabled->AllocateOutputData(1);
        }
        if(!pRect->IsNull())
        {
            pRect->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputTargetRect(in_pVideoProcessor,
                                                         Enabled->GetOutputPointer(),
                                                         pRect->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetOutputBackgroundColor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<BOOL>*                       pYCbCr,
    StructPointerDecoder<Decoded_D3D11_VIDEO_COLOR>* pColor)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pYCbCr->IsNull())
        {
            pYCbCr->AllocateOutputData(1);
        }
        if(!pColor->IsNull())
        {
            pColor->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputBackgroundColor(in_pVideoProcessor,
                                                              pYCbCr->GetOutputPointer(),
                                                              pColor->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetOutputColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_COLOR_SPACE>* pColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pColorSpace->IsNull())
        {
            pColorSpace->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputColorSpace(in_pVideoProcessor,
                                                         pColorSpace->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetOutputAlphaFillMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<D3D11_VIDEO_PROCESSOR_ALPHA_FILL_MODE>* pAlphaFillMode,
    PointerDecoder<UINT>*                       pStreamIndex)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pAlphaFillMode->IsNull())
        {
            pAlphaFillMode->AllocateOutputData(1);
        }
        if(!pStreamIndex->IsNull())
        {
            pStreamIndex->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputAlphaFillMode(in_pVideoProcessor,
                                                            pAlphaFillMode->GetOutputPointer(),
                                                            pStreamIndex->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetOutputConstriction(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<BOOL>*                       pEnabled,
    StructPointerDecoder<Decoded_tagSIZE>*      pSize)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        if(!pSize->IsNull())
        {
            pSize->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputConstriction(in_pVideoProcessor,
                                                           pEnabled->GetOutputPointer(),
                                                           pSize->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetOutputStereoMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<BOOL>*                       pEnabled)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputStereoMode(in_pVideoProcessor,
                                                         pEnabled->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetOutputExtension(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pVideoProcessor,
    StructPointerDecoder<Decoded_GUID>*         pExtensionGuid,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->VideoProcessorGetOutputExtension(in_pVideoProcessor,
                                                                             pExtensionGuid->GetPointer(),
                                                                             DataSize,
                                                                             pData->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamFrameFormat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    D3D11_VIDEO_FRAME_FORMAT                    FrameFormat)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamFrameFormat(in_pVideoProcessor,
                                                          StreamIndex,
                                                          FrameFormat);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_COLOR_SPACE>* pColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamColorSpace(in_pVideoProcessor,
                                                         StreamIndex,
                                                         pColorSpace->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamOutputRate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    D3D11_VIDEO_PROCESSOR_OUTPUT_RATE           OutputRate,
    BOOL                                        RepeatFrame,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pCustomRate)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamOutputRate(in_pVideoProcessor,
                                                         StreamIndex,
                                                         OutputRate,
                                                         RepeatFrame,
                                                         pCustomRate->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamSourceRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamSourceRect(in_pVideoProcessor,
                                                         StreamIndex,
                                                         Enable,
                                                         pRect->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamDestRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamDestRect(in_pVideoProcessor,
                                                       StreamIndex,
                                                       Enable,
                                                       pRect->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamAlpha(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    FLOAT                                       Alpha)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamAlpha(in_pVideoProcessor,
                                                    StreamIndex,
                                                    Enable,
                                                    Alpha);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamPalette(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    UINT                                        Count,
    PointerDecoder<UINT>*                       pEntries)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamPalette(in_pVideoProcessor,
                                                      StreamIndex,
                                                      Count,
                                                      pEntries->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamPixelAspectRatio(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pSourceAspectRatio,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pDestinationAspectRatio)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamPixelAspectRatio(in_pVideoProcessor,
                                                               StreamIndex,
                                                               Enable,
                                                               pSourceAspectRatio->GetPointer(),
                                                               pDestinationAspectRatio->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamLumaKey(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    FLOAT                                       Lower,
    FLOAT                                       Upper)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamLumaKey(in_pVideoProcessor,
                                                      StreamIndex,
                                                      Enable,
                                                      Lower,
                                                      Upper);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamStereoFormat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    D3D11_VIDEO_PROCESSOR_STEREO_FORMAT         Format,
    BOOL                                        LeftViewFrame0,
    BOOL                                        BaseViewFrame0,
    D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE      FlipMode,
    int                                         MonoOffset)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamStereoFormat(in_pVideoProcessor,
                                                           StreamIndex,
                                                           Enable,
                                                           Format,
                                                           LeftViewFrame0,
                                                           BaseViewFrame0,
                                                           FlipMode,
                                                           MonoOffset);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamAutoProcessingMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamAutoProcessingMode(in_pVideoProcessor,
                                                                 StreamIndex,
                                                                 Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    D3D11_VIDEO_PROCESSOR_FILTER                Filter,
    BOOL                                        Enable,
    int                                         Level)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamFilter(in_pVideoProcessor,
                                                     StreamIndex,
                                                     Filter,
                                                     Enable,
                                                     Level);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamExtension(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    StructPointerDecoder<Decoded_GUID>*         pExtensionGuid,
    UINT                                        DataSize,
    uint64_t                                    pData)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        auto in_pData = PreProcessExternalObject(pData, format::ApiCallId::ApiCall_ID3D11VideoContext_VideoProcessorSetStreamExtension, "ID3D11VideoContext_VideoProcessorSetStreamExtension");
        auto replay_result = replay_object->VideoProcessorSetStreamExtension(in_pVideoProcessor,
                                                                             StreamIndex,
                                                                             pExtensionGuid->GetPointer(),
                                                                             DataSize,
                                                                             in_pData);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamFrameFormat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<D3D11_VIDEO_FRAME_FORMAT>*   pFrameFormat)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pFrameFormat->IsNull())
        {
            pFrameFormat->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamFrameFormat(in_pVideoProcessor,
                                                          StreamIndex,
                                                          pFrameFormat->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_COLOR_SPACE>* pColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pColorSpace->IsNull())
        {
            pColorSpace->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamColorSpace(in_pVideoProcessor,
                                                         StreamIndex,
                                                         pColorSpace->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamOutputRate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<D3D11_VIDEO_PROCESSOR_OUTPUT_RATE>* pOutputRate,
    PointerDecoder<BOOL>*                       pRepeatFrame,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pCustomRate)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pOutputRate->IsNull())
        {
            pOutputRate->AllocateOutputData(1);
        }
        if(!pRepeatFrame->IsNull())
        {
            pRepeatFrame->AllocateOutputData(1);
        }
        if(!pCustomRate->IsNull())
        {
            pCustomRate->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamOutputRate(in_pVideoProcessor,
                                                         StreamIndex,
                                                         pOutputRate->GetOutputPointer(),
                                                         pRepeatFrame->GetOutputPointer(),
                                                         pCustomRate->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamSourceRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnabled,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        if(!pRect->IsNull())
        {
            pRect->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamSourceRect(in_pVideoProcessor,
                                                         StreamIndex,
                                                         pEnabled->GetOutputPointer(),
                                                         pRect->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamDestRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnabled,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        if(!pRect->IsNull())
        {
            pRect->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamDestRect(in_pVideoProcessor,
                                                       StreamIndex,
                                                       pEnabled->GetOutputPointer(),
                                                       pRect->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamAlpha(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnabled,
    PointerDecoder<FLOAT>*                      pAlpha)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        if(!pAlpha->IsNull())
        {
            pAlpha->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamAlpha(in_pVideoProcessor,
                                                    StreamIndex,
                                                    pEnabled->GetOutputPointer(),
                                                    pAlpha->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamPalette(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    UINT                                        Count,
    PointerDecoder<UINT>*                       pEntries)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEntries->IsNull())
        {
            pEntries->AllocateOutputData(Count);
        }
        replay_object->VideoProcessorGetStreamPalette(in_pVideoProcessor,
                                                      StreamIndex,
                                                      Count,
                                                      pEntries->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamPixelAspectRatio(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnabled,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pSourceAspectRatio,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pDestinationAspectRatio)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        if(!pSourceAspectRatio->IsNull())
        {
            pSourceAspectRatio->AllocateOutputData(1);
        }
        if(!pDestinationAspectRatio->IsNull())
        {
            pDestinationAspectRatio->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamPixelAspectRatio(in_pVideoProcessor,
                                                               StreamIndex,
                                                               pEnabled->GetOutputPointer(),
                                                               pSourceAspectRatio->GetOutputPointer(),
                                                               pDestinationAspectRatio->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamLumaKey(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnabled,
    PointerDecoder<FLOAT>*                      pLower,
    PointerDecoder<FLOAT>*                      pUpper)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        if(!pLower->IsNull())
        {
            pLower->AllocateOutputData(1);
        }
        if(!pUpper->IsNull())
        {
            pUpper->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamLumaKey(in_pVideoProcessor,
                                                      StreamIndex,
                                                      pEnabled->GetOutputPointer(),
                                                      pLower->GetOutputPointer(),
                                                      pUpper->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamStereoFormat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnable,
    PointerDecoder<D3D11_VIDEO_PROCESSOR_STEREO_FORMAT>* pFormat,
    PointerDecoder<BOOL>*                       pLeftViewFrame0,
    PointerDecoder<BOOL>*                       pBaseViewFrame0,
    PointerDecoder<D3D11_VIDEO_PROCESSOR_STEREO_FLIP_MODE>* pFlipMode,
    PointerDecoder<int>*                        MonoOffset)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnable->IsNull())
        {
            pEnable->AllocateOutputData(1);
        }
        if(!pFormat->IsNull())
        {
            pFormat->AllocateOutputData(1);
        }
        if(!pLeftViewFrame0->IsNull())
        {
            pLeftViewFrame0->AllocateOutputData(1);
        }
        if(!pBaseViewFrame0->IsNull())
        {
            pBaseViewFrame0->AllocateOutputData(1);
        }
        if(!pFlipMode->IsNull())
        {
            pFlipMode->AllocateOutputData(1);
        }
        if(!MonoOffset->IsNull())
        {
            MonoOffset->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamStereoFormat(in_pVideoProcessor,
                                                           StreamIndex,
                                                           pEnable->GetOutputPointer(),
                                                           pFormat->GetOutputPointer(),
                                                           pLeftViewFrame0->GetOutputPointer(),
                                                           pBaseViewFrame0->GetOutputPointer(),
                                                           pFlipMode->GetOutputPointer(),
                                                           MonoOffset->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamAutoProcessingMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnabled)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamAutoProcessingMode(in_pVideoProcessor,
                                                                 StreamIndex,
                                                                 pEnabled->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    D3D11_VIDEO_PROCESSOR_FILTER                Filter,
    PointerDecoder<BOOL>*                       pEnabled,
    PointerDecoder<int>*                        pLevel)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnabled->IsNull())
        {
            pEnabled->AllocateOutputData(1);
        }
        if(!pLevel->IsNull())
        {
            pLevel->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamFilter(in_pVideoProcessor,
                                                     StreamIndex,
                                                     Filter,
                                                     pEnabled->GetOutputPointer(),
                                                     pLevel->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamExtension(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    StructPointerDecoder<Decoded_GUID>*         pExtensionGuid,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->VideoProcessorGetStreamExtension(in_pVideoProcessor,
                                                                             StreamIndex,
                                                                             pExtensionGuid->GetPointer(),
                                                                             DataSize,
                                                                             pData->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorBlt(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pVideoProcessor,
    format::HandleId                            pView,
    UINT                                        OutputFrame,
    UINT                                        StreamCount,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_STREAM>* pStreams)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        auto in_pView = MapObject<ID3D11VideoProcessorOutputView>(pView);
        MapStructArrayObjects(pStreams->GetMetaStructPointer(), pStreams->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = replay_object->VideoProcessorBlt(in_pVideoProcessor,
                                                              in_pView,
                                                              OutputFrame,
                                                              StreamCount,
                                                              pStreams->GetPointer());
        CheckReplayResult("ID3D11VideoContext_VideoProcessorBlt", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_NegotiateCryptoSessionKeyExchange(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pCryptoSession,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->NegotiateCryptoSessionKeyExchange(in_pCryptoSession,
                                                                              DataSize,
                                                                              pData->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext_NegotiateCryptoSessionKeyExchange", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_EncryptionBlt(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCryptoSession,
    format::HandleId                            pSrcSurface,
    format::HandleId                            pDstSurface,
    UINT                                        IVSize,
    PointerDecoder<uint8_t>*                    pIV)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        auto in_pSrcSurface = MapObject<ID3D11Texture2D>(pSrcSurface);
        auto in_pDstSurface = MapObject<ID3D11Texture2D>(pDstSurface);
        if(!pIV->IsNull())
        {
            pIV->AllocateOutputData(IVSize);
        }
        replay_object->EncryptionBlt(in_pCryptoSession,
                                     in_pSrcSurface,
                                     in_pDstSurface,
                                     IVSize,
                                     pIV->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_DecryptionBlt(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCryptoSession,
    format::HandleId                            pSrcSurface,
    format::HandleId                            pDstSurface,
    StructPointerDecoder<Decoded_D3D11_ENCRYPTED_BLOCK_INFO>* pEncryptedBlockInfo,
    UINT                                        ContentKeySize,
    PointerDecoder<uint8_t>*                    pContentKey,
    UINT                                        IVSize,
    PointerDecoder<uint8_t>*                    pIV)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        auto in_pSrcSurface = MapObject<ID3D11Texture2D>(pSrcSurface);
        auto in_pDstSurface = MapObject<ID3D11Texture2D>(pDstSurface);
        if(!pIV->IsNull())
        {
            pIV->AllocateOutputData(IVSize);
        }
        replay_object->DecryptionBlt(in_pCryptoSession,
                                     in_pSrcSurface,
                                     in_pDstSurface,
                                     pEncryptedBlockInfo->GetPointer(),
                                     ContentKeySize,
                                     pContentKey->GetPointer(),
                                     IVSize,
                                     pIV->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_StartSessionKeyRefresh(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCryptoSession,
    UINT                                        RandomNumberSize,
    PointerDecoder<uint8_t>*                    pRandomNumber)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        if(!pRandomNumber->IsNull())
        {
            pRandomNumber->AllocateOutputData(RandomNumberSize);
        }
        replay_object->StartSessionKeyRefresh(in_pCryptoSession,
                                              RandomNumberSize,
                                              pRandomNumber->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_FinishSessionKeyRefresh(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCryptoSession)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        replay_object->FinishSessionKeyRefresh(in_pCryptoSession);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_GetEncryptionBltKey(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pCryptoSession,
    UINT                                        KeySize,
    PointerDecoder<uint8_t>*                    pReadbackKey)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        if(!pReadbackKey->IsNull())
        {
            pReadbackKey->AllocateOutputData(KeySize);
        }
        auto replay_result = replay_object->GetEncryptionBltKey(in_pCryptoSession,
                                                                KeySize,
                                                                pReadbackKey->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext_GetEncryptionBltKey", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_NegotiateAuthenticatedChannelKeyExchange(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pChannel,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pChannel = MapObject<ID3D11AuthenticatedChannel>(pChannel);
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->NegotiateAuthenticatedChannelKeyExchange(in_pChannel,
                                                                                     DataSize,
                                                                                     pData->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext_NegotiateAuthenticatedChannelKeyExchange", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_QueryAuthenticatedChannel(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pChannel,
    UINT                                        InputSize,
    PointerDecoder<uint8_t>*                    pInput,
    UINT                                        OutputSize,
    PointerDecoder<uint8_t>*                    pOutput)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pChannel = MapObject<ID3D11AuthenticatedChannel>(pChannel);
        if(!pOutput->IsNull())
        {
            pOutput->AllocateOutputData(OutputSize);
        }
        auto replay_result = replay_object->QueryAuthenticatedChannel(in_pChannel,
                                                                      InputSize,
                                                                      pInput->GetPointer(),
                                                                      OutputSize,
                                                                      pOutput->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext_QueryAuthenticatedChannel", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_ConfigureAuthenticatedChannel(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pChannel,
    UINT                                        InputSize,
    PointerDecoder<uint8_t>*                    pInput,
    StructPointerDecoder<Decoded_D3D11_AUTHENTICATED_CONFIGURE_OUTPUT>* pOutput)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pChannel = MapObject<ID3D11AuthenticatedChannel>(pChannel);
        if(!pOutput->IsNull())
        {
            pOutput->AllocateOutputData(1);
        }
        auto replay_result = replay_object->ConfigureAuthenticatedChannel(in_pChannel,
                                                                          InputSize,
                                                                          pInput->GetPointer(),
                                                                          pOutput->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext_ConfigureAuthenticatedChannel", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorSetStreamRotation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    D3D11_VIDEO_PROCESSOR_ROTATION              Rotation)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamRotation(in_pVideoProcessor,
                                                       StreamIndex,
                                                       Enable,
                                                       Rotation);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext_VideoProcessorGetStreamRotation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnable,
    PointerDecoder<D3D11_VIDEO_PROCESSOR_ROTATION>* pRotation)
{
    auto replay_object = MapObject<ID3D11VideoContext>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnable->IsNull())
        {
            pEnable->AllocateOutputData(1);
        }
        if(!pRotation->IsNull())
        {
            pRotation->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamRotation(in_pVideoProcessor,
                                                       StreamIndex,
                                                       pEnable->GetOutputPointer(),
                                                       pRotation->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateVideoDecoder(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_DESC>* pVideoDesc,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_CONFIG>* pConfig,
    HandlePointerDecoder<ID3D11VideoDecoder*>*  ppDecoder)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDecoder->IsNull()) ppDecoder->SetHandleLength(1);
        auto out_p_ppDecoder    = ppDecoder->GetPointer();
        auto out_hp_ppDecoder   = ppDecoder->GetHandlePointer();
        auto replay_result = replay_object->CreateVideoDecoder(pVideoDesc->GetPointer(),
                                                               pConfig->GetPointer(),
                                                               out_hp_ppDecoder);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDecoder, out_hp_ppDecoder, format::ApiCall_ID3D11VideoDevice_CreateVideoDecoder);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateVideoDecoder", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateVideoProcessor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pEnum,
    UINT                                        RateConversionIndex,
    HandlePointerDecoder<ID3D11VideoProcessor*>* ppVideoProcessor)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pEnum = MapObject<ID3D11VideoProcessorEnumerator>(pEnum);
        if(!ppVideoProcessor->IsNull()) ppVideoProcessor->SetHandleLength(1);
        auto out_p_ppVideoProcessor    = ppVideoProcessor->GetPointer();
        auto out_hp_ppVideoProcessor   = ppVideoProcessor->GetHandlePointer();
        auto replay_result = replay_object->CreateVideoProcessor(in_pEnum,
                                                                 RateConversionIndex,
                                                                 out_hp_ppVideoProcessor);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppVideoProcessor, out_hp_ppVideoProcessor, format::ApiCall_ID3D11VideoDevice_CreateVideoProcessor);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateVideoProcessor", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateAuthenticatedChannel(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D11_AUTHENTICATED_CHANNEL_TYPE            ChannelType,
    HandlePointerDecoder<ID3D11AuthenticatedChannel*>* ppAuthenticatedChannel)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppAuthenticatedChannel->IsNull()) ppAuthenticatedChannel->SetHandleLength(1);
        auto out_p_ppAuthenticatedChannel    = ppAuthenticatedChannel->GetPointer();
        auto out_hp_ppAuthenticatedChannel   = ppAuthenticatedChannel->GetHandlePointer();
        auto replay_result = replay_object->CreateAuthenticatedChannel(ChannelType,
                                                                       out_hp_ppAuthenticatedChannel);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppAuthenticatedChannel, out_hp_ppAuthenticatedChannel, format::ApiCall_ID3D11VideoDevice_CreateAuthenticatedChannel);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateAuthenticatedChannel", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateCryptoSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pCryptoType,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile,
    StructPointerDecoder<Decoded_GUID>*         pKeyExchangeType,
    HandlePointerDecoder<ID3D11CryptoSession*>* ppCryptoSession)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppCryptoSession->IsNull()) ppCryptoSession->SetHandleLength(1);
        auto out_p_ppCryptoSession    = ppCryptoSession->GetPointer();
        auto out_hp_ppCryptoSession   = ppCryptoSession->GetHandlePointer();
        auto replay_result = replay_object->CreateCryptoSession(pCryptoType->GetPointer(),
                                                                pDecoderProfile->GetPointer(),
                                                                pKeyExchangeType->GetPointer(),
                                                                out_hp_ppCryptoSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCryptoSession, out_hp_ppCryptoSession, format::ApiCall_ID3D11VideoDevice_CreateCryptoSession);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateCryptoSession", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateVideoDecoderOutputView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC>* pDesc,
    HandlePointerDecoder<ID3D11VideoDecoderOutputView*>* ppVDOVView)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppVDOVView->IsNull()) ppVDOVView->SetHandleLength(1);
        auto out_p_ppVDOVView    = ppVDOVView->GetPointer();
        auto out_hp_ppVDOVView   = ppVDOVView->GetHandlePointer();
        auto replay_result = replay_object->CreateVideoDecoderOutputView(in_pResource,
                                                                         pDesc->GetPointer(),
                                                                         out_hp_ppVDOVView);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppVDOVView, out_hp_ppVDOVView, format::ApiCall_ID3D11VideoDevice_CreateVideoDecoderOutputView);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateVideoDecoderOutputView", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateVideoProcessorInputView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    format::HandleId                            pEnum,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_INPUT_VIEW_DESC>* pDesc,
    HandlePointerDecoder<ID3D11VideoProcessorInputView*>* ppVPIView)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        auto in_pEnum = MapObject<ID3D11VideoProcessorEnumerator>(pEnum);
        if(!ppVPIView->IsNull()) ppVPIView->SetHandleLength(1);
        auto out_p_ppVPIView    = ppVPIView->GetPointer();
        auto out_hp_ppVPIView   = ppVPIView->GetHandlePointer();
        auto replay_result = replay_object->CreateVideoProcessorInputView(in_pResource,
                                                                          in_pEnum,
                                                                          pDesc->GetPointer(),
                                                                          out_hp_ppVPIView);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppVPIView, out_hp_ppVPIView, format::ApiCall_ID3D11VideoDevice_CreateVideoProcessorInputView);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateVideoProcessorInputView", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateVideoProcessorOutputView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    format::HandleId                            pEnum,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_OUTPUT_VIEW_DESC>* pDesc,
    HandlePointerDecoder<ID3D11VideoProcessorOutputView*>* ppVPOView)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        auto in_pEnum = MapObject<ID3D11VideoProcessorEnumerator>(pEnum);
        if(!ppVPOView->IsNull()) ppVPOView->SetHandleLength(1);
        auto out_p_ppVPOView    = ppVPOView->GetPointer();
        auto out_hp_ppVPOView   = ppVPOView->GetHandlePointer();
        auto replay_result = replay_object->CreateVideoProcessorOutputView(in_pResource,
                                                                           in_pEnum,
                                                                           pDesc->GetPointer(),
                                                                           out_hp_ppVPOView);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppVPOView, out_hp_ppVPOView, format::ApiCall_ID3D11VideoDevice_CreateVideoProcessorOutputView);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateVideoProcessorOutputView", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CreateVideoProcessorEnumerator(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_CONTENT_DESC>* pDesc,
    HandlePointerDecoder<ID3D11VideoProcessorEnumerator*>* ppEnum)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppEnum->IsNull()) ppEnum->SetHandleLength(1);
        auto out_p_ppEnum    = ppEnum->GetPointer();
        auto out_hp_ppEnum   = ppEnum->GetHandlePointer();
        auto replay_result = replay_object->CreateVideoProcessorEnumerator(pDesc->GetPointer(),
                                                                           out_hp_ppEnum);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppEnum, out_hp_ppEnum, format::ApiCall_ID3D11VideoDevice_CreateVideoProcessorEnumerator);
        }
        CheckReplayResult("ID3D11VideoDevice_CreateVideoProcessorEnumerator", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_GetVideoDecoderProfileCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetVideoDecoderProfileCount();
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_GetVideoDecoderProfile(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Index,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDecoderProfile->IsNull())
        {
            pDecoderProfile->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoDecoderProfile(Index,
                                                                   pDecoderProfile->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice_GetVideoDecoderProfile", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CheckVideoDecoderFormat(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile,
    DXGI_FORMAT                                 Format,
    PointerDecoder<BOOL>*                       pSupported)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pSupported->IsNull())
        {
            pSupported->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckVideoDecoderFormat(pDecoderProfile->GetPointer(),
                                                                    Format,
                                                                    pSupported->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice_CheckVideoDecoderFormat", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_GetVideoDecoderConfigCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_DESC>* pDesc,
    PointerDecoder<UINT>*                       pCount)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCount->IsNull())
        {
            pCount->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoDecoderConfigCount(pDesc->GetPointer(),
                                                                       pCount->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice_GetVideoDecoderConfigCount", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_GetVideoDecoderConfig(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_DESC>* pDesc,
    UINT                                        Index,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_CONFIG>* pConfig)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pConfig->IsNull())
        {
            pConfig->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoDecoderConfig(pDesc->GetPointer(),
                                                                  Index,
                                                                  pConfig->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice_GetVideoDecoderConfig", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_GetContentProtectionCaps(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pCryptoType,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile,
    StructPointerDecoder<Decoded_D3D11_VIDEO_CONTENT_PROTECTION_CAPS>* pCaps)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCaps->IsNull())
        {
            pCaps->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetContentProtectionCaps(pCryptoType->GetPointer(),
                                                                     pDecoderProfile->GetPointer(),
                                                                     pCaps->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice_GetContentProtectionCaps", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_CheckCryptoKeyExchange(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pCryptoType,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile,
    UINT                                        Index,
    StructPointerDecoder<Decoded_GUID>*         pKeyExchangeType)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pKeyExchangeType->IsNull())
        {
            pKeyExchangeType->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckCryptoKeyExchange(pCryptoType->GetPointer(),
                                                                   pDecoderProfile->GetPointer(),
                                                                   Index,
                                                                   pKeyExchangeType->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice_CheckCryptoKeyExchange", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_SetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPrivateData(*guid.decoded_value,
                                                           DataSize,
                                                           pData->GetPointer());
        CheckReplayResult("ID3D11VideoDevice_SetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice_SetPrivateDataInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    format::HandleId                            pData)
{
    auto replay_object = MapObject<ID3D11VideoDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pData = MapObject<IUnknown>(pData);
        auto replay_result = replay_object->SetPrivateDataInterface(*guid.decoded_value,
                                                                    in_pData);
        CheckReplayResult("ID3D11VideoDevice_SetPrivateDataInterface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateShaderResourceView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC>* pDesc,
    HandlePointerDecoder<ID3D11ShaderResourceView*>* ppSRView)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppSRView->IsNull()) ppSRView->SetHandleLength(1);
        auto out_p_ppSRView    = ppSRView->GetPointer();
        auto out_hp_ppSRView   = ppSRView->GetHandlePointer();
        auto replay_result = replay_object->CreateShaderResourceView(in_pResource,
                                                                     pDesc->GetPointer(),
                                                                     out_hp_ppSRView);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSRView, out_hp_ppSRView, format::ApiCall_ID3D11Device_CreateShaderResourceView);
        }
        CheckReplayResult("ID3D11Device_CreateShaderResourceView", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
    HandlePointerDecoder<ID3D11UnorderedAccessView*>* ppUAView)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppUAView->IsNull()) ppUAView->SetHandleLength(1);
        auto out_p_ppUAView    = ppUAView->GetPointer();
        auto out_hp_ppUAView   = ppUAView->GetHandlePointer();
        auto replay_result = replay_object->CreateUnorderedAccessView(in_pResource,
                                                                      pDesc->GetPointer(),
                                                                      out_hp_ppUAView);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppUAView, out_hp_ppUAView, format::ApiCall_ID3D11Device_CreateUnorderedAccessView);
        }
        CheckReplayResult("ID3D11Device_CreateUnorderedAccessView", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateRenderTargetView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_RENDER_TARGET_VIEW_DESC>* pDesc,
    HandlePointerDecoder<ID3D11RenderTargetView*>* ppRTView)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppRTView->IsNull()) ppRTView->SetHandleLength(1);
        auto out_p_ppRTView    = ppRTView->GetPointer();
        auto out_hp_ppRTView   = ppRTView->GetHandlePointer();
        auto replay_result = replay_object->CreateRenderTargetView(in_pResource,
                                                                   pDesc->GetPointer(),
                                                                   out_hp_ppRTView);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppRTView, out_hp_ppRTView, format::ApiCall_ID3D11Device_CreateRenderTargetView);
        }
        CheckReplayResult("ID3D11Device_CreateRenderTargetView", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateDepthStencilView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_DEPTH_STENCIL_VIEW_DESC>* pDesc,
    HandlePointerDecoder<ID3D11DepthStencilView*>* ppDepthStencilView)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppDepthStencilView->IsNull()) ppDepthStencilView->SetHandleLength(1);
        auto out_p_ppDepthStencilView    = ppDepthStencilView->GetPointer();
        auto out_hp_ppDepthStencilView   = ppDepthStencilView->GetHandlePointer();
        auto replay_result = replay_object->CreateDepthStencilView(in_pResource,
                                                                   pDesc->GetPointer(),
                                                                   out_hp_ppDepthStencilView);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDepthStencilView, out_hp_ppDepthStencilView, format::ApiCall_ID3D11Device_CreateDepthStencilView);
        }
        CheckReplayResult("ID3D11Device_CreateDepthStencilView", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateInputLayout(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_INPUT_ELEMENT_DESC>* pInputElementDescs,
    UINT                                        NumElements,
    PointerDecoder<uint8_t>*                    pShaderBytecodeWithInputSignature,
    SIZE_T                                      BytecodeLength,
    HandlePointerDecoder<ID3D11InputLayout*>*   ppInputLayout)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppInputLayout->IsNull()) ppInputLayout->SetHandleLength(1);
        auto out_p_ppInputLayout    = ppInputLayout->GetPointer();
        auto out_hp_ppInputLayout   = ppInputLayout->GetHandlePointer();
        auto replay_result = replay_object->CreateInputLayout(pInputElementDescs->GetPointer(),
                                                              NumElements,
                                                              pShaderBytecodeWithInputSignature->GetPointer(),
                                                              BytecodeLength,
                                                              out_hp_ppInputLayout);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppInputLayout, out_hp_ppInputLayout, format::ApiCall_ID3D11Device_CreateInputLayout);
        }
        CheckReplayResult("ID3D11Device_CreateInputLayout", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateVertexShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pShaderBytecode,
    SIZE_T                                      BytecodeLength,
    format::HandleId                            pClassLinkage,
    HandlePointerDecoder<ID3D11VertexShader*>*  ppVertexShader)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pClassLinkage = MapObject<ID3D11ClassLinkage>(pClassLinkage);
        if(!ppVertexShader->IsNull()) ppVertexShader->SetHandleLength(1);
        auto out_p_ppVertexShader    = ppVertexShader->GetPointer();
        auto out_hp_ppVertexShader   = ppVertexShader->GetHandlePointer();
        auto replay_result = replay_object->CreateVertexShader(pShaderBytecode->GetPointer(),
                                                               BytecodeLength,
                                                               in_pClassLinkage,
                                                               out_hp_ppVertexShader);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppVertexShader, out_hp_ppVertexShader, format::ApiCall_ID3D11Device_CreateVertexShader);
        }
        CheckReplayResult("ID3D11Device_CreateVertexShader", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateGeometryShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pShaderBytecode,
    SIZE_T                                      BytecodeLength,
    format::HandleId                            pClassLinkage,
    HandlePointerDecoder<ID3D11GeometryShader*>* ppGeometryShader)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pClassLinkage = MapObject<ID3D11ClassLinkage>(pClassLinkage);
        if(!ppGeometryShader->IsNull()) ppGeometryShader->SetHandleLength(1);
        auto out_p_ppGeometryShader    = ppGeometryShader->GetPointer();
        auto out_hp_ppGeometryShader   = ppGeometryShader->GetHandlePointer();
        auto replay_result = replay_object->CreateGeometryShader(pShaderBytecode->GetPointer(),
                                                                 BytecodeLength,
                                                                 in_pClassLinkage,
                                                                 out_hp_ppGeometryShader);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppGeometryShader, out_hp_ppGeometryShader, format::ApiCall_ID3D11Device_CreateGeometryShader);
        }
        CheckReplayResult("ID3D11Device_CreateGeometryShader", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateGeometryShaderWithStreamOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pShaderBytecode,
    SIZE_T                                      BytecodeLength,
    StructPointerDecoder<Decoded_D3D11_SO_DECLARATION_ENTRY>* pSODeclaration,
    UINT                                        NumEntries,
    PointerDecoder<UINT>*                       pBufferStrides,
    UINT                                        NumStrides,
    UINT                                        RasterizedStream,
    format::HandleId                            pClassLinkage,
    HandlePointerDecoder<ID3D11GeometryShader*>* ppGeometryShader)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pClassLinkage = MapObject<ID3D11ClassLinkage>(pClassLinkage);
        if(!ppGeometryShader->IsNull()) ppGeometryShader->SetHandleLength(1);
        auto out_p_ppGeometryShader    = ppGeometryShader->GetPointer();
        auto out_hp_ppGeometryShader   = ppGeometryShader->GetHandlePointer();
        auto replay_result = replay_object->CreateGeometryShaderWithStreamOutput(pShaderBytecode->GetPointer(),
                                                                                 BytecodeLength,
                                                                                 pSODeclaration->GetPointer(),
                                                                                 NumEntries,
                                                                                 pBufferStrides->GetPointer(),
                                                                                 NumStrides,
                                                                                 RasterizedStream,
                                                                                 in_pClassLinkage,
                                                                                 out_hp_ppGeometryShader);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppGeometryShader, out_hp_ppGeometryShader, format::ApiCall_ID3D11Device_CreateGeometryShaderWithStreamOutput);
        }
        CheckReplayResult("ID3D11Device_CreateGeometryShaderWithStreamOutput", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreatePixelShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pShaderBytecode,
    SIZE_T                                      BytecodeLength,
    format::HandleId                            pClassLinkage,
    HandlePointerDecoder<ID3D11PixelShader*>*   ppPixelShader)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pClassLinkage = MapObject<ID3D11ClassLinkage>(pClassLinkage);
        if(!ppPixelShader->IsNull()) ppPixelShader->SetHandleLength(1);
        auto out_p_ppPixelShader    = ppPixelShader->GetPointer();
        auto out_hp_ppPixelShader   = ppPixelShader->GetHandlePointer();
        auto replay_result = replay_object->CreatePixelShader(pShaderBytecode->GetPointer(),
                                                              BytecodeLength,
                                                              in_pClassLinkage,
                                                              out_hp_ppPixelShader);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPixelShader, out_hp_ppPixelShader, format::ApiCall_ID3D11Device_CreatePixelShader);
        }
        CheckReplayResult("ID3D11Device_CreatePixelShader", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateHullShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pShaderBytecode,
    SIZE_T                                      BytecodeLength,
    format::HandleId                            pClassLinkage,
    HandlePointerDecoder<ID3D11HullShader*>*    ppHullShader)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pClassLinkage = MapObject<ID3D11ClassLinkage>(pClassLinkage);
        if(!ppHullShader->IsNull()) ppHullShader->SetHandleLength(1);
        auto out_p_ppHullShader    = ppHullShader->GetPointer();
        auto out_hp_ppHullShader   = ppHullShader->GetHandlePointer();
        auto replay_result = replay_object->CreateHullShader(pShaderBytecode->GetPointer(),
                                                             BytecodeLength,
                                                             in_pClassLinkage,
                                                             out_hp_ppHullShader);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppHullShader, out_hp_ppHullShader, format::ApiCall_ID3D11Device_CreateHullShader);
        }
        CheckReplayResult("ID3D11Device_CreateHullShader", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateDomainShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pShaderBytecode,
    SIZE_T                                      BytecodeLength,
    format::HandleId                            pClassLinkage,
    HandlePointerDecoder<ID3D11DomainShader*>*  ppDomainShader)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pClassLinkage = MapObject<ID3D11ClassLinkage>(pClassLinkage);
        if(!ppDomainShader->IsNull()) ppDomainShader->SetHandleLength(1);
        auto out_p_ppDomainShader    = ppDomainShader->GetPointer();
        auto out_hp_ppDomainShader   = ppDomainShader->GetHandlePointer();
        auto replay_result = replay_object->CreateDomainShader(pShaderBytecode->GetPointer(),
                                                               BytecodeLength,
                                                               in_pClassLinkage,
                                                               out_hp_ppDomainShader);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDomainShader, out_hp_ppDomainShader, format::ApiCall_ID3D11Device_CreateDomainShader);
        }
        CheckReplayResult("ID3D11Device_CreateDomainShader", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateComputeShader(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pShaderBytecode,
    SIZE_T                                      BytecodeLength,
    format::HandleId                            pClassLinkage,
    HandlePointerDecoder<ID3D11ComputeShader*>* ppComputeShader)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pClassLinkage = MapObject<ID3D11ClassLinkage>(pClassLinkage);
        if(!ppComputeShader->IsNull()) ppComputeShader->SetHandleLength(1);
        auto out_p_ppComputeShader    = ppComputeShader->GetPointer();
        auto out_hp_ppComputeShader   = ppComputeShader->GetHandlePointer();
        auto replay_result = replay_object->CreateComputeShader(pShaderBytecode->GetPointer(),
                                                                BytecodeLength,
                                                                in_pClassLinkage,
                                                                out_hp_ppComputeShader);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppComputeShader, out_hp_ppComputeShader, format::ApiCall_ID3D11Device_CreateComputeShader);
        }
        CheckReplayResult("ID3D11Device_CreateComputeShader", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateClassLinkage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<ID3D11ClassLinkage*>*  ppLinkage)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppLinkage->IsNull()) ppLinkage->SetHandleLength(1);
        auto out_p_ppLinkage    = ppLinkage->GetPointer();
        auto out_hp_ppLinkage   = ppLinkage->GetHandlePointer();
        auto replay_result = replay_object->CreateClassLinkage(out_hp_ppLinkage);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppLinkage, out_hp_ppLinkage, format::ApiCall_ID3D11Device_CreateClassLinkage);
        }
        CheckReplayResult("ID3D11Device_CreateClassLinkage", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateBlendState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_BLEND_DESC>* pBlendStateDesc,
    HandlePointerDecoder<ID3D11BlendState*>*    ppBlendState)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppBlendState->IsNull()) ppBlendState->SetHandleLength(1);
        auto out_p_ppBlendState    = ppBlendState->GetPointer();
        auto out_hp_ppBlendState   = ppBlendState->GetHandlePointer();
        auto replay_result = replay_object->CreateBlendState(pBlendStateDesc->GetPointer(),
                                                             out_hp_ppBlendState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppBlendState, out_hp_ppBlendState, format::ApiCall_ID3D11Device_CreateBlendState);
        }
        CheckReplayResult("ID3D11Device_CreateBlendState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateDepthStencilState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_DEPTH_STENCIL_DESC>* pDepthStencilDesc,
    HandlePointerDecoder<ID3D11DepthStencilState*>* ppDepthStencilState)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDepthStencilState->IsNull()) ppDepthStencilState->SetHandleLength(1);
        auto out_p_ppDepthStencilState    = ppDepthStencilState->GetPointer();
        auto out_hp_ppDepthStencilState   = ppDepthStencilState->GetHandlePointer();
        auto replay_result = replay_object->CreateDepthStencilState(pDepthStencilDesc->GetPointer(),
                                                                    out_hp_ppDepthStencilState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDepthStencilState, out_hp_ppDepthStencilState, format::ApiCall_ID3D11Device_CreateDepthStencilState);
        }
        CheckReplayResult("ID3D11Device_CreateDepthStencilState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateRasterizerState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_RASTERIZER_DESC>* pRasterizerDesc,
    HandlePointerDecoder<ID3D11RasterizerState*>* ppRasterizerState)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRasterizerState->IsNull()) ppRasterizerState->SetHandleLength(1);
        auto out_p_ppRasterizerState    = ppRasterizerState->GetPointer();
        auto out_hp_ppRasterizerState   = ppRasterizerState->GetHandlePointer();
        auto replay_result = replay_object->CreateRasterizerState(pRasterizerDesc->GetPointer(),
                                                                  out_hp_ppRasterizerState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppRasterizerState, out_hp_ppRasterizerState, format::ApiCall_ID3D11Device_CreateRasterizerState);
        }
        CheckReplayResult("ID3D11Device_CreateRasterizerState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateSamplerState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_SAMPLER_DESC>* pSamplerDesc,
    HandlePointerDecoder<ID3D11SamplerState*>*  ppSamplerState)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSamplerState->IsNull()) ppSamplerState->SetHandleLength(1);
        auto out_p_ppSamplerState    = ppSamplerState->GetPointer();
        auto out_hp_ppSamplerState   = ppSamplerState->GetHandlePointer();
        auto replay_result = replay_object->CreateSamplerState(pSamplerDesc->GetPointer(),
                                                               out_hp_ppSamplerState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSamplerState, out_hp_ppSamplerState, format::ApiCall_ID3D11Device_CreateSamplerState);
        }
        CheckReplayResult("ID3D11Device_CreateSamplerState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_QUERY_DESC>* pQueryDesc,
    HandlePointerDecoder<ID3D11Query*>*         ppQuery)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppQuery->IsNull()) ppQuery->SetHandleLength(1);
        auto out_p_ppQuery    = ppQuery->GetPointer();
        auto out_hp_ppQuery   = ppQuery->GetHandlePointer();
        auto replay_result = replay_object->CreateQuery(pQueryDesc->GetPointer(),
                                                        out_hp_ppQuery);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppQuery, out_hp_ppQuery, format::ApiCall_ID3D11Device_CreateQuery);
        }
        CheckReplayResult("ID3D11Device_CreateQuery", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreatePredicate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_QUERY_DESC>* pPredicateDesc,
    HandlePointerDecoder<ID3D11Predicate*>*     ppPredicate)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPredicate->IsNull()) ppPredicate->SetHandleLength(1);
        auto out_p_ppPredicate    = ppPredicate->GetPointer();
        auto out_hp_ppPredicate   = ppPredicate->GetHandlePointer();
        auto replay_result = replay_object->CreatePredicate(pPredicateDesc->GetPointer(),
                                                            out_hp_ppPredicate);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPredicate, out_hp_ppPredicate, format::ApiCall_ID3D11Device_CreatePredicate);
        }
        CheckReplayResult("ID3D11Device_CreatePredicate", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateCounter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_COUNTER_DESC>* pCounterDesc,
    HandlePointerDecoder<ID3D11Counter*>*       ppCounter)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppCounter->IsNull()) ppCounter->SetHandleLength(1);
        auto out_p_ppCounter    = ppCounter->GetPointer();
        auto out_hp_ppCounter   = ppCounter->GetHandlePointer();
        auto replay_result = replay_object->CreateCounter(pCounterDesc->GetPointer(),
                                                          out_hp_ppCounter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCounter, out_hp_ppCounter, format::ApiCall_ID3D11Device_CreateCounter);
        }
        CheckReplayResult("ID3D11Device_CreateCounter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CreateDeferredContext(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        ContextFlags,
    HandlePointerDecoder<ID3D11DeviceContext*>* ppDeferredContext)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDeferredContext->IsNull()) ppDeferredContext->SetHandleLength(1);
        auto out_p_ppDeferredContext    = ppDeferredContext->GetPointer();
        auto out_hp_ppDeferredContext   = ppDeferredContext->GetHandlePointer();
        auto replay_result = replay_object->CreateDeferredContext(ContextFlags,
                                                                  out_hp_ppDeferredContext);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDeferredContext, out_hp_ppDeferredContext, format::ApiCall_ID3D11Device_CreateDeferredContext);
        }
        CheckReplayResult("ID3D11Device_CreateDeferredContext", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_OpenSharedResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hResource,
    Decoded_GUID                                ReturnedInterface,
    HandlePointerDecoder<void*>*                ppResource)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hResource = static_cast<HANDLE>(PreProcessExternalObject(hResource, format::ApiCallId::ApiCall_ID3D11Device_OpenSharedResource, "ID3D11Device_OpenSharedResource"));
        if(!ppResource->IsNull()) ppResource->SetHandleLength(1);
        auto out_p_ppResource    = ppResource->GetPointer();
        auto out_hp_ppResource   = ppResource->GetHandlePointer();
        auto replay_result = replay_object->OpenSharedResource(in_hResource,
                                                               *ReturnedInterface.decoded_value,
                                                               out_hp_ppResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppResource, out_hp_ppResource, format::ApiCall_ID3D11Device_OpenSharedResource);
        }
        CheckReplayResult("ID3D11Device_OpenSharedResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CheckFormatSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 Format,
    PointerDecoder<UINT>*                       pFormatSupport)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFormatSupport->IsNull())
        {
            pFormatSupport->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckFormatSupport(Format,
                                                               pFormatSupport->GetOutputPointer());
        CheckReplayResult("ID3D11Device_CheckFormatSupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CheckMultisampleQualityLevels(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 Format,
    UINT                                        SampleCount,
    PointerDecoder<UINT>*                       pNumQualityLevels)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNumQualityLevels->IsNull())
        {
            pNumQualityLevels->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckMultisampleQualityLevels(Format,
                                                                          SampleCount,
                                                                          pNumQualityLevels->GetOutputPointer());
        CheckReplayResult("ID3D11Device_CheckMultisampleQualityLevels", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CheckCounterInfo(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_COUNTER_INFO>* pCounterInfo)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pCounterInfo->IsNull())
        {
            pCounterInfo->AllocateOutputData(1);
        }
        replay_object->CheckCounterInfo(pCounterInfo->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_CheckCounter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_COUNTER_DESC>* pDesc,
    PointerDecoder<D3D11_COUNTER_TYPE>*         pType,
    PointerDecoder<UINT>*                       pActiveCounters,
    StringDecoder*                              szName,
    PointerDecoder<UINT>*                       pNameLength,
    StringDecoder*                              szUnits,
    PointerDecoder<UINT>*                       pUnitsLength,
    StringDecoder*                              szDescription,
    PointerDecoder<UINT>*                       pDescriptionLength)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pType->IsNull())
        {
            pType->AllocateOutputData(1);
        }
        if(!pActiveCounters->IsNull())
        {
            pActiveCounters->AllocateOutputData(1);
        }
        if(!pNameLength->IsNull())
        {
            pNameLength->AllocateOutputData(1, GetOutputArrayCount("ID3D11Device::CheckCounter", return_value, object_id, VariableLengthArrayIndices::kD3D11DeviceArrayCheckCounter, pNameLength, szName));
        }
        if(!pUnitsLength->IsNull())
        {
            pUnitsLength->AllocateOutputData(1, GetOutputArrayCount("ID3D11Device::CheckCounter", return_value, object_id, VariableLengthArrayIndices::kD3D11DeviceArrayCheckCounter, pUnitsLength, szUnits));
        }
        if(!pDescriptionLength->IsNull())
        {
            pDescriptionLength->AllocateOutputData(1, GetOutputArrayCount("ID3D11Device::CheckCounter", return_value, object_id, VariableLengthArrayIndices::kD3D11DeviceArrayCheckCounter, pDescriptionLength, szDescription));
        }
        if(!szName->IsNull() && !pNameLength->IsNull())
        {
            szName->AllocateOutputData(*pNameLength->GetOutputPointer());
        }
        if(!szUnits->IsNull() && !pUnitsLength->IsNull())
        {
            szUnits->AllocateOutputData(*pUnitsLength->GetOutputPointer());
        }
        if(!szDescription->IsNull() && !pDescriptionLength->IsNull())
        {
            szDescription->AllocateOutputData(*pDescriptionLength->GetOutputPointer());
        }
        auto replay_result = replay_object->CheckCounter(pDesc->GetPointer(),
                                                         pType->GetOutputPointer(),
                                                         pActiveCounters->GetOutputPointer(),
                                                         szName->GetOutputPointer(),
                                                         pNameLength->GetOutputPointer(),
                                                         szUnits->GetOutputPointer(),
                                                         pUnitsLength->GetOutputPointer(),
                                                         szDescription->GetOutputPointer(),
                                                         pDescriptionLength->GetOutputPointer());
        if (szName->IsNull() && !pNameLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceArrayCheckCounter, *pNameLength->GetOutputPointer()); }
        if (szUnits->IsNull() && !pUnitsLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceArrayCheckCounter, *pUnitsLength->GetOutputPointer()); }
        if (szDescription->IsNull() && !pDescriptionLength->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceArrayCheckCounter, *pDescriptionLength->GetOutputPointer()); }
        CheckReplayResult("ID3D11Device_CheckCounter", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_GetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    PointerDecoder<UINT>*                       pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDataSize->IsNull())
        {
            pDataSize->AllocateOutputData(1, GetOutputArrayCount("ID3D11Device::GetPrivateData", return_value, object_id, VariableLengthArrayIndices::kD3D11DeviceArrayGetPrivateData, pDataSize, pData));
        }
        if(!pData->IsNull() && !pDataSize->IsNull())
        {
            pData->AllocateOutputData(*pDataSize->GetOutputPointer());
        }
        auto replay_result = replay_object->GetPrivateData(*guid.decoded_value,
                                                           pDataSize->GetOutputPointer(),
                                                           pData->GetOutputPointer());
        if (pData->IsNull() && !pDataSize->IsNull()) { SetOutputArrayCount(object_id, VariableLengthArrayIndices::kD3D11DeviceArrayGetPrivateData, *pDataSize->GetOutputPointer()); }
        CheckReplayResult("ID3D11Device_GetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_SetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPrivateData(*guid.decoded_value,
                                                           DataSize,
                                                           pData->GetPointer());
        CheckReplayResult("ID3D11Device_SetPrivateData", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_SetPrivateDataInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    format::HandleId                            pData)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pData = MapObject<IUnknown>(pData);
        auto replay_result = replay_object->SetPrivateDataInterface(*guid.decoded_value,
                                                                    in_pData);
        CheckReplayResult("ID3D11Device_SetPrivateDataInterface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_GetFeatureLevel(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D_FEATURE_LEVEL                           return_value)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFeatureLevel();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_GetCreationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCreationFlags();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_GetDeviceRemovedReason(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDeviceRemovedReason();
        CheckReplayResult("ID3D11Device_GetDeviceRemovedReason", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_GetImmediateContext(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11DeviceContext*>* ppImmediateContext)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppImmediateContext->IsNull()) ppImmediateContext->SetHandleLength(1);
        auto out_p_ppImmediateContext    = ppImmediateContext->GetPointer();
        auto out_hp_ppImmediateContext   = ppImmediateContext->GetHandlePointer();
        replay_object->GetImmediateContext(out_hp_ppImmediateContext);
        AddObject(out_p_ppImmediateContext, out_hp_ppImmediateContext, format::ApiCall_ID3D11Device_GetImmediateContext);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_SetExceptionMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        RaiseFlags)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetExceptionMode(RaiseFlags);
        CheckReplayResult("ID3D11Device_SetExceptionMode", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device_GetExceptionMode(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = MapObject<ID3D11Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetExceptionMode();
    }
}

void Dx12ReplayConsumer::Process_ID3D11BlendState1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_BLEND_DESC1>* pDesc)
{
    auto replay_object = MapObject<ID3D11BlendState1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11RasterizerState1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_RASTERIZER_DESC1>* pDesc)
{
    auto replay_object = MapObject<ID3D11RasterizerState1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_CopySubresourceRegion1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    UINT                                        DstSubresource,
    UINT                                        DstX,
    UINT                                        DstY,
    UINT                                        DstZ,
    format::HandleId                            pSrcResource,
    UINT                                        SrcSubresource,
    StructPointerDecoder<Decoded_D3D11_BOX>*    pSrcBox,
    UINT                                        CopyFlags)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D11Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D11Resource>(pSrcResource);
        replay_object->CopySubresourceRegion1(in_pDstResource,
                                              DstSubresource,
                                              DstX,
                                              DstY,
                                              DstZ,
                                              in_pSrcResource,
                                              SrcSubresource,
                                              pSrcBox->GetPointer(),
                                              CopyFlags);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_DiscardResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        replay_object->DiscardResource(in_pResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_DiscardView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResourceView)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResourceView = MapObject<ID3D11View>(pResourceView);
        replay_object->DiscardView(in_pResourceView);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_VSSetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->VSSetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             in_ppConstantBuffers,
                                             pFirstConstant->GetPointer(),
                                             pNumConstants->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_HSSetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->HSSetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             in_ppConstantBuffers,
                                             pFirstConstant->GetPointer(),
                                             pNumConstants->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_DSSetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->DSSetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             in_ppConstantBuffers,
                                             pFirstConstant->GetPointer(),
                                             pNumConstants->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_GSSetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->GSSetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             in_ppConstantBuffers,
                                             pFirstConstant->GetPointer(),
                                             pNumConstants->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_PSSetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->PSSetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             in_ppConstantBuffers,
                                             pFirstConstant->GetPointer(),
                                             pNumConstants->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_CSSetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppConstantBuffers = MapObjects<ID3D11Buffer>(ppConstantBuffers, NumBuffers);
        replay_object->CSSetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             in_ppConstantBuffers,
                                             pFirstConstant->GetPointer(),
                                             pNumConstants->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_VSGetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        if(!pFirstConstant->IsNull())
        {
            pFirstConstant->AllocateOutputData(NumBuffers);
        }
        if(!pNumConstants->IsNull())
        {
            pNumConstants->AllocateOutputData(NumBuffers);
        }
        replay_object->VSGetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             out_hp_ppConstantBuffers,
                                             pFirstConstant->GetOutputPointer(),
                                             pNumConstants->GetOutputPointer());
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext1_VSGetConstantBuffers1);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_HSGetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        if(!pFirstConstant->IsNull())
        {
            pFirstConstant->AllocateOutputData(NumBuffers);
        }
        if(!pNumConstants->IsNull())
        {
            pNumConstants->AllocateOutputData(NumBuffers);
        }
        replay_object->HSGetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             out_hp_ppConstantBuffers,
                                             pFirstConstant->GetOutputPointer(),
                                             pNumConstants->GetOutputPointer());
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext1_HSGetConstantBuffers1);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_DSGetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        if(!pFirstConstant->IsNull())
        {
            pFirstConstant->AllocateOutputData(NumBuffers);
        }
        if(!pNumConstants->IsNull())
        {
            pNumConstants->AllocateOutputData(NumBuffers);
        }
        replay_object->DSGetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             out_hp_ppConstantBuffers,
                                             pFirstConstant->GetOutputPointer(),
                                             pNumConstants->GetOutputPointer());
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext1_DSGetConstantBuffers1);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_GSGetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        if(!pFirstConstant->IsNull())
        {
            pFirstConstant->AllocateOutputData(NumBuffers);
        }
        if(!pNumConstants->IsNull())
        {
            pNumConstants->AllocateOutputData(NumBuffers);
        }
        replay_object->GSGetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             out_hp_ppConstantBuffers,
                                             pFirstConstant->GetOutputPointer(),
                                             pNumConstants->GetOutputPointer());
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext1_GSGetConstantBuffers1);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_PSGetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        if(!pFirstConstant->IsNull())
        {
            pFirstConstant->AllocateOutputData(NumBuffers);
        }
        if(!pNumConstants->IsNull())
        {
            pNumConstants->AllocateOutputData(NumBuffers);
        }
        replay_object->PSGetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             out_hp_ppConstantBuffers,
                                             pFirstConstant->GetOutputPointer(),
                                             pNumConstants->GetOutputPointer());
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext1_PSGetConstantBuffers1);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_CSGetConstantBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumBuffers,
    HandlePointerDecoder<ID3D11Buffer*>*        ppConstantBuffers,
    PointerDecoder<UINT>*                       pFirstConstant,
    PointerDecoder<UINT>*                       pNumConstants)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppConstantBuffers->IsNull()) ppConstantBuffers->SetHandleLength(NumBuffers);
        auto out_p_ppConstantBuffers    = ppConstantBuffers->GetPointer();
        auto out_hp_ppConstantBuffers   = ppConstantBuffers->GetHandlePointer();
        if(!pFirstConstant->IsNull())
        {
            pFirstConstant->AllocateOutputData(NumBuffers);
        }
        if(!pNumConstants->IsNull())
        {
            pNumConstants->AllocateOutputData(NumBuffers);
        }
        replay_object->CSGetConstantBuffers1(StartSlot,
                                             NumBuffers,
                                             out_hp_ppConstantBuffers,
                                             pFirstConstant->GetOutputPointer(),
                                             pNumConstants->GetOutputPointer());
        AddObjects(out_p_ppConstantBuffers, ppConstantBuffers->GetLength(), out_hp_ppConstantBuffers, NumBuffers, format::ApiCall_ID3D11DeviceContext1_CSGetConstantBuffers1);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_SwapDeviceContextState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pState,
    HandlePointerDecoder<ID3DDeviceContextState*>* ppPreviousState)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pState = MapObject<ID3DDeviceContextState>(pState);
        if(!ppPreviousState->IsNull()) ppPreviousState->SetHandleLength(1);
        auto out_p_ppPreviousState    = ppPreviousState->GetPointer();
        auto out_hp_ppPreviousState   = ppPreviousState->GetHandlePointer();
        replay_object->SwapDeviceContextState(in_pState,
                                              out_hp_ppPreviousState);
        AddObject(out_p_ppPreviousState, out_hp_ppPreviousState, format::ApiCall_ID3D11DeviceContext1_SwapDeviceContextState);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_ClearView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pView,
    PointerDecoder<FLOAT>*                      Color,
    StructPointerDecoder<Decoded_tagRECT>*      pRect,
    UINT                                        NumRects)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pView = MapObject<ID3D11View>(pView);
        replay_object->ClearView(in_pView,
                                 Color->GetPointer(),
                                 pRect->GetPointer(),
                                 NumRects);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext1_DiscardView1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResourceView,
    StructPointerDecoder<Decoded_tagRECT>*      pRects,
    UINT                                        NumRects)
{
    auto replay_object = MapObject<ID3D11DeviceContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResourceView = MapObject<ID3D11View>(pResourceView);
        replay_object->DiscardView1(in_pResourceView,
                                    pRects->GetPointer(),
                                    NumRects);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_SubmitDecoderBuffers1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    UINT                                        NumBuffers,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC1>* pBufferDesc)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto replay_result = replay_object->SubmitDecoderBuffers1(in_pDecoder,
                                                                  NumBuffers,
                                                                  pBufferDesc->GetPointer());
        CheckReplayResult("ID3D11VideoContext1_SubmitDecoderBuffers1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_GetDataForNewHardwareKey(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pCryptoSession,
    UINT                                        PrivateInputSize,
    PointerDecoder<uint8_t>*                    pPrivatInputData,
    PointerDecoder<UINT64>*                     pPrivateOutputData)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        if(!pPrivateOutputData->IsNull())
        {
            pPrivateOutputData->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetDataForNewHardwareKey(in_pCryptoSession,
                                                                     PrivateInputSize,
                                                                     pPrivatInputData->GetPointer(),
                                                                     pPrivateOutputData->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext1_GetDataForNewHardwareKey", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_CheckCryptoSessionStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pCryptoSession,
    PointerDecoder<D3D11_CRYPTO_SESSION_STATUS>* pStatus)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        if(!pStatus->IsNull())
        {
            pStatus->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckCryptoSessionStatus(in_pCryptoSession,
                                                                     pStatus->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext1_CheckCryptoSessionStatus", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_DecoderEnableDownsampling(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    DXGI_COLOR_SPACE_TYPE                       InputColorSpace,
    StructPointerDecoder<Decoded_D3D11_VIDEO_SAMPLE_DESC>* pOutputDesc,
    UINT                                        ReferenceFrameCount)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto replay_result = replay_object->DecoderEnableDownsampling(in_pDecoder,
                                                                      InputColorSpace,
                                                                      pOutputDesc->GetPointer(),
                                                                      ReferenceFrameCount);
        CheckReplayResult("ID3D11VideoContext1_DecoderEnableDownsampling", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_DecoderUpdateDownsampling(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    StructPointerDecoder<Decoded_D3D11_VIDEO_SAMPLE_DESC>* pOutputDesc)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto replay_result = replay_object->DecoderUpdateDownsampling(in_pDecoder,
                                                                      pOutputDesc->GetPointer());
        CheckReplayResult("ID3D11VideoContext1_DecoderUpdateDownsampling", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorSetOutputColorSpace1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputColorSpace1(in_pVideoProcessor,
                                                          ColorSpace);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorSetOutputShaderUsage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    BOOL                                        ShaderUsage)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputShaderUsage(in_pVideoProcessor,
                                                          ShaderUsage);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorGetOutputColorSpace1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<DXGI_COLOR_SPACE_TYPE>*      pColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pColorSpace->IsNull())
        {
            pColorSpace->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputColorSpace1(in_pVideoProcessor,
                                                          pColorSpace->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorGetOutputShaderUsage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<BOOL>*                       pShaderUsage)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pShaderUsage->IsNull())
        {
            pShaderUsage->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetOutputShaderUsage(in_pVideoProcessor,
                                                          pShaderUsage->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorSetStreamColorSpace1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamColorSpace1(in_pVideoProcessor,
                                                          StreamIndex,
                                                          ColorSpace);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorSetStreamMirror(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    BOOL                                        Enable,
    BOOL                                        FlipHorizontal,
    BOOL                                        FlipVertical)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamMirror(in_pVideoProcessor,
                                                     StreamIndex,
                                                     Enable,
                                                     FlipHorizontal,
                                                     FlipVertical);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorGetStreamColorSpace1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<DXGI_COLOR_SPACE_TYPE>*      pColorSpace)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pColorSpace->IsNull())
        {
            pColorSpace->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamColorSpace1(in_pVideoProcessor,
                                                          StreamIndex,
                                                          pColorSpace->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorGetStreamMirror(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<BOOL>*                       pEnable,
    PointerDecoder<BOOL>*                       pFlipHorizontal,
    PointerDecoder<BOOL>*                       pFlipVertical)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pEnable->IsNull())
        {
            pEnable->AllocateOutputData(1);
        }
        if(!pFlipHorizontal->IsNull())
        {
            pFlipHorizontal->AllocateOutputData(1);
        }
        if(!pFlipVertical->IsNull())
        {
            pFlipVertical->AllocateOutputData(1);
        }
        replay_object->VideoProcessorGetStreamMirror(in_pVideoProcessor,
                                                     StreamIndex,
                                                     pEnable->GetOutputPointer(),
                                                     pFlipHorizontal->GetOutputPointer(),
                                                     pFlipVertical->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext1_VideoProcessorGetBehaviorHints(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pVideoProcessor,
    UINT                                        OutputWidth,
    UINT                                        OutputHeight,
    DXGI_FORMAT                                 OutputFormat,
    UINT                                        StreamCount,
    StructPointerDecoder<Decoded_D3D11_VIDEO_PROCESSOR_STREAM_BEHAVIOR_HINT>* pStreams,
    PointerDecoder<UINT>*                       pBehaviorHints)
{
    auto replay_object = MapObject<ID3D11VideoContext1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pBehaviorHints->IsNull())
        {
            pBehaviorHints->AllocateOutputData(1);
        }
        auto replay_result = replay_object->VideoProcessorGetBehaviorHints(in_pVideoProcessor,
                                                                           OutputWidth,
                                                                           OutputHeight,
                                                                           OutputFormat,
                                                                           StreamCount,
                                                                           pStreams->GetPointer(),
                                                                           pBehaviorHints->GetOutputPointer());
        CheckReplayResult("ID3D11VideoContext1_VideoProcessorGetBehaviorHints", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice1_GetCryptoSessionPrivateDataSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pCryptoType,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile,
    StructPointerDecoder<Decoded_GUID>*         pKeyExchangeType,
    PointerDecoder<UINT>*                       pPrivateInputSize,
    PointerDecoder<UINT>*                       pPrivateOutputSize)
{
    auto replay_object = MapObject<ID3D11VideoDevice1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pPrivateInputSize->IsNull())
        {
            pPrivateInputSize->AllocateOutputData(1);
        }
        if(!pPrivateOutputSize->IsNull())
        {
            pPrivateOutputSize->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetCryptoSessionPrivateDataSize(pCryptoType->GetPointer(),
                                                                            pDecoderProfile->GetPointer(),
                                                                            pKeyExchangeType->GetPointer(),
                                                                            pPrivateInputSize->GetOutputPointer(),
                                                                            pPrivateOutputSize->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice1_GetCryptoSessionPrivateDataSize", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice1_GetVideoDecoderCaps(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pDecoderProfile,
    UINT                                        SampleWidth,
    UINT                                        SampleHeight,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pFrameRate,
    UINT                                        BitRate,
    StructPointerDecoder<Decoded_GUID>*         pCryptoType,
    PointerDecoder<UINT>*                       pDecoderCaps)
{
    auto replay_object = MapObject<ID3D11VideoDevice1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDecoderCaps->IsNull())
        {
            pDecoderCaps->AllocateOutputData(1);
        }
        auto replay_result = replay_object->GetVideoDecoderCaps(pDecoderProfile->GetPointer(),
                                                                SampleWidth,
                                                                SampleHeight,
                                                                pFrameRate->GetPointer(),
                                                                BitRate,
                                                                pCryptoType->GetPointer(),
                                                                pDecoderCaps->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice1_GetVideoDecoderCaps", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice1_CheckVideoDecoderDownsampling(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_DESC>* pInputDesc,
    DXGI_COLOR_SPACE_TYPE                       InputColorSpace,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_CONFIG>* pInputConfig,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pFrameRate,
    StructPointerDecoder<Decoded_D3D11_VIDEO_SAMPLE_DESC>* pOutputDesc,
    PointerDecoder<BOOL>*                       pSupported,
    PointerDecoder<BOOL>*                       pRealTimeHint)
{
    auto replay_object = MapObject<ID3D11VideoDevice1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pSupported->IsNull())
        {
            pSupported->AllocateOutputData(1);
        }
        if(!pRealTimeHint->IsNull())
        {
            pRealTimeHint->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckVideoDecoderDownsampling(pInputDesc->GetPointer(),
                                                                          InputColorSpace,
                                                                          pInputConfig->GetPointer(),
                                                                          pFrameRate->GetPointer(),
                                                                          pOutputDesc->GetPointer(),
                                                                          pSupported->GetOutputPointer(),
                                                                          pRealTimeHint->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice1_CheckVideoDecoderDownsampling", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice1_RecommendVideoDecoderDownsampleParameters(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_DESC>* pInputDesc,
    DXGI_COLOR_SPACE_TYPE                       InputColorSpace,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_CONFIG>* pInputConfig,
    StructPointerDecoder<Decoded_DXGI_RATIONAL>* pFrameRate,
    StructPointerDecoder<Decoded_D3D11_VIDEO_SAMPLE_DESC>* pRecommendedOutputDesc)
{
    auto replay_object = MapObject<ID3D11VideoDevice1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pRecommendedOutputDesc->IsNull())
        {
            pRecommendedOutputDesc->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RecommendVideoDecoderDownsampleParameters(pInputDesc->GetPointer(),
                                                                                      InputColorSpace,
                                                                                      pInputConfig->GetPointer(),
                                                                                      pFrameRate->GetPointer(),
                                                                                      pRecommendedOutputDesc->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice1_RecommendVideoDecoderDownsampleParameters", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoProcessorEnumerator1_CheckVideoProcessorFormatConversion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 InputFormat,
    DXGI_COLOR_SPACE_TYPE                       InputColorSpace,
    DXGI_FORMAT                                 OutputFormat,
    DXGI_COLOR_SPACE_TYPE                       OutputColorSpace,
    PointerDecoder<BOOL>*                       pSupported)
{
    auto replay_object = MapObject<ID3D11VideoProcessorEnumerator1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pSupported->IsNull())
        {
            pSupported->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckVideoProcessorFormatConversion(InputFormat,
                                                                                InputColorSpace,
                                                                                OutputFormat,
                                                                                OutputColorSpace,
                                                                                pSupported->GetOutputPointer());
        CheckReplayResult("ID3D11VideoProcessorEnumerator1_CheckVideoProcessorFormatConversion", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device1_GetImmediateContext1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11DeviceContext1*>* ppImmediateContext)
{
    auto replay_object = MapObject<ID3D11Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppImmediateContext->IsNull()) ppImmediateContext->SetHandleLength(1);
        auto out_p_ppImmediateContext    = ppImmediateContext->GetPointer();
        auto out_hp_ppImmediateContext   = ppImmediateContext->GetHandlePointer();
        replay_object->GetImmediateContext1(out_hp_ppImmediateContext);
        AddObject(out_p_ppImmediateContext, out_hp_ppImmediateContext, format::ApiCall_ID3D11Device1_GetImmediateContext1);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device1_CreateDeferredContext1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        ContextFlags,
    HandlePointerDecoder<ID3D11DeviceContext1*>* ppDeferredContext)
{
    auto replay_object = MapObject<ID3D11Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDeferredContext->IsNull()) ppDeferredContext->SetHandleLength(1);
        auto out_p_ppDeferredContext    = ppDeferredContext->GetPointer();
        auto out_hp_ppDeferredContext   = ppDeferredContext->GetHandlePointer();
        auto replay_result = replay_object->CreateDeferredContext1(ContextFlags,
                                                                   out_hp_ppDeferredContext);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDeferredContext, out_hp_ppDeferredContext, format::ApiCall_ID3D11Device1_CreateDeferredContext1);
        }
        CheckReplayResult("ID3D11Device1_CreateDeferredContext1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device1_CreateBlendState1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_BLEND_DESC1>* pBlendStateDesc,
    HandlePointerDecoder<ID3D11BlendState1*>*   ppBlendState)
{
    auto replay_object = MapObject<ID3D11Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppBlendState->IsNull()) ppBlendState->SetHandleLength(1);
        auto out_p_ppBlendState    = ppBlendState->GetPointer();
        auto out_hp_ppBlendState   = ppBlendState->GetHandlePointer();
        auto replay_result = replay_object->CreateBlendState1(pBlendStateDesc->GetPointer(),
                                                              out_hp_ppBlendState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppBlendState, out_hp_ppBlendState, format::ApiCall_ID3D11Device1_CreateBlendState1);
        }
        CheckReplayResult("ID3D11Device1_CreateBlendState1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device1_CreateRasterizerState1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_RASTERIZER_DESC1>* pRasterizerDesc,
    HandlePointerDecoder<ID3D11RasterizerState1*>* ppRasterizerState)
{
    auto replay_object = MapObject<ID3D11Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRasterizerState->IsNull()) ppRasterizerState->SetHandleLength(1);
        auto out_p_ppRasterizerState    = ppRasterizerState->GetPointer();
        auto out_hp_ppRasterizerState   = ppRasterizerState->GetHandlePointer();
        auto replay_result = replay_object->CreateRasterizerState1(pRasterizerDesc->GetPointer(),
                                                                   out_hp_ppRasterizerState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppRasterizerState, out_hp_ppRasterizerState, format::ApiCall_ID3D11Device1_CreateRasterizerState1);
        }
        CheckReplayResult("ID3D11Device1_CreateRasterizerState1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device1_CreateDeviceContextState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Flags,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pFeatureLevels,
    UINT                                        FeatureLevels,
    UINT                                        SDKVersion,
    Decoded_GUID                                EmulatedInterface,
    PointerDecoder<D3D_FEATURE_LEVEL>*          pChosenFeatureLevel,
    HandlePointerDecoder<ID3DDeviceContextState*>* ppContextState)
{
    auto replay_object = MapObject<ID3D11Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pChosenFeatureLevel->IsNull())
        {
            pChosenFeatureLevel->AllocateOutputData(1);
        }
        if(!ppContextState->IsNull()) ppContextState->SetHandleLength(1);
        auto out_p_ppContextState    = ppContextState->GetPointer();
        auto out_hp_ppContextState   = ppContextState->GetHandlePointer();
        auto replay_result = replay_object->CreateDeviceContextState(Flags,
                                                                     pFeatureLevels->GetPointer(),
                                                                     FeatureLevels,
                                                                     SDKVersion,
                                                                     *EmulatedInterface.decoded_value,
                                                                     pChosenFeatureLevel->GetOutputPointer(),
                                                                     out_hp_ppContextState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppContextState, out_hp_ppContextState, format::ApiCall_ID3D11Device1_CreateDeviceContextState);
        }
        CheckReplayResult("ID3D11Device1_CreateDeviceContextState", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device1_OpenSharedResource1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hResource,
    Decoded_GUID                                returnedInterface,
    HandlePointerDecoder<void*>*                ppResource)
{
    auto replay_object = MapObject<ID3D11Device1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hResource = static_cast<HANDLE>(PreProcessExternalObject(hResource, format::ApiCallId::ApiCall_ID3D11Device1_OpenSharedResource1, "ID3D11Device1_OpenSharedResource1"));
        if(!ppResource->IsNull()) ppResource->SetHandleLength(1);
        auto out_p_ppResource    = ppResource->GetPointer();
        auto out_hp_ppResource   = ppResource->GetHandlePointer();
        auto replay_result = replay_object->OpenSharedResource1(in_hResource,
                                                                *returnedInterface.decoded_value,
                                                                out_hp_ppResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppResource, out_hp_ppResource, format::ApiCall_ID3D11Device1_OpenSharedResource1);
        }
        CheckReplayResult("ID3D11Device1_OpenSharedResource1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device1_OpenSharedResourceByName(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             lpName,
    DWORD                                       dwDesiredAccess,
    Decoded_GUID                                returnedInterface,
    HandlePointerDecoder<void*>*                ppResource)
{
    auto replay_object = MapObject<ID3D11Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppResource->IsNull()) ppResource->SetHandleLength(1);
        auto out_p_ppResource    = ppResource->GetPointer();
        auto out_hp_ppResource   = ppResource->GetHandlePointer();
        auto replay_result = replay_object->OpenSharedResourceByName(lpName->GetPointer(),
                                                                     dwDesiredAccess,
                                                                     *returnedInterface.decoded_value,
                                                                     out_hp_ppResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppResource, out_hp_ppResource, format::ApiCall_ID3D11Device1_OpenSharedResourceByName);
        }
        CheckReplayResult("ID3D11Device1_OpenSharedResourceByName", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3DUserDefinedAnnotation_BeginEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    INT                                         return_value,
    WStringDecoder*                             Name)
{
    auto replay_object = MapObject<ID3DUserDefinedAnnotation>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->BeginEvent(Name->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3DUserDefinedAnnotation_EndEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    INT                                         return_value)
{
    auto replay_object = MapObject<ID3DUserDefinedAnnotation>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->EndEvent();
    }
}

void Dx12ReplayConsumer::Process_ID3DUserDefinedAnnotation_SetMarker(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    WStringDecoder*                             Name)
{
    auto replay_object = MapObject<ID3DUserDefinedAnnotation>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetMarker(Name->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3DUserDefinedAnnotation_GetStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<ID3DUserDefinedAnnotation>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetStatus();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_UpdateTileMappings(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pTiledResource,
    UINT                                        NumTiledResourceRegions,
    StructPointerDecoder<Decoded_D3D11_TILED_RESOURCE_COORDINATE>* pTiledResourceRegionStartCoordinates,
    StructPointerDecoder<Decoded_D3D11_TILE_REGION_SIZE>* pTiledResourceRegionSizes,
    format::HandleId                            pTilePool,
    UINT                                        NumRanges,
    PointerDecoder<UINT>*                       pRangeFlags,
    PointerDecoder<UINT>*                       pTilePoolStartOffsets,
    PointerDecoder<UINT>*                       pRangeTileCounts,
    UINT                                        Flags)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTiledResource = MapObject<ID3D11Resource>(pTiledResource);
        auto in_pTilePool = MapObject<ID3D11Buffer>(pTilePool);
        auto replay_result = replay_object->UpdateTileMappings(in_pTiledResource,
                                                               NumTiledResourceRegions,
                                                               pTiledResourceRegionStartCoordinates->GetPointer(),
                                                               pTiledResourceRegionSizes->GetPointer(),
                                                               in_pTilePool,
                                                               NumRanges,
                                                               pRangeFlags->GetPointer(),
                                                               pTilePoolStartOffsets->GetPointer(),
                                                               pRangeTileCounts->GetPointer(),
                                                               Flags);
        CheckReplayResult("ID3D11DeviceContext2_UpdateTileMappings", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_CopyTileMappings(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDestTiledResource,
    StructPointerDecoder<Decoded_D3D11_TILED_RESOURCE_COORDINATE>* pDestRegionStartCoordinate,
    format::HandleId                            pSourceTiledResource,
    StructPointerDecoder<Decoded_D3D11_TILED_RESOURCE_COORDINATE>* pSourceRegionStartCoordinate,
    StructPointerDecoder<Decoded_D3D11_TILE_REGION_SIZE>* pTileRegionSize,
    UINT                                        Flags)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDestTiledResource = MapObject<ID3D11Resource>(pDestTiledResource);
        auto in_pSourceTiledResource = MapObject<ID3D11Resource>(pSourceTiledResource);
        auto replay_result = replay_object->CopyTileMappings(in_pDestTiledResource,
                                                             pDestRegionStartCoordinate->GetPointer(),
                                                             in_pSourceTiledResource,
                                                             pSourceRegionStartCoordinate->GetPointer(),
                                                             pTileRegionSize->GetPointer(),
                                                             Flags);
        CheckReplayResult("ID3D11DeviceContext2_CopyTileMappings", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_CopyTiles(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pTiledResource,
    StructPointerDecoder<Decoded_D3D11_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
    StructPointerDecoder<Decoded_D3D11_TILE_REGION_SIZE>* pTileRegionSize,
    format::HandleId                            pBuffer,
    UINT64                                      BufferStartOffsetInBytes,
    UINT                                        Flags)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTiledResource = MapObject<ID3D11Resource>(pTiledResource);
        auto in_pBuffer = MapObject<ID3D11Buffer>(pBuffer);
        replay_object->CopyTiles(in_pTiledResource,
                                 pTileRegionStartCoordinate->GetPointer(),
                                 pTileRegionSize->GetPointer(),
                                 in_pBuffer,
                                 BufferStartOffsetInBytes,
                                 Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_UpdateTiles(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pDestTiledResource,
    StructPointerDecoder<Decoded_D3D11_TILED_RESOURCE_COORDINATE>* pDestTileRegionStartCoordinate,
    StructPointerDecoder<Decoded_D3D11_TILE_REGION_SIZE>* pDestTileRegionSize,
    uint64_t                                    pSourceTileData,
    UINT                                        Flags)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDestTiledResource = MapObject<ID3D11Resource>(pDestTiledResource);
        auto in_pSourceTileData = PreProcessExternalObject(pSourceTileData, format::ApiCallId::ApiCall_ID3D11DeviceContext2_UpdateTiles, "ID3D11DeviceContext2_UpdateTiles");
        replay_object->UpdateTiles(in_pDestTiledResource,
                                   pDestTileRegionStartCoordinate->GetPointer(),
                                   pDestTileRegionSize->GetPointer(),
                                   in_pSourceTileData,
                                   Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_ResizeTilePool(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pTilePool,
    UINT64                                      NewSizeInBytes)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTilePool = MapObject<ID3D11Buffer>(pTilePool);
        auto replay_result = replay_object->ResizeTilePool(in_pTilePool,
                                                           NewSizeInBytes);
        CheckReplayResult("ID3D11DeviceContext2_ResizeTilePool", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_TiledResourceBarrier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pTiledResourceOrViewAccessBeforeBarrier,
    format::HandleId                            pTiledResourceOrViewAccessAfterBarrier)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTiledResourceOrViewAccessBeforeBarrier = MapObject<ID3D11DeviceChild>(pTiledResourceOrViewAccessBeforeBarrier);
        auto in_pTiledResourceOrViewAccessAfterBarrier = MapObject<ID3D11DeviceChild>(pTiledResourceOrViewAccessAfterBarrier);
        replay_object->TiledResourceBarrier(in_pTiledResourceOrViewAccessBeforeBarrier,
                                            in_pTiledResourceOrViewAccessAfterBarrier);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_IsAnnotationEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsAnnotationEnabled();
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_SetMarkerInt(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    WStringDecoder*                             pLabel,
    INT                                         Data)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetMarkerInt(pLabel->GetPointer(),
                                    Data);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_BeginEventInt(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    WStringDecoder*                             pLabel,
    INT                                         Data)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginEventInt(pLabel->GetPointer(),
                                     Data);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext2_EndEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D11DeviceContext2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndEvent();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device2_GetImmediateContext2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11DeviceContext2*>* ppImmediateContext)
{
    auto replay_object = MapObject<ID3D11Device2>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppImmediateContext->IsNull()) ppImmediateContext->SetHandleLength(1);
        auto out_p_ppImmediateContext    = ppImmediateContext->GetPointer();
        auto out_hp_ppImmediateContext   = ppImmediateContext->GetHandlePointer();
        replay_object->GetImmediateContext2(out_hp_ppImmediateContext);
        AddObject(out_p_ppImmediateContext, out_hp_ppImmediateContext, format::ApiCall_ID3D11Device2_GetImmediateContext2);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device2_CreateDeferredContext2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        ContextFlags,
    HandlePointerDecoder<ID3D11DeviceContext2*>* ppDeferredContext)
{
    auto replay_object = MapObject<ID3D11Device2>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDeferredContext->IsNull()) ppDeferredContext->SetHandleLength(1);
        auto out_p_ppDeferredContext    = ppDeferredContext->GetPointer();
        auto out_hp_ppDeferredContext   = ppDeferredContext->GetHandlePointer();
        auto replay_result = replay_object->CreateDeferredContext2(ContextFlags,
                                                                   out_hp_ppDeferredContext);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDeferredContext, out_hp_ppDeferredContext, format::ApiCall_ID3D11Device2_CreateDeferredContext2);
        }
        CheckReplayResult("ID3D11Device2_CreateDeferredContext2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device2_GetResourceTiling(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pTiledResource,
    PointerDecoder<UINT>*                       pNumTilesForEntireResource,
    StructPointerDecoder<Decoded_D3D11_PACKED_MIP_DESC>* pPackedMipDesc,
    StructPointerDecoder<Decoded_D3D11_TILE_SHAPE>* pStandardTileShapeForNonPackedMips,
    PointerDecoder<UINT>*                       pNumSubresourceTilings,
    UINT                                        FirstSubresourceTilingToGet,
    StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_TILING>* pSubresourceTilingsForNonPackedMips)
{
    auto replay_object = MapObject<ID3D11Device2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTiledResource = MapObject<ID3D11Resource>(pTiledResource);
        if(!pNumTilesForEntireResource->IsNull())
        {
            pNumTilesForEntireResource->AllocateOutputData(1);
        }
        if(!pPackedMipDesc->IsNull())
        {
            pPackedMipDesc->AllocateOutputData(1);
        }
        if(!pStandardTileShapeForNonPackedMips->IsNull())
        {
            pStandardTileShapeForNonPackedMips->AllocateOutputData(1);
        }
        if(!pNumSubresourceTilings->IsNull())
        {
            pNumSubresourceTilings->AllocateOutputData(1);
        }
        if(!pSubresourceTilingsForNonPackedMips->IsNull())
        {
            pSubresourceTilingsForNonPackedMips->AllocateOutputData(!pNumSubresourceTilings->IsNull() ? *pNumSubresourceTilings->GetPointer() : 0);
        }
        replay_object->GetResourceTiling(in_pTiledResource,
                                         pNumTilesForEntireResource->GetOutputPointer(),
                                         pPackedMipDesc->GetOutputPointer(),
                                         pStandardTileShapeForNonPackedMips->GetOutputPointer(),
                                         pNumSubresourceTilings->GetOutputPointer(),
                                         FirstSubresourceTilingToGet,
                                         pSubresourceTilingsForNonPackedMips->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device2_CheckMultisampleQualityLevels1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_FORMAT                                 Format,
    UINT                                        SampleCount,
    UINT                                        Flags,
    PointerDecoder<UINT>*                       pNumQualityLevels)
{
    auto replay_object = MapObject<ID3D11Device2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNumQualityLevels->IsNull())
        {
            pNumQualityLevels->AllocateOutputData(1);
        }
        auto replay_result = replay_object->CheckMultisampleQualityLevels1(Format,
                                                                           SampleCount,
                                                                           Flags,
                                                                           pNumQualityLevels->GetOutputPointer());
        CheckReplayResult("ID3D11Device2_CheckMultisampleQualityLevels1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Texture2D1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC1>* pDesc)
{
    auto replay_object = MapObject<ID3D11Texture2D1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Texture3D1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC1>* pDesc)
{
    auto replay_object = MapObject<ID3D11Texture3D1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11RasterizerState2_GetDesc2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_RASTERIZER_DESC2>* pDesc)
{
    auto replay_object = MapObject<ID3D11RasterizerState2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc->IsNull())
        {
            pDesc->AllocateOutputData(1);
        }
        replay_object->GetDesc2(pDesc->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11ShaderResourceView1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC1>* pDesc1)
{
    auto replay_object = MapObject<ID3D11ShaderResourceView1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc1->IsNull())
        {
            pDesc1->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc1->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11RenderTargetView1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_RENDER_TARGET_VIEW_DESC1>* pDesc1)
{
    auto replay_object = MapObject<ID3D11RenderTargetView1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc1->IsNull())
        {
            pDesc1->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc1->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11UnorderedAccessView1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC1>* pDesc1)
{
    auto replay_object = MapObject<ID3D11UnorderedAccessView1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc1->IsNull())
        {
            pDesc1->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc1->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Query1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D11_QUERY_DESC1>* pDesc1)
{
    auto replay_object = MapObject<ID3D11Query1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pDesc1->IsNull())
        {
            pDesc1->AllocateOutputData(1);
        }
        replay_object->GetDesc1(pDesc1->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext3_Flush1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D11_CONTEXT_TYPE                          ContextType,
    uint64_t                                    hEvent)
{
    auto replay_object = MapObject<ID3D11DeviceContext3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_ID3D11DeviceContext3_Flush1, "ID3D11DeviceContext3_Flush1"));
        replay_object->Flush1(ContextType,
                              in_hEvent);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext3_SetHardwareProtectionState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        HwProtectionEnable)
{
    auto replay_object = MapObject<ID3D11DeviceContext3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetHardwareProtectionState(HwProtectionEnable);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext3_GetHardwareProtectionState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<BOOL>*                       pHwProtectionEnable)
{
    auto replay_object = MapObject<ID3D11DeviceContext3>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHwProtectionEnable->IsNull())
        {
            pHwProtectionEnable->AllocateOutputData(1);
        }
        replay_object->GetHardwareProtectionState(pHwProtectionEnable->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11Fence_CreateSharedHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
    DWORD                                       dwAccess,
    WStringDecoder*                             lpName,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto replay_object = MapObject<ID3D11Fence>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHandle->IsNull())
        {
            pHandle->AllocateOutputData(1);
        }
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = replay_object->CreateSharedHandle(pAttributes->GetPointer(),
                                                               dwAccess,
                                                               lpName->GetPointer(),
                                                               out_op_pHandle);
        CheckReplayResult("ID3D11Fence_CreateSharedHandle", return_value, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHandle, out_p_pHandle, format::ApiCallId::ApiCall_ID3D11Fence_CreateSharedHandle, "ID3D11Fence_CreateSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_ID3D11Fence_GetCompletedValue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = MapObject<ID3D11Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCompletedValue();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Fence_SetEventOnCompletion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      Value,
    uint64_t                                    hEvent)
{
    auto replay_object = MapObject<ID3D11Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_ID3D11Fence_SetEventOnCompletion, "ID3D11Fence_SetEventOnCompletion"));
        auto replay_result = replay_object->SetEventOnCompletion(Value,
                                                                 in_hEvent);
        CheckReplayResult("ID3D11Fence_SetEventOnCompletion", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext4_Signal(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pFence,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D11DeviceContext4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pFence = MapObject<ID3D11Fence>(pFence);
        auto replay_result = replay_object->Signal(in_pFence,
                                                   Value);
        CheckReplayResult("ID3D11DeviceContext4_Signal", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11DeviceContext4_Wait(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pFence,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D11DeviceContext4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pFence = MapObject<ID3D11Fence>(pFence);
        auto replay_result = replay_object->Wait(in_pFence,
                                                 Value);
        CheckReplayResult("ID3D11DeviceContext4_Wait", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_CreateRasterizerState2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_RASTERIZER_DESC2>* pRasterizerDesc,
    HandlePointerDecoder<ID3D11RasterizerState2*>* ppRasterizerState)
{
    auto replay_object = MapObject<ID3D11Device3>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRasterizerState->IsNull()) ppRasterizerState->SetHandleLength(1);
        auto out_p_ppRasterizerState    = ppRasterizerState->GetPointer();
        auto out_hp_ppRasterizerState   = ppRasterizerState->GetHandlePointer();
        auto replay_result = replay_object->CreateRasterizerState2(pRasterizerDesc->GetPointer(),
                                                                   out_hp_ppRasterizerState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppRasterizerState, out_hp_ppRasterizerState, format::ApiCall_ID3D11Device3_CreateRasterizerState2);
        }
        CheckReplayResult("ID3D11Device3_CreateRasterizerState2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_CreateShaderResourceView1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_SHADER_RESOURCE_VIEW_DESC1>* pDesc1,
    HandlePointerDecoder<ID3D11ShaderResourceView1*>* ppSRView1)
{
    auto replay_object = MapObject<ID3D11Device3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppSRView1->IsNull()) ppSRView1->SetHandleLength(1);
        auto out_p_ppSRView1    = ppSRView1->GetPointer();
        auto out_hp_ppSRView1   = ppSRView1->GetHandlePointer();
        auto replay_result = replay_object->CreateShaderResourceView1(in_pResource,
                                                                      pDesc1->GetPointer(),
                                                                      out_hp_ppSRView1);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSRView1, out_hp_ppSRView1, format::ApiCall_ID3D11Device3_CreateShaderResourceView1);
        }
        CheckReplayResult("ID3D11Device3_CreateShaderResourceView1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_CreateUnorderedAccessView1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_UNORDERED_ACCESS_VIEW_DESC1>* pDesc1,
    HandlePointerDecoder<ID3D11UnorderedAccessView1*>* ppUAView1)
{
    auto replay_object = MapObject<ID3D11Device3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppUAView1->IsNull()) ppUAView1->SetHandleLength(1);
        auto out_p_ppUAView1    = ppUAView1->GetPointer();
        auto out_hp_ppUAView1   = ppUAView1->GetHandlePointer();
        auto replay_result = replay_object->CreateUnorderedAccessView1(in_pResource,
                                                                       pDesc1->GetPointer(),
                                                                       out_hp_ppUAView1);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppUAView1, out_hp_ppUAView1, format::ApiCall_ID3D11Device3_CreateUnorderedAccessView1);
        }
        CheckReplayResult("ID3D11Device3_CreateUnorderedAccessView1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_CreateRenderTargetView1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D11_RENDER_TARGET_VIEW_DESC1>* pDesc1,
    HandlePointerDecoder<ID3D11RenderTargetView1*>* ppRTView1)
{
    auto replay_object = MapObject<ID3D11Device3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D11Resource>(pResource);
        if(!ppRTView1->IsNull()) ppRTView1->SetHandleLength(1);
        auto out_p_ppRTView1    = ppRTView1->GetPointer();
        auto out_hp_ppRTView1   = ppRTView1->GetHandlePointer();
        auto replay_result = replay_object->CreateRenderTargetView1(in_pResource,
                                                                    pDesc1->GetPointer(),
                                                                    out_hp_ppRTView1);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppRTView1, out_hp_ppRTView1, format::ApiCall_ID3D11Device3_CreateRenderTargetView1);
        }
        CheckReplayResult("ID3D11Device3_CreateRenderTargetView1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_CreateQuery1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D11_QUERY_DESC1>* pQueryDesc1,
    HandlePointerDecoder<ID3D11Query1*>*        ppQuery1)
{
    auto replay_object = MapObject<ID3D11Device3>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppQuery1->IsNull()) ppQuery1->SetHandleLength(1);
        auto out_p_ppQuery1    = ppQuery1->GetPointer();
        auto out_hp_ppQuery1   = ppQuery1->GetHandlePointer();
        auto replay_result = replay_object->CreateQuery1(pQueryDesc1->GetPointer(),
                                                         out_hp_ppQuery1);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppQuery1, out_hp_ppQuery1, format::ApiCall_ID3D11Device3_CreateQuery1);
        }
        CheckReplayResult("ID3D11Device3_CreateQuery1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_GetImmediateContext3(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11DeviceContext3*>* ppImmediateContext)
{
    auto replay_object = MapObject<ID3D11Device3>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppImmediateContext->IsNull()) ppImmediateContext->SetHandleLength(1);
        auto out_p_ppImmediateContext    = ppImmediateContext->GetPointer();
        auto out_hp_ppImmediateContext   = ppImmediateContext->GetHandlePointer();
        replay_object->GetImmediateContext3(out_hp_ppImmediateContext);
        AddObject(out_p_ppImmediateContext, out_hp_ppImmediateContext, format::ApiCall_ID3D11Device3_GetImmediateContext3);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_CreateDeferredContext3(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        ContextFlags,
    HandlePointerDecoder<ID3D11DeviceContext3*>* ppDeferredContext)
{
    auto replay_object = MapObject<ID3D11Device3>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDeferredContext->IsNull()) ppDeferredContext->SetHandleLength(1);
        auto out_p_ppDeferredContext    = ppDeferredContext->GetPointer();
        auto out_hp_ppDeferredContext   = ppDeferredContext->GetHandlePointer();
        auto replay_result = replay_object->CreateDeferredContext3(ContextFlags,
                                                                   out_hp_ppDeferredContext);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDeferredContext, out_hp_ppDeferredContext, format::ApiCall_ID3D11Device3_CreateDeferredContext3);
        }
        CheckReplayResult("ID3D11Device3_CreateDeferredContext3", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device3_ReadFromSubresource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    uint64_t                                    pDstData,
    UINT                                        DstRowPitch,
    UINT                                        DstDepthPitch,
    format::HandleId                            pSrcResource,
    UINT                                        SrcSubresource,
    StructPointerDecoder<Decoded_D3D11_BOX>*    pSrcBox)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pSrcResource = GetObjectInfo(pSrcResource);
        OverrideDevice3ReadFromSubresource(replay_object,
                                           pDstData,
                                           DstRowPitch,
                                           DstDepthPitch,
                                           in_pSrcResource,
                                           SrcSubresource,
                                           pSrcBox);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device4_RegisterDeviceRemovedEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<ID3D11Device4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_ID3D11Device4_RegisterDeviceRemovedEvent, "ID3D11Device4_RegisterDeviceRemovedEvent"));
        if(!pdwCookie->IsNull())
        {
            pdwCookie->AllocateOutputData(1);
        }
        auto replay_result = replay_object->RegisterDeviceRemovedEvent(in_hEvent,
                                                                       pdwCookie->GetOutputPointer());
        CheckReplayResult("ID3D11Device4_RegisterDeviceRemovedEvent", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device4_UnregisterDeviceRemoved(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<ID3D11Device4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterDeviceRemoved(dwCookie);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device5_OpenSharedFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hFence,
    Decoded_GUID                                ReturnedInterface,
    HandlePointerDecoder<void*>*                ppFence)
{
    auto replay_object = MapObject<ID3D11Device5>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hFence = static_cast<HANDLE>(PreProcessExternalObject(hFence, format::ApiCallId::ApiCall_ID3D11Device5_OpenSharedFence, "ID3D11Device5_OpenSharedFence"));
        if(!ppFence->IsNull()) ppFence->SetHandleLength(1);
        auto out_p_ppFence    = ppFence->GetPointer();
        auto out_hp_ppFence   = ppFence->GetHandlePointer();
        auto replay_result = replay_object->OpenSharedFence(in_hFence,
                                                            *ReturnedInterface.decoded_value,
                                                            out_hp_ppFence);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppFence, out_hp_ppFence, format::ApiCall_ID3D11Device5_OpenSharedFence);
        }
        CheckReplayResult("ID3D11Device5_OpenSharedFence", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Device5_CreateFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      InitialValue,
    D3D11_FENCE_FLAG                            Flags,
    Decoded_GUID                                ReturnedInterface,
    HandlePointerDecoder<void*>*                ppFence)
{
    auto replay_object = MapObject<ID3D11Device5>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppFence->IsNull()) ppFence->SetHandleLength(1);
        auto out_p_ppFence    = ppFence->GetPointer();
        auto out_hp_ppFence   = ppFence->GetHandlePointer();
        auto replay_result = replay_object->CreateFence(InitialValue,
                                                        Flags,
                                                        *ReturnedInterface.decoded_value,
                                                        out_hp_ppFence);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppFence, out_hp_ppFence, format::ApiCall_ID3D11Device5_CreateFence);
        }
        CheckReplayResult("ID3D11Device5_CreateFence", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Multithread_Enter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D11Multithread>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Enter();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Multithread_Leave(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D11Multithread>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Leave();
    }
}

void Dx12ReplayConsumer::Process_ID3D11Multithread_SetMultithreadProtected(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    BOOL                                        bMTProtect)
{
    auto replay_object = MapObject<ID3D11Multithread>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMultithreadProtected(bMTProtect);
    }
}

void Dx12ReplayConsumer::Process_ID3D11Multithread_GetMultithreadProtected(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = MapObject<ID3D11Multithread>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMultithreadProtected();
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext2_VideoProcessorSetOutputHDRMetaData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    DXGI_HDR_METADATA_TYPE                      Type,
    UINT                                        Size,
    PointerDecoder<uint8_t>*                    pHDRMetaData)
{
    auto replay_object = MapObject<ID3D11VideoContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetOutputHDRMetaData(in_pVideoProcessor,
                                                          Type,
                                                          Size,
                                                          pHDRMetaData->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext2_VideoProcessorGetOutputHDRMetaData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    PointerDecoder<DXGI_HDR_METADATA_TYPE>*     pType,
    UINT                                        Size,
    PointerDecoder<uint8_t>*                    pMetaData)
{
    auto replay_object = MapObject<ID3D11VideoContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pType->IsNull())
        {
            pType->AllocateOutputData(1);
        }
        if(!pMetaData->IsNull())
        {
            pMetaData->AllocateOutputData(Size);
        }
        replay_object->VideoProcessorGetOutputHDRMetaData(in_pVideoProcessor,
                                                          pType->GetOutputPointer(),
                                                          Size,
                                                          pMetaData->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext2_VideoProcessorSetStreamHDRMetaData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    DXGI_HDR_METADATA_TYPE                      Type,
    UINT                                        Size,
    PointerDecoder<uint8_t>*                    pHDRMetaData)
{
    auto replay_object = MapObject<ID3D11VideoContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        replay_object->VideoProcessorSetStreamHDRMetaData(in_pVideoProcessor,
                                                          StreamIndex,
                                                          Type,
                                                          Size,
                                                          pHDRMetaData->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext2_VideoProcessorGetStreamHDRMetaData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pVideoProcessor,
    UINT                                        StreamIndex,
    PointerDecoder<DXGI_HDR_METADATA_TYPE>*     pType,
    UINT                                        Size,
    PointerDecoder<uint8_t>*                    pMetaData)
{
    auto replay_object = MapObject<ID3D11VideoContext2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pVideoProcessor = MapObject<ID3D11VideoProcessor>(pVideoProcessor);
        if(!pType->IsNull())
        {
            pType->AllocateOutputData(1);
        }
        if(!pMetaData->IsNull())
        {
            pMetaData->AllocateOutputData(Size);
        }
        replay_object->VideoProcessorGetStreamHDRMetaData(in_pVideoProcessor,
                                                          StreamIndex,
                                                          pType->GetOutputPointer(),
                                                          Size,
                                                          pMetaData->GetOutputPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice2_CheckFeatureSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D11_FEATURE_VIDEO                         Feature,
    PointerDecoder<uint8_t>*                    pFeatureSupportData,
    UINT                                        FeatureSupportDataSize)
{
    auto replay_object = MapObject<ID3D11VideoDevice2>(object_id);
    if (replay_object != nullptr)
    {
        if(!pFeatureSupportData->IsNull())
        {
            pFeatureSupportData->AllocateOutputData(FeatureSupportDataSize);
        }
        auto replay_result = replay_object->CheckFeatureSupport(Feature,
                                                                pFeatureSupportData->GetOutputPointer(),
                                                                FeatureSupportDataSize);
        CheckReplayResult("ID3D11VideoDevice2_CheckFeatureSupport", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoDevice2_NegotiateCryptoSessionKeyExchangeMT(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pCryptoSession,
    D3D11_CRYPTO_SESSION_KEY_EXCHANGE_FLAGS     flags,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D11VideoDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCryptoSession = MapObject<ID3D11CryptoSession>(pCryptoSession);
        if(!pData->IsNull())
        {
            pData->AllocateOutputData(DataSize);
        }
        auto replay_result = replay_object->NegotiateCryptoSessionKeyExchangeMT(in_pCryptoSession,
                                                                                flags,
                                                                                DataSize,
                                                                                pData->GetOutputPointer());
        CheckReplayResult("ID3D11VideoDevice2_NegotiateCryptoSessionKeyExchangeMT", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext3_DecoderBeginFrame1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    format::HandleId                            pView,
    UINT                                        ContentKeySize,
    PointerDecoder<uint8_t>*                    pContentKey,
    UINT                                        NumComponentHistograms,
    PointerDecoder<UINT>*                       pHistogramOffsets,
    HandlePointerDecoder<ID3D11Buffer*>*        ppHistogramBuffers)
{
    auto replay_object = MapObject<ID3D11VideoContext3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto in_pView = MapObject<ID3D11VideoDecoderOutputView>(pView);
        auto in_ppHistogramBuffers = MapObjects<ID3D11Buffer>(ppHistogramBuffers, NumComponentHistograms);
        auto replay_result = replay_object->DecoderBeginFrame1(in_pDecoder,
                                                               in_pView,
                                                               ContentKeySize,
                                                               pContentKey->GetPointer(),
                                                               NumComponentHistograms,
                                                               pHistogramOffsets->GetPointer(),
                                                               in_ppHistogramBuffers);
        CheckReplayResult("ID3D11VideoContext3_DecoderBeginFrame1", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11VideoContext3_SubmitDecoderBuffers2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDecoder,
    UINT                                        NumBuffers,
    StructPointerDecoder<Decoded_D3D11_VIDEO_DECODER_BUFFER_DESC2>* pBufferDesc)
{
    auto replay_object = MapObject<ID3D11VideoContext3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDecoder = MapObject<ID3D11VideoDecoder>(pDecoder);
        auto replay_result = replay_object->SubmitDecoderBuffers2(in_pDecoder,
                                                                  NumBuffers,
                                                                  pBufferDesc->GetPointer());
        CheckReplayResult("ID3D11VideoContext3_SubmitDecoderBuffers2", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11On12Device_CreateWrappedResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource12,
    StructPointerDecoder<Decoded_D3D11_RESOURCE_FLAGS>* pFlags11,
    D3D12_RESOURCE_STATES                       InState,
    D3D12_RESOURCE_STATES                       OutState,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppResource11)
{
    auto replay_object = MapObject<ID3D11On12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource12 = MapObject<IUnknown>(pResource12);
        if(!ppResource11->IsNull()) ppResource11->SetHandleLength(1);
        auto out_p_ppResource11    = ppResource11->GetPointer();
        auto out_hp_ppResource11   = ppResource11->GetHandlePointer();
        auto replay_result = replay_object->CreateWrappedResource(in_pResource12,
                                                                  pFlags11->GetPointer(),
                                                                  InState,
                                                                  OutState,
                                                                  *riid.decoded_value,
                                                                  out_hp_ppResource11);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppResource11, out_hp_ppResource11, format::ApiCall_ID3D11On12Device_CreateWrappedResource);
        }
        CheckReplayResult("ID3D11On12Device_CreateWrappedResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11On12Device_ReleaseWrappedResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11Resource*>*      ppResources,
    UINT                                        NumResources)
{
    auto replay_object = MapObject<ID3D11On12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<ID3D11Resource>(ppResources, NumResources);
        replay_object->ReleaseWrappedResources(in_ppResources,
                                               NumResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11On12Device_AcquireWrappedResources(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D11Resource*>*      ppResources,
    UINT                                        NumResources)
{
    auto replay_object = MapObject<ID3D11On12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<ID3D11Resource>(ppResources, NumResources);
        replay_object->AcquireWrappedResources(in_ppResources,
                                               NumResources);
    }
}

void Dx12ReplayConsumer::Process_ID3D11On12Device1_GetD3D12Device(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDevice)
{
    auto replay_object = MapObject<ID3D11On12Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvDevice->IsNull()) ppvDevice->SetHandleLength(1);
        auto out_p_ppvDevice    = ppvDevice->GetPointer();
        auto out_hp_ppvDevice   = ppvDevice->GetHandlePointer();
        auto replay_result = replay_object->GetD3D12Device(*riid.decoded_value,
                                                           out_hp_ppvDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDevice, out_hp_ppvDevice, format::ApiCall_ID3D11On12Device1_GetD3D12Device);
        }
        CheckReplayResult("ID3D11On12Device1_GetD3D12Device", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11On12Device2_UnwrapUnderlyingResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource11,
    format::HandleId                            pCommandQueue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource12)
{
    auto replay_object = MapObject<ID3D11On12Device2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource11 = MapObject<ID3D11Resource>(pResource11);
        auto in_pCommandQueue = MapObject<ID3D12CommandQueue>(pCommandQueue);
        if(!ppvResource12->IsNull()) ppvResource12->SetHandleLength(1);
        auto out_p_ppvResource12    = ppvResource12->GetPointer();
        auto out_hp_ppvResource12   = ppvResource12->GetHandlePointer();
        auto replay_result = replay_object->UnwrapUnderlyingResource(in_pResource11,
                                                                     in_pCommandQueue,
                                                                     *riid.decoded_value,
                                                                     out_hp_ppvResource12);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource12, out_hp_ppvResource12, format::ApiCall_ID3D11On12Device2_UnwrapUnderlyingResource);
        }
        CheckReplayResult("ID3D11On12Device2_UnwrapUnderlyingResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D11On12Device2_ReturnUnderlyingResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pResource11,
    UINT                                        NumSync,
    PointerDecoder<UINT64>*                     pSignalValues,
    HandlePointerDecoder<ID3D12Fence*>*         ppFences)
{
    auto replay_object = MapObject<ID3D11On12Device2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource11 = MapObject<ID3D11Resource>(pResource11);
        auto in_ppFences = MapObjects<ID3D12Fence>(ppFences, NumSync);
        auto replay_result = replay_object->ReturnUnderlyingResource(in_pResource11,
                                                                     NumSync,
                                                                     pSignalValues->GetPointer(),
                                                                     in_ppFences);
        CheckReplayResult("ID3D11On12Device2_ReturnUnderlyingResource", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IUnknown_QueryInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvObject)
{
    auto replay_object = MapObject<IUnknown>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvObject->IsNull()) ppvObject->SetHandleLength(1);
        auto out_p_ppvObject    = ppvObject->GetPointer();
        auto out_hp_ppvObject   = ppvObject->GetHandlePointer();
        auto replay_result = replay_object->QueryInterface(*riid.decoded_value,
                                                           out_hp_ppvObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvObject, out_hp_ppvObject, format::ApiCall_IUnknown_QueryInterface);
        }
        CheckReplayResult("IUnknown_QueryInterface", return_value, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IUnknown_AddRef(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    ULONG                                       return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideAddRef(replay_object,
                                            return_value);
    }
}

void Dx12ReplayConsumer::Process_IUnknown_Release(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    ULONG                                       return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideRelease(replay_object,
                                             return_value);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
