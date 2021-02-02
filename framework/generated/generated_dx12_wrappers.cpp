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
** This file is generated from dx12_wrapper_body_generator.py.
**
*/

#include "generated/generated_dx12_wrappers.h"

#include "encode/d3d12_dispatch_table.h"
#include "encode/dxgi_dispatch_table.h"
#include "encode/trace_manager.h"
#include "generated/generated_dx12_wrapper_creators.h"
#include "util/defines.h"

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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

/*
** This part is generated from dxgi.h in Windows SDK: 10.0.19041.0
**
*/

HRESULT WINAPI CreateDXGIFactory(
    REFIID riid,
    void** ppFactory)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory(
        riid,
        ppFactory);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppFactory, nullptr);
    }

    return result;
}

HRESULT WINAPI CreateDXGIFactory1(
    REFIID riid,
    void** ppFactory)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory1(
        riid,
        ppFactory);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppFactory, nullptr);
    }

    return result;
}

IDXGIObject_Wrapper::IDXGIObject_Wrapper(REFIID riid, IDXGIObject* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIObject_Wrapper::SetPrivateData(
    REFGUID Name,
    UINT DataSize,
    const void* pData)
{
    auto result = object_->SetPrivateData(
        Name,
        DataSize,
        pData);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIObject_Wrapper::SetPrivateDataInterface(
    REFGUID Name,
    const IUnknown* pUnknown)
{
    auto result = object_->SetPrivateDataInterface(
        Name,
        pUnknown);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIObject_Wrapper::GetPrivateData(
    REFGUID Name,
    UINT* pDataSize,
    void* pData)
{
    auto result = object_->GetPrivateData(
        Name,
        pDataSize,
        pData);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIObject_Wrapper::GetParent(
    REFIID riid,
    void** ppParent)
{
    auto result = object_->GetParent(
        riid,
        ppParent);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppParent, nullptr);
    }

    return result;
}

IDXGIDeviceSubObject_Wrapper::IDXGIDeviceSubObject_Wrapper(REFIID riid, IDXGIDeviceSubObject* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDeviceSubObject_Wrapper::GetDevice(
    REFIID riid,
    void** ppDevice)
{
    auto result = object_->GetDevice(
        riid,
        ppDevice);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppDevice, nullptr);
    }

    return result;
}

IDXGIResource_Wrapper::IDXGIResource_Wrapper(REFIID riid, IDXGIResource* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::GetSharedHandle(
    HANDLE* pSharedHandle)
{
    auto result = object_->GetSharedHandle(
        pSharedHandle);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::GetUsage(
    DXGI_USAGE* pUsage)
{
    auto result = object_->GetUsage(
        pUsage);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::SetEvictionPriority(
    UINT EvictionPriority)
{
    auto result = object_->SetEvictionPriority(
        EvictionPriority);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::GetEvictionPriority(
    UINT* pEvictionPriority)
{
    auto result = object_->GetEvictionPriority(
        pEvictionPriority);

    return result;
}

IDXGIKeyedMutex_Wrapper::IDXGIKeyedMutex_Wrapper(REFIID riid, IDXGIKeyedMutex* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIKeyedMutex_Wrapper::AcquireSync(
    UINT64 Key,
    DWORD dwMilliseconds)
{
    auto result = object_->AcquireSync(
        Key,
        dwMilliseconds);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIKeyedMutex_Wrapper::ReleaseSync(
    UINT64 Key)
{
    auto result = object_->ReleaseSync(
        Key);

    return result;
}

IDXGISurface_Wrapper::IDXGISurface_Wrapper(REFIID riid, IDXGISurface* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISurface_Wrapper::GetDesc(
    DXGI_SURFACE_DESC* pDesc)
{
    auto result = object_->GetDesc(
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISurface_Wrapper::Map(
    DXGI_MAPPED_RECT* pLockedRect,
    UINT MapFlags)
{
    auto result = object_->Map(
        pLockedRect,
        MapFlags);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISurface_Wrapper::Unmap()
{
    auto result = object_->Unmap();

    return result;
}

IDXGISurface1_Wrapper::IDXGISurface1_Wrapper(REFIID riid, IDXGISurface1* object, DxWrapperResources* resources) : IDXGISurface_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISurface1_Wrapper::GetDC(
    BOOL Discard,
    HDC* phdc)
{
    auto result = object_->GetDC(
        Discard,
        phdc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISurface1_Wrapper::ReleaseDC(
    RECT* pDirtyRect)
{
    auto result = object_->ReleaseDC(
        pDirtyRect);

    return result;
}

IDXGIAdapter_Wrapper::IDXGIAdapter_Wrapper(REFIID riid, IDXGIAdapter* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter_Wrapper::EnumOutputs(
    UINT Output,
    IDXGIOutput** ppOutput)
{
    auto result = object_->EnumOutputs(
        Output,
        ppOutput);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppOutput), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter_Wrapper::GetDesc(
    DXGI_ADAPTER_DESC* pDesc)
{
    auto result = object_->GetDesc(
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter_Wrapper::CheckInterfaceSupport(
    REFGUID InterfaceName,
    LARGE_INTEGER* pUMDVersion)
{
    auto result = object_->CheckInterfaceSupport(
        InterfaceName,
        pUMDVersion);

    return result;
}

IDXGIOutput_Wrapper::IDXGIOutput_Wrapper(REFIID riid, IDXGIOutput* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetDesc(
    DXGI_OUTPUT_DESC* pDesc)
{
    auto result = object_->GetDesc(
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetDisplayModeList(
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC* pDesc)
{
    auto result = object_->GetDisplayModeList(
        EnumFormat,
        Flags,
        pNumModes,
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::FindClosestMatchingMode(
    const DXGI_MODE_DESC* pModeToMatch,
    DXGI_MODE_DESC* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    auto result = object_->FindClosestMatchingMode(
        pModeToMatch,
        pClosestMatch,
        pConcernedDevice);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::WaitForVBlank()
{
    auto result = object_->WaitForVBlank();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::TakeOwnership(
    IUnknown* pDevice,
    BOOL Exclusive)
{
    auto result = object_->TakeOwnership(
        pDevice,
        Exclusive);

    return result;
}

void STDMETHODCALLTYPE IDXGIOutput_Wrapper::ReleaseOwnership()
{
    object_->ReleaseOwnership();
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetGammaControlCapabilities(
    DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps)
{
    auto result = object_->GetGammaControlCapabilities(
        pGammaCaps);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::SetGammaControl(
    const DXGI_GAMMA_CONTROL* pArray)
{
    auto result = object_->SetGammaControl(
        pArray);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetGammaControl(
    DXGI_GAMMA_CONTROL* pArray)
{
    auto result = object_->GetGammaControl(
        pArray);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::SetDisplaySurface(
    IDXGISurface* pScanoutSurface)
{
    auto result = object_->SetDisplaySurface(
        pScanoutSurface);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetDisplaySurfaceData(
    IDXGISurface* pDestination)
{
    auto result = object_->GetDisplaySurfaceData(
        pDestination);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetFrameStatistics(
    DXGI_FRAME_STATISTICS* pStats)
{
    auto result = object_->GetFrameStatistics(
        pStats);

    return result;
}

IDXGISwapChain_Wrapper::IDXGISwapChain_Wrapper(REFIID riid, IDXGISwapChain* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::Present(
    UINT SyncInterval,
    UINT Flags)
{
    auto result = object_->Present(
        SyncInterval,
        Flags);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetBuffer(
    UINT Buffer,
    REFIID riid,
    void** ppSurface)
{
    auto result = object_->GetBuffer(
        Buffer,
        riid,
        ppSurface);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppSurface, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::SetFullscreenState(
    BOOL Fullscreen,
    IDXGIOutput* pTarget)
{
    auto result = object_->SetFullscreenState(
        Fullscreen,
        pTarget);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetFullscreenState(
    BOOL* pFullscreen,
    IDXGIOutput** ppTarget)
{
    auto result = object_->GetFullscreenState(
        pFullscreen,
        ppTarget);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppTarget), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetDesc(
    DXGI_SWAP_CHAIN_DESC* pDesc)
{
    auto result = object_->GetDesc(
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::ResizeBuffers(
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT NewFormat,
    UINT SwapChainFlags)
{
    auto result = object_->ResizeBuffers(
        BufferCount,
        Width,
        Height,
        NewFormat,
        SwapChainFlags);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::ResizeTarget(
    const DXGI_MODE_DESC* pNewTargetParameters)
{
    auto result = object_->ResizeTarget(
        pNewTargetParameters);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetContainingOutput(
    IDXGIOutput** ppOutput)
{
    auto result = object_->GetContainingOutput(
        ppOutput);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppOutput), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetFrameStatistics(
    DXGI_FRAME_STATISTICS* pStats)
{
    auto result = object_->GetFrameStatistics(
        pStats);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetLastPresentCount(
    UINT* pLastPresentCount)
{
    auto result = object_->GetLastPresentCount(
        pLastPresentCount);

    return result;
}

IDXGIFactory_Wrapper::IDXGIFactory_Wrapper(REFIID riid, IDXGIFactory* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::EnumAdapters(
    UINT Adapter,
    IDXGIAdapter** ppAdapter)
{
    auto result = object_->EnumAdapters(
        Adapter,
        ppAdapter);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIAdapter, reinterpret_cast<void**>(ppAdapter), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::MakeWindowAssociation(
    HWND WindowHandle,
    UINT Flags)
{
    auto result = object_->MakeWindowAssociation(
        WindowHandle,
        Flags);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::GetWindowAssociation(
    HWND* pWindowHandle)
{
    auto result = object_->GetWindowAssociation(
        pWindowHandle);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::CreateSwapChain(
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain)
{
    auto result = object_->CreateSwapChain(
        pDevice,
        pDesc,
        ppSwapChain);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGISwapChain, reinterpret_cast<void**>(ppSwapChain), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::CreateSoftwareAdapter(
    HMODULE Module,
    IDXGIAdapter** ppAdapter)
{
    auto result = object_->CreateSoftwareAdapter(
        Module,
        ppAdapter);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIAdapter, reinterpret_cast<void**>(ppAdapter), nullptr);
    }

    return result;
}

IDXGIDevice_Wrapper::IDXGIDevice_Wrapper(REFIID riid, IDXGIDevice* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::GetAdapter(
    IDXGIAdapter** pAdapter)
{
    auto result = object_->GetAdapter(
        pAdapter);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIAdapter, reinterpret_cast<void**>(pAdapter), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::CreateSurface(
    const DXGI_SURFACE_DESC* pDesc,
    UINT NumSurfaces,
    DXGI_USAGE Usage,
    const DXGI_SHARED_RESOURCE* pSharedResource,
    IDXGISurface** ppSurface)
{
    auto result = object_->CreateSurface(
        pDesc,
        NumSurfaces,
        Usage,
        pSharedResource,
        ppSurface);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGISurface, reinterpret_cast<void**>(ppSurface), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::QueryResourceResidency(
    IUnknown* const* ppResources,
    DXGI_RESIDENCY* pResidencyStatus,
    UINT NumResources)
{
    auto result = object_->QueryResourceResidency(
        ppResources,
        pResidencyStatus,
        NumResources);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::SetGPUThreadPriority(
    INT Priority)
{
    auto result = object_->SetGPUThreadPriority(
        Priority);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::GetGPUThreadPriority(
    INT* pPriority)
{
    auto result = object_->GetGPUThreadPriority(
        pPriority);

    return result;
}

IDXGIFactory1_Wrapper::IDXGIFactory1_Wrapper(REFIID riid, IDXGIFactory1* object, DxWrapperResources* resources) : IDXGIFactory_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory1_Wrapper::EnumAdapters1(
    UINT Adapter,
    IDXGIAdapter1** ppAdapter)
{
    auto result = object_->EnumAdapters1(
        Adapter,
        ppAdapter);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIAdapter1, reinterpret_cast<void**>(ppAdapter), nullptr);
    }

    return result;
}

BOOL STDMETHODCALLTYPE IDXGIFactory1_Wrapper::IsCurrent()
{
    auto result = object_->IsCurrent();

    return result;
}

IDXGIAdapter1_Wrapper::IDXGIAdapter1_Wrapper(REFIID riid, IDXGIAdapter1* object, DxWrapperResources* resources) : IDXGIAdapter_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter1_Wrapper::GetDesc1(
    DXGI_ADAPTER_DESC1* pDesc)
{
    auto result = object_->GetDesc1(
        pDesc);

    return result;
}

IDXGIDevice1_Wrapper::IDXGIDevice1_Wrapper(REFIID riid, IDXGIDevice1* object, DxWrapperResources* resources) : IDXGIDevice_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDevice1_Wrapper::SetMaximumFrameLatency(
    UINT MaxLatency)
{
    auto result = object_->SetMaximumFrameLatency(
        MaxLatency);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice1_Wrapper::GetMaximumFrameLatency(
    UINT* pMaxLatency)
{
    auto result = object_->GetMaximumFrameLatency(
        pMaxLatency);

    return result;
}


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/

IDXGIDisplayControl_Wrapper::IDXGIDisplayControl_Wrapper(REFIID riid, IDXGIDisplayControl* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

BOOL STDMETHODCALLTYPE IDXGIDisplayControl_Wrapper::IsStereoEnabled()
{
    auto result = object_->IsStereoEnabled();

    return result;
}

void STDMETHODCALLTYPE IDXGIDisplayControl_Wrapper::SetStereoEnabled(
    BOOL enabled)
{
    object_->SetStereoEnabled(
        enabled);
}

IDXGIOutputDuplication_Wrapper::IDXGIOutputDuplication_Wrapper(REFIID riid, IDXGIOutputDuplication* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetDesc(
    DXGI_OUTDUPL_DESC* pDesc)
{
    object_->GetDesc(
        pDesc);
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::AcquireNextFrame(
    UINT TimeoutInMilliseconds,
    DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
    IDXGIResource** ppDesktopResource)
{
    auto result = object_->AcquireNextFrame(
        TimeoutInMilliseconds,
        pFrameInfo,
        ppDesktopResource);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIResource, reinterpret_cast<void**>(ppDesktopResource), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetFrameDirtyRects(
    UINT DirtyRectsBufferSize,
    RECT* pDirtyRectsBuffer,
    UINT* pDirtyRectsBufferSizeRequired)
{
    auto result = object_->GetFrameDirtyRects(
        DirtyRectsBufferSize,
        pDirtyRectsBuffer,
        pDirtyRectsBufferSizeRequired);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetFrameMoveRects(
    UINT MoveRectsBufferSize,
    DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
    UINT* pMoveRectsBufferSizeRequired)
{
    auto result = object_->GetFrameMoveRects(
        MoveRectsBufferSize,
        pMoveRectBuffer,
        pMoveRectsBufferSizeRequired);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetFramePointerShape(
    UINT PointerShapeBufferSize,
    void* pPointerShapeBuffer,
    UINT* pPointerShapeBufferSizeRequired,
    DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo)
{
    auto result = object_->GetFramePointerShape(
        PointerShapeBufferSize,
        pPointerShapeBuffer,
        pPointerShapeBufferSizeRequired,
        pPointerShapeInfo);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::MapDesktopSurface(
    DXGI_MAPPED_RECT* pLockedRect)
{
    auto result = object_->MapDesktopSurface(
        pLockedRect);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::UnMapDesktopSurface()
{
    auto result = object_->UnMapDesktopSurface();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::ReleaseFrame()
{
    auto result = object_->ReleaseFrame();

    return result;
}

IDXGISurface2_Wrapper::IDXGISurface2_Wrapper(REFIID riid, IDXGISurface2* object, DxWrapperResources* resources) : IDXGISurface1_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISurface2_Wrapper::GetResource(
    REFIID riid,
    void** ppParentResource,
    UINT* pSubresourceIndex)
{
    auto result = object_->GetResource(
        riid,
        ppParentResource,
        pSubresourceIndex);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppParentResource, nullptr);
    }

    return result;
}

IDXGIResource1_Wrapper::IDXGIResource1_Wrapper(REFIID riid, IDXGIResource1* object, DxWrapperResources* resources) : IDXGIResource_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIResource1_Wrapper::CreateSubresourceSurface(
    UINT index,
    IDXGISurface2** ppSurface)
{
    auto result = object_->CreateSubresourceSurface(
        index,
        ppSurface);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGISurface2, reinterpret_cast<void**>(ppSurface), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource1_Wrapper::CreateSharedHandle(
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD dwAccess,
    LPCWSTR lpName,
    HANDLE* pHandle)
{
    auto result = object_->CreateSharedHandle(
        pAttributes,
        dwAccess,
        lpName,
        pHandle);

    return result;
}

IDXGIDevice2_Wrapper::IDXGIDevice2_Wrapper(REFIID riid, IDXGIDevice2* object, DxWrapperResources* resources) : IDXGIDevice1_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDevice2_Wrapper::OfferResources(
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority)
{
    auto result = object_->OfferResources(
        NumResources,
        ppResources,
        Priority);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice2_Wrapper::ReclaimResources(
    UINT NumResources,
    IDXGIResource* const* ppResources,
    BOOL* pDiscarded)
{
    auto result = object_->ReclaimResources(
        NumResources,
        ppResources,
        pDiscarded);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice2_Wrapper::EnqueueSetEvent(
    HANDLE hEvent)
{
    auto result = object_->EnqueueSetEvent(
        hEvent);

    return result;
}

IDXGISwapChain1_Wrapper::IDXGISwapChain1_Wrapper(REFIID riid, IDXGISwapChain1* object, DxWrapperResources* resources) : IDXGISwapChain_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetDesc1(
    DXGI_SWAP_CHAIN_DESC1* pDesc)
{
    auto result = object_->GetDesc1(
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetFullscreenDesc(
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc)
{
    auto result = object_->GetFullscreenDesc(
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetHwnd(
    HWND* pHwnd)
{
    auto result = object_->GetHwnd(
        pHwnd);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetCoreWindow(
    REFIID refiid,
    void** ppUnk)
{
    auto result = object_->GetCoreWindow(
        refiid,
        ppUnk);

    if (SUCCEEDED(result))
    {
        WrapObject(refiid, ppUnk, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::Present1(
    UINT SyncInterval,
    UINT PresentFlags,
    const DXGI_PRESENT_PARAMETERS* pPresentParameters)
{
    auto result = object_->Present1(
        SyncInterval,
        PresentFlags,
        pPresentParameters);

    return result;
}

BOOL STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::IsTemporaryMonoSupported()
{
    auto result = object_->IsTemporaryMonoSupported();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetRestrictToOutput(
    IDXGIOutput** ppRestrictToOutput)
{
    auto result = object_->GetRestrictToOutput(
        ppRestrictToOutput);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppRestrictToOutput), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::SetBackgroundColor(
    const DXGI_RGBA* pColor)
{
    auto result = object_->SetBackgroundColor(
        pColor);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetBackgroundColor(
    DXGI_RGBA* pColor)
{
    auto result = object_->GetBackgroundColor(
        pColor);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::SetRotation(
    DXGI_MODE_ROTATION Rotation)
{
    auto result = object_->SetRotation(
        Rotation);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetRotation(
    DXGI_MODE_ROTATION* pRotation)
{
    auto result = object_->GetRotation(
        pRotation);

    return result;
}

IDXGIFactory2_Wrapper::IDXGIFactory2_Wrapper(REFIID riid, IDXGIFactory2* object, DxWrapperResources* resources) : IDXGIFactory1_Wrapper(riid, object, resources), object_(object)
{
}

BOOL STDMETHODCALLTYPE IDXGIFactory2_Wrapper::IsWindowedStereoEnabled()
{
    auto result = object_->IsWindowedStereoEnabled();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::CreateSwapChainForHwnd(
    IUnknown* pDevice,
    HWND hWnd,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto result = object_->CreateSwapChainForHwnd(
        pDevice,
        hWnd,
        pDesc,
        pFullscreenDesc,
        pRestrictToOutput,
        ppSwapChain);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::CreateSwapChainForCoreWindow(
    IUnknown* pDevice,
    IUnknown* pWindow,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto result = object_->CreateSwapChainForCoreWindow(
        pDevice,
        pWindow,
        pDesc,
        pRestrictToOutput,
        ppSwapChain);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::GetSharedResourceAdapterLuid(
    HANDLE hResource,
    LUID* pLuid)
{
    auto result = object_->GetSharedResourceAdapterLuid(
        hResource,
        pLuid);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterStereoStatusWindow(
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    auto result = object_->RegisterStereoStatusWindow(
        WindowHandle,
        wMsg,
        pdwCookie);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterStereoStatusEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto result = object_->RegisterStereoStatusEvent(
        hEvent,
        pdwCookie);

    return result;
}

void STDMETHODCALLTYPE IDXGIFactory2_Wrapper::UnregisterStereoStatus(
    DWORD dwCookie)
{
    object_->UnregisterStereoStatus(
        dwCookie);
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterOcclusionStatusWindow(
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    auto result = object_->RegisterOcclusionStatusWindow(
        WindowHandle,
        wMsg,
        pdwCookie);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterOcclusionStatusEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto result = object_->RegisterOcclusionStatusEvent(
        hEvent,
        pdwCookie);

    return result;
}

void STDMETHODCALLTYPE IDXGIFactory2_Wrapper::UnregisterOcclusionStatus(
    DWORD dwCookie)
{
    object_->UnregisterOcclusionStatus(
        dwCookie);
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::CreateSwapChainForComposition(
    IUnknown* pDevice,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto result = object_->CreateSwapChainForComposition(
        pDevice,
        pDesc,
        pRestrictToOutput,
        ppSwapChain);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
    }

    return result;
}

IDXGIAdapter2_Wrapper::IDXGIAdapter2_Wrapper(REFIID riid, IDXGIAdapter2* object, DxWrapperResources* resources) : IDXGIAdapter1_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter2_Wrapper::GetDesc2(
    DXGI_ADAPTER_DESC2* pDesc)
{
    auto result = object_->GetDesc2(
        pDesc);

    return result;
}

IDXGIOutput1_Wrapper::IDXGIOutput1_Wrapper(REFIID riid, IDXGIOutput1* object, DxWrapperResources* resources) : IDXGIOutput_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput1_Wrapper::GetDisplayModeList1(
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC1* pDesc)
{
    auto result = object_->GetDisplayModeList1(
        EnumFormat,
        Flags,
        pNumModes,
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput1_Wrapper::FindClosestMatchingMode1(
    const DXGI_MODE_DESC1* pModeToMatch,
    DXGI_MODE_DESC1* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    auto result = object_->FindClosestMatchingMode1(
        pModeToMatch,
        pClosestMatch,
        pConcernedDevice);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput1_Wrapper::GetDisplaySurfaceData1(
    IDXGIResource* pDestination)
{
    auto result = object_->GetDisplaySurfaceData1(
        pDestination);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput1_Wrapper::DuplicateOutput(
    IUnknown* pDevice,
    IDXGIOutputDuplication** ppOutputDuplication)
{
    auto result = object_->DuplicateOutput(
        pDevice,
        ppOutputDuplication);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIOutputDuplication, reinterpret_cast<void**>(ppOutputDuplication), nullptr);
    }

    return result;
}


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/

HRESULT WINAPI CreateDXGIFactory2(
    UINT Flags,
    REFIID riid,
    void** ppFactory)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory2(
        Flags,
        riid,
        ppFactory);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppFactory, nullptr);
    }

    return result;
}

HRESULT WINAPI DXGIGetDebugInterface1(
    UINT Flags,
    REFIID riid,
    void** pDebug)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetDxgiDispatchTable().DXGIGetDebugInterface1(
        Flags,
        riid,
        pDebug);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, pDebug, nullptr);
    }

    return result;
}

IDXGIDevice3_Wrapper::IDXGIDevice3_Wrapper(REFIID riid, IDXGIDevice3* object, DxWrapperResources* resources) : IDXGIDevice2_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE IDXGIDevice3_Wrapper::Trim()
{
    object_->Trim();
}

IDXGISwapChain2_Wrapper::IDXGISwapChain2_Wrapper(REFIID riid, IDXGISwapChain2* object, DxWrapperResources* resources) : IDXGISwapChain1_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::SetSourceSize(
    UINT Width,
    UINT Height)
{
    auto result = object_->SetSourceSize(
        Width,
        Height);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetSourceSize(
    UINT* pWidth,
    UINT* pHeight)
{
    auto result = object_->GetSourceSize(
        pWidth,
        pHeight);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::SetMaximumFrameLatency(
    UINT MaxLatency)
{
    auto result = object_->SetMaximumFrameLatency(
        MaxLatency);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetMaximumFrameLatency(
    UINT* pMaxLatency)
{
    auto result = object_->GetMaximumFrameLatency(
        pMaxLatency);

    return result;
}

HANDLE STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetFrameLatencyWaitableObject()
{
    auto result = object_->GetFrameLatencyWaitableObject();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::SetMatrixTransform(
    const DXGI_MATRIX_3X2_F* pMatrix)
{
    auto result = object_->SetMatrixTransform(
        pMatrix);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetMatrixTransform(
    DXGI_MATRIX_3X2_F* pMatrix)
{
    auto result = object_->GetMatrixTransform(
        pMatrix);

    return result;
}

IDXGIOutput2_Wrapper::IDXGIOutput2_Wrapper(REFIID riid, IDXGIOutput2* object, DxWrapperResources* resources) : IDXGIOutput1_Wrapper(riid, object, resources), object_(object)
{
}

BOOL STDMETHODCALLTYPE IDXGIOutput2_Wrapper::SupportsOverlays()
{
    auto result = object_->SupportsOverlays();

    return result;
}

IDXGIFactory3_Wrapper::IDXGIFactory3_Wrapper(REFIID riid, IDXGIFactory3* object, DxWrapperResources* resources) : IDXGIFactory2_Wrapper(riid, object, resources), object_(object)
{
}

UINT STDMETHODCALLTYPE IDXGIFactory3_Wrapper::GetCreationFlags()
{
    auto result = object_->GetCreationFlags();

    return result;
}

IDXGIDecodeSwapChain_Wrapper::IDXGIDecodeSwapChain_Wrapper(REFIID riid, IDXGIDecodeSwapChain* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::PresentBuffer(
    UINT BufferToPresent,
    UINT SyncInterval,
    UINT Flags)
{
    auto result = object_->PresentBuffer(
        BufferToPresent,
        SyncInterval,
        Flags);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetSourceRect(
    const RECT* pRect)
{
    auto result = object_->SetSourceRect(
        pRect);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetTargetRect(
    const RECT* pRect)
{
    auto result = object_->SetTargetRect(
        pRect);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetDestSize(
    UINT Width,
    UINT Height)
{
    auto result = object_->SetDestSize(
        Width,
        Height);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetSourceRect(
    RECT* pRect)
{
    auto result = object_->GetSourceRect(
        pRect);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetTargetRect(
    RECT* pRect)
{
    auto result = object_->GetTargetRect(
        pRect);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetDestSize(
    UINT* pWidth,
    UINT* pHeight)
{
    auto result = object_->GetDestSize(
        pWidth,
        pHeight);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetColorSpace(
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    auto result = object_->SetColorSpace(
        ColorSpace);

    return result;
}

DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetColorSpace()
{
    auto result = object_->GetColorSpace();

    return result;
}

IDXGIFactoryMedia_Wrapper::IDXGIFactoryMedia_Wrapper(REFIID riid, IDXGIFactoryMedia* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactoryMedia_Wrapper::CreateSwapChainForCompositionSurfaceHandle(
    IUnknown* pDevice,
    HANDLE hSurface,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    auto result = object_->CreateSwapChainForCompositionSurfaceHandle(
        pDevice,
        hSurface,
        pDesc,
        pRestrictToOutput,
        ppSwapChain);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactoryMedia_Wrapper::CreateDecodeSwapChainForCompositionSurfaceHandle(
    IUnknown* pDevice,
    HANDLE hSurface,
    DXGI_DECODE_SWAP_CHAIN_DESC* pDesc,
    IDXGIResource* pYuvDecodeBuffers,
    IDXGIOutput* pRestrictToOutput,
    IDXGIDecodeSwapChain** ppSwapChain)
{
    auto result = object_->CreateDecodeSwapChainForCompositionSurfaceHandle(
        pDevice,
        hSurface,
        pDesc,
        pYuvDecodeBuffers,
        pRestrictToOutput,
        ppSwapChain);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIDecodeSwapChain, reinterpret_cast<void**>(ppSwapChain), nullptr);
    }

    return result;
}

IDXGISwapChainMedia_Wrapper::IDXGISwapChainMedia_Wrapper(REFIID riid, IDXGISwapChainMedia* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChainMedia_Wrapper::GetFrameStatisticsMedia(
    DXGI_FRAME_STATISTICS_MEDIA* pStats)
{
    auto result = object_->GetFrameStatisticsMedia(
        pStats);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChainMedia_Wrapper::SetPresentDuration(
    UINT Duration)
{
    auto result = object_->SetPresentDuration(
        Duration);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChainMedia_Wrapper::CheckPresentDurationSupport(
    UINT DesiredPresentDuration,
    UINT* pClosestSmallerPresentDuration,
    UINT* pClosestLargerPresentDuration)
{
    auto result = object_->CheckPresentDurationSupport(
        DesiredPresentDuration,
        pClosestSmallerPresentDuration,
        pClosestLargerPresentDuration);

    return result;
}

IDXGIOutput3_Wrapper::IDXGIOutput3_Wrapper(REFIID riid, IDXGIOutput3* object, DxWrapperResources* resources) : IDXGIOutput2_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput3_Wrapper::CheckOverlaySupport(
    DXGI_FORMAT EnumFormat,
    IUnknown* pConcernedDevice,
    UINT* pFlags)
{
    auto result = object_->CheckOverlaySupport(
        EnumFormat,
        pConcernedDevice,
        pFlags);

    return result;
}


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/

IDXGISwapChain3_Wrapper::IDXGISwapChain3_Wrapper(REFIID riid, IDXGISwapChain3* object, DxWrapperResources* resources) : IDXGISwapChain2_Wrapper(riid, object, resources), object_(object)
{
}

UINT STDMETHODCALLTYPE IDXGISwapChain3_Wrapper::GetCurrentBackBufferIndex()
{
    auto result = object_->GetCurrentBackBufferIndex();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain3_Wrapper::CheckColorSpaceSupport(
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    UINT* pColorSpaceSupport)
{
    auto result = object_->CheckColorSpaceSupport(
        ColorSpace,
        pColorSpaceSupport);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain3_Wrapper::SetColorSpace1(
    DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    auto result = object_->SetColorSpace1(
        ColorSpace);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain3_Wrapper::ResizeBuffers1(
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT Format,
    UINT SwapChainFlags,
    const UINT* pCreationNodeMask,
    IUnknown* const* ppPresentQueue)
{
    auto result = object_->ResizeBuffers1(
        BufferCount,
        Width,
        Height,
        Format,
        SwapChainFlags,
        pCreationNodeMask,
        ppPresentQueue);

    return result;
}

IDXGIOutput4_Wrapper::IDXGIOutput4_Wrapper(REFIID riid, IDXGIOutput4* object, DxWrapperResources* resources) : IDXGIOutput3_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput4_Wrapper::CheckOverlayColorSpaceSupport(
    DXGI_FORMAT Format,
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    IUnknown* pConcernedDevice,
    UINT* pFlags)
{
    auto result = object_->CheckOverlayColorSpaceSupport(
        Format,
        ColorSpace,
        pConcernedDevice,
        pFlags);

    return result;
}

IDXGIFactory4_Wrapper::IDXGIFactory4_Wrapper(REFIID riid, IDXGIFactory4* object, DxWrapperResources* resources) : IDXGIFactory3_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory4_Wrapper::EnumAdapterByLuid(
    LUID AdapterLuid,
    REFIID riid,
    void** ppvAdapter)
{
    auto result = object_->EnumAdapterByLuid(
        AdapterLuid,
        riid,
        ppvAdapter);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvAdapter, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory4_Wrapper::EnumWarpAdapter(
    REFIID riid,
    void** ppvAdapter)
{
    auto result = object_->EnumWarpAdapter(
        riid,
        ppvAdapter);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvAdapter, nullptr);
    }

    return result;
}

IDXGIAdapter3_Wrapper::IDXGIAdapter3_Wrapper(REFIID riid, IDXGIAdapter3* object, DxWrapperResources* resources) : IDXGIAdapter2_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::RegisterHardwareContentProtectionTeardownStatusEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto result = object_->RegisterHardwareContentProtectionTeardownStatusEvent(
        hEvent,
        pdwCookie);

    return result;
}

void STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::UnregisterHardwareContentProtectionTeardownStatus(
    DWORD dwCookie)
{
    object_->UnregisterHardwareContentProtectionTeardownStatus(
        dwCookie);
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::QueryVideoMemoryInfo(
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo)
{
    auto result = object_->QueryVideoMemoryInfo(
        NodeIndex,
        MemorySegmentGroup,
        pVideoMemoryInfo);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::SetVideoMemoryReservation(
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    UINT64 Reservation)
{
    auto result = object_->SetVideoMemoryReservation(
        NodeIndex,
        MemorySegmentGroup,
        Reservation);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::RegisterVideoMemoryBudgetChangeNotificationEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto result = object_->RegisterVideoMemoryBudgetChangeNotificationEvent(
        hEvent,
        pdwCookie);

    return result;
}

void STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::UnregisterVideoMemoryBudgetChangeNotification(
    DWORD dwCookie)
{
    object_->UnregisterVideoMemoryBudgetChangeNotification(
        dwCookie);
}


/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.19041.0
**
*/

IDXGIOutput5_Wrapper::IDXGIOutput5_Wrapper(REFIID riid, IDXGIOutput5* object, DxWrapperResources* resources) : IDXGIOutput4_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput5_Wrapper::DuplicateOutput1(
    IUnknown* pDevice,
    UINT Flags,
    UINT SupportedFormatsCount,
    const DXGI_FORMAT* pSupportedFormats,
    IDXGIOutputDuplication** ppOutputDuplication)
{
    auto result = object_->DuplicateOutput1(
        pDevice,
        Flags,
        SupportedFormatsCount,
        pSupportedFormats,
        ppOutputDuplication);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_IDXGIOutputDuplication, reinterpret_cast<void**>(ppOutputDuplication), nullptr);
    }

    return result;
}

IDXGISwapChain4_Wrapper::IDXGISwapChain4_Wrapper(REFIID riid, IDXGISwapChain4* object, DxWrapperResources* resources) : IDXGISwapChain3_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain4_Wrapper::SetHDRMetaData(
    DXGI_HDR_METADATA_TYPE Type,
    UINT Size,
    void* pMetaData)
{
    auto result = object_->SetHDRMetaData(
        Type,
        Size,
        pMetaData);

    return result;
}

IDXGIDevice4_Wrapper::IDXGIDevice4_Wrapper(REFIID riid, IDXGIDevice4* object, DxWrapperResources* resources) : IDXGIDevice3_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDevice4_Wrapper::OfferResources1(
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_OFFER_RESOURCE_PRIORITY Priority,
    UINT Flags)
{
    auto result = object_->OfferResources1(
        NumResources,
        ppResources,
        Priority,
        Flags);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice4_Wrapper::ReclaimResources1(
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_RECLAIM_RESOURCE_RESULTS* pResults)
{
    auto result = object_->ReclaimResources1(
        NumResources,
        ppResources,
        pResults);

    return result;
}

IDXGIFactory5_Wrapper::IDXGIFactory5_Wrapper(REFIID riid, IDXGIFactory5* object, DxWrapperResources* resources) : IDXGIFactory4_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory5_Wrapper::CheckFeatureSupport(
    DXGI_FEATURE Feature,
    void* pFeatureSupportData,
    UINT FeatureSupportDataSize)
{
    auto result = object_->CheckFeatureSupport(
        Feature,
        pFeatureSupportData,
        FeatureSupportDataSize);

    return result;
}


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/

HRESULT WINAPI DXGIDeclareAdapterRemovalSupport()
{
    auto manager = TraceManager::Get();

    auto result = manager->GetDxgiDispatchTable().DXGIDeclareAdapterRemovalSupport();

    return result;
}

IDXGIAdapter4_Wrapper::IDXGIAdapter4_Wrapper(REFIID riid, IDXGIAdapter4* object, DxWrapperResources* resources) : IDXGIAdapter3_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter4_Wrapper::GetDesc3(
    DXGI_ADAPTER_DESC3* pDesc)
{
    auto result = object_->GetDesc3(
        pDesc);

    return result;
}

IDXGIOutput6_Wrapper::IDXGIOutput6_Wrapper(REFIID riid, IDXGIOutput6* object, DxWrapperResources* resources) : IDXGIOutput5_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput6_Wrapper::GetDesc1(
    DXGI_OUTPUT_DESC1* pDesc)
{
    auto result = object_->GetDesc1(
        pDesc);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput6_Wrapper::CheckHardwareCompositionSupport(
    UINT* pFlags)
{
    auto result = object_->CheckHardwareCompositionSupport(
        pFlags);

    return result;
}

IDXGIFactory6_Wrapper::IDXGIFactory6_Wrapper(REFIID riid, IDXGIFactory6* object, DxWrapperResources* resources) : IDXGIFactory5_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory6_Wrapper::EnumAdapterByGpuPreference(
    UINT Adapter,
    DXGI_GPU_PREFERENCE GpuPreference,
    REFIID riid,
    void** ppvAdapter)
{
    auto result = object_->EnumAdapterByGpuPreference(
        Adapter,
        GpuPreference,
        riid,
        ppvAdapter);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvAdapter, nullptr);
    }

    return result;
}

IDXGIFactory7_Wrapper::IDXGIFactory7_Wrapper(REFIID riid, IDXGIFactory7* object, DxWrapperResources* resources) : IDXGIFactory6_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory7_Wrapper::RegisterAdaptersChangedEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    auto result = object_->RegisterAdaptersChangedEvent(
        hEvent,
        pdwCookie);

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory7_Wrapper::UnregisterAdaptersChangedEvent(
    DWORD dwCookie)
{
    auto result = object_->UnregisterAdaptersChangedEvent(
        dwCookie);

    return result;
}


/*
** This part is generated from dxgicommon.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from dxgiformat.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from dxgitype.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from d3d12.h in Windows SDK: 10.0.19041.0
**
*/

HRESULT WINAPI D3D12SerializeRootSignature(
    const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
    D3D_ROOT_SIGNATURE_VERSION Version,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetD3D12DispatchTable().D3D12SerializeRootSignature(
        pRootSignature,
        Version,
        ppBlob,
        ppErrorBlob);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppBlob), nullptr);
        WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppErrorBlob), nullptr);
    }

    return result;
}

HRESULT WINAPI D3D12CreateRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetD3D12DispatchTable().D3D12CreateRootSignatureDeserializer(
        pSrcData,
        SrcDataSizeInBytes,
        pRootSignatureDeserializerInterface,
        ppRootSignatureDeserializer);

    if (SUCCEEDED(result))
    {
        WrapObject(pRootSignatureDeserializerInterface, ppRootSignatureDeserializer, nullptr);
    }

    return result;
}

HRESULT WINAPI D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetD3D12DispatchTable().D3D12SerializeVersionedRootSignature(
        pRootSignature,
        ppBlob,
        ppErrorBlob);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppBlob), nullptr);
        WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppErrorBlob), nullptr);
    }

    return result;
}

HRESULT WINAPI D3D12CreateVersionedRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetD3D12DispatchTable().D3D12CreateVersionedRootSignatureDeserializer(
        pSrcData,
        SrcDataSizeInBytes,
        pRootSignatureDeserializerInterface,
        ppRootSignatureDeserializer);

    if (SUCCEEDED(result))
    {
        WrapObject(pRootSignatureDeserializerInterface, ppRootSignatureDeserializer, nullptr);
    }

    return result;
}

HRESULT WINAPI D3D12CreateDevice(
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetD3D12DispatchTable().D3D12CreateDevice(
        pAdapter,
        MinimumFeatureLevel,
        riid,
        ppDevice);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppDevice, nullptr);
    }

    return result;
}

HRESULT WINAPI D3D12GetDebugInterface(
    REFIID riid,
    void** ppvDebug)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetD3D12DispatchTable().D3D12GetDebugInterface(
        riid,
        ppvDebug);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvDebug, nullptr);
    }

    return result;
}

HRESULT WINAPI D3D12EnableExperimentalFeatures(
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes)
{
    auto manager = TraceManager::Get();

    auto result = manager->GetD3D12DispatchTable().D3D12EnableExperimentalFeatures(
        NumFeatures,
        pIIDs,
        pConfigurationStructs,
        pConfigurationStructSizes);

    return result;
}

ID3D12Object_Wrapper::ID3D12Object_Wrapper(REFIID riid, ID3D12Object* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Object_Wrapper::GetPrivateData(
    REFGUID guid,
    UINT* pDataSize,
    void* pData)
{
    auto result = object_->GetPrivateData(
        guid,
        pDataSize,
        pData);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Object_Wrapper::SetPrivateData(
    REFGUID guid,
    UINT DataSize,
    const void* pData)
{
    auto result = object_->SetPrivateData(
        guid,
        DataSize,
        pData);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Object_Wrapper::SetPrivateDataInterface(
    REFGUID guid,
    const IUnknown* pData)
{
    auto result = object_->SetPrivateDataInterface(
        guid,
        pData);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Object_Wrapper::SetName(
    LPCWSTR Name)
{
    auto result = object_->SetName(
        Name);

    return result;
}

ID3D12DeviceChild_Wrapper::ID3D12DeviceChild_Wrapper(REFIID riid, ID3D12DeviceChild* object, DxWrapperResources* resources) : ID3D12Object_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceChild_Wrapper::GetDevice(
    REFIID riid,
    void** ppvDevice)
{
    auto result = object_->GetDevice(
        riid,
        ppvDevice);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvDevice, nullptr);
    }

    return result;
}

ID3D12RootSignature_Wrapper::ID3D12RootSignature_Wrapper(REFIID riid, ID3D12RootSignature* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

ID3D12RootSignatureDeserializer_Wrapper::ID3D12RootSignatureDeserializer_Wrapper(REFIID riid, ID3D12RootSignatureDeserializer* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

const D3D12_ROOT_SIGNATURE_DESC* STDMETHODCALLTYPE ID3D12RootSignatureDeserializer_Wrapper::GetRootSignatureDesc()
{
    auto result = object_->GetRootSignatureDesc();

    return result;
}

ID3D12VersionedRootSignatureDeserializer_Wrapper::ID3D12VersionedRootSignatureDeserializer_Wrapper(REFIID riid, ID3D12VersionedRootSignatureDeserializer* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12VersionedRootSignatureDeserializer_Wrapper::GetRootSignatureDescAtVersion(
    D3D_ROOT_SIGNATURE_VERSION convertToVersion,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc)
{
    auto result = object_->GetRootSignatureDescAtVersion(
        convertToVersion,
        ppDesc);

    return result;
}

const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* STDMETHODCALLTYPE ID3D12VersionedRootSignatureDeserializer_Wrapper::GetUnconvertedRootSignatureDesc()
{
    auto result = object_->GetUnconvertedRootSignatureDesc();

    return result;
}

ID3D12Pageable_Wrapper::ID3D12Pageable_Wrapper(REFIID riid, ID3D12Pageable* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

ID3D12Heap_Wrapper::ID3D12Heap_Wrapper(REFIID riid, ID3D12Heap* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_HEAP_DESC STDMETHODCALLTYPE ID3D12Heap_Wrapper::GetDesc()
{
    auto result = object_->GetDesc();

    return result;
}

ID3D12Resource_Wrapper::ID3D12Resource_Wrapper(REFIID riid, ID3D12Resource* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Resource_Wrapper::Map(
    UINT Subresource,
    const D3D12_RANGE* pReadRange,
    void** ppData)
{
    auto result = object_->Map(
        Subresource,
        pReadRange,
        ppData);

    return result;
}

void STDMETHODCALLTYPE ID3D12Resource_Wrapper::Unmap(
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange)
{
    object_->Unmap(
        Subresource,
        pWrittenRange);
}

D3D12_RESOURCE_DESC STDMETHODCALLTYPE ID3D12Resource_Wrapper::GetDesc()
{
    auto result = object_->GetDesc();

    return result;
}

D3D12_GPU_VIRTUAL_ADDRESS STDMETHODCALLTYPE ID3D12Resource_Wrapper::GetGPUVirtualAddress()
{
    auto result = object_->GetGPUVirtualAddress();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Resource_Wrapper::WriteToSubresource(
    UINT DstSubresource,
    const D3D12_BOX* pDstBox,
    const void* pSrcData,
    UINT SrcRowPitch,
    UINT SrcDepthPitch)
{
    auto result = object_->WriteToSubresource(
        DstSubresource,
        pDstBox,
        pSrcData,
        SrcRowPitch,
        SrcDepthPitch);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Resource_Wrapper::ReadFromSubresource(
    void* pDstData,
    UINT DstRowPitch,
    UINT DstDepthPitch,
    UINT SrcSubresource,
    const D3D12_BOX* pSrcBox)
{
    auto result = object_->ReadFromSubresource(
        pDstData,
        DstRowPitch,
        DstDepthPitch,
        SrcSubresource,
        pSrcBox);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Resource_Wrapper::GetHeapProperties(
    D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS* pHeapFlags)
{
    auto result = object_->GetHeapProperties(
        pHeapProperties,
        pHeapFlags);

    return result;
}

ID3D12CommandAllocator_Wrapper::ID3D12CommandAllocator_Wrapper(REFIID riid, ID3D12CommandAllocator* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12CommandAllocator_Wrapper::Reset()
{
    auto result = object_->Reset();

    return result;
}

ID3D12Fence_Wrapper::ID3D12Fence_Wrapper(REFIID riid, ID3D12Fence* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

UINT64 STDMETHODCALLTYPE ID3D12Fence_Wrapper::GetCompletedValue()
{
    auto result = object_->GetCompletedValue();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Fence_Wrapper::SetEventOnCompletion(
    UINT64 Value,
    HANDLE hEvent)
{
    auto result = object_->SetEventOnCompletion(
        Value,
        hEvent);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Fence_Wrapper::Signal(
    UINT64 Value)
{
    auto result = object_->Signal(
        Value);

    return result;
}

ID3D12Fence1_Wrapper::ID3D12Fence1_Wrapper(REFIID riid, ID3D12Fence1* object, DxWrapperResources* resources) : ID3D12Fence_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_FENCE_FLAGS STDMETHODCALLTYPE ID3D12Fence1_Wrapper::GetCreationFlags()
{
    auto result = object_->GetCreationFlags();

    return result;
}

ID3D12PipelineState_Wrapper::ID3D12PipelineState_Wrapper(REFIID riid, ID3D12PipelineState* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineState_Wrapper::GetCachedBlob(
    ID3DBlob** ppBlob)
{
    auto result = object_->GetCachedBlob(
        ppBlob);

    if (SUCCEEDED(result))
    {
        WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppBlob), nullptr);
    }

    return result;
}

ID3D12DescriptorHeap_Wrapper::ID3D12DescriptorHeap_Wrapper(REFIID riid, ID3D12DescriptorHeap* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_DESCRIPTOR_HEAP_DESC STDMETHODCALLTYPE ID3D12DescriptorHeap_Wrapper::GetDesc()
{
    auto result = object_->GetDesc();

    return result;
}

D3D12_CPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE ID3D12DescriptorHeap_Wrapper::GetCPUDescriptorHandleForHeapStart()
{
    auto result = object_->GetCPUDescriptorHandleForHeapStart();

    return result;
}

D3D12_GPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE ID3D12DescriptorHeap_Wrapper::GetGPUDescriptorHandleForHeapStart()
{
    auto result = object_->GetGPUDescriptorHandleForHeapStart();

    return result;
}

ID3D12QueryHeap_Wrapper::ID3D12QueryHeap_Wrapper(REFIID riid, ID3D12QueryHeap* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

ID3D12CommandSignature_Wrapper::ID3D12CommandSignature_Wrapper(REFIID riid, ID3D12CommandSignature* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

ID3D12CommandList_Wrapper::ID3D12CommandList_Wrapper(REFIID riid, ID3D12CommandList* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_COMMAND_LIST_TYPE STDMETHODCALLTYPE ID3D12CommandList_Wrapper::GetType()
{
    auto result = object_->GetType();

    return result;
}

ID3D12GraphicsCommandList_Wrapper::ID3D12GraphicsCommandList_Wrapper(REFIID riid, ID3D12GraphicsCommandList* object, DxWrapperResources* resources) : ID3D12CommandList_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::Close()
{
    auto result = object_->Close();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::Reset(
    ID3D12CommandAllocator* pAllocator,
    ID3D12PipelineState* pInitialState)
{
    auto result = object_->Reset(
        pAllocator,
        pInitialState);

    return result;
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearState(
    ID3D12PipelineState* pPipelineState)
{
    object_->ClearState(
        pPipelineState);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::DrawInstanced(
    UINT VertexCountPerInstance,
    UINT InstanceCount,
    UINT StartVertexLocation,
    UINT StartInstanceLocation)
{
    object_->DrawInstanced(
        VertexCountPerInstance,
        InstanceCount,
        StartVertexLocation,
        StartInstanceLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::DrawIndexedInstanced(
    UINT IndexCountPerInstance,
    UINT InstanceCount,
    UINT StartIndexLocation,
    INT BaseVertexLocation,
    UINT StartInstanceLocation)
{
    object_->DrawIndexedInstanced(
        IndexCountPerInstance,
        InstanceCount,
        StartIndexLocation,
        BaseVertexLocation,
        StartInstanceLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::Dispatch(
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    object_->Dispatch(
        ThreadGroupCountX,
        ThreadGroupCountY,
        ThreadGroupCountZ);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyBufferRegion(
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT64 NumBytes)
{
    object_->CopyBufferRegion(
        pDstBuffer,
        DstOffset,
        pSrcBuffer,
        SrcOffset,
        NumBytes);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyTextureRegion(
    const D3D12_TEXTURE_COPY_LOCATION* pDst,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    const D3D12_TEXTURE_COPY_LOCATION* pSrc,
    const D3D12_BOX* pSrcBox)
{
    object_->CopyTextureRegion(
        pDst,
        DstX,
        DstY,
        DstZ,
        pSrc,
        pSrcBox);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyResource(
    ID3D12Resource* pDstResource,
    ID3D12Resource* pSrcResource)
{
    object_->CopyResource(
        pDstResource,
        pSrcResource);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyTiles(
    ID3D12Resource* pTiledResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pTileRegionSize,
    ID3D12Resource* pBuffer,
    UINT64 BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS Flags)
{
    object_->CopyTiles(
        pTiledResource,
        pTileRegionStartCoordinate,
        pTileRegionSize,
        pBuffer,
        BufferStartOffsetInBytes,
        Flags);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ResolveSubresource(
    ID3D12Resource* pDstResource,
    UINT DstSubresource,
    ID3D12Resource* pSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT Format)
{
    object_->ResolveSubresource(
        pDstResource,
        DstSubresource,
        pSrcResource,
        SrcSubresource,
        Format);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::IASetPrimitiveTopology(
    D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    object_->IASetPrimitiveTopology(
        PrimitiveTopology);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::RSSetViewports(
    UINT NumViewports,
    const D3D12_VIEWPORT* pViewports)
{
    object_->RSSetViewports(
        NumViewports,
        pViewports);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::RSSetScissorRects(
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    object_->RSSetScissorRects(
        NumRects,
        pRects);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::OMSetBlendFactor(
    const FLOAT BlendFactor [4])
{
    object_->OMSetBlendFactor(
        BlendFactor);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::OMSetStencilRef(
    UINT StencilRef)
{
    object_->OMSetStencilRef(
        StencilRef);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetPipelineState(
    ID3D12PipelineState* pPipelineState)
{
    object_->SetPipelineState(
        pPipelineState);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ResourceBarrier(
    UINT NumBarriers,
    const D3D12_RESOURCE_BARRIER* pBarriers)
{
    object_->ResourceBarrier(
        NumBarriers,
        pBarriers);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ExecuteBundle(
    ID3D12GraphicsCommandList* pCommandList)
{
    object_->ExecuteBundle(
        pCommandList);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetDescriptorHeaps(
    UINT NumDescriptorHeaps,
    ID3D12DescriptorHeap* const* ppDescriptorHeaps)
{
    object_->SetDescriptorHeaps(
        NumDescriptorHeaps,
        ppDescriptorHeaps);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootSignature(
    ID3D12RootSignature* pRootSignature)
{
    object_->SetComputeRootSignature(
        pRootSignature);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootSignature(
    ID3D12RootSignature* pRootSignature)
{
    object_->SetGraphicsRootSignature(
        pRootSignature);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootDescriptorTable(
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    object_->SetComputeRootDescriptorTable(
        RootParameterIndex,
        BaseDescriptor);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootDescriptorTable(
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    object_->SetGraphicsRootDescriptorTable(
        RootParameterIndex,
        BaseDescriptor);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRoot32BitConstant(
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    object_->SetComputeRoot32BitConstant(
        RootParameterIndex,
        SrcData,
        DestOffsetIn32BitValues);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRoot32BitConstant(
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    object_->SetGraphicsRoot32BitConstant(
        RootParameterIndex,
        SrcData,
        DestOffsetIn32BitValues);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRoot32BitConstants(
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    object_->SetComputeRoot32BitConstants(
        RootParameterIndex,
        Num32BitValuesToSet,
        pSrcData,
        DestOffsetIn32BitValues);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRoot32BitConstants(
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    object_->SetGraphicsRoot32BitConstants(
        RootParameterIndex,
        Num32BitValuesToSet,
        pSrcData,
        DestOffsetIn32BitValues);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootConstantBufferView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    object_->SetComputeRootConstantBufferView(
        RootParameterIndex,
        BufferLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootConstantBufferView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    object_->SetGraphicsRootConstantBufferView(
        RootParameterIndex,
        BufferLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootShaderResourceView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    object_->SetComputeRootShaderResourceView(
        RootParameterIndex,
        BufferLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootShaderResourceView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    object_->SetGraphicsRootShaderResourceView(
        RootParameterIndex,
        BufferLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootUnorderedAccessView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    object_->SetComputeRootUnorderedAccessView(
        RootParameterIndex,
        BufferLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootUnorderedAccessView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    object_->SetGraphicsRootUnorderedAccessView(
        RootParameterIndex,
        BufferLocation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::IASetIndexBuffer(
    const D3D12_INDEX_BUFFER_VIEW* pView)
{
    object_->IASetIndexBuffer(
        pView);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::IASetVertexBuffers(
    UINT StartSlot,
    UINT NumViews,
    const D3D12_VERTEX_BUFFER_VIEW* pViews)
{
    object_->IASetVertexBuffers(
        StartSlot,
        NumViews,
        pViews);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SOSetTargets(
    UINT StartSlot,
    UINT NumViews,
    const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews)
{
    object_->SOSetTargets(
        StartSlot,
        NumViews,
        pViews);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::OMSetRenderTargets(
    UINT NumRenderTargetDescriptors,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
    BOOL RTsSingleHandleToDescriptorRange,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor)
{
    object_->OMSetRenderTargets(
        NumRenderTargetDescriptors,
        pRenderTargetDescriptors,
        RTsSingleHandleToDescriptorRange,
        pDepthStencilDescriptor);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearDepthStencilView(
    D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
    D3D12_CLEAR_FLAGS ClearFlags,
    FLOAT Depth,
    UINT8 Stencil,
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    object_->ClearDepthStencilView(
        DepthStencilView,
        ClearFlags,
        Depth,
        Stencil,
        NumRects,
        pRects);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearRenderTargetView(
    D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
    const FLOAT ColorRGBA [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    object_->ClearRenderTargetView(
        RenderTargetView,
        ColorRGBA,
        NumRects,
        pRects);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearUnorderedAccessViewUint(
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const UINT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    object_->ClearUnorderedAccessViewUint(
        ViewGPUHandleInCurrentHeap,
        ViewCPUHandle,
        pResource,
        Values,
        NumRects,
        pRects);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearUnorderedAccessViewFloat(
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const FLOAT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    object_->ClearUnorderedAccessViewFloat(
        ViewGPUHandleInCurrentHeap,
        ViewCPUHandle,
        pResource,
        Values,
        NumRects,
        pRects);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::DiscardResource(
    ID3D12Resource* pResource,
    const D3D12_DISCARD_REGION* pRegion)
{
    object_->DiscardResource(
        pResource,
        pRegion);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::BeginQuery(
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    object_->BeginQuery(
        pQueryHeap,
        Type,
        Index);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::EndQuery(
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    object_->EndQuery(
        pQueryHeap,
        Type,
        Index);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ResolveQueryData(
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT StartIndex,
    UINT NumQueries,
    ID3D12Resource* pDestinationBuffer,
    UINT64 AlignedDestinationBufferOffset)
{
    object_->ResolveQueryData(
        pQueryHeap,
        Type,
        StartIndex,
        NumQueries,
        pDestinationBuffer,
        AlignedDestinationBufferOffset);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetPredication(
    ID3D12Resource* pBuffer,
    UINT64 AlignedBufferOffset,
    D3D12_PREDICATION_OP Operation)
{
    object_->SetPredication(
        pBuffer,
        AlignedBufferOffset,
        Operation);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetMarker(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    object_->SetMarker(
        Metadata,
        pData,
        Size);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::BeginEvent(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    object_->BeginEvent(
        Metadata,
        pData,
        Size);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::EndEvent()
{
    object_->EndEvent();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ExecuteIndirect(
    ID3D12CommandSignature* pCommandSignature,
    UINT MaxCommandCount,
    ID3D12Resource* pArgumentBuffer,
    UINT64 ArgumentBufferOffset,
    ID3D12Resource* pCountBuffer,
    UINT64 CountBufferOffset)
{
    object_->ExecuteIndirect(
        pCommandSignature,
        MaxCommandCount,
        pArgumentBuffer,
        ArgumentBufferOffset,
        pCountBuffer,
        CountBufferOffset);
}

ID3D12GraphicsCommandList1_Wrapper::ID3D12GraphicsCommandList1_Wrapper(REFIID riid, ID3D12GraphicsCommandList1* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::AtomicCopyBufferUINT(
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges)
{
    object_->AtomicCopyBufferUINT(
        pDstBuffer,
        DstOffset,
        pSrcBuffer,
        SrcOffset,
        Dependencies,
        ppDependentResources,
        pDependentSubresourceRanges);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::AtomicCopyBufferUINT64(
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT Dependencies,
    ID3D12Resource* const* ppDependentResources,
    const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges)
{
    object_->AtomicCopyBufferUINT64(
        pDstBuffer,
        DstOffset,
        pSrcBuffer,
        SrcOffset,
        Dependencies,
        ppDependentResources,
        pDependentSubresourceRanges);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::OMSetDepthBounds(
    FLOAT Min,
    FLOAT Max)
{
    object_->OMSetDepthBounds(
        Min,
        Max);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::SetSamplePositions(
    UINT NumSamplesPerPixel,
    UINT NumPixels,
    D3D12_SAMPLE_POSITION* pSamplePositions)
{
    object_->SetSamplePositions(
        NumSamplesPerPixel,
        NumPixels,
        pSamplePositions);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::ResolveSubresourceRegion(
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
    object_->ResolveSubresourceRegion(
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

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::SetViewInstanceMask(
    UINT Mask)
{
    object_->SetViewInstanceMask(
        Mask);
}

ID3D12GraphicsCommandList2_Wrapper::ID3D12GraphicsCommandList2_Wrapper(REFIID riid, ID3D12GraphicsCommandList2* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList1_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList2_Wrapper::WriteBufferImmediate(
    UINT Count,
    const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
    const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes)
{
    object_->WriteBufferImmediate(
        Count,
        pParams,
        pModes);
}

ID3D12CommandQueue_Wrapper::ID3D12CommandQueue_Wrapper(REFIID riid, ID3D12CommandQueue* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::UpdateTileMappings(
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
    object_->UpdateTileMappings(
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

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::CopyTileMappings(
    ID3D12Resource* pDstResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
    ID3D12Resource* pSrcResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS Flags)
{
    object_->CopyTileMappings(
        pDstResource,
        pDstRegionStartCoordinate,
        pSrcResource,
        pSrcRegionStartCoordinate,
        pRegionSize,
        Flags);
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::ExecuteCommandLists(
    UINT NumCommandLists,
    ID3D12CommandList* const* ppCommandLists)
{
    object_->ExecuteCommandLists(
        NumCommandLists,
        ppCommandLists);
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::SetMarker(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    object_->SetMarker(
        Metadata,
        pData,
        Size);
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::BeginEvent(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    object_->BeginEvent(
        Metadata,
        pData,
        Size);
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::EndEvent()
{
    object_->EndEvent();
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::Signal(
    ID3D12Fence* pFence,
    UINT64 Value)
{
    auto result = object_->Signal(
        pFence,
        Value);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::Wait(
    ID3D12Fence* pFence,
    UINT64 Value)
{
    auto result = object_->Wait(
        pFence,
        Value);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::GetTimestampFrequency(
    UINT64* pFrequency)
{
    auto result = object_->GetTimestampFrequency(
        pFrequency);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::GetClockCalibration(
    UINT64* pGpuTimestamp,
    UINT64* pCpuTimestamp)
{
    auto result = object_->GetClockCalibration(
        pGpuTimestamp,
        pCpuTimestamp);

    return result;
}

D3D12_COMMAND_QUEUE_DESC STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::GetDesc()
{
    auto result = object_->GetDesc();

    return result;
}

ID3D12Device_Wrapper::ID3D12Device_Wrapper(REFIID riid, ID3D12Device* object, DxWrapperResources* resources) : ID3D12Object_Wrapper(riid, object, resources), object_(object)
{
}

UINT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetNodeCount()
{
    auto result = object_->GetNodeCount();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandQueue(
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID riid,
    void** ppCommandQueue)
{
    auto result = object_->CreateCommandQueue(
        pDesc,
        riid,
        ppCommandQueue);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppCommandQueue, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandAllocator(
    D3D12_COMMAND_LIST_TYPE type,
    REFIID riid,
    void** ppCommandAllocator)
{
    auto result = object_->CreateCommandAllocator(
        type,
        riid,
        ppCommandAllocator);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppCommandAllocator, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateGraphicsPipelineState(
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto result = object_->CreateGraphicsPipelineState(
        pDesc,
        riid,
        ppPipelineState);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppPipelineState, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateComputePipelineState(
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto result = object_->CreateComputePipelineState(
        pDesc,
        riid,
        ppPipelineState);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppPipelineState, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandList(
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    ID3D12CommandAllocator* pCommandAllocator,
    ID3D12PipelineState* pInitialState,
    REFIID riid,
    void** ppCommandList)
{
    auto result = object_->CreateCommandList(
        nodeMask,
        type,
        pCommandAllocator,
        pInitialState,
        riid,
        ppCommandList);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppCommandList, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CheckFeatureSupport(
    D3D12_FEATURE Feature,
    void* pFeatureSupportData,
    UINT FeatureSupportDataSize)
{
    auto result = object_->CheckFeatureSupport(
        Feature,
        pFeatureSupportData,
        FeatureSupportDataSize);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateDescriptorHeap(
    const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto result = object_->CreateDescriptorHeap(
        pDescriptorHeapDesc,
        riid,
        ppvHeap);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvHeap, nullptr);
    }

    return result;
}

UINT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetDescriptorHandleIncrementSize(
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    auto result = object_->GetDescriptorHandleIncrementSize(
        DescriptorHeapType);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateRootSignature(
    UINT nodeMask,
    const void* pBlobWithRootSignature,
    SIZE_T blobLengthInBytes,
    REFIID riid,
    void** ppvRootSignature)
{
    auto result = object_->CreateRootSignature(
        nodeMask,
        pBlobWithRootSignature,
        blobLengthInBytes,
        riid,
        ppvRootSignature);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvRootSignature, nullptr);
    }

    return result;
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateConstantBufferView(
    const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    object_->CreateConstantBufferView(
        pDesc,
        DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateShaderResourceView(
    ID3D12Resource* pResource,
    const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    object_->CreateShaderResourceView(
        pResource,
        pDesc,
        DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateUnorderedAccessView(
    ID3D12Resource* pResource,
    ID3D12Resource* pCounterResource,
    const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    object_->CreateUnorderedAccessView(
        pResource,
        pCounterResource,
        pDesc,
        DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateRenderTargetView(
    ID3D12Resource* pResource,
    const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    object_->CreateRenderTargetView(
        pResource,
        pDesc,
        DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateDepthStencilView(
    ID3D12Resource* pResource,
    const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    object_->CreateDepthStencilView(
        pResource,
        pDesc,
        DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateSampler(
    const D3D12_SAMPLER_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    object_->CreateSampler(
        pDesc,
        DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CopyDescriptors(
    UINT NumDestDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
    const UINT* pDestDescriptorRangeSizes,
    UINT NumSrcDescriptorRanges,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
    const UINT* pSrcDescriptorRangeSizes,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    object_->CopyDescriptors(
        NumDestDescriptorRanges,
        pDestDescriptorRangeStarts,
        pDestDescriptorRangeSizes,
        NumSrcDescriptorRanges,
        pSrcDescriptorRangeStarts,
        pSrcDescriptorRangeSizes,
        DescriptorHeapsType);
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CopyDescriptorsSimple(
    UINT NumDescriptors,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    object_->CopyDescriptorsSimple(
        NumDescriptors,
        DestDescriptorRangeStart,
        SrcDescriptorRangeStart,
        DescriptorHeapsType);
}

D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE ID3D12Device_Wrapper::GetResourceAllocationInfo(
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs)
{
    auto result = object_->GetResourceAllocationInfo(
        visibleMask,
        numResourceDescs,
        pResourceDescs);

    return result;
}

D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE ID3D12Device_Wrapper::GetCustomHeapProperties(
    UINT nodeMask,
    D3D12_HEAP_TYPE heapType)
{
    auto result = object_->GetCustomHeapProperties(
        nodeMask,
        heapType);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommittedResource(
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riidResource,
    void** ppvResource)
{
    auto result = object_->CreateCommittedResource(
        pHeapProperties,
        HeapFlags,
        pDesc,
        InitialResourceState,
        pOptimizedClearValue,
        riidResource,
        ppvResource);

    if (SUCCEEDED(result))
    {
        WrapObject(riidResource, ppvResource, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateHeap(
    const D3D12_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto result = object_->CreateHeap(
        pDesc,
        riid,
        ppvHeap);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvHeap, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreatePlacedResource(
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto result = object_->CreatePlacedResource(
        pHeap,
        HeapOffset,
        pDesc,
        InitialState,
        pOptimizedClearValue,
        riid,
        ppvResource);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvResource, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateReservedResource(
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto result = object_->CreateReservedResource(
        pDesc,
        InitialState,
        pOptimizedClearValue,
        riid,
        ppvResource);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvResource, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateSharedHandle(
    ID3D12DeviceChild* pObject,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD Access,
    LPCWSTR Name,
    HANDLE* pHandle)
{
    auto result = object_->CreateSharedHandle(
        pObject,
        pAttributes,
        Access,
        Name,
        pHandle);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::OpenSharedHandle(
    HANDLE NTHandle,
    REFIID riid,
    void** ppvObj)
{
    auto result = object_->OpenSharedHandle(
        NTHandle,
        riid,
        ppvObj);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvObj, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::OpenSharedHandleByName(
    LPCWSTR Name,
    DWORD Access,
    HANDLE* pNTHandle)
{
    auto result = object_->OpenSharedHandleByName(
        Name,
        Access,
        pNTHandle);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::MakeResident(
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    auto result = object_->MakeResident(
        NumObjects,
        ppObjects);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::Evict(
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    auto result = object_->Evict(
        NumObjects,
        ppObjects);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateFence(
    UINT64 InitialValue,
    D3D12_FENCE_FLAGS Flags,
    REFIID riid,
    void** ppFence)
{
    auto result = object_->CreateFence(
        InitialValue,
        Flags,
        riid,
        ppFence);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppFence, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetDeviceRemovedReason()
{
    auto result = object_->GetDeviceRemovedReason();

    return result;
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::GetCopyableFootprints(
    const D3D12_RESOURCE_DESC* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes)
{
    object_->GetCopyableFootprints(
        pResourceDesc,
        FirstSubresource,
        NumSubresources,
        BaseOffset,
        pLayouts,
        pNumRows,
        pRowSizeInBytes,
        pTotalBytes);
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateQueryHeap(
    const D3D12_QUERY_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    auto result = object_->CreateQueryHeap(
        pDesc,
        riid,
        ppvHeap);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvHeap, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::SetStablePowerState(
    BOOL Enable)
{
    auto result = object_->SetStablePowerState(
        Enable);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandSignature(
    const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
    ID3D12RootSignature* pRootSignature,
    REFIID riid,
    void** ppvCommandSignature)
{
    auto result = object_->CreateCommandSignature(
        pDesc,
        pRootSignature,
        riid,
        ppvCommandSignature);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvCommandSignature, nullptr);
    }

    return result;
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::GetResourceTiling(
    ID3D12Resource* pTiledResource,
    UINT* pNumTilesForEntireResource,
    D3D12_PACKED_MIP_INFO* pPackedMipDesc,
    D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
    UINT* pNumSubresourceTilings,
    UINT FirstSubresourceTilingToGet,
    D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips)
{
    object_->GetResourceTiling(
        pTiledResource,
        pNumTilesForEntireResource,
        pPackedMipDesc,
        pStandardTileShapeForNonPackedMips,
        pNumSubresourceTilings,
        FirstSubresourceTilingToGet,
        pSubresourceTilingsForNonPackedMips);
}

LUID STDMETHODCALLTYPE ID3D12Device_Wrapper::GetAdapterLuid()
{
    auto result = object_->GetAdapterLuid();

    return result;
}

ID3D12PipelineLibrary_Wrapper::ID3D12PipelineLibrary_Wrapper(REFIID riid, ID3D12PipelineLibrary* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::StorePipeline(
    LPCWSTR pName,
    ID3D12PipelineState* pPipeline)
{
    auto result = object_->StorePipeline(
        pName,
        pPipeline);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::LoadGraphicsPipeline(
    LPCWSTR pName,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto result = object_->LoadGraphicsPipeline(
        pName,
        pDesc,
        riid,
        ppPipelineState);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppPipelineState, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::LoadComputePipeline(
    LPCWSTR pName,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto result = object_->LoadComputePipeline(
        pName,
        pDesc,
        riid,
        ppPipelineState);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppPipelineState, nullptr);
    }

    return result;
}

SIZE_T STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::GetSerializedSize()
{
    auto result = object_->GetSerializedSize();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::Serialize(
    void* pData,
    SIZE_T DataSizeInBytes)
{
    auto result = object_->Serialize(
        pData,
        DataSizeInBytes);

    return result;
}

ID3D12PipelineLibrary1_Wrapper::ID3D12PipelineLibrary1_Wrapper(REFIID riid, ID3D12PipelineLibrary1* object, DxWrapperResources* resources) : ID3D12PipelineLibrary_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary1_Wrapper::LoadPipeline(
    LPCWSTR pName,
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto result = object_->LoadPipeline(
        pName,
        pDesc,
        riid,
        ppPipelineState);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppPipelineState, nullptr);
    }

    return result;
}

ID3D12Device1_Wrapper::ID3D12Device1_Wrapper(REFIID riid, ID3D12Device1* object, DxWrapperResources* resources) : ID3D12Device_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device1_Wrapper::CreatePipelineLibrary(
    const void* pLibraryBlob,
    SIZE_T BlobLength,
    REFIID riid,
    void** ppPipelineLibrary)
{
    auto result = object_->CreatePipelineLibrary(
        pLibraryBlob,
        BlobLength,
        riid,
        ppPipelineLibrary);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppPipelineLibrary, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device1_Wrapper::SetEventOnMultipleFenceCompletion(
    ID3D12Fence* const* ppFences,
    const UINT64* pFenceValues,
    UINT NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
    HANDLE hEvent)
{
    auto result = object_->SetEventOnMultipleFenceCompletion(
        ppFences,
        pFenceValues,
        NumFences,
        Flags,
        hEvent);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device1_Wrapper::SetResidencyPriority(
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    const D3D12_RESIDENCY_PRIORITY* pPriorities)
{
    auto result = object_->SetResidencyPriority(
        NumObjects,
        ppObjects,
        pPriorities);

    return result;
}

ID3D12Device2_Wrapper::ID3D12Device2_Wrapper(REFIID riid, ID3D12Device2* object, DxWrapperResources* resources) : ID3D12Device1_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device2_Wrapper::CreatePipelineState(
    const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    auto result = object_->CreatePipelineState(
        pDesc,
        riid,
        ppPipelineState);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppPipelineState, nullptr);
    }

    return result;
}

ID3D12Device3_Wrapper::ID3D12Device3_Wrapper(REFIID riid, ID3D12Device3* object, DxWrapperResources* resources) : ID3D12Device2_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device3_Wrapper::OpenExistingHeapFromAddress(
    const void* pAddress,
    REFIID riid,
    void** ppvHeap)
{
    auto result = object_->OpenExistingHeapFromAddress(
        pAddress,
        riid,
        ppvHeap);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvHeap, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device3_Wrapper::OpenExistingHeapFromFileMapping(
    HANDLE hFileMapping,
    REFIID riid,
    void** ppvHeap)
{
    auto result = object_->OpenExistingHeapFromFileMapping(
        hFileMapping,
        riid,
        ppvHeap);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvHeap, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device3_Wrapper::EnqueueMakeResident(
    D3D12_RESIDENCY_FLAGS Flags,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    ID3D12Fence* pFenceToSignal,
    UINT64 FenceValueToSignal)
{
    auto result = object_->EnqueueMakeResident(
        Flags,
        NumObjects,
        ppObjects,
        pFenceToSignal,
        FenceValueToSignal);

    return result;
}

ID3D12ProtectedSession_Wrapper::ID3D12ProtectedSession_Wrapper(REFIID riid, ID3D12ProtectedSession* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12ProtectedSession_Wrapper::GetStatusFence(
    REFIID riid,
    void** ppFence)
{
    auto result = object_->GetStatusFence(
        riid,
        ppFence);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppFence, nullptr);
    }

    return result;
}

D3D12_PROTECTED_SESSION_STATUS STDMETHODCALLTYPE ID3D12ProtectedSession_Wrapper::GetSessionStatus()
{
    auto result = object_->GetSessionStatus();

    return result;
}

ID3D12ProtectedResourceSession_Wrapper::ID3D12ProtectedResourceSession_Wrapper(REFIID riid, ID3D12ProtectedResourceSession* object, DxWrapperResources* resources) : ID3D12ProtectedSession_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_PROTECTED_RESOURCE_SESSION_DESC STDMETHODCALLTYPE ID3D12ProtectedResourceSession_Wrapper::GetDesc()
{
    auto result = object_->GetDesc();

    return result;
}

ID3D12Device4_Wrapper::ID3D12Device4_Wrapper(REFIID riid, ID3D12Device4* object, DxWrapperResources* resources) : ID3D12Device3_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device4_Wrapper::CreateCommandList1(
    UINT nodeMask,
    D3D12_COMMAND_LIST_TYPE type,
    D3D12_COMMAND_LIST_FLAGS flags,
    REFIID riid,
    void** ppCommandList)
{
    auto result = object_->CreateCommandList1(
        nodeMask,
        type,
        flags,
        riid,
        ppCommandList);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppCommandList, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device4_Wrapper::CreateProtectedResourceSession(
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppSession)
{
    auto result = object_->CreateProtectedResourceSession(
        pDesc,
        riid,
        ppSession);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppSession, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device4_Wrapper::CreateCommittedResource1(
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riidResource,
    void** ppvResource)
{
    auto result = object_->CreateCommittedResource1(
        pHeapProperties,
        HeapFlags,
        pDesc,
        InitialResourceState,
        pOptimizedClearValue,
        pProtectedSession,
        riidResource,
        ppvResource);

    if (SUCCEEDED(result))
    {
        WrapObject(riidResource, ppvResource, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device4_Wrapper::CreateHeap1(
    const D3D12_HEAP_DESC* pDesc,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvHeap)
{
    auto result = object_->CreateHeap1(
        pDesc,
        pProtectedSession,
        riid,
        ppvHeap);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvHeap, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device4_Wrapper::CreateReservedResource1(
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvResource)
{
    auto result = object_->CreateReservedResource1(
        pDesc,
        InitialState,
        pOptimizedClearValue,
        pProtectedSession,
        riid,
        ppvResource);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvResource, nullptr);
    }

    return result;
}

D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE ID3D12Device4_Wrapper::GetResourceAllocationInfo1(
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    auto result = object_->GetResourceAllocationInfo1(
        visibleMask,
        numResourceDescs,
        pResourceDescs,
        pResourceAllocationInfo1);

    return result;
}

ID3D12LifetimeOwner_Wrapper::ID3D12LifetimeOwner_Wrapper(REFIID riid, ID3D12LifetimeOwner* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12LifetimeOwner_Wrapper::LifetimeStateUpdated(
    D3D12_LIFETIME_STATE NewState)
{
    object_->LifetimeStateUpdated(
        NewState);
}

ID3D12SwapChainAssistant_Wrapper::ID3D12SwapChainAssistant_Wrapper(REFIID riid, ID3D12SwapChainAssistant* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

LUID STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::GetLUID()
{
    auto result = object_->GetLUID();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::GetSwapChainObject(
    REFIID riid,
    void** ppv)
{
    auto result = object_->GetSwapChainObject(
        riid,
        ppv);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppv, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::GetCurrentResourceAndCommandQueue(
    REFIID riidResource,
    void** ppvResource,
    REFIID riidQueue,
    void** ppvQueue)
{
    auto result = object_->GetCurrentResourceAndCommandQueue(
        riidResource,
        ppvResource,
        riidQueue,
        ppvQueue);

    if (SUCCEEDED(result))
    {
        WrapObject(riidResource, ppvResource, nullptr);
        WrapObject(riidQueue, ppvQueue, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::InsertImplicitSync()
{
    auto result = object_->InsertImplicitSync();

    return result;
}

ID3D12LifetimeTracker_Wrapper::ID3D12LifetimeTracker_Wrapper(REFIID riid, ID3D12LifetimeTracker* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12LifetimeTracker_Wrapper::DestroyOwnedObject(
    ID3D12DeviceChild* pObject)
{
    auto result = object_->DestroyOwnedObject(
        pObject);

    return result;
}

ID3D12StateObject_Wrapper::ID3D12StateObject_Wrapper(REFIID riid, ID3D12StateObject* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

ID3D12StateObjectProperties_Wrapper::ID3D12StateObjectProperties_Wrapper(REFIID riid, ID3D12StateObjectProperties* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

void* STDMETHODCALLTYPE ID3D12StateObjectProperties_Wrapper::GetShaderIdentifier(
    LPCWSTR pExportName)
{
    auto result = object_->GetShaderIdentifier(
        pExportName);

    return result;
}

UINT64 STDMETHODCALLTYPE ID3D12StateObjectProperties_Wrapper::GetShaderStackSize(
    LPCWSTR pExportName)
{
    auto result = object_->GetShaderStackSize(
        pExportName);

    return result;
}

UINT64 STDMETHODCALLTYPE ID3D12StateObjectProperties_Wrapper::GetPipelineStackSize()
{
    auto result = object_->GetPipelineStackSize();

    return result;
}

void STDMETHODCALLTYPE ID3D12StateObjectProperties_Wrapper::SetPipelineStackSize(
    UINT64 PipelineStackSizeInBytes)
{
    object_->SetPipelineStackSize(
        PipelineStackSizeInBytes);
}

ID3D12Device5_Wrapper::ID3D12Device5_Wrapper(REFIID riid, ID3D12Device5* object, DxWrapperResources* resources) : ID3D12Device4_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::CreateLifetimeTracker(
    ID3D12LifetimeOwner* pOwner,
    REFIID riid,
    void** ppvTracker)
{
    auto result = object_->CreateLifetimeTracker(
        pOwner,
        riid,
        ppvTracker);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvTracker, nullptr);
    }

    return result;
}

void STDMETHODCALLTYPE ID3D12Device5_Wrapper::RemoveDevice()
{
    object_->RemoveDevice();
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::EnumerateMetaCommands(
    UINT* pNumMetaCommands,
    D3D12_META_COMMAND_DESC* pDescs)
{
    auto result = object_->EnumerateMetaCommands(
        pNumMetaCommands,
        pDescs);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::EnumerateMetaCommandParameters(
    REFGUID CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT* pTotalStructureSizeInBytes,
    UINT* pParameterCount,
    D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs)
{
    auto result = object_->EnumerateMetaCommandParameters(
        CommandId,
        Stage,
        pTotalStructureSizeInBytes,
        pParameterCount,
        pParameterDescs);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::CreateMetaCommand(
    REFGUID CommandId,
    UINT NodeMask,
    const void* pCreationParametersData,
    SIZE_T CreationParametersDataSizeInBytes,
    REFIID riid,
    void** ppMetaCommand)
{
    auto result = object_->CreateMetaCommand(
        CommandId,
        NodeMask,
        pCreationParametersData,
        CreationParametersDataSizeInBytes,
        riid,
        ppMetaCommand);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppMetaCommand, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::CreateStateObject(
    const D3D12_STATE_OBJECT_DESC* pDesc,
    REFIID riid,
    void** ppStateObject)
{
    auto result = object_->CreateStateObject(
        pDesc,
        riid,
        ppStateObject);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppStateObject, nullptr);
    }

    return result;
}

void STDMETHODCALLTYPE ID3D12Device5_Wrapper::GetRaytracingAccelerationStructurePrebuildInfo(
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo)
{
    object_->GetRaytracingAccelerationStructurePrebuildInfo(
        pDesc,
        pInfo);
}

D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS STDMETHODCALLTYPE ID3D12Device5_Wrapper::CheckDriverMatchingIdentifier(
    D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
    const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck)
{
    auto result = object_->CheckDriverMatchingIdentifier(
        SerializedDataType,
        pIdentifierToCheck);

    return result;
}

ID3D12DeviceRemovedExtendedDataSettings_Wrapper::ID3D12DeviceRemovedExtendedDataSettings_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings_Wrapper::SetAutoBreadcrumbsEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    object_->SetAutoBreadcrumbsEnablement(
        Enablement);
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings_Wrapper::SetPageFaultEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    object_->SetPageFaultEnablement(
        Enablement);
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings_Wrapper::SetWatsonDumpEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    object_->SetWatsonDumpEnablement(
        Enablement);
}

ID3D12DeviceRemovedExtendedDataSettings1_Wrapper::ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings1* object, DxWrapperResources* resources) : ID3D12DeviceRemovedExtendedDataSettings_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings1_Wrapper::SetBreadcrumbContextEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    object_->SetBreadcrumbContextEnablement(
        Enablement);
}

ID3D12DeviceRemovedExtendedData_Wrapper::ID3D12DeviceRemovedExtendedData_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedData* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData_Wrapper::GetAutoBreadcrumbsOutput(
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput)
{
    auto result = object_->GetAutoBreadcrumbsOutput(
        pOutput);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData_Wrapper::GetPageFaultAllocationOutput(
    D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput)
{
    auto result = object_->GetPageFaultAllocationOutput(
        pOutput);

    return result;
}

ID3D12DeviceRemovedExtendedData1_Wrapper::ID3D12DeviceRemovedExtendedData1_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedData1* object, DxWrapperResources* resources) : ID3D12DeviceRemovedExtendedData_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData1_Wrapper::GetAutoBreadcrumbsOutput1(
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput)
{
    auto result = object_->GetAutoBreadcrumbsOutput1(
        pOutput);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData1_Wrapper::GetPageFaultAllocationOutput1(
    D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput)
{
    auto result = object_->GetPageFaultAllocationOutput1(
        pOutput);

    return result;
}

ID3D12Device6_Wrapper::ID3D12Device6_Wrapper(REFIID riid, ID3D12Device6* object, DxWrapperResources* resources) : ID3D12Device5_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device6_Wrapper::SetBackgroundProcessingMode(
    D3D12_BACKGROUND_PROCESSING_MODE Mode,
    D3D12_MEASUREMENTS_ACTION MeasurementsAction,
    HANDLE hEventToSignalUponCompletion,
    BOOL* pbFurtherMeasurementsDesired)
{
    auto result = object_->SetBackgroundProcessingMode(
        Mode,
        MeasurementsAction,
        hEventToSignalUponCompletion,
        pbFurtherMeasurementsDesired);

    return result;
}

ID3D12ProtectedResourceSession1_Wrapper::ID3D12ProtectedResourceSession1_Wrapper(REFIID riid, ID3D12ProtectedResourceSession1* object, DxWrapperResources* resources) : ID3D12ProtectedResourceSession_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_PROTECTED_RESOURCE_SESSION_DESC1 STDMETHODCALLTYPE ID3D12ProtectedResourceSession1_Wrapper::GetDesc1()
{
    auto result = object_->GetDesc1();

    return result;
}

ID3D12Device7_Wrapper::ID3D12Device7_Wrapper(REFIID riid, ID3D12Device7* object, DxWrapperResources* resources) : ID3D12Device6_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device7_Wrapper::AddToStateObject(
    const D3D12_STATE_OBJECT_DESC* pAddition,
    ID3D12StateObject* pStateObjectToGrowFrom,
    REFIID riid,
    void** ppNewStateObject)
{
    auto result = object_->AddToStateObject(
        pAddition,
        pStateObjectToGrowFrom,
        riid,
        ppNewStateObject);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppNewStateObject, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device7_Wrapper::CreateProtectedResourceSession1(
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
    REFIID riid,
    void** ppSession)
{
    auto result = object_->CreateProtectedResourceSession1(
        pDesc,
        riid,
        ppSession);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppSession, nullptr);
    }

    return result;
}

ID3D12Device8_Wrapper::ID3D12Device8_Wrapper(REFIID riid, ID3D12Device8* object, DxWrapperResources* resources) : ID3D12Device7_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE ID3D12Device8_Wrapper::GetResourceAllocationInfo2(
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC1* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    auto result = object_->GetResourceAllocationInfo2(
        visibleMask,
        numResourceDescs,
        pResourceDescs,
        pResourceAllocationInfo1);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device8_Wrapper::CreateCommittedResource2(
    const D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS HeapFlags,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialResourceState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riidResource,
    void** ppvResource)
{
    auto result = object_->CreateCommittedResource2(
        pHeapProperties,
        HeapFlags,
        pDesc,
        InitialResourceState,
        pOptimizedClearValue,
        pProtectedSession,
        riidResource,
        ppvResource);

    if (SUCCEEDED(result))
    {
        WrapObject(riidResource, ppvResource, nullptr);
    }

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device8_Wrapper::CreatePlacedResource1(
    ID3D12Heap* pHeap,
    UINT64 HeapOffset,
    const D3D12_RESOURCE_DESC1* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    auto result = object_->CreatePlacedResource1(
        pHeap,
        HeapOffset,
        pDesc,
        InitialState,
        pOptimizedClearValue,
        riid,
        ppvResource);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppvResource, nullptr);
    }

    return result;
}

void STDMETHODCALLTYPE ID3D12Device8_Wrapper::CreateSamplerFeedbackUnorderedAccessView(
    ID3D12Resource* pTargetedResource,
    ID3D12Resource* pFeedbackResource,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    object_->CreateSamplerFeedbackUnorderedAccessView(
        pTargetedResource,
        pFeedbackResource,
        DestDescriptor);
}

void STDMETHODCALLTYPE ID3D12Device8_Wrapper::GetCopyableFootprints1(
    const D3D12_RESOURCE_DESC1* pResourceDesc,
    UINT FirstSubresource,
    UINT NumSubresources,
    UINT64 BaseOffset,
    D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
    UINT* pNumRows,
    UINT64* pRowSizeInBytes,
    UINT64* pTotalBytes)
{
    object_->GetCopyableFootprints1(
        pResourceDesc,
        FirstSubresource,
        NumSubresources,
        BaseOffset,
        pLayouts,
        pNumRows,
        pRowSizeInBytes,
        pTotalBytes);
}

ID3D12Resource1_Wrapper::ID3D12Resource1_Wrapper(REFIID riid, ID3D12Resource1* object, DxWrapperResources* resources) : ID3D12Resource_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Resource1_Wrapper::GetProtectedResourceSession(
    REFIID riid,
    void** ppProtectedSession)
{
    auto result = object_->GetProtectedResourceSession(
        riid,
        ppProtectedSession);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppProtectedSession, nullptr);
    }

    return result;
}

ID3D12Resource2_Wrapper::ID3D12Resource2_Wrapper(REFIID riid, ID3D12Resource2* object, DxWrapperResources* resources) : ID3D12Resource1_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_RESOURCE_DESC1 STDMETHODCALLTYPE ID3D12Resource2_Wrapper::GetDesc1()
{
    auto result = object_->GetDesc1();

    return result;
}

ID3D12Heap1_Wrapper::ID3D12Heap1_Wrapper(REFIID riid, ID3D12Heap1* object, DxWrapperResources* resources) : ID3D12Heap_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Heap1_Wrapper::GetProtectedResourceSession(
    REFIID riid,
    void** ppProtectedSession)
{
    auto result = object_->GetProtectedResourceSession(
        riid,
        ppProtectedSession);

    if (SUCCEEDED(result))
    {
        WrapObject(riid, ppProtectedSession, nullptr);
    }

    return result;
}

ID3D12GraphicsCommandList3_Wrapper::ID3D12GraphicsCommandList3_Wrapper(REFIID riid, ID3D12GraphicsCommandList3* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList2_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList3_Wrapper::SetProtectedResourceSession(
    ID3D12ProtectedResourceSession* pProtectedResourceSession)
{
    object_->SetProtectedResourceSession(
        pProtectedResourceSession);
}

ID3D12MetaCommand_Wrapper::ID3D12MetaCommand_Wrapper(REFIID riid, ID3D12MetaCommand* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

UINT64 STDMETHODCALLTYPE ID3D12MetaCommand_Wrapper::GetRequiredParameterResourceSize(
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT ParameterIndex)
{
    auto result = object_->GetRequiredParameterResourceSize(
        Stage,
        ParameterIndex);

    return result;
}

ID3D12GraphicsCommandList4_Wrapper::ID3D12GraphicsCommandList4_Wrapper(REFIID riid, ID3D12GraphicsCommandList4* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList3_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::BeginRenderPass(
    UINT NumRenderTargets,
    const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
    const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
    D3D12_RENDER_PASS_FLAGS Flags)
{
    object_->BeginRenderPass(
        NumRenderTargets,
        pRenderTargets,
        pDepthStencil,
        Flags);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::EndRenderPass()
{
    object_->EndRenderPass();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::InitializeMetaCommand(
    ID3D12MetaCommand* pMetaCommand,
    const void* pInitializationParametersData,
    SIZE_T InitializationParametersDataSizeInBytes)
{
    object_->InitializeMetaCommand(
        pMetaCommand,
        pInitializationParametersData,
        InitializationParametersDataSizeInBytes);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::ExecuteMetaCommand(
    ID3D12MetaCommand* pMetaCommand,
    const void* pExecutionParametersData,
    SIZE_T ExecutionParametersDataSizeInBytes)
{
    object_->ExecuteMetaCommand(
        pMetaCommand,
        pExecutionParametersData,
        ExecutionParametersDataSizeInBytes);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::BuildRaytracingAccelerationStructure(
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
    UINT NumPostbuildInfoDescs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs)
{
    object_->BuildRaytracingAccelerationStructure(
        pDesc,
        NumPostbuildInfoDescs,
        pPostbuildInfoDescs);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::EmitRaytracingAccelerationStructurePostbuildInfo(
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
    UINT NumSourceAccelerationStructures,
    const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData)
{
    object_->EmitRaytracingAccelerationStructurePostbuildInfo(
        pDesc,
        NumSourceAccelerationStructures,
        pSourceAccelerationStructureData);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::CopyRaytracingAccelerationStructure(
    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    object_->CopyRaytracingAccelerationStructure(
        DestAccelerationStructureData,
        SourceAccelerationStructureData,
        Mode);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::SetPipelineState1(
    ID3D12StateObject* pStateObject)
{
    object_->SetPipelineState1(
        pStateObject);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::DispatchRays(
    const D3D12_DISPATCH_RAYS_DESC* pDesc)
{
    object_->DispatchRays(
        pDesc);
}

ID3D12Tools_Wrapper::ID3D12Tools_Wrapper(REFIID riid, ID3D12Tools* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12Tools_Wrapper::EnableShaderInstrumentation(
    BOOL bEnable)
{
    object_->EnableShaderInstrumentation(
        bEnable);
}

BOOL STDMETHODCALLTYPE ID3D12Tools_Wrapper::ShaderInstrumentationEnabled()
{
    auto result = object_->ShaderInstrumentationEnabled();

    return result;
}

ID3D12GraphicsCommandList5_Wrapper::ID3D12GraphicsCommandList5_Wrapper(REFIID riid, ID3D12GraphicsCommandList5* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList4_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList5_Wrapper::RSSetShadingRate(
    D3D12_SHADING_RATE baseShadingRate,
    const D3D12_SHADING_RATE_COMBINER* combiners)
{
    object_->RSSetShadingRate(
        baseShadingRate,
        combiners);
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList5_Wrapper::RSSetShadingRateImage(
    ID3D12Resource* shadingRateImage)
{
    object_->RSSetShadingRateImage(
        shadingRateImage);
}

ID3D12GraphicsCommandList6_Wrapper::ID3D12GraphicsCommandList6_Wrapper(REFIID riid, ID3D12GraphicsCommandList6* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList5_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList6_Wrapper::DispatchMesh(
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    object_->DispatchMesh(
        ThreadGroupCountX,
        ThreadGroupCountY,
        ThreadGroupCountZ);
}


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/

ID3D10Blob_Wrapper::ID3D10Blob_Wrapper(REFIID riid, ID3D10Blob* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

LPVOID STDMETHODCALLTYPE ID3D10Blob_Wrapper::GetBufferPointer()
{
    auto result = object_->GetBufferPointer();

    return result;
}

SIZE_T STDMETHODCALLTYPE ID3D10Blob_Wrapper::GetBufferSize()
{
    auto result = object_->GetBufferSize();

    return result;
}

ID3DDestructionNotifier_Wrapper::ID3DDestructionNotifier_Wrapper(REFIID riid, ID3DDestructionNotifier* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3DDestructionNotifier_Wrapper::RegisterDestructionCallback(
    PFN_DESTRUCTION_CALLBACK callbackFn,
    void* pData,
    UINT* pCallbackID)
{
    auto result = object_->RegisterDestructionCallback(
        callbackFn,
        pData,
        pCallbackID);

    return result;
}

HRESULT STDMETHODCALLTYPE ID3DDestructionNotifier_Wrapper::UnregisterDestructionCallback(
    UINT callbackID)
{
    auto result = object_->UnregisterDestructionCallback(
        callbackID);

    return result;
}


/*
** This part is generated from Unknwnbase.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from guiddef.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from windef.h in Windows SDK: 10.0.19041.0
**
*/


/*
** This part is generated from minwinbase.h in Windows SDK: 10.0.19041.0
**
*/

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
