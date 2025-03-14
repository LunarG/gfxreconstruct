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
#include "encode/dx12_dll_initializer.h"
#include "util/defines.h"
#include "util/file_path.h"
#include "util/platform.h"
#include "hook_d3d12.h"

#include <cassert>
#include <array>
#include <mutex>
#include <string>
#include <windows.h>

const char kSystemDllName[]             = "d3d12.dll";
const char kSystemDllNameRenamed[]      = "d3d12_ms.dll";
const char kCaptureDllName[]            = "d3d12_capture.dll";
const char kCaptureDllInitProcName[]    = "InitializeD3D12Capture";
const char kCaptureDllDestroyProcName[] = "ReleaseD3D12Capture";

static gfxrecon::encode::DxDllInitializer<gfxrecon::encode::D3D12DispatchTable> dll_initializer;

inline const gfxrecon::encode::D3D12DispatchTable& GetDispatchTable()
{
    return dll_initializer.GetDispatchTable();
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

static void LoadD3D12CaptureProcs(HMODULE system_dll, encode::D3D12DispatchTable* dispatch_table)
{
    if (system_dll != nullptr && dispatch_table != nullptr)
    {
        dispatch_table->D3D12CreateDevice =
            reinterpret_cast<PFN_D3D12_CREATE_DEVICE>(GetProcAddress(system_dll, "D3D12CreateDevice"));
        dispatch_table->D3D12CreateRootSignatureDeserializer =
            reinterpret_cast<PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER>(
                GetProcAddress(system_dll, "D3D12CreateRootSignatureDeserializer"));
        dispatch_table->D3D12CreateVersionedRootSignatureDeserializer =
            reinterpret_cast<PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER>(
                GetProcAddress(system_dll, "D3D12CreateVersionedRootSignatureDeserializer"));
        dispatch_table->D3D12GetDebugInterface =
            reinterpret_cast<PFN_D3D12_GET_DEBUG_INTERFACE>(GetProcAddress(system_dll, "D3D12GetDebugInterface"));
        dispatch_table->D3D12SerializeRootSignature = reinterpret_cast<PFN_D3D12_SERIALIZE_ROOT_SIGNATURE>(
            GetProcAddress(system_dll, "D3D12SerializeRootSignature"));
        dispatch_table->D3D12SerializeVersionedRootSignature =
            reinterpret_cast<PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE>(
                GetProcAddress(system_dll, "D3D12SerializeVersionedRootSignature"));
        dispatch_table->D3D12GetInterface =
            reinterpret_cast<PFN_D3D12_GET_INTERFACE>(GetProcAddress(system_dll, "D3D12GetInterface"));
        dispatch_table->D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary =
            reinterpret_cast<PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER_FROM_SUBOBJECT_IN_LIBRARY>(
                GetProcAddress(system_dll, "D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary"));
        dispatch_table->D3D12EnableExperimentalFeatures = reinterpret_cast<decltype(D3D12EnableExperimentalFeatures)*>(
            GetProcAddress(system_dll, "D3D12EnableExperimentalFeatures"));
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
                module_path.c_str(), kCaptureDllName, kCaptureDllInitProcName, LoadD3D12CaptureProcs);
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
        Hook_D3D12::HookInterceptor(dll_initializer.IsCaptureEnabled());
        hooked = true;
    }
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12CreateDevice(IUnknown*         pAdapter,
                                                   D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                                   REFIID            riid,
                                                   void**            ppDevice)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12CreateDevice(pAdapter, MinimumFeatureLevel, riid, ppDevice);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12CreateRootSignatureDeserializer(LPCVOID pSrcData,
                                                                      SIZE_T  SrcDataSizeInBytes,
                                                                      REFIID  pRootSignatureDeserializerInterface,
                                                                      void**  ppRootSignatureDeserializer)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12CreateRootSignatureDeserializer(
            pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI
gfxrecon_D3D12CreateVersionedRootSignatureDeserializer(LPCVOID pSrcData,
                                                       SIZE_T  SrcDataSizeInBytes,
                                                       REFIID  pRootSignatureDeserializerInterface,
                                                       void**  ppRootSignatureDeserializer)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12CreateVersionedRootSignatureDeserializer(
            pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12GetDebugInterface(REFIID riid, void** ppvDebug)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12GetDebugInterface(riid, ppvDebug);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
                                                             D3D_ROOT_SIGNATURE_VERSION       Version,
                                                             ID3DBlob**                       ppBlob,
                                                             ID3DBlob**                       ppErrorBlob)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12SerializeRootSignature(pRootSignature, Version, ppBlob, ppErrorBlob);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature, ID3DBlob** ppBlob, ID3DBlob** ppErrorBlob)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12GetInterface(REFCLSID rclsid, REFIID riid, void** ppvDebug)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12GetInterface(rclsid, riid, ppvDebug);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI
gfxrecon_D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(LPCVOID pSrcData,
                                                                             SIZE_T  SrcDataSizeInBytes,
                                                                             LPCWSTR RootSignatureSubobjectName,
                                                                             REFIID  pRootSignatureDeserializerInterface,
                                                                             void**  ppRootSignatureDeserializer)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary(
            pSrcData,
            SrcDataSizeInBytes,
            RootSignatureSubobjectName,
            pRootSignatureDeserializerInterface,
            ppRootSignatureDeserializer);
    }

    return E_FAIL;
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12EnableExperimentalFeatures(UINT       NumFeatures,
                                                                 const IID* pIIDs,
                                                                 void*      pConfigurationStructs,
                                                                 UINT*      pConfigurationStructSizes)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().D3D12EnableExperimentalFeatures(
            NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes);
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
