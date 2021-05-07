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
#include <Unknwnbase.h>
#include <guiddef.h>
#include <windef.h>
#include <minwinbase.h>

#include "encode/parameter_encoder.h"
#include "util/defines.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)


/*
** This part is generated from dxgi.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_CreateDXGIFactory(
    HRESULT result,
    REFIID riid,
    void** ppFactory);

void Encode_CreateDXGIFactory1(
    HRESULT result,
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
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID Name,
    UINT DataSize,
    const void* pData);

void Encode_IDXGIObject_SetPrivateDataInterface(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID Name,
    const IUnknown* pUnknown);

void Encode_IDXGIObject_GetPrivateData(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID Name,
    UINT* pDataSize,
    void* pData);

void Encode_IDXGIObject_GetParent(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppParent);

void Encode_IDXGIDeviceSubObject_GetDevice(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppDevice);

void Encode_IDXGIResource_GetSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE* pSharedHandle);

void Encode_IDXGIResource_GetUsage(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_USAGE* pUsage);

void Encode_IDXGIResource_SetEvictionPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT EvictionPriority);

void Encode_IDXGIResource_GetEvictionPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pEvictionPriority);

void Encode_IDXGIKeyedMutex_AcquireSync(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Key,
    DWORD dwMilliseconds);

void Encode_IDXGIKeyedMutex_ReleaseSync(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Key);

void Encode_IDXGISurface_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SURFACE_DESC* pDesc);

void Encode_IDXGISurface_Map(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MAPPED_RECT* pLockedRect,
    UINT MapFlags);

void Encode_IDXGISurface_Unmap(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_IDXGISurface1_GetDC(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL Discard,
    HDC* phdc);

void Encode_IDXGISurface1_ReleaseDC(
    format::HandleId wrapper_id,
    HRESULT result,
    RECT* pDirtyRect);

void Encode_IDXGIAdapter_EnumOutputs(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Output,
    IDXGIOutput** ppOutput);

void Encode_IDXGIAdapter_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC* pDesc);

void Encode_IDXGIAdapter_CheckInterfaceSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID InterfaceName,
    LARGE_INTEGER* pUMDVersion);

void Encode_IDXGIOutput_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_OUTPUT_DESC* pDesc);

void Encode_IDXGIOutput_GetDisplayModeList(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC* pDesc);

void Encode_IDXGIOutput_FindClosestMatchingMode(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MODE_DESC* pModeToMatch,
    DXGI_MODE_DESC* pClosestMatch,
    IUnknown* pConcernedDevice);

void Encode_IDXGIOutput_WaitForVBlank(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_IDXGIOutput_TakeOwnership(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    BOOL Exclusive);

void Encode_IDXGIOutput_ReleaseOwnership(
    format::HandleId wrapper_id);

void Encode_IDXGIOutput_GetGammaControlCapabilities(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps);

void Encode_IDXGIOutput_SetGammaControl(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_GAMMA_CONTROL* pArray);

void Encode_IDXGIOutput_GetGammaControl(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_GAMMA_CONTROL* pArray);

void Encode_IDXGIOutput_SetDisplaySurface(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGISurface* pScanoutSurface);

void Encode_IDXGIOutput_GetDisplaySurfaceData(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGISurface* pDestination);

void Encode_IDXGIOutput_GetFrameStatistics(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FRAME_STATISTICS* pStats);

void Encode_IDXGISwapChain_Present(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT SyncInterval,
    UINT Flags);

void Encode_IDXGISwapChain_GetBuffer(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Buffer,
    REFIID riid,
    void** ppSurface);

void Encode_IDXGISwapChain_SetFullscreenState(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL Fullscreen,
    IDXGIOutput* pTarget);

void Encode_IDXGISwapChain_GetFullscreenState(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL* pFullscreen,
    IDXGIOutput** ppTarget);

void Encode_IDXGISwapChain_GetDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SWAP_CHAIN_DESC* pDesc);

void Encode_IDXGISwapChain_ResizeBuffers(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT NewFormat,
    UINT SwapChainFlags);

void Encode_IDXGISwapChain_ResizeTarget(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MODE_DESC* pNewTargetParameters);

void Encode_IDXGISwapChain_GetContainingOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIOutput** ppOutput);

void Encode_IDXGISwapChain_GetFrameStatistics(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FRAME_STATISTICS* pStats);

void Encode_IDXGISwapChain_GetLastPresentCount(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pLastPresentCount);

void Encode_IDXGIFactory_EnumAdapters(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Adapter,
    IDXGIAdapter** ppAdapter);

void Encode_IDXGIFactory_MakeWindowAssociation(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND WindowHandle,
    UINT Flags);

void Encode_IDXGIFactory_GetWindowAssociation(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND* pWindowHandle);

void Encode_IDXGIFactory_CreateSwapChain(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain);

void Encode_IDXGIFactory_CreateSoftwareAdapter(
    format::HandleId wrapper_id,
    HRESULT result,
    HMODULE Module,
    IDXGIAdapter** ppAdapter);

void Encode_IDXGIDevice_GetAdapter(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIAdapter** pAdapter);

void Encode_IDXGIDevice_CreateSurface(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_SURFACE_DESC* pDesc,
    UINT NumSurfaces,
    DXGI_USAGE Usage,
    const DXGI_SHARED_RESOURCE* pSharedResource,
    IDXGISurface** ppSurface);

void Encode_IDXGIDevice_QueryResourceResidency(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* const* ppResources,
    DXGI_RESIDENCY* pResidencyStatus,
    UINT NumResources);

void Encode_IDXGIDevice_SetGPUThreadPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    INT Priority);

void Encode_IDXGIDevice_GetGPUThreadPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    INT* pPriority);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_DISPLAY_COLOR_SPACE& value);

void Encode_IDXGIFactory1_EnumAdapters1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Adapter,
    IDXGIAdapter1** ppAdapter);

void Encode_IDXGIFactory1_IsCurrent(
    format::HandleId wrapper_id,
    BOOL result);

void Encode_IDXGIAdapter1_GetDesc1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC1* pDesc);

void Encode_IDXGIDevice1_SetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT MaxLatency);

void Encode_IDXGIDevice1_GetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pMaxLatency);


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_IDXGIDisplayControl_IsStereoEnabled(
    format::HandleId wrapper_id,
    BOOL result);

void Encode_IDXGIDisplayControl_SetStereoEnabled(
    format::HandleId wrapper_id,
    BOOL enabled);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_MOVE_RECT& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_POINTER_POSITION& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_POINTER_SHAPE_INFO& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTDUPL_FRAME_INFO& value);

void Encode_IDXGIOutputDuplication_GetDesc(
    format::HandleId wrapper_id,
    DXGI_OUTDUPL_DESC* pDesc);

void Encode_IDXGIOutputDuplication_AcquireNextFrame(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT TimeoutInMilliseconds,
    DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
    IDXGIResource** ppDesktopResource);

void Encode_IDXGIOutputDuplication_GetFrameDirtyRects(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT DirtyRectsBufferSize,
    RECT* pDirtyRectsBuffer,
    UINT* pDirtyRectsBufferSizeRequired);

void Encode_IDXGIOutputDuplication_GetFrameMoveRects(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT MoveRectsBufferSize,
    DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
    UINT* pMoveRectsBufferSizeRequired);

void Encode_IDXGIOutputDuplication_GetFramePointerShape(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT PointerShapeBufferSize,
    void* pPointerShapeBuffer,
    UINT* pPointerShapeBufferSizeRequired,
    DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo);

void Encode_IDXGIOutputDuplication_MapDesktopSurface(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MAPPED_RECT* pLockedRect);

void Encode_IDXGIOutputDuplication_UnMapDesktopSurface(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_IDXGIOutputDuplication_ReleaseFrame(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_IDXGISurface2_GetResource(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppParentResource,
    UINT* pSubresourceIndex);

void Encode_IDXGIResource1_CreateSubresourceSurface(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT index,
    IDXGISurface2** ppSurface);

void Encode_IDXGIResource1_CreateSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD dwAccess,
    LPCWSTR lpName,
    HANDLE* pHandle);

void Encode_IDXGIDevice2_OfferResources(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority);

void Encode_IDXGIDevice2_ReclaimResources(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    BOOL* pDiscarded);

void Encode_IDXGIDevice2_EnqueueSetEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MODE_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SWAP_CHAIN_FULLSCREEN_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_PRESENT_PARAMETERS& value);

void Encode_IDXGISwapChain1_GetDesc1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SWAP_CHAIN_DESC1* pDesc);

void Encode_IDXGISwapChain1_GetFullscreenDesc(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc);

void Encode_IDXGISwapChain1_GetHwnd(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND* pHwnd);

void Encode_IDXGISwapChain1_GetCoreWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID refiid,
    void** ppUnk);

void Encode_IDXGISwapChain1_Present1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT SyncInterval,
    UINT PresentFlags,
    const DXGI_PRESENT_PARAMETERS* pPresentParameters);

void Encode_IDXGISwapChain1_IsTemporaryMonoSupported(
    format::HandleId wrapper_id,
    BOOL result);

void Encode_IDXGISwapChain1_GetRestrictToOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIOutput** ppRestrictToOutput);

void Encode_IDXGISwapChain1_SetBackgroundColor(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_RGBA* pColor);

void Encode_IDXGISwapChain1_GetBackgroundColor(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_RGBA* pColor);

void Encode_IDXGISwapChain1_SetRotation(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MODE_ROTATION Rotation);

void Encode_IDXGISwapChain1_GetRotation(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MODE_ROTATION* pRotation);

void Encode_IDXGIFactory2_IsWindowedStereoEnabled(
    format::HandleId wrapper_id,
    BOOL result);

void Encode_IDXGIFactory2_CreateSwapChainForHwnd(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    HWND hWnd,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void Encode_IDXGIFactory2_CreateSwapChainForCoreWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    IUnknown* pWindow,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void Encode_IDXGIFactory2_GetSharedResourceAdapterLuid(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hResource,
    LUID* pLuid);

void Encode_IDXGIFactory2_RegisterStereoStatusWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_RegisterStereoStatusEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_UnregisterStereoStatus(
    format::HandleId wrapper_id,
    DWORD dwCookie);

void Encode_IDXGIFactory2_RegisterOcclusionStatusWindow(
    format::HandleId wrapper_id,
    HRESULT result,
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_RegisterOcclusionStatusEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIFactory2_UnregisterOcclusionStatus(
    format::HandleId wrapper_id,
    DWORD dwCookie);

void Encode_IDXGIFactory2_CreateSwapChainForComposition(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC2& value);

void Encode_IDXGIAdapter2_GetDesc2(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC2* pDesc);

void Encode_IDXGIOutput1_GetDisplayModeList1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC1* pDesc);

void Encode_IDXGIOutput1_FindClosestMatchingMode1(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MODE_DESC1* pModeToMatch,
    DXGI_MODE_DESC1* pClosestMatch,
    IUnknown* pConcernedDevice);

void Encode_IDXGIOutput1_GetDisplaySurfaceData1(
    format::HandleId wrapper_id,
    HRESULT result,
    IDXGIResource* pDestination);

void Encode_IDXGIOutput1_DuplicateOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    IDXGIOutputDuplication** ppOutputDuplication);


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_CreateDXGIFactory2(
    HRESULT result,
    UINT Flags,
    REFIID riid,
    void** ppFactory);

void Encode_DXGIGetDebugInterface1(
    HRESULT result,
    UINT Flags,
    REFIID riid,
    void** pDebug);

void Encode_IDXGIDevice3_Trim(
    format::HandleId wrapper_id);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_MATRIX_3X2_F& value);

void Encode_IDXGISwapChain2_SetSourceSize(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Width,
    UINT Height);

void Encode_IDXGISwapChain2_GetSourceSize(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pWidth,
    UINT* pHeight);

void Encode_IDXGISwapChain2_SetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT MaxLatency);

void Encode_IDXGISwapChain2_GetMaximumFrameLatency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pMaxLatency);

void Encode_IDXGISwapChain2_GetFrameLatencyWaitableObject(
    format::HandleId wrapper_id,
    HANDLE result);

void Encode_IDXGISwapChain2_SetMatrixTransform(
    format::HandleId wrapper_id,
    HRESULT result,
    const DXGI_MATRIX_3X2_F* pMatrix);

void Encode_IDXGISwapChain2_GetMatrixTransform(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MATRIX_3X2_F* pMatrix);

void Encode_IDXGIOutput2_SupportsOverlays(
    format::HandleId wrapper_id,
    BOOL result);

void Encode_IDXGIFactory3_GetCreationFlags(
    format::HandleId wrapper_id,
    UINT result);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_DECODE_SWAP_CHAIN_DESC& value);

void Encode_IDXGIDecodeSwapChain_PresentBuffer(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT BufferToPresent,
    UINT SyncInterval,
    UINT Flags);

void Encode_IDXGIDecodeSwapChain_SetSourceRect(
    format::HandleId wrapper_id,
    HRESULT result,
    const RECT* pRect);

void Encode_IDXGIDecodeSwapChain_SetTargetRect(
    format::HandleId wrapper_id,
    HRESULT result,
    const RECT* pRect);

void Encode_IDXGIDecodeSwapChain_SetDestSize(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Width,
    UINT Height);

void Encode_IDXGIDecodeSwapChain_GetSourceRect(
    format::HandleId wrapper_id,
    HRESULT result,
    RECT* pRect);

void Encode_IDXGIDecodeSwapChain_GetTargetRect(
    format::HandleId wrapper_id,
    HRESULT result,
    RECT* pRect);

void Encode_IDXGIDecodeSwapChain_GetDestSize(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pWidth,
    UINT* pHeight);

void Encode_IDXGIDecodeSwapChain_SetColorSpace(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace);

void Encode_IDXGIDecodeSwapChain_GetColorSpace(
    format::HandleId wrapper_id,
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS result);

void Encode_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    HANDLE hSurface,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain);

void Encode_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    IUnknown* pDevice,
    HANDLE hSurface,
    DXGI_DECODE_SWAP_CHAIN_DESC* pDesc,
    IDXGIResource* pYuvDecodeBuffers,
    IDXGIOutput* pRestrictToOutput,
    IDXGIDecodeSwapChain** ppSwapChain);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_FRAME_STATISTICS_MEDIA& value);

void Encode_IDXGISwapChainMedia_GetFrameStatisticsMedia(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FRAME_STATISTICS_MEDIA* pStats);

void Encode_IDXGISwapChainMedia_SetPresentDuration(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Duration);

void Encode_IDXGISwapChainMedia_CheckPresentDurationSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT DesiredPresentDuration,
    UINT* pClosestSmallerPresentDuration,
    UINT* pClosestLargerPresentDuration);

void Encode_IDXGIOutput3_CheckOverlaySupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT EnumFormat,
    IUnknown* pConcernedDevice,
    UINT* pFlags);


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_IDXGISwapChain3_GetCurrentBackBufferIndex(
    format::HandleId wrapper_id,
    UINT result);

void Encode_IDXGISwapChain3_CheckColorSpaceSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    UINT* pColorSpaceSupport);

void Encode_IDXGISwapChain3_SetColorSpace1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_COLOR_SPACE_TYPE ColorSpace);

void Encode_IDXGISwapChain3_ResizeBuffers1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT Format,
    UINT SwapChainFlags,
    const UINT* pCreationNodeMask,
    IUnknown* const* ppPresentQueue);

void Encode_IDXGIOutput4_CheckOverlayColorSpaceSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FORMAT Format,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    IUnknown* pConcernedDevice,
    UINT* pFlags);

void Encode_IDXGIFactory4_EnumAdapterByLuid(
    format::HandleId wrapper_id,
    HRESULT result,
    LUID AdapterLuid,
    REFIID riid,
    void** ppvAdapter);

void Encode_IDXGIFactory4_EnumWarpAdapter(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppvAdapter);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_QUERY_VIDEO_MEMORY_INFO& value);

void Encode_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
    format::HandleId wrapper_id,
    DWORD dwCookie);

void Encode_IDXGIAdapter3_QueryVideoMemoryInfo(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo);

void Encode_IDXGIAdapter3_SetVideoMemoryReservation(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    UINT64 Reservation);

void Encode_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
    format::HandleId wrapper_id,
    DWORD dwCookie);


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
    IDXGIOutputDuplication** ppOutputDuplication);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_HDR_METADATA_HDR10& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_HDR_METADATA_HDR10PLUS& value);

void Encode_IDXGISwapChain4_SetHDRMetaData(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_HDR_METADATA_TYPE Type,
    UINT Size,
    void* pMetaData);

void Encode_IDXGIDevice4_OfferResources1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority,
    UINT Flags);

void Encode_IDXGIDevice4_ReclaimResources1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_RECLAIM_RESOURCE_RESULTS* pResults);

void Encode_IDXGIFactory5_CheckFeatureSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_FEATURE Feature,
    void* pFeatureSupportData,
    UINT FeatureSupportDataSize);


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_DXGIDeclareAdapterRemovalSupport(
    HRESULT result);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_ADAPTER_DESC3& value);

void Encode_IDXGIAdapter4_GetDesc3(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_ADAPTER_DESC3* pDesc);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_OUTPUT_DESC1& value);

void Encode_IDXGIOutput6_GetDesc1(
    format::HandleId wrapper_id,
    HRESULT result,
    DXGI_OUTPUT_DESC1* pDesc);

void Encode_IDXGIOutput6_CheckHardwareCompositionSupport(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pFlags);

void Encode_IDXGIFactory6_EnumAdapterByGpuPreference(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Adapter,
    DXGI_GPU_PREFERENCE GpuPreference,
    REFIID riid,
    void** ppvAdapter);

void Encode_IDXGIFactory7_RegisterAdaptersChangedEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hEvent,
    DWORD* pdwCookie);

void Encode_IDXGIFactory7_UnregisterAdaptersChangedEvent(
    format::HandleId wrapper_id,
    HRESULT result,
    DWORD dwCookie);


/*
** This part is generated from dxgicommon.h in Windows SDK: 10.0.19041.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const DXGI_RATIONAL& value);

void EncodeStruct(ParameterEncoder* encoder, const DXGI_SAMPLE_DESC& value);


/*
** This part is generated from dxgiformat.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from dxgitype.h in Windows SDK: 10.0.19041.0
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
** This part is generated from d3d12.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_D3D12SerializeRootSignature(
    HRESULT result,
    const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION Version,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob);

void Encode_D3D12CreateRootSignatureDeserializer(
    HRESULT result,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

void Encode_D3D12SerializeVersionedRootSignature(
    HRESULT result,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob);

void Encode_D3D12CreateVersionedRootSignatureDeserializer(
    HRESULT result,
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

void Encode_D3D12CreateDevice(
    HRESULT result,
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice);

void Encode_D3D12GetDebugInterface(
    HRESULT result,
    REFIID riid,
    void** ppvDebug);

void Encode_D3D12EnableExperimentalFeatures(
    HRESULT result,
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_QUEUE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INPUT_ELEMENT_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SO_DECLARATION_ENTRY& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VIEWPORT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BOX& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCILOP_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEPTH_STENCIL_DESC1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_TARGET_BLEND_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_BLEND_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RASTERIZER_DESC& value);

void Encode_ID3D12Object_GetPrivateData(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID guid,
    UINT* pDataSize,
    void* pData);

void Encode_ID3D12Object_SetPrivateData(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID guid,
    UINT DataSize,
    const void* pData);

void Encode_ID3D12Object_SetPrivateDataInterface(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID guid,
    const IUnknown* pData);

void Encode_ID3D12Object_SetName(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR Name);

void Encode_ID3D12DeviceChild_GetDevice(
    format::HandleId wrapper_id,
    HRESULT result,
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS4& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_SERIALIZATION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_CROSS_NODE& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS5& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS6& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_D3D12_OPTIONS7& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_QUERY_META_COMMAND& value);

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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DESCRIPTOR_RANGE1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR_TABLE1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_DESCRIPTOR1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_ROOT_SIGNATURE_DESC1& value);

void Encode_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
    format::HandleId wrapper_id,
    const D3D12_ROOT_SIGNATURE_DESC * result);

void Encode_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D_ROOT_SIGNATURE_VERSION convertToVersion,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc);

void Encode_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
    format::HandleId wrapper_id,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC * result);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISCARD_REGION& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_HEAP_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_PIPELINE_STATISTICS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_QUERY_DATA_SO_STATISTICS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_STREAM_OUTPUT_BUFFER_VIEW& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRAW_ARGUMENTS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DRAW_INDEXED_ARGUMENTS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_ARGUMENTS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_VERTEX_BUFFER_VIEW& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_INDEX_BUFFER_VIEW& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_COMMAND_SIGNATURE_DESC& value);

void Encode_ID3D12Heap_GetDesc(
    format::HandleId wrapper_id,
    D3D12_HEAP_DESC result);

void Encode_ID3D12Resource_Map(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT Subresource,
    const D3D12_RANGE* pReadRange,
    void** ppData);

void Encode_ID3D12Resource_Unmap(
    format::HandleId wrapper_id,
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange);

void Encode_ID3D12Resource_GetDesc(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_DESC result);

void Encode_ID3D12Resource_GetGPUVirtualAddress(
    format::HandleId wrapper_id,
    D3D12_GPU_VIRTUAL_ADDRESS result);

void Encode_ID3D12Resource_WriteToSubresource(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT DstSubresource,
    const D3D12_BOX* pDstBox,
    const void* pSrcData,
    UINT SrcRowPitch,
    UINT SrcDepthPitch);

void Encode_ID3D12Resource_ReadFromSubresource(
    format::HandleId wrapper_id,
    HRESULT result,
    void* pDstData,
    UINT DstRowPitch,
    UINT DstDepthPitch,
    UINT SrcSubresource,
    const D3D12_BOX* pSrcBox);

void Encode_ID3D12Resource_GetHeapProperties(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS* pHeapFlags);

void Encode_ID3D12CommandAllocator_Reset(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_ID3D12Fence_GetCompletedValue(
    format::HandleId wrapper_id,
    UINT64 result);

void Encode_ID3D12Fence_SetEventOnCompletion(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Value,
    HANDLE hEvent);

void Encode_ID3D12Fence_Signal(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 Value);

void Encode_ID3D12Fence1_GetCreationFlags(
    format::HandleId wrapper_id,
    D3D12_FENCE_FLAGS result);

void Encode_ID3D12PipelineState_GetCachedBlob(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3DBlob** ppBlob);

void Encode_ID3D12DescriptorHeap_GetDesc(
    format::HandleId wrapper_id,
    D3D12_DESCRIPTOR_HEAP_DESC result);

void Encode_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
    format::HandleId wrapper_id,
    D3D12_CPU_DESCRIPTOR_HANDLE result);

void Encode_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
    format::HandleId wrapper_id,
    D3D12_GPU_DESCRIPTOR_HANDLE result);

void Encode_ID3D12CommandList_GetType(
    format::HandleId wrapper_id,
    D3D12_COMMAND_LIST_TYPE result);

void Encode_ID3D12GraphicsCommandList_Close(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_ID3D12GraphicsCommandList_Reset(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12CommandAllocator* pAllocator,
    ID3D12PipelineState* pInitialState);

void Encode_ID3D12GraphicsCommandList_ClearState(
    format::HandleId wrapper_id,
    ID3D12PipelineState* pPipelineState);

void Encode_ID3D12GraphicsCommandList_DrawInstanced(
    format::HandleId wrapper_id,
    UINT VertexCountPerInstance,
    UINT InstanceCount,
    UINT StartVertexLocation,
    UINT StartInstanceLocation);

void Encode_ID3D12GraphicsCommandList_DrawIndexedInstanced(
    format::HandleId wrapper_id,
    UINT IndexCountPerInstance,
    UINT InstanceCount,
    UINT StartIndexLocation,
    INT BaseVertexLocation,
    UINT StartInstanceLocation);

void Encode_ID3D12GraphicsCommandList_Dispatch(
    format::HandleId wrapper_id,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ);

void Encode_ID3D12GraphicsCommandList_CopyBufferRegion(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT64 NumBytes);

void Encode_ID3D12GraphicsCommandList_CopyTextureRegion(
    format::HandleId wrapper_id,
    const D3D12_TEXTURE_COPY_LOCATION* pDst,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    const D3D12_TEXTURE_COPY_LOCATION* pSrc,
    const D3D12_BOX* pSrcBox);

void Encode_ID3D12GraphicsCommandList_CopyResource(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstResource,
    ID3D12Resource* pSrcResource);

void Encode_ID3D12GraphicsCommandList_CopyTiles(
    format::HandleId wrapper_id,
    ID3D12Resource* pTiledResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pTileRegionSize,
    ID3D12Resource* pBuffer,
    UINT64 BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS Flags);

void Encode_ID3D12GraphicsCommandList_ResolveSubresource(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstResource,
    UINT DstSubresource,
    ID3D12Resource* pSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT Format);

void Encode_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
    format::HandleId wrapper_id,
    D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology);

void Encode_ID3D12GraphicsCommandList_RSSetViewports(
    format::HandleId wrapper_id,
    UINT NumViewports,
    const D3D12_VIEWPORT* pViewports);

void Encode_ID3D12GraphicsCommandList_RSSetScissorRects(
    format::HandleId wrapper_id,
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_OMSetBlendFactor(
    format::HandleId wrapper_id,
    const FLOAT BlendFactor [4]);

void Encode_ID3D12GraphicsCommandList_OMSetStencilRef(
    format::HandleId wrapper_id,
    UINT StencilRef);

void Encode_ID3D12GraphicsCommandList_SetPipelineState(
    format::HandleId wrapper_id,
    ID3D12PipelineState* pPipelineState);

void Encode_ID3D12GraphicsCommandList_ResourceBarrier(
    format::HandleId wrapper_id,
    UINT NumBarriers,
    const D3D12_RESOURCE_BARRIER* pBarriers);

void Encode_ID3D12GraphicsCommandList_ExecuteBundle(
    format::HandleId wrapper_id,
    ID3D12GraphicsCommandList* pCommandList);

void Encode_ID3D12GraphicsCommandList_SetDescriptorHeaps(
    format::HandleId wrapper_id,
    UINT NumDescriptorHeaps,
    ID3D12DescriptorHeap* const* ppDescriptorHeaps);

void Encode_ID3D12GraphicsCommandList_SetComputeRootSignature(
    format::HandleId wrapper_id,
    ID3D12RootSignature* pRootSignature);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
    format::HandleId wrapper_id,
    ID3D12RootSignature* pRootSignature);

void Encode_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues);

void Encode_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
    format::HandleId wrapper_id,
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

void Encode_ID3D12GraphicsCommandList_IASetIndexBuffer(
    format::HandleId wrapper_id,
    const D3D12_INDEX_BUFFER_VIEW* pView);

void Encode_ID3D12GraphicsCommandList_IASetVertexBuffers(
    format::HandleId wrapper_id,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_VERTEX_BUFFER_VIEW* pViews);

void Encode_ID3D12GraphicsCommandList_SOSetTargets(
    format::HandleId wrapper_id,
    UINT StartSlot,
    UINT NumViews,
    const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews);

void Encode_ID3D12GraphicsCommandList_OMSetRenderTargets(
    format::HandleId wrapper_id,
    UINT NumRenderTargetDescriptors,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
    BOOL RTsSingleHandleToDescriptorRange,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor);

void Encode_ID3D12GraphicsCommandList_ClearDepthStencilView(
    format::HandleId wrapper_id,
    D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
    D3D12_CLEAR_FLAGS ClearFlags,
    FLOAT Depth,
    UINT8 Stencil,
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_ClearRenderTargetView(
    format::HandleId wrapper_id,
    D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
    const FLOAT ColorRGBA [4],
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
    format::HandleId wrapper_id,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const UINT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
    format::HandleId wrapper_id,
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const FLOAT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects);

void Encode_ID3D12GraphicsCommandList_DiscardResource(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_DISCARD_REGION* pRegion);

void Encode_ID3D12GraphicsCommandList_BeginQuery(
    format::HandleId wrapper_id,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index);

void Encode_ID3D12GraphicsCommandList_EndQuery(
    format::HandleId wrapper_id,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index);

void Encode_ID3D12GraphicsCommandList_ResolveQueryData(
    format::HandleId wrapper_id,
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT StartIndex,
    UINT NumQueries,
    ID3D12Resource* pDestinationBuffer,
    UINT64 AlignedDestinationBufferOffset);

void Encode_ID3D12GraphicsCommandList_SetPredication(
    format::HandleId wrapper_id,
    ID3D12Resource* pBuffer,
    UINT64 AlignedBufferOffset,
    D3D12_PREDICATION_OP Operation);

void Encode_ID3D12GraphicsCommandList_SetMarker(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12GraphicsCommandList_BeginEvent(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12GraphicsCommandList_EndEvent(
    format::HandleId wrapper_id);

void Encode_ID3D12GraphicsCommandList_ExecuteIndirect(
    format::HandleId wrapper_id,
    ID3D12CommandSignature* pCommandSignature,
    UINT MaxCommandCount,
    ID3D12Resource* pArgumentBuffer,
    UINT64 ArgumentBufferOffset,
    ID3D12Resource* pCountBuffer,
    UINT64 CountBufferOffset);

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

void Encode_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

void Encode_ID3D12GraphicsCommandList1_OMSetDepthBounds(
    format::HandleId wrapper_id,
    FLOAT Min,
    FLOAT Max);

void Encode_ID3D12GraphicsCommandList1_SetSamplePositions(
    format::HandleId wrapper_id,
    UINT NumSamplesPerPixel,
    UINT NumPixels,
    D3D12_SAMPLE_POSITION* pSamplePositions);

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
    D3D12_RESOLVE_MODE ResolveMode);

void Encode_ID3D12GraphicsCommandList1_SetViewInstanceMask(
    format::HandleId wrapper_id,
    UINT Mask);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER& value);

void Encode_ID3D12GraphicsCommandList2_WriteBufferImmediate(
    format::HandleId wrapper_id,
    UINT Count,
    const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
    const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes);

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
    D3D12_TILE_MAPPING_FLAGS Flags);

void Encode_ID3D12CommandQueue_CopyTileMappings(
    format::HandleId wrapper_id,
    ID3D12Resource* pDstResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
    ID3D12Resource* pSrcResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS Flags);

void Encode_ID3D12CommandQueue_ExecuteCommandLists(
    format::HandleId wrapper_id,
    UINT NumCommandLists,
    ID3D12CommandList* const* ppCommandLists);

void Encode_ID3D12CommandQueue_SetMarker(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12CommandQueue_BeginEvent(
    format::HandleId wrapper_id,
    UINT Metadata,
    const void* pData,
    UINT Size);

void Encode_ID3D12CommandQueue_EndEvent(
    format::HandleId wrapper_id);

void Encode_ID3D12CommandQueue_Signal(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Fence* pFence,
    UINT64 Value);

void Encode_ID3D12CommandQueue_Wait(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Fence* pFence,
    UINT64 Value);

void Encode_ID3D12CommandQueue_GetTimestampFrequency(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64* pFrequency);

void Encode_ID3D12CommandQueue_GetClockCalibration(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64* pGpuTimestamp,
    UINT64* pCpuTimestamp);

void Encode_ID3D12CommandQueue_GetDesc(
    format::HandleId wrapper_id,
    D3D12_COMMAND_QUEUE_DESC result);

void Encode_ID3D12Device_GetNodeCount(
    format::HandleId wrapper_id,
    UINT result);

void Encode_ID3D12Device_CreateCommandQueue(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID riid,
    void** ppCommandQueue);

void Encode_ID3D12Device_CreateCommandAllocator(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_COMMAND_LIST_TYPE type,
    REFIID riid,
    void** ppCommandAllocator);

void Encode_ID3D12Device_CreateGraphicsPipelineState(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device_CreateComputePipelineState(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device_CreateCommandList(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    ID3D12CommandAllocator* pCommandAllocator,
    ID3D12PipelineState* pInitialState,
    REFIID riid,
    void** ppCommandList);

void Encode_ID3D12Device_CreateDescriptorHeap(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device_GetDescriptorHandleIncrementSize(
    format::HandleId wrapper_id,
    UINT result,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType);

void Encode_ID3D12Device_CreateRootSignature(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT nodeMask,
    const void* pBlobWithRootSignature,
    SIZE_T blobLengthInBytes,
    REFIID riid,
    void** ppvRootSignature);

void Encode_ID3D12Device_CreateConstantBufferView(
    format::HandleId wrapper_id,
    const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateShaderResourceView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateUnorderedAccessView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    ID3D12Resource* pCounterResource,
    const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateRenderTargetView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateDepthStencilView(
    format::HandleId wrapper_id,
    ID3D12Resource* pResource,
    const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CreateSampler(
    format::HandleId wrapper_id,
    const D3D12_SAMPLER_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device_CopyDescriptors(
    format::HandleId wrapper_id,
    UINT NumDestDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
    const UINT* pDestDescriptorRangeSizes,
    UINT NumSrcDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
    const UINT* pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

void Encode_ID3D12Device_CopyDescriptorsSimple(
    format::HandleId wrapper_id,
    UINT NumDescriptors,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

void Encode_ID3D12Device_GetResourceAllocationInfo(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_ALLOCATION_INFO result,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs);

void Encode_ID3D12Device_GetCustomHeapProperties(
    format::HandleId wrapper_id,
    D3D12_HEAP_PROPERTIES result,
    UINT nodeMask,
    D3D12_HEAP_TYPE heapType);

void Encode_ID3D12Device_CreateCommittedResource(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riidResource,
    void** ppvResource);

void Encode_ID3D12Device_CreateHeap(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device_CreatePlacedResource(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device_CreateReservedResource(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device_CreateSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12DeviceChild* pObject,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD Access,
    LPCWSTR Name,
    HANDLE* pHandle);

void Encode_ID3D12Device_OpenSharedHandle(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE NTHandle,
    REFIID riid,
    void** ppvObj);

void Encode_ID3D12Device_OpenSharedHandleByName(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR Name,
    DWORD Access,
    HANDLE* pNTHandle);

void Encode_ID3D12Device_MakeResident(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects);

void Encode_ID3D12Device_Evict(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects);

void Encode_ID3D12Device_CreateFence(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT64 InitialValue,
    D3D12_FENCE_FLAGS Flags,
    REFIID riid,
    void** ppFence);

void Encode_ID3D12Device_GetDeviceRemovedReason(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_ID3D12Device_GetCopyableFootprints(
    format::HandleId wrapper_id,
    const D3D12_RESOURCE_DESC* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes);

void Encode_ID3D12Device_CreateQueryHeap(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_QUERY_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device_SetStablePowerState(
    format::HandleId wrapper_id,
    HRESULT result,
    BOOL Enable);

void Encode_ID3D12Device_CreateCommandSignature(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
    ID3D12RootSignature* pRootSignature,
    REFIID riid,
    void** ppvCommandSignature);

void Encode_ID3D12Device_GetResourceTiling(
    format::HandleId wrapper_id,
    ID3D12Resource* pTiledResource,
    UINT* pNumTilesForEntireResource,
    D3D12_PACKED_MIP_INFO* pPackedMipDesc,
    D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
    UINT* pNumSubresourceTilings,
    UINT FirstSubresourceTilingToGet,
    D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips);

void Encode_ID3D12Device_GetAdapterLuid(
    format::HandleId wrapper_id,
    LUID result);

void Encode_ID3D12PipelineLibrary_StorePipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    ID3D12PipelineState* pPipeline);

void Encode_ID3D12PipelineLibrary_LoadGraphicsPipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12PipelineLibrary_LoadComputePipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12PipelineLibrary_GetSerializedSize(
    format::HandleId wrapper_id,
    SIZE_T result);

void Encode_ID3D12PipelineLibrary_Serialize(
    format::HandleId wrapper_id,
    HRESULT result,
    void* pData,
    SIZE_T DataSizeInBytes);

void Encode_ID3D12PipelineLibrary1_LoadPipeline(
    format::HandleId wrapper_id,
    HRESULT result,
    LPCWSTR pName,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device1_CreatePipelineLibrary(
    format::HandleId wrapper_id,
    HRESULT result,
    const void* pLibraryBlob,
    SIZE_T BlobLength,
    REFIID riid,
    void** ppPipelineLibrary);

void Encode_ID3D12Device1_SetEventOnMultipleFenceCompletion(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Fence* const* ppFences,
    const UINT64* pFenceValues,
    UINT NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
    HANDLE hEvent);

void Encode_ID3D12Device1_SetResidencyPriority(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    const D3D12_RESIDENCY_PRIORITY* pPriorities);

void Encode_ID3D12Device2_CreatePipelineState(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState);

void Encode_ID3D12Device3_OpenExistingHeapFromAddress(
    format::HandleId wrapper_id,
    HRESULT result,
    const void* pAddress,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device3_OpenExistingHeapFromFileMapping(
    format::HandleId wrapper_id,
    HRESULT result,
    HANDLE hFileMapping,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device3_EnqueueMakeResident(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_RESIDENCY_FLAGS Flags,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    ID3D12Fence* pFenceToSignal,
    UINT64 FenceValueToSignal);

void Encode_ID3D12ProtectedSession_GetStatusFence(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppFence);

void Encode_ID3D12ProtectedSession_GetSessionStatus(
    format::HandleId wrapper_id,
    D3D12_PROTECTED_SESSION_STATUS result);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_SUPPORT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PROTECTED_RESOURCE_SESSION_DESC& value);

void Encode_ID3D12ProtectedResourceSession_GetDesc(
    format::HandleId wrapper_id,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC result);

void Encode_ID3D12Device4_CreateCommandList1(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    D3D12_COMMAND_LIST_FLAGS flags,
    REFIID riid,
    void** ppCommandList);

void Encode_ID3D12Device4_CreateProtectedResourceSession(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppSession);

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
    void** ppvResource);

void Encode_ID3D12Device4_CreateHeap1(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_HEAP_DESC* pDesc,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvHeap);

void Encode_ID3D12Device4_CreateReservedResource1(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device4_GetResourceAllocationInfo1(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_ALLOCATION_INFO result,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

void Encode_ID3D12LifetimeOwner_LifetimeStateUpdated(
    format::HandleId wrapper_id,
    D3D12_LIFETIME_STATE NewState);

void Encode_ID3D12SwapChainAssistant_GetLUID(
    format::HandleId wrapper_id,
    LUID result);

void Encode_ID3D12SwapChainAssistant_GetSwapChainObject(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppv);

void Encode_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riidResource,
    void** ppvResource,
    REFIID riidQueue,
    void** ppvQueue);

void Encode_ID3D12SwapChainAssistant_InsertImplicitSync(
    format::HandleId wrapper_id,
    HRESULT result);

void Encode_ID3D12LifetimeTracker_DestroyOwnedObject(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12DeviceChild* pObject);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_META_COMMAND_PARAMETER_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_META_COMMAND_DESC& value);

void Encode_ID3D12StateObjectProperties_GetShaderIdentifier(
    format::HandleId wrapper_id,
    void* result,
    LPCWSTR pExportName);

void Encode_ID3D12StateObjectProperties_GetShaderStackSize(
    format::HandleId wrapper_id,
    UINT64 result,
    LPCWSTR pExportName);

void Encode_ID3D12StateObjectProperties_GetPipelineStackSize(
    format::HandleId wrapper_id,
    UINT64 result);

void Encode_ID3D12StateObjectProperties_SetPipelineStackSize(
    format::HandleId wrapper_id,
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
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12LifetimeOwner* pOwner,
    REFIID riid,
    void** ppvTracker);

void Encode_ID3D12Device5_RemoveDevice(
    format::HandleId wrapper_id);

void Encode_ID3D12Device5_EnumerateMetaCommands(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT* pNumMetaCommands,
    D3D12_META_COMMAND_DESC* pDescs);

void Encode_ID3D12Device5_EnumerateMetaCommandParameters(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT* pTotalStructureSizeInBytes,
    UINT* pParameterCount,
    D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs);

void Encode_ID3D12Device5_CreateMetaCommand(
    format::HandleId wrapper_id,
    HRESULT result,
    REFGUID CommandId,
    UINT NodeMask,
    const void* pCreationParametersData,
    SIZE_T CreationParametersDataSizeInBytes,
    REFIID riid,
    void** ppMetaCommand);

void Encode_ID3D12Device5_CreateStateObject(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_STATE_OBJECT_DESC* pDesc,
    REFIID riid,
    void** ppStateObject);

void Encode_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
    format::HandleId wrapper_id,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo);

void Encode_ID3D12Device5_CheckDriverMatchingIdentifier(
    format::HandleId wrapper_id,
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS result,
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

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA1& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DEVICE_REMOVED_EXTENDED_DATA2& value);

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
    format::HandleId wrapper_id,
    D3D12_DRED_ENABLEMENT Enablement);

void Encode_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput);

void Encode_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput);

void Encode_ID3D12Device6_SetBackgroundProcessingMode(
    format::HandleId wrapper_id,
    HRESULT result,
    D3D12_BACKGROUND_PROCESSING_MODE Mode,
    D3D12_MEASUREMENTS_ACTION MeasurementsAction,
    HANDLE hEventToSignalUponCompletion,
    BOOL* pbFurtherMeasurementsDesired);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPE_COUNT& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_FEATURE_DATA_PROTECTED_RESOURCE_SESSION_TYPES& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_PROTECTED_RESOURCE_SESSION_DESC1& value);

void Encode_ID3D12ProtectedResourceSession1_GetDesc1(
    format::HandleId wrapper_id,
    D3D12_PROTECTED_RESOURCE_SESSION_DESC1 result);

void Encode_ID3D12Device7_AddToStateObject(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_STATE_OBJECT_DESC* pAddition,
    ID3D12StateObject* pStateObjectToGrowFrom,
    REFIID riid,
    void** ppNewStateObject);

void Encode_ID3D12Device7_CreateProtectedResourceSession1(
    format::HandleId wrapper_id,
    HRESULT result,
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
    REFIID riid,
    void** ppSession);

void Encode_ID3D12Device8_GetResourceAllocationInfo2(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_ALLOCATION_INFO result,
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC1* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

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
    void** ppvResource);

void Encode_ID3D12Device8_CreatePlacedResource1(
    format::HandleId wrapper_id,
    HRESULT result,
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource);

void Encode_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
    format::HandleId wrapper_id,
    ID3D12Resource* pTargetedResource,
    ID3D12Resource* pFeedbackResource,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

void Encode_ID3D12Device8_GetCopyableFootprints1(
    format::HandleId wrapper_id,
    const D3D12_RESOURCE_DESC1* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes);

void Encode_ID3D12Resource1_GetProtectedResourceSession(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppProtectedSession);

void Encode_ID3D12Resource2_GetDesc1(
    format::HandleId wrapper_id,
    D3D12_RESOURCE_DESC1 result);

void Encode_ID3D12Heap1_GetProtectedResourceSession(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppProtectedSession);

void Encode_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
    format::HandleId wrapper_id,
    ID3D12ProtectedResourceSession* pProtectedResourceSession);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_BEGINNING_ACCESS_CLEAR_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_SUBRESOURCE_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_ENDING_ACCESS_RESOLVE_PARAMETERS& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_RENDER_TARGET_DESC& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC& value);

void Encode_ID3D12MetaCommand_GetRequiredParameterResourceSize(
    format::HandleId wrapper_id,
    UINT64 result,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT ParameterIndex);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_RAYS_DESC& value);

void Encode_ID3D12GraphicsCommandList4_BeginRenderPass(
    format::HandleId wrapper_id,
    UINT NumRenderTargets,
    const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
    const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS Flags);

void Encode_ID3D12GraphicsCommandList4_EndRenderPass(
    format::HandleId wrapper_id);

void Encode_ID3D12GraphicsCommandList4_InitializeMetaCommand(
    format::HandleId wrapper_id,
    ID3D12MetaCommand* pMetaCommand,
    const void* pInitializationParametersData,
    SIZE_T InitializationParametersDataSizeInBytes);

void Encode_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
    format::HandleId wrapper_id,
    ID3D12MetaCommand* pMetaCommand,
    const void* pExecutionParametersData,
    SIZE_T ExecutionParametersDataSizeInBytes);

void Encode_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
    format::HandleId wrapper_id,
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
    UINT NumPostbuildInfoDescs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs);

void Encode_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
    format::HandleId wrapper_id,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
    UINT NumSourceAccelerationStructures,
    const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData);

void Encode_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
    format::HandleId wrapper_id,
    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode);

void Encode_ID3D12GraphicsCommandList4_SetPipelineState1(
    format::HandleId wrapper_id,
    ID3D12StateObject* pStateObject);

void Encode_ID3D12GraphicsCommandList4_DispatchRays(
    format::HandleId wrapper_id,
    const D3D12_DISPATCH_RAYS_DESC* pDesc);

void Encode_ID3D12Tools_EnableShaderInstrumentation(
    format::HandleId wrapper_id,
    BOOL bEnable);

void Encode_ID3D12Tools_ShaderInstrumentationEnabled(
    format::HandleId wrapper_id,
    BOOL result);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_SUBRESOURCE_DATA& value);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_MEMCPY_DEST& value);

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRate(
    format::HandleId wrapper_id,
    D3D12_SHADING_RATE baseShadingRate,
    const D3D12_SHADING_RATE_COMBINER* combiners);

void Encode_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
    format::HandleId wrapper_id,
    ID3D12Resource* shadingRateImage);

void EncodeStruct(ParameterEncoder* encoder, const D3D12_DISPATCH_MESH_ARGUMENTS& value);

void Encode_ID3D12GraphicsCommandList6_DispatchMesh(
    format::HandleId wrapper_id,
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ);


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const D3D_SHADER_MACRO& value);

void Encode_ID3D10Blob_GetBufferPointer(
    format::HandleId wrapper_id,
    LPVOID result);

void Encode_ID3D10Blob_GetBufferSize(
    format::HandleId wrapper_id,
    SIZE_T result);

void Encode_ID3DDestructionNotifier_RegisterDestructionCallback(
    format::HandleId wrapper_id,
    HRESULT result,
    PFN_DESTRUCTION_CALLBACK callbackFn,
    void* pData,
    UINT* pCallbackID);

void Encode_ID3DDestructionNotifier_UnregisterDestructionCallback(
    format::HandleId wrapper_id,
    HRESULT result,
    UINT callbackID);


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.19041.0
**
*/

void Encode_IUnknown_QueryInterface(
    format::HandleId wrapper_id,
    HRESULT result,
    REFIID riid,
    void** ppvObject);

void Encode_IUnknown_AddRef(
    format::HandleId wrapper_id,
    ULONG result);

void Encode_IUnknown_Release(
    format::HandleId wrapper_id,
    ULONG result);


/*
** This part is generated from guiddef.h in Windows SDK: 10.0.19041.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const GUID& value);


/*
** This part is generated from windef.h in Windows SDK: 10.0.19041.0
**
*/

void EncodeStruct(ParameterEncoder* encoder, const tagRECT& value);

void EncodeStruct(ParameterEncoder* encoder, const tagPOINT& value);


/*
** This part is generated from minwinbase.h in Windows SDK: 10.0.19041.0
**
*/


GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
