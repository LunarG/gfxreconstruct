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
** This file is generated from dx12_api_call_encoders_body_generator.py.
**
*/

#include "generated/generated_dx12_api_call_encoders.h"

#include "encode/custom_encoder_commands.h"
#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/trace_manager.h"
#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodeDxObjectPtr(ParameterEncoder* encoder, void** object, bool omit_output_data)
{
    format::HandleId  device_id = format::kNullHandleId;
    format::HandleId* device_id_ptr = nullptr;
    if ((object != nullptr) && (*object != nullptr))
    {
        //device_id = reinterpret_cast<const IUnknown_Wrapper*>(*object)->GetObjectId();
        device_id_ptr = &device_id;
    }
    // The final version of the encoder would use the address of object as the address that is encoded for the pointer value.
    encoder->EncodeHandleIdPtr(device_id_ptr, omit_output_data);
}

void EncodeDxObjectPtrArray(ParameterEncoder* encoder, void*** value, size_t len, bool omit_data, bool omit_addr)
{
    encoder->EncodeStructArrayPreamble(value, len, omit_data, omit_addr);
    if ((value != nullptr) && (len > 0) && !omit_data)
    {
        for (size_t i = 0; i < len; ++i)
        {
            EncodeDxObjectPtr(encoder, value[i]);
        }
    }
}

/*
** This part is generated from dxgi.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_CreateDXGIFactory(
    HRESULT result,
    REFIID riid,
    void** ppFactory)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_CreateDXGIFactory);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppFactory, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_CreateDXGIFactory1(
    HRESULT result,
    REFIID riid,
    void** ppFactory)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_CreateDXGIFactory1);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppFactory, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_FRAME_STATISTICS& value)
{
    encoder->EncodeUInt32Value(value.PresentCount);
    encoder->EncodeUInt32Value(value.PresentRefreshCount);
    encoder->EncodeUInt32Value(value.SyncRefreshCount);
    encoder->EncodeInt64Value(value.SyncQPCTime.QuadPart);
    encoder->EncodeInt64Value(value.SyncGPUTime.QuadPart);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MAPPED_RECT& value)
{
    encoder->EncodeInt32Value(value.Pitch);
    encoder->EncodeUInt8Ptr(value.pBits);
}

void EncodeStruct(ParameterEncoder* encoder, const LUID& value)
{
    encoder->EncodeUInt32Value(value.LowPart);
    encoder->EncodeInt64Value(value.HighPart);
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
    encoder->EncodeHandleValue(value.Monitor);
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SHARED_RESOURCE& value)
{
    encoder->EncodeHandleValue(value.Handle);
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
    encoder->EncodeHandleValue(value.OutputWindow);
    encoder->EncodeInt32Value(value.Windowed);
    encoder->EncodeEnumValue(value.SwapEffect);
    encoder->EncodeUInt32Value(value.Flags);
}

void Encode_IDXGIObject_SetPrivateData(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID Name,
    UINT DataSize,
    const void* pData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIObject_SetPrivateData, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, Name);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIObject_SetPrivateDataInterface(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID Name,
    const IUnknown* pUnknown)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIObject_SetPrivateDataInterface, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, Name);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(const_cast<IUnknown**>(&pUnknown)));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIObject_GetPrivateData(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID Name,
    UINT* pDataSize,
    void* pData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIObject_GetPrivateData, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, Name);
        encoder->EncodeUInt32Ptr(pDataSize);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIObject_GetParent(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppParent)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIObject_GetParent, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppParent, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDeviceSubObject_GetDevice(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppDevice)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDeviceSubObject_GetDevice, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppDevice, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIResource_GetSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE* pSharedHandle)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIResource_GetSharedHandle, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandlePtr(pSharedHandle);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIResource_GetUsage(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_USAGE* pUsage)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIResource_GetUsage, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pUsage);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIResource_SetEvictionPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT EvictionPriority)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIResource_SetEvictionPriority, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(EvictionPriority);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIResource_GetEvictionPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pEvictionPriority)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIResource_GetEvictionPriority, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pEvictionPriority);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIKeyedMutex_AcquireSync(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Key,
    DWORD dwMilliseconds)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIKeyedMutex_AcquireSync, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(Key);
        encoder->EncodeUInt32Value(dwMilliseconds);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIKeyedMutex_ReleaseSync(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Key)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIKeyedMutex_ReleaseSync, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(Key);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISurface_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SURFACE_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISurface_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISurface_Map(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MAPPED_RECT* pLockedRect,
    UINT MapFlags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISurface_Map, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pLockedRect);
        encoder->EncodeUInt32Value(MapFlags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISurface_Unmap(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISurface_Unmap, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISurface1_GetDC(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL Discard,
    HDC* phdc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISurface1_GetDC, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(Discard);
        encoder->EncodeHandlePtr(phdc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISurface1_ReleaseDC(
    format::HandleId wrapper_id,
    HRESULT result,
    RECT* pDirtyRect)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISurface1_ReleaseDC, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDirtyRect);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter_EnumOutputs(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Output,
    IDXGIOutput** ppOutput)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter_EnumOutputs, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Output);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppOutput));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter_CheckInterfaceSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID InterfaceName,
    LARGE_INTEGER* pUMDVersion)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter_CheckInterfaceSupport, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, InterfaceName);
        encoder->EncodeInt64Ptr(&pUMDVersion->QuadPart);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_OUTPUT_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_GetDisplayModeList(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_GetDisplayModeList, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(EnumFormat);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeUInt32Ptr(pNumModes);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_FindClosestMatchingMode(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MODE_DESC* pModeToMatch,
    DXGI_MODE_DESC* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_FindClosestMatchingMode, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pModeToMatch);
        EncodeStructPtr(encoder, pClosestMatch);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pConcernedDevice));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_WaitForVBlank(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_WaitForVBlank, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_TakeOwnership(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    BOOL Exclusive)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_TakeOwnership, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        encoder->EncodeInt32Value(Exclusive);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_ReleaseOwnership(
    format::HandleId wrapper_id)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_ReleaseOwnership, wrapper_id);
    if(encoder)
    {
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_GetGammaControlCapabilities(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControlCapabilities, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pGammaCaps);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_SetGammaControl(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_GAMMA_CONTROL* pArray)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_SetGammaControl, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pArray);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_GetGammaControl(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_GAMMA_CONTROL* pArray)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_GetGammaControl, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pArray);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_SetDisplaySurface(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGISurface* pScanoutSurface)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_SetDisplaySurface, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pScanoutSurface));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_GetDisplaySurfaceData(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGISurface* pDestination)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_GetDisplaySurfaceData, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDestination));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput_GetFrameStatistics(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FRAME_STATISTICS* pStats)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput_GetFrameStatistics, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pStats);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_Present(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT SyncInterval,
    UINT Flags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_Present, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(SyncInterval);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_GetBuffer(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Buffer,
    REFIID riid,
    void** ppSurface)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_GetBuffer, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Buffer);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppSurface, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_SetFullscreenState(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL Fullscreen,
    IDXGIOutput* pTarget)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_SetFullscreenState, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(Fullscreen);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pTarget));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_GetFullscreenState(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL* pFullscreen,
    IDXGIOutput** ppTarget)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_GetFullscreenState, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Ptr(pFullscreen);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppTarget));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SWAP_CHAIN_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_ResizeBuffers(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT NewFormat,
    UINT SwapChainFlags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_ResizeBuffers, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(BufferCount);
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeEnumValue(NewFormat);
        encoder->EncodeUInt32Value(SwapChainFlags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_ResizeTarget(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MODE_DESC* pNewTargetParameters)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_ResizeTarget, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pNewTargetParameters);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_GetContainingOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIOutput** ppOutput)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_GetContainingOutput, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppOutput));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_GetFrameStatistics(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FRAME_STATISTICS* pStats)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_GetFrameStatistics, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pStats);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain_GetLastPresentCount(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pLastPresentCount)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain_GetLastPresentCount, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pLastPresentCount);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory_EnumAdapters(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Adapter,
    IDXGIAdapter** ppAdapter)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory_EnumAdapters, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Adapter);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppAdapter));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory_MakeWindowAssociation(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND WindowHandle,
    UINT Flags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory_MakeWindowAssociation, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(WindowHandle);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory_GetWindowAssociation(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND* pWindowHandle)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory_GetWindowAssociation, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandlePtr(pWindowHandle);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory_CreateSwapChain(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory_CreateSwapChain, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        EncodeStructPtr(encoder, pDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSwapChain));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory_CreateSoftwareAdapter(
    format::HandleId wrapper_id,
    HRESULT result,
    HMODULE Module,
    IDXGIAdapter** ppAdapter)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory_CreateSoftwareAdapter, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(Module);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppAdapter));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice_GetAdapter(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIAdapter** pAdapter)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice_GetAdapter, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pAdapter));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice_CreateSurface(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_SURFACE_DESC* pDesc,
    UINT NumSurfaces,
    DXGI_USAGE Usage,
    const DXGI_SHARED_RESOURCE* pSharedResource,
    IDXGISurface** ppSurface)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice_CreateSurface, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeUInt32Value(NumSurfaces);
        encoder->EncodeUInt32Value(Usage);
        EncodeStructPtr(encoder, pSharedResource);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSurface));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice_QueryResourceResidency(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* const* ppResources,
    DXGI_RESIDENCY* pResidencyStatus,
    UINT NumResources)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice_QueryResourceResidency, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<IUnknown***>(&ppResources)), NumResources );
        encoder->EncodeEnumArray(pResidencyStatus, NumResources );
        encoder->EncodeUInt32Value(NumResources);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice_SetGPUThreadPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    INT Priority)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice_SetGPUThreadPriority, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(Priority);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice_GetGPUThreadPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    INT* pPriority)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice_GetGPUThreadPriority, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Ptr(pPriority);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Adapter,
    IDXGIAdapter1** ppAdapter)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory1_EnumAdapters1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Adapter);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppAdapter));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory1_IsCurrent(
    format::HandleId wrapper_id,
    BOOL result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory1_IsCurrent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter1_GetDesc1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC1* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter1_GetDesc1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice1_SetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT MaxLatency)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice1_SetMaximumFrameLatency, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(MaxLatency);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice1_GetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pMaxLatency)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice1_GetMaximumFrameLatency, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pMaxLatency);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_IDXGIDisplayControl_IsStereoEnabled(
    format::HandleId wrapper_id,
    BOOL result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDisplayControl_IsStereoEnabled, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDisplayControl_SetStereoEnabled(
    format::HandleId wrapper_id,
    BOOL enabled)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDisplayControl_SetStereoEnabled, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(enabled);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    encoder->EncodeInt64Value(value.LastPresentTime.QuadPart);
    encoder->EncodeInt64Value(value.LastMouseUpdateTime.QuadPart);
    encoder->EncodeUInt32Value(value.AccumulatedFrames);
    encoder->EncodeInt32Value(value.RectsCoalesced);
    encoder->EncodeInt32Value(value.ProtectedContentMaskedOut);
    EncodeStruct(encoder, value.PointerPosition);
    encoder->EncodeUInt32Value(value.TotalMetadataBufferSize);
    encoder->EncodeUInt32Value(value.PointerShapeBufferSize);
}

void Encode_IDXGIOutputDuplication_GetDesc(
    format::HandleId wrapper_id,
    DXGI_OUTDUPL_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutputDuplication_AcquireNextFrame(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT TimeoutInMilliseconds,
    DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
    IDXGIResource** ppDesktopResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_AcquireNextFrame, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(TimeoutInMilliseconds);
        EncodeStructPtr(encoder, pFrameInfo);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppDesktopResource));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutputDuplication_GetFrameDirtyRects(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT DirtyRectsBufferSize,
    RECT* pDirtyRectsBuffer,
    UINT* pDirtyRectsBufferSizeRequired)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameDirtyRects, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(DirtyRectsBufferSize);
        EncodeStructPtr(encoder, pDirtyRectsBuffer);
        encoder->EncodeUInt32Ptr(pDirtyRectsBufferSizeRequired);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutputDuplication_GetFrameMoveRects(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT MoveRectsBufferSize,
    DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
    UINT* pMoveRectsBufferSizeRequired)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFrameMoveRects, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(MoveRectsBufferSize);
        EncodeStructPtr(encoder, pMoveRectBuffer);
        encoder->EncodeUInt32Ptr(pMoveRectsBufferSizeRequired);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutputDuplication_GetFramePointerShape(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT PointerShapeBufferSize,
    void* pPointerShapeBuffer,
    UINT* pPointerShapeBufferSizeRequired,
    DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_GetFramePointerShape, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(PointerShapeBufferSize);
        encoder->EncodeVoidPtr(pPointerShapeBuffer);
        encoder->EncodeUInt32Ptr(pPointerShapeBufferSizeRequired);
        EncodeStructPtr(encoder, pPointerShapeInfo);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutputDuplication_MapDesktopSurface(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MAPPED_RECT* pLockedRect)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_MapDesktopSurface, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pLockedRect);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutputDuplication_UnMapDesktopSurface(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_UnMapDesktopSurface, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutputDuplication_ReleaseFrame(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutputDuplication_ReleaseFrame, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISurface2_GetResource(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppParentResource,
    UINT* pSubresourceIndex)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISurface2_GetResource, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppParentResource, FAILED(result));
        encoder->EncodeUInt32Ptr(pSubresourceIndex);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIResource1_CreateSubresourceSurface(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT index,
    IDXGISurface2** ppSurface)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIResource1_CreateSubresourceSurface, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(index);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSurface));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIResource1_CreateSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD dwAccess,
    LPCWSTR lpName,
    HANDLE* pHandle)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIResource1_CreateSharedHandle, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pAttributes);
        encoder->EncodeUInt32Value(dwAccess);
        encoder->EncodeWString(lpName);
        encoder->EncodeHandlePtr(pHandle);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice2_OfferResources(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice2_OfferResources, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumResources);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<IDXGIResource***>(&ppResources)), NumResources );
        encoder->EncodeEnumValue(Priority);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice2_ReclaimResources(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    BOOL* pDiscarded)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice2_ReclaimResources, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumResources);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<IDXGIResource***>(&ppResources)), NumResources );
        encoder->EncodeInt32Array(pDiscarded, NumResources );
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice2_EnqueueSetEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice2_EnqueueSetEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SWAP_CHAIN_DESC1* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_GetDesc1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_GetFullscreenDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_GetFullscreenDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_GetHwnd(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND* pHwnd)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_GetHwnd, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandlePtr(pHwnd);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_GetCoreWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID refiid,
    void** ppUnk)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_GetCoreWindow, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, refiid);
        EncodeDxObjectPtr(encoder, ppUnk, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_Present1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT SyncInterval,
    UINT PresentFlags,
    const DXGI_PRESENT_PARAMETERS* pPresentParameters)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_Present1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(SyncInterval);
        encoder->EncodeUInt32Value(PresentFlags);
        EncodeStructPtr(encoder, pPresentParameters);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_IsTemporaryMonoSupported(
    format::HandleId wrapper_id,
    BOOL result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_IsTemporaryMonoSupported, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_GetRestrictToOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIOutput** ppRestrictToOutput)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_GetRestrictToOutput, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppRestrictToOutput));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_SetBackgroundColor(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_RGBA* pColor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_SetBackgroundColor, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pColor);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_GetBackgroundColor(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_RGBA* pColor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_GetBackgroundColor, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pColor);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_SetRotation(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MODE_ROTATION Rotation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_SetRotation, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Rotation);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain1_GetRotation(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MODE_ROTATION* pRotation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain1_GetRotation, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumPtr(pRotation);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_IsWindowedStereoEnabled(
    format::HandleId wrapper_id,
    BOOL result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_IsWindowedStereoEnabled, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_CreateSwapChainForHwnd(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    HWND hWnd,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForHwnd, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        encoder->EncodeHandleValue(hWnd);
        EncodeStructPtr(encoder, pDesc);
        EncodeStructPtr(encoder, pFullscreenDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRestrictToOutput));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSwapChain));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_CreateSwapChainForCoreWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    IUnknown* pWindow,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForCoreWindow, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pWindow));
        EncodeStructPtr(encoder, pDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRestrictToOutput));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSwapChain));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_GetSharedResourceAdapterLuid(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hResource,
    LUID* pLuid)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_GetSharedResourceAdapterLuid, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hResource);
        EncodeStructPtr(encoder, pLuid);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_RegisterStereoStatusWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusWindow, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(WindowHandle);
        encoder->EncodeUInt32Value(wMsg);
        encoder->EncodeUInt32Ptr(pdwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_RegisterStereoStatusEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterStereoStatusEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_UnregisterStereoStatus(
    format::HandleId wrapper_id,
    DWORD dwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterStereoStatus, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_RegisterOcclusionStatusWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusWindow, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(WindowHandle);
        encoder->EncodeUInt32Value(wMsg);
        encoder->EncodeUInt32Ptr(pdwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_RegisterOcclusionStatusEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_RegisterOcclusionStatusEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_UnregisterOcclusionStatus(
    format::HandleId wrapper_id,
    DWORD dwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_UnregisterOcclusionStatus, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory2_CreateSwapChainForComposition(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory2_CreateSwapChainForComposition, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        EncodeStructPtr(encoder, pDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRestrictToOutput));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSwapChain));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC2* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter2_GetDesc2, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput1_GetDisplayModeList1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC1* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplayModeList1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(EnumFormat);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeUInt32Ptr(pNumModes);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput1_FindClosestMatchingMode1(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MODE_DESC1* pModeToMatch,
    DXGI_MODE_DESC1* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput1_FindClosestMatchingMode1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pModeToMatch);
        EncodeStructPtr(encoder, pClosestMatch);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pConcernedDevice));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput1_GetDisplaySurfaceData1(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIResource* pDestination)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput1_GetDisplaySurfaceData1, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDestination));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput1_DuplicateOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    IDXGIOutputDuplication** ppOutputDuplication)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput1_DuplicateOutput, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppOutputDuplication));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_CreateDXGIFactory2(
    HRESULT result,
    UINT Flags,
    REFIID riid,
    void** ppFactory)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_CreateDXGIFactory2);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Flags);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppFactory, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_DXGIGetDebugInterface1(
    HRESULT result,
    UINT Flags,
    REFIID riid,
    void** pDebug)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_DXGIGetDebugInterface1);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Flags);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, pDebug, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_IDXGIDevice3_Trim(
    format::HandleId wrapper_id)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice3_Trim, wrapper_id);
    if(encoder)
    {
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Width,
    UINT Height)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain2_SetSourceSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain2_GetSourceSize(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pWidth,
    UINT* pHeight)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain2_GetSourceSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pWidth);
        encoder->EncodeUInt32Ptr(pHeight);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain2_SetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT MaxLatency)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain2_SetMaximumFrameLatency, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(MaxLatency);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain2_GetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pMaxLatency)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain2_GetMaximumFrameLatency, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pMaxLatency);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    format::HandleId wrapper_id,
    HANDLE result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain2_GetFrameLatencyWaitableObject, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain2_SetMatrixTransform(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MATRIX_3X2_F* pMatrix)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain2_SetMatrixTransform, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pMatrix);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain2_GetMatrixTransform(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MATRIX_3X2_F* pMatrix)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain2_GetMatrixTransform, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pMatrix);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput2_SupportsOverlays(
    format::HandleId wrapper_id,
    BOOL result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput2_SupportsOverlays, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory3_GetCreationFlags(
    format::HandleId wrapper_id,
    UINT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory3_GetCreationFlags, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_DECODE_SWAP_CHAIN_DESC& value)
{
    encoder->EncodeUInt32Value(value.Flags);
}

void Encode_IDXGIDecodeSwapChain_PresentBuffer(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT BufferToPresent,
    UINT SyncInterval,
    UINT Flags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_PresentBuffer, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(BufferToPresent);
        encoder->EncodeUInt32Value(SyncInterval);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_SetSourceRect(
    format::HandleId wrapper_id,
    HRESULT result,
    const RECT* pRect)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetSourceRect, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pRect);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_SetTargetRect(
    format::HandleId wrapper_id,
    HRESULT result,
    const RECT* pRect)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetTargetRect, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pRect);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_SetDestSize(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Width,
    UINT Height)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetDestSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_GetSourceRect(
    format::HandleId wrapper_id,
    HRESULT result,
    RECT* pRect)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetSourceRect, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pRect);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_GetTargetRect(
    format::HandleId wrapper_id,
    HRESULT result,
    RECT* pRect)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetTargetRect, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pRect);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_GetDestSize(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pWidth,
    UINT* pHeight)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetDestSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pWidth);
        encoder->EncodeUInt32Ptr(pHeight);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_SetColorSpace(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_SetColorSpace, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(ColorSpace);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDecodeSwapChain_GetColorSpace(
    format::HandleId wrapper_id,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDecodeSwapChain_GetColorSpace, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    HANDLE hSurface,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        encoder->EncodeHandleValue(hSurface);
        EncodeStructPtr(encoder, pDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRestrictToOutput));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSwapChain));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    HANDLE hSurface,
    DXGI_DECODE_SWAP_CHAIN_DESC* pDesc,
    IDXGIResource* pYuvDecodeBuffers,
    IDXGIOutput* pRestrictToOutput,
    IDXGIDecodeSwapChain** ppSwapChain)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        encoder->EncodeHandleValue(hSurface);
        EncodeStructPtr(encoder, pDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pYuvDecodeBuffers));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRestrictToOutput));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppSwapChain));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_FRAME_STATISTICS_MEDIA& value)
{
    encoder->EncodeUInt32Value(value.PresentCount);
    encoder->EncodeUInt32Value(value.PresentRefreshCount);
    encoder->EncodeUInt32Value(value.SyncRefreshCount);
    encoder->EncodeInt64Value(value.SyncQPCTime.QuadPart);
    encoder->EncodeInt64Value(value.SyncGPUTime.QuadPart);
    encoder->EncodeEnumValue(value.CompositionMode);
    encoder->EncodeUInt32Value(value.ApprovedPresentDuration);
}

void Encode_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FRAME_STATISTICS_MEDIA* pStats)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChainMedia_GetFrameStatisticsMedia, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pStats);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChainMedia_SetPresentDuration(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Duration)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChainMedia_SetPresentDuration, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Duration);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChainMedia_CheckPresentDurationSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT DesiredPresentDuration,
    UINT* pClosestSmallerPresentDuration,
    UINT* pClosestLargerPresentDuration)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChainMedia_CheckPresentDurationSupport, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(DesiredPresentDuration);
        encoder->EncodeUInt32Ptr(pClosestSmallerPresentDuration);
        encoder->EncodeUInt32Ptr(pClosestLargerPresentDuration);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput3_CheckOverlaySupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT EnumFormat,
    IUnknown* pConcernedDevice,
    UINT* pFlags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput3_CheckOverlaySupport, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(EnumFormat);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pConcernedDevice));
        encoder->EncodeUInt32Ptr(pFlags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_IDXGISwapChain3_GetCurrentBackBufferIndex(
    format::HandleId wrapper_id,
    UINT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain3_GetCurrentBackBufferIndex, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain3_CheckColorSpaceSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    UINT* pColorSpaceSupport)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain3_CheckColorSpaceSupport, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(ColorSpace);
        encoder->EncodeUInt32Ptr(pColorSpaceSupport);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain3_SetColorSpace1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain3_SetColorSpace1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(ColorSpace);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGISwapChain3_ResizeBuffers1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT Format,
    UINT SwapChainFlags,
    const UINT* pCreationNodeMask,
    IUnknown* const* ppPresentQueue)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain3_ResizeBuffers1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(BufferCount);
        encoder->EncodeUInt32Value(Width);
        encoder->EncodeUInt32Value(Height);
        encoder->EncodeEnumValue(Format);
        encoder->EncodeUInt32Value(SwapChainFlags);
        encoder->EncodeUInt32Array(pCreationNodeMask, BufferCount);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<IUnknown***>(&ppPresentQueue)), BufferCount);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput4_CheckOverlayColorSpaceSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT Format,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    IUnknown* pConcernedDevice,
    UINT* pFlags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput4_CheckOverlayColorSpaceSupport, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Format);
        encoder->EncodeEnumValue(ColorSpace);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pConcernedDevice));
        encoder->EncodeUInt32Ptr(pFlags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory4_EnumAdapterByLuid(
    format::HandleId wrapper_id,
    HRESULT result,
    LUID AdapterLuid,
    REFIID riid,
    void** ppvAdapter)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory4_EnumAdapterByLuid, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, AdapterLuid);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvAdapter, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory4_EnumWarpAdapter(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppvAdapter)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory4_EnumWarpAdapter, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvAdapter, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
    format::HandleId wrapper_id,
    DWORD dwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter3_QueryVideoMemoryInfo(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter3_QueryVideoMemoryInfo, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NodeIndex);
        encoder->EncodeEnumValue(MemorySegmentGroup);
        EncodeStructPtr(encoder, pVideoMemoryInfo);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter3_SetVideoMemoryReservation(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    UINT64 Reservation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter3_SetVideoMemoryReservation, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NodeIndex);
        encoder->EncodeEnumValue(MemorySegmentGroup);
        encoder->EncodeUInt64Value(Reservation);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
    format::HandleId wrapper_id,
    DWORD dwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_IDXGIOutput5_DuplicateOutput1(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    UINT Flags,
    UINT SupportedFormatsCount,
    const DXGI_FORMAT* pSupportedFormats,
    IDXGIOutputDuplication** ppOutputDuplication)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput5_DuplicateOutput1, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDevice));
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeUInt32Value(SupportedFormatsCount);
        encoder->EncodeEnumPtr(pSupportedFormats);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppOutputDuplication));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_HDR_METADATA_TYPE Type,
    UINT Size,
    void* pMetaData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGISwapChain4_SetHDRMetaData, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(Size);
        encoder->EncodeVoidPtr(pMetaData);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice4_OfferResources1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority,
    UINT Flags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice4_OfferResources1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumResources);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<IDXGIResource***>(&ppResources)), NumResources );
        encoder->EncodeEnumValue(Priority);
        encoder->EncodeUInt32Value(Flags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIDevice4_ReclaimResources1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_RECLAIM_RESOURCE_RESULTS* pResults)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIDevice4_ReclaimResources1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumResources);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<IDXGIResource***>(&ppResources)), NumResources );
        encoder->EncodeEnumArray(pResults, NumResources );
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory5_CheckFeatureSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FEATURE Feature,
    void* pFeatureSupportData,
    UINT FeatureSupportDataSize)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory5_CheckFeatureSupport, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Feature);
        encoder->EncodeVoidPtr(pFeatureSupportData);
        encoder->EncodeUInt32Value(FeatureSupportDataSize);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_DXGIDeclareAdapterRemovalSupport(
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_DXGIDeclareAdapterRemovalSupport);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
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
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC3* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIAdapter4_GetDesc3, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTPUT_DESC1& value)
{
    encoder->EncodeWString(value.DeviceName);
    EncodeStruct(encoder, value.DesktopCoordinates);
    encoder->EncodeInt32Value(value.AttachedToDesktop);
    encoder->EncodeEnumValue(value.Rotation);
    encoder->EncodeHandleValue(value.Monitor);
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
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_OUTPUT_DESC1* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput6_GetDesc1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIOutput6_CheckHardwareCompositionSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pFlags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIOutput6_CheckHardwareCompositionSupport, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pFlags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory6_EnumAdapterByGpuPreference(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Adapter,
    DXGI_GPU_PREFERENCE GpuPreference,
    REFIID riid,
    void** ppvAdapter)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory6_EnumAdapterByGpuPreference, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Adapter);
        encoder->EncodeEnumValue(GpuPreference);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvAdapter, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory7_RegisterAdaptersChangedEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory7_RegisterAdaptersChangedEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeUInt32Ptr(pdwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    DWORD dwCookie)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IDXGIFactory7_UnregisterAdaptersChangedEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(dwCookie);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from dxgicommon.h in Windows SDK: 10.0.19041.0
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
** This part is generated from dxgiformat.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from dxgitype.h in Windows SDK: 10.0.19041.0
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
** This part is generated from d3d12.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_D3D12SerializeRootSignature(
    HRESULT result,
    const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION Version,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12SerializeRootSignature);
    if(encoder)
    {
        EncodeStructPtr(encoder, pRootSignature);
        encoder->EncodeEnumValue(Version);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppBlob));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppErrorBlob));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_D3D12CreateRootSignatureDeserializer(
    HRESULT result,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12CreateRootSignatureDeserializer);
    if(encoder)
    {
        encoder->EncodeVoidPtr(pSrcData);
        encoder->EncodeSizeTValue(SrcDataSizeInBytes);
        EncodeStruct(encoder, pRootSignatureDeserializerInterface);
        EncodeDxObjectPtr(encoder, ppRootSignatureDeserializer, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_D3D12SerializeVersionedRootSignature(
    HRESULT result,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12SerializeVersionedRootSignature);
    if(encoder)
    {
        EncodeStructPtr(encoder, pRootSignature);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppBlob));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppErrorBlob));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_D3D12CreateVersionedRootSignatureDeserializer(
    HRESULT result,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12CreateVersionedRootSignatureDeserializer);
    if(encoder)
    {
        encoder->EncodeVoidPtr(pSrcData);
        encoder->EncodeSizeTValue(SrcDataSizeInBytes);
        EncodeStruct(encoder, pRootSignatureDeserializerInterface);
        EncodeDxObjectPtr(encoder, ppRootSignatureDeserializer, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_D3D12CreateDevice(
    HRESULT result,
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12CreateDevice);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pAdapter));
        encoder->EncodeEnumValue(MinimumFeatureLevel);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppDevice, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_D3D12GetDebugInterface(
    HRESULT result,
    REFIID riid,
    void** ppvDebug)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12GetDebugInterface);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvDebug, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
    }
}

void Encode_D3D12EnableExperimentalFeatures(
    HRESULT result,
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes)
{
    auto encoder = TraceManager::Get()->BeginApiCallTrace(format::ApiCallId::ApiCall_D3D12EnableExperimentalFeatures);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumFeatures);
        EncodeStructArray(encoder, pIIDs, NumFeatures );
        encoder->EncodeVoidArray(pConfigurationStructs, NumFeatures );
        encoder->EncodeUInt32Array(pConfigurationStructSizes, NumFeatures );
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndApiCallTrace(encoder);
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

void Encode_ID3D12Object_GetPrivateData(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID guid,
    UINT* pDataSize,
    void* pData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Object_GetPrivateData, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, guid);
        encoder->EncodeUInt32Ptr(pDataSize);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Object_SetPrivateData(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID guid,
    UINT DataSize,
    const void* pData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Object_SetPrivateData, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, guid);
        encoder->EncodeUInt32Value(DataSize);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Object_SetPrivateDataInterface(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID guid,
    const IUnknown* pData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Object_SetPrivateDataInterface, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, guid);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(const_cast<IUnknown**>(&pData)));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Object_SetName(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR Name)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Object_SetName, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(Name);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceChild_GetDevice(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppvDevice)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceChild_GetDevice, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvDevice, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_GRAPHICS_PIPELINE_STATE_DESC*>
            (&value)->pRootSignature));
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
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_COMPUTE_PIPELINE_STATE_DESC*>
            (&value)->pRootSignature));
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PIPELINE_STATE_STREAM_DESC& value)
{
    encoder->EncodeSizeTValue(value.SizeInBytes);
    encoder->EncodeVoidArray(value.pPipelineStateSubobjectStream, value.SizeInBytes);
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
    encoder->EncodeEnumArray(value.pFeatureLevelsRequested, value.NumFeatureLevels );
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CLEAR_VALUE& value)
{
    encoder->EncodeEnumValue(value.Format);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Color) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.DepthStencil) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Color), union_size_max);
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
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_RESOURCE_TRANSITION_BARRIER*>
            (&value)->pResource));
    encoder->EncodeUInt32Value(value.Subresource);
    encoder->EncodeEnumValue(value.StateBefore);
    encoder->EncodeEnumValue(value.StateAfter);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_ALIASING_BARRIER& value)
{
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_RESOURCE_ALIASING_BARRIER*>
            (&value)->pResourceBefore));
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_RESOURCE_ALIASING_BARRIER*>
            (&value)->pResourceAfter));
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_UAV_BARRIER& value)
{
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_RESOURCE_UAV_BARRIER*>
            (&value)->pResource));
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_BARRIER& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.Flags);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Transition) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Aliasing) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.UAV) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Transition), union_size_max);
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXTURE_COPY_LOCATION& value)
{
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_TEXTURE_COPY_LOCATION*>
            (&value)->pResource));
    encoder->EncodeEnumValue(value.Type);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.PlacedFootprint) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.SubresourceIndex) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.PlacedFootprint), union_size_max);
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SHADER_RESOURCE_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);
    encoder->EncodeUInt32Value(value.Shader4ComponentMapping);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Buffer) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture1D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture1DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DMS) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DMSArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture3D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.TextureCube) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.TextureCubeArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.RaytracingAccelerationStructure) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Buffer), union_size_max);
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX3D_UAV& value)
{
    encoder->EncodeUInt32Value(value.MipSlice);
    encoder->EncodeUInt32Value(value.FirstWSlice);
    encoder->EncodeUInt32Value(value.WSize);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_UNORDERED_ACCESS_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Buffer) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture1D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture1DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture3D) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Buffer), union_size_max);
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_TARGET_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Buffer) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture1D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture1DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DMS) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DMSArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture3D) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Buffer), union_size_max);
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_VIEW_DESC& value)
{
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ViewDimension);
    encoder->EncodeEnumValue(value.Flags);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Texture1D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture1DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2D) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DArray) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DMS) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Texture2DMSArray) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Texture1D), union_size_max);
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_PARAMETER& value)
{
    encoder->EncodeEnumValue(value.ParameterType);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.DescriptorTable) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Constants) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Descriptor) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.DescriptorTable), union_size_max);
    encoder->EncodeEnumValue(value.ShaderVisibility);
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_PARAMETER1& value)
{
    encoder->EncodeEnumValue(value.ParameterType);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.DescriptorTable) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Constants) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Descriptor) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.DescriptorTable), union_size_max);
    encoder->EncodeEnumValue(value.ShaderVisibility);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC1& value)
{
    encoder->EncodeUInt32Value(value.NumParameters);
    EncodeStructArray(encoder, value.pParameters, value.NumParameters);
    encoder->EncodeUInt32Value(value.NumStaticSamplers);
    EncodeStructArray(encoder, value.pStaticSamplers, value.NumStaticSamplers);
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERSIONED_ROOT_SIGNATURE_DESC& value)
{
    encoder->EncodeEnumValue(value.Version);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Desc_1_0) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Desc_1_1) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Desc_1_0), union_size_max);
}

void Encode_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    format::HandleId wrapper_id,
    const D3D12_ROOT_SIGNATURE_DESC * result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12RootSignatureDeserializer_GetRootSignatureDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D_ROOT_SIGNATURE_VERSION convertToVersion,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(convertToVersion);
        EncodeStructPtr(encoder, *ppDesc);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    format::HandleId wrapper_id,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC * result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CPU_DESCRIPTOR_HANDLE& value)
{
    encoder->EncodeSizeTValue(value.ptr);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_DESCRIPTOR_HANDLE& value)
{
    encoder->EncodeUInt64Value(value.ptr);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISCARD_REGION& value)
{
    encoder->EncodeUInt32Value(value.NumRects);
    EncodeStructArray(encoder, value.pRects, value.NumRects );
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INDIRECT_ARGUMENT_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.VertexBuffer) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Constant) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.ConstantBufferView) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.ShaderResourceView) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.UnorderedAccessView) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.VertexBuffer), union_size_max);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_SIGNATURE_DESC& value)
{
    encoder->EncodeUInt32Value(value.ByteStride);
    encoder->EncodeUInt32Value(value.NumArgumentDescs);
    EncodeStructArray(encoder, value.pArgumentDescs, value.NumArgumentDescs);
    encoder->EncodeUInt32Value(value.NodeMask);
}

void Encode_ID3D12Heap_GetDesc(
    format::HandleId wrapper_id,
    D3D12_HEAP_DESC result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Heap_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource_Map(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Subresource,
    const D3D12_RANGE* pReadRange,
    void** ppData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource_Map, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Subresource);
        EncodeStructPtr(encoder, pReadRange);
        EncodeDxObjectPtr(encoder, ppData, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource_Unmap(
    format::HandleId wrapper_id,
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource_Unmap, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Subresource);
        EncodeStructPtr(encoder, pWrittenRange);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource_GetDesc(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_DESC result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource_GetGPUVirtualAddress(
    format::HandleId wrapper_id,
    D3D12_GPU_VIRTUAL_ADDRESS result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource_GetGPUVirtualAddress, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource_WriteToSubresource(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT DstSubresource,
    const D3D12_BOX* pDstBox,
    const void* pSrcData,
    UINT SrcRowPitch,
    UINT SrcDepthPitch)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource_WriteToSubresource, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(DstSubresource);
        EncodeStructPtr(encoder, pDstBox);
        encoder->EncodeVoidPtr(pSrcData);
        encoder->EncodeUInt32Value(SrcRowPitch);
        encoder->EncodeUInt32Value(SrcDepthPitch);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource_ReadFromSubresource(
    format::HandleId wrapper_id,
    HRESULT result,
    void* pDstData,
    UINT DstRowPitch,
    UINT DstDepthPitch,
    UINT SrcSubresource,
    const D3D12_BOX* pSrcBox)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource_ReadFromSubresource, wrapper_id);
    if(encoder)
    {
        encoder->EncodeVoidPtr(pDstData);
        encoder->EncodeUInt32Value(DstRowPitch);
        encoder->EncodeUInt32Value(DstDepthPitch);
        encoder->EncodeUInt32Value(SrcSubresource);
        EncodeStructPtr(encoder, pSrcBox);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource_GetHeapProperties(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS* pHeapFlags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource_GetHeapProperties, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumPtr(pHeapFlags);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandAllocator_Reset(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandAllocator_Reset, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Fence_GetCompletedValue(
    format::HandleId wrapper_id,
    UINT64 result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Fence_GetCompletedValue, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Fence_SetEventOnCompletion(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Value,
    HANDLE hEvent)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Fence_SetEventOnCompletion, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Fence_Signal(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Value)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Fence_Signal, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Fence1_GetCreationFlags(
    format::HandleId wrapper_id,
    D3D12_FENCE_FLAGS result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Fence1_GetCreationFlags, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12PipelineState_GetCachedBlob(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3DBlob** ppBlob)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12PipelineState_GetCachedBlob, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&ppBlob));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DescriptorHeap_GetDesc(
    format::HandleId wrapper_id,
    D3D12_DESCRIPTOR_HEAP_DESC result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    format::HandleId wrapper_id,
    D3D12_CPU_DESCRIPTOR_HANDLE result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    format::HandleId wrapper_id,
    D3D12_GPU_DESCRIPTOR_HANDLE result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandList_GetType(
    format::HandleId wrapper_id,
    D3D12_COMMAND_LIST_TYPE result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandList_GetType, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_Close(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Close, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_Reset(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12CommandAllocator* pAllocator,
    ID3D12PipelineState* pInitialState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Reset, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pAllocator));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pInitialState));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearState(
    format::HandleId wrapper_id,
    ID3D12PipelineState* pPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearState, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pPipelineState));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_DrawInstanced(
    format::HandleId wrapper_id,
    UINT VertexCountPerInstance,
    UINT InstanceCount,
    UINT StartVertexLocation,
    UINT StartInstanceLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawInstanced, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(VertexCountPerInstance);
        encoder->EncodeUInt32Value(InstanceCount);
        encoder->EncodeUInt32Value(StartVertexLocation);
        encoder->EncodeUInt32Value(StartInstanceLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_DrawIndexedInstanced(
    format::HandleId wrapper_id,
    UINT IndexCountPerInstance,
    UINT InstanceCount,
    UINT StartIndexLocation,
    INT BaseVertexLocation,
    UINT StartInstanceLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DrawIndexedInstanced, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(IndexCountPerInstance);
        encoder->EncodeUInt32Value(InstanceCount);
        encoder->EncodeUInt32Value(StartIndexLocation);
        encoder->EncodeInt32Value(BaseVertexLocation);
        encoder->EncodeUInt32Value(StartInstanceLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_Dispatch(
    format::HandleId wrapper_id,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_Dispatch, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(ThreadGroupCountX);
        encoder->EncodeUInt32Value(ThreadGroupCountY);
        encoder->EncodeUInt32Value(ThreadGroupCountZ);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyBufferRegion(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT64 NumBytes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyBufferRegion, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDstBuffer));
        encoder->EncodeUInt64Value(DstOffset);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pSrcBuffer));
        encoder->EncodeUInt64Value(SrcOffset);
        encoder->EncodeUInt64Value(NumBytes);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyTextureRegion(
    format::HandleId wrapper_id,
    const D3D12_TEXTURE_COPY_LOCATION* pDst,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    const D3D12_TEXTURE_COPY_LOCATION* pSrc,
    const D3D12_BOX* pSrcBox)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTextureRegion, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDst);
        encoder->EncodeUInt32Value(DstX);
        encoder->EncodeUInt32Value(DstY);
        encoder->EncodeUInt32Value(DstZ);
        EncodeStructPtr(encoder, pSrc);
        EncodeStructPtr(encoder, pSrcBox);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyResource(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstResource,
    ID3D12Resource* pSrcResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyResource, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDstResource));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pSrcResource));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_CopyTiles(
    format::HandleId wrapper_id,
    ID3D12Resource* pTiledResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pTileRegionSize,
    ID3D12Resource* pBuffer,
    UINT64 BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS Flags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_CopyTiles, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pTiledResource));
        EncodeStructPtr(encoder, pTileRegionStartCoordinate);
        EncodeStructPtr(encoder, pTileRegionSize);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pBuffer));
        encoder->EncodeUInt64Value(BufferStartOffsetInBytes);
        encoder->EncodeEnumValue(Flags);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ResolveSubresource(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstResource,
    UINT DstSubresource,
    ID3D12Resource* pSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT Format)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveSubresource, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDstResource));
        encoder->EncodeUInt32Value(DstSubresource);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pSrcResource));
        encoder->EncodeUInt32Value(SrcSubresource);
        encoder->EncodeEnumValue(Format);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
    format::HandleId wrapper_id,
    D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetPrimitiveTopology, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(PrimitiveTopology);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_RSSetViewports(
    format::HandleId wrapper_id,
    UINT NumViewports,
    const D3D12_VIEWPORT* pViewports)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetViewports, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumViewports);
        EncodeStructArray(encoder, pViewports, NumViewports );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_RSSetScissorRects(
    format::HandleId wrapper_id,
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_RSSetScissorRects, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_OMSetBlendFactor(
    format::HandleId wrapper_id,
    const FLOAT BlendFactor [4])
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetBlendFactor, wrapper_id);
    if(encoder)
    {
        encoder->EncodeFloatArray(BlendFactor, 4);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_OMSetStencilRef(
    format::HandleId wrapper_id,
    UINT StencilRef)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetStencilRef, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(StencilRef);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetPipelineState(
    format::HandleId wrapper_id,
    ID3D12PipelineState* pPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPipelineState, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pPipelineState));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ResourceBarrier(
    format::HandleId wrapper_id,
    UINT NumBarriers,
    const D3D12_RESOURCE_BARRIER* pBarriers)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResourceBarrier, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumBarriers);
        EncodeStructArray(encoder, pBarriers, NumBarriers );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ExecuteBundle(
    format::HandleId wrapper_id,
    ID3D12GraphicsCommandList* pCommandList)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteBundle, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pCommandList));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    format::HandleId wrapper_id,
    UINT NumDescriptorHeaps,
    ID3D12DescriptorHeap* const* ppDescriptorHeaps)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetDescriptorHeaps, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumDescriptorHeaps);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12DescriptorHeap***>(&ppDescriptorHeaps)), NumDescriptorHeaps );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootSignature(
    format::HandleId wrapper_id,
    ID3D12RootSignature* pRootSignature)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootSignature, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRootSignature));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    format::HandleId wrapper_id,
    ID3D12RootSignature* pRootSignature)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootSignature, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRootSignature));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        EncodeStruct(encoder, BaseDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        EncodeStruct(encoder, BaseDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(SrcData);
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(SrcData);
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(Num32BitValuesToSet);
        encoder->EncodeVoidArray(pSrcData, Num32BitValuesToSet * sizeof ( UINT ) );
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt32Value(Num32BitValuesToSet);
        encoder->EncodeVoidArray(pSrcData, Num32BitValuesToSet * sizeof ( UINT ) );
        encoder->EncodeUInt32Value(DestOffsetIn32BitValues);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(RootParameterIndex);
        encoder->EncodeUInt64Value(BufferLocation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_IASetIndexBuffer(
    format::HandleId wrapper_id,
    const D3D12_INDEX_BUFFER_VIEW* pView)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetIndexBuffer, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pView);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_IASetVertexBuffers(
    format::HandleId wrapper_id,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_VERTEX_BUFFER_VIEW* pViews)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_IASetVertexBuffers, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(StartSlot);
        encoder->EncodeUInt32Value(NumViews);
        EncodeStructArray(encoder, pViews, NumViews );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SOSetTargets(
    format::HandleId wrapper_id,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SOSetTargets, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(StartSlot);
        encoder->EncodeUInt32Value(NumViews);
        EncodeStructArray(encoder, pViews, NumViews );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_OMSetRenderTargets(
    format::HandleId wrapper_id,
    UINT NumRenderTargetDescriptors,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
    BOOL RTsSingleHandleToDescriptorRange,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_OMSetRenderTargets, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumRenderTargetDescriptors);
        EncodeStructPtr(encoder, pRenderTargetDescriptors);
        encoder->EncodeInt32Value(RTsSingleHandleToDescriptorRange);
        EncodeStructPtr(encoder, pDepthStencilDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearDepthStencilView(
    format::HandleId wrapper_id,
    D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
    D3D12_CLEAR_FLAGS ClearFlags,
    FLOAT Depth,
    UINT8 Stencil,
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearDepthStencilView, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, DepthStencilView);
        encoder->EncodeEnumValue(ClearFlags);
        encoder->EncodeFloatValue(Depth);
        encoder->EncodeUInt8Value(Stencil);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearRenderTargetView(
    format::HandleId wrapper_id,
    D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
    const FLOAT ColorRGBA [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearRenderTargetView, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, RenderTargetView);
        encoder->EncodeFloatArray(ColorRGBA, 4);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
    format::HandleId wrapper_id,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const UINT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, ViewGPUHandleInCurrentHeap);
        EncodeStruct(encoder, ViewCPUHandle);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        encoder->EncodeUInt32Array(Values, 4);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
    format::HandleId wrapper_id,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const FLOAT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, ViewGPUHandleInCurrentHeap);
        EncodeStruct(encoder, ViewCPUHandle);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        encoder->EncodeFloatArray(Values, 4);
        encoder->EncodeUInt32Value(NumRects);
        EncodeStructArray(encoder, pRects, NumRects );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_DiscardResource(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_DISCARD_REGION* pRegion)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_DiscardResource, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        EncodeStructPtr(encoder, pRegion);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_BeginQuery(
    format::HandleId wrapper_id,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginQuery, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pQueryHeap));
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(Index);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_EndQuery(
    format::HandleId wrapper_id,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndQuery, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pQueryHeap));
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(Index);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ResolveQueryData(
    format::HandleId wrapper_id,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT StartIndex,
    UINT NumQueries,
    ID3D12Resource* pDestinationBuffer,
    UINT64 AlignedDestinationBufferOffset)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ResolveQueryData, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pQueryHeap));
        encoder->EncodeEnumValue(Type);
        encoder->EncodeUInt32Value(StartIndex);
        encoder->EncodeUInt32Value(NumQueries);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDestinationBuffer));
        encoder->EncodeUInt64Value(AlignedDestinationBufferOffset);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetPredication(
    format::HandleId wrapper_id,
    ID3D12Resource* pBuffer,
    UINT64 AlignedBufferOffset,
    D3D12_PREDICATION_OP Operation)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetPredication, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pBuffer));
        encoder->EncodeUInt64Value(AlignedBufferOffset);
        encoder->EncodeEnumValue(Operation);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_SetMarker(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_SetMarker, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeUInt32Value(Size);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_BeginEvent(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_BeginEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeUInt32Value(Size);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_EndEvent(
    format::HandleId wrapper_id)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_EndEvent, wrapper_id);
    if(encoder)
    {
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList_ExecuteIndirect(
    format::HandleId wrapper_id,
    ID3D12CommandSignature* pCommandSignature,
    UINT MaxCommandCount,
    ID3D12Resource* pArgumentBuffer,
    UINT64 ArgumentBufferOffset,
    ID3D12Resource* pCountBuffer,
    UINT64 CountBufferOffset)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList_ExecuteIndirect, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pCommandSignature));
        encoder->EncodeUInt32Value(MaxCommandCount);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pArgumentBuffer));
        encoder->EncodeUInt64Value(ArgumentBufferOffset);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pCountBuffer));
        encoder->EncodeUInt64Value(CountBufferOffset);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDstBuffer));
        encoder->EncodeUInt64Value(DstOffset);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pSrcBuffer));
        encoder->EncodeUInt64Value(SrcOffset);
        encoder->EncodeUInt32Value(Dependencies);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12Resource***>(&ppDependentResources)), Dependencies);
        EncodeStructArray(encoder, pDependentSubresourceRanges, Dependencies);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDstBuffer));
        encoder->EncodeUInt64Value(DstOffset);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pSrcBuffer));
        encoder->EncodeUInt64Value(SrcOffset);
        encoder->EncodeUInt32Value(Dependencies);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12Resource***>(&ppDependentResources)), Dependencies);
        EncodeStructArray(encoder, pDependentSubresourceRanges, Dependencies);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList1_OMSetDepthBounds(
    format::HandleId wrapper_id,
    FLOAT Min,
    FLOAT Max)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_OMSetDepthBounds, wrapper_id);
    if(encoder)
    {
        encoder->EncodeFloatValue(Min);
        encoder->EncodeFloatValue(Max);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList1_SetSamplePositions(
    format::HandleId wrapper_id,
    UINT NumSamplesPerPixel,
    UINT NumPixels,
    D3D12_SAMPLE_POSITION* pSamplePositions)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetSamplePositions, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumSamplesPerPixel);
        encoder->EncodeUInt32Value(NumPixels);
        EncodeStructArray(encoder, pSamplePositions, NumSamplesPerPixel * NumPixels );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
    format::HandleId wrapper_id,
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
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_ResolveSubresourceRegion, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDstResource));
        encoder->EncodeUInt32Value(DstSubresource);
        encoder->EncodeUInt32Value(DstX);
        encoder->EncodeUInt32Value(DstY);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pSrcResource));
        encoder->EncodeUInt32Value(SrcSubresource);
        EncodeStructPtr(encoder, pSrcRect);
        encoder->EncodeEnumValue(Format);
        encoder->EncodeEnumValue(ResolveMode);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList1_SetViewInstanceMask(
    format::HandleId wrapper_id,
    UINT Mask)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList1_SetViewInstanceMask, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Mask);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& value)
{
    encoder->EncodeUInt64Value(value.Dest);
    encoder->EncodeUInt32Value(value.Value);
}

void Encode_ID3D12GraphicsCommandList2_WriteBufferImmediate(
    format::HandleId wrapper_id,
    UINT Count,
    const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
    const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList2_WriteBufferImmediate, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Count);
        EncodeStructPtr(encoder, pParams);
        encoder->EncodeEnumPtr(pModes);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_UpdateTileMappings(
    format::HandleId wrapper_id,
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
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_UpdateTileMappings, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        encoder->EncodeUInt32Value(NumResourceRegions);
        EncodeStructArray(encoder, pResourceRegionStartCoordinates, NumResourceRegions );
        EncodeStructArray(encoder, pResourceRegionSizes, NumResourceRegions );
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pHeap));
        encoder->EncodeUInt32Value(NumRanges);
        encoder->EncodeEnumArray(pRangeFlags, NumRanges );
        encoder->EncodeUInt32Array(pHeapRangeStartOffsets, NumRanges );
        encoder->EncodeUInt32Array(pRangeTileCounts, NumRanges );
        encoder->EncodeEnumValue(Flags);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_CopyTileMappings(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
    ID3D12Resource* pSrcResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS Flags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_CopyTileMappings, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pDstResource));
        EncodeStructPtr(encoder, pDstRegionStartCoordinate);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pSrcResource));
        EncodeStructPtr(encoder, pSrcRegionStartCoordinate);
        EncodeStructPtr(encoder, pRegionSize);
        encoder->EncodeEnumValue(Flags);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_ExecuteCommandLists(
    format::HandleId wrapper_id,
    UINT NumCommandLists,
    ID3D12CommandList* const* ppCommandLists)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_ExecuteCommandLists, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumCommandLists);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12CommandList***>(&ppCommandLists)), NumCommandLists );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_SetMarker(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_SetMarker, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeUInt32Value(Size);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_BeginEvent(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_BeginEvent, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(Metadata);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeUInt32Value(Size);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_EndEvent(
    format::HandleId wrapper_id)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_EndEvent, wrapper_id);
    if(encoder)
    {
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_Signal(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Fence* pFence,
    UINT64 Value)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_Signal, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pFence));
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_Wait(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Fence* pFence,
    UINT64 Value)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_Wait, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pFence));
        encoder->EncodeUInt64Value(Value);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_GetTimestampFrequency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64* pFrequency)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_GetTimestampFrequency, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Ptr(pFrequency);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_GetClockCalibration(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64* pGpuTimestamp,
    UINT64* pCpuTimestamp)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_GetClockCalibration, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Ptr(pGpuTimestamp);
        encoder->EncodeUInt64Ptr(pCpuTimestamp);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12CommandQueue_GetDesc(
    format::HandleId wrapper_id,
    D3D12_COMMAND_QUEUE_DESC result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12CommandQueue_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetNodeCount(
    format::HandleId wrapper_id,
    UINT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetNodeCount, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateCommandQueue(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID riid,
    void** ppCommandQueue)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandQueue, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppCommandQueue, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateCommandAllocator(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_COMMAND_LIST_TYPE type,
    REFIID riid,
    void** ppCommandAllocator)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandAllocator, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(type);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppCommandAllocator, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateGraphicsPipelineState(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppPipelineState, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateComputePipelineState(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppPipelineState, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateCommandList(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    ID3D12CommandAllocator* pCommandAllocator,
    ID3D12PipelineState* pInitialState,
    REFIID riid,
    void** ppCommandList)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandList, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeEnumValue(type);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pCommandAllocator));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pInitialState));
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppCommandList, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CheckFeatureSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_FEATURE Feature,
    void* pFeatureSupportData,
    UINT FeatureSupportDataSize)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CheckFeatureSupport, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Feature);
        encoder->EncodeVoidPtr(pFeatureSupportData);
        encoder->EncodeUInt32Value(FeatureSupportDataSize);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateDescriptorHeap(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateDescriptorHeap, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDescriptorHeapDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvHeap, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetDescriptorHandleIncrementSize(
    format::HandleId wrapper_id,
    UINT result,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetDescriptorHandleIncrementSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(DescriptorHeapType);
        encoder->EncodeUInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateRootSignature(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT nodeMask,
    const void* pBlobWithRootSignature,
    SIZE_T blobLengthInBytes,
    REFIID riid,
    void** ppvRootSignature)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateRootSignature, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeVoidPtr(pBlobWithRootSignature);
        encoder->EncodeSizeTValue(blobLengthInBytes);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvRootSignature, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateConstantBufferView(
    format::HandleId wrapper_id,
    const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateConstantBufferView, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateShaderResourceView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateShaderResourceView, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateUnorderedAccessView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    ID3D12Resource* pCounterResource,
    const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateUnorderedAccessView, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pCounterResource));
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateRenderTargetView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateRenderTargetView, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateDepthStencilView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateDepthStencilView, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pResource));
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateSampler(
    format::HandleId wrapper_id,
    const D3D12_SAMPLER_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateSampler, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, DestDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CopyDescriptors(
    format::HandleId wrapper_id,
    UINT NumDestDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
    const UINT* pDestDescriptorRangeSizes,
    UINT NumSrcDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
    const UINT* pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptors, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumDestDescriptorRanges);
        EncodeStructArray(encoder, pDestDescriptorRangeStarts, NumDestDescriptorRanges );
        encoder->EncodeUInt32Array(pDestDescriptorRangeSizes, NumDestDescriptorRanges );
        encoder->EncodeUInt32Value(NumSrcDescriptorRanges);
        EncodeStructArray(encoder, pSrcDescriptorRangeStarts, NumSrcDescriptorRanges );
        encoder->EncodeUInt32Array(pSrcDescriptorRangeSizes, NumSrcDescriptorRanges );
        encoder->EncodeEnumValue(DescriptorHeapsType);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CopyDescriptorsSimple(
    format::HandleId wrapper_id,
    UINT NumDescriptors,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CopyDescriptorsSimple, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumDescriptors);
        EncodeStruct(encoder, DestDescriptorRangeStart);
        EncodeStruct(encoder, SrcDescriptorRangeStart);
        encoder->EncodeEnumValue(DescriptorHeapsType);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetResourceAllocationInfo(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_ALLOCATION_INFO result,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetResourceAllocationInfo, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(visibleMask);
        encoder->EncodeUInt32Value(numResourceDescs);
        EncodeStructPtr(encoder, pResourceDescs);
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetCustomHeapProperties(
    format::HandleId wrapper_id,
    D3D12_HEAP_PROPERTIES result,
    UINT nodeMask,
    D3D12_HEAP_TYPE heapType)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetCustomHeapProperties, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeEnumValue(heapType);
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateCommittedResource(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riidResource,
    void** ppvResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateCommittedResource, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumValue(HeapFlags);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialResourceState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riidResource);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateHeap(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateHeap, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvHeap, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreatePlacedResource(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreatePlacedResource, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pHeap));
        encoder->EncodeUInt64Value(HeapOffset);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateReservedResource(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateReservedResource, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12DeviceChild* pObject,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD Access,
    LPCWSTR Name,
    HANDLE* pHandle)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateSharedHandle, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pObject));
        EncodeStructPtr(encoder, pAttributes);
        encoder->EncodeUInt32Value(Access);
        encoder->EncodeWString(Name);
        encoder->EncodeHandlePtr(pHandle);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_OpenSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE NTHandle,
    REFIID riid,
    void** ppvObj)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandle, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(NTHandle);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvObj, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_OpenSharedHandleByName(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR Name,
    DWORD Access,
    HANDLE* pNTHandle)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_OpenSharedHandleByName, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(Name);
        encoder->EncodeUInt32Value(Access);
        encoder->EncodeHandlePtr(pNTHandle);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_MakeResident(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_MakeResident, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumObjects);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12Pageable***>(&ppObjects)), NumObjects );
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_Evict(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_Evict, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumObjects);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12Pageable***>(&ppObjects)), NumObjects );
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateFence(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 InitialValue,
    D3D12_FENCE_FLAGS Flags,
    REFIID riid,
    void** ppFence)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateFence, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(InitialValue);
        encoder->EncodeEnumValue(Flags);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppFence, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetDeviceRemovedReason(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetDeviceRemovedReason, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetCopyableFootprints(
    format::HandleId wrapper_id,
    const D3D12_RESOURCE_DESC* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetCopyableFootprints, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pResourceDesc);
        encoder->EncodeUInt32Value(FirstSubresource);
        encoder->EncodeUInt32Value(NumSubresources);
        encoder->EncodeUInt64Value(BaseOffset);
        EncodeStructArray(encoder, pLayouts, NumSubresources );
        encoder->EncodeUInt32Array(pNumRows, NumSubresources );
        encoder->EncodeUInt64Array(pRowSizeInBytes, NumSubresources );
        encoder->EncodeUInt64Ptr(pTotalBytes);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateQueryHeap(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_QUERY_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateQueryHeap, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvHeap, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_SetStablePowerState(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL Enable)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_SetStablePowerState, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(Enable);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_CreateCommandSignature(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
    ID3D12RootSignature* pRootSignature,
    REFIID riid,
    void** ppvCommandSignature)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_CreateCommandSignature, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pRootSignature));
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvCommandSignature, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetResourceTiling(
    format::HandleId wrapper_id,
    ID3D12Resource* pTiledResource,
    UINT* pNumTilesForEntireResource,
    D3D12_PACKED_MIP_INFO* pPackedMipDesc,
    D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
    UINT* pNumSubresourceTilings,
    UINT FirstSubresourceTilingToGet,
    D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetResourceTiling, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pTiledResource));
        encoder->EncodeUInt32Ptr(pNumTilesForEntireResource);
        EncodeStructPtr(encoder, pPackedMipDesc);
        EncodeStructPtr(encoder, pStandardTileShapeForNonPackedMips);
        encoder->EncodeUInt32Ptr(pNumSubresourceTilings);
        encoder->EncodeUInt32Value(FirstSubresourceTilingToGet);
        EncodeStructPtr(encoder, pSubresourceTilingsForNonPackedMips);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device_GetAdapterLuid(
    format::HandleId wrapper_id,
    LUID result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device_GetAdapterLuid, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12PipelineLibrary_StorePipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    ID3D12PipelineState* pPipeline)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(pName);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pPipeline));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12PipelineLibrary_LoadGraphicsPipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadGraphicsPipeline, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(pName);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppPipelineState, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12PipelineLibrary_LoadComputePipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_LoadComputePipeline, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(pName);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppPipelineState, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12PipelineLibrary_GetSerializedSize(
    format::HandleId wrapper_id,
    SIZE_T result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_GetSerializedSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeSizeTValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12PipelineLibrary_Serialize(
    format::HandleId wrapper_id,
    HRESULT result,
    void* pData,
    SIZE_T DataSizeInBytes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12PipelineLibrary_Serialize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeSizeTValue(DataSizeInBytes);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12PipelineLibrary1_LoadPipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12PipelineLibrary1_LoadPipeline, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(pName);
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppPipelineState, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device1_CreatePipelineLibrary(
    format::HandleId wrapper_id,
    HRESULT result,
    const void* pLibraryBlob,
    SIZE_T BlobLength,
    REFIID riid,
    void** ppPipelineLibrary)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device1_CreatePipelineLibrary, wrapper_id);
    if(encoder)
    {
        encoder->EncodeVoidPtr(pLibraryBlob);
        encoder->EncodeSizeTValue(BlobLength);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppPipelineLibrary, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device1_SetEventOnMultipleFenceCompletion(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Fence* const* ppFences,
    const UINT64* pFenceValues,
    UINT NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
    HANDLE hEvent)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device1_SetEventOnMultipleFenceCompletion, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12Fence***>(&ppFences)), NumFences );
        encoder->EncodeUInt64Array(pFenceValues, NumFences );
        encoder->EncodeUInt32Value(NumFences);
        encoder->EncodeEnumValue(Flags);
        encoder->EncodeHandleValue(hEvent);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device1_SetResidencyPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    const D3D12_RESIDENCY_PRIORITY* pPriorities)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device1_SetResidencyPriority, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumObjects);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12Pageable***>(&ppObjects)), NumObjects );
        encoder->EncodeEnumArray(pPriorities, NumObjects );
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device2_CreatePipelineState(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device2_CreatePipelineState, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppPipelineState, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device3_OpenExistingHeapFromAddress(
    format::HandleId wrapper_id,
    HRESULT result,
    const void* pAddress,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromAddress, wrapper_id);
    if(encoder)
    {
        encoder->EncodeVoidPtr(pAddress);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvHeap, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device3_OpenExistingHeapFromFileMapping(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hFileMapping,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device3_OpenExistingHeapFromFileMapping, wrapper_id);
    if(encoder)
    {
        encoder->EncodeHandleValue(hFileMapping);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvHeap, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device3_EnqueueMakeResident(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_RESIDENCY_FLAGS Flags,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    ID3D12Fence* pFenceToSignal,
    UINT64 FenceValueToSignal)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device3_EnqueueMakeResident, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Flags);
        encoder->EncodeUInt32Value(NumObjects);
        EncodeDxObjectPtrArray(encoder, reinterpret_cast<void***>(const_cast<ID3D12Pageable***>(&ppObjects)), NumObjects );
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pFenceToSignal));
        encoder->EncodeUInt64Value(FenceValueToSignal);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12ProtectedSession_GetStatusFence(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppFence)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetStatusFence, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppFence, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12ProtectedSession_GetSessionStatus(
    format::HandleId wrapper_id,
    D3D12_PROTECTED_SESSION_STATUS result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12ProtectedSession_GetSessionStatus, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession_GetDesc, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device4_CreateCommandList1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    D3D12_COMMAND_LIST_FLAGS flags,
    REFIID riid,
    void** ppCommandList)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device4_CreateCommandList1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(nodeMask);
        encoder->EncodeEnumValue(type);
        encoder->EncodeEnumValue(flags);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppCommandList, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device4_CreateProtectedResourceSession(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppSession)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device4_CreateProtectedResourceSession, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppSession, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device4_CreateCommittedResource1(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riidResource,
    void** ppvResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device4_CreateCommittedResource1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumValue(HeapFlags);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialResourceState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pProtectedSession));
        EncodeStruct(encoder, riidResource);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device4_CreateHeap1(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_DESC* pDesc,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvHeap)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device4_CreateHeap1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pProtectedSession));
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvHeap, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device4_CreateReservedResource1(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device4_CreateReservedResource1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pProtectedSession));
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device4_GetResourceAllocationInfo1(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_ALLOCATION_INFO result,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device4_GetResourceAllocationInfo1, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(visibleMask);
        encoder->EncodeUInt32Value(numResourceDescs);
        EncodeStructPtr(encoder, pResourceDescs);
        EncodeStructPtr(encoder, pResourceAllocationInfo1);
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12LifetimeOwner_LifetimeStateUpdated(
    format::HandleId wrapper_id,
    D3D12_LIFETIME_STATE NewState)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12LifetimeOwner_LifetimeStateUpdated, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(NewState);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12SwapChainAssistant_GetLUID(
    format::HandleId wrapper_id,
    LUID result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetLUID, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12SwapChainAssistant_GetSwapChainObject(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppv)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetSwapChainObject, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppv, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riidResource,
    void** ppvResource,
    REFIID riidQueue,
    void** ppvQueue)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riidResource);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        EncodeStruct(encoder, riidQueue);
        EncodeDxObjectPtr(encoder, ppvQueue, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12SwapChainAssistant_InsertImplicitSync(
    format::HandleId wrapper_id,
    HRESULT result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12SwapChainAssistant_InsertImplicitSync, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12LifetimeTracker_DestroyOwnedObject(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12DeviceChild* pObject)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12LifetimeTracker_DestroyOwnedObject, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pObject));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    void* result,
    LPCWSTR pExportName)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderIdentifier, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(pExportName);
        encoder->EncodeVoidPtr(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12StateObjectProperties_GetShaderStackSize(
    format::HandleId wrapper_id,
    UINT64 result,
    LPCWSTR pExportName)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetShaderStackSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeWString(pExportName);
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12StateObjectProperties_GetPipelineStackSize(
    format::HandleId wrapper_id,
    UINT64 result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_GetPipelineStackSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12StateObjectProperties_SetPipelineStackSize(
    format::HandleId wrapper_id,
    UINT64 PipelineStackSizeInBytes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12StateObjectProperties_SetPipelineStackSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(PipelineStackSizeInBytes);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_SUBOBJECT& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeVoidPtr(value.pDesc);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_OBJECT_CONFIG& value)
{
    encoder->EncodeEnumValue(value.Flags);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GLOBAL_ROOT_SIGNATURE& value)
{
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_GLOBAL_ROOT_SIGNATURE*>
            (&value)->pGlobalRootSignature));
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_LOCAL_ROOT_SIGNATURE& value)
{
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_LOCAL_ROOT_SIGNATURE*>
            (&value)->pLocalRootSignature));
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
    EncodeStructArray(encoder, value.pExports, value.NumExports );
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_EXISTING_COLLECTION_DESC& value)
{
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_EXISTING_COLLECTION_DESC*>
            (&value)->pExistingCollection));
    encoder->EncodeUInt32Value(value.NumExports);
    EncodeStructArray(encoder, value.pExports, value.NumExports );
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION& value)
{
    EncodeStructPtr(encoder, value.pSubobjectToAssociate);
    encoder->EncodeUInt32Value(value.NumExports);
    encoder->EncodeWStringArray(value.pExports, value.NumExports );
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& value)
{
    encoder->EncodeWString(value.SubobjectToAssociate);
    encoder->EncodeUInt32Value(value.NumExports);
    encoder->EncodeWStringArray(value.pExports, value.NumExports );
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_OBJECT_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeUInt32Value(value.NumSubobjects);
    EncodeStructArray(encoder, value.pSubobjects, value.NumSubobjects );
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_GEOMETRY_DESC& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.Flags);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Triangles) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.AABBs) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Triangles), union_size_max);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS& value)
{
    encoder->EncodeEnumValue(value.Type);
    encoder->EncodeEnumValue(value.Flags);
    encoder->EncodeUInt32Value(value.NumDescs);
    encoder->EncodeEnumValue(value.DescsLayout);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.InstanceDescs) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.pGeometryDescs) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.ppGeometryDescs) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.InstanceDescs), union_size_max);
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
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12LifetimeOwner* pOwner,
    REFIID riid,
    void** ppvTracker)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_CreateLifetimeTracker, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pOwner));
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvTracker, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device5_RemoveDevice(
    format::HandleId wrapper_id)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_RemoveDevice, wrapper_id);
    if(encoder)
    {
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device5_EnumerateMetaCommands(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pNumMetaCommands,
    D3D12_META_COMMAND_DESC* pDescs)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommands, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Ptr(pNumMetaCommands);
        EncodeStructPtr(encoder, pDescs);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device5_EnumerateMetaCommandParameters(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT* pTotalStructureSizeInBytes,
    UINT* pParameterCount,
    D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_EnumerateMetaCommandParameters, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, CommandId);
        encoder->EncodeEnumValue(Stage);
        encoder->EncodeUInt32Ptr(pTotalStructureSizeInBytes);
        encoder->EncodeUInt32Ptr(pParameterCount);
        EncodeStructPtr(encoder, pParameterDescs);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device5_CreateMetaCommand(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID CommandId,
    UINT NodeMask,
    const void* pCreationParametersData,
    SIZE_T CreationParametersDataSizeInBytes,
    REFIID riid,
    void** ppMetaCommand)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_CreateMetaCommand, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, CommandId);
        encoder->EncodeUInt32Value(NodeMask);
        encoder->EncodeVoidPtr(pCreationParametersData);
        encoder->EncodeSizeTValue(CreationParametersDataSizeInBytes);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppMetaCommand, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device5_CreateStateObject(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_STATE_OBJECT_DESC* pDesc,
    REFIID riid,
    void** ppStateObject)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_CreateStateObject, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppStateObject, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
    format::HandleId wrapper_id,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStructPtr(encoder, pInfo);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device5_CheckDriverMatchingIdentifier(
    format::HandleId wrapper_id,
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS result,
    D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
    const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device5_CheckDriverMatchingIdentifier, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(SerializedDataType);
        EncodeStructPtr(encoder, pIdentifierToCheck);
        encoder->EncodeEnumValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_AUTO_BREADCRUMB_NODE& value)
{
    encoder->EncodeString(value.pCommandListDebugNameA);
    encoder->EncodeWString(value.pCommandListDebugNameW);
    encoder->EncodeString(value.pCommandQueueDebugNameA);
    encoder->EncodeWString(value.pCommandQueueDebugNameW);
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_AUTO_BREADCRUMB_NODE*>
            (&value)->pCommandList));
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_AUTO_BREADCRUMB_NODE*>
            (&value)->pCommandQueue));
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
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_AUTO_BREADCRUMB_NODE1*>
            (&value)->pCommandList));
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_AUTO_BREADCRUMB_NODE1*>
            (&value)->pCommandQueue));
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
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(const_cast<IUnknown**>
            (&const_cast<D3D12_DRED_ALLOCATION_NODE1*>(&value)->pObject)));
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& value)
{
    encoder->EncodeInt64Value(value.DeviceRemovedReason);
    EncodeStruct(encoder, value.AutoBreadcrumbsOutput);
    EncodeStruct(encoder, value.PageFaultOutput);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& value)
{
    encoder->EncodeInt64Value(value.DeviceRemovedReason);
    EncodeStruct(encoder, value.AutoBreadcrumbsOutput);
    EncodeStruct(encoder, value.PageFaultOutput);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERSIONED_DEVICE_REMOVED_EXTENDED_DATA& value)
{
    encoder->EncodeEnumValue(value.Version);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Dred_1_0) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Dred_1_1) > union_size_max) union_size_max = union_size;
    if (union_size = sizeof(value.Dred_1_2) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Dred_1_0), union_size_max);
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Enablement);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pOutput);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pOutput);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pOutput);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pOutput);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device6_SetBackgroundProcessingMode(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_BACKGROUND_PROCESSING_MODE Mode,
    D3D12_MEASUREMENTS_ACTION MeasurementsAction,
    HANDLE hEventToSignalUponCompletion,
    BOOL* pbFurtherMeasurementsDesired)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device6_SetBackgroundProcessingMode, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Mode);
        encoder->EncodeEnumValue(MeasurementsAction);
        encoder->EncodeHandleValue(hEventToSignalUponCompletion);
        encoder->EncodeInt32Ptr(pbFurtherMeasurementsDesired);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC1 result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12ProtectedResourceSession1_GetDesc1, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device7_AddToStateObject(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_STATE_OBJECT_DESC* pAddition,
    ID3D12StateObject* pStateObjectToGrowFrom,
    REFIID riid,
    void** ppNewStateObject)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device7_AddToStateObject, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pAddition);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pStateObjectToGrowFrom));
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppNewStateObject, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device7_CreateProtectedResourceSession1(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
    REFIID riid,
    void** ppSession)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device7_CreateProtectedResourceSession1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppSession, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device8_GetResourceAllocationInfo2(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_ALLOCATION_INFO result,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC1* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device8_GetResourceAllocationInfo2, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(visibleMask);
        encoder->EncodeUInt32Value(numResourceDescs);
        EncodeStructPtr(encoder, pResourceDescs);
        EncodeStructPtr(encoder, pResourceAllocationInfo1);
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device8_CreateCommittedResource2(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riidResource,
    void** ppvResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device8_CreateCommittedResource2, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pHeapProperties);
        encoder->EncodeEnumValue(HeapFlags);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialResourceState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pProtectedSession));
        EncodeStruct(encoder, riidResource);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device8_CreatePlacedResource1(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device8_CreatePlacedResource1, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pHeap));
        encoder->EncodeUInt64Value(HeapOffset);
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeEnumValue(InitialState);
        EncodeStructPtr(encoder, pOptimizedClearValue);
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvResource, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    format::HandleId wrapper_id,
    ID3D12Resource* pTargetedResource,
    ID3D12Resource* pFeedbackResource,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pTargetedResource));
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pFeedbackResource));
        EncodeStruct(encoder, DestDescriptor);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Device8_GetCopyableFootprints1(
    format::HandleId wrapper_id,
    const D3D12_RESOURCE_DESC1* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Device8_GetCopyableFootprints1, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pResourceDesc);
        encoder->EncodeUInt32Value(FirstSubresource);
        encoder->EncodeUInt32Value(NumSubresources);
        encoder->EncodeUInt64Value(BaseOffset);
        EncodeStructArray(encoder, pLayouts, NumSubresources );
        encoder->EncodeUInt32Array(pNumRows, NumSubresources );
        encoder->EncodeUInt64Array(pRowSizeInBytes, NumSubresources );
        encoder->EncodeUInt64Ptr(pTotalBytes);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource1_GetProtectedResourceSession(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppProtectedSession)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource1_GetProtectedResourceSession, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppProtectedSession, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Resource2_GetDesc1(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_DESC1 result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Resource2_GetDesc1, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Heap1_GetProtectedResourceSession(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppProtectedSession)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Heap1_GetProtectedResourceSession, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppProtectedSession, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
    format::HandleId wrapper_id,
    ID3D12ProtectedResourceSession* pProtectedResourceSession)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList3_SetProtectedResourceSession, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pProtectedResourceSession));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& value)
{
    EncodeStruct(encoder, value.ClearValue);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS& value)
{
    encoder->EncodeEnumValue(value.Type);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Clear) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Clear), union_size_max);
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
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS*>
            (&value)->pSrcResource));
    EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&const_cast<D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS*>
            (&value)->pDstResource));
    encoder->EncodeUInt32Value(value.SubresourceCount);
    EncodeStructArray(encoder, value.pSubresourceParameters, value.SubresourceCount);
    encoder->EncodeEnumValue(value.Format);
    encoder->EncodeEnumValue(value.ResolveMode);
    encoder->EncodeInt32Value(value.PreserveResolveSource);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS& value)
{
    encoder->EncodeEnumValue(value.Type);
    // For Union, find the largest size in the member and encode it.
    uint64_t union_size_max = 0, union_size = 0;
    if (union_size = sizeof(value.Resolve) > union_size_max) union_size_max = union_size;
    encoder->EncodeVoidArray(reinterpret_cast<const void*>(&value.Resolve), union_size_max);
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
    format::HandleId wrapper_id,
    UINT64 result,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT ParameterIndex)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12MetaCommand_GetRequiredParameterResourceSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(Stage);
        encoder->EncodeUInt32Value(ParameterIndex);
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
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
    format::HandleId wrapper_id,
    UINT NumRenderTargets,
    const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
    const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS Flags)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BeginRenderPass, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(NumRenderTargets);
        EncodeStructArray(encoder, pRenderTargets, NumRenderTargets );
        EncodeStructPtr(encoder, pDepthStencil);
        encoder->EncodeEnumValue(Flags);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_EndRenderPass(
    format::HandleId wrapper_id)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EndRenderPass, wrapper_id);
    if(encoder)
    {
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_InitializeMetaCommand(
    format::HandleId wrapper_id,
    ID3D12MetaCommand* pMetaCommand,
    const void* pInitializationParametersData,
    SIZE_T InitializationParametersDataSizeInBytes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_InitializeMetaCommand, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pMetaCommand));
        encoder->EncodeVoidPtr(pInitializationParametersData);
        encoder->EncodeSizeTValue(InitializationParametersDataSizeInBytes);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
    format::HandleId wrapper_id,
    ID3D12MetaCommand* pMetaCommand,
    const void* pExecutionParametersData,
    SIZE_T ExecutionParametersDataSizeInBytes)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_ExecuteMetaCommand, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pMetaCommand));
        encoder->EncodeVoidPtr(pExecutionParametersData);
        encoder->EncodeSizeTValue(ExecutionParametersDataSizeInBytes);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
    format::HandleId wrapper_id,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
    UINT NumPostbuildInfoDescs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeUInt32Value(NumPostbuildInfoDescs);
        EncodeStructArray(encoder, pPostbuildInfoDescs, NumPostbuildInfoDescs );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
    format::HandleId wrapper_id,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
    UINT NumSourceAccelerationStructures,
    const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        encoder->EncodeUInt32Value(NumSourceAccelerationStructures);
        encoder->EncodeUInt64Array(pSourceAccelerationStructureData, NumSourceAccelerationStructures );
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    format::HandleId wrapper_id,
    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(DestAccelerationStructureData);
        encoder->EncodeUInt64Value(SourceAccelerationStructureData);
        encoder->EncodeEnumValue(Mode);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_SetPipelineState1(
    format::HandleId wrapper_id,
    ID3D12StateObject* pStateObject)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_SetPipelineState1, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&pStateObject));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList4_DispatchRays(
    format::HandleId wrapper_id,
    const D3D12_DISPATCH_RAYS_DESC* pDesc)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList4_DispatchRays, wrapper_id);
    if(encoder)
    {
        EncodeStructPtr(encoder, pDesc);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Tools_EnableShaderInstrumentation(
    format::HandleId wrapper_id,
    BOOL bEnable)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Tools_EnableShaderInstrumentation, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(bEnable);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12Tools_ShaderInstrumentationEnabled(
    format::HandleId wrapper_id,
    BOOL result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12Tools_ShaderInstrumentationEnabled, wrapper_id);
    if(encoder)
    {
        encoder->EncodeInt32Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_DATA& value)
{
    encoder->EncodeVoidPtr(value.pData);
    encoder->EncodeInt64Value(value.RowPitch);
    encoder->EncodeInt64Value(value.SlicePitch);
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MEMCPY_DEST& value)
{
    encoder->EncodeVoidPtr(value.pData);
    encoder->EncodeSizeTValue(value.RowPitch);
    encoder->EncodeSizeTValue(value.SlicePitch);
}

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRate(
    format::HandleId wrapper_id,
    D3D12_SHADING_RATE baseShadingRate,
    const D3D12_SHADING_RATE_COMBINER* combiners)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRate, wrapper_id);
    if(encoder)
    {
        encoder->EncodeEnumValue(baseShadingRate);
        encoder->EncodeEnumPtr(combiners);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
    format::HandleId wrapper_id,
    ID3D12Resource* shadingRateImage)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList5_RSSetShadingRateImage, wrapper_id);
    if(encoder)
    {
        EncodeDxObjectPtr(encoder, reinterpret_cast<void**>(&shadingRateImage));
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_MESH_ARGUMENTS& value)
{
    encoder->EncodeUInt32Value(value.ThreadGroupCountX);
    encoder->EncodeUInt32Value(value.ThreadGroupCountY);
    encoder->EncodeUInt32Value(value.ThreadGroupCountZ);
}

void Encode_ID3D12GraphicsCommandList6_DispatchMesh(
    format::HandleId wrapper_id,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D12GraphicsCommandList6_DispatchMesh, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(ThreadGroupCountX);
        encoder->EncodeUInt32Value(ThreadGroupCountY);
        encoder->EncodeUInt32Value(ThreadGroupCountZ);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const D3D_SHADER_MACRO& value)
{
    encoder->EncodeString(value.Name);
    encoder->EncodeString(value.Definition);
}

void Encode_ID3D10Blob_GetBufferPointer(
    format::HandleId wrapper_id,
    LPVOID result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D10Blob_GetBufferPointer, wrapper_id);
    if(encoder)
    {
        encoder->EncodeVoidPtr(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3D10Blob_GetBufferSize(
    format::HandleId wrapper_id,
    SIZE_T result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3D10Blob_GetBufferSize, wrapper_id);
    if(encoder)
    {
        encoder->EncodeSizeTValue(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3DDestructionNotifier_RegisterDestructionCallback(
    format::HandleId wrapper_id,
    HRESULT result,
    PFN_DESTRUCTION_CALLBACK callbackFn,
    void* pData,
    UINT* pCallbackID)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3DDestructionNotifier_RegisterDestructionCallback, wrapper_id);
    if(encoder)
    {
        encoder->EncodeFunctionPtr(callbackFn);
        encoder->EncodeVoidPtr(pData);
        encoder->EncodeUInt32Ptr(pCallbackID);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_ID3DDestructionNotifier_UnregisterDestructionCallback(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT callbackID)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_ID3DDestructionNotifier_UnregisterDestructionCallback, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt32Value(callbackID);
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_IUnknown_QueryInterface(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppvObject)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IUnknown_QueryInterface, wrapper_id);
    if(encoder)
    {
        EncodeStruct(encoder, riid);
        EncodeDxObjectPtr(encoder, ppvObject, FAILED(result));
        encoder->EncodeInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IUnknown_AddRef(
    format::HandleId wrapper_id,
    ULONG result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IUnknown_AddRef, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}

void Encode_IUnknown_Release(
    format::HandleId wrapper_id,
    ULONG result)
{
    auto encoder = TraceManager::Get()->BeginMethodCallTrace(format::ApiCallId::ApiCall_IUnknown_Release, wrapper_id);
    if(encoder)
    {
        encoder->EncodeUInt64Value(result);
        TraceManager::Get()->EndMethodCallTrace(encoder);
    }
}


/*
** This part is generated from guiddef.h in Windows SDK: 10.0.19041.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const GUID& value)
{
    encoder->EncodeUInt64Value(value.Data1);
    encoder->EncodeUInt16Value(value.Data2);
    encoder->EncodeUInt16Value(value.Data3);
    encoder->EncodeUInt8Array(value.Data4, 8);
}


/*
** This part is generated from windef.h in Windows SDK: 10.0.19041.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const tagRECT& value)
{
    encoder->EncodeInt64Value(value.left);
    encoder->EncodeInt64Value(value.top);
    encoder->EncodeInt64Value(value.right);
    encoder->EncodeInt64Value(value.bottom);
}

void EncodeStruct(ParameterEncoder* encoder, const tagPOINT& value)
{
    encoder->EncodeInt64Value(value.x);
    encoder->EncodeInt64Value(value.y);
}


/*
** This part is generated from minwinbase.h in Windows SDK: 10.0.19041.0
**
*/


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
