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
** This file is generated from dx12_api_call_encoders_body_generator.py.
**
*/

#include "generated/generated_dx12_api_call_encoders.h"
#include "generated/generated_dx12_command_list_util.h"
#include "encode/custom_dx12_array_size_2d.h"
#include "encode/custom_dx12_struct_encoders.h"
#include "encode/custom_dx12_command_list_util.h"

#include "encode/d3d12_capture_manager.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)


/*
** This part is generated from dxgi.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_CreateDXGIFactory(
    HRESULT return_value,
    REFIID riid,
    void** ppFactory)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_CreateDXGIFactory);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppFactory, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, riid, ppFactory);
    }
}

void Encode_CreateDXGIFactory1(
    HRESULT return_value,
    REFIID riid,
    void** ppFactory)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_CreateDXGIFactory1);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppFactory, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, riid, ppFactory);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_FRAME_STATISTICS& value)
{
    encoder->EncodeUInt32Value(value.PresentCount);
    encoder->EncodeUInt32Value(value.PresentRefreshCount);
    encoder->EncodeUInt32Value(value.SyncRefreshCount);
    EncodeStruct(encoder, value.SyncQPCTime);
    EncodeStruct(encoder, value.SyncGPUTime);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MAPPED_RECT& value)
{
    encoder->EncodeInt32Value(value.Pitch);
    encoder->EncodeUInt8Ptr(value.pBits);
}

void EncodeStruct(ParameterEncoder* encoder, const LUID& value)
{
    encoder->EncodeUInt32Value(value.LowPart);
    encoder->EncodeInt32Value(value.HighPart);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC& value)
{
    encoder->EncodeWString(value.Description);
    encoder->EncodeUInt32Value(value.VendorId);
    encoder->EncodeUInt32Value(value.DeviceId);
    encoder->EncodeUInt32Value(value.SubSysId);
    encoder->EncodeUInt32Value(value.Revision);
    encoder->EncodeSizeTValue(value.DedicatedVideoMemory);
    encoder->EncodeSizeTValue(value.DedicatedSystemMemory);
    encoder->EncodeSizeTValue(value.SharedSystemMemory);
    EncodeStruct(encoder, value.AdapterLuid);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTPUT_DESC& value)
{
    encoder->EncodeWString(value.DeviceName);
    EncodeStruct(encoder, value.DesktopCoordinates);
    encoder->EncodeInt32Value(value.AttachedToDesktop);
    encoder->EncodeEnumValue(value.Rotation);
    encoder->EncodeVoidPtr(value.Monitor);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SHARED_RESOURCE& value)
{
    encoder->EncodeVoidPtr(value.Handle);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SURFACE_DESC& value)
{
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeEnumValue(value.Format);
    EncodeStruct(encoder, value.SampleDesc);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_DESC& value)
{
    EncodeStruct(encoder, value.BufferDesc);
    EncodeStruct(encoder, value.SampleDesc);
    encoder->EncodeUInt32Value(value.BufferUsage);
    encoder->EncodeUInt32Value(value.BufferCount);
    encoder->EncodeVoidPtr(value.OutputWindow);
    encoder->EncodeInt32Value(value.Windowed);
    encoder->EncodeEnumValue(value.SwapEffect);
    encoder->EncodeUInt32Value(value.Flags);
}

void Encode_IDXGIObject_SetPrivateData(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID Name,
    UINT DataSize,
    const void* pData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIObject_SetPrivateData, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, Name);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeVoidArray(pData, DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIObject_SetPrivateDataInterface(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID Name,
    const IUnknown* pUnknown)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIObject_SetPrivateDataInterface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, Name);
        encoder->EncodeObjectValue(pUnknown);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIObject_GetPrivateData(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID Name,
    UINT* pDataSize,
    void* pData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIObject_GetPrivateData, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, Name);
        encoder->EncodeUInt32Ptr(pDataSize, omit_output_data);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? *pDataSize : 0, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIObject_GetParent(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppParent)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIObject_GetParent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppParent, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppParent, static_cast<IUnknown_Wrapper*>(wrapper));
    }
}

void Encode_IDXGIDeviceSubObject_GetDevice(
    IDXGIDeviceSubObject_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppDevice)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDeviceSubObject_GetDevice, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppDevice, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppDevice, static_cast<IUnknown_Wrapper*>(wrapper));
    }
}

void Encode_IDXGIResource_GetSharedHandle(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE* pSharedHandle)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtrPtr(pSharedHandle, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIResource_GetUsage(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_USAGE* pUsage)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIResource_GetUsage, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pUsage);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIResource_SetEvictionPriority(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    UINT EvictionPriority)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIResource_SetEvictionPriority, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(EvictionPriority);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIResource_GetEvictionPriority(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pEvictionPriority)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIResource_GetEvictionPriority, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pEvictionPriority, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIKeyedMutex_AcquireSync(
    IDXGIKeyedMutex_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Key,
    DWORD dwMilliseconds)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIKeyedMutex_AcquireSync, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Value(Key);
        encoder->EncodeUInt32Value(dwMilliseconds);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIKeyedMutex_ReleaseSync(
    IDXGIKeyedMutex_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Key)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIKeyedMutex_ReleaseSync, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Value(Key);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISurface_GetDesc(
    IDXGISurface_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SURFACE_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISurface_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISurface_Map(
    IDXGISurface_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MAPPED_RECT* pLockedRect,
    UINT MapFlags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISurface_Map, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pLockedRect, omit_output_data);
        encoder->EncodeUInt32Value(MapFlags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISurface_Unmap(
    IDXGISurface_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISurface_Unmap, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISurface1_GetDC(
    IDXGISurface1_Wrapper* wrapper,
    HRESULT return_value,
    BOOL Discard,
    HDC* phdc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISurface1_GetDC, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(Discard);
        encoder->EncodeVoidPtrPtr(phdc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISurface1_ReleaseDC(
    IDXGISurface1_Wrapper* wrapper,
    HRESULT return_value,
    RECT* pDirtyRect)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISurface1_ReleaseDC, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDirtyRect);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter_EnumOutputs(
    IDXGIAdapter_Wrapper* wrapper,
    HRESULT return_value,
    UINT Output,
    IDXGIOutput** ppOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter_EnumOutputs, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Output);
        encoder->EncodeObjectPtr(ppOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIOutput, reinterpret_cast<void**>(ppOutput), wrapper);
    }
}

void Encode_IDXGIAdapter_GetDesc(
    IDXGIAdapter_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter_CheckInterfaceSupport(
    IDXGIAdapter_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID InterfaceName,
    LARGE_INTEGER* pUMDVersion)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter_CheckInterfaceSupport, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, InterfaceName);
        EncodeStructPtr(encoder, pUMDVersion, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_GetDesc(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_OUTPUT_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_GetDisplayModeList(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_GetDisplayModeList, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(EnumFormat);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeUInt32Ptr(pNumModes, omit_output_data);
        EncodeStructArray(encoder, pDesc, ((pNumModes == nullptr) ? 0 : *pNumModes), omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_FindClosestMatchingMode(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MODE_DESC* pModeToMatch,
    DXGI_MODE_DESC* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_FindClosestMatchingMode, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pModeToMatch);
        EncodeStructPtr(encoder, pClosestMatch, omit_output_data);
        encoder->EncodeObjectValue(pConcernedDevice);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_WaitForVBlank(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_WaitForVBlank, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_TakeOwnership(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    BOOL Exclusive)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_TakeOwnership, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        encoder->EncodeInt32Value(Exclusive);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_ReleaseOwnership(
    IDXGIOutput_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_ReleaseOwnership, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_GetGammaControlCapabilities(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControlCapabilities, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pGammaCaps, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_SetGammaControl(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_GAMMA_CONTROL* pArray)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_SetGammaControl, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pArray);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_GetGammaControl(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_GAMMA_CONTROL* pArray)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControl, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pArray, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_SetDisplaySurface(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    IDXGISurface* pScanoutSurface)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_SetDisplaySurface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pScanoutSurface);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_GetDisplaySurfaceData(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    IDXGISurface* pDestination)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_GetDisplaySurfaceData, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDestination);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput_GetFrameStatistics(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FRAME_STATISTICS* pStats)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput_GetFrameStatistics, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pStats, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain_Present(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT SyncInterval,
    UINT Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_Present, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(SyncInterval);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain_GetBuffer(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT Buffer,
    REFIID riid,
    void** ppSurface)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_GetBuffer, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Buffer);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppSurface, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppSurface, wrapper);
    }
}

void Encode_IDXGISwapChain_SetFullscreenState(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    BOOL Fullscreen,
    IDXGIOutput* pTarget)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_SetFullscreenState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(Fullscreen);
        encoder->EncodeObjectValue(pTarget);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain_GetFullscreenState(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    BOOL* pFullscreen,
    IDXGIOutput** ppTarget)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_GetFullscreenState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Ptr(pFullscreen, omit_output_data);
        encoder->EncodeObjectPtr(ppTarget, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIOutput, reinterpret_cast<void**>(ppTarget), wrapper);
    }
}

void Encode_IDXGISwapChain_GetDesc(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SWAP_CHAIN_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain_ResizeBuffers(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT NewFormat,
    UINT SwapChainFlags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_ResizeBuffers, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(BufferCount);
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeEnumValue(NewFormat);
        encoder->EncodeUInt32Value(SwapChainFlags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain_ResizeTarget(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MODE_DESC* pNewTargetParameters)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_ResizeTarget, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pNewTargetParameters);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain_GetContainingOutput(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIOutput** ppOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_GetContainingOutput, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectPtr(ppOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIOutput, reinterpret_cast<void**>(ppOutput), wrapper);
    }
}

void Encode_IDXGISwapChain_GetFrameStatistics(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FRAME_STATISTICS* pStats)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_GetFrameStatistics, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pStats, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain_GetLastPresentCount(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pLastPresentCount)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain_GetLastPresentCount, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pLastPresentCount, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory_EnumAdapters(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    UINT Adapter,
    IDXGIAdapter** ppAdapter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory_EnumAdapters, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Adapter);
        encoder->EncodeObjectPtr(ppAdapter, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIAdapter, reinterpret_cast<void**>(ppAdapter), wrapper);
    }
}

void Encode_IDXGIFactory_MakeWindowAssociation(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    HWND WindowHandle,
    UINT Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(WindowHandle);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory_GetWindowAssociation(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    HWND* pWindowHandle)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtrPtr(pWindowHandle, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory_CreateSwapChain(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory_CreateSwapChain, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectPtr(ppSwapChain, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGISwapChain, reinterpret_cast<void**>(ppSwapChain), wrapper);
    }
}

void Encode_IDXGIFactory_CreateSoftwareAdapter(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    HMODULE Module,
    IDXGIAdapter** ppAdapter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(Module);
        encoder->EncodeObjectPtr(ppAdapter, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIAdapter, reinterpret_cast<void**>(ppAdapter), wrapper);
    }
}

void Encode_IDXGIDevice_GetAdapter(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIAdapter** pAdapter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice_GetAdapter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectPtr(pAdapter, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIAdapter, reinterpret_cast<void**>(pAdapter), wrapper);
    }
}

void Encode_IDXGIDevice_CreateSurface(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_SURFACE_DESC* pDesc,
    UINT NumSurfaces,
    DXGI_USAGE Usage,
    const DXGI_SHARED_RESOURCE* pSharedResource,
    IDXGISurface** ppSurface)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice_CreateSurface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeUInt32Value(NumSurfaces);
        encoder->EncodeUInt32Value(Usage);
        EncodeStructPtr(encoder, pSharedResource);
        encoder->EncodeObjectArray(ppSurface, NumSurfaces, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGISurface, reinterpret_cast<void**>(ppSurface), wrapper);
    }
}

void Encode_IDXGIDevice_QueryResourceResidency(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* const* ppResources,
    DXGI_RESIDENCY* pResidencyStatus,
    UINT NumResources)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice_QueryResourceResidency, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectArray(ppResources, NumResources);
        encoder->EncodeEnumArray(pResidencyStatus, NumResources, omit_output_data);
        encoder->EncodeUInt32Value(NumResources);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice_SetGPUThreadPriority(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    INT Priority)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice_SetGPUThreadPriority, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(Priority);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice_GetGPUThreadPriority(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    INT* pPriority)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice_GetGPUThreadPriority, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Ptr(pPriority, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC1& value)
{
    encoder->EncodeWString(value.Description);
    encoder->EncodeUInt32Value(value.VendorId);
    encoder->EncodeUInt32Value(value.DeviceId);
    encoder->EncodeUInt32Value(value.SubSysId);
    encoder->EncodeUInt32Value(value.Revision);
    encoder->EncodeSizeTValue(value.DedicatedVideoMemory);
    encoder->EncodeSizeTValue(value.DedicatedSystemMemory);
    encoder->EncodeSizeTValue(value.SharedSystemMemory);
    EncodeStruct(encoder, value.AdapterLuid);
    encoder->EncodeUInt32Value(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_DISPLAY_COLOR_SPACE& value)
{
    encoder->EncodeFloatArray(*value.PrimaryCoordinates, 16);
    encoder->EncodeFloatArray(*value.WhitePoints, 32);
}

void Encode_IDXGIFactory1_EnumAdapters1(
    IDXGIFactory1_Wrapper* wrapper,
    HRESULT return_value,
    UINT Adapter,
    IDXGIAdapter1** ppAdapter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory1_EnumAdapters1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Adapter);
        encoder->EncodeObjectPtr(ppAdapter, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIAdapter1, reinterpret_cast<void**>(ppAdapter), wrapper);
    }
}

void Encode_IDXGIFactory1_IsCurrent(
    IDXGIFactory1_Wrapper* wrapper,
    BOOL return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory1_IsCurrent, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter1_GetDesc1(
    IDXGIAdapter1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC1* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter1_GetDesc1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice1_SetMaximumFrameLatency(
    IDXGIDevice1_Wrapper* wrapper,
    HRESULT return_value,
    UINT MaxLatency)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice1_SetMaximumFrameLatency, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(MaxLatency);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice1_GetMaximumFrameLatency(
    IDXGIDevice1_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pMaxLatency)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice1_GetMaximumFrameLatency, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pMaxLatency, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_IDXGIDisplayControl_IsStereoEnabled(
    IDXGIDisplayControl_Wrapper* wrapper,
    BOOL return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDisplayControl_IsStereoEnabled, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDisplayControl_SetStereoEnabled(
    IDXGIDisplayControl_Wrapper* wrapper,
    BOOL enabled)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDisplayControl_SetStereoEnabled, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(enabled);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_MOVE_RECT& value)
{
    EncodeStruct(encoder, value.SourcePoint);
    EncodeStruct(encoder, value.DestinationRect);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_DESC& value)
{
    EncodeStruct(encoder, value.ModeDesc);
    encoder->EncodeEnumValue(value.Rotation);
    encoder->EncodeInt32Value(value.DesktopImageInSystemMemory);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_POINTER_POSITION& value)
{
    EncodeStruct(encoder, value.Position);
    encoder->EncodeInt32Value(value.Visible);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_POINTER_SHAPE_INFO& value)
{
    encoder->EncodeUInt32Value(value.Type);
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeUInt32Value(value.Pitch);
    EncodeStruct(encoder, value.HotSpot);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_FRAME_INFO& value)
{
    EncodeStruct(encoder, value.LastPresentTime);
    EncodeStruct(encoder, value.LastMouseUpdateTime);
    encoder->EncodeUInt32Value(value.AccumulatedFrames);
    encoder->EncodeInt32Value(value.RectsCoalesced);
    encoder->EncodeInt32Value(value.ProtectedContentMaskedOut);
    EncodeStruct(encoder, value.PointerPosition);
    encoder->EncodeUInt32Value(value.TotalMetadataBufferSize);
    encoder->EncodeUInt32Value(value.PointerShapeBufferSize);
}

void Encode_IDXGIOutputDuplication_GetDesc(
    IDXGIOutputDuplication_Wrapper* wrapper,
    DXGI_OUTDUPL_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutputDuplication_AcquireNextFrame(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT TimeoutInMilliseconds,
    DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
    IDXGIResource** ppDesktopResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_AcquireNextFrame, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(TimeoutInMilliseconds);
        EncodeStructPtr(encoder, pFrameInfo, omit_output_data);
        encoder->EncodeObjectPtr(ppDesktopResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIResource, reinterpret_cast<void**>(ppDesktopResource), wrapper);
    }
}

void Encode_IDXGIOutputDuplication_GetFrameDirtyRects(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT DirtyRectsBufferSize,
    RECT* pDirtyRectsBuffer,
    UINT* pDirtyRectsBufferSizeRequired)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(DirtyRectsBufferSize);
        EncodeStructArray(encoder, pDirtyRectsBuffer, DirtyRectsBufferSize/sizeof tagRECT, omit_output_data);
        encoder->EncodeUInt32Ptr(pDirtyRectsBufferSizeRequired, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutputDuplication_GetFrameMoveRects(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT MoveRectsBufferSize,
    DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
    UINT* pMoveRectsBufferSizeRequired)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameMoveRects, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(MoveRectsBufferSize);
        EncodeStructArray(encoder, pMoveRectBuffer, MoveRectsBufferSize/sizeof DXGI_OUTDUPL_MOVE_RECT, omit_output_data);
        encoder->EncodeUInt32Ptr(pMoveRectsBufferSizeRequired, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutputDuplication_GetFramePointerShape(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT PointerShapeBufferSize,
    void* pPointerShapeBuffer,
    UINT* pPointerShapeBufferSizeRequired,
    DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFramePointerShape, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(PointerShapeBufferSize);
        encoder->EncodeVoidArray(pPointerShapeBuffer, PointerShapeBufferSize, omit_output_data);
        encoder->EncodeUInt32Ptr(pPointerShapeBufferSizeRequired, omit_output_data);
        EncodeStructPtr(encoder, pPointerShapeInfo, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutputDuplication_MapDesktopSurface(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MAPPED_RECT* pLockedRect)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_MapDesktopSurface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pLockedRect, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutputDuplication_UnMapDesktopSurface(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutputDuplication_ReleaseFrame(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutputDuplication_ReleaseFrame, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISurface2_GetResource(
    IDXGISurface2_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppParentResource,
    UINT* pSubresourceIndex)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISurface2_GetResource, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppParentResource, omit_output_data);
        encoder->EncodeUInt32Ptr(pSubresourceIndex, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppParentResource, wrapper);
    }
}

void Encode_IDXGIResource1_CreateSubresourceSurface(
    IDXGIResource1_Wrapper* wrapper,
    HRESULT return_value,
    UINT index,
    IDXGISurface2** ppSurface)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIResource1_CreateSubresourceSurface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(index);
        encoder->EncodeObjectPtr(ppSurface, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGISurface2, reinterpret_cast<void**>(ppSurface), wrapper);
    }
}

void Encode_IDXGIResource1_CreateSharedHandle(
    IDXGIResource1_Wrapper* wrapper,
    HRESULT return_value,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD dwAccess,
    LPCWSTR lpName,
    HANDLE* pHandle)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pAttributes);
        encoder->EncodeUInt32Value(dwAccess);
        encoder->EncodeWString(lpName);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice2_OfferResources(
    IDXGIDevice2_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice2_OfferResources, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumResources);
        encoder->EncodeObjectArray(ppResources, NumResources);
        encoder->EncodeEnumValue(Priority);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice2_ReclaimResources(
    IDXGIDevice2_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    BOOL* pDiscarded)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice2_ReclaimResources, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumResources);
        encoder->EncodeObjectArray(ppResources, NumResources);
        encoder->EncodeInt32Array(pDiscarded, NumResources, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice2_EnqueueSetEvent(
    IDXGIDevice2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MODE_DESC1& value)
{
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    EncodeStruct(encoder, value.RefreshRate);
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ScanlineOrdering);
    encoder->EncodeEnumValue(value.Scaling);
    encoder->EncodeInt32Value(value.Stereo);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_DESC1& value)
{
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeInt32Value(value.Stereo);
    EncodeStruct(encoder, value.SampleDesc);
    encoder->EncodeUInt32Value(value.BufferUsage);
    encoder->EncodeUInt32Value(value.BufferCount);
    encoder->EncodeEnumValue(value.Scaling);
    encoder->EncodeEnumValue(value.SwapEffect);
    encoder->EncodeEnumValue(value.AlphaMode);
    encoder->EncodeUInt32Value(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& value)
{
    EncodeStruct(encoder, value.RefreshRate);
    encoder->EncodeEnumValue(value.ScanlineOrdering);
    encoder->EncodeEnumValue(value.Scaling);
    encoder->EncodeInt32Value(value.Windowed);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_PRESENT_PARAMETERS& value)
{
    encoder->EncodeUInt32Value(value.DirtyRectsCount);
    EncodeStructArray(encoder, value.pDirtyRects, value.DirtyRectsCount);
    EncodeStructPtr(encoder, value.pScrollRect);
    EncodeStructPtr(encoder, value.pScrollOffset);
}

void Encode_IDXGISwapChain1_GetDesc1(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SWAP_CHAIN_DESC1* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_GetDesc1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_GetFullscreenDesc(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_GetFullscreenDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_GetHwnd(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    HWND* pHwnd)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtrPtr(pHwnd, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_GetCoreWindow(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    REFIID refiid,
    void** ppUnk)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_GetCoreWindow, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, refiid);
        encoder->EncodeObjectPtr(ppUnk, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, refiid, ppUnk, wrapper);
    }
}

void Encode_IDXGISwapChain1_Present1(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    UINT SyncInterval,
    UINT PresentFlags,
    const DXGI_PRESENT_PARAMETERS* pPresentParameters)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_Present1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(SyncInterval);
        encoder->EncodeUInt32Value(PresentFlags);
        EncodeStructPtr(encoder, pPresentParameters);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_IsTemporaryMonoSupported(
    IDXGISwapChain1_Wrapper* wrapper,
    BOOL return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_GetRestrictToOutput(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIOutput** ppRestrictToOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_GetRestrictToOutput, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectPtr(ppRestrictToOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIOutput, reinterpret_cast<void**>(ppRestrictToOutput), wrapper);
    }
}

void Encode_IDXGISwapChain1_SetBackgroundColor(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_RGBA* pColor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_SetBackgroundColor, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pColor);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_GetBackgroundColor(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_RGBA* pColor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_GetBackgroundColor, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pColor, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_SetRotation(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MODE_ROTATION Rotation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_SetRotation, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Rotation);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain1_GetRotation(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MODE_ROTATION* pRotation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain1_GetRotation, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumPtr(pRotation, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_IsWindowedStereoEnabled(
    IDXGIFactory2_Wrapper* wrapper,
    BOOL return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_IsWindowedStereoEnabled, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_CreateSwapChainForHwnd(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    HWND hWnd,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        encoder->EncodeVoidPtr(hWnd);
        EncodeStructPtr(encoder, pDesc);
        EncodeStructPtr(encoder, pFullscreenDesc);
        encoder->EncodeObjectValue(pRestrictToOutput);
        encoder->EncodeObjectPtr(ppSwapChain, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), wrapper);
    }
}

void Encode_IDXGIFactory2_CreateSwapChainForCoreWindow(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    IUnknown* pWindow,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        encoder->EncodeObjectValue(pWindow);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectValue(pRestrictToOutput);
        encoder->EncodeObjectPtr(ppSwapChain, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), wrapper);
    }
}

void Encode_IDXGIFactory2_GetSharedResourceAdapterLuid(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hResource,
    LUID* pLuid)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hResource);
        EncodeStructPtr(encoder, pLuid, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_RegisterStereoStatusWindow(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(WindowHandle);
        encoder->EncodeUInt32Value(wMsg);
        encoder->EncodeUInt32Ptr(pdwCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_RegisterStereoStatusEvent(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_UnregisterStereoStatus(
    IDXGIFactory2_Wrapper* wrapper,
    DWORD dwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterStereoStatus, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_RegisterOcclusionStatusWindow(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(WindowHandle);
        encoder->EncodeUInt32Value(wMsg);
        encoder->EncodeUInt32Ptr(pdwCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_RegisterOcclusionStatusEvent(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_UnregisterOcclusionStatus(
    IDXGIFactory2_Wrapper* wrapper,
    DWORD dwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterOcclusionStatus, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory2_CreateSwapChainForComposition(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForComposition, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectValue(pRestrictToOutput);
        encoder->EncodeObjectPtr(ppSwapChain, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), wrapper);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC2& value)
{
    encoder->EncodeWString(value.Description);
    encoder->EncodeUInt32Value(value.VendorId);
    encoder->EncodeUInt32Value(value.DeviceId);
    encoder->EncodeUInt32Value(value.SubSysId);
    encoder->EncodeUInt32Value(value.Revision);
    encoder->EncodeSizeTValue(value.DedicatedVideoMemory);
    encoder->EncodeSizeTValue(value.DedicatedSystemMemory);
    encoder->EncodeSizeTValue(value.SharedSystemMemory);
    EncodeStruct(encoder, value.AdapterLuid);
    encoder->EncodeUInt32Value(value.Flags);
    encoder->EncodeEnumValue(value.GraphicsPreemptionGranularity);
    encoder->EncodeEnumValue(value.ComputePreemptionGranularity);
}

void Encode_IDXGIAdapter2_GetDesc2(
    IDXGIAdapter2_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC2* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter2_GetDesc2, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput1_GetDisplayModeList1(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC1* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplayModeList1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(EnumFormat);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeUInt32Ptr(pNumModes, omit_output_data);
        EncodeStructArray(encoder, pDesc, ((pNumModes == nullptr) ? 0 : *pNumModes), omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput1_FindClosestMatchingMode1(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MODE_DESC1* pModeToMatch,
    DXGI_MODE_DESC1* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput1_FindClosestMatchingMode1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pModeToMatch);
        EncodeStructPtr(encoder, pClosestMatch, omit_output_data);
        encoder->EncodeObjectValue(pConcernedDevice);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput1_GetDisplaySurfaceData1(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIResource* pDestination)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplaySurfaceData1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDestination);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput1_DuplicateOutput(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    IDXGIOutputDuplication** ppOutputDuplication)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput1_DuplicateOutput, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        encoder->EncodeObjectPtr(ppOutputDuplication, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIOutputDuplication, reinterpret_cast<void**>(ppOutputDuplication), wrapper);
    }
}


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_CreateDXGIFactory2(
    HRESULT return_value,
    UINT Flags,
    REFIID riid,
    void** ppFactory)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_CreateDXGIFactory2);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Flags);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppFactory, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, riid, ppFactory);
    }
}

void Encode_DXGIGetDebugInterface1(
    HRESULT return_value,
    UINT Flags,
    REFIID riid,
    void** pDebug)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_DXGIGetDebugInterface1);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Flags);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(pDebug, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, riid, pDebug);
    }
}

void Encode_IDXGIDevice3_Trim(
    IDXGIDevice3_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice3_Trim, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MATRIX_3X2_F& value)
{
    encoder->EncodeFloatValue(value._11);
    encoder->EncodeFloatValue(value._12);
    encoder->EncodeFloatValue(value._21);
    encoder->EncodeFloatValue(value._22);
    encoder->EncodeFloatValue(value._31);
    encoder->EncodeFloatValue(value._32);
}

void Encode_IDXGISwapChain2_SetSourceSize(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT Width,
    UINT Height)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain2_SetSourceSize, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain2_GetSourceSize(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pWidth,
    UINT* pHeight)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain2_GetSourceSize, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pWidth, omit_output_data);
        encoder->EncodeUInt32Ptr(pHeight, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain2_SetMaximumFrameLatency(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT MaxLatency)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain2_SetMaximumFrameLatency, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(MaxLatency);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain2_GetMaximumFrameLatency(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pMaxLatency)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain2_GetMaximumFrameLatency, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pMaxLatency, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    IDXGISwapChain2_Wrapper* wrapper,
    HANDLE return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeVoidPtr(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain2_SetMatrixTransform(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MATRIX_3X2_F* pMatrix)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain2_SetMatrixTransform, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pMatrix);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain2_GetMatrixTransform(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MATRIX_3X2_F* pMatrix)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain2_GetMatrixTransform, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pMatrix, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput2_SupportsOverlays(
    IDXGIOutput2_Wrapper* wrapper,
    BOOL return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput2_SupportsOverlays, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory3_GetCreationFlags(
    IDXGIFactory3_Wrapper* wrapper,
    UINT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory3_GetCreationFlags, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_DECODE_SWAP_CHAIN_DESC& value)
{
    encoder->EncodeUInt32Value(value.Flags);
}

void Encode_IDXGIDecodeSwapChain_PresentBuffer(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT BufferToPresent,
    UINT SyncInterval,
    UINT Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_PresentBuffer, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(BufferToPresent);
        encoder->EncodeUInt32Value(SyncInterval);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_SetSourceRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    const RECT* pRect)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetSourceRect, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pRect);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_SetTargetRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    const RECT* pRect)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetTargetRect, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pRect);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_SetDestSize(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT Width,
    UINT Height)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetDestSize, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_GetSourceRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    RECT* pRect)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetSourceRect, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pRect, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_GetTargetRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    RECT* pRect)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetTargetRect, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pRect, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_GetDestSize(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pWidth,
    UINT* pHeight)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetDestSize, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pWidth, omit_output_data);
        encoder->EncodeUInt32Ptr(pHeight, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_SetColorSpace(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetColorSpace, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(ColorSpace);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDecodeSwapChain_GetColorSpace(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetColorSpace, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
    IDXGIFactoryMedia_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    HANDLE hSurface,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        encoder->EncodeVoidPtr(hSurface);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectValue(pRestrictToOutput);
        encoder->EncodeObjectPtr(ppSwapChain, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), wrapper);
    }
}

void Encode_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
    IDXGIFactoryMedia_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    HANDLE hSurface,
    DXGI_DECODE_SWAP_CHAIN_DESC* pDesc,
    IDXGIResource* pYuvDecodeBuffers,
    IDXGIOutput* pRestrictToOutput,
    IDXGIDecodeSwapChain** ppSwapChain)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        encoder->EncodeVoidPtr(hSurface);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectValue(pYuvDecodeBuffers);
        encoder->EncodeObjectValue(pRestrictToOutput);
        encoder->EncodeObjectPtr(ppSwapChain, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIDecodeSwapChain, reinterpret_cast<void**>(ppSwapChain), wrapper);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_FRAME_STATISTICS_MEDIA& value)
{
    encoder->EncodeUInt32Value(value.PresentCount);
    encoder->EncodeUInt32Value(value.PresentRefreshCount);
    encoder->EncodeUInt32Value(value.SyncRefreshCount);
    EncodeStruct(encoder, value.SyncQPCTime);
    EncodeStruct(encoder, value.SyncGPUTime);
    encoder->EncodeEnumValue(value.CompositionMode);
    encoder->EncodeUInt32Value(value.ApprovedPresentDuration);
}

void Encode_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    IDXGISwapChainMedia_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FRAME_STATISTICS_MEDIA* pStats)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pStats, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChainMedia_SetPresentDuration(
    IDXGISwapChainMedia_Wrapper* wrapper,
    HRESULT return_value,
    UINT Duration)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChainMedia_SetPresentDuration, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Duration);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChainMedia_CheckPresentDurationSupport(
    IDXGISwapChainMedia_Wrapper* wrapper,
    HRESULT return_value,
    UINT DesiredPresentDuration,
    UINT* pClosestSmallerPresentDuration,
    UINT* pClosestLargerPresentDuration)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(DesiredPresentDuration);
        encoder->EncodeUInt32Ptr(pClosestSmallerPresentDuration, omit_output_data);
        encoder->EncodeUInt32Ptr(pClosestLargerPresentDuration, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput3_CheckOverlaySupport(
    IDXGIOutput3_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT EnumFormat,
    IUnknown* pConcernedDevice,
    UINT* pFlags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput3_CheckOverlaySupport, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(EnumFormat);
        encoder->EncodeObjectValue(pConcernedDevice);
        encoder->EncodeUInt32Ptr(pFlags, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_IDXGISwapChain3_GetCurrentBackBufferIndex(
    IDXGISwapChain3_Wrapper* wrapper,
    UINT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain3_CheckColorSpaceSupport(
    IDXGISwapChain3_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    UINT* pColorSpaceSupport)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain3_CheckColorSpaceSupport, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(ColorSpace);
        encoder->EncodeUInt32Ptr(pColorSpaceSupport, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain3_SetColorSpace1(
    IDXGISwapChain3_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain3_SetColorSpace1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(ColorSpace);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGISwapChain3_ResizeBuffers1(
    IDXGISwapChain3_Wrapper* wrapper,
    HRESULT return_value,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT Format,
    UINT SwapChainFlags,
    const UINT* pCreationNodeMask,
    IUnknown* const* ppPresentQueue)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain3_ResizeBuffers1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(BufferCount);
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeEnumValue(Format);
        encoder->EncodeUInt32Value(SwapChainFlags);
        encoder->EncodeUInt32Array(pCreationNodeMask, BufferCount);
        encoder->EncodeObjectArray(ppPresentQueue, BufferCount);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput4_CheckOverlayColorSpaceSupport(
    IDXGIOutput4_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT Format,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    IUnknown* pConcernedDevice,
    UINT* pFlags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Format);
        encoder->EncodeEnumValue(ColorSpace);
        encoder->EncodeObjectValue(pConcernedDevice);
        encoder->EncodeUInt32Ptr(pFlags, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory4_EnumAdapterByLuid(
    IDXGIFactory4_Wrapper* wrapper,
    HRESULT return_value,
    LUID AdapterLuid,
    REFIID riid,
    void** ppvAdapter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory4_EnumAdapterByLuid, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, AdapterLuid);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvAdapter, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvAdapter, wrapper);
    }
}

void Encode_IDXGIFactory4_EnumWarpAdapter(
    IDXGIFactory4_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppvAdapter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory4_EnumWarpAdapter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvAdapter, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvAdapter, wrapper);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_QUERY_VIDEO_MEMORY_INFO& value)
{
    encoder->EncodeUInt64Value(value.Budget);
    encoder->EncodeUInt64Value(value.CurrentUsage);
    encoder->EncodeUInt64Value(value.AvailableForReservation);
    encoder->EncodeUInt64Value(value.CurrentReservation);
}

void Encode_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
    IDXGIAdapter3_Wrapper* wrapper,
    DWORD dwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter3_QueryVideoMemoryInfo(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NodeIndex);
        encoder->EncodeEnumValue(MemorySegmentGroup);
        EncodeStructPtr(encoder, pVideoMemoryInfo, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter3_SetVideoMemoryReservation(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    UINT64 Reservation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter3_SetVideoMemoryReservation, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NodeIndex);
        encoder->EncodeEnumValue(MemorySegmentGroup);
        encoder->EncodeUInt64Value(Reservation);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
    IDXGIAdapter3_Wrapper* wrapper,
    DWORD dwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_IDXGIOutput5_DuplicateOutput1(
    IDXGIOutput5_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    UINT Flags,
    UINT SupportedFormatsCount,
    const DXGI_FORMAT* pSupportedFormats,
    IDXGIOutputDuplication** ppOutputDuplication)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput5_DuplicateOutput1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pDevice);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeUInt32Value(SupportedFormatsCount);
        encoder->EncodeEnumArray(pSupportedFormats, SupportedFormatsCount);
        encoder->EncodeObjectPtr(ppOutputDuplication, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_IDXGIOutputDuplication, reinterpret_cast<void**>(ppOutputDuplication), wrapper);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_HDR_METADATA_HDR10& value)
{
    encoder->EncodeUInt16Array(value.RedPrimary, 2);
    encoder->EncodeUInt16Array(value.GreenPrimary, 2);
    encoder->EncodeUInt16Array(value.BluePrimary, 2);
    encoder->EncodeUInt16Array(value.WhitePoint, 2);
    encoder->EncodeUInt32Value(value.MaxMasteringLuminance);
    encoder->EncodeUInt32Value(value.MinMasteringLuminance);
    encoder->EncodeUInt16Value(value.MaxContentLightLevel);
    encoder->EncodeUInt16Value(value.MaxFrameAverageLightLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_HDR_METADATA_HDR10PLUS& value)
{
    encoder->EncodeUInt8Array(value.Data, 72);
}

void Encode_IDXGISwapChain4_SetHDRMetaData(
    IDXGISwapChain4_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_HDR_METADATA_TYPE Type,
    UINT Size,
    void* pMetaData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGISwapChain4_SetHDRMetaData, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(Size);
        encoder->EncodeVoidArray(pMetaData, Size);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice4_OfferResources1(
    IDXGIDevice4_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority,
    UINT Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice4_OfferResources1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumResources);
        encoder->EncodeObjectArray(ppResources, NumResources);
        encoder->EncodeEnumValue(Priority);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIDevice4_ReclaimResources1(
    IDXGIDevice4_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_RECLAIM_RESOURCE_RESULTS* pResults)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIDevice4_ReclaimResources1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumResources);
        encoder->EncodeObjectArray(ppResources, NumResources);
        encoder->EncodeEnumArray(pResults, NumResources, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_DXGIDeclareAdapterRemovalSupport(
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_DXGIDeclareAdapterRemovalSupport);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC3& value)
{
    encoder->EncodeWString(value.Description);
    encoder->EncodeUInt32Value(value.VendorId);
    encoder->EncodeUInt32Value(value.DeviceId);
    encoder->EncodeUInt32Value(value.SubSysId);
    encoder->EncodeUInt32Value(value.Revision);
    encoder->EncodeSizeTValue(value.DedicatedVideoMemory);
    encoder->EncodeSizeTValue(value.DedicatedSystemMemory);
    encoder->EncodeSizeTValue(value.SharedSystemMemory);
    EncodeStruct(encoder, value.AdapterLuid);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeEnumValue(value.GraphicsPreemptionGranularity);
    encoder->EncodeEnumValue(value.ComputePreemptionGranularity);
}

void Encode_IDXGIAdapter4_GetDesc3(
    IDXGIAdapter4_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC3* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIAdapter4_GetDesc3, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTPUT_DESC1& value)
{
    encoder->EncodeWString(value.DeviceName);
    EncodeStruct(encoder, value.DesktopCoordinates);
    encoder->EncodeInt32Value(value.AttachedToDesktop);
    encoder->EncodeEnumValue(value.Rotation);
    encoder->EncodeVoidPtr(value.Monitor);
    encoder->EncodeUInt32Value(value.BitsPerColor);
    encoder->EncodeEnumValue(value.ColorSpace);
    encoder->EncodeFloatArray(value.RedPrimary, 2);
    encoder->EncodeFloatArray(value.GreenPrimary, 2);
    encoder->EncodeFloatArray(value.BluePrimary, 2);
    encoder->EncodeFloatArray(value.WhitePoint, 2);
    encoder->EncodeFloatValue(value.MinLuminance);
    encoder->EncodeFloatValue(value.MaxLuminance);
    encoder->EncodeFloatValue(value.MaxFullFrameLuminance);
}

void Encode_IDXGIOutput6_GetDesc1(
    IDXGIOutput6_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_OUTPUT_DESC1* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput6_GetDesc1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIOutput6_CheckHardwareCompositionSupport(
    IDXGIOutput6_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pFlags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pFlags, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory6_EnumAdapterByGpuPreference(
    IDXGIFactory6_Wrapper* wrapper,
    HRESULT return_value,
    UINT Adapter,
    DXGI_GPU_PREFERENCE GpuPreference,
    REFIID riid,
    void** ppvAdapter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Adapter);
        encoder->EncodeEnumValue(GpuPreference);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvAdapter, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvAdapter, wrapper);
    }
}

void Encode_IDXGIFactory7_RegisterAdaptersChangedEvent(
    IDXGIFactory7_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    IDXGIFactory7_Wrapper* wrapper,
    HRESULT return_value,
    DWORD dwCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(dwCookie);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from dxgicommon.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const DXGI_RATIONAL& value)
{
    encoder->EncodeUInt32Value(value.Numerator);
    encoder->EncodeUInt32Value(value.Denominator);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SAMPLE_DESC& value)
{
    encoder->EncodeUInt32Value(value.Count);
    encoder->EncodeUInt32Value(value.Quality);
}


/*
** This part is generated from dxgiformat.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from dxgitype.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const DXGI_RGB& value)
{
    encoder->EncodeFloatValue(value.Red);
    encoder->EncodeFloatValue(value.Green);
    encoder->EncodeFloatValue(value.Blue);
}

void EncodeStruct(ParameterEncoder* encoder, const D3DCOLORVALUE& value)
{
    encoder->EncodeFloatValue(value.r);
    encoder->EncodeFloatValue(value.g);
    encoder->EncodeFloatValue(value.b);
    encoder->EncodeFloatValue(value.a);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_GAMMA_CONTROL& value)
{
    EncodeStruct(encoder, value.Scale);
    EncodeStruct(encoder, value.Offset);
    EncodeStructArray(encoder, value.GammaCurve, 1025);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_GAMMA_CONTROL_CAPABILITIES& value)
{
    encoder->EncodeInt32Value(value.ScaleAndOffsetSupported);
    encoder->EncodeFloatValue(value.MaxConvertedValue);
    encoder->EncodeFloatValue(value.MinConvertedValue);
    encoder->EncodeUInt32Value(value.NumGammaControlPoints);
    encoder->EncodeFloatArray(value.ControlPointPositions, 1025);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MODE_DESC& value)
{
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    EncodeStruct(encoder, value.RefreshRate);
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ScanlineOrdering);
    encoder->EncodeEnumValue(value.Scaling);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_JPEG_DC_HUFFMAN_TABLE& value)
{
    encoder->EncodeUInt8Array(value.CodeCounts, 12);
    encoder->EncodeUInt8Array(value.CodeValues, 12);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_JPEG_AC_HUFFMAN_TABLE& value)
{
    encoder->EncodeUInt8Array(value.CodeCounts, 16);
    encoder->EncodeUInt8Array(value.CodeValues, 162);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_JPEG_QUANTIZATION_TABLE& value)
{
    encoder->EncodeUInt8Array(value.Elements, 64);
}


/*
** This part is generated from d3d12.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_D3D12SerializeRootSignature(
    HRESULT return_value,
    const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION Version,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob)
{
    auto encoder = D3D12CaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_D3D12SerializeRootSignature);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pRootSignature);
        encoder->EncodeEnumValue(Version);
        encoder->EncodeObjectPtr(ppBlob, omit_output_data);
        encoder->EncodeObjectPtr(ppErrorBlob, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void Encode_D3D12CreateRootSignatureDeserializer(
    HRESULT return_value,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_D3D12CreateRootSignatureDeserializer);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidArray(pSrcData, SrcDataSizeInBytes);
        encoder->EncodeSizeTValue(SrcDataSizeInBytes);
        EncodeStruct(encoder, pRootSignatureDeserializerInterface);
        encoder->EncodeObjectPtr(ppRootSignatureDeserializer, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
    }
}

void Encode_D3D12SerializeVersionedRootSignature(
    HRESULT return_value,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob)
{
    auto encoder = D3D12CaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_D3D12SerializeVersionedRootSignature);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pRootSignature);
        encoder->EncodeObjectPtr(ppBlob, omit_output_data);
        encoder->EncodeObjectPtr(ppErrorBlob, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void Encode_D3D12CreateVersionedRootSignatureDeserializer(
    HRESULT return_value,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializer);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidArray(pSrcData, SrcDataSizeInBytes);
        encoder->EncodeSizeTValue(SrcDataSizeInBytes);
        EncodeStruct(encoder, pRootSignatureDeserializerInterface);
        encoder->EncodeObjectPtr(ppRootSignatureDeserializer, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
    }
}

void Encode_D3D12CreateDevice(
    HRESULT return_value,
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_D3D12CreateDevice);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pAdapter);
        encoder->EncodeEnumValue(MinimumFeatureLevel);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppDevice, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, riid, ppDevice);
    }
}

void Encode_D3D12GetDebugInterface(
    HRESULT return_value,
    REFIID riid,
    void** ppvDebug)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_D3D12GetDebugInterface);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvDebug, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, riid, ppvDebug);
    }
}

void Encode_D3D12EnableExperimentalFeatures(
    HRESULT return_value,
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginApiCallCapture(format::ApiCallId::ApiCall_D3D12EnableExperimentalFeatures);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumFeatures);
        EncodeStructArray(encoder, pIIDs, NumFeatures);
        encoder->EncodeVoidArray(pConfigurationStructs, NumFeatures);
        encoder->EncodeUInt32Array(pConfigurationStructSizes, NumFeatures);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndApiCallCapture();
    }
}

void Encode_D3D12GetInterface(
    HRESULT return_value,
    REFCLSID rclsid,
    REFIID riid,
    void** ppvDebug)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_D3D12GetInterface);
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, rclsid);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvDebug, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateApiCallCapture(return_value, riid, ppvDebug);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_QUEUE_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeInt32Value(value.Priority);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.NodeMask);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INPUT_ELEMENT_DESC& value)
{
    encoder->EncodeString(value.SemanticName);
    encoder->EncodeUInt32Value(value.SemanticIndex);
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeUInt32Value(value.InputSlot);
    encoder->EncodeUInt32Value(value.AlignedByteOffset);
    encoder->EncodeEnumValue(value.InputSlotClass);
    encoder->EncodeUInt32Value(value.InstanceDataStepRate);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SO_DECLARATION_ENTRY& value)
{
    encoder->EncodeUInt32Value(value.Stream);
    encoder->EncodeString(value.SemanticName);
    encoder->EncodeUInt32Value(value.SemanticIndex);
    encoder->EncodeUInt8Value(value.StartComponent);
    encoder->EncodeUInt8Value(value.ComponentCount);
    encoder->EncodeUInt8Value(value.OutputSlot);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VIEWPORT& value)
{
    encoder->EncodeFloatValue(value.TopLeftX);
    encoder->EncodeFloatValue(value.TopLeftY);
    encoder->EncodeFloatValue(value.Width);
    encoder->EncodeFloatValue(value.Height);
    encoder->EncodeFloatValue(value.MinDepth);
    encoder->EncodeFloatValue(value.MaxDepth);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BOX& value)
{
    encoder->EncodeUInt32Value(value.left);
    encoder->EncodeUInt32Value(value.top);
    encoder->EncodeUInt32Value(value.front);
    encoder->EncodeUInt32Value(value.right);
    encoder->EncodeUInt32Value(value.bottom);
    encoder->EncodeUInt32Value(value.back);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCILOP_DESC& value)
{
    encoder->EncodeEnumValue(value.StencilFailOp);
    encoder->EncodeEnumValue(value.StencilDepthFailOp);
    encoder->EncodeEnumValue(value.StencilPassOp);
    encoder->EncodeEnumValue(value.StencilFunc);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC& value)
{
    encoder->EncodeInt32Value(value.DepthEnable);
    encoder->EncodeEnumValue(value.DepthWriteMask);
    encoder->EncodeEnumValue(value.DepthFunc);
    encoder->EncodeInt32Value(value.StencilEnable);
    encoder->EncodeUInt8Value(value.StencilReadMask);
    encoder->EncodeUInt8Value(value.StencilWriteMask);
    EncodeStruct(encoder, value.FrontFace);
    EncodeStruct(encoder, value.BackFace);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC1& value)
{
    encoder->EncodeInt32Value(value.DepthEnable);
    encoder->EncodeEnumValue(value.DepthWriteMask);
    encoder->EncodeEnumValue(value.DepthFunc);
    encoder->EncodeInt32Value(value.StencilEnable);
    encoder->EncodeUInt8Value(value.StencilReadMask);
    encoder->EncodeUInt8Value(value.StencilWriteMask);
    EncodeStruct(encoder, value.FrontFace);
    EncodeStruct(encoder, value.BackFace);
    encoder->EncodeInt32Value(value.DepthBoundsTestEnable);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCILOP_DESC1& value)
{
    encoder->EncodeEnumValue(value.StencilFailOp);
    encoder->EncodeEnumValue(value.StencilDepthFailOp);
    encoder->EncodeEnumValue(value.StencilPassOp);
    encoder->EncodeEnumValue(value.StencilFunc);
    encoder->EncodeUInt8Value(value.StencilReadMask);
    encoder->EncodeUInt8Value(value.StencilWriteMask);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC2& value)
{
    encoder->EncodeInt32Value(value.DepthEnable);
    encoder->EncodeEnumValue(value.DepthWriteMask);
    encoder->EncodeEnumValue(value.DepthFunc);
    encoder->EncodeInt32Value(value.StencilEnable);
    EncodeStruct(encoder, value.FrontFace);
    EncodeStruct(encoder, value.BackFace);
    encoder->EncodeInt32Value(value.DepthBoundsTestEnable);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_TARGET_BLEND_DESC& value)
{
    encoder->EncodeInt32Value(value.BlendEnable);
    encoder->EncodeInt32Value(value.LogicOpEnable);
    encoder->EncodeEnumValue(value.SrcBlend);
    encoder->EncodeEnumValue(value.DestBlend);
    encoder->EncodeEnumValue(value.BlendOp);
    encoder->EncodeEnumValue(value.SrcBlendAlpha);
    encoder->EncodeEnumValue(value.DestBlendAlpha);
    encoder->EncodeEnumValue(value.BlendOpAlpha);
    encoder->EncodeEnumValue(value.LogicOp);
    encoder->EncodeUInt8Value(value.RenderTargetWriteMask);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BLEND_DESC& value)
{
    encoder->EncodeInt32Value(value.AlphaToCoverageEnable);
    encoder->EncodeInt32Value(value.IndependentBlendEnable);
    EncodeStructArray(encoder, value.RenderTarget, 8);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RASTERIZER_DESC& value)
{
    encoder->EncodeEnumValue(value.FillMode);
    encoder->EncodeEnumValue(value.CullMode);
    encoder->EncodeInt32Value(value.FrontCounterClockwise);
    encoder->EncodeInt32Value(value.DepthBias);
    encoder->EncodeFloatValue(value.DepthBiasClamp);
    encoder->EncodeFloatValue(value.SlopeScaledDepthBias);
    encoder->EncodeInt32Value(value.DepthClipEnable);
    encoder->EncodeInt32Value(value.MultisampleEnable);
    encoder->EncodeInt32Value(value.AntialiasedLineEnable);
    encoder->EncodeUInt32Value(value.ForcedSampleCount);
    encoder->EncodeEnumValue(value.ConservativeRaster);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RASTERIZER_DESC1& value)
{
    encoder->EncodeEnumValue(value.FillMode);
    encoder->EncodeEnumValue(value.CullMode);
    encoder->EncodeInt32Value(value.FrontCounterClockwise);
    encoder->EncodeFloatValue(value.DepthBias);
    encoder->EncodeFloatValue(value.DepthBiasClamp);
    encoder->EncodeFloatValue(value.SlopeScaledDepthBias);
    encoder->EncodeInt32Value(value.DepthClipEnable);
    encoder->EncodeInt32Value(value.MultisampleEnable);
    encoder->EncodeInt32Value(value.AntialiasedLineEnable);
    encoder->EncodeUInt32Value(value.ForcedSampleCount);
    encoder->EncodeEnumValue(value.ConservativeRaster);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RASTERIZER_DESC2& value)
{
    encoder->EncodeEnumValue(value.FillMode);
    encoder->EncodeEnumValue(value.CullMode);
    encoder->EncodeInt32Value(value.FrontCounterClockwise);
    encoder->EncodeFloatValue(value.DepthBias);
    encoder->EncodeFloatValue(value.DepthBiasClamp);
    encoder->EncodeFloatValue(value.SlopeScaledDepthBias);
    encoder->EncodeInt32Value(value.DepthClipEnable);
    encoder->EncodeEnumValue(value.LineRasterizationMode);
    encoder->EncodeUInt32Value(value.ForcedSampleCount);
    encoder->EncodeEnumValue(value.ConservativeRaster);
}

void Encode_ID3D12Object_GetPrivateData(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID guid,
    UINT* pDataSize,
    void* pData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Object_GetPrivateData, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, guid);
        encoder->EncodeUInt32Ptr(pDataSize, omit_output_data);
        encoder->EncodeVoidArray(pData, (pDataSize != nullptr) ? *pDataSize : 0, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Object_SetPrivateData(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID guid,
    UINT DataSize,
    const void* pData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Object_SetPrivateData, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, guid);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeVoidArray(pData, DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Object_SetPrivateDataInterface(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID guid,
    const IUnknown* pData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Object_SetPrivateDataInterface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, guid);
        encoder->EncodeObjectValue(pData);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Object_SetName(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR Name)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Object_SetName, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeWString(Name);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceChild_GetDevice(
    ID3D12DeviceChild_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppvDevice)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceChild_GetDevice, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvDevice, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvDevice, static_cast<IUnknown_Wrapper*>(wrapper));
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SHADER_BYTECODE& value)
{
    encoder->EncodeVoidArray(value.pShaderBytecode, value.BytecodeLength);
    encoder->EncodeSizeTValue(value.BytecodeLength);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STREAM_OUTPUT_DESC& value)
{
    EncodeStructArray(encoder, value.pSODeclaration, value.NumEntries);
    encoder->EncodeUInt32Value(value.NumEntries);
    encoder->EncodeUInt32Array(value.pBufferStrides, value.NumStrides);
    encoder->EncodeUInt32Value(value.NumStrides);
    encoder->EncodeUInt32Value(value.RasterizedStream);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INPUT_LAYOUT_DESC& value)
{
    EncodeStructArray(encoder, value.pInputElementDescs, value.NumElements);
    encoder->EncodeUInt32Value(value.NumElements);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CACHED_PIPELINE_STATE& value)
{
    encoder->EncodeVoidArray(value.pCachedBlob, value.CachedBlobSizeInBytes);
    encoder->EncodeSizeTValue(value.CachedBlobSizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GRAPHICS_PIPELINE_STATE_DESC& value)
{
    encoder->EncodeObjectValue(value.pRootSignature);
    EncodeStruct(encoder, value.VS);
    EncodeStruct(encoder, value.PS);
    EncodeStruct(encoder, value.DS);
    EncodeStruct(encoder, value.HS);
    EncodeStruct(encoder, value.GS);
    EncodeStruct(encoder, value.StreamOutput);
    EncodeStruct(encoder, value.BlendState);
    encoder->EncodeUInt32Value(value.SampleMask);
    EncodeStruct(encoder, value.RasterizerState);
    EncodeStruct(encoder, value.DepthStencilState);
    EncodeStruct(encoder, value.InputLayout);
    encoder->EncodeEnumValue(value.IBStripCutValue);
    encoder->EncodeEnumValue(value.PrimitiveTopologyType);
    encoder->EncodeUInt32Value(value.NumRenderTargets);
    encoder->EncodeEnumArray(value.RTVFormats, 8);
    encoder->EncodeEnumValue(value.DSVFormat);
    EncodeStruct(encoder, value.SampleDesc);
    encoder->EncodeUInt32Value(value.NodeMask);
    EncodeStruct(encoder, value.CachedPSO);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMPUTE_PIPELINE_STATE_DESC& value)
{
    encoder->EncodeObjectValue(value.pRootSignature);
    EncodeStruct(encoder, value.CS);
    encoder->EncodeUInt32Value(value.NodeMask);
    EncodeStruct(encoder, value.CachedPSO);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RT_FORMAT_ARRAY& value)
{
    encoder->EncodeEnumArray(value.RTFormats, 8);
    encoder->EncodeUInt32Value(value.NumRenderTargets);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS& value)
{
    encoder->EncodeInt32Value(value.DoublePrecisionFloatShaderOps);
    encoder->EncodeInt32Value(value.OutputMergerLogicOp);
    encoder->EncodeEnumValue(value.MinPrecisionSupport);
    encoder->EncodeEnumValue(value.TiledResourcesTier);
    encoder->EncodeEnumValue(value.ResourceBindingTier);
    encoder->EncodeInt32Value(value.PSSpecifiedStencilRefSupported);
    encoder->EncodeInt32Value(value.TypedUAVLoadAdditionalFormats);
    encoder->EncodeInt32Value(value.ROVsSupported);
    encoder->EncodeEnumValue(value.ConservativeRasterizationTier);
    encoder->EncodeUInt32Value(value.MaxGPUVirtualAddressBitsPerResource);
    encoder->EncodeInt32Value(value.StandardSwizzle64KBSupported);
    encoder->EncodeEnumValue(value.CrossNodeSharingTier);
    encoder->EncodeInt32Value(value.CrossAdapterRowMajorTextureSupported);
    encoder->EncodeInt32Value(value.VPAndRTArrayIndexFromAnyShaderFeedingRasterizerSupportedWithoutGSEmulation);
    encoder->EncodeEnumValue(value.ResourceHeapTier);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS1& value)
{
    encoder->EncodeInt32Value(value.WaveOps);
    encoder->EncodeUInt32Value(value.WaveLaneCountMin);
    encoder->EncodeUInt32Value(value.WaveLaneCountMax);
    encoder->EncodeUInt32Value(value.TotalLaneCount);
    encoder->EncodeInt32Value(value.ExpandedComputeResourceStates);
    encoder->EncodeInt32Value(value.Int64ShaderOps);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS2& value)
{
    encoder->EncodeInt32Value(value.DepthBoundsTestSupported);
    encoder->EncodeEnumValue(value.ProgrammableSamplePositionsTier);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_ROOT_SIGNATURE& value)
{
    encoder->EncodeEnumValue(value.HighestVersion);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_ARCHITECTURE& value)
{
    encoder->EncodeUInt32Value(value.NodeIndex);
    encoder->EncodeInt32Value(value.TileBasedRenderer);
    encoder->EncodeInt32Value(value.UMA);
    encoder->EncodeInt32Value(value.CacheCoherentUMA);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_ARCHITECTURE1& value)
{
    encoder->EncodeUInt32Value(value.NodeIndex);
    encoder->EncodeInt32Value(value.TileBasedRenderer);
    encoder->EncodeInt32Value(value.UMA);
    encoder->EncodeInt32Value(value.CacheCoherentUMA);
    encoder->EncodeInt32Value(value.IsolatedMMU);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_FEATURE_LEVELS& value)
{
    encoder->EncodeUInt32Value(value.NumFeatureLevels);
    encoder->EncodeEnumArray(value.pFeatureLevelsRequested, value.NumFeatureLevels);
    encoder->EncodeEnumValue(value.MaxSupportedFeatureLevel);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_SHADER_MODEL& value)
{
    encoder->EncodeEnumValue(value.HighestShaderModel);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_FORMAT_SUPPORT& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.Support1);
    encoder->EncodeEnumValue(value.Support2);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeUInt32Value(value.SampleCount);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.NumQualityLevels);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_FORMAT_INFO& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeUInt8Value(value.PlaneCount);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& value)
{
    encoder->EncodeUInt32Value(value.MaxGPUVirtualAddressBitsPerResource);
    encoder->EncodeUInt32Value(value.MaxGPUVirtualAddressBitsPerProcess);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_SHADER_CACHE& value)
{
    encoder->EncodeEnumValue(value.SupportFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& value)
{
    encoder->EncodeEnumValue(value.CommandListType);
    encoder->EncodeUInt32Value(value.Priority);
    encoder->EncodeInt32Value(value.PriorityForTypeIsSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS3& value)
{
    encoder->EncodeInt32Value(value.CopyQueueTimestampQueriesSupported);
    encoder->EncodeInt32Value(value.CastingFullyTypedFormatSupported);
    encoder->EncodeEnumValue(value.WriteBufferImmediateSupportFlags);
    encoder->EncodeEnumValue(value.ViewInstancingTier);
    encoder->EncodeInt32Value(value.BarycentricsSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_EXISTING_HEAPS& value)
{
    encoder->EncodeInt32Value(value.Supported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_DISPLAYABLE& value)
{
    encoder->EncodeInt32Value(value.DisplayableTexture);
    encoder->EncodeEnumValue(value.SharedResourceCompatibilityTier);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS4& value)
{
    encoder->EncodeInt32Value(value.MSAA64KBAlignedTextureSupported);
    encoder->EncodeEnumValue(value.SharedResourceCompatibilityTier);
    encoder->EncodeInt32Value(value.Native16BitShaderOpsSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_SERIALIZATION& value)
{
    encoder->EncodeUInt32Value(value.NodeIndex);
    encoder->EncodeEnumValue(value.HeapSerializationTier);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_CROSS_NODE& value)
{
    encoder->EncodeEnumValue(value.SharingTier);
    encoder->EncodeInt32Value(value.AtomicShaderInstructions);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS5& value)
{
    encoder->EncodeInt32Value(value.SRVOnlyTiledResourceTier3);
    encoder->EncodeEnumValue(value.RenderPassesTier);
    encoder->EncodeEnumValue(value.RaytracingTier);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS6& value)
{
    encoder->EncodeInt32Value(value.AdditionalShadingRatesSupported);
    encoder->EncodeInt32Value(value.PerPrimitiveShadingRateSupportedWithViewportIndexing);
    encoder->EncodeEnumValue(value.VariableShadingRateTier);
    encoder->EncodeUInt32Value(value.ShadingRateImageTileSize);
    encoder->EncodeInt32Value(value.BackgroundProcessingSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS7& value)
{
    encoder->EncodeEnumValue(value.MeshShaderTier);
    encoder->EncodeEnumValue(value.SamplerFeedbackTier);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_QUERY_META_COMMAND& value)
{
    EncodeStruct(encoder, value.CommandId);
    encoder->EncodeUInt32Value(value.NodeMask);
    encoder->EncodeVoidArray(value.pQueryInputData, value.QueryInputDataSizeInBytes);
    encoder->EncodeSizeTValue(value.QueryInputDataSizeInBytes);
    encoder->EncodeVoidArray(value.pQueryOutputData, value.QueryOutputDataSizeInBytes);
    encoder->EncodeSizeTValue(value.QueryOutputDataSizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS8& value)
{
    encoder->EncodeInt32Value(value.UnalignedBlockTexturesSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS9& value)
{
    encoder->EncodeInt32Value(value.MeshShaderPipelineStatsSupported);
    encoder->EncodeInt32Value(value.MeshShaderSupportsFullRangeRenderTargetArrayIndex);
    encoder->EncodeInt32Value(value.AtomicInt64OnTypedResourceSupported);
    encoder->EncodeInt32Value(value.AtomicInt64OnGroupSharedSupported);
    encoder->EncodeInt32Value(value.DerivativesInMeshAndAmplificationShadersSupported);
    encoder->EncodeEnumValue(value.WaveMMATier);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS10& value)
{
    encoder->EncodeInt32Value(value.VariableRateShadingSumCombinerSupported);
    encoder->EncodeInt32Value(value.MeshShaderPerPrimitiveShadingRateSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS11& value)
{
    encoder->EncodeInt32Value(value.AtomicInt64OnDescriptorHeapResourceSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS12& value)
{
    encoder->EncodeEnumValue(value.MSPrimitivesPipelineStatisticIncludesCulledPrimitives);
    encoder->EncodeInt32Value(value.EnhancedBarriersSupported);
    encoder->EncodeInt32Value(value.RelaxedFormatCastingSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS13& value)
{
    encoder->EncodeInt32Value(value.UnrestrictedBufferTextureCopyPitchSupported);
    encoder->EncodeInt32Value(value.UnrestrictedVertexElementAlignmentSupported);
    encoder->EncodeInt32Value(value.InvertedViewportHeightFlipsYSupported);
    encoder->EncodeInt32Value(value.InvertedViewportDepthFlipsZSupported);
    encoder->EncodeInt32Value(value.TextureCopyBetweenDimensionsSupported);
    encoder->EncodeInt32Value(value.AlphaBlendFactorSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS14& value)
{
    encoder->EncodeInt32Value(value.AdvancedTextureOpsSupported);
    encoder->EncodeInt32Value(value.WriteableMSAATexturesSupported);
    encoder->EncodeInt32Value(value.IndependentFrontAndBackStencilRefMaskSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS15& value)
{
    encoder->EncodeInt32Value(value.TriangleFanSupported);
    encoder->EncodeInt32Value(value.DynamicIndexBufferStripCutSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS16& value)
{
    encoder->EncodeInt32Value(value.DynamicDepthBiasSupported);
    encoder->EncodeInt32Value(value.GPUUploadHeapSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS17& value)
{
    encoder->EncodeInt32Value(value.NonNormalizedCoordinateSamplersSupported);
    encoder->EncodeInt32Value(value.ManualWriteTrackingResourceSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS18& value)
{
    encoder->EncodeInt32Value(value.RenderPassesValid);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS19& value)
{
    encoder->EncodeInt32Value(value.MismatchingOutputDimensionsSupported);
    encoder->EncodeUInt32Value(value.SupportedSampleCountsWithNoOutputs);
    encoder->EncodeInt32Value(value.PointSamplingAddressesNeverRoundUp);
    encoder->EncodeInt32Value(value.RasterizerDesc2Supported);
    encoder->EncodeInt32Value(value.NarrowQuadrilateralLinesSupported);
    encoder->EncodeInt32Value(value.AnisoFilterWithPointMipSupported);
    encoder->EncodeUInt32Value(value.MaxSamplerDescriptorHeapSize);
    encoder->EncodeUInt32Value(value.MaxSamplerDescriptorHeapSizeWithStaticSamplers);
    encoder->EncodeUInt32Value(value.MaxViewDescriptorHeapSize);
    encoder->EncodeInt32Value(value.ComputeOnlyCustomHeapSupported);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_ALLOCATION_INFO& value)
{
    encoder->EncodeUInt64Value(value.SizeInBytes);
    encoder->EncodeUInt64Value(value.Alignment);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_ALLOCATION_INFO1& value)
{
    encoder->EncodeUInt64Value(value.Offset);
    encoder->EncodeUInt64Value(value.Alignment);
    encoder->EncodeUInt64Value(value.SizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_HEAP_PROPERTIES& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.CPUPageProperty);
    encoder->EncodeEnumValue(value.MemoryPoolPreference);
    encoder->EncodeUInt32Value(value.CreationNodeMask);
    encoder->EncodeUInt32Value(value.VisibleNodeMask);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_HEAP_DESC& value)
{
    encoder->EncodeUInt64Value(value.SizeInBytes);
    EncodeStruct(encoder, value.Properties);
    encoder->EncodeUInt64Value(value.Alignment);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MIP_REGION& value)
{
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeUInt32Value(value.Depth);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_DESC& value)
{
    encoder->EncodeEnumValue(value.Dimension);
    encoder->EncodeUInt64Value(value.Alignment);
    encoder->EncodeUInt64Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeUInt16Value(value.DepthOrArraySize);
    encoder->EncodeUInt16Value(value.MipLevels);
    encoder->EncodeEnumValue(value.Format);
    EncodeStruct(encoder, value.SampleDesc);
    encoder->EncodeEnumValue(value.Layout);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_DESC1& value)
{
    encoder->EncodeEnumValue(value.Dimension);
    encoder->EncodeUInt64Value(value.Alignment);
    encoder->EncodeUInt64Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeUInt16Value(value.DepthOrArraySize);
    encoder->EncodeUInt16Value(value.MipLevels);
    encoder->EncodeEnumValue(value.Format);
    EncodeStruct(encoder, value.SampleDesc);
    encoder->EncodeEnumValue(value.Layout);
    encoder->EncodeEnumValue(value.Flags);
    EncodeStruct(encoder, value.SamplerFeedbackMipRegion);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_VALUE& value)
{
    encoder->EncodeFloatValue(value.Depth);
    encoder->EncodeUInt8Value(value.Stencil);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RANGE& value)
{
    encoder->EncodeSizeTValue(value.Begin);
    encoder->EncodeSizeTValue(value.End);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RANGE_UINT64& value)
{
    encoder->EncodeUInt64Value(value.Begin);
    encoder->EncodeUInt64Value(value.End);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_RANGE_UINT64& value)
{
    encoder->EncodeUInt32Value(value.Subresource);
    EncodeStruct(encoder, value.Range);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_INFO& value)
{
    encoder->EncodeUInt64Value(value.Offset);
    encoder->EncodeUInt32Value(value.RowPitch);
    encoder->EncodeUInt32Value(value.DepthPitch);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TILED_RESOURCE_COORDINATE& value)
{
    encoder->EncodeUInt32Value(value.X);
    encoder->EncodeUInt32Value(value.Y);
    encoder->EncodeUInt32Value(value.Z);
    encoder->EncodeUInt32Value(value.Subresource);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TILE_REGION_SIZE& value)
{
    encoder->EncodeUInt32Value(value.NumTiles);
    encoder->EncodeInt32Value(value.UseBox);
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt16Value(value.Height);
    encoder->EncodeUInt16Value(value.Depth);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_TILING& value)
{
    encoder->EncodeUInt32Value(value.WidthInTiles);
    encoder->EncodeUInt16Value(value.HeightInTiles);
    encoder->EncodeUInt16Value(value.DepthInTiles);
    encoder->EncodeUInt32Value(value.StartTileIndexInOverallResource);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TILE_SHAPE& value)
{
    encoder->EncodeUInt32Value(value.WidthInTexels);
    encoder->EncodeUInt32Value(value.HeightInTexels);
    encoder->EncodeUInt32Value(value.DepthInTexels);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PACKED_MIP_INFO& value)
{
    encoder->EncodeUInt8Value(value.NumStandardMips);
    encoder->EncodeUInt8Value(value.NumPackedMips);
    encoder->EncodeUInt32Value(value.NumTilesForPackedMips);
    encoder->EncodeUInt32Value(value.StartTileIndexInOverallResource);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_TRANSITION_BARRIER& value)
{
    encoder->EncodeObjectValue(value.pResource);
    encoder->EncodeUInt32Value(value.Subresource);
    encoder->EncodeEnumValue(value.StateBefore);
    encoder->EncodeEnumValue(value.StateAfter);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_ALIASING_BARRIER& value)
{
    encoder->EncodeObjectValue(value.pResourceBefore);
    encoder->EncodeObjectValue(value.pResourceAfter);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_UAV_BARRIER& value)
{
    encoder->EncodeObjectValue(value.pResource);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_FOOTPRINT& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeUInt32Value(value.Depth);
    encoder->EncodeUInt32Value(value.RowPitch);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& value)
{
    encoder->EncodeUInt64Value(value.Offset);
    EncodeStruct(encoder, value.Footprint);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SAMPLE_POSITION& value)
{
    encoder->EncodeInt8Value(value.X);
    encoder->EncodeInt8Value(value.Y);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VIEW_INSTANCE_LOCATION& value)
{
    encoder->EncodeUInt32Value(value.ViewportArrayIndex);
    encoder->EncodeUInt32Value(value.RenderTargetArrayIndex);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VIEW_INSTANCING_DESC& value)
{
    encoder->EncodeUInt32Value(value.ViewInstanceCount);
    EncodeStructArray(encoder, value.pViewInstanceLocations, value.ViewInstanceCount);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_SRV& value)
{
    encoder->EncodeUInt64Value(value.FirstElement);
    encoder->EncodeUInt32Value(value.NumElements);
    encoder->EncodeUInt32Value(value.StructureByteStride);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_SRV& value)
{
    encoder->EncodeUInt32Value(value.MostDetailedMip);
    encoder->EncodeUInt32Value(value.MipLevels);
    encoder->EncodeFloatValue(value.ResourceMinLODClamp);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_SRV& value)
{
    encoder->EncodeUInt32Value(value.MostDetailedMip);
    encoder->EncodeUInt32Value(value.MipLevels);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
    encoder->EncodeFloatValue(value.ResourceMinLODClamp);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_SRV& value)
{
    encoder->EncodeUInt32Value(value.MostDetailedMip);
    encoder->EncodeUInt32Value(value.MipLevels);
    encoder->EncodeUInt32Value(value.PlaneSlice);
    encoder->EncodeFloatValue(value.ResourceMinLODClamp);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_SRV& value)
{
    encoder->EncodeUInt32Value(value.MostDetailedMip);
    encoder->EncodeUInt32Value(value.MipLevels);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
    encoder->EncodeUInt32Value(value.PlaneSlice);
    encoder->EncodeFloatValue(value.ResourceMinLODClamp);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX3D_SRV& value)
{
    encoder->EncodeUInt32Value(value.MostDetailedMip);
    encoder->EncodeUInt32Value(value.MipLevels);
    encoder->EncodeFloatValue(value.ResourceMinLODClamp);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXCUBE_SRV& value)
{
    encoder->EncodeUInt32Value(value.MostDetailedMip);
    encoder->EncodeUInt32Value(value.MipLevels);
    encoder->EncodeFloatValue(value.ResourceMinLODClamp);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXCUBE_ARRAY_SRV& value)
{
    encoder->EncodeUInt32Value(value.MostDetailedMip);
    encoder->EncodeUInt32Value(value.MipLevels);
    encoder->EncodeUInt32Value(value.First2DArrayFace);
    encoder->EncodeUInt32Value(value.NumCubes);
    encoder->EncodeFloatValue(value.ResourceMinLODClamp);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_SRV& value)
{
    encoder->EncodeUInt32Value(value.UnusedField_NothingToDefine);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_SRV& value)
{
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& value)
{
    encoder->EncodeUInt64Value(value.Location);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CONSTANT_BUFFER_VIEW_DESC& value)
{
    encoder->EncodeUInt64Value(value.BufferLocation);
    encoder->EncodeUInt32Value(value.SizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SAMPLER_DESC& value)
{
    encoder->EncodeEnumValue(value.Filter);
    encoder->EncodeEnumValue(value.AddressU);
    encoder->EncodeEnumValue(value.AddressV);
    encoder->EncodeEnumValue(value.AddressW);
    encoder->EncodeFloatValue(value.MipLODBias);
    encoder->EncodeUInt32Value(value.MaxAnisotropy);
    encoder->EncodeEnumValue(value.ComparisonFunc);
    encoder->EncodeFloatArray(value.BorderColor, 4);
    encoder->EncodeFloatValue(value.MinLOD);
    encoder->EncodeFloatValue(value.MaxLOD);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_UAV& value)
{
    encoder->EncodeUInt64Value(value.FirstElement);
    encoder->EncodeUInt32Value(value.NumElements);
    encoder->EncodeUInt32Value(value.StructureByteStride);
    encoder->EncodeUInt64Value(value.CounterOffsetInBytes);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_UAV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_UAV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_UAV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.PlaneSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_UAV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
    encoder->EncodeUInt32Value(value.PlaneSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_UAV& value)
{
    encoder->EncodeUInt32Value(value.UnusedField_NothingToDefine);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_UAV& value)
{
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX3D_UAV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstWSlice);
    encoder->EncodeUInt32Value(value.WSize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_RTV& value)
{
    encoder->EncodeUInt64Value(value.FirstElement);
    encoder->EncodeUInt32Value(value.NumElements);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_RTV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_RTV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_RTV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.PlaneSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_RTV& value)
{
    encoder->EncodeUInt32Value(value.UnusedField_NothingToDefine);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_RTV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
    encoder->EncodeUInt32Value(value.PlaneSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_RTV& value)
{
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX3D_RTV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstWSlice);
    encoder->EncodeUInt32Value(value.WSize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_DSV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_DSV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_DSV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_DSV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_DSV& value)
{
    encoder->EncodeUInt32Value(value.UnusedField_NothingToDefine);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_DSV& value)
{
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.ArraySize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DESCRIPTOR_HEAP_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeUInt32Value(value.NumDescriptors);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.NodeMask);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DESCRIPTOR_RANGE& value)
{
    encoder->EncodeEnumValue(value.RangeType);
    encoder->EncodeUInt32Value(value.NumDescriptors);
    encoder->EncodeUInt32Value(value.BaseShaderRegister);
    encoder->EncodeUInt32Value(value.RegisterSpace);
    encoder->EncodeUInt32Value(value.OffsetInDescriptorsFromTableStart);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR_TABLE& value)
{
    encoder->EncodeUInt32Value(value.NumDescriptorRanges);
    EncodeStructArray(encoder, value.pDescriptorRanges, value.NumDescriptorRanges);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_CONSTANTS& value)
{
    encoder->EncodeUInt32Value(value.ShaderRegister);
    encoder->EncodeUInt32Value(value.RegisterSpace);
    encoder->EncodeUInt32Value(value.Num32BitValues);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR& value)
{
    encoder->EncodeUInt32Value(value.ShaderRegister);
    encoder->EncodeUInt32Value(value.RegisterSpace);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATIC_SAMPLER_DESC& value)
{
    encoder->EncodeEnumValue(value.Filter);
    encoder->EncodeEnumValue(value.AddressU);
    encoder->EncodeEnumValue(value.AddressV);
    encoder->EncodeEnumValue(value.AddressW);
    encoder->EncodeFloatValue(value.MipLODBias);
    encoder->EncodeUInt32Value(value.MaxAnisotropy);
    encoder->EncodeEnumValue(value.ComparisonFunc);
    encoder->EncodeEnumValue(value.BorderColor);
    encoder->EncodeFloatValue(value.MinLOD);
    encoder->EncodeFloatValue(value.MaxLOD);
    encoder->EncodeUInt32Value(value.ShaderRegister);
    encoder->EncodeUInt32Value(value.RegisterSpace);
    encoder->EncodeEnumValue(value.ShaderVisibility);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATIC_SAMPLER_DESC1& value)
{
    encoder->EncodeEnumValue(value.Filter);
    encoder->EncodeEnumValue(value.AddressU);
    encoder->EncodeEnumValue(value.AddressV);
    encoder->EncodeEnumValue(value.AddressW);
    encoder->EncodeFloatValue(value.MipLODBias);
    encoder->EncodeUInt32Value(value.MaxAnisotropy);
    encoder->EncodeEnumValue(value.ComparisonFunc);
    encoder->EncodeEnumValue(value.BorderColor);
    encoder->EncodeFloatValue(value.MinLOD);
    encoder->EncodeFloatValue(value.MaxLOD);
    encoder->EncodeUInt32Value(value.ShaderRegister);
    encoder->EncodeUInt32Value(value.RegisterSpace);
    encoder->EncodeEnumValue(value.ShaderVisibility);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC& value)
{
    encoder->EncodeUInt32Value(value.NumParameters);
    EncodeStructArray(encoder, value.pParameters, value.NumParameters);
    encoder->EncodeUInt32Value(value.NumStaticSamplers);
    EncodeStructArray(encoder, value.pStaticSamplers, value.NumStaticSamplers);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DESCRIPTOR_RANGE1& value)
{
    encoder->EncodeEnumValue(value.RangeType);
    encoder->EncodeUInt32Value(value.NumDescriptors);
    encoder->EncodeUInt32Value(value.BaseShaderRegister);
    encoder->EncodeUInt32Value(value.RegisterSpace);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.OffsetInDescriptorsFromTableStart);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR_TABLE1& value)
{
    encoder->EncodeUInt32Value(value.NumDescriptorRanges);
    EncodeStructArray(encoder, value.pDescriptorRanges, value.NumDescriptorRanges);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR1& value)
{
    encoder->EncodeUInt32Value(value.ShaderRegister);
    encoder->EncodeUInt32Value(value.RegisterSpace);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC1& value)
{
    encoder->EncodeUInt32Value(value.NumParameters);
    EncodeStructArray(encoder, value.pParameters, value.NumParameters);
    encoder->EncodeUInt32Value(value.NumStaticSamplers);
    EncodeStructArray(encoder, value.pStaticSamplers, value.NumStaticSamplers);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC2& value)
{
    encoder->EncodeUInt32Value(value.NumParameters);
    EncodeStructArray(encoder, value.pParameters, value.NumParameters);
    encoder->EncodeUInt32Value(value.NumStaticSamplers);
    EncodeStructArray(encoder, value.pStaticSamplers, value.NumStaticSamplers);
    encoder->EncodeEnumValue(value.Flags);
}

void Encode_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    ID3D12RootSignatureDeserializer_Wrapper* wrapper,
    const D3D12_ROOT_SIGNATURE_DESC * return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
    ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper,
    HRESULT return_value,
    D3D_ROOT_SIGNATURE_VERSION convertToVersion,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(convertToVersion);
        EncodeStructPtr(encoder, *ppDesc, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC * return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_DESCRIPTOR_HANDLE& value)
{
    encoder->EncodeUInt64Value(value.ptr);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISCARD_REGION& value)
{
    encoder->EncodeUInt32Value(value.NumRects);
    EncodeStructArray(encoder, value.pRects, value.NumRects);
    encoder->EncodeUInt32Value(value.FirstSubresource);
    encoder->EncodeUInt32Value(value.NumSubresources);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_HEAP_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeUInt32Value(value.Count);
    encoder->EncodeUInt32Value(value.NodeMask);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_PIPELINE_STATISTICS& value)
{
    encoder->EncodeUInt64Value(value.IAVertices);
    encoder->EncodeUInt64Value(value.IAPrimitives);
    encoder->EncodeUInt64Value(value.VSInvocations);
    encoder->EncodeUInt64Value(value.GSInvocations);
    encoder->EncodeUInt64Value(value.GSPrimitives);
    encoder->EncodeUInt64Value(value.CInvocations);
    encoder->EncodeUInt64Value(value.CPrimitives);
    encoder->EncodeUInt64Value(value.PSInvocations);
    encoder->EncodeUInt64Value(value.HSInvocations);
    encoder->EncodeUInt64Value(value.DSInvocations);
    encoder->EncodeUInt64Value(value.CSInvocations);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& value)
{
    encoder->EncodeUInt64Value(value.IAVertices);
    encoder->EncodeUInt64Value(value.IAPrimitives);
    encoder->EncodeUInt64Value(value.VSInvocations);
    encoder->EncodeUInt64Value(value.GSInvocations);
    encoder->EncodeUInt64Value(value.GSPrimitives);
    encoder->EncodeUInt64Value(value.CInvocations);
    encoder->EncodeUInt64Value(value.CPrimitives);
    encoder->EncodeUInt64Value(value.PSInvocations);
    encoder->EncodeUInt64Value(value.HSInvocations);
    encoder->EncodeUInt64Value(value.DSInvocations);
    encoder->EncodeUInt64Value(value.CSInvocations);
    encoder->EncodeUInt64Value(value.ASInvocations);
    encoder->EncodeUInt64Value(value.MSInvocations);
    encoder->EncodeUInt64Value(value.MSPrimitives);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_SO_STATISTICS& value)
{
    encoder->EncodeUInt64Value(value.NumPrimitivesWritten);
    encoder->EncodeUInt64Value(value.PrimitivesStorageNeeded);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STREAM_OUTPUT_BUFFER_VIEW& value)
{
    encoder->EncodeUInt64Value(value.BufferLocation);
    encoder->EncodeUInt64Value(value.SizeInBytes);
    encoder->EncodeUInt64Value(value.BufferFilledSizeLocation);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRAW_ARGUMENTS& value)
{
    encoder->EncodeUInt32Value(value.VertexCountPerInstance);
    encoder->EncodeUInt32Value(value.InstanceCount);
    encoder->EncodeUInt32Value(value.StartVertexLocation);
    encoder->EncodeUInt32Value(value.StartInstanceLocation);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRAW_INDEXED_ARGUMENTS& value)
{
    encoder->EncodeUInt32Value(value.IndexCountPerInstance);
    encoder->EncodeUInt32Value(value.InstanceCount);
    encoder->EncodeUInt32Value(value.StartIndexLocation);
    encoder->EncodeInt32Value(value.BaseVertexLocation);
    encoder->EncodeUInt32Value(value.StartInstanceLocation);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_ARGUMENTS& value)
{
    encoder->EncodeUInt32Value(value.ThreadGroupCountX);
    encoder->EncodeUInt32Value(value.ThreadGroupCountY);
    encoder->EncodeUInt32Value(value.ThreadGroupCountZ);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERTEX_BUFFER_VIEW& value)
{
    encoder->EncodeUInt64Value(value.BufferLocation);
    encoder->EncodeUInt32Value(value.SizeInBytes);
    encoder->EncodeUInt32Value(value.StrideInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INDEX_BUFFER_VIEW& value)
{
    encoder->EncodeUInt64Value(value.BufferLocation);
    encoder->EncodeUInt32Value(value.SizeInBytes);
    encoder->EncodeEnumValue(value.Format);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_SIGNATURE_DESC& value)
{
    encoder->EncodeUInt32Value(value.ByteStride);
    encoder->EncodeUInt32Value(value.NumArgumentDescs);
    EncodeStructArray(encoder, value.pArgumentDescs, value.NumArgumentDescs);
    encoder->EncodeUInt32Value(value.NodeMask);
}

void Encode_ID3D12Heap_GetDesc(
    ID3D12Heap_Wrapper* wrapper,
    D3D12_HEAP_DESC return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Heap_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource_Map(
    ID3D12Resource_Wrapper* wrapper,
    HRESULT return_value,
    UINT Subresource,
    const D3D12_RANGE* pReadRange,
    void** ppData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource_Map, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(Subresource);
        EncodeStructPtr(encoder, pReadRange);
        encoder->EncodeVoidPtrPtr(ppData, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource_Unmap(
    ID3D12Resource_Wrapper* wrapper,
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource_Unmap, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Subresource);
        EncodeStructPtr(encoder, pWrittenRange);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource_GetDesc(
    ID3D12Resource_Wrapper* wrapper,
    D3D12_RESOURCE_DESC return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource_GetGPUVirtualAddress(
    ID3D12Resource_Wrapper* wrapper,
    D3D12_GPU_VIRTUAL_ADDRESS return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource_ReadFromSubresource(
    ID3D12Resource_Wrapper* wrapper,
    HRESULT return_value,
    void* pDstData,
    UINT DstRowPitch,
    UINT DstDepthPitch,
    UINT SrcSubresource,
    const D3D12_BOX* pSrcBox)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource_ReadFromSubresource, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(pDstData);
        encoder->EncodeUInt32Value(DstRowPitch);
        encoder->EncodeUInt32Value(DstDepthPitch);
        encoder->EncodeUInt32Value(SrcSubresource);
        EncodeStructPtr(encoder, pSrcBox);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource_GetHeapProperties(
    ID3D12Resource_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS* pHeapFlags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource_GetHeapProperties, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pHeapProperties, omit_output_data);
        encoder->EncodeEnumPtr(pHeapFlags, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandAllocator_Reset(
    ID3D12CommandAllocator_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandAllocator_Reset, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Fence_GetCompletedValue(
    ID3D12Fence_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Fence_GetCompletedValue, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Fence_SetEventOnCompletion(
    ID3D12Fence_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Value,
    HANDLE hEvent)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Fence_Signal(
    ID3D12Fence_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Fence_Signal, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Fence1_GetCreationFlags(
    ID3D12Fence1_Wrapper* wrapper,
    D3D12_FENCE_FLAGS return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Fence1_GetCreationFlags, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12PipelineState_GetCachedBlob(
    ID3D12PipelineState_Wrapper* wrapper,
    HRESULT return_value,
    ID3DBlob** ppBlob)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12PipelineState_GetCachedBlob, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectPtr(ppBlob, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, IID_ID3D10Blob, reinterpret_cast<void**>(ppBlob), wrapper);
    }
}

void Encode_ID3D12DescriptorHeap_GetDesc(
    ID3D12DescriptorHeap_Wrapper* wrapper,
    D3D12_DESCRIPTOR_HEAP_DESC return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper,
    D3D12_CPU_DESCRIPTOR_HANDLE return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper,
    D3D12_GPU_DESCRIPTOR_HANDLE return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandList_GetType(
    ID3D12CommandList_Wrapper* wrapper,
    D3D12_COMMAND_LIST_TYPE return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandList_GetType, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12GraphicsCommandList_Close(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_Reset(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12CommandAllocator* pAllocator,
    ID3D12PipelineState* pInitialState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pAllocator);
        encoder->EncodeObjectValue(pInitialState);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_Reset, pAllocator, pInitialState);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearState(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12PipelineState* pPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearState, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pPipelineState);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ClearState, pPipelineState);
    }
}

void Encode_ID3D12GraphicsCommandList_DrawInstanced(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT VertexCountPerInstance,
    UINT InstanceCount,
    UINT StartVertexLocation,
    UINT StartInstanceLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(VertexCountPerInstance);
        encoder->EncodeUInt32Value(InstanceCount);
        encoder->EncodeUInt32Value(StartVertexLocation);
        encoder->EncodeUInt32Value(StartInstanceLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_DrawIndexedInstanced(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT IndexCountPerInstance,
    UINT InstanceCount,
    UINT StartIndexLocation,
    INT BaseVertexLocation,
    UINT StartInstanceLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(IndexCountPerInstance);
        encoder->EncodeUInt32Value(InstanceCount);
        encoder->EncodeUInt32Value(StartIndexLocation);
        encoder->EncodeInt32Value(BaseVertexLocation);
        encoder->EncodeUInt32Value(StartInstanceLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_Dispatch(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(ThreadGroupCountX);
        encoder->EncodeUInt32Value(ThreadGroupCountY);
        encoder->EncodeUInt32Value(ThreadGroupCountZ);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyBufferRegion(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT64 NumBytes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pDstBuffer);
        encoder->EncodeUInt64Value(DstOffset);
        encoder->EncodeObjectValue(pSrcBuffer);
        encoder->EncodeUInt64Value(SrcOffset);
        encoder->EncodeUInt64Value(NumBytes);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_CopyBufferRegion, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, NumBytes);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyTextureRegion(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    const D3D12_TEXTURE_COPY_LOCATION* pDst,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    const D3D12_TEXTURE_COPY_LOCATION* pSrc,
    const D3D12_BOX* pSrcBox)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDst);
        encoder->EncodeUInt32Value(DstX);
        encoder->EncodeUInt32Value(DstY);
        encoder->EncodeUInt32Value(DstZ);
        EncodeStructPtr(encoder, pSrc);
        EncodeStructPtr(encoder, pSrcBox);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_CopyTextureRegion, pDst, DstX, DstY, DstZ, pSrc, pSrcBox);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyResource(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pDstResource,
    ID3D12Resource* pSrcResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyResource, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pDstResource);
        encoder->EncodeObjectValue(pSrcResource);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_CopyResource, pDstResource, pSrcResource);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyTiles(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pTiledResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pTileRegionSize,
    ID3D12Resource* pBuffer,
    UINT64 BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTiles, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pTiledResource);
        EncodeStructPtr(encoder, pTileRegionStartCoordinate);
        EncodeStructPtr(encoder, pTileRegionSize);
        encoder->EncodeObjectValue(pBuffer);
        encoder->EncodeUInt64Value(BufferStartOffsetInBytes);
        encoder->EncodeEnumValue(Flags);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_CopyTiles, pTiledResource, pTileRegionStartCoordinate, pTileRegionSize, pBuffer, BufferStartOffsetInBytes, Flags);
    }
}

void Encode_ID3D12GraphicsCommandList_ResolveSubresource(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pDstResource,
    UINT DstSubresource,
    ID3D12Resource* pSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT Format)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveSubresource, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pDstResource);
        encoder->EncodeUInt32Value(DstSubresource);
        encoder->EncodeObjectValue(pSrcResource);
        encoder->EncodeUInt32Value(SrcSubresource);
        encoder->EncodeEnumValue(Format);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ResolveSubresource, pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
    }
}

void Encode_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(PrimitiveTopology);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_RSSetViewports(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumViewports,
    const D3D12_VIEWPORT* pViewports)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetViewports, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumViewports);
        EncodeStructArray(encoder, pViewports, NumViewports);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_RSSetScissorRects(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_OMSetBlendFactor(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    const FLOAT BlendFactor [4])
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeFloatArray(BlendFactor, 4);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_OMSetStencilRef(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT StencilRef)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(StencilRef);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_SetPipelineState(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12PipelineState* pPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPipelineState, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pPipelineState);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetPipelineState, pPipelineState);
    }
}

void Encode_ID3D12GraphicsCommandList_ResourceBarrier(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumBarriers,
    const D3D12_RESOURCE_BARRIER* pBarriers)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumBarriers);
        EncodeStructArray(encoder, pBarriers, NumBarriers);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ResourceBarrier, NumBarriers, pBarriers);
    }
}

void Encode_ID3D12GraphicsCommandList_ExecuteBundle(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12GraphicsCommandList* pCommandList)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pCommandList);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ExecuteBundle, pCommandList);
    }
}

void Encode_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumDescriptorHeaps,
    ID3D12DescriptorHeap* const* ppDescriptorHeaps)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumDescriptorHeaps);
        encoder->EncodeObjectArray(ppDescriptorHeaps, NumDescriptorHeaps);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetDescriptorHeaps, NumDescriptorHeaps, ppDescriptorHeaps);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootSignature(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12RootSignature* pRootSignature)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pRootSignature);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetComputeRootSignature, pRootSignature);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12RootSignature* pRootSignature)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pRootSignature);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetGraphicsRootSignature, pRootSignature);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        EncodeStruct(encoder, BaseDescriptor);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable, RootParameterIndex, BaseDescriptor);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        EncodeStruct(encoder, BaseDescriptor);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable, RootParameterIndex, BaseDescriptor);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(SrcData);
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(SrcData);
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(Num32BitValuesToSet);
        encoder->EncodeVoidArray(pSrcData, Num32BitValuesToSet * sizeof ( UINT ));
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(Num32BitValuesToSet);
        encoder->EncodeVoidArray(pSrcData, Num32BitValuesToSet * sizeof ( UINT ));
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView, RootParameterIndex, BufferLocation);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView, RootParameterIndex, BufferLocation);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView, RootParameterIndex, BufferLocation);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView, RootParameterIndex, BufferLocation);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView, RootParameterIndex, BufferLocation);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView, RootParameterIndex, BufferLocation);
    }
}

void Encode_ID3D12GraphicsCommandList_IASetIndexBuffer(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    const D3D12_INDEX_BUFFER_VIEW* pView)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pView);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_IASetIndexBuffer, pView);
    }
}

void Encode_ID3D12GraphicsCommandList_IASetVertexBuffers(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_VERTEX_BUFFER_VIEW* pViews)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(StartSlot);
        encoder->EncodeUInt32Value(NumViews);
        EncodeStructArray(encoder, pViews, NumViews);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_IASetVertexBuffers, StartSlot, NumViews, pViews);
    }
}

void Encode_ID3D12GraphicsCommandList_SOSetTargets(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SOSetTargets, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(StartSlot);
        encoder->EncodeUInt32Value(NumViews);
        EncodeStructArray(encoder, pViews, NumViews);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SOSetTargets, StartSlot, NumViews, pViews);
    }
}

void Encode_ID3D12GraphicsCommandList_OMSetRenderTargets(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumRenderTargetDescriptors,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
    BOOL RTsSingleHandleToDescriptorRange,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumRenderTargetDescriptors);
        EncodeStructArray(encoder, pRenderTargetDescriptors, (NumRenderTargetDescriptors ? (RTsSingleHandleToDescriptorRange ? 1 : NumRenderTargetDescriptors) : 0));
        encoder->EncodeInt32Value(RTsSingleHandleToDescriptorRange);
        EncodeStructPtr(encoder, pDepthStencilDescriptor);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_OMSetRenderTargets, NumRenderTargetDescriptors, pRenderTargetDescriptors, RTsSingleHandleToDescriptorRange, pDepthStencilDescriptor);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearDepthStencilView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
    D3D12_CLEAR_FLAGS ClearFlags,
    FLOAT Depth,
    UINT8 Stencil,
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, DepthStencilView);
        encoder->EncodeEnumValue(ClearFlags);
        encoder->EncodeFloatValue(Depth);
        encoder->EncodeUInt8Value(Stencil);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ClearDepthStencilView, DepthStencilView, ClearFlags, Depth, Stencil, NumRects, pRects);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearRenderTargetView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
    const FLOAT ColorRGBA [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, RenderTargetView);
        encoder->EncodeFloatArray(ColorRGBA, 4);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ClearRenderTargetView, RenderTargetView, ColorRGBA, NumRects, pRects);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const UINT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, ViewGPUHandleInCurrentHeap);
        EncodeStruct(encoder, ViewCPUHandle);
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Array(Values, 4);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint, ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const FLOAT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, ViewGPUHandleInCurrentHeap);
        EncodeStruct(encoder, ViewCPUHandle);
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeFloatArray(Values, 4);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat, ViewGPUHandleInCurrentHeap, ViewCPUHandle, pResource, Values, NumRects, pRects);
    }
}

void Encode_ID3D12GraphicsCommandList_DiscardResource(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_DISCARD_REGION* pRegion)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DiscardResource, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        EncodeStructPtr(encoder, pRegion);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_DiscardResource, pResource, pRegion);
    }
}

void Encode_ID3D12GraphicsCommandList_BeginQuery(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginQuery, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pQueryHeap);
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(Index);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_BeginQuery, pQueryHeap, Type, Index);
    }
}

void Encode_ID3D12GraphicsCommandList_EndQuery(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndQuery, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pQueryHeap);
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(Index);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_EndQuery, pQueryHeap, Type, Index);
    }
}

void Encode_ID3D12GraphicsCommandList_ResolveQueryData(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT StartIndex,
    UINT NumQueries,
    ID3D12Resource* pDestinationBuffer,
    UINT64 AlignedDestinationBufferOffset)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveQueryData, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pQueryHeap);
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(StartIndex);
        encoder->EncodeUInt32Value(NumQueries);
        encoder->EncodeObjectValue(pDestinationBuffer);
        encoder->EncodeUInt64Value(AlignedDestinationBufferOffset);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ResolveQueryData, pQueryHeap, Type, StartIndex, NumQueries, pDestinationBuffer, AlignedDestinationBufferOffset);
    }
}

void Encode_ID3D12GraphicsCommandList_SetPredication(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pBuffer,
    UINT64 AlignedBufferOffset,
    D3D12_PREDICATION_OP Operation)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPredication, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pBuffer);
        encoder->EncodeUInt64Value(AlignedBufferOffset);
        encoder->EncodeEnumValue(Operation);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_SetPredication, pBuffer, AlignedBufferOffset, Operation);
    }
}

void Encode_ID3D12GraphicsCommandList_SetMarker(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetMarker, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidArray(pData, Size);
        encoder->EncodeUInt32Value(Size);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_BeginEvent(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidArray(pData, Size);
        encoder->EncodeUInt32Value(Size);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_EndEvent(
    ID3D12GraphicsCommandList_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList_ExecuteIndirect(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12CommandSignature* pCommandSignature,
    UINT MaxCommandCount,
    ID3D12Resource* pArgumentBuffer,
    UINT64 ArgumentBufferOffset,
    ID3D12Resource* pCountBuffer,
    UINT64 CountBufferOffset)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pCommandSignature);
        encoder->EncodeUInt32Value(MaxCommandCount);
        encoder->EncodeObjectValue(pArgumentBuffer);
        encoder->EncodeUInt64Value(ArgumentBufferOffset);
        encoder->EncodeObjectValue(pCountBuffer);
        encoder->EncodeUInt64Value(CountBufferOffset);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList_ExecuteIndirect, pCommandSignature, MaxCommandCount, pArgumentBuffer, ArgumentBufferOffset, pCountBuffer, CountBufferOffset);
    }
}

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pDstBuffer);
        encoder->EncodeUInt64Value(DstOffset);
        encoder->EncodeObjectValue(pSrcBuffer);
        encoder->EncodeUInt64Value(SrcOffset);
        encoder->EncodeUInt32Value(Dependencies);
        encoder->EncodeObjectArray(ppDependentResources, Dependencies);
        EncodeStructArray(encoder, pDependentSubresourceRanges, Dependencies);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, ppDependentResources, pDependentSubresourceRanges);
    }
}

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pDstBuffer);
        encoder->EncodeUInt64Value(DstOffset);
        encoder->EncodeObjectValue(pSrcBuffer);
        encoder->EncodeUInt64Value(SrcOffset);
        encoder->EncodeUInt32Value(Dependencies);
        encoder->EncodeObjectArray(ppDependentResources, Dependencies);
        EncodeStructArray(encoder, pDependentSubresourceRanges, Dependencies);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64, pDstBuffer, DstOffset, pSrcBuffer, SrcOffset, Dependencies, ppDependentResources, pDependentSubresourceRanges);
    }
}

void Encode_ID3D12GraphicsCommandList1_OMSetDepthBounds(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    FLOAT Min,
    FLOAT Max)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeFloatValue(Min);
        encoder->EncodeFloatValue(Max);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList1_SetSamplePositions(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    UINT NumSamplesPerPixel,
    UINT NumPixels,
    D3D12_SAMPLE_POSITION* pSamplePositions)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumSamplesPerPixel);
        encoder->EncodeUInt32Value(NumPixels);
        EncodeStructArray(encoder, pSamplePositions, NumSamplesPerPixel * NumPixels);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    ID3D12Resource* pDstResource,
    UINT DstSubresource,
    UINT DstX,
    UINT DstY,
    ID3D12Resource* pSrcResource,
    UINT SrcSubresource,
    D3D12_RECT* pSrcRect,
    DXGI_FORMAT Format,
    D3D12_RESOLVE_MODE ResolveMode)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pDstResource);
        encoder->EncodeUInt32Value(DstSubresource);
        encoder->EncodeUInt32Value(DstX);
        encoder->EncodeUInt32Value(DstY);
        encoder->EncodeObjectValue(pSrcResource);
        encoder->EncodeUInt32Value(SrcSubresource);
        EncodeStructPtr(encoder, pSrcRect);
        encoder->EncodeEnumValue(Format);
        encoder->EncodeEnumValue(ResolveMode);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList1_ResolveSubresourceRegion, pDstResource, DstSubresource, DstX, DstY, pSrcResource, SrcSubresource, pSrcRect, Format, ResolveMode);
    }
}

void Encode_ID3D12GraphicsCommandList1_SetViewInstanceMask(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    UINT Mask)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Mask);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& value)
{
    encoder->EncodeUInt64Value(value.Dest);
    encoder->EncodeUInt32Value(value.Value);
}

void Encode_ID3D12GraphicsCommandList2_WriteBufferImmediate(
    ID3D12GraphicsCommandList2_Wrapper* wrapper,
    UINT Count,
    const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
    const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Count);
        EncodeStructArray(encoder, pParams, Count);
        encoder->EncodeEnumArray(pModes, Count);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList2_WriteBufferImmediate, Count, pParams, pModes);
    }
}

void Encode_ID3D12CommandQueue_UpdateTileMappings(
    ID3D12CommandQueue_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT NumResourceRegions,
    const D3D12_TILED_RESOURCE_COORDINATE* pResourceRegionStartCoordinates,
    const D3D12_TILE_REGION_SIZE* pResourceRegionSizes,
    ID3D12Heap* pHeap,
    UINT NumRanges,
    const D3D12_TILE_RANGE_FLAGS* pRangeFlags,
    const UINT* pHeapRangeStartOffsets,
    const UINT* pRangeTileCounts,
    D3D12_TILE_MAPPING_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_UpdateTileMappings, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(NumResourceRegions);
        EncodeStructArray(encoder, pResourceRegionStartCoordinates, NumResourceRegions);
        EncodeStructArray(encoder, pResourceRegionSizes, NumResourceRegions);
        encoder->EncodeObjectValue(pHeap);
        encoder->EncodeUInt32Value(NumRanges);
        encoder->EncodeEnumArray(pRangeFlags, NumRanges);
        encoder->EncodeUInt32Array(pHeapRangeStartOffsets, NumRanges);
        encoder->EncodeUInt32Array(pRangeTileCounts, NumRanges);
        encoder->EncodeEnumValue(Flags);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_CopyTileMappings(
    ID3D12CommandQueue_Wrapper* wrapper,
    ID3D12Resource* pDstResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
    ID3D12Resource* pSrcResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_CopyTileMappings, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pDstResource);
        EncodeStructPtr(encoder, pDstRegionStartCoordinate);
        encoder->EncodeObjectValue(pSrcResource);
        EncodeStructPtr(encoder, pSrcRegionStartCoordinate);
        EncodeStructPtr(encoder, pRegionSize);
        encoder->EncodeEnumValue(Flags);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_ExecuteCommandLists(
    ID3D12CommandQueue_Wrapper* wrapper,
    UINT NumCommandLists,
    ID3D12CommandList* const* ppCommandLists)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumCommandLists);
        encoder->EncodeObjectArray(ppCommandLists, NumCommandLists);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_SetMarker(
    ID3D12CommandQueue_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_SetMarker, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidArray(pData, Size);
        encoder->EncodeUInt32Value(Size);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_BeginEvent(
    ID3D12CommandQueue_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_BeginEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidArray(pData, Size);
        encoder->EncodeUInt32Value(Size);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_EndEvent(
    ID3D12CommandQueue_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_EndEvent, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_Signal(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* pFence,
    UINT64 Value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pFence);
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_Wait(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* pFence,
    UINT64 Value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_Wait, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pFence);
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_GetTimestampFrequency(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64* pFrequency)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_GetTimestampFrequency, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Ptr(pFrequency, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_GetClockCalibration(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64* pGpuTimestamp,
    UINT64* pCpuTimestamp)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_GetClockCalibration, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Ptr(pGpuTimestamp, omit_output_data);
        encoder->EncodeUInt64Ptr(pCpuTimestamp, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12CommandQueue_GetDesc(
    ID3D12CommandQueue_Wrapper* wrapper,
    D3D12_COMMAND_QUEUE_DESC return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12CommandQueue_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_GetNodeCount(
    ID3D12Device_Wrapper* wrapper,
    UINT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetNodeCount, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_CreateCommandQueue(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID riid,
    void** ppCommandQueue)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppCommandQueue, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppCommandQueue, wrapper);
    }
}

void Encode_ID3D12Device_CreateCommandAllocator(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_COMMAND_LIST_TYPE type,
    REFIID riid,
    void** ppCommandAllocator)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandAllocator, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(type);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppCommandAllocator, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppCommandAllocator, wrapper);
    }
}

void Encode_ID3D12Device_CreateGraphicsPipelineState(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppPipelineState, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppPipelineState, wrapper);
    }
}

void Encode_ID3D12Device_CreateComputePipelineState(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppPipelineState, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppPipelineState, wrapper);
    }
}

void Encode_ID3D12Device_CreateCommandList(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    ID3D12CommandAllocator* pCommandAllocator,
    ID3D12PipelineState* pInitialState,
    REFIID riid,
    void** ppCommandList)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandList, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeEnumValue(type);
        encoder->EncodeObjectValue(pCommandAllocator);
        encoder->EncodeObjectValue(pInitialState);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppCommandList, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppCommandList, wrapper);
    }
}

void Encode_ID3D12Device_CreateDescriptorHeap(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateDescriptorHeap, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDescriptorHeapDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvHeap, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvHeap, wrapper);
    }
}

void Encode_ID3D12Device_GetDescriptorHandleIncrementSize(
    ID3D12Device_Wrapper* wrapper,
    UINT return_value,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(DescriptorHeapType);
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_CreateRootSignature(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT nodeMask,
    const void* pBlobWithRootSignature,
    SIZE_T blobLengthInBytes,
    REFIID riid,
    void** ppvRootSignature)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateRootSignature, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeVoidArray(pBlobWithRootSignature, blobLengthInBytes);
        encoder->EncodeSizeTValue(blobLengthInBytes);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvRootSignature, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvRootSignature, wrapper);
    }
}

void Encode_ID3D12Device_CreateConstantBufferView(
    ID3D12Device_Wrapper* wrapper,
    const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateConstantBufferView, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device_CreateShaderResourceView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateShaderResourceView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device_CreateUnorderedAccessView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    ID3D12Resource* pCounterResource,
    const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateUnorderedAccessView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeObjectValue(pCounterResource);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device_CreateRenderTargetView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateRenderTargetView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device_CreateDepthStencilView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateDepthStencilView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device_CreateSampler(
    ID3D12Device_Wrapper* wrapper,
    const D3D12_SAMPLER_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateSampler, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device_CopyDescriptors(
    ID3D12Device_Wrapper* wrapper,
    UINT NumDestDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
    const UINT* pDestDescriptorRangeSizes,
    UINT NumSrcDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
    const UINT* pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptors, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumDestDescriptorRanges);
        EncodeStructArray(encoder, pDestDescriptorRangeStarts, NumDestDescriptorRanges);
        encoder->EncodeUInt32Array(pDestDescriptorRangeSizes, NumDestDescriptorRanges);
        encoder->EncodeUInt32Value(NumSrcDescriptorRanges);
        EncodeStructArray(encoder, pSrcDescriptorRangeStarts, NumSrcDescriptorRanges);
        encoder->EncodeUInt32Array(pSrcDescriptorRangeSizes, NumSrcDescriptorRanges);
        encoder->EncodeEnumValue(DescriptorHeapsType);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_CopyDescriptorsSimple(
    ID3D12Device_Wrapper* wrapper,
    UINT NumDescriptors,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptorsSimple, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumDescriptors);
        EncodeStruct(encoder, DestDescriptorRangeStart);
        EncodeStruct(encoder, SrcDescriptorRangeStart);
        encoder->EncodeEnumValue(DescriptorHeapsType);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_GetResourceAllocationInfo(
    ID3D12Device_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetResourceAllocationInfo, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(visibleMask);
        encoder->EncodeUInt32Value(numResourceDescs);
        EncodeStructArray(encoder, pResourceDescs, numResourceDescs);
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_GetCustomHeapProperties(
    ID3D12Device_Wrapper* wrapper,
    D3D12_HEAP_PROPERTIES return_value,
    UINT nodeMask,
    D3D12_HEAP_TYPE heapType)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetCustomHeapProperties, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeEnumValue(heapType);
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_CreateCommittedResource(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riidResource,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateCommittedResource, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumValue(HeapFlags);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialResourceState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riidResource);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riidResource, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device_CreateHeap(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateHeap, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvHeap, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvHeap, wrapper);
    }
}

void Encode_ID3D12Device_CreatePlacedResource(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreatePlacedResource, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pHeap);
        encoder->EncodeUInt64Value(HeapOffset);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device_CreateReservedResource(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateReservedResource, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device_CreateSharedHandle(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12DeviceChild* pObject,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD Access,
    LPCWSTR Name,
    HANDLE* pHandle)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pObject);
        EncodeStructPtr(encoder, pAttributes);
        encoder->EncodeUInt32Value(Access);
        encoder->EncodeWString(Name);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_OpenSharedHandle(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE NTHandle,
    REFIID riid,
    void** ppvObj)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(NTHandle);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvObj, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvObj, wrapper);
    }
}

void Encode_ID3D12Device_OpenSharedHandleByName(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR Name,
    DWORD Access,
    HANDLE* pNTHandle)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeWString(Name);
        encoder->EncodeUInt32Value(Access);
        encoder->EncodeVoidPtrPtr(pNTHandle, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_MakeResident(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_MakeResident, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumObjects);
        encoder->EncodeObjectArray(ppObjects, NumObjects);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_Evict(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_Evict, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumObjects);
        encoder->EncodeObjectArray(ppObjects, NumObjects);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_CreateFence(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 InitialValue,
    D3D12_FENCE_FLAGS Flags,
    REFIID riid,
    void** ppFence)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateFence, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Value(InitialValue);
        encoder->EncodeEnumValue(Flags);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppFence, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppFence, wrapper);
    }
}

void Encode_ID3D12Device_GetDeviceRemovedReason(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetDeviceRemovedReason, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_GetCopyableFootprints(
    ID3D12Device_Wrapper* wrapper,
    const D3D12_RESOURCE_DESC* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetCopyableFootprints, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pResourceDesc);
        encoder->EncodeUInt32Value(FirstSubresource);
        encoder->EncodeUInt32Value(NumSubresources);
        encoder->EncodeUInt64Value(BaseOffset);
        EncodeStructArray(encoder, pLayouts, NumSubresources);
        encoder->EncodeUInt32Array(pNumRows, NumSubresources);
        encoder->EncodeUInt64Array(pRowSizeInBytes, NumSubresources);
        encoder->EncodeUInt64Ptr(pTotalBytes);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_CreateQueryHeap(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_QUERY_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateQueryHeap, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvHeap, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvHeap, wrapper);
    }
}

void Encode_ID3D12Device_SetStablePowerState(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    BOOL Enable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_SetStablePowerState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(Enable);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_CreateCommandSignature(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
    ID3D12RootSignature* pRootSignature,
    REFIID riid,
    void** ppvCommandSignature)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandSignature, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectValue(pRootSignature);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvCommandSignature, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvCommandSignature, wrapper);
    }
}

void Encode_ID3D12Device_GetResourceTiling(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pTiledResource,
    UINT* pNumTilesForEntireResource,
    D3D12_PACKED_MIP_INFO* pPackedMipDesc,
    D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
    UINT* pNumSubresourceTilings,
    UINT FirstSubresourceTilingToGet,
    D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetResourceTiling, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pTiledResource);
        encoder->EncodeUInt32Ptr(pNumTilesForEntireResource);
        EncodeStructPtr(encoder, pPackedMipDesc);
        EncodeStructPtr(encoder, pStandardTileShapeForNonPackedMips);
        encoder->EncodeUInt32Ptr(pNumSubresourceTilings);
        encoder->EncodeUInt32Value(FirstSubresourceTilingToGet);
        EncodeStructArray(encoder, pSubresourceTilingsForNonPackedMips, ((pNumSubresourceTilings == nullptr) ? 0 : *pNumSubresourceTilings));
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device_GetAdapterLuid(
    ID3D12Device_Wrapper* wrapper,
    LUID return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device_GetAdapterLuid, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12PipelineLibrary_StorePipeline(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    ID3D12PipelineState* pPipeline)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeWString(pName);
        encoder->EncodeObjectValue(pPipeline);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12PipelineLibrary_LoadGraphicsPipeline(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeWString(pName);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppPipelineState, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppPipelineState, wrapper);
    }
}

void Encode_ID3D12PipelineLibrary_LoadComputePipeline(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeWString(pName);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppPipelineState, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppPipelineState, wrapper);
    }
}

void Encode_ID3D12PipelineLibrary_GetSerializedSize(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    SIZE_T return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_GetSerializedSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeSizeTValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12PipelineLibrary_Serialize(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    void* pData,
    SIZE_T DataSizeInBytes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_Serialize, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidArray(pData, DataSizeInBytes, omit_output_data);
        encoder->EncodeSizeTValue(DataSizeInBytes);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12PipelineLibrary1_LoadPipeline(
    ID3D12PipelineLibrary1_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12PipelineLibrary1_LoadPipeline, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeWString(pName);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppPipelineState, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppPipelineState, wrapper);
    }
}

void Encode_ID3D12Device1_CreatePipelineLibrary(
    ID3D12Device1_Wrapper* wrapper,
    HRESULT return_value,
    const void* pLibraryBlob,
    SIZE_T BlobLength,
    REFIID riid,
    void** ppPipelineLibrary)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device1_CreatePipelineLibrary, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidArray(pLibraryBlob, BlobLength);
        encoder->EncodeSizeTValue(BlobLength);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppPipelineLibrary, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppPipelineLibrary, wrapper);
    }
}

void Encode_ID3D12Device1_SetEventOnMultipleFenceCompletion(
    ID3D12Device1_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* const* ppFences,
    const UINT64* pFenceValues,
    UINT NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
    HANDLE hEvent)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectArray(ppFences, NumFences);
        encoder->EncodeUInt64Array(pFenceValues, NumFences);
        encoder->EncodeUInt32Value(NumFences);
        encoder->EncodeEnumValue(Flags);
        encoder->EncodeVoidPtr(hEvent);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device1_SetResidencyPriority(
    ID3D12Device1_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    const D3D12_RESIDENCY_PRIORITY* pPriorities)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device1_SetResidencyPriority, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumObjects);
        encoder->EncodeObjectArray(ppObjects, NumObjects);
        encoder->EncodeEnumArray(pPriorities, NumObjects);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device2_CreatePipelineState(
    ID3D12Device2_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device2_CreatePipelineState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppPipelineState, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppPipelineState, wrapper);
    }
}

void Encode_ID3D12Device3_OpenExistingHeapFromAddress(
    ID3D12Device3_Wrapper* wrapper,
    HRESULT return_value,
    const void* pAddress,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(pAddress);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvHeap, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvHeap, wrapper);
    }
}

void Encode_ID3D12Device3_OpenExistingHeapFromFileMapping(
    ID3D12Device3_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hFileMapping,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidPtr(hFileMapping);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvHeap, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvHeap, wrapper);
    }
}

void Encode_ID3D12Device3_EnqueueMakeResident(
    ID3D12Device3_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_RESIDENCY_FLAGS Flags,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    ID3D12Fence* pFenceToSignal,
    UINT64 FenceValueToSignal)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device3_EnqueueMakeResident, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Flags);
        encoder->EncodeUInt32Value(NumObjects);
        encoder->EncodeObjectArray(ppObjects, NumObjects);
        encoder->EncodeObjectValue(pFenceToSignal);
        encoder->EncodeUInt64Value(FenceValueToSignal);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12ProtectedSession_GetStatusFence(
    ID3D12ProtectedSession_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppFence)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetStatusFence, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppFence, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppFence, static_cast<IUnknown_Wrapper*>(wrapper));
    }
}

void Encode_ID3D12ProtectedSession_GetSessionStatus(
    ID3D12ProtectedSession_Wrapper* wrapper,
    D3D12_PROTECTED_SESSION_STATUS return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetSessionStatus, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& value)
{
    encoder->EncodeUInt32Value(value.NodeIndex);
    encoder->EncodeEnumValue(value.Support);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PROTECTED_RESOURCE_SESSION_DESC& value)
{
    encoder->EncodeUInt32Value(value.NodeMask);
    encoder->EncodeEnumValue(value.Flags);
}

void Encode_ID3D12ProtectedResourceSession_GetDesc(
    ID3D12ProtectedResourceSession_Wrapper* wrapper,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device4_CreateCommandList1(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    D3D12_COMMAND_LIST_FLAGS flags,
    REFIID riid,
    void** ppCommandList)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device4_CreateCommandList1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(flags);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppCommandList, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppCommandList, wrapper);
    }
}

void Encode_ID3D12Device4_CreateProtectedResourceSession(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppSession)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device4_CreateProtectedResourceSession, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppSession, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppSession, wrapper);
    }
}

void Encode_ID3D12Device4_CreateCommittedResource1(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riidResource,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device4_CreateCommittedResource1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumValue(HeapFlags);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialResourceState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        encoder->EncodeObjectValue(pProtectedSession);
        EncodeStruct(encoder, riidResource);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riidResource, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device4_CreateHeap1(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_DESC* pDesc,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device4_CreateHeap1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectValue(pProtectedSession);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvHeap, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvHeap, wrapper);
    }
}

void Encode_ID3D12Device4_CreateReservedResource1(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device4_CreateReservedResource1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        encoder->EncodeObjectValue(pProtectedSession);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device4_GetResourceAllocationInfo1(
    ID3D12Device4_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device4_GetResourceAllocationInfo1, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(visibleMask);
        encoder->EncodeUInt32Value(numResourceDescs);
        EncodeStructArray(encoder, pResourceDescs, numResourceDescs);
        EncodeStructArray(encoder, pResourceAllocationInfo1, numResourceDescs);
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12LifetimeOwner_LifetimeStateUpdated(
    ID3D12LifetimeOwner_Wrapper* wrapper,
    D3D12_LIFETIME_STATE NewState)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(NewState);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SwapChainAssistant_GetLUID(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    LUID return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetLUID, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SwapChainAssistant_GetSwapChainObject(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppv)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppv, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppv, wrapper);
    }
}

void Encode_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riidResource,
    void** ppvResource,
    REFIID riidQueue,
    void** ppvQueue)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riidResource);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        EncodeStruct(encoder, riidQueue);
        encoder->EncodeObjectPtr(ppvQueue, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SwapChainAssistant_InsertImplicitSync(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12LifetimeTracker_DestroyOwnedObject(
    ID3D12LifetimeTracker_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12DeviceChild* pObject)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pObject);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_META_COMMAND_PARAMETER_DESC& value)
{
    encoder->EncodeWString(value.Name);
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeEnumValue(value.RequiredResourceState);
    encoder->EncodeUInt32Value(value.StructureOffset);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_META_COMMAND_DESC& value)
{
    EncodeStruct(encoder, value.Id);
    encoder->EncodeWString(value.Name);
    encoder->EncodeEnumValue(value.InitializationDirtyState);
    encoder->EncodeEnumValue(value.ExecutionDirtyState);
}

void Encode_ID3D12StateObjectProperties_GetShaderIdentifier(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    void* return_value,
    LPCWSTR pExportName)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeWString(pExportName);
        encoder->EncodeVoidArray(return_value, D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12StateObjectProperties_GetShaderStackSize(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    UINT64 return_value,
    LPCWSTR pExportName)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderStackSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeWString(pExportName);
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12StateObjectProperties_GetPipelineStackSize(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12StateObjectProperties_SetPipelineStackSize(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    UINT64 PipelineStackSizeInBytes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(PipelineStackSizeInBytes);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_OBJECT_CONFIG& value)
{
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GLOBAL_ROOT_SIGNATURE& value)
{
    encoder->EncodeObjectValue(value.pGlobalRootSignature);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_LOCAL_ROOT_SIGNATURE& value)
{
    encoder->EncodeObjectValue(value.pLocalRootSignature);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_NODE_MASK& value)
{
    encoder->EncodeUInt32Value(value.NodeMask);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_EXPORT_DESC& value)
{
    encoder->EncodeWString(value.Name);
    encoder->EncodeWString(value.ExportToRename);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DXIL_LIBRARY_DESC& value)
{
    EncodeStruct(encoder, value.DXILLibrary);
    encoder->EncodeUInt32Value(value.NumExports);
    EncodeStructArray(encoder, value.pExports, value.NumExports);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_EXISTING_COLLECTION_DESC& value)
{
    encoder->EncodeObjectValue(value.pExistingCollection);
    encoder->EncodeUInt32Value(value.NumExports);
    EncodeStructArray(encoder, value.pExports, value.NumExports);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& value)
{
    encoder->EncodeWString(value.SubobjectToAssociate);
    encoder->EncodeUInt32Value(value.NumExports);
    encoder->EncodeWStringArray(value.pExports, value.NumExports);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_HIT_GROUP_DESC& value)
{
    encoder->EncodeWString(value.HitGroupExport);
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeWString(value.AnyHitShaderImport);
    encoder->EncodeWString(value.ClosestHitShaderImport);
    encoder->EncodeWString(value.IntersectionShaderImport);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_SHADER_CONFIG& value)
{
    encoder->EncodeUInt32Value(value.MaxPayloadSizeInBytes);
    encoder->EncodeUInt32Value(value.MaxAttributeSizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_PIPELINE_CONFIG& value)
{
    encoder->EncodeUInt32Value(value.MaxTraceRecursionDepth);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_PIPELINE_CONFIG1& value)
{
    encoder->EncodeUInt32Value(value.MaxTraceRecursionDepth);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& value)
{
    encoder->EncodeUInt64Value(value.StartAddress);
    encoder->EncodeUInt64Value(value.StrideInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& value)
{
    encoder->EncodeUInt64Value(value.StartAddress);
    encoder->EncodeUInt64Value(value.SizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& value)
{
    encoder->EncodeUInt64Value(value.StartAddress);
    encoder->EncodeUInt64Value(value.SizeInBytes);
    encoder->EncodeUInt64Value(value.StrideInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& value)
{
    encoder->EncodeUInt64Value(value.Transform3x4);
    encoder->EncodeEnumValue(value.IndexFormat);
    encoder->EncodeEnumValue(value.VertexFormat);
    encoder->EncodeUInt32Value(value.IndexCount);
    encoder->EncodeUInt32Value(value.VertexCount);
    encoder->EncodeUInt64Value(value.IndexBuffer);
    EncodeStruct(encoder, value.VertexBuffer);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_AABB& value)
{
    encoder->EncodeFloatValue(value.MinX);
    encoder->EncodeFloatValue(value.MinY);
    encoder->EncodeFloatValue(value.MinZ);
    encoder->EncodeFloatValue(value.MaxX);
    encoder->EncodeFloatValue(value.MaxY);
    encoder->EncodeFloatValue(value.MaxZ);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& value)
{
    encoder->EncodeUInt64Value(value.AABBCount);
    EncodeStruct(encoder, value.AABBs);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& value)
{
    encoder->EncodeUInt64Value(value.DestBuffer);
    encoder->EncodeEnumValue(value.InfoType);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& value)
{
    encoder->EncodeUInt64Value(value.CompactedSizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& value)
{
    encoder->EncodeUInt64Value(value.DecodedSizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeUInt32Value(value.NumDescs);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& value)
{
    encoder->EncodeUInt64Value(value.SerializedSizeInBytes);
    encoder->EncodeUInt64Value(value.NumBottomLevelAccelerationStructurePointers);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& value)
{
    EncodeStruct(encoder, value.DriverOpaqueGUID);
    encoder->EncodeUInt8Array(value.DriverOpaqueVersioningData, 16);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& value)
{
    EncodeStruct(encoder, value.DriverMatchingIdentifier);
    encoder->EncodeUInt64Value(value.SerializedSizeInBytesIncludingHeader);
    encoder->EncodeUInt64Value(value.DeserializedSizeInBytes);
    encoder->EncodeUInt64Value(value.NumBottomLevelAccelerationStructurePointersAfterHeader);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& value)
{
    encoder->EncodeUInt64Value(value.CurrentSizeInBytes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_INSTANCE_DESC& value)
{
    encoder->EncodeFloatArray(*value.Transform, 12);
    encoder->EncodeUInt32Value(value.InstanceID);
    encoder->EncodeUInt32Value(value.InstanceMask);
    encoder->EncodeUInt32Value(value.InstanceContributionToHitGroupIndex);
    encoder->EncodeUInt32Value(value.Flags);
    encoder->EncodeUInt64Value(value.AccelerationStructure);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& value)
{
    encoder->EncodeUInt64Value(value.DestAccelerationStructureData);
    EncodeStruct(encoder, value.Inputs);
    encoder->EncodeUInt64Value(value.SourceAccelerationStructureData);
    encoder->EncodeUInt64Value(value.ScratchAccelerationStructureData);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& value)
{
    encoder->EncodeUInt64Value(value.ResultDataMaxSizeInBytes);
    encoder->EncodeUInt64Value(value.ScratchDataSizeInBytes);
    encoder->EncodeUInt64Value(value.UpdateScratchDataSizeInBytes);
}

void Encode_ID3D12Device5_CreateLifetimeTracker(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12LifetimeOwner* pOwner,
    REFIID riid,
    void** ppvTracker)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_CreateLifetimeTracker, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pOwner);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvTracker, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvTracker, wrapper);
    }
}

void Encode_ID3D12Device5_RemoveDevice(
    ID3D12Device5_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_RemoveDevice, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device5_EnumerateMetaCommands(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pNumMetaCommands,
    D3D12_META_COMMAND_DESC* pDescs)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommands, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Ptr(pNumMetaCommands, omit_output_data);
        EncodeStructArray(encoder, pDescs, ((pNumMetaCommands == nullptr) ? 0 : *pNumMetaCommands), omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device5_EnumerateMetaCommandParameters(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT* pTotalStructureSizeInBytes,
    UINT* pParameterCount,
    D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommandParameters, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, CommandId);
        encoder->EncodeEnumValue(Stage);
        encoder->EncodeUInt32Ptr(pTotalStructureSizeInBytes, omit_output_data);
        encoder->EncodeUInt32Ptr(pParameterCount, omit_output_data);
        EncodeStructArray(encoder, pParameterDescs, ((pParameterCount == nullptr) ? 0 : *pParameterCount), omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device5_CreateMetaCommand(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID CommandId,
    UINT NodeMask,
    const void* pCreationParametersData,
    SIZE_T CreationParametersDataSizeInBytes,
    REFIID riid,
    void** ppMetaCommand)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_CreateMetaCommand, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, CommandId);
        encoder->EncodeUInt32Value(NodeMask);
        encoder->EncodeVoidArray(pCreationParametersData, CreationParametersDataSizeInBytes);
        encoder->EncodeSizeTValue(CreationParametersDataSizeInBytes);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppMetaCommand, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppMetaCommand, wrapper);
    }
}

void Encode_ID3D12Device5_CreateStateObject(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_STATE_OBJECT_DESC* pDesc,
    REFIID riid,
    void** ppStateObject)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_CreateStateObject, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppStateObject, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppStateObject, wrapper);
    }
}

void Encode_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
    ID3D12Device5_Wrapper* wrapper,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStructPtr(encoder, pInfo);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device5_CheckDriverMatchingIdentifier(
    ID3D12Device5_Wrapper* wrapper,
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS return_value,
    D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
    const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(SerializedDataType);
        EncodeStructPtr(encoder, pIdentifierToCheck);
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_AUTO_BREADCRUMB_NODE& value)
{
    encoder->EncodeString(value.pCommandListDebugNameA);
    encoder->EncodeWString(value.pCommandListDebugNameW);
    encoder->EncodeString(value.pCommandQueueDebugNameA);
    encoder->EncodeWString(value.pCommandQueueDebugNameW);
    encoder->EncodeObjectValue(value.pCommandList);
    encoder->EncodeObjectValue(value.pCommandQueue);
    encoder->EncodeUInt32Value(value.BreadcrumbCount);
    encoder->EncodeUInt32Ptr(value.pLastBreadcrumbValue);
    encoder->EncodeEnumArray(value.pCommandHistory, value.BreadcrumbCount);
    EncodeStructPtr(encoder, value.pNext);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_BREADCRUMB_CONTEXT& value)
{
    encoder->EncodeUInt32Value(value.BreadcrumbIndex);
    encoder->EncodeWString(value.pContextString);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_AUTO_BREADCRUMB_NODE1& value)
{
    encoder->EncodeString(value.pCommandListDebugNameA);
    encoder->EncodeWString(value.pCommandListDebugNameW);
    encoder->EncodeString(value.pCommandQueueDebugNameA);
    encoder->EncodeWString(value.pCommandQueueDebugNameW);
    encoder->EncodeObjectValue(value.pCommandList);
    encoder->EncodeObjectValue(value.pCommandQueue);
    encoder->EncodeUInt32Value(value.BreadcrumbCount);
    encoder->EncodeUInt32Ptr(value.pLastBreadcrumbValue);
    encoder->EncodeEnumArray(value.pCommandHistory, value.BreadcrumbCount);
    EncodeStructPtr(encoder, value.pNext);
    encoder->EncodeUInt32Value(value.BreadcrumbContextsCount);
    EncodeStructArray(encoder, value.pBreadcrumbContexts, value.BreadcrumbContextsCount);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA& value)
{
    encoder->EncodeEnumValue(value.Flags);
    EncodeStructPtr(encoder, value.pHeadAutoBreadcrumbNode);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_ALLOCATION_NODE& value)
{
    encoder->EncodeString(value.ObjectNameA);
    encoder->EncodeWString(value.ObjectNameW);
    encoder->EncodeEnumValue(value.AllocationType);
    EncodeStructPtr(encoder, value.pNext);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_ALLOCATION_NODE1& value)
{
    encoder->EncodeString(value.ObjectNameA);
    encoder->EncodeWString(value.ObjectNameW);
    encoder->EncodeEnumValue(value.AllocationType);
    EncodeStructPtr(encoder, value.pNext);
    encoder->EncodeObjectValue(value.pObject);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& value)
{
    EncodeStructPtr(encoder, value.pHeadAutoBreadcrumbNode);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& value)
{
    EncodeStructPtr(encoder, value.pHeadAutoBreadcrumbNode);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_PAGE_FAULT_OUTPUT& value)
{
    encoder->EncodeUInt64Value(value.PageFaultVA);
    EncodeStructPtr(encoder, value.pHeadExistingAllocationNode);
    EncodeStructPtr(encoder, value.pHeadRecentFreedAllocationNode);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_PAGE_FAULT_OUTPUT1& value)
{
    encoder->EncodeUInt64Value(value.PageFaultVA);
    EncodeStructPtr(encoder, value.pHeadExistingAllocationNode);
    EncodeStructPtr(encoder, value.pHeadRecentFreedAllocationNode);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_PAGE_FAULT_OUTPUT2& value)
{
    encoder->EncodeUInt64Value(value.PageFaultVA);
    EncodeStructPtr(encoder, value.pHeadExistingAllocationNode);
    EncodeStructPtr(encoder, value.pHeadRecentFreedAllocationNode);
    encoder->EncodeEnumValue(value.PageFaultFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& value)
{
    encoder->EncodeInt32Value(value.DeviceRemovedReason);
    EncodeStruct(encoder, value.AutoBreadcrumbsOutput);
    EncodeStruct(encoder, value.PageFaultOutput);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& value)
{
    encoder->EncodeInt32Value(value.DeviceRemovedReason);
    EncodeStruct(encoder, value.AutoBreadcrumbsOutput);
    EncodeStruct(encoder, value.PageFaultOutput);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& value)
{
    encoder->EncodeInt32Value(value.DeviceRemovedReason);
    EncodeStruct(encoder, value.AutoBreadcrumbsOutput);
    EncodeStruct(encoder, value.PageFaultOutput);
    encoder->EncodeEnumValue(value.DeviceState);
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
    ID3D12DeviceRemovedExtendedDataSettings1_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(
    ID3D12DeviceRemovedExtendedDataSettings2_Wrapper* wrapper,
    BOOL MarkersOnly)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(MarkersOnly);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    ID3D12DeviceRemovedExtendedData_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    ID3D12DeviceRemovedExtendedData_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    ID3D12DeviceRemovedExtendedData1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    ID3D12DeviceRemovedExtendedData1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(
    ID3D12DeviceRemovedExtendedData2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_PAGE_FAULT_OUTPUT2* pOutput)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pOutput, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceRemovedExtendedData2_GetDeviceState(
    ID3D12DeviceRemovedExtendedData2_Wrapper* wrapper,
    D3D12_DRED_DEVICE_STATE return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData2_GetDeviceState, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device6_SetBackgroundProcessingMode(
    ID3D12Device6_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_BACKGROUND_PROCESSING_MODE Mode,
    D3D12_MEASUREMENTS_ACTION MeasurementsAction,
    HANDLE hEventToSignalUponCompletion,
    BOOL* pbFurtherMeasurementsDesired)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Mode);
        encoder->EncodeEnumValue(MeasurementsAction);
        encoder->EncodeVoidPtr(hEventToSignalUponCompletion);
        encoder->EncodeInt32Ptr(pbFurtherMeasurementsDesired, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& value)
{
    encoder->EncodeUInt32Value(value.NodeIndex);
    encoder->EncodeUInt32Value(value.Count);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& value)
{
    encoder->EncodeUInt32Value(value.NodeIndex);
    encoder->EncodeUInt32Value(value.Count);
    EncodeStructArray(encoder, value.pTypes, value.Count);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& value)
{
    encoder->EncodeUInt32Value(value.NodeMask);
    encoder->EncodeEnumValue(value.Flags);
    EncodeStruct(encoder, value.ProtectionType);
}

void Encode_ID3D12ProtectedResourceSession1_GetDesc1(
    ID3D12ProtectedResourceSession1_Wrapper* wrapper,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession1_GetDesc1, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device7_AddToStateObject(
    ID3D12Device7_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_STATE_OBJECT_DESC* pAddition,
    ID3D12StateObject* pStateObjectToGrowFrom,
    REFIID riid,
    void** ppNewStateObject)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device7_AddToStateObject, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pAddition);
        encoder->EncodeObjectValue(pStateObjectToGrowFrom);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppNewStateObject, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppNewStateObject, wrapper);
    }
}

void Encode_ID3D12Device7_CreateProtectedResourceSession1(
    ID3D12Device7_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
    REFIID riid,
    void** ppSession)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device7_CreateProtectedResourceSession1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppSession, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppSession, wrapper);
    }
}

void Encode_ID3D12Device8_GetResourceAllocationInfo2(
    ID3D12Device8_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC1* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device8_GetResourceAllocationInfo2, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(visibleMask);
        encoder->EncodeUInt32Value(numResourceDescs);
        EncodeStructArray(encoder, pResourceDescs, numResourceDescs);
        EncodeStructArray(encoder, pResourceAllocationInfo1, numResourceDescs);
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device8_CreateCommittedResource2(
    ID3D12Device8_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riidResource,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device8_CreateCommittedResource2, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumValue(HeapFlags);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialResourceState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        encoder->EncodeObjectValue(pProtectedSession);
        EncodeStruct(encoder, riidResource);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riidResource, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device8_CreatePlacedResource1(
    ID3D12Device8_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device8_CreatePlacedResource1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pHeap);
        encoder->EncodeUInt64Value(HeapOffset);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    ID3D12Device8_Wrapper* wrapper,
    ID3D12Resource* pTargetedResource,
    ID3D12Resource* pFeedbackResource,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pTargetedResource);
        encoder->EncodeObjectValue(pFeedbackResource);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device8_GetCopyableFootprints1(
    ID3D12Device8_Wrapper* wrapper,
    const D3D12_RESOURCE_DESC1* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device8_GetCopyableFootprints1, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pResourceDesc);
        encoder->EncodeUInt32Value(FirstSubresource);
        encoder->EncodeUInt32Value(NumSubresources);
        encoder->EncodeUInt64Value(BaseOffset);
        EncodeStructArray(encoder, pLayouts, NumSubresources);
        encoder->EncodeUInt32Array(pNumRows, NumSubresources);
        encoder->EncodeUInt64Array(pRowSizeInBytes, NumSubresources);
        encoder->EncodeUInt64Ptr(pTotalBytes);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Resource1_GetProtectedResourceSession(
    ID3D12Resource1_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppProtectedSession)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource1_GetProtectedResourceSession, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppProtectedSession, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppProtectedSession, wrapper);
    }
}

void Encode_ID3D12Resource2_GetDesc1(
    ID3D12Resource2_Wrapper* wrapper,
    D3D12_RESOURCE_DESC1 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Resource2_GetDesc1, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Heap1_GetProtectedResourceSession(
    ID3D12Heap1_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppProtectedSession)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Heap1_GetProtectedResourceSession, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppProtectedSession, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppProtectedSession, wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
    ID3D12GraphicsCommandList3_Wrapper* wrapper,
    ID3D12ProtectedResourceSession* pProtectedResourceSession)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pProtectedResourceSession);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList3_SetProtectedResourceSession, pProtectedResourceSession);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& value)
{
    EncodeStruct(encoder, value.ClearValue);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& value)
{
    encoder->EncodeUInt32Value(value.AdditionalWidth);
    encoder->EncodeUInt32Value(value.AdditionalHeight);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& value)
{
    encoder->EncodeUInt32Value(value.SrcSubresource);
    encoder->EncodeUInt32Value(value.DstSubresource);
    encoder->EncodeUInt32Value(value.DstX);
    encoder->EncodeUInt32Value(value.DstY);
    EncodeStruct(encoder, value.SrcRect);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& value)
{
    encoder->EncodeObjectValue(value.pSrcResource);
    encoder->EncodeObjectValue(value.pDstResource);
    encoder->EncodeUInt32Value(value.SubresourceCount);
    EncodeStructArray(encoder, value.pSubresourceParameters, value.SubresourceCount);
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ResolveMode);
    encoder->EncodeInt32Value(value.PreserveResolveSource);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& value)
{
    encoder->EncodeUInt32Value(value.AdditionalWidth);
    encoder->EncodeUInt32Value(value.AdditionalHeight);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_RENDER_TARGET_DESC& value)
{
    EncodeStruct(encoder, value.cpuDescriptor);
    EncodeStruct(encoder, value.BeginningAccess);
    EncodeStruct(encoder, value.EndingAccess);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& value)
{
    EncodeStruct(encoder, value.cpuDescriptor);
    EncodeStruct(encoder, value.DepthBeginningAccess);
    EncodeStruct(encoder, value.StencilBeginningAccess);
    EncodeStruct(encoder, value.DepthEndingAccess);
    EncodeStruct(encoder, value.StencilEndingAccess);
}

void Encode_ID3D12MetaCommand_GetRequiredParameterResourceSize(
    ID3D12MetaCommand_Wrapper* wrapper,
    UINT64 return_value,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT ParameterIndex)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Stage);
        encoder->EncodeUInt32Value(ParameterIndex);
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_RAYS_DESC& value)
{
    EncodeStruct(encoder, value.RayGenerationShaderRecord);
    EncodeStruct(encoder, value.MissShaderTable);
    EncodeStruct(encoder, value.HitGroupTable);
    EncodeStruct(encoder, value.CallableShaderTable);
    encoder->EncodeUInt32Value(value.Width);
    encoder->EncodeUInt32Value(value.Height);
    encoder->EncodeUInt32Value(value.Depth);
}

void Encode_ID3D12GraphicsCommandList4_BeginRenderPass(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    UINT NumRenderTargets,
    const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
    const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumRenderTargets);
        EncodeStructArray(encoder, pRenderTargets, NumRenderTargets);
        EncodeStructPtr(encoder, pDepthStencil);
        encoder->EncodeEnumValue(Flags);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_BeginRenderPass, NumRenderTargets, pRenderTargets, pDepthStencil, Flags);
    }
}

void Encode_ID3D12GraphicsCommandList4_EndRenderPass(
    ID3D12GraphicsCommandList4_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList4_InitializeMetaCommand(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    ID3D12MetaCommand* pMetaCommand,
    const void* pInitializationParametersData,
    SIZE_T InitializationParametersDataSizeInBytes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pMetaCommand);
        encoder->EncodeVoidArray(pInitializationParametersData, InitializationParametersDataSizeInBytes);
        encoder->EncodeSizeTValue(InitializationParametersDataSizeInBytes);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_InitializeMetaCommand, pMetaCommand, pInitializationParametersData, InitializationParametersDataSizeInBytes);
    }
}

void Encode_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    ID3D12MetaCommand* pMetaCommand,
    const void* pExecutionParametersData,
    SIZE_T ExecutionParametersDataSizeInBytes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pMetaCommand);
        encoder->EncodeVoidArray(pExecutionParametersData, ExecutionParametersDataSizeInBytes);
        encoder->EncodeSizeTValue(ExecutionParametersDataSizeInBytes);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_ExecuteMetaCommand, pMetaCommand, pExecutionParametersData, ExecutionParametersDataSizeInBytes);
    }
}

void Encode_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
    UINT NumPostbuildInfoDescs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeUInt32Value(NumPostbuildInfoDescs);
        EncodeStructArray(encoder, pPostbuildInfoDescs, NumPostbuildInfoDescs);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure, pDesc, NumPostbuildInfoDescs, pPostbuildInfoDescs);
    }
}

void Encode_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
    UINT NumSourceAccelerationStructures,
    const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeUInt32Value(NumSourceAccelerationStructures);
        encoder->EncodeUInt64Array(pSourceAccelerationStructureData, NumSourceAccelerationStructures);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo, pDesc, NumSourceAccelerationStructures, pSourceAccelerationStructureData);
    }
}

void Encode_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(DestAccelerationStructureData);
        encoder->EncodeUInt64Value(SourceAccelerationStructureData);
        encoder->EncodeEnumValue(Mode);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure, DestAccelerationStructureData, SourceAccelerationStructureData, Mode);
    }
}

void Encode_ID3D12GraphicsCommandList4_SetPipelineState1(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    ID3D12StateObject* pStateObject)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pStateObject);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_SetPipelineState1, pStateObject);
    }
}

void Encode_ID3D12GraphicsCommandList4_DispatchRays(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    const D3D12_DISPATCH_RAYS_DESC* pDesc)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_DispatchRays, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList4_DispatchRays, pDesc);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SHADER_CACHE_SESSION_DESC& value)
{
    EncodeStruct(encoder, value.Identifier);
    encoder->EncodeEnumValue(value.Mode);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.MaximumInMemoryCacheSizeBytes);
    encoder->EncodeUInt32Value(value.MaximumInMemoryCacheEntries);
    encoder->EncodeUInt32Value(value.MaximumValueFileSizeBytes);
    encoder->EncodeUInt64Value(value.Version);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BARRIER_SUBRESOURCE_RANGE& value)
{
    encoder->EncodeUInt32Value(value.IndexOrFirstMipLevel);
    encoder->EncodeUInt32Value(value.NumMipLevels);
    encoder->EncodeUInt32Value(value.FirstArraySlice);
    encoder->EncodeUInt32Value(value.NumArraySlices);
    encoder->EncodeUInt32Value(value.FirstPlane);
    encoder->EncodeUInt32Value(value.NumPlanes);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GLOBAL_BARRIER& value)
{
    encoder->EncodeEnumValue(value.SyncBefore);
    encoder->EncodeEnumValue(value.SyncAfter);
    encoder->EncodeEnumValue(value.AccessBefore);
    encoder->EncodeEnumValue(value.AccessAfter);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXTURE_BARRIER& value)
{
    encoder->EncodeEnumValue(value.SyncBefore);
    encoder->EncodeEnumValue(value.SyncAfter);
    encoder->EncodeEnumValue(value.AccessBefore);
    encoder->EncodeEnumValue(value.AccessAfter);
    encoder->EncodeEnumValue(value.LayoutBefore);
    encoder->EncodeEnumValue(value.LayoutAfter);
    encoder->EncodeObjectValue(value.pResource);
    EncodeStruct(encoder, value.Subresources);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_BARRIER& value)
{
    encoder->EncodeEnumValue(value.SyncBefore);
    encoder->EncodeEnumValue(value.SyncAfter);
    encoder->EncodeEnumValue(value.AccessBefore);
    encoder->EncodeEnumValue(value.AccessAfter);
    encoder->EncodeObjectValue(value.pResource);
    encoder->EncodeUInt64Value(value.Offset);
    encoder->EncodeUInt64Value(value.Size);
}

void Encode_ID3D12ShaderCacheSession_FindValue(
    ID3D12ShaderCacheSession_Wrapper* wrapper,
    HRESULT return_value,
    const void* pKey,
    UINT KeySize,
    void* pValue,
    UINT* pValueSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_FindValue, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidArray(pKey, KeySize);
        encoder->EncodeUInt32Value(KeySize);
        encoder->EncodeVoidArray(pValue, (pValueSize != nullptr) ? *pValueSize : 0, omit_output_data);
        encoder->EncodeUInt32Ptr(pValueSize, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12ShaderCacheSession_StoreValue(
    ID3D12ShaderCacheSession_Wrapper* wrapper,
    HRESULT return_value,
    const void* pKey,
    UINT KeySize,
    const void* pValue,
    UINT ValueSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_StoreValue, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidArray(pKey, KeySize);
        encoder->EncodeUInt32Value(KeySize);
        encoder->EncodeVoidArray(pValue, ValueSize);
        encoder->EncodeUInt32Value(ValueSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12ShaderCacheSession_SetDeleteOnDestroy(
    ID3D12ShaderCacheSession_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_SetDeleteOnDestroy, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12ShaderCacheSession_GetDesc(
    ID3D12ShaderCacheSession_Wrapper* wrapper,
    D3D12_SHADER_CACHE_SESSION_DESC return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ShaderCacheSession_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device9_CreateShaderCacheSession(
    ID3D12Device9_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_SHADER_CACHE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppvSession)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device9_CreateShaderCacheSession, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvSession, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvSession, wrapper);
    }
}

void Encode_ID3D12Device9_ShaderCacheControl(
    ID3D12Device9_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_SHADER_CACHE_KIND_FLAGS Kinds,
    D3D12_SHADER_CACHE_CONTROL_FLAGS Control)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device9_ShaderCacheControl, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Kinds);
        encoder->EncodeEnumValue(Control);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Device9_CreateCommandQueue1(
    ID3D12Device9_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID CreatorID,
    REFIID riid,
    void** ppCommandQueue)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device9_CreateCommandQueue1, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, CreatorID);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppCommandQueue, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppCommandQueue, wrapper);
    }
}

void Encode_ID3D12Device10_CreateCommittedResource3(
    ID3D12Device10_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_BARRIER_LAYOUT InitialLayout,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    UINT32 NumCastableFormats,
    const DXGI_FORMAT* pCastableFormats,
    REFIID riidResource,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device10_CreateCommittedResource3, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumValue(HeapFlags);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialLayout);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        encoder->EncodeObjectValue(pProtectedSession);
        encoder->EncodeUInt32Value(NumCastableFormats);
        encoder->EncodeEnumArray(pCastableFormats, NumCastableFormats);
        EncodeStruct(encoder, riidResource);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riidResource, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device10_CreatePlacedResource2(
    ID3D12Device10_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_BARRIER_LAYOUT InitialLayout,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    UINT32 NumCastableFormats,
    const DXGI_FORMAT* pCastableFormats,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device10_CreatePlacedResource2, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pHeap);
        encoder->EncodeUInt64Value(HeapOffset);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialLayout);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        encoder->EncodeUInt32Value(NumCastableFormats);
        encoder->EncodeEnumArray(pCastableFormats, NumCastableFormats);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device10_CreateReservedResource2(
    ID3D12Device10_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_BARRIER_LAYOUT InitialLayout,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    UINT32 NumCastableFormats,
    const DXGI_FORMAT* pCastableFormats,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device10_CreateReservedResource2, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialLayout);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        encoder->EncodeObjectValue(pProtectedSession);
        encoder->EncodeUInt32Value(NumCastableFormats);
        encoder->EncodeEnumArray(pCastableFormats, NumCastableFormats);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvResource, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvResource, wrapper);
    }
}

void Encode_ID3D12Device11_CreateSampler2(
    ID3D12Device11_Wrapper* wrapper,
    const D3D12_SAMPLER_DESC2* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device11_CreateSampler2, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        D3D12CaptureManager::Get()->EndCreateDescriptorMethodCallCapture(DestDescriptor, wrapper);
    }
}

void Encode_ID3D12Device12_GetResourceAllocationInfo3(
    ID3D12Device12_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC1* pResourceDescs,
    const UINT32* pNumCastableFormats,
    const DXGI_FORMAT* const* ppCastableFormats,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Device12_GetResourceAllocationInfo3, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(visibleMask);
        encoder->EncodeUInt32Value(numResourceDescs);
        EncodeStructArray(encoder, pResourceDescs, numResourceDescs);
        encoder->EncodeUInt32Array(pNumCastableFormats, numResourceDescs);
        encoder->EncodeEnumArray2D(ppCastableFormats, ArraySize2D<UINT, UINT, const D3D12_RESOURCE_DESC1 *, const UINT32 *, const DXGI_FORMAT * const *, D3D12_RESOURCE_ALLOCATION_INFO1 *>(visibleMask, numResourceDescs, pResourceDescs, pNumCastableFormats, ppCastableFormats, pResourceAllocationInfo1));
        EncodeStructArray(encoder, pResourceAllocationInfo1, numResourceDescs);
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12VirtualizationGuestDevice_ShareWithHost(
    ID3D12VirtualizationGuestDevice_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12DeviceChild* pObject,
    HANDLE* pHandle)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_ShareWithHost, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pObject);
        encoder->EncodeVoidPtrPtr(pHandle, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12VirtualizationGuestDevice_CreateFenceFd(
    ID3D12VirtualizationGuestDevice_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* pFence,
    UINT64 FenceValue,
    int* pFenceFd)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12VirtualizationGuestDevice_CreateFenceFd, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pFence);
        encoder->EncodeUInt64Value(FenceValue);
        encoder->EncodeInt32Ptr(pFenceFd, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Tools_EnableShaderInstrumentation(
    ID3D12Tools_Wrapper* wrapper,
    BOOL bEnable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Tools_EnableShaderInstrumentation, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(bEnable);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Tools_ShaderInstrumentationEnabled(
    ID3D12Tools_Wrapper* wrapper,
    BOOL return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Tools_ShaderInstrumentationEnabled, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_DATA& value)
{
    encoder->EncodeVoidPtr(value.pData);
    encoder->EncodeSizeTValue(value.RowPitch);
    encoder->EncodeSizeTValue(value.SlicePitch);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MEMCPY_DEST& value)
{
    encoder->EncodeVoidPtr(value.pData);
    encoder->EncodeSizeTValue(value.RowPitch);
    encoder->EncodeSizeTValue(value.SlicePitch);
}

void Encode_ID3D12SDKConfiguration_SetSDKVersion(
    ID3D12SDKConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    UINT SDKVersion,
    LPCSTR SDKPath)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SDKConfiguration_SetSDKVersion, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(SDKVersion);
        encoder->EncodeString(SDKPath);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SDKConfiguration1_CreateDeviceFactory(
    ID3D12SDKConfiguration1_Wrapper* wrapper,
    HRESULT return_value,
    UINT SDKVersion,
    LPCSTR SDKPath,
    REFIID riid,
    void** ppvFactory)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_CreateDeviceFactory, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(SDKVersion);
        encoder->EncodeString(SDKPath);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvFactory, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvFactory, wrapper);
    }
}

void Encode_ID3D12SDKConfiguration1_FreeUnusedSDKs(
    ID3D12SDKConfiguration1_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SDKConfiguration1_FreeUnusedSDKs, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceFactory_InitializeFromGlobalState(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceFactory_InitializeFromGlobalState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceFactory_ApplyToGlobalState(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceFactory_ApplyToGlobalState, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceFactory_SetFlags(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEVICE_FACTORY_FLAGS flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceFactory_SetFlags, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(flags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceFactory_GetFlags(
    ID3D12DeviceFactory_Wrapper* wrapper,
    D3D12_DEVICE_FACTORY_FLAGS return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetFlags, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceFactory_GetConfigurationInterface(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    REFCLSID clsid,
    REFIID iid,
    void** ppv)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceFactory_GetConfigurationInterface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, clsid);
        EncodeStruct(encoder, iid);
        encoder->EncodeObjectPtr(ppv, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, iid, ppv, wrapper);
    }
}

void Encode_ID3D12DeviceFactory_EnableExperimentalFeatures(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceFactory_EnableExperimentalFeatures, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(NumFeatures);
        EncodeStructArray(encoder, pIIDs, NumFeatures);
        encoder->EncodeVoidArray(pConfigurationStructs, NumFeatures);
        encoder->EncodeUInt32Array(pConfigurationStructSizes, NumFeatures);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceFactory_CreateDevice(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* adapter,
    D3D_FEATURE_LEVEL FeatureLevel,
    REFIID riid,
    void** ppvDevice)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceFactory_CreateDevice, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(adapter);
        encoder->EncodeEnumValue(FeatureLevel);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvDevice, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvDevice, wrapper);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_CONFIGURATION_DESC& value)
{
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.GpuBasedValidationFlags);
    encoder->EncodeUInt32Value(value.SDKVersion);
    encoder->EncodeUInt32Value(value.NumEnabledExperimentalFeatures);
}

void Encode_ID3D12DeviceConfiguration_GetDesc(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    D3D12_DEVICE_CONFIGURATION_DESC return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetDesc, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    GUID* pGuids,
    UINT NumGuids)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructArray(encoder, pGuids, NumGuids, omit_output_data);
        encoder->EncodeUInt32Value(NumGuids);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pDesc,
    ID3DBlob** ppResult,
    ID3DBlob** ppError)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_SerializeVersionedRootSignature, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeObjectPtr(ppResult, omit_output_data);
        encoder->EncodeObjectPtr(ppError, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    const void* pBlob,
    SIZE_T Size,
    REFIID riid,
    void** ppvDeserializer)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeVoidArray(pBlob, Size);
        encoder->EncodeSizeTValue(Size);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvDeserializer, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvDeserializer, wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRate(
    ID3D12GraphicsCommandList5_Wrapper* wrapper,
    D3D12_SHADING_RATE baseShadingRate,
    const D3D12_SHADING_RATE_COMBINER* combiners)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(baseShadingRate);
        encoder->EncodeEnumArray(combiners, D3D12_RS_SET_SHADING_RATE_COMBINER_COUNT);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
    ID3D12GraphicsCommandList5_Wrapper* wrapper,
    ID3D12Resource* shadingRateImage)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(shadingRateImage);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList5_RSSetShadingRateImage, shadingRateImage);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_MESH_ARGUMENTS& value)
{
    encoder->EncodeUInt32Value(value.ThreadGroupCountX);
    encoder->EncodeUInt32Value(value.ThreadGroupCountY);
    encoder->EncodeUInt32Value(value.ThreadGroupCountZ);
}

void Encode_ID3D12GraphicsCommandList6_DispatchMesh(
    ID3D12GraphicsCommandList6_Wrapper* wrapper,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList6_DispatchMesh, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(ThreadGroupCountX);
        encoder->EncodeUInt32Value(ThreadGroupCountY);
        encoder->EncodeUInt32Value(ThreadGroupCountZ);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList7_Barrier(
    ID3D12GraphicsCommandList7_Wrapper* wrapper,
    UINT32 NumBarrierGroups,
    const D3D12_BARRIER_GROUP* pBarrierGroups)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList7_Barrier, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumBarrierGroups);
        EncodeStructArray(encoder, pBarrierGroups, NumBarrierGroups);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper, Track_ID3D12GraphicsCommandList7_Barrier, NumBarrierGroups, pBarrierGroups);
    }
}

void Encode_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(
    ID3D12GraphicsCommandList8_Wrapper* wrapper,
    UINT FrontStencilRef,
    UINT BackStencilRef)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(FrontStencilRef);
        encoder->EncodeUInt32Value(BackStencilRef);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList9_RSSetDepthBias(
    ID3D12GraphicsCommandList9_Wrapper* wrapper,
    FLOAT DepthBias,
    FLOAT DepthBiasClamp,
    FLOAT SlopeScaledDepthBias)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_RSSetDepthBias, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeFloatValue(DepthBias);
        encoder->EncodeFloatValue(DepthBiasClamp);
        encoder->EncodeFloatValue(SlopeScaledDepthBias);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(
    ID3D12GraphicsCommandList9_Wrapper* wrapper,
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(IBStripCutValue);
        D3D12CaptureManager::Get()->EndCommandListMethodCallCapture(wrapper);
    }
}

void Encode_ID3D12DSRDeviceFactory_CreateDSRDevice(
    ID3D12DSRDeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Device* pD3D12Device,
    UINT NodeMask,
    REFIID riid,
    void** ppvDSRDevice)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DSRDeviceFactory_CreateDSRDevice, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeObjectValue(pD3D12Device);
        encoder->EncodeUInt32Value(NodeMask);
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvDSRDevice, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvDSRDevice, wrapper);
    }
}


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const D3D_SHADER_MACRO& value)
{
    encoder->EncodeString(value.Name);
    encoder->EncodeString(value.Definition);
}

void Encode_ID3D10Blob_GetBufferPointer(
    ID3D10Blob_Wrapper* wrapper,
    LPVOID return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D10Blob_GetBufferPointer, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeVoidPtr(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D10Blob_GetBufferSize(
    ID3D10Blob_Wrapper* wrapper,
    SIZE_T return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D10Blob_GetBufferSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeSizeTValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3DDestructionNotifier_RegisterDestructionCallback(
    ID3DDestructionNotifier_Wrapper* wrapper,
    HRESULT return_value,
    PFN_DESTRUCTION_CALLBACK callbackFn,
    void* pData,
    UINT* pCallbackID)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeFunctionPtr(callbackFn);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeUInt32Ptr(pCallbackID, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3DDestructionNotifier_UnregisterDestructionCallback(
    ID3DDestructionNotifier_Wrapper* wrapper,
    HRESULT return_value,
    UINT callbackID)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(callbackID);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_ID3D12Debug_EnableDebugLayer(
    ID3D12Debug_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug_EnableDebugLayer, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug1_EnableDebugLayer(
    ID3D12Debug1_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug1_EnableDebugLayer, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug1_SetEnableGPUBasedValidation(
    ID3D12Debug1_Wrapper* wrapper,
    BOOL Enable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableGPUBasedValidation, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(Enable);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
    ID3D12Debug1_Wrapper* wrapper,
    BOOL Enable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(Enable);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug2_SetGPUBasedValidationFlags(
    ID3D12Debug2_Wrapper* wrapper,
    D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug2_SetGPUBasedValidationFlags, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Flags);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug3_SetEnableGPUBasedValidation(
    ID3D12Debug3_Wrapper* wrapper,
    BOOL Enable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableGPUBasedValidation, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(Enable);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
    ID3D12Debug3_Wrapper* wrapper,
    BOOL Enable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(Enable);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug3_SetGPUBasedValidationFlags(
    ID3D12Debug3_Wrapper* wrapper,
    D3D12_GPU_BASED_VALIDATION_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug3_SetGPUBasedValidationFlags, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Flags);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug4_DisableDebugLayer(
    ID3D12Debug4_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug4_DisableDebugLayer, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug5_SetEnableAutoName(
    ID3D12Debug5_Wrapper* wrapper,
    BOOL Enable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug5_SetEnableAutoName, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(Enable);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12Debug6_SetForceLegacyBarrierValidation(
    ID3D12Debug6_Wrapper* wrapper,
    BOOL Enable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12Debug6_SetForceLegacyBarrierValidation, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(Enable);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& value)
{
    encoder->EncodeUInt32Value(value.MaxMessagesPerCommandList);
    encoder->EncodeEnumValue(value.DefaultShaderPatchMode);
    encoder->EncodeEnumValue(value.PipelineStateCreateFlags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& value)
{
    encoder->EncodeFloatValue(value.SlowdownFactor);
}

void Encode_ID3D12DebugDevice1_SetDebugParameter(
    ID3D12DebugDevice1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice1_SetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugDevice1_GetDebugParameter(
    ID3D12DebugDevice1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice1_GetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize, omit_output_data);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugDevice1_ReportLiveDeviceObjects(
    ID3D12DebugDevice1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_RLDO_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice1_ReportLiveDeviceObjects, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Flags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugDevice_SetFeatureMask(
    ID3D12DebugDevice_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_FEATURE Mask)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice_SetFeatureMask, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Mask);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugDevice_GetFeatureMask(
    ID3D12DebugDevice_Wrapper* wrapper,
    D3D12_DEBUG_FEATURE return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice_GetFeatureMask, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugDevice_ReportLiveDeviceObjects(
    ID3D12DebugDevice_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_RLDO_FLAGS Flags)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice_ReportLiveDeviceObjects, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Flags);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugDevice2_SetDebugParameter(
    ID3D12DebugDevice2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice2_SetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugDevice2_GetDebugParameter(
    ID3D12DebugDevice2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugDevice2_GetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize, omit_output_data);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandQueue_AssertResourceState(
    ID3D12DebugCommandQueue_Wrapper* wrapper,
    BOOL return_value,
    ID3D12Resource* pResource,
    UINT Subresource,
    UINT State)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandQueue_AssertResourceState, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeUInt32Value(State);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandQueue1_AssertResourceAccess(
    ID3D12DebugCommandQueue1_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_ACCESS Access)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertResourceAccess, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeEnumValue(Access);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandQueue1_AssertTextureLayout(
    ID3D12DebugCommandQueue1_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_LAYOUT Layout)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandQueue1_AssertTextureLayout, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeEnumValue(Layout);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& value)
{
    encoder->EncodeEnumValue(value.ShaderPatchMode);
}

void Encode_ID3D12DebugCommandList1_AssertResourceState(
    ID3D12DebugCommandList1_Wrapper* wrapper,
    BOOL return_value,
    ID3D12Resource* pResource,
    UINT Subresource,
    UINT State)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList1_AssertResourceState, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeUInt32Value(State);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList1_SetDebugParameter(
    ID3D12DebugCommandList1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList1_SetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList1_GetDebugParameter(
    ID3D12DebugCommandList1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList1_GetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize, omit_output_data);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList_AssertResourceState(
    ID3D12DebugCommandList_Wrapper* wrapper,
    BOOL return_value,
    ID3D12Resource* pResource,
    UINT Subresource,
    UINT State)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList_AssertResourceState, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeUInt32Value(State);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList_SetFeatureMask(
    ID3D12DebugCommandList_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_FEATURE Mask)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList_SetFeatureMask, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Mask);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList_GetFeatureMask(
    ID3D12DebugCommandList_Wrapper* wrapper,
    D3D12_DEBUG_FEATURE return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList_GetFeatureMask, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList2_SetDebugParameter(
    ID3D12DebugCommandList2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList2_SetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList2_GetDebugParameter(
    ID3D12DebugCommandList2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList2_GetDebugParameter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Type);
        encoder->EncodeVoidArray(pData, DataSize, omit_output_data);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList3_AssertResourceAccess(
    ID3D12DebugCommandList3_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_ACCESS Access)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertResourceAccess, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeEnumValue(Access);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12DebugCommandList3_AssertTextureLayout(
    ID3D12DebugCommandList3_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_LAYOUT Layout)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12DebugCommandList3_AssertTextureLayout, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeEnumValue(Layout);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SharingContract_Present(
    ID3D12SharingContract_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    HWND window)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SharingContract_Present, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pResource);
        encoder->EncodeUInt32Value(Subresource);
        encoder->EncodeVoidPtr(window);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SharingContract_SharedFenceSignal(
    ID3D12SharingContract_Wrapper* wrapper,
    ID3D12Fence* pFence,
    UINT64 FenceValue)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SharingContract_SharedFenceSignal, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeObjectValue(pFence);
        encoder->EncodeUInt64Value(FenceValue);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SharingContract_BeginCapturableWork(
    ID3D12SharingContract_Wrapper* wrapper,
    REFGUID guid)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SharingContract_BeginCapturableWork, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, guid);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12SharingContract_EndCapturableWork(
    ID3D12SharingContract_Wrapper* wrapper,
    REFGUID guid)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12SharingContract_EndCapturableWork, wrapper->GetCaptureId());
    if(encoder)
    {
        EncodeStruct(encoder, guid);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12ManualWriteTrackingResource_TrackWrite(
    ID3D12ManualWriteTrackingResource_Wrapper* wrapper,
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12ManualWriteTrackingResource_TrackWrite, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(Subresource);
        EncodeStructPtr(encoder, pWrittenRange);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MESSAGE& value)
{
    encoder->EncodeEnumValue(value.Category);
    encoder->EncodeEnumValue(value.Severity);
    encoder->EncodeEnumValue(value.ID);
    encoder->EncodeString(value.pDescription);
    encoder->EncodeSizeTValue(value.DescriptionByteLength);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INFO_QUEUE_FILTER_DESC& value)
{
    encoder->EncodeUInt32Value(value.NumCategories);
    encoder->EncodeEnumArray(value.pCategoryList, value.NumCategories);
    encoder->EncodeUInt32Value(value.NumSeverities);
    encoder->EncodeEnumArray(value.pSeverityList, value.NumSeverities);
    encoder->EncodeUInt32Value(value.NumIDs);
    encoder->EncodeEnumArray(value.pIDList, value.NumIDs);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INFO_QUEUE_FILTER& value)
{
    EncodeStruct(encoder, value.AllowList);
    EncodeStruct(encoder, value.DenyList);
}

void Encode_ID3D12InfoQueue_SetMessageCountLimit(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 MessageCountLimit)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMessageCountLimit, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Value(MessageCountLimit);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_ClearStoredMessages(
    ID3D12InfoQueue_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStoredMessages, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetMessage(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 MessageIndex,
    D3D12_MESSAGE* pMessage,
    SIZE_T* pMessageByteLength)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessage, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt64Value(MessageIndex);
        EncodeStructArray(encoder, pMessage, ((pMessageByteLength == nullptr) ? 0 : *pMessageByteLength), omit_output_data);
        encoder->EncodeSizeTPtr(pMessageByteLength, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetNumStoredMessages(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessages, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetMessageCountLimit(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMessageCountLimit, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt64Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_AddStorageFilterEntries(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_AddStorageFilterEntries, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pFilter);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter,
    SIZE_T* pFilterByteLength)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructArray(encoder, pFilter, ((pFilterByteLength == nullptr) ? 0 : *pFilterByteLength), omit_output_data);
        encoder->EncodeSizeTPtr(pFilterByteLength, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_ClearStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PushEmptyStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PushCopyOfStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PushStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PushStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pFilter);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PopStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PopStorageFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetStorageFilterStackSize(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetStorageFilterStackSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_AddRetrievalFilterEntries(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_AddRetrievalFilterEntries, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pFilter);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter,
    SIZE_T* pFilterByteLength)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructArray(encoder, pFilter, ((pFilterByteLength == nullptr) ? 0 : *pFilterByteLength), omit_output_data);
        encoder->EncodeSizeTPtr(pFilterByteLength, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_ClearRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_ClearRetrievalFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PushEmptyRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PushEmptyRetrievalFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PushCopyOfRetrievalFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PushRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PushRetrievalFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStructPtr(encoder, pFilter);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_PopRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_PopRetrievalFilter, wrapper->GetCaptureId());
    if(encoder)
    {
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetRetrievalFilterStackSize(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetRetrievalFilterStackSize, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_AddMessage(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_CATEGORY Category,
    D3D12_MESSAGE_SEVERITY Severity,
    D3D12_MESSAGE_ID ID,
    LPCSTR pDescription)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_AddMessage, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Category);
        encoder->EncodeEnumValue(Severity);
        encoder->EncodeEnumValue(ID);
        encoder->EncodeString(pDescription);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_AddApplicationMessage(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_SEVERITY Severity,
    LPCSTR pDescription)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_AddApplicationMessage, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Severity);
        encoder->EncodeString(pDescription);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_SetBreakOnCategory(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_CATEGORY Category,
    BOOL bEnable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnCategory, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Category);
        encoder->EncodeInt32Value(bEnable);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_SetBreakOnSeverity(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_SEVERITY Severity,
    BOOL bEnable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnSeverity, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(Severity);
        encoder->EncodeInt32Value(bEnable);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_SetBreakOnID(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_ID ID,
    BOOL bEnable)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_SetBreakOnID, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeEnumValue(ID);
        encoder->EncodeInt32Value(bEnable);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetBreakOnCategory(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value,
    D3D12_MESSAGE_CATEGORY Category)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnCategory, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Category);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetBreakOnSeverity(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value,
    D3D12_MESSAGE_SEVERITY Severity)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnSeverity, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(Severity);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetBreakOnID(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value,
    D3D12_MESSAGE_ID ID)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetBreakOnID, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeEnumValue(ID);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_SetMuteDebugOutput(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL bMute)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_SetMuteDebugOutput, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(bMute);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue_GetMuteDebugOutput(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue_GetMuteDebugOutput, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue1_RegisterMessageCallback(
    ID3D12InfoQueue1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12MessageFunc CallbackFunc,
    D3D12_MESSAGE_CALLBACK_FLAGS CallbackFilterFlags,
    void* pContext,
    DWORD* pCallbackCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue1_RegisterMessageCallback, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeFunctionPtr(CallbackFunc);
        encoder->EncodeEnumValue(CallbackFilterFlags);
        encoder->EncodeVoidPtr(pContext);
        encoder->EncodeUInt32Ptr(pCallbackCookie, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_ID3D12InfoQueue1_UnregisterMessageCallback(
    ID3D12InfoQueue1_Wrapper* wrapper,
    HRESULT return_value,
    DWORD CallbackCookie)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_ID3D12InfoQueue1_UnregisterMessageCallback, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        encoder->EncodeUInt32Value(CallbackCookie);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_IUnknown_QueryInterface(
    IUnknown_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppvObject)
{
    auto encoder = D3D12CaptureManager::Get()->BeginTrackedMethodCallCapture(format::ApiCallId::ApiCall_IUnknown_QueryInterface, wrapper->GetCaptureId());
    if(encoder)
    {
        bool omit_output_data = false;
        if (return_value != S_OK)
        {
            omit_output_data = true;
        }
        EncodeStruct(encoder, riid);
        encoder->EncodeObjectPtr(ppvObject, omit_output_data);
        encoder->EncodeInt32Value(return_value);
        D3D12CaptureManager::Get()->EndCreateMethodCallCapture(return_value, riid, ppvObject, static_cast<IUnknown_Wrapper*>(wrapper));
    }
}

void Encode_IUnknown_AddRef(
    IUnknown_Wrapper* wrapper,
    ULONG return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IUnknown_AddRef, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}

void Encode_IUnknown_Release(
    IUnknown_Wrapper* wrapper,
    ULONG return_value)
{
    auto encoder = D3D12CaptureManager::Get()->BeginMethodCallCapture(format::ApiCallId::ApiCall_IUnknown_Release, wrapper->GetCaptureId());
    if(encoder)
    {
        encoder->EncodeUInt32Value(return_value);
        D3D12CaptureManager::Get()->EndMethodCallCapture();
    }
}


/*
** This part is generated from guiddef.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const GUID& value)
{
    encoder->EncodeUInt32Value(value.Data1);
    encoder->EncodeUInt16Value(value.Data2);
    encoder->EncodeUInt16Value(value.Data3);
    encoder->EncodeUInt8Array(value.Data4, 8);
}


/*
** This part is generated from windef.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const tagRECT& value)
{
    encoder->EncodeInt32Value(value.left);
    encoder->EncodeInt32Value(value.top);
    encoder->EncodeInt32Value(value.right);
    encoder->EncodeInt32Value(value.bottom);
}

void EncodeStruct(ParameterEncoder* encoder, const tagPOINT& value)
{
    encoder->EncodeInt32Value(value.x);
    encoder->EncodeInt32Value(value.y);
}


/*
** This part is generated from minwinbase.h in Windows SDK: 10.0.20348.0
**
*/


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
