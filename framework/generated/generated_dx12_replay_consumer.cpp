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
** This file is generated from dx12_replay_consumer_body_generator.py.
**
*/

#include "generated/generated_dx12_replay_consumer.h"

#include "decode/custom_dx12_struct_object_mappers.h"
#include "decode/custom_dx12_replay_commands.h"
#include "generated/generated_dx12_struct_object_mappers.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void Dx12ReplayConsumer::Process_CreateDXGIFactory(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_CreateDXGIFactory>::Dispatch(
        this,
        call_info,
        riid,
        ppFactory);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_CreateDXGIFactory>::Dispatch(
        this,
        call_info,
        riid,
        ppFactory);
}

void Dx12ReplayConsumer::Process_CreateDXGIFactory1(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_CreateDXGIFactory1>::Dispatch(
        this,
        call_info,
        riid,
        ppFactory);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_CreateDXGIFactory1>::Dispatch(
        this,
        call_info,
        riid,
        ppFactory);
}

void Dx12ReplayConsumer::Process_CreateDXGIFactory2(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    UINT                                        Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_CreateDXGIFactory2>::Dispatch(
        this,
        call_info,
        Flags,
        riid,
        ppFactory);
    if(!ppFactory->IsNull()) ppFactory->SetHandleLength(1);
    DxObjectInfo object_info{};
    ppFactory->SetConsumerData(0, &object_info);
    auto replay_result = OverrideCreateDXGIFactory2(return_value,
                                                    Flags,
                                                    riid,
                                                    ppFactory);
    if (SUCCEEDED(replay_result))
    {
        AddObject(ppFactory->GetPointer(), ppFactory->GetHandlePointer(), std::move(object_info), format::ApiCall_CreateDXGIFactory2);
    }
    CheckReplayResult("CreateDXGIFactory2", return_value, replay_result);
    CustomReplayPostCall<format::ApiCallId::ApiCall_CreateDXGIFactory2>::Dispatch(
        this,
        call_info,
        Flags,
        riid,
        ppFactory);
}

void Dx12ReplayConsumer::Process_DXGIGetDebugInterface1(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    UINT                                        Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                pDebug)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_DXGIGetDebugInterface1>::Dispatch(
        this,
        call_info,
        Flags,
        riid,
        pDebug);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_DXGIGetDebugInterface1>::Dispatch(
        this,
        call_info,
        Flags,
        riid,
        pDebug);
}

void Dx12ReplayConsumer::Process_DXGIDeclareAdapterRemovalSupport(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_DXGIDeclareAdapterRemovalSupport>::Dispatch(
        this,
        call_info);
    auto replay_result = DXGIDeclareAdapterRemovalSupport();
    CheckReplayResult("DXGIDeclareAdapterRemovalSupport", return_value, replay_result);
    CustomReplayPostCall<format::ApiCallId::ApiCall_DXGIDeclareAdapterRemovalSupport>::Dispatch(
        this,
        call_info);
}

void Dx12ReplayConsumer::Process_D3D12SerializeRootSignature(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION                  Version,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob,
    HandlePointerDecoder<ID3D10Blob*>*          ppErrorBlob)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12SerializeRootSignature>::Dispatch(
        this,
        call_info,
        pRootSignature,
        Version,
        ppBlob,
        ppErrorBlob);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12SerializeRootSignature>::Dispatch(
        this,
        call_info,
        pRootSignature,
        Version,
        ppBlob,
        ppErrorBlob);
}

void Dx12ReplayConsumer::Process_D3D12CreateRootSignatureDeserializer(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pSrcData,
    SIZE_T                                      SrcDataSizeInBytes,
    Decoded_GUID                                pRootSignatureDeserializerInterface,
    HandlePointerDecoder<void*>*                ppRootSignatureDeserializer)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12CreateRootSignatureDeserializer>::Dispatch(
        this,
        call_info,
        pSrcData,
        SrcDataSizeInBytes,
        pRootSignatureDeserializerInterface,
        ppRootSignatureDeserializer);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12CreateRootSignatureDeserializer>::Dispatch(
        this,
        call_info,
        pSrcData,
        SrcDataSizeInBytes,
        pRootSignatureDeserializerInterface,
        ppRootSignatureDeserializer);
}

void Dx12ReplayConsumer::Process_D3D12SerializeVersionedRootSignature(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob,
    HandlePointerDecoder<ID3D10Blob*>*          ppErrorBlob)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12SerializeVersionedRootSignature>::Dispatch(
        this,
        call_info,
        pRootSignature,
        ppBlob,
        ppErrorBlob);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12SerializeVersionedRootSignature>::Dispatch(
        this,
        call_info,
        pRootSignature,
        ppBlob,
        ppErrorBlob);
}

void Dx12ReplayConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pSrcData,
    SIZE_T                                      SrcDataSizeInBytes,
    Decoded_GUID                                pRootSignatureDeserializerInterface,
    HandlePointerDecoder<void*>*                ppRootSignatureDeserializer)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializer>::Dispatch(
        this,
        call_info,
        pSrcData,
        SrcDataSizeInBytes,
        pRootSignatureDeserializerInterface,
        ppRootSignatureDeserializer);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializer>::Dispatch(
        this,
        call_info,
        pSrcData,
        SrcDataSizeInBytes,
        pRootSignatureDeserializerInterface,
        ppRootSignatureDeserializer);
}

void Dx12ReplayConsumer::Process_D3D12CreateDevice(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    format::HandleId                            pAdapter,
    D3D_FEATURE_LEVEL                           MinimumFeatureLevel,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppDevice)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12CreateDevice>::Dispatch(
        this,
        call_info,
        pAdapter,
        MinimumFeatureLevel,
        riid,
        ppDevice);
    auto in_pAdapter = GetObjectInfo(pAdapter);
    if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
    DxObjectInfo object_info{};
    ppDevice->SetConsumerData(0, &object_info);
    auto replay_result = OverrideD3D12CreateDevice(return_value,
                                                   in_pAdapter,
                                                   MinimumFeatureLevel,
                                                   riid,
                                                   ppDevice);
    if (SUCCEEDED(replay_result))
    {
        AddObject(ppDevice->GetPointer(), ppDevice->GetHandlePointer(), std::move(object_info), format::ApiCall_D3D12CreateDevice);
    }
    CheckReplayResult("D3D12CreateDevice", return_value, replay_result);
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12CreateDevice>::Dispatch(
        this,
        call_info,
        pAdapter,
        MinimumFeatureLevel,
        riid,
        ppDevice);
}

void Dx12ReplayConsumer::Process_D3D12GetDebugInterface(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDebug)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12GetDebugInterface>::Dispatch(
        this,
        call_info,
        riid,
        ppvDebug);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12GetDebugInterface>::Dispatch(
        this,
        call_info,
        riid,
        ppvDebug);
}

void Dx12ReplayConsumer::Process_D3D12EnableExperimentalFeatures(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    UINT                                        NumFeatures,
    StructPointerDecoder<Decoded_GUID>*         pIIDs,
    PointerDecoder<uint8_t>*                    pConfigurationStructs,
    PointerDecoder<UINT>*                       pConfigurationStructSizes)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12EnableExperimentalFeatures>::Dispatch(
        this,
        call_info,
        NumFeatures,
        pIIDs,
        pConfigurationStructs,
        pConfigurationStructSizes);
    auto replay_result = D3D12EnableExperimentalFeatures(NumFeatures,
                                                         pIIDs->GetPointer(),
                                                         pConfigurationStructs->GetPointer(),
                                                         pConfigurationStructSizes->GetPointer());
    CheckReplayResult("D3D12EnableExperimentalFeatures", return_value, replay_result);
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12EnableExperimentalFeatures>::Dispatch(
        this,
        call_info,
        NumFeatures,
        pIIDs,
        pConfigurationStructs,
        pConfigurationStructSizes);
}

void Dx12ReplayConsumer::Process_D3D12GetInterface(
    const ApiCallInfo&                          call_info,
    HRESULT                                     return_value,
    Decoded_GUID                                rclsid,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDebug)
{
    CustomReplayPreCall<format::ApiCallId::ApiCall_D3D12GetInterface>::Dispatch(
        this,
        call_info,
        rclsid,
        riid,
        ppvDebug);
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
    CustomReplayPostCall<format::ApiCallId::ApiCall_D3D12GetInterface>::Dispatch(
        this,
        call_info,
        rclsid,
        riid,
        ppvDebug);
}
void Dx12ReplayConsumer::Process_IDXGIObject_SetPrivateData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                Name,
    UINT                                        DataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIObject_SetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            DataSize,
            pData);
        auto replay_result = reinterpret_cast<IDXGIObject*>(replay_object->object)->SetPrivateData(*Name.decoded_value,
                                                                                                   DataSize,
                                                                                                   pData->GetPointer());
        CheckReplayResult("IDXGIObject_SetPrivateData", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIObject_SetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            DataSize,
            pData);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_SetPrivateDataInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                Name,
    format::HandleId                            pUnknown)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIObject_SetPrivateDataInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            pUnknown);
        auto in_pUnknown = MapObject<IUnknown>(pUnknown);
        auto replay_result = reinterpret_cast<IDXGIObject*>(replay_object->object)->SetPrivateDataInterface(*Name.decoded_value,
                                                                                                            in_pUnknown);
        CheckReplayResult("IDXGIObject_SetPrivateDataInterface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIObject_SetPrivateDataInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            pUnknown);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIObject_GetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            pDataSize,
            pData);
        auto replay_result = reinterpret_cast<IDXGIObject*>(replay_object->object)->GetPrivateData(*Name.decoded_value,
                                                                                                   pDataSize->GetPointer(),
                                                                                                   pData->GetPointer());
        CheckReplayResult("IDXGIObject_GetPrivateData", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIObject_GetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            pDataSize,
            pData);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_GetParent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppParent)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIObject_GetParent>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppParent);
        if(!ppParent->IsNull()) ppParent->SetHandleLength(1);
        auto out_p_ppParent    = ppParent->GetPointer();
        auto out_hp_ppParent   = ppParent->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIObject*>(replay_object->object)->GetParent(*riid.decoded_value,
                                                                                              out_hp_ppParent);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppParent, out_hp_ppParent, format::ApiCall_IDXGIObject_GetParent);
        }
        CheckReplayResult("IDXGIObject_GetParent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIObject_GetParent>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppParent);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDeviceSubObject_GetDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppDevice)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDeviceSubObject_GetDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppDevice);
        if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
        auto out_p_ppDevice    = ppDevice->GetPointer();
        auto out_hp_ppDevice   = ppDevice->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIDeviceSubObject*>(replay_object->object)->GetDevice(*riid.decoded_value,
                                                                                                       out_hp_ppDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDevice, out_hp_ppDevice, format::ApiCall_IDXGIDeviceSubObject_GetDevice);
        }
        CheckReplayResult("IDXGIDeviceSubObject_GetDevice", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDeviceSubObject_GetDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppDevice);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetSharedHandle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint64_t, void*>*            pSharedHandle)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pSharedHandle);
        if(!pSharedHandle->IsNull())
        {
            pSharedHandle->AllocateOutputData(1);
        }
        auto out_p_pSharedHandle    = pSharedHandle->GetPointer();
        auto out_op_pSharedHandle   = reinterpret_cast<HANDLE*>(pSharedHandle->GetOutputPointer());
        auto replay_result = reinterpret_cast<IDXGIResource*>(replay_object->object)->GetSharedHandle(out_op_pSharedHandle);
        CheckReplayResult("IDXGIResource_GetSharedHandle", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pSharedHandle);
        PostProcessExternalObject(replay_result, out_op_pSharedHandle, out_p_pSharedHandle, format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle, "IDXGIResource_GetSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetUsage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<DXGI_USAGE>*                 pUsage)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIResource_GetUsage>::Dispatch(
            this,
            call_info,
            replay_object,
            pUsage);
        auto replay_result = reinterpret_cast<IDXGIResource*>(replay_object->object)->GetUsage(pUsage->GetPointer());
        CheckReplayResult("IDXGIResource_GetUsage", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIResource_GetUsage>::Dispatch(
            this,
            call_info,
            replay_object,
            pUsage);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_SetEvictionPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        EvictionPriority)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIResource_SetEvictionPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            EvictionPriority);
        auto replay_result = reinterpret_cast<IDXGIResource*>(replay_object->object)->SetEvictionPriority(EvictionPriority);
        CheckReplayResult("IDXGIResource_SetEvictionPriority", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIResource_SetEvictionPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            EvictionPriority);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetEvictionPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pEvictionPriority)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIResource_GetEvictionPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            pEvictionPriority);
        auto replay_result = reinterpret_cast<IDXGIResource*>(replay_object->object)->GetEvictionPriority(pEvictionPriority->GetPointer());
        CheckReplayResult("IDXGIResource_GetEvictionPriority", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIResource_GetEvictionPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            pEvictionPriority);
    }
}

void Dx12ReplayConsumer::Process_IDXGIKeyedMutex_AcquireSync(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      Key,
    DWORD                                       dwMilliseconds)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIKeyedMutex_AcquireSync>::Dispatch(
            this,
            call_info,
            replay_object,
            Key,
            dwMilliseconds);
        auto replay_result = reinterpret_cast<IDXGIKeyedMutex*>(replay_object->object)->AcquireSync(Key,
                                                                                                    dwMilliseconds);
        CheckReplayResult("IDXGIKeyedMutex_AcquireSync", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIKeyedMutex_AcquireSync>::Dispatch(
            this,
            call_info,
            replay_object,
            Key,
            dwMilliseconds);
    }
}

void Dx12ReplayConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      Key)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIKeyedMutex_ReleaseSync>::Dispatch(
            this,
            call_info,
            replay_object,
            Key);
        auto replay_result = reinterpret_cast<IDXGIKeyedMutex*>(replay_object->object)->ReleaseSync(Key);
        CheckReplayResult("IDXGIKeyedMutex_ReleaseSync", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIKeyedMutex_ReleaseSync>::Dispatch(
            this,
            call_info,
            replay_object,
            Key);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISurface_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGISurface*>(replay_object->object)->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGISurface_GetDesc", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISurface_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_Map(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
    UINT                                        MapFlags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISurface_Map>::Dispatch(
            this,
            call_info,
            replay_object,
            pLockedRect,
            MapFlags);
        auto replay_result = reinterpret_cast<IDXGISurface*>(replay_object->object)->Map(pLockedRect->GetPointer(),
                                                                                         MapFlags);
        CheckReplayResult("IDXGISurface_Map", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISurface_Map>::Dispatch(
            this,
            call_info,
            replay_object,
            pLockedRect,
            MapFlags);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_Unmap(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISurface_Unmap>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGISurface*>(replay_object->object)->Unmap();
        CheckReplayResult("IDXGISurface_Unmap", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISurface_Unmap>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface1_GetDC(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    BOOL                                        Discard,
    PointerDecoder<uint64_t, void*>*            phdc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISurface1_GetDC>::Dispatch(
            this,
            call_info,
            replay_object,
            Discard,
            phdc);
        if(!phdc->IsNull())
        {
            phdc->AllocateOutputData(1);
        }
        auto out_p_phdc    = phdc->GetPointer();
        auto out_op_phdc   = reinterpret_cast<HDC*>(phdc->GetOutputPointer());
        auto replay_result = reinterpret_cast<IDXGISurface1*>(replay_object->object)->GetDC(Discard,
                                                                                            out_op_phdc);
        CheckReplayResult("IDXGISurface1_GetDC", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISurface1_GetDC>::Dispatch(
            this,
            call_info,
            replay_object,
            Discard,
            phdc);
        PostProcessExternalObject(replay_result, out_op_phdc, out_p_phdc, format::ApiCallId::ApiCall_IDXGISurface1_GetDC, "IDXGISurface1_GetDC");
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface1_ReleaseDC(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pDirtyRect)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISurface1_ReleaseDC>::Dispatch(
            this,
            call_info,
            replay_object,
            pDirtyRect);
        auto replay_result = reinterpret_cast<IDXGISurface1*>(replay_object->object)->ReleaseDC(pDirtyRect->GetPointer());
        CheckReplayResult("IDXGISurface1_ReleaseDC", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISurface1_ReleaseDC>::Dispatch(
            this,
            call_info,
            replay_object,
            pDirtyRect);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_EnumOutputs(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Output,
    HandlePointerDecoder<IDXGIOutput*>*         ppOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter_EnumOutputs>::Dispatch(
            this,
            call_info,
            replay_object,
            Output,
            ppOutput);
        if(!ppOutput->IsNull()) ppOutput->SetHandleLength(1);
        auto out_p_ppOutput    = ppOutput->GetPointer();
        auto out_hp_ppOutput   = ppOutput->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIAdapter*>(replay_object->object)->EnumOutputs(Output,
                                                                                                 out_hp_ppOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutput, out_hp_ppOutput, format::ApiCall_IDXGIAdapter_EnumOutputs);
        }
        CheckReplayResult("IDXGIAdapter_EnumOutputs", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter_EnumOutputs>::Dispatch(
            this,
            call_info,
            replay_object,
            Output,
            ppOutput);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIAdapter*>(replay_object->object)->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter_GetDesc", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                InterfaceName,
    StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter_CheckInterfaceSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            InterfaceName,
            pUMDVersion);
        auto replay_result = reinterpret_cast<IDXGIAdapter*>(replay_object->object)->CheckInterfaceSupport(*InterfaceName.decoded_value,
                                                                                                           pUMDVersion->GetPointer());
        CheckReplayResult("IDXGIAdapter_CheckInterfaceSupport", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter_CheckInterfaceSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            InterfaceName,
            pUMDVersion);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput_GetDesc", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_GetDisplayModeList>::Dispatch(
            this,
            call_info,
            replay_object,
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->GetDisplayModeList(EnumFormat,
                                                                                                       Flags,
                                                                                                       pNumModes->GetPointer(),
                                                                                                       pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput_GetDisplayModeList", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_GetDisplayModeList>::Dispatch(
            this,
            call_info,
            replay_object,
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_FindClosestMatchingMode>::Dispatch(
            this,
            call_info,
            replay_object,
            pModeToMatch,
            pClosestMatch,
            pConcernedDevice);
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->FindClosestMatchingMode(pModeToMatch->GetPointer(),
                                                                                                            pClosestMatch->GetPointer(),
                                                                                                            in_pConcernedDevice);
        CheckReplayResult("IDXGIOutput_FindClosestMatchingMode", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_FindClosestMatchingMode>::Dispatch(
            this,
            call_info,
            replay_object,
            pModeToMatch,
            pClosestMatch,
            pConcernedDevice);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_WaitForVBlank(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_WaitForVBlank>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->WaitForVBlank();
        CheckReplayResult("IDXGIOutput_WaitForVBlank", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_WaitForVBlank>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_TakeOwnership(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    BOOL                                        Exclusive)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_TakeOwnership>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            Exclusive);
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->TakeOwnership(in_pDevice,
                                                                                                  Exclusive);
        CheckReplayResult("IDXGIOutput_TakeOwnership", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_TakeOwnership>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            Exclusive);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_ReleaseOwnership(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_ReleaseOwnership>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<IDXGIOutput*>(replay_object->object)->ReleaseOwnership();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_ReleaseOwnership>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControlCapabilities>::Dispatch(
            this,
            call_info,
            replay_object,
            pGammaCaps);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->GetGammaControlCapabilities(pGammaCaps->GetPointer());
        CheckReplayResult("IDXGIOutput_GetGammaControlCapabilities", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControlCapabilities>::Dispatch(
            this,
            call_info,
            replay_object,
            pGammaCaps);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_SetGammaControl(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_SetGammaControl>::Dispatch(
            this,
            call_info,
            replay_object,
            pArray);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->SetGammaControl(pArray->GetPointer());
        CheckReplayResult("IDXGIOutput_SetGammaControl", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_SetGammaControl>::Dispatch(
            this,
            call_info,
            replay_object,
            pArray);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetGammaControl(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControl>::Dispatch(
            this,
            call_info,
            replay_object,
            pArray);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->GetGammaControl(pArray->GetPointer());
        CheckReplayResult("IDXGIOutput_GetGammaControl", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControl>::Dispatch(
            this,
            call_info,
            replay_object,
            pArray);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_SetDisplaySurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pScanoutSurface)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_SetDisplaySurface>::Dispatch(
            this,
            call_info,
            replay_object,
            pScanoutSurface);
        auto in_pScanoutSurface = MapObject<IDXGISurface>(pScanoutSurface);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->SetDisplaySurface(in_pScanoutSurface);
        CheckReplayResult("IDXGIOutput_SetDisplaySurface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_SetDisplaySurface>::Dispatch(
            this,
            call_info,
            replay_object,
            pScanoutSurface);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDestination)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_GetDisplaySurfaceData>::Dispatch(
            this,
            call_info,
            replay_object,
            pDestination);
        auto in_pDestination = MapObject<IDXGISurface>(pDestination);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->GetDisplaySurfaceData(in_pDestination);
        CheckReplayResult("IDXGIOutput_GetDisplaySurfaceData", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_GetDisplaySurfaceData>::Dispatch(
            this,
            call_info,
            replay_object,
            pDestination);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetFrameStatistics(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput_GetFrameStatistics>::Dispatch(
            this,
            call_info,
            replay_object,
            pStats);
        auto replay_result = reinterpret_cast<IDXGIOutput*>(replay_object->object)->GetFrameStatistics(pStats->GetPointer());
        CheckReplayResult("IDXGIOutput_GetFrameStatistics", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput_GetFrameStatistics>::Dispatch(
            this,
            call_info,
            replay_object,
            pStats);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_Present>::Dispatch(
            this,
            call_info,
            replay_object,
            SyncInterval,
            Flags);
        auto replay_result = OverridePresent(replay_object,
                                             return_value,
                                             SyncInterval,
                                             Flags);
        CheckReplayResult("IDXGISwapChain_Present", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_Present>::Dispatch(
            this,
            call_info,
            replay_object,
            SyncInterval,
            Flags);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetBuffer>::Dispatch(
            this,
            call_info,
            replay_object,
            Buffer,
            riid,
            ppSurface);
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSurface->SetConsumerData(0, &object_info);
        auto replay_result = OverrideGetBuffer(replay_object,
                                               return_value,
                                               Buffer,
                                               riid,
                                               ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSurface->GetPointer(), ppSurface->GetHandlePointer(), std::move(object_info), format::ApiCall_IDXGISwapChain_GetBuffer);
        }
        CheckReplayResult("IDXGISwapChain_GetBuffer", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetBuffer>::Dispatch(
            this,
            call_info,
            replay_object,
            Buffer,
            riid,
            ppSurface);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_SetFullscreenState>::Dispatch(
            this,
            call_info,
            replay_object,
            Fullscreen,
            pTarget);
        auto in_pTarget = GetObjectInfo(pTarget);
        auto replay_result = OverrideSetFullscreenState(replay_object,
                                                        return_value,
                                                        Fullscreen,
                                                        in_pTarget);
        CheckReplayResult("IDXGISwapChain_SetFullscreenState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_SetFullscreenState>::Dispatch(
            this,
            call_info,
            replay_object,
            Fullscreen,
            pTarget);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetFullscreenState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<BOOL>*                       pFullscreen,
    HandlePointerDecoder<IDXGIOutput*>*         ppTarget)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetFullscreenState>::Dispatch(
            this,
            call_info,
            replay_object,
            pFullscreen,
            ppTarget);
        if(!ppTarget->IsNull()) ppTarget->SetHandleLength(1);
        auto out_p_ppTarget    = ppTarget->GetPointer();
        auto out_hp_ppTarget   = ppTarget->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGISwapChain*>(replay_object->object)->GetFullscreenState(pFullscreen->GetPointer(),
                                                                                                          out_hp_ppTarget);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppTarget, out_hp_ppTarget, format::ApiCall_IDXGISwapChain_GetFullscreenState);
        }
        CheckReplayResult("IDXGISwapChain_GetFullscreenState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetFullscreenState>::Dispatch(
            this,
            call_info,
            replay_object,
            pFullscreen,
            ppTarget);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGISwapChain*>(replay_object->object)->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGISwapChain_GetDesc", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_ResizeBuffers>::Dispatch(
            this,
            call_info,
            replay_object,
            BufferCount,
            Width,
            Height,
            NewFormat,
            SwapChainFlags);
        auto replay_result = OverrideResizeBuffers(replay_object,
                                                   return_value,
                                                   BufferCount,
                                                   Width,
                                                   Height,
                                                   NewFormat,
                                                   SwapChainFlags);
        CheckReplayResult("IDXGISwapChain_ResizeBuffers", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_ResizeBuffers>::Dispatch(
            this,
            call_info,
            replay_object,
            BufferCount,
            Width,
            Height,
            NewFormat,
            SwapChainFlags);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_ResizeTarget(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_ResizeTarget>::Dispatch(
            this,
            call_info,
            replay_object,
            pNewTargetParameters);
        auto replay_result = reinterpret_cast<IDXGISwapChain*>(replay_object->object)->ResizeTarget(pNewTargetParameters->GetPointer());
        CheckReplayResult("IDXGISwapChain_ResizeTarget", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_ResizeTarget>::Dispatch(
            this,
            call_info,
            replay_object,
            pNewTargetParameters);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetContainingOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<IDXGIOutput*>*         ppOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetContainingOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            ppOutput);
        if(!ppOutput->IsNull()) ppOutput->SetHandleLength(1);
        auto out_p_ppOutput    = ppOutput->GetPointer();
        auto out_hp_ppOutput   = ppOutput->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGISwapChain*>(replay_object->object)->GetContainingOutput(out_hp_ppOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutput, out_hp_ppOutput, format::ApiCall_IDXGISwapChain_GetContainingOutput);
        }
        CheckReplayResult("IDXGISwapChain_GetContainingOutput", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetContainingOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            ppOutput);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetFrameStatistics(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetFrameStatistics>::Dispatch(
            this,
            call_info,
            replay_object,
            pStats);
        auto replay_result = reinterpret_cast<IDXGISwapChain*>(replay_object->object)->GetFrameStatistics(pStats->GetPointer());
        CheckReplayResult("IDXGISwapChain_GetFrameStatistics", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetFrameStatistics>::Dispatch(
            this,
            call_info,
            replay_object,
            pStats);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetLastPresentCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pLastPresentCount)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetLastPresentCount>::Dispatch(
            this,
            call_info,
            replay_object,
            pLastPresentCount);
        auto replay_result = reinterpret_cast<IDXGISwapChain*>(replay_object->object)->GetLastPresentCount(pLastPresentCount->GetPointer());
        CheckReplayResult("IDXGISwapChain_GetLastPresentCount", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain_GetLastPresentCount>::Dispatch(
            this,
            call_info,
            replay_object,
            pLastPresentCount);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_EnumAdapters(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Adapter,
    HandlePointerDecoder<IDXGIAdapter*>*        ppAdapter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory_EnumAdapters>::Dispatch(
            this,
            call_info,
            replay_object,
            Adapter,
            ppAdapter);
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto out_p_ppAdapter    = ppAdapter->GetPointer();
        auto out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactory*>(replay_object->object)->EnumAdapters(Adapter,
                                                                                                  out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppAdapter, out_hp_ppAdapter, format::ApiCall_IDXGIFactory_EnumAdapters);
        }
        CheckReplayResult("IDXGIFactory_EnumAdapters", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory_EnumAdapters>::Dispatch(
            this,
            call_info,
            replay_object,
            Adapter,
            ppAdapter);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_MakeWindowAssociation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    WindowHandle,
    UINT                                        Flags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation>::Dispatch(
            this,
            call_info,
            replay_object,
            WindowHandle,
            Flags);
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation, "IDXGIFactory_MakeWindowAssociation"));
        auto replay_result = reinterpret_cast<IDXGIFactory*>(replay_object->object)->MakeWindowAssociation(in_WindowHandle,
                                                                                                           Flags);
        CheckReplayResult("IDXGIFactory_MakeWindowAssociation", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation>::Dispatch(
            this,
            call_info,
            replay_object,
            WindowHandle,
            Flags);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_GetWindowAssociation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint64_t, void*>*            pWindowHandle)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation>::Dispatch(
            this,
            call_info,
            replay_object,
            pWindowHandle);
        if(!pWindowHandle->IsNull())
        {
            pWindowHandle->AllocateOutputData(1);
        }
        auto out_p_pWindowHandle    = pWindowHandle->GetPointer();
        auto out_op_pWindowHandle   = reinterpret_cast<HWND*>(pWindowHandle->GetOutputPointer());
        auto replay_result = reinterpret_cast<IDXGIFactory*>(replay_object->object)->GetWindowAssociation(out_op_pWindowHandle);
        CheckReplayResult("IDXGIFactory_GetWindowAssociation", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation>::Dispatch(
            this,
            call_info,
            replay_object,
            pWindowHandle);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory_CreateSwapChain>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            pDesc,
            ppSwapChain);
        auto in_pDevice = GetObjectInfo(pDevice);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateSwapChain(replay_object,
                                                     return_value,
                                                     in_pDevice,
                                                     pDesc,
                                                     ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info), format::ApiCall_IDXGIFactory_CreateSwapChain);
        }
        CheckReplayResult("IDXGIFactory_CreateSwapChain", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory_CreateSwapChain>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            pDesc,
            ppSwapChain);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    Module,
    HandlePointerDecoder<IDXGIAdapter*>*        ppAdapter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter>::Dispatch(
            this,
            call_info,
            replay_object,
            Module,
            ppAdapter);
        auto in_Module = static_cast<HMODULE>(PreProcessExternalObject(Module, format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter, "IDXGIFactory_CreateSoftwareAdapter"));
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto out_p_ppAdapter    = ppAdapter->GetPointer();
        auto out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactory*>(replay_object->object)->CreateSoftwareAdapter(in_Module,
                                                                                                           out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppAdapter, out_hp_ppAdapter, format::ApiCall_IDXGIFactory_CreateSoftwareAdapter);
        }
        CheckReplayResult("IDXGIFactory_CreateSoftwareAdapter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter>::Dispatch(
            this,
            call_info,
            replay_object,
            Module,
            ppAdapter);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_GetAdapter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<IDXGIAdapter*>*        pAdapter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice_GetAdapter>::Dispatch(
            this,
            call_info,
            replay_object,
            pAdapter);
        if(!pAdapter->IsNull()) pAdapter->SetHandleLength(1);
        auto out_p_pAdapter    = pAdapter->GetPointer();
        auto out_hp_pAdapter   = pAdapter->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIDevice*>(replay_object->object)->GetAdapter(out_hp_pAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_pAdapter, out_hp_pAdapter, format::ApiCall_IDXGIDevice_GetAdapter);
        }
        CheckReplayResult("IDXGIDevice_GetAdapter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice_GetAdapter>::Dispatch(
            this,
            call_info,
            replay_object,
            pAdapter);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice_CreateSurface>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            NumSurfaces,
            Usage,
            pSharedResource,
            ppSurface);
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(1);
        auto out_p_ppSurface    = ppSurface->GetPointer();
        auto out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIDevice*>(replay_object->object)->CreateSurface(pDesc->GetPointer(),
                                                                                                  NumSurfaces,
                                                                                                  Usage,
                                                                                                  pSharedResource->GetPointer(),
                                                                                                  out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSurface, out_hp_ppSurface, format::ApiCall_IDXGIDevice_CreateSurface);
        }
        CheckReplayResult("IDXGIDevice_CreateSurface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice_CreateSurface>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            NumSurfaces,
            Usage,
            pSharedResource,
            ppSurface);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice_QueryResourceResidency>::Dispatch(
            this,
            call_info,
            replay_object,
            ppResources,
            pResidencyStatus,
            NumResources);
        auto in_ppResources = MapObjects<IUnknown>(ppResources, NumResources);
        auto replay_result = reinterpret_cast<IDXGIDevice*>(replay_object->object)->QueryResourceResidency(in_ppResources,
                                                                                                           pResidencyStatus->GetPointer(),
                                                                                                           NumResources);
        CheckReplayResult("IDXGIDevice_QueryResourceResidency", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice_QueryResourceResidency>::Dispatch(
            this,
            call_info,
            replay_object,
            ppResources,
            pResidencyStatus,
            NumResources);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    INT                                         Priority)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice_SetGPUThreadPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            Priority);
        auto replay_result = reinterpret_cast<IDXGIDevice*>(replay_object->object)->SetGPUThreadPriority(Priority);
        CheckReplayResult("IDXGIDevice_SetGPUThreadPriority", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice_SetGPUThreadPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            Priority);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<INT>*                        pPriority)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice_GetGPUThreadPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            pPriority);
        auto replay_result = reinterpret_cast<IDXGIDevice*>(replay_object->object)->GetGPUThreadPriority(pPriority->GetPointer());
        CheckReplayResult("IDXGIDevice_GetGPUThreadPriority", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice_GetGPUThreadPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            pPriority);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory1_EnumAdapters1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Adapter,
    HandlePointerDecoder<IDXGIAdapter1*>*       ppAdapter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory1_EnumAdapters1>::Dispatch(
            this,
            call_info,
            replay_object,
            Adapter,
            ppAdapter);
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto out_p_ppAdapter    = ppAdapter->GetPointer();
        auto out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactory1*>(replay_object->object)->EnumAdapters1(Adapter,
                                                                                                    out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppAdapter, out_hp_ppAdapter, format::ApiCall_IDXGIFactory1_EnumAdapters1);
        }
        CheckReplayResult("IDXGIFactory1_EnumAdapters1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory1_EnumAdapters1>::Dispatch(
            this,
            call_info,
            replay_object,
            Adapter,
            ppAdapter);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory1_IsCurrent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory1_IsCurrent>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIFactory1*>(replay_object->object)->IsCurrent();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory1_IsCurrent>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter1_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIAdapter1*>(replay_object->object)->GetDesc1(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter1_GetDesc1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter1_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        MaxLatency)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice1_SetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            MaxLatency);
        auto replay_result = reinterpret_cast<IDXGIDevice1*>(replay_object->object)->SetMaximumFrameLatency(MaxLatency);
        CheckReplayResult("IDXGIDevice1_SetMaximumFrameLatency", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice1_SetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            MaxLatency);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice1_GetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            pMaxLatency);
        auto replay_result = reinterpret_cast<IDXGIDevice1*>(replay_object->object)->GetMaximumFrameLatency(pMaxLatency->GetPointer());
        CheckReplayResult("IDXGIDevice1_GetMaximumFrameLatency", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice1_GetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            pMaxLatency);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDisplayControl_IsStereoEnabled>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIDisplayControl*>(replay_object->object)->IsStereoEnabled();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDisplayControl_IsStereoEnabled>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        enabled)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDisplayControl_SetStereoEnabled>::Dispatch(
            this,
            call_info,
            replay_object,
            enabled);
        reinterpret_cast<IDXGIDisplayControl*>(replay_object->object)->SetStereoEnabled(enabled);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDisplayControl_SetStereoEnabled>::Dispatch(
            this,
            call_info,
            replay_object,
            enabled);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->GetDesc(pDesc->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_AcquireNextFrame>::Dispatch(
            this,
            call_info,
            replay_object,
            TimeoutInMilliseconds,
            pFrameInfo,
            ppDesktopResource);
        if(!ppDesktopResource->IsNull()) ppDesktopResource->SetHandleLength(1);
        auto out_p_ppDesktopResource    = ppDesktopResource->GetPointer();
        auto out_hp_ppDesktopResource   = ppDesktopResource->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->AcquireNextFrame(TimeoutInMilliseconds,
                                                                                                                pFrameInfo->GetPointer(),
                                                                                                                out_hp_ppDesktopResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDesktopResource, out_hp_ppDesktopResource, format::ApiCall_IDXGIOutputDuplication_AcquireNextFrame);
        }
        CheckReplayResult("IDXGIOutputDuplication_AcquireNextFrame", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_AcquireNextFrame>::Dispatch(
            this,
            call_info,
            replay_object,
            TimeoutInMilliseconds,
            pFrameInfo,
            ppDesktopResource);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects>::Dispatch(
            this,
            call_info,
            replay_object,
            DirtyRectsBufferSize,
            pDirtyRectsBuffer,
            pDirtyRectsBufferSizeRequired);
        auto replay_result = reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->GetFrameDirtyRects(DirtyRectsBufferSize,
                                                                                                                  pDirtyRectsBuffer->GetPointer(),
                                                                                                                  pDirtyRectsBufferSizeRequired->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFrameDirtyRects", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects>::Dispatch(
            this,
            call_info,
            replay_object,
            DirtyRectsBufferSize,
            pDirtyRectsBuffer,
            pDirtyRectsBufferSizeRequired);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameMoveRects>::Dispatch(
            this,
            call_info,
            replay_object,
            MoveRectsBufferSize,
            pMoveRectBuffer,
            pMoveRectsBufferSizeRequired);
        auto replay_result = reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->GetFrameMoveRects(MoveRectsBufferSize,
                                                                                                                 pMoveRectBuffer->GetPointer(),
                                                                                                                 pMoveRectsBufferSizeRequired->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFrameMoveRects", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameMoveRects>::Dispatch(
            this,
            call_info,
            replay_object,
            MoveRectsBufferSize,
            pMoveRectBuffer,
            pMoveRectsBufferSizeRequired);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFramePointerShape>::Dispatch(
            this,
            call_info,
            replay_object,
            PointerShapeBufferSize,
            pPointerShapeBuffer,
            pPointerShapeBufferSizeRequired,
            pPointerShapeInfo);
        auto replay_result = reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->GetFramePointerShape(PointerShapeBufferSize,
                                                                                                                    pPointerShapeBuffer->GetPointer(),
                                                                                                                    pPointerShapeBufferSizeRequired->GetPointer(),
                                                                                                                    pPointerShapeInfo->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFramePointerShape", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFramePointerShape>::Dispatch(
            this,
            call_info,
            replay_object,
            PointerShapeBufferSize,
            pPointerShapeBuffer,
            pPointerShapeBufferSizeRequired,
            pPointerShapeInfo);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_MapDesktopSurface>::Dispatch(
            this,
            call_info,
            replay_object,
            pLockedRect);
        auto replay_result = reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->MapDesktopSurface(pLockedRect->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_MapDesktopSurface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_MapDesktopSurface>::Dispatch(
            this,
            call_info,
            replay_object,
            pLockedRect);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->UnMapDesktopSurface();
        CheckReplayResult("IDXGIOutputDuplication_UnMapDesktopSurface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_ReleaseFrame>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIOutputDuplication*>(replay_object->object)->ReleaseFrame();
        CheckReplayResult("IDXGIOutputDuplication_ReleaseFrame", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutputDuplication_ReleaseFrame>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISurface2_GetResource>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppParentResource,
            pSubresourceIndex);
        if(!ppParentResource->IsNull()) ppParentResource->SetHandleLength(1);
        auto out_p_ppParentResource    = ppParentResource->GetPointer();
        auto out_hp_ppParentResource   = ppParentResource->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGISurface2*>(replay_object->object)->GetResource(*riid.decoded_value,
                                                                                                  out_hp_ppParentResource,
                                                                                                  pSubresourceIndex->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppParentResource, out_hp_ppParentResource, format::ApiCall_IDXGISurface2_GetResource);
        }
        CheckReplayResult("IDXGISurface2_GetResource", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISurface2_GetResource>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppParentResource,
            pSubresourceIndex);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        index,
    HandlePointerDecoder<IDXGISurface2*>*       ppSurface)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIResource1_CreateSubresourceSurface>::Dispatch(
            this,
            call_info,
            replay_object,
            index,
            ppSurface);
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(1);
        auto out_p_ppSurface    = ppSurface->GetPointer();
        auto out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIResource1*>(replay_object->object)->CreateSubresourceSurface(index,
                                                                                                                out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSurface, out_hp_ppSurface, format::ApiCall_IDXGIResource1_CreateSubresourceSurface);
        }
        CheckReplayResult("IDXGIResource1_CreateSubresourceSurface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIResource1_CreateSubresourceSurface>::Dispatch(
            this,
            call_info,
            replay_object,
            index,
            ppSurface);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pAttributes,
            dwAccess,
            lpName,
            pHandle);
        if(!pHandle->IsNull())
        {
            pHandle->AllocateOutputData(1);
        }
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = reinterpret_cast<IDXGIResource1*>(replay_object->object)->CreateSharedHandle(pAttributes->GetPointer(),
                                                                                                          dwAccess,
                                                                                                          lpName->GetPointer(),
                                                                                                          out_op_pHandle);
        CheckReplayResult("IDXGIResource1_CreateSharedHandle", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pAttributes,
            dwAccess,
            lpName,
            pHandle);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice2_OfferResources>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            Priority);
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        auto replay_result = reinterpret_cast<IDXGIDevice2*>(replay_object->object)->OfferResources(NumResources,
                                                                                                    in_ppResources,
                                                                                                    Priority);
        CheckReplayResult("IDXGIDevice2_OfferResources", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice2_OfferResources>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            Priority);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice2_ReclaimResources>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            pDiscarded);
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        auto replay_result = reinterpret_cast<IDXGIDevice2*>(replay_object->object)->ReclaimResources(NumResources,
                                                                                                      in_ppResources,
                                                                                                      pDiscarded->GetPointer());
        CheckReplayResult("IDXGIDevice2_ReclaimResources", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice2_ReclaimResources>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            pDiscarded);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent, "IDXGIDevice2_EnqueueSetEvent"));
        auto replay_result = reinterpret_cast<IDXGIDevice2*>(replay_object->object)->EnqueueSetEvent(in_hEvent);
        CheckReplayResult("IDXGIDevice2_EnqueueSetEvent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->GetDesc1(pDesc->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetDesc1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetFullscreenDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->GetFullscreenDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetFullscreenDesc", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetFullscreenDesc>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetHwnd(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint64_t, void*>*            pHwnd)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd>::Dispatch(
            this,
            call_info,
            replay_object,
            pHwnd);
        if(!pHwnd->IsNull())
        {
            pHwnd->AllocateOutputData(1);
        }
        auto out_p_pHwnd    = pHwnd->GetPointer();
        auto out_op_pHwnd   = reinterpret_cast<HWND*>(pHwnd->GetOutputPointer());
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->GetHwnd(out_op_pHwnd);
        CheckReplayResult("IDXGISwapChain1_GetHwnd", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd>::Dispatch(
            this,
            call_info,
            replay_object,
            pHwnd);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetCoreWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            refiid,
            ppUnk);
        if(!ppUnk->IsNull()) ppUnk->SetHandleLength(1);
        auto out_p_ppUnk    = ppUnk->GetPointer();
        auto out_hp_ppUnk   = ppUnk->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->GetCoreWindow(*refiid.decoded_value,
                                                                                                      out_hp_ppUnk);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppUnk, out_hp_ppUnk, format::ApiCall_IDXGISwapChain1_GetCoreWindow);
        }
        CheckReplayResult("IDXGISwapChain1_GetCoreWindow", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetCoreWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            refiid,
            ppUnk);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_Present1>::Dispatch(
            this,
            call_info,
            replay_object,
            SyncInterval,
            PresentFlags,
            pPresentParameters);
        auto replay_result = OverridePresent1(replay_object,
                                              return_value,
                                              SyncInterval,
                                              PresentFlags,
                                              pPresentParameters);
        CheckReplayResult("IDXGISwapChain1_Present1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_Present1>::Dispatch(
            this,
            call_info,
            replay_object,
            SyncInterval,
            PresentFlags,
            pPresentParameters);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->IsTemporaryMonoSupported();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<IDXGIOutput*>*         ppRestrictToOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetRestrictToOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            ppRestrictToOutput);
        if(!ppRestrictToOutput->IsNull()) ppRestrictToOutput->SetHandleLength(1);
        auto out_p_ppRestrictToOutput    = ppRestrictToOutput->GetPointer();
        auto out_hp_ppRestrictToOutput   = ppRestrictToOutput->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->GetRestrictToOutput(out_hp_ppRestrictToOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppRestrictToOutput, out_hp_ppRestrictToOutput, format::ApiCall_IDXGISwapChain1_GetRestrictToOutput);
        }
        CheckReplayResult("IDXGISwapChain1_GetRestrictToOutput", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetRestrictToOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            ppRestrictToOutput);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_SetBackgroundColor>::Dispatch(
            this,
            call_info,
            replay_object,
            pColor);
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->SetBackgroundColor(pColor->GetPointer());
        CheckReplayResult("IDXGISwapChain1_SetBackgroundColor", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_SetBackgroundColor>::Dispatch(
            this,
            call_info,
            replay_object,
            pColor);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetBackgroundColor>::Dispatch(
            this,
            call_info,
            replay_object,
            pColor);
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->GetBackgroundColor(pColor->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetBackgroundColor", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetBackgroundColor>::Dispatch(
            this,
            call_info,
            replay_object,
            pColor);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_SetRotation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_MODE_ROTATION                          Rotation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_SetRotation>::Dispatch(
            this,
            call_info,
            replay_object,
            Rotation);
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->SetRotation(Rotation);
        CheckReplayResult("IDXGISwapChain1_SetRotation", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_SetRotation>::Dispatch(
            this,
            call_info,
            replay_object,
            Rotation);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetRotation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<DXGI_MODE_ROTATION>*         pRotation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetRotation>::Dispatch(
            this,
            call_info,
            replay_object,
            pRotation);
        auto replay_result = reinterpret_cast<IDXGISwapChain1*>(replay_object->object)->GetRotation(pRotation->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetRotation", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain1_GetRotation>::Dispatch(
            this,
            call_info,
            replay_object,
            pRotation);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_IsWindowedStereoEnabled>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIFactory2*>(replay_object->object)->IsWindowedStereoEnabled();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_IsWindowedStereoEnabled>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            hWnd,
            pDesc,
            pFullscreenDesc,
            pRestrictToOutput,
            ppSwapChain);
        auto in_pDevice = GetObjectInfo(pDevice);
        auto in_pRestrictToOutput = GetObjectInfo(pRestrictToOutput);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
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
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info), format::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForHwnd", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            hWnd,
            pDesc,
            pFullscreenDesc,
            pRestrictToOutput,
            ppSwapChain);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            pWindow,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
        auto in_pDevice = GetObjectInfo(pDevice);
        auto in_pWindow = GetObjectInfo(pWindow);
        auto in_pRestrictToOutput = GetObjectInfo(pRestrictToOutput);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateSwapChainForCoreWindow(replay_object,
                                                                  return_value,
                                                                  in_pDevice,
                                                                  in_pWindow,
                                                                  pDesc,
                                                                  in_pRestrictToOutput,
                                                                  ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info), format::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForCoreWindow", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            pWindow,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hResource,
    StructPointerDecoder<Decoded_LUID>*         pLuid)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid>::Dispatch(
            this,
            call_info,
            replay_object,
            hResource,
            pLuid);
        auto in_hResource = static_cast<HANDLE>(PreProcessExternalObject(hResource, format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid, "IDXGIFactory2_GetSharedResourceAdapterLuid"));
        auto replay_result = reinterpret_cast<IDXGIFactory2*>(replay_object->object)->GetSharedResourceAdapterLuid(in_hResource,
                                                                                                                   pLuid->GetPointer());
        CheckReplayResult("IDXGIFactory2_GetSharedResourceAdapterLuid", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid>::Dispatch(
            this,
            call_info,
            replay_object,
            hResource,
            pLuid);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            WindowHandle,
            wMsg,
            pdwCookie);
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow, "IDXGIFactory2_RegisterStereoStatusWindow"));
        auto replay_result = reinterpret_cast<IDXGIFactory2*>(replay_object->object)->RegisterStereoStatusWindow(in_WindowHandle,
                                                                                                                 wMsg,
                                                                                                                 pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusWindow", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            WindowHandle,
            wMsg,
            pdwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent, "IDXGIFactory2_RegisterStereoStatusEvent"));
        auto replay_result = reinterpret_cast<IDXGIFactory2*>(replay_object->object)->RegisterStereoStatusEvent(in_hEvent,
                                                                                                                pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusEvent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterStereoStatus>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
        reinterpret_cast<IDXGIFactory2*>(replay_object->object)->UnregisterStereoStatus(dwCookie);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterStereoStatus>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            WindowHandle,
            wMsg,
            pdwCookie);
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow, "IDXGIFactory2_RegisterOcclusionStatusWindow"));
        auto replay_result = reinterpret_cast<IDXGIFactory2*>(replay_object->object)->RegisterOcclusionStatusWindow(in_WindowHandle,
                                                                                                                    wMsg,
                                                                                                                    pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusWindow", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow>::Dispatch(
            this,
            call_info,
            replay_object,
            WindowHandle,
            wMsg,
            pdwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent, "IDXGIFactory2_RegisterOcclusionStatusEvent"));
        auto replay_result = reinterpret_cast<IDXGIFactory2*>(replay_object->object)->RegisterOcclusionStatusEvent(in_hEvent,
                                                                                                                   pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusEvent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterOcclusionStatus>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
        reinterpret_cast<IDXGIFactory2*>(replay_object->object)->UnregisterOcclusionStatus(dwCookie);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterOcclusionStatus>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForComposition>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
        auto in_pDevice = GetObjectInfo(pDevice);
        auto in_pRestrictToOutput = GetObjectInfo(pRestrictToOutput);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateSwapChainForComposition(replay_object,
                                                                   return_value,
                                                                   in_pDevice,
                                                                   pDesc,
                                                                   in_pRestrictToOutput,
                                                                   ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), std::move(object_info), format::ApiCall_IDXGIFactory2_CreateSwapChainForComposition);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForComposition", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForComposition>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter2_GetDesc2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter2_GetDesc2>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIAdapter2*>(replay_object->object)->GetDesc2(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter2_GetDesc2", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter2_GetDesc2>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplayModeList1>::Dispatch(
            this,
            call_info,
            replay_object,
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIOutput1*>(replay_object->object)->GetDisplayModeList1(EnumFormat,
                                                                                                         Flags,
                                                                                                         pNumModes->GetPointer(),
                                                                                                         pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput1_GetDisplayModeList1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplayModeList1>::Dispatch(
            this,
            call_info,
            replay_object,
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput1_FindClosestMatchingMode1>::Dispatch(
            this,
            call_info,
            replay_object,
            pModeToMatch,
            pClosestMatch,
            pConcernedDevice);
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = reinterpret_cast<IDXGIOutput1*>(replay_object->object)->FindClosestMatchingMode1(pModeToMatch->GetPointer(),
                                                                                                              pClosestMatch->GetPointer(),
                                                                                                              in_pConcernedDevice);
        CheckReplayResult("IDXGIOutput1_FindClosestMatchingMode1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput1_FindClosestMatchingMode1>::Dispatch(
            this,
            call_info,
            replay_object,
            pModeToMatch,
            pClosestMatch,
            pConcernedDevice);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDestination)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplaySurfaceData1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDestination);
        auto in_pDestination = MapObject<IDXGIResource>(pDestination);
        auto replay_result = reinterpret_cast<IDXGIOutput1*>(replay_object->object)->GetDisplaySurfaceData1(in_pDestination);
        CheckReplayResult("IDXGIOutput1_GetDisplaySurfaceData1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplaySurfaceData1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDestination);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_DuplicateOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pDevice,
    HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput1_DuplicateOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            ppOutputDuplication);
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        if(!ppOutputDuplication->IsNull()) ppOutputDuplication->SetHandleLength(1);
        auto out_p_ppOutputDuplication    = ppOutputDuplication->GetPointer();
        auto out_hp_ppOutputDuplication   = ppOutputDuplication->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIOutput1*>(replay_object->object)->DuplicateOutput(in_pDevice,
                                                                                                     out_hp_ppOutputDuplication);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutputDuplication, out_hp_ppOutputDuplication, format::ApiCall_IDXGIOutput1_DuplicateOutput);
        }
        CheckReplayResult("IDXGIOutput1_DuplicateOutput", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput1_DuplicateOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            ppOutputDuplication);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice3_Trim(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice3_Trim>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<IDXGIDevice3*>(replay_object->object)->Trim();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice3_Trim>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetSourceSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Width,
    UINT                                        Height)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain2_SetSourceSize>::Dispatch(
            this,
            call_info,
            replay_object,
            Width,
            Height);
        auto replay_result = reinterpret_cast<IDXGISwapChain2*>(replay_object->object)->SetSourceSize(Width,
                                                                                                      Height);
        CheckReplayResult("IDXGISwapChain2_SetSourceSize", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain2_SetSourceSize>::Dispatch(
            this,
            call_info,
            replay_object,
            Width,
            Height);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetSourceSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pWidth,
    PointerDecoder<UINT>*                       pHeight)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetSourceSize>::Dispatch(
            this,
            call_info,
            replay_object,
            pWidth,
            pHeight);
        auto replay_result = reinterpret_cast<IDXGISwapChain2*>(replay_object->object)->GetSourceSize(pWidth->GetPointer(),
                                                                                                      pHeight->GetPointer());
        CheckReplayResult("IDXGISwapChain2_GetSourceSize", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetSourceSize>::Dispatch(
            this,
            call_info,
            replay_object,
            pWidth,
            pHeight);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        MaxLatency)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain2_SetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            MaxLatency);
        auto replay_result = reinterpret_cast<IDXGISwapChain2*>(replay_object->object)->SetMaximumFrameLatency(MaxLatency);
        CheckReplayResult("IDXGISwapChain2_SetMaximumFrameLatency", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain2_SetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            MaxLatency);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            pMaxLatency);
        auto replay_result = reinterpret_cast<IDXGISwapChain2*>(replay_object->object)->GetMaximumFrameLatency(pMaxLatency->GetPointer());
        CheckReplayResult("IDXGISwapChain2_GetMaximumFrameLatency", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetMaximumFrameLatency>::Dispatch(
            this,
            call_info,
            replay_object,
            pMaxLatency);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    uint64_t                                    return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGISwapChain2*>(replay_object->object)->GetFrameLatencyWaitableObject();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain2_SetMatrixTransform>::Dispatch(
            this,
            call_info,
            replay_object,
            pMatrix);
        auto replay_result = reinterpret_cast<IDXGISwapChain2*>(replay_object->object)->SetMatrixTransform(pMatrix->GetPointer());
        CheckReplayResult("IDXGISwapChain2_SetMatrixTransform", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain2_SetMatrixTransform>::Dispatch(
            this,
            call_info,
            replay_object,
            pMatrix);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetMatrixTransform>::Dispatch(
            this,
            call_info,
            replay_object,
            pMatrix);
        auto replay_result = reinterpret_cast<IDXGISwapChain2*>(replay_object->object)->GetMatrixTransform(pMatrix->GetPointer());
        CheckReplayResult("IDXGISwapChain2_GetMatrixTransform", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain2_GetMatrixTransform>::Dispatch(
            this,
            call_info,
            replay_object,
            pMatrix);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput2_SupportsOverlays(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput2_SupportsOverlays>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIOutput2*>(replay_object->object)->SupportsOverlays();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput2_SupportsOverlays>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory3_GetCreationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory3_GetCreationFlags>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIFactory3*>(replay_object->object)->GetCreationFlags();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory3_GetCreationFlags>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_PresentBuffer>::Dispatch(
            this,
            call_info,
            replay_object,
            BufferToPresent,
            SyncInterval,
            Flags);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->PresentBuffer(BufferToPresent,
                                                                                                           SyncInterval,
                                                                                                           Flags);
        CheckReplayResult("IDXGIDecodeSwapChain_PresentBuffer", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_PresentBuffer>::Dispatch(
            this,
            call_info,
            replay_object,
            BufferToPresent,
            SyncInterval,
            Flags);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetSourceRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->SetSourceRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_SetSourceRect", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetSourceRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetTargetRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->SetTargetRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_SetTargetRect", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetTargetRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Width,
    UINT                                        Height)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetDestSize>::Dispatch(
            this,
            call_info,
            replay_object,
            Width,
            Height);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->SetDestSize(Width,
                                                                                                         Height);
        CheckReplayResult("IDXGIDecodeSwapChain_SetDestSize", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetDestSize>::Dispatch(
            this,
            call_info,
            replay_object,
            Width,
            Height);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetSourceRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->GetSourceRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetSourceRect", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetSourceRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetTargetRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->GetTargetRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetTargetRect", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetTargetRect>::Dispatch(
            this,
            call_info,
            replay_object,
            pRect);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pWidth,
    PointerDecoder<UINT>*                       pHeight)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetDestSize>::Dispatch(
            this,
            call_info,
            replay_object,
            pWidth,
            pHeight);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->GetDestSize(pWidth->GetPointer(),
                                                                                                         pHeight->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetDestSize", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetDestSize>::Dispatch(
            this,
            call_info,
            replay_object,
            pWidth,
            pHeight);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         ColorSpace)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetColorSpace>::Dispatch(
            this,
            call_info,
            replay_object,
            ColorSpace);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->SetColorSpace(ColorSpace);
        CheckReplayResult("IDXGIDecodeSwapChain_SetColorSpace", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetColorSpace>::Dispatch(
            this,
            call_info,
            replay_object,
            ColorSpace);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetColorSpace>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGIDecodeSwapChain*>(replay_object->object)->GetColorSpace();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetColorSpace>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            hSurface,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        auto in_hSurface = static_cast<HANDLE>(PreProcessExternalObject(hSurface, format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle, "IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle"));
        auto in_pRestrictToOutput = MapObject<IDXGIOutput>(pRestrictToOutput);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactoryMedia*>(replay_object->object)->CreateSwapChainForCompositionSurfaceHandle(in_pDevice,
                                                                                                                                     in_hSurface,
                                                                                                                                     pDesc->GetPointer(),
                                                                                                                                     in_pRestrictToOutput,
                                                                                                                                     out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSwapChain, out_hp_ppSwapChain, format::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle);
        }
        CheckReplayResult("IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            hSurface,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            hSurface,
            pDesc,
            pYuvDecodeBuffers,
            pRestrictToOutput,
            ppSwapChain);
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        auto in_hSurface = static_cast<HANDLE>(PreProcessExternalObject(hSurface, format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle, "IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle"));
        auto in_pYuvDecodeBuffers = MapObject<IDXGIResource>(pYuvDecodeBuffers);
        auto in_pRestrictToOutput = MapObject<IDXGIOutput>(pRestrictToOutput);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactoryMedia*>(replay_object->object)->CreateDecodeSwapChainForCompositionSurfaceHandle(in_pDevice,
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            hSurface,
            pDesc,
            pYuvDecodeBuffers,
            pRestrictToOutput,
            ppSwapChain);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia>::Dispatch(
            this,
            call_info,
            replay_object,
            pStats);
        auto replay_result = reinterpret_cast<IDXGISwapChainMedia*>(replay_object->object)->GetFrameStatisticsMedia(pStats->GetPointer());
        CheckReplayResult("IDXGISwapChainMedia_GetFrameStatisticsMedia", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia>::Dispatch(
            this,
            call_info,
            replay_object,
            pStats);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        Duration)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChainMedia_SetPresentDuration>::Dispatch(
            this,
            call_info,
            replay_object,
            Duration);
        auto replay_result = reinterpret_cast<IDXGISwapChainMedia*>(replay_object->object)->SetPresentDuration(Duration);
        CheckReplayResult("IDXGISwapChainMedia_SetPresentDuration", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChainMedia_SetPresentDuration>::Dispatch(
            this,
            call_info,
            replay_object,
            Duration);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            DesiredPresentDuration,
            pClosestSmallerPresentDuration,
            pClosestLargerPresentDuration);
        auto replay_result = reinterpret_cast<IDXGISwapChainMedia*>(replay_object->object)->CheckPresentDurationSupport(DesiredPresentDuration,
                                                                                                                        pClosestSmallerPresentDuration->GetPointer(),
                                                                                                                        pClosestLargerPresentDuration->GetPointer());
        CheckReplayResult("IDXGISwapChainMedia_CheckPresentDurationSupport", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            DesiredPresentDuration,
            pClosestSmallerPresentDuration,
            pClosestLargerPresentDuration);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput3_CheckOverlaySupport>::Dispatch(
            this,
            call_info,
            replay_object,
            EnumFormat,
            pConcernedDevice,
            pFlags);
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = reinterpret_cast<IDXGIOutput3*>(replay_object->object)->CheckOverlaySupport(EnumFormat,
                                                                                                         in_pConcernedDevice,
                                                                                                         pFlags->GetPointer());
        CheckReplayResult("IDXGIOutput3_CheckOverlaySupport", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput3_CheckOverlaySupport>::Dispatch(
            this,
            call_info,
            replay_object,
            EnumFormat,
            pConcernedDevice,
            pFlags);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<IDXGISwapChain3*>(replay_object->object)->GetCurrentBackBufferIndex();
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace,
    PointerDecoder<UINT>*                       pColorSpaceSupport)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain3_CheckColorSpaceSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            ColorSpace,
            pColorSpaceSupport);
        auto replay_result = reinterpret_cast<IDXGISwapChain3*>(replay_object->object)->CheckColorSpaceSupport(ColorSpace,
                                                                                                               pColorSpaceSupport->GetPointer());
        CheckReplayResult("IDXGISwapChain3_CheckColorSpaceSupport", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain3_CheckColorSpaceSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            ColorSpace,
            pColorSpaceSupport);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_SetColorSpace1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain3_SetColorSpace1>::Dispatch(
            this,
            call_info,
            replay_object,
            ColorSpace);
        auto replay_result = reinterpret_cast<IDXGISwapChain3*>(replay_object->object)->SetColorSpace1(ColorSpace);
        CheckReplayResult("IDXGISwapChain3_SetColorSpace1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain3_SetColorSpace1>::Dispatch(
            this,
            call_info,
            replay_object,
            ColorSpace);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain3_ResizeBuffers1>::Dispatch(
            this,
            call_info,
            replay_object,
            BufferCount,
            Width,
            Height,
            Format,
            SwapChainFlags,
            pCreationNodeMask,
            ppPresentQueue);
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain3_ResizeBuffers1>::Dispatch(
            this,
            call_info,
            replay_object,
            BufferCount,
            Width,
            Height,
            Format,
            SwapChainFlags,
            pCreationNodeMask,
            ppPresentQueue);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            Format,
            ColorSpace,
            pConcernedDevice,
            pFlags);
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = reinterpret_cast<IDXGIOutput4*>(replay_object->object)->CheckOverlayColorSpaceSupport(Format,
                                                                                                                   ColorSpace,
                                                                                                                   in_pConcernedDevice,
                                                                                                                   pFlags->GetPointer());
        CheckReplayResult("IDXGIOutput4_CheckOverlayColorSpaceSupport", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            Format,
            ColorSpace,
            pConcernedDevice,
            pFlags);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory4_EnumAdapterByLuid>::Dispatch(
            this,
            call_info,
            replay_object,
            AdapterLuid,
            riid,
            ppvAdapter);
        if(!ppvAdapter->IsNull()) ppvAdapter->SetHandleLength(1);
        auto out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactory4*>(replay_object->object)->EnumAdapterByLuid(*AdapterLuid.decoded_value,
                                                                                                        *riid.decoded_value,
                                                                                                        out_hp_ppvAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter, format::ApiCall_IDXGIFactory4_EnumAdapterByLuid);
        }
        CheckReplayResult("IDXGIFactory4_EnumAdapterByLuid", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory4_EnumAdapterByLuid>::Dispatch(
            this,
            call_info,
            replay_object,
            AdapterLuid,
            riid,
            ppvAdapter);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvAdapter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory4_EnumWarpAdapter>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppvAdapter);
        if(!ppvAdapter->IsNull()) ppvAdapter->SetHandleLength(1);
        auto out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactory4*>(replay_object->object)->EnumWarpAdapter(*riid.decoded_value,
                                                                                                      out_hp_ppvAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter, format::ApiCall_IDXGIFactory4_EnumWarpAdapter);
        }
        CheckReplayResult("IDXGIFactory4_EnumWarpAdapter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory4_EnumWarpAdapter>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppvAdapter);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent, "IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent"));
        auto replay_result = reinterpret_cast<IDXGIAdapter3*>(replay_object->object)->RegisterHardwareContentProtectionTeardownStatusEvent(in_hEvent,
                                                                                                                                           pdwCookie->GetPointer());
        CheckReplayResult("IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
        reinterpret_cast<IDXGIAdapter3*>(replay_object->object)->UnregisterHardwareContentProtectionTeardownStatus(dwCookie);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo>::Dispatch(
            this,
            call_info,
            replay_object,
            NodeIndex,
            MemorySegmentGroup,
            pVideoMemoryInfo);
        auto replay_result = reinterpret_cast<IDXGIAdapter3*>(replay_object->object)->QueryVideoMemoryInfo(NodeIndex,
                                                                                                           MemorySegmentGroup,
                                                                                                           pVideoMemoryInfo->GetPointer());
        CheckReplayResult("IDXGIAdapter3_QueryVideoMemoryInfo", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo>::Dispatch(
            this,
            call_info,
            replay_object,
            NodeIndex,
            MemorySegmentGroup,
            pVideoMemoryInfo);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter3_SetVideoMemoryReservation>::Dispatch(
            this,
            call_info,
            replay_object,
            NodeIndex,
            MemorySegmentGroup,
            Reservation);
        auto replay_result = reinterpret_cast<IDXGIAdapter3*>(replay_object->object)->SetVideoMemoryReservation(NodeIndex,
                                                                                                                MemorySegmentGroup,
                                                                                                                Reservation);
        CheckReplayResult("IDXGIAdapter3_SetVideoMemoryReservation", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter3_SetVideoMemoryReservation>::Dispatch(
            this,
            call_info,
            replay_object,
            NodeIndex,
            MemorySegmentGroup,
            Reservation);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent, "IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent"));
        auto replay_result = reinterpret_cast<IDXGIAdapter3*>(replay_object->object)->RegisterVideoMemoryBudgetChangeNotificationEvent(in_hEvent,
                                                                                                                                       pdwCookie->GetPointer());
        CheckReplayResult("IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
        reinterpret_cast<IDXGIAdapter3*>(replay_object->object)->UnregisterVideoMemoryBudgetChangeNotification(dwCookie);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput5_DuplicateOutput1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            Flags,
            SupportedFormatsCount,
            pSupportedFormats,
            ppOutputDuplication);
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        if(!ppOutputDuplication->IsNull()) ppOutputDuplication->SetHandleLength(1);
        auto out_p_ppOutputDuplication    = ppOutputDuplication->GetPointer();
        auto out_hp_ppOutputDuplication   = ppOutputDuplication->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIOutput5*>(replay_object->object)->DuplicateOutput1(in_pDevice,
                                                                                                      Flags,
                                                                                                      SupportedFormatsCount,
                                                                                                      pSupportedFormats->GetPointer(),
                                                                                                      out_hp_ppOutputDuplication);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppOutputDuplication, out_hp_ppOutputDuplication, format::ApiCall_IDXGIOutput5_DuplicateOutput1);
        }
        CheckReplayResult("IDXGIOutput5_DuplicateOutput1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput5_DuplicateOutput1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDevice,
            Flags,
            SupportedFormatsCount,
            pSupportedFormats,
            ppOutputDuplication);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGISwapChain4_SetHDRMetaData>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            Size,
            pMetaData);
        auto replay_result = reinterpret_cast<IDXGISwapChain4*>(replay_object->object)->SetHDRMetaData(Type,
                                                                                                       Size,
                                                                                                       pMetaData->GetPointer());
        CheckReplayResult("IDXGISwapChain4_SetHDRMetaData", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGISwapChain4_SetHDRMetaData>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            Size,
            pMetaData);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice4_OfferResources1>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            Priority,
            Flags);
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        auto replay_result = reinterpret_cast<IDXGIDevice4*>(replay_object->object)->OfferResources1(NumResources,
                                                                                                     in_ppResources,
                                                                                                     Priority,
                                                                                                     Flags);
        CheckReplayResult("IDXGIDevice4_OfferResources1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice4_OfferResources1>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            Priority,
            Flags);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIDevice4_ReclaimResources1>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            pResults);
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources, NumResources);
        auto replay_result = reinterpret_cast<IDXGIDevice4*>(replay_object->object)->ReclaimResources1(NumResources,
                                                                                                       in_ppResources,
                                                                                                       pResults->GetPointer());
        CheckReplayResult("IDXGIDevice4_ReclaimResources1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIDevice4_ReclaimResources1>::Dispatch(
            this,
            call_info,
            replay_object,
            NumResources,
            ppResources,
            pResults);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter4_GetDesc3(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIAdapter4_GetDesc3>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIAdapter4*>(replay_object->object)->GetDesc3(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter4_GetDesc3", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIAdapter4_GetDesc3>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput6_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput6_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        auto replay_result = reinterpret_cast<IDXGIOutput6*>(replay_object->object)->GetDesc1(pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput6_GetDesc1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput6_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            pFlags);
        auto replay_result = reinterpret_cast<IDXGIOutput6*>(replay_object->object)->CheckHardwareCompositionSupport(pFlags->GetPointer());
        CheckReplayResult("IDXGIOutput6_CheckHardwareCompositionSupport", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport>::Dispatch(
            this,
            call_info,
            replay_object,
            pFlags);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference>::Dispatch(
            this,
            call_info,
            replay_object,
            Adapter,
            GpuPreference,
            riid,
            ppvAdapter);
        if(!ppvAdapter->IsNull()) ppvAdapter->SetHandleLength(1);
        auto out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = reinterpret_cast<IDXGIFactory6*>(replay_object->object)->EnumAdapterByGpuPreference(Adapter,
                                                                                                                 GpuPreference,
                                                                                                                 *riid.decoded_value,
                                                                                                                 out_hp_ppvAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter, format::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference);
        }
        CheckReplayResult("IDXGIFactory6_EnumAdapterByGpuPreference", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference>::Dispatch(
            this,
            call_info,
            replay_object,
            Adapter,
            GpuPreference,
            riid,
            ppvAdapter);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent, "IDXGIFactory7_RegisterAdaptersChangedEvent"));
        auto replay_result = reinterpret_cast<IDXGIFactory7*>(replay_object->object)->RegisterAdaptersChangedEvent(in_hEvent,
                                                                                                                   pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory7_RegisterAdaptersChangedEvent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            hEvent,
            pdwCookie);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DWORD                                       dwCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
        auto replay_result = reinterpret_cast<IDXGIFactory7*>(replay_object->object)->UnregisterAdaptersChangedEvent(dwCookie);
        CheckReplayResult("IDXGIFactory7_UnregisterAdaptersChangedEvent", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            dwCookie);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Object_GetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            guid,
            pDataSize,
            pData);
        auto replay_result = reinterpret_cast<ID3D12Object*>(replay_object->object)->GetPrivateData(*guid.decoded_value,
                                                                                                    pDataSize->GetPointer(),
                                                                                                    pData->GetPointer());
        CheckReplayResult("ID3D12Object_GetPrivateData", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Object_GetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            guid,
            pDataSize,
            pData);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Object_SetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            guid,
            DataSize,
            pData);
        auto replay_result = reinterpret_cast<ID3D12Object*>(replay_object->object)->SetPrivateData(*guid.decoded_value,
                                                                                                    DataSize,
                                                                                                    pData->GetPointer());
        CheckReplayResult("ID3D12Object_SetPrivateData", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Object_SetPrivateData>::Dispatch(
            this,
            call_info,
            replay_object,
            guid,
            DataSize,
            pData);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_SetPrivateDataInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                guid,
    format::HandleId                            pData)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Object_SetPrivateDataInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            guid,
            pData);
        auto in_pData = MapObject<IUnknown>(pData);
        auto replay_result = reinterpret_cast<ID3D12Object*>(replay_object->object)->SetPrivateDataInterface(*guid.decoded_value,
                                                                                                             in_pData);
        CheckReplayResult("ID3D12Object_SetPrivateDataInterface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Object_SetPrivateDataInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            guid,
            pData);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Object_SetName>::Dispatch(
            this,
            call_info,
            replay_object,
            Name);
        auto replay_result = OverrideSetName(replay_object,
                                             return_value,
                                             Name);
        CheckReplayResult("ID3D12Object_SetName", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Object_SetName>::Dispatch(
            this,
            call_info,
            replay_object,
            Name);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceChild_GetDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDevice)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceChild_GetDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppvDevice);
        if(!ppvDevice->IsNull()) ppvDevice->SetHandleLength(1);
        auto out_p_ppvDevice    = ppvDevice->GetPointer();
        auto out_hp_ppvDevice   = ppvDevice->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12DeviceChild*>(replay_object->object)->GetDevice(*riid.decoded_value,
                                                                                                    out_hp_ppvDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDevice, out_hp_ppvDevice, format::ApiCall_ID3D12DeviceChild_GetDevice);
        }
        CheckReplayResult("ID3D12DeviceChild_GetDevice", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceChild_GetDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppvDevice);
    }
}

void Dx12ReplayConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12RootSignatureDeserializer*>(replay_object->object)->GetRootSignatureDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D_ROOT_SIGNATURE_VERSION                  convertToVersion,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* ppDesc)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion>::Dispatch(
            this,
            call_info,
            replay_object,
            convertToVersion,
            ppDesc);
        auto in_ppDesc    = ppDesc->GetPointer();
        auto replay_result = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer*>(replay_object->object)->GetRootSignatureDescAtVersion(convertToVersion,
                                                                                                                                               const_cast<const D3D12_VERSIONED_ROOT_SIGNATURE_DESC**>(&in_ppDesc));
        CheckReplayResult("ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion>::Dispatch(
            this,
            call_info,
            replay_object,
            convertToVersion,
            ppDesc);
    }
}

void Dx12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12VersionedRootSignatureDeserializer*>(replay_object->object)->GetUnconvertedRootSignatureDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Heap_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_HEAP_DESC                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Heap_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Heap*>(replay_object->object)->GetDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Heap_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource_Map>::Dispatch(
            this,
            call_info,
            replay_object,
            Subresource,
            pReadRange,
            ppData);
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource_Map>::Dispatch(
            this,
            call_info,
            replay_object,
            Subresource,
            pReadRange,
            ppData);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource_Unmap>::Dispatch(
            this,
            call_info,
            replay_object,
            Subresource,
            pWrittenRange);
        OverrideResourceUnmap(replay_object,
                              Subresource,
                              pWrittenRange);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource_Unmap>::Dispatch(
            this,
            call_info,
            replay_object,
            Subresource,
            pWrittenRange);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC                 return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Resource*>(replay_object->object)->GetDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = OverrideGetGpuVirtualAddress(replay_object,
                                                          return_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource_ReadFromSubresource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstData,
            DstRowPitch,
            DstDepthPitch,
            SrcSubresource,
            pSrcBox);
        auto replay_result = OverrideReadFromSubresource(replay_object,
                                                         return_value,
                                                         pDstData,
                                                         DstRowPitch,
                                                         DstDepthPitch,
                                                         SrcSubresource,
                                                         pSrcBox);
        CheckReplayResult("ID3D12Resource_ReadFromSubresource", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource_ReadFromSubresource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstData,
            DstRowPitch,
            DstDepthPitch,
            SrcSubresource,
            pSrcBox);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_GetHeapProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    PointerDecoder<D3D12_HEAP_FLAGS>*           pHeapFlags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource_GetHeapProperties>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            pHeapFlags);
        auto replay_result = reinterpret_cast<ID3D12Resource*>(replay_object->object)->GetHeapProperties(pHeapProperties->GetPointer(),
                                                                                                         pHeapFlags->GetPointer());
        CheckReplayResult("ID3D12Resource_GetHeapProperties", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource_GetHeapProperties>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            pHeapFlags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandAllocator_Reset(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandAllocator_Reset>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12CommandAllocator*>(replay_object->object)->Reset();
        CheckReplayResult("ID3D12CommandAllocator_Reset", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandAllocator_Reset>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Fence_GetCompletedValue>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = OverrideGetCompletedValue(replay_object,
                                                       return_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Fence_GetCompletedValue>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion>::Dispatch(
            this,
            call_info,
            replay_object,
            Value,
            hEvent);
        auto replay_result = OverrideSetEventOnCompletion(replay_object,
                                                          return_value,
                                                          Value,
                                                          hEvent);
        CheckReplayResult("ID3D12Fence_SetEventOnCompletion", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion>::Dispatch(
            this,
            call_info,
            replay_object,
            Value,
            hEvent);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Fence_Signal>::Dispatch(
            this,
            call_info,
            replay_object,
            Value);
        auto replay_result = OverrideFenceSignal(replay_object,
                                                 return_value,
                                                 Value);
        CheckReplayResult("ID3D12Fence_Signal", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Fence_Signal>::Dispatch(
            this,
            call_info,
            replay_object,
            Value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence1_GetCreationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_FENCE_FLAGS                           return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Fence1_GetCreationFlags>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Fence1*>(replay_object->object)->GetCreationFlags();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Fence1_GetCreationFlags>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineState_GetCachedBlob(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12PipelineState_GetCachedBlob>::Dispatch(
            this,
            call_info,
            replay_object,
            ppBlob);
        if(!ppBlob->IsNull()) ppBlob->SetHandleLength(1);
        auto out_p_ppBlob    = ppBlob->GetPointer();
        auto out_hp_ppBlob   = ppBlob->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12PipelineState*>(replay_object->object)->GetCachedBlob(out_hp_ppBlob);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppBlob, out_hp_ppBlob, format::ApiCall_ID3D12PipelineState_GetCachedBlob);
        }
        CheckReplayResult("ID3D12PipelineState_GetCachedBlob", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12PipelineState_GetCachedBlob>::Dispatch(
            this,
            call_info,
            replay_object,
            ppBlob);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DescriptorHeap_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_DESCRIPTOR_HEAP_DESC          return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DescriptorHeap*>(replay_object->object)->GetDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = OverrideGetCPUDescriptorHandleForHeapStart(replay_object,
                                                                        return_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = OverrideGetGPUDescriptorHandleForHeapStart(replay_object,
                                                                        return_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandList_GetType(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_COMMAND_LIST_TYPE                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandList_GetType>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12CommandList*>(replay_object->object)->GetType();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandList_GetType>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_Close(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->Close();
        CheckReplayResult("ID3D12GraphicsCommandList_Close", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset>::Dispatch(
            this,
            call_info,
            replay_object,
            pAllocator,
            pInitialState);
        auto in_pAllocator = GetObjectInfo(pAllocator);
        auto in_pInitialState = GetObjectInfo(pInitialState);
        auto replay_result = OverrideCommandListReset(replay_object,
                                                      return_value,
                                                      in_pAllocator,
                                                      in_pInitialState);
        CheckReplayResult("ID3D12GraphicsCommandList_Reset", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset>::Dispatch(
            this,
            call_info,
            replay_object,
            pAllocator,
            pInitialState);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pPipelineState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearState>::Dispatch(
            this,
            call_info,
            replay_object,
            pPipelineState);
        auto in_pPipelineState = MapObject<ID3D12PipelineState>(pPipelineState);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ClearState(in_pPipelineState);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearState>::Dispatch(
            this,
            call_info,
            replay_object,
            pPipelineState);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced>::Dispatch(
            this,
            call_info,
            replay_object,
            VertexCountPerInstance,
            InstanceCount,
            StartVertexLocation,
            StartInstanceLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->DrawInstanced(VertexCountPerInstance,
                                                                                           InstanceCount,
                                                                                           StartVertexLocation,
                                                                                           StartInstanceLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced>::Dispatch(
            this,
            call_info,
            replay_object,
            VertexCountPerInstance,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced>::Dispatch(
            this,
            call_info,
            replay_object,
            IndexCountPerInstance,
            InstanceCount,
            StartIndexLocation,
            BaseVertexLocation,
            StartInstanceLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->DrawIndexedInstanced(IndexCountPerInstance,
                                                                                                  InstanceCount,
                                                                                                  StartIndexLocation,
                                                                                                  BaseVertexLocation,
                                                                                                  StartInstanceLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced>::Dispatch(
            this,
            call_info,
            replay_object,
            IndexCountPerInstance,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch>::Dispatch(
            this,
            call_info,
            replay_object,
            ThreadGroupCountX,
            ThreadGroupCountY,
            ThreadGroupCountZ);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->Dispatch(ThreadGroupCountX,
                                                                                      ThreadGroupCountY,
                                                                                      ThreadGroupCountZ);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch>::Dispatch(
            this,
            call_info,
            replay_object,
            ThreadGroupCountX,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstBuffer,
            DstOffset,
            pSrcBuffer,
            SrcOffset,
            NumBytes);
        auto in_pDstBuffer = GetObjectInfo(pDstBuffer);
        auto in_pSrcBuffer = GetObjectInfo(pSrcBuffer);
        OverrideCopyBufferRegion(replay_object,
                                 in_pDstBuffer,
                                 DstOffset,
                                 in_pSrcBuffer,
                                 SrcOffset,
                                 NumBytes);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstBuffer,
            DstOffset,
            pSrcBuffer,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion>::Dispatch(
            this,
            call_info,
            replay_object,
            pDst,
            DstX,
            DstY,
            DstZ,
            pSrc,
            pSrcBox);
        MapStructObjects(pDst->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(pSrc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideCopyTextureRegion(replay_object,
                                  pDst,
                                  DstX,
                                  DstY,
                                  DstZ,
                                  pSrc,
                                  pSrcBox);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion>::Dispatch(
            this,
            call_info,
            replay_object,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            pSrcResource);
        auto in_pDstResource = GetObjectInfo(pDstResource);
        auto in_pSrcResource = GetObjectInfo(pSrcResource);
        OverrideCopyResource(replay_object,
                             in_pDstResource,
                             in_pSrcResource);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            pSrcResource);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTiles>::Dispatch(
            this,
            call_info,
            replay_object,
            pTiledResource,
            pTileRegionStartCoordinate,
            pTileRegionSize,
            pBuffer,
            BufferStartOffsetInBytes,
            Flags);
        auto in_pTiledResource = MapObject<ID3D12Resource>(pTiledResource);
        auto in_pBuffer = MapObject<ID3D12Resource>(pBuffer);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->CopyTiles(in_pTiledResource,
                                                                                       pTileRegionStartCoordinate->GetPointer(),
                                                                                       pTileRegionSize->GetPointer(),
                                                                                       in_pBuffer,
                                                                                       BufferStartOffsetInBytes,
                                                                                       Flags);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTiles>::Dispatch(
            this,
            call_info,
            replay_object,
            pTiledResource,
            pTileRegionStartCoordinate,
            pTileRegionSize,
            pBuffer,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveSubresource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            DstSubresource,
            pSrcResource,
            SrcSubresource,
            Format);
        auto in_pDstResource = MapObject<ID3D12Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D12Resource>(pSrcResource);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ResolveSubresource(in_pDstResource,
                                                                                                DstSubresource,
                                                                                                in_pSrcResource,
                                                                                                SrcSubresource,
                                                                                                Format);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveSubresource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            DstSubresource,
            pSrcResource,
            SrcSubresource,
            Format);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D_PRIMITIVE_TOPOLOGY                      PrimitiveTopology)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology>::Dispatch(
            this,
            call_info,
            replay_object,
            PrimitiveTopology);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->IASetPrimitiveTopology(PrimitiveTopology);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology>::Dispatch(
            this,
            call_info,
            replay_object,
            PrimitiveTopology);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumViewports,
    StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetViewports>::Dispatch(
            this,
            call_info,
            replay_object,
            NumViewports,
            pViewports);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->RSSetViewports(NumViewports,
                                                                                            pViewports->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetViewports>::Dispatch(
            this,
            call_info,
            replay_object,
            NumViewports,
            pViewports);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects>::Dispatch(
            this,
            call_info,
            replay_object,
            NumRects,
            pRects);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->RSSetScissorRects(NumRects,
                                                                                               pRects->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects>::Dispatch(
            this,
            call_info,
            replay_object,
            NumRects,
            pRects);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    PointerDecoder<FLOAT>*                      BlendFactor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor>::Dispatch(
            this,
            call_info,
            replay_object,
            BlendFactor);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->OMSetBlendFactor(BlendFactor->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor>::Dispatch(
            this,
            call_info,
            replay_object,
            BlendFactor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetStencilRef(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        StencilRef)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef>::Dispatch(
            this,
            call_info,
            replay_object,
            StencilRef);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->OMSetStencilRef(StencilRef);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef>::Dispatch(
            this,
            call_info,
            replay_object,
            StencilRef);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pPipelineState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pPipelineState);
        auto in_pPipelineState = MapObject<ID3D12PipelineState>(pPipelineState);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetPipelineState(in_pPipelineState);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pPipelineState);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumBarriers,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier>::Dispatch(
            this,
            call_info,
            replay_object,
            NumBarriers,
            pBarriers);
        MapStructArrayObjects(pBarriers->GetMetaStructPointer(), pBarriers->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ResourceBarrier(NumBarriers,
                                                                                             pBarriers->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier>::Dispatch(
            this,
            call_info,
            replay_object,
            NumBarriers,
            pBarriers);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pCommandList)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle>::Dispatch(
            this,
            call_info,
            replay_object,
            pCommandList);
        auto in_pCommandList = MapObject<ID3D12GraphicsCommandList>(pCommandList);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ExecuteBundle(in_pCommandList);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle>::Dispatch(
            this,
            call_info,
            replay_object,
            pCommandList);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        NumDescriptorHeaps,
    HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps>::Dispatch(
            this,
            call_info,
            replay_object,
            NumDescriptorHeaps,
            ppDescriptorHeaps);
        auto in_ppDescriptorHeaps = MapObjects<ID3D12DescriptorHeap>(ppDescriptorHeaps, NumDescriptorHeaps);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetDescriptorHeaps(NumDescriptorHeaps,
                                                                                                in_ppDescriptorHeaps);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps>::Dispatch(
            this,
            call_info,
            replay_object,
            NumDescriptorHeaps,
            ppDescriptorHeaps);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pRootSignature)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pRootSignature);
        auto in_pRootSignature = MapObject<ID3D12RootSignature>(pRootSignature);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetComputeRootSignature(in_pRootSignature);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pRootSignature);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pRootSignature)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pRootSignature);
        auto in_pRootSignature = MapObject<ID3D12RootSignature>(pRootSignature);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetGraphicsRootSignature(in_pRootSignature);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pRootSignature);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         BaseDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BaseDescriptor);
        MapGpuDescriptorHandle(*BaseDescriptor.decoded_value);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetComputeRootDescriptorTable(RootParameterIndex,
                                                                                                           *BaseDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BaseDescriptor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         BaseDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BaseDescriptor);
        MapGpuDescriptorHandle(*BaseDescriptor.decoded_value);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetGraphicsRootDescriptorTable(RootParameterIndex,
                                                                                                            *BaseDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BaseDescriptor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    UINT                                        SrcData,
    UINT                                        DestOffsetIn32BitValues)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            SrcData,
            DestOffsetIn32BitValues);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetComputeRoot32BitConstant(RootParameterIndex,
                                                                                                         SrcData,
                                                                                                         DestOffsetIn32BitValues);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            SrcData,
            DestOffsetIn32BitValues);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetGraphicsRoot32BitConstant(RootParameterIndex,
                                                                                                          SrcData,
                                                                                                          DestOffsetIn32BitValues);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
            DestOffsetIn32BitValues);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetComputeRoot32BitConstants(RootParameterIndex,
                                                                                                          Num32BitValuesToSet,
                                                                                                          pSrcData->GetPointer(),
                                                                                                          DestOffsetIn32BitValues);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
            DestOffsetIn32BitValues);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetGraphicsRoot32BitConstants(RootParameterIndex,
                                                                                                           Num32BitValuesToSet,
                                                                                                           pSrcData->GetPointer(),
                                                                                                           DestOffsetIn32BitValues);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
            DestOffsetIn32BitValues);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
        MapGpuVirtualAddress(BufferLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetComputeRootConstantBufferView(RootParameterIndex,
                                                                                                              BufferLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
        MapGpuVirtualAddress(BufferLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetGraphicsRootConstantBufferView(RootParameterIndex,
                                                                                                               BufferLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
        MapGpuVirtualAddress(BufferLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetComputeRootShaderResourceView(RootParameterIndex,
                                                                                                              BufferLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
        MapGpuVirtualAddress(BufferLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetGraphicsRootShaderResourceView(RootParameterIndex,
                                                                                                               BufferLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
        MapGpuVirtualAddress(BufferLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetComputeRootUnorderedAccessView(RootParameterIndex,
                                                                                                               BufferLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
            BufferLocation);
        MapGpuVirtualAddress(BufferLocation);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetGraphicsRootUnorderedAccessView(RootParameterIndex,
                                                                                                                BufferLocation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            RootParameterIndex,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer>::Dispatch(
            this,
            call_info,
            replay_object,
            pView);
        MapStructObjects(pView->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideIASetIndexBuffer(replay_object,
                                 pView);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer>::Dispatch(
            this,
            call_info,
            replay_object,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers>::Dispatch(
            this,
            call_info,
            replay_object,
            StartSlot,
            NumViews,
            pViews);
        MapStructArrayObjects(pViews->GetMetaStructPointer(), pViews->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideIASetVertexBuffers(replay_object,
                                   StartSlot,
                                   NumViews,
                                   pViews);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers>::Dispatch(
            this,
            call_info,
            replay_object,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SOSetTargets>::Dispatch(
            this,
            call_info,
            replay_object,
            StartSlot,
            NumViews,
            pViews);
        MapStructArrayObjects(pViews->GetMetaStructPointer(), pViews->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SOSetTargets(StartSlot,
                                                                                          NumViews,
                                                                                          pViews->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SOSetTargets>::Dispatch(
            this,
            call_info,
            replay_object,
            StartSlot,
            NumViews,
            pViews);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets>::Dispatch(
            this,
            call_info,
            replay_object,
            NumRenderTargetDescriptors,
            pRenderTargetDescriptors,
            RTsSingleHandleToDescriptorRange,
            pDepthStencilDescriptor);
        MapStructArrayObjects(pRenderTargetDescriptors->GetMetaStructPointer(), pRenderTargetDescriptors->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(pDepthStencilDescriptor->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->OMSetRenderTargets(NumRenderTargetDescriptors,
                                                                                                pRenderTargetDescriptors->GetPointer(),
                                                                                                RTsSingleHandleToDescriptorRange,
                                                                                                pDepthStencilDescriptor->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets>::Dispatch(
            this,
            call_info,
            replay_object,
            NumRenderTargetDescriptors,
            pRenderTargetDescriptors,
            RTsSingleHandleToDescriptorRange,
            pDepthStencilDescriptor);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView>::Dispatch(
            this,
            call_info,
            replay_object,
            DepthStencilView,
            ClearFlags,
            Depth,
            Stencil,
            NumRects,
            pRects);
        MapStructObjects(&DepthStencilView, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ClearDepthStencilView(*DepthStencilView.decoded_value,
                                                                                                   ClearFlags,
                                                                                                   Depth,
                                                                                                   Stencil,
                                                                                                   NumRects,
                                                                                                   pRects->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView>::Dispatch(
            this,
            call_info,
            replay_object,
            DepthStencilView,
            ClearFlags,
            Depth,
            Stencil,
            NumRects,
            pRects);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView>::Dispatch(
            this,
            call_info,
            replay_object,
            RenderTargetView,
            ColorRGBA,
            NumRects,
            pRects);
        MapStructObjects(&RenderTargetView, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ClearRenderTargetView(*RenderTargetView.decoded_value,
                                                                                                   ColorRGBA->GetPointer(),
                                                                                                   NumRects,
                                                                                                   pRects->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView>::Dispatch(
            this,
            call_info,
            replay_object,
            RenderTargetView,
            ColorRGBA,
            NumRects,
            pRects);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint>::Dispatch(
            this,
            call_info,
            replay_object,
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            pResource,
            Values,
            NumRects,
            pRects);
        MapGpuDescriptorHandle(*ViewGPUHandleInCurrentHeap.decoded_value);
        MapStructObjects(&ViewCPUHandle, GetObjectInfoTable(), GetGpuVaTable());
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ClearUnorderedAccessViewUint(*ViewGPUHandleInCurrentHeap.decoded_value,
                                                                                                          *ViewCPUHandle.decoded_value,
                                                                                                          in_pResource,
                                                                                                          Values->GetPointer(),
                                                                                                          NumRects,
                                                                                                          pRects->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint>::Dispatch(
            this,
            call_info,
            replay_object,
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            pResource,
            Values,
            NumRects,
            pRects);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat>::Dispatch(
            this,
            call_info,
            replay_object,
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            pResource,
            Values,
            NumRects,
            pRects);
        MapGpuDescriptorHandle(*ViewGPUHandleInCurrentHeap.decoded_value);
        MapStructObjects(&ViewCPUHandle, GetObjectInfoTable(), GetGpuVaTable());
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ClearUnorderedAccessViewFloat(*ViewGPUHandleInCurrentHeap.decoded_value,
                                                                                                           *ViewCPUHandle.decoded_value,
                                                                                                           in_pResource,
                                                                                                           Values->GetPointer(),
                                                                                                           NumRects,
                                                                                                           pRects->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat>::Dispatch(
            this,
            call_info,
            replay_object,
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            pResource,
            Values,
            NumRects,
            pRects);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DiscardResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pRegion);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->DiscardResource(in_pResource,
                                                                                             pRegion->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DiscardResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pRegion);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pQueryHeap,
    D3D12_QUERY_TYPE                            Type,
    UINT                                        Index)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginQuery>::Dispatch(
            this,
            call_info,
            replay_object,
            pQueryHeap,
            Type,
            Index);
        auto in_pQueryHeap = MapObject<ID3D12QueryHeap>(pQueryHeap);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->BeginQuery(in_pQueryHeap,
                                                                                        Type,
                                                                                        Index);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginQuery>::Dispatch(
            this,
            call_info,
            replay_object,
            pQueryHeap,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndQuery>::Dispatch(
            this,
            call_info,
            replay_object,
            pQueryHeap,
            Type,
            Index);
        auto in_pQueryHeap = MapObject<ID3D12QueryHeap>(pQueryHeap);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->EndQuery(in_pQueryHeap,
                                                                                      Type,
                                                                                      Index);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndQuery>::Dispatch(
            this,
            call_info,
            replay_object,
            pQueryHeap,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveQueryData>::Dispatch(
            this,
            call_info,
            replay_object,
            pQueryHeap,
            Type,
            StartIndex,
            NumQueries,
            pDestinationBuffer,
            AlignedDestinationBufferOffset);
        auto in_pQueryHeap = MapObject<ID3D12QueryHeap>(pQueryHeap);
        auto in_pDestinationBuffer = MapObject<ID3D12Resource>(pDestinationBuffer);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->ResolveQueryData(in_pQueryHeap,
                                                                                              Type,
                                                                                              StartIndex,
                                                                                              NumQueries,
                                                                                              in_pDestinationBuffer,
                                                                                              AlignedDestinationBufferOffset);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveQueryData>::Dispatch(
            this,
            call_info,
            replay_object,
            pQueryHeap,
            Type,
            StartIndex,
            NumQueries,
            pDestinationBuffer,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPredication>::Dispatch(
            this,
            call_info,
            replay_object,
            pBuffer,
            AlignedBufferOffset,
            Operation);
        auto in_pBuffer = MapObject<ID3D12Resource>(pBuffer);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetPredication(in_pBuffer,
                                                                                            AlignedBufferOffset,
                                                                                            Operation);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPredication>::Dispatch(
            this,
            call_info,
            replay_object,
            pBuffer,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetMarker>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
            Size);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->SetMarker(Metadata,
                                                                                       pData->GetPointer(),
                                                                                       Size);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetMarker>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
            Size);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->BeginEvent(Metadata,
                                                                                        pData->GetPointer(),
                                                                                        Size);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
            Size);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndEvent>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12GraphicsCommandList*>(replay_object->object)->EndEvent();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndEvent>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect>::Dispatch(
            this,
            call_info,
            replay_object,
            pCommandSignature,
            MaxCommandCount,
            pArgumentBuffer,
            ArgumentBufferOffset,
            pCountBuffer,
            CountBufferOffset);
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect>::Dispatch(
            this,
            call_info,
            replay_object,
            pCommandSignature,
            MaxCommandCount,
            pArgumentBuffer,
            ArgumentBufferOffset,
            pCountBuffer,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstBuffer,
            DstOffset,
            pSrcBuffer,
            SrcOffset,
            Dependencies,
            ppDependentResources,
            pDependentSubresourceRanges);
        auto in_pDstBuffer = MapObject<ID3D12Resource>(pDstBuffer);
        auto in_pSrcBuffer = MapObject<ID3D12Resource>(pSrcBuffer);
        auto in_ppDependentResources = MapObjects<ID3D12Resource>(ppDependentResources, Dependencies);
        reinterpret_cast<ID3D12GraphicsCommandList1*>(replay_object->object)->AtomicCopyBufferUINT(in_pDstBuffer,
                                                                                                   DstOffset,
                                                                                                   in_pSrcBuffer,
                                                                                                   SrcOffset,
                                                                                                   Dependencies,
                                                                                                   in_ppDependentResources,
                                                                                                   pDependentSubresourceRanges->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstBuffer,
            DstOffset,
            pSrcBuffer,
            SrcOffset,
            Dependencies,
            ppDependentResources,
            pDependentSubresourceRanges);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstBuffer,
            DstOffset,
            pSrcBuffer,
            SrcOffset,
            Dependencies,
            ppDependentResources,
            pDependentSubresourceRanges);
        auto in_pDstBuffer = MapObject<ID3D12Resource>(pDstBuffer);
        auto in_pSrcBuffer = MapObject<ID3D12Resource>(pSrcBuffer);
        auto in_ppDependentResources = MapObjects<ID3D12Resource>(ppDependentResources, Dependencies);
        reinterpret_cast<ID3D12GraphicsCommandList1*>(replay_object->object)->AtomicCopyBufferUINT64(in_pDstBuffer,
                                                                                                     DstOffset,
                                                                                                     in_pSrcBuffer,
                                                                                                     SrcOffset,
                                                                                                     Dependencies,
                                                                                                     in_ppDependentResources,
                                                                                                     pDependentSubresourceRanges->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstBuffer,
            DstOffset,
            pSrcBuffer,
            SrcOffset,
            Dependencies,
            ppDependentResources,
            pDependentSubresourceRanges);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    FLOAT                                       Min,
    FLOAT                                       Max)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds>::Dispatch(
            this,
            call_info,
            replay_object,
            Min,
            Max);
        reinterpret_cast<ID3D12GraphicsCommandList1*>(replay_object->object)->OMSetDepthBounds(Min,
                                                                                               Max);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds>::Dispatch(
            this,
            call_info,
            replay_object,
            Min,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions>::Dispatch(
            this,
            call_info,
            replay_object,
            NumSamplesPerPixel,
            NumPixels,
            pSamplePositions);
        reinterpret_cast<ID3D12GraphicsCommandList1*>(replay_object->object)->SetSamplePositions(NumSamplesPerPixel,
                                                                                                 NumPixels,
                                                                                                 pSamplePositions->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions>::Dispatch(
            this,
            call_info,
            replay_object,
            NumSamplesPerPixel,
            NumPixels,
            pSamplePositions);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            DstSubresource,
            DstX,
            DstY,
            pSrcResource,
            SrcSubresource,
            pSrcRect,
            Format,
            ResolveMode);
        auto in_pDstResource = MapObject<ID3D12Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D12Resource>(pSrcResource);
        reinterpret_cast<ID3D12GraphicsCommandList1*>(replay_object->object)->ResolveSubresourceRegion(in_pDstResource,
                                                                                                       DstSubresource,
                                                                                                       DstX,
                                                                                                       DstY,
                                                                                                       in_pSrcResource,
                                                                                                       SrcSubresource,
                                                                                                       pSrcRect->GetPointer(),
                                                                                                       Format,
                                                                                                       ResolveMode);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            DstSubresource,
            DstX,
            DstY,
            pSrcResource,
            SrcSubresource,
            pSrcRect,
            Format,
            ResolveMode);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Mask)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask>::Dispatch(
            this,
            call_info,
            replay_object,
            Mask);
        reinterpret_cast<ID3D12GraphicsCommandList1*>(replay_object->object)->SetViewInstanceMask(Mask);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask>::Dispatch(
            this,
            call_info,
            replay_object,
            Mask);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Count,
    StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
    PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate>::Dispatch(
            this,
            call_info,
            replay_object,
            Count,
            pParams,
            pModes);
        MapStructArrayObjects(pParams->GetMetaStructPointer(), pParams->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList2*>(replay_object->object)->WriteBufferImmediate(Count,
                                                                                                   pParams->GetPointer(),
                                                                                                   pModes->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate>::Dispatch(
            this,
            call_info,
            replay_object,
            Count,
            pParams,
            pModes);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_UpdateTileMappings>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            NumResourceRegions,
            pResourceRegionStartCoordinates,
            pResourceRegionSizes,
            pHeap,
            NumRanges,
            pRangeFlags,
            pHeapRangeStartOffsets,
            pRangeTileCounts,
            Flags);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->UpdateTileMappings(in_pResource,
                                                                                         NumResourceRegions,
                                                                                         pResourceRegionStartCoordinates->GetPointer(),
                                                                                         pResourceRegionSizes->GetPointer(),
                                                                                         in_pHeap,
                                                                                         NumRanges,
                                                                                         pRangeFlags->GetPointer(),
                                                                                         pHeapRangeStartOffsets->GetPointer(),
                                                                                         pRangeTileCounts->GetPointer(),
                                                                                         Flags);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_UpdateTileMappings>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            NumResourceRegions,
            pResourceRegionStartCoordinates,
            pResourceRegionSizes,
            pHeap,
            NumRanges,
            pRangeFlags,
            pHeapRangeStartOffsets,
            pRangeTileCounts,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_CopyTileMappings>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            pDstRegionStartCoordinate,
            pSrcResource,
            pSrcRegionStartCoordinate,
            pRegionSize,
            Flags);
        auto in_pDstResource = MapObject<ID3D12Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D12Resource>(pSrcResource);
        reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->CopyTileMappings(in_pDstResource,
                                                                                       pDstRegionStartCoordinate->GetPointer(),
                                                                                       in_pSrcResource,
                                                                                       pSrcRegionStartCoordinate->GetPointer(),
                                                                                       pRegionSize->GetPointer(),
                                                                                       Flags);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_CopyTileMappings>::Dispatch(
            this,
            call_info,
            replay_object,
            pDstResource,
            pDstRegionStartCoordinate,
            pSrcResource,
            pSrcRegionStartCoordinate,
            pRegionSize,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists>::Dispatch(
            this,
            call_info,
            replay_object,
            NumCommandLists,
            ppCommandLists);
        MapObjects<ID3D12CommandList>(ppCommandLists, NumCommandLists);
        OverrideExecuteCommandLists(replay_object,
                                    NumCommandLists,
                                    ppCommandLists);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists>::Dispatch(
            this,
            call_info,
            replay_object,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_SetMarker>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
            Size);
        reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->SetMarker(Metadata,
                                                                                pData->GetPointer(),
                                                                                Size);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_SetMarker>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_BeginEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
            Size);
        reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->BeginEvent(Metadata,
                                                                                 pData->GetPointer(),
                                                                                 Size);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_BeginEvent>::Dispatch(
            this,
            call_info,
            replay_object,
            Metadata,
            pData,
            Size);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_EndEvent(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_EndEvent>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->EndEvent();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_EndEvent>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            Value);
        auto in_pFence = GetObjectInfo(pFence);
        auto replay_result = OverrideCommandQueueSignal(replay_object,
                                                        return_value,
                                                        in_pFence,
                                                        Value);
        CheckReplayResult("ID3D12CommandQueue_Signal", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            Value);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_Wait>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            Value);
        auto in_pFence = GetObjectInfo(pFence);
        auto replay_result = OverrideCommandQueueWait(replay_object,
                                                      return_value,
                                                      in_pFence,
                                                      Value);
        CheckReplayResult("ID3D12CommandQueue_Wait", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_Wait>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            Value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT64>*                     pFrequency)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_GetTimestampFrequency>::Dispatch(
            this,
            call_info,
            replay_object,
            pFrequency);
        auto replay_result = reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->GetTimestampFrequency(pFrequency->GetPointer());
        CheckReplayResult("ID3D12CommandQueue_GetTimestampFrequency", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_GetTimestampFrequency>::Dispatch(
            this,
            call_info,
            replay_object,
            pFrequency);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT64>*                     pGpuTimestamp,
    PointerDecoder<UINT64>*                     pCpuTimestamp)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_GetClockCalibration>::Dispatch(
            this,
            call_info,
            replay_object,
            pGpuTimestamp,
            pCpuTimestamp);
        auto replay_result = reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->GetClockCalibration(pGpuTimestamp->GetPointer(),
                                                                                                               pCpuTimestamp->GetPointer());
        CheckReplayResult("ID3D12CommandQueue_GetClockCalibration", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_GetClockCalibration>::Dispatch(
            this,
            call_info,
            replay_object,
            pGpuTimestamp,
            pCpuTimestamp);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_COMMAND_QUEUE_DESC            return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12CommandQueue*>(replay_object->object)->GetDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12CommandQueue_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetNodeCount(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetNodeCount>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->GetNodeCount();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetNodeCount>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppCommandQueue);
        if(!ppCommandQueue->IsNull()) ppCommandQueue->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppCommandQueue->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateCommandQueue(replay_object,
                                                        return_value,
                                                        pDesc,
                                                        riid,
                                                        ppCommandQueue);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppCommandQueue->GetPointer(), ppCommandQueue->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateCommandQueue);
        }
        CheckReplayResult("ID3D12Device_CreateCommandQueue", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppCommandQueue);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandAllocator>::Dispatch(
            this,
            call_info,
            replay_object,
            type,
            riid,
            ppCommandAllocator);
        if(!ppCommandAllocator->IsNull()) ppCommandAllocator->SetHandleLength(1);
        auto out_p_ppCommandAllocator    = ppCommandAllocator->GetPointer();
        auto out_hp_ppCommandAllocator   = ppCommandAllocator->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateCommandAllocator(type,
                                                                                                            *riid.decoded_value,
                                                                                                            out_hp_ppCommandAllocator);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCommandAllocator, out_hp_ppCommandAllocator, format::ApiCall_ID3D12Device_CreateCommandAllocator);
        }
        CheckReplayResult("ID3D12Device_CreateCommandAllocator", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandAllocator>::Dispatch(
            this,
            call_info,
            replay_object,
            type,
            riid,
            ppCommandAllocator);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppPipelineState);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppPipelineState->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateGraphicsPipelineState(replay_object,
                                                                 return_value,
                                                                 pDesc,
                                                                 riid,
                                                                 ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateGraphicsPipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateGraphicsPipelineState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppPipelineState);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppPipelineState);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppPipelineState->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateComputePipelineState(replay_object,
                                                                return_value,
                                                                pDesc,
                                                                riid,
                                                                ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateComputePipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateComputePipelineState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppPipelineState);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandList>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
            type,
            pCommandAllocator,
            pInitialState,
            riid,
            ppCommandList);
        auto in_pCommandAllocator = GetObjectInfo(pCommandAllocator);
        auto in_pInitialState = GetObjectInfo(pInitialState);
        if(!ppCommandList->IsNull()) ppCommandList->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppCommandList->SetConsumerData(0, &object_info);
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
            AddObject(ppCommandList->GetPointer(), ppCommandList->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateCommandList);
        }
        CheckReplayResult("ID3D12Device_CreateCommandList", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandList>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
            type,
            pCommandAllocator,
            pInitialState,
            riid,
            ppCommandList);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateDescriptorHeap>::Dispatch(
            this,
            call_info,
            replay_object,
            pDescriptorHeapDesc,
            riid,
            ppvHeap);
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvHeap->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateDescriptorHeap(replay_object,
                                                          return_value,
                                                          pDescriptorHeapDesc,
                                                          riid,
                                                          ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateDescriptorHeap);
        }
        CheckReplayResult("ID3D12Device_CreateDescriptorHeap", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateDescriptorHeap>::Dispatch(
            this,
            call_info,
            replay_object,
            pDescriptorHeapDesc,
            riid,
            ppvHeap);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize>::Dispatch(
            this,
            call_info,
            replay_object,
            DescriptorHeapType);
        auto replay_result = OverrideGetDescriptorHandleIncrementSize(replay_object,
                                                                      return_value,
                                                                      DescriptorHeapType);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize>::Dispatch(
            this,
            call_info,
            replay_object,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
            pBlobWithRootSignature,
            blobLengthInBytes,
            riid,
            ppvRootSignature);
        if(!ppvRootSignature->IsNull()) ppvRootSignature->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvRootSignature->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateRootSignature(replay_object,
                                                         return_value,
                                                         nodeMask,
                                                         pBlobWithRootSignature,
                                                         blobLengthInBytes,
                                                         riid,
                                                         ppvRootSignature);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvRootSignature->GetPointer(), ppvRootSignature->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateRootSignature);
        }
        CheckReplayResult("ID3D12Device_CreateRootSignature", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
            pBlobWithRootSignature,
            blobLengthInBytes,
            riid,
            ppvRootSignature);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateConstantBufferView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateConstantBufferView>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            DestDescriptor);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateConstantBufferView(pDesc->GetPointer(),
                                                                                         *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateConstantBufferView>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            DestDescriptor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateShaderResourceView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateShaderResourceView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pDesc,
            DestDescriptor);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateShaderResourceView(in_pResource,
                                                                                         pDesc->GetPointer(),
                                                                                         *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateShaderResourceView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pDesc,
            DestDescriptor);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pCounterResource,
            pDesc,
            DestDescriptor);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto in_pCounterResource = MapObject<ID3D12Resource>(pCounterResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateUnorderedAccessView(in_pResource,
                                                                                          in_pCounterResource,
                                                                                          pDesc->GetPointer(),
                                                                                          *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pCounterResource,
            pDesc,
            DestDescriptor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateRenderTargetView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateRenderTargetView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pDesc,
            DestDescriptor);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateRenderTargetView(in_pResource,
                                                                                       pDesc->GetPointer(),
                                                                                       *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateRenderTargetView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pDesc,
            DestDescriptor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateDepthStencilView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateDepthStencilView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pDesc,
            DestDescriptor);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateDepthStencilView(in_pResource,
                                                                                       pDesc->GetPointer(),
                                                                                       *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateDepthStencilView>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            pDesc,
            DestDescriptor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateSampler(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateSampler>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            DestDescriptor);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateSampler(pDesc->GetPointer(),
                                                                              *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateSampler>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            DestDescriptor);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptors>::Dispatch(
            this,
            call_info,
            replay_object,
            NumDestDescriptorRanges,
            pDestDescriptorRangeStarts,
            pDestDescriptorRangeSizes,
            NumSrcDescriptorRanges,
            pSrcDescriptorRangeStarts,
            pSrcDescriptorRangeSizes,
            DescriptorHeapsType);
        MapStructArrayObjects(pDestDescriptorRangeStarts->GetMetaStructPointer(), pDestDescriptorRangeStarts->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructArrayObjects(pSrcDescriptorRangeStarts->GetMetaStructPointer(), pSrcDescriptorRangeStarts->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CopyDescriptors(NumDestDescriptorRanges,
                                                                                pDestDescriptorRangeStarts->GetPointer(),
                                                                                pDestDescriptorRangeSizes->GetPointer(),
                                                                                NumSrcDescriptorRanges,
                                                                                pSrcDescriptorRangeStarts->GetPointer(),
                                                                                pSrcDescriptorRangeSizes->GetPointer(),
                                                                                DescriptorHeapsType);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptors>::Dispatch(
            this,
            call_info,
            replay_object,
            NumDestDescriptorRanges,
            pDestDescriptorRangeStarts,
            pDestDescriptorRangeSizes,
            NumSrcDescriptorRanges,
            pSrcDescriptorRangeStarts,
            pSrcDescriptorRangeSizes,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptorsSimple>::Dispatch(
            this,
            call_info,
            replay_object,
            NumDescriptors,
            DestDescriptorRangeStart,
            SrcDescriptorRangeStart,
            DescriptorHeapsType);
        MapStructObjects(&DestDescriptorRangeStart, GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(&SrcDescriptorRangeStart, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device*>(replay_object->object)->CopyDescriptorsSimple(NumDescriptors,
                                                                                      *DestDescriptorRangeStart.decoded_value,
                                                                                      *SrcDescriptorRangeStart.decoded_value,
                                                                                      DescriptorHeapsType);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptorsSimple>::Dispatch(
            this,
            call_info,
            replay_object,
            NumDescriptors,
            DestDescriptorRangeStart,
            SrcDescriptorRangeStart,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetResourceAllocationInfo>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->GetResourceAllocationInfo(visibleMask,
                                                                                                               numResourceDescs,
                                                                                                               pResourceDescs->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetResourceAllocationInfo>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetCustomHeapProperties(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_HEAP_PROPERTIES               return_value,
    UINT                                        nodeMask,
    D3D12_HEAP_TYPE                             heapType)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetCustomHeapProperties>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
            heapType);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->GetCustomHeapProperties(nodeMask,
                                                                                                             heapType);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetCustomHeapProperties>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommittedResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            riidResource,
            ppvResource);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvResource->SetConsumerData(0, &object_info);
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
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateCommittedResource);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device_CreateCommittedResource", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommittedResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            riidResource,
            ppvResource);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateHeap>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppvHeap);
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvHeap->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateHeap(replay_object,
                                                return_value,
                                                pDesc,
                                                riid,
                                                ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateHeap);
        }
        CheckReplayResult("ID3D12Device_CreateHeap", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateHeap>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppvHeap);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreatePlacedResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeap,
            HeapOffset,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->CreatePlacedResource(in_pHeap,
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreatePlacedResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeap,
            HeapOffset,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateReservedResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvResource->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateReservedResource(replay_object,
                                                            return_value,
                                                            pDesc,
                                                            InitialState,
                                                            pOptimizedClearValue,
                                                            riid,
                                                            ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateReservedResource);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device_CreateReservedResource", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateReservedResource>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pObject,
            pAttributes,
            Access,
            Name,
            pHandle);
        auto in_pObject = MapObject<ID3D12DeviceChild>(pObject);
        if(!pHandle->IsNull())
        {
            pHandle->AllocateOutputData(1);
        }
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateSharedHandle(in_pObject,
                                                                                                        pAttributes->GetPointer(),
                                                                                                        Access,
                                                                                                        Name->GetPointer(),
                                                                                                        out_op_pHandle);
        CheckReplayResult("ID3D12Device_CreateSharedHandle", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            pObject,
            pAttributes,
            Access,
            Name,
            pHandle);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            NTHandle,
            riid,
            ppvObj);
        auto in_NTHandle = static_cast<HANDLE>(PreProcessExternalObject(NTHandle, format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle, "ID3D12Device_OpenSharedHandle"));
        if(!ppvObj->IsNull()) ppvObj->SetHandleLength(1);
        auto out_p_ppvObj    = ppvObj->GetPointer();
        auto out_hp_ppvObj   = ppvObj->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->OpenSharedHandle(in_NTHandle,
                                                                                                      *riid.decoded_value,
                                                                                                      out_hp_ppvObj);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvObj, out_hp_ppvObj, format::ApiCall_ID3D12Device_OpenSharedHandle);
        }
        CheckReplayResult("ID3D12Device_OpenSharedHandle", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle>::Dispatch(
            this,
            call_info,
            replay_object,
            NTHandle,
            riid,
            ppvObj);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            Access,
            pNTHandle);
        if(!pNTHandle->IsNull())
        {
            pNTHandle->AllocateOutputData(1);
        }
        auto out_p_pNTHandle    = pNTHandle->GetPointer();
        auto out_op_pNTHandle   = reinterpret_cast<HANDLE*>(pNTHandle->GetOutputPointer());
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->OpenSharedHandleByName(Name->GetPointer(),
                                                                                                            Access,
                                                                                                            out_op_pNTHandle);
        CheckReplayResult("ID3D12Device_OpenSharedHandleByName", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName>::Dispatch(
            this,
            call_info,
            replay_object,
            Name,
            Access,
            pNTHandle);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_MakeResident>::Dispatch(
            this,
            call_info,
            replay_object,
            NumObjects,
            ppObjects);
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects, NumObjects);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->MakeResident(NumObjects,
                                                                                                  in_ppObjects);
        CheckReplayResult("ID3D12Device_MakeResident", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_MakeResident>::Dispatch(
            this,
            call_info,
            replay_object,
            NumObjects,
            ppObjects);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_Evict(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_Evict>::Dispatch(
            this,
            call_info,
            replay_object,
            NumObjects,
            ppObjects);
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects, NumObjects);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->Evict(NumObjects,
                                                                                           in_ppObjects);
        CheckReplayResult("ID3D12Device_Evict", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_Evict>::Dispatch(
            this,
            call_info,
            replay_object,
            NumObjects,
            ppObjects);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateFence>::Dispatch(
            this,
            call_info,
            replay_object,
            InitialValue,
            Flags,
            riid,
            ppFence);
        if(!ppFence->IsNull()) ppFence->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppFence->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateFence(replay_object,
                                                 return_value,
                                                 InitialValue,
                                                 Flags,
                                                 riid,
                                                 ppFence);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppFence->GetPointer(), ppFence->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateFence);
        }
        CheckReplayResult("ID3D12Device_CreateFence", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateFence>::Dispatch(
            this,
            call_info,
            replay_object,
            InitialValue,
            Flags,
            riid,
            ppFence);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetDeviceRemovedReason>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->GetDeviceRemovedReason();
        CheckReplayResult("ID3D12Device_GetDeviceRemovedReason", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetDeviceRemovedReason>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetCopyableFootprints>::Dispatch(
            this,
            call_info,
            replay_object,
            pResourceDesc,
            FirstSubresource,
            NumSubresources,
            BaseOffset,
            pLayouts,
            pNumRows,
            pRowSizeInBytes,
            pTotalBytes);
        reinterpret_cast<ID3D12Device*>(replay_object->object)->GetCopyableFootprints(pResourceDesc->GetPointer(),
                                                                                      FirstSubresource,
                                                                                      NumSubresources,
                                                                                      BaseOffset,
                                                                                      pLayouts->GetPointer(),
                                                                                      pNumRows->GetPointer(),
                                                                                      pRowSizeInBytes->GetPointer(),
                                                                                      pTotalBytes->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetCopyableFootprints>::Dispatch(
            this,
            call_info,
            replay_object,
            pResourceDesc,
            FirstSubresource,
            NumSubresources,
            BaseOffset,
            pLayouts,
            pNumRows,
            pRowSizeInBytes,
            pTotalBytes);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateQueryHeap>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppvHeap);
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto out_p_ppvHeap    = ppvHeap->GetPointer();
        auto out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->CreateQueryHeap(pDesc->GetPointer(),
                                                                                                     *riid.decoded_value,
                                                                                                     out_hp_ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvHeap, out_hp_ppvHeap, format::ApiCall_ID3D12Device_CreateQueryHeap);
        }
        CheckReplayResult("ID3D12Device_CreateQueryHeap", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateQueryHeap>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppvHeap);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_SetStablePowerState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    BOOL                                        Enable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_SetStablePowerState>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->SetStablePowerState(Enable);
        CheckReplayResult("ID3D12Device_SetStablePowerState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_SetStablePowerState>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            pRootSignature,
            riid,
            ppvCommandSignature);
        auto in_pRootSignature = GetObjectInfo(pRootSignature);
        if(!ppvCommandSignature->IsNull()) ppvCommandSignature->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvCommandSignature->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateCommandSignature(replay_object,
                                                            return_value,
                                                            pDesc,
                                                            in_pRootSignature,
                                                            riid,
                                                            ppvCommandSignature);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvCommandSignature->GetPointer(), ppvCommandSignature->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device_CreateCommandSignature);
        }
        CheckReplayResult("ID3D12Device_CreateCommandSignature", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_CreateCommandSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            pRootSignature,
            riid,
            ppvCommandSignature);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetResourceTiling>::Dispatch(
            this,
            call_info,
            replay_object,
            pTiledResource,
            pNumTilesForEntireResource,
            pPackedMipDesc,
            pStandardTileShapeForNonPackedMips,
            pNumSubresourceTilings,
            FirstSubresourceTilingToGet,
            pSubresourceTilingsForNonPackedMips);
        auto in_pTiledResource = MapObject<ID3D12Resource>(pTiledResource);
        reinterpret_cast<ID3D12Device*>(replay_object->object)->GetResourceTiling(in_pTiledResource,
                                                                                  pNumTilesForEntireResource->GetPointer(),
                                                                                  pPackedMipDesc->GetPointer(),
                                                                                  pStandardTileShapeForNonPackedMips->GetPointer(),
                                                                                  pNumSubresourceTilings->GetPointer(),
                                                                                  FirstSubresourceTilingToGet,
                                                                                  pSubresourceTilingsForNonPackedMips->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetResourceTiling>::Dispatch(
            this,
            call_info,
            replay_object,
            pTiledResource,
            pNumTilesForEntireResource,
            pPackedMipDesc,
            pStandardTileShapeForNonPackedMips,
            pNumSubresourceTilings,
            FirstSubresourceTilingToGet,
            pSubresourceTilingsForNonPackedMips);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetAdapterLuid(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_LUID                                return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device_GetAdapterLuid>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Device*>(replay_object->object)->GetAdapterLuid();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device_GetAdapterLuid>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    WStringDecoder*                             pName,
    format::HandleId                            pPipeline)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pPipeline);
        auto in_pPipeline = MapObject<ID3D12PipelineState>(pPipeline);
        auto replay_result = reinterpret_cast<ID3D12PipelineLibrary*>(replay_object->object)->StorePipeline(pName->GetPointer(),
                                                                                                            in_pPipeline);
        CheckReplayResult("ID3D12PipelineLibrary_StorePipeline", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pPipeline);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pDesc,
            riid,
            ppPipelineState);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppPipelineState->SetConsumerData(0, &object_info);
        auto replay_result = OverrideLoadGraphicsPipeline(replay_object,
                                                          return_value,
                                                          pName,
                                                          pDesc,
                                                          riid,
                                                          ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadGraphicsPipeline", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pDesc,
            riid,
            ppPipelineState);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pDesc,
            riid,
            ppPipelineState);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppPipelineState->SetConsumerData(0, &object_info);
        auto replay_result = OverrideLoadComputePipeline(replay_object,
                                                         return_value,
                                                         pName,
                                                         pDesc,
                                                         riid,
                                                         ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadComputePipeline", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pDesc,
            riid,
            ppPipelineState);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    SIZE_T                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_GetSerializedSize>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12PipelineLibrary*>(replay_object->object)->GetSerializedSize();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_GetSerializedSize>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_Serialize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<uint8_t>*                    pData,
    SIZE_T                                      DataSizeInBytes)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_Serialize>::Dispatch(
            this,
            call_info,
            replay_object,
            pData,
            DataSizeInBytes);
        auto replay_result = reinterpret_cast<ID3D12PipelineLibrary*>(replay_object->object)->Serialize(pData->GetPointer(),
                                                                                                        DataSizeInBytes);
        CheckReplayResult("ID3D12PipelineLibrary_Serialize", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary_Serialize>::Dispatch(
            this,
            call_info,
            replay_object,
            pData,
            DataSizeInBytes);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary1_LoadPipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pDesc,
            riid,
            ppPipelineState);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppPipelineState->SetConsumerData(0, &object_info);
        auto replay_result = OverrideLoadPipeline(replay_object,
                                                  return_value,
                                                  pName,
                                                  pDesc,
                                                  riid,
                                                  ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineState->GetPointer(), ppPipelineState->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12PipelineLibrary1_LoadPipeline);
        }
        CheckReplayResult("ID3D12PipelineLibrary1_LoadPipeline", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12PipelineLibrary1_LoadPipeline>::Dispatch(
            this,
            call_info,
            replay_object,
            pName,
            pDesc,
            riid,
            ppPipelineState);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device1_CreatePipelineLibrary>::Dispatch(
            this,
            call_info,
            replay_object,
            pLibraryBlob,
            BlobLength,
            riid,
            ppPipelineLibrary);
        if(!ppPipelineLibrary->IsNull()) ppPipelineLibrary->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppPipelineLibrary->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreatePipelineLibrary(replay_object,
                                                           return_value,
                                                           pLibraryBlob,
                                                           BlobLength,
                                                           riid,
                                                           ppPipelineLibrary);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppPipelineLibrary->GetPointer(), ppPipelineLibrary->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device1_CreatePipelineLibrary);
        }
        CheckReplayResult("ID3D12Device1_CreatePipelineLibrary", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device1_CreatePipelineLibrary>::Dispatch(
            this,
            call_info,
            replay_object,
            pLibraryBlob,
            BlobLength,
            riid,
            ppPipelineLibrary);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion>::Dispatch(
            this,
            call_info,
            replay_object,
            ppFences,
            pFenceValues,
            NumFences,
            Flags,
            hEvent);
        auto in_ppFences = MapObjects<ID3D12Fence>(ppFences, NumFences);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion, "ID3D12Device1_SetEventOnMultipleFenceCompletion"));
        auto replay_result = reinterpret_cast<ID3D12Device1*>(replay_object->object)->SetEventOnMultipleFenceCompletion(in_ppFences,
                                                                                                                        pFenceValues->GetPointer(),
                                                                                                                        NumFences,
                                                                                                                        Flags,
                                                                                                                        in_hEvent);
        CheckReplayResult("ID3D12Device1_SetEventOnMultipleFenceCompletion", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion>::Dispatch(
            this,
            call_info,
            replay_object,
            ppFences,
            pFenceValues,
            NumFences,
            Flags,
            hEvent);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device1_SetResidencyPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            NumObjects,
            ppObjects,
            pPriorities);
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects, NumObjects);
        auto replay_result = reinterpret_cast<ID3D12Device1*>(replay_object->object)->SetResidencyPriority(NumObjects,
                                                                                                           in_ppObjects,
                                                                                                           pPriorities->GetPointer());
        CheckReplayResult("ID3D12Device1_SetResidencyPriority", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device1_SetResidencyPriority>::Dispatch(
            this,
            call_info,
            replay_object,
            NumObjects,
            ppObjects,
            pPriorities);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device2_CreatePipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppPipelineState);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device2*>(replay_object->object)->CreatePipelineState(pDesc->GetPointer(),
                                                                                                          *riid.decoded_value,
                                                                                                          out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState, format::ApiCall_ID3D12Device2_CreatePipelineState);
        }
        CheckReplayResult("ID3D12Device2_CreatePipelineState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device2_CreatePipelineState>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppPipelineState);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress>::Dispatch(
            this,
            call_info,
            replay_object,
            pAddress,
            riid,
            ppvHeap);
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvHeap->SetConsumerData(0, &object_info);
        auto replay_result = OverrideOpenExistingHeapFromAddress(replay_object,
                                                                 return_value,
                                                                 pAddress,
                                                                 riid,
                                                                 ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromAddress", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress>::Dispatch(
            this,
            call_info,
            replay_object,
            pAddress,
            riid,
            ppvHeap);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping>::Dispatch(
            this,
            call_info,
            replay_object,
            hFileMapping,
            riid,
            ppvHeap);
        auto in_hFileMapping = static_cast<HANDLE>(PreProcessExternalObject(hFileMapping, format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping, "ID3D12Device3_OpenExistingHeapFromFileMapping"));
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto out_p_ppvHeap    = ppvHeap->GetPointer();
        auto out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device3*>(replay_object->object)->OpenExistingHeapFromFileMapping(in_hFileMapping,
                                                                                                                      *riid.decoded_value,
                                                                                                                      out_hp_ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvHeap, out_hp_ppvHeap, format::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromFileMapping", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping>::Dispatch(
            this,
            call_info,
            replay_object,
            hFileMapping,
            riid,
            ppvHeap);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device3_EnqueueMakeResident>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags,
            NumObjects,
            ppObjects,
            pFenceToSignal,
            FenceValueToSignal);
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device3_EnqueueMakeResident>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags,
            NumObjects,
            ppObjects,
            pFenceToSignal,
            FenceValueToSignal);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFence)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetStatusFence>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppFence);
        if(!ppFence->IsNull()) ppFence->SetHandleLength(1);
        auto out_p_ppFence    = ppFence->GetPointer();
        auto out_hp_ppFence   = ppFence->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12ProtectedSession*>(replay_object->object)->GetStatusFence(*riid.decoded_value,
                                                                                                              out_hp_ppFence);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppFence, out_hp_ppFence, format::ApiCall_ID3D12ProtectedSession_GetStatusFence);
        }
        CheckReplayResult("ID3D12ProtectedSession_GetStatusFence", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetStatusFence>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppFence);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_PROTECTED_SESSION_STATUS              return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetSessionStatus>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12ProtectedSession*>(replay_object->object)->GetSessionStatus();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetSessionStatus>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12ProtectedResourceSession*>(replay_object->object)->GetDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateCommandList1>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
            type,
            flags,
            riid,
            ppCommandList);
        if(!ppCommandList->IsNull()) ppCommandList->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppCommandList->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateCommandList1(replay_object,
                                                        return_value,
                                                        nodeMask,
                                                        type,
                                                        flags,
                                                        riid,
                                                        ppCommandList);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppCommandList->GetPointer(), ppCommandList->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device4_CreateCommandList1);
        }
        CheckReplayResult("ID3D12Device4_CreateCommandList1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateCommandList1>::Dispatch(
            this,
            call_info,
            replay_object,
            nodeMask,
            type,
            flags,
            riid,
            ppCommandList);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppSession);
        if(!ppSession->IsNull()) ppSession->SetHandleLength(1);
        auto out_p_ppSession    = ppSession->GetPointer();
        auto out_hp_ppSession   = ppSession->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device4*>(replay_object->object)->CreateProtectedResourceSession(pDesc->GetPointer(),
                                                                                                                     *riid.decoded_value,
                                                                                                                     out_hp_ppSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSession, out_hp_ppSession, format::ApiCall_ID3D12Device4_CreateProtectedResourceSession);
        }
        CheckReplayResult("ID3D12Device4_CreateProtectedResourceSession", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppSession);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateCommittedResource1>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            pProtectedSession,
            riidResource,
            ppvResource);
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvResource->SetConsumerData(0, &object_info);
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
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device4_CreateCommittedResource1);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device4_CreateCommittedResource1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateCommittedResource1>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            pProtectedSession,
            riidResource,
            ppvResource);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateHeap1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            pProtectedSession,
            riid,
            ppvHeap);
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvHeap->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateHeap1(replay_object,
                                                 return_value,
                                                 pDesc,
                                                 in_pProtectedSession,
                                                 riid,
                                                 ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device4_CreateHeap1);
        }
        CheckReplayResult("ID3D12Device4_CreateHeap1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateHeap1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            pProtectedSession,
            riid,
            ppvHeap);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateReservedResource1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            pProtectedSession,
            riid,
            ppvResource);
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvResource->SetConsumerData(0, &object_info);
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
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device4_CreateReservedResource1);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device4_CreateReservedResource1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device4_CreateReservedResource1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            pProtectedSession,
            riid,
            ppvResource);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device4_GetResourceAllocationInfo1>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
        auto replay_result = reinterpret_cast<ID3D12Device4*>(replay_object->object)->GetResourceAllocationInfo1(visibleMask,
                                                                                                                 numResourceDescs,
                                                                                                                 pResourceDescs->GetPointer(),
                                                                                                                 pResourceAllocationInfo1->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device4_GetResourceAllocationInfo1>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
    }
}

void Dx12ReplayConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_LIFETIME_STATE                        NewState)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated>::Dispatch(
            this,
            call_info,
            replay_object,
            NewState);
        reinterpret_cast<ID3D12LifetimeOwner*>(replay_object->object)->LifetimeStateUpdated(NewState);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated>::Dispatch(
            this,
            call_info,
            replay_object,
            NewState);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_LUID                                return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetLUID>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12SwapChainAssistant*>(replay_object->object)->GetLUID();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetLUID>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppv)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppv);
        if(!ppv->IsNull()) ppv->SetHandleLength(1);
        auto out_p_ppv    = ppv->GetPointer();
        auto out_hp_ppv   = ppv->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12SwapChainAssistant*>(replay_object->object)->GetSwapChainObject(*riid.decoded_value,
                                                                                                                    out_hp_ppv);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppv, out_hp_ppv, format::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetSwapChainObject", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppv);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue>::Dispatch(
            this,
            call_info,
            replay_object,
            riidResource,
            ppvResource,
            riidQueue,
            ppvQueue);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        if(!ppvQueue->IsNull()) ppvQueue->SetHandleLength(1);
        auto out_p_ppvQueue    = ppvQueue->GetPointer();
        auto out_hp_ppvQueue   = ppvQueue->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12SwapChainAssistant*>(replay_object->object)->GetCurrentResourceAndCommandQueue(*riidResource.decoded_value,
                                                                                                                                   out_hp_ppvResource,
                                                                                                                                   *riidQueue.decoded_value,
                                                                                                                                   out_hp_ppvQueue);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource, format::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue);
            AddObject(out_p_ppvQueue, out_hp_ppvQueue, format::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue>::Dispatch(
            this,
            call_info,
            replay_object,
            riidResource,
            ppvResource,
            riidQueue,
            ppvQueue);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12SwapChainAssistant*>(replay_object->object)->InsertImplicitSync();
        CheckReplayResult("ID3D12SwapChainAssistant_InsertImplicitSync", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pObject)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject>::Dispatch(
            this,
            call_info,
            replay_object,
            pObject);
        auto in_pObject = MapObject<ID3D12DeviceChild>(pObject);
        auto replay_result = reinterpret_cast<ID3D12LifetimeTracker*>(replay_object->object)->DestroyOwnedObject(in_pObject);
        CheckReplayResult("ID3D12LifetimeTracker_DestroyOwnedObject", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject>::Dispatch(
            this,
            call_info,
            replay_object,
            pObject);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier>::Dispatch(
            this,
            call_info,
            replay_object,
            pExportName);
        auto replay_result = OverrideGetShaderIdentifier(replay_object,
                                                         return_value,
                                                         pExportName);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier>::Dispatch(
            this,
            call_info,
            replay_object,
            pExportName);
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value,
    WStringDecoder*                             pExportName)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderStackSize>::Dispatch(
            this,
            call_info,
            replay_object,
            pExportName);
        auto replay_result = reinterpret_cast<ID3D12StateObjectProperties*>(replay_object->object)->GetShaderStackSize(pExportName->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderStackSize>::Dispatch(
            this,
            call_info,
            replay_object,
            pExportName);
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12StateObjectProperties*>(replay_object->object)->GetPipelineStackSize();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      PipelineStackSizeInBytes)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize>::Dispatch(
            this,
            call_info,
            replay_object,
            PipelineStackSizeInBytes);
        reinterpret_cast<ID3D12StateObjectProperties*>(replay_object->object)->SetPipelineStackSize(PipelineStackSizeInBytes);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize>::Dispatch(
            this,
            call_info,
            replay_object,
            PipelineStackSizeInBytes);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_CreateLifetimeTracker>::Dispatch(
            this,
            call_info,
            replay_object,
            pOwner,
            riid,
            ppvTracker);
        auto in_pOwner = MapObject<ID3D12LifetimeOwner>(pOwner);
        if(!ppvTracker->IsNull()) ppvTracker->SetHandleLength(1);
        auto out_p_ppvTracker    = ppvTracker->GetPointer();
        auto out_hp_ppvTracker   = ppvTracker->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device5*>(replay_object->object)->CreateLifetimeTracker(in_pOwner,
                                                                                                            *riid.decoded_value,
                                                                                                            out_hp_ppvTracker);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvTracker, out_hp_ppvTracker, format::ApiCall_ID3D12Device5_CreateLifetimeTracker);
        }
        CheckReplayResult("ID3D12Device5_CreateLifetimeTracker", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_CreateLifetimeTracker>::Dispatch(
            this,
            call_info,
            replay_object,
            pOwner,
            riid,
            ppvTracker);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_RemoveDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_RemoveDevice>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12Device5*>(replay_object->object)->RemoveDevice();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_RemoveDevice>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    PointerDecoder<UINT>*                       pNumMetaCommands,
    StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommands>::Dispatch(
            this,
            call_info,
            replay_object,
            pNumMetaCommands,
            pDescs);
        auto replay_result = reinterpret_cast<ID3D12Device5*>(replay_object->object)->EnumerateMetaCommands(pNumMetaCommands->GetPointer(),
                                                                                                            pDescs->GetPointer());
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommands", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommands>::Dispatch(
            this,
            call_info,
            replay_object,
            pNumMetaCommands,
            pDescs);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommandParameters>::Dispatch(
            this,
            call_info,
            replay_object,
            CommandId,
            Stage,
            pTotalStructureSizeInBytes,
            pParameterCount,
            pParameterDescs);
        auto replay_result = reinterpret_cast<ID3D12Device5*>(replay_object->object)->EnumerateMetaCommandParameters(*CommandId.decoded_value,
                                                                                                                     Stage,
                                                                                                                     pTotalStructureSizeInBytes->GetPointer(),
                                                                                                                     pParameterCount->GetPointer(),
                                                                                                                     pParameterDescs->GetPointer());
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommandParameters", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommandParameters>::Dispatch(
            this,
            call_info,
            replay_object,
            CommandId,
            Stage,
            pTotalStructureSizeInBytes,
            pParameterCount,
            pParameterDescs);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_CreateMetaCommand>::Dispatch(
            this,
            call_info,
            replay_object,
            CommandId,
            NodeMask,
            pCreationParametersData,
            CreationParametersDataSizeInBytes,
            riid,
            ppMetaCommand);
        if(!ppMetaCommand->IsNull()) ppMetaCommand->SetHandleLength(1);
        auto out_p_ppMetaCommand    = ppMetaCommand->GetPointer();
        auto out_hp_ppMetaCommand   = ppMetaCommand->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device5*>(replay_object->object)->CreateMetaCommand(*CommandId.decoded_value,
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_CreateMetaCommand>::Dispatch(
            this,
            call_info,
            replay_object,
            CommandId,
            NodeMask,
            pCreationParametersData,
            CreationParametersDataSizeInBytes,
            riid,
            ppMetaCommand);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_CreateStateObject>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppStateObject);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if(!ppStateObject->IsNull()) ppStateObject->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppStateObject->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateStateObject(replay_object,
                                                       return_value,
                                                       pDesc,
                                                       riid,
                                                       ppStateObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppStateObject->GetPointer(), ppStateObject->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device5_CreateStateObject);
        }
        CheckReplayResult("ID3D12Device5_CreateStateObject", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_CreateStateObject>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppStateObject);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            pInfo);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideGetRaytracingAccelerationStructurePrebuildInfo(replay_object,
                                                               pDesc,
                                                               pInfo);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo>::Dispatch(
            this,
            call_info,
            replay_object,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier>::Dispatch(
            this,
            call_info,
            replay_object,
            SerializedDataType,
            pIdentifierToCheck);
        auto replay_result = reinterpret_cast<ID3D12Device5*>(replay_object->object)->CheckDriverMatchingIdentifier(SerializedDataType,
                                                                                                                    pIdentifierToCheck->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier>::Dispatch(
            this,
            call_info,
            replay_object,
            SerializedDataType,
            pIdentifierToCheck);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
            Enablement);
        OverrideSetAutoBreadcrumbsEnablement(replay_object,
                                             Enablement);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
            Enablement);
        OverrideSetPageFaultEnablement(replay_object,
                                       Enablement);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
            Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
            Enablement);
        reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings*>(replay_object->object)->SetWatsonDumpEnablement(Enablement);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
            Enablement);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
            Enablement);
        OverrideSetBreadcrumbContextEnablement(replay_object,
                                               Enablement);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement>::Dispatch(
            this,
            call_info,
            replay_object,
            Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        MarkersOnly)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs>::Dispatch(
            this,
            call_info,
            replay_object,
            MarkersOnly);
        reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings2*>(replay_object->object)->UseMarkersOnlyAutoBreadcrumbs(MarkersOnly);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs>::Dispatch(
            this,
            call_info,
            replay_object,
            MarkersOnly);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
        auto replay_result = reinterpret_cast<ID3D12DeviceRemovedExtendedData*>(replay_object->object)->GetAutoBreadcrumbsOutput(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
        MapStructObjects(pOutput->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = reinterpret_cast<ID3D12DeviceRemovedExtendedData*>(replay_object->object)->GetPageFaultAllocationOutput(pOutput->GetPointer());
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
        auto replay_result = reinterpret_cast<ID3D12DeviceRemovedExtendedData1*>(replay_object->object)->GetAutoBreadcrumbsOutput1(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
        MapStructObjects(pOutput->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = reinterpret_cast<ID3D12DeviceRemovedExtendedData1*>(replay_object->object)->GetPageFaultAllocationOutput1(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT2>* pOutput)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
        MapStructObjects(pOutput->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto replay_result = reinterpret_cast<ID3D12DeviceRemovedExtendedData2*>(replay_object->object)->GetPageFaultAllocationOutput2(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddStructObjects(pOutput, pOutput->GetPointer(), GetObjectInfoTable());
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2>::Dispatch(
            this,
            call_info,
            replay_object,
            pOutput);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData2_GetDeviceState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DRED_DEVICE_STATE                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetDeviceState>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DeviceRemovedExtendedData2*>(replay_object->object)->GetDeviceState();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetDeviceState>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode>::Dispatch(
            this,
            call_info,
            replay_object,
            Mode,
            MeasurementsAction,
            hEventToSignalUponCompletion,
            pbFurtherMeasurementsDesired);
        auto in_hEventToSignalUponCompletion = static_cast<HANDLE>(PreProcessExternalObject(hEventToSignalUponCompletion, format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode, "ID3D12Device6_SetBackgroundProcessingMode"));
        auto replay_result = reinterpret_cast<ID3D12Device6*>(replay_object->object)->SetBackgroundProcessingMode(Mode,
                                                                                                                  MeasurementsAction,
                                                                                                                  in_hEventToSignalUponCompletion,
                                                                                                                  pbFurtherMeasurementsDesired->GetPointer());
        CheckReplayResult("ID3D12Device6_SetBackgroundProcessingMode", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode>::Dispatch(
            this,
            call_info,
            replay_object,
            Mode,
            MeasurementsAction,
            hEventToSignalUponCompletion,
            pbFurtherMeasurementsDesired);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession1_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12ProtectedResourceSession1*>(replay_object->object)->GetDesc1();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession1_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device7_AddToStateObject>::Dispatch(
            this,
            call_info,
            replay_object,
            pAddition,
            pStateObjectToGrowFrom,
            riid,
            ppNewStateObject);
        MapStructObjects(pAddition->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        auto in_pStateObjectToGrowFrom = GetObjectInfo(pStateObjectToGrowFrom);
        if(!ppNewStateObject->IsNull()) ppNewStateObject->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppNewStateObject->SetConsumerData(0, &object_info);
        auto replay_result = OverrideAddToStateObject(replay_object,
                                                      return_value,
                                                      pAddition,
                                                      in_pStateObjectToGrowFrom,
                                                      riid,
                                                      ppNewStateObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppNewStateObject->GetPointer(), ppNewStateObject->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device7_AddToStateObject);
        }
        CheckReplayResult("ID3D12Device7_AddToStateObject", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device7_AddToStateObject>::Dispatch(
            this,
            call_info,
            replay_object,
            pAddition,
            pStateObjectToGrowFrom,
            riid,
            ppNewStateObject);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device7_CreateProtectedResourceSession1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppSession);
        if(!ppSession->IsNull()) ppSession->SetHandleLength(1);
        auto out_p_ppSession    = ppSession->GetPointer();
        auto out_hp_ppSession   = ppSession->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device7*>(replay_object->object)->CreateProtectedResourceSession1(pDesc->GetPointer(),
                                                                                                                      *riid.decoded_value,
                                                                                                                      out_hp_ppSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSession, out_hp_ppSession, format::ApiCall_ID3D12Device7_CreateProtectedResourceSession1);
        }
        CheckReplayResult("ID3D12Device7_CreateProtectedResourceSession1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device7_CreateProtectedResourceSession1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppSession);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device8_GetResourceAllocationInfo2>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
        auto replay_result = reinterpret_cast<ID3D12Device8*>(replay_object->object)->GetResourceAllocationInfo2(visibleMask,
                                                                                                                 numResourceDescs,
                                                                                                                 pResourceDescs->GetPointer(),
                                                                                                                 pResourceAllocationInfo1->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device8_GetResourceAllocationInfo2>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device8_CreateCommittedResource2>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            pProtectedSession,
            riidResource,
            ppvResource);
        auto in_pProtectedSession = GetObjectInfo(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvResource->SetConsumerData(0, &object_info);
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
            AddObject(ppvResource->GetPointer(), ppvResource->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device8_CreateCommittedResource2);
            SetResourceDesc(ppvResource, pDesc);
        }
        CheckReplayResult("ID3D12Device8_CreateCommittedResource2", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device8_CreateCommittedResource2>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            pProtectedSession,
            riidResource,
            ppvResource);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device8_CreatePlacedResource1>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeap,
            HeapOffset,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device8*>(replay_object->object)->CreatePlacedResource1(in_pHeap,
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device8_CreatePlacedResource1>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeap,
            HeapOffset,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pTargetedResource,
    format::HandleId                            pFeedbackResource,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            pTargetedResource,
            pFeedbackResource,
            DestDescriptor);
        auto in_pTargetedResource = MapObject<ID3D12Resource>(pTargetedResource);
        auto in_pFeedbackResource = MapObject<ID3D12Resource>(pFeedbackResource);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device8*>(replay_object->object)->CreateSamplerFeedbackUnorderedAccessView(in_pTargetedResource,
                                                                                                          in_pFeedbackResource,
                                                                                                          *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView>::Dispatch(
            this,
            call_info,
            replay_object,
            pTargetedResource,
            pFeedbackResource,
            DestDescriptor);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device8_GetCopyableFootprints1>::Dispatch(
            this,
            call_info,
            replay_object,
            pResourceDesc,
            FirstSubresource,
            NumSubresources,
            BaseOffset,
            pLayouts,
            pNumRows,
            pRowSizeInBytes,
            pTotalBytes);
        reinterpret_cast<ID3D12Device8*>(replay_object->object)->GetCopyableFootprints1(pResourceDesc->GetPointer(),
                                                                                        FirstSubresource,
                                                                                        NumSubresources,
                                                                                        BaseOffset,
                                                                                        pLayouts->GetPointer(),
                                                                                        pNumRows->GetPointer(),
                                                                                        pRowSizeInBytes->GetPointer(),
                                                                                        pTotalBytes->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device8_GetCopyableFootprints1>::Dispatch(
            this,
            call_info,
            replay_object,
            pResourceDesc,
            FirstSubresource,
            NumSubresources,
            BaseOffset,
            pLayouts,
            pNumRows,
            pRowSizeInBytes,
            pTotalBytes);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppProtectedSession)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource1_GetProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppProtectedSession);
        if(!ppProtectedSession->IsNull()) ppProtectedSession->SetHandleLength(1);
        auto out_p_ppProtectedSession    = ppProtectedSession->GetPointer();
        auto out_hp_ppProtectedSession   = ppProtectedSession->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Resource1*>(replay_object->object)->GetProtectedResourceSession(*riid.decoded_value,
                                                                                                                    out_hp_ppProtectedSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppProtectedSession, out_hp_ppProtectedSession, format::ApiCall_ID3D12Resource1_GetProtectedResourceSession);
        }
        CheckReplayResult("ID3D12Resource1_GetProtectedResourceSession", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource1_GetProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppProtectedSession);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource2_GetDesc1(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC1                return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Resource2_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Resource2*>(replay_object->object)->GetDesc1();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Resource2_GetDesc1>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppProtectedSession)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Heap1_GetProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppProtectedSession);
        if(!ppProtectedSession->IsNull()) ppProtectedSession->SetHandleLength(1);
        auto out_p_ppProtectedSession    = ppProtectedSession->GetPointer();
        auto out_hp_ppProtectedSession   = ppProtectedSession->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Heap1*>(replay_object->object)->GetProtectedResourceSession(*riid.decoded_value,
                                                                                                                out_hp_ppProtectedSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppProtectedSession, out_hp_ppProtectedSession, format::ApiCall_ID3D12Heap1_GetProtectedResourceSession);
        }
        CheckReplayResult("ID3D12Heap1_GetProtectedResourceSession", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Heap1_GetProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppProtectedSession);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pProtectedResourceSession)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            pProtectedResourceSession);
        auto in_pProtectedResourceSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedResourceSession);
        reinterpret_cast<ID3D12GraphicsCommandList3*>(replay_object->object)->SetProtectedResourceSession(in_pProtectedResourceSession);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession>::Dispatch(
            this,
            call_info,
            replay_object,
            pProtectedResourceSession);
    }
}

void Dx12ReplayConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value,
    D3D12_META_COMMAND_PARAMETER_STAGE          Stage,
    UINT                                        ParameterIndex)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize>::Dispatch(
            this,
            call_info,
            replay_object,
            Stage,
            ParameterIndex);
        auto replay_result = reinterpret_cast<ID3D12MetaCommand*>(replay_object->object)->GetRequiredParameterResourceSize(Stage,
                                                                                                                           ParameterIndex);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize>::Dispatch(
            this,
            call_info,
            replay_object,
            Stage,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass>::Dispatch(
            this,
            call_info,
            replay_object,
            NumRenderTargets,
            pRenderTargets,
            pDepthStencil,
            Flags);
        MapStructArrayObjects(pRenderTargets->GetMetaStructPointer(), pRenderTargets->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructObjects(pDepthStencil->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList4*>(replay_object->object)->BeginRenderPass(NumRenderTargets,
                                                                                              pRenderTargets->GetPointer(),
                                                                                              pDepthStencil->GetPointer(),
                                                                                              Flags);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass>::Dispatch(
            this,
            call_info,
            replay_object,
            NumRenderTargets,
            pRenderTargets,
            pDepthStencil,
            Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12GraphicsCommandList4*>(replay_object->object)->EndRenderPass();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pMetaCommand,
    PointerDecoder<uint8_t>*                    pInitializationParametersData,
    SIZE_T                                      InitializationParametersDataSizeInBytes)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand>::Dispatch(
            this,
            call_info,
            replay_object,
            pMetaCommand,
            pInitializationParametersData,
            InitializationParametersDataSizeInBytes);
        auto in_pMetaCommand = MapObject<ID3D12MetaCommand>(pMetaCommand);
        reinterpret_cast<ID3D12GraphicsCommandList4*>(replay_object->object)->InitializeMetaCommand(in_pMetaCommand,
                                                                                                    pInitializationParametersData->GetPointer(),
                                                                                                    InitializationParametersDataSizeInBytes);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand>::Dispatch(
            this,
            call_info,
            replay_object,
            pMetaCommand,
            pInitializationParametersData,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand>::Dispatch(
            this,
            call_info,
            replay_object,
            pMetaCommand,
            pExecutionParametersData,
            ExecutionParametersDataSizeInBytes);
        auto in_pMetaCommand = MapObject<ID3D12MetaCommand>(pMetaCommand);
        reinterpret_cast<ID3D12GraphicsCommandList4*>(replay_object->object)->ExecuteMetaCommand(in_pMetaCommand,
                                                                                                 pExecutionParametersData->GetPointer(),
                                                                                                 ExecutionParametersDataSizeInBytes);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand>::Dispatch(
            this,
            call_info,
            replay_object,
            pMetaCommand,
            pExecutionParametersData,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            NumPostbuildInfoDescs,
            pPostbuildInfoDescs);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        MapStructArrayObjects(pPostbuildInfoDescs->GetMetaStructPointer(), pPostbuildInfoDescs->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideBuildRaytracingAccelerationStructure(replay_object,
                                                     pDesc,
                                                     NumPostbuildInfoDescs,
                                                     pPostbuildInfoDescs);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure>::Dispatch(
            this,
            call_info,
            replay_object,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            NumSourceAccelerationStructures,
            pSourceAccelerationStructureData);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        if (pSourceAccelerationStructureData && !pSourceAccelerationStructureData->IsNull())
        {
            MapGpuVirtualAddresses(pSourceAccelerationStructureData->GetPointer(), NumSourceAccelerationStructures);
        }
        reinterpret_cast<ID3D12GraphicsCommandList4*>(replay_object->object)->EmitRaytracingAccelerationStructurePostbuildInfo(pDesc->GetPointer(),
                                                                                                                               NumSourceAccelerationStructures,
                                                                                                                               pSourceAccelerationStructureData->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            NumSourceAccelerationStructures,
            pSourceAccelerationStructureData);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_GPU_VIRTUAL_ADDRESS                   DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS                   SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure>::Dispatch(
            this,
            call_info,
            replay_object,
            DestAccelerationStructureData,
            SourceAccelerationStructureData,
            Mode);
        MapGpuVirtualAddress(DestAccelerationStructureData);
        MapGpuVirtualAddress(SourceAccelerationStructureData);
        reinterpret_cast<ID3D12GraphicsCommandList4*>(replay_object->object)->CopyRaytracingAccelerationStructure(DestAccelerationStructureData,
                                                                                                                  SourceAccelerationStructureData,
                                                                                                                  Mode);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure>::Dispatch(
            this,
            call_info,
            replay_object,
            DestAccelerationStructureData,
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1>::Dispatch(
            this,
            call_info,
            replay_object,
            pStateObject);
        auto in_pStateObject = GetObjectInfo(pStateObject);
        OverrideSetPipelineState1(replay_object,
                                  in_pStateObject);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1>::Dispatch(
            this,
            call_info,
            replay_object,
            pStateObject);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_DispatchRays>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc);
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable(), GetGpuVaTable());
        OverrideDispatchRays(replay_object,
                             pDesc);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_DispatchRays>::Dispatch(
            this,
            call_info,
            replay_object,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_FindValue>::Dispatch(
            this,
            call_info,
            replay_object,
            pKey,
            KeySize,
            pValue,
            pValueSize);
        auto replay_result = reinterpret_cast<ID3D12ShaderCacheSession*>(replay_object->object)->FindValue(pKey->GetPointer(),
                                                                                                           KeySize,
                                                                                                           pValue->GetPointer(),
                                                                                                           pValueSize->GetPointer());
        CheckReplayResult("ID3D12ShaderCacheSession_FindValue", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_FindValue>::Dispatch(
            this,
            call_info,
            replay_object,
            pKey,
            KeySize,
            pValue,
            pValueSize);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_StoreValue>::Dispatch(
            this,
            call_info,
            replay_object,
            pKey,
            KeySize,
            pValue,
            ValueSize);
        auto replay_result = reinterpret_cast<ID3D12ShaderCacheSession*>(replay_object->object)->StoreValue(pKey->GetPointer(),
                                                                                                            KeySize,
                                                                                                            pValue->GetPointer(),
                                                                                                            ValueSize);
        CheckReplayResult("ID3D12ShaderCacheSession_StoreValue", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_StoreValue>::Dispatch(
            this,
            call_info,
            replay_object,
            pKey,
            KeySize,
            pValue,
            ValueSize);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ShaderCacheSession_SetDeleteOnDestroy(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_SetDeleteOnDestroy>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12ShaderCacheSession*>(replay_object->object)->SetDeleteOnDestroy();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_SetDeleteOnDestroy>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ShaderCacheSession_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_SHADER_CACHE_SESSION_DESC     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12ShaderCacheSession*>(replay_object->object)->GetDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device9_CreateShaderCacheSession>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppvSession);
        if(!ppvSession->IsNull()) ppvSession->SetHandleLength(1);
        auto out_p_ppvSession    = ppvSession->GetPointer();
        auto out_hp_ppvSession   = ppvSession->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device9*>(replay_object->object)->CreateShaderCacheSession(pDesc->GetPointer(),
                                                                                                               *riid.decoded_value,
                                                                                                               out_hp_ppvSession);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvSession, out_hp_ppvSession, format::ApiCall_ID3D12Device9_CreateShaderCacheSession);
        }
        CheckReplayResult("ID3D12Device9_CreateShaderCacheSession", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device9_CreateShaderCacheSession>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            riid,
            ppvSession);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device9_ShaderCacheControl(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_SHADER_CACHE_KIND_FLAGS               Kinds,
    D3D12_SHADER_CACHE_CONTROL_FLAGS            Control)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device9_ShaderCacheControl>::Dispatch(
            this,
            call_info,
            replay_object,
            Kinds,
            Control);
        auto replay_result = reinterpret_cast<ID3D12Device9*>(replay_object->object)->ShaderCacheControl(Kinds,
                                                                                                         Control);
        CheckReplayResult("ID3D12Device9_ShaderCacheControl", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device9_ShaderCacheControl>::Dispatch(
            this,
            call_info,
            replay_object,
            Kinds,
            Control);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device9_CreateCommandQueue1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            CreatorID,
            riid,
            ppCommandQueue);
        if(!ppCommandQueue->IsNull()) ppCommandQueue->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppCommandQueue->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateCommandQueue1(replay_object,
                                                         return_value,
                                                         pDesc,
                                                         CreatorID,
                                                         riid,
                                                         ppCommandQueue);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppCommandQueue->GetPointer(), ppCommandQueue->GetHandlePointer(), std::move(object_info), format::ApiCall_ID3D12Device9_CreateCommandQueue1);
        }
        CheckReplayResult("ID3D12Device9_CreateCommandQueue1", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device9_CreateCommandQueue1>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            CreatorID,
            riid,
            ppCommandQueue);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device10_CreateCommittedResource3>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialLayout,
            pOptimizedClearValue,
            pProtectedSession,
            NumCastableFormats,
            pCastableFormats,
            riidResource,
            ppvResource);
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device10*>(replay_object->object)->CreateCommittedResource3(pHeapProperties->GetPointer(),
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device10_CreateCommittedResource3>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialLayout,
            pOptimizedClearValue,
            pProtectedSession,
            NumCastableFormats,
            pCastableFormats,
            riidResource,
            ppvResource);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device10_CreatePlacedResource2>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeap,
            HeapOffset,
            pDesc,
            InitialLayout,
            pOptimizedClearValue,
            NumCastableFormats,
            pCastableFormats,
            riid,
            ppvResource);
        auto in_pHeap = MapObject<ID3D12Heap>(pHeap);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device10*>(replay_object->object)->CreatePlacedResource2(in_pHeap,
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device10_CreatePlacedResource2>::Dispatch(
            this,
            call_info,
            replay_object,
            pHeap,
            HeapOffset,
            pDesc,
            InitialLayout,
            pOptimizedClearValue,
            NumCastableFormats,
            pCastableFormats,
            riid,
            ppvResource);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device10_CreateReservedResource2>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            InitialLayout,
            pOptimizedClearValue,
            pProtectedSession,
            NumCastableFormats,
            pCastableFormats,
            riid,
            ppvResource);
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12Device10*>(replay_object->object)->CreateReservedResource2(pDesc->GetPointer(),
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
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device10_CreateReservedResource2>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            InitialLayout,
            pOptimizedClearValue,
            pProtectedSession,
            NumCastableFormats,
            pCastableFormats,
            riid,
            ppvResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device11_CreateSampler2(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC2>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device11_CreateSampler2>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            DestDescriptor);
        MapStructObjects(&DestDescriptor, GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12Device11*>(replay_object->object)->CreateSampler2(pDesc->GetPointer(),
                                                                                 *DestDescriptor.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device11_CreateSampler2>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            DestDescriptor);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device12_GetResourceAllocationInfo3(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO      return_value,
    UINT                                        visibleMask,
    UINT                                        numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
    PointerDecoder<UINT32>*                     pNumCastableFormats,
    PointerDecoder<DXGI_FORMAT*>*               ppCastableFormats,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Device12_GetResourceAllocationInfo3>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pNumCastableFormats,
            ppCastableFormats,
            pResourceAllocationInfo1);
        auto replay_result = reinterpret_cast<ID3D12Device12*>(replay_object->object)->GetResourceAllocationInfo3(visibleMask,
                                                                                                                  numResourceDescs,
                                                                                                                  pResourceDescs->GetPointer(),
                                                                                                                  pNumCastableFormats->GetPointer(),
                                                                                                                  ppCastableFormats->GetPointer(),
                                                                                                                  pResourceAllocationInfo1->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Device12_GetResourceAllocationInfo3>::Dispatch(
            this,
            call_info,
            replay_object,
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pNumCastableFormats,
            ppCastableFormats,
            pResourceAllocationInfo1);
    }
}

void Dx12ReplayConsumer::Process_ID3D12VirtualizationGuestDevice_ShareWithHost(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pObject,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost>::Dispatch(
            this,
            call_info,
            replay_object,
            pObject,
            pHandle);
        auto in_pObject = MapObject<ID3D12DeviceChild>(pObject);
        if(!pHandle->IsNull())
        {
            pHandle->AllocateOutputData(1);
        }
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = reinterpret_cast<ID3D12VirtualizationGuestDevice*>(replay_object->object)->ShareWithHost(in_pObject,
                                                                                                                      out_op_pHandle);
        CheckReplayResult("ID3D12VirtualizationGuestDevice_ShareWithHost", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost>::Dispatch(
            this,
            call_info,
            replay_object,
            pObject,
            pHandle);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_CreateFenceFd>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            FenceValue,
            pFenceFd);
        auto in_pFence = MapObject<ID3D12Fence>(pFence);
        auto replay_result = reinterpret_cast<ID3D12VirtualizationGuestDevice*>(replay_object->object)->CreateFenceFd(in_pFence,
                                                                                                                      FenceValue,
                                                                                                                      pFenceFd->GetPointer());
        CheckReplayResult("ID3D12VirtualizationGuestDevice_CreateFenceFd", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_CreateFenceFd>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            FenceValue,
            pFenceFd);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        bEnable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Tools_EnableShaderInstrumentation>::Dispatch(
            this,
            call_info,
            replay_object,
            bEnable);
        reinterpret_cast<ID3D12Tools*>(replay_object->object)->EnableShaderInstrumentation(bEnable);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Tools_EnableShaderInstrumentation>::Dispatch(
            this,
            call_info,
            replay_object,
            bEnable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Tools_ShaderInstrumentationEnabled>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12Tools*>(replay_object->object)->ShaderInstrumentationEnabled();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Tools_ShaderInstrumentationEnabled>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SDKConfiguration_SetSDKVersion(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        SDKVersion,
    StringDecoder*                              SDKPath)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SDKConfiguration_SetSDKVersion>::Dispatch(
            this,
            call_info,
            replay_object,
            SDKVersion,
            SDKPath);
        auto replay_result = reinterpret_cast<ID3D12SDKConfiguration*>(replay_object->object)->SetSDKVersion(SDKVersion,
                                                                                                             SDKPath->GetPointer());
        CheckReplayResult("ID3D12SDKConfiguration_SetSDKVersion", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SDKConfiguration_SetSDKVersion>::Dispatch(
            this,
            call_info,
            replay_object,
            SDKVersion,
            SDKPath);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory>::Dispatch(
            this,
            call_info,
            replay_object,
            SDKVersion,
            SDKPath,
            riid,
            ppvFactory);
        if(!ppvFactory->IsNull()) ppvFactory->SetHandleLength(1);
        auto out_p_ppvFactory    = ppvFactory->GetPointer();
        auto out_hp_ppvFactory   = ppvFactory->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12SDKConfiguration1*>(replay_object->object)->CreateDeviceFactory(SDKVersion,
                                                                                                                    SDKPath->GetPointer(),
                                                                                                                    *riid.decoded_value,
                                                                                                                    out_hp_ppvFactory);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvFactory, out_hp_ppvFactory, format::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory);
        }
        CheckReplayResult("ID3D12SDKConfiguration1_CreateDeviceFactory", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory>::Dispatch(
            this,
            call_info,
            replay_object,
            SDKVersion,
            SDKPath,
            riid,
            ppvFactory);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SDKConfiguration1_FreeUnusedSDKs(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_FreeUnusedSDKs>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12SDKConfiguration1*>(replay_object->object)->FreeUnusedSDKs();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_FreeUnusedSDKs>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_InitializeFromGlobalState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_InitializeFromGlobalState>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DeviceFactory*>(replay_object->object)->InitializeFromGlobalState();
        CheckReplayResult("ID3D12DeviceFactory_InitializeFromGlobalState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_InitializeFromGlobalState>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_ApplyToGlobalState(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_ApplyToGlobalState>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DeviceFactory*>(replay_object->object)->ApplyToGlobalState();
        CheckReplayResult("ID3D12DeviceFactory_ApplyToGlobalState", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_ApplyToGlobalState>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_SetFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEVICE_FACTORY_FLAGS                  flags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_SetFlags>::Dispatch(
            this,
            call_info,
            replay_object,
            flags);
        auto replay_result = reinterpret_cast<ID3D12DeviceFactory*>(replay_object->object)->SetFlags(flags);
        CheckReplayResult("ID3D12DeviceFactory_SetFlags", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_SetFlags>::Dispatch(
            this,
            call_info,
            replay_object,
            flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceFactory_GetFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DEVICE_FACTORY_FLAGS                  return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetFlags>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DeviceFactory*>(replay_object->object)->GetFlags();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetFlags>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            clsid,
            iid,
            ppv);
        if(!ppv->IsNull()) ppv->SetHandleLength(1);
        auto out_p_ppv    = ppv->GetPointer();
        auto out_hp_ppv   = ppv->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12DeviceFactory*>(replay_object->object)->GetConfigurationInterface(*clsid.decoded_value,
                                                                                                                      *iid.decoded_value,
                                                                                                                      out_hp_ppv);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppv, out_hp_ppv, format::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface);
        }
        CheckReplayResult("ID3D12DeviceFactory_GetConfigurationInterface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            clsid,
            iid,
            ppv);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_EnableExperimentalFeatures>::Dispatch(
            this,
            call_info,
            replay_object,
            NumFeatures,
            pIIDs,
            pConfigurationStructs,
            pConfigurationStructSizes);
        auto replay_result = reinterpret_cast<ID3D12DeviceFactory*>(replay_object->object)->EnableExperimentalFeatures(NumFeatures,
                                                                                                                       pIIDs->GetPointer(),
                                                                                                                       pConfigurationStructs->GetPointer(),
                                                                                                                       pConfigurationStructSizes->GetPointer());
        CheckReplayResult("ID3D12DeviceFactory_EnableExperimentalFeatures", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_EnableExperimentalFeatures>::Dispatch(
            this,
            call_info,
            replay_object,
            NumFeatures,
            pIIDs,
            pConfigurationStructs,
            pConfigurationStructSizes);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_CreateDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            adapter,
            FeatureLevel,
            riid,
            ppvDevice);
        auto in_adapter = MapObject<IUnknown>(adapter);
        if(!ppvDevice->IsNull()) ppvDevice->SetHandleLength(1);
        auto out_p_ppvDevice    = ppvDevice->GetPointer();
        auto out_hp_ppvDevice   = ppvDevice->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12DeviceFactory*>(replay_object->object)->CreateDevice(in_adapter,
                                                                                                         FeatureLevel,
                                                                                                         *riid.decoded_value,
                                                                                                         out_hp_ppvDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDevice, out_hp_ppvDevice, format::ApiCall_ID3D12DeviceFactory_CreateDevice);
        }
        CheckReplayResult("ID3D12DeviceFactory_CreateDevice", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceFactory_CreateDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            adapter,
            FeatureLevel,
            riid,
            ppvDevice);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceConfiguration_GetDesc(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_D3D12_DEVICE_CONFIGURATION_DESC     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DeviceConfiguration*>(replay_object->object)->GetDesc();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetDesc>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_GUID>*         pGuids,
    UINT                                        NumGuids)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures>::Dispatch(
            this,
            call_info,
            replay_object,
            pGuids,
            NumGuids);
        auto replay_result = reinterpret_cast<ID3D12DeviceConfiguration*>(replay_object->object)->GetEnabledExperimentalFeatures(pGuids->GetPointer(),
                                                                                                                                 NumGuids);
        CheckReplayResult("ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures>::Dispatch(
            this,
            call_info,
            replay_object,
            pGuids,
            NumGuids);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            ppResult,
            ppError);
        if(!ppResult->IsNull()) ppResult->SetHandleLength(1);
        auto out_p_ppResult    = ppResult->GetPointer();
        auto out_hp_ppResult   = ppResult->GetHandlePointer();
        if(!ppError->IsNull()) ppError->SetHandleLength(1);
        auto out_p_ppError    = ppError->GetPointer();
        auto out_hp_ppError   = ppError->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12DeviceConfiguration*>(replay_object->object)->SerializeVersionedRootSignature(pDesc->GetPointer(),
                                                                                                                                  out_hp_ppResult,
                                                                                                                                  out_hp_ppError);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppResult, out_hp_ppResult, format::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature);
            AddObject(out_p_ppError, out_hp_ppError, format::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature);
        }
        CheckReplayResult("ID3D12DeviceConfiguration_SerializeVersionedRootSignature", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature>::Dispatch(
            this,
            call_info,
            replay_object,
            pDesc,
            ppResult,
            ppError);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer>::Dispatch(
            this,
            call_info,
            replay_object,
            pBlob,
            Size,
            riid,
            ppvDeserializer);
        if(!ppvDeserializer->IsNull()) ppvDeserializer->SetHandleLength(1);
        auto out_p_ppvDeserializer    = ppvDeserializer->GetPointer();
        auto out_hp_ppvDeserializer   = ppvDeserializer->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12DeviceConfiguration*>(replay_object->object)->CreateVersionedRootSignatureDeserializer(pBlob->GetPointer(),
                                                                                                                                           Size,
                                                                                                                                           *riid.decoded_value,
                                                                                                                                           out_hp_ppvDeserializer);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDeserializer, out_hp_ppvDeserializer, format::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer);
        }
        CheckReplayResult("ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer>::Dispatch(
            this,
            call_info,
            replay_object,
            pBlob,
            Size,
            riid,
            ppvDeserializer);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_SHADING_RATE                          baseShadingRate,
    PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate>::Dispatch(
            this,
            call_info,
            replay_object,
            baseShadingRate,
            combiners);
        reinterpret_cast<ID3D12GraphicsCommandList5*>(replay_object->object)->RSSetShadingRate(baseShadingRate,
                                                                                               combiners->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate>::Dispatch(
            this,
            call_info,
            replay_object,
            baseShadingRate,
            combiners);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            shadingRateImage)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage>::Dispatch(
            this,
            call_info,
            replay_object,
            shadingRateImage);
        auto in_shadingRateImage = MapObject<ID3D12Resource>(shadingRateImage);
        reinterpret_cast<ID3D12GraphicsCommandList5*>(replay_object->object)->RSSetShadingRateImage(in_shadingRateImage);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage>::Dispatch(
            this,
            call_info,
            replay_object,
            shadingRateImage);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        ThreadGroupCountX,
    UINT                                        ThreadGroupCountY,
    UINT                                        ThreadGroupCountZ)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList6_DispatchMesh>::Dispatch(
            this,
            call_info,
            replay_object,
            ThreadGroupCountX,
            ThreadGroupCountY,
            ThreadGroupCountZ);
        reinterpret_cast<ID3D12GraphicsCommandList6*>(replay_object->object)->DispatchMesh(ThreadGroupCountX,
                                                                                           ThreadGroupCountY,
                                                                                           ThreadGroupCountZ);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList6_DispatchMesh>::Dispatch(
            this,
            call_info,
            replay_object,
            ThreadGroupCountX,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList7_Barrier>::Dispatch(
            this,
            call_info,
            replay_object,
            NumBarrierGroups,
            pBarrierGroups);
        MapStructArrayObjects(pBarrierGroups->GetMetaStructPointer(), pBarrierGroups->GetLength(), GetObjectInfoTable(), GetGpuVaTable());
        reinterpret_cast<ID3D12GraphicsCommandList7*>(replay_object->object)->Barrier(NumBarrierGroups,
                                                                                      pBarrierGroups->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList7_Barrier>::Dispatch(
            this,
            call_info,
            replay_object,
            NumBarrierGroups,
            pBarrierGroups);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        FrontStencilRef,
    UINT                                        BackStencilRef)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef>::Dispatch(
            this,
            call_info,
            replay_object,
            FrontStencilRef,
            BackStencilRef);
        reinterpret_cast<ID3D12GraphicsCommandList8*>(replay_object->object)->OMSetFrontAndBackStencilRef(FrontStencilRef,
                                                                                                          BackStencilRef);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef>::Dispatch(
            this,
            call_info,
            replay_object,
            FrontStencilRef,
            BackStencilRef);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList9_RSSetDepthBias(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    FLOAT                                       DepthBias,
    FLOAT                                       DepthBiasClamp,
    FLOAT                                       SlopeScaledDepthBias)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_RSSetDepthBias>::Dispatch(
            this,
            call_info,
            replay_object,
            DepthBias,
            DepthBiasClamp,
            SlopeScaledDepthBias);
        reinterpret_cast<ID3D12GraphicsCommandList9*>(replay_object->object)->RSSetDepthBias(DepthBias,
                                                                                             DepthBiasClamp,
                                                                                             SlopeScaledDepthBias);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_RSSetDepthBias>::Dispatch(
            this,
            call_info,
            replay_object,
            DepthBias,
            DepthBiasClamp,
            SlopeScaledDepthBias);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE          IBStripCutValue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue>::Dispatch(
            this,
            call_info,
            replay_object,
            IBStripCutValue);
        reinterpret_cast<ID3D12GraphicsCommandList9*>(replay_object->object)->IASetIndexBufferStripCutValue(IBStripCutValue);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue>::Dispatch(
            this,
            call_info,
            replay_object,
            IBStripCutValue);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DSRDeviceFactory_CreateDSRDevice(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    format::HandleId                            pD3D12Device,
    UINT                                        NodeMask,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDSRDevice)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            pD3D12Device,
            NodeMask,
            riid,
            ppvDSRDevice);
        auto in_pD3D12Device = MapObject<ID3D12Device>(pD3D12Device);
        if(!ppvDSRDevice->IsNull()) ppvDSRDevice->SetHandleLength(1);
        auto out_p_ppvDSRDevice    = ppvDSRDevice->GetPointer();
        auto out_hp_ppvDSRDevice   = ppvDSRDevice->GetHandlePointer();
        auto replay_result = reinterpret_cast<ID3D12DSRDeviceFactory*>(replay_object->object)->CreateDSRDevice(in_pD3D12Device,
                                                                                                               NodeMask,
                                                                                                               *riid.decoded_value,
                                                                                                               out_hp_ppvDSRDevice);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvDSRDevice, out_hp_ppvDSRDevice, format::ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice);
        }
        CheckReplayResult("ID3D12DSRDeviceFactory_CreateDSRDevice", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice>::Dispatch(
            this,
            call_info,
            replay_object,
            pD3D12Device,
            NodeMask,
            riid,
            ppvDSRDevice);
    }
}

void Dx12ReplayConsumer::Process_ID3D10Blob_GetBufferPointer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    uint64_t                                    return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D10Blob_GetBufferPointer>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D10Blob*>(replay_object->object)->GetBufferPointer();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D10Blob_GetBufferPointer>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D10Blob_GetBufferSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    SIZE_T                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D10Blob_GetBufferSize>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D10Blob*>(replay_object->object)->GetBufferSize();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D10Blob_GetBufferSize>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            callbackFn,
            pData,
            pCallbackID);
        auto in_pData = PreProcessExternalObject(pData, format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback, "ID3DDestructionNotifier_RegisterDestructionCallback");
        auto replay_result = reinterpret_cast<ID3DDestructionNotifier*>(replay_object->object)->RegisterDestructionCallback(reinterpret_cast<PFN_DESTRUCTION_CALLBACK>(callbackFn),
                                                                                                                            in_pData,
                                                                                                                            pCallbackID->GetPointer());
        CheckReplayResult("ID3DDestructionNotifier_RegisterDestructionCallback", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            callbackFn,
            pData,
            pCallbackID);
    }
}

void Dx12ReplayConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT                                        callbackID)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            callbackID);
        auto replay_result = reinterpret_cast<ID3DDestructionNotifier*>(replay_object->object)->UnregisterDestructionCallback(callbackID);
        CheckReplayResult("ID3DDestructionNotifier_UnregisterDestructionCallback", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            callbackID);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug_EnableDebugLayer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug_EnableDebugLayer>::Dispatch(
            this,
            call_info,
            replay_object);
        OverrideEnableDebugLayer(replay_object);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug_EnableDebugLayer>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug1_EnableDebugLayer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug1_EnableDebugLayer>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12Debug1*>(replay_object->object)->EnableDebugLayer();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug1_EnableDebugLayer>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug1_SetEnableGPUBasedValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableGPUBasedValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
        reinterpret_cast<ID3D12Debug1*>(replay_object->object)->SetEnableGPUBasedValidation(Enable);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableGPUBasedValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
        reinterpret_cast<ID3D12Debug1*>(replay_object->object)->SetEnableSynchronizedCommandQueueValidation(Enable);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug2_SetGPUBasedValidationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_GPU_BASED_VALIDATION_FLAGS            Flags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug2_SetGPUBasedValidationFlags>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
        reinterpret_cast<ID3D12Debug2*>(replay_object->object)->SetGPUBasedValidationFlags(Flags);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug2_SetGPUBasedValidationFlags>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug3_SetEnableGPUBasedValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableGPUBasedValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
        reinterpret_cast<ID3D12Debug3*>(replay_object->object)->SetEnableGPUBasedValidation(Enable);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableGPUBasedValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
        reinterpret_cast<ID3D12Debug3*>(replay_object->object)->SetEnableSynchronizedCommandQueueValidation(Enable);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug3_SetGPUBasedValidationFlags(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_GPU_BASED_VALIDATION_FLAGS            Flags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug3_SetGPUBasedValidationFlags>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
        reinterpret_cast<ID3D12Debug3*>(replay_object->object)->SetGPUBasedValidationFlags(Flags);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug3_SetGPUBasedValidationFlags>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug4_DisableDebugLayer(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug4_DisableDebugLayer>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12Debug4*>(replay_object->object)->DisableDebugLayer();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug4_DisableDebugLayer>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug5_SetEnableAutoName(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug5_SetEnableAutoName>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
        reinterpret_cast<ID3D12Debug5*>(replay_object->object)->SetEnableAutoName(Enable);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug5_SetEnableAutoName>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Debug6_SetForceLegacyBarrierValidation(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        Enable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12Debug6_SetForceLegacyBarrierValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
        reinterpret_cast<ID3D12Debug6*>(replay_object->object)->SetForceLegacyBarrierValidation(Enable);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12Debug6_SetForceLegacyBarrierValidation>::Dispatch(
            this,
            call_info,
            replay_object,
            Enable);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice1_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice1*>(replay_object->object)->SetDebugParameter(Type,
                                                                                                             pData->GetPointer(),
                                                                                                             DataSize);
        CheckReplayResult("ID3D12DebugDevice1_SetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice1_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice1_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice1*>(replay_object->object)->GetDebugParameter(Type,
                                                                                                             pData->GetPointer(),
                                                                                                             DataSize);
        CheckReplayResult("ID3D12DebugDevice1_GetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice1_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice1_ReportLiveDeviceObjects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_RLDO_FLAGS                            Flags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice1_ReportLiveDeviceObjects>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice1*>(replay_object->object)->ReportLiveDeviceObjects(Flags);
        CheckReplayResult("ID3D12DebugDevice1_ReportLiveDeviceObjects", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice1_ReportLiveDeviceObjects>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice_SetFeatureMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_DEBUG_FEATURE                         Mask)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice_SetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object,
            Mask);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice*>(replay_object->object)->SetFeatureMask(Mask);
        CheckReplayResult("ID3D12DebugDevice_SetFeatureMask", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice_SetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object,
            Mask);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice_GetFeatureMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DEBUG_FEATURE                         return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice_GetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice*>(replay_object->object)->GetFeatureMask();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice_GetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugDevice_ReportLiveDeviceObjects(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_RLDO_FLAGS                            Flags)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice_ReportLiveDeviceObjects>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice*>(replay_object->object)->ReportLiveDeviceObjects(Flags);
        CheckReplayResult("ID3D12DebugDevice_ReportLiveDeviceObjects", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice_ReportLiveDeviceObjects>::Dispatch(
            this,
            call_info,
            replay_object,
            Flags);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice2_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice2*>(replay_object->object)->SetDebugParameter(Type,
                                                                                                             pData->GetPointer(),
                                                                                                             DataSize);
        CheckReplayResult("ID3D12DebugDevice2_SetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice2_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugDevice2_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugDevice2*>(replay_object->object)->GetDebugParameter(Type,
                                                                                                             pData->GetPointer(),
                                                                                                             DataSize);
        CheckReplayResult("ID3D12DebugDevice2_GetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugDevice2_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandQueue_AssertResourceState>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            State);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandQueue*>(replay_object->object)->AssertResourceState(in_pResource,
                                                                                                                    Subresource,
                                                                                                                    State);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandQueue_AssertResourceState>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertResourceAccess>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            Access);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        reinterpret_cast<ID3D12DebugCommandQueue1*>(replay_object->object)->AssertResourceAccess(in_pResource,
                                                                                                 Subresource,
                                                                                                 Access);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertResourceAccess>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertTextureLayout>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            Layout);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        reinterpret_cast<ID3D12DebugCommandQueue1*>(replay_object->object)->AssertTextureLayout(in_pResource,
                                                                                                Subresource,
                                                                                                Layout);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertTextureLayout>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList1_AssertResourceState>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            State);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList1*>(replay_object->object)->AssertResourceState(in_pResource,
                                                                                                                    Subresource,
                                                                                                                    State);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList1_AssertResourceState>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList1_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList1*>(replay_object->object)->SetDebugParameter(Type,
                                                                                                                  pData->GetPointer(),
                                                                                                                  DataSize);
        CheckReplayResult("ID3D12DebugCommandList1_SetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList1_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList1_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList1*>(replay_object->object)->GetDebugParameter(Type,
                                                                                                                  pData->GetPointer(),
                                                                                                                  DataSize);
        CheckReplayResult("ID3D12DebugCommandList1_GetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList1_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList_AssertResourceState>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            State);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList*>(replay_object->object)->AssertResourceState(in_pResource,
                                                                                                                   Subresource,
                                                                                                                   State);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList_AssertResourceState>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList_SetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object,
            Mask);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList*>(replay_object->object)->SetFeatureMask(Mask);
        CheckReplayResult("ID3D12DebugCommandList_SetFeatureMask", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList_SetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object,
            Mask);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList_GetFeatureMask(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    D3D12_DEBUG_FEATURE                         return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList_GetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList*>(replay_object->object)->GetFeatureMask();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList_GetFeatureMask>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList2_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList2*>(replay_object->object)->SetDebugParameter(Type,
                                                                                                                  pData->GetPointer(),
                                                                                                                  DataSize);
        CheckReplayResult("ID3D12DebugCommandList2_SetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList2_SetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList2_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
        auto replay_result = reinterpret_cast<ID3D12DebugCommandList2*>(replay_object->object)->GetDebugParameter(Type,
                                                                                                                  pData->GetPointer(),
                                                                                                                  DataSize);
        CheckReplayResult("ID3D12DebugCommandList2_GetDebugParameter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList2_GetDebugParameter>::Dispatch(
            this,
            call_info,
            replay_object,
            Type,
            pData,
            DataSize);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DebugCommandList3_AssertResourceAccess(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    UINT                                        Subresource,
    D3D12_BARRIER_ACCESS                        Access)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertResourceAccess>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            Access);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        reinterpret_cast<ID3D12DebugCommandList3*>(replay_object->object)->AssertResourceAccess(in_pResource,
                                                                                                Subresource,
                                                                                                Access);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertResourceAccess>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertTextureLayout>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            Layout);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        reinterpret_cast<ID3D12DebugCommandList3*>(replay_object->object)->AssertTextureLayout(in_pResource,
                                                                                               Subresource,
                                                                                               Layout);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertTextureLayout>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SharingContract_Present>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            window);
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        auto in_window = static_cast<HWND>(PreProcessExternalObject(window, format::ApiCallId::ApiCall_ID3D12SharingContract_Present, "ID3D12SharingContract_Present"));
        reinterpret_cast<ID3D12SharingContract*>(replay_object->object)->Present(in_pResource,
                                                                                 Subresource,
                                                                                 in_window);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SharingContract_Present>::Dispatch(
            this,
            call_info,
            replay_object,
            pResource,
            Subresource,
            window);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SharingContract_SharedFenceSignal(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    format::HandleId                            pFence,
    UINT64                                      FenceValue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SharingContract_SharedFenceSignal>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            FenceValue);
        auto in_pFence = MapObject<ID3D12Fence>(pFence);
        reinterpret_cast<ID3D12SharingContract*>(replay_object->object)->SharedFenceSignal(in_pFence,
                                                                                           FenceValue);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SharingContract_SharedFenceSignal>::Dispatch(
            this,
            call_info,
            replay_object,
            pFence,
            FenceValue);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SharingContract_BeginCapturableWork(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_GUID                                guid)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SharingContract_BeginCapturableWork>::Dispatch(
            this,
            call_info,
            replay_object,
            guid);
        reinterpret_cast<ID3D12SharingContract*>(replay_object->object)->BeginCapturableWork(*guid.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SharingContract_BeginCapturableWork>::Dispatch(
            this,
            call_info,
            replay_object,
            guid);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SharingContract_EndCapturableWork(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    Decoded_GUID                                guid)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12SharingContract_EndCapturableWork>::Dispatch(
            this,
            call_info,
            replay_object,
            guid);
        reinterpret_cast<ID3D12SharingContract*>(replay_object->object)->EndCapturableWork(*guid.decoded_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12SharingContract_EndCapturableWork>::Dispatch(
            this,
            call_info,
            replay_object,
            guid);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ManualWriteTrackingResource_TrackWrite(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        Subresource,
    StructPointerDecoder<Decoded_D3D12_RANGE>*  pWrittenRange)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12ManualWriteTrackingResource_TrackWrite>::Dispatch(
            this,
            call_info,
            replay_object,
            Subresource,
            pWrittenRange);
        reinterpret_cast<ID3D12ManualWriteTrackingResource*>(replay_object->object)->TrackWrite(Subresource,
                                                                                                pWrittenRange->GetPointer());
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12ManualWriteTrackingResource_TrackWrite>::Dispatch(
            this,
            call_info,
            replay_object,
            Subresource,
            pWrittenRange);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetMessageCountLimit(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    UINT64                                      MessageCountLimit)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMessageCountLimit>::Dispatch(
            this,
            call_info,
            replay_object,
            MessageCountLimit);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->SetMessageCountLimit(MessageCountLimit);
        CheckReplayResult("ID3D12InfoQueue_SetMessageCountLimit", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMessageCountLimit>::Dispatch(
            this,
            call_info,
            replay_object,
            MessageCountLimit);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_ClearStoredMessages(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStoredMessages>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->ClearStoredMessages();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStoredMessages>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessage>::Dispatch(
            this,
            call_info,
            replay_object,
            MessageIndex,
            pMessage,
            pMessageByteLength);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetMessage(MessageIndex,
                                                                                                   pMessage->GetPointer(),
                                                                                                   pMessageByteLength->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_GetMessage", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessage>::Dispatch(
            this,
            call_info,
            replay_object,
            MessageIndex,
            pMessage,
            pMessageByteLength);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetNumMessagesAllowedByStorageFilter();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetNumMessagesDeniedByStorageFilter();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumStoredMessages(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessages>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetNumStoredMessages();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessages>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetNumStoredMessagesAllowedByRetrievalFilter();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetNumMessagesDiscardedByMessageCountLimit();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetMessageCountLimit(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT64                                      return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessageCountLimit>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetMessageCountLimit();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessageCountLimit>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_AddStorageFilterEntries(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddStorageFilterEntries>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->AddStorageFilterEntries(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddStorageFilterEntries", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddStorageFilterEntries>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                     pFilterByteLength)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter,
            pFilterByteLength);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetStorageFilter(pFilter->GetPointer(),
                                                                                                         pFilterByteLength->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_GetStorageFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter,
            pFilterByteLength);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_ClearStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->ClearStorageFilter();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushEmptyStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PushEmptyStorageFilter();
        CheckReplayResult("ID3D12InfoQueue_PushEmptyStorageFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushCopyOfStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PushCopyOfStorageFilter();
        CheckReplayResult("ID3D12InfoQueue_PushCopyOfStorageFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PushStorageFilter(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_PushStorageFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PopStorageFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PopStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PopStorageFilter();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PopStorageFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetStorageFilterStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilterStackSize>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetStorageFilterStackSize();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilterStackSize>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_AddRetrievalFilterEntries(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddRetrievalFilterEntries>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->AddRetrievalFilterEntries(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddRetrievalFilterEntries", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddRetrievalFilterEntries>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter,
    PointerDecoder<SIZE_T>*                     pFilterByteLength)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter,
            pFilterByteLength);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetRetrievalFilter(pFilter->GetPointer(),
                                                                                                           pFilterByteLength->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_GetRetrievalFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter,
            pFilterByteLength);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_ClearRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->ClearRetrievalFilter();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushEmptyRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PushEmptyRetrievalFilter();
        CheckReplayResult("ID3D12InfoQueue_PushEmptyRetrievalFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PushCopyOfRetrievalFilter();
        CheckReplayResult("ID3D12InfoQueue_PushCopyOfRetrievalFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PushRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    StructPointerDecoder<Decoded_D3D12_INFO_QUEUE_FILTER>* pFilter)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PushRetrievalFilter(pFilter->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_PushRetrievalFilter", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PushRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object,
            pFilter);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_PopRetrievalFilter(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PopRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
        reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->PopRetrievalFilter();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_PopRetrievalFilter>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetRetrievalFilterStackSize(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    UINT                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilterStackSize>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetRetrievalFilterStackSize();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilterStackSize>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddMessage>::Dispatch(
            this,
            call_info,
            replay_object,
            Category,
            Severity,
            ID,
            pDescription);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->AddMessage(Category,
                                                                                                   Severity,
                                                                                                   ID,
                                                                                                   pDescription->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddMessage", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddMessage>::Dispatch(
            this,
            call_info,
            replay_object,
            Category,
            Severity,
            ID,
            pDescription);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_AddApplicationMessage(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_SEVERITY                      Severity,
    StringDecoder*                              pDescription)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddApplicationMessage>::Dispatch(
            this,
            call_info,
            replay_object,
            Severity,
            pDescription);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->AddApplicationMessage(Severity,
                                                                                                              pDescription->GetPointer());
        CheckReplayResult("ID3D12InfoQueue_AddApplicationMessage", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_AddApplicationMessage>::Dispatch(
            this,
            call_info,
            replay_object,
            Severity,
            pDescription);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetBreakOnCategory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_CATEGORY                      Category,
    BOOL                                        bEnable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnCategory>::Dispatch(
            this,
            call_info,
            replay_object,
            Category,
            bEnable);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->SetBreakOnCategory(Category,
                                                                                                           bEnable);
        CheckReplayResult("ID3D12InfoQueue_SetBreakOnCategory", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnCategory>::Dispatch(
            this,
            call_info,
            replay_object,
            Category,
            bEnable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetBreakOnSeverity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_SEVERITY                      Severity,
    BOOL                                        bEnable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnSeverity>::Dispatch(
            this,
            call_info,
            replay_object,
            Severity,
            bEnable);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->SetBreakOnSeverity(Severity,
                                                                                                           bEnable);
        CheckReplayResult("ID3D12InfoQueue_SetBreakOnSeverity", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnSeverity>::Dispatch(
            this,
            call_info,
            replay_object,
            Severity,
            bEnable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetBreakOnID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    D3D12_MESSAGE_ID                            ID,
    BOOL                                        bEnable)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnID>::Dispatch(
            this,
            call_info,
            replay_object,
            ID,
            bEnable);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->SetBreakOnID(ID,
                                                                                                     bEnable);
        CheckReplayResult("ID3D12InfoQueue_SetBreakOnID", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnID>::Dispatch(
            this,
            call_info,
            replay_object,
            ID,
            bEnable);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetBreakOnCategory(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    D3D12_MESSAGE_CATEGORY                      Category)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnCategory>::Dispatch(
            this,
            call_info,
            replay_object,
            Category);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetBreakOnCategory(Category);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnCategory>::Dispatch(
            this,
            call_info,
            replay_object,
            Category);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetBreakOnSeverity(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    D3D12_MESSAGE_SEVERITY                      Severity)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnSeverity>::Dispatch(
            this,
            call_info,
            replay_object,
            Severity);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetBreakOnSeverity(Severity);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnSeverity>::Dispatch(
            this,
            call_info,
            replay_object,
            Severity);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetBreakOnID(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value,
    D3D12_MESSAGE_ID                            ID)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnID>::Dispatch(
            this,
            call_info,
            replay_object,
            ID);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetBreakOnID(ID);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnID>::Dispatch(
            this,
            call_info,
            replay_object,
            ID);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_SetMuteDebugOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        bMute)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMuteDebugOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            bMute);
        reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->SetMuteDebugOutput(bMute);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMuteDebugOutput>::Dispatch(
            this,
            call_info,
            replay_object,
            bMute);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue_GetMuteDebugOutput(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    BOOL                                        return_value)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMuteDebugOutput>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue*>(replay_object->object)->GetMuteDebugOutput();
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMuteDebugOutput>::Dispatch(
            this,
            call_info,
            replay_object);
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
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            CallbackFunc,
            CallbackFilterFlags,
            pContext,
            pCallbackCookie);
        auto in_pContext = PreProcessExternalObject(pContext, format::ApiCallId::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback, "ID3D12InfoQueue1_RegisterMessageCallback");
        auto replay_result = reinterpret_cast<ID3D12InfoQueue1*>(replay_object->object)->RegisterMessageCallback(reinterpret_cast<D3D12MessageFunc>(CallbackFunc),
                                                                                                                 CallbackFilterFlags,
                                                                                                                 in_pContext,
                                                                                                                 pCallbackCookie->GetPointer());
        CheckReplayResult("ID3D12InfoQueue1_RegisterMessageCallback", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            CallbackFunc,
            CallbackFilterFlags,
            pContext,
            pCallbackCookie);
    }
}

void Dx12ReplayConsumer::Process_ID3D12InfoQueue1_UnregisterMessageCallback(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    DWORD                                       CallbackCookie)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_ID3D12InfoQueue1_UnregisterMessageCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            CallbackCookie);
        auto replay_result = reinterpret_cast<ID3D12InfoQueue1*>(replay_object->object)->UnregisterMessageCallback(CallbackCookie);
        CheckReplayResult("ID3D12InfoQueue1_UnregisterMessageCallback", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_ID3D12InfoQueue1_UnregisterMessageCallback>::Dispatch(
            this,
            call_info,
            replay_object,
            CallbackCookie);
    }
}

void Dx12ReplayConsumer::Process_IUnknown_QueryInterface(
    const ApiCallInfo&                          call_info,
    format::HandleId                            object_id,
    HRESULT                                     return_value,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvObject)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        CustomReplayPreCall<format::ApiCallId::ApiCall_IUnknown_QueryInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppvObject);
        if(!ppvObject->IsNull()) ppvObject->SetHandleLength(1);
        auto out_p_ppvObject    = ppvObject->GetPointer();
        auto out_hp_ppvObject   = ppvObject->GetHandlePointer();
        auto replay_result = reinterpret_cast<IUnknown*>(replay_object->object)->QueryInterface(*riid.decoded_value,
                                                                                                out_hp_ppvObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvObject, out_hp_ppvObject, format::ApiCall_IUnknown_QueryInterface);
        }
        CheckReplayResult("IUnknown_QueryInterface", return_value, replay_result);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IUnknown_QueryInterface>::Dispatch(
            this,
            call_info,
            replay_object,
            riid,
            ppvObject);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IUnknown_AddRef>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = OverrideAddRef(replay_object,
                                            return_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IUnknown_AddRef>::Dispatch(
            this,
            call_info,
            replay_object);
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
        CustomReplayPreCall<format::ApiCallId::ApiCall_IUnknown_Release>::Dispatch(
            this,
            call_info,
            replay_object);
        auto replay_result = OverrideRelease(replay_object,
                                             return_value);
        CustomReplayPostCall<format::ApiCallId::ApiCall_IUnknown_Release>::Dispatch(
            this,
            call_info,
            replay_object);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
