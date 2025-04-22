/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Technologies, Inc. and/or its subsidiaries.
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

#include "encode/d3d11_dispatch_table.h"
#include "encode/dx12_dll_initializer.h"
#include "util/defines.h"
#include "util/file_path.h"
#include "util/platform.h"
#include "hook_d3d11.h"

#include <cassert>
#include <array>
#include <mutex>
#include <string>
#include <windows.h>

const char kSystemDllName[]             = "d3d11.dll";
const char kSystemDllNameRenamed[]      = "d3d11_ms.dll";
const char kCaptureDllName[]            = "d3d12_capture.dll";
const char kCaptureDllInitProcName[]    = "InitializeD3D11Capture";
const char kCaptureDllDestroyProcName[] = "ReleaseD3D11Capture";

static HINSTANCE                                                                dll_instance;
static gfxrecon::encode::DxDllInitializer<gfxrecon::encode::D3D11DispatchTable> dll_initializer;

inline const gfxrecon::encode::D3D11DispatchTable& GetDispatchTable()
{
    return dll_initializer.GetDispatchTable();
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

static void LoadD3D11CaptureProcs(HMODULE system_dll, encode::D3D11DispatchTable* dispatch_table)
{
    if (system_dll != nullptr && dispatch_table != nullptr)
    {
        dispatch_table->D3D11CreateDevice =
            reinterpret_cast<PFN_D3D11_CREATE_DEVICE>(GetProcAddress(system_dll, "D3D11CreateDevice"));
        dispatch_table->D3D11CreateDeviceAndSwapChain = reinterpret_cast<PFN_D3D11_CREATE_DEVICE_AND_SWAP_CHAIN>(
            GetProcAddress(system_dll, "D3D11CreateDeviceAndSwapChain"));
        dispatch_table->D3D11On12CreateDevice =
            reinterpret_cast<PFN_D3D11ON12_CREATE_DEVICE>(GetProcAddress(system_dll, "D3D11On12CreateDevice"));
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
            std::string module_path =
                gfxrecon::encode::SetupCaptureModule(dll_instance, kSystemDllName, kSystemDllNameRenamed, nullptr);

            initialized = dll_initializer.Initialize(
                module_path.c_str(), kCaptureDllName, kCaptureDllInitProcName, LoadD3D11CaptureProcs);
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
        Hook_D3D11::HookInterceptor(dll_initializer.IsCaptureEnabled());
        hooked = true;
    }
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D11CreateDevice(IDXGIAdapter*            pAdapter,
                                                   D3D_DRIVER_TYPE          DriverType,
                                                   HMODULE                  Software,
                                                   UINT                     Flags,
                                                   const D3D_FEATURE_LEVEL* pFeatureLevels,
                                                   UINT                     FeatureLevels,
                                                   UINT                     SDKVersion,
                                                   ID3D11Device**           ppDevice,
                                                   D3D_FEATURE_LEVEL*       pFeatureLevel,
                                                   ID3D11DeviceContext**    ppImmediateContext)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D11CreateDevice(pAdapter,
                                                    DriverType,
                                                    Software,
                                                    Flags,
                                                    pFeatureLevels,
                                                    FeatureLevels,
                                                    SDKVersion,
                                                    ppDevice,
                                                    pFeatureLevel,
                                                    ppImmediateContext);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D11CreateDeviceAndSwapChain(IDXGIAdapter*               pAdapter,
                                                               D3D_DRIVER_TYPE             DriverType,
                                                               HMODULE                     Software,
                                                               UINT                        Flags,
                                                               const D3D_FEATURE_LEVEL*    pFeatureLevels,
                                                               UINT                        FeatureLevels,
                                                               UINT                        SDKVersion,
                                                               const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
                                                               IDXGISwapChain**            ppSwapChain,
                                                               ID3D11Device**              ppDevice,
                                                               D3D_FEATURE_LEVEL*          pFeatureLevel,
                                                               ID3D11DeviceContext**       ppImmediateContext)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D11CreateDeviceAndSwapChain(pAdapter,
                                                                DriverType,
                                                                Software,
                                                                Flags,
                                                                pFeatureLevels,
                                                                FeatureLevels,
                                                                SDKVersion,
                                                                pSwapChainDesc,
                                                                ppSwapChain,
                                                                ppDevice,
                                                                pFeatureLevel,
                                                                ppImmediateContext);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D11On12CreateDevice(IUnknown*                pDevice,
                                                       UINT                     Flags,
                                                       const D3D_FEATURE_LEVEL* pFeatureLevels,
                                                       UINT                     FeatureLevels,
                                                       IUnknown* const*         ppCommandQueues,
                                                       UINT                     NumQueues,
                                                       UINT                     NodeMask,
                                                       ID3D11Device**           ppDevice,
                                                       ID3D11DeviceContext**    ppImmediateContext,
                                                       D3D_FEATURE_LEVEL*       pChosenFeatureLevel)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D11On12CreateDevice(pDevice,
                                                        Flags,
                                                        pFeatureLevels,
                                                        FeatureLevels,
                                                        ppCommandQueues,
                                                        NumQueues,
                                                        NodeMask,
                                                        ppDevice,
                                                        ppImmediateContext,
                                                        pChosenFeatureLevel);
    }

    return E_FAIL;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            dll_instance = hinstDLL;
            break;
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
