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
** This file is generated from dx12_api_call_encoders_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_API_CALL_ENCODERS_H
#define  GFXRECON_GENERATED_DX12_API_CALL_ENCODERS_H

#include <dxgi.h>
#include <dxgi1_2.h>
#include <dxgi1_3.h>
#include <dxgi1_4.h>
#include <dxgi1_5.h>
#include <dxgi1_6.h>
#include <dxgicommon.h>
#include <dxgiformat.h>
#include <dxgitype.h>
#include <d3d12.h>
#include <d3dcommon.h>
#include <d3d12sdklayers.h>
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

#include "encode/parameter_encoder.h"
#include "generated/generated_dx12_wrappers.h"
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
    void** ppFactory);

void Encode_CreateDXGIFactory1(
    HRESULT return_value,
    REFIID riid,
    void** ppFactory);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_FRAME_STATISTICS& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MAPPED_RECT& value);

void EncodeStruct(ParameterEncoder* encoder, const LUID& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTPUT_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SHARED_RESOURCE& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SURFACE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_DESC& value);

void Encode_IDXGIObject_SetPrivateData(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID Name,
    UINT DataSize,
    const void* pData);

void Encode_IDXGIObject_SetPrivateDataInterface(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID Name,
    const IUnknown* pUnknown);

void Encode_IDXGIObject_GetPrivateData(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID Name,
    UINT* pDataSize,
    void* pData);

void Encode_IDXGIObject_GetParent(
    IDXGIObject_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppParent);

void Encode_IDXGIDeviceSubObject_GetDevice(
    IDXGIDeviceSubObject_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppDevice);

void Encode_IDXGIResource_GetSharedHandle(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE* pSharedHandle);

void Encode_IDXGIResource_GetUsage(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_USAGE* pUsage);

void Encode_IDXGIResource_SetEvictionPriority(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    UINT EvictionPriority);

void Encode_IDXGIResource_GetEvictionPriority(
    IDXGIResource_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pEvictionPriority);

void Encode_IDXGIKeyedMutex_AcquireSync(
    IDXGIKeyedMutex_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Key,
    DWORD dwMilliseconds);

void Encode_IDXGIKeyedMutex_ReleaseSync(
    IDXGIKeyedMutex_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Key);

void Encode_IDXGISurface_GetDesc(
    IDXGISurface_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SURFACE_DESC* pDesc);

void Encode_IDXGISurface_Map(
    IDXGISurface_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MAPPED_RECT* pLockedRect,
    UINT MapFlags);

void Encode_IDXGISurface_Unmap(
    IDXGISurface_Wrapper* wrapper,
    HRESULT return_value);

void Encode_IDXGISurface1_GetDC(
    IDXGISurface1_Wrapper* wrapper,
    HRESULT return_value,
    BOOL Discard,
    HDC* phdc);

void Encode_IDXGISurface1_ReleaseDC(
    IDXGISurface1_Wrapper* wrapper,
    HRESULT return_value,
    RECT* pDirtyRect);

void Encode_IDXGIAdapter_EnumOutputs(
    IDXGIAdapter_Wrapper* wrapper,
    HRESULT return_value,
    UINT Output,
    IDXGIOutput** ppOutput);

void Encode_IDXGIAdapter_GetDesc(
    IDXGIAdapter_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC* pDesc);

void Encode_IDXGIAdapter_CheckInterfaceSupport(
    IDXGIAdapter_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID InterfaceName,
    LARGE_INTEGER* pUMDVersion);

void Encode_IDXGIOutput_GetDesc(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_OUTPUT_DESC* pDesc);

void Encode_IDXGIOutput_GetDisplayModeList(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC* pDesc);

void Encode_IDXGIOutput_FindClosestMatchingMode(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MODE_DESC* pModeToMatch,
    DXGI_MODE_DESC* pClosestMatch,
    IUnknown* pConcernedDevice);

void Encode_IDXGIOutput_WaitForVBlank(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value);

void Encode_IDXGIOutput_TakeOwnership(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    BOOL Exclusive);

void Encode_IDXGIOutput_ReleaseOwnership(
    IDXGIOutput_Wrapper* wrapper);

void Encode_IDXGIOutput_GetGammaControlCapabilities(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps);

void Encode_IDXGIOutput_SetGammaControl(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_GAMMA_CONTROL* pArray);

void Encode_IDXGIOutput_GetGammaControl(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_GAMMA_CONTROL* pArray);

void Encode_IDXGIOutput_SetDisplaySurface(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    IDXGISurface* pScanoutSurface);

void Encode_IDXGIOutput_GetDisplaySurfaceData(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    IDXGISurface* pDestination);

void Encode_IDXGIOutput_GetFrameStatistics(
    IDXGIOutput_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FRAME_STATISTICS* pStats);

void Encode_IDXGISwapChain_Present(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT SyncInterval,
    UINT Flags);

void Encode_IDXGISwapChain_GetBuffer(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT Buffer,
    REFIID riid,
    void** ppSurface);

void Encode_IDXGISwapChain_SetFullscreenState(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    BOOL Fullscreen,
    IDXGIOutput* pTarget);

void Encode_IDXGISwapChain_GetFullscreenState(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    BOOL* pFullscreen,
    IDXGIOutput** ppTarget);

void Encode_IDXGISwapChain_GetDesc(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SWAP_CHAIN_DESC* pDesc);

void Encode_IDXGISwapChain_ResizeBuffers(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT NewFormat,
    UINT SwapChainFlags);

void Encode_IDXGISwapChain_ResizeTarget(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MODE_DESC* pNewTargetParameters);

void Encode_IDXGISwapChain_GetContainingOutput(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIOutput** ppOutput);

void Encode_IDXGISwapChain_GetFrameStatistics(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FRAME_STATISTICS* pStats);

void Encode_IDXGISwapChain_GetLastPresentCount(
    IDXGISwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pLastPresentCount);

void Encode_IDXGIFactory_EnumAdapters(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    UINT Adapter,
    IDXGIAdapter** ppAdapter);

void Encode_IDXGIFactory_MakeWindowAssociation(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    HWND WindowHandle,
    UINT Flags);

void Encode_IDXGIFactory_GetWindowAssociation(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    HWND* pWindowHandle);

void Encode_IDXGIFactory_CreateSwapChain(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain);

void Encode_IDXGIFactory_CreateSoftwareAdapter(
    IDXGIFactory_Wrapper* wrapper,
    HRESULT return_value,
    HMODULE Module,
    IDXGIAdapter** ppAdapter);

void Encode_IDXGIDevice_GetAdapter(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIAdapter** pAdapter);

void Encode_IDXGIDevice_CreateSurface(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_SURFACE_DESC* pDesc,
    UINT NumSurfaces,
    DXGI_USAGE Usage,
    const DXGI_SHARED_RESOURCE* pSharedResource,
    IDXGISurface** ppSurface);

void Encode_IDXGIDevice_QueryResourceResidency(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* const* ppResources,
    DXGI_RESIDENCY* pResidencyStatus,
    UINT NumResources);

void Encode_IDXGIDevice_SetGPUThreadPriority(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    INT Priority);

void Encode_IDXGIDevice_GetGPUThreadPriority(
    IDXGIDevice_Wrapper* wrapper,
    HRESULT return_value,
    INT* pPriority);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_DISPLAY_COLOR_SPACE& value);

void Encode_IDXGIFactory1_EnumAdapters1(
    IDXGIFactory1_Wrapper* wrapper,
    HRESULT return_value,
    UINT Adapter,
    IDXGIAdapter1** ppAdapter);

void Encode_IDXGIFactory1_IsCurrent(
    IDXGIFactory1_Wrapper* wrapper,
    BOOL return_value);

void Encode_IDXGIAdapter1_GetDesc1(
    IDXGIAdapter1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC1* pDesc);

void Encode_IDXGIDevice1_SetMaximumFrameLatency(
    IDXGIDevice1_Wrapper* wrapper,
    HRESULT return_value,
    UINT MaxLatency);

void Encode_IDXGIDevice1_GetMaximumFrameLatency(
    IDXGIDevice1_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pMaxLatency);


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_IDXGIDisplayControl_IsStereoEnabled(
    IDXGIDisplayControl_Wrapper* wrapper,
    BOOL return_value);

void Encode_IDXGIDisplayControl_SetStereoEnabled(
    IDXGIDisplayControl_Wrapper* wrapper,
    BOOL enabled);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_MOVE_RECT& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_POINTER_POSITION& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_POINTER_SHAPE_INFO& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_FRAME_INFO& value);

void Encode_IDXGIOutputDuplication_GetDesc(
    IDXGIOutputDuplication_Wrapper* wrapper,
    DXGI_OUTDUPL_DESC* pDesc);

void Encode_IDXGIOutputDuplication_AcquireNextFrame(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT TimeoutInMilliseconds,
    DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
    IDXGIResource** ppDesktopResource);

void Encode_IDXGIOutputDuplication_GetFrameDirtyRects(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT DirtyRectsBufferSize,
    RECT* pDirtyRectsBuffer,
    UINT* pDirtyRectsBufferSizeRequired);

void Encode_IDXGIOutputDuplication_GetFrameMoveRects(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT MoveRectsBufferSize,
    DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
    UINT* pMoveRectsBufferSizeRequired);

void Encode_IDXGIOutputDuplication_GetFramePointerShape(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    UINT PointerShapeBufferSize,
    void* pPointerShapeBuffer,
    UINT* pPointerShapeBufferSizeRequired,
    DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo);

void Encode_IDXGIOutputDuplication_MapDesktopSurface(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MAPPED_RECT* pLockedRect);

void Encode_IDXGIOutputDuplication_UnMapDesktopSurface(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value);

void Encode_IDXGIOutputDuplication_ReleaseFrame(
    IDXGIOutputDuplication_Wrapper* wrapper,
    HRESULT return_value);

void Encode_IDXGISurface2_GetResource(
    IDXGISurface2_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppParentResource,
    UINT* pSubresourceIndex);

void Encode_IDXGIResource1_CreateSubresourceSurface(
    IDXGIResource1_Wrapper* wrapper,
    HRESULT return_value,
    UINT index,
    IDXGISurface2** ppSurface);

void Encode_IDXGIResource1_CreateSharedHandle(
    IDXGIResource1_Wrapper* wrapper,
    HRESULT return_value,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD dwAccess,
    LPCWSTR lpName,
    HANDLE* pHandle);

void Encode_IDXGIDevice2_OfferResources(
    IDXGIDevice2_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority);

void Encode_IDXGIDevice2_ReclaimResources(
    IDXGIDevice2_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    BOOL* pDiscarded);

void Encode_IDXGIDevice2_EnqueueSetEvent(
    IDXGIDevice2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MODE_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_PRESENT_PARAMETERS& value);

void Encode_IDXGISwapChain1_GetDesc1(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SWAP_CHAIN_DESC1* pDesc);

void Encode_IDXGISwapChain1_GetFullscreenDesc(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc);

void Encode_IDXGISwapChain1_GetHwnd(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    HWND* pHwnd);

void Encode_IDXGISwapChain1_GetCoreWindow(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    REFIID refiid,
    void** ppUnk);

void Encode_IDXGISwapChain1_Present1(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    UINT SyncInterval,
    UINT PresentFlags,
    const DXGI_PRESENT_PARAMETERS* pPresentParameters);

void Encode_IDXGISwapChain1_IsTemporaryMonoSupported(
    IDXGISwapChain1_Wrapper* wrapper,
    BOOL return_value);

void Encode_IDXGISwapChain1_GetRestrictToOutput(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIOutput** ppRestrictToOutput);

void Encode_IDXGISwapChain1_SetBackgroundColor(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_RGBA* pColor);

void Encode_IDXGISwapChain1_GetBackgroundColor(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_RGBA* pColor);

void Encode_IDXGISwapChain1_SetRotation(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MODE_ROTATION Rotation);

void Encode_IDXGISwapChain1_GetRotation(
    IDXGISwapChain1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MODE_ROTATION* pRotation);

void Encode_IDXGIFactory2_IsWindowedStereoEnabled(
    IDXGIFactory2_Wrapper* wrapper,
    BOOL return_value);

void Encode_IDXGIFactory2_CreateSwapChainForHwnd(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    HWND hWnd,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void Encode_IDXGIFactory2_CreateSwapChainForCoreWindow(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    IUnknown* pWindow,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void Encode_IDXGIFactory2_GetSharedResourceAdapterLuid(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hResource,
    LUID* pLuid);

void Encode_IDXGIFactory2_RegisterStereoStatusWindow(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_RegisterStereoStatusEvent(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_UnregisterStereoStatus(
    IDXGIFactory2_Wrapper* wrapper,
    DWORD dwCookie);

void Encode_IDXGIFactory2_RegisterOcclusionStatusWindow(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_RegisterOcclusionStatusEvent(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_UnregisterOcclusionStatus(
    IDXGIFactory2_Wrapper* wrapper,
    DWORD dwCookie);

void Encode_IDXGIFactory2_CreateSwapChainForComposition(
    IDXGIFactory2_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC2& value);

void Encode_IDXGIAdapter2_GetDesc2(
    IDXGIAdapter2_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC2* pDesc);

void Encode_IDXGIOutput1_GetDisplayModeList1(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC1* pDesc);

void Encode_IDXGIOutput1_FindClosestMatchingMode1(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MODE_DESC1* pModeToMatch,
    DXGI_MODE_DESC1* pClosestMatch,
    IUnknown* pConcernedDevice);

void Encode_IDXGIOutput1_GetDisplaySurfaceData1(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    IDXGIResource* pDestination);

void Encode_IDXGIOutput1_DuplicateOutput(
    IDXGIOutput1_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    IDXGIOutputDuplication** ppOutputDuplication);


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_CreateDXGIFactory2(
    HRESULT return_value,
    UINT Flags,
    REFIID riid,
    void** ppFactory);

void Encode_DXGIGetDebugInterface1(
    HRESULT return_value,
    UINT Flags,
    REFIID riid,
    void** pDebug);

void Encode_IDXGIDevice3_Trim(
    IDXGIDevice3_Wrapper* wrapper);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MATRIX_3X2_F& value);

void Encode_IDXGISwapChain2_SetSourceSize(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT Width,
    UINT Height);

void Encode_IDXGISwapChain2_GetSourceSize(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pWidth,
    UINT* pHeight);

void Encode_IDXGISwapChain2_SetMaximumFrameLatency(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT MaxLatency);

void Encode_IDXGISwapChain2_GetMaximumFrameLatency(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pMaxLatency);

void Encode_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    IDXGISwapChain2_Wrapper* wrapper,
    HANDLE return_value);

void Encode_IDXGISwapChain2_SetMatrixTransform(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    const DXGI_MATRIX_3X2_F* pMatrix);

void Encode_IDXGISwapChain2_GetMatrixTransform(
    IDXGISwapChain2_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MATRIX_3X2_F* pMatrix);

void Encode_IDXGIOutput2_SupportsOverlays(
    IDXGIOutput2_Wrapper* wrapper,
    BOOL return_value);

void Encode_IDXGIFactory3_GetCreationFlags(
    IDXGIFactory3_Wrapper* wrapper,
    UINT return_value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_DECODE_SWAP_CHAIN_DESC& value);

void Encode_IDXGIDecodeSwapChain_PresentBuffer(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT BufferToPresent,
    UINT SyncInterval,
    UINT Flags);

void Encode_IDXGIDecodeSwapChain_SetSourceRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    const RECT* pRect);

void Encode_IDXGIDecodeSwapChain_SetTargetRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    const RECT* pRect);

void Encode_IDXGIDecodeSwapChain_SetDestSize(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT Width,
    UINT Height);

void Encode_IDXGIDecodeSwapChain_GetSourceRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    RECT* pRect);

void Encode_IDXGIDecodeSwapChain_GetTargetRect(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    RECT* pRect);

void Encode_IDXGIDecodeSwapChain_GetDestSize(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pWidth,
    UINT* pHeight);

void Encode_IDXGIDecodeSwapChain_SetColorSpace(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace);

void Encode_IDXGIDecodeSwapChain_GetColorSpace(
    IDXGIDecodeSwapChain_Wrapper* wrapper,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS return_value);

void Encode_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
    IDXGIFactoryMedia_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    HANDLE hSurface,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void Encode_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
    IDXGIFactoryMedia_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* pDevice,
    HANDLE hSurface,
    DXGI_DECODE_SWAP_CHAIN_DESC* pDesc,
    IDXGIResource* pYuvDecodeBuffers,
    IDXGIOutput* pRestrictToOutput,
    IDXGIDecodeSwapChain** ppSwapChain);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_FRAME_STATISTICS_MEDIA& value);

void Encode_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    IDXGISwapChainMedia_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FRAME_STATISTICS_MEDIA* pStats);

void Encode_IDXGISwapChainMedia_SetPresentDuration(
    IDXGISwapChainMedia_Wrapper* wrapper,
    HRESULT return_value,
    UINT Duration);

void Encode_IDXGISwapChainMedia_CheckPresentDurationSupport(
    IDXGISwapChainMedia_Wrapper* wrapper,
    HRESULT return_value,
    UINT DesiredPresentDuration,
    UINT* pClosestSmallerPresentDuration,
    UINT* pClosestLargerPresentDuration);

void Encode_IDXGIOutput3_CheckOverlaySupport(
    IDXGIOutput3_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT EnumFormat,
    IUnknown* pConcernedDevice,
    UINT* pFlags);


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_IDXGISwapChain3_GetCurrentBackBufferIndex(
    IDXGISwapChain3_Wrapper* wrapper,
    UINT return_value);

void Encode_IDXGISwapChain3_CheckColorSpaceSupport(
    IDXGISwapChain3_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    UINT* pColorSpaceSupport);

void Encode_IDXGISwapChain3_SetColorSpace1(
    IDXGISwapChain3_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_COLOR_SPACE_TYPE ColorSpace);

void Encode_IDXGISwapChain3_ResizeBuffers1(
    IDXGISwapChain3_Wrapper* wrapper,
    HRESULT return_value,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT Format,
    UINT SwapChainFlags,
    const UINT* pCreationNodeMask,
    IUnknown* const* ppPresentQueue);

void Encode_IDXGIOutput4_CheckOverlayColorSpaceSupport(
    IDXGIOutput4_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_FORMAT Format,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    IUnknown* pConcernedDevice,
    UINT* pFlags);

void Encode_IDXGIFactory4_EnumAdapterByLuid(
    IDXGIFactory4_Wrapper* wrapper,
    HRESULT return_value,
    LUID AdapterLuid,
    REFIID riid,
    void** ppvAdapter);

void Encode_IDXGIFactory4_EnumWarpAdapter(
    IDXGIFactory4_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppvAdapter);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_QUERY_VIDEO_MEMORY_INFO& value);

void Encode_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
    IDXGIAdapter3_Wrapper* wrapper,
    DWORD dwCookie);

void Encode_IDXGIAdapter3_QueryVideoMemoryInfo(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo);

void Encode_IDXGIAdapter3_SetVideoMemoryReservation(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    UINT64 Reservation);

void Encode_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    IDXGIAdapter3_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
    IDXGIAdapter3_Wrapper* wrapper,
    DWORD dwCookie);


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
    IDXGIOutputDuplication** ppOutputDuplication);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_HDR_METADATA_HDR10& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_HDR_METADATA_HDR10PLUS& value);

void Encode_IDXGISwapChain4_SetHDRMetaData(
    IDXGISwapChain4_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_HDR_METADATA_TYPE Type,
    UINT Size,
    void* pMetaData);

void Encode_IDXGIDevice4_OfferResources1(
    IDXGIDevice4_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority,
    UINT Flags);

void Encode_IDXGIDevice4_ReclaimResources1(
    IDXGIDevice4_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_RECLAIM_RESOURCE_RESULTS* pResults);


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_DXGIDeclareAdapterRemovalSupport(
    HRESULT return_value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC3& value);

void Encode_IDXGIAdapter4_GetDesc3(
    IDXGIAdapter4_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_ADAPTER_DESC3* pDesc);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTPUT_DESC1& value);

void Encode_IDXGIOutput6_GetDesc1(
    IDXGIOutput6_Wrapper* wrapper,
    HRESULT return_value,
    DXGI_OUTPUT_DESC1* pDesc);

void Encode_IDXGIOutput6_CheckHardwareCompositionSupport(
    IDXGIOutput6_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pFlags);

void Encode_IDXGIFactory6_EnumAdapterByGpuPreference(
    IDXGIFactory6_Wrapper* wrapper,
    HRESULT return_value,
    UINT Adapter,
    DXGI_GPU_PREFERENCE GpuPreference,
    REFIID riid,
    void** ppvAdapter);

void Encode_IDXGIFactory7_RegisterAdaptersChangedEvent(
    IDXGIFactory7_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    IDXGIFactory7_Wrapper* wrapper,
    HRESULT return_value,
    DWORD dwCookie);


/*
** This part is generated from dxgicommon.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const DXGI_RATIONAL& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SAMPLE_DESC& value);


/*
** This part is generated from dxgiformat.h in Windows SDK: 10.0.20348.0
**
*/


/*
** This part is generated from dxgitype.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const DXGI_RGB& value);

void EncodeStruct(ParameterEncoder* encoder, const D3DCOLORVALUE& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_GAMMA_CONTROL& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_GAMMA_CONTROL_CAPABILITIES& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MODE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_JPEG_DC_HUFFMAN_TABLE& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_JPEG_AC_HUFFMAN_TABLE& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_JPEG_QUANTIZATION_TABLE& value);


/*
** This part is generated from d3d12.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_D3D12SerializeRootSignature(
    HRESULT return_value,
    const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION Version,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob);

void Encode_D3D12CreateRootSignatureDeserializer(
    HRESULT return_value,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

void Encode_D3D12SerializeVersionedRootSignature(
    HRESULT return_value,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob);

void Encode_D3D12CreateVersionedRootSignatureDeserializer(
    HRESULT return_value,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

void Encode_D3D12CreateDevice(
    HRESULT return_value,
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice);

void Encode_D3D12GetDebugInterface(
    HRESULT return_value,
    REFIID riid,
    void** ppvDebug);

void Encode_D3D12EnableExperimentalFeatures(
    HRESULT return_value,
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes);

void Encode_D3D12GetInterface(
    HRESULT return_value,
    REFCLSID rclsid,
    REFIID riid,
    void** ppvDebug);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_QUEUE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INPUT_ELEMENT_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SO_DECLARATION_ENTRY& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VIEWPORT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BOX& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCILOP_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCILOP_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC2& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_TARGET_BLEND_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BLEND_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RASTERIZER_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RASTERIZER_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RASTERIZER_DESC2& value);

void Encode_ID3D12Object_GetPrivateData(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID guid,
    UINT* pDataSize,
    void* pData);

void Encode_ID3D12Object_SetPrivateData(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID guid,
    UINT DataSize,
    const void* pData);

void Encode_ID3D12Object_SetPrivateDataInterface(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID guid,
    const IUnknown* pData);

void Encode_ID3D12Object_SetName(
    ID3D12Object_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR Name);

void Encode_ID3D12DeviceChild_GetDevice(
    ID3D12DeviceChild_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppvDevice);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SHADER_BYTECODE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STREAM_OUTPUT_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INPUT_LAYOUT_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CACHED_PIPELINE_STATE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GRAPHICS_PIPELINE_STATE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMPUTE_PIPELINE_STATE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RT_FORMAT_ARRAY& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS2& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_ROOT_SIGNATURE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_ARCHITECTURE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_ARCHITECTURE1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_FEATURE_LEVELS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_SHADER_MODEL& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_FORMAT_SUPPORT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_MULTISAMPLE_QUALITY_LEVELS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_FORMAT_INFO& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_GPU_VIRTUAL_ADDRESS_SUPPORT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_SHADER_CACHE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_COMMAND_QUEUE_PRIORITY& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS3& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_EXISTING_HEAPS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_DISPLAYABLE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS4& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_SERIALIZATION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_CROSS_NODE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS5& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS6& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS7& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_QUERY_META_COMMAND& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS8& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS9& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS10& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS11& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS12& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS13& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS14& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS15& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS16& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS17& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS18& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS19& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_ALLOCATION_INFO& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_ALLOCATION_INFO1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_HEAP_PROPERTIES& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_HEAP_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MIP_REGION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_VALUE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RANGE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RANGE_UINT64& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_RANGE_UINT64& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_INFO& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TILED_RESOURCE_COORDINATE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TILE_REGION_SIZE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_TILING& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TILE_SHAPE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PACKED_MIP_INFO& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_TRANSITION_BARRIER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_ALIASING_BARRIER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RESOURCE_UAV_BARRIER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_FOOTPRINT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PLACED_SUBRESOURCE_FOOTPRINT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SAMPLE_POSITION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VIEW_INSTANCE_LOCATION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VIEW_INSTANCING_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX3D_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXCUBE_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXCUBE_ARRAY_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_SRV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_CONSTANT_BUFFER_VIEW_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SAMPLER_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX3D_UAV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX3D_RTV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_DSV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX1D_ARRAY_DSV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_DSV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2D_ARRAY_DSV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_DSV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEX2DMS_ARRAY_DSV& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DESCRIPTOR_HEAP_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DESCRIPTOR_RANGE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR_TABLE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_CONSTANTS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATIC_SAMPLER_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATIC_SAMPLER_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DESCRIPTOR_RANGE1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR_TABLE1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC2& value);

void Encode_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    ID3D12RootSignatureDeserializer_Wrapper* wrapper,
    const D3D12_ROOT_SIGNATURE_DESC * return_value);

void Encode_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
    ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper,
    HRESULT return_value,
    D3D_ROOT_SIGNATURE_VERSION convertToVersion,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc);

void Encode_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    ID3D12VersionedRootSignatureDeserializer_Wrapper* wrapper,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC * return_value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_DESCRIPTOR_HANDLE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISCARD_REGION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_HEAP_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_PIPELINE_STATISTICS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_PIPELINE_STATISTICS1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_SO_STATISTICS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STREAM_OUTPUT_BUFFER_VIEW& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRAW_ARGUMENTS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRAW_INDEXED_ARGUMENTS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_ARGUMENTS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERTEX_BUFFER_VIEW& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INDEX_BUFFER_VIEW& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_SIGNATURE_DESC& value);

void Encode_ID3D12Heap_GetDesc(
    ID3D12Heap_Wrapper* wrapper,
    D3D12_HEAP_DESC return_value);

void Encode_ID3D12Resource_Map(
    ID3D12Resource_Wrapper* wrapper,
    HRESULT return_value,
    UINT Subresource,
    const D3D12_RANGE* pReadRange,
    void** ppData);

void Encode_ID3D12Resource_Unmap(
    ID3D12Resource_Wrapper* wrapper,
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange);

void Encode_ID3D12Resource_GetDesc(
    ID3D12Resource_Wrapper* wrapper,
    D3D12_RESOURCE_DESC return_value);

void Encode_ID3D12Resource_GetGPUVirtualAddress(
    ID3D12Resource_Wrapper* wrapper,
    D3D12_GPU_VIRTUAL_ADDRESS return_value);

void Encode_ID3D12Resource_ReadFromSubresource(
    ID3D12Resource_Wrapper* wrapper,
    HRESULT return_value,
    void* pDstData,
    UINT DstRowPitch,
    UINT DstDepthPitch,
    UINT SrcSubresource,
    const D3D12_BOX* pSrcBox);

void Encode_ID3D12Resource_GetHeapProperties(
    ID3D12Resource_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS* pHeapFlags);

void Encode_ID3D12CommandAllocator_Reset(
    ID3D12CommandAllocator_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12Fence_GetCompletedValue(
    ID3D12Fence_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12Fence_SetEventOnCompletion(
    ID3D12Fence_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Value,
    HANDLE hEvent);

void Encode_ID3D12Fence_Signal(
    ID3D12Fence_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 Value);

void Encode_ID3D12Fence1_GetCreationFlags(
    ID3D12Fence1_Wrapper* wrapper,
    D3D12_FENCE_FLAGS return_value);

void Encode_ID3D12PipelineState_GetCachedBlob(
    ID3D12PipelineState_Wrapper* wrapper,
    HRESULT return_value,
    ID3DBlob** ppBlob);

void Encode_ID3D12DescriptorHeap_GetDesc(
    ID3D12DescriptorHeap_Wrapper* wrapper,
    D3D12_DESCRIPTOR_HEAP_DESC return_value);

void Encode_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper,
    D3D12_CPU_DESCRIPTOR_HANDLE return_value);

void Encode_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    ID3D12DescriptorHeap_Wrapper* wrapper,
    D3D12_GPU_DESCRIPTOR_HANDLE return_value);

void Encode_ID3D12CommandList_GetType(
    ID3D12CommandList_Wrapper* wrapper,
    D3D12_COMMAND_LIST_TYPE return_value);

void Encode_ID3D12GraphicsCommandList_Close(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12GraphicsCommandList_Reset(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12CommandAllocator* pAllocator,
    ID3D12PipelineState* pInitialState);

void Encode_ID3D12GraphicsCommandList_ClearState(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12PipelineState* pPipelineState);

void Encode_ID3D12GraphicsCommandList_DrawInstanced(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT VertexCountPerInstance,
    UINT InstanceCount,
    UINT StartVertexLocation,
    UINT StartInstanceLocation);

void Encode_ID3D12GraphicsCommandList_DrawIndexedInstanced(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT IndexCountPerInstance,
    UINT InstanceCount,
    UINT StartIndexLocation,
    INT BaseVertexLocation,
    UINT StartInstanceLocation);

void Encode_ID3D12GraphicsCommandList_Dispatch(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ);

void Encode_ID3D12GraphicsCommandList_CopyBufferRegion(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT64 NumBytes);

void Encode_ID3D12GraphicsCommandList_CopyTextureRegion(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    const D3D12_TEXTURE_COPY_LOCATION* pDst,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    const D3D12_TEXTURE_COPY_LOCATION* pSrc,
    const D3D12_BOX* pSrcBox);

void Encode_ID3D12GraphicsCommandList_CopyResource(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pDstResource,
    ID3D12Resource* pSrcResource);

void Encode_ID3D12GraphicsCommandList_CopyTiles(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pTiledResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pTileRegionSize,
    ID3D12Resource* pBuffer,
    UINT64 BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS Flags);

void Encode_ID3D12GraphicsCommandList_ResolveSubresource(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pDstResource,
    UINT DstSubresource,
    ID3D12Resource* pSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT Format);

void Encode_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology);

void Encode_ID3D12GraphicsCommandList_RSSetViewports(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumViewports,
    const D3D12_VIEWPORT* pViewports);

void Encode_ID3D12GraphicsCommandList_RSSetScissorRects(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_OMSetBlendFactor(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    const FLOAT BlendFactor [4]);

void Encode_ID3D12GraphicsCommandList_OMSetStencilRef(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT StencilRef);

void Encode_ID3D12GraphicsCommandList_SetPipelineState(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12PipelineState* pPipelineState);

void Encode_ID3D12GraphicsCommandList_ResourceBarrier(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumBarriers,
    const D3D12_RESOURCE_BARRIER* pBarriers);

void Encode_ID3D12GraphicsCommandList_ExecuteBundle(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12GraphicsCommandList* pCommandList);

void Encode_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumDescriptorHeaps,
    ID3D12DescriptorHeap* const* ppDescriptorHeaps);

void Encode_ID3D12GraphicsCommandList_SetComputeRootSignature(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12RootSignature* pRootSignature);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12RootSignature* pRootSignature);

void Encode_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_IASetIndexBuffer(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    const D3D12_INDEX_BUFFER_VIEW* pView);

void Encode_ID3D12GraphicsCommandList_IASetVertexBuffers(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_VERTEX_BUFFER_VIEW* pViews);

void Encode_ID3D12GraphicsCommandList_SOSetTargets(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews);

void Encode_ID3D12GraphicsCommandList_OMSetRenderTargets(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT NumRenderTargetDescriptors,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
    BOOL RTsSingleHandleToDescriptorRange,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor);

void Encode_ID3D12GraphicsCommandList_ClearDepthStencilView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
    D3D12_CLEAR_FLAGS ClearFlags,
    FLOAT Depth,
    UINT8 Stencil,
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_ClearRenderTargetView(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
    const FLOAT ColorRGBA [4],
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const UINT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const FLOAT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_DiscardResource(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_DISCARD_REGION* pRegion);

void Encode_ID3D12GraphicsCommandList_BeginQuery(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index);

void Encode_ID3D12GraphicsCommandList_EndQuery(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index);

void Encode_ID3D12GraphicsCommandList_ResolveQueryData(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT StartIndex,
    UINT NumQueries,
    ID3D12Resource* pDestinationBuffer,
    UINT64 AlignedDestinationBufferOffset);

void Encode_ID3D12GraphicsCommandList_SetPredication(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12Resource* pBuffer,
    UINT64 AlignedBufferOffset,
    D3D12_PREDICATION_OP Operation);

void Encode_ID3D12GraphicsCommandList_SetMarker(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12GraphicsCommandList_BeginEvent(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12GraphicsCommandList_EndEvent(
    ID3D12GraphicsCommandList_Wrapper* wrapper);

void Encode_ID3D12GraphicsCommandList_ExecuteIndirect(
    ID3D12GraphicsCommandList_Wrapper* wrapper,
    ID3D12CommandSignature* pCommandSignature,
    UINT MaxCommandCount,
    ID3D12Resource* pArgumentBuffer,
    UINT64 ArgumentBufferOffset,
    ID3D12Resource* pCountBuffer,
    UINT64 CountBufferOffset);

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

void Encode_ID3D12GraphicsCommandList1_OMSetDepthBounds(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    FLOAT Min,
    FLOAT Max);

void Encode_ID3D12GraphicsCommandList1_SetSamplePositions(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    UINT NumSamplesPerPixel,
    UINT NumPixels,
    D3D12_SAMPLE_POSITION* pSamplePositions);

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
    D3D12_RESOLVE_MODE ResolveMode);

void Encode_ID3D12GraphicsCommandList1_SetViewInstanceMask(
    ID3D12GraphicsCommandList1_Wrapper* wrapper,
    UINT Mask);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& value);

void Encode_ID3D12GraphicsCommandList2_WriteBufferImmediate(
    ID3D12GraphicsCommandList2_Wrapper* wrapper,
    UINT Count,
    const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
    const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes);

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
    D3D12_TILE_MAPPING_FLAGS Flags);

void Encode_ID3D12CommandQueue_CopyTileMappings(
    ID3D12CommandQueue_Wrapper* wrapper,
    ID3D12Resource* pDstResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
    ID3D12Resource* pSrcResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS Flags);

void Encode_ID3D12CommandQueue_SetMarker(
    ID3D12CommandQueue_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12CommandQueue_BeginEvent(
    ID3D12CommandQueue_Wrapper* wrapper,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12CommandQueue_EndEvent(
    ID3D12CommandQueue_Wrapper* wrapper);

void Encode_ID3D12CommandQueue_Signal(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* pFence,
    UINT64 Value);

void Encode_ID3D12CommandQueue_Wait(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* pFence,
    UINT64 Value);

void Encode_ID3D12CommandQueue_GetTimestampFrequency(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64* pFrequency);

void Encode_ID3D12CommandQueue_GetClockCalibration(
    ID3D12CommandQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64* pGpuTimestamp,
    UINT64* pCpuTimestamp);

void Encode_ID3D12CommandQueue_GetDesc(
    ID3D12CommandQueue_Wrapper* wrapper,
    D3D12_COMMAND_QUEUE_DESC return_value);

void Encode_ID3D12Device_GetNodeCount(
    ID3D12Device_Wrapper* wrapper,
    UINT return_value);

void Encode_ID3D12Device_CreateCommandQueue(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID riid,
    void** ppCommandQueue);

void Encode_ID3D12Device_CreateCommandAllocator(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_COMMAND_LIST_TYPE type,
    REFIID riid,
    void** ppCommandAllocator);

void Encode_ID3D12Device_CreateGraphicsPipelineState(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device_CreateComputePipelineState(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device_CreateCommandList(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    ID3D12CommandAllocator* pCommandAllocator,
    ID3D12PipelineState* pInitialState,
    REFIID riid,
    void** ppCommandList);

void Encode_ID3D12Device_CreateDescriptorHeap(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device_GetDescriptorHandleIncrementSize(
    ID3D12Device_Wrapper* wrapper,
    UINT return_value,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType);

void Encode_ID3D12Device_CreateRootSignature(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT nodeMask,
    const void* pBlobWithRootSignature,
    SIZE_T blobLengthInBytes,
    REFIID riid,
    void** ppvRootSignature);

void Encode_ID3D12Device_CreateConstantBufferView(
    ID3D12Device_Wrapper* wrapper,
    const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateShaderResourceView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateUnorderedAccessView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    ID3D12Resource* pCounterResource,
    const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateRenderTargetView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateDepthStencilView(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pResource,
    const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateSampler(
    ID3D12Device_Wrapper* wrapper,
    const D3D12_SAMPLER_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CopyDescriptors(
    ID3D12Device_Wrapper* wrapper,
    UINT NumDestDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
    const UINT* pDestDescriptorRangeSizes,
    UINT NumSrcDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
    const UINT* pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

void Encode_ID3D12Device_CopyDescriptorsSimple(
    ID3D12Device_Wrapper* wrapper,
    UINT NumDescriptors,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

void Encode_ID3D12Device_GetResourceAllocationInfo(
    ID3D12Device_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs);

void Encode_ID3D12Device_GetCustomHeapProperties(
    ID3D12Device_Wrapper* wrapper,
    D3D12_HEAP_PROPERTIES return_value,
    UINT nodeMask,
    D3D12_HEAP_TYPE heapType);

void Encode_ID3D12Device_CreateCommittedResource(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riidResource,
    void** ppvResource);

void Encode_ID3D12Device_CreateHeap(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device_CreatePlacedResource(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device_CreateReservedResource(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device_CreateSharedHandle(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12DeviceChild* pObject,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD Access,
    LPCWSTR Name,
    HANDLE* pHandle);

void Encode_ID3D12Device_OpenSharedHandle(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE NTHandle,
    REFIID riid,
    void** ppvObj);

void Encode_ID3D12Device_OpenSharedHandleByName(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR Name,
    DWORD Access,
    HANDLE* pNTHandle);

void Encode_ID3D12Device_MakeResident(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects);

void Encode_ID3D12Device_Evict(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects);

void Encode_ID3D12Device_CreateFence(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 InitialValue,
    D3D12_FENCE_FLAGS Flags,
    REFIID riid,
    void** ppFence);

void Encode_ID3D12Device_GetDeviceRemovedReason(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12Device_GetCopyableFootprints(
    ID3D12Device_Wrapper* wrapper,
    const D3D12_RESOURCE_DESC* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes);

void Encode_ID3D12Device_CreateQueryHeap(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_QUERY_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device_SetStablePowerState(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    BOOL Enable);

void Encode_ID3D12Device_CreateCommandSignature(
    ID3D12Device_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
    ID3D12RootSignature* pRootSignature,
    REFIID riid,
    void** ppvCommandSignature);

void Encode_ID3D12Device_GetResourceTiling(
    ID3D12Device_Wrapper* wrapper,
    ID3D12Resource* pTiledResource,
    UINT* pNumTilesForEntireResource,
    D3D12_PACKED_MIP_INFO* pPackedMipDesc,
    D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
    UINT* pNumSubresourceTilings,
    UINT FirstSubresourceTilingToGet,
    D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips);

void Encode_ID3D12Device_GetAdapterLuid(
    ID3D12Device_Wrapper* wrapper,
    LUID return_value);

void Encode_ID3D12PipelineLibrary_StorePipeline(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    ID3D12PipelineState* pPipeline);

void Encode_ID3D12PipelineLibrary_LoadGraphicsPipeline(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12PipelineLibrary_LoadComputePipeline(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12PipelineLibrary_GetSerializedSize(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    SIZE_T return_value);

void Encode_ID3D12PipelineLibrary_Serialize(
    ID3D12PipelineLibrary_Wrapper* wrapper,
    HRESULT return_value,
    void* pData,
    SIZE_T DataSizeInBytes);

void Encode_ID3D12PipelineLibrary1_LoadPipeline(
    ID3D12PipelineLibrary1_Wrapper* wrapper,
    HRESULT return_value,
    LPCWSTR pName,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device1_CreatePipelineLibrary(
    ID3D12Device1_Wrapper* wrapper,
    HRESULT return_value,
    const void* pLibraryBlob,
    SIZE_T BlobLength,
    REFIID riid,
    void** ppPipelineLibrary);

void Encode_ID3D12Device1_SetEventOnMultipleFenceCompletion(
    ID3D12Device1_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* const* ppFences,
    const UINT64* pFenceValues,
    UINT NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
    HANDLE hEvent);

void Encode_ID3D12Device1_SetResidencyPriority(
    ID3D12Device1_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    const D3D12_RESIDENCY_PRIORITY* pPriorities);

void Encode_ID3D12Device2_CreatePipelineState(
    ID3D12Device2_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device3_OpenExistingHeapFromAddress(
    ID3D12Device3_Wrapper* wrapper,
    HRESULT return_value,
    const void* pAddress,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device3_OpenExistingHeapFromFileMapping(
    ID3D12Device3_Wrapper* wrapper,
    HRESULT return_value,
    HANDLE hFileMapping,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device3_EnqueueMakeResident(
    ID3D12Device3_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_RESIDENCY_FLAGS Flags,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    ID3D12Fence* pFenceToSignal,
    UINT64 FenceValueToSignal);

void Encode_ID3D12ProtectedSession_GetStatusFence(
    ID3D12ProtectedSession_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppFence);

void Encode_ID3D12ProtectedSession_GetSessionStatus(
    ID3D12ProtectedSession_Wrapper* wrapper,
    D3D12_PROTECTED_SESSION_STATUS return_value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PROTECTED_RESOURCE_SESSION_DESC& value);

void Encode_ID3D12ProtectedResourceSession_GetDesc(
    ID3D12ProtectedResourceSession_Wrapper* wrapper,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC return_value);

void Encode_ID3D12Device4_CreateCommandList1(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    D3D12_COMMAND_LIST_FLAGS flags,
    REFIID riid,
    void** ppCommandList);

void Encode_ID3D12Device4_CreateProtectedResourceSession(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppSession);

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
    void** ppvResource);

void Encode_ID3D12Device4_CreateHeap1(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_HEAP_DESC* pDesc,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device4_CreateReservedResource1(
    ID3D12Device4_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device4_GetResourceAllocationInfo1(
    ID3D12Device4_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

void Encode_ID3D12LifetimeOwner_LifetimeStateUpdated(
    ID3D12LifetimeOwner_Wrapper* wrapper,
    D3D12_LIFETIME_STATE NewState);

void Encode_ID3D12SwapChainAssistant_GetLUID(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    LUID return_value);

void Encode_ID3D12SwapChainAssistant_GetSwapChainObject(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppv);

void Encode_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riidResource,
    void** ppvResource,
    REFIID riidQueue,
    void** ppvQueue);

void Encode_ID3D12SwapChainAssistant_InsertImplicitSync(
    ID3D12SwapChainAssistant_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12LifetimeTracker_DestroyOwnedObject(
    ID3D12LifetimeTracker_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12DeviceChild* pObject);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_META_COMMAND_PARAMETER_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_META_COMMAND_DESC& value);

void Encode_ID3D12StateObjectProperties_GetShaderIdentifier(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    void* return_value,
    LPCWSTR pExportName);

void Encode_ID3D12StateObjectProperties_GetShaderStackSize(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    UINT64 return_value,
    LPCWSTR pExportName);

void Encode_ID3D12StateObjectProperties_GetPipelineStackSize(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12StateObjectProperties_SetPipelineStackSize(
    ID3D12StateObjectProperties_Wrapper* wrapper,
    UINT64 PipelineStackSizeInBytes);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STATE_OBJECT_CONFIG& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GLOBAL_ROOT_SIGNATURE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_LOCAL_ROOT_SIGNATURE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_NODE_MASK& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_EXPORT_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DXIL_LIBRARY_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_EXISTING_COLLECTION_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DXIL_SUBOBJECT_TO_EXPORTS_ASSOCIATION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_HIT_GROUP_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_SHADER_CONFIG& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_PIPELINE_CONFIG& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_PIPELINE_CONFIG1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_VIRTUAL_ADDRESS_AND_STRIDE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GPU_VIRTUAL_ADDRESS_RANGE_AND_STRIDE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_AABB& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_GEOMETRY_AABBS_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_COMPACTED_SIZE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_TOOLS_VISUALIZATION_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_TOOLS_VISUALIZATION_HEADER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_SERIALIZATION_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SERIALIZED_RAYTRACING_ACCELERATION_STRUCTURE_HEADER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_CURRENT_SIZE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_INSTANCE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO& value);

void Encode_ID3D12Device5_CreateLifetimeTracker(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12LifetimeOwner* pOwner,
    REFIID riid,
    void** ppvTracker);

void Encode_ID3D12Device5_RemoveDevice(
    ID3D12Device5_Wrapper* wrapper);

void Encode_ID3D12Device5_EnumerateMetaCommands(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    UINT* pNumMetaCommands,
    D3D12_META_COMMAND_DESC* pDescs);

void Encode_ID3D12Device5_EnumerateMetaCommandParameters(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT* pTotalStructureSizeInBytes,
    UINT* pParameterCount,
    D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs);

void Encode_ID3D12Device5_CreateMetaCommand(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    REFGUID CommandId,
    UINT NodeMask,
    const void* pCreationParametersData,
    SIZE_T CreationParametersDataSizeInBytes,
    REFIID riid,
    void** ppMetaCommand);

void Encode_ID3D12Device5_CreateStateObject(
    ID3D12Device5_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_STATE_OBJECT_DESC* pDesc,
    REFIID riid,
    void** ppStateObject);

void Encode_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
    ID3D12Device5_Wrapper* wrapper,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo);

void Encode_ID3D12Device5_CheckDriverMatchingIdentifier(
    ID3D12Device5_Wrapper* wrapper,
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS return_value,
    D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
    const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_AUTO_BREADCRUMB_NODE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_BREADCRUMB_CONTEXT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_AUTO_BREADCRUMB_NODE1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_ALLOCATION_NODE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_ALLOCATION_NODE1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_PAGE_FAULT_OUTPUT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_PAGE_FAULT_OUTPUT1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRED_PAGE_FAULT_OUTPUT2& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA3& value);

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
    ID3D12DeviceRemovedExtendedDataSettings1_Wrapper* wrapper,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedDataSettings2_UseMarkersOnlyAutoBreadcrumbs(
    ID3D12DeviceRemovedExtendedDataSettings2_Wrapper* wrapper,
    BOOL MarkersOnly);

void Encode_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    ID3D12DeviceRemovedExtendedData_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    ID3D12DeviceRemovedExtendedData_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    ID3D12DeviceRemovedExtendedData1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    ID3D12DeviceRemovedExtendedData1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData2_GetPageFaultAllocationOutput2(
    ID3D12DeviceRemovedExtendedData2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DRED_PAGE_FAULT_OUTPUT2* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData2_GetDeviceState(
    ID3D12DeviceRemovedExtendedData2_Wrapper* wrapper,
    D3D12_DRED_DEVICE_STATE return_value);

void Encode_ID3D12Device6_SetBackgroundProcessingMode(
    ID3D12Device6_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_BACKGROUND_PROCESSING_MODE Mode,
    D3D12_MEASUREMENTS_ACTION MeasurementsAction,
    HANDLE hEventToSignalUponCompletion,
    BOOL* pbFurtherMeasurementsDesired);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& value);

void Encode_ID3D12ProtectedResourceSession1_GetDesc1(
    ID3D12ProtectedResourceSession1_Wrapper* wrapper,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC1 return_value);

void Encode_ID3D12Device7_AddToStateObject(
    ID3D12Device7_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_STATE_OBJECT_DESC* pAddition,
    ID3D12StateObject* pStateObjectToGrowFrom,
    REFIID riid,
    void** ppNewStateObject);

void Encode_ID3D12Device7_CreateProtectedResourceSession1(
    ID3D12Device7_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
    REFIID riid,
    void** ppSession);

void Encode_ID3D12Device8_GetResourceAllocationInfo2(
    ID3D12Device8_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC1* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

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
    void** ppvResource);

void Encode_ID3D12Device8_CreatePlacedResource1(
    ID3D12Device8_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    ID3D12Device8_Wrapper* wrapper,
    ID3D12Resource* pTargetedResource,
    ID3D12Resource* pFeedbackResource,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device8_GetCopyableFootprints1(
    ID3D12Device8_Wrapper* wrapper,
    const D3D12_RESOURCE_DESC1* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes);

void Encode_ID3D12Resource1_GetProtectedResourceSession(
    ID3D12Resource1_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppProtectedSession);

void Encode_ID3D12Resource2_GetDesc1(
    ID3D12Resource2_Wrapper* wrapper,
    D3D12_RESOURCE_DESC1 return_value);

void Encode_ID3D12Heap1_GetProtectedResourceSession(
    ID3D12Heap1_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppProtectedSession);

void Encode_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
    ID3D12GraphicsCommandList3_Wrapper* wrapper,
    ID3D12ProtectedResourceSession* pProtectedResourceSession);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS_PRESERVE_LOCAL_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_PRESERVE_LOCAL_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_RENDER_TARGET_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& value);

void Encode_ID3D12MetaCommand_GetRequiredParameterResourceSize(
    ID3D12MetaCommand_Wrapper* wrapper,
    UINT64 return_value,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT ParameterIndex);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_RAYS_DESC& value);

void Encode_ID3D12GraphicsCommandList4_BeginRenderPass(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    UINT NumRenderTargets,
    const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
    const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS Flags);

void Encode_ID3D12GraphicsCommandList4_EndRenderPass(
    ID3D12GraphicsCommandList4_Wrapper* wrapper);

void Encode_ID3D12GraphicsCommandList4_InitializeMetaCommand(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    ID3D12MetaCommand* pMetaCommand,
    const void* pInitializationParametersData,
    SIZE_T InitializationParametersDataSizeInBytes);

void Encode_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    ID3D12MetaCommand* pMetaCommand,
    const void* pExecutionParametersData,
    SIZE_T ExecutionParametersDataSizeInBytes);

void Encode_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
    UINT NumPostbuildInfoDescs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs);

void Encode_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
    UINT NumSourceAccelerationStructures,
    const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData);

void Encode_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode);

void Encode_ID3D12GraphicsCommandList4_SetPipelineState1(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    ID3D12StateObject* pStateObject);

void Encode_ID3D12GraphicsCommandList4_DispatchRays(
    ID3D12GraphicsCommandList4_Wrapper* wrapper,
    const D3D12_DISPATCH_RAYS_DESC* pDesc);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SHADER_CACHE_SESSION_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BARRIER_SUBRESOURCE_RANGE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_GLOBAL_BARRIER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_TEXTURE_BARRIER& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BUFFER_BARRIER& value);

void Encode_ID3D12ShaderCacheSession_FindValue(
    ID3D12ShaderCacheSession_Wrapper* wrapper,
    HRESULT return_value,
    const void* pKey,
    UINT KeySize,
    void* pValue,
    UINT* pValueSize);

void Encode_ID3D12ShaderCacheSession_StoreValue(
    ID3D12ShaderCacheSession_Wrapper* wrapper,
    HRESULT return_value,
    const void* pKey,
    UINT KeySize,
    const void* pValue,
    UINT ValueSize);

void Encode_ID3D12ShaderCacheSession_SetDeleteOnDestroy(
    ID3D12ShaderCacheSession_Wrapper* wrapper);

void Encode_ID3D12ShaderCacheSession_GetDesc(
    ID3D12ShaderCacheSession_Wrapper* wrapper,
    D3D12_SHADER_CACHE_SESSION_DESC return_value);

void Encode_ID3D12Device9_CreateShaderCacheSession(
    ID3D12Device9_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_SHADER_CACHE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppvSession);

void Encode_ID3D12Device9_ShaderCacheControl(
    ID3D12Device9_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_SHADER_CACHE_KIND_FLAGS Kinds,
    D3D12_SHADER_CACHE_CONTROL_FLAGS Control);

void Encode_ID3D12Device9_CreateCommandQueue1(
    ID3D12Device9_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID CreatorID,
    REFIID riid,
    void** ppCommandQueue);

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
    void** ppvResource);

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
    void** ppvResource);

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
    void** ppvResource);

void Encode_ID3D12Device11_CreateSampler2(
    ID3D12Device11_Wrapper* wrapper,
    const D3D12_SAMPLER_DESC2* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device12_GetResourceAllocationInfo3(
    ID3D12Device12_Wrapper* wrapper,
    D3D12_RESOURCE_ALLOCATION_INFO return_value,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC1* pResourceDescs,
    const UINT32* pNumCastableFormats,
    const DXGI_FORMAT* const* ppCastableFormats,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

void Encode_ID3D12VirtualizationGuestDevice_ShareWithHost(
    ID3D12VirtualizationGuestDevice_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12DeviceChild* pObject,
    HANDLE* pHandle);

void Encode_ID3D12VirtualizationGuestDevice_CreateFenceFd(
    ID3D12VirtualizationGuestDevice_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Fence* pFence,
    UINT64 FenceValue,
    int* pFenceFd);

void Encode_ID3D12Tools_EnableShaderInstrumentation(
    ID3D12Tools_Wrapper* wrapper,
    BOOL bEnable);

void Encode_ID3D12Tools_ShaderInstrumentationEnabled(
    ID3D12Tools_Wrapper* wrapper,
    BOOL return_value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_DATA& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MEMCPY_DEST& value);

void Encode_ID3D12SDKConfiguration_SetSDKVersion(
    ID3D12SDKConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    UINT SDKVersion,
    LPCSTR SDKPath);

void Encode_ID3D12SDKConfiguration1_CreateDeviceFactory(
    ID3D12SDKConfiguration1_Wrapper* wrapper,
    HRESULT return_value,
    UINT SDKVersion,
    LPCSTR SDKPath,
    REFIID riid,
    void** ppvFactory);

void Encode_ID3D12SDKConfiguration1_FreeUnusedSDKs(
    ID3D12SDKConfiguration1_Wrapper* wrapper);

void Encode_ID3D12DeviceFactory_InitializeFromGlobalState(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12DeviceFactory_ApplyToGlobalState(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12DeviceFactory_SetFlags(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEVICE_FACTORY_FLAGS flags);

void Encode_ID3D12DeviceFactory_GetFlags(
    ID3D12DeviceFactory_Wrapper* wrapper,
    D3D12_DEVICE_FACTORY_FLAGS return_value);

void Encode_ID3D12DeviceFactory_GetConfigurationInterface(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    REFCLSID clsid,
    REFIID iid,
    void** ppv);

void Encode_ID3D12DeviceFactory_EnableExperimentalFeatures(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes);

void Encode_ID3D12DeviceFactory_CreateDevice(
    ID3D12DeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    IUnknown* adapter,
    D3D_FEATURE_LEVEL FeatureLevel,
    REFIID riid,
    void** ppvDevice);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_CONFIGURATION_DESC& value);

void Encode_ID3D12DeviceConfiguration_GetDesc(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    D3D12_DEVICE_CONFIGURATION_DESC return_value);

void Encode_ID3D12DeviceConfiguration_GetEnabledExperimentalFeatures(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    GUID* pGuids,
    UINT NumGuids);

void Encode_ID3D12DeviceConfiguration_SerializeVersionedRootSignature(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pDesc,
    ID3DBlob** ppResult,
    ID3DBlob** ppError);

void Encode_ID3D12DeviceConfiguration_CreateVersionedRootSignatureDeserializer(
    ID3D12DeviceConfiguration_Wrapper* wrapper,
    HRESULT return_value,
    const void* pBlob,
    SIZE_T Size,
    REFIID riid,
    void** ppvDeserializer);

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRate(
    ID3D12GraphicsCommandList5_Wrapper* wrapper,
    D3D12_SHADING_RATE baseShadingRate,
    const D3D12_SHADING_RATE_COMBINER* combiners);

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
    ID3D12GraphicsCommandList5_Wrapper* wrapper,
    ID3D12Resource* shadingRateImage);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_MESH_ARGUMENTS& value);

void Encode_ID3D12GraphicsCommandList6_DispatchMesh(
    ID3D12GraphicsCommandList6_Wrapper* wrapper,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ);

void Encode_ID3D12GraphicsCommandList7_Barrier(
    ID3D12GraphicsCommandList7_Wrapper* wrapper,
    UINT32 NumBarrierGroups,
    const D3D12_BARRIER_GROUP* pBarrierGroups);

void Encode_ID3D12GraphicsCommandList8_OMSetFrontAndBackStencilRef(
    ID3D12GraphicsCommandList8_Wrapper* wrapper,
    UINT FrontStencilRef,
    UINT BackStencilRef);

void Encode_ID3D12GraphicsCommandList9_RSSetDepthBias(
    ID3D12GraphicsCommandList9_Wrapper* wrapper,
    FLOAT DepthBias,
    FLOAT DepthBiasClamp,
    FLOAT SlopeScaledDepthBias);

void Encode_ID3D12GraphicsCommandList9_IASetIndexBufferStripCutValue(
    ID3D12GraphicsCommandList9_Wrapper* wrapper,
    D3D12_INDEX_BUFFER_STRIP_CUT_VALUE IBStripCutValue);

void Encode_ID3D12DSRDeviceFactory_CreateDSRDevice(
    ID3D12DSRDeviceFactory_Wrapper* wrapper,
    HRESULT return_value,
    ID3D12Device* pD3D12Device,
    UINT NodeMask,
    REFIID riid,
    void** ppvDSRDevice);


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const D3D_SHADER_MACRO& value);

void Encode_ID3D10Blob_GetBufferPointer(
    ID3D10Blob_Wrapper* wrapper,
    LPVOID return_value);

void Encode_ID3D10Blob_GetBufferSize(
    ID3D10Blob_Wrapper* wrapper,
    SIZE_T return_value);

void Encode_ID3DDestructionNotifier_RegisterDestructionCallback(
    ID3DDestructionNotifier_Wrapper* wrapper,
    HRESULT return_value,
    PFN_DESTRUCTION_CALLBACK callbackFn,
    void* pData,
    UINT* pCallbackID);

void Encode_ID3DDestructionNotifier_UnregisterDestructionCallback(
    ID3DDestructionNotifier_Wrapper* wrapper,
    HRESULT return_value,
    UINT callbackID);


/*
** This part is generated from d3d12sdklayers.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_ID3D12Debug_EnableDebugLayer(
    ID3D12Debug_Wrapper* wrapper);

void Encode_ID3D12Debug1_EnableDebugLayer(
    ID3D12Debug1_Wrapper* wrapper);

void Encode_ID3D12Debug1_SetEnableGPUBasedValidation(
    ID3D12Debug1_Wrapper* wrapper,
    BOOL Enable);

void Encode_ID3D12Debug1_SetEnableSynchronizedCommandQueueValidation(
    ID3D12Debug1_Wrapper* wrapper,
    BOOL Enable);

void Encode_ID3D12Debug2_SetGPUBasedValidationFlags(
    ID3D12Debug2_Wrapper* wrapper,
    D3D12_GPU_BASED_VALIDATION_FLAGS Flags);

void Encode_ID3D12Debug3_SetEnableGPUBasedValidation(
    ID3D12Debug3_Wrapper* wrapper,
    BOOL Enable);

void Encode_ID3D12Debug3_SetEnableSynchronizedCommandQueueValidation(
    ID3D12Debug3_Wrapper* wrapper,
    BOOL Enable);

void Encode_ID3D12Debug3_SetGPUBasedValidationFlags(
    ID3D12Debug3_Wrapper* wrapper,
    D3D12_GPU_BASED_VALIDATION_FLAGS Flags);

void Encode_ID3D12Debug4_DisableDebugLayer(
    ID3D12Debug4_Wrapper* wrapper);

void Encode_ID3D12Debug5_SetEnableAutoName(
    ID3D12Debug5_Wrapper* wrapper,
    BOOL Enable);

void Encode_ID3D12Debug6_SetForceLegacyBarrierValidation(
    ID3D12Debug6_Wrapper* wrapper,
    BOOL Enable);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEBUG_DEVICE_GPU_BASED_VALIDATION_SETTINGS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR& value);

void Encode_ID3D12DebugDevice1_SetDebugParameter(
    ID3D12DebugDevice1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize);

void Encode_ID3D12DebugDevice1_GetDebugParameter(
    ID3D12DebugDevice1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize);

void Encode_ID3D12DebugDevice1_ReportLiveDeviceObjects(
    ID3D12DebugDevice1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_RLDO_FLAGS Flags);

void Encode_ID3D12DebugDevice_SetFeatureMask(
    ID3D12DebugDevice_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_FEATURE Mask);

void Encode_ID3D12DebugDevice_GetFeatureMask(
    ID3D12DebugDevice_Wrapper* wrapper,
    D3D12_DEBUG_FEATURE return_value);

void Encode_ID3D12DebugDevice_ReportLiveDeviceObjects(
    ID3D12DebugDevice_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_RLDO_FLAGS Flags);

void Encode_ID3D12DebugDevice2_SetDebugParameter(
    ID3D12DebugDevice2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize);

void Encode_ID3D12DebugDevice2_GetDebugParameter(
    ID3D12DebugDevice2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_DEVICE_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize);

void Encode_ID3D12DebugCommandQueue_AssertResourceState(
    ID3D12DebugCommandQueue_Wrapper* wrapper,
    BOOL return_value,
    ID3D12Resource* pResource,
    UINT Subresource,
    UINT State);

void Encode_ID3D12DebugCommandQueue1_AssertResourceAccess(
    ID3D12DebugCommandQueue1_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_ACCESS Access);

void Encode_ID3D12DebugCommandQueue1_AssertTextureLayout(
    ID3D12DebugCommandQueue1_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_LAYOUT Layout);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEBUG_COMMAND_LIST_GPU_BASED_VALIDATION_SETTINGS& value);

void Encode_ID3D12DebugCommandList1_AssertResourceState(
    ID3D12DebugCommandList1_Wrapper* wrapper,
    BOOL return_value,
    ID3D12Resource* pResource,
    UINT Subresource,
    UINT State);

void Encode_ID3D12DebugCommandList1_SetDebugParameter(
    ID3D12DebugCommandList1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize);

void Encode_ID3D12DebugCommandList1_GetDebugParameter(
    ID3D12DebugCommandList1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize);

void Encode_ID3D12DebugCommandList_AssertResourceState(
    ID3D12DebugCommandList_Wrapper* wrapper,
    BOOL return_value,
    ID3D12Resource* pResource,
    UINT Subresource,
    UINT State);

void Encode_ID3D12DebugCommandList_SetFeatureMask(
    ID3D12DebugCommandList_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_FEATURE Mask);

void Encode_ID3D12DebugCommandList_GetFeatureMask(
    ID3D12DebugCommandList_Wrapper* wrapper,
    D3D12_DEBUG_FEATURE return_value);

void Encode_ID3D12DebugCommandList2_SetDebugParameter(
    ID3D12DebugCommandList2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    const void* pData,
    UINT DataSize);

void Encode_ID3D12DebugCommandList2_GetDebugParameter(
    ID3D12DebugCommandList2_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_DEBUG_COMMAND_LIST_PARAMETER_TYPE Type,
    void* pData,
    UINT DataSize);

void Encode_ID3D12DebugCommandList3_AssertResourceAccess(
    ID3D12DebugCommandList3_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_ACCESS Access);

void Encode_ID3D12DebugCommandList3_AssertTextureLayout(
    ID3D12DebugCommandList3_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    D3D12_BARRIER_LAYOUT Layout);

void Encode_ID3D12SharingContract_Present(
    ID3D12SharingContract_Wrapper* wrapper,
    ID3D12Resource* pResource,
    UINT Subresource,
    HWND window);

void Encode_ID3D12SharingContract_SharedFenceSignal(
    ID3D12SharingContract_Wrapper* wrapper,
    ID3D12Fence* pFence,
    UINT64 FenceValue);

void Encode_ID3D12SharingContract_BeginCapturableWork(
    ID3D12SharingContract_Wrapper* wrapper,
    REFGUID guid);

void Encode_ID3D12SharingContract_EndCapturableWork(
    ID3D12SharingContract_Wrapper* wrapper,
    REFGUID guid);

void Encode_ID3D12ManualWriteTrackingResource_TrackWrite(
    ID3D12ManualWriteTrackingResource_Wrapper* wrapper,
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MESSAGE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INFO_QUEUE_FILTER_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INFO_QUEUE_FILTER& value);

void Encode_ID3D12InfoQueue_SetMessageCountLimit(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 MessageCountLimit);

void Encode_ID3D12InfoQueue_ClearStoredMessages(
    ID3D12InfoQueue_Wrapper* wrapper);

void Encode_ID3D12InfoQueue_GetMessage(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    UINT64 MessageIndex,
    D3D12_MESSAGE* pMessage,
    SIZE_T* pMessageByteLength);

void Encode_ID3D12InfoQueue_GetNumMessagesAllowedByStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12InfoQueue_GetNumMessagesDeniedByStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12InfoQueue_GetNumStoredMessages(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12InfoQueue_GetNumStoredMessagesAllowedByRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12InfoQueue_GetNumMessagesDiscardedByMessageCountLimit(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12InfoQueue_GetMessageCountLimit(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT64 return_value);

void Encode_ID3D12InfoQueue_AddStorageFilterEntries(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter);

void Encode_ID3D12InfoQueue_GetStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter,
    SIZE_T* pFilterByteLength);

void Encode_ID3D12InfoQueue_ClearStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper);

void Encode_ID3D12InfoQueue_PushEmptyStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12InfoQueue_PushCopyOfStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12InfoQueue_PushStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter);

void Encode_ID3D12InfoQueue_PopStorageFilter(
    ID3D12InfoQueue_Wrapper* wrapper);

void Encode_ID3D12InfoQueue_GetStorageFilterStackSize(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT return_value);

void Encode_ID3D12InfoQueue_AddRetrievalFilterEntries(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter);

void Encode_ID3D12InfoQueue_GetRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter,
    SIZE_T* pFilterByteLength);

void Encode_ID3D12InfoQueue_ClearRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper);

void Encode_ID3D12InfoQueue_PushEmptyRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12InfoQueue_PushCopyOfRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value);

void Encode_ID3D12InfoQueue_PushRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_INFO_QUEUE_FILTER* pFilter);

void Encode_ID3D12InfoQueue_PopRetrievalFilter(
    ID3D12InfoQueue_Wrapper* wrapper);

void Encode_ID3D12InfoQueue_GetRetrievalFilterStackSize(
    ID3D12InfoQueue_Wrapper* wrapper,
    UINT return_value);

void Encode_ID3D12InfoQueue_AddMessage(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_CATEGORY Category,
    D3D12_MESSAGE_SEVERITY Severity,
    D3D12_MESSAGE_ID ID,
    LPCSTR pDescription);

void Encode_ID3D12InfoQueue_AddApplicationMessage(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_SEVERITY Severity,
    LPCSTR pDescription);

void Encode_ID3D12InfoQueue_SetBreakOnCategory(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_CATEGORY Category,
    BOOL bEnable);

void Encode_ID3D12InfoQueue_SetBreakOnSeverity(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_SEVERITY Severity,
    BOOL bEnable);

void Encode_ID3D12InfoQueue_SetBreakOnID(
    ID3D12InfoQueue_Wrapper* wrapper,
    HRESULT return_value,
    D3D12_MESSAGE_ID ID,
    BOOL bEnable);

void Encode_ID3D12InfoQueue_GetBreakOnCategory(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value,
    D3D12_MESSAGE_CATEGORY Category);

void Encode_ID3D12InfoQueue_GetBreakOnSeverity(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value,
    D3D12_MESSAGE_SEVERITY Severity);

void Encode_ID3D12InfoQueue_GetBreakOnID(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value,
    D3D12_MESSAGE_ID ID);

void Encode_ID3D12InfoQueue_SetMuteDebugOutput(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL bMute);

void Encode_ID3D12InfoQueue_GetMuteDebugOutput(
    ID3D12InfoQueue_Wrapper* wrapper,
    BOOL return_value);

void Encode_ID3D12InfoQueue1_RegisterMessageCallback(
    ID3D12InfoQueue1_Wrapper* wrapper,
    HRESULT return_value,
    D3D12MessageFunc CallbackFunc,
    D3D12_MESSAGE_CALLBACK_FLAGS CallbackFilterFlags,
    void* pContext,
    DWORD* pCallbackCookie);

void Encode_ID3D12InfoQueue1_UnregisterMessageCallback(
    ID3D12InfoQueue1_Wrapper* wrapper,
    HRESULT return_value,
    DWORD CallbackCookie);


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.20348.0
**
*/

void Encode_IUnknown_QueryInterface(
    IUnknown_Wrapper* wrapper,
    HRESULT return_value,
    REFIID riid,
    void** ppvObject);

void Encode_IUnknown_AddRef(
    IUnknown_Wrapper* wrapper,
    ULONG return_value);

void Encode_IUnknown_Release(
    IUnknown_Wrapper* wrapper,
    ULONG return_value);


/*
** This part is generated from guiddef.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const GUID& value);


/*
** This part is generated from windef.h in Windows SDK: 10.0.20348.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const tagRECT& value);

void EncodeStruct(ParameterEncoder* encoder, const tagPOINT& value);


/*
** This part is generated from minwinbase.h in Windows SDK: 10.0.20348.0
**
*/


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
