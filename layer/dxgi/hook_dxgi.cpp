/*
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "util/file_path.h"
#include "util/interception/interception_util.h"

// Static data required for hook management
static DxgiHookInfo hook_info_ = {};

HRESULT WINAPI Mine_CreateDXGIFactory(const IID& riid, void** ppFactory)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.CreateDXGIFactory(riid, ppFactory);

    return result;
}

HRESULT WINAPI Mine_CreateDXGIFactory1(const IID& riid, void** ppFactory)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.CreateDXGIFactory1(riid, ppFactory);

    return result;
}

HRESULT WINAPI Mine_CreateDXGIFactory2(UINT Flags, const IID& riid, void** ppFactory)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.CreateDXGIFactory2(Flags, riid, ppFactory);

    return result;
}

HRESULT WINAPI Mine_DXGIDeclareAdapterRemovalSupport()
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.DXGIDeclareAdapterRemovalSupport();

    return result;
}

HRESULT WINAPI Mine_DXGIGetDebugInterface1(UINT Flags, const IID& riid, void** pDebug)
{
    HRESULT result = S_FALSE;

    result = hook_info_.dispatch_table.DXGIGetDebugInterface1(Flags, riid, pDebug);

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

//----------------------------------------------------------------------------
/// Fill in a dispatch table with function addresses obtained from dxgi.dll
///
/// \param  dxgi_module Output dispatch table.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetDxgiDispatchTable(gfxrecon::encode::DxgiDispatchTable& dxgi_table)
{
    std::string library_base_path = "";

    bool success = gfxrecon::util::filepath::GetWindowsSystemLibrariesPath(library_base_path);

    if (success == true)
    {
        std::string library_path = library_base_path + "\\dxgi.dll";

        hook_info_.dxgi_dll = LoadLibraryA(library_path.c_str());

        if (hook_info_.dxgi_dll != nullptr)
        {
            dxgi_table.CreateDXGIFactory =
                reinterpret_cast<PFN_CREATEDXGIFACTORY>(GetProcAddress(hook_info_.dxgi_dll, "CreateDXGIFactory"));

            dxgi_table.CreateDXGIFactory1 =
                reinterpret_cast<PFN_CREATEDXGIFACTORY1>(GetProcAddress(hook_info_.dxgi_dll, "CreateDXGIFactory1"));

            dxgi_table.CreateDXGIFactory2 =
                reinterpret_cast<PFN_CREATEDXGIFACTORY2>(GetProcAddress(hook_info_.dxgi_dll, "CreateDXGIFactory2"));

            dxgi_table.DXGIDeclareAdapterRemovalSupport = reinterpret_cast<PFN_DXGIDECLAREADAPTERREMOVALSUPPORT>(
                GetProcAddress(hook_info_.dxgi_dll, "DXGIDeclareAdapterRemovalSupport"));

            dxgi_table.DXGIGetDebugInterface1 = reinterpret_cast<PFN_DXGIGETDEBUGINTERFACE1>(
                GetProcAddress(hook_info_.dxgi_dll, "DXGIGetDebugInterface1"));

            success = true;
        }
    }

    return success;
}

//----------------------------------------------------------------------------
/// Given a dxgi dispatch table, perform hooking and write out the final
/// dispatch table that will be called by intercepted entry points.
///
/// \param  dxgi_table  Incoming dispatch table with entry function addresses
///                     in dxgi.
///
/// \param  gpu_table Outgoing dispatch table with hooked entry points that
///                   will either go to the GPU or capture layer.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetDxgiDispatchTableHooked(gfxrecon::encode::DxgiDispatchTable  dxgi_table,
                                gfxrecon::encode::DxgiDispatchTable& gpu_table)
{
    bool success = false;

    Hook_DXGI* pInterceptor = Hook_DXGI::GetInterceptor();

    if (pInterceptor != nullptr)
    {
        bool attach_success = false;

        if (dxgi_table.CreateDXGIFactory != nullptr)
        {
            pInterceptor->hook_CreateDXGIFactory_.SetHooks(dxgi_table.CreateDXGIFactory, Mine_CreateDXGIFactory);
            attach_success = pInterceptor->hook_CreateDXGIFactory_.Attach();

            gpu_table.CreateDXGIFactory = pInterceptor->hook_CreateDXGIFactory_.real_hook_;
        }

        if (dxgi_table.CreateDXGIFactory1 != nullptr)
        {
            pInterceptor->hook_CreateDXGIFactory1_.SetHooks(dxgi_table.CreateDXGIFactory1, Mine_CreateDXGIFactory1);
            attach_success = pInterceptor->hook_CreateDXGIFactory1_.Attach();

            gpu_table.CreateDXGIFactory1 = pInterceptor->hook_CreateDXGIFactory1_.real_hook_;
        }

        if (dxgi_table.CreateDXGIFactory2 != nullptr)
        {
            pInterceptor->hook_CreateDXGIFactory2_.SetHooks(dxgi_table.CreateDXGIFactory2, Mine_CreateDXGIFactory2);
            attach_success = pInterceptor->hook_CreateDXGIFactory2_.Attach();

            gpu_table.CreateDXGIFactory2 = pInterceptor->hook_CreateDXGIFactory2_.real_hook_;
        }

        if (dxgi_table.DXGIDeclareAdapterRemovalSupport != nullptr)
        {
            pInterceptor->hook_DXGIDeclareAdapterRemovalSupport_.SetHooks(dxgi_table.DXGIDeclareAdapterRemovalSupport,
                                                                          Mine_DXGIDeclareAdapterRemovalSupport);
            attach_success = pInterceptor->hook_DXGIDeclareAdapterRemovalSupport_.Attach();

            gpu_table.DXGIDeclareAdapterRemovalSupport =
                pInterceptor->hook_DXGIDeclareAdapterRemovalSupport_.real_hook_;
        }

        if (dxgi_table.DXGIGetDebugInterface1 != nullptr)
        {
            pInterceptor->hook_DXGIGetDebugInterface1_.SetHooks(dxgi_table.DXGIGetDebugInterface1,
                                                                Mine_DXGIGetDebugInterface1);
            attach_success = pInterceptor->hook_DXGIGetDebugInterface1_.Attach();

            gpu_table.DXGIGetDebugInterface1 = pInterceptor->hook_DXGIGetDebugInterface1_.real_hook_;
        }

        success = true;
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Get unique instance of Hook_DXGI
//-----------------------------------------------------------------------------
Hook_DXGI* Hook_DXGI::GetInterceptor()
{
    if (hook_info_.interceptor == nullptr)
    {
        hook_info_.interceptor = new Hook_DXGI();
    }

    return hook_info_.interceptor;
}

//-----------------------------------------------------------------------------
/// Attach API entry points for hooking.
///
/// \param capture Whether capture is enabled
///
/// \return True if entry points were successfully hooked.
//-----------------------------------------------------------------------------
bool Hook_DXGI::HookInterceptor(bool capture)
{
    bool success = false;

    Hook_DXGI* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        gfxrecon::encode::DxgiDispatchTable dispatch_table_dxgi = {};

        success = GetDxgiDispatchTable(dispatch_table_dxgi);

        if (success == true)
        {
            success = GetDxgiDispatchTableHooked(dispatch_table_dxgi, hook_info_.dispatch_table);

            if (success == true)
            {
                if (capture == true)
                {
                    if (hook_info_.capture_dll == nullptr)
                    {
                        const std::string gfxr_d3d12_capture_path = gfxrecon::util::interception::CaptureLibPath();

                        hook_info_.capture_dll = gfxrecon::util::platform::OpenLibrary(gfxr_d3d12_capture_path.c_str());

                        if (hook_info_.capture_dll != nullptr)
                        {
                            auto init_func = reinterpret_cast<PFN_InitializeDxgiCapture>(
                                GetProcAddress(hook_info_.capture_dll, "InitializeDxgiCapture"));

                            if (init_func != nullptr)
                            {
                                init_func(&hook_info_.dispatch_table);
                            }
                        }
                    }
                }
            }
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
