/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "encode/d3d12_dispatch_table.h"
#include "util/defines.h"
#include "util/file_path.h"
#include "util/platform.h"

#include <cassert>
#include <array>
#include <string>
#include <windows.h>

const wchar_t kLocalDllName[]   = L"dxgi.dll";
const wchar_t kSystemDllName[]  = L"dxgi_ms.dll";
const wchar_t kCaptureDllName[] = L"d3d12_capture.dll";

static HMODULE                             dxgi_dll    = nullptr;
static HMODULE                             capture_dll = nullptr;
static gfxrecon::encode::DxgiDispatchTable dispatch_table;

// Functions forwarded to the system DLL.
EXTERN_C FARPROC gfxrecon_ApplyCompatResolutionQuirking{ nullptr };
EXTERN_C FARPROC gfxrecon_CompatString{ nullptr };
EXTERN_C FARPROC gfxrecon_CompatValue{ nullptr };
EXTERN_C FARPROC gfxrecon_DXGID3D10CreateDevice{ nullptr };
EXTERN_C FARPROC gfxrecon_DXGID3D10CreateLayeredDevice{ nullptr };
EXTERN_C FARPROC gfxrecon_DXGID3D10GetLayeredDeviceSize{ nullptr };
EXTERN_C FARPROC gfxrecon_DXGID3D10RegisterLayers{ nullptr };
EXTERN_C FARPROC gfxrecon_DXGIDumpJournal{ nullptr };
EXTERN_C FARPROC gfxrecon_DXGIReportAdapterConfiguration{ nullptr };
EXTERN_C FARPROC gfxrecon_PIXBeginCapture{ nullptr };
EXTERN_C FARPROC gfxrecon_PIXEndCapture{ nullptr };
EXTERN_C FARPROC gfxrecon_PIXGetCaptureState{ nullptr };
EXTERN_C FARPROC gfxrecon_SetAppCompatStringPointer{ nullptr };
EXTERN_C FARPROC gfxrecon_UpdateHMDEmulationStatus{ nullptr };

EXTERN_C HRESULT WINAPI gfxrecon_CreateDXGIFactory(REFIID riid, void** ppFactory)
{
    return dispatch_table.create_dxgi_factory(riid, ppFactory);
}

EXTERN_C HRESULT WINAPI gfxrecon_CreateDXGIFactory1(REFIID riid, void** ppFactory)
{
    return dispatch_table.create_dxgi_factory1(riid, ppFactory);
}

EXTERN_C HRESULT WINAPI gfxrecon_CreateDXGIFactory2(UINT Flags, REFIID riid, void** ppFactory)
{
    return dispatch_table.create_dxgi_factory2(Flags, riid, ppFactory);
}

EXTERN_C HRESULT WINAPI gfxrecon_DXGIDeclareAdapterRemovalSupport()
{
    return dispatch_table.declare_adapter_removal_support();
}

EXTERN_C HRESULT WINAPI gfxrecon_DXGIGetDebugInterface1(UINT Flags, REFIID riid, void** ppDebug)
{
    return dispatch_table.get_debug_interface1(Flags, riid, ppDebug);
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

static bool IsCaptureEnabled()
{
    // TODO: Read environment variable.
    return false;
}

static bool IsSystemLibrary(HMODULE library)
{
    std::array<wchar_t, MAX_PATH> system_path{};

    auto length = GetSystemDirectoryW(system_path.data(), static_cast<uint32_t>(system_path.size()));
    if (length > 0)
    {
        std::array<wchar_t, MAX_PATH> library_path{};

        if (GetModuleFileNameW(library, library_path.data(), static_cast<uint32_t>(library_path.size())) > 0)
        {
            if (wcsncmp(system_path.data(), library_path.data(), length) == 0)
            {
                return true;
            }
        }
    }

    return false;
}

static HMODULE LoadSystemLibrary(const wchar_t* name)
{
    std::array<wchar_t, MAX_PATH> system_path{};
    HMODULE                       library = nullptr;

    auto length = GetSystemDirectoryW(system_path.data(), static_cast<uint32_t>(system_path.size()));
    if (length > 0)
    {
        std::wstring path = system_path.data();
        path += L"\\";
        path += name;
        library = LoadLibraryW(path.c_str());
    }

    return library;
}

static void LoadDxgiPassThroughProcs()
{
    assert(dxgi_dll != nullptr);

    gfxrecon_ApplyCompatResolutionQuirking  = GetProcAddress(dxgi_dll, "ApplyCompatResolutionQuirking");
    gfxrecon_CompatString                   = GetProcAddress(dxgi_dll, "CompatString");
    gfxrecon_CompatValue                    = GetProcAddress(dxgi_dll, "CompatValue");
    gfxrecon_DXGID3D10CreateDevice          = GetProcAddress(dxgi_dll, "DXGID3D10CreateDevice");
    gfxrecon_DXGID3D10CreateLayeredDevice   = GetProcAddress(dxgi_dll, "DXGID3D10CreateLayeredDevice");
    gfxrecon_DXGID3D10GetLayeredDeviceSize  = GetProcAddress(dxgi_dll, "DXGID3D10GetLayeredDeviceSize");
    gfxrecon_DXGID3D10RegisterLayers        = GetProcAddress(dxgi_dll, "DXGID3D10RegisterLayers");
    gfxrecon_DXGIDumpJournal                = GetProcAddress(dxgi_dll, "DXGIDumpJournal");
    gfxrecon_DXGIReportAdapterConfiguration = GetProcAddress(dxgi_dll, "DXGIReportAdapterConfiguration");
    gfxrecon_PIXBeginCapture                = GetProcAddress(dxgi_dll, "PIXBeginCapture");
    gfxrecon_PIXEndCapture                  = GetProcAddress(dxgi_dll, "PIXEndCapture");
    gfxrecon_PIXGetCaptureState             = GetProcAddress(dxgi_dll, "PIXGetCaptureState");
    gfxrecon_SetAppCompatStringPointer      = GetProcAddress(dxgi_dll, "SetAppCompatStringPointer");
    gfxrecon_UpdateHMDEmulationStatus       = GetProcAddress(dxgi_dll, "UpdateHMDEmulationStatus");
}

static void LoadDxgiCaptureProcs()
{
    assert(dxgi_dll != nullptr);

    dispatch_table.create_dxgi_factory =
        reinterpret_cast<decltype(CreateDXGIFactory)*>(GetProcAddress(dxgi_dll, "CreateDXGIFactory"));
    dispatch_table.create_dxgi_factory1 =
        reinterpret_cast<decltype(CreateDXGIFactory1)*>(GetProcAddress(dxgi_dll, "CreateDXGIFactory1"));
    dispatch_table.create_dxgi_factory2 =
        reinterpret_cast<decltype(CreateDXGIFactory2)*>(GetProcAddress(dxgi_dll, "CreateDXGIFactory2"));
    dispatch_table.declare_adapter_removal_support = reinterpret_cast<decltype(DXGIDeclareAdapterRemovalSupport)*>(
        GetProcAddress(dxgi_dll, "DXGIDeclareAdapterRemovalSupport"));
    dispatch_table.get_debug_interface1 =
        reinterpret_cast<decltype(DXGIGetDebugInterface1)*>(GetProcAddress(dxgi_dll, "DXGIGetDebugInterface1"));
}

static BOOL Initialize(HINSTANCE instance)
{
    if (dxgi_dll == nullptr)
    {
        auto dll_name = kLocalDllName;

        if (IsSystemLibrary(instance))
        {
            // If the current capture dxgi.dll is in the system folder, the real dxgi.dll must have been renamed.
            dll_name = kSystemDllName;
        }

        dxgi_dll = LoadSystemLibrary(dll_name);

        if (dxgi_dll != nullptr)
        {
            LoadDxgiPassThroughProcs();
            LoadDxgiCaptureProcs();

            if (IsCaptureEnabled() && capture_dll == nullptr)
            {
                capture_dll = LoadLibraryW(kCaptureDllName);
                if (capture_dll != nullptr)
                {
                    auto init_func = reinterpret_cast<PFN_InitializeDxgiCapture>(
                        GetProcAddress(capture_dll, "InitializeDxgiCapture"));

                    if (init_func != nullptr)
                    {
                        init_func(&dispatch_table);
                    }
                }
                else
                {
                    OutputDebugStringA(
                        "GFXRECON: Failed to load GFXReconstruct capture DLL for dxgi.dll initialization");
                    OutputDebugStringA("GFXRECON: GFXReconstruct capture will be disabled");
                }
            }
        }
        else
        {
            OutputDebugStringA("GFXRECON: Failed to load system DLL for dxgi.dll initialization");
            return FALSE;
        }
    }

    return TRUE;
}

static void Destroy()
{
    if (capture_dll != nullptr)
    {
        auto release_func = reinterpret_cast<PFN_ReleaseDxgiCapture>(GetProcAddress(capture_dll, "ReleaseDxgiCapture"));

        if (release_func != nullptr)
        {
            release_func(&dispatch_table);
        }

        FreeLibrary(capture_dll);
        capture_dll = nullptr;
    }

    if (dxgi_dll != nullptr)
    {
        FreeLibrary(dxgi_dll);
        dxgi_dll = nullptr;
    }
}

GFXRECON_END_NAMESPACE(gfxrecon)

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL success = TRUE;

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            success = gfxrecon::Initialize(hinstDLL);
            break;
        case DLL_PROCESS_DETACH:
            if (lpvReserved == nullptr)
            {
                gfxrecon::Destroy();
            }
            break;
    }

    return success;
}
