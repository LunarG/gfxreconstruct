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

#include "encode/custom_dx12_struct_unwrappers.h"
#include "encode/d3d12_dispatch_table.h"
#include "encode/dx12_object_wrapper_util.h"
#include "encode/dxgi_dispatch_table.h"
#include "encode/trace_manager.h"
#include "generated/generated_dx12_struct_unwrappers.h"
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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory(
            riid,
            ppFactory);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppFactory, nullptr);
        }
    }
    else
    {
        auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory(
            riid,
            ppFactory);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI CreateDXGIFactory1(
    REFIID riid,
    void** ppFactory)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory1(
            riid,
            ppFactory);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppFactory, nullptr);
        }
    }
    else
    {
        auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory1(
            riid,
            ppFactory);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetPrivateData(
            Name,
            DataSize,
            pData);
    }
    else
    {
        result = object_->SetPrivateData(
            Name,
            DataSize,
            pData);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIObject_Wrapper::SetPrivateDataInterface(
    REFGUID Name,
    const IUnknown* pUnknown)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetPrivateDataInterface(
            Name,
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pUnknown));
    }
    else
    {
        result = object_->SetPrivateDataInterface(
            Name,
            pUnknown);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIObject_Wrapper::GetPrivateData(
    REFGUID Name,
    UINT* pDataSize,
    void* pData)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetPrivateData(
            Name,
            pDataSize,
            pData);
    }
    else
    {
        result = object_->GetPrivateData(
            Name,
            pDataSize,
            pData);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIObject_Wrapper::GetParent(
    REFIID riid,
    void** ppParent)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetParent(
            riid,
            ppParent);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppParent, nullptr);
        }
    }
    else
    {
        result = object_->GetParent(
            riid,
            ppParent);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIDeviceSubObject_Wrapper::IDXGIDeviceSubObject_Wrapper(REFIID riid, IDXGIDeviceSubObject* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDeviceSubObject_Wrapper::GetDevice(
    REFIID riid,
    void** ppDevice)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDevice(
            riid,
            ppDevice);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppDevice, nullptr);
        }
    }
    else
    {
        result = object_->GetDevice(
            riid,
            ppDevice);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIResource_Wrapper::IDXGIResource_Wrapper(REFIID riid, IDXGIResource* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::GetSharedHandle(
    HANDLE* pSharedHandle)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetSharedHandle(
            pSharedHandle);
    }
    else
    {
        result = object_->GetSharedHandle(
            pSharedHandle);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::GetUsage(
    DXGI_USAGE* pUsage)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetUsage(
            pUsage);
    }
    else
    {
        result = object_->GetUsage(
            pUsage);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::SetEvictionPriority(
    UINT EvictionPriority)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetEvictionPriority(
            EvictionPriority);
    }
    else
    {
        result = object_->SetEvictionPriority(
            EvictionPriority);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource_Wrapper::GetEvictionPriority(
    UINT* pEvictionPriority)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetEvictionPriority(
            pEvictionPriority);
    }
    else
    {
        result = object_->GetEvictionPriority(
            pEvictionPriority);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIKeyedMutex_Wrapper::IDXGIKeyedMutex_Wrapper(REFIID riid, IDXGIKeyedMutex* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIKeyedMutex_Wrapper::AcquireSync(
    UINT64 Key,
    DWORD dwMilliseconds)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->AcquireSync(
            Key,
            dwMilliseconds);
    }
    else
    {
        result = object_->AcquireSync(
            Key,
            dwMilliseconds);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIKeyedMutex_Wrapper::ReleaseSync(
    UINT64 Key)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->ReleaseSync(
            Key);
    }
    else
    {
        result = object_->ReleaseSync(
            Key);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGISurface_Wrapper::IDXGISurface_Wrapper(REFIID riid, IDXGISurface* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISurface_Wrapper::GetDesc(
    DXGI_SURFACE_DESC* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc(
            pDesc);
    }
    else
    {
        result = object_->GetDesc(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISurface_Wrapper::Map(
    DXGI_MAPPED_RECT* pLockedRect,
    UINT MapFlags)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Map(
            pLockedRect,
            MapFlags);
    }
    else
    {
        result = object_->Map(
            pLockedRect,
            MapFlags);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISurface_Wrapper::Unmap()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Unmap();
    }
    else
    {
        result = object_->Unmap();
    }

    manager->DecrementCallScope();

    return result;
}

IDXGISurface1_Wrapper::IDXGISurface1_Wrapper(REFIID riid, IDXGISurface1* object, DxWrapperResources* resources) : IDXGISurface_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISurface1_Wrapper::GetDC(
    BOOL Discard,
    HDC* phdc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDC(
            Discard,
            phdc);
    }
    else
    {
        result = object_->GetDC(
            Discard,
            phdc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISurface1_Wrapper::ReleaseDC(
    RECT* pDirtyRect)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->ReleaseDC(
            pDirtyRect);
    }
    else
    {
        result = object_->ReleaseDC(
            pDirtyRect);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIAdapter_Wrapper::IDXGIAdapter_Wrapper(REFIID riid, IDXGIAdapter* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter_Wrapper::EnumOutputs(
    UINT Output,
    IDXGIOutput** ppOutput)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumOutputs(
            Output,
            ppOutput);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppOutput), nullptr);
        }
    }
    else
    {
        result = object_->EnumOutputs(
            Output,
            ppOutput);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter_Wrapper::GetDesc(
    DXGI_ADAPTER_DESC* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc(
            pDesc);
    }
    else
    {
        result = object_->GetDesc(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter_Wrapper::CheckInterfaceSupport(
    REFGUID InterfaceName,
    LARGE_INTEGER* pUMDVersion)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckInterfaceSupport(
            InterfaceName,
            pUMDVersion);
    }
    else
    {
        result = object_->CheckInterfaceSupport(
            InterfaceName,
            pUMDVersion);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIOutput_Wrapper::IDXGIOutput_Wrapper(REFIID riid, IDXGIOutput* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetDesc(
    DXGI_OUTPUT_DESC* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc(
            pDesc);
    }
    else
    {
        result = object_->GetDesc(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetDisplayModeList(
    DXGI_FORMAT EnumFormat,
    UINT Flags,
    UINT* pNumModes,
    DXGI_MODE_DESC* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDisplayModeList(
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
    }
    else
    {
        result = object_->GetDisplayModeList(
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::FindClosestMatchingMode(
    const DXGI_MODE_DESC* pModeToMatch,
    DXGI_MODE_DESC* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->FindClosestMatchingMode(
            pModeToMatch,
            pClosestMatch,
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pConcernedDevice));
    }
    else
    {
        result = object_->FindClosestMatchingMode(
            pModeToMatch,
            pClosestMatch,
            pConcernedDevice);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::WaitForVBlank()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->WaitForVBlank();
    }
    else
    {
        result = object_->WaitForVBlank();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::TakeOwnership(
    IUnknown* pDevice,
    BOOL Exclusive)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->TakeOwnership(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            Exclusive);
    }
    else
    {
        result = object_->TakeOwnership(
            pDevice,
            Exclusive);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE IDXGIOutput_Wrapper::ReleaseOwnership()
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ReleaseOwnership();
    }
    else
    {
        object_->ReleaseOwnership();
    }

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetGammaControlCapabilities(
    DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetGammaControlCapabilities(
            pGammaCaps);
    }
    else
    {
        result = object_->GetGammaControlCapabilities(
            pGammaCaps);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::SetGammaControl(
    const DXGI_GAMMA_CONTROL* pArray)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetGammaControl(
            pArray);
    }
    else
    {
        result = object_->SetGammaControl(
            pArray);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetGammaControl(
    DXGI_GAMMA_CONTROL* pArray)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetGammaControl(
            pArray);
    }
    else
    {
        result = object_->GetGammaControl(
            pArray);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::SetDisplaySurface(
    IDXGISurface* pScanoutSurface)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetDisplaySurface(
            encode::GetWrappedObject<IDXGISurface_Wrapper, IDXGISurface>(pScanoutSurface));
    }
    else
    {
        result = object_->SetDisplaySurface(
            pScanoutSurface);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetDisplaySurfaceData(
    IDXGISurface* pDestination)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDisplaySurfaceData(
            encode::GetWrappedObject<IDXGISurface_Wrapper, IDXGISurface>(pDestination));
    }
    else
    {
        result = object_->GetDisplaySurfaceData(
            pDestination);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput_Wrapper::GetFrameStatistics(
    DXGI_FRAME_STATISTICS* pStats)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFrameStatistics(
            pStats);
    }
    else
    {
        result = object_->GetFrameStatistics(
            pStats);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGISwapChain_Wrapper::IDXGISwapChain_Wrapper(REFIID riid, IDXGISwapChain* object, DxWrapperResources* resources) : IDXGIDeviceSubObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::Present(
    UINT SyncInterval,
    UINT Flags)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Present(
            SyncInterval,
            Flags);
    }
    else
    {
        result = object_->Present(
            SyncInterval,
            Flags);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetBuffer(
    UINT Buffer,
    REFIID riid,
    void** ppSurface)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetBuffer(
            Buffer,
            riid,
            ppSurface);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppSurface, nullptr);
        }
    }
    else
    {
        result = object_->GetBuffer(
            Buffer,
            riid,
            ppSurface);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::SetFullscreenState(
    BOOL Fullscreen,
    IDXGIOutput* pTarget)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetFullscreenState(
            Fullscreen,
            encode::GetWrappedObject<IDXGIOutput_Wrapper, IDXGIOutput>(pTarget));
    }
    else
    {
        result = object_->SetFullscreenState(
            Fullscreen,
            pTarget);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetFullscreenState(
    BOOL* pFullscreen,
    IDXGIOutput** ppTarget)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFullscreenState(
            pFullscreen,
            ppTarget);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppTarget), nullptr);
        }
    }
    else
    {
        result = object_->GetFullscreenState(
            pFullscreen,
            ppTarget);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetDesc(
    DXGI_SWAP_CHAIN_DESC* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc(
            pDesc);
    }
    else
    {
        result = object_->GetDesc(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::ResizeBuffers(
    UINT BufferCount,
    UINT Width,
    UINT Height,
    DXGI_FORMAT NewFormat,
    UINT SwapChainFlags)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->ResizeBuffers(
            BufferCount,
            Width,
            Height,
            NewFormat,
            SwapChainFlags);
    }
    else
    {
        result = object_->ResizeBuffers(
            BufferCount,
            Width,
            Height,
            NewFormat,
            SwapChainFlags);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::ResizeTarget(
    const DXGI_MODE_DESC* pNewTargetParameters)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->ResizeTarget(
            pNewTargetParameters);
    }
    else
    {
        result = object_->ResizeTarget(
            pNewTargetParameters);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetContainingOutput(
    IDXGIOutput** ppOutput)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetContainingOutput(
            ppOutput);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppOutput), nullptr);
        }
    }
    else
    {
        result = object_->GetContainingOutput(
            ppOutput);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetFrameStatistics(
    DXGI_FRAME_STATISTICS* pStats)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFrameStatistics(
            pStats);
    }
    else
    {
        result = object_->GetFrameStatistics(
            pStats);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain_Wrapper::GetLastPresentCount(
    UINT* pLastPresentCount)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetLastPresentCount(
            pLastPresentCount);
    }
    else
    {
        result = object_->GetLastPresentCount(
            pLastPresentCount);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIFactory_Wrapper::IDXGIFactory_Wrapper(REFIID riid, IDXGIFactory* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::EnumAdapters(
    UINT Adapter,
    IDXGIAdapter** ppAdapter)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumAdapters(
            Adapter,
            ppAdapter);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIAdapter, reinterpret_cast<void**>(ppAdapter), nullptr);
        }
    }
    else
    {
        result = object_->EnumAdapters(
            Adapter,
            ppAdapter);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::MakeWindowAssociation(
    HWND WindowHandle,
    UINT Flags)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->MakeWindowAssociation(
            WindowHandle,
            Flags);
    }
    else
    {
        result = object_->MakeWindowAssociation(
            WindowHandle,
            Flags);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::GetWindowAssociation(
    HWND* pWindowHandle)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetWindowAssociation(
            pWindowHandle);
    }
    else
    {
        result = object_->GetWindowAssociation(
            pWindowHandle);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::CreateSwapChain(
    IUnknown* pDevice,
    DXGI_SWAP_CHAIN_DESC* pDesc,
    IDXGISwapChain** ppSwapChain)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSwapChain(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            pDesc,
            ppSwapChain);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGISwapChain, reinterpret_cast<void**>(ppSwapChain), nullptr);
        }
    }
    else
    {
        result = object_->CreateSwapChain(
            pDevice,
            pDesc,
            ppSwapChain);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory_Wrapper::CreateSoftwareAdapter(
    HMODULE Module,
    IDXGIAdapter** ppAdapter)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSoftwareAdapter(
            Module,
            ppAdapter);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIAdapter, reinterpret_cast<void**>(ppAdapter), nullptr);
        }
    }
    else
    {
        result = object_->CreateSoftwareAdapter(
            Module,
            ppAdapter);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIDevice_Wrapper::IDXGIDevice_Wrapper(REFIID riid, IDXGIDevice* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::GetAdapter(
    IDXGIAdapter** pAdapter)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetAdapter(
            pAdapter);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIAdapter, reinterpret_cast<void**>(pAdapter), nullptr);
        }
    }
    else
    {
        result = object_->GetAdapter(
            pAdapter);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::CreateSurface(
    const DXGI_SURFACE_DESC* pDesc,
    UINT NumSurfaces,
    DXGI_USAGE Usage,
    const DXGI_SHARED_RESOURCE* pSharedResource,
    IDXGISurface** ppSurface)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSurface(
            pDesc,
            NumSurfaces,
            Usage,
            pSharedResource,
            ppSurface);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGISurface, reinterpret_cast<void**>(ppSurface), nullptr);
        }
    }
    else
    {
        result = object_->CreateSurface(
            pDesc,
            NumSurfaces,
            Usage,
            pSharedResource,
            ppSurface);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::QueryResourceResidency(
    IUnknown* const* ppResources,
    DXGI_RESIDENCY* pResidencyStatus,
    UINT NumResources)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->QueryResourceResidency(
            UnwrapObjects<IUnknown_Wrapper, IUnknown>(ppResources, NumResources, unwrap_memory),
            pResidencyStatus,
            NumResources);
    }
    else
    {
        result = object_->QueryResourceResidency(
            ppResources,
            pResidencyStatus,
            NumResources);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::SetGPUThreadPriority(
    INT Priority)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetGPUThreadPriority(
            Priority);
    }
    else
    {
        result = object_->SetGPUThreadPriority(
            Priority);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice_Wrapper::GetGPUThreadPriority(
    INT* pPriority)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetGPUThreadPriority(
            pPriority);
    }
    else
    {
        result = object_->GetGPUThreadPriority(
            pPriority);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIFactory1_Wrapper::IDXGIFactory1_Wrapper(REFIID riid, IDXGIFactory1* object, DxWrapperResources* resources) : IDXGIFactory_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory1_Wrapper::EnumAdapters1(
    UINT Adapter,
    IDXGIAdapter1** ppAdapter)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumAdapters1(
            Adapter,
            ppAdapter);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIAdapter1, reinterpret_cast<void**>(ppAdapter), nullptr);
        }
    }
    else
    {
        result = object_->EnumAdapters1(
            Adapter,
            ppAdapter);
    }

    manager->DecrementCallScope();

    return result;
}

BOOL STDMETHODCALLTYPE IDXGIFactory1_Wrapper::IsCurrent()
{
    BOOL result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->IsCurrent();
    }
    else
    {
        result = object_->IsCurrent();
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIAdapter1_Wrapper::IDXGIAdapter1_Wrapper(REFIID riid, IDXGIAdapter1* object, DxWrapperResources* resources) : IDXGIAdapter_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter1_Wrapper::GetDesc1(
    DXGI_ADAPTER_DESC1* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc1(
            pDesc);
    }
    else
    {
        result = object_->GetDesc1(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIDevice1_Wrapper::IDXGIDevice1_Wrapper(REFIID riid, IDXGIDevice1* object, DxWrapperResources* resources) : IDXGIDevice_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIDevice1_Wrapper::SetMaximumFrameLatency(
    UINT MaxLatency)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetMaximumFrameLatency(
            MaxLatency);
    }
    else
    {
        result = object_->SetMaximumFrameLatency(
            MaxLatency);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice1_Wrapper::GetMaximumFrameLatency(
    UINT* pMaxLatency)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetMaximumFrameLatency(
            pMaxLatency);
    }
    else
    {
        result = object_->GetMaximumFrameLatency(
            pMaxLatency);
    }

    manager->DecrementCallScope();

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
    BOOL result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->IsStereoEnabled();
    }
    else
    {
        result = object_->IsStereoEnabled();
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE IDXGIDisplayControl_Wrapper::SetStereoEnabled(
    BOOL enabled)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetStereoEnabled(
            enabled);
    }
    else
    {
        object_->SetStereoEnabled(
            enabled);
    }

    manager->DecrementCallScope();
}

IDXGIOutputDuplication_Wrapper::IDXGIOutputDuplication_Wrapper(REFIID riid, IDXGIOutputDuplication* object, DxWrapperResources* resources) : IDXGIObject_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetDesc(
    DXGI_OUTDUPL_DESC* pDesc)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->GetDesc(
            pDesc);
    }
    else
    {
        object_->GetDesc(
            pDesc);
    }

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::AcquireNextFrame(
    UINT TimeoutInMilliseconds,
    DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
    IDXGIResource** ppDesktopResource)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->AcquireNextFrame(
            TimeoutInMilliseconds,
            pFrameInfo,
            ppDesktopResource);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIResource, reinterpret_cast<void**>(ppDesktopResource), nullptr);
        }
    }
    else
    {
        result = object_->AcquireNextFrame(
            TimeoutInMilliseconds,
            pFrameInfo,
            ppDesktopResource);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetFrameDirtyRects(
    UINT DirtyRectsBufferSize,
    RECT* pDirtyRectsBuffer,
    UINT* pDirtyRectsBufferSizeRequired)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFrameDirtyRects(
            DirtyRectsBufferSize,
            pDirtyRectsBuffer,
            pDirtyRectsBufferSizeRequired);
    }
    else
    {
        result = object_->GetFrameDirtyRects(
            DirtyRectsBufferSize,
            pDirtyRectsBuffer,
            pDirtyRectsBufferSizeRequired);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetFrameMoveRects(
    UINT MoveRectsBufferSize,
    DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
    UINT* pMoveRectsBufferSizeRequired)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFrameMoveRects(
            MoveRectsBufferSize,
            pMoveRectBuffer,
            pMoveRectsBufferSizeRequired);
    }
    else
    {
        result = object_->GetFrameMoveRects(
            MoveRectsBufferSize,
            pMoveRectBuffer,
            pMoveRectsBufferSizeRequired);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::GetFramePointerShape(
    UINT PointerShapeBufferSize,
    void* pPointerShapeBuffer,
    UINT* pPointerShapeBufferSizeRequired,
    DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFramePointerShape(
            PointerShapeBufferSize,
            pPointerShapeBuffer,
            pPointerShapeBufferSizeRequired,
            pPointerShapeInfo);
    }
    else
    {
        result = object_->GetFramePointerShape(
            PointerShapeBufferSize,
            pPointerShapeBuffer,
            pPointerShapeBufferSizeRequired,
            pPointerShapeInfo);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::MapDesktopSurface(
    DXGI_MAPPED_RECT* pLockedRect)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->MapDesktopSurface(
            pLockedRect);
    }
    else
    {
        result = object_->MapDesktopSurface(
            pLockedRect);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::UnMapDesktopSurface()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->UnMapDesktopSurface();
    }
    else
    {
        result = object_->UnMapDesktopSurface();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutputDuplication_Wrapper::ReleaseFrame()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->ReleaseFrame();
    }
    else
    {
        result = object_->ReleaseFrame();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetResource(
            riid,
            ppParentResource,
            pSubresourceIndex);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppParentResource, nullptr);
        }
    }
    else
    {
        result = object_->GetResource(
            riid,
            ppParentResource,
            pSubresourceIndex);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIResource1_Wrapper::IDXGIResource1_Wrapper(REFIID riid, IDXGIResource1* object, DxWrapperResources* resources) : IDXGIResource_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIResource1_Wrapper::CreateSubresourceSurface(
    UINT index,
    IDXGISurface2** ppSurface)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSubresourceSurface(
            index,
            ppSurface);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGISurface2, reinterpret_cast<void**>(ppSurface), nullptr);
        }
    }
    else
    {
        result = object_->CreateSubresourceSurface(
            index,
            ppSurface);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIResource1_Wrapper::CreateSharedHandle(
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD dwAccess,
    LPCWSTR lpName,
    HANDLE* pHandle)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSharedHandle(
            pAttributes,
            dwAccess,
            lpName,
            pHandle);
    }
    else
    {
        result = object_->CreateSharedHandle(
            pAttributes,
            dwAccess,
            lpName,
            pHandle);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->OfferResources(
            NumResources,
            UnwrapObjects<IDXGIResource_Wrapper, IDXGIResource>(ppResources, NumResources, unwrap_memory),
            Priority);
    }
    else
    {
        result = object_->OfferResources(
            NumResources,
            ppResources,
            Priority);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice2_Wrapper::ReclaimResources(
    UINT NumResources,
    IDXGIResource* const* ppResources,
    BOOL* pDiscarded)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->ReclaimResources(
            NumResources,
            UnwrapObjects<IDXGIResource_Wrapper, IDXGIResource>(ppResources, NumResources, unwrap_memory),
            pDiscarded);
    }
    else
    {
        result = object_->ReclaimResources(
            NumResources,
            ppResources,
            pDiscarded);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice2_Wrapper::EnqueueSetEvent(
    HANDLE hEvent)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnqueueSetEvent(
            hEvent);
    }
    else
    {
        result = object_->EnqueueSetEvent(
            hEvent);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGISwapChain1_Wrapper::IDXGISwapChain1_Wrapper(REFIID riid, IDXGISwapChain1* object, DxWrapperResources* resources) : IDXGISwapChain_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetDesc1(
    DXGI_SWAP_CHAIN_DESC1* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc1(
            pDesc);
    }
    else
    {
        result = object_->GetDesc1(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetFullscreenDesc(
    DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFullscreenDesc(
            pDesc);
    }
    else
    {
        result = object_->GetFullscreenDesc(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetHwnd(
    HWND* pHwnd)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetHwnd(
            pHwnd);
    }
    else
    {
        result = object_->GetHwnd(
            pHwnd);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetCoreWindow(
    REFIID refiid,
    void** ppUnk)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCoreWindow(
            refiid,
            ppUnk);

        if (SUCCEEDED(result))
        {
            WrapObject(refiid, ppUnk, nullptr);
        }
    }
    else
    {
        result = object_->GetCoreWindow(
            refiid,
            ppUnk);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::Present1(
    UINT SyncInterval,
    UINT PresentFlags,
    const DXGI_PRESENT_PARAMETERS* pPresentParameters)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Present1(
            SyncInterval,
            PresentFlags,
            pPresentParameters);
    }
    else
    {
        result = object_->Present1(
            SyncInterval,
            PresentFlags,
            pPresentParameters);
    }

    manager->DecrementCallScope();

    return result;
}

BOOL STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::IsTemporaryMonoSupported()
{
    BOOL result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->IsTemporaryMonoSupported();
    }
    else
    {
        result = object_->IsTemporaryMonoSupported();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetRestrictToOutput(
    IDXGIOutput** ppRestrictToOutput)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetRestrictToOutput(
            ppRestrictToOutput);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIOutput, reinterpret_cast<void**>(ppRestrictToOutput), nullptr);
        }
    }
    else
    {
        result = object_->GetRestrictToOutput(
            ppRestrictToOutput);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::SetBackgroundColor(
    const DXGI_RGBA* pColor)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetBackgroundColor(
            pColor);
    }
    else
    {
        result = object_->SetBackgroundColor(
            pColor);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetBackgroundColor(
    DXGI_RGBA* pColor)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetBackgroundColor(
            pColor);
    }
    else
    {
        result = object_->GetBackgroundColor(
            pColor);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::SetRotation(
    DXGI_MODE_ROTATION Rotation)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetRotation(
            Rotation);
    }
    else
    {
        result = object_->SetRotation(
            Rotation);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain1_Wrapper::GetRotation(
    DXGI_MODE_ROTATION* pRotation)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetRotation(
            pRotation);
    }
    else
    {
        result = object_->GetRotation(
            pRotation);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIFactory2_Wrapper::IDXGIFactory2_Wrapper(REFIID riid, IDXGIFactory2* object, DxWrapperResources* resources) : IDXGIFactory1_Wrapper(riid, object, resources), object_(object)
{
}

BOOL STDMETHODCALLTYPE IDXGIFactory2_Wrapper::IsWindowedStereoEnabled()
{
    BOOL result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->IsWindowedStereoEnabled();
    }
    else
    {
        result = object_->IsWindowedStereoEnabled();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSwapChainForHwnd(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            hWnd,
            pDesc,
            pFullscreenDesc,
            encode::GetWrappedObject<IDXGIOutput_Wrapper, IDXGIOutput>(pRestrictToOutput),
            ppSwapChain);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
        }
    }
    else
    {
        result = object_->CreateSwapChainForHwnd(
            pDevice,
            hWnd,
            pDesc,
            pFullscreenDesc,
            pRestrictToOutput,
            ppSwapChain);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::CreateSwapChainForCoreWindow(
    IUnknown* pDevice,
    IUnknown* pWindow,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSwapChainForCoreWindow(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pWindow),
            pDesc,
            encode::GetWrappedObject<IDXGIOutput_Wrapper, IDXGIOutput>(pRestrictToOutput),
            ppSwapChain);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
        }
    }
    else
    {
        result = object_->CreateSwapChainForCoreWindow(
            pDevice,
            pWindow,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::GetSharedResourceAdapterLuid(
    HANDLE hResource,
    LUID* pLuid)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetSharedResourceAdapterLuid(
            hResource,
            pLuid);
    }
    else
    {
        result = object_->GetSharedResourceAdapterLuid(
            hResource,
            pLuid);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterStereoStatusWindow(
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterStereoStatusWindow(
            WindowHandle,
            wMsg,
            pdwCookie);
    }
    else
    {
        result = object_->RegisterStereoStatusWindow(
            WindowHandle,
            wMsg,
            pdwCookie);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterStereoStatusEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterStereoStatusEvent(
            hEvent,
            pdwCookie);
    }
    else
    {
        result = object_->RegisterStereoStatusEvent(
            hEvent,
            pdwCookie);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE IDXGIFactory2_Wrapper::UnregisterStereoStatus(
    DWORD dwCookie)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->UnregisterStereoStatus(
            dwCookie);
    }
    else
    {
        object_->UnregisterStereoStatus(
            dwCookie);
    }

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterOcclusionStatusWindow(
    HWND WindowHandle,
    UINT wMsg,
    DWORD* pdwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterOcclusionStatusWindow(
            WindowHandle,
            wMsg,
            pdwCookie);
    }
    else
    {
        result = object_->RegisterOcclusionStatusWindow(
            WindowHandle,
            wMsg,
            pdwCookie);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::RegisterOcclusionStatusEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterOcclusionStatusEvent(
            hEvent,
            pdwCookie);
    }
    else
    {
        result = object_->RegisterOcclusionStatusEvent(
            hEvent,
            pdwCookie);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE IDXGIFactory2_Wrapper::UnregisterOcclusionStatus(
    DWORD dwCookie)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->UnregisterOcclusionStatus(
            dwCookie);
    }
    else
    {
        object_->UnregisterOcclusionStatus(
            dwCookie);
    }

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE IDXGIFactory2_Wrapper::CreateSwapChainForComposition(
    IUnknown* pDevice,
    const DXGI_SWAP_CHAIN_DESC1* pDesc,
    IDXGIOutput* pRestrictToOutput,
    IDXGISwapChain1** ppSwapChain)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSwapChainForComposition(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            pDesc,
            encode::GetWrappedObject<IDXGIOutput_Wrapper, IDXGIOutput>(pRestrictToOutput),
            ppSwapChain);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
        }
    }
    else
    {
        result = object_->CreateSwapChainForComposition(
            pDevice,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIAdapter2_Wrapper::IDXGIAdapter2_Wrapper(REFIID riid, IDXGIAdapter2* object, DxWrapperResources* resources) : IDXGIAdapter1_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter2_Wrapper::GetDesc2(
    DXGI_ADAPTER_DESC2* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc2(
            pDesc);
    }
    else
    {
        result = object_->GetDesc2(
            pDesc);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDisplayModeList1(
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
    }
    else
    {
        result = object_->GetDisplayModeList1(
            EnumFormat,
            Flags,
            pNumModes,
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput1_Wrapper::FindClosestMatchingMode1(
    const DXGI_MODE_DESC1* pModeToMatch,
    DXGI_MODE_DESC1* pClosestMatch,
    IUnknown* pConcernedDevice)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->FindClosestMatchingMode1(
            pModeToMatch,
            pClosestMatch,
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pConcernedDevice));
    }
    else
    {
        result = object_->FindClosestMatchingMode1(
            pModeToMatch,
            pClosestMatch,
            pConcernedDevice);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput1_Wrapper::GetDisplaySurfaceData1(
    IDXGIResource* pDestination)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDisplaySurfaceData1(
            encode::GetWrappedObject<IDXGIResource_Wrapper, IDXGIResource>(pDestination));
    }
    else
    {
        result = object_->GetDisplaySurfaceData1(
            pDestination);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput1_Wrapper::DuplicateOutput(
    IUnknown* pDevice,
    IDXGIOutputDuplication** ppOutputDuplication)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->DuplicateOutput(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            ppOutputDuplication);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIOutputDuplication, reinterpret_cast<void**>(ppOutputDuplication), nullptr);
        }
    }
    else
    {
        result = object_->DuplicateOutput(
            pDevice,
            ppOutputDuplication);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory2(
            Flags,
            riid,
            ppFactory);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppFactory, nullptr);
        }
    }
    else
    {
        auto result = manager->GetDxgiDispatchTable().CreateDXGIFactory2(
            Flags,
            riid,
            ppFactory);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI DXGIGetDebugInterface1(
    UINT Flags,
    REFIID riid,
    void** pDebug)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetDxgiDispatchTable().DXGIGetDebugInterface1(
            Flags,
            riid,
            pDebug);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, pDebug, nullptr);
        }
    }
    else
    {
        auto result = manager->GetDxgiDispatchTable().DXGIGetDebugInterface1(
            Flags,
            riid,
            pDebug);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIDevice3_Wrapper::IDXGIDevice3_Wrapper(REFIID riid, IDXGIDevice3* object, DxWrapperResources* resources) : IDXGIDevice2_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE IDXGIDevice3_Wrapper::Trim()
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->Trim();
    }
    else
    {
        object_->Trim();
    }

    manager->DecrementCallScope();
}

IDXGISwapChain2_Wrapper::IDXGISwapChain2_Wrapper(REFIID riid, IDXGISwapChain2* object, DxWrapperResources* resources) : IDXGISwapChain1_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::SetSourceSize(
    UINT Width,
    UINT Height)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetSourceSize(
            Width,
            Height);
    }
    else
    {
        result = object_->SetSourceSize(
            Width,
            Height);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetSourceSize(
    UINT* pWidth,
    UINT* pHeight)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetSourceSize(
            pWidth,
            pHeight);
    }
    else
    {
        result = object_->GetSourceSize(
            pWidth,
            pHeight);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::SetMaximumFrameLatency(
    UINT MaxLatency)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetMaximumFrameLatency(
            MaxLatency);
    }
    else
    {
        result = object_->SetMaximumFrameLatency(
            MaxLatency);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetMaximumFrameLatency(
    UINT* pMaxLatency)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetMaximumFrameLatency(
            pMaxLatency);
    }
    else
    {
        result = object_->GetMaximumFrameLatency(
            pMaxLatency);
    }

    manager->DecrementCallScope();

    return result;
}

HANDLE STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetFrameLatencyWaitableObject()
{
    HANDLE result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFrameLatencyWaitableObject();
    }
    else
    {
        result = object_->GetFrameLatencyWaitableObject();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::SetMatrixTransform(
    const DXGI_MATRIX_3X2_F* pMatrix)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetMatrixTransform(
            pMatrix);
    }
    else
    {
        result = object_->SetMatrixTransform(
            pMatrix);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain2_Wrapper::GetMatrixTransform(
    DXGI_MATRIX_3X2_F* pMatrix)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetMatrixTransform(
            pMatrix);
    }
    else
    {
        result = object_->GetMatrixTransform(
            pMatrix);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIOutput2_Wrapper::IDXGIOutput2_Wrapper(REFIID riid, IDXGIOutput2* object, DxWrapperResources* resources) : IDXGIOutput1_Wrapper(riid, object, resources), object_(object)
{
}

BOOL STDMETHODCALLTYPE IDXGIOutput2_Wrapper::SupportsOverlays()
{
    BOOL result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SupportsOverlays();
    }
    else
    {
        result = object_->SupportsOverlays();
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIFactory3_Wrapper::IDXGIFactory3_Wrapper(REFIID riid, IDXGIFactory3* object, DxWrapperResources* resources) : IDXGIFactory2_Wrapper(riid, object, resources), object_(object)
{
}

UINT STDMETHODCALLTYPE IDXGIFactory3_Wrapper::GetCreationFlags()
{
    UINT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCreationFlags();
    }
    else
    {
        result = object_->GetCreationFlags();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->PresentBuffer(
            BufferToPresent,
            SyncInterval,
            Flags);
    }
    else
    {
        result = object_->PresentBuffer(
            BufferToPresent,
            SyncInterval,
            Flags);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetSourceRect(
    const RECT* pRect)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetSourceRect(
            pRect);
    }
    else
    {
        result = object_->SetSourceRect(
            pRect);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetTargetRect(
    const RECT* pRect)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetTargetRect(
            pRect);
    }
    else
    {
        result = object_->SetTargetRect(
            pRect);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetDestSize(
    UINT Width,
    UINT Height)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetDestSize(
            Width,
            Height);
    }
    else
    {
        result = object_->SetDestSize(
            Width,
            Height);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetSourceRect(
    RECT* pRect)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetSourceRect(
            pRect);
    }
    else
    {
        result = object_->GetSourceRect(
            pRect);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetTargetRect(
    RECT* pRect)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetTargetRect(
            pRect);
    }
    else
    {
        result = object_->GetTargetRect(
            pRect);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetDestSize(
    UINT* pWidth,
    UINT* pHeight)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDestSize(
            pWidth,
            pHeight);
    }
    else
    {
        result = object_->GetDestSize(
            pWidth,
            pHeight);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::SetColorSpace(
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetColorSpace(
            ColorSpace);
    }
    else
    {
        result = object_->SetColorSpace(
            ColorSpace);
    }

    manager->DecrementCallScope();

    return result;
}

DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS STDMETHODCALLTYPE IDXGIDecodeSwapChain_Wrapper::GetColorSpace()
{
    DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetColorSpace();
    }
    else
    {
        result = object_->GetColorSpace();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSwapChainForCompositionSurfaceHandle(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            hSurface,
            pDesc,
            encode::GetWrappedObject<IDXGIOutput_Wrapper, IDXGIOutput>(pRestrictToOutput),
            ppSwapChain);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGISwapChain1, reinterpret_cast<void**>(ppSwapChain), nullptr);
        }
    }
    else
    {
        result = object_->CreateSwapChainForCompositionSurfaceHandle(
            pDevice,
            hSurface,
            pDesc,
            pRestrictToOutput,
            ppSwapChain);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateDecodeSwapChainForCompositionSurfaceHandle(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            hSurface,
            pDesc,
            encode::GetWrappedObject<IDXGIResource_Wrapper, IDXGIResource>(pYuvDecodeBuffers),
            encode::GetWrappedObject<IDXGIOutput_Wrapper, IDXGIOutput>(pRestrictToOutput),
            ppSwapChain);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIDecodeSwapChain, reinterpret_cast<void**>(ppSwapChain), nullptr);
        }
    }
    else
    {
        result = object_->CreateDecodeSwapChainForCompositionSurfaceHandle(
            pDevice,
            hSurface,
            pDesc,
            pYuvDecodeBuffers,
            pRestrictToOutput,
            ppSwapChain);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGISwapChainMedia_Wrapper::IDXGISwapChainMedia_Wrapper(REFIID riid, IDXGISwapChainMedia* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGISwapChainMedia_Wrapper::GetFrameStatisticsMedia(
    DXGI_FRAME_STATISTICS_MEDIA* pStats)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetFrameStatisticsMedia(
            pStats);
    }
    else
    {
        result = object_->GetFrameStatisticsMedia(
            pStats);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChainMedia_Wrapper::SetPresentDuration(
    UINT Duration)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetPresentDuration(
            Duration);
    }
    else
    {
        result = object_->SetPresentDuration(
            Duration);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChainMedia_Wrapper::CheckPresentDurationSupport(
    UINT DesiredPresentDuration,
    UINT* pClosestSmallerPresentDuration,
    UINT* pClosestLargerPresentDuration)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckPresentDurationSupport(
            DesiredPresentDuration,
            pClosestSmallerPresentDuration,
            pClosestLargerPresentDuration);
    }
    else
    {
        result = object_->CheckPresentDurationSupport(
            DesiredPresentDuration,
            pClosestSmallerPresentDuration,
            pClosestLargerPresentDuration);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckOverlaySupport(
            EnumFormat,
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pConcernedDevice),
            pFlags);
    }
    else
    {
        result = object_->CheckOverlaySupport(
            EnumFormat,
            pConcernedDevice,
            pFlags);
    }

    manager->DecrementCallScope();

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
    UINT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCurrentBackBufferIndex();
    }
    else
    {
        result = object_->GetCurrentBackBufferIndex();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain3_Wrapper::CheckColorSpaceSupport(
    DXGI_COLOR_SPACE_TYPE ColorSpace,
    UINT* pColorSpaceSupport)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckColorSpaceSupport(
            ColorSpace,
            pColorSpaceSupport);
    }
    else
    {
        result = object_->CheckColorSpaceSupport(
            ColorSpace,
            pColorSpaceSupport);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGISwapChain3_Wrapper::SetColorSpace1(
    DXGI_COLOR_SPACE_TYPE ColorSpace)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetColorSpace1(
            ColorSpace);
    }
    else
    {
        result = object_->SetColorSpace1(
            ColorSpace);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->ResizeBuffers1(
            BufferCount,
            Width,
            Height,
            Format,
            SwapChainFlags,
            pCreationNodeMask,
            UnwrapObjects<IUnknown_Wrapper, IUnknown>(ppPresentQueue, BufferCount, unwrap_memory));
    }
    else
    {
        result = object_->ResizeBuffers1(
            BufferCount,
            Width,
            Height,
            Format,
            SwapChainFlags,
            pCreationNodeMask,
            ppPresentQueue);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckOverlayColorSpaceSupport(
            Format,
            ColorSpace,
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pConcernedDevice),
            pFlags);
    }
    else
    {
        result = object_->CheckOverlayColorSpaceSupport(
            Format,
            ColorSpace,
            pConcernedDevice,
            pFlags);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumAdapterByLuid(
            AdapterLuid,
            riid,
            ppvAdapter);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvAdapter, nullptr);
        }
    }
    else
    {
        result = object_->EnumAdapterByLuid(
            AdapterLuid,
            riid,
            ppvAdapter);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory4_Wrapper::EnumWarpAdapter(
    REFIID riid,
    void** ppvAdapter)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumWarpAdapter(
            riid,
            ppvAdapter);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvAdapter, nullptr);
        }
    }
    else
    {
        result = object_->EnumWarpAdapter(
            riid,
            ppvAdapter);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIAdapter3_Wrapper::IDXGIAdapter3_Wrapper(REFIID riid, IDXGIAdapter3* object, DxWrapperResources* resources) : IDXGIAdapter2_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::RegisterHardwareContentProtectionTeardownStatusEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterHardwareContentProtectionTeardownStatusEvent(
            hEvent,
            pdwCookie);
    }
    else
    {
        result = object_->RegisterHardwareContentProtectionTeardownStatusEvent(
            hEvent,
            pdwCookie);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::UnregisterHardwareContentProtectionTeardownStatus(
    DWORD dwCookie)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->UnregisterHardwareContentProtectionTeardownStatus(
            dwCookie);
    }
    else
    {
        object_->UnregisterHardwareContentProtectionTeardownStatus(
            dwCookie);
    }

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::QueryVideoMemoryInfo(
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->QueryVideoMemoryInfo(
            NodeIndex,
            MemorySegmentGroup,
            pVideoMemoryInfo);
    }
    else
    {
        result = object_->QueryVideoMemoryInfo(
            NodeIndex,
            MemorySegmentGroup,
            pVideoMemoryInfo);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::SetVideoMemoryReservation(
    UINT NodeIndex,
    DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
    UINT64 Reservation)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetVideoMemoryReservation(
            NodeIndex,
            MemorySegmentGroup,
            Reservation);
    }
    else
    {
        result = object_->SetVideoMemoryReservation(
            NodeIndex,
            MemorySegmentGroup,
            Reservation);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::RegisterVideoMemoryBudgetChangeNotificationEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterVideoMemoryBudgetChangeNotificationEvent(
            hEvent,
            pdwCookie);
    }
    else
    {
        result = object_->RegisterVideoMemoryBudgetChangeNotificationEvent(
            hEvent,
            pdwCookie);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE IDXGIAdapter3_Wrapper::UnregisterVideoMemoryBudgetChangeNotification(
    DWORD dwCookie)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->UnregisterVideoMemoryBudgetChangeNotification(
            dwCookie);
    }
    else
    {
        object_->UnregisterVideoMemoryBudgetChangeNotification(
            dwCookie);
    }

    manager->DecrementCallScope();
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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->DuplicateOutput1(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pDevice),
            Flags,
            SupportedFormatsCount,
            pSupportedFormats,
            ppOutputDuplication);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_IDXGIOutputDuplication, reinterpret_cast<void**>(ppOutputDuplication), nullptr);
        }
    }
    else
    {
        result = object_->DuplicateOutput1(
            pDevice,
            Flags,
            SupportedFormatsCount,
            pSupportedFormats,
            ppOutputDuplication);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetHDRMetaData(
            Type,
            Size,
            pMetaData);
    }
    else
    {
        result = object_->SetHDRMetaData(
            Type,
            Size,
            pMetaData);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->OfferResources1(
            NumResources,
            UnwrapObjects<IDXGIResource_Wrapper, IDXGIResource>(ppResources, NumResources, unwrap_memory),
            Priority,
            Flags);
    }
    else
    {
        result = object_->OfferResources1(
            NumResources,
            ppResources,
            Priority,
            Flags);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIDevice4_Wrapper::ReclaimResources1(
    UINT NumResources,
    IDXGIResource* const* ppResources,
    DXGI_RECLAIM_RESOURCE_RESULTS* pResults)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->ReclaimResources1(
            NumResources,
            UnwrapObjects<IDXGIResource_Wrapper, IDXGIResource>(ppResources, NumResources, unwrap_memory),
            pResults);
    }
    else
    {
        result = object_->ReclaimResources1(
            NumResources,
            ppResources,
            pResults);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckFeatureSupport(
            Feature,
            pFeatureSupportData,
            FeatureSupportDataSize);
    }
    else
    {
        result = object_->CheckFeatureSupport(
            Feature,
            pFeatureSupportData,
            FeatureSupportDataSize);
    }

    manager->DecrementCallScope();

    return result;
}


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/

HRESULT WINAPI DXGIDeclareAdapterRemovalSupport()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetDxgiDispatchTable().DXGIDeclareAdapterRemovalSupport();
    }
    else
    {
        auto result = manager->GetDxgiDispatchTable().DXGIDeclareAdapterRemovalSupport();
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIAdapter4_Wrapper::IDXGIAdapter4_Wrapper(REFIID riid, IDXGIAdapter4* object, DxWrapperResources* resources) : IDXGIAdapter3_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIAdapter4_Wrapper::GetDesc3(
    DXGI_ADAPTER_DESC3* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc3(
            pDesc);
    }
    else
    {
        result = object_->GetDesc3(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIOutput6_Wrapper::IDXGIOutput6_Wrapper(REFIID riid, IDXGIOutput6* object, DxWrapperResources* resources) : IDXGIOutput5_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIOutput6_Wrapper::GetDesc1(
    DXGI_OUTPUT_DESC1* pDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc1(
            pDesc);
    }
    else
    {
        result = object_->GetDesc1(
            pDesc);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIOutput6_Wrapper::CheckHardwareCompositionSupport(
    UINT* pFlags)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckHardwareCompositionSupport(
            pFlags);
    }
    else
    {
        result = object_->CheckHardwareCompositionSupport(
            pFlags);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumAdapterByGpuPreference(
            Adapter,
            GpuPreference,
            riid,
            ppvAdapter);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvAdapter, nullptr);
        }
    }
    else
    {
        result = object_->EnumAdapterByGpuPreference(
            Adapter,
            GpuPreference,
            riid,
            ppvAdapter);
    }

    manager->DecrementCallScope();

    return result;
}

IDXGIFactory7_Wrapper::IDXGIFactory7_Wrapper(REFIID riid, IDXGIFactory7* object, DxWrapperResources* resources) : IDXGIFactory6_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE IDXGIFactory7_Wrapper::RegisterAdaptersChangedEvent(
    HANDLE hEvent,
    DWORD* pdwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterAdaptersChangedEvent(
            hEvent,
            pdwCookie);
    }
    else
    {
        result = object_->RegisterAdaptersChangedEvent(
            hEvent,
            pdwCookie);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE IDXGIFactory7_Wrapper::UnregisterAdaptersChangedEvent(
    DWORD dwCookie)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->UnregisterAdaptersChangedEvent(
            dwCookie);
    }
    else
    {
        result = object_->UnregisterAdaptersChangedEvent(
            dwCookie);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
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
    }
    else
    {
        auto result = manager->GetD3D12DispatchTable().D3D12SerializeRootSignature(
            pRootSignature,
            Version,
            ppBlob,
            ppErrorBlob);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI D3D12CreateRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetD3D12DispatchTable().D3D12CreateRootSignatureDeserializer(
            pSrcData,
            SrcDataSizeInBytes,
            pRootSignatureDeserializerInterface,
            ppRootSignatureDeserializer);

        if (SUCCEEDED(result))
        {
            WrapObject(pRootSignatureDeserializerInterface, ppRootSignatureDeserializer, nullptr);
        }
    }
    else
    {
        auto result = manager->GetD3D12DispatchTable().D3D12CreateRootSignatureDeserializer(
            pSrcData,
            SrcDataSizeInBytes,
            pRootSignatureDeserializerInterface,
            ppRootSignatureDeserializer);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetD3D12DispatchTable().D3D12SerializeVersionedRootSignature(
            pRootSignature,
            ppBlob,
            ppErrorBlob);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppBlob), nullptr);
            WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppErrorBlob), nullptr);
        }
    }
    else
    {
        auto result = manager->GetD3D12DispatchTable().D3D12SerializeVersionedRootSignature(
            pRootSignature,
            ppBlob,
            ppErrorBlob);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI D3D12CreateVersionedRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetD3D12DispatchTable().D3D12CreateVersionedRootSignatureDeserializer(
            pSrcData,
            SrcDataSizeInBytes,
            pRootSignatureDeserializerInterface,
            ppRootSignatureDeserializer);

        if (SUCCEEDED(result))
        {
            WrapObject(pRootSignatureDeserializerInterface, ppRootSignatureDeserializer, nullptr);
        }
    }
    else
    {
        auto result = manager->GetD3D12DispatchTable().D3D12CreateVersionedRootSignatureDeserializer(
            pSrcData,
            SrcDataSizeInBytes,
            pRootSignatureDeserializerInterface,
            ppRootSignatureDeserializer);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI D3D12CreateDevice(
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetD3D12DispatchTable().D3D12CreateDevice(
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pAdapter),
            MinimumFeatureLevel,
            riid,
            ppDevice);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppDevice, nullptr);
        }
    }
    else
    {
        auto result = manager->GetD3D12DispatchTable().D3D12CreateDevice(
            pAdapter,
            MinimumFeatureLevel,
            riid,
            ppDevice);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI D3D12GetDebugInterface(
    REFIID riid,
    void** ppvDebug)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetD3D12DispatchTable().D3D12GetDebugInterface(
            riid,
            ppvDebug);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvDebug, nullptr);
        }
    }
    else
    {
        auto result = manager->GetD3D12DispatchTable().D3D12GetDebugInterface(
            riid,
            ppvDebug);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT WINAPI D3D12EnableExperimentalFeatures(
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto result = manager->GetD3D12DispatchTable().D3D12EnableExperimentalFeatures(
            NumFeatures,
            pIIDs,
            pConfigurationStructs,
            pConfigurationStructSizes);
    }
    else
    {
        auto result = manager->GetD3D12DispatchTable().D3D12EnableExperimentalFeatures(
            NumFeatures,
            pIIDs,
            pConfigurationStructs,
            pConfigurationStructSizes);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetPrivateData(
            guid,
            pDataSize,
            pData);
    }
    else
    {
        result = object_->GetPrivateData(
            guid,
            pDataSize,
            pData);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Object_Wrapper::SetPrivateData(
    REFGUID guid,
    UINT DataSize,
    const void* pData)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetPrivateData(
            guid,
            DataSize,
            pData);
    }
    else
    {
        result = object_->SetPrivateData(
            guid,
            DataSize,
            pData);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Object_Wrapper::SetPrivateDataInterface(
    REFGUID guid,
    const IUnknown* pData)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetPrivateDataInterface(
            guid,
            encode::GetWrappedObject<IUnknown_Wrapper, IUnknown>(pData));
    }
    else
    {
        result = object_->SetPrivateDataInterface(
            guid,
            pData);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Object_Wrapper::SetName(
    LPCWSTR Name)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetName(
            Name);
    }
    else
    {
        result = object_->SetName(
            Name);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12DeviceChild_Wrapper::ID3D12DeviceChild_Wrapper(REFIID riid, ID3D12DeviceChild* object, DxWrapperResources* resources) : ID3D12Object_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceChild_Wrapper::GetDevice(
    REFIID riid,
    void** ppvDevice)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDevice(
            riid,
            ppvDevice);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvDevice, nullptr);
        }
    }
    else
    {
        result = object_->GetDevice(
            riid,
            ppvDevice);
    }

    manager->DecrementCallScope();

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
    const D3D12_ROOT_SIGNATURE_DESC* result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetRootSignatureDesc();
    }
    else
    {
        result = object_->GetRootSignatureDesc();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12VersionedRootSignatureDeserializer_Wrapper::ID3D12VersionedRootSignatureDeserializer_Wrapper(REFIID riid, ID3D12VersionedRootSignatureDeserializer* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12VersionedRootSignatureDeserializer_Wrapper::GetRootSignatureDescAtVersion(
    D3D_ROOT_SIGNATURE_VERSION convertToVersion,
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetRootSignatureDescAtVersion(
            convertToVersion,
            ppDesc);
    }
    else
    {
        result = object_->GetRootSignatureDescAtVersion(
            convertToVersion,
            ppDesc);
    }

    manager->DecrementCallScope();

    return result;
}

const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* STDMETHODCALLTYPE ID3D12VersionedRootSignatureDeserializer_Wrapper::GetUnconvertedRootSignatureDesc()
{
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetUnconvertedRootSignatureDesc();
    }
    else
    {
        result = object_->GetUnconvertedRootSignatureDesc();
    }

    manager->DecrementCallScope();

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
    D3D12_HEAP_DESC result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc();
    }
    else
    {
        result = object_->GetDesc();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Map(
            Subresource,
            pReadRange,
            ppData);
    }
    else
    {
        result = object_->Map(
            Subresource,
            pReadRange,
            ppData);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE ID3D12Resource_Wrapper::Unmap(
    UINT Subresource,
    const D3D12_RANGE* pWrittenRange)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->Unmap(
            Subresource,
            pWrittenRange);
    }
    else
    {
        object_->Unmap(
            Subresource,
            pWrittenRange);
    }

    manager->DecrementCallScope();
}

D3D12_RESOURCE_DESC STDMETHODCALLTYPE ID3D12Resource_Wrapper::GetDesc()
{
    D3D12_RESOURCE_DESC result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc();
    }
    else
    {
        result = object_->GetDesc();
    }

    manager->DecrementCallScope();

    return result;
}

D3D12_GPU_VIRTUAL_ADDRESS STDMETHODCALLTYPE ID3D12Resource_Wrapper::GetGPUVirtualAddress()
{
    D3D12_GPU_VIRTUAL_ADDRESS result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetGPUVirtualAddress();
    }
    else
    {
        result = object_->GetGPUVirtualAddress();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Resource_Wrapper::WriteToSubresource(
    UINT DstSubresource,
    const D3D12_BOX* pDstBox,
    const void* pSrcData,
    UINT SrcRowPitch,
    UINT SrcDepthPitch)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->WriteToSubresource(
            DstSubresource,
            pDstBox,
            pSrcData,
            SrcRowPitch,
            SrcDepthPitch);
    }
    else
    {
        result = object_->WriteToSubresource(
            DstSubresource,
            pDstBox,
            pSrcData,
            SrcRowPitch,
            SrcDepthPitch);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Resource_Wrapper::ReadFromSubresource(
    void* pDstData,
    UINT DstRowPitch,
    UINT DstDepthPitch,
    UINT SrcSubresource,
    const D3D12_BOX* pSrcBox)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->ReadFromSubresource(
            pDstData,
            DstRowPitch,
            DstDepthPitch,
            SrcSubresource,
            pSrcBox);
    }
    else
    {
        result = object_->ReadFromSubresource(
            pDstData,
            DstRowPitch,
            DstDepthPitch,
            SrcSubresource,
            pSrcBox);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Resource_Wrapper::GetHeapProperties(
    D3D12_HEAP_PROPERTIES* pHeapProperties,
    D3D12_HEAP_FLAGS* pHeapFlags)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetHeapProperties(
            pHeapProperties,
            pHeapFlags);
    }
    else
    {
        result = object_->GetHeapProperties(
            pHeapProperties,
            pHeapFlags);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12CommandAllocator_Wrapper::ID3D12CommandAllocator_Wrapper(REFIID riid, ID3D12CommandAllocator* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12CommandAllocator_Wrapper::Reset()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Reset();
    }
    else
    {
        result = object_->Reset();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12Fence_Wrapper::ID3D12Fence_Wrapper(REFIID riid, ID3D12Fence* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

UINT64 STDMETHODCALLTYPE ID3D12Fence_Wrapper::GetCompletedValue()
{
    UINT64 result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCompletedValue();
    }
    else
    {
        result = object_->GetCompletedValue();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Fence_Wrapper::SetEventOnCompletion(
    UINT64 Value,
    HANDLE hEvent)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetEventOnCompletion(
            Value,
            hEvent);
    }
    else
    {
        result = object_->SetEventOnCompletion(
            Value,
            hEvent);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Fence_Wrapper::Signal(
    UINT64 Value)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Signal(
            Value);
    }
    else
    {
        result = object_->Signal(
            Value);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12Fence1_Wrapper::ID3D12Fence1_Wrapper(REFIID riid, ID3D12Fence1* object, DxWrapperResources* resources) : ID3D12Fence_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_FENCE_FLAGS STDMETHODCALLTYPE ID3D12Fence1_Wrapper::GetCreationFlags()
{
    D3D12_FENCE_FLAGS result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCreationFlags();
    }
    else
    {
        result = object_->GetCreationFlags();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12PipelineState_Wrapper::ID3D12PipelineState_Wrapper(REFIID riid, ID3D12PipelineState* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineState_Wrapper::GetCachedBlob(
    ID3DBlob** ppBlob)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCachedBlob(
            ppBlob);

        if (SUCCEEDED(result))
        {
            WrapObject(IID_ID3D10Blob, reinterpret_cast<void**>(ppBlob), nullptr);
        }
    }
    else
    {
        result = object_->GetCachedBlob(
            ppBlob);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12DescriptorHeap_Wrapper::ID3D12DescriptorHeap_Wrapper(REFIID riid, ID3D12DescriptorHeap* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_DESCRIPTOR_HEAP_DESC STDMETHODCALLTYPE ID3D12DescriptorHeap_Wrapper::GetDesc()
{
    D3D12_DESCRIPTOR_HEAP_DESC result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc();
    }
    else
    {
        result = object_->GetDesc();
    }

    manager->DecrementCallScope();

    return result;
}

D3D12_CPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE ID3D12DescriptorHeap_Wrapper::GetCPUDescriptorHandleForHeapStart()
{
    D3D12_CPU_DESCRIPTOR_HANDLE result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCPUDescriptorHandleForHeapStart();
    }
    else
    {
        result = object_->GetCPUDescriptorHandleForHeapStart();
    }

    manager->DecrementCallScope();

    return result;
}

D3D12_GPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE ID3D12DescriptorHeap_Wrapper::GetGPUDescriptorHandleForHeapStart()
{
    D3D12_GPU_DESCRIPTOR_HANDLE result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetGPUDescriptorHandleForHeapStart();
    }
    else
    {
        result = object_->GetGPUDescriptorHandleForHeapStart();
    }

    manager->DecrementCallScope();

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
    D3D12_COMMAND_LIST_TYPE result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetType();
    }
    else
    {
        result = object_->GetType();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12GraphicsCommandList_Wrapper::ID3D12GraphicsCommandList_Wrapper(REFIID riid, ID3D12GraphicsCommandList* object, DxWrapperResources* resources) : ID3D12CommandList_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::Close()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Close();
    }
    else
    {
        result = object_->Close();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::Reset(
    ID3D12CommandAllocator* pAllocator,
    ID3D12PipelineState* pInitialState)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Reset(
            encode::GetWrappedObject<ID3D12CommandAllocator_Wrapper, ID3D12CommandAllocator>(pAllocator),
            encode::GetWrappedObject<ID3D12PipelineState_Wrapper, ID3D12PipelineState>(pInitialState));
    }
    else
    {
        result = object_->Reset(
            pAllocator,
            pInitialState);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearState(
    ID3D12PipelineState* pPipelineState)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ClearState(
            encode::GetWrappedObject<ID3D12PipelineState_Wrapper, ID3D12PipelineState>(pPipelineState));
    }
    else
    {
        object_->ClearState(
            pPipelineState);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::DrawInstanced(
    UINT VertexCountPerInstance,
    UINT InstanceCount,
    UINT StartVertexLocation,
    UINT StartInstanceLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->DrawInstanced(
            VertexCountPerInstance,
            InstanceCount,
            StartVertexLocation,
            StartInstanceLocation);
    }
    else
    {
        object_->DrawInstanced(
            VertexCountPerInstance,
            InstanceCount,
            StartVertexLocation,
            StartInstanceLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::DrawIndexedInstanced(
    UINT IndexCountPerInstance,
    UINT InstanceCount,
    UINT StartIndexLocation,
    INT BaseVertexLocation,
    UINT StartInstanceLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->DrawIndexedInstanced(
            IndexCountPerInstance,
            InstanceCount,
            StartIndexLocation,
            BaseVertexLocation,
            StartInstanceLocation);
    }
    else
    {
        object_->DrawIndexedInstanced(
            IndexCountPerInstance,
            InstanceCount,
            StartIndexLocation,
            BaseVertexLocation,
            StartInstanceLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::Dispatch(
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->Dispatch(
            ThreadGroupCountX,
            ThreadGroupCountY,
            ThreadGroupCountZ);
    }
    else
    {
        object_->Dispatch(
            ThreadGroupCountX,
            ThreadGroupCountY,
            ThreadGroupCountZ);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyBufferRegion(
    ID3D12Resource* pDstBuffer,
    UINT64 DstOffset,
    ID3D12Resource* pSrcBuffer,
    UINT64 SrcOffset,
    UINT64 NumBytes)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CopyBufferRegion(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDstBuffer),
            DstOffset,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pSrcBuffer),
            SrcOffset,
            NumBytes);
    }
    else
    {
        object_->CopyBufferRegion(
            pDstBuffer,
            DstOffset,
            pSrcBuffer,
            SrcOffset,
            NumBytes);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyTextureRegion(
    const D3D12_TEXTURE_COPY_LOCATION* pDst,
    UINT DstX,
    UINT DstY,
    UINT DstZ,
    const D3D12_TEXTURE_COPY_LOCATION* pSrc,
    const D3D12_BOX* pSrcBox)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        object_->CopyTextureRegion(
            UnwrapStructPtrObjects(pDst, unwrap_memory),
            DstX,
            DstY,
            DstZ,
            UnwrapStructPtrObjects(pSrc, unwrap_memory),
            pSrcBox);
    }
    else
    {
        object_->CopyTextureRegion(
            pDst,
            DstX,
            DstY,
            DstZ,
            pSrc,
            pSrcBox);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyResource(
    ID3D12Resource* pDstResource,
    ID3D12Resource* pSrcResource)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CopyResource(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDstResource),
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pSrcResource));
    }
    else
    {
        object_->CopyResource(
            pDstResource,
            pSrcResource);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::CopyTiles(
    ID3D12Resource* pTiledResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pTileRegionSize,
    ID3D12Resource* pBuffer,
    UINT64 BufferStartOffsetInBytes,
    D3D12_TILE_COPY_FLAGS Flags)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CopyTiles(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pTiledResource),
            pTileRegionStartCoordinate,
            pTileRegionSize,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pBuffer),
            BufferStartOffsetInBytes,
            Flags);
    }
    else
    {
        object_->CopyTiles(
            pTiledResource,
            pTileRegionStartCoordinate,
            pTileRegionSize,
            pBuffer,
            BufferStartOffsetInBytes,
            Flags);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ResolveSubresource(
    ID3D12Resource* pDstResource,
    UINT DstSubresource,
    ID3D12Resource* pSrcResource,
    UINT SrcSubresource,
    DXGI_FORMAT Format)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ResolveSubresource(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDstResource),
            DstSubresource,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pSrcResource),
            SrcSubresource,
            Format);
    }
    else
    {
        object_->ResolveSubresource(
            pDstResource,
            DstSubresource,
            pSrcResource,
            SrcSubresource,
            Format);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::IASetPrimitiveTopology(
    D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->IASetPrimitiveTopology(
            PrimitiveTopology);
    }
    else
    {
        object_->IASetPrimitiveTopology(
            PrimitiveTopology);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::RSSetViewports(
    UINT NumViewports,
    const D3D12_VIEWPORT* pViewports)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->RSSetViewports(
            NumViewports,
            pViewports);
    }
    else
    {
        object_->RSSetViewports(
            NumViewports,
            pViewports);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::RSSetScissorRects(
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->RSSetScissorRects(
            NumRects,
            pRects);
    }
    else
    {
        object_->RSSetScissorRects(
            NumRects,
            pRects);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::OMSetBlendFactor(
    const FLOAT BlendFactor [4])
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->OMSetBlendFactor(
            BlendFactor);
    }
    else
    {
        object_->OMSetBlendFactor(
            BlendFactor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::OMSetStencilRef(
    UINT StencilRef)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->OMSetStencilRef(
            StencilRef);
    }
    else
    {
        object_->OMSetStencilRef(
            StencilRef);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetPipelineState(
    ID3D12PipelineState* pPipelineState)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetPipelineState(
            encode::GetWrappedObject<ID3D12PipelineState_Wrapper, ID3D12PipelineState>(pPipelineState));
    }
    else
    {
        object_->SetPipelineState(
            pPipelineState);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ResourceBarrier(
    UINT NumBarriers,
    const D3D12_RESOURCE_BARRIER* pBarriers)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        object_->ResourceBarrier(
            NumBarriers,
            UnwrapStructArrayObjects(pBarriers, NumBarriers, unwrap_memory));
    }
    else
    {
        object_->ResourceBarrier(
            NumBarriers,
            pBarriers);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ExecuteBundle(
    ID3D12GraphicsCommandList* pCommandList)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ExecuteBundle(
            encode::GetWrappedObject<ID3D12GraphicsCommandList_Wrapper, ID3D12GraphicsCommandList>(pCommandList));
    }
    else
    {
        object_->ExecuteBundle(
            pCommandList);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetDescriptorHeaps(
    UINT NumDescriptorHeaps,
    ID3D12DescriptorHeap* const* ppDescriptorHeaps)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        object_->SetDescriptorHeaps(
            NumDescriptorHeaps,
            UnwrapObjects<ID3D12DescriptorHeap_Wrapper, ID3D12DescriptorHeap>(ppDescriptorHeaps, NumDescriptorHeaps, unwrap_memory));
    }
    else
    {
        object_->SetDescriptorHeaps(
            NumDescriptorHeaps,
            ppDescriptorHeaps);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootSignature(
    ID3D12RootSignature* pRootSignature)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetComputeRootSignature(
            encode::GetWrappedObject<ID3D12RootSignature_Wrapper, ID3D12RootSignature>(pRootSignature));
    }
    else
    {
        object_->SetComputeRootSignature(
            pRootSignature);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootSignature(
    ID3D12RootSignature* pRootSignature)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetGraphicsRootSignature(
            encode::GetWrappedObject<ID3D12RootSignature_Wrapper, ID3D12RootSignature>(pRootSignature));
    }
    else
    {
        object_->SetGraphicsRootSignature(
            pRootSignature);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootDescriptorTable(
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetComputeRootDescriptorTable(
            RootParameterIndex,
            BaseDescriptor);
    }
    else
    {
        object_->SetComputeRootDescriptorTable(
            RootParameterIndex,
            BaseDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootDescriptorTable(
    UINT RootParameterIndex,
    D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetGraphicsRootDescriptorTable(
            RootParameterIndex,
            BaseDescriptor);
    }
    else
    {
        object_->SetGraphicsRootDescriptorTable(
            RootParameterIndex,
            BaseDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRoot32BitConstant(
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetComputeRoot32BitConstant(
            RootParameterIndex,
            SrcData,
            DestOffsetIn32BitValues);
    }
    else
    {
        object_->SetComputeRoot32BitConstant(
            RootParameterIndex,
            SrcData,
            DestOffsetIn32BitValues);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRoot32BitConstant(
    UINT RootParameterIndex,
    UINT SrcData,
    UINT DestOffsetIn32BitValues)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetGraphicsRoot32BitConstant(
            RootParameterIndex,
            SrcData,
            DestOffsetIn32BitValues);
    }
    else
    {
        object_->SetGraphicsRoot32BitConstant(
            RootParameterIndex,
            SrcData,
            DestOffsetIn32BitValues);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRoot32BitConstants(
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetComputeRoot32BitConstants(
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
            DestOffsetIn32BitValues);
    }
    else
    {
        object_->SetComputeRoot32BitConstants(
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
            DestOffsetIn32BitValues);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRoot32BitConstants(
    UINT RootParameterIndex,
    UINT Num32BitValuesToSet,
    const void* pSrcData,
    UINT DestOffsetIn32BitValues)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetGraphicsRoot32BitConstants(
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
            DestOffsetIn32BitValues);
    }
    else
    {
        object_->SetGraphicsRoot32BitConstants(
            RootParameterIndex,
            Num32BitValuesToSet,
            pSrcData,
            DestOffsetIn32BitValues);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootConstantBufferView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetComputeRootConstantBufferView(
            RootParameterIndex,
            BufferLocation);
    }
    else
    {
        object_->SetComputeRootConstantBufferView(
            RootParameterIndex,
            BufferLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootConstantBufferView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetGraphicsRootConstantBufferView(
            RootParameterIndex,
            BufferLocation);
    }
    else
    {
        object_->SetGraphicsRootConstantBufferView(
            RootParameterIndex,
            BufferLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootShaderResourceView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetComputeRootShaderResourceView(
            RootParameterIndex,
            BufferLocation);
    }
    else
    {
        object_->SetComputeRootShaderResourceView(
            RootParameterIndex,
            BufferLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootShaderResourceView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetGraphicsRootShaderResourceView(
            RootParameterIndex,
            BufferLocation);
    }
    else
    {
        object_->SetGraphicsRootShaderResourceView(
            RootParameterIndex,
            BufferLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetComputeRootUnorderedAccessView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetComputeRootUnorderedAccessView(
            RootParameterIndex,
            BufferLocation);
    }
    else
    {
        object_->SetComputeRootUnorderedAccessView(
            RootParameterIndex,
            BufferLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetGraphicsRootUnorderedAccessView(
    UINT RootParameterIndex,
    D3D12_GPU_VIRTUAL_ADDRESS BufferLocation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetGraphicsRootUnorderedAccessView(
            RootParameterIndex,
            BufferLocation);
    }
    else
    {
        object_->SetGraphicsRootUnorderedAccessView(
            RootParameterIndex,
            BufferLocation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::IASetIndexBuffer(
    const D3D12_INDEX_BUFFER_VIEW* pView)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->IASetIndexBuffer(
            pView);
    }
    else
    {
        object_->IASetIndexBuffer(
            pView);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::IASetVertexBuffers(
    UINT StartSlot,
    UINT NumViews,
    const D3D12_VERTEX_BUFFER_VIEW* pViews)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->IASetVertexBuffers(
            StartSlot,
            NumViews,
            pViews);
    }
    else
    {
        object_->IASetVertexBuffers(
            StartSlot,
            NumViews,
            pViews);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SOSetTargets(
    UINT StartSlot,
    UINT NumViews,
    const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SOSetTargets(
            StartSlot,
            NumViews,
            pViews);
    }
    else
    {
        object_->SOSetTargets(
            StartSlot,
            NumViews,
            pViews);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::OMSetRenderTargets(
    UINT NumRenderTargetDescriptors,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
    BOOL RTsSingleHandleToDescriptorRange,
    const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->OMSetRenderTargets(
            NumRenderTargetDescriptors,
            pRenderTargetDescriptors,
            RTsSingleHandleToDescriptorRange,
            pDepthStencilDescriptor);
    }
    else
    {
        object_->OMSetRenderTargets(
            NumRenderTargetDescriptors,
            pRenderTargetDescriptors,
            RTsSingleHandleToDescriptorRange,
            pDepthStencilDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearDepthStencilView(
    D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
    D3D12_CLEAR_FLAGS ClearFlags,
    FLOAT Depth,
    UINT8 Stencil,
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ClearDepthStencilView(
            DepthStencilView,
            ClearFlags,
            Depth,
            Stencil,
            NumRects,
            pRects);
    }
    else
    {
        object_->ClearDepthStencilView(
            DepthStencilView,
            ClearFlags,
            Depth,
            Stencil,
            NumRects,
            pRects);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearRenderTargetView(
    D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
    const FLOAT ColorRGBA [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ClearRenderTargetView(
            RenderTargetView,
            ColorRGBA,
            NumRects,
            pRects);
    }
    else
    {
        object_->ClearRenderTargetView(
            RenderTargetView,
            ColorRGBA,
            NumRects,
            pRects);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearUnorderedAccessViewUint(
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const UINT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ClearUnorderedAccessViewUint(
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            Values,
            NumRects,
            pRects);
    }
    else
    {
        object_->ClearUnorderedAccessViewUint(
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            pResource,
            Values,
            NumRects,
            pRects);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ClearUnorderedAccessViewFloat(
    D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
    D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
    ID3D12Resource* pResource,
    const FLOAT Values [4],
    UINT NumRects,
    const D3D12_RECT* pRects)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ClearUnorderedAccessViewFloat(
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            Values,
            NumRects,
            pRects);
    }
    else
    {
        object_->ClearUnorderedAccessViewFloat(
            ViewGPUHandleInCurrentHeap,
            ViewCPUHandle,
            pResource,
            Values,
            NumRects,
            pRects);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::DiscardResource(
    ID3D12Resource* pResource,
    const D3D12_DISCARD_REGION* pRegion)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->DiscardResource(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            pRegion);
    }
    else
    {
        object_->DiscardResource(
            pResource,
            pRegion);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::BeginQuery(
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->BeginQuery(
            encode::GetWrappedObject<ID3D12QueryHeap_Wrapper, ID3D12QueryHeap>(pQueryHeap),
            Type,
            Index);
    }
    else
    {
        object_->BeginQuery(
            pQueryHeap,
            Type,
            Index);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::EndQuery(
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT Index)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->EndQuery(
            encode::GetWrappedObject<ID3D12QueryHeap_Wrapper, ID3D12QueryHeap>(pQueryHeap),
            Type,
            Index);
    }
    else
    {
        object_->EndQuery(
            pQueryHeap,
            Type,
            Index);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ResolveQueryData(
    ID3D12QueryHeap* pQueryHeap,
    D3D12_QUERY_TYPE Type,
    UINT StartIndex,
    UINT NumQueries,
    ID3D12Resource* pDestinationBuffer,
    UINT64 AlignedDestinationBufferOffset)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ResolveQueryData(
            encode::GetWrappedObject<ID3D12QueryHeap_Wrapper, ID3D12QueryHeap>(pQueryHeap),
            Type,
            StartIndex,
            NumQueries,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDestinationBuffer),
            AlignedDestinationBufferOffset);
    }
    else
    {
        object_->ResolveQueryData(
            pQueryHeap,
            Type,
            StartIndex,
            NumQueries,
            pDestinationBuffer,
            AlignedDestinationBufferOffset);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetPredication(
    ID3D12Resource* pBuffer,
    UINT64 AlignedBufferOffset,
    D3D12_PREDICATION_OP Operation)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetPredication(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pBuffer),
            AlignedBufferOffset,
            Operation);
    }
    else
    {
        object_->SetPredication(
            pBuffer,
            AlignedBufferOffset,
            Operation);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::SetMarker(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetMarker(
            Metadata,
            pData,
            Size);
    }
    else
    {
        object_->SetMarker(
            Metadata,
            pData,
            Size);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::BeginEvent(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->BeginEvent(
            Metadata,
            pData,
            Size);
    }
    else
    {
        object_->BeginEvent(
            Metadata,
            pData,
            Size);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::EndEvent()
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->EndEvent();
    }
    else
    {
        object_->EndEvent();
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList_Wrapper::ExecuteIndirect(
    ID3D12CommandSignature* pCommandSignature,
    UINT MaxCommandCount,
    ID3D12Resource* pArgumentBuffer,
    UINT64 ArgumentBufferOffset,
    ID3D12Resource* pCountBuffer,
    UINT64 CountBufferOffset)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ExecuteIndirect(
            encode::GetWrappedObject<ID3D12CommandSignature_Wrapper, ID3D12CommandSignature>(pCommandSignature),
            MaxCommandCount,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pArgumentBuffer),
            ArgumentBufferOffset,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pCountBuffer),
            CountBufferOffset);
    }
    else
    {
        object_->ExecuteIndirect(
            pCommandSignature,
            MaxCommandCount,
            pArgumentBuffer,
            ArgumentBufferOffset,
            pCountBuffer,
            CountBufferOffset);
    }

    manager->DecrementCallScope();
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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        object_->AtomicCopyBufferUINT(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDstBuffer),
            DstOffset,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pSrcBuffer),
            SrcOffset,
            Dependencies,
            UnwrapObjects<ID3D12Resource_Wrapper, ID3D12Resource>(ppDependentResources, Dependencies, unwrap_memory),
            pDependentSubresourceRanges);
    }
    else
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

    manager->DecrementCallScope();
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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        object_->AtomicCopyBufferUINT64(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDstBuffer),
            DstOffset,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pSrcBuffer),
            SrcOffset,
            Dependencies,
            UnwrapObjects<ID3D12Resource_Wrapper, ID3D12Resource>(ppDependentResources, Dependencies, unwrap_memory),
            pDependentSubresourceRanges);
    }
    else
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

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::OMSetDepthBounds(
    FLOAT Min,
    FLOAT Max)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->OMSetDepthBounds(
            Min,
            Max);
    }
    else
    {
        object_->OMSetDepthBounds(
            Min,
            Max);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::SetSamplePositions(
    UINT NumSamplesPerPixel,
    UINT NumPixels,
    D3D12_SAMPLE_POSITION* pSamplePositions)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetSamplePositions(
            NumSamplesPerPixel,
            NumPixels,
            pSamplePositions);
    }
    else
    {
        object_->SetSamplePositions(
            NumSamplesPerPixel,
            NumPixels,
            pSamplePositions);
    }

    manager->DecrementCallScope();
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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ResolveSubresourceRegion(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDstResource),
            DstSubresource,
            DstX,
            DstY,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pSrcResource),
            SrcSubresource,
            pSrcRect,
            Format,
            ResolveMode);
    }
    else
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

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList1_Wrapper::SetViewInstanceMask(
    UINT Mask)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetViewInstanceMask(
            Mask);
    }
    else
    {
        object_->SetViewInstanceMask(
            Mask);
    }

    manager->DecrementCallScope();
}

ID3D12GraphicsCommandList2_Wrapper::ID3D12GraphicsCommandList2_Wrapper(REFIID riid, ID3D12GraphicsCommandList2* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList1_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList2_Wrapper::WriteBufferImmediate(
    UINT Count,
    const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
    const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->WriteBufferImmediate(
            Count,
            pParams,
            pModes);
    }
    else
    {
        object_->WriteBufferImmediate(
            Count,
            pParams,
            pModes);
    }

    manager->DecrementCallScope();
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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->UpdateTileMappings(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            NumResourceRegions,
            pResourceRegionStartCoordinates,
            pResourceRegionSizes,
            encode::GetWrappedObject<ID3D12Heap_Wrapper, ID3D12Heap>(pHeap),
            NumRanges,
            pRangeFlags,
            pHeapRangeStartOffsets,
            pRangeTileCounts,
            Flags);
    }
    else
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

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::CopyTileMappings(
    ID3D12Resource* pDstResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
    ID3D12Resource* pSrcResource,
    const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
    const D3D12_TILE_REGION_SIZE* pRegionSize,
    D3D12_TILE_MAPPING_FLAGS Flags)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CopyTileMappings(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pDstResource),
            pDstRegionStartCoordinate,
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pSrcResource),
            pSrcRegionStartCoordinate,
            pRegionSize,
            Flags);
    }
    else
    {
        object_->CopyTileMappings(
            pDstResource,
            pDstRegionStartCoordinate,
            pSrcResource,
            pSrcRegionStartCoordinate,
            pRegionSize,
            Flags);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::ExecuteCommandLists(
    UINT NumCommandLists,
    ID3D12CommandList* const* ppCommandLists)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        object_->ExecuteCommandLists(
            NumCommandLists,
            UnwrapObjects<ID3D12CommandList_Wrapper, ID3D12CommandList>(ppCommandLists, NumCommandLists, unwrap_memory));
    }
    else
    {
        object_->ExecuteCommandLists(
            NumCommandLists,
            ppCommandLists);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::SetMarker(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetMarker(
            Metadata,
            pData,
            Size);
    }
    else
    {
        object_->SetMarker(
            Metadata,
            pData,
            Size);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::BeginEvent(
    UINT Metadata,
    const void* pData,
    UINT Size)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->BeginEvent(
            Metadata,
            pData,
            Size);
    }
    else
    {
        object_->BeginEvent(
            Metadata,
            pData,
            Size);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::EndEvent()
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->EndEvent();
    }
    else
    {
        object_->EndEvent();
    }

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::Signal(
    ID3D12Fence* pFence,
    UINT64 Value)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Signal(
            encode::GetWrappedObject<ID3D12Fence_Wrapper, ID3D12Fence>(pFence),
            Value);
    }
    else
    {
        result = object_->Signal(
            pFence,
            Value);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::Wait(
    ID3D12Fence* pFence,
    UINT64 Value)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Wait(
            encode::GetWrappedObject<ID3D12Fence_Wrapper, ID3D12Fence>(pFence),
            Value);
    }
    else
    {
        result = object_->Wait(
            pFence,
            Value);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::GetTimestampFrequency(
    UINT64* pFrequency)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetTimestampFrequency(
            pFrequency);
    }
    else
    {
        result = object_->GetTimestampFrequency(
            pFrequency);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::GetClockCalibration(
    UINT64* pGpuTimestamp,
    UINT64* pCpuTimestamp)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetClockCalibration(
            pGpuTimestamp,
            pCpuTimestamp);
    }
    else
    {
        result = object_->GetClockCalibration(
            pGpuTimestamp,
            pCpuTimestamp);
    }

    manager->DecrementCallScope();

    return result;
}

D3D12_COMMAND_QUEUE_DESC STDMETHODCALLTYPE ID3D12CommandQueue_Wrapper::GetDesc()
{
    D3D12_COMMAND_QUEUE_DESC result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc();
    }
    else
    {
        result = object_->GetDesc();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12Device_Wrapper::ID3D12Device_Wrapper(REFIID riid, ID3D12Device* object, DxWrapperResources* resources) : ID3D12Object_Wrapper(riid, object, resources), object_(object)
{
}

UINT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetNodeCount()
{
    UINT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetNodeCount();
    }
    else
    {
        result = object_->GetNodeCount();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandQueue(
    const D3D12_COMMAND_QUEUE_DESC* pDesc,
    REFIID riid,
    void** ppCommandQueue)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommandQueue(
            pDesc,
            riid,
            ppCommandQueue);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppCommandQueue, nullptr);
        }
    }
    else
    {
        result = object_->CreateCommandQueue(
            pDesc,
            riid,
            ppCommandQueue);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandAllocator(
    D3D12_COMMAND_LIST_TYPE type,
    REFIID riid,
    void** ppCommandAllocator)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommandAllocator(
            type,
            riid,
            ppCommandAllocator);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppCommandAllocator, nullptr);
        }
    }
    else
    {
        result = object_->CreateCommandAllocator(
            type,
            riid,
            ppCommandAllocator);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateGraphicsPipelineState(
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->CreateGraphicsPipelineState(
            UnwrapStructPtrObjects(pDesc, unwrap_memory),
            riid,
            ppPipelineState);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppPipelineState, nullptr);
        }
    }
    else
    {
        result = object_->CreateGraphicsPipelineState(
            pDesc,
            riid,
            ppPipelineState);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateComputePipelineState(
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->CreateComputePipelineState(
            UnwrapStructPtrObjects(pDesc, unwrap_memory),
            riid,
            ppPipelineState);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppPipelineState, nullptr);
        }
    }
    else
    {
        result = object_->CreateComputePipelineState(
            pDesc,
            riid,
            ppPipelineState);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommandList(
            nodeMask,
            type,
            encode::GetWrappedObject<ID3D12CommandAllocator_Wrapper, ID3D12CommandAllocator>(pCommandAllocator),
            encode::GetWrappedObject<ID3D12PipelineState_Wrapper, ID3D12PipelineState>(pInitialState),
            riid,
            ppCommandList);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppCommandList, nullptr);
        }
    }
    else
    {
        result = object_->CreateCommandList(
            nodeMask,
            type,
            pCommandAllocator,
            pInitialState,
            riid,
            ppCommandList);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CheckFeatureSupport(
    D3D12_FEATURE Feature,
    void* pFeatureSupportData,
    UINT FeatureSupportDataSize)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckFeatureSupport(
            Feature,
            pFeatureSupportData,
            FeatureSupportDataSize);
    }
    else
    {
        result = object_->CheckFeatureSupport(
            Feature,
            pFeatureSupportData,
            FeatureSupportDataSize);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateDescriptorHeap(
    const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
    REFIID riid,
    void** ppvHeap)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateDescriptorHeap(
            pDescriptorHeapDesc,
            riid,
            ppvHeap);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvHeap, nullptr);
        }
    }
    else
    {
        result = object_->CreateDescriptorHeap(
            pDescriptorHeapDesc,
            riid,
            ppvHeap);
    }

    manager->DecrementCallScope();

    return result;
}

UINT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetDescriptorHandleIncrementSize(
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType)
{
    UINT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDescriptorHandleIncrementSize(
            DescriptorHeapType);
    }
    else
    {
        result = object_->GetDescriptorHandleIncrementSize(
            DescriptorHeapType);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateRootSignature(
    UINT nodeMask,
    const void* pBlobWithRootSignature,
    SIZE_T blobLengthInBytes,
    REFIID riid,
    void** ppvRootSignature)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateRootSignature(
            nodeMask,
            pBlobWithRootSignature,
            blobLengthInBytes,
            riid,
            ppvRootSignature);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvRootSignature, nullptr);
        }
    }
    else
    {
        result = object_->CreateRootSignature(
            nodeMask,
            pBlobWithRootSignature,
            blobLengthInBytes,
            riid,
            ppvRootSignature);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateConstantBufferView(
    const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CreateConstantBufferView(
            pDesc,
            DestDescriptor);
    }
    else
    {
        object_->CreateConstantBufferView(
            pDesc,
            DestDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateShaderResourceView(
    ID3D12Resource* pResource,
    const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CreateShaderResourceView(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            pDesc,
            DestDescriptor);
    }
    else
    {
        object_->CreateShaderResourceView(
            pResource,
            pDesc,
            DestDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateUnorderedAccessView(
    ID3D12Resource* pResource,
    ID3D12Resource* pCounterResource,
    const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CreateUnorderedAccessView(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pCounterResource),
            pDesc,
            DestDescriptor);
    }
    else
    {
        object_->CreateUnorderedAccessView(
            pResource,
            pCounterResource,
            pDesc,
            DestDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateRenderTargetView(
    ID3D12Resource* pResource,
    const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CreateRenderTargetView(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            pDesc,
            DestDescriptor);
    }
    else
    {
        object_->CreateRenderTargetView(
            pResource,
            pDesc,
            DestDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateDepthStencilView(
    ID3D12Resource* pResource,
    const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CreateDepthStencilView(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pResource),
            pDesc,
            DestDescriptor);
    }
    else
    {
        object_->CreateDepthStencilView(
            pResource,
            pDesc,
            DestDescriptor);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateSampler(
    const D3D12_SAMPLER_DESC* pDesc,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CreateSampler(
            pDesc,
            DestDescriptor);
    }
    else
    {
        object_->CreateSampler(
            pDesc,
            DestDescriptor);
    }

    manager->DecrementCallScope();
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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
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
    else
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

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12Device_Wrapper::CopyDescriptorsSimple(
    UINT NumDescriptors,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
    D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
    D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CopyDescriptorsSimple(
            NumDescriptors,
            DestDescriptorRangeStart,
            SrcDescriptorRangeStart,
            DescriptorHeapsType);
    }
    else
    {
        object_->CopyDescriptorsSimple(
            NumDescriptors,
            DestDescriptorRangeStart,
            SrcDescriptorRangeStart,
            DescriptorHeapsType);
    }

    manager->DecrementCallScope();
}

D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE ID3D12Device_Wrapper::GetResourceAllocationInfo(
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs)
{
    D3D12_RESOURCE_ALLOCATION_INFO result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetResourceAllocationInfo(
            visibleMask,
            numResourceDescs,
            pResourceDescs);
    }
    else
    {
        result = object_->GetResourceAllocationInfo(
            visibleMask,
            numResourceDescs,
            pResourceDescs);
    }

    manager->DecrementCallScope();

    return result;
}

D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE ID3D12Device_Wrapper::GetCustomHeapProperties(
    UINT nodeMask,
    D3D12_HEAP_TYPE heapType)
{
    D3D12_HEAP_PROPERTIES result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCustomHeapProperties(
            nodeMask,
            heapType);
    }
    else
    {
        result = object_->GetCustomHeapProperties(
            nodeMask,
            heapType);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommittedResource(
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
    }
    else
    {
        result = object_->CreateCommittedResource(
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            riidResource,
            ppvResource);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateHeap(
    const D3D12_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateHeap(
            pDesc,
            riid,
            ppvHeap);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvHeap, nullptr);
        }
    }
    else
    {
        result = object_->CreateHeap(
            pDesc,
            riid,
            ppvHeap);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreatePlacedResource(
            encode::GetWrappedObject<ID3D12Heap_Wrapper, ID3D12Heap>(pHeap),
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
    }
    else
    {
        result = object_->CreatePlacedResource(
            pHeap,
            HeapOffset,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateReservedResource(
    const D3D12_RESOURCE_DESC* pDesc,
    D3D12_RESOURCE_STATES InitialState,
    const D3D12_CLEAR_VALUE* pOptimizedClearValue,
    REFIID riid,
    void** ppvResource)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateReservedResource(
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvResource, nullptr);
        }
    }
    else
    {
        result = object_->CreateReservedResource(
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateSharedHandle(
    ID3D12DeviceChild* pObject,
    const SECURITY_ATTRIBUTES* pAttributes,
    DWORD Access,
    LPCWSTR Name,
    HANDLE* pHandle)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateSharedHandle(
            encode::GetWrappedObject<ID3D12DeviceChild_Wrapper, ID3D12DeviceChild>(pObject),
            pAttributes,
            Access,
            Name,
            pHandle);
    }
    else
    {
        result = object_->CreateSharedHandle(
            pObject,
            pAttributes,
            Access,
            Name,
            pHandle);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::OpenSharedHandle(
    HANDLE NTHandle,
    REFIID riid,
    void** ppvObj)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->OpenSharedHandle(
            NTHandle,
            riid,
            ppvObj);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvObj, nullptr);
        }
    }
    else
    {
        result = object_->OpenSharedHandle(
            NTHandle,
            riid,
            ppvObj);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::OpenSharedHandleByName(
    LPCWSTR Name,
    DWORD Access,
    HANDLE* pNTHandle)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->OpenSharedHandleByName(
            Name,
            Access,
            pNTHandle);
    }
    else
    {
        result = object_->OpenSharedHandleByName(
            Name,
            Access,
            pNTHandle);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::MakeResident(
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->MakeResident(
            NumObjects,
            UnwrapObjects<ID3D12Pageable_Wrapper, ID3D12Pageable>(ppObjects, NumObjects, unwrap_memory));
    }
    else
    {
        result = object_->MakeResident(
            NumObjects,
            ppObjects);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::Evict(
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->Evict(
            NumObjects,
            UnwrapObjects<ID3D12Pageable_Wrapper, ID3D12Pageable>(ppObjects, NumObjects, unwrap_memory));
    }
    else
    {
        result = object_->Evict(
            NumObjects,
            ppObjects);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateFence(
    UINT64 InitialValue,
    D3D12_FENCE_FLAGS Flags,
    REFIID riid,
    void** ppFence)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateFence(
            InitialValue,
            Flags,
            riid,
            ppFence);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppFence, nullptr);
        }
    }
    else
    {
        result = object_->CreateFence(
            InitialValue,
            Flags,
            riid,
            ppFence);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::GetDeviceRemovedReason()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDeviceRemovedReason();
    }
    else
    {
        result = object_->GetDeviceRemovedReason();
    }

    manager->DecrementCallScope();

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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
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
    else
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

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateQueryHeap(
    const D3D12_QUERY_HEAP_DESC* pDesc,
    REFIID riid,
    void** ppvHeap)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateQueryHeap(
            pDesc,
            riid,
            ppvHeap);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvHeap, nullptr);
        }
    }
    else
    {
        result = object_->CreateQueryHeap(
            pDesc,
            riid,
            ppvHeap);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::SetStablePowerState(
    BOOL Enable)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetStablePowerState(
            Enable);
    }
    else
    {
        result = object_->SetStablePowerState(
            Enable);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device_Wrapper::CreateCommandSignature(
    const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
    ID3D12RootSignature* pRootSignature,
    REFIID riid,
    void** ppvCommandSignature)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommandSignature(
            pDesc,
            encode::GetWrappedObject<ID3D12RootSignature_Wrapper, ID3D12RootSignature>(pRootSignature),
            riid,
            ppvCommandSignature);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvCommandSignature, nullptr);
        }
    }
    else
    {
        result = object_->CreateCommandSignature(
            pDesc,
            pRootSignature,
            riid,
            ppvCommandSignature);
    }

    manager->DecrementCallScope();

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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->GetResourceTiling(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pTiledResource),
            pNumTilesForEntireResource,
            pPackedMipDesc,
            pStandardTileShapeForNonPackedMips,
            pNumSubresourceTilings,
            FirstSubresourceTilingToGet,
            pSubresourceTilingsForNonPackedMips);
    }
    else
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

    manager->DecrementCallScope();
}

LUID STDMETHODCALLTYPE ID3D12Device_Wrapper::GetAdapterLuid()
{
    LUID result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetAdapterLuid();
    }
    else
    {
        result = object_->GetAdapterLuid();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12PipelineLibrary_Wrapper::ID3D12PipelineLibrary_Wrapper(REFIID riid, ID3D12PipelineLibrary* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::StorePipeline(
    LPCWSTR pName,
    ID3D12PipelineState* pPipeline)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->StorePipeline(
            pName,
            encode::GetWrappedObject<ID3D12PipelineState_Wrapper, ID3D12PipelineState>(pPipeline));
    }
    else
    {
        result = object_->StorePipeline(
            pName,
            pPipeline);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::LoadGraphicsPipeline(
    LPCWSTR pName,
    const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->LoadGraphicsPipeline(
            pName,
            UnwrapStructPtrObjects(pDesc, unwrap_memory),
            riid,
            ppPipelineState);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppPipelineState, nullptr);
        }
    }
    else
    {
        result = object_->LoadGraphicsPipeline(
            pName,
            pDesc,
            riid,
            ppPipelineState);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::LoadComputePipeline(
    LPCWSTR pName,
    const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
    REFIID riid,
    void** ppPipelineState)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->LoadComputePipeline(
            pName,
            UnwrapStructPtrObjects(pDesc, unwrap_memory),
            riid,
            ppPipelineState);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppPipelineState, nullptr);
        }
    }
    else
    {
        result = object_->LoadComputePipeline(
            pName,
            pDesc,
            riid,
            ppPipelineState);
    }

    manager->DecrementCallScope();

    return result;
}

SIZE_T STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::GetSerializedSize()
{
    SIZE_T result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetSerializedSize();
    }
    else
    {
        result = object_->GetSerializedSize();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12PipelineLibrary_Wrapper::Serialize(
    void* pData,
    SIZE_T DataSizeInBytes)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->Serialize(
            pData,
            DataSizeInBytes);
    }
    else
    {
        result = object_->Serialize(
            pData,
            DataSizeInBytes);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->LoadPipeline(
            pName,
            pDesc,
            riid,
            ppPipelineState);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppPipelineState, nullptr);
        }
    }
    else
    {
        result = object_->LoadPipeline(
            pName,
            pDesc,
            riid,
            ppPipelineState);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreatePipelineLibrary(
            pLibraryBlob,
            BlobLength,
            riid,
            ppPipelineLibrary);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppPipelineLibrary, nullptr);
        }
    }
    else
    {
        result = object_->CreatePipelineLibrary(
            pLibraryBlob,
            BlobLength,
            riid,
            ppPipelineLibrary);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device1_Wrapper::SetEventOnMultipleFenceCompletion(
    ID3D12Fence* const* ppFences,
    const UINT64* pFenceValues,
    UINT NumFences,
    D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
    HANDLE hEvent)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->SetEventOnMultipleFenceCompletion(
            UnwrapObjects<ID3D12Fence_Wrapper, ID3D12Fence>(ppFences, NumFences, unwrap_memory),
            pFenceValues,
            NumFences,
            Flags,
            hEvent);
    }
    else
    {
        result = object_->SetEventOnMultipleFenceCompletion(
            ppFences,
            pFenceValues,
            NumFences,
            Flags,
            hEvent);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device1_Wrapper::SetResidencyPriority(
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    const D3D12_RESIDENCY_PRIORITY* pPriorities)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->SetResidencyPriority(
            NumObjects,
            UnwrapObjects<ID3D12Pageable_Wrapper, ID3D12Pageable>(ppObjects, NumObjects, unwrap_memory),
            pPriorities);
    }
    else
    {
        result = object_->SetResidencyPriority(
            NumObjects,
            ppObjects,
            pPriorities);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreatePipelineState(
            pDesc,
            riid,
            ppPipelineState);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppPipelineState, nullptr);
        }
    }
    else
    {
        result = object_->CreatePipelineState(
            pDesc,
            riid,
            ppPipelineState);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->OpenExistingHeapFromAddress(
            pAddress,
            riid,
            ppvHeap);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvHeap, nullptr);
        }
    }
    else
    {
        result = object_->OpenExistingHeapFromAddress(
            pAddress,
            riid,
            ppvHeap);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device3_Wrapper::OpenExistingHeapFromFileMapping(
    HANDLE hFileMapping,
    REFIID riid,
    void** ppvHeap)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->OpenExistingHeapFromFileMapping(
            hFileMapping,
            riid,
            ppvHeap);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvHeap, nullptr);
        }
    }
    else
    {
        result = object_->OpenExistingHeapFromFileMapping(
            hFileMapping,
            riid,
            ppvHeap);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device3_Wrapper::EnqueueMakeResident(
    D3D12_RESIDENCY_FLAGS Flags,
    UINT NumObjects,
    ID3D12Pageable* const* ppObjects,
    ID3D12Fence* pFenceToSignal,
    UINT64 FenceValueToSignal)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        auto unwrap_memory = manager->GetHandleUnwrapMemory();

        result = object_->EnqueueMakeResident(
            Flags,
            NumObjects,
            UnwrapObjects<ID3D12Pageable_Wrapper, ID3D12Pageable>(ppObjects, NumObjects, unwrap_memory),
            encode::GetWrappedObject<ID3D12Fence_Wrapper, ID3D12Fence>(pFenceToSignal),
            FenceValueToSignal);
    }
    else
    {
        result = object_->EnqueueMakeResident(
            Flags,
            NumObjects,
            ppObjects,
            pFenceToSignal,
            FenceValueToSignal);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12ProtectedSession_Wrapper::ID3D12ProtectedSession_Wrapper(REFIID riid, ID3D12ProtectedSession* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12ProtectedSession_Wrapper::GetStatusFence(
    REFIID riid,
    void** ppFence)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetStatusFence(
            riid,
            ppFence);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppFence, nullptr);
        }
    }
    else
    {
        result = object_->GetStatusFence(
            riid,
            ppFence);
    }

    manager->DecrementCallScope();

    return result;
}

D3D12_PROTECTED_SESSION_STATUS STDMETHODCALLTYPE ID3D12ProtectedSession_Wrapper::GetSessionStatus()
{
    D3D12_PROTECTED_SESSION_STATUS result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetSessionStatus();
    }
    else
    {
        result = object_->GetSessionStatus();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12ProtectedResourceSession_Wrapper::ID3D12ProtectedResourceSession_Wrapper(REFIID riid, ID3D12ProtectedResourceSession* object, DxWrapperResources* resources) : ID3D12ProtectedSession_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_PROTECTED_RESOURCE_SESSION_DESC STDMETHODCALLTYPE ID3D12ProtectedResourceSession_Wrapper::GetDesc()
{
    D3D12_PROTECTED_RESOURCE_SESSION_DESC result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc();
    }
    else
    {
        result = object_->GetDesc();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommandList1(
            nodeMask,
            type,
            flags,
            riid,
            ppCommandList);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppCommandList, nullptr);
        }
    }
    else
    {
        result = object_->CreateCommandList1(
            nodeMask,
            type,
            flags,
            riid,
            ppCommandList);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device4_Wrapper::CreateProtectedResourceSession(
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
    REFIID riid,
    void** ppSession)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateProtectedResourceSession(
            pDesc,
            riid,
            ppSession);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppSession, nullptr);
        }
    }
    else
    {
        result = object_->CreateProtectedResourceSession(
            pDesc,
            riid,
            ppSession);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommittedResource1(
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            encode::GetWrappedObject<ID3D12ProtectedResourceSession_Wrapper, ID3D12ProtectedResourceSession>(pProtectedSession),
            riidResource,
            ppvResource);

        if (SUCCEEDED(result))
        {
            WrapObject(riidResource, ppvResource, nullptr);
        }
    }
    else
    {
        result = object_->CreateCommittedResource1(
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            pProtectedSession,
            riidResource,
            ppvResource);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device4_Wrapper::CreateHeap1(
    const D3D12_HEAP_DESC* pDesc,
    ID3D12ProtectedResourceSession* pProtectedSession,
    REFIID riid,
    void** ppvHeap)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateHeap1(
            pDesc,
            encode::GetWrappedObject<ID3D12ProtectedResourceSession_Wrapper, ID3D12ProtectedResourceSession>(pProtectedSession),
            riid,
            ppvHeap);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvHeap, nullptr);
        }
    }
    else
    {
        result = object_->CreateHeap1(
            pDesc,
            pProtectedSession,
            riid,
            ppvHeap);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateReservedResource1(
            pDesc,
            InitialState,
            pOptimizedClearValue,
            encode::GetWrappedObject<ID3D12ProtectedResourceSession_Wrapper, ID3D12ProtectedResourceSession>(pProtectedSession),
            riid,
            ppvResource);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvResource, nullptr);
        }
    }
    else
    {
        result = object_->CreateReservedResource1(
            pDesc,
            InitialState,
            pOptimizedClearValue,
            pProtectedSession,
            riid,
            ppvResource);
    }

    manager->DecrementCallScope();

    return result;
}

D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE ID3D12Device4_Wrapper::GetResourceAllocationInfo1(
    UINT visibleMask,
    UINT numResourceDescs,
    const D3D12_RESOURCE_DESC* pResourceDescs,
    D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1)
{
    D3D12_RESOURCE_ALLOCATION_INFO result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetResourceAllocationInfo1(
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
    }
    else
    {
        result = object_->GetResourceAllocationInfo1(
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12LifetimeOwner_Wrapper::ID3D12LifetimeOwner_Wrapper(REFIID riid, ID3D12LifetimeOwner* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12LifetimeOwner_Wrapper::LifetimeStateUpdated(
    D3D12_LIFETIME_STATE NewState)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->LifetimeStateUpdated(
            NewState);
    }
    else
    {
        object_->LifetimeStateUpdated(
            NewState);
    }

    manager->DecrementCallScope();
}

ID3D12SwapChainAssistant_Wrapper::ID3D12SwapChainAssistant_Wrapper(REFIID riid, ID3D12SwapChainAssistant* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

LUID STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::GetLUID()
{
    LUID result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetLUID();
    }
    else
    {
        result = object_->GetLUID();
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::GetSwapChainObject(
    REFIID riid,
    void** ppv)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetSwapChainObject(
            riid,
            ppv);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppv, nullptr);
        }
    }
    else
    {
        result = object_->GetSwapChainObject(
            riid,
            ppv);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::GetCurrentResourceAndCommandQueue(
    REFIID riidResource,
    void** ppvResource,
    REFIID riidQueue,
    void** ppvQueue)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetCurrentResourceAndCommandQueue(
            riidResource,
            ppvResource,
            riidQueue,
            ppvQueue);

        if (SUCCEEDED(result))
        {
            WrapObject(riidResource, ppvResource, nullptr);
            WrapObject(riidQueue, ppvQueue, nullptr);
        }
    }
    else
    {
        result = object_->GetCurrentResourceAndCommandQueue(
            riidResource,
            ppvResource,
            riidQueue,
            ppvQueue);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12SwapChainAssistant_Wrapper::InsertImplicitSync()
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->InsertImplicitSync();
    }
    else
    {
        result = object_->InsertImplicitSync();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12LifetimeTracker_Wrapper::ID3D12LifetimeTracker_Wrapper(REFIID riid, ID3D12LifetimeTracker* object, DxWrapperResources* resources) : ID3D12DeviceChild_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12LifetimeTracker_Wrapper::DestroyOwnedObject(
    ID3D12DeviceChild* pObject)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->DestroyOwnedObject(
            encode::GetWrappedObject<ID3D12DeviceChild_Wrapper, ID3D12DeviceChild>(pObject));
    }
    else
    {
        result = object_->DestroyOwnedObject(
            pObject);
    }

    manager->DecrementCallScope();

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
    void* result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetShaderIdentifier(
            pExportName);
    }
    else
    {
        result = object_->GetShaderIdentifier(
            pExportName);
    }

    manager->DecrementCallScope();

    return result;
}

UINT64 STDMETHODCALLTYPE ID3D12StateObjectProperties_Wrapper::GetShaderStackSize(
    LPCWSTR pExportName)
{
    UINT64 result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetShaderStackSize(
            pExportName);
    }
    else
    {
        result = object_->GetShaderStackSize(
            pExportName);
    }

    manager->DecrementCallScope();

    return result;
}

UINT64 STDMETHODCALLTYPE ID3D12StateObjectProperties_Wrapper::GetPipelineStackSize()
{
    UINT64 result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetPipelineStackSize();
    }
    else
    {
        result = object_->GetPipelineStackSize();
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE ID3D12StateObjectProperties_Wrapper::SetPipelineStackSize(
    UINT64 PipelineStackSizeInBytes)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetPipelineStackSize(
            PipelineStackSizeInBytes);
    }
    else
    {
        object_->SetPipelineStackSize(
            PipelineStackSizeInBytes);
    }

    manager->DecrementCallScope();
}

ID3D12Device5_Wrapper::ID3D12Device5_Wrapper(REFIID riid, ID3D12Device5* object, DxWrapperResources* resources) : ID3D12Device4_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::CreateLifetimeTracker(
    ID3D12LifetimeOwner* pOwner,
    REFIID riid,
    void** ppvTracker)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateLifetimeTracker(
            encode::GetWrappedObject<ID3D12LifetimeOwner_Wrapper, ID3D12LifetimeOwner>(pOwner),
            riid,
            ppvTracker);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppvTracker, nullptr);
        }
    }
    else
    {
        result = object_->CreateLifetimeTracker(
            pOwner,
            riid,
            ppvTracker);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE ID3D12Device5_Wrapper::RemoveDevice()
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->RemoveDevice();
    }
    else
    {
        object_->RemoveDevice();
    }

    manager->DecrementCallScope();
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::EnumerateMetaCommands(
    UINT* pNumMetaCommands,
    D3D12_META_COMMAND_DESC* pDescs)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumerateMetaCommands(
            pNumMetaCommands,
            pDescs);
    }
    else
    {
        result = object_->EnumerateMetaCommands(
            pNumMetaCommands,
            pDescs);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::EnumerateMetaCommandParameters(
    REFGUID CommandId,
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT* pTotalStructureSizeInBytes,
    UINT* pParameterCount,
    D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->EnumerateMetaCommandParameters(
            CommandId,
            Stage,
            pTotalStructureSizeInBytes,
            pParameterCount,
            pParameterDescs);
    }
    else
    {
        result = object_->EnumerateMetaCommandParameters(
            CommandId,
            Stage,
            pTotalStructureSizeInBytes,
            pParameterCount,
            pParameterDescs);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateMetaCommand(
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
    }
    else
    {
        result = object_->CreateMetaCommand(
            CommandId,
            NodeMask,
            pCreationParametersData,
            CreationParametersDataSizeInBytes,
            riid,
            ppMetaCommand);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device5_Wrapper::CreateStateObject(
    const D3D12_STATE_OBJECT_DESC* pDesc,
    REFIID riid,
    void** ppStateObject)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateStateObject(
            pDesc,
            riid,
            ppStateObject);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppStateObject, nullptr);
        }
    }
    else
    {
        result = object_->CreateStateObject(
            pDesc,
            riid,
            ppStateObject);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE ID3D12Device5_Wrapper::GetRaytracingAccelerationStructurePrebuildInfo(
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->GetRaytracingAccelerationStructurePrebuildInfo(
            pDesc,
            pInfo);
    }
    else
    {
        object_->GetRaytracingAccelerationStructurePrebuildInfo(
            pDesc,
            pInfo);
    }

    manager->DecrementCallScope();
}

D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS STDMETHODCALLTYPE ID3D12Device5_Wrapper::CheckDriverMatchingIdentifier(
    D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
    const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck)
{
    D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CheckDriverMatchingIdentifier(
            SerializedDataType,
            pIdentifierToCheck);
    }
    else
    {
        result = object_->CheckDriverMatchingIdentifier(
            SerializedDataType,
            pIdentifierToCheck);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12DeviceRemovedExtendedDataSettings_Wrapper::ID3D12DeviceRemovedExtendedDataSettings_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings_Wrapper::SetAutoBreadcrumbsEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetAutoBreadcrumbsEnablement(
            Enablement);
    }
    else
    {
        object_->SetAutoBreadcrumbsEnablement(
            Enablement);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings_Wrapper::SetPageFaultEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetPageFaultEnablement(
            Enablement);
    }
    else
    {
        object_->SetPageFaultEnablement(
            Enablement);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings_Wrapper::SetWatsonDumpEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetWatsonDumpEnablement(
            Enablement);
    }
    else
    {
        object_->SetWatsonDumpEnablement(
            Enablement);
    }

    manager->DecrementCallScope();
}

ID3D12DeviceRemovedExtendedDataSettings1_Wrapper::ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings1* object, DxWrapperResources* resources) : ID3D12DeviceRemovedExtendedDataSettings_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedDataSettings1_Wrapper::SetBreadcrumbContextEnablement(
    D3D12_DRED_ENABLEMENT Enablement)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetBreadcrumbContextEnablement(
            Enablement);
    }
    else
    {
        object_->SetBreadcrumbContextEnablement(
            Enablement);
    }

    manager->DecrementCallScope();
}

ID3D12DeviceRemovedExtendedData_Wrapper::ID3D12DeviceRemovedExtendedData_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedData* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData_Wrapper::GetAutoBreadcrumbsOutput(
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetAutoBreadcrumbsOutput(
            pOutput);
    }
    else
    {
        result = object_->GetAutoBreadcrumbsOutput(
            pOutput);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData_Wrapper::GetPageFaultAllocationOutput(
    D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetPageFaultAllocationOutput(
            pOutput);
    }
    else
    {
        result = object_->GetPageFaultAllocationOutput(
            pOutput);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12DeviceRemovedExtendedData1_Wrapper::ID3D12DeviceRemovedExtendedData1_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedData1* object, DxWrapperResources* resources) : ID3D12DeviceRemovedExtendedData_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData1_Wrapper::GetAutoBreadcrumbsOutput1(
    D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetAutoBreadcrumbsOutput1(
            pOutput);
    }
    else
    {
        result = object_->GetAutoBreadcrumbsOutput1(
            pOutput);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12DeviceRemovedExtendedData1_Wrapper::GetPageFaultAllocationOutput1(
    D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetPageFaultAllocationOutput1(
            pOutput);
    }
    else
    {
        result = object_->GetPageFaultAllocationOutput1(
            pOutput);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->SetBackgroundProcessingMode(
            Mode,
            MeasurementsAction,
            hEventToSignalUponCompletion,
            pbFurtherMeasurementsDesired);
    }
    else
    {
        result = object_->SetBackgroundProcessingMode(
            Mode,
            MeasurementsAction,
            hEventToSignalUponCompletion,
            pbFurtherMeasurementsDesired);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12ProtectedResourceSession1_Wrapper::ID3D12ProtectedResourceSession1_Wrapper(REFIID riid, ID3D12ProtectedResourceSession1* object, DxWrapperResources* resources) : ID3D12ProtectedResourceSession_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_PROTECTED_RESOURCE_SESSION_DESC1 STDMETHODCALLTYPE ID3D12ProtectedResourceSession1_Wrapper::GetDesc1()
{
    D3D12_PROTECTED_RESOURCE_SESSION_DESC1 result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc1();
    }
    else
    {
        result = object_->GetDesc1();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->AddToStateObject(
            pAddition,
            encode::GetWrappedObject<ID3D12StateObject_Wrapper, ID3D12StateObject>(pStateObjectToGrowFrom),
            riid,
            ppNewStateObject);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppNewStateObject, nullptr);
        }
    }
    else
    {
        result = object_->AddToStateObject(
            pAddition,
            pStateObjectToGrowFrom,
            riid,
            ppNewStateObject);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3D12Device7_Wrapper::CreateProtectedResourceSession1(
    const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
    REFIID riid,
    void** ppSession)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateProtectedResourceSession1(
            pDesc,
            riid,
            ppSession);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppSession, nullptr);
        }
    }
    else
    {
        result = object_->CreateProtectedResourceSession1(
            pDesc,
            riid,
            ppSession);
    }

    manager->DecrementCallScope();

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
    D3D12_RESOURCE_ALLOCATION_INFO result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetResourceAllocationInfo2(
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
    }
    else
    {
        result = object_->GetResourceAllocationInfo2(
            visibleMask,
            numResourceDescs,
            pResourceDescs,
            pResourceAllocationInfo1);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreateCommittedResource2(
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            encode::GetWrappedObject<ID3D12ProtectedResourceSession_Wrapper, ID3D12ProtectedResourceSession>(pProtectedSession),
            riidResource,
            ppvResource);

        if (SUCCEEDED(result))
        {
            WrapObject(riidResource, ppvResource, nullptr);
        }
    }
    else
    {
        result = object_->CreateCommittedResource2(
            pHeapProperties,
            HeapFlags,
            pDesc,
            InitialResourceState,
            pOptimizedClearValue,
            pProtectedSession,
            riidResource,
            ppvResource);
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->CreatePlacedResource1(
            encode::GetWrappedObject<ID3D12Heap_Wrapper, ID3D12Heap>(pHeap),
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
    }
    else
    {
        result = object_->CreatePlacedResource1(
            pHeap,
            HeapOffset,
            pDesc,
            InitialState,
            pOptimizedClearValue,
            riid,
            ppvResource);
    }

    manager->DecrementCallScope();

    return result;
}

void STDMETHODCALLTYPE ID3D12Device8_Wrapper::CreateSamplerFeedbackUnorderedAccessView(
    ID3D12Resource* pTargetedResource,
    ID3D12Resource* pFeedbackResource,
    D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CreateSamplerFeedbackUnorderedAccessView(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pTargetedResource),
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(pFeedbackResource),
            DestDescriptor);
    }
    else
    {
        object_->CreateSamplerFeedbackUnorderedAccessView(
            pTargetedResource,
            pFeedbackResource,
            DestDescriptor);
    }

    manager->DecrementCallScope();
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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
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
    else
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

    manager->DecrementCallScope();
}

ID3D12Resource1_Wrapper::ID3D12Resource1_Wrapper(REFIID riid, ID3D12Resource1* object, DxWrapperResources* resources) : ID3D12Resource_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Resource1_Wrapper::GetProtectedResourceSession(
    REFIID riid,
    void** ppProtectedSession)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetProtectedResourceSession(
            riid,
            ppProtectedSession);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppProtectedSession, nullptr);
        }
    }
    else
    {
        result = object_->GetProtectedResourceSession(
            riid,
            ppProtectedSession);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12Resource2_Wrapper::ID3D12Resource2_Wrapper(REFIID riid, ID3D12Resource2* object, DxWrapperResources* resources) : ID3D12Resource1_Wrapper(riid, object, resources), object_(object)
{
}

D3D12_RESOURCE_DESC1 STDMETHODCALLTYPE ID3D12Resource2_Wrapper::GetDesc1()
{
    D3D12_RESOURCE_DESC1 result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetDesc1();
    }
    else
    {
        result = object_->GetDesc1();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12Heap1_Wrapper::ID3D12Heap1_Wrapper(REFIID riid, ID3D12Heap1* object, DxWrapperResources* resources) : ID3D12Heap_Wrapper(riid, object, resources), object_(object)
{
}

HRESULT STDMETHODCALLTYPE ID3D12Heap1_Wrapper::GetProtectedResourceSession(
    REFIID riid,
    void** ppProtectedSession)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetProtectedResourceSession(
            riid,
            ppProtectedSession);

        if (SUCCEEDED(result))
        {
            WrapObject(riid, ppProtectedSession, nullptr);
        }
    }
    else
    {
        result = object_->GetProtectedResourceSession(
            riid,
            ppProtectedSession);
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12GraphicsCommandList3_Wrapper::ID3D12GraphicsCommandList3_Wrapper(REFIID riid, ID3D12GraphicsCommandList3* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList2_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList3_Wrapper::SetProtectedResourceSession(
    ID3D12ProtectedResourceSession* pProtectedResourceSession)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetProtectedResourceSession(
            encode::GetWrappedObject<ID3D12ProtectedResourceSession_Wrapper, ID3D12ProtectedResourceSession>(pProtectedResourceSession));
    }
    else
    {
        object_->SetProtectedResourceSession(
            pProtectedResourceSession);
    }

    manager->DecrementCallScope();
}

ID3D12MetaCommand_Wrapper::ID3D12MetaCommand_Wrapper(REFIID riid, ID3D12MetaCommand* object, DxWrapperResources* resources) : ID3D12Pageable_Wrapper(riid, object, resources), object_(object)
{
}

UINT64 STDMETHODCALLTYPE ID3D12MetaCommand_Wrapper::GetRequiredParameterResourceSize(
    D3D12_META_COMMAND_PARAMETER_STAGE Stage,
    UINT ParameterIndex)
{
    UINT64 result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetRequiredParameterResourceSize(
            Stage,
            ParameterIndex);
    }
    else
    {
        result = object_->GetRequiredParameterResourceSize(
            Stage,
            ParameterIndex);
    }

    manager->DecrementCallScope();

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
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->BeginRenderPass(
            NumRenderTargets,
            pRenderTargets,
            pDepthStencil,
            Flags);
    }
    else
    {
        object_->BeginRenderPass(
            NumRenderTargets,
            pRenderTargets,
            pDepthStencil,
            Flags);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::EndRenderPass()
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->EndRenderPass();
    }
    else
    {
        object_->EndRenderPass();
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::InitializeMetaCommand(
    ID3D12MetaCommand* pMetaCommand,
    const void* pInitializationParametersData,
    SIZE_T InitializationParametersDataSizeInBytes)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->InitializeMetaCommand(
            encode::GetWrappedObject<ID3D12MetaCommand_Wrapper, ID3D12MetaCommand>(pMetaCommand),
            pInitializationParametersData,
            InitializationParametersDataSizeInBytes);
    }
    else
    {
        object_->InitializeMetaCommand(
            pMetaCommand,
            pInitializationParametersData,
            InitializationParametersDataSizeInBytes);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::ExecuteMetaCommand(
    ID3D12MetaCommand* pMetaCommand,
    const void* pExecutionParametersData,
    SIZE_T ExecutionParametersDataSizeInBytes)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->ExecuteMetaCommand(
            encode::GetWrappedObject<ID3D12MetaCommand_Wrapper, ID3D12MetaCommand>(pMetaCommand),
            pExecutionParametersData,
            ExecutionParametersDataSizeInBytes);
    }
    else
    {
        object_->ExecuteMetaCommand(
            pMetaCommand,
            pExecutionParametersData,
            ExecutionParametersDataSizeInBytes);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::BuildRaytracingAccelerationStructure(
    const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
    UINT NumPostbuildInfoDescs,
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->BuildRaytracingAccelerationStructure(
            pDesc,
            NumPostbuildInfoDescs,
            pPostbuildInfoDescs);
    }
    else
    {
        object_->BuildRaytracingAccelerationStructure(
            pDesc,
            NumPostbuildInfoDescs,
            pPostbuildInfoDescs);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::EmitRaytracingAccelerationStructurePostbuildInfo(
    const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
    UINT NumSourceAccelerationStructures,
    const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->EmitRaytracingAccelerationStructurePostbuildInfo(
            pDesc,
            NumSourceAccelerationStructures,
            pSourceAccelerationStructureData);
    }
    else
    {
        object_->EmitRaytracingAccelerationStructurePostbuildInfo(
            pDesc,
            NumSourceAccelerationStructures,
            pSourceAccelerationStructureData);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::CopyRaytracingAccelerationStructure(
    D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
    D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
    D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->CopyRaytracingAccelerationStructure(
            DestAccelerationStructureData,
            SourceAccelerationStructureData,
            Mode);
    }
    else
    {
        object_->CopyRaytracingAccelerationStructure(
            DestAccelerationStructureData,
            SourceAccelerationStructureData,
            Mode);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::SetPipelineState1(
    ID3D12StateObject* pStateObject)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->SetPipelineState1(
            encode::GetWrappedObject<ID3D12StateObject_Wrapper, ID3D12StateObject>(pStateObject));
    }
    else
    {
        object_->SetPipelineState1(
            pStateObject);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList4_Wrapper::DispatchRays(
    const D3D12_DISPATCH_RAYS_DESC* pDesc)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->DispatchRays(
            pDesc);
    }
    else
    {
        object_->DispatchRays(
            pDesc);
    }

    manager->DecrementCallScope();
}

ID3D12Tools_Wrapper::ID3D12Tools_Wrapper(REFIID riid, ID3D12Tools* object, DxWrapperResources* resources) : IUnknown_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12Tools_Wrapper::EnableShaderInstrumentation(
    BOOL bEnable)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->EnableShaderInstrumentation(
            bEnable);
    }
    else
    {
        object_->EnableShaderInstrumentation(
            bEnable);
    }

    manager->DecrementCallScope();
}

BOOL STDMETHODCALLTYPE ID3D12Tools_Wrapper::ShaderInstrumentationEnabled()
{
    BOOL result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->ShaderInstrumentationEnabled();
    }
    else
    {
        result = object_->ShaderInstrumentationEnabled();
    }

    manager->DecrementCallScope();

    return result;
}

ID3D12GraphicsCommandList5_Wrapper::ID3D12GraphicsCommandList5_Wrapper(REFIID riid, ID3D12GraphicsCommandList5* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList4_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList5_Wrapper::RSSetShadingRate(
    D3D12_SHADING_RATE baseShadingRate,
    const D3D12_SHADING_RATE_COMBINER* combiners)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->RSSetShadingRate(
            baseShadingRate,
            combiners);
    }
    else
    {
        object_->RSSetShadingRate(
            baseShadingRate,
            combiners);
    }

    manager->DecrementCallScope();
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList5_Wrapper::RSSetShadingRateImage(
    ID3D12Resource* shadingRateImage)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->RSSetShadingRateImage(
            encode::GetWrappedObject<ID3D12Resource_Wrapper, ID3D12Resource>(shadingRateImage));
    }
    else
    {
        object_->RSSetShadingRateImage(
            shadingRateImage);
    }

    manager->DecrementCallScope();
}

ID3D12GraphicsCommandList6_Wrapper::ID3D12GraphicsCommandList6_Wrapper(REFIID riid, ID3D12GraphicsCommandList6* object, DxWrapperResources* resources) : ID3D12GraphicsCommandList5_Wrapper(riid, object, resources), object_(object)
{
}

void STDMETHODCALLTYPE ID3D12GraphicsCommandList6_Wrapper::DispatchMesh(
    UINT ThreadGroupCountX,
    UINT ThreadGroupCountY,
    UINT ThreadGroupCountZ)
{
    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        object_->DispatchMesh(
            ThreadGroupCountX,
            ThreadGroupCountY,
            ThreadGroupCountZ);
    }
    else
    {
        object_->DispatchMesh(
            ThreadGroupCountX,
            ThreadGroupCountY,
            ThreadGroupCountZ);
    }

    manager->DecrementCallScope();
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
    LPVOID result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetBufferPointer();
    }
    else
    {
        result = object_->GetBufferPointer();
    }

    manager->DecrementCallScope();

    return result;
}

SIZE_T STDMETHODCALLTYPE ID3D10Blob_Wrapper::GetBufferSize()
{
    SIZE_T result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->GetBufferSize();
    }
    else
    {
        result = object_->GetBufferSize();
    }

    manager->DecrementCallScope();

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
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->RegisterDestructionCallback(
            callbackFn,
            pData,
            pCallbackID);
    }
    else
    {
        result = object_->RegisterDestructionCallback(
            callbackFn,
            pData,
            pCallbackID);
    }

    manager->DecrementCallScope();

    return result;
}

HRESULT STDMETHODCALLTYPE ID3DDestructionNotifier_Wrapper::UnregisterDestructionCallback(
    UINT callbackID)
{
    HRESULT result{};

    auto manager = TraceManager::Get();
    auto call_scope = manager->IncrementCallScope();

    if (call_scope == 1)
    {
        result = object_->UnregisterDestructionCallback(
            callbackID);
    }
    else
    {
        result = object_->UnregisterDestructionCallback(
            callbackID);
    }

    manager->DecrementCallScope();

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
