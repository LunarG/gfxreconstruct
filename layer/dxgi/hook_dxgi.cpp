/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#include "hook_dxgi.h"

#include <string>

static Hook_DXGI* dxgi_hook_ = nullptr;

typedef int (*pFuncPtr)(void);

HRESULT WINAPI Mine_CreateDXGIFactory(const IID& riid, void** ppFactory)
{
    HRESULT result = S_FALSE;

    Hook_DXGI::GetInterceptor()->hook_CreateDXGIFactory_.real_hook_(riid, ppFactory);

    return result;
}

HRESULT WINAPI Mine_CreateDXGIFactory1(const IID& riid, void** ppFactory)
{
    HRESULT result = S_FALSE;

    result = Hook_DXGI::GetInterceptor()->hook_CreateDXGIFactory1_.real_hook_(riid, ppFactory);

    return result;
}

HRESULT WINAPI Mine_CreateDXGIFactory2(UINT Flags, const IID& riid, void** ppFactory)
{
    HRESULT result = S_FALSE;

    result = Hook_DXGI::GetInterceptor()->hook_CreateDXGIFactory2_.real_hook_(Flags, riid, ppFactory);

    return result;
}

HRESULT WINAPI Mine_DXGIDeclareAdapterRemovalSupport()
{
    HRESULT result = S_FALSE;

    result = Hook_DXGI::GetInterceptor()->hook_DXGIDeclareAdapterRemovalSupport_.real_hook_();

    return result;
}

HRESULT WINAPI Mine_DXGIGetDebugInterface1(UINT Flags, const IID& riid, void** pDebug)
{
    HRESULT result = S_FALSE;

    result = Hook_DXGI::GetInterceptor()->hook_DXGIGetDebugInterface1_.real_hook_(Flags, riid, pDebug);

    return result;
}

HRESULT WINAPI Mine_DXGID3D10CreateDevice(
    HMODULE d3d10core, IDXGIFactory* factory, IDXGIAdapter* adapter, UINT flags, DWORD arg5, void** device)
{
    HRESULT result = S_FALSE;

    result = Hook_DXGI::GetInterceptor()->hook_DXGID3D10CreateDevice_.real_hook_(
        d3d10core, factory, adapter, flags, arg5, device);

    return result;
}

HRESULT WINAPI CreateDXGIFactory(const IID& riid, void** ppFactory)
{
    return Mine_CreateDXGIFactory(riid, ppFactory);
}

HRESULT WINAPI CreateDXGIFactory1(const IID& riid, void** ppFactory)
{
    return Mine_CreateDXGIFactory1(riid, ppFactory);
}

HRESULT WINAPI CreateDXGIFactory2(UINT Flags, const IID& riid, void** ppFactory)
{
    return Mine_CreateDXGIFactory2(Flags, riid, ppFactory);
}

HRESULT WINAPI DXGIDeclareAdapterRemovalSupport()
{
    return Mine_DXGIDeclareAdapterRemovalSupport();
}

HRESULT WINAPI DXGIGetDebugInterface1(UINT Flags, const IID& riid, void** pDebug)
{
    return Mine_DXGIGetDebugInterface1(Flags, riid, pDebug);
}

HRESULT WINAPI DXGID3D10CreateDevice(
    HMODULE d3d10core, IDXGIFactory* factory, IDXGIAdapter* adapter, UINT flags, DWORD arg5, void** device)
{
    return Mine_DXGID3D10CreateDevice(d3d10core, factory, adapter, flags, arg5, device);
}

//-----------------------------------------------------------------------------
/// Get unique instance of Hook_DXGI
//-----------------------------------------------------------------------------
Hook_DXGI* Hook_DXGI::GetInterceptor()
{
    if (dxgi_hook_ == nullptr)
    {
        dxgi_hook_ = new Hook_DXGI();
    }

    return dxgi_hook_;
}

//-----------------------------------------------------------------------------
/// Attach API entry points for hooking.
/// \return True if entry points were successfully hooked.
//-----------------------------------------------------------------------------
bool Hook_DXGI::HookInterceptor()
{
    bool success = false;

    HMODULE module_handle = ::LoadLibraryA("dxgi.dll");

    if (module_handle != nullptr)
    {
        Hook_DXGI* pInterceptor = GetInterceptor();

        if (pInterceptor != nullptr)
        {
            bool attachSuccess = false;

            pFuncPtr CreateDXGIFactory_funcPtr = (pFuncPtr)(::GetProcAddress(module_handle, "CreateDXGIFactory"));
            if (CreateDXGIFactory_funcPtr != nullptr)
            {
                pInterceptor->hook_CreateDXGIFactory_.SetHooks((PFN_CREATEDXGIFACTORY)CreateDXGIFactory_funcPtr,
                                                               Mine_CreateDXGIFactory);
                attachSuccess = pInterceptor->hook_CreateDXGIFactory_.Attach();
            }

            pFuncPtr CreateDXGIFactory1_funcPtr = (pFuncPtr)(::GetProcAddress(module_handle, "CreateDXGIFactory1"));
            if (CreateDXGIFactory1_funcPtr != nullptr)
            {
                pInterceptor->hook_CreateDXGIFactory1_.SetHooks((PFN_CREATEDXGIFACTORY1)CreateDXGIFactory1_funcPtr,
                                                                Mine_CreateDXGIFactory1);
                attachSuccess = pInterceptor->hook_CreateDXGIFactory1_.Attach();
            }

            pFuncPtr CreateDXGIFactory2_funcPtr = (pFuncPtr)(::GetProcAddress(module_handle, "CreateDXGIFactory2"));
            if (CreateDXGIFactory2_funcPtr != nullptr)
            {
                pInterceptor->hook_CreateDXGIFactory2_.SetHooks((PFN_CREATEDXGIFACTORY2)CreateDXGIFactory2_funcPtr,
                                                                Mine_CreateDXGIFactory2);
                attachSuccess = pInterceptor->hook_CreateDXGIFactory2_.Attach();
            }

            pFuncPtr DXGIDeclareAdapterRemovalSupport_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "DXGIDeclareAdapterRemovalSupport"));
            if (DXGIDeclareAdapterRemovalSupport_funcPtr != nullptr)
            {
                pInterceptor->hook_DXGIDeclareAdapterRemovalSupport_.SetHooks(
                    (PFN_DXGIDECLAREADAPTERREMOVALSUPPORT)DXGIDeclareAdapterRemovalSupport_funcPtr,
                    Mine_DXGIDeclareAdapterRemovalSupport);
                attachSuccess = pInterceptor->hook_DXGIDeclareAdapterRemovalSupport_.Attach();
            }

            pFuncPtr DXGIGetDebugInterface1_funcPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "DXGIGetDebugInterface1"));
            if (DXGIGetDebugInterface1_funcPtr != nullptr)
            {
                pInterceptor->hook_DXGIGetDebugInterface1_.SetHooks(
                    (PFN_DXGIGETDEBUGINTERFACE1)DXGIGetDebugInterface1_funcPtr, Mine_DXGIGetDebugInterface1);
                attachSuccess = pInterceptor->hook_DXGIGetDebugInterface1_.Attach();
            }

            pFuncPtr DXGID3D10CreateDevice_FuncPtr =
                (pFuncPtr)(::GetProcAddress(module_handle, "DXGID3D10CreateDevice"));
            if (DXGID3D10CreateDevice_FuncPtr != nullptr)
            {
                pInterceptor->hook_DXGID3D10CreateDevice_.SetHooks(
                    (PFN_DXGID3D10CREATEDEVICE)DXGID3D10CreateDevice_FuncPtr, Mine_DXGID3D10CreateDevice);
                attachSuccess = pInterceptor->hook_DXGID3D10CreateDevice_.Attach();
            }

            success = true;
        }
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Detach all hooked API entry points.
/// \return True if entry points were successfully detached.
//-----------------------------------------------------------------------------
bool Hook_DXGI::UnhookInterceptor()
{
    bool success = false;

    Hook_DXGI* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        pInterceptor->hook_CreateDXGIFactory_.Detach();
        pInterceptor->hook_CreateDXGIFactory1_.Detach();
        pInterceptor->hook_CreateDXGIFactory2_.Detach();
        pInterceptor->hook_DXGIDeclareAdapterRemovalSupport_.Detach();
        pInterceptor->hook_DXGIGetDebugInterface1_.Detach();
        pInterceptor->hook_DXGID3D10CreateDevice_.Detach();

        success = true;
    }

    return success;
}
