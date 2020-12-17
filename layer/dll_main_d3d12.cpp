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
#include <wchar.h>
#include <windows.h>

const wchar_t kLocalDllName[]   = L"d3d12.dll";
const wchar_t kSystemDllName[]  = L"d3d12_ms.dll";
const wchar_t kCaptureDllName[] = L"d3d12_capture.dll";

static HMODULE                              d3d12_dll   = nullptr;
static HMODULE                              capture_dll = nullptr;
static gfxrecon::encode::D3D12DispatchTable dispatch_table;

// Functions forwarded to the system DLL.
EXTERN_C FARPROC gfxrecon_D3D12CoreCreateLayeredDevice{ nullptr };
EXTERN_C FARPROC gfxrecon_D3D12CoreGetLayeredDeviceSize{ nullptr };
EXTERN_C FARPROC gfxrecon_D3D12CoreRegisterLayers{ nullptr };
EXTERN_C FARPROC gfxrecon_D3D12DeviceRemovedExtendedData{ nullptr };
EXTERN_C FARPROC gfxrecon_D3D12PIXEventsReplaceBlock{ nullptr };
EXTERN_C FARPROC gfxrecon_D3D12PIXGetThreadInfo{ nullptr };
EXTERN_C FARPROC gfxrecon_D3D12PIXNotifyWakeFromFenceSignal{ nullptr };
EXTERN_C FARPROC gfxrecon_D3D12PIXReportCounter{ nullptr };
EXTERN_C FARPROC gfxrecon_GetBehaviorValue{ nullptr };
EXTERN_C FARPROC gfxrecon_SetAppCompatStringPointer{ nullptr };

EXTERN_C HRESULT WINAPI gfxrecon_D3D12CreateDevice(IUnknown*         pAdapter,
                                                   D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                                   REFIID            riid,
                                                   void**            ppDevice)
{
    return dispatch_table.create_device(pAdapter, MinimumFeatureLevel, riid, ppDevice);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12CreateRootSignatureDeserializer(LPCVOID pSrcData,
                                                                      SIZE_T  SrcDataSizeInBytes,
                                                                      REFIID  pRootSignatureDeserializerInterface,
                                                                      void**  ppRootSignatureDeserializer)
{
    return dispatch_table.create_root_signature_deserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

EXTERN_C HRESULT WINAPI
                 gfxrecon_D3D12CreateVersionedRootSignatureDeserializer(LPCVOID pSrcData,
                                                                        SIZE_T  SrcDataSizeInBytes,
                                                                        REFIID  pRootSignatureDeserializerInterface,
                                                                        void**  ppRootSignatureDeserializer)
{
    return dispatch_table.create_versioned_root_signature_deserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12GetDebugInterface(REFIID riid, void** ppvDebug)
{
    return dispatch_table.get_debug_interface(riid, ppvDebug);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
                                                             D3D_ROOT_SIGNATURE_VERSION       Version,
                                                             ID3DBlob**                       ppBlob,
                                                             ID3DBlob**                       ppErrorBlob)
{
    return dispatch_table.serialize_root_signature(pRootSignature, Version, ppBlob, ppErrorBlob);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature, ID3DBlob** ppBlob, ID3DBlob** ppErrorBlob)
{
    return dispatch_table.serialize_versioned_root_signature(pRootSignature, ppBlob, ppErrorBlob);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12EnableExperimentalFeatures(UINT       NumFeatures,
                                                                 const IID* pIIDs,
                                                                 void*      pConfigurationStructs,
                                                                 UINT*      pConfigurationStructSizes)
{
    return dispatch_table.enable_experiemental_features(
        NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes);
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
    assert(d3d12_dll != nullptr);

    gfxrecon_D3D12CoreCreateLayeredDevice      = GetProcAddress(d3d12_dll, "D3D12CoreCreateLayeredDevice");
    gfxrecon_D3D12CoreGetLayeredDeviceSize     = GetProcAddress(d3d12_dll, "D3D12CoreGetLayeredDeviceSize");
    gfxrecon_D3D12CoreRegisterLayers           = GetProcAddress(d3d12_dll, "D3D12CoreRegisterLayers");
    gfxrecon_D3D12DeviceRemovedExtendedData    = GetProcAddress(d3d12_dll, "D3D12DeviceRemovedExtendedData");
    gfxrecon_D3D12PIXEventsReplaceBlock        = GetProcAddress(d3d12_dll, "D3D12PIXEventsReplaceBlock");
    gfxrecon_D3D12PIXGetThreadInfo             = GetProcAddress(d3d12_dll, "D3D12PIXGetThreadInfo");
    gfxrecon_D3D12PIXNotifyWakeFromFenceSignal = GetProcAddress(d3d12_dll, "D3D12PIXNotifyWakeFromFenceSignal");
    gfxrecon_D3D12PIXReportCounter             = GetProcAddress(d3d12_dll, "D3D12PIXReportCounter");
    gfxrecon_GetBehaviorValue                  = GetProcAddress(d3d12_dll, "GetBehaviorValue");
    gfxrecon_SetAppCompatStringPointer         = GetProcAddress(d3d12_dll, "SetAppCompatStringPointer");
}

static void LoadDxgiCaptureProcs()
{
    assert(d3d12_dll != nullptr);

    dispatch_table.create_device =
        reinterpret_cast<PFN_D3D12_CREATE_DEVICE>(GetProcAddress(d3d12_dll, "D3D12CreateDevice"));
    dispatch_table.create_root_signature_deserializer = reinterpret_cast<PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER>(
        GetProcAddress(d3d12_dll, "D3D12CreateRootSignatureDeserializer"));
    dispatch_table.create_versioned_root_signature_deserializer =
        reinterpret_cast<PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER>(
            GetProcAddress(d3d12_dll, "D3D12CreateVersionedRootSignatureDeserializer"));
    dispatch_table.get_debug_interface =
        reinterpret_cast<PFN_D3D12_GET_DEBUG_INTERFACE>(GetProcAddress(d3d12_dll, "D3D12GetDebugInterface"));
    dispatch_table.serialize_root_signature =
        reinterpret_cast<PFN_D3D12_SERIALIZE_ROOT_SIGNATURE>(GetProcAddress(d3d12_dll, "D3D12SerializeRootSignature"));
    dispatch_table.serialize_versioned_root_signature = reinterpret_cast<PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE>(
        GetProcAddress(d3d12_dll, "D3D12SerializeVersionedRootSignature"));
    dispatch_table.enable_experiemental_features = reinterpret_cast<decltype(D3D12EnableExperimentalFeatures)*>(
        GetProcAddress(d3d12_dll, "D3D12EnableExperimentalFeatures"));
}

static BOOL Initialize(HINSTANCE instance)
{
    if (d3d12_dll == nullptr)
    {
        auto dll_name = kLocalDllName;

        if (IsSystemLibrary(instance))
        {
            // If the current capture d3d12.dll is in the system folder, the real d3d12.dll must have been renamed.
            dll_name = kSystemDllName;
        }

        d3d12_dll = LoadSystemLibrary(dll_name);

        if (d3d12_dll != nullptr)
        {
            LoadDxgiPassThroughProcs();
            LoadDxgiCaptureProcs();

            if (IsCaptureEnabled() && capture_dll == nullptr)
            {
                capture_dll = LoadLibraryW(kCaptureDllName);
                if (capture_dll != nullptr)
                {
                    auto init_func = reinterpret_cast<PFN_InitializeD3D12Capture>(
                        GetProcAddress(capture_dll, "InitializeD3D12Capture"));

                    if (init_func != nullptr)
                    {
                        init_func(&dispatch_table);
                    }
                }
                else
                {
                    OutputDebugStringA(
                        "GFXRECON: Failed to load GFXReconstruct capture DLL for d3d12.dll initialization");
                    OutputDebugStringA("GFXRECON: GFXReconstruct capture will be disabled");
                }
            }
        }
        else
        {
            OutputDebugStringA("GFXRECON: Failed to load system DLL for d3d12.dll initialization");
            return FALSE;
        }
    }

    return TRUE;
}

static void Destroy()
{
    if (capture_dll != nullptr)
    {
        auto release_func =
            reinterpret_cast<PFN_ReleaseD3D12Capture>(GetProcAddress(capture_dll, "ReleaseD3D12Capture"));

        if (release_func != nullptr)
        {
            release_func(&dispatch_table);
        }

        FreeLibrary(capture_dll);
        capture_dll = nullptr;
    }

    if (d3d12_dll != nullptr)
    {
        FreeLibrary(d3d12_dll);
        d3d12_dll = nullptr;
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
