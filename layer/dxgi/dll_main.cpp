/*
** Copyright (c) 2023 LunarG, Inc.
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

#include "encode/dx12_dll_initializer.h"
#include "encode/dxgi_dispatch_table.h"
#include "util/defines.h"
#include "util/file_path.h"
#include "util/platform.h"
#include "hook_dxgi.h"

#include <cassert>
#include <array>
#include <mutex>
#include <string>
#include <windows.h>

const char kSystemDllName[]             = "dxgi.dll";
const char kSystemDllNameRenamed[]      = "dxgi_ms.dll";
const char kCaptureDllName[]            = "d3d12_capture.dll";
const char kCaptureDllInitProcName[]    = "InitializeDxgiCapture";
const char kCaptureDllDestroyProcName[] = "ReleaseDxgiCapture";

static gfxrecon::encode::DxDllInitializer<gfxrecon::encode::DxgiDispatchTable> dll_initializer;

inline const gfxrecon::encode::DxgiDispatchTable& GetDispatchTable()
{
    return dll_initializer.GetDispatchTable();
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

static void LoadDxgiCaptureProcs(HMODULE system_dll, encode::DxgiDispatchTable* dispatch_table)
{
    if (system_dll != nullptr && dispatch_table != nullptr)
    {
        dispatch_table->CreateDXGIFactory =
            reinterpret_cast<decltype(CreateDXGIFactory)*>(GetProcAddress(system_dll, "CreateDXGIFactory"));
        dispatch_table->CreateDXGIFactory1 =
            reinterpret_cast<decltype(CreateDXGIFactory1)*>(GetProcAddress(system_dll, "CreateDXGIFactory1"));
        dispatch_table->CreateDXGIFactory2 =
            reinterpret_cast<decltype(CreateDXGIFactory2)*>(GetProcAddress(system_dll, "CreateDXGIFactory2"));
        dispatch_table->DXGIDeclareAdapterRemovalSupport =
            reinterpret_cast<decltype(DXGIDeclareAdapterRemovalSupport)*>(
                GetProcAddress(system_dll, "DXGIDeclareAdapterRemovalSupport"));
        dispatch_table->DXGIGetDebugInterface1 =
            reinterpret_cast<decltype(DXGIGetDebugInterface1)*>(GetProcAddress(system_dll, "DXGIGetDebugInterface1"));
    }
}

static bool Initialize()
{
    static bool       initialized = false;
    static std::mutex initialization_mutex;

    // Check `initialized` before locking to avoid locking unnecessarily.
    if (initialized == false)
    {
        std::unique_lock<std::mutex> initialization_lock(initialization_mutex);
        if (initialized == false)
        {
            std::string module_path = gfxrecon::encode::SetupCaptureModule(kSystemDllName, kSystemDllNameRenamed);

            initialized = dll_initializer.Initialize(
                module_path.c_str(), kCaptureDllName, kCaptureDllInitProcName, LoadDxgiCaptureProcs);
        }
    }

    return initialized;
}

static void Destroy()
{
    dll_initializer.Destroy(kCaptureDllDestroyProcName);
}

GFXRECON_END_NAMESPACE(gfxrecon)

extern "C" __declspec(dllexport) void UpdateHooks()
{
    static bool hooked = false;

    if (hooked == false)
    {
        Hook_DXGI::HookInterceptor(dll_initializer.IsCaptureEnabled());
        hooked = true;
    }
}

EXTERN_C HRESULT WINAPI gfxrecon_CreateDXGIFactory(REFIID riid, void** ppFactory)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().CreateDXGIFactory(riid, ppFactory);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_CreateDXGIFactory1(REFIID riid, void** ppFactory)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().CreateDXGIFactory1(riid, ppFactory);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_CreateDXGIFactory2(UINT Flags, REFIID riid, void** ppFactory)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().CreateDXGIFactory2(Flags, riid, ppFactory);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_DXGIDeclareAdapterRemovalSupport()
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().DXGIDeclareAdapterRemovalSupport();
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_DXGIGetDebugInterface1(UINT Flags, REFIID riid, void** ppDebug)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().DXGIGetDebugInterface1(Flags, riid, ppDebug);
    }

    return E_FAIL;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_DETACH:
            // Only cleanup if the process is not exiting.
            if (lpvReserved == nullptr)
            {
                gfxrecon::Destroy();
            }
            break;
        default:
            break;
    }

    return TRUE;
}
