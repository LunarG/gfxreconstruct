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
#include "hook_d3d12.h"

#include <cassert>
#include <array>
#include <string>
#include <windows.h>

const wchar_t kSystemDllName[]  = L"d3d12_ms.dll";
const wchar_t kCaptureDllName[] = L"d3d12_capture.dll";

static HMODULE                              d3d12_dll   = nullptr;
static HMODULE                              capture_dll = nullptr;
static gfxrecon::encode::D3D12DispatchTable dispatch_table;

EXTERN_C HRESULT WINAPI gfxrecon_D3D12CreateDevice(IUnknown*         pAdapter,
                                                   D3D_FEATURE_LEVEL MinimumFeatureLevel,
                                                   REFIID            riid,
                                                   void**            ppDevice)
{
    return dispatch_table.D3D12CreateDevice(pAdapter, MinimumFeatureLevel, riid, ppDevice);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12CreateRootSignatureDeserializer(LPCVOID pSrcData,
                                                                      SIZE_T  SrcDataSizeInBytes,
                                                                      REFIID  pRootSignatureDeserializerInterface,
                                                                      void**  ppRootSignatureDeserializer)
{
    return dispatch_table.D3D12CreateRootSignatureDeserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

EXTERN_C HRESULT WINAPI
                 gfxrecon_D3D12CreateVersionedRootSignatureDeserializer(LPCVOID pSrcData,
                                                                        SIZE_T  SrcDataSizeInBytes,
                                                                        REFIID  pRootSignatureDeserializerInterface,
                                                                        void**  ppRootSignatureDeserializer)
{
    return dispatch_table.D3D12CreateVersionedRootSignatureDeserializer(
        pSrcData, SrcDataSizeInBytes, pRootSignatureDeserializerInterface, ppRootSignatureDeserializer);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12GetDebugInterface(REFIID riid, void** ppvDebug)
{
    return dispatch_table.D3D12GetDebugInterface(riid, ppvDebug);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC* pRootSignature,
                                                             D3D_ROOT_SIGNATURE_VERSION       Version,
                                                             ID3DBlob**                       ppBlob,
                                                             ID3DBlob**                       ppErrorBlob)
{
    return dispatch_table.D3D12SerializeRootSignature(pRootSignature, Version, ppBlob, ppErrorBlob);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12SerializeVersionedRootSignature(
    const D3D12_VERSIONED_ROOT_SIGNATURE_DESC* pRootSignature, ID3DBlob** ppBlob, ID3DBlob** ppErrorBlob)
{
    return dispatch_table.D3D12SerializeVersionedRootSignature(pRootSignature, ppBlob, ppErrorBlob);
}

EXTERN_C HRESULT WINAPI gfxrecon_D3D12EnableExperimentalFeatures(UINT       NumFeatures,
                                                                 const IID* pIIDs,
                                                                 void*      pConfigurationStructs,
                                                                 UINT*      pConfigurationStructSizes)
{
    return dispatch_table.D3D12EnableExperimentalFeatures(
        NumFeatures, pIIDs, pConfigurationStructs, pConfigurationStructSizes);
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

static bool IsCaptureEnabled()
{
    // TODO: Read environment variable.
    return false;
}

static void LoadDxgiCaptureProcs()
{
    assert(d3d12_dll != nullptr);

    dispatch_table.D3D12CreateDevice =
        reinterpret_cast<PFN_D3D12_CREATE_DEVICE>(GetProcAddress(d3d12_dll, "D3D12CreateDevice"));
    dispatch_table.D3D12CreateRootSignatureDeserializer =
        reinterpret_cast<PFN_D3D12_CREATE_ROOT_SIGNATURE_DESERIALIZER>(
            GetProcAddress(d3d12_dll, "D3D12CreateRootSignatureDeserializer"));
    dispatch_table.D3D12CreateVersionedRootSignatureDeserializer =
        reinterpret_cast<PFN_D3D12_CREATE_VERSIONED_ROOT_SIGNATURE_DESERIALIZER>(
            GetProcAddress(d3d12_dll, "D3D12CreateVersionedRootSignatureDeserializer"));
    dispatch_table.D3D12GetDebugInterface =
        reinterpret_cast<PFN_D3D12_GET_DEBUG_INTERFACE>(GetProcAddress(d3d12_dll, "D3D12GetDebugInterface"));
    dispatch_table.D3D12SerializeRootSignature =
        reinterpret_cast<PFN_D3D12_SERIALIZE_ROOT_SIGNATURE>(GetProcAddress(d3d12_dll, "D3D12SerializeRootSignature"));
    dispatch_table.D3D12SerializeVersionedRootSignature =
        reinterpret_cast<PFN_D3D12_SERIALIZE_VERSIONED_ROOT_SIGNATURE>(
            GetProcAddress(d3d12_dll, "D3D12SerializeVersionedRootSignature"));
    dispatch_table.D3D12EnableExperimentalFeatures = reinterpret_cast<decltype(D3D12EnableExperimentalFeatures)*>(
        GetProcAddress(d3d12_dll, "D3D12EnableExperimentalFeatures"));
}

static BOOL Initialize(HINSTANCE instance)
{
    if (d3d12_dll == nullptr)
    {
        d3d12_dll = LoadLibraryW(kSystemDllName);

        if (d3d12_dll != nullptr)
        {
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

extern "C" __declspec(dllexport) void UpdateHooks()
{
    static bool hooked = false;

    if (hooked == false)
    {
        Hook_D3D12::HookInterceptor();
        hooked = true;
    }
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL success = TRUE;

    if (gfxrecon::util::interception::UseDetoursHooking() == false)
    {
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
    }

    return success;
}
