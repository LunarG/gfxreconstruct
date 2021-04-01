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
    HRESULT                                     returnValue,
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
        AddObject(out_p_ppFactory, out_hp_ppFactory);
    }
    CheckReplayResult("CreateDXGIFactory", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_CreateDXGIFactory1(
    HRESULT                                     returnValue,
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
        AddObject(out_p_ppFactory, out_hp_ppFactory);
    }
    CheckReplayResult("CreateDXGIFactory1", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_CreateDXGIFactory2(
    HRESULT                                     returnValue,
    UINT                                        Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    if(!ppFactory->IsNull()) ppFactory->SetHandleLength(1);
    auto out_p_ppFactory    = ppFactory->GetPointer();
    auto out_hp_ppFactory   = ppFactory->GetHandlePointer();
    auto replay_result = CreateDXGIFactory2(Flags,
                                            *riid.decoded_value,
                                            out_hp_ppFactory);
    if (SUCCEEDED(replay_result))
    {
        AddObject(out_p_ppFactory, out_hp_ppFactory);
    }
    CheckReplayResult("CreateDXGIFactory2", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_DXGIGetDebugInterface1(
    HRESULT                                     returnValue,
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
        AddObject(out_p_pDebug, out_hp_pDebug);
    }
    CheckReplayResult("DXGIGetDebugInterface1", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_DXGIDeclareAdapterRemovalSupport(
    HRESULT                                     returnValue)
{
    auto replay_result = DXGIDeclareAdapterRemovalSupport();
    CheckReplayResult("DXGIDeclareAdapterRemovalSupport", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12SerializeRootSignature(
    HRESULT                                     returnValue,
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
        AddObject(out_p_ppBlob, out_hp_ppBlob);
        AddObject(out_p_ppErrorBlob, out_hp_ppErrorBlob);
    }
    CheckReplayResult("D3D12SerializeRootSignature", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12CreateRootSignatureDeserializer(
    HRESULT                                     returnValue,
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
        AddObject(out_p_ppRootSignatureDeserializer, out_hp_ppRootSignatureDeserializer);
    }
    CheckReplayResult("D3D12CreateRootSignatureDeserializer", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12SerializeVersionedRootSignature(
    HRESULT                                     returnValue,
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
        AddObject(out_p_ppBlob, out_hp_ppBlob);
        AddObject(out_p_ppErrorBlob, out_hp_ppErrorBlob);
    }
    CheckReplayResult("D3D12SerializeVersionedRootSignature", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
    HRESULT                                     returnValue,
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
        AddObject(out_p_ppRootSignatureDeserializer, out_hp_ppRootSignatureDeserializer);
    }
    CheckReplayResult("D3D12CreateVersionedRootSignatureDeserializer", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12CreateDevice(
    HRESULT                                     returnValue,
    format::HandleId                            pAdapter,
    D3D_FEATURE_LEVEL                           MinimumFeatureLevel,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppDevice)
{
    auto in_pAdapter = GetObjectInfo(pAdapter);
    if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
    DxObjectInfo object_info{};
    ppDevice->SetConsumerData(0, &object_info);
    auto replay_result = OverrideD3D12CreateDevice(returnValue,
                                                   in_pAdapter,
                                                   MinimumFeatureLevel,
                                                   riid,
                                                   ppDevice);
    if (SUCCEEDED(replay_result))
    {
        AddObject(ppDevice->GetPointer(), ppDevice->GetHandlePointer(), object_info.extra_info_type, object_info.extra_info);
    }
    CheckReplayResult("D3D12CreateDevice", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12GetDebugInterface(
    HRESULT                                     returnValue,
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
        AddObject(out_p_ppvDebug, out_hp_ppvDebug);
    }
    CheckReplayResult("D3D12GetDebugInterface", returnValue, replay_result);
}

void Dx12ReplayConsumer::Process_D3D12EnableExperimentalFeatures(
    HRESULT                                     returnValue,
    UINT                                        NumFeatures,
    StructPointerDecoder<Decoded_GUID>*         pIIDs,
    PointerDecoder<uint8_t>*                    pConfigurationStructs,
    PointerDecoder<UINT>*                       pConfigurationStructSizes)
{
    auto replay_result = D3D12EnableExperimentalFeatures(NumFeatures,
                                                         pIIDs->GetPointer(),
                                                         pConfigurationStructs->GetPointer(),
                                                         pConfigurationStructSizes->GetPointer());
    CheckReplayResult("D3D12EnableExperimentalFeatures", returnValue, replay_result);
}
void Dx12ReplayConsumer::Process_IDXGIObject_SetPrivateData(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        CheckReplayResult("IDXGIObject_SetPrivateData", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_SetPrivateDataInterface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                Name,
    format::HandleId                            pUnknown)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pUnknown = MapObject<IUnknown>(pUnknown);
        auto replay_result = replay_object->SetPrivateDataInterface(*Name.decoded_value,
                                                                    in_pUnknown);
        CheckReplayResult("IDXGIObject_SetPrivateDataInterface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_GetPrivateData(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                Name,
    PointerDecoder<UINT>*                       pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPrivateData(*Name.decoded_value,
                                                           pDataSize->GetPointer(),
                                                           pData->GetPointer());
        CheckReplayResult("IDXGIObject_GetPrivateData", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIObject_GetParent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppParent, out_hp_ppParent);
        }
        CheckReplayResult("IDXGIObject_GetParent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDeviceSubObject_GetDevice(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppDevice, out_hp_ppDevice);
        }
        CheckReplayResult("IDXGIDeviceSubObject_GetDevice", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<uint64_t, void*>*            pSharedHandle)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        pSharedHandle->AllocateOutputData(1);
        auto out_p_pSharedHandle    = pSharedHandle->GetPointer();
        auto out_op_pSharedHandle   = reinterpret_cast<HANDLE*>(pSharedHandle->GetOutputPointer());
        auto replay_result = replay_object->GetSharedHandle(out_op_pSharedHandle);
        CheckReplayResult("IDXGIResource_GetSharedHandle", returnValue, replay_result);
        PostProcessExternalObject(replay_result, out_op_pSharedHandle, out_p_pSharedHandle, format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle, "IDXGIResource_GetSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetUsage(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<DXGI_USAGE>*                 pUsage)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetUsage(pUsage->GetPointer());
        CheckReplayResult("IDXGIResource_GetUsage", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_SetEvictionPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        EvictionPriority)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetEvictionPriority(EvictionPriority);
        CheckReplayResult("IDXGIResource_SetEvictionPriority", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource_GetEvictionPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pEvictionPriority)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetEvictionPriority(pEvictionPriority->GetPointer());
        CheckReplayResult("IDXGIResource_GetEvictionPriority", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIKeyedMutex_AcquireSync(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      Key,
    DWORD                                       dwMilliseconds)
{
    auto replay_object = MapObject<IDXGIKeyedMutex>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->AcquireSync(Key,
                                                        dwMilliseconds);
        CheckReplayResult("IDXGIKeyedMutex_AcquireSync", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      Key)
{
    auto replay_object = MapObject<IDXGIKeyedMutex>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseSync(Key);
        CheckReplayResult("IDXGIKeyedMutex_ReleaseSync", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGISurface_GetDesc", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_Map(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
    UINT                                        MapFlags)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Map(pLockedRect->GetPointer(),
                                                MapFlags);
        CheckReplayResult("IDXGISurface_Map", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface_Unmap(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Unmap();
        CheckReplayResult("IDXGISurface_Unmap", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface1_GetDC(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    BOOL                                        Discard,
    PointerDecoder<uint64_t, void*>*            phdc)
{
    auto replay_object = MapObject<IDXGISurface1>(object_id);
    if (replay_object != nullptr)
    {
        phdc->AllocateOutputData(1);
        auto out_p_phdc    = phdc->GetPointer();
        auto out_op_phdc   = reinterpret_cast<HDC*>(phdc->GetOutputPointer());
        auto replay_result = replay_object->GetDC(Discard,
                                                  out_op_phdc);
        CheckReplayResult("IDXGISurface1_GetDC", returnValue, replay_result);
        PostProcessExternalObject(replay_result, out_op_phdc, out_p_phdc, format::ApiCallId::ApiCall_IDXGISurface1_GetDC, "IDXGISurface1_GetDC");
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface1_ReleaseDC(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pDirtyRect)
{
    auto replay_object = MapObject<IDXGISurface1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseDC(pDirtyRect->GetPointer());
        CheckReplayResult("IDXGISurface1_ReleaseDC", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_EnumOutputs(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppOutput, out_hp_ppOutput);
        }
        CheckReplayResult("IDXGIAdapter_EnumOutputs", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter_GetDesc", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                InterfaceName,
    StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion)
{
    auto replay_object = MapObject<IDXGIAdapter>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckInterfaceSupport(*InterfaceName.decoded_value,
                                                                  pUMDVersion->GetPointer());
        CheckReplayResult("IDXGIAdapter_CheckInterfaceSupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput_GetDesc", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDisplayModeList(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_FORMAT                                 EnumFormat,
    UINT                                        Flags,
    PointerDecoder<UINT>*                       pNumModes,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDisplayModeList(EnumFormat,
                                                               Flags,
                                                               pNumModes->GetPointer(),
                                                               pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput_GetDisplayModeList", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
    format::HandleId                            pConcernedDevice)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = replay_object->FindClosestMatchingMode(pModeToMatch->GetPointer(),
                                                                    pClosestMatch->GetPointer(),
                                                                    in_pConcernedDevice);
        CheckReplayResult("IDXGIOutput_FindClosestMatchingMode", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_WaitForVBlank(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->WaitForVBlank();
        CheckReplayResult("IDXGIOutput_WaitForVBlank", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_TakeOwnership(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pDevice,
    BOOL                                        Exclusive)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDevice = MapObject<IUnknown>(pDevice);
        auto replay_result = replay_object->TakeOwnership(in_pDevice,
                                                          Exclusive);
        CheckReplayResult("IDXGIOutput_TakeOwnership", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_ReleaseOwnership(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ReleaseOwnership();
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGammaControlCapabilities(pGammaCaps->GetPointer());
        CheckReplayResult("IDXGIOutput_GetGammaControlCapabilities", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_SetGammaControl(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetGammaControl(pArray->GetPointer());
        CheckReplayResult("IDXGIOutput_SetGammaControl", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetGammaControl(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGammaControl(pArray->GetPointer());
        CheckReplayResult("IDXGIOutput_GetGammaControl", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_SetDisplaySurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pScanoutSurface)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pScanoutSurface = MapObject<IDXGISurface>(pScanoutSurface);
        auto replay_result = replay_object->SetDisplaySurface(in_pScanoutSurface);
        CheckReplayResult("IDXGIOutput_SetDisplaySurface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pDestination)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDestination = MapObject<IDXGISurface>(pDestination);
        auto replay_result = replay_object->GetDisplaySurfaceData(in_pDestination);
        CheckReplayResult("IDXGIOutput_GetDisplaySurfaceData", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput_GetFrameStatistics(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameStatistics(pStats->GetPointer());
        CheckReplayResult("IDXGIOutput_GetFrameStatistics", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_Present(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        SyncInterval,
    UINT                                        Flags)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Present(SyncInterval,
                                                    Flags);
        CheckReplayResult("IDXGISwapChain_Present", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetBuffer(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Buffer,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppSurface)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(1);
        auto out_p_ppSurface    = ppSurface->GetPointer();
        auto out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = replay_object->GetBuffer(Buffer,
                                                      *riid.decoded_value,
                                                      out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSurface, out_hp_ppSurface);
        }
        CheckReplayResult("IDXGISwapChain_GetBuffer", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_SetFullscreenState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    BOOL                                        Fullscreen,
    format::HandleId                            pTarget)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pTarget = MapObject<IDXGIOutput>(pTarget);
        auto replay_result = replay_object->SetFullscreenState(Fullscreen,
                                                               in_pTarget);
        CheckReplayResult("IDXGISwapChain_SetFullscreenState", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetFullscreenState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<BOOL>*                       pFullscreen,
    HandlePointerDecoder<IDXGIOutput*>*         ppTarget)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppTarget->IsNull()) ppTarget->SetHandleLength(1);
        auto out_p_ppTarget    = ppTarget->GetPointer();
        auto out_hp_ppTarget   = ppTarget->GetHandlePointer();
        auto replay_result = replay_object->GetFullscreenState(pFullscreen->GetPointer(),
                                                               out_hp_ppTarget);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppTarget, out_hp_ppTarget);
        }
        CheckReplayResult("IDXGISwapChain_GetFullscreenState", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGISwapChain_GetDesc", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_ResizeBuffers(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        BufferCount,
    UINT                                        Width,
    UINT                                        Height,
    DXGI_FORMAT                                 NewFormat,
    UINT                                        SwapChainFlags)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ResizeBuffers(BufferCount,
                                                          Width,
                                                          Height,
                                                          NewFormat,
                                                          SwapChainFlags);
        CheckReplayResult("IDXGISwapChain_ResizeBuffers", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_ResizeTarget(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ResizeTarget(pNewTargetParameters->GetPointer());
        CheckReplayResult("IDXGISwapChain_ResizeTarget", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetContainingOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppOutput, out_hp_ppOutput);
        }
        CheckReplayResult("IDXGISwapChain_GetContainingOutput", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetFrameStatistics(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameStatistics(pStats->GetPointer());
        CheckReplayResult("IDXGISwapChain_GetFrameStatistics", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain_GetLastPresentCount(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pLastPresentCount)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetLastPresentCount(pLastPresentCount->GetPointer());
        CheckReplayResult("IDXGISwapChain_GetLastPresentCount", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_EnumAdapters(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppAdapter, out_hp_ppAdapter);
        }
        CheckReplayResult("IDXGIFactory_EnumAdapters", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_MakeWindowAssociation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    WindowHandle,
    UINT                                        Flags)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation, "IDXGIFactory_MakeWindowAssociation"));
        auto replay_result = replay_object->MakeWindowAssociation(in_WindowHandle,
                                                                  Flags);
        CheckReplayResult("IDXGIFactory_MakeWindowAssociation", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_GetWindowAssociation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<uint64_t, void*>*            pWindowHandle)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        pWindowHandle->AllocateOutputData(1);
        auto out_p_pWindowHandle    = pWindowHandle->GetPointer();
        auto out_op_pWindowHandle   = reinterpret_cast<HWND*>(pWindowHandle->GetOutputPointer());
        auto replay_result = replay_object->GetWindowAssociation(out_op_pWindowHandle);
        CheckReplayResult("IDXGIFactory_GetWindowAssociation", returnValue, replay_result);
        PostProcessExternalObject(replay_result, out_op_pWindowHandle, out_p_pWindowHandle, format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation, "IDXGIFactory_GetWindowAssociation");
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_CreateSwapChain(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pDevice,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
    HandlePointerDecoder<IDXGISwapChain*>*      ppSwapChain)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto in_pDevice = GetObjectInfo(pDevice);
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateSwapChain(replay_object,
                                                     returnValue,
                                                     in_pDevice,
                                                     pDesc,
                                                     ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), object_info.extra_info_type, object_info.extra_info);
        }
        CheckReplayResult("IDXGIFactory_CreateSwapChain", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppAdapter, out_hp_ppAdapter);
        }
        CheckReplayResult("IDXGIFactory_CreateSoftwareAdapter", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_GetAdapter(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_pAdapter, out_hp_pAdapter);
        }
        CheckReplayResult("IDXGIDevice_GetAdapter", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_CreateSurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc,
    UINT                                        NumSurfaces,
    DXGI_USAGE                                  Usage,
    StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE>* pSharedResource,
    HandlePointerDecoder<IDXGISurface*>*        ppSurface)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(1);
        auto out_p_ppSurface    = ppSurface->GetPointer();
        auto out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = replay_object->CreateSurface(pDesc->GetPointer(),
                                                          NumSurfaces,
                                                          Usage,
                                                          pSharedResource->GetPointer(),
                                                          out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppSurface, out_hp_ppSurface);
        }
        CheckReplayResult("IDXGIDevice_CreateSurface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_QueryResourceResidency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            ppResources,
    PointerDecoder<DXGI_RESIDENCY>*             pResidencyStatus,
    UINT                                        NumResources)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IUnknown>(ppResources->GetPointer(), NumResources);
        auto replay_result = replay_object->QueryResourceResidency(in_ppResources.data(),
                                                                   pResidencyStatus->GetPointer(),
                                                                   NumResources);
        CheckReplayResult("IDXGIDevice_QueryResourceResidency", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    INT                                         Priority)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetGPUThreadPriority(Priority);
        CheckReplayResult("IDXGIDevice_SetGPUThreadPriority", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<INT>*                        pPriority)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGPUThreadPriority(pPriority->GetPointer());
        CheckReplayResult("IDXGIDevice_GetGPUThreadPriority", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory1_EnumAdapters1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppAdapter, out_hp_ppAdapter);
        }
        CheckReplayResult("IDXGIFactory1_EnumAdapters1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory1_IsCurrent(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIFactory1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsCurrent();
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter1_GetDesc1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter1_GetDesc1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        MaxLatency)
{
    auto replay_object = MapObject<IDXGIDevice1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMaximumFrameLatency(MaxLatency);
        CheckReplayResult("IDXGIDevice1_SetMaximumFrameLatency", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = MapObject<IDXGIDevice1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMaximumFrameLatency(pMaxLatency->GetPointer());
        CheckReplayResult("IDXGIDevice1_GetMaximumFrameLatency", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIDisplayControl>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsStereoEnabled();
    }
}

void Dx12ReplayConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
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
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->GetDesc(pDesc->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_AcquireNextFrame(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        TimeoutInMilliseconds,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
    HandlePointerDecoder<IDXGIResource*>*       ppDesktopResource)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDesktopResource->IsNull()) ppDesktopResource->SetHandleLength(1);
        auto out_p_ppDesktopResource    = ppDesktopResource->GetPointer();
        auto out_hp_ppDesktopResource   = ppDesktopResource->GetHandlePointer();
        auto replay_result = replay_object->AcquireNextFrame(TimeoutInMilliseconds,
                                                             pFrameInfo->GetPointer(),
                                                             out_hp_ppDesktopResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppDesktopResource, out_hp_ppDesktopResource);
        }
        CheckReplayResult("IDXGIOutputDuplication_AcquireNextFrame", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        DirtyRectsBufferSize,
    StructPointerDecoder<Decoded_tagRECT>*      pDirtyRectsBuffer,
    PointerDecoder<UINT>*                       pDirtyRectsBufferSizeRequired)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameDirtyRects(DirtyRectsBufferSize,
                                                               pDirtyRectsBuffer->GetPointer(),
                                                               pDirtyRectsBufferSizeRequired->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFrameDirtyRects", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        MoveRectsBufferSize,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
    PointerDecoder<UINT>*                       pMoveRectsBufferSizeRequired)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameMoveRects(MoveRectsBufferSize,
                                                              pMoveRectBuffer->GetPointer(),
                                                              pMoveRectsBufferSizeRequired->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFrameMoveRects", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        PointerShapeBufferSize,
    PointerDecoder<uint8_t>*                    pPointerShapeBuffer,
    PointerDecoder<UINT>*                       pPointerShapeBufferSizeRequired,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFramePointerShape(PointerShapeBufferSize,
                                                                 pPointerShapeBuffer->GetPointer(),
                                                                 pPointerShapeBufferSizeRequired->GetPointer(),
                                                                 pPointerShapeInfo->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_GetFramePointerShape", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->MapDesktopSurface(pLockedRect->GetPointer());
        CheckReplayResult("IDXGIOutputDuplication_MapDesktopSurface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnMapDesktopSurface();
        CheckReplayResult("IDXGIOutputDuplication_UnMapDesktopSurface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseFrame();
        CheckReplayResult("IDXGIOutputDuplication_ReleaseFrame", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISurface2_GetResource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        auto replay_result = replay_object->GetResource(*riid.decoded_value,
                                                        out_hp_ppParentResource,
                                                        pSubresourceIndex->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppParentResource, out_hp_ppParentResource);
        }
        CheckReplayResult("IDXGISurface2_GetResource", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppSurface, out_hp_ppSurface);
        }
        CheckReplayResult("IDXGIResource1_CreateSubresourceSurface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIResource1_CreateSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
    DWORD                                       dwAccess,
    WStringDecoder*                             lpName,
    PointerDecoder<uint64_t, void*>*            pHandle)
{
    auto replay_object = MapObject<IDXGIResource1>(object_id);
    if (replay_object != nullptr)
    {
        pHandle->AllocateOutputData(1);
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = replay_object->CreateSharedHandle(pAttributes->GetPointer(),
                                                               dwAccess,
                                                               lpName->GetPointer(),
                                                               out_op_pHandle);
        CheckReplayResult("IDXGIResource1_CreateSharedHandle", returnValue, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHandle, out_p_pHandle, format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle, "IDXGIResource1_CreateSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice2_OfferResources(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY                Priority)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources->GetPointer(), NumResources);
        auto replay_result = replay_object->OfferResources(NumResources,
                                                           in_ppResources.data(),
                                                           Priority);
        CheckReplayResult("IDXGIDevice2_OfferResources", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice2_ReclaimResources(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    PointerDecoder<BOOL>*                       pDiscarded)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources->GetPointer(), NumResources);
        auto replay_result = replay_object->ReclaimResources(NumResources,
                                                             in_ppResources.data(),
                                                             pDiscarded->GetPointer());
        CheckReplayResult("IDXGIDevice2_ReclaimResources", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    hEvent)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent, "IDXGIDevice2_EnqueueSetEvent"));
        auto replay_result = replay_object->EnqueueSetEvent(in_hEvent);
        CheckReplayResult("IDXGIDevice2_EnqueueSetEvent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetDesc1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1(pDesc->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetDesc1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFullscreenDesc(pDesc->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetFullscreenDesc", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetHwnd(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<uint64_t, void*>*            pHwnd)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        pHwnd->AllocateOutputData(1);
        auto out_p_pHwnd    = pHwnd->GetPointer();
        auto out_op_pHwnd   = reinterpret_cast<HWND*>(pHwnd->GetOutputPointer());
        auto replay_result = replay_object->GetHwnd(out_op_pHwnd);
        CheckReplayResult("IDXGISwapChain1_GetHwnd", returnValue, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHwnd, out_p_pHwnd, format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd, "IDXGISwapChain1_GetHwnd");
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetCoreWindow(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppUnk, out_hp_ppUnk);
        }
        CheckReplayResult("IDXGISwapChain1_GetCoreWindow", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_Present1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        SyncInterval,
    UINT                                        PresentFlags,
    StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Present1(SyncInterval,
                                                     PresentFlags,
                                                     pPresentParameters->GetPointer());
        CheckReplayResult("IDXGISwapChain1_Present1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsTemporaryMonoSupported();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppRestrictToOutput, out_hp_ppRestrictToOutput);
        }
        CheckReplayResult("IDXGISwapChain1_GetRestrictToOutput", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetBackgroundColor(pColor->GetPointer());
        CheckReplayResult("IDXGISwapChain1_SetBackgroundColor", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBackgroundColor(pColor->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetBackgroundColor", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_SetRotation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_MODE_ROTATION                          Rotation)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetRotation(Rotation);
        CheckReplayResult("IDXGISwapChain1_SetRotation", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain1_GetRotation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<DXGI_MODE_ROTATION>*         pRotation)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRotation(pRotation->GetPointer());
        CheckReplayResult("IDXGISwapChain1_GetRotation", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsWindowedStereoEnabled();
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateSwapChainForHwnd(replay_object,
                                                            returnValue,
                                                            in_pDevice,
                                                            hWnd,
                                                            pDesc,
                                                            pFullscreenDesc,
                                                            in_pRestrictToOutput,
                                                            ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), object_info.extra_info_type, object_info.extra_info);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForHwnd", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateSwapChainForCoreWindow(replay_object,
                                                                  returnValue,
                                                                  in_pDevice,
                                                                  in_pWindow,
                                                                  pDesc,
                                                                  in_pRestrictToOutput,
                                                                  ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), object_info.extra_info_type, object_info.extra_info);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForCoreWindow", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    hResource,
    StructPointerDecoder<Decoded_LUID>*         pLuid)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hResource = static_cast<HANDLE>(PreProcessExternalObject(hResource, format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid, "IDXGIFactory2_GetSharedResourceAdapterLuid"));
        auto replay_result = replay_object->GetSharedResourceAdapterLuid(in_hResource,
                                                                         pLuid->GetPointer());
        CheckReplayResult("IDXGIFactory2_GetSharedResourceAdapterLuid", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    WindowHandle,
    UINT                                        wMsg,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow, "IDXGIFactory2_RegisterStereoStatusWindow"));
        auto replay_result = replay_object->RegisterStereoStatusWindow(in_WindowHandle,
                                                                       wMsg,
                                                                       pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusWindow", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent, "IDXGIFactory2_RegisterStereoStatusEvent"));
        auto replay_result = replay_object->RegisterStereoStatusEvent(in_hEvent,
                                                                      pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusEvent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
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
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    WindowHandle,
    UINT                                        wMsg,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_WindowHandle = static_cast<HWND>(PreProcessExternalObject(WindowHandle, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow, "IDXGIFactory2_RegisterOcclusionStatusWindow"));
        auto replay_result = replay_object->RegisterOcclusionStatusWindow(in_WindowHandle,
                                                                          wMsg,
                                                                          pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusWindow", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent, "IDXGIFactory2_RegisterOcclusionStatusEvent"));
        auto replay_result = replay_object->RegisterOcclusionStatusEvent(in_hEvent,
                                                                         pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusEvent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
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
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppSwapChain->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateSwapChainForComposition(replay_object,
                                                                   returnValue,
                                                                   in_pDevice,
                                                                   pDesc,
                                                                   in_pRestrictToOutput,
                                                                   ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppSwapChain->GetPointer(), ppSwapChain->GetHandlePointer(), object_info.extra_info_type, object_info.extra_info);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForComposition", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter2_GetDesc2(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc2(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter2_GetDesc2", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_FORMAT                                 EnumFormat,
    UINT                                        Flags,
    PointerDecoder<UINT>*                       pNumModes,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDisplayModeList1(EnumFormat,
                                                                Flags,
                                                                pNumModes->GetPointer(),
                                                                pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput1_GetDisplayModeList1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
    format::HandleId                            pConcernedDevice)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = replay_object->FindClosestMatchingMode1(pModeToMatch->GetPointer(),
                                                                     pClosestMatch->GetPointer(),
                                                                     in_pConcernedDevice);
        CheckReplayResult("IDXGIOutput1_FindClosestMatchingMode1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pDestination)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDestination = MapObject<IDXGIResource>(pDestination);
        auto replay_result = replay_object->GetDisplaySurfaceData1(in_pDestination);
        CheckReplayResult("IDXGIOutput1_GetDisplaySurfaceData1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput1_DuplicateOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppOutputDuplication, out_hp_ppOutputDuplication);
        }
        CheckReplayResult("IDXGIOutput1_DuplicateOutput", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice3_Trim(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<IDXGIDevice3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Trim();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetSourceSize(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Width,
    UINT                                        Height)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetSourceSize(Width,
                                                          Height);
        CheckReplayResult("IDXGISwapChain2_SetSourceSize", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetSourceSize(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pWidth,
    PointerDecoder<UINT>*                       pHeight)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSourceSize(pWidth->GetPointer(),
                                                          pHeight->GetPointer());
        CheckReplayResult("IDXGISwapChain2_GetSourceSize", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        MaxLatency)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMaximumFrameLatency(MaxLatency);
        CheckReplayResult("IDXGISwapChain2_SetMaximumFrameLatency", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMaximumFrameLatency(pMaxLatency->GetPointer());
        CheckReplayResult("IDXGISwapChain2_GetMaximumFrameLatency", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    format::HandleId                            object_id,
    uint64_t                                    returnValue)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameLatencyWaitableObject();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMatrixTransform(pMatrix->GetPointer());
        CheckReplayResult("IDXGISwapChain2_SetMatrixTransform", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMatrixTransform(pMatrix->GetPointer());
        CheckReplayResult("IDXGISwapChain2_GetMatrixTransform", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput2_SupportsOverlays(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIOutput2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SupportsOverlays();
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory3_GetCreationFlags(
    format::HandleId                            object_id,
    UINT                                        returnValue)
{
    auto replay_object = MapObject<IDXGIFactory3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCreationFlags();
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        CheckReplayResult("IDXGIDecodeSwapChain_PresentBuffer", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetSourceRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_SetSourceRect", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetTargetRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_SetTargetRect", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Width,
    UINT                                        Height)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetDestSize(Width,
                                                        Height);
        CheckReplayResult("IDXGIDecodeSwapChain_SetDestSize", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSourceRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetSourceRect", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetTargetRect(pRect->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetTargetRect", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pWidth,
    PointerDecoder<UINT>*                       pHeight)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDestSize(pWidth->GetPointer(),
                                                        pHeight->GetPointer());
        CheckReplayResult("IDXGIDecodeSwapChain_GetDestSize", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         ColorSpace)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetColorSpace(ColorSpace);
        CheckReplayResult("IDXGIDecodeSwapChain_SetColorSpace", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
    format::HandleId                            object_id,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         returnValue)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetColorSpace();
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppSwapChain, out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppSwapChain, out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameStatisticsMedia(pStats->GetPointer());
        CheckReplayResult("IDXGISwapChainMedia_GetFrameStatisticsMedia", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Duration)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPresentDuration(Duration);
        CheckReplayResult("IDXGISwapChainMedia_SetPresentDuration", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        DesiredPresentDuration,
    PointerDecoder<UINT>*                       pClosestSmallerPresentDuration,
    PointerDecoder<UINT>*                       pClosestLargerPresentDuration)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckPresentDurationSupport(DesiredPresentDuration,
                                                                        pClosestSmallerPresentDuration->GetPointer(),
                                                                        pClosestLargerPresentDuration->GetPointer());
        CheckReplayResult("IDXGISwapChainMedia_CheckPresentDurationSupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_FORMAT                                 EnumFormat,
    format::HandleId                            pConcernedDevice,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = replay_object->CheckOverlaySupport(EnumFormat,
                                                                in_pConcernedDevice,
                                                                pFlags->GetPointer());
        CheckReplayResult("IDXGIOutput3_CheckOverlaySupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
    format::HandleId                            object_id,
    UINT                                        returnValue)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCurrentBackBufferIndex();
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace,
    PointerDecoder<UINT>*                       pColorSpaceSupport)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckColorSpaceSupport(ColorSpace,
                                                                   pColorSpaceSupport->GetPointer());
        CheckReplayResult("IDXGISwapChain3_CheckColorSpaceSupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_SetColorSpace1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetColorSpace1(ColorSpace);
        CheckReplayResult("IDXGISwapChain3_SetColorSpace1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        BufferCount,
    UINT                                        Width,
    UINT                                        Height,
    DXGI_FORMAT                                 Format,
    UINT                                        SwapChainFlags,
    PointerDecoder<UINT>*                       pCreationNodeMask,
    HandlePointerDecoder<IUnknown*>*            ppPresentQueue)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppPresentQueue = MapObjects<IUnknown>(ppPresentQueue->GetPointer(), BufferCount);
        auto replay_result = replay_object->ResizeBuffers1(BufferCount,
                                                           Width,
                                                           Height,
                                                           Format,
                                                           SwapChainFlags,
                                                           pCreationNodeMask->GetPointer(),
                                                           in_ppPresentQueue.data());
        CheckReplayResult("IDXGISwapChain3_ResizeBuffers1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_FORMAT                                 Format,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace,
    format::HandleId                            pConcernedDevice,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pConcernedDevice = MapObject<IUnknown>(pConcernedDevice);
        auto replay_result = replay_object->CheckOverlayColorSpaceSupport(Format,
                                                                          ColorSpace,
                                                                          in_pConcernedDevice,
                                                                          pFlags->GetPointer());
        CheckReplayResult("IDXGIOutput4_CheckOverlayColorSpaceSupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter);
        }
        CheckReplayResult("IDXGIFactory4_EnumAdapterByLuid", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter);
        }
        CheckReplayResult("IDXGIFactory4_EnumWarpAdapter", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent, "IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent"));
        auto replay_result = replay_object->RegisterHardwareContentProtectionTeardownStatusEvent(in_hEvent,
                                                                                                 pdwCookie->GetPointer());
        CheckReplayResult("IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
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
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP                   MemorySegmentGroup,
    StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->QueryVideoMemoryInfo(NodeIndex,
                                                                 MemorySegmentGroup,
                                                                 pVideoMemoryInfo->GetPointer());
        CheckReplayResult("IDXGIAdapter3_QueryVideoMemoryInfo", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        CheckReplayResult("IDXGIAdapter3_SetVideoMemoryReservation", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent, "IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent"));
        auto replay_result = replay_object->RegisterVideoMemoryBudgetChangeNotificationEvent(in_hEvent,
                                                                                             pdwCookie->GetPointer());
        CheckReplayResult("IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
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
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppOutputDuplication, out_hp_ppOutputDuplication);
        }
        CheckReplayResult("IDXGIOutput5_DuplicateOutput1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        CheckReplayResult("IDXGISwapChain4_SetHDRMetaData", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice4_OfferResources1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY                Priority,
    UINT                                        Flags)
{
    auto replay_object = MapObject<IDXGIDevice4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources->GetPointer(), NumResources);
        auto replay_result = replay_object->OfferResources1(NumResources,
                                                            in_ppResources.data(),
                                                            Priority,
                                                            Flags);
        CheckReplayResult("IDXGIDevice4_OfferResources1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIDevice4_ReclaimResources1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    auto replay_object = MapObject<IDXGIDevice4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppResources = MapObjects<IDXGIResource>(ppResources->GetPointer(), NumResources);
        auto replay_result = replay_object->ReclaimResources1(NumResources,
                                                              in_ppResources.data(),
                                                              pResults->GetPointer());
        CheckReplayResult("IDXGIDevice4_ReclaimResources1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory5_CheckFeatureSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_FEATURE                                Feature,
    PointerDecoder<uint8_t>*                    pFeatureSupportData,
    UINT                                        FeatureSupportDataSize)
{
    auto replay_object = MapObject<IDXGIFactory5>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckFeatureSupport(Feature,
                                                                pFeatureSupportData->GetPointer(),
                                                                FeatureSupportDataSize);
        CheckReplayResult("IDXGIFactory5_CheckFeatureSupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIAdapter4_GetDesc3(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter4>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc3(pDesc->GetPointer());
        CheckReplayResult("IDXGIAdapter4_GetDesc3", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput6_GetDesc1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput6>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1(pDesc->GetPointer());
        CheckReplayResult("IDXGIOutput6_GetDesc1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput6>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckHardwareCompositionSupport(pFlags->GetPointer());
        CheckReplayResult("IDXGIOutput6_CheckHardwareCompositionSupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvAdapter, out_hp_ppvAdapter);
        }
        CheckReplayResult("IDXGIFactory6_EnumAdapterByGpuPreference", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory7>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent, "IDXGIFactory7_RegisterAdaptersChangedEvent"));
        auto replay_result = replay_object->RegisterAdaptersChangedEvent(in_hEvent,
                                                                         pdwCookie->GetPointer());
        CheckReplayResult("IDXGIFactory7_RegisterAdaptersChangedEvent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIFactory7>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnregisterAdaptersChangedEvent(dwCookie);
        CheckReplayResult("IDXGIFactory7_UnregisterAdaptersChangedEvent", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_GetPrivateData(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                guid,
    PointerDecoder<UINT>*                       pDataSize,
    PointerDecoder<uint8_t>*                    pData)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPrivateData(*guid.decoded_value,
                                                           pDataSize->GetPointer(),
                                                           pData->GetPointer());
        CheckReplayResult("ID3D12Object_GetPrivateData", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_SetPrivateData(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        CheckReplayResult("ID3D12Object_SetPrivateData", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_SetPrivateDataInterface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                guid,
    format::HandleId                            pData)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pData = MapObject<IUnknown>(pData);
        auto replay_result = replay_object->SetPrivateDataInterface(*guid.decoded_value,
                                                                    in_pData);
        CheckReplayResult("ID3D12Object_SetPrivateDataInterface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Object_SetName(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             Name)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetName(Name->GetPointer());
        CheckReplayResult("ID3D12Object_SetName", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceChild_GetDevice(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvDevice, out_hp_ppvDevice);
        }
        CheckReplayResult("ID3D12DeviceChild_GetDevice", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* returnValue)
{
    auto replay_object = MapObject<ID3D12RootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRootSignatureDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    D3D_ROOT_SIGNATURE_VERSION                  convertToVersion,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC*>* ppDesc)
{
    auto replay_object = MapObject<ID3D12VersionedRootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRootSignatureDescAtVersion(convertToVersion,
                                                                          const_cast<const D3D12_VERSIONED_ROOT_SIGNATURE_DESC**>(ppDesc->GetPointer()));
        CheckReplayResult("ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* returnValue)
{
    auto replay_object = MapObject<ID3D12VersionedRootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetUnconvertedRootSignatureDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Heap_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_HEAP_DESC                     returnValue)
{
    auto replay_object = MapObject<ID3D12Heap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_Map(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Subresource,
    StructPointerDecoder<Decoded_D3D12_RANGE>*  pReadRange,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        ppData->AllocateOutputData(1);
        auto replay_result = OverrideResourceMap(replay_object,
                                                 returnValue,
                                                 Subresource,
                                                 pReadRange,
                                                 ppData);
        CheckReplayResult("ID3D12Resource_Map", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_Unmap(
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
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC                 returnValue)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
    format::HandleId                            object_id,
    D3D12_GPU_VIRTUAL_ADDRESS                   returnValue)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGPUVirtualAddress();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_WriteToSubresource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        DstSubresource,
    StructPointerDecoder<Decoded_D3D12_BOX>*    pDstBox,
    uint64_t                                    pSrcData,
    UINT                                        SrcRowPitch,
    UINT                                        SrcDepthPitch)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideWriteToSubresource(replay_object,
                                                        returnValue,
                                                        DstSubresource,
                                                        pDstBox,
                                                        pSrcData,
                                                        SrcRowPitch,
                                                        SrcDepthPitch);
        CheckReplayResult("ID3D12Resource_WriteToSubresource", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_ReadFromSubresource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
                                                         returnValue,
                                                         pDstData,
                                                         DstRowPitch,
                                                         DstDepthPitch,
                                                         SrcSubresource,
                                                         pSrcBox);
        CheckReplayResult("ID3D12Resource_ReadFromSubresource", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource_GetHeapProperties(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    PointerDecoder<D3D12_HEAP_FLAGS>*           pHeapFlags)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetHeapProperties(pHeapProperties->GetPointer(),
                                                              pHeapFlags->GetPointer());
        CheckReplayResult("ID3D12Resource_GetHeapProperties", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandAllocator_Reset(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12CommandAllocator>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Reset();
        CheckReplayResult("ID3D12CommandAllocator_Reset", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence_GetCompletedValue(
    format::HandleId                            object_id,
    UINT64                                      returnValue)
{
    auto replay_object = MapObject<ID3D12Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCompletedValue();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence_SetEventOnCompletion(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      Value,
    uint64_t                                    hEvent)
{
    auto replay_object = MapObject<ID3D12Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion, "ID3D12Fence_SetEventOnCompletion"));
        auto replay_result = replay_object->SetEventOnCompletion(Value,
                                                                 in_hEvent);
        CheckReplayResult("ID3D12Fence_SetEventOnCompletion", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence_Signal(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D12Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Signal(Value);
        CheckReplayResult("ID3D12Fence_Signal", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Fence1_GetCreationFlags(
    format::HandleId                            object_id,
    D3D12_FENCE_FLAGS                           returnValue)
{
    auto replay_object = MapObject<ID3D12Fence1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCreationFlags();
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineState_GetCachedBlob(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppBlob, out_hp_ppBlob);
        }
        CheckReplayResult("ID3D12PipelineState_GetCachedBlob", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DescriptorHeap_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_DESCRIPTOR_HEAP_DESC          returnValue)
{
    auto replay_object = MapObject<ID3D12DescriptorHeap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    format::HandleId                            object_id,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         returnValue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetCPUDescriptorHandleForHeapStart(replay_object,
                                                                        returnValue);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    format::HandleId                            object_id,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         returnValue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetGPUDescriptorHandleForHeapStart(replay_object,
                                                                        returnValue);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandList_GetType(
    format::HandleId                            object_id,
    D3D12_COMMAND_LIST_TYPE                     returnValue)
{
    auto replay_object = MapObject<ID3D12CommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetType();
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_Close(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Close();
        CheckReplayResult("ID3D12GraphicsCommandList_Close", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_Reset(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pAllocator,
    format::HandleId                            pInitialState)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pAllocator = MapObject<ID3D12CommandAllocator>(pAllocator);
        auto in_pInitialState = MapObject<ID3D12PipelineState>(pInitialState);
        auto replay_result = replay_object->Reset(in_pAllocator,
                                                  in_pInitialState);
        CheckReplayResult("ID3D12GraphicsCommandList_Reset", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearState(
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
    format::HandleId                            object_id,
    format::HandleId                            pDstBuffer,
    UINT64                                      DstOffset,
    format::HandleId                            pSrcBuffer,
    UINT64                                      SrcOffset,
    UINT64                                      NumBytes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstBuffer = MapObject<ID3D12Resource>(pDstBuffer);
        auto in_pSrcBuffer = MapObject<ID3D12Resource>(pSrcBuffer);
        replay_object->CopyBufferRegion(in_pDstBuffer,
                                        DstOffset,
                                        in_pSrcBuffer,
                                        SrcOffset,
                                        NumBytes);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
    UINT                                        DstX,
    UINT                                        DstY,
    UINT                                        DstZ,
    StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
    StructPointerDecoder<Decoded_D3D12_BOX>*    pSrcBox)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDst->GetMetaStructPointer(), GetObjectInfoTable());
        MapStructObjects(pSrc->GetMetaStructPointer(), GetObjectInfoTable());
        replay_object->CopyTextureRegion(pDst->GetPointer(),
                                         DstX,
                                         DstY,
                                         DstZ,
                                         pSrc->GetPointer(),
                                         pSrcBox->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyResource(
    format::HandleId                            object_id,
    format::HandleId                            pDstResource,
    format::HandleId                            pSrcResource)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pDstResource = MapObject<ID3D12Resource>(pDstResource);
        auto in_pSrcResource = MapObject<ID3D12Resource>(pSrcResource);
        replay_object->CopyResource(in_pDstResource,
                                    in_pSrcResource);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
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
    format::HandleId                            object_id,
    UINT                                        NumBarriers,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pBarriers->GetMetaStructPointer(), pBarriers->GetLength(), GetObjectInfoTable());
        replay_object->ResourceBarrier(NumBarriers,
                                       pBarriers->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
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
    format::HandleId                            object_id,
    UINT                                        NumDescriptorHeaps,
    HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppDescriptorHeaps = MapObjects<ID3D12DescriptorHeap>(ppDescriptorHeaps->GetPointer(), NumDescriptorHeaps);
        replay_object->SetDescriptorHeaps(NumDescriptorHeaps,
                                          in_ppDescriptorHeaps.data());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
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
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         BaseDescriptor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetComputeRootDescriptorTable(RootParameterIndex,
                                                     *BaseDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         BaseDescriptor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGraphicsRootDescriptorTable(RootParameterIndex,
                                                      *BaseDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
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
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetComputeRootConstantBufferView(RootParameterIndex,
                                                        BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGraphicsRootConstantBufferView(RootParameterIndex,
                                                         BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetComputeRootShaderResourceView(RootParameterIndex,
                                                        BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGraphicsRootShaderResourceView(RootParameterIndex,
                                                         BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetComputeRootUnorderedAccessView(RootParameterIndex,
                                                         BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
    format::HandleId                            object_id,
    UINT                                        RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS                   BufferLocation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGraphicsRootUnorderedAccessView(RootParameterIndex,
                                                          BufferLocation);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->IASetIndexBuffer(pView->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->IASetVertexBuffers(StartSlot,
                                          NumViews,
                                          pViews->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
    format::HandleId                            object_id,
    UINT                                        StartSlot,
    UINT                                        NumViews,
    StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SOSetTargets(StartSlot,
                                    NumViews,
                                    pViews->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
    format::HandleId                            object_id,
    UINT                                        NumRenderTargetDescriptors,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
    BOOL                                        RTsSingleHandleToDescriptorRange,
    StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->OMSetRenderTargets(NumRenderTargetDescriptors,
                                          pRenderTargetDescriptors->GetPointer(),
                                          RTsSingleHandleToDescriptorRange,
                                          pDepthStencilDescriptor->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
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
        replay_object->ClearDepthStencilView(*DepthStencilView.decoded_value,
                                             ClearFlags,
                                             Depth,
                                             Stencil,
                                             NumRects,
                                             pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
    format::HandleId                            object_id,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         RenderTargetView,
    PointerDecoder<FLOAT>*                      ColorRGBA,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearRenderTargetView(*RenderTargetView.decoded_value,
                                             ColorRGBA->GetPointer(),
                                             NumRects,
                                             pRects->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
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
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndEvent();
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
    format::HandleId                            object_id,
    format::HandleId                            pCommandSignature,
    UINT                                        MaxCommandCount,
    format::HandleId                            pArgumentBuffer,
    UINT64                                      ArgumentBufferOffset,
    format::HandleId                            pCountBuffer,
    UINT64                                      CountBufferOffset)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCommandSignature = MapObject<ID3D12CommandSignature>(pCommandSignature);
        auto in_pArgumentBuffer = MapObject<ID3D12Resource>(pArgumentBuffer);
        auto in_pCountBuffer = MapObject<ID3D12Resource>(pCountBuffer);
        replay_object->ExecuteIndirect(in_pCommandSignature,
                                       MaxCommandCount,
                                       in_pArgumentBuffer,
                                       ArgumentBufferOffset,
                                       in_pCountBuffer,
                                       CountBufferOffset);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
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
        auto in_ppDependentResources = MapObjects<ID3D12Resource>(ppDependentResources->GetPointer(), Dependencies);
        replay_object->AtomicCopyBufferUINT(in_pDstBuffer,
                                            DstOffset,
                                            in_pSrcBuffer,
                                            SrcOffset,
                                            Dependencies,
                                            in_ppDependentResources.data(),
                                            pDependentSubresourceRanges->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
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
        auto in_ppDependentResources = MapObjects<ID3D12Resource>(ppDependentResources->GetPointer(), Dependencies);
        replay_object->AtomicCopyBufferUINT64(in_pDstBuffer,
                                              DstOffset,
                                              in_pSrcBuffer,
                                              SrcOffset,
                                              Dependencies,
                                              in_ppDependentResources.data(),
                                              pDependentSubresourceRanges->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
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
    format::HandleId                            object_id,
    UINT                                        Count,
    StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
    PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->WriteBufferImmediate(Count,
                                            pParams->GetPointer(),
                                            pModes->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_UpdateTileMappings(
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
    format::HandleId                            object_id,
    UINT                                        NumCommandLists,
    HandlePointerDecoder<ID3D12CommandList*>*   ppCommandLists)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppCommandLists = MapObjects<ID3D12CommandList>(ppCommandLists->GetPointer(), NumCommandLists);
        replay_object->ExecuteCommandLists(NumCommandLists,
                                           in_ppCommandLists.data());
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_SetMarker(
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
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndEvent();
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_Signal(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pFence,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pFence = MapObject<ID3D12Fence>(pFence);
        auto replay_result = replay_object->Signal(in_pFence,
                                                   Value);
        CheckReplayResult("ID3D12CommandQueue_Signal", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_Wait(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pFence,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pFence = MapObject<ID3D12Fence>(pFence);
        auto replay_result = replay_object->Wait(in_pFence,
                                                 Value);
        CheckReplayResult("ID3D12CommandQueue_Wait", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT64>*                     pFrequency)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetTimestampFrequency(pFrequency->GetPointer());
        CheckReplayResult("ID3D12CommandQueue_GetTimestampFrequency", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT64>*                     pGpuTimestamp,
    PointerDecoder<UINT64>*                     pCpuTimestamp)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetClockCalibration(pGpuTimestamp->GetPointer(),
                                                                pCpuTimestamp->GetPointer());
        CheckReplayResult("ID3D12CommandQueue_GetClockCalibration", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12CommandQueue_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_COMMAND_QUEUE_DESC            returnValue)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetNodeCount(
    format::HandleId                            object_id,
    UINT                                        returnValue)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNodeCount();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandQueue(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandQueue)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppCommandQueue->IsNull()) ppCommandQueue->SetHandleLength(1);
        auto out_p_ppCommandQueue    = ppCommandQueue->GetPointer();
        auto out_hp_ppCommandQueue   = ppCommandQueue->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandQueue(pDesc->GetPointer(),
                                                               *riid.decoded_value,
                                                               out_hp_ppCommandQueue);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCommandQueue, out_hp_ppCommandQueue);
        }
        CheckReplayResult("ID3D12Device_CreateCommandQueue", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandAllocator(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppCommandAllocator, out_hp_ppCommandAllocator);
        }
        CheckReplayResult("ID3D12Device_CreateCommandAllocator", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->CreateGraphicsPipelineState(pDesc->GetPointer(),
                                                                        *riid.decoded_value,
                                                                        out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateGraphicsPipelineState", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateComputePipelineState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->CreateComputePipelineState(pDesc->GetPointer(),
                                                                       *riid.decoded_value,
                                                                       out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateComputePipelineState", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandList(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        nodeMask,
    D3D12_COMMAND_LIST_TYPE                     type,
    format::HandleId                            pCommandAllocator,
    format::HandleId                            pInitialState,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandList)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pCommandAllocator = MapObject<ID3D12CommandAllocator>(pCommandAllocator);
        auto in_pInitialState = MapObject<ID3D12PipelineState>(pInitialState);
        if(!ppCommandList->IsNull()) ppCommandList->SetHandleLength(1);
        auto out_p_ppCommandList    = ppCommandList->GetPointer();
        auto out_hp_ppCommandList   = ppCommandList->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandList(nodeMask,
                                                              type,
                                                              in_pCommandAllocator,
                                                              in_pInitialState,
                                                              *riid.decoded_value,
                                                              out_hp_ppCommandList);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCommandList, out_hp_ppCommandList);
        }
        CheckReplayResult("ID3D12Device_CreateCommandList", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CheckFeatureSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    D3D12_FEATURE                               Feature,
    PointerDecoder<uint8_t>*                    pFeatureSupportData,
    UINT                                        FeatureSupportDataSize)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckFeatureSupport(Feature,
                                                                pFeatureSupportData->GetPointer(),
                                                                FeatureSupportDataSize);
        CheckReplayResult("ID3D12Device_CheckFeatureSupport", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateDescriptorHeap(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        DxObjectInfo object_info{};
        ppvHeap->SetConsumerData(0, &object_info);
        auto replay_result = OverrideCreateDescriptorHeap(replay_object,
                                                          returnValue,
                                                          pDescriptorHeapDesc,
                                                          riid,
                                                          ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(ppvHeap->GetPointer(), ppvHeap->GetHandlePointer(), object_info.extra_info_type, object_info.extra_info);
        }
        CheckReplayResult("ID3D12Device_CreateDescriptorHeap", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
    format::HandleId                            object_id,
    UINT                                        returnValue,
    D3D12_DESCRIPTOR_HEAP_TYPE                  DescriptorHeapType)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideGetDescriptorHandleIncrementSize(replay_object,
                                                                      returnValue,
                                                                      DescriptorHeapType);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateRootSignature(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        nodeMask,
    PointerDecoder<uint8_t>*                    pBlobWithRootSignature,
    SIZE_T                                      blobLengthInBytes,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvRootSignature)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvRootSignature->IsNull()) ppvRootSignature->SetHandleLength(1);
        auto out_p_ppvRootSignature    = ppvRootSignature->GetPointer();
        auto out_hp_ppvRootSignature   = ppvRootSignature->GetHandlePointer();
        auto replay_result = replay_object->CreateRootSignature(nodeMask,
                                                                pBlobWithRootSignature->GetPointer(),
                                                                blobLengthInBytes,
                                                                *riid.decoded_value,
                                                                out_hp_ppvRootSignature);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvRootSignature, out_hp_ppvRootSignature);
        }
        CheckReplayResult("ID3D12Device_CreateRootSignature", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateConstantBufferView(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CreateConstantBufferView(pDesc->GetPointer(),
                                                *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateShaderResourceView(
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->CreateShaderResourceView(in_pResource,
                                                pDesc->GetPointer(),
                                                *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateUnorderedAccessView(
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
        replay_object->CreateUnorderedAccessView(in_pResource,
                                                 in_pCounterResource,
                                                 pDesc->GetPointer(),
                                                 *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateRenderTargetView(
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->CreateRenderTargetView(in_pResource,
                                              pDesc->GetPointer(),
                                              *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateDepthStencilView(
    format::HandleId                            object_id,
    format::HandleId                            pResource,
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pResource = MapObject<ID3D12Resource>(pResource);
        replay_object->CreateDepthStencilView(in_pResource,
                                              pDesc->GetPointer(),
                                              *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateSampler(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CreateSampler(pDesc->GetPointer(),
                                     *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CopyDescriptors(
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
    format::HandleId                            object_id,
    UINT                                        NumDescriptors,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptorRangeStart,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE                  DescriptorHeapsType)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CopyDescriptorsSimple(NumDescriptors,
                                             *DestDescriptorRangeStart.decoded_value,
                                             *SrcDescriptorRangeStart.decoded_value,
                                             DescriptorHeapsType);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO      returnValue,
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
    format::HandleId                            object_id,
    Decoded_D3D12_HEAP_PROPERTIES               returnValue,
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
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateCommittedResource(pHeapProperties->GetPointer(),
                                                                    HeapFlags,
                                                                    pDesc->GetPointer(),
                                                                    InitialResourceState,
                                                                    pOptimizedClearValue->GetPointer(),
                                                                    *riidResource.decoded_value,
                                                                    out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device_CreateCommittedResource", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateHeap(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto out_p_ppvHeap    = ppvHeap->GetPointer();
        auto out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->CreateHeap(pDesc->GetPointer(),
                                                       *riid.decoded_value,
                                                       out_hp_ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvHeap, out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device_CreateHeap", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreatePlacedResource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvResource, out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device_CreatePlacedResource", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateReservedResource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateReservedResource(pDesc->GetPointer(),
                                                                   InitialState,
                                                                   pOptimizedClearValue->GetPointer(),
                                                                   *riid.decoded_value,
                                                                   out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device_CreateReservedResource", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
        pHandle->AllocateOutputData(1);
        auto out_p_pHandle    = pHandle->GetPointer();
        auto out_op_pHandle   = reinterpret_cast<HANDLE*>(pHandle->GetOutputPointer());
        auto replay_result = replay_object->CreateSharedHandle(in_pObject,
                                                               pAttributes->GetPointer(),
                                                               Access,
                                                               Name->GetPointer(),
                                                               out_op_pHandle);
        CheckReplayResult("ID3D12Device_CreateSharedHandle", returnValue, replay_result);
        PostProcessExternalObject(replay_result, out_op_pHandle, out_p_pHandle, format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle, "ID3D12Device_CreateSharedHandle");
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_OpenSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvObj, out_hp_ppvObj);
        }
        CheckReplayResult("ID3D12Device_OpenSharedHandle", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_OpenSharedHandleByName(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             Name,
    DWORD                                       Access,
    PointerDecoder<uint64_t, void*>*            pNTHandle)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        pNTHandle->AllocateOutputData(1);
        auto out_p_pNTHandle    = pNTHandle->GetPointer();
        auto out_op_pNTHandle   = reinterpret_cast<HANDLE*>(pNTHandle->GetOutputPointer());
        auto replay_result = replay_object->OpenSharedHandleByName(Name->GetPointer(),
                                                                   Access,
                                                                   out_op_pNTHandle);
        CheckReplayResult("ID3D12Device_OpenSharedHandleByName", returnValue, replay_result);
        PostProcessExternalObject(replay_result, out_op_pNTHandle, out_p_pNTHandle, format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName, "ID3D12Device_OpenSharedHandleByName");
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_MakeResident(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects->GetPointer(), NumObjects);
        auto replay_result = replay_object->MakeResident(NumObjects,
                                                         in_ppObjects.data());
        CheckReplayResult("ID3D12Device_MakeResident", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_Evict(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects->GetPointer(), NumObjects);
        auto replay_result = replay_object->Evict(NumObjects,
                                                  in_ppObjects.data());
        CheckReplayResult("ID3D12Device_Evict", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateFence(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      InitialValue,
    D3D12_FENCE_FLAGS                           Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFence)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppFence->IsNull()) ppFence->SetHandleLength(1);
        auto out_p_ppFence    = ppFence->GetPointer();
        auto out_hp_ppFence   = ppFence->GetHandlePointer();
        auto replay_result = replay_object->CreateFence(InitialValue,
                                                        Flags,
                                                        *riid.decoded_value,
                                                        out_hp_ppFence);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppFence, out_hp_ppFence);
        }
        CheckReplayResult("ID3D12Device_CreateFence", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDeviceRemovedReason();
        CheckReplayResult("ID3D12Device_GetDeviceRemovedReason", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetCopyableFootprints(
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
        replay_object->GetCopyableFootprints(pResourceDesc->GetPointer(),
                                             FirstSubresource,
                                             NumSubresources,
                                             BaseOffset,
                                             pLayouts->GetPointer(),
                                             pNumRows->GetPointer(),
                                             pRowSizeInBytes->GetPointer(),
                                             pTotalBytes->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateQueryHeap(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvHeap, out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device_CreateQueryHeap", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_SetStablePowerState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetStablePowerState(Enable);
        CheckReplayResult("ID3D12Device_SetStablePowerState", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_CreateCommandSignature(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
    format::HandleId                            pRootSignature,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvCommandSignature)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pRootSignature = MapObject<ID3D12RootSignature>(pRootSignature);
        if(!ppvCommandSignature->IsNull()) ppvCommandSignature->SetHandleLength(1);
        auto out_p_ppvCommandSignature    = ppvCommandSignature->GetPointer();
        auto out_hp_ppvCommandSignature   = ppvCommandSignature->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandSignature(pDesc->GetPointer(),
                                                                   in_pRootSignature,
                                                                   *riid.decoded_value,
                                                                   out_hp_ppvCommandSignature);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvCommandSignature, out_hp_ppvCommandSignature);
        }
        CheckReplayResult("ID3D12Device_CreateCommandSignature", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetResourceTiling(
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
        replay_object->GetResourceTiling(in_pTiledResource,
                                         pNumTilesForEntireResource->GetPointer(),
                                         pPackedMipDesc->GetPointer(),
                                         pStandardTileShapeForNonPackedMips->GetPointer(),
                                         pNumSubresourceTilings->GetPointer(),
                                         FirstSubresourceTilingToGet,
                                         pSubresourceTilingsForNonPackedMips->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device_GetAdapterLuid(
    format::HandleId                            object_id,
    Decoded_LUID                                returnValue)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetAdapterLuid();
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             pName,
    format::HandleId                            pPipeline)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pPipeline = MapObject<ID3D12PipelineState>(pPipeline);
        auto replay_result = replay_object->StorePipeline(pName->GetPointer(),
                                                          in_pPipeline);
        CheckReplayResult("ID3D12PipelineLibrary_StorePipeline", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             pName,
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->LoadGraphicsPipeline(pName->GetPointer(),
                                                                 pDesc->GetPointer(),
                                                                 *riid.decoded_value,
                                                                 out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadGraphicsPipeline", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             pName,
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        MapStructObjects(pDesc->GetMetaStructPointer(), GetObjectInfoTable());
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->LoadComputePipeline(pName->GetPointer(),
                                                                pDesc->GetPointer(),
                                                                *riid.decoded_value,
                                                                out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadComputePipeline", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
    format::HandleId                            object_id,
    SIZE_T                                      returnValue)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSerializedSize();
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary_Serialize(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<uint8_t>*                    pData,
    SIZE_T                                      DataSizeInBytes)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Serialize(pData->GetPointer(),
                                                      DataSizeInBytes);
        CheckReplayResult("ID3D12PipelineLibrary_Serialize", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             pName,
    StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->LoadPipeline(pName->GetPointer(),
                                                         pDesc->GetPointer(),
                                                         *riid.decoded_value,
                                                         out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12PipelineLibrary1_LoadPipeline", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device1_CreatePipelineLibrary(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<uint8_t>*                    pLibraryBlob,
    SIZE_T                                      BlobLength,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineLibrary)
{
    auto replay_object = MapObject<ID3D12Device1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPipelineLibrary->IsNull()) ppPipelineLibrary->SetHandleLength(1);
        auto out_p_ppPipelineLibrary    = ppPipelineLibrary->GetPointer();
        auto out_hp_ppPipelineLibrary   = ppPipelineLibrary->GetHandlePointer();
        auto replay_result = replay_object->CreatePipelineLibrary(pLibraryBlob->GetPointer(),
                                                                  BlobLength,
                                                                  *riid.decoded_value,
                                                                  out_hp_ppPipelineLibrary);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineLibrary, out_hp_ppPipelineLibrary);
        }
        CheckReplayResult("ID3D12Device1_CreatePipelineLibrary", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12Fence*>*         ppFences,
    PointerDecoder<UINT64>*                     pFenceValues,
    UINT                                        NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS             Flags,
    uint64_t                                    hEvent)
{
    auto replay_object = MapObject<ID3D12Device1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppFences = MapObjects<ID3D12Fence>(ppFences->GetPointer(), NumFences);
        auto in_hEvent = static_cast<HANDLE>(PreProcessExternalObject(hEvent, format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion, "ID3D12Device1_SetEventOnMultipleFenceCompletion"));
        auto replay_result = replay_object->SetEventOnMultipleFenceCompletion(in_ppFences.data(),
                                                                              pFenceValues->GetPointer(),
                                                                              NumFences,
                                                                              Flags,
                                                                              in_hEvent);
        CheckReplayResult("ID3D12Device1_SetEventOnMultipleFenceCompletion", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device1_SetResidencyPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects,
    PointerDecoder<D3D12_RESIDENCY_PRIORITY>*   pPriorities)
{
    auto replay_object = MapObject<ID3D12Device1>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects->GetPointer(), NumObjects);
        auto replay_result = replay_object->SetResidencyPriority(NumObjects,
                                                                 in_ppObjects.data(),
                                                                 pPriorities->GetPointer());
        CheckReplayResult("ID3D12Device1_SetResidencyPriority", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device2_CreatePipelineState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12Device2>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->CreatePipelineState(pDesc->GetPointer(),
                                                                *riid.decoded_value,
                                                                out_hp_ppPipelineState);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppPipelineState, out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12Device2_CreatePipelineState", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    pAddress,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pAddress = PreProcessExternalObject(pAddress, format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress, "ID3D12Device3_OpenExistingHeapFromAddress");
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto out_p_ppvHeap    = ppvHeap->GetPointer();
        auto out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->OpenExistingHeapFromAddress(in_pAddress,
                                                                        *riid.decoded_value,
                                                                        out_hp_ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvHeap, out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromAddress", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvHeap, out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromFileMapping", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device3_EnqueueMakeResident(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    D3D12_RESIDENCY_FLAGS                       Flags,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects,
    format::HandleId                            pFenceToSignal,
    UINT64                                      FenceValueToSignal)
{
    auto replay_object = MapObject<ID3D12Device3>(object_id);
    if (replay_object != nullptr)
    {
        auto in_ppObjects = MapObjects<ID3D12Pageable>(ppObjects->GetPointer(), NumObjects);
        auto in_pFenceToSignal = MapObject<ID3D12Fence>(pFenceToSignal);
        auto replay_result = replay_object->EnqueueMakeResident(Flags,
                                                                NumObjects,
                                                                in_ppObjects.data(),
                                                                in_pFenceToSignal,
                                                                FenceValueToSignal);
        CheckReplayResult("ID3D12Device3_EnqueueMakeResident", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppFence, out_hp_ppFence);
        }
        CheckReplayResult("ID3D12ProtectedSession_GetStatusFence", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
    format::HandleId                            object_id,
    D3D12_PROTECTED_SESSION_STATUS              returnValue)
{
    auto replay_object = MapObject<ID3D12ProtectedSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSessionStatus();
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC returnValue)
{
    auto replay_object = MapObject<ID3D12ProtectedResourceSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateCommandList1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        nodeMask,
    D3D12_COMMAND_LIST_TYPE                     type,
    D3D12_COMMAND_LIST_FLAGS                    flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandList)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppCommandList->IsNull()) ppCommandList->SetHandleLength(1);
        auto out_p_ppCommandList    = ppCommandList->GetPointer();
        auto out_hp_ppCommandList   = ppCommandList->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandList1(nodeMask,
                                                               type,
                                                               flags,
                                                               *riid.decoded_value,
                                                               out_hp_ppCommandList);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppCommandList, out_hp_ppCommandList);
        }
        CheckReplayResult("ID3D12Device4_CreateCommandList1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppSession, out_hp_ppSession);
        }
        CheckReplayResult("ID3D12Device4_CreateProtectedResourceSession", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateCommittedResource1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateCommittedResource1(pHeapProperties->GetPointer(),
                                                                     HeapFlags,
                                                                     pDesc->GetPointer(),
                                                                     InitialResourceState,
                                                                     pOptimizedClearValue->GetPointer(),
                                                                     in_pProtectedSession,
                                                                     *riidResource.decoded_value,
                                                                     out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device4_CreateCommittedResource1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateHeap1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto out_p_ppvHeap    = ppvHeap->GetPointer();
        auto out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->CreateHeap1(pDesc->GetPointer(),
                                                        in_pProtectedSession,
                                                        *riid.decoded_value,
                                                        out_hp_ppvHeap);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvHeap, out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device4_CreateHeap1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_CreateReservedResource1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateReservedResource1(pDesc->GetPointer(),
                                                                    InitialState,
                                                                    pOptimizedClearValue->GetPointer(),
                                                                    in_pProtectedSession,
                                                                    *riid.decoded_value,
                                                                    out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device4_CreateReservedResource1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO      returnValue,
    UINT                                        visibleMask,
    UINT                                        numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetResourceAllocationInfo1(visibleMask,
                                                                       numResourceDescs,
                                                                       pResourceDescs->GetPointer(),
                                                                       pResourceAllocationInfo1->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
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
    format::HandleId                            object_id,
    Decoded_LUID                                returnValue)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetLUID();
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppv, out_hp_ppv);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetSwapChainObject", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvResource, out_hp_ppvResource);
            AddObject(out_p_ppvQueue, out_hp_ppvQueue);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->InsertImplicitSync();
        CheckReplayResult("ID3D12SwapChainAssistant_InsertImplicitSync", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            pObject)
{
    auto replay_object = MapObject<ID3D12LifetimeTracker>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pObject = MapObject<ID3D12DeviceChild>(pObject);
        auto replay_result = replay_object->DestroyOwnedObject(in_pObject);
        CheckReplayResult("ID3D12LifetimeTracker_DestroyOwnedObject", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
    format::HandleId                            object_id,
    uint64_t                                    returnValue,
    WStringDecoder*                             pExportName)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetShaderIdentifier(pExportName->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
    format::HandleId                            object_id,
    UINT64                                      returnValue,
    WStringDecoder*                             pExportName)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetShaderStackSize(pExportName->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
    format::HandleId                            object_id,
    UINT64                                      returnValue)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPipelineStackSize();
    }
}

void Dx12ReplayConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
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
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvTracker, out_hp_ppvTracker);
        }
        CheckReplayResult("ID3D12Device5_CreateLifetimeTracker", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_RemoveDevice(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RemoveDevice();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pNumMetaCommands,
    StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->EnumerateMetaCommands(pNumMetaCommands->GetPointer(),
                                                                  pDescs->GetPointer());
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommands", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE          Stage,
    PointerDecoder<UINT>*                       pTotalStructureSizeInBytes,
    PointerDecoder<UINT>*                       pParameterCount,
    StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC>* pParameterDescs)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->EnumerateMetaCommandParameters(*CommandId.decoded_value,
                                                                           Stage,
                                                                           pTotalStructureSizeInBytes->GetPointer(),
                                                                           pParameterCount->GetPointer(),
                                                                           pParameterDescs->GetPointer());
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommandParameters", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_CreateMetaCommand(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppMetaCommand, out_hp_ppMetaCommand);
        }
        CheckReplayResult("ID3D12Device5_CreateMetaCommand", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_CreateStateObject(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppStateObject)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppStateObject->IsNull()) ppStateObject->SetHandleLength(1);
        auto out_p_ppStateObject    = ppStateObject->GetPointer();
        auto out_hp_ppStateObject   = ppStateObject->GetHandlePointer();
        auto replay_result = replay_object->CreateStateObject(pDesc->GetPointer(),
                                                              *riid.decoded_value,
                                                              out_hp_ppStateObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppStateObject, out_hp_ppStateObject);
        }
        CheckReplayResult("ID3D12Device5_CreateStateObject", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->GetRaytracingAccelerationStructurePrebuildInfo(pDesc->GetPointer(),
                                                                      pInfo->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device5_CheckDriverMatchingIdentifier(
    format::HandleId                            object_id,
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS     returnValue,
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
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetAutoBreadcrumbsEnablement(Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetPageFaultEnablement(Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
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
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetBreadcrumbContextEnablement(Enablement);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetAutoBreadcrumbsOutput(pOutput->GetPointer());
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPageFaultAllocationOutput(pOutput->GetPointer());
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetAutoBreadcrumbsOutput1(pOutput->GetPointer());
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPageFaultAllocationOutput1(pOutput->GetPointer());
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    D3D12_BACKGROUND_PROCESSING_MODE            Mode,
    D3D12_MEASUREMENTS_ACTION                   MeasurementsAction,
    uint64_t                                    hEventToSignalUponCompletion,
    PointerDecoder<BOOL>*                       pbFurtherMeasurementsDesired)
{
    auto replay_object = MapObject<ID3D12Device6>(object_id);
    if (replay_object != nullptr)
    {
        auto in_hEventToSignalUponCompletion = static_cast<HANDLE>(PreProcessExternalObject(hEventToSignalUponCompletion, format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode, "ID3D12Device6_SetBackgroundProcessingMode"));
        auto replay_result = replay_object->SetBackgroundProcessingMode(Mode,
                                                                        MeasurementsAction,
                                                                        in_hEventToSignalUponCompletion,
                                                                        pbFurtherMeasurementsDesired->GetPointer());
        CheckReplayResult("ID3D12Device6_SetBackgroundProcessingMode", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 returnValue)
{
    auto replay_object = MapObject<ID3D12ProtectedResourceSession1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device7_AddToStateObject(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
    format::HandleId                            pStateObjectToGrowFrom,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppNewStateObject)
{
    auto replay_object = MapObject<ID3D12Device7>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pStateObjectToGrowFrom = MapObject<ID3D12StateObject>(pStateObjectToGrowFrom);
        if(!ppNewStateObject->IsNull()) ppNewStateObject->SetHandleLength(1);
        auto out_p_ppNewStateObject    = ppNewStateObject->GetPointer();
        auto out_hp_ppNewStateObject   = ppNewStateObject->GetHandlePointer();
        auto replay_result = replay_object->AddToStateObject(pAddition->GetPointer(),
                                                             in_pStateObjectToGrowFrom,
                                                             *riid.decoded_value,
                                                             out_hp_ppNewStateObject);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppNewStateObject, out_hp_ppNewStateObject);
        }
        CheckReplayResult("ID3D12Device7_AddToStateObject", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppSession, out_hp_ppSession);
        }
        CheckReplayResult("ID3D12Device7_CreateProtectedResourceSession1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_ALLOCATION_INFO      returnValue,
    UINT                                        visibleMask,
    UINT                                        numResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetResourceAllocationInfo2(visibleMask,
                                                                       numResourceDescs,
                                                                       pResourceDescs->GetPointer(),
                                                                       pResourceAllocationInfo1->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_CreateCommittedResource2(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    format::HandleId                            pProtectedSession,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pProtectedSession = MapObject<ID3D12ProtectedResourceSession>(pProtectedSession);
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto out_p_ppvResource    = ppvResource->GetPointer();
        auto out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateCommittedResource2(pHeapProperties->GetPointer(),
                                                                     HeapFlags,
                                                                     pDesc->GetPointer(),
                                                                     InitialResourceState,
                                                                     pOptimizedClearValue->GetPointer(),
                                                                     in_pProtectedSession,
                                                                     *riidResource.decoded_value,
                                                                     out_hp_ppvResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(out_p_ppvResource, out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device8_CreateCommittedResource2", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_CreatePlacedResource1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvResource, out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device8_CreatePlacedResource1", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
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
        replay_object->CreateSamplerFeedbackUnorderedAccessView(in_pTargetedResource,
                                                                in_pFeedbackResource,
                                                                *DestDescriptor.decoded_value);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
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
        replay_object->GetCopyableFootprints1(pResourceDesc->GetPointer(),
                                              FirstSubresource,
                                              NumSubresources,
                                              BaseOffset,
                                              pLayouts->GetPointer(),
                                              pNumRows->GetPointer(),
                                              pRowSizeInBytes->GetPointer(),
                                              pTotalBytes->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppProtectedSession, out_hp_ppProtectedSession);
        }
        CheckReplayResult("ID3D12Resource1_GetProtectedResourceSession", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12Resource2_GetDesc1(
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC1                returnValue)
{
    auto replay_object = MapObject<ID3D12Resource2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1();
    }
}

void Dx12ReplayConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppProtectedSession, out_hp_ppProtectedSession);
        }
        CheckReplayResult("ID3D12Heap1_GetProtectedResourceSession", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
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
    format::HandleId                            object_id,
    UINT64                                      returnValue,
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
    format::HandleId                            object_id,
    UINT                                        NumRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS                     Flags)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        MapStructArrayObjects(pRenderTargets->GetMetaStructPointer(), pRenderTargets->GetLength(), GetObjectInfoTable());
        MapStructObjects(pDepthStencil->GetMetaStructPointer(), GetObjectInfoTable());
        replay_object->BeginRenderPass(NumRenderTargets,
                                       pRenderTargets->GetPointer(),
                                       pDepthStencil->GetPointer(),
                                       Flags);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndRenderPass();
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
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
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
    UINT                                        NumPostbuildInfoDescs,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BuildRaytracingAccelerationStructure(pDesc->GetPointer(),
                                                            NumPostbuildInfoDescs,
                                                            pPostbuildInfoDescs->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
    UINT                                        NumSourceAccelerationStructures,
    PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>*  pSourceAccelerationStructureData)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EmitRaytracingAccelerationStructurePostbuildInfo(pDesc->GetPointer(),
                                                                        NumSourceAccelerationStructures,
                                                                        pSourceAccelerationStructureData->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    format::HandleId                            object_id,
    D3D12_GPU_VIRTUAL_ADDRESS                   DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS                   SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CopyRaytracingAccelerationStructure(DestAccelerationStructureData,
                                                           SourceAccelerationStructureData,
                                                           Mode);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
    format::HandleId                            object_id,
    format::HandleId                            pStateObject)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pStateObject = MapObject<ID3D12StateObject>(pStateObject);
        replay_object->SetPipelineState1(in_pStateObject);
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DispatchRays(pDesc->GetPointer());
    }
}

void Dx12ReplayConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
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
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<ID3D12Tools>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ShaderInstrumentationEnabled();
    }
}

void Dx12ReplayConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
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

void Dx12ReplayConsumer::Process_ID3D10Blob_GetBufferPointer(
    format::HandleId                            object_id,
    uint64_t                                    returnValue)
{
    auto replay_object = MapObject<ID3D10Blob>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBufferPointer();
    }
}

void Dx12ReplayConsumer::Process_ID3D10Blob_GetBufferSize(
    format::HandleId                            object_id,
    SIZE_T                                      returnValue)
{
    auto replay_object = MapObject<ID3D10Blob>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBufferSize();
    }
}

void Dx12ReplayConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    callbackFn,
    uint64_t                                    pData,
    PointerDecoder<UINT>*                       pCallbackID)
{
    auto replay_object = MapObject<ID3DDestructionNotifier>(object_id);
    if (replay_object != nullptr)
    {
        auto in_pData = PreProcessExternalObject(pData, format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback, "ID3DDestructionNotifier_RegisterDestructionCallback");
        auto replay_result = replay_object->RegisterDestructionCallback(reinterpret_cast<PFN_DESTRUCTION_CALLBACK>(callbackFn),
                                                                        in_pData,
                                                                        pCallbackID->GetPointer());
        CheckReplayResult("ID3DDestructionNotifier_RegisterDestructionCallback", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        callbackID)
{
    auto replay_object = MapObject<ID3DDestructionNotifier>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnregisterDestructionCallback(callbackID);
        CheckReplayResult("ID3DDestructionNotifier_UnregisterDestructionCallback", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IUnknown_QueryInterface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
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
            AddObject(out_p_ppvObject, out_hp_ppvObject);
        }
        CheckReplayResult("IUnknown_QueryInterface", returnValue, replay_result);
    }
}

void Dx12ReplayConsumer::Process_IUnknown_AddRef(
    format::HandleId                            object_id,
    ULONG                                       returnValue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideAddRef(replay_object,
                                            returnValue);
    }
}

void Dx12ReplayConsumer::Process_IUnknown_Release(
    format::HandleId                            object_id,
    ULONG                                       returnValue)
{
    auto replay_object = GetObjectInfo(object_id);
    if ((replay_object != nullptr) && (replay_object->object != nullptr))
    {
        auto replay_result = OverrideRelease(replay_object,
                                             returnValue);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
