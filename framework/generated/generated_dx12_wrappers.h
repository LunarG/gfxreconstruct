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
** This file is generated from dx12_wrapper_header_generator.py.
**
*/

#ifndef  GFXRECON_GENERATED_DX12_WRAPPERS_H
#define  GFXRECON_GENERATED_DX12_WRAPPERS_H

#include "encode/iunknown_wrapper.h"
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
    void** ppFactory);

HRESULT WINAPI CreateDXGIFactory1(
    REFIID riid,
    void** ppFactory);

class IDXGIObject_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIObject_Wrapper(REFIID riid, IDXGIObject* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIObject_Wrapper*>(u); });

    void GetWrappedObject(IDXGIObject** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID Name,
        UINT DataSize,
        const void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        REFGUID Name,
        const IUnknown* pUnknown);

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        REFGUID Name,
        UINT* pDataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE GetParent(
        REFIID riid,
        void** ppParent);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIObject* object_;
};

class IDXGIDeviceSubObject_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIDeviceSubObject_Wrapper(REFIID riid, IDXGIDeviceSubObject* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDeviceSubObject_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDeviceSubObject** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDevice(
        REFIID riid,
        void** ppDevice);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDeviceSubObject* object_;
};

class IDXGIResource_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGIResource_Wrapper(REFIID riid, IDXGIResource* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIResource_Wrapper*>(u); });

    void GetWrappedObject(IDXGIResource** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetSharedHandle(
        HANDLE* pSharedHandle);

    virtual HRESULT STDMETHODCALLTYPE GetUsage(
        DXGI_USAGE* pUsage);

    virtual HRESULT STDMETHODCALLTYPE SetEvictionPriority(
        UINT EvictionPriority);

    virtual HRESULT STDMETHODCALLTYPE GetEvictionPriority(
        UINT* pEvictionPriority);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIResource* object_;
};

class IDXGIKeyedMutex_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGIKeyedMutex_Wrapper(REFIID riid, IDXGIKeyedMutex* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIKeyedMutex_Wrapper*>(u); });

    void GetWrappedObject(IDXGIKeyedMutex** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE AcquireSync(
        UINT64 Key,
        DWORD dwMilliseconds);

    virtual HRESULT STDMETHODCALLTYPE ReleaseSync(
        UINT64 Key);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIKeyedMutex* object_;
};

class IDXGISurface_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGISurface_Wrapper(REFIID riid, IDXGISurface* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISurface_Wrapper*>(u); });

    void GetWrappedObject(IDXGISurface** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_SURFACE_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE Map(
        DXGI_MAPPED_RECT* pLockedRect,
        UINT MapFlags);

    virtual HRESULT STDMETHODCALLTYPE Unmap();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISurface* object_;
};

class IDXGISurface1_Wrapper : public IDXGISurface_Wrapper
{
  public:
    IDXGISurface1_Wrapper(REFIID riid, IDXGISurface1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISurface1_Wrapper*>(u); });

    void GetWrappedObject(IDXGISurface1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDC(
        BOOL Discard,
        HDC* phdc);

    virtual HRESULT STDMETHODCALLTYPE ReleaseDC(
        RECT* pDirtyRect);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISurface1* object_;
};

class IDXGIAdapter_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIAdapter_Wrapper(REFIID riid, IDXGIAdapter* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter_Wrapper*>(u); });

    void GetWrappedObject(IDXGIAdapter** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE EnumOutputs(
        UINT Output,
        IDXGIOutput** ppOutput);

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_ADAPTER_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE CheckInterfaceSupport(
        REFGUID InterfaceName,
        LARGE_INTEGER* pUMDVersion);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIAdapter* object_;
};

class IDXGIOutput_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIOutput_Wrapper(REFIID riid, IDXGIOutput* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutput** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_OUTPUT_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE GetDisplayModeList(
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        UINT* pNumModes,
        DXGI_MODE_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE FindClosestMatchingMode(
        const DXGI_MODE_DESC* pModeToMatch,
        DXGI_MODE_DESC* pClosestMatch,
        IUnknown* pConcernedDevice);

    virtual HRESULT STDMETHODCALLTYPE WaitForVBlank();

    virtual HRESULT STDMETHODCALLTYPE TakeOwnership(
        IUnknown* pDevice,
        BOOL Exclusive);

    virtual void STDMETHODCALLTYPE ReleaseOwnership();

    virtual HRESULT STDMETHODCALLTYPE GetGammaControlCapabilities(
        DXGI_GAMMA_CONTROL_CAPABILITIES* pGammaCaps);

    virtual HRESULT STDMETHODCALLTYPE SetGammaControl(
        const DXGI_GAMMA_CONTROL* pArray);

    virtual HRESULT STDMETHODCALLTYPE GetGammaControl(
        DXGI_GAMMA_CONTROL* pArray);

    virtual HRESULT STDMETHODCALLTYPE SetDisplaySurface(
        IDXGISurface* pScanoutSurface);

    virtual HRESULT STDMETHODCALLTYPE GetDisplaySurfaceData(
        IDXGISurface* pDestination);

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
        DXGI_FRAME_STATISTICS* pStats);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutput* object_;
};

class IDXGISwapChain_Wrapper : public IDXGIDeviceSubObject_Wrapper
{
  public:
    IDXGISwapChain_Wrapper(REFIID riid, IDXGISwapChain* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain_Wrapper*>(u); });

    void GetWrappedObject(IDXGISwapChain** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE Present(
        UINT SyncInterval,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE GetBuffer(
        UINT Buffer,
        REFIID riid,
        void** ppSurface);

    virtual HRESULT STDMETHODCALLTYPE SetFullscreenState(
        BOOL Fullscreen,
        IDXGIOutput* pTarget);

    virtual HRESULT STDMETHODCALLTYPE GetFullscreenState(
        BOOL* pFullscreen,
        IDXGIOutput** ppTarget);

    virtual HRESULT STDMETHODCALLTYPE GetDesc(
        DXGI_SWAP_CHAIN_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE ResizeBuffers(
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT NewFormat,
        UINT SwapChainFlags);

    virtual HRESULT STDMETHODCALLTYPE ResizeTarget(
        const DXGI_MODE_DESC* pNewTargetParameters);

    virtual HRESULT STDMETHODCALLTYPE GetContainingOutput(
        IDXGIOutput** ppOutput);

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatistics(
        DXGI_FRAME_STATISTICS* pStats);

    virtual HRESULT STDMETHODCALLTYPE GetLastPresentCount(
        UINT* pLastPresentCount);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISwapChain* object_;
};

class IDXGIFactory_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIFactory_Wrapper(REFIID riid, IDXGIFactory* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE EnumAdapters(
        UINT Adapter,
        IDXGIAdapter** ppAdapter);

    virtual HRESULT STDMETHODCALLTYPE MakeWindowAssociation(
        HWND WindowHandle,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE GetWindowAssociation(
        HWND* pWindowHandle);

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChain(
        IUnknown* pDevice,
        DXGI_SWAP_CHAIN_DESC* pDesc,
        IDXGISwapChain** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE CreateSoftwareAdapter(
        HMODULE Module,
        IDXGIAdapter** ppAdapter);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory* object_;
};

class IDXGIDevice_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIDevice_Wrapper(REFIID riid, IDXGIDevice* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDevice** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetAdapter(
        IDXGIAdapter** pAdapter);

    virtual HRESULT STDMETHODCALLTYPE CreateSurface(
        const DXGI_SURFACE_DESC* pDesc,
        UINT NumSurfaces,
        DXGI_USAGE Usage,
        const DXGI_SHARED_RESOURCE* pSharedResource,
        IDXGISurface** ppSurface);

    virtual HRESULT STDMETHODCALLTYPE QueryResourceResidency(
        IUnknown* const* ppResources,
        DXGI_RESIDENCY* pResidencyStatus,
        UINT NumResources);

    virtual HRESULT STDMETHODCALLTYPE SetGPUThreadPriority(
        INT Priority);

    virtual HRESULT STDMETHODCALLTYPE GetGPUThreadPriority(
        INT* pPriority);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDevice* object_;
};

class IDXGIFactory1_Wrapper : public IDXGIFactory_Wrapper
{
  public:
    IDXGIFactory1_Wrapper(REFIID riid, IDXGIFactory1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory1_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE EnumAdapters1(
        UINT Adapter,
        IDXGIAdapter1** ppAdapter);

    virtual BOOL STDMETHODCALLTYPE IsCurrent();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory1* object_;
};

class IDXGIAdapter1_Wrapper : public IDXGIAdapter_Wrapper
{
  public:
    IDXGIAdapter1_Wrapper(REFIID riid, IDXGIAdapter1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter1_Wrapper*>(u); });

    void GetWrappedObject(IDXGIAdapter1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDesc1(
        DXGI_ADAPTER_DESC1* pDesc);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIAdapter1* object_;
};

class IDXGIDevice1_Wrapper : public IDXGIDevice_Wrapper
{
  public:
    IDXGIDevice1_Wrapper(REFIID riid, IDXGIDevice1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice1_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDevice1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(
        UINT MaxLatency);

    virtual HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(
        UINT* pMaxLatency);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDevice1* object_;
};


/*
** This part is generated from dxgi1_2.h in Windows SDK: 10.0.19041.0
**
*/

class IDXGIDisplayControl_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIDisplayControl_Wrapper(REFIID riid, IDXGIDisplayControl* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDisplayControl_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDisplayControl** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual BOOL STDMETHODCALLTYPE IsStereoEnabled();

    virtual void STDMETHODCALLTYPE SetStereoEnabled(
        BOOL enabled);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDisplayControl* object_;
};

class IDXGIOutputDuplication_Wrapper : public IDXGIObject_Wrapper
{
  public:
    IDXGIOutputDuplication_Wrapper(REFIID riid, IDXGIOutputDuplication* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutputDuplication_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutputDuplication** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE GetDesc(
        DXGI_OUTDUPL_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE AcquireNextFrame(
        UINT TimeoutInMilliseconds,
        DXGI_OUTDUPL_FRAME_INFO* pFrameInfo,
        IDXGIResource** ppDesktopResource);

    virtual HRESULT STDMETHODCALLTYPE GetFrameDirtyRects(
        UINT DirtyRectsBufferSize,
        RECT* pDirtyRectsBuffer,
        UINT* pDirtyRectsBufferSizeRequired);

    virtual HRESULT STDMETHODCALLTYPE GetFrameMoveRects(
        UINT MoveRectsBufferSize,
        DXGI_OUTDUPL_MOVE_RECT* pMoveRectBuffer,
        UINT* pMoveRectsBufferSizeRequired);

    virtual HRESULT STDMETHODCALLTYPE GetFramePointerShape(
        UINT PointerShapeBufferSize,
        void* pPointerShapeBuffer,
        UINT* pPointerShapeBufferSizeRequired,
        DXGI_OUTDUPL_POINTER_SHAPE_INFO* pPointerShapeInfo);

    virtual HRESULT STDMETHODCALLTYPE MapDesktopSurface(
        DXGI_MAPPED_RECT* pLockedRect);

    virtual HRESULT STDMETHODCALLTYPE UnMapDesktopSurface();

    virtual HRESULT STDMETHODCALLTYPE ReleaseFrame();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutputDuplication* object_;
};

class IDXGISurface2_Wrapper : public IDXGISurface1_Wrapper
{
  public:
    IDXGISurface2_Wrapper(REFIID riid, IDXGISurface2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISurface2_Wrapper*>(u); });

    void GetWrappedObject(IDXGISurface2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetResource(
        REFIID riid,
        void** ppParentResource,
        UINT* pSubresourceIndex);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISurface2* object_;
};

class IDXGIResource1_Wrapper : public IDXGIResource_Wrapper
{
  public:
    IDXGIResource1_Wrapper(REFIID riid, IDXGIResource1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIResource1_Wrapper*>(u); });

    void GetWrappedObject(IDXGIResource1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CreateSubresourceSurface(
        UINT index,
        IDXGISurface2** ppSurface);

    virtual HRESULT STDMETHODCALLTYPE CreateSharedHandle(
        const SECURITY_ATTRIBUTES* pAttributes,
        DWORD dwAccess,
        LPCWSTR lpName,
        HANDLE* pHandle);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIResource1* object_;
};

class IDXGIDevice2_Wrapper : public IDXGIDevice1_Wrapper
{
  public:
    IDXGIDevice2_Wrapper(REFIID riid, IDXGIDevice2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice2_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDevice2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE OfferResources(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority);

    virtual HRESULT STDMETHODCALLTYPE ReclaimResources(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        BOOL* pDiscarded);

    virtual HRESULT STDMETHODCALLTYPE EnqueueSetEvent(
        HANDLE hEvent);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDevice2* object_;
};

class IDXGISwapChain1_Wrapper : public IDXGISwapChain_Wrapper
{
  public:
    IDXGISwapChain1_Wrapper(REFIID riid, IDXGISwapChain1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain1_Wrapper*>(u); });

    void GetWrappedObject(IDXGISwapChain1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDesc1(
        DXGI_SWAP_CHAIN_DESC1* pDesc);

    virtual HRESULT STDMETHODCALLTYPE GetFullscreenDesc(
        DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pDesc);

    virtual HRESULT STDMETHODCALLTYPE GetHwnd(
        HWND* pHwnd);

    virtual HRESULT STDMETHODCALLTYPE GetCoreWindow(
        REFIID refiid,
        void** ppUnk);

    virtual HRESULT STDMETHODCALLTYPE Present1(
        UINT SyncInterval,
        UINT PresentFlags,
        const DXGI_PRESENT_PARAMETERS* pPresentParameters);

    virtual BOOL STDMETHODCALLTYPE IsTemporaryMonoSupported();

    virtual HRESULT STDMETHODCALLTYPE GetRestrictToOutput(
        IDXGIOutput** ppRestrictToOutput);

    virtual HRESULT STDMETHODCALLTYPE SetBackgroundColor(
        const DXGI_RGBA* pColor);

    virtual HRESULT STDMETHODCALLTYPE GetBackgroundColor(
        DXGI_RGBA* pColor);

    virtual HRESULT STDMETHODCALLTYPE SetRotation(
        DXGI_MODE_ROTATION Rotation);

    virtual HRESULT STDMETHODCALLTYPE GetRotation(
        DXGI_MODE_ROTATION* pRotation);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISwapChain1* object_;
};

class IDXGIFactory2_Wrapper : public IDXGIFactory1_Wrapper
{
  public:
    IDXGIFactory2_Wrapper(REFIID riid, IDXGIFactory2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory2_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual BOOL STDMETHODCALLTYPE IsWindowedStereoEnabled();

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForHwnd(
        IUnknown* pDevice,
        HWND hWnd,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        const DXGI_SWAP_CHAIN_FULLSCREEN_DESC* pFullscreenDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCoreWindow(
        IUnknown* pDevice,
        IUnknown* pWindow,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE GetSharedResourceAdapterLuid(
        HANDLE hResource,
        LUID* pLuid);

    virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusWindow(
        HWND WindowHandle,
        UINT wMsg,
        DWORD* pdwCookie);

    virtual HRESULT STDMETHODCALLTYPE RegisterStereoStatusEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterStereoStatus(
        DWORD dwCookie);

    virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusWindow(
        HWND WindowHandle,
        UINT wMsg,
        DWORD* pdwCookie);

    virtual HRESULT STDMETHODCALLTYPE RegisterOcclusionStatusEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterOcclusionStatus(
        DWORD dwCookie);

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForComposition(
        IUnknown* pDevice,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory2* object_;
};

class IDXGIAdapter2_Wrapper : public IDXGIAdapter1_Wrapper
{
  public:
    IDXGIAdapter2_Wrapper(REFIID riid, IDXGIAdapter2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter2_Wrapper*>(u); });

    void GetWrappedObject(IDXGIAdapter2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDesc2(
        DXGI_ADAPTER_DESC2* pDesc);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIAdapter2* object_;
};

class IDXGIOutput1_Wrapper : public IDXGIOutput_Wrapper
{
  public:
    IDXGIOutput1_Wrapper(REFIID riid, IDXGIOutput1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput1_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutput1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDisplayModeList1(
        DXGI_FORMAT EnumFormat,
        UINT Flags,
        UINT* pNumModes,
        DXGI_MODE_DESC1* pDesc);

    virtual HRESULT STDMETHODCALLTYPE FindClosestMatchingMode1(
        const DXGI_MODE_DESC1* pModeToMatch,
        DXGI_MODE_DESC1* pClosestMatch,
        IUnknown* pConcernedDevice);

    virtual HRESULT STDMETHODCALLTYPE GetDisplaySurfaceData1(
        IDXGIResource* pDestination);

    virtual HRESULT STDMETHODCALLTYPE DuplicateOutput(
        IUnknown* pDevice,
        IDXGIOutputDuplication** ppOutputDuplication);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutput1* object_;
};


/*
** This part is generated from dxgi1_3.h in Windows SDK: 10.0.19041.0
**
*/

HRESULT WINAPI CreateDXGIFactory2(
    UINT Flags,
    REFIID riid,
    void** ppFactory);

HRESULT WINAPI DXGIGetDebugInterface1(
    UINT Flags,
    REFIID riid,
    void** pDebug);

class IDXGIDevice3_Wrapper : public IDXGIDevice2_Wrapper
{
  public:
    IDXGIDevice3_Wrapper(REFIID riid, IDXGIDevice3* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice3_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDevice3** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE Trim();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDevice3* object_;
};

class IDXGISwapChain2_Wrapper : public IDXGISwapChain1_Wrapper
{
  public:
    IDXGISwapChain2_Wrapper(REFIID riid, IDXGISwapChain2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain2_Wrapper*>(u); });

    void GetWrappedObject(IDXGISwapChain2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE SetSourceSize(
        UINT Width,
        UINT Height);

    virtual HRESULT STDMETHODCALLTYPE GetSourceSize(
        UINT* pWidth,
        UINT* pHeight);

    virtual HRESULT STDMETHODCALLTYPE SetMaximumFrameLatency(
        UINT MaxLatency);

    virtual HRESULT STDMETHODCALLTYPE GetMaximumFrameLatency(
        UINT* pMaxLatency);

    virtual HANDLE STDMETHODCALLTYPE GetFrameLatencyWaitableObject();

    virtual HRESULT STDMETHODCALLTYPE SetMatrixTransform(
        const DXGI_MATRIX_3X2_F* pMatrix);

    virtual HRESULT STDMETHODCALLTYPE GetMatrixTransform(
        DXGI_MATRIX_3X2_F* pMatrix);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISwapChain2* object_;
};

class IDXGIOutput2_Wrapper : public IDXGIOutput1_Wrapper
{
  public:
    IDXGIOutput2_Wrapper(REFIID riid, IDXGIOutput2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput2_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutput2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual BOOL STDMETHODCALLTYPE SupportsOverlays();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutput2* object_;
};

class IDXGIFactory3_Wrapper : public IDXGIFactory2_Wrapper
{
  public:
    IDXGIFactory3_Wrapper(REFIID riid, IDXGIFactory3* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory3_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory3** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual UINT STDMETHODCALLTYPE GetCreationFlags();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory3* object_;
};

class IDXGIDecodeSwapChain_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIDecodeSwapChain_Wrapper(REFIID riid, IDXGIDecodeSwapChain* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDecodeSwapChain_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDecodeSwapChain** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE PresentBuffer(
        UINT BufferToPresent,
        UINT SyncInterval,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE SetSourceRect(
        const RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE SetTargetRect(
        const RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE SetDestSize(
        UINT Width,
        UINT Height);

    virtual HRESULT STDMETHODCALLTYPE GetSourceRect(
        RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE GetTargetRect(
        RECT* pRect);

    virtual HRESULT STDMETHODCALLTYPE GetDestSize(
        UINT* pWidth,
        UINT* pHeight);

    virtual HRESULT STDMETHODCALLTYPE SetColorSpace(
        DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS ColorSpace);

    virtual DXGI_MULTIPLANE_OVERLAY_YCbCr_FLAGS STDMETHODCALLTYPE GetColorSpace();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDecodeSwapChain* object_;
};

class IDXGIFactoryMedia_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGIFactoryMedia_Wrapper(REFIID riid, IDXGIFactoryMedia* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactoryMedia_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactoryMedia** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CreateSwapChainForCompositionSurfaceHandle(
        IUnknown* pDevice,
        HANDLE hSurface,
        const DXGI_SWAP_CHAIN_DESC1* pDesc,
        IDXGIOutput* pRestrictToOutput,
        IDXGISwapChain1** ppSwapChain);

    virtual HRESULT STDMETHODCALLTYPE CreateDecodeSwapChainForCompositionSurfaceHandle(
        IUnknown* pDevice,
        HANDLE hSurface,
        DXGI_DECODE_SWAP_CHAIN_DESC* pDesc,
        IDXGIResource* pYuvDecodeBuffers,
        IDXGIOutput* pRestrictToOutput,
        IDXGIDecodeSwapChain** ppSwapChain);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactoryMedia* object_;
};

class IDXGISwapChainMedia_Wrapper : public IUnknown_Wrapper
{
  public:
    IDXGISwapChainMedia_Wrapper(REFIID riid, IDXGISwapChainMedia* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChainMedia_Wrapper*>(u); });

    void GetWrappedObject(IDXGISwapChainMedia** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetFrameStatisticsMedia(
        DXGI_FRAME_STATISTICS_MEDIA* pStats);

    virtual HRESULT STDMETHODCALLTYPE SetPresentDuration(
        UINT Duration);

    virtual HRESULT STDMETHODCALLTYPE CheckPresentDurationSupport(
        UINT DesiredPresentDuration,
        UINT* pClosestSmallerPresentDuration,
        UINT* pClosestLargerPresentDuration);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISwapChainMedia* object_;
};

class IDXGIOutput3_Wrapper : public IDXGIOutput2_Wrapper
{
  public:
    IDXGIOutput3_Wrapper(REFIID riid, IDXGIOutput3* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput3_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutput3** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CheckOverlaySupport(
        DXGI_FORMAT EnumFormat,
        IUnknown* pConcernedDevice,
        UINT* pFlags);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutput3* object_;
};


/*
** This part is generated from dxgi1_4.h in Windows SDK: 10.0.19041.0
**
*/

class IDXGISwapChain3_Wrapper : public IDXGISwapChain2_Wrapper
{
  public:
    IDXGISwapChain3_Wrapper(REFIID riid, IDXGISwapChain3* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain3_Wrapper*>(u); });

    void GetWrappedObject(IDXGISwapChain3** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual UINT STDMETHODCALLTYPE GetCurrentBackBufferIndex();

    virtual HRESULT STDMETHODCALLTYPE CheckColorSpaceSupport(
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        UINT* pColorSpaceSupport);

    virtual HRESULT STDMETHODCALLTYPE SetColorSpace1(
        DXGI_COLOR_SPACE_TYPE ColorSpace);

    virtual HRESULT STDMETHODCALLTYPE ResizeBuffers1(
        UINT BufferCount,
        UINT Width,
        UINT Height,
        DXGI_FORMAT Format,
        UINT SwapChainFlags,
        const UINT* pCreationNodeMask,
        IUnknown* const* ppPresentQueue);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISwapChain3* object_;
};

class IDXGIOutput4_Wrapper : public IDXGIOutput3_Wrapper
{
  public:
    IDXGIOutput4_Wrapper(REFIID riid, IDXGIOutput4* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput4_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutput4** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CheckOverlayColorSpaceSupport(
        DXGI_FORMAT Format,
        DXGI_COLOR_SPACE_TYPE ColorSpace,
        IUnknown* pConcernedDevice,
        UINT* pFlags);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutput4* object_;
};

class IDXGIFactory4_Wrapper : public IDXGIFactory3_Wrapper
{
  public:
    IDXGIFactory4_Wrapper(REFIID riid, IDXGIFactory4* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory4_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory4** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE EnumAdapterByLuid(
        LUID AdapterLuid,
        REFIID riid,
        void** ppvAdapter);

    virtual HRESULT STDMETHODCALLTYPE EnumWarpAdapter(
        REFIID riid,
        void** ppvAdapter);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory4* object_;
};

class IDXGIAdapter3_Wrapper : public IDXGIAdapter2_Wrapper
{
  public:
    IDXGIAdapter3_Wrapper(REFIID riid, IDXGIAdapter3* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter3_Wrapper*>(u); });

    void GetWrappedObject(IDXGIAdapter3** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE RegisterHardwareContentProtectionTeardownStatusEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterHardwareContentProtectionTeardownStatus(
        DWORD dwCookie);

    virtual HRESULT STDMETHODCALLTYPE QueryVideoMemoryInfo(
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo);

    virtual HRESULT STDMETHODCALLTYPE SetVideoMemoryReservation(
        UINT NodeIndex,
        DXGI_MEMORY_SEGMENT_GROUP MemorySegmentGroup,
        UINT64 Reservation);

    virtual HRESULT STDMETHODCALLTYPE RegisterVideoMemoryBudgetChangeNotificationEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual void STDMETHODCALLTYPE UnregisterVideoMemoryBudgetChangeNotification(
        DWORD dwCookie);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIAdapter3* object_;
};


/*
** This part is generated from dxgi1_5.h in Windows SDK: 10.0.19041.0
**
*/

class IDXGIOutput5_Wrapper : public IDXGIOutput4_Wrapper
{
  public:
    IDXGIOutput5_Wrapper(REFIID riid, IDXGIOutput5* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput5_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutput5** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE DuplicateOutput1(
        IUnknown* pDevice,
        UINT Flags,
        UINT SupportedFormatsCount,
        const DXGI_FORMAT* pSupportedFormats,
        IDXGIOutputDuplication** ppOutputDuplication);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutput5* object_;
};

class IDXGISwapChain4_Wrapper : public IDXGISwapChain3_Wrapper
{
  public:
    IDXGISwapChain4_Wrapper(REFIID riid, IDXGISwapChain4* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGISwapChain4_Wrapper*>(u); });

    void GetWrappedObject(IDXGISwapChain4** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE SetHDRMetaData(
        DXGI_HDR_METADATA_TYPE Type,
        UINT Size,
        void* pMetaData);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGISwapChain4* object_;
};

class IDXGIDevice4_Wrapper : public IDXGIDevice3_Wrapper
{
  public:
    IDXGIDevice4_Wrapper(REFIID riid, IDXGIDevice4* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIDevice4_Wrapper*>(u); });

    void GetWrappedObject(IDXGIDevice4** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE OfferResources1(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        DXGI_OFFER_RESOURCE_PRIORITY Priority,
        UINT Flags);

    virtual HRESULT STDMETHODCALLTYPE ReclaimResources1(
        UINT NumResources,
        IDXGIResource* const* ppResources,
        DXGI_RECLAIM_RESOURCE_RESULTS* pResults);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIDevice4* object_;
};

class IDXGIFactory5_Wrapper : public IDXGIFactory4_Wrapper
{
  public:
    IDXGIFactory5_Wrapper(REFIID riid, IDXGIFactory5* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory5_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory5** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
        DXGI_FEATURE Feature,
        void* pFeatureSupportData,
        UINT FeatureSupportDataSize);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory5* object_;
};


/*
** This part is generated from dxgi1_6.h in Windows SDK: 10.0.19041.0
**
*/

HRESULT WINAPI DXGIDeclareAdapterRemovalSupport();

class IDXGIAdapter4_Wrapper : public IDXGIAdapter3_Wrapper
{
  public:
    IDXGIAdapter4_Wrapper(REFIID riid, IDXGIAdapter4* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIAdapter4_Wrapper*>(u); });

    void GetWrappedObject(IDXGIAdapter4** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDesc3(
        DXGI_ADAPTER_DESC3* pDesc);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIAdapter4* object_;
};

class IDXGIOutput6_Wrapper : public IDXGIOutput5_Wrapper
{
  public:
    IDXGIOutput6_Wrapper(REFIID riid, IDXGIOutput6* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIOutput6_Wrapper*>(u); });

    void GetWrappedObject(IDXGIOutput6** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDesc1(
        DXGI_OUTPUT_DESC1* pDesc);

    virtual HRESULT STDMETHODCALLTYPE CheckHardwareCompositionSupport(
        UINT* pFlags);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIOutput6* object_;
};

class IDXGIFactory6_Wrapper : public IDXGIFactory5_Wrapper
{
  public:
    IDXGIFactory6_Wrapper(REFIID riid, IDXGIFactory6* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory6_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory6** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE EnumAdapterByGpuPreference(
        UINT Adapter,
        DXGI_GPU_PREFERENCE GpuPreference,
        REFIID riid,
        void** ppvAdapter);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory6* object_;
};

class IDXGIFactory7_Wrapper : public IDXGIFactory6_Wrapper
{
  public:
    IDXGIFactory7_Wrapper(REFIID riid, IDXGIFactory7* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<IDXGIFactory7_Wrapper*>(u); });

    void GetWrappedObject(IDXGIFactory7** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE RegisterAdaptersChangedEvent(
        HANDLE hEvent,
        DWORD* pdwCookie);

    virtual HRESULT STDMETHODCALLTYPE UnregisterAdaptersChangedEvent(
        DWORD dwCookie);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    IDXGIFactory7* object_;
};


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
    ID3DBlob** ppErrorBlob);

HRESULT WINAPI D3D12CreateRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

HRESULT WINAPI D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature,
    ID3DBlob** ppBlob,
    ID3DBlob** ppErrorBlob);

HRESULT WINAPI D3D12CreateVersionedRootSignatureDeserializer(
    LPCVOID pSrcData,
    SIZE_T SrcDataSizeInBytes,
    REFIID pRootSignatureDeserializerInterface,
    void** ppRootSignatureDeserializer);

HRESULT WINAPI D3D12CreateDevice(
    IUnknown* pAdapter,
    D3D_FEATURE_LEVEL MinimumFeatureLevel,
    REFIID riid,
    void** ppDevice);

HRESULT WINAPI D3D12GetDebugInterface(
    REFIID riid,
    void** ppvDebug);

HRESULT WINAPI D3D12EnableExperimentalFeatures(
    UINT NumFeatures,
    const IID* pIIDs,
    void* pConfigurationStructs,
    UINT* pConfigurationStructSizes);

class ID3D12Object_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12Object_Wrapper(REFIID riid, ID3D12Object* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Object_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Object** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetPrivateData(
        REFGUID guid,
        UINT* pDataSize,
        void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateData(
        REFGUID guid,
        UINT DataSize,
        const void* pData);

    virtual HRESULT STDMETHODCALLTYPE SetPrivateDataInterface(
        REFGUID guid,
        const IUnknown* pData);

    virtual HRESULT STDMETHODCALLTYPE SetName(
        LPCWSTR Name);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Object* object_;
};

class ID3D12DeviceChild_Wrapper : public ID3D12Object_Wrapper
{
  public:
    ID3D12DeviceChild_Wrapper(REFIID riid, ID3D12DeviceChild* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceChild_Wrapper*>(u); });

    void GetWrappedObject(ID3D12DeviceChild** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetDevice(
        REFIID riid,
        void** ppvDevice);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12DeviceChild* object_;
};

class ID3D12RootSignature_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12RootSignature_Wrapper(REFIID riid, ID3D12RootSignature* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12RootSignature_Wrapper*>(u); });

    void GetWrappedObject(ID3D12RootSignature** object) const { if (object != nullptr) { (*object) = object_; } }

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12RootSignature* object_;
};

class ID3D12RootSignatureDeserializer_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12RootSignatureDeserializer_Wrapper(REFIID riid, ID3D12RootSignatureDeserializer* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12RootSignatureDeserializer_Wrapper*>(u); });

    void GetWrappedObject(ID3D12RootSignatureDeserializer** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual const D3D12_ROOT_SIGNATURE_DESC* STDMETHODCALLTYPE GetRootSignatureDesc();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12RootSignatureDeserializer* object_;
};

class ID3D12VersionedRootSignatureDeserializer_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12VersionedRootSignatureDeserializer_Wrapper(REFIID riid, ID3D12VersionedRootSignatureDeserializer* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12VersionedRootSignatureDeserializer_Wrapper*>(u); });

    void GetWrappedObject(ID3D12VersionedRootSignatureDeserializer** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetRootSignatureDescAtVersion(
        D3D_ROOT_SIGNATURE_VERSION convertToVersion,
        const D3D12_VERSIONED_ROOT_SIGNATURE_DESC** ppDesc);

    virtual const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* STDMETHODCALLTYPE GetUnconvertedRootSignatureDesc();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12VersionedRootSignatureDeserializer* object_;
};

class ID3D12Pageable_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12Pageable_Wrapper(REFIID riid, ID3D12Pageable* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Pageable_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Pageable** object) const { if (object != nullptr) { (*object) = object_; } }

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Pageable* object_;
};

class ID3D12Heap_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12Heap_Wrapper(REFIID riid, ID3D12Heap* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Heap_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Heap** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_HEAP_DESC STDMETHODCALLTYPE GetDesc();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Heap* object_;
};

class ID3D12Resource_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12Resource_Wrapper(REFIID riid, ID3D12Resource* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Resource_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Resource** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE Map(
        UINT Subresource,
        const D3D12_RANGE* pReadRange,
        void** ppData);

    virtual void STDMETHODCALLTYPE Unmap(
        UINT Subresource,
        const D3D12_RANGE* pWrittenRange);

    virtual D3D12_RESOURCE_DESC STDMETHODCALLTYPE GetDesc();

    virtual D3D12_GPU_VIRTUAL_ADDRESS STDMETHODCALLTYPE GetGPUVirtualAddress();

    virtual HRESULT STDMETHODCALLTYPE WriteToSubresource(
        UINT DstSubresource,
        const D3D12_BOX* pDstBox,
        const void* pSrcData,
        UINT SrcRowPitch,
        UINT SrcDepthPitch);

    virtual HRESULT STDMETHODCALLTYPE ReadFromSubresource(
        void* pDstData,
        UINT DstRowPitch,
        UINT DstDepthPitch,
        UINT SrcSubresource,
        const D3D12_BOX* pSrcBox);

    virtual HRESULT STDMETHODCALLTYPE GetHeapProperties(
        D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS* pHeapFlags);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Resource* object_;
};

class ID3D12CommandAllocator_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12CommandAllocator_Wrapper(REFIID riid, ID3D12CommandAllocator* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandAllocator_Wrapper*>(u); });

    void GetWrappedObject(ID3D12CommandAllocator** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE Reset();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12CommandAllocator* object_;
};

class ID3D12Fence_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12Fence_Wrapper(REFIID riid, ID3D12Fence* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Fence_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Fence** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual UINT64 STDMETHODCALLTYPE GetCompletedValue();

    virtual HRESULT STDMETHODCALLTYPE SetEventOnCompletion(
        UINT64 Value,
        HANDLE hEvent);

    virtual HRESULT STDMETHODCALLTYPE Signal(
        UINT64 Value);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Fence* object_;
};

class ID3D12Fence1_Wrapper : public ID3D12Fence_Wrapper
{
  public:
    ID3D12Fence1_Wrapper(REFIID riid, ID3D12Fence1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Fence1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Fence1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_FENCE_FLAGS STDMETHODCALLTYPE GetCreationFlags();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Fence1* object_;
};

class ID3D12PipelineState_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12PipelineState_Wrapper(REFIID riid, ID3D12PipelineState* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12PipelineState_Wrapper*>(u); });

    void GetWrappedObject(ID3D12PipelineState** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetCachedBlob(
        ID3DBlob** ppBlob);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12PipelineState* object_;
};

class ID3D12DescriptorHeap_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12DescriptorHeap_Wrapper(REFIID riid, ID3D12DescriptorHeap* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DescriptorHeap_Wrapper*>(u); });

    void GetWrappedObject(ID3D12DescriptorHeap** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_DESCRIPTOR_HEAP_DESC STDMETHODCALLTYPE GetDesc();

    virtual D3D12_CPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE GetCPUDescriptorHandleForHeapStart();

    virtual D3D12_GPU_DESCRIPTOR_HANDLE STDMETHODCALLTYPE GetGPUDescriptorHandleForHeapStart();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12DescriptorHeap* object_;
};

class ID3D12QueryHeap_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12QueryHeap_Wrapper(REFIID riid, ID3D12QueryHeap* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12QueryHeap_Wrapper*>(u); });

    void GetWrappedObject(ID3D12QueryHeap** object) const { if (object != nullptr) { (*object) = object_; } }

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12QueryHeap* object_;
};

class ID3D12CommandSignature_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12CommandSignature_Wrapper(REFIID riid, ID3D12CommandSignature* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandSignature_Wrapper*>(u); });

    void GetWrappedObject(ID3D12CommandSignature** object) const { if (object != nullptr) { (*object) = object_; } }

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12CommandSignature* object_;
};

class ID3D12CommandList_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12CommandList_Wrapper(REFIID riid, ID3D12CommandList* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandList_Wrapper*>(u); });

    void GetWrappedObject(ID3D12CommandList** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_COMMAND_LIST_TYPE STDMETHODCALLTYPE GetType();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12CommandList* object_;
};

class ID3D12GraphicsCommandList_Wrapper : public ID3D12CommandList_Wrapper
{
  public:
    ID3D12GraphicsCommandList_Wrapper(REFIID riid, ID3D12GraphicsCommandList* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList_Wrapper*>(u); });

    void GetWrappedObject(ID3D12GraphicsCommandList** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE Close();

    virtual HRESULT STDMETHODCALLTYPE Reset(
        ID3D12CommandAllocator* pAllocator,
        ID3D12PipelineState* pInitialState);

    virtual void STDMETHODCALLTYPE ClearState(
        ID3D12PipelineState* pPipelineState);

    virtual void STDMETHODCALLTYPE DrawInstanced(
        UINT VertexCountPerInstance,
        UINT InstanceCount,
        UINT StartVertexLocation,
        UINT StartInstanceLocation);

    virtual void STDMETHODCALLTYPE DrawIndexedInstanced(
        UINT IndexCountPerInstance,
        UINT InstanceCount,
        UINT StartIndexLocation,
        INT BaseVertexLocation,
        UINT StartInstanceLocation);

    virtual void STDMETHODCALLTYPE Dispatch(
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ);

    virtual void STDMETHODCALLTYPE CopyBufferRegion(
        ID3D12Resource* pDstBuffer,
        UINT64 DstOffset,
        ID3D12Resource* pSrcBuffer,
        UINT64 SrcOffset,
        UINT64 NumBytes);

    virtual void STDMETHODCALLTYPE CopyTextureRegion(
        const D3D12_TEXTURE_COPY_LOCATION* pDst,
        UINT DstX,
        UINT DstY,
        UINT DstZ,
        const D3D12_TEXTURE_COPY_LOCATION* pSrc,
        const D3D12_BOX* pSrcBox);

    virtual void STDMETHODCALLTYPE CopyResource(
        ID3D12Resource* pDstResource,
        ID3D12Resource* pSrcResource);

    virtual void STDMETHODCALLTYPE CopyTiles(
        ID3D12Resource* pTiledResource,
        const D3D12_TILED_RESOURCE_COORDINATE* pTileRegionStartCoordinate,
        const D3D12_TILE_REGION_SIZE* pTileRegionSize,
        ID3D12Resource* pBuffer,
        UINT64 BufferStartOffsetInBytes,
        D3D12_TILE_COPY_FLAGS Flags);

    virtual void STDMETHODCALLTYPE ResolveSubresource(
        ID3D12Resource* pDstResource,
        UINT DstSubresource,
        ID3D12Resource* pSrcResource,
        UINT SrcSubresource,
        DXGI_FORMAT Format);

    virtual void STDMETHODCALLTYPE IASetPrimitiveTopology(
        D3D12_PRIMITIVE_TOPOLOGY PrimitiveTopology);

    virtual void STDMETHODCALLTYPE RSSetViewports(
        UINT NumViewports,
        const D3D12_VIEWPORT* pViewports);

    virtual void STDMETHODCALLTYPE RSSetScissorRects(
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE OMSetBlendFactor(
        const FLOAT BlendFactor [4]);

    virtual void STDMETHODCALLTYPE OMSetStencilRef(
        UINT StencilRef);

    virtual void STDMETHODCALLTYPE SetPipelineState(
        ID3D12PipelineState* pPipelineState);

    virtual void STDMETHODCALLTYPE ResourceBarrier(
        UINT NumBarriers,
        const D3D12_RESOURCE_BARRIER* pBarriers);

    virtual void STDMETHODCALLTYPE ExecuteBundle(
        ID3D12GraphicsCommandList* pCommandList);

    virtual void STDMETHODCALLTYPE SetDescriptorHeaps(
        UINT NumDescriptorHeaps,
        ID3D12DescriptorHeap* const* ppDescriptorHeaps);

    virtual void STDMETHODCALLTYPE SetComputeRootSignature(
        ID3D12RootSignature* pRootSignature);

    virtual void STDMETHODCALLTYPE SetGraphicsRootSignature(
        ID3D12RootSignature* pRootSignature);

    virtual void STDMETHODCALLTYPE SetComputeRootDescriptorTable(
        UINT RootParameterIndex,
        D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

    virtual void STDMETHODCALLTYPE SetGraphicsRootDescriptorTable(
        UINT RootParameterIndex,
        D3D12_GPU_DESCRIPTOR_HANDLE BaseDescriptor);

    virtual void STDMETHODCALLTYPE SetComputeRoot32BitConstant(
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetGraphicsRoot32BitConstant(
        UINT RootParameterIndex,
        UINT SrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetComputeRoot32BitConstants(
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        const void* pSrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetGraphicsRoot32BitConstants(
        UINT RootParameterIndex,
        UINT Num32BitValuesToSet,
        const void* pSrcData,
        UINT DestOffsetIn32BitValues);

    virtual void STDMETHODCALLTYPE SetComputeRootConstantBufferView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetGraphicsRootConstantBufferView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetComputeRootShaderResourceView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetGraphicsRootShaderResourceView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetComputeRootUnorderedAccessView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE SetGraphicsRootUnorderedAccessView(
        UINT RootParameterIndex,
        D3D12_GPU_VIRTUAL_ADDRESS BufferLocation);

    virtual void STDMETHODCALLTYPE IASetIndexBuffer(
        const D3D12_INDEX_BUFFER_VIEW* pView);

    virtual void STDMETHODCALLTYPE IASetVertexBuffers(
        UINT StartSlot,
        UINT NumViews,
        const D3D12_VERTEX_BUFFER_VIEW* pViews);

    virtual void STDMETHODCALLTYPE SOSetTargets(
        UINT StartSlot,
        UINT NumViews,
        const D3D12_STREAM_OUTPUT_BUFFER_VIEW* pViews);

    virtual void STDMETHODCALLTYPE OMSetRenderTargets(
        UINT NumRenderTargetDescriptors,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pRenderTargetDescriptors,
        BOOL RTsSingleHandleToDescriptorRange,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pDepthStencilDescriptor);

    virtual void STDMETHODCALLTYPE ClearDepthStencilView(
        D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView,
        D3D12_CLEAR_FLAGS ClearFlags,
        FLOAT Depth,
        UINT8 Stencil,
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE ClearRenderTargetView(
        D3D12_CPU_DESCRIPTOR_HANDLE RenderTargetView,
        const FLOAT ColorRGBA [4],
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewUint(
        D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        ID3D12Resource* pResource,
        const UINT Values [4],
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewFloat(
        D3D12_GPU_DESCRIPTOR_HANDLE ViewGPUHandleInCurrentHeap,
        D3D12_CPU_DESCRIPTOR_HANDLE ViewCPUHandle,
        ID3D12Resource* pResource,
        const FLOAT Values [4],
        UINT NumRects,
        const D3D12_RECT* pRects);

    virtual void STDMETHODCALLTYPE DiscardResource(
        ID3D12Resource* pResource,
        const D3D12_DISCARD_REGION* pRegion);

    virtual void STDMETHODCALLTYPE BeginQuery(
        ID3D12QueryHeap* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index);

    virtual void STDMETHODCALLTYPE EndQuery(
        ID3D12QueryHeap* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT Index);

    virtual void STDMETHODCALLTYPE ResolveQueryData(
        ID3D12QueryHeap* pQueryHeap,
        D3D12_QUERY_TYPE Type,
        UINT StartIndex,
        UINT NumQueries,
        ID3D12Resource* pDestinationBuffer,
        UINT64 AlignedDestinationBufferOffset);

    virtual void STDMETHODCALLTYPE SetPredication(
        ID3D12Resource* pBuffer,
        UINT64 AlignedBufferOffset,
        D3D12_PREDICATION_OP Operation);

    virtual void STDMETHODCALLTYPE SetMarker(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE BeginEvent(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE EndEvent();

    virtual void STDMETHODCALLTYPE ExecuteIndirect(
        ID3D12CommandSignature* pCommandSignature,
        UINT MaxCommandCount,
        ID3D12Resource* pArgumentBuffer,
        UINT64 ArgumentBufferOffset,
        ID3D12Resource* pCountBuffer,
        UINT64 CountBufferOffset);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12GraphicsCommandList* object_;
};

class ID3D12GraphicsCommandList1_Wrapper : public ID3D12GraphicsCommandList_Wrapper
{
  public:
    ID3D12GraphicsCommandList1_Wrapper(REFIID riid, ID3D12GraphicsCommandList1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12GraphicsCommandList1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE AtomicCopyBufferUINT(
        ID3D12Resource* pDstBuffer,
        UINT64 DstOffset,
        ID3D12Resource* pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        ID3D12Resource* const* ppDependentResources,
        const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

    virtual void STDMETHODCALLTYPE AtomicCopyBufferUINT64(
        ID3D12Resource* pDstBuffer,
        UINT64 DstOffset,
        ID3D12Resource* pSrcBuffer,
        UINT64 SrcOffset,
        UINT Dependencies,
        ID3D12Resource* const* ppDependentResources,
        const D3D12_SUBRESOURCE_RANGE_UINT64* pDependentSubresourceRanges);

    virtual void STDMETHODCALLTYPE OMSetDepthBounds(
        FLOAT Min,
        FLOAT Max);

    virtual void STDMETHODCALLTYPE SetSamplePositions(
        UINT NumSamplesPerPixel,
        UINT NumPixels,
        D3D12_SAMPLE_POSITION* pSamplePositions);

    virtual void STDMETHODCALLTYPE ResolveSubresourceRegion(
        ID3D12Resource* pDstResource,
        UINT DstSubresource,
        UINT DstX,
        UINT DstY,
        ID3D12Resource* pSrcResource,
        UINT SrcSubresource,
        D3D12_RECT* pSrcRect,
        DXGI_FORMAT Format,
        D3D12_RESOLVE_MODE ResolveMode);

    virtual void STDMETHODCALLTYPE SetViewInstanceMask(
        UINT Mask);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12GraphicsCommandList1* object_;
};

class ID3D12GraphicsCommandList2_Wrapper : public ID3D12GraphicsCommandList1_Wrapper
{
  public:
    ID3D12GraphicsCommandList2_Wrapper(REFIID riid, ID3D12GraphicsCommandList2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList2_Wrapper*>(u); });

    void GetWrappedObject(ID3D12GraphicsCommandList2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE WriteBufferImmediate(
        UINT Count,
        const D3D12_WRITEBUFFERIMMEDIATE_PARAMETER* pParams,
        const D3D12_WRITEBUFFERIMMEDIATE_MODE* pModes);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12GraphicsCommandList2* object_;
};

class ID3D12CommandQueue_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12CommandQueue_Wrapper(REFIID riid, ID3D12CommandQueue* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12CommandQueue_Wrapper*>(u); });

    void GetWrappedObject(ID3D12CommandQueue** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE UpdateTileMappings(
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

    virtual void STDMETHODCALLTYPE CopyTileMappings(
        ID3D12Resource* pDstResource,
        const D3D12_TILED_RESOURCE_COORDINATE* pDstRegionStartCoordinate,
        ID3D12Resource* pSrcResource,
        const D3D12_TILED_RESOURCE_COORDINATE* pSrcRegionStartCoordinate,
        const D3D12_TILE_REGION_SIZE* pRegionSize,
        D3D12_TILE_MAPPING_FLAGS Flags);

    virtual void STDMETHODCALLTYPE ExecuteCommandLists(
        UINT NumCommandLists,
        ID3D12CommandList* const* ppCommandLists);

    virtual void STDMETHODCALLTYPE SetMarker(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE BeginEvent(
        UINT Metadata,
        const void* pData,
        UINT Size);

    virtual void STDMETHODCALLTYPE EndEvent();

    virtual HRESULT STDMETHODCALLTYPE Signal(
        ID3D12Fence* pFence,
        UINT64 Value);

    virtual HRESULT STDMETHODCALLTYPE Wait(
        ID3D12Fence* pFence,
        UINT64 Value);

    virtual HRESULT STDMETHODCALLTYPE GetTimestampFrequency(
        UINT64* pFrequency);

    virtual HRESULT STDMETHODCALLTYPE GetClockCalibration(
        UINT64* pGpuTimestamp,
        UINT64* pCpuTimestamp);

    virtual D3D12_COMMAND_QUEUE_DESC STDMETHODCALLTYPE GetDesc();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12CommandQueue* object_;
};

class ID3D12Device_Wrapper : public ID3D12Object_Wrapper
{
  public:
    ID3D12Device_Wrapper(REFIID riid, ID3D12Device* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual UINT STDMETHODCALLTYPE GetNodeCount();

    virtual HRESULT STDMETHODCALLTYPE CreateCommandQueue(
        const D3D12_COMMAND_QUEUE_DESC* pDesc,
        REFIID riid,
        void** ppCommandQueue);

    virtual HRESULT STDMETHODCALLTYPE CreateCommandAllocator(
        D3D12_COMMAND_LIST_TYPE type,
        REFIID riid,
        void** ppCommandAllocator);

    virtual HRESULT STDMETHODCALLTYPE CreateGraphicsPipelineState(
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual HRESULT STDMETHODCALLTYPE CreateComputePipelineState(
        const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual HRESULT STDMETHODCALLTYPE CreateCommandList(
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        ID3D12CommandAllocator* pCommandAllocator,
        ID3D12PipelineState* pInitialState,
        REFIID riid,
        void** ppCommandList);

    virtual HRESULT STDMETHODCALLTYPE CheckFeatureSupport(
        D3D12_FEATURE Feature,
        void* pFeatureSupportData,
        UINT FeatureSupportDataSize);

    virtual HRESULT STDMETHODCALLTYPE CreateDescriptorHeap(
        const D3D12_DESCRIPTOR_HEAP_DESC* pDescriptorHeapDesc,
        REFIID riid,
        void** ppvHeap);

    virtual UINT STDMETHODCALLTYPE GetDescriptorHandleIncrementSize(
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapType);

    virtual HRESULT STDMETHODCALLTYPE CreateRootSignature(
        UINT nodeMask,
        const void* pBlobWithRootSignature,
        SIZE_T blobLengthInBytes,
        REFIID riid,
        void** ppvRootSignature);

    virtual void STDMETHODCALLTYPE CreateConstantBufferView(
        const D3D12_CONSTANT_BUFFER_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateShaderResourceView(
        ID3D12Resource* pResource,
        const D3D12_SHADER_RESOURCE_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateUnorderedAccessView(
        ID3D12Resource* pResource,
        ID3D12Resource* pCounterResource,
        const D3D12_UNORDERED_ACCESS_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateRenderTargetView(
        ID3D12Resource* pResource,
        const D3D12_RENDER_TARGET_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateDepthStencilView(
        ID3D12Resource* pResource,
        const D3D12_DEPTH_STENCIL_VIEW_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CreateSampler(
        const D3D12_SAMPLER_DESC* pDesc,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE CopyDescriptors(
        UINT NumDestDescriptorRanges,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pDestDescriptorRangeStarts,
        const UINT* pDestDescriptorRangeSizes,
        UINT NumSrcDescriptorRanges,
        const D3D12_CPU_DESCRIPTOR_HANDLE* pSrcDescriptorRangeStarts,
        const UINT* pSrcDescriptorRangeSizes,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

    virtual void STDMETHODCALLTYPE CopyDescriptorsSimple(
        UINT NumDescriptors,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptorRangeStart,
        D3D12_CPU_DESCRIPTOR_HANDLE SrcDescriptorRangeStart,
        D3D12_DESCRIPTOR_HEAP_TYPE DescriptorHeapsType);

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo(
        UINT visibleMask,
        UINT numResourceDescs,
        const D3D12_RESOURCE_DESC* pResourceDescs);

    virtual D3D12_HEAP_PROPERTIES STDMETHODCALLTYPE GetCustomHeapProperties(
        UINT nodeMask,
        D3D12_HEAP_TYPE heapType);

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource(
        const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riidResource,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateHeap(
        const D3D12_HEAP_DESC* pDesc,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE CreatePlacedResource(
        ID3D12Heap* pHeap,
        UINT64 HeapOffset,
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateReservedResource(
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateSharedHandle(
        ID3D12DeviceChild* pObject,
        const SECURITY_ATTRIBUTES* pAttributes,
        DWORD Access,
        LPCWSTR Name,
        HANDLE* pHandle);

    virtual HRESULT STDMETHODCALLTYPE OpenSharedHandle(
        HANDLE NTHandle,
        REFIID riid,
        void** ppvObj);

    virtual HRESULT STDMETHODCALLTYPE OpenSharedHandleByName(
        LPCWSTR Name,
        DWORD Access,
        HANDLE* pNTHandle);

    virtual HRESULT STDMETHODCALLTYPE MakeResident(
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects);

    virtual HRESULT STDMETHODCALLTYPE Evict(
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects);

    virtual HRESULT STDMETHODCALLTYPE CreateFence(
        UINT64 InitialValue,
        D3D12_FENCE_FLAGS Flags,
        REFIID riid,
        void** ppFence);

    virtual HRESULT STDMETHODCALLTYPE GetDeviceRemovedReason();

    virtual void STDMETHODCALLTYPE GetCopyableFootprints(
        const D3D12_RESOURCE_DESC* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
        UINT* pNumRows,
        UINT64* pRowSizeInBytes,
        UINT64* pTotalBytes);

    virtual HRESULT STDMETHODCALLTYPE CreateQueryHeap(
        const D3D12_QUERY_HEAP_DESC* pDesc,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE SetStablePowerState(
        BOOL Enable);

    virtual HRESULT STDMETHODCALLTYPE CreateCommandSignature(
        const D3D12_COMMAND_SIGNATURE_DESC* pDesc,
        ID3D12RootSignature* pRootSignature,
        REFIID riid,
        void** ppvCommandSignature);

    virtual void STDMETHODCALLTYPE GetResourceTiling(
        ID3D12Resource* pTiledResource,
        UINT* pNumTilesForEntireResource,
        D3D12_PACKED_MIP_INFO* pPackedMipDesc,
        D3D12_TILE_SHAPE* pStandardTileShapeForNonPackedMips,
        UINT* pNumSubresourceTilings,
        UINT FirstSubresourceTilingToGet,
        D3D12_SUBRESOURCE_TILING* pSubresourceTilingsForNonPackedMips);

    virtual LUID STDMETHODCALLTYPE GetAdapterLuid();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device* object_;
};

class ID3D12PipelineLibrary_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12PipelineLibrary_Wrapper(REFIID riid, ID3D12PipelineLibrary* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12PipelineLibrary_Wrapper*>(u); });

    void GetWrappedObject(ID3D12PipelineLibrary** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE StorePipeline(
        LPCWSTR pName,
        ID3D12PipelineState* pPipeline);

    virtual HRESULT STDMETHODCALLTYPE LoadGraphicsPipeline(
        LPCWSTR pName,
        const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual HRESULT STDMETHODCALLTYPE LoadComputePipeline(
        LPCWSTR pName,
        const D3D12_COMPUTE_PIPELINE_STATE_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

    virtual SIZE_T STDMETHODCALLTYPE GetSerializedSize();

    virtual HRESULT STDMETHODCALLTYPE Serialize(
        void* pData,
        SIZE_T DataSizeInBytes);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12PipelineLibrary* object_;
};

class ID3D12PipelineLibrary1_Wrapper : public ID3D12PipelineLibrary_Wrapper
{
  public:
    ID3D12PipelineLibrary1_Wrapper(REFIID riid, ID3D12PipelineLibrary1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12PipelineLibrary1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12PipelineLibrary1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE LoadPipeline(
        LPCWSTR pName,
        const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12PipelineLibrary1* object_;
};

class ID3D12Device1_Wrapper : public ID3D12Device_Wrapper
{
  public:
    ID3D12Device1_Wrapper(REFIID riid, ID3D12Device1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CreatePipelineLibrary(
        const void* pLibraryBlob,
        SIZE_T BlobLength,
        REFIID riid,
        void** ppPipelineLibrary);

    virtual HRESULT STDMETHODCALLTYPE SetEventOnMultipleFenceCompletion(
        ID3D12Fence* const* ppFences,
        const UINT64* pFenceValues,
        UINT NumFences,
        D3D12_MULTIPLE_FENCE_WAIT_FLAGS Flags,
        HANDLE hEvent);

    virtual HRESULT STDMETHODCALLTYPE SetResidencyPriority(
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects,
        const D3D12_RESIDENCY_PRIORITY* pPriorities);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device1* object_;
};

class ID3D12Device2_Wrapper : public ID3D12Device1_Wrapper
{
  public:
    ID3D12Device2_Wrapper(REFIID riid, ID3D12Device2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device2_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CreatePipelineState(
        const D3D12_PIPELINE_STATE_STREAM_DESC* pDesc,
        REFIID riid,
        void** ppPipelineState);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device2* object_;
};

class ID3D12Device3_Wrapper : public ID3D12Device2_Wrapper
{
  public:
    ID3D12Device3_Wrapper(REFIID riid, ID3D12Device3* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device3_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device3** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE OpenExistingHeapFromAddress(
        const void* pAddress,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE OpenExistingHeapFromFileMapping(
        HANDLE hFileMapping,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE EnqueueMakeResident(
        D3D12_RESIDENCY_FLAGS Flags,
        UINT NumObjects,
        ID3D12Pageable* const* ppObjects,
        ID3D12Fence* pFenceToSignal,
        UINT64 FenceValueToSignal);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device3* object_;
};

class ID3D12ProtectedSession_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12ProtectedSession_Wrapper(REFIID riid, ID3D12ProtectedSession* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ProtectedSession_Wrapper*>(u); });

    void GetWrappedObject(ID3D12ProtectedSession** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetStatusFence(
        REFIID riid,
        void** ppFence);

    virtual D3D12_PROTECTED_SESSION_STATUS STDMETHODCALLTYPE GetSessionStatus();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12ProtectedSession* object_;
};

class ID3D12ProtectedResourceSession_Wrapper : public ID3D12ProtectedSession_Wrapper
{
  public:
    ID3D12ProtectedResourceSession_Wrapper(REFIID riid, ID3D12ProtectedResourceSession* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ProtectedResourceSession_Wrapper*>(u); });

    void GetWrappedObject(ID3D12ProtectedResourceSession** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_PROTECTED_RESOURCE_SESSION_DESC STDMETHODCALLTYPE GetDesc();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12ProtectedResourceSession* object_;
};

class ID3D12Device4_Wrapper : public ID3D12Device3_Wrapper
{
  public:
    ID3D12Device4_Wrapper(REFIID riid, ID3D12Device4* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device4_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device4** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CreateCommandList1(
        UINT nodeMask,
        D3D12_COMMAND_LIST_TYPE type,
        D3D12_COMMAND_LIST_FLAGS flags,
        REFIID riid,
        void** ppCommandList);

    virtual HRESULT STDMETHODCALLTYPE CreateProtectedResourceSession(
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC* pDesc,
        REFIID riid,
        void** ppSession);

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource1(
        const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riidResource,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreateHeap1(
        const D3D12_HEAP_DESC* pDesc,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riid,
        void** ppvHeap);

    virtual HRESULT STDMETHODCALLTYPE CreateReservedResource1(
        const D3D12_RESOURCE_DESC* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riid,
        void** ppvResource);

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo1(
        UINT visibleMask,
        UINT numResourceDescs,
        const D3D12_RESOURCE_DESC* pResourceDescs,
        D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device4* object_;
};

class ID3D12LifetimeOwner_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12LifetimeOwner_Wrapper(REFIID riid, ID3D12LifetimeOwner* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12LifetimeOwner_Wrapper*>(u); });

    void GetWrappedObject(ID3D12LifetimeOwner** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE LifetimeStateUpdated(
        D3D12_LIFETIME_STATE NewState);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12LifetimeOwner* object_;
};

class ID3D12SwapChainAssistant_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12SwapChainAssistant_Wrapper(REFIID riid, ID3D12SwapChainAssistant* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12SwapChainAssistant_Wrapper*>(u); });

    void GetWrappedObject(ID3D12SwapChainAssistant** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual LUID STDMETHODCALLTYPE GetLUID();

    virtual HRESULT STDMETHODCALLTYPE GetSwapChainObject(
        REFIID riid,
        void** ppv);

    virtual HRESULT STDMETHODCALLTYPE GetCurrentResourceAndCommandQueue(
        REFIID riidResource,
        void** ppvResource,
        REFIID riidQueue,
        void** ppvQueue);

    virtual HRESULT STDMETHODCALLTYPE InsertImplicitSync();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12SwapChainAssistant* object_;
};

class ID3D12LifetimeTracker_Wrapper : public ID3D12DeviceChild_Wrapper
{
  public:
    ID3D12LifetimeTracker_Wrapper(REFIID riid, ID3D12LifetimeTracker* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12LifetimeTracker_Wrapper*>(u); });

    void GetWrappedObject(ID3D12LifetimeTracker** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE DestroyOwnedObject(
        ID3D12DeviceChild* pObject);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12LifetimeTracker* object_;
};

class ID3D12StateObject_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12StateObject_Wrapper(REFIID riid, ID3D12StateObject* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12StateObject_Wrapper*>(u); });

    void GetWrappedObject(ID3D12StateObject** object) const { if (object != nullptr) { (*object) = object_; } }

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12StateObject* object_;
};

class ID3D12StateObjectProperties_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12StateObjectProperties_Wrapper(REFIID riid, ID3D12StateObjectProperties* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12StateObjectProperties_Wrapper*>(u); });

    void GetWrappedObject(ID3D12StateObjectProperties** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void* STDMETHODCALLTYPE GetShaderIdentifier(
        LPCWSTR pExportName);

    virtual UINT64 STDMETHODCALLTYPE GetShaderStackSize(
        LPCWSTR pExportName);

    virtual UINT64 STDMETHODCALLTYPE GetPipelineStackSize();

    virtual void STDMETHODCALLTYPE SetPipelineStackSize(
        UINT64 PipelineStackSizeInBytes);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12StateObjectProperties* object_;
};

class ID3D12Device5_Wrapper : public ID3D12Device4_Wrapper
{
  public:
    ID3D12Device5_Wrapper(REFIID riid, ID3D12Device5* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device5_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device5** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE CreateLifetimeTracker(
        ID3D12LifetimeOwner* pOwner,
        REFIID riid,
        void** ppvTracker);

    virtual void STDMETHODCALLTYPE RemoveDevice();

    virtual HRESULT STDMETHODCALLTYPE EnumerateMetaCommands(
        UINT* pNumMetaCommands,
        D3D12_META_COMMAND_DESC* pDescs);

    virtual HRESULT STDMETHODCALLTYPE EnumerateMetaCommandParameters(
        REFGUID CommandId,
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT* pTotalStructureSizeInBytes,
        UINT* pParameterCount,
        D3D12_META_COMMAND_PARAMETER_DESC* pParameterDescs);

    virtual HRESULT STDMETHODCALLTYPE CreateMetaCommand(
        REFGUID CommandId,
        UINT NodeMask,
        const void* pCreationParametersData,
        SIZE_T CreationParametersDataSizeInBytes,
        REFIID riid,
        void** ppMetaCommand);

    virtual HRESULT STDMETHODCALLTYPE CreateStateObject(
        const D3D12_STATE_OBJECT_DESC* pDesc,
        REFIID riid,
        void** ppStateObject);

    virtual void STDMETHODCALLTYPE GetRaytracingAccelerationStructurePrebuildInfo(
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_INPUTS* pDesc,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_PREBUILD_INFO* pInfo);

    virtual D3D12_DRIVER_MATCHING_IDENTIFIER_STATUS STDMETHODCALLTYPE CheckDriverMatchingIdentifier(
        D3D12_SERIALIZED_DATA_TYPE SerializedDataType,
        const D3D12_SERIALIZED_DATA_DRIVER_MATCHING_IDENTIFIER* pIdentifierToCheck);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device5* object_;
};

class ID3D12DeviceRemovedExtendedDataSettings_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedDataSettings_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings_Wrapper*>(u); });

    void GetWrappedObject(ID3D12DeviceRemovedExtendedDataSettings** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE SetAutoBreadcrumbsEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void STDMETHODCALLTYPE SetPageFaultEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

    virtual void STDMETHODCALLTYPE SetWatsonDumpEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12DeviceRemovedExtendedDataSettings* object_;
};

class ID3D12DeviceRemovedExtendedDataSettings1_Wrapper : public ID3D12DeviceRemovedExtendedDataSettings_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedDataSettings1_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedDataSettings1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedDataSettings1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12DeviceRemovedExtendedDataSettings1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE SetBreadcrumbContextEnablement(
        D3D12_DRED_ENABLEMENT Enablement);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12DeviceRemovedExtendedDataSettings1* object_;
};

class ID3D12DeviceRemovedExtendedData_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedData_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedData* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedData_Wrapper*>(u); });

    void GetWrappedObject(ID3D12DeviceRemovedExtendedData** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetAutoBreadcrumbsOutput(
        D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT* pOutput);

    virtual HRESULT STDMETHODCALLTYPE GetPageFaultAllocationOutput(
        D3D12_DRED_PAGE_FAULT_OUTPUT* pOutput);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12DeviceRemovedExtendedData* object_;
};

class ID3D12DeviceRemovedExtendedData1_Wrapper : public ID3D12DeviceRemovedExtendedData_Wrapper
{
  public:
    ID3D12DeviceRemovedExtendedData1_Wrapper(REFIID riid, ID3D12DeviceRemovedExtendedData1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12DeviceRemovedExtendedData1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12DeviceRemovedExtendedData1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetAutoBreadcrumbsOutput1(
        D3D12_DRED_AUTO_BREADCRUMBS_OUTPUT1* pOutput);

    virtual HRESULT STDMETHODCALLTYPE GetPageFaultAllocationOutput1(
        D3D12_DRED_PAGE_FAULT_OUTPUT1* pOutput);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12DeviceRemovedExtendedData1* object_;
};

class ID3D12Device6_Wrapper : public ID3D12Device5_Wrapper
{
  public:
    ID3D12Device6_Wrapper(REFIID riid, ID3D12Device6* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device6_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device6** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE SetBackgroundProcessingMode(
        D3D12_BACKGROUND_PROCESSING_MODE Mode,
        D3D12_MEASUREMENTS_ACTION MeasurementsAction,
        HANDLE hEventToSignalUponCompletion,
        BOOL* pbFurtherMeasurementsDesired);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device6* object_;
};

class ID3D12ProtectedResourceSession1_Wrapper : public ID3D12ProtectedResourceSession_Wrapper
{
  public:
    ID3D12ProtectedResourceSession1_Wrapper(REFIID riid, ID3D12ProtectedResourceSession1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12ProtectedResourceSession1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12ProtectedResourceSession1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_PROTECTED_RESOURCE_SESSION_DESC1 STDMETHODCALLTYPE GetDesc1();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12ProtectedResourceSession1* object_;
};

class ID3D12Device7_Wrapper : public ID3D12Device6_Wrapper
{
  public:
    ID3D12Device7_Wrapper(REFIID riid, ID3D12Device7* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device7_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device7** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE AddToStateObject(
        const D3D12_STATE_OBJECT_DESC* pAddition,
        ID3D12StateObject* pStateObjectToGrowFrom,
        REFIID riid,
        void** ppNewStateObject);

    virtual HRESULT STDMETHODCALLTYPE CreateProtectedResourceSession1(
        const D3D12_PROTECTED_RESOURCE_SESSION_DESC1* pDesc,
        REFIID riid,
        void** ppSession);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device7* object_;
};

class ID3D12Device8_Wrapper : public ID3D12Device7_Wrapper
{
  public:
    ID3D12Device8_Wrapper(REFIID riid, ID3D12Device8* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Device8_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Device8** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_RESOURCE_ALLOCATION_INFO STDMETHODCALLTYPE GetResourceAllocationInfo2(
        UINT visibleMask,
        UINT numResourceDescs,
        const D3D12_RESOURCE_DESC1* pResourceDescs,
        D3D12_RESOURCE_ALLOCATION_INFO1* pResourceAllocationInfo1);

    virtual HRESULT STDMETHODCALLTYPE CreateCommittedResource2(
        const D3D12_HEAP_PROPERTIES* pHeapProperties,
        D3D12_HEAP_FLAGS HeapFlags,
        const D3D12_RESOURCE_DESC1* pDesc,
        D3D12_RESOURCE_STATES InitialResourceState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        ID3D12ProtectedResourceSession* pProtectedSession,
        REFIID riidResource,
        void** ppvResource);

    virtual HRESULT STDMETHODCALLTYPE CreatePlacedResource1(
        ID3D12Heap* pHeap,
        UINT64 HeapOffset,
        const D3D12_RESOURCE_DESC1* pDesc,
        D3D12_RESOURCE_STATES InitialState,
        const D3D12_CLEAR_VALUE* pOptimizedClearValue,
        REFIID riid,
        void** ppvResource);

    virtual void STDMETHODCALLTYPE CreateSamplerFeedbackUnorderedAccessView(
        ID3D12Resource* pTargetedResource,
        ID3D12Resource* pFeedbackResource,
        D3D12_CPU_DESCRIPTOR_HANDLE DestDescriptor);

    virtual void STDMETHODCALLTYPE GetCopyableFootprints1(
        const D3D12_RESOURCE_DESC1* pResourceDesc,
        UINT FirstSubresource,
        UINT NumSubresources,
        UINT64 BaseOffset,
        D3D12_PLACED_SUBRESOURCE_FOOTPRINT* pLayouts,
        UINT* pNumRows,
        UINT64* pRowSizeInBytes,
        UINT64* pTotalBytes);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Device8* object_;
};

class ID3D12Resource1_Wrapper : public ID3D12Resource_Wrapper
{
  public:
    ID3D12Resource1_Wrapper(REFIID riid, ID3D12Resource1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Resource1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Resource1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetProtectedResourceSession(
        REFIID riid,
        void** ppProtectedSession);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Resource1* object_;
};

class ID3D12Resource2_Wrapper : public ID3D12Resource1_Wrapper
{
  public:
    ID3D12Resource2_Wrapper(REFIID riid, ID3D12Resource2* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Resource2_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Resource2** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual D3D12_RESOURCE_DESC1 STDMETHODCALLTYPE GetDesc1();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Resource2* object_;
};

class ID3D12Heap1_Wrapper : public ID3D12Heap_Wrapper
{
  public:
    ID3D12Heap1_Wrapper(REFIID riid, ID3D12Heap1* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Heap1_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Heap1** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE GetProtectedResourceSession(
        REFIID riid,
        void** ppProtectedSession);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Heap1* object_;
};

class ID3D12GraphicsCommandList3_Wrapper : public ID3D12GraphicsCommandList2_Wrapper
{
  public:
    ID3D12GraphicsCommandList3_Wrapper(REFIID riid, ID3D12GraphicsCommandList3* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList3_Wrapper*>(u); });

    void GetWrappedObject(ID3D12GraphicsCommandList3** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE SetProtectedResourceSession(
        ID3D12ProtectedResourceSession* pProtectedResourceSession);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12GraphicsCommandList3* object_;
};

class ID3D12MetaCommand_Wrapper : public ID3D12Pageable_Wrapper
{
  public:
    ID3D12MetaCommand_Wrapper(REFIID riid, ID3D12MetaCommand* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12MetaCommand_Wrapper*>(u); });

    void GetWrappedObject(ID3D12MetaCommand** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual UINT64 STDMETHODCALLTYPE GetRequiredParameterResourceSize(
        D3D12_META_COMMAND_PARAMETER_STAGE Stage,
        UINT ParameterIndex);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12MetaCommand* object_;
};

class ID3D12GraphicsCommandList4_Wrapper : public ID3D12GraphicsCommandList3_Wrapper
{
  public:
    ID3D12GraphicsCommandList4_Wrapper(REFIID riid, ID3D12GraphicsCommandList4* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList4_Wrapper*>(u); });

    void GetWrappedObject(ID3D12GraphicsCommandList4** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE BeginRenderPass(
        UINT NumRenderTargets,
        const D3D12_RENDER_PASS_RENDER_TARGET_DESC* pRenderTargets,
        const D3D12_RENDER_PASS_DEPTH_STENCIL_DESC* pDepthStencil,
        D3D12_RENDER_PASS_FLAGS Flags);

    virtual void STDMETHODCALLTYPE EndRenderPass();

    virtual void STDMETHODCALLTYPE InitializeMetaCommand(
        ID3D12MetaCommand* pMetaCommand,
        const void* pInitializationParametersData,
        SIZE_T InitializationParametersDataSizeInBytes);

    virtual void STDMETHODCALLTYPE ExecuteMetaCommand(
        ID3D12MetaCommand* pMetaCommand,
        const void* pExecutionParametersData,
        SIZE_T ExecutionParametersDataSizeInBytes);

    virtual void STDMETHODCALLTYPE BuildRaytracingAccelerationStructure(
        const D3D12_BUILD_RAYTRACING_ACCELERATION_STRUCTURE_DESC* pDesc,
        UINT NumPostbuildInfoDescs,
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pPostbuildInfoDescs);

    virtual void STDMETHODCALLTYPE EmitRaytracingAccelerationStructurePostbuildInfo(
        const D3D12_RAYTRACING_ACCELERATION_STRUCTURE_POSTBUILD_INFO_DESC* pDesc,
        UINT NumSourceAccelerationStructures,
        const D3D12_GPU_VIRTUAL_ADDRESS* pSourceAccelerationStructureData);

    virtual void STDMETHODCALLTYPE CopyRaytracingAccelerationStructure(
        D3D12_GPU_VIRTUAL_ADDRESS DestAccelerationStructureData,
        D3D12_GPU_VIRTUAL_ADDRESS SourceAccelerationStructureData,
        D3D12_RAYTRACING_ACCELERATION_STRUCTURE_COPY_MODE Mode);

    virtual void STDMETHODCALLTYPE SetPipelineState1(
        ID3D12StateObject* pStateObject);

    virtual void STDMETHODCALLTYPE DispatchRays(
        const D3D12_DISPATCH_RAYS_DESC* pDesc);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12GraphicsCommandList4* object_;
};

class ID3D12Tools_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D12Tools_Wrapper(REFIID riid, ID3D12Tools* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12Tools_Wrapper*>(u); });

    void GetWrappedObject(ID3D12Tools** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE EnableShaderInstrumentation(
        BOOL bEnable);

    virtual BOOL STDMETHODCALLTYPE ShaderInstrumentationEnabled();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12Tools* object_;
};

class ID3D12GraphicsCommandList5_Wrapper : public ID3D12GraphicsCommandList4_Wrapper
{
  public:
    ID3D12GraphicsCommandList5_Wrapper(REFIID riid, ID3D12GraphicsCommandList5* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList5_Wrapper*>(u); });

    void GetWrappedObject(ID3D12GraphicsCommandList5** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE RSSetShadingRate(
        D3D12_SHADING_RATE baseShadingRate,
        const D3D12_SHADING_RATE_COMBINER* combiners);

    virtual void STDMETHODCALLTYPE RSSetShadingRateImage(
        ID3D12Resource* shadingRateImage);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12GraphicsCommandList5* object_;
};

class ID3D12GraphicsCommandList6_Wrapper : public ID3D12GraphicsCommandList5_Wrapper
{
  public:
    ID3D12GraphicsCommandList6_Wrapper(REFIID riid, ID3D12GraphicsCommandList6* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D12GraphicsCommandList6_Wrapper*>(u); });

    void GetWrappedObject(ID3D12GraphicsCommandList6** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual void STDMETHODCALLTYPE DispatchMesh(
        UINT ThreadGroupCountX,
        UINT ThreadGroupCountY,
        UINT ThreadGroupCountZ);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D12GraphicsCommandList6* object_;
};


/*
** This part is generated from d3dcommon.h in Windows SDK: 10.0.19041.0
**
*/

class ID3D10Blob_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3D10Blob_Wrapper(REFIID riid, ID3D10Blob* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3D10Blob_Wrapper*>(u); });

    void GetWrappedObject(ID3D10Blob** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual LPVOID STDMETHODCALLTYPE GetBufferPointer();

    virtual SIZE_T STDMETHODCALLTYPE GetBufferSize();

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3D10Blob* object_;
};

class ID3DDestructionNotifier_Wrapper : public IUnknown_Wrapper
{
  public:
    ID3DDestructionNotifier_Wrapper(REFIID riid, ID3DDestructionNotifier* object, DxWrapperResources* resources = nullptr, const std::function<void(IUnknown_Wrapper*)>& destructor = [](IUnknown_Wrapper* u){ delete reinterpret_cast<ID3DDestructionNotifier_Wrapper*>(u); });

    void GetWrappedObject(ID3DDestructionNotifier** object) const { if (object != nullptr) { (*object) = object_; } }

    virtual HRESULT STDMETHODCALLTYPE RegisterDestructionCallback(
        PFN_DESTRUCTION_CALLBACK callbackFn,
        void* pData,
        UINT* pCallbackID);

    virtual HRESULT STDMETHODCALLTYPE UnregisterDestructionCallback(
        UINT callbackID);

  private:
    // Store a raw pointer to the wrapped object.
    // Only the IUnkown base class maintains a reference to the object.
    ID3DDestructionNotifier* object_;
};


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

#endif
