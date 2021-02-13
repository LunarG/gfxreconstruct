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

#include "generated_dx12_replay_consumer.h"
GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void DX12ReplayConsumer::Process_CreateDXGIFactory(
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    if(!ppFactory->IsNull()) ppFactory->SetHandleLength(1);
    auto _out_p_ppFactory    = ppFactory->GetPointer();
    auto _out_hp_ppFactory   = ppFactory->GetHandlePointer();
    auto replay_result = CreateDXGIFactory(*riid.decoded_value,
                                           reinterpret_cast<void**>(_out_hp_ppFactory));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppFactory, _out_hp_ppFactory);
    }
    CheckReplayResult("CreateDXGIFactory", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_CreateDXGIFactory1(
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    if(!ppFactory->IsNull()) ppFactory->SetHandleLength(1);
    auto _out_p_ppFactory    = ppFactory->GetPointer();
    auto _out_hp_ppFactory   = ppFactory->GetHandlePointer();
    auto replay_result = CreateDXGIFactory1(*riid.decoded_value,
                                            reinterpret_cast<void**>(_out_hp_ppFactory));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppFactory, _out_hp_ppFactory);
    }
    CheckReplayResult("CreateDXGIFactory1", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_CreateDXGIFactory2(
    HRESULT                                     returnValue,
    UINT                                        Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFactory)
{
    if(!ppFactory->IsNull()) ppFactory->SetHandleLength(1);
    auto _out_p_ppFactory    = ppFactory->GetPointer();
    auto _out_hp_ppFactory   = ppFactory->GetHandlePointer();
    auto replay_result = CreateDXGIFactory2(Flags,
                                            *riid.decoded_value,
                                            reinterpret_cast<void**>(_out_hp_ppFactory));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppFactory, _out_hp_ppFactory);
    }
    CheckReplayResult("CreateDXGIFactory2", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_DXGIGetDebugInterface1(
    HRESULT                                     returnValue,
    UINT                                        Flags,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                pDebug)
{
    if(!pDebug->IsNull()) pDebug->SetHandleLength(1);
    auto _out_p_pDebug    = pDebug->GetPointer();
    auto _out_hp_pDebug   = pDebug->GetHandlePointer();
    auto replay_result = DXGIGetDebugInterface1(Flags,
                                                *riid.decoded_value,
                                                reinterpret_cast<void**>(_out_hp_pDebug));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_pDebug, _out_hp_pDebug);
    }
    CheckReplayResult("DXGIGetDebugInterface1", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_DXGIDeclareAdapterRemovalSupport(
    HRESULT                                     returnValue)
{
    auto replay_result = DXGIDeclareAdapterRemovalSupport();
}

void DX12ReplayConsumer::Process_D3D12SerializeRootSignature(
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION                  Version,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob,
    HandlePointerDecoder<ID3D10Blob*>*          ppErrorBlob)
{
    if(!ppBlob->IsNull()) ppBlob->SetHandleLength(1);
    auto _out_p_ppBlob    = ppBlob->GetPointer();
    auto _out_hp_ppBlob   = ppBlob->GetHandlePointer();
    if(!ppErrorBlob->IsNull()) ppErrorBlob->SetHandleLength(1);
    auto _out_p_ppErrorBlob    = ppErrorBlob->GetPointer();
    auto _out_hp_ppErrorBlob   = ppErrorBlob->GetHandlePointer();
    auto replay_result = D3D12SerializeRootSignature(pRootSignature->GetPointer(),
                                                     Version,
                                                     _out_hp_ppBlob,
                                                     _out_hp_ppErrorBlob);
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppBlob, _out_hp_ppBlob);
        AddObject(_out_p_ppErrorBlob, _out_hp_ppErrorBlob);
    }
    CheckReplayResult("D3D12SerializeRootSignature", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_D3D12CreateRootSignatureDeserializer(
    HRESULT                                     returnValue,
    PointerDecoder<uint8_t>*                    pSrcData,
    SIZE_T                                      SrcDataSizeInBytes,
    Decoded_GUID                                pRootSignatureDeserializerInterface,
    HandlePointerDecoder<void*>*                ppRootSignatureDeserializer)
{
    if(!ppRootSignatureDeserializer->IsNull()) ppRootSignatureDeserializer->SetHandleLength(1);
    auto _out_p_ppRootSignatureDeserializer    = ppRootSignatureDeserializer->GetPointer();
    auto _out_hp_ppRootSignatureDeserializer   = ppRootSignatureDeserializer->GetHandlePointer();
    auto replay_result = D3D12CreateRootSignatureDeserializer(reinterpret_cast<void*>(pSrcData),
                                                              SrcDataSizeInBytes,
                                                              *pRootSignatureDeserializerInterface.decoded_value,
                                                              reinterpret_cast<void**>(_out_hp_ppRootSignatureDeserializer));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppRootSignatureDeserializer, _out_hp_ppRootSignatureDeserializer);
    }
    CheckReplayResult("D3D12CreateRootSignatureDeserializer", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_D3D12SerializeVersionedRootSignature(
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob,
    HandlePointerDecoder<ID3D10Blob*>*          ppErrorBlob)
{
    if(!ppBlob->IsNull()) ppBlob->SetHandleLength(1);
    auto _out_p_ppBlob    = ppBlob->GetPointer();
    auto _out_hp_ppBlob   = ppBlob->GetHandlePointer();
    if(!ppErrorBlob->IsNull()) ppErrorBlob->SetHandleLength(1);
    auto _out_p_ppErrorBlob    = ppErrorBlob->GetPointer();
    auto _out_hp_ppErrorBlob   = ppErrorBlob->GetHandlePointer();
    auto replay_result = D3D12SerializeVersionedRootSignature(pRootSignature->GetPointer(),
                                                              _out_hp_ppBlob,
                                                              _out_hp_ppErrorBlob);
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppBlob, _out_hp_ppBlob);
        AddObject(_out_p_ppErrorBlob, _out_hp_ppErrorBlob);
    }
    CheckReplayResult("D3D12SerializeVersionedRootSignature", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_D3D12CreateVersionedRootSignatureDeserializer(
    HRESULT                                     returnValue,
    PointerDecoder<uint8_t>*                    pSrcData,
    SIZE_T                                      SrcDataSizeInBytes,
    Decoded_GUID                                pRootSignatureDeserializerInterface,
    HandlePointerDecoder<void*>*                ppRootSignatureDeserializer)
{
    if(!ppRootSignatureDeserializer->IsNull()) ppRootSignatureDeserializer->SetHandleLength(1);
    auto _out_p_ppRootSignatureDeserializer    = ppRootSignatureDeserializer->GetPointer();
    auto _out_hp_ppRootSignatureDeserializer   = ppRootSignatureDeserializer->GetHandlePointer();
    auto replay_result = D3D12CreateVersionedRootSignatureDeserializer(reinterpret_cast<void*>(pSrcData),
                                                                       SrcDataSizeInBytes,
                                                                       *pRootSignatureDeserializerInterface.decoded_value,
                                                                       reinterpret_cast<void**>(_out_hp_ppRootSignatureDeserializer));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppRootSignatureDeserializer, _out_hp_ppRootSignatureDeserializer);
    }
    CheckReplayResult("D3D12CreateVersionedRootSignatureDeserializer", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_D3D12CreateDevice(
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pAdapter,
    D3D_FEATURE_LEVEL                           MinimumFeatureLevel,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppDevice)
{
    if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
    auto _out_p_ppDevice    = ppDevice->GetPointer();
    auto _out_hp_ppDevice   = ppDevice->GetHandlePointer();
    auto replay_result = D3D12CreateDevice(MapObject<IUnknown>(*pAdapter->GetPointer()),
                                           MinimumFeatureLevel,
                                           *riid.decoded_value,
                                           reinterpret_cast<void**>(_out_hp_ppDevice));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppDevice, _out_hp_ppDevice);
    }
    CheckReplayResult("D3D12CreateDevice", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_D3D12GetDebugInterface(
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDebug)
{
    if(!ppvDebug->IsNull()) ppvDebug->SetHandleLength(1);
    auto _out_p_ppvDebug    = ppvDebug->GetPointer();
    auto _out_hp_ppvDebug   = ppvDebug->GetHandlePointer();
    auto replay_result = D3D12GetDebugInterface(*riid.decoded_value,
                                                reinterpret_cast<void**>(_out_hp_ppvDebug));
    if (SUCCEEDED(replay_result))
    {
        AddObject(_out_p_ppvDebug, _out_hp_ppvDebug);
    }
    CheckReplayResult("D3D12GetDebugInterface", returnValue, replay_result);
}

void DX12ReplayConsumer::Process_D3D12EnableExperimentalFeatures(
    HRESULT                                     returnValue,
    UINT                                        NumFeatures,
    StructPointerDecoder<Decoded_GUID>*         pIIDs,
    PointerDecoder<uint8_t>*                    pConfigurationStructs,
    PointerDecoder<UINT>*                       pConfigurationStructSizes)
{
    auto replay_result = D3D12EnableExperimentalFeatures(NumFeatures,
                                                         pIIDs->GetPointer(),
                                                         reinterpret_cast<void*>(pConfigurationStructs),
                                                         pConfigurationStructSizes->GetPointer());
    if (SUCCEEDED(replay_result))
    {
    }
    CheckReplayResult("D3D12EnableExperimentalFeatures", returnValue, replay_result);
}
void DX12ReplayConsumer::Process_IDXGIObject_SetPrivateData(
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
                                                           reinterpret_cast<void*>(pData));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIObject_SetPrivateData", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIObject_SetPrivateDataInterface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                Name,
    HandlePointerDecoder<IUnknown*>*            pUnknown)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPrivateDataInterface(*Name.decoded_value,
                                                                    MapObject<IUnknown>(*pUnknown->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIObject_SetPrivateDataInterface", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIObject_GetPrivateData(
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
                                                           reinterpret_cast<void*>(pData));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIObject_GetPrivateData", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIObject_GetParent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppParent)
{
    auto replay_object = MapObject<IDXGIObject>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppParent->IsNull()) ppParent->SetHandleLength(1);
        auto _out_p_ppParent    = ppParent->GetPointer();
        auto _out_hp_ppParent   = ppParent->GetHandlePointer();
        auto replay_result = replay_object->GetParent(*riid.decoded_value,
                                                      reinterpret_cast<void**>(_out_hp_ppParent));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppParent, _out_hp_ppParent);
        }
        CheckReplayResult("IDXGIObject_GetParent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDeviceSubObject_GetDevice(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppDevice)
{
    auto replay_object = MapObject<IDXGIDeviceSubObject>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppDevice->IsNull()) ppDevice->SetHandleLength(1);
        auto _out_p_ppDevice    = ppDevice->GetPointer();
        auto _out_hp_ppDevice   = ppDevice->GetHandlePointer();
        auto replay_result = replay_object->GetDevice(*riid.decoded_value,
                                                      reinterpret_cast<void**>(_out_hp_ppDevice));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppDevice, _out_hp_ppDevice);
        }
        CheckReplayResult("IDXGIDeviceSubObject_GetDevice", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIResource_GetSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<HANDLE>*               pSharedHandle)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        if(!pSharedHandle->IsNull()) pSharedHandle->SetHandleLength(1);
        auto _out_p_pSharedHandle    = pSharedHandle->GetPointer();
        auto _out_hp_pSharedHandle   = pSharedHandle->GetHandlePointer();
        auto replay_result = replay_object->GetSharedHandle(_out_hp_pSharedHandle);
        if (SUCCEEDED(replay_result))
        {
            AddHandle(_out_p_pSharedHandle, _out_hp_pSharedHandle);
        }
        CheckReplayResult("IDXGIResource_GetSharedHandle", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIResource_GetUsage(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<DXGI_USAGE>*                 pUsage)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetUsage(pUsage->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIResource_GetUsage", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIResource_SetEvictionPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        EvictionPriority)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetEvictionPriority(EvictionPriority);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIResource_SetEvictionPriority", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIResource_GetEvictionPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pEvictionPriority)
{
    auto replay_object = MapObject<IDXGIResource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetEvictionPriority(pEvictionPriority->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIResource_GetEvictionPriority", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIKeyedMutex_AcquireSync(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIKeyedMutex_AcquireSync", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIKeyedMutex_ReleaseSync(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      Key)
{
    auto replay_object = MapObject<IDXGIKeyedMutex>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseSync(Key);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIKeyedMutex_ReleaseSync", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISurface_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISurface_GetDesc", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISurface_Map(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISurface_Map", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISurface_Unmap(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGISurface>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Unmap();
    }
}

void DX12ReplayConsumer::Process_IDXGISurface1_GetDC(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    BOOL                                        Discard,
    HandlePointerDecoder<HDC>*                  phdc)
{
    auto replay_object = MapObject<IDXGISurface1>(object_id);
    if (replay_object != nullptr)
    {
        if(!phdc->IsNull()) phdc->SetHandleLength(1);
        auto _out_p_phdc    = phdc->GetPointer();
        auto _out_hp_phdc   = phdc->GetHandlePointer();
        auto replay_result = replay_object->GetDC(Discard,
                                                  _out_hp_phdc);
        if (SUCCEEDED(replay_result))
        {
            AddHandle(_out_p_phdc, _out_hp_phdc);
        }
        CheckReplayResult("IDXGISurface1_GetDC", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISurface1_ReleaseDC(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pDirtyRect)
{
    auto replay_object = MapObject<IDXGISurface1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseDC(pDirtyRect->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISurface1_ReleaseDC", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter_EnumOutputs(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Output,
    HandlePointerDecoder<IDXGIOutput*>*         ppOutput)
{
    auto replay_object = MapObject<IDXGIAdapter>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppOutput->IsNull()) ppOutput->SetHandleLength(1);
        auto _out_p_ppOutput    = ppOutput->GetPointer();
        auto _out_hp_ppOutput   = ppOutput->GetHandlePointer();
        auto replay_result = replay_object->EnumOutputs(Output,
                                                        _out_hp_ppOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppOutput, _out_hp_ppOutput);
        }
        CheckReplayResult("IDXGIAdapter_EnumOutputs", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter_GetDesc", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter_CheckInterfaceSupport(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter_CheckInterfaceSupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_GetDesc", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_GetDisplayModeList(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_GetDisplayModeList", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_FindClosestMatchingMode(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
    HandlePointerDecoder<IUnknown*>*            pConcernedDevice)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->FindClosestMatchingMode(pModeToMatch->GetPointer(),
                                                                    pClosestMatch->GetPointer(),
                                                                    MapObject<IUnknown>(*pConcernedDevice->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_FindClosestMatchingMode", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_WaitForVBlank(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->WaitForVBlank();
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_TakeOwnership(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    BOOL                                        Exclusive)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->TakeOwnership(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                          Exclusive);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_TakeOwnership", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_ReleaseOwnership(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ReleaseOwnership();
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_GetGammaControlCapabilities(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGammaControlCapabilities(pGammaCaps->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_GetGammaControlCapabilities", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_SetGammaControl(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetGammaControl(pArray->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_SetGammaControl", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_GetGammaControl(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGammaControl(pArray->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_GetGammaControl", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_SetDisplaySurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IDXGISurface*>*        pScanoutSurface)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetDisplaySurface(MapObject<IDXGISurface>(*pScanoutSurface->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_SetDisplaySurface", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_GetDisplaySurfaceData(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IDXGISurface*>*        pDestination)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDisplaySurfaceData(MapObject<IDXGISurface>(*pDestination->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_GetDisplaySurfaceData", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput_GetFrameStatistics(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = MapObject<IDXGIOutput>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameStatistics(pStats->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput_GetFrameStatistics", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_Present(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain_Present", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_GetBuffer(
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
        auto _out_p_ppSurface    = ppSurface->GetPointer();
        auto _out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = replay_object->GetBuffer(Buffer,
                                                      *riid.decoded_value,
                                                      reinterpret_cast<void**>(_out_hp_ppSurface));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSurface, _out_hp_ppSurface);
        }
        CheckReplayResult("IDXGISwapChain_GetBuffer", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_SetFullscreenState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    BOOL                                        Fullscreen,
    HandlePointerDecoder<IDXGIOutput*>*         pTarget)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetFullscreenState(Fullscreen,
                                                               MapObject<IDXGIOutput>(*pTarget->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain_SetFullscreenState", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_GetFullscreenState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<BOOL>*                       pFullscreen,
    HandlePointerDecoder<IDXGIOutput*>*         ppTarget)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppTarget->IsNull()) ppTarget->SetHandleLength(1);
        auto _out_p_ppTarget    = ppTarget->GetPointer();
        auto _out_hp_ppTarget   = ppTarget->GetHandlePointer();
        auto replay_result = replay_object->GetFullscreenState(pFullscreen->GetPointer(),
                                                               _out_hp_ppTarget);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppTarget, _out_hp_ppTarget);
        }
        CheckReplayResult("IDXGISwapChain_GetFullscreenState", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_GetDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain_GetDesc", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_ResizeBuffers(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain_ResizeBuffers", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_ResizeTarget(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ResizeTarget(pNewTargetParameters->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain_ResizeTarget", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_GetContainingOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IDXGIOutput*>*         ppOutput)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppOutput->IsNull()) ppOutput->SetHandleLength(1);
        auto _out_p_ppOutput    = ppOutput->GetPointer();
        auto _out_hp_ppOutput   = ppOutput->GetHandlePointer();
        auto replay_result = replay_object->GetContainingOutput(_out_hp_ppOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppOutput, _out_hp_ppOutput);
        }
        CheckReplayResult("IDXGISwapChain_GetContainingOutput", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_GetFrameStatistics(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameStatistics(pStats->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain_GetFrameStatistics", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain_GetLastPresentCount(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pLastPresentCount)
{
    auto replay_object = MapObject<IDXGISwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetLastPresentCount(pLastPresentCount->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain_GetLastPresentCount", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory_EnumAdapters(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Adapter,
    HandlePointerDecoder<IDXGIAdapter*>*        ppAdapter)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto _out_p_ppAdapter    = ppAdapter->GetPointer();
        auto _out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapters(Adapter,
                                                         _out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppAdapter, _out_hp_ppAdapter);
        }
        CheckReplayResult("IDXGIFactory_EnumAdapters", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory_MakeWindowAssociation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            WindowHandle,
    UINT                                        Flags)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->MakeWindowAssociation(MapHandle<HWND>(WindowHandle),
                                                                  Flags);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory_MakeWindowAssociation", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory_GetWindowAssociation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<HWND>*                 pWindowHandle)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        if(!pWindowHandle->IsNull()) pWindowHandle->SetHandleLength(1);
        auto _out_p_pWindowHandle    = pWindowHandle->GetPointer();
        auto _out_hp_pWindowHandle   = pWindowHandle->GetHandlePointer();
        auto replay_result = replay_object->GetWindowAssociation(_out_hp_pWindowHandle);
        if (SUCCEEDED(replay_result))
        {
            AddHandle(_out_p_pWindowHandle, _out_hp_pWindowHandle);
        }
        CheckReplayResult("IDXGIFactory_GetWindowAssociation", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory_CreateSwapChain(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
    HandlePointerDecoder<IDXGISwapChain*>*      ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto _out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto _out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateSwapChain(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                            pDesc->GetPointer(),
                                                            _out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSwapChain, _out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactory_CreateSwapChain", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory_CreateSoftwareAdapter(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            Module,
    HandlePointerDecoder<IDXGIAdapter*>*        ppAdapter)
{
    auto replay_object = MapObject<IDXGIFactory>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto _out_p_ppAdapter    = ppAdapter->GetPointer();
        auto _out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = replay_object->CreateSoftwareAdapter(MapHandle<HMODULE>(Module),
                                                                  _out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppAdapter, _out_hp_ppAdapter);
        }
        CheckReplayResult("IDXGIFactory_CreateSoftwareAdapter", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice_GetAdapter(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IDXGIAdapter*>*        pAdapter)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        if(!pAdapter->IsNull()) pAdapter->SetHandleLength(1);
        auto _out_p_pAdapter    = pAdapter->GetPointer();
        auto _out_hp_pAdapter   = pAdapter->GetHandlePointer();
        auto replay_result = replay_object->GetAdapter(_out_hp_pAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_pAdapter, _out_hp_pAdapter);
        }
        CheckReplayResult("IDXGIDevice_GetAdapter", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice_CreateSurface(
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
        auto _out_p_ppSurface    = ppSurface->GetPointer();
        auto _out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = replay_object->CreateSurface(pDesc->GetPointer(),
                                                          NumSurfaces,
                                                          Usage,
                                                          pSharedResource->GetPointer(),
                                                          _out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSurface, _out_hp_ppSurface);
        }
        CheckReplayResult("IDXGIDevice_CreateSurface", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice_QueryResourceResidency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            ppResources,
    PointerDecoder<DXGI_RESIDENCY>*             pResidencyStatus,
    UINT                                        NumResources)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->QueryResourceResidency(MapObject<IUnknown*>(*ppResources->GetPointer()),
                                                                   pResidencyStatus->GetPointer(),
                                                                   NumResources);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice_QueryResourceResidency", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice_SetGPUThreadPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    INT                                         Priority)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetGPUThreadPriority(Priority);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice_SetGPUThreadPriority", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice_GetGPUThreadPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<INT>*                        pPriority)
{
    auto replay_object = MapObject<IDXGIDevice>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGPUThreadPriority(pPriority->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice_GetGPUThreadPriority", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory1_EnumAdapters1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Adapter,
    HandlePointerDecoder<IDXGIAdapter1*>*       ppAdapter)
{
    auto replay_object = MapObject<IDXGIFactory1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppAdapter->IsNull()) ppAdapter->SetHandleLength(1);
        auto _out_p_ppAdapter    = ppAdapter->GetPointer();
        auto _out_hp_ppAdapter   = ppAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapters1(Adapter,
                                                          _out_hp_ppAdapter);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppAdapter, _out_hp_ppAdapter);
        }
        CheckReplayResult("IDXGIFactory1_EnumAdapters1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory1_IsCurrent(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIFactory1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsCurrent();
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter1_GetDesc1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter1_GetDesc1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice1_SetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        MaxLatency)
{
    auto replay_object = MapObject<IDXGIDevice1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMaximumFrameLatency(MaxLatency);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice1_SetMaximumFrameLatency", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice1_GetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = MapObject<IDXGIDevice1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMaximumFrameLatency(pMaxLatency->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice1_GetMaximumFrameLatency", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDisplayControl_IsStereoEnabled(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIDisplayControl>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsStereoEnabled();
    }
}

void DX12ReplayConsumer::Process_IDXGIDisplayControl_SetStereoEnabled(
    format::HandleId                            object_id,
    BOOL                                        enabled)
{
    auto replay_object = MapObject<IDXGIDisplayControl>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetStereoEnabled(enabled);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_GetDesc(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->GetDesc(pDesc->GetPointer());
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_AcquireNextFrame(
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
        auto _out_p_ppDesktopResource    = ppDesktopResource->GetPointer();
        auto _out_hp_ppDesktopResource   = ppDesktopResource->GetHandlePointer();
        auto replay_result = replay_object->AcquireNextFrame(TimeoutInMilliseconds,
                                                             pFrameInfo->GetPointer(),
                                                             _out_hp_ppDesktopResource);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppDesktopResource, _out_hp_ppDesktopResource);
        }
        CheckReplayResult("IDXGIOutputDuplication_AcquireNextFrame", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_GetFrameDirtyRects(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutputDuplication_GetFrameDirtyRects", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_GetFrameMoveRects(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutputDuplication_GetFrameMoveRects", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_GetFramePointerShape(
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
                                                                 reinterpret_cast<void*>(pPointerShapeBuffer),
                                                                 pPointerShapeBufferSizeRequired->GetPointer(),
                                                                 pPointerShapeInfo->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutputDuplication_GetFramePointerShape", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_MapDesktopSurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->MapDesktopSurface(pLockedRect->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutputDuplication_MapDesktopSurface", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_UnMapDesktopSurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnMapDesktopSurface();
    }
}

void DX12ReplayConsumer::Process_IDXGIOutputDuplication_ReleaseFrame(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<IDXGIOutputDuplication>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReleaseFrame();
    }
}

void DX12ReplayConsumer::Process_IDXGISurface2_GetResource(
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
        auto _out_p_ppParentResource    = ppParentResource->GetPointer();
        auto _out_hp_ppParentResource   = ppParentResource->GetHandlePointer();
        auto replay_result = replay_object->GetResource(*riid.decoded_value,
                                                        reinterpret_cast<void**>(_out_hp_ppParentResource),
                                                        pSubresourceIndex->GetPointer());
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppParentResource, _out_hp_ppParentResource);
        }
        CheckReplayResult("IDXGISurface2_GetResource", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIResource1_CreateSubresourceSurface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        index,
    HandlePointerDecoder<IDXGISurface2*>*       ppSurface)
{
    auto replay_object = MapObject<IDXGIResource1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSurface->IsNull()) ppSurface->SetHandleLength(1);
        auto _out_p_ppSurface    = ppSurface->GetPointer();
        auto _out_hp_ppSurface   = ppSurface->GetHandlePointer();
        auto replay_result = replay_object->CreateSubresourceSurface(index,
                                                                     _out_hp_ppSurface);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSurface, _out_hp_ppSurface);
        }
        CheckReplayResult("IDXGIResource1_CreateSubresourceSurface", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIResource1_CreateSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
    DWORD                                       dwAccess,
    WStringDecoder*                             lpName,
    HandlePointerDecoder<HANDLE>*               pHandle)
{
    auto replay_object = MapObject<IDXGIResource1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHandle->IsNull()) pHandle->SetHandleLength(1);
        auto _out_p_pHandle    = pHandle->GetPointer();
        auto _out_hp_pHandle   = pHandle->GetHandlePointer();
        auto replay_result = replay_object->CreateSharedHandle(pAttributes->GetPointer(),
                                                               dwAccess,
                                                               lpName->GetPointer(),
                                                               _out_hp_pHandle);
        if (SUCCEEDED(replay_result))
        {
            AddHandle(_out_p_pHandle, _out_hp_pHandle);
        }
        CheckReplayResult("IDXGIResource1_CreateSharedHandle", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice2_OfferResources(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY                Priority)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->OfferResources(NumResources,
                                                           MapObject<IDXGIResource*>(*ppResources->GetPointer()),
                                                           Priority);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice2_OfferResources", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice2_ReclaimResources(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    PointerDecoder<BOOL>*                       pDiscarded)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReclaimResources(NumResources,
                                                             MapObject<IDXGIResource*>(*ppResources->GetPointer()),
                                                             pDiscarded->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice2_ReclaimResources", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice2_EnqueueSetEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hEvent)
{
    auto replay_object = MapObject<IDXGIDevice2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->EnqueueSetEvent(MapHandle<HANDLE>(hEvent));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice2_EnqueueSetEvent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_GetDesc1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain1_GetDesc1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_GetFullscreenDesc(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFullscreenDesc(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain1_GetFullscreenDesc", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_GetHwnd(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<HWND>*                 pHwnd)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHwnd->IsNull()) pHwnd->SetHandleLength(1);
        auto _out_p_pHwnd    = pHwnd->GetPointer();
        auto _out_hp_pHwnd   = pHwnd->GetHandlePointer();
        auto replay_result = replay_object->GetHwnd(_out_hp_pHwnd);
        if (SUCCEEDED(replay_result))
        {
            AddHandle(_out_p_pHwnd, _out_hp_pHwnd);
        }
        CheckReplayResult("IDXGISwapChain1_GetHwnd", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_GetCoreWindow(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                refiid,
    HandlePointerDecoder<void*>*                ppUnk)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppUnk->IsNull()) ppUnk->SetHandleLength(1);
        auto _out_p_ppUnk    = ppUnk->GetPointer();
        auto _out_hp_ppUnk   = ppUnk->GetHandlePointer();
        auto replay_result = replay_object->GetCoreWindow(*refiid.decoded_value,
                                                          reinterpret_cast<void**>(_out_hp_ppUnk));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppUnk, _out_hp_ppUnk);
        }
        CheckReplayResult("IDXGISwapChain1_GetCoreWindow", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_Present1(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain1_Present1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_IsTemporaryMonoSupported(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsTemporaryMonoSupported();
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_GetRestrictToOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IDXGIOutput*>*         ppRestrictToOutput)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppRestrictToOutput->IsNull()) ppRestrictToOutput->SetHandleLength(1);
        auto _out_p_ppRestrictToOutput    = ppRestrictToOutput->GetPointer();
        auto _out_hp_ppRestrictToOutput   = ppRestrictToOutput->GetHandlePointer();
        auto replay_result = replay_object->GetRestrictToOutput(_out_hp_ppRestrictToOutput);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppRestrictToOutput, _out_hp_ppRestrictToOutput);
        }
        CheckReplayResult("IDXGISwapChain1_GetRestrictToOutput", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_SetBackgroundColor(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetBackgroundColor(pColor->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain1_SetBackgroundColor", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_GetBackgroundColor(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBackgroundColor(pColor->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain1_GetBackgroundColor", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_SetRotation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_MODE_ROTATION                          Rotation)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetRotation(Rotation);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain1_SetRotation", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain1_GetRotation(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<DXGI_MODE_ROTATION>*         pRotation)
{
    auto replay_object = MapObject<IDXGISwapChain1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRotation(pRotation->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain1_GetRotation", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_IsWindowedStereoEnabled(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->IsWindowedStereoEnabled();
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForHwnd(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    format::HandleId                            hWnd,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
    HandlePointerDecoder<IDXGIOutput*>*         pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto _out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto _out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateSwapChainForHwnd(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                                   MapHandle<HWND>(hWnd),
                                                                   pDesc->GetPointer(),
                                                                   pFullscreenDesc->GetPointer(),
                                                                   MapObject<IDXGIOutput>(*pRestrictToOutput->GetPointer()),
                                                                   _out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSwapChain, _out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForHwnd", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    HandlePointerDecoder<IUnknown*>*            pWindow,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    HandlePointerDecoder<IDXGIOutput*>*         pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto _out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto _out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateSwapChainForCoreWindow(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                                         MapObject<IUnknown>(*pWindow->GetPointer()),
                                                                         pDesc->GetPointer(),
                                                                         MapObject<IDXGIOutput>(*pRestrictToOutput->GetPointer()),
                                                                         _out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSwapChain, _out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForCoreWindow", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hResource,
    StructPointerDecoder<Decoded_LUID>*         pLuid)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSharedResourceAdapterLuid(MapHandle<HANDLE>(hResource),
                                                                         pLuid->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory2_GetSharedResourceAdapterLuid", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_RegisterStereoStatusWindow(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            WindowHandle,
    UINT                                        wMsg,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterStereoStatusWindow(MapHandle<HWND>(WindowHandle),
                                                                       wMsg,
                                                                       pdwCookie->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusWindow", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_RegisterStereoStatusEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterStereoStatusEvent(MapHandle<HANDLE>(hEvent),
                                                                      pdwCookie->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory2_RegisterStereoStatusEvent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_UnregisterStereoStatus(
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterStereoStatus(dwCookie);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            WindowHandle,
    UINT                                        wMsg,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterOcclusionStatusWindow(MapHandle<HWND>(WindowHandle),
                                                                          wMsg,
                                                                          pdwCookie->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusWindow", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterOcclusionStatusEvent(MapHandle<HANDLE>(hEvent),
                                                                         pdwCookie->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory2_RegisterOcclusionStatusEvent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_UnregisterOcclusionStatus(
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterOcclusionStatus(dwCookie);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory2_CreateSwapChainForComposition(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    HandlePointerDecoder<IDXGIOutput*>*         pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactory2>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto _out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto _out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateSwapChainForComposition(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                                          pDesc->GetPointer(),
                                                                          MapObject<IDXGIOutput>(*pRestrictToOutput->GetPointer()),
                                                                          _out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSwapChain, _out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactory2_CreateSwapChainForComposition", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter2_GetDesc2(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc2(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter2_GetDesc2", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput1_GetDisplayModeList1(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput1_GetDisplayModeList1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput1_FindClosestMatchingMode1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
    StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
    HandlePointerDecoder<IUnknown*>*            pConcernedDevice)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->FindClosestMatchingMode1(pModeToMatch->GetPointer(),
                                                                     pClosestMatch->GetPointer(),
                                                                     MapObject<IUnknown>(*pConcernedDevice->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput1_FindClosestMatchingMode1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput1_GetDisplaySurfaceData1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IDXGIResource*>*       pDestination)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDisplaySurfaceData1(MapObject<IDXGIResource>(*pDestination->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput1_GetDisplaySurfaceData1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput1_DuplicateOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    auto replay_object = MapObject<IDXGIOutput1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppOutputDuplication->IsNull()) ppOutputDuplication->SetHandleLength(1);
        auto _out_p_ppOutputDuplication    = ppOutputDuplication->GetPointer();
        auto _out_hp_ppOutputDuplication   = ppOutputDuplication->GetHandlePointer();
        auto replay_result = replay_object->DuplicateOutput(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                            _out_hp_ppOutputDuplication);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppOutputDuplication, _out_hp_ppOutputDuplication);
        }
        CheckReplayResult("IDXGIOutput1_DuplicateOutput", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice3_Trim(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<IDXGIDevice3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Trim();
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain2_SetSourceSize(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain2_SetSourceSize", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain2_GetSourceSize(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain2_GetSourceSize", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain2_SetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        MaxLatency)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMaximumFrameLatency(MaxLatency);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain2_SetMaximumFrameLatency", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain2_GetMaximumFrameLatency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pMaxLatency)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMaximumFrameLatency(pMaxLatency->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain2_GetMaximumFrameLatency", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    format::HandleId                            object_id,
    format::HandleId                            returnValue)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameLatencyWaitableObject();
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain2_SetMatrixTransform(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetMatrixTransform(pMatrix->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain2_SetMatrixTransform", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain2_GetMatrixTransform(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix)
{
    auto replay_object = MapObject<IDXGISwapChain2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetMatrixTransform(pMatrix->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain2_GetMatrixTransform", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput2_SupportsOverlays(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<IDXGIOutput2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SupportsOverlays();
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory3_GetCreationFlags(
    format::HandleId                            object_id,
    UINT                                        returnValue)
{
    auto replay_object = MapObject<IDXGIFactory3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCreationFlags();
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_PresentBuffer(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_PresentBuffer", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetSourceRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetSourceRect(pRect->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_SetSourceRect", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetTargetRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetTargetRect(pRect->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_SetTargetRect", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetDestSize(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_SetDestSize", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetSourceRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSourceRect(pRect->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_GetSourceRect", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetTargetRect(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_tagRECT>*      pRect)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetTargetRect(pRect->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_GetTargetRect", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetDestSize(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_GetDestSize", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_SetColorSpace(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         ColorSpace)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetColorSpace(ColorSpace);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDecodeSwapChain_SetColorSpace", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDecodeSwapChain_GetColorSpace(
    format::HandleId                            object_id,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS         returnValue)
{
    auto replay_object = MapObject<IDXGIDecodeSwapChain>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetColorSpace();
    }
}

void DX12ReplayConsumer::Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    format::HandleId                            hSurface,
    StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
    HandlePointerDecoder<IDXGIOutput*>*         pRestrictToOutput,
    HandlePointerDecoder<IDXGISwapChain1*>*     ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactoryMedia>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto _out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto _out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateSwapChainForCompositionSurfaceHandle(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                                                       MapHandle<HANDLE>(hSurface),
                                                                                       pDesc->GetPointer(),
                                                                                       MapObject<IDXGIOutput>(*pRestrictToOutput->GetPointer()),
                                                                                       _out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSwapChain, _out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    format::HandleId                            hSurface,
    StructPointerDecoder<Decoded_DXGI_DECODE_SWAP_CHAIN_DESC>* pDesc,
    HandlePointerDecoder<IDXGIResource*>*       pYuvDecodeBuffers,
    HandlePointerDecoder<IDXGIOutput*>*         pRestrictToOutput,
    HandlePointerDecoder<IDXGIDecodeSwapChain*>* ppSwapChain)
{
    auto replay_object = MapObject<IDXGIFactoryMedia>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppSwapChain->IsNull()) ppSwapChain->SetHandleLength(1);
        auto _out_p_ppSwapChain    = ppSwapChain->GetPointer();
        auto _out_hp_ppSwapChain   = ppSwapChain->GetHandlePointer();
        auto replay_result = replay_object->CreateDecodeSwapChainForCompositionSurfaceHandle(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                                                             MapHandle<HANDLE>(hSurface),
                                                                                             pDesc->GetPointer(),
                                                                                             MapObject<IDXGIResource>(*pYuvDecodeBuffers->GetPointer()),
                                                                                             MapObject<IDXGIOutput>(*pRestrictToOutput->GetPointer()),
                                                                                             _out_hp_ppSwapChain);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSwapChain, _out_hp_ppSwapChain);
        }
        CheckReplayResult("IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetFrameStatisticsMedia(pStats->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChainMedia_GetFrameStatisticsMedia", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChainMedia_SetPresentDuration(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Duration)
{
    auto replay_object = MapObject<IDXGISwapChainMedia>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPresentDuration(Duration);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChainMedia_SetPresentDuration", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChainMedia_CheckPresentDurationSupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput3_CheckOverlaySupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_FORMAT                                 EnumFormat,
    HandlePointerDecoder<IUnknown*>*            pConcernedDevice,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckOverlaySupport(EnumFormat,
                                                                MapObject<IUnknown>(*pConcernedDevice->GetPointer()),
                                                                pFlags->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput3_CheckOverlaySupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
    format::HandleId                            object_id,
    UINT                                        returnValue)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCurrentBackBufferIndex();
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain3_CheckColorSpaceSupport(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain3_CheckColorSpaceSupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain3_SetColorSpace1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace)
{
    auto replay_object = MapObject<IDXGISwapChain3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetColorSpace1(ColorSpace);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain3_SetColorSpace1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain3_ResizeBuffers1(
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
        auto replay_result = replay_object->ResizeBuffers1(BufferCount,
                                                           Width,
                                                           Height,
                                                           Format,
                                                           SwapChainFlags,
                                                           pCreationNodeMask->GetPointer(),
                                                           MapObject<IUnknown*>(*ppPresentQueue->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain3_ResizeBuffers1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DXGI_FORMAT                                 Format,
    DXGI_COLOR_SPACE_TYPE                       ColorSpace,
    HandlePointerDecoder<IUnknown*>*            pConcernedDevice,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput4>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckOverlayColorSpaceSupport(Format,
                                                                          ColorSpace,
                                                                          MapObject<IUnknown>(*pConcernedDevice->GetPointer()),
                                                                          pFlags->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput4_CheckOverlayColorSpaceSupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory4_EnumAdapterByLuid(
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
        auto _out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto _out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapterByLuid(*AdapterLuid.decoded_value,
                                                              *riid.decoded_value,
                                                              reinterpret_cast<void**>(_out_hp_ppvAdapter));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvAdapter, _out_hp_ppvAdapter);
        }
        CheckReplayResult("IDXGIFactory4_EnumAdapterByLuid", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory4_EnumWarpAdapter(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvAdapter)
{
    auto replay_object = MapObject<IDXGIFactory4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvAdapter->IsNull()) ppvAdapter->SetHandleLength(1);
        auto _out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto _out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumWarpAdapter(*riid.decoded_value,
                                                            reinterpret_cast<void**>(_out_hp_ppvAdapter));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvAdapter, _out_hp_ppvAdapter);
        }
        CheckReplayResult("IDXGIFactory4_EnumWarpAdapter", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterHardwareContentProtectionTeardownStatusEvent(MapHandle<HANDLE>(hEvent),
                                                                                                 pdwCookie->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterHardwareContentProtectionTeardownStatus(dwCookie);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter3_QueryVideoMemoryInfo(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter3_QueryVideoMemoryInfo", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter3_SetVideoMemoryReservation(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter3_SetVideoMemoryReservation", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterVideoMemoryBudgetChangeNotificationEvent(MapHandle<HANDLE>(hEvent),
                                                                                             pdwCookie->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
    format::HandleId                            object_id,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIAdapter3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UnregisterVideoMemoryBudgetChangeNotification(dwCookie);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput5_DuplicateOutput1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<IUnknown*>*            pDevice,
    UINT                                        Flags,
    UINT                                        SupportedFormatsCount,
    PointerDecoder<DXGI_FORMAT>*                pSupportedFormats,
    HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication)
{
    auto replay_object = MapObject<IDXGIOutput5>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppOutputDuplication->IsNull()) ppOutputDuplication->SetHandleLength(1);
        auto _out_p_ppOutputDuplication    = ppOutputDuplication->GetPointer();
        auto _out_hp_ppOutputDuplication   = ppOutputDuplication->GetHandlePointer();
        auto replay_result = replay_object->DuplicateOutput1(MapObject<IUnknown>(*pDevice->GetPointer()),
                                                             Flags,
                                                             SupportedFormatsCount,
                                                             pSupportedFormats->GetPointer(),
                                                             _out_hp_ppOutputDuplication);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppOutputDuplication, _out_hp_ppOutputDuplication);
        }
        CheckReplayResult("IDXGIOutput5_DuplicateOutput1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGISwapChain4_SetHDRMetaData(
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
                                                           reinterpret_cast<void*>(pMetaData));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGISwapChain4_SetHDRMetaData", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice4_OfferResources1(
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
        auto replay_result = replay_object->OfferResources1(NumResources,
                                                            MapObject<IDXGIResource*>(*ppResources->GetPointer()),
                                                            Priority,
                                                            Flags);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice4_OfferResources1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIDevice4_ReclaimResources1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumResources,
    HandlePointerDecoder<IDXGIResource*>*       ppResources,
    PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults)
{
    auto replay_object = MapObject<IDXGIDevice4>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReclaimResources1(NumResources,
                                                              MapObject<IDXGIResource*>(*ppResources->GetPointer()),
                                                              pResults->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIDevice4_ReclaimResources1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory5_CheckFeatureSupport(
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
                                                                reinterpret_cast<void*>(pFeatureSupportData),
                                                                FeatureSupportDataSize);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory5_CheckFeatureSupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIAdapter4_GetDesc3(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc)
{
    auto replay_object = MapObject<IDXGIAdapter4>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc3(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIAdapter4_GetDesc3", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput6_GetDesc1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc)
{
    auto replay_object = MapObject<IDXGIOutput6>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1(pDesc->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput6_GetDesc1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIOutput6_CheckHardwareCompositionSupport(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT>*                       pFlags)
{
    auto replay_object = MapObject<IDXGIOutput6>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->CheckHardwareCompositionSupport(pFlags->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIOutput6_CheckHardwareCompositionSupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory6_EnumAdapterByGpuPreference(
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
        auto _out_p_ppvAdapter    = ppvAdapter->GetPointer();
        auto _out_hp_ppvAdapter   = ppvAdapter->GetHandlePointer();
        auto replay_result = replay_object->EnumAdapterByGpuPreference(Adapter,
                                                                       GpuPreference,
                                                                       *riid.decoded_value,
                                                                       reinterpret_cast<void**>(_out_hp_ppvAdapter));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvAdapter, _out_hp_ppvAdapter);
        }
        CheckReplayResult("IDXGIFactory6_EnumAdapterByGpuPreference", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hEvent,
    PointerDecoder<DWORD>*                      pdwCookie)
{
    auto replay_object = MapObject<IDXGIFactory7>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterAdaptersChangedEvent(MapHandle<HANDLE>(hEvent),
                                                                         pdwCookie->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory7_RegisterAdaptersChangedEvent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    DWORD                                       dwCookie)
{
    auto replay_object = MapObject<IDXGIFactory7>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnregisterAdaptersChangedEvent(dwCookie);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("IDXGIFactory7_UnregisterAdaptersChangedEvent", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Object_GetPrivateData(
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
                                                           reinterpret_cast<void*>(pData));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Object_GetPrivateData", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Object_SetPrivateData(
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
                                                           reinterpret_cast<void*>(pData));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Object_SetPrivateData", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Object_SetPrivateDataInterface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                guid,
    HandlePointerDecoder<IUnknown*>*            pData)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetPrivateDataInterface(*guid.decoded_value,
                                                                    MapObject<IUnknown>(*pData->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Object_SetPrivateDataInterface", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Object_SetName(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             Name)
{
    auto replay_object = MapObject<ID3D12Object>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetName(Name->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Object_SetName", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceChild_GetDevice(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvDevice)
{
    auto replay_object = MapObject<ID3D12DeviceChild>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvDevice->IsNull()) ppvDevice->SetHandleLength(1);
        auto _out_p_ppvDevice    = ppvDevice->GetPointer();
        auto _out_hp_ppvDevice   = ppvDevice->GetHandlePointer();
        auto replay_result = replay_object->GetDevice(*riid.decoded_value,
                                                      reinterpret_cast<void**>(_out_hp_ppvDevice));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvDevice, _out_hp_ppvDevice);
        }
        CheckReplayResult("ID3D12DeviceChild_GetDevice", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* returnValue)
{
    auto replay_object = MapObject<ID3D12RootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetRootSignatureDesc();
    }
}

void DX12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* returnValue)
{
    auto replay_object = MapObject<ID3D12VersionedRootSignatureDeserializer>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetUnconvertedRootSignatureDesc();
    }
}

void DX12ReplayConsumer::Process_ID3D12Heap_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_HEAP_DESC                     returnValue)
{
    auto replay_object = MapObject<ID3D12Heap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource_Map(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        Subresource,
    StructPointerDecoder<Decoded_D3D12_RANGE>*  pReadRange,
    PointerDecoder<uint64_t, void*>*            ppData)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Map(Subresource,
                                                pReadRange->GetPointer(),
                                                ppData->GetOutputPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Resource_Map", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource_Unmap(
    format::HandleId                            object_id,
    UINT                                        Subresource,
    StructPointerDecoder<Decoded_D3D12_RANGE>*  pWrittenRange)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->Unmap(Subresource,
                             pWrittenRange->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC                 returnValue)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource_GetGPUVirtualAddress(
    format::HandleId                            object_id,
    D3D12_GPU_VIRTUAL_ADDRESS                   returnValue)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGPUVirtualAddress();
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource_WriteToSubresource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        DstSubresource,
    StructPointerDecoder<Decoded_D3D12_BOX>*    pDstBox,
    uint64_t                                    pSrcData,
    UINT                                        SrcRowPitch,
    UINT                                        SrcDepthPitch)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->WriteToSubresource(DstSubresource,
                                                               pDstBox->GetPointer(),
                                                               reinterpret_cast<void*>(pSrcData),
                                                               SrcRowPitch,
                                                               SrcDepthPitch);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Resource_WriteToSubresource", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource_ReadFromSubresource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    pDstData,
    UINT                                        DstRowPitch,
    UINT                                        DstDepthPitch,
    UINT                                        SrcSubresource,
    StructPointerDecoder<Decoded_D3D12_BOX>*    pSrcBox)
{
    auto replay_object = MapObject<ID3D12Resource>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ReadFromSubresource(reinterpret_cast<void*>(pDstData),
                                                                DstRowPitch,
                                                                DstDepthPitch,
                                                                SrcSubresource,
                                                                pSrcBox->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Resource_ReadFromSubresource", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource_GetHeapProperties(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Resource_GetHeapProperties", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandAllocator_Reset(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12CommandAllocator>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Reset();
    }
}

void DX12ReplayConsumer::Process_ID3D12Fence_GetCompletedValue(
    format::HandleId                            object_id,
    UINT64                                      returnValue)
{
    auto replay_object = MapObject<ID3D12Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCompletedValue();
    }
}

void DX12ReplayConsumer::Process_ID3D12Fence_SetEventOnCompletion(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      Value,
    format::HandleId                            hEvent)
{
    auto replay_object = MapObject<ID3D12Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetEventOnCompletion(Value,
                                                                 MapHandle<HANDLE>(hEvent));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Fence_SetEventOnCompletion", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Fence_Signal(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D12Fence>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Signal(Value);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Fence_Signal", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Fence1_GetCreationFlags(
    format::HandleId                            object_id,
    D3D12_FENCE_FLAGS                           returnValue)
{
    auto replay_object = MapObject<ID3D12Fence1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCreationFlags();
    }
}

void DX12ReplayConsumer::Process_ID3D12PipelineState_GetCachedBlob(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D10Blob*>*          ppBlob)
{
    auto replay_object = MapObject<ID3D12PipelineState>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppBlob->IsNull()) ppBlob->SetHandleLength(1);
        auto _out_p_ppBlob    = ppBlob->GetPointer();
        auto _out_hp_ppBlob   = ppBlob->GetHandlePointer();
        auto replay_result = replay_object->GetCachedBlob(_out_hp_ppBlob);
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppBlob, _out_hp_ppBlob);
        }
        CheckReplayResult("ID3D12PipelineState_GetCachedBlob", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12DescriptorHeap_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_DESCRIPTOR_HEAP_DESC          returnValue)
{
    auto replay_object = MapObject<ID3D12DescriptorHeap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void DX12ReplayConsumer::Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    format::HandleId                            object_id,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         returnValue)
{
    auto replay_object = MapObject<ID3D12DescriptorHeap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetCPUDescriptorHandleForHeapStart();
    }
}

void DX12ReplayConsumer::Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    format::HandleId                            object_id,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         returnValue)
{
    auto replay_object = MapObject<ID3D12DescriptorHeap>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetGPUDescriptorHandleForHeapStart();
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandList_GetType(
    format::HandleId                            object_id,
    D3D12_COMMAND_LIST_TYPE                     returnValue)
{
    auto replay_object = MapObject<ID3D12CommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetType();
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_Close(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Close();
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_Reset(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12CommandAllocator*>* pAllocator,
    HandlePointerDecoder<ID3D12PipelineState*>* pInitialState)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Reset(MapObject<ID3D12CommandAllocator>(*pAllocator->GetPointer()),
                                                  MapObject<ID3D12PipelineState>(*pInitialState->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12GraphicsCommandList_Reset", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearState(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12PipelineState*>* pPipelineState)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearState(MapObject<ID3D12PipelineState>(*pPipelineState->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_DrawInstanced(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_Dispatch(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyBufferRegion(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pDstBuffer,
    UINT64                                      DstOffset,
    HandlePointerDecoder<ID3D12Resource*>*      pSrcBuffer,
    UINT64                                      SrcOffset,
    UINT64                                      NumBytes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CopyBufferRegion(MapObject<ID3D12Resource>(*pDstBuffer->GetPointer()),
                                        DstOffset,
                                        MapObject<ID3D12Resource>(*pSrcBuffer->GetPointer()),
                                        SrcOffset,
                                        NumBytes);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyTextureRegion(
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
        replay_object->CopyTextureRegion(pDst->GetPointer(),
                                         DstX,
                                         DstY,
                                         DstZ,
                                         pSrc->GetPointer(),
                                         pSrcBox->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyResource(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pDstResource,
    HandlePointerDecoder<ID3D12Resource*>*      pSrcResource)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CopyResource(MapObject<ID3D12Resource>(*pDstResource->GetPointer()),
                                    MapObject<ID3D12Resource>(*pSrcResource->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_CopyTiles(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pTiledResource,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pTileRegionSize,
    HandlePointerDecoder<ID3D12Resource*>*      pBuffer,
    UINT64                                      BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS                       Flags)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CopyTiles(MapObject<ID3D12Resource>(*pTiledResource->GetPointer()),
                                 pTileRegionStartCoordinate->GetPointer(),
                                 pTileRegionSize->GetPointer(),
                                 MapObject<ID3D12Resource>(*pBuffer->GetPointer()),
                                 BufferStartOffsetInBytes,
                                 Flags);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ResolveSubresource(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pDstResource,
    UINT                                        DstSubresource,
    HandlePointerDecoder<ID3D12Resource*>*      pSrcResource,
    UINT                                        SrcSubresource,
    DXGI_FORMAT                                 Format)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ResolveSubresource(MapObject<ID3D12Resource>(*pDstResource->GetPointer()),
                                          DstSubresource,
                                          MapObject<ID3D12Resource>(*pSrcResource->GetPointer()),
                                          SrcSubresource,
                                          Format);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
    format::HandleId                            object_id,
    D3D_PRIMITIVE_TOPOLOGY                      PrimitiveTopology)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->IASetPrimitiveTopology(PrimitiveTopology);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_RSSetViewports(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_RSSetScissorRects(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
    format::HandleId                            object_id,
    PointerDecoder<FLOAT>*                      BlendFactor)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->OMSetBlendFactor(BlendFactor->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetStencilRef(
    format::HandleId                            object_id,
    UINT                                        StencilRef)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->OMSetStencilRef(StencilRef);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetPipelineState(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12PipelineState*>* pPipelineState)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetPipelineState(MapObject<ID3D12PipelineState>(*pPipelineState->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ResourceBarrier(
    format::HandleId                            object_id,
    UINT                                        NumBarriers,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ResourceBarrier(NumBarriers,
                                       pBarriers->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ExecuteBundle(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12GraphicsCommandList*>* pCommandList)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ExecuteBundle(MapObject<ID3D12GraphicsCommandList>(*pCommandList->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    format::HandleId                            object_id,
    UINT                                        NumDescriptorHeaps,
    HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetDescriptorHeaps(NumDescriptorHeaps,
                                          MapObject<ID3D12DescriptorHeap*>(*ppDescriptorHeaps->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12RootSignature*>* pRootSignature)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetComputeRootSignature(MapObject<ID3D12RootSignature>(*pRootSignature->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12RootSignature*>* pRootSignature)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetGraphicsRootSignature(MapObject<ID3D12RootSignature>(*pRootSignature->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
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
                                                    reinterpret_cast<void*>(pSrcData),
                                                    DestOffsetIn32BitValues);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
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
                                                     reinterpret_cast<void*>(pSrcData),
                                                     DestOffsetIn32BitValues);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->IASetIndexBuffer(pView->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SOSetTargets(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
    format::HandleId                            object_id,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         ViewGPUHandleInCurrentHeap,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         ViewCPUHandle,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    PointerDecoder<UINT>*                       Values,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearUnorderedAccessViewUint(*ViewGPUHandleInCurrentHeap.decoded_value,
                                                    *ViewCPUHandle.decoded_value,
                                                    MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                                    Values->GetPointer(),
                                                    NumRects,
                                                    pRects->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
    format::HandleId                            object_id,
    Decoded_D3D12_GPU_DESCRIPTOR_HANDLE         ViewGPUHandleInCurrentHeap,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         ViewCPUHandle,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    PointerDecoder<FLOAT>*                      Values,
    UINT                                        NumRects,
    StructPointerDecoder<Decoded_tagRECT>*      pRects)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ClearUnorderedAccessViewFloat(*ViewGPUHandleInCurrentHeap.decoded_value,
                                                     *ViewCPUHandle.decoded_value,
                                                     MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                                     Values->GetPointer(),
                                                     NumRects,
                                                     pRects->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_DiscardResource(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DiscardResource(MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                       pRegion->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_BeginQuery(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12QueryHeap*>*     pQueryHeap,
    D3D12_QUERY_TYPE                            Type,
    UINT                                        Index)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginQuery(MapObject<ID3D12QueryHeap>(*pQueryHeap->GetPointer()),
                                  Type,
                                  Index);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_EndQuery(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12QueryHeap*>*     pQueryHeap,
    D3D12_QUERY_TYPE                            Type,
    UINT                                        Index)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndQuery(MapObject<ID3D12QueryHeap>(*pQueryHeap->GetPointer()),
                                Type,
                                Index);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ResolveQueryData(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12QueryHeap*>*     pQueryHeap,
    D3D12_QUERY_TYPE                            Type,
    UINT                                        StartIndex,
    UINT                                        NumQueries,
    HandlePointerDecoder<ID3D12Resource*>*      pDestinationBuffer,
    UINT64                                      AlignedDestinationBufferOffset)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ResolveQueryData(MapObject<ID3D12QueryHeap>(*pQueryHeap->GetPointer()),
                                        Type,
                                        StartIndex,
                                        NumQueries,
                                        MapObject<ID3D12Resource>(*pDestinationBuffer->GetPointer()),
                                        AlignedDestinationBufferOffset);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetPredication(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pBuffer,
    UINT64                                      AlignedBufferOffset,
    D3D12_PREDICATION_OP                        Operation)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetPredication(MapObject<ID3D12Resource>(*pBuffer->GetPointer()),
                                      AlignedBufferOffset,
                                      Operation);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_SetMarker(
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetMarker(Metadata,
                                 reinterpret_cast<void*>(pData),
                                 Size);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_BeginEvent(
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginEvent(Metadata,
                                  reinterpret_cast<void*>(pData),
                                  Size);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_EndEvent(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndEvent();
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList_ExecuteIndirect(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12CommandSignature*>* pCommandSignature,
    UINT                                        MaxCommandCount,
    HandlePointerDecoder<ID3D12Resource*>*      pArgumentBuffer,
    UINT64                                      ArgumentBufferOffset,
    HandlePointerDecoder<ID3D12Resource*>*      pCountBuffer,
    UINT64                                      CountBufferOffset)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ExecuteIndirect(MapObject<ID3D12CommandSignature>(*pCommandSignature->GetPointer()),
                                       MaxCommandCount,
                                       MapObject<ID3D12Resource>(*pArgumentBuffer->GetPointer()),
                                       ArgumentBufferOffset,
                                       MapObject<ID3D12Resource>(*pCountBuffer->GetPointer()),
                                       CountBufferOffset);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pDstBuffer,
    UINT64                                      DstOffset,
    HandlePointerDecoder<ID3D12Resource*>*      pSrcBuffer,
    UINT64                                      SrcOffset,
    UINT                                        Dependencies,
    HandlePointerDecoder<ID3D12Resource*>*      ppDependentResources,
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->AtomicCopyBufferUINT(MapObject<ID3D12Resource>(*pDstBuffer->GetPointer()),
                                            DstOffset,
                                            MapObject<ID3D12Resource>(*pSrcBuffer->GetPointer()),
                                            SrcOffset,
                                            Dependencies,
                                            MapObject<ID3D12Resource*>(*ppDependentResources->GetPointer()),
                                            pDependentSubresourceRanges->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pDstBuffer,
    UINT64                                      DstOffset,
    HandlePointerDecoder<ID3D12Resource*>*      pSrcBuffer,
    UINT64                                      SrcOffset,
    UINT                                        Dependencies,
    HandlePointerDecoder<ID3D12Resource*>*      ppDependentResources,
    StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->AtomicCopyBufferUINT64(MapObject<ID3D12Resource>(*pDstBuffer->GetPointer()),
                                              DstOffset,
                                              MapObject<ID3D12Resource>(*pSrcBuffer->GetPointer()),
                                              SrcOffset,
                                              Dependencies,
                                              MapObject<ID3D12Resource*>(*ppDependentResources->GetPointer()),
                                              pDependentSubresourceRanges->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList1_SetSamplePositions(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pDstResource,
    UINT                                        DstSubresource,
    UINT                                        DstX,
    UINT                                        DstY,
    HandlePointerDecoder<ID3D12Resource*>*      pSrcResource,
    UINT                                        SrcSubresource,
    StructPointerDecoder<Decoded_tagRECT>*      pSrcRect,
    DXGI_FORMAT                                 Format,
    D3D12_RESOLVE_MODE                          ResolveMode)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ResolveSubresourceRegion(MapObject<ID3D12Resource>(*pDstResource->GetPointer()),
                                                DstSubresource,
                                                DstX,
                                                DstY,
                                                MapObject<ID3D12Resource>(*pSrcResource->GetPointer()),
                                                SrcSubresource,
                                                pSrcRect->GetPointer(),
                                                Format,
                                                ResolveMode);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
    format::HandleId                            object_id,
    UINT                                        Mask)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetViewInstanceMask(Mask);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
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

void DX12ReplayConsumer::Process_ID3D12CommandQueue_UpdateTileMappings(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    UINT                                        NumResourceRegions,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pResourceRegionStartCoordinates,
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pResourceRegionSizes,
    HandlePointerDecoder<ID3D12Heap*>*          pHeap,
    UINT                                        NumRanges,
    PointerDecoder<D3D12_TILE_RANGE_FLAGS>*     pRangeFlags,
    PointerDecoder<UINT>*                       pHeapRangeStartOffsets,
    PointerDecoder<UINT>*                       pRangeTileCounts,
    D3D12_TILE_MAPPING_FLAGS                    Flags)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->UpdateTileMappings(MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                          NumResourceRegions,
                                          pResourceRegionStartCoordinates->GetPointer(),
                                          pResourceRegionSizes->GetPointer(),
                                          MapObject<ID3D12Heap>(*pHeap->GetPointer()),
                                          NumRanges,
                                          pRangeFlags->GetPointer(),
                                          pHeapRangeStartOffsets->GetPointer(),
                                          pRangeTileCounts->GetPointer(),
                                          Flags);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_CopyTileMappings(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pDstResource,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pDstRegionStartCoordinate,
    HandlePointerDecoder<ID3D12Resource*>*      pSrcResource,
    StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pSrcRegionStartCoordinate,
    StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS                    Flags)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CopyTileMappings(MapObject<ID3D12Resource>(*pDstResource->GetPointer()),
                                        pDstRegionStartCoordinate->GetPointer(),
                                        MapObject<ID3D12Resource>(*pSrcResource->GetPointer()),
                                        pSrcRegionStartCoordinate->GetPointer(),
                                        pRegionSize->GetPointer(),
                                        Flags);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_ExecuteCommandLists(
    format::HandleId                            object_id,
    UINT                                        NumCommandLists,
    HandlePointerDecoder<ID3D12CommandList*>*   ppCommandLists)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ExecuteCommandLists(NumCommandLists,
                                           MapObject<ID3D12CommandList*>(*ppCommandLists->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_SetMarker(
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetMarker(Metadata,
                                 reinterpret_cast<void*>(pData),
                                 Size);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_BeginEvent(
    format::HandleId                            object_id,
    UINT                                        Metadata,
    PointerDecoder<uint8_t>*                    pData,
    UINT                                        Size)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginEvent(Metadata,
                                  reinterpret_cast<void*>(pData),
                                  Size);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_EndEvent(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndEvent();
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_Signal(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12Fence*>*         pFence,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Signal(MapObject<ID3D12Fence>(*pFence->GetPointer()),
                                                   Value);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12CommandQueue_Signal", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_Wait(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12Fence*>*         pFence,
    UINT64                                      Value)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Wait(MapObject<ID3D12Fence>(*pFence->GetPointer()),
                                                 Value);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12CommandQueue_Wait", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_GetTimestampFrequency(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<UINT64>*                     pFrequency)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetTimestampFrequency(pFrequency->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12CommandQueue_GetTimestampFrequency", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_GetClockCalibration(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12CommandQueue_GetClockCalibration", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12CommandQueue_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_COMMAND_QUEUE_DESC            returnValue)
{
    auto replay_object = MapObject<ID3D12CommandQueue>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_GetNodeCount(
    format::HandleId                            object_id,
    UINT                                        returnValue)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetNodeCount();
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateCommandQueue(
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
        auto _out_p_ppCommandQueue    = ppCommandQueue->GetPointer();
        auto _out_hp_ppCommandQueue   = ppCommandQueue->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandQueue(pDesc->GetPointer(),
                                                               *riid.decoded_value,
                                                               reinterpret_cast<void**>(_out_hp_ppCommandQueue));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppCommandQueue, _out_hp_ppCommandQueue);
        }
        CheckReplayResult("ID3D12Device_CreateCommandQueue", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateCommandAllocator(
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
        auto _out_p_ppCommandAllocator    = ppCommandAllocator->GetPointer();
        auto _out_hp_ppCommandAllocator   = ppCommandAllocator->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandAllocator(type,
                                                                   *riid.decoded_value,
                                                                   reinterpret_cast<void**>(_out_hp_ppCommandAllocator));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppCommandAllocator, _out_hp_ppCommandAllocator);
        }
        CheckReplayResult("ID3D12Device_CreateCommandAllocator", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateGraphicsPipelineState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto _out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto _out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->CreateGraphicsPipelineState(pDesc->GetPointer(),
                                                                        *riid.decoded_value,
                                                                        reinterpret_cast<void**>(_out_hp_ppPipelineState));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppPipelineState, _out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateGraphicsPipelineState", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateComputePipelineState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppPipelineState)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto _out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto _out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->CreateComputePipelineState(pDesc->GetPointer(),
                                                                       *riid.decoded_value,
                                                                       reinterpret_cast<void**>(_out_hp_ppPipelineState));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppPipelineState, _out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12Device_CreateComputePipelineState", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateCommandList(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        nodeMask,
    D3D12_COMMAND_LIST_TYPE                     type,
    HandlePointerDecoder<ID3D12CommandAllocator*>* pCommandAllocator,
    HandlePointerDecoder<ID3D12PipelineState*>* pInitialState,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppCommandList)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppCommandList->IsNull()) ppCommandList->SetHandleLength(1);
        auto _out_p_ppCommandList    = ppCommandList->GetPointer();
        auto _out_hp_ppCommandList   = ppCommandList->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandList(nodeMask,
                                                              type,
                                                              MapObject<ID3D12CommandAllocator>(*pCommandAllocator->GetPointer()),
                                                              MapObject<ID3D12PipelineState>(*pInitialState->GetPointer()),
                                                              *riid.decoded_value,
                                                              reinterpret_cast<void**>(_out_hp_ppCommandList));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppCommandList, _out_hp_ppCommandList);
        }
        CheckReplayResult("ID3D12Device_CreateCommandList", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CheckFeatureSupport(
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
                                                                reinterpret_cast<void*>(pFeatureSupportData),
                                                                FeatureSupportDataSize);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device_CheckFeatureSupport", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateDescriptorHeap(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto _out_p_ppvHeap    = ppvHeap->GetPointer();
        auto _out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->CreateDescriptorHeap(pDescriptorHeapDesc->GetPointer(),
                                                                 *riid.decoded_value,
                                                                 reinterpret_cast<void**>(_out_hp_ppvHeap));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvHeap, _out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device_CreateDescriptorHeap", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_GetDescriptorHandleIncrementSize(
    format::HandleId                            object_id,
    UINT                                        returnValue,
    D3D12_DESCRIPTOR_HEAP_TYPE                  DescriptorHeapType)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDescriptorHandleIncrementSize(DescriptorHeapType);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateRootSignature(
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
        auto _out_p_ppvRootSignature    = ppvRootSignature->GetPointer();
        auto _out_hp_ppvRootSignature   = ppvRootSignature->GetHandlePointer();
        auto replay_result = replay_object->CreateRootSignature(nodeMask,
                                                                reinterpret_cast<void*>(pBlobWithRootSignature),
                                                                blobLengthInBytes,
                                                                *riid.decoded_value,
                                                                reinterpret_cast<void**>(_out_hp_ppvRootSignature));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvRootSignature, _out_hp_ppvRootSignature);
        }
        CheckReplayResult("ID3D12Device_CreateRootSignature", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateConstantBufferView(
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

void DX12ReplayConsumer::Process_ID3D12Device_CreateShaderResourceView(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CreateShaderResourceView(MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                                pDesc->GetPointer(),
                                                *DestDescriptor.decoded_value);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateUnorderedAccessView(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    HandlePointerDecoder<ID3D12Resource*>*      pCounterResource,
    StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CreateUnorderedAccessView(MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                                 MapObject<ID3D12Resource>(*pCounterResource->GetPointer()),
                                                 pDesc->GetPointer(),
                                                 *DestDescriptor.decoded_value);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateRenderTargetView(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CreateRenderTargetView(MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                              pDesc->GetPointer(),
                                              *DestDescriptor.decoded_value);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateDepthStencilView(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pResource,
    StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CreateDepthStencilView(MapObject<ID3D12Resource>(*pResource->GetPointer()),
                                              pDesc->GetPointer(),
                                              *DestDescriptor.decoded_value);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateSampler(
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

void DX12ReplayConsumer::Process_ID3D12Device_CopyDescriptors(
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

void DX12ReplayConsumer::Process_ID3D12Device_CopyDescriptorsSimple(
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

void DX12ReplayConsumer::Process_ID3D12Device_GetResourceAllocationInfo(
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

void DX12ReplayConsumer::Process_ID3D12Device_GetCustomHeapProperties(
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

void DX12ReplayConsumer::Process_ID3D12Device_CreateCommittedResource(
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
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateCommittedResource(pHeapProperties->GetPointer(),
                                                                    HeapFlags,
                                                                    pDesc->GetPointer(),
                                                                    InitialResourceState,
                                                                    pOptimizedClearValue->GetPointer(),
                                                                    *riidResource.decoded_value,
                                                                    reinterpret_cast<void**>(_out_hp_ppvResource));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device_CreateCommittedResource", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateHeap(
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
        auto _out_p_ppvHeap    = ppvHeap->GetPointer();
        auto _out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->CreateHeap(pDesc->GetPointer(),
                                                       *riid.decoded_value,
                                                       reinterpret_cast<void**>(_out_hp_ppvHeap));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvHeap, _out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device_CreateHeap", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreatePlacedResource(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12Heap*>*          pHeap,
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
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreatePlacedResource(MapObject<ID3D12Heap>(*pHeap->GetPointer()),
                                                                 HeapOffset,
                                                                 pDesc->GetPointer(),
                                                                 InitialState,
                                                                 pOptimizedClearValue->GetPointer(),
                                                                 *riid.decoded_value,
                                                                 reinterpret_cast<void**>(_out_hp_ppvResource));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device_CreatePlacedResource", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateReservedResource(
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
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateReservedResource(pDesc->GetPointer(),
                                                                   InitialState,
                                                                   pOptimizedClearValue->GetPointer(),
                                                                   *riid.decoded_value,
                                                                   reinterpret_cast<void**>(_out_hp_ppvResource));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device_CreateReservedResource", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12DeviceChild*>*   pObject,
    StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
    DWORD                                       Access,
    WStringDecoder*                             Name,
    HandlePointerDecoder<HANDLE>*               pHandle)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pHandle->IsNull()) pHandle->SetHandleLength(1);
        auto _out_p_pHandle    = pHandle->GetPointer();
        auto _out_hp_pHandle   = pHandle->GetHandlePointer();
        auto replay_result = replay_object->CreateSharedHandle(MapObject<ID3D12DeviceChild>(*pObject->GetPointer()),
                                                               pAttributes->GetPointer(),
                                                               Access,
                                                               Name->GetPointer(),
                                                               _out_hp_pHandle);
        if (SUCCEEDED(replay_result))
        {
            AddHandle(_out_p_pHandle, _out_hp_pHandle);
        }
        CheckReplayResult("ID3D12Device_CreateSharedHandle", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_OpenSharedHandle(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            NTHandle,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvObj)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvObj->IsNull()) ppvObj->SetHandleLength(1);
        auto _out_p_ppvObj    = ppvObj->GetPointer();
        auto _out_hp_ppvObj   = ppvObj->GetHandlePointer();
        auto replay_result = replay_object->OpenSharedHandle(MapHandle<HANDLE>(NTHandle),
                                                             *riid.decoded_value,
                                                             reinterpret_cast<void**>(_out_hp_ppvObj));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvObj, _out_hp_ppvObj);
        }
        CheckReplayResult("ID3D12Device_OpenSharedHandle", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_OpenSharedHandleByName(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             Name,
    DWORD                                       Access,
    HandlePointerDecoder<HANDLE>*               pNTHandle)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!pNTHandle->IsNull()) pNTHandle->SetHandleLength(1);
        auto _out_p_pNTHandle    = pNTHandle->GetPointer();
        auto _out_hp_pNTHandle   = pNTHandle->GetHandlePointer();
        auto replay_result = replay_object->OpenSharedHandleByName(Name->GetPointer(),
                                                                   Access,
                                                                   _out_hp_pNTHandle);
        if (SUCCEEDED(replay_result))
        {
            AddHandle(_out_p_pNTHandle, _out_hp_pNTHandle);
        }
        CheckReplayResult("ID3D12Device_OpenSharedHandleByName", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_MakeResident(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->MakeResident(NumObjects,
                                                         MapObject<ID3D12Pageable*>(*ppObjects->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device_MakeResident", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_Evict(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Evict(NumObjects,
                                                  MapObject<ID3D12Pageable*>(*ppObjects->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device_Evict", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateFence(
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
        auto _out_p_ppFence    = ppFence->GetPointer();
        auto _out_hp_ppFence   = ppFence->GetHandlePointer();
        auto replay_result = replay_object->CreateFence(InitialValue,
                                                        Flags,
                                                        *riid.decoded_value,
                                                        reinterpret_cast<void**>(_out_hp_ppFence));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppFence, _out_hp_ppFence);
        }
        CheckReplayResult("ID3D12Device_CreateFence", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_GetDeviceRemovedReason(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDeviceRemovedReason();
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_GetCopyableFootprints(
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

void DX12ReplayConsumer::Process_ID3D12Device_CreateQueryHeap(
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
        auto _out_p_ppvHeap    = ppvHeap->GetPointer();
        auto _out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->CreateQueryHeap(pDesc->GetPointer(),
                                                            *riid.decoded_value,
                                                            reinterpret_cast<void**>(_out_hp_ppvHeap));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvHeap, _out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device_CreateQueryHeap", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_SetStablePowerState(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    BOOL                                        Enable)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetStablePowerState(Enable);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device_SetStablePowerState", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_CreateCommandSignature(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
    HandlePointerDecoder<ID3D12RootSignature*>* pRootSignature,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvCommandSignature)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvCommandSignature->IsNull()) ppvCommandSignature->SetHandleLength(1);
        auto _out_p_ppvCommandSignature    = ppvCommandSignature->GetPointer();
        auto _out_hp_ppvCommandSignature   = ppvCommandSignature->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandSignature(pDesc->GetPointer(),
                                                                   MapObject<ID3D12RootSignature>(*pRootSignature->GetPointer()),
                                                                   *riid.decoded_value,
                                                                   reinterpret_cast<void**>(_out_hp_ppvCommandSignature));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvCommandSignature, _out_hp_ppvCommandSignature);
        }
        CheckReplayResult("ID3D12Device_CreateCommandSignature", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_GetResourceTiling(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pTiledResource,
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
        replay_object->GetResourceTiling(MapObject<ID3D12Resource>(*pTiledResource->GetPointer()),
                                         pNumTilesForEntireResource->GetPointer(),
                                         pPackedMipDesc->GetPointer(),
                                         pStandardTileShapeForNonPackedMips->GetPointer(),
                                         pNumSubresourceTilings->GetPointer(),
                                         FirstSubresourceTilingToGet,
                                         pSubresourceTilingsForNonPackedMips->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12Device_GetAdapterLuid(
    format::HandleId                            object_id,
    Decoded_LUID                                returnValue)
{
    auto replay_object = MapObject<ID3D12Device>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetAdapterLuid();
    }
}

void DX12ReplayConsumer::Process_ID3D12PipelineLibrary_StorePipeline(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    WStringDecoder*                             pName,
    HandlePointerDecoder<ID3D12PipelineState*>* pPipeline)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->StorePipeline(pName->GetPointer(),
                                                          MapObject<ID3D12PipelineState>(*pPipeline->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12PipelineLibrary_StorePipeline", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
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
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto _out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto _out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->LoadGraphicsPipeline(pName->GetPointer(),
                                                                 pDesc->GetPointer(),
                                                                 *riid.decoded_value,
                                                                 reinterpret_cast<void**>(_out_hp_ppPipelineState));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppPipelineState, _out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadGraphicsPipeline", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12PipelineLibrary_LoadComputePipeline(
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
        if(!ppPipelineState->IsNull()) ppPipelineState->SetHandleLength(1);
        auto _out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto _out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->LoadComputePipeline(pName->GetPointer(),
                                                                pDesc->GetPointer(),
                                                                *riid.decoded_value,
                                                                reinterpret_cast<void**>(_out_hp_ppPipelineState));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppPipelineState, _out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12PipelineLibrary_LoadComputePipeline", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12PipelineLibrary_GetSerializedSize(
    format::HandleId                            object_id,
    SIZE_T                                      returnValue)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSerializedSize();
    }
}

void DX12ReplayConsumer::Process_ID3D12PipelineLibrary_Serialize(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    PointerDecoder<uint8_t>*                    pData,
    SIZE_T                                      DataSizeInBytes)
{
    auto replay_object = MapObject<ID3D12PipelineLibrary>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->Serialize(reinterpret_cast<void*>(pData),
                                                      DataSizeInBytes);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12PipelineLibrary_Serialize", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12PipelineLibrary1_LoadPipeline(
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
        auto _out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto _out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->LoadPipeline(pName->GetPointer(),
                                                         pDesc->GetPointer(),
                                                         *riid.decoded_value,
                                                         reinterpret_cast<void**>(_out_hp_ppPipelineState));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppPipelineState, _out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12PipelineLibrary1_LoadPipeline", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device1_CreatePipelineLibrary(
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
        auto _out_p_ppPipelineLibrary    = ppPipelineLibrary->GetPointer();
        auto _out_hp_ppPipelineLibrary   = ppPipelineLibrary->GetHandlePointer();
        auto replay_result = replay_object->CreatePipelineLibrary(reinterpret_cast<void*>(pLibraryBlob),
                                                                  BlobLength,
                                                                  *riid.decoded_value,
                                                                  reinterpret_cast<void**>(_out_hp_ppPipelineLibrary));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppPipelineLibrary, _out_hp_ppPipelineLibrary);
        }
        CheckReplayResult("ID3D12Device1_CreatePipelineLibrary", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12Fence*>*         ppFences,
    PointerDecoder<UINT64>*                     pFenceValues,
    UINT                                        NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS             Flags,
    format::HandleId                            hEvent)
{
    auto replay_object = MapObject<ID3D12Device1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetEventOnMultipleFenceCompletion(MapObject<ID3D12Fence*>(*ppFences->GetPointer()),
                                                                              pFenceValues->GetPointer(),
                                                                              NumFences,
                                                                              Flags,
                                                                              MapHandle<HANDLE>(hEvent));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device1_SetEventOnMultipleFenceCompletion", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device1_SetResidencyPriority(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects,
    PointerDecoder<D3D12_RESIDENCY_PRIORITY>*   pPriorities)
{
    auto replay_object = MapObject<ID3D12Device1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetResidencyPriority(NumObjects,
                                                                 MapObject<ID3D12Pageable*>(*ppObjects->GetPointer()),
                                                                 pPriorities->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device1_SetResidencyPriority", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device2_CreatePipelineState(
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
        auto _out_p_ppPipelineState    = ppPipelineState->GetPointer();
        auto _out_hp_ppPipelineState   = ppPipelineState->GetHandlePointer();
        auto replay_result = replay_object->CreatePipelineState(pDesc->GetPointer(),
                                                                *riid.decoded_value,
                                                                reinterpret_cast<void**>(_out_hp_ppPipelineState));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppPipelineState, _out_hp_ppPipelineState);
        }
        CheckReplayResult("ID3D12Device2_CreatePipelineState", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device3_OpenExistingHeapFromAddress(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    pAddress,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device3>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto _out_p_ppvHeap    = ppvHeap->GetPointer();
        auto _out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->OpenExistingHeapFromAddress(reinterpret_cast<void*>(pAddress),
                                                                        *riid.decoded_value,
                                                                        reinterpret_cast<void**>(_out_hp_ppvHeap));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvHeap, _out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromAddress", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    format::HandleId                            hFileMapping,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device3>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto _out_p_ppvHeap    = ppvHeap->GetPointer();
        auto _out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->OpenExistingHeapFromFileMapping(MapHandle<HANDLE>(hFileMapping),
                                                                            *riid.decoded_value,
                                                                            reinterpret_cast<void**>(_out_hp_ppvHeap));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvHeap, _out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device3_OpenExistingHeapFromFileMapping", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device3_EnqueueMakeResident(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    D3D12_RESIDENCY_FLAGS                       Flags,
    UINT                                        NumObjects,
    HandlePointerDecoder<ID3D12Pageable*>*      ppObjects,
    HandlePointerDecoder<ID3D12Fence*>*         pFenceToSignal,
    UINT64                                      FenceValueToSignal)
{
    auto replay_object = MapObject<ID3D12Device3>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->EnqueueMakeResident(Flags,
                                                                NumObjects,
                                                                MapObject<ID3D12Pageable*>(*ppObjects->GetPointer()),
                                                                MapObject<ID3D12Fence>(*pFenceToSignal->GetPointer()),
                                                                FenceValueToSignal);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device3_EnqueueMakeResident", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12ProtectedSession_GetStatusFence(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppFence)
{
    auto replay_object = MapObject<ID3D12ProtectedSession>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppFence->IsNull()) ppFence->SetHandleLength(1);
        auto _out_p_ppFence    = ppFence->GetPointer();
        auto _out_hp_ppFence   = ppFence->GetHandlePointer();
        auto replay_result = replay_object->GetStatusFence(*riid.decoded_value,
                                                           reinterpret_cast<void**>(_out_hp_ppFence));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppFence, _out_hp_ppFence);
        }
        CheckReplayResult("ID3D12ProtectedSession_GetStatusFence", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12ProtectedSession_GetSessionStatus(
    format::HandleId                            object_id,
    D3D12_PROTECTED_SESSION_STATUS              returnValue)
{
    auto replay_object = MapObject<ID3D12ProtectedSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetSessionStatus();
    }
}

void DX12ReplayConsumer::Process_ID3D12ProtectedResourceSession_GetDesc(
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC returnValue)
{
    auto replay_object = MapObject<ID3D12ProtectedResourceSession>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc();
    }
}

void DX12ReplayConsumer::Process_ID3D12Device4_CreateCommandList1(
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
        auto _out_p_ppCommandList    = ppCommandList->GetPointer();
        auto _out_hp_ppCommandList   = ppCommandList->GetHandlePointer();
        auto replay_result = replay_object->CreateCommandList1(nodeMask,
                                                               type,
                                                               flags,
                                                               *riid.decoded_value,
                                                               reinterpret_cast<void**>(_out_hp_ppCommandList));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppCommandList, _out_hp_ppCommandList);
        }
        CheckReplayResult("ID3D12Device4_CreateCommandList1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device4_CreateProtectedResourceSession(
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
        auto _out_p_ppSession    = ppSession->GetPointer();
        auto _out_hp_ppSession   = ppSession->GetHandlePointer();
        auto replay_result = replay_object->CreateProtectedResourceSession(pDesc->GetPointer(),
                                                                           *riid.decoded_value,
                                                                           reinterpret_cast<void**>(_out_hp_ppSession));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSession, _out_hp_ppSession);
        }
        CheckReplayResult("ID3D12Device4_CreateProtectedResourceSession", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device4_CreateCommittedResource1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateCommittedResource1(pHeapProperties->GetPointer(),
                                                                     HeapFlags,
                                                                     pDesc->GetPointer(),
                                                                     InitialResourceState,
                                                                     pOptimizedClearValue->GetPointer(),
                                                                     MapObject<ID3D12ProtectedResourceSession>(*pProtectedSession->GetPointer()),
                                                                     *riidResource.decoded_value,
                                                                     reinterpret_cast<void**>(_out_hp_ppvResource));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device4_CreateCommittedResource1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device4_CreateHeap1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
    HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvHeap)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvHeap->IsNull()) ppvHeap->SetHandleLength(1);
        auto _out_p_ppvHeap    = ppvHeap->GetPointer();
        auto _out_hp_ppvHeap   = ppvHeap->GetHandlePointer();
        auto replay_result = replay_object->CreateHeap1(pDesc->GetPointer(),
                                                        MapObject<ID3D12ProtectedResourceSession>(*pProtectedSession->GetPointer()),
                                                        *riid.decoded_value,
                                                        reinterpret_cast<void**>(_out_hp_ppvHeap));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvHeap, _out_hp_ppvHeap);
        }
        CheckReplayResult("ID3D12Device4_CreateHeap1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device4_CreateReservedResource1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
    D3D12_RESOURCE_STATES                       InitialState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device4>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateReservedResource1(pDesc->GetPointer(),
                                                                    InitialState,
                                                                    pOptimizedClearValue->GetPointer(),
                                                                    MapObject<ID3D12ProtectedResourceSession>(*pProtectedSession->GetPointer()),
                                                                    *riid.decoded_value,
                                                                    reinterpret_cast<void**>(_out_hp_ppvResource));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device4_CreateReservedResource1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device4_GetResourceAllocationInfo1(
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

void DX12ReplayConsumer::Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
    format::HandleId                            object_id,
    D3D12_LIFETIME_STATE                        NewState)
{
    auto replay_object = MapObject<ID3D12LifetimeOwner>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->LifetimeStateUpdated(NewState);
    }
}

void DX12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetLUID(
    format::HandleId                            object_id,
    Decoded_LUID                                returnValue)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetLUID();
    }
}

void DX12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetSwapChainObject(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppv)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppv->IsNull()) ppv->SetHandleLength(1);
        auto _out_p_ppv    = ppv->GetPointer();
        auto _out_hp_ppv   = ppv->GetHandlePointer();
        auto replay_result = replay_object->GetSwapChainObject(*riid.decoded_value,
                                                               reinterpret_cast<void**>(_out_hp_ppv));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppv, _out_hp_ppv);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetSwapChainObject", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
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
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        if(!ppvQueue->IsNull()) ppvQueue->SetHandleLength(1);
        auto _out_p_ppvQueue    = ppvQueue->GetPointer();
        auto _out_hp_ppvQueue   = ppvQueue->GetHandlePointer();
        auto replay_result = replay_object->GetCurrentResourceAndCommandQueue(*riidResource.decoded_value,
                                                                              reinterpret_cast<void**>(_out_hp_ppvResource),
                                                                              *riidQueue.decoded_value,
                                                                              reinterpret_cast<void**>(_out_hp_ppvQueue));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
            AddObject(_out_p_ppvQueue, _out_hp_ppvQueue);
        }
        CheckReplayResult("ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12SwapChainAssistant_InsertImplicitSync(
    format::HandleId                            object_id,
    HRESULT                                     returnValue)
{
    auto replay_object = MapObject<ID3D12SwapChainAssistant>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->InsertImplicitSync();
    }
}

void DX12ReplayConsumer::Process_ID3D12LifetimeTracker_DestroyOwnedObject(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12DeviceChild*>*   pObject)
{
    auto replay_object = MapObject<ID3D12LifetimeTracker>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->DestroyOwnedObject(MapObject<ID3D12DeviceChild>(*pObject->GetPointer()));
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12LifetimeTracker_DestroyOwnedObject", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12StateObjectProperties_GetShaderIdentifier(
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

void DX12ReplayConsumer::Process_ID3D12StateObjectProperties_GetShaderStackSize(
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

void DX12ReplayConsumer::Process_ID3D12StateObjectProperties_GetPipelineStackSize(
    format::HandleId                            object_id,
    UINT64                                      returnValue)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPipelineStackSize();
    }
}

void DX12ReplayConsumer::Process_ID3D12StateObjectProperties_SetPipelineStackSize(
    format::HandleId                            object_id,
    UINT64                                      PipelineStackSizeInBytes)
{
    auto replay_object = MapObject<ID3D12StateObjectProperties>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetPipelineStackSize(PipelineStackSizeInBytes);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device5_CreateLifetimeTracker(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12LifetimeOwner*>* pOwner,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvTracker)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvTracker->IsNull()) ppvTracker->SetHandleLength(1);
        auto _out_p_ppvTracker    = ppvTracker->GetPointer();
        auto _out_hp_ppvTracker   = ppvTracker->GetHandlePointer();
        auto replay_result = replay_object->CreateLifetimeTracker(MapObject<ID3D12LifetimeOwner>(*pOwner->GetPointer()),
                                                                  *riid.decoded_value,
                                                                  reinterpret_cast<void**>(_out_hp_ppvTracker));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvTracker, _out_hp_ppvTracker);
        }
        CheckReplayResult("ID3D12Device5_CreateLifetimeTracker", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device5_RemoveDevice(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12Device5>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RemoveDevice();
    }
}

void DX12ReplayConsumer::Process_ID3D12Device5_EnumerateMetaCommands(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommands", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device5_EnumerateMetaCommandParameters(
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
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device5_EnumerateMetaCommandParameters", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device5_CreateMetaCommand(
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
        auto _out_p_ppMetaCommand    = ppMetaCommand->GetPointer();
        auto _out_hp_ppMetaCommand   = ppMetaCommand->GetHandlePointer();
        auto replay_result = replay_object->CreateMetaCommand(*CommandId.decoded_value,
                                                              NodeMask,
                                                              reinterpret_cast<void*>(pCreationParametersData),
                                                              CreationParametersDataSizeInBytes,
                                                              *riid.decoded_value,
                                                              reinterpret_cast<void**>(_out_hp_ppMetaCommand));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppMetaCommand, _out_hp_ppMetaCommand);
        }
        CheckReplayResult("ID3D12Device5_CreateMetaCommand", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device5_CreateStateObject(
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
        auto _out_p_ppStateObject    = ppStateObject->GetPointer();
        auto _out_hp_ppStateObject   = ppStateObject->GetHandlePointer();
        auto replay_result = replay_object->CreateStateObject(pDesc->GetPointer(),
                                                              *riid.decoded_value,
                                                              reinterpret_cast<void**>(_out_hp_ppStateObject));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppStateObject, _out_hp_ppStateObject);
        }
        CheckReplayResult("ID3D12Device5_CreateStateObject", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
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

void DX12ReplayConsumer::Process_ID3D12Device5_CheckDriverMatchingIdentifier(
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

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetAutoBreadcrumbsEnablement(Enablement);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetPageFaultEnablement(Enablement);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetWatsonDumpEnablement(Enablement);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
    format::HandleId                            object_id,
    D3D12_DRED_ENABLEMENT                       Enablement)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedDataSettings1>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetBreadcrumbContextEnablement(Enablement);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetAutoBreadcrumbsOutput(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPageFaultAllocationOutput(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetAutoBreadcrumbsOutput1(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput)
{
    auto replay_object = MapObject<ID3D12DeviceRemovedExtendedData1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetPageFaultAllocationOutput1(pOutput->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device6_SetBackgroundProcessingMode(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    D3D12_BACKGROUND_PROCESSING_MODE            Mode,
    D3D12_MEASUREMENTS_ACTION                   MeasurementsAction,
    format::HandleId                            hEventToSignalUponCompletion,
    PointerDecoder<BOOL>*                       pbFurtherMeasurementsDesired)
{
    auto replay_object = MapObject<ID3D12Device6>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->SetBackgroundProcessingMode(Mode,
                                                                        MeasurementsAction,
                                                                        MapHandle<HANDLE>(hEventToSignalUponCompletion),
                                                                        pbFurtherMeasurementsDesired->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3D12Device6_SetBackgroundProcessingMode", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12ProtectedResourceSession1_GetDesc1(
    format::HandleId                            object_id,
    Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 returnValue)
{
    auto replay_object = MapObject<ID3D12ProtectedResourceSession1>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1();
    }
}

void DX12ReplayConsumer::Process_ID3D12Device7_AddToStateObject(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
    HandlePointerDecoder<ID3D12StateObject*>*   pStateObjectToGrowFrom,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppNewStateObject)
{
    auto replay_object = MapObject<ID3D12Device7>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppNewStateObject->IsNull()) ppNewStateObject->SetHandleLength(1);
        auto _out_p_ppNewStateObject    = ppNewStateObject->GetPointer();
        auto _out_hp_ppNewStateObject   = ppNewStateObject->GetHandlePointer();
        auto replay_result = replay_object->AddToStateObject(pAddition->GetPointer(),
                                                             MapObject<ID3D12StateObject>(*pStateObjectToGrowFrom->GetPointer()),
                                                             *riid.decoded_value,
                                                             reinterpret_cast<void**>(_out_hp_ppNewStateObject));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppNewStateObject, _out_hp_ppNewStateObject);
        }
        CheckReplayResult("ID3D12Device7_AddToStateObject", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device7_CreateProtectedResourceSession1(
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
        auto _out_p_ppSession    = ppSession->GetPointer();
        auto _out_hp_ppSession   = ppSession->GetHandlePointer();
        auto replay_result = replay_object->CreateProtectedResourceSession1(pDesc->GetPointer(),
                                                                            *riid.decoded_value,
                                                                            reinterpret_cast<void**>(_out_hp_ppSession));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppSession, _out_hp_ppSession);
        }
        CheckReplayResult("ID3D12Device7_CreateProtectedResourceSession1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device8_GetResourceAllocationInfo2(
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

void DX12ReplayConsumer::Process_ID3D12Device8_CreateCommittedResource2(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
    D3D12_HEAP_FLAGS                            HeapFlags,
    StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
    D3D12_RESOURCE_STATES                       InitialResourceState,
    StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
    HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
    Decoded_GUID                                riidResource,
    HandlePointerDecoder<void*>*                ppvResource)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreateCommittedResource2(pHeapProperties->GetPointer(),
                                                                     HeapFlags,
                                                                     pDesc->GetPointer(),
                                                                     InitialResourceState,
                                                                     pOptimizedClearValue->GetPointer(),
                                                                     MapObject<ID3D12ProtectedResourceSession>(*pProtectedSession->GetPointer()),
                                                                     *riidResource.decoded_value,
                                                                     reinterpret_cast<void**>(_out_hp_ppvResource));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device8_CreateCommittedResource2", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device8_CreatePlacedResource1(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    HandlePointerDecoder<ID3D12Heap*>*          pHeap,
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
        if(!ppvResource->IsNull()) ppvResource->SetHandleLength(1);
        auto _out_p_ppvResource    = ppvResource->GetPointer();
        auto _out_hp_ppvResource   = ppvResource->GetHandlePointer();
        auto replay_result = replay_object->CreatePlacedResource1(MapObject<ID3D12Heap>(*pHeap->GetPointer()),
                                                                  HeapOffset,
                                                                  pDesc->GetPointer(),
                                                                  InitialState,
                                                                  pOptimizedClearValue->GetPointer(),
                                                                  *riid.decoded_value,
                                                                  reinterpret_cast<void**>(_out_hp_ppvResource));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvResource, _out_hp_ppvResource);
        }
        CheckReplayResult("ID3D12Device8_CreatePlacedResource1", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      pTargetedResource,
    HandlePointerDecoder<ID3D12Resource*>*      pFeedbackResource,
    Decoded_D3D12_CPU_DESCRIPTOR_HANDLE         DestDescriptor)
{
    auto replay_object = MapObject<ID3D12Device8>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->CreateSamplerFeedbackUnorderedAccessView(MapObject<ID3D12Resource>(*pTargetedResource->GetPointer()),
                                                                MapObject<ID3D12Resource>(*pFeedbackResource->GetPointer()),
                                                                *DestDescriptor.decoded_value);
    }
}

void DX12ReplayConsumer::Process_ID3D12Device8_GetCopyableFootprints1(
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

void DX12ReplayConsumer::Process_ID3D12Resource1_GetProtectedResourceSession(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppProtectedSession)
{
    auto replay_object = MapObject<ID3D12Resource1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppProtectedSession->IsNull()) ppProtectedSession->SetHandleLength(1);
        auto _out_p_ppProtectedSession    = ppProtectedSession->GetPointer();
        auto _out_hp_ppProtectedSession   = ppProtectedSession->GetHandlePointer();
        auto replay_result = replay_object->GetProtectedResourceSession(*riid.decoded_value,
                                                                        reinterpret_cast<void**>(_out_hp_ppProtectedSession));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppProtectedSession, _out_hp_ppProtectedSession);
        }
        CheckReplayResult("ID3D12Resource1_GetProtectedResourceSession", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12Resource2_GetDesc1(
    format::HandleId                            object_id,
    Decoded_D3D12_RESOURCE_DESC1                returnValue)
{
    auto replay_object = MapObject<ID3D12Resource2>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetDesc1();
    }
}

void DX12ReplayConsumer::Process_ID3D12Heap1_GetProtectedResourceSession(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppProtectedSession)
{
    auto replay_object = MapObject<ID3D12Heap1>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppProtectedSession->IsNull()) ppProtectedSession->SetHandleLength(1);
        auto _out_p_ppProtectedSession    = ppProtectedSession->GetPointer();
        auto _out_hp_ppProtectedSession   = ppProtectedSession->GetHandlePointer();
        auto replay_result = replay_object->GetProtectedResourceSession(*riid.decoded_value,
                                                                        reinterpret_cast<void**>(_out_hp_ppProtectedSession));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppProtectedSession, _out_hp_ppProtectedSession);
        }
        CheckReplayResult("ID3D12Heap1_GetProtectedResourceSession", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedResourceSession)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList3>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetProtectedResourceSession(MapObject<ID3D12ProtectedResourceSession>(*pProtectedResourceSession->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_BeginRenderPass(
    format::HandleId                            object_id,
    UINT                                        NumRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
    StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS                     Flags)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->BeginRenderPass(NumRenderTargets,
                                       pRenderTargets->GetPointer(),
                                       pDepthStencil->GetPointer(),
                                       Flags);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_EndRenderPass(
    format::HandleId                            object_id)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EndRenderPass();
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12MetaCommand*>*   pMetaCommand,
    PointerDecoder<uint8_t>*                    pInitializationParametersData,
    SIZE_T                                      InitializationParametersDataSizeInBytes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->InitializeMetaCommand(MapObject<ID3D12MetaCommand>(*pMetaCommand->GetPointer()),
                                             reinterpret_cast<void*>(pInitializationParametersData),
                                             InitializationParametersDataSizeInBytes);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12MetaCommand*>*   pMetaCommand,
    PointerDecoder<uint8_t>*                    pExecutionParametersData,
    SIZE_T                                      ExecutionParametersDataSizeInBytes)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->ExecuteMetaCommand(MapObject<ID3D12MetaCommand>(*pMetaCommand->GetPointer()),
                                          reinterpret_cast<void*>(pExecutionParametersData),
                                          ExecutionParametersDataSizeInBytes);
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_SetPipelineState1(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12StateObject*>*   pStateObject)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->SetPipelineState1(MapObject<ID3D12StateObject>(*pStateObject->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList4_DispatchRays(
    format::HandleId                            object_id,
    StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList4>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->DispatchRays(pDesc->GetPointer());
    }
}

void DX12ReplayConsumer::Process_ID3D12Tools_EnableShaderInstrumentation(
    format::HandleId                            object_id,
    BOOL                                        bEnable)
{
    auto replay_object = MapObject<ID3D12Tools>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->EnableShaderInstrumentation(bEnable);
    }
}

void DX12ReplayConsumer::Process_ID3D12Tools_ShaderInstrumentationEnabled(
    format::HandleId                            object_id,
    BOOL                                        returnValue)
{
    auto replay_object = MapObject<ID3D12Tools>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->ShaderInstrumentationEnabled();
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
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

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
    format::HandleId                            object_id,
    HandlePointerDecoder<ID3D12Resource*>*      shadingRateImage)
{
    auto replay_object = MapObject<ID3D12GraphicsCommandList5>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->RSSetShadingRateImage(MapObject<ID3D12Resource>(*shadingRateImage->GetPointer()));
    }
}

void DX12ReplayConsumer::Process_ID3D12GraphicsCommandList6_DispatchMesh(
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

void DX12ReplayConsumer::Process_ID3D10Blob_GetBufferPointer(
    format::HandleId                            object_id,
    uint64_t                                    returnValue)
{
    auto replay_object = MapObject<ID3D10Blob>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBufferPointer();
    }
}

void DX12ReplayConsumer::Process_ID3D10Blob_GetBufferSize(
    format::HandleId                            object_id,
    SIZE_T                                      returnValue)
{
    auto replay_object = MapObject<ID3D10Blob>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->GetBufferSize();
    }
}

void DX12ReplayConsumer::Process_ID3DDestructionNotifier_RegisterDestructionCallback(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    uint64_t                                    callbackFn,
    uint64_t                                    pData,
    PointerDecoder<UINT>*                       pCallbackID)
{
    auto replay_object = MapObject<ID3DDestructionNotifier>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->RegisterDestructionCallback(reinterpret_cast<PFN_DESTRUCTION_CALLBACK>(callbackFn),
                                                                        reinterpret_cast<void*>(pData),
                                                                        pCallbackID->GetPointer());
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3DDestructionNotifier_RegisterDestructionCallback", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    UINT                                        callbackID)
{
    auto replay_object = MapObject<ID3DDestructionNotifier>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_result = replay_object->UnregisterDestructionCallback(callbackID);
        if (SUCCEEDED(replay_result))
        {
        }
        CheckReplayResult("ID3DDestructionNotifier_UnregisterDestructionCallback", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IUnknown_QueryInterface(
    format::HandleId                            object_id,
    HRESULT                                     returnValue,
    Decoded_GUID                                riid,
    HandlePointerDecoder<void*>*                ppvObject)
{
    auto replay_object = MapObject<IUnknown>(object_id);
    if (replay_object != nullptr)
    {
        if(!ppvObject->IsNull()) ppvObject->SetHandleLength(1);
        auto _out_p_ppvObject    = ppvObject->GetPointer();
        auto _out_hp_ppvObject   = ppvObject->GetHandlePointer();
        auto replay_result = replay_object->QueryInterface(*riid.decoded_value,
                                                           reinterpret_cast<void**>(_out_hp_ppvObject));
        if (SUCCEEDED(replay_result))
        {
            AddObject(_out_p_ppvObject, _out_hp_ppvObject);
        }
        CheckReplayResult("IUnknown_QueryInterface", returnValue, replay_result);
    }
}

void DX12ReplayConsumer::Process_IUnknown_AddRef(
    format::HandleId                            object_id,
    ULONG                                       returnValue)
{
    auto replay_object = MapObject<IUnknown>(object_id);
    if (replay_object != nullptr)
    {
        replay_object->AddRef();
    }
}

void DX12ReplayConsumer::Process_IUnknown_Release(
    format::HandleId                            object_id,
    ULONG                                       returnValue)
{
    auto replay_object = MapObject<IUnknown>(object_id);
    if (replay_object != nullptr)
    {
        auto replay_count = replay_object->Release();
        if (replay_count == 0)
        {
            RemoveObject(object_id);
            GFXRECON_LOG_INFO("Object with ID %" PRIu64 " has been destroyed", object_id);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
