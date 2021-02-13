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
** This file is generated from dx12_replay_consumer_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_REPLAY_CONSUMER_H
#define  GFXRECON_GENERATED_DX12_REPLAY_CONSUMER_H


#include "decode/dx12_replay_consumer_base.h"


GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class DX12ReplayConsumer : public DX12ReplayConsumerBase
{
  public:
    DX12ReplayConsumer(){}
    virtual ~DX12ReplayConsumer() override {}
/*
** This part is generated from dxgi.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_CreateDXGIFactory(
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory);

    virtual void Process_CreateDXGIFactory1(
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory);

    virtual void Process_IDXGIObject_SetPrivateData(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID Name,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData);

    virtual void Process_IDXGIObject_SetPrivateDataInterface(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID Name,
        HandlePointerDecoder<IUnknown*>* pUnknown);

    virtual void Process_IDXGIObject_GetPrivateData(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID Name,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData);

    virtual void Process_IDXGIObject_GetParent(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParent);

    virtual void Process_IDXGIDeviceSubObject_GetDevice(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice);

    virtual void Process_IDXGIResource_GetSharedHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<HANDLE>* pSharedHandle);

    virtual void Process_IDXGIResource_GetUsage(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<DXGI_USAGE>* pUsage);

    virtual void Process_IDXGIResource_SetEvictionPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT EvictionPriority);

    virtual void Process_IDXGIResource_GetEvictionPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pEvictionPriority);

    virtual void Process_IDXGIKeyedMutex_AcquireSync(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Key,
        DWORD dwMilliseconds);

    virtual void Process_IDXGIKeyedMutex_ReleaseSync(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Key);

    virtual void Process_IDXGISurface_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc);

    virtual void Process_IDXGISurface_Map(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect,
        UINT MapFlags);

    virtual void Process_IDXGISurface_Unmap(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_IDXGISurface1_GetDC(
        format::HandleId object_id,
        HRESULT returnValue,
        BOOL Discard,
        HandlePointerDecoder<HDC>* phdc);

    virtual void Process_IDXGISurface1_ReleaseDC(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRect);

    virtual void Process_IDXGIAdapter_EnumOutputs(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Output,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput);

    virtual void Process_IDXGIAdapter_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC>* pDesc);

    virtual void Process_IDXGIAdapter_CheckInterfaceSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID InterfaceName,
        StructPointerDecoder<Decoded_LARGE_INTEGER>* pUMDVersion);

    virtual void Process_IDXGIOutput_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC>* pDesc);

    virtual void Process_IDXGIOutput_GetDisplayModeList(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pDesc);

    virtual void Process_IDXGIOutput_FindClosestMatchingMode(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pClosestMatch,
        HandlePointerDecoder<IUnknown*>* pConcernedDevice);

    virtual void Process_IDXGIOutput_WaitForVBlank(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_IDXGIOutput_TakeOwnership(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        BOOL Exclusive);

    virtual void Process_IDXGIOutput_ReleaseOwnership(
        format::HandleId object_id);

    virtual void Process_IDXGIOutput_GetGammaControlCapabilities(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL_CAPABILITIES>* pGammaCaps);

    virtual void Process_IDXGIOutput_SetGammaControl(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray);

    virtual void Process_IDXGIOutput_GetGammaControl(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_GAMMA_CONTROL>* pArray);

    virtual void Process_IDXGIOutput_SetDisplaySurface(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGISurface*>* pScanoutSurface);

    virtual void Process_IDXGIOutput_GetDisplaySurfaceData(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGISurface*>* pDestination);

    virtual void Process_IDXGIOutput_GetFrameStatistics(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats);

    virtual void Process_IDXGISwapChain_Present(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT SyncInterval,
        UINT Flags);

    virtual void Process_IDXGISwapChain_GetBuffer(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Buffer,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSurface);

    virtual void Process_IDXGISwapChain_SetFullscreenState(
        format::HandleId object_id,
        HRESULT returnValue,
        BOOL Fullscreen,
        HandlePointerDecoder<IDXGIOutput*>* pTarget);

    virtual void Process_IDXGISwapChain_GetFullscreenState(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<BOOL>* pFullscreen,
        HandlePointerDecoder<IDXGIOutput*>* ppTarget);

    virtual void Process_IDXGISwapChain_GetDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc);

    virtual void Process_IDXGISwapChain_ResizeBuffers(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags);

    virtual void Process_IDXGISwapChain_ResizeTarget(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC>* pNewTargetParameters);

    virtual void Process_IDXGISwapChain_GetContainingOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGIOutput*>* ppOutput);

    virtual void Process_IDXGISwapChain_GetFrameStatistics(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS>* pStats);

    virtual void Process_IDXGISwapChain_GetLastPresentCount(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pLastPresentCount);

    virtual void Process_IDXGIFactory_EnumAdapters(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter);

    virtual void Process_IDXGIFactory_MakeWindowAssociation(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId WindowHandle,
        UINT Flags);

    virtual void Process_IDXGIFactory_GetWindowAssociation(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<HWND>* pWindowHandle);

    virtual void Process_IDXGIFactory_CreateSwapChain(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC>* pDesc,
        HandlePointerDecoder<IDXGISwapChain*>* ppSwapChain);

    virtual void Process_IDXGIFactory_CreateSoftwareAdapter(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId Module,
        HandlePointerDecoder<IDXGIAdapter*>* ppAdapter);

    virtual void Process_IDXGIDevice_GetAdapter(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGIAdapter*>* pAdapter);

    virtual void Process_IDXGIDevice_CreateSurface(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SURFACE_DESC>* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        StructPointerDecoder<Decoded_DXGI_SHARED_RESOURCE>* pSharedResource,
        HandlePointerDecoder<IDXGISurface*>* ppSurface);

    virtual void Process_IDXGIDevice_QueryResourceResidency(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* ppResources,
        PointerDecoder<DXGI_RESIDENCY>* pResidencyStatus,
        UINT NumResources);

    virtual void Process_IDXGIDevice_SetGPUThreadPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        INT Priority);

    virtual void Process_IDXGIDevice_GetGPUThreadPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<INT>* pPriority);

    virtual void Process_IDXGIFactory1_EnumAdapters1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Adapter,
        HandlePointerDecoder<IDXGIAdapter1*>* ppAdapter);

    virtual void Process_IDXGIFactory1_IsCurrent(
        format::HandleId object_id,
        BOOL returnValue);

    virtual void Process_IDXGIAdapter1_GetDesc1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC1>* pDesc);

    virtual void Process_IDXGIDevice1_SetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT MaxLatency);

    virtual void Process_IDXGIDevice1_GetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pMaxLatency);

/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_IDXGIDisplayControl_IsStereoEnabled(
        format::HandleId object_id,
        BOOL returnValue);

    virtual void Process_IDXGIDisplayControl_SetStereoEnabled(
        format::HandleId object_id,
        BOOL enabled);

    virtual void Process_IDXGIOutputDuplication_GetDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_DESC>* pDesc);

    virtual void Process_IDXGIOutputDuplication_AcquireNextFrame(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT TimeoutInMilliseconds,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_FRAME_INFO>* pFrameInfo,
        HandlePointerDecoder<IDXGIResource*>* ppDesktopResource);

    virtual void Process_IDXGIOutputDuplication_GetFrameDirtyRects(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT DirtyRectsBufferSize,
        StructPointerDecoder<Decoded_tagRECT>* pDirtyRectsBuffer,
        PointerDecoder<UINT>* pDirtyRectsBufferSizeRequired);

    virtual void Process_IDXGIOutputDuplication_GetFrameMoveRects(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT MoveRectsBufferSize,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_MOVE_RECT>* pMoveRectBuffer,
        PointerDecoder<UINT>* pMoveRectsBufferSizeRequired);

    virtual void Process_IDXGIOutputDuplication_GetFramePointerShape(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT PointerShapeBufferSize,
        PointerDecoder<uint8_t>* pPointerShapeBuffer,
        PointerDecoder<UINT>* pPointerShapeBufferSizeRequired,
        StructPointerDecoder<Decoded_DXGI_OUTDUPL_POINTER_SHAPE_INFO>* pPointerShapeInfo);

    virtual void Process_IDXGIOutputDuplication_MapDesktopSurface(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MAPPED_RECT>* pLockedRect);

    virtual void Process_IDXGIOutputDuplication_UnMapDesktopSurface(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_IDXGIOutputDuplication_ReleaseFrame(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_IDXGISurface2_GetResource(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppParentResource,
        PointerDecoder<UINT>* pSubresourceIndex);

    virtual void Process_IDXGIResource1_CreateSubresourceSurface(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT index,
        HandlePointerDecoder<IDXGISurface2*>* ppSurface);

    virtual void Process_IDXGIResource1_CreateSharedHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD dwAccess,
        WStringDecoder* lpName,
        HandlePointerDecoder<HANDLE>* pHandle);

    virtual void Process_IDXGIDevice2_OfferResources(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority);

    virtual void Process_IDXGIDevice2_ReclaimResources(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<BOOL>* pDiscarded);

    virtual void Process_IDXGIDevice2_EnqueueSetEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hEvent);

    virtual void Process_IDXGISwapChain1_GetDesc1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc);

    virtual void Process_IDXGISwapChain1_GetFullscreenDesc(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pDesc);

    virtual void Process_IDXGISwapChain1_GetHwnd(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<HWND>* pHwnd);

    virtual void Process_IDXGISwapChain1_GetCoreWindow(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID refiid,
        HandlePointerDecoder<void*>* ppUnk);

    virtual void Process_IDXGISwapChain1_Present1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT SyncInterval,
        UINT PresentFlags,
        StructPointerDecoder<Decoded_DXGI_PRESENT_PARAMETERS>* pPresentParameters);

    virtual void Process_IDXGISwapChain1_IsTemporaryMonoSupported(
        format::HandleId object_id,
        BOOL returnValue);

    virtual void Process_IDXGISwapChain1_GetRestrictToOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGIOutput*>* ppRestrictToOutput);

    virtual void Process_IDXGISwapChain1_SetBackgroundColor(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor);

    virtual void Process_IDXGISwapChain1_GetBackgroundColor(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3DCOLORVALUE>* pColor);

    virtual void Process_IDXGISwapChain1_SetRotation(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_MODE_ROTATION Rotation);

    virtual void Process_IDXGISwapChain1_GetRotation(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<DXGI_MODE_ROTATION>* pRotation);

    virtual void Process_IDXGIFactory2_IsWindowedStereoEnabled(
        format::HandleId object_id,
        BOOL returnValue);

    virtual void Process_IDXGIFactory2_CreateSwapChainForHwnd(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        format::HandleId hWnd,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_FULLSCREEN_DESC>* pFullscreenDesc,
        HandlePointerDecoder<IDXGIOutput*>* pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain);

    virtual void Process_IDXGIFactory2_CreateSwapChainForCoreWindow(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        HandlePointerDecoder<IUnknown*>* pWindow,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        HandlePointerDecoder<IDXGIOutput*>* pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain);

    virtual void Process_IDXGIFactory2_GetSharedResourceAdapterLuid(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hResource,
        StructPointerDecoder<Decoded_LUID>* pLuid);

    virtual void Process_IDXGIFactory2_RegisterStereoStatusWindow(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie);

    virtual void Process_IDXGIFactory2_RegisterStereoStatusEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hEvent,
        PointerDecoder<DWORD>* pdwCookie);

    virtual void Process_IDXGIFactory2_UnregisterStereoStatus(
        format::HandleId object_id,
        DWORD dwCookie);

    virtual void Process_IDXGIFactory2_RegisterOcclusionStatusWindow(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId WindowHandle,
        UINT wMsg,
        PointerDecoder<DWORD>* pdwCookie);

    virtual void Process_IDXGIFactory2_RegisterOcclusionStatusEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hEvent,
        PointerDecoder<DWORD>* pdwCookie);

    virtual void Process_IDXGIFactory2_UnregisterOcclusionStatus(
        format::HandleId object_id,
        DWORD dwCookie);

    virtual void Process_IDXGIFactory2_CreateSwapChainForComposition(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        HandlePointerDecoder<IDXGIOutput*>* pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain);

    virtual void Process_IDXGIAdapter2_GetDesc2(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC2>* pDesc);

    virtual void Process_IDXGIOutput1_GetDisplayModeList1(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        PointerDecoder<UINT>* pNumModes,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pDesc);

    virtual void Process_IDXGIOutput1_FindClosestMatchingMode1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pModeToMatch,
        StructPointerDecoder<Decoded_DXGI_MODE_DESC1>* pClosestMatch,
        HandlePointerDecoder<IUnknown*>* pConcernedDevice);

    virtual void Process_IDXGIOutput1_GetDisplaySurfaceData1(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IDXGIResource*>* pDestination);

    virtual void Process_IDXGIOutput1_DuplicateOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication);

/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_CreateDXGIFactory2(
        HRESULT returnValue,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFactory);

    virtual void Process_DXGIGetDebugInterface1(
        HRESULT returnValue,
        UINT Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* pDebug);

    virtual void Process_IDXGIDevice3_Trim(
        format::HandleId object_id);

    virtual void Process_IDXGISwapChain2_SetSourceSize(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Width,
        UINT Height);

    virtual void Process_IDXGISwapChain2_GetSourceSize(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight);

    virtual void Process_IDXGISwapChain2_SetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT MaxLatency);

    virtual void Process_IDXGISwapChain2_GetMaximumFrameLatency(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pMaxLatency);

    virtual void Process_IDXGISwapChain2_GetFrameLatencyWaitableObject(
        format::HandleId object_id,
        format::HandleId returnValue);

    virtual void Process_IDXGISwapChain2_SetMatrixTransform(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix);

    virtual void Process_IDXGISwapChain2_GetMatrixTransform(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_MATRIX_3X2_F>* pMatrix);

    virtual void Process_IDXGIOutput2_SupportsOverlays(
        format::HandleId object_id,
        BOOL returnValue);

    virtual void Process_IDXGIFactory3_GetCreationFlags(
        format::HandleId object_id,
        UINT returnValue);

    virtual void Process_IDXGIDecodeSwapChain_PresentBuffer(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags);

    virtual void Process_IDXGIDecodeSwapChain_SetSourceRect(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect);

    virtual void Process_IDXGIDecodeSwapChain_SetTargetRect(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect);

    virtual void Process_IDXGIDecodeSwapChain_SetDestSize(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Width,
        UINT Height);

    virtual void Process_IDXGIDecodeSwapChain_GetSourceRect(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect);

    virtual void Process_IDXGIDecodeSwapChain_GetTargetRect(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_tagRECT>* pRect);

    virtual void Process_IDXGIDecodeSwapChain_GetDestSize(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pWidth,
        PointerDecoder<UINT>* pHeight);

    virtual void Process_IDXGIDecodeSwapChain_SetColorSpace(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace);

    virtual void Process_IDXGIDecodeSwapChain_GetColorSpace(
        format::HandleId object_id,
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS returnValue);

    virtual void Process_IDXGIFactoryMedia_CreateSwapChainForCompositionSurfaceHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        format::HandleId hSurface,
        StructPointerDecoder<Decoded_DXGI_SWAP_CHAIN_DESC1>* pDesc,
        HandlePointerDecoder<IDXGIOutput*>* pRestrictToOutput,
        HandlePointerDecoder<IDXGISwapChain1*>* ppSwapChain);

    virtual void Process_IDXGIFactoryMedia_CreateDecodeSwapChainForCompositionSurfaceHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        format::HandleId hSurface,
        StructPointerDecoder<Decoded_DXGI_DECODE_SWAP_CHAIN_DESC>* pDesc,
        HandlePointerDecoder<IDXGIResource*>* pYuvDecodeBuffers,
        HandlePointerDecoder<IDXGIOutput*>* pRestrictToOutput,
        HandlePointerDecoder<IDXGIDecodeSwapChain*>* ppSwapChain);

    virtual void Process_IDXGISwapChainMedia_GetFrameStatisticsMedia(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_FRAME_STATISTICS_MEDIA>* pStats);

    virtual void Process_IDXGISwapChainMedia_SetPresentDuration(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Duration);

    virtual void Process_IDXGISwapChainMedia_CheckPresentDurationSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT DesiredPresentDuration,
        PointerDecoder<UINT>* pClosestSmallerPresentDuration,
        PointerDecoder<UINT>* pClosestLargerPresentDuration);

    virtual void Process_IDXGIOutput3_CheckOverlaySupport(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT EnumFormat,
        HandlePointerDecoder<IUnknown*>* pConcernedDevice,
        PointerDecoder<UINT>* pFlags);

/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_IDXGISwapChain3_GetCurrentBackBufferIndex(
        format::HandleId object_id,
        UINT returnValue);

    virtual void Process_IDXGISwapChain3_CheckColorSpaceSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        PointerDecoder<UINT>* pColorSpaceSupport);

    virtual void Process_IDXGISwapChain3_SetColorSpace1(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_COLOR_SPACE_TYPE ColorSpace);

    virtual void Process_IDXGISwapChain3_ResizeBuffers1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT Format,
        UINT SwapChainFlags,
        PointerDecoder<UINT>* pCreationNodeMask,
        HandlePointerDecoder<IUnknown*>* ppPresentQueue);

    virtual void Process_IDXGIOutput4_CheckOverlayColorSpaceSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        HandlePointerDecoder<IUnknown*>* pConcernedDevice,
        PointerDecoder<UINT>* pFlags);

    virtual void Process_IDXGIFactory4_EnumAdapterByLuid(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_LUID AdapterLuid,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter);

    virtual void Process_IDXGIFactory4_EnumWarpAdapter(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter);

    virtual void Process_IDXGIAdapter3_RegisterHardwareContentProtectionTeardownStatusEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hEvent,
        PointerDecoder<DWORD>* pdwCookie);

    virtual void Process_IDXGIAdapter3_UnregisterHardwareContentProtectionTeardownStatus(
        format::HandleId object_id,
        DWORD dwCookie);

    virtual void Process_IDXGIAdapter3_QueryVideoMemoryInfo(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        StructPointerDecoder<Decoded_DXGI_QUERY_VIDEO_MEMORY_INFO>* pVideoMemoryInfo);

    virtual void Process_IDXGIAdapter3_SetVideoMemoryReservation(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation);

    virtual void Process_IDXGIAdapter3_RegisterVideoMemoryBudgetChangeNotificationEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hEvent,
        PointerDecoder<DWORD>* pdwCookie);

    virtual void Process_IDXGIAdapter3_UnregisterVideoMemoryBudgetChangeNotification(
        format::HandleId object_id,
        DWORD dwCookie);

/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_IDXGIOutput5_DuplicateOutput1(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pDevice,
        UINT Flags,
        UINT SupportedFormatsCount,
        PointerDecoder<DXGI_FORMAT>* pSupportedFormats,
        HandlePointerDecoder<IDXGIOutputDuplication*>* ppOutputDuplication);

    virtual void Process_IDXGISwapChain4_SetHDRMetaData(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        PointerDecoder<uint8_t>* pMetaData);

    virtual void Process_IDXGIDevice4_OfferResources1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags);

    virtual void Process_IDXGIDevice4_ReclaimResources1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumResources,
        HandlePointerDecoder<IDXGIResource*>* ppResources,
        PointerDecoder<DXGI_RECLAIM_RESOURCE_RESULTS>* pResults);

    virtual void Process_IDXGIFactory5_CheckFeatureSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        DXGI_FEATURE Feature,
        PointerDecoder<uint8_t>* pFeatureSupportData,
        UINT FeatureSupportDataSize);

/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_DXGIDeclareAdapterRemovalSupport(
        HRESULT returnValue);

    virtual void Process_IDXGIAdapter4_GetDesc3(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_ADAPTER_DESC3>* pDesc);

    virtual void Process_IDXGIOutput6_GetDesc1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_DXGI_OUTPUT_DESC1>* pDesc);

    virtual void Process_IDXGIOutput6_CheckHardwareCompositionSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pFlags);

    virtual void Process_IDXGIFactory6_EnumAdapterByGpuPreference(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvAdapter);

    virtual void Process_IDXGIFactory7_RegisterAdaptersChangedEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hEvent,
        PointerDecoder<DWORD>* pdwCookie);

    virtual void Process_IDXGIFactory7_UnregisterAdaptersChangedEvent(
        format::HandleId object_id,
        HRESULT returnValue,
        DWORD dwCookie);

/*
** This part is generated from d3d12.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_D3D12SerializeRootSignature(
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* pRootSignature,
        D3D_ROOT_SIGNATURE_VERSION Version,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob);

    virtual void Process_D3D12CreateRootSignatureDeserializer(
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer);

    virtual void Process_D3D12SerializeVersionedRootSignature(
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* pRootSignature,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob,
        HandlePointerDecoder<ID3D10Blob*>* ppErrorBlob);

    virtual void Process_D3D12CreateVersionedRootSignatureDeserializer(
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pSrcData,
        SIZE_T SrcDataSizeInBytes,
        Decoded_GUID pRootSignatureDeserializerInterface,
        HandlePointerDecoder<void*>* ppRootSignatureDeserializer);

    virtual void Process_D3D12CreateDevice(
        HRESULT returnValue,
        HandlePointerDecoder<IUnknown*>* pAdapter,
        D3D_FEATURE_LEVEL MinimumFeatureLevel,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppDevice);

    virtual void Process_D3D12GetDebugInterface(
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDebug);

    virtual void Process_D3D12EnableExperimentalFeatures(
        HRESULT returnValue,
        UINT NumFeatures,
        StructPointerDecoder<Decoded_GUID>* pIIDs,
        PointerDecoder<uint8_t>* pConfigurationStructs,
        PointerDecoder<UINT>* pConfigurationStructSizes);

    virtual void Process_ID3D12Object_GetPrivateData(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID guid,
        PointerDecoder<UINT>* pDataSize,
        PointerDecoder<uint8_t>* pData);

    virtual void Process_ID3D12Object_SetPrivateData(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID guid,
        UINT DataSize,
        PointerDecoder<uint8_t>* pData);

    virtual void Process_ID3D12Object_SetPrivateDataInterface(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID guid,
        HandlePointerDecoder<IUnknown*>* pData);

    virtual void Process_ID3D12Object_SetName(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* Name);

    virtual void Process_ID3D12DeviceChild_GetDevice(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvDevice);

    virtual void Process_ID3D12RootSignatureDeserializer_GetRootSignatureDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_ROOT_SIGNATURE_DESC>* returnValue);

    virtual void Process_ID3D12VersionedRootSignatureDeserializer_GetRootSignatureDescAtVersion(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC*>* ppDesc);

    virtual void Process_ID3D12VersionedRootSignatureDeserializer_GetUnconvertedRootSignatureDesc(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_VERSIONED_ROOT_SIGNATURE_DESC>* returnValue);

    virtual void Process_ID3D12Heap_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_HEAP_DESC returnValue);

    virtual void Process_ID3D12Resource_Map(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pReadRange,
        PointerDecoder<uint64_t, void*>* ppData);

    virtual void Process_ID3D12Resource_Unmap(
        format::HandleId object_id,
        UINT Subresource,
        StructPointerDecoder<Decoded_D3D12_RANGE>* pWrittenRange);

    virtual void Process_ID3D12Resource_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC returnValue);

    virtual void Process_ID3D12Resource_GetGPUVirtualAddress(
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS returnValue);

    virtual void Process_ID3D12Resource_WriteToSubresource(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT DstSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
        uint64_t pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch);

    virtual void Process_ID3D12Resource_ReadFromSubresource(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox);

    virtual void Process_ID3D12Resource_GetHeapProperties(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        PointerDecoder<D3D12_HEAP_FLAGS>* pHeapFlags);

    virtual void Process_ID3D12CommandAllocator_Reset(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_ID3D12Fence_GetCompletedValue(
        format::HandleId object_id,
        UINT64 returnValue);

    virtual void Process_ID3D12Fence_SetEventOnCompletion(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Value,
        format::HandleId hEvent);

    virtual void Process_ID3D12Fence_Signal(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 Value);

    virtual void Process_ID3D12Fence1_GetCreationFlags(
        format::HandleId object_id,
        D3D12_FENCE_FLAGS returnValue);

    virtual void Process_ID3D12PipelineState_GetCachedBlob(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D10Blob*>* ppBlob);

    virtual void Process_ID3D12DescriptorHeap_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_DESCRIPTOR_HEAP_DESC returnValue);

    virtual void Process_ID3D12DescriptorHeap_GetCPUDescriptorHandleForHeapStart(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE returnValue);

    virtual void Process_ID3D12DescriptorHeap_GetGPUDescriptorHandleForHeapStart(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE returnValue);

    virtual void Process_ID3D12CommandList_GetType(
        format::HandleId object_id,
        D3D12_COMMAND_LIST_TYPE returnValue);

    virtual void Process_ID3D12GraphicsCommandList_Close(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_ID3D12GraphicsCommandList_Reset(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12CommandAllocator*>* pAllocator,
        HandlePointerDecoder<ID3D12PipelineState*>* pInitialState);

    virtual void Process_ID3D12GraphicsCommandList_ClearState(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12PipelineState*>* pPipelineState);

    virtual void Process_ID3D12GraphicsCommandList_DrawInstanced(
        format::HandleId object_id,
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation);

    virtual void Process_ID3D12GraphicsCommandList_DrawIndexedInstanced(
        format::HandleId object_id,
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation);

    virtual void Process_ID3D12GraphicsCommandList_Dispatch(
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ);

    virtual void Process_ID3D12GraphicsCommandList_CopyBufferRegion(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pDstBuffer,
        UINT64 DstOffset,
        HandlePointerDecoder<ID3D12Resource*>* pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes);

    virtual void Process_ID3D12GraphicsCommandList_CopyTextureRegion(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pDst,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        StructPointerDecoder<Decoded_D3D12_TEXTURE_COPY_LOCATION>* pSrc,
        StructPointerDecoder<Decoded_D3D12_BOX>* pSrcBox);

    virtual void Process_ID3D12GraphicsCommandList_CopyResource(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pDstResource,
        HandlePointerDecoder<ID3D12Resource*>* pSrcResource);

    virtual void Process_ID3D12GraphicsCommandList_CopyTiles(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pTiledResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pTileRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pTileRegionSize,
        HandlePointerDecoder<ID3D12Resource*>* pBuffer,
        UINT64 BufferStartOffsetInBytes,
        D3D12_TILE_COPY_FLAGS Flags);

    virtual void Process_ID3D12GraphicsCommandList_ResolveSubresource(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pDstResource,
        UINT DstSubresource,
        HandlePointerDecoder<ID3D12Resource*>* pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format);

    virtual void Process_ID3D12GraphicsCommandList_IASetPrimitiveTopology(
        format::HandleId object_id,
        D3D_PRIMITIVE_TOPOLOGY PrimitiveTopology);

    virtual void Process_ID3D12GraphicsCommandList_RSSetViewports(
        format::HandleId object_id,
        UINT NumViewports,
        StructPointerDecoder<Decoded_D3D12_VIEWPORT>* pViewports);

    virtual void Process_ID3D12GraphicsCommandList_RSSetScissorRects(
        format::HandleId object_id,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects);

    virtual void Process_ID3D12GraphicsCommandList_OMSetBlendFactor(
        format::HandleId object_id,
        PointerDecoder<FLOAT> BlendFactor [4]);

    virtual void Process_ID3D12GraphicsCommandList_OMSetStencilRef(
        format::HandleId object_id,
        UINT StencilRef);

    virtual void Process_ID3D12GraphicsCommandList_SetPipelineState(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12PipelineState*>* pPipelineState);

    virtual void Process_ID3D12GraphicsCommandList_ResourceBarrier(
        format::HandleId object_id,
        UINT NumBarriers,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_BARRIER>* pBarriers);

    virtual void Process_ID3D12GraphicsCommandList_ExecuteBundle(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12GraphicsCommandList*>* pCommandList);

    virtual void Process_ID3D12GraphicsCommandList_SetDescriptorHeaps(
        format::HandleId object_id,
        UINT NumDescriptorHeaps,
        HandlePointerDecoder<ID3D12DescriptorHeap*>* ppDescriptorHeaps);

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootSignature(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12RootSignature*>* pRootSignature);

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootSignature(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12RootSignature*>* pRootSignature);

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootDescriptorTable(
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootDescriptorTable(
        format::HandleId object_id,
        UINT RootParameterIndex,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstant(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues);

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstant(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues);

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRoot32BitConstants(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues);

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRoot32BitConstants(
        format::HandleId object_id,
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        PointerDecoder<uint8_t>* pSrcData,
        UINT DestOffsetIn32BitValues);

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootConstantBufferView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootConstantBufferView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootShaderResourceView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootShaderResourceView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void Process_ID3D12GraphicsCommandList_SetComputeRootUnorderedAccessView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void Process_ID3D12GraphicsCommandList_SetGraphicsRootUnorderedAccessView(
        format::HandleId object_id,
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void Process_ID3D12GraphicsCommandList_IASetIndexBuffer(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_INDEX_BUFFER_VIEW>* pView);

    virtual void Process_ID3D12GraphicsCommandList_IASetVertexBuffers(
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_VERTEX_BUFFER_VIEW>* pViews);

    virtual void Process_ID3D12GraphicsCommandList_SOSetTargets(
        format::HandleId object_id,
        UINT StartSlot,
        UINT NumViews,
        StructPointerDecoder<Decoded_D3D12_STREAM_OUTPUT_BUFFER_VIEW>* pViews);

    virtual void Process_ID3D12GraphicsCommandList_OMSetRenderTargets(
        format::HandleId object_id,
        UINT NumRenderTargetDescriptors,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDepthStencilDescriptor);

    virtual void Process_ID3D12GraphicsCommandList_ClearDepthStencilView(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
        D3D12_CLEAR_FLAGS ClearFlags,
        FLOAT Depth,
        UINT8 Stencil,
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects);

    virtual void Process_ID3D12GraphicsCommandList_ClearRenderTargetView(
        format::HandleId object_id,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        PointerDecoder<FLOAT> ColorRGBA [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects);

    virtual void Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewUint(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        PointerDecoder<UINT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects);

    virtual void Process_ID3D12GraphicsCommandList_ClearUnorderedAccessViewFloat(
        format::HandleId object_id,
        Decoded_D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        PointerDecoder<FLOAT> Values [4],
        UINT NumRects,
        StructPointerDecoder<Decoded_tagRECT>* pRects);

    virtual void Process_ID3D12GraphicsCommandList_DiscardResource(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        StructPointerDecoder<Decoded_D3D12_DISCARD_REGION>* pRegion);

    virtual void Process_ID3D12GraphicsCommandList_BeginQuery(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12QueryHeap*>* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index);

    virtual void Process_ID3D12GraphicsCommandList_EndQuery(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12QueryHeap*>* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index);

    virtual void Process_ID3D12GraphicsCommandList_ResolveQueryData(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12QueryHeap*>* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT StartIndex,
        UINT NumQueries,
        HandlePointerDecoder<ID3D12Resource*>* pDestinationBuffer,
        UINT64 AlignedDestinationBufferOffset);

    virtual void Process_ID3D12GraphicsCommandList_SetPredication(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation);

    virtual void Process_ID3D12GraphicsCommandList_SetMarker(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size);

    virtual void Process_ID3D12GraphicsCommandList_BeginEvent(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size);

    virtual void Process_ID3D12GraphicsCommandList_EndEvent(
        format::HandleId object_id);

    virtual void Process_ID3D12GraphicsCommandList_ExecuteIndirect(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12CommandSignature*>* pCommandSignature,
        UINT MaxCommandCount,
        HandlePointerDecoder<ID3D12Resource*>* pArgumentBuffer,
        UINT64 ArgumentBufferOffset,
        HandlePointerDecoder<ID3D12Resource*>* pCountBuffer,
        UINT64 CountBufferOffset);

    virtual void Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pDstBuffer,
        UINT64 DstOffset,
        HandlePointerDecoder<ID3D12Resource*>* pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        HandlePointerDecoder<ID3D12Resource*>* ppDependentResources,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges);

    virtual void Process_ID3D12GraphicsCommandList1_AtomicCopyBufferUINT64(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pDstBuffer,
        UINT64 DstOffset,
        HandlePointerDecoder<ID3D12Resource*>* pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        HandlePointerDecoder<ID3D12Resource*>* ppDependentResources,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_RANGE_UINT64>* pDependentSubresourceRanges);

    virtual void Process_ID3D12GraphicsCommandList1_OMSetDepthBounds(
        format::HandleId object_id,
        FLOAT Min,
        FLOAT Max);

    virtual void Process_ID3D12GraphicsCommandList1_SetSamplePositions(
        format::HandleId object_id,
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        StructPointerDecoder<Decoded_D3D12_SAMPLE_POSITION>* pSamplePositions);

    virtual void Process_ID3D12GraphicsCommandList1_ResolveSubresourceRegion(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pDstResource,
        UINT DstSubresource,
        UINT DstX,
        UINT DstY,
        HandlePointerDecoder<ID3D12Resource*>* pSrcResource,
        UINT SrcSubresource,
        StructPointerDecoder<Decoded_tagRECT>* pSrcRect,
        DXGI_FORMAT Format,
        D3D12_RESOLVE_MODE ResolveMode);

    virtual void Process_ID3D12GraphicsCommandList1_SetViewInstanceMask(
        format::HandleId object_id,
        UINT Mask);

    virtual void Process_ID3D12GraphicsCommandList2_WriteBufferImmediate(
        format::HandleId object_id,
        UINT Count,
        StructPointerDecoder<Decoded_D3D12_WRITEBUFFERIMMEDIATE_PARAMETER>* pParams,
        PointerDecoder<D3D12_WRITEBUFFERIMMEDIATE_MODE>* pModes);

    virtual void Process_ID3D12CommandQueue_UpdateTileMappings(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        UINT NumResourceRegions,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pResourceRegionStartCoordinates,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pResourceRegionSizes,
        HandlePointerDecoder<ID3D12Heap*>* pHeap,
        UINT NumRanges,
        PointerDecoder<D3D12_TILE_RANGE_FLAGS>* pRangeFlags,
        PointerDecoder<UINT>* pHeapRangeStartOffsets,
        PointerDecoder<UINT>* pRangeTileCounts,
        D3D12_TILE_MAPPING_FLAGS Flags);

    virtual void Process_ID3D12CommandQueue_CopyTileMappings(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pDstResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pDstRegionStartCoordinate,
        HandlePointerDecoder<ID3D12Resource*>* pSrcResource,
        StructPointerDecoder<Decoded_D3D12_TILED_RESOURCE_COORDINATE>* pSrcRegionStartCoordinate,
        StructPointerDecoder<Decoded_D3D12_TILE_REGION_SIZE>* pRegionSize,
        D3D12_TILE_MAPPING_FLAGS Flags);

    virtual void Process_ID3D12CommandQueue_ExecuteCommandLists(
        format::HandleId object_id,
        UINT NumCommandLists,
        HandlePointerDecoder<ID3D12CommandList*>* ppCommandLists);

    virtual void Process_ID3D12CommandQueue_SetMarker(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size);

    virtual void Process_ID3D12CommandQueue_BeginEvent(
        format::HandleId object_id,
        UINT Metadata,
        PointerDecoder<uint8_t>* pData,
        UINT Size);

    virtual void Process_ID3D12CommandQueue_EndEvent(
        format::HandleId object_id);

    virtual void Process_ID3D12CommandQueue_Signal(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12Fence*>* pFence,
        UINT64 Value);

    virtual void Process_ID3D12CommandQueue_Wait(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12Fence*>* pFence,
        UINT64 Value);

    virtual void Process_ID3D12CommandQueue_GetTimestampFrequency(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT64>* pFrequency);

    virtual void Process_ID3D12CommandQueue_GetClockCalibration(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT64>* pGpuTimestamp,
        PointerDecoder<UINT64>* pCpuTimestamp);

    virtual void Process_ID3D12CommandQueue_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_COMMAND_QUEUE_DESC returnValue);

    virtual void Process_ID3D12Device_GetNodeCount(
        format::HandleId object_id,
        UINT returnValue);

    virtual void Process_ID3D12Device_CreateCommandQueue(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_COMMAND_QUEUE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandQueue);

    virtual void Process_ID3D12Device_CreateCommandAllocator(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_COMMAND_LIST_TYPE type,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandAllocator);

    virtual void Process_ID3D12Device_CreateGraphicsPipelineState(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState);

    virtual void Process_ID3D12Device_CreateComputePipelineState(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState);

    virtual void Process_ID3D12Device_CreateCommandList(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        HandlePointerDecoder<ID3D12CommandAllocator*>* pCommandAllocator,
        HandlePointerDecoder<ID3D12PipelineState*>* pInitialState,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList);

    virtual void Process_ID3D12Device_CheckFeatureSupport(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_FEATURE Feature,
        PointerDecoder<uint8_t>* pFeatureSupportData,
        UINT FeatureSupportDataSize);

    virtual void Process_ID3D12Device_CreateDescriptorHeap(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DESCRIPTOR_HEAP_DESC>* pDescriptorHeapDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap);

    virtual void Process_ID3D12Device_GetDescriptorHandleIncrementSize(
        format::HandleId object_id,
        UINT returnValue,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType);

    virtual void Process_ID3D12Device_CreateRootSignature(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT nodeMask,
        PointerDecoder<uint8_t>* pBlobWithRootSignature,
        SIZE_T blobLengthInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvRootSignature);

    virtual void Process_ID3D12Device_CreateConstantBufferView(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_CONSTANT_BUFFER_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void Process_ID3D12Device_CreateShaderResourceView(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        StructPointerDecoder<Decoded_D3D12_SHADER_RESOURCE_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void Process_ID3D12Device_CreateUnorderedAccessView(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        HandlePointerDecoder<ID3D12Resource*>* pCounterResource,
        StructPointerDecoder<Decoded_D3D12_UNORDERED_ACCESS_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void Process_ID3D12Device_CreateRenderTargetView(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        StructPointerDecoder<Decoded_D3D12_RENDER_TARGET_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void Process_ID3D12Device_CreateDepthStencilView(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pResource,
        StructPointerDecoder<Decoded_D3D12_DEPTH_STENCIL_VIEW_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void Process_ID3D12Device_CreateSampler(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_SAMPLER_DESC>* pDesc,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void Process_ID3D12Device_CopyDescriptors(
        format::HandleId object_id,
        UINT NumDestDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pDestDescriptorRangeStarts,
        PointerDecoder<UINT>* pDestDescriptorRangeSizes,
        UINT NumSrcDescriptorRanges,
        StructPointerDecoder<Decoded_D3D12_CPU_DESCRIPTOR_HANDLE>* pSrcDescriptorRangeStarts,
        PointerDecoder<UINT>* pSrcDescriptorRangeSizes,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

    virtual void Process_ID3D12Device_CopyDescriptorsSimple(
        format::HandleId object_id,
        UINT NumDescriptors,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

    virtual void Process_ID3D12Device_GetResourceAllocationInfo(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO returnValue,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs);

    virtual void Process_ID3D12Device_GetCustomHeapProperties(
        format::HandleId object_id,
        Decoded_D3D12_HEAP_PROPERTIES returnValue,
        UINT nodeMask,
        D3D12_HEAP_TYPE heapType);

    virtual void Process_ID3D12Device_CreateCommittedResource(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource);

    virtual void Process_ID3D12Device_CreateHeap(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap);

    virtual void Process_ID3D12Device_CreatePlacedResource(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12Heap*>* pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource);

    virtual void Process_ID3D12Device_CreateReservedResource(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource);

    virtual void Process_ID3D12Device_CreateSharedHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12DeviceChild*>* pObject,
        StructPointerDecoder<Decoded__SECURITY_ATTRIBUTES>* pAttributes,
        DWORD Access,
        WStringDecoder* Name,
        HandlePointerDecoder<HANDLE>* pHandle);

    virtual void Process_ID3D12Device_OpenSharedHandle(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId NTHandle,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObj);

    virtual void Process_ID3D12Device_OpenSharedHandleByName(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* Name,
        DWORD Access,
        HandlePointerDecoder<HANDLE>* pNTHandle);

    virtual void Process_ID3D12Device_MakeResident(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects);

    virtual void Process_ID3D12Device_Evict(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects);

    virtual void Process_ID3D12Device_CreateFence(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence);

    virtual void Process_ID3D12Device_GetDeviceRemovedReason(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_ID3D12Device_GetCopyableFootprints(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
        PointerDecoder<UINT>* pNumRows,
        PointerDecoder<UINT64>* pRowSizeInBytes,
        PointerDecoder<UINT64>* pTotalBytes);

    virtual void Process_ID3D12Device_CreateQueryHeap(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_QUERY_HEAP_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap);

    virtual void Process_ID3D12Device_SetStablePowerState(
        format::HandleId object_id,
        HRESULT returnValue,
        BOOL Enable);

    virtual void Process_ID3D12Device_CreateCommandSignature(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_COMMAND_SIGNATURE_DESC>* pDesc,
        HandlePointerDecoder<ID3D12RootSignature*>* pRootSignature,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvCommandSignature);

    virtual void Process_ID3D12Device_GetResourceTiling(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pTiledResource,
        PointerDecoder<UINT>* pNumTilesForEntireResource,
        StructPointerDecoder<Decoded_D3D12_PACKED_MIP_INFO>* pPackedMipDesc,
        StructPointerDecoder<Decoded_D3D12_TILE_SHAPE>* pStandardTileShapeForNonPackedMips,
        PointerDecoder<UINT>* pNumSubresourceTilings,
        UINT FirstSubresourceTilingToGet,
        StructPointerDecoder<Decoded_D3D12_SUBRESOURCE_TILING>* pSubresourceTilingsForNonPackedMips);

    virtual void Process_ID3D12Device_GetAdapterLuid(
        format::HandleId object_id,
        Decoded_LUID returnValue);

    virtual void Process_ID3D12PipelineLibrary_StorePipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        HandlePointerDecoder<ID3D12PipelineState*>* pPipeline);

    virtual void Process_ID3D12PipelineLibrary_LoadGraphicsPipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_GRAPHICS_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState);

    virtual void Process_ID3D12PipelineLibrary_LoadComputePipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_COMPUTE_PIPELINE_STATE_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState);

    virtual void Process_ID3D12PipelineLibrary_GetSerializedSize(
        format::HandleId object_id,
        SIZE_T returnValue);

    virtual void Process_ID3D12PipelineLibrary_Serialize(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pData,
        SIZE_T DataSizeInBytes);

    virtual void Process_ID3D12PipelineLibrary1_LoadPipeline(
        format::HandleId object_id,
        HRESULT returnValue,
        WStringDecoder* pName,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState);

    virtual void Process_ID3D12Device1_CreatePipelineLibrary(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<uint8_t>* pLibraryBlob,
        SIZE_T BlobLength,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineLibrary);

    virtual void Process_ID3D12Device1_SetEventOnMultipleFenceCompletion(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12Fence*>* ppFences,
        PointerDecoder<UINT64>* pFenceValues,
        UINT NumFences,
        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
        format::HandleId hEvent);

    virtual void Process_ID3D12Device1_SetResidencyPriority(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        PointerDecoder<D3D12_RESIDENCY_PRIORITY>* pPriorities);

    virtual void Process_ID3D12Device2_CreatePipelineState(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_PIPELINE_STATE_STREAM_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppPipelineState);

    virtual void Process_ID3D12Device3_OpenExistingHeapFromAddress(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t pAddress,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap);

    virtual void Process_ID3D12Device3_OpenExistingHeapFromFileMapping(
        format::HandleId object_id,
        HRESULT returnValue,
        format::HandleId hFileMapping,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap);

    virtual void Process_ID3D12Device3_EnqueueMakeResident(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_RESIDENCY_FLAGS Flags,
        UINT NumObjects,
        HandlePointerDecoder<ID3D12Pageable*>* ppObjects,
        HandlePointerDecoder<ID3D12Fence*>* pFenceToSignal,
        UINT64 FenceValueToSignal);

    virtual void Process_ID3D12ProtectedSession_GetStatusFence(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppFence);

    virtual void Process_ID3D12ProtectedSession_GetSessionStatus(
        format::HandleId object_id,
        D3D12_PROTECTED_SESSION_STATUS returnValue);

    virtual void Process_ID3D12ProtectedResourceSession_GetDesc(
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC returnValue);

    virtual void Process_ID3D12Device4_CreateCommandList1(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        D3D12_COMMAND_LIST_FLAGS flags,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppCommandList);

    virtual void Process_ID3D12Device4_CreateProtectedResourceSession(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession);

    virtual void Process_ID3D12Device4_CreateCommittedResource1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource);

    virtual void Process_ID3D12Device4_CreateHeap1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_DESC>* pDesc,
        HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvHeap);

    virtual void Process_ID3D12Device4_CreateReservedResource1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource);

    virtual void Process_ID3D12Device4_GetResourceAllocationInfo1(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO returnValue,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1);

    virtual void Process_ID3D12LifetimeOwner_LifetimeStateUpdated(
        format::HandleId object_id,
        D3D12_LIFETIME_STATE NewState);

    virtual void Process_ID3D12SwapChainAssistant_GetLUID(
        format::HandleId object_id,
        Decoded_LUID returnValue);

    virtual void Process_ID3D12SwapChainAssistant_GetSwapChainObject(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppv);

    virtual void Process_ID3D12SwapChainAssistant_GetCurrentResourceAndCommandQueue(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource,
        Decoded_GUID riidQueue,
        HandlePointerDecoder<void*>* ppvQueue);

    virtual void Process_ID3D12SwapChainAssistant_InsertImplicitSync(
        format::HandleId object_id,
        HRESULT returnValue);

    virtual void Process_ID3D12LifetimeTracker_DestroyOwnedObject(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12DeviceChild*>* pObject);

    virtual void Process_ID3D12StateObjectProperties_GetShaderIdentifier(
        format::HandleId object_id,
        uint64_t returnValue,
        WStringDecoder* pExportName);

    virtual void Process_ID3D12StateObjectProperties_GetShaderStackSize(
        format::HandleId object_id,
        UINT64 returnValue,
        WStringDecoder* pExportName);

    virtual void Process_ID3D12StateObjectProperties_GetPipelineStackSize(
        format::HandleId object_id,
        UINT64 returnValue);

    virtual void Process_ID3D12StateObjectProperties_SetPipelineStackSize(
        format::HandleId object_id,
        UINT64 PipelineStackSizeInBytes);

    virtual void Process_ID3D12Device5_CreateLifetimeTracker(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12LifetimeOwner*>* pOwner,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvTracker);

    virtual void Process_ID3D12Device5_RemoveDevice(
        format::HandleId object_id);

    virtual void Process_ID3D12Device5_EnumerateMetaCommands(
        format::HandleId object_id,
        HRESULT returnValue,
        PointerDecoder<UINT>* pNumMetaCommands,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_DESC>* pDescs);

    virtual void Process_ID3D12Device5_EnumerateMetaCommandParameters(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID CommandId,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        PointerDecoder<UINT>* pTotalStructureSizeInBytes,
        PointerDecoder<UINT>* pParameterCount,
        StructPointerDecoder<Decoded_D3D12_META_COMMAND_PARAMETER_DESC>* pParameterDescs);

    virtual void Process_ID3D12Device5_CreateMetaCommand(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID CommandId,
        UINT NodeMask,
        PointerDecoder<uint8_t>* pCreationParametersData,
        SIZE_T CreationParametersDataSizeInBytes,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppMetaCommand);

    virtual void Process_ID3D12Device5_CreateStateObject(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppStateObject);

    virtual void Process_ID3D12Device5_GetRaytracingAccelerationStructurePrebuildInfo(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS>* pDesc,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO>* pInfo);

    virtual void Process_ID3D12Device5_CheckDriverMatchingIdentifier(
        format::HandleId object_id,
        D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS returnValue,
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        StructPointerDecoder<Decoded_D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER>* pIdentifierToCheck);

    virtual void Process_ID3D12DeviceRemovedExtendedDataSettings_SetAutoBreadcrumbsEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void Process_ID3D12DeviceRemovedExtendedDataSettings_SetPageFaultEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void Process_ID3D12DeviceRemovedExtendedDataSettings_SetWatsonDumpEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void Process_ID3D12DeviceRemovedExtendedDataSettings1_SetBreadcrumbContextEnablement(
        format::HandleId object_id,
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void Process_ID3D12DeviceRemovedExtendedData_GetAutoBreadcrumbsOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT>* pOutput);

    virtual void Process_ID3D12DeviceRemovedExtendedData_GetPageFaultAllocationOutput(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT>* pOutput);

    virtual void Process_ID3D12DeviceRemovedExtendedData1_GetAutoBreadcrumbsOutput1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1>* pOutput);

    virtual void Process_ID3D12DeviceRemovedExtendedData1_GetPageFaultAllocationOutput1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_DRED_PAGE_FAULT_OUTPUT1>* pOutput);

    virtual void Process_ID3D12Device6_SetBackgroundProcessingMode(
        format::HandleId object_id,
        HRESULT returnValue,
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        format::HandleId hEventToSignalUponCompletion,
        PointerDecoder<BOOL>* pbFurtherMeasurementsDesired);

    virtual void Process_ID3D12ProtectedResourceSession1_GetDesc1(
        format::HandleId object_id,
        Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1 returnValue);

    virtual void Process_ID3D12Device7_AddToStateObject(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_STATE_OBJECT_DESC>* pAddition,
        HandlePointerDecoder<ID3D12StateObject*>* pStateObjectToGrowFrom,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppNewStateObject);

    virtual void Process_ID3D12Device7_CreateProtectedResourceSession1(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_PROTECTED_RESOURCE_SESSION_DESC1>* pDesc,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppSession);

    virtual void Process_ID3D12Device8_GetResourceAllocationInfo2(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_ALLOCATION_INFO returnValue,
        UINT visibleMask,
        UINT numResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDescs,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_ALLOCATION_INFO1>* pResourceAllocationInfo1);

    virtual void Process_ID3D12Device8_CreateCommittedResource2(
        format::HandleId object_id,
        HRESULT returnValue,
        StructPointerDecoder<Decoded_D3D12_HEAP_PROPERTIES>* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedSession,
        Decoded_GUID riidResource,
        HandlePointerDecoder<void*>* ppvResource);

    virtual void Process_ID3D12Device8_CreatePlacedResource1(
        format::HandleId object_id,
        HRESULT returnValue,
        HandlePointerDecoder<ID3D12Heap*>* pHeap,
        UINT64 HeapOffset,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        StructPointerDecoder<Decoded_D3D12_CLEAR_VALUE>* pOptimizedClearValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvResource);

    virtual void Process_ID3D12Device8_CreateSamplerFeedbackUnorderedAccessView(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* pTargetedResource,
        HandlePointerDecoder<ID3D12Resource*>* pFeedbackResource,
        Decoded_D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void Process_ID3D12Device8_GetCopyableFootprints1(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RESOURCE_DESC1>* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        StructPointerDecoder<Decoded_D3D12_PLACED_SUBRESOURCE_FOOTPRINT>* pLayouts,
        PointerDecoder<UINT>* pNumRows,
        PointerDecoder<UINT64>* pRowSizeInBytes,
        PointerDecoder<UINT64>* pTotalBytes);

    virtual void Process_ID3D12Resource1_GetProtectedResourceSession(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession);

    virtual void Process_ID3D12Resource2_GetDesc1(
        format::HandleId object_id,
        Decoded_D3D12_RESOURCE_DESC1 returnValue);

    virtual void Process_ID3D12Heap1_GetProtectedResourceSession(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppProtectedSession);

    virtual void Process_ID3D12GraphicsCommandList3_SetProtectedResourceSession(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12ProtectedResourceSession*>* pProtectedResourceSession);

    virtual void Process_ID3D12MetaCommand_GetRequiredParameterResourceSize(
        format::HandleId object_id,
        UINT64 returnValue,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex);

    virtual void Process_ID3D12GraphicsCommandList4_BeginRenderPass(
        format::HandleId object_id,
        UINT NumRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_RENDER_TARGET_DESC>* pRenderTargets,
        StructPointerDecoder<Decoded_D3D12_RENDER_PASS_DEPTH_STENCIL_DESC>* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags);

    virtual void Process_ID3D12GraphicsCommandList4_EndRenderPass(
        format::HandleId object_id);

    virtual void Process_ID3D12GraphicsCommandList4_InitializeMetaCommand(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12MetaCommand*>* pMetaCommand,
        PointerDecoder<uint8_t>* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes);

    virtual void Process_ID3D12GraphicsCommandList4_ExecuteMetaCommand(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12MetaCommand*>* pMetaCommand,
        PointerDecoder<uint8_t>* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes);

    virtual void Process_ID3D12GraphicsCommandList4_BuildRaytracingAccelerationStructure(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC>* pDesc,
        UINT NumPostbuildInfoDescs,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pPostbuildInfoDescs);

    virtual void Process_ID3D12GraphicsCommandList4_EmitRaytracingAccelerationStructurePostbuildInfo(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC>* pDesc,
        UINT NumSourceAccelerationStructures,
        PointerDecoder<D3D12_GPU_VIRTUAL_ADDRESS>* pSourceAccelerationStructureData);

    virtual void Process_ID3D12GraphicsCommandList4_CopyRaytracingAccelerationStructure(
        format::HandleId object_id,
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode);

    virtual void Process_ID3D12GraphicsCommandList4_SetPipelineState1(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12StateObject*>* pStateObject);

    virtual void Process_ID3D12GraphicsCommandList4_DispatchRays(
        format::HandleId object_id,
        StructPointerDecoder<Decoded_D3D12_DISPATCH_RAYS_DESC>* pDesc);

    virtual void Process_ID3D12Tools_EnableShaderInstrumentation(
        format::HandleId object_id,
        BOOL bEnable);

    virtual void Process_ID3D12Tools_ShaderInstrumentationEnabled(
        format::HandleId object_id,
        BOOL returnValue);

    virtual void Process_ID3D12GraphicsCommandList5_RSSetShadingRate(
        format::HandleId object_id,
        D3D12_SHADING_RATE baseShadingRate,
        PointerDecoder<D3D12_SHADING_RATE_COMBINER>* combiners);

    virtual void Process_ID3D12GraphicsCommandList5_RSSetShadingRateImage(
        format::HandleId object_id,
        HandlePointerDecoder<ID3D12Resource*>* shadingRateImage);

    virtual void Process_ID3D12GraphicsCommandList6_DispatchMesh(
        format::HandleId object_id,
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ);

/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_ID3D10Blob_GetBufferPointer(
        format::HandleId object_id,
        uint64_t returnValue);

    virtual void Process_ID3D10Blob_GetBufferSize(
        format::HandleId object_id,
        SIZE_T returnValue);

    virtual void Process_ID3DDestructionNotifier_RegisterDestructionCallback(
        format::HandleId object_id,
        HRESULT returnValue,
        uint64_t callbackFn,
        uint64_t pData,
        PointerDecoder<UINT>* pCallbackID);

    virtual void Process_ID3DDestructionNotifier_UnregisterDestructionCallback(
        format::HandleId object_id,
        HRESULT returnValue,
        UINT callbackID);

/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.19041.0
**
*/
    virtual void Process_IUnknown_QueryInterface(
        format::HandleId object_id,
        HRESULT returnValue,
        Decoded_GUID riid,
        HandlePointerDecoder<void*>* ppvObject);

    virtual void Process_IUnknown_AddRef(
        format::HandleId object_id,
        ULONG returnValue);

    virtual void Process_IUnknown_Release(
        format::HandleId object_id,
        ULONG returnValue);

};


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
