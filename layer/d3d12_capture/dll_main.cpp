/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

// This needs to be included before d3d12.h so that IIDs are defined and not just declared.
#include <initguid.h>

#ifdef GFXRECON_AGS_SUPPORT
#include "encode/custom_ags_wrappers.h"
#endif // GFXRECON_AGS_SUPPORT
#include "encode/d3d12_capture_manager.h"
#include "encode/d3d12_dispatch_table.h"
#include "encode/d3d11_dispatch_table.h"
#include "encode/dxgi_dispatch_table.h"
#include "generated/generated_dx12_wrappers.h"

// This IID is not defined in d3dcommon.h or dxguid.lib
DEFINE_GUID(IID_ID3DDestructionNotifier, 0xa06eb39a, 0x50da, 0x425b, 0x8c, 0x31, 0x4e, 0xec, 0xd6, 0xc2, 0x70, 0xf3);

EXTERN_C bool InitializeDxgiCapture(gfxrecon::encode::DxgiDispatchTable* table)
{
    if ((table != nullptr) && gfxrecon::encode::D3D12CaptureManager::CreateInstance())
    {
        // Store the real DXGI functions with the capture manager.  The wrapper functions will retrieve the real
        // functions from the capture manager.
        auto manager = gfxrecon::encode::D3D12CaptureManager::Get();
        manager->InitDxgiDispatchTable(*table);

        // Update the dispatch table with the wrapper functions.
        table->CreateDXGIFactory                = gfxrecon::encode::CreateDXGIFactory;
        table->CreateDXGIFactory1               = gfxrecon::encode::CreateDXGIFactory1;
        table->CreateDXGIFactory2               = gfxrecon::encode::CreateDXGIFactory2;
        table->DXGIDeclareAdapterRemovalSupport = gfxrecon::encode::DXGIDeclareAdapterRemovalSupport;
        table->DXGIGetDebugInterface1           = gfxrecon::encode::DXGIGetDebugInterface1;

        return true;
    }

    return false;
}

EXTERN_C bool InitializeD3D12Capture(gfxrecon::encode::D3D12DispatchTable* table)
{
    if (gfxrecon::encode::D3D12CaptureManager::CreateInstance())
    {
        // Store the real D3D12 functions with the capture manager.  The wrapper functions will retrieve the real
        // functions from the capture manager.
        auto manager = gfxrecon::encode::D3D12CaptureManager::Get();
        manager->InitD3D12DispatchTable(*table);

        // Update the dispatch table with the wrapper functions.
        table->D3D12CreateDevice                    = gfxrecon::encode::D3D12CreateDevice;
        table->D3D12CreateRootSignatureDeserializer = gfxrecon::encode::D3D12CreateRootSignatureDeserializer;
        table->D3D12CreateVersionedRootSignatureDeserializer =
            gfxrecon::encode::D3D12CreateVersionedRootSignatureDeserializer;
        table->D3D12GetDebugInterface               = gfxrecon::encode::D3D12GetDebugInterface;
        table->D3D12SerializeRootSignature          = gfxrecon::encode::D3D12SerializeRootSignature;
        table->D3D12SerializeVersionedRootSignature = gfxrecon::encode::D3D12SerializeVersionedRootSignature;
        table->D3D12GetInterface                    = gfxrecon::encode::D3D12GetInterface;
        table->D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary =
            gfxrecon::encode::D3D12CreateVersionedRootSignatureDeserializerFromSubobjectInLibrary;
        table->D3D12EnableExperimentalFeatures      = gfxrecon::encode::D3D12EnableExperimentalFeatures;

        return true;
    }

    return false;
}

#ifdef GFXRECON_AGS_SUPPORT
EXTERN_C bool InitializeAgsCapture(gfxrecon::encode::AgsDispatchTable* table)
{

    if ((table != nullptr) && gfxrecon::encode::D3D12CaptureManager::CreateInstance())
    {
        // Store the real Ags functions with the capture manager.  The wrapper functions will retrieve the real
        // functions from the capture manager.
        auto manager = gfxrecon::encode::D3D12CaptureManager::Get();
        manager->InitAgsDispatchTable(*table);

        // Update the dispatch table with the wrapper functions.
        table->agsInitialize                         = gfxrecon::encode::agsInitialize;
        table->agsDeInitialize                       = gfxrecon::encode::agsDeInitialize;
        table->agsDriverExtensionsDX12_CreateDevice  = gfxrecon::encode::agsDriverExtensionsDX12_CreateDevice;
        table->agsDriverExtensionsDX12_DestroyDevice = gfxrecon::encode::agsDriverExtensionsDX12_DestroyDevice;
        table->agsCheckDriverVersion                 = gfxrecon::encode::agsCheckDriverVersion;
        table->agsGetVersionNumber                   = gfxrecon::encode::agsGetVersionNumber;
        table->agsSetDisplayMode                     = gfxrecon::encode::agsSetDisplayMode;
        table->agsDriverExtensionsDX12_PushMarker    = gfxrecon::encode::agsDriverExtensionsDX12_PushMarker;
        table->agsDriverExtensionsDX12_PopMarker     = gfxrecon::encode::agsDriverExtensionsDX12_PopMarker;
        table->agsDriverExtensionsDX12_SetMarker     = gfxrecon::encode::agsDriverExtensionsDX12_SetMarker;

        table->agsInitNotSupported = gfxrecon::encode::agsInitNotSupported;

        return true;
    }

    return false;
}
#else
EXTERN_C bool InitializeAgsCapture()
{
    return false;
}
#endif // GFXRECON_AGS_SUPPORT

EXTERN_C bool InitializeD3D11Capture(gfxrecon::encode::D3D11DispatchTable* table)
{
    if (gfxrecon::encode::D3D12CaptureManager::CreateInstance())
    {
        // Store the real D3D11 functions with the capture manager.  The wrapper functions will retrieve the real
        // functions from the capture manager.
        auto manager = gfxrecon::encode::D3D12CaptureManager::Get();
        manager->InitD3D11DispatchTable(*table);

        // Update the dispatch table with the wrapper functions.
        table->D3D11CreateDevice             = gfxrecon::encode::D3D11CreateDevice;
        table->D3D11CreateDeviceAndSwapChain = gfxrecon::encode::D3D11CreateDeviceAndSwapChain;
        table->D3D11On12CreateDevice         = gfxrecon::encode::D3D11On12CreateDevice;

        return true;
    }

    return false;
}

EXTERN_C void WINAPI ReleaseDxgiCapture(gfxrecon::encode::DxgiDispatchTable*)
{
    gfxrecon::encode::D3D12CaptureManager::DestroyInstance();
}

EXTERN_C void WINAPI ReleaseD3D12Capture(gfxrecon::encode::D3D12DispatchTable*)
{
    gfxrecon::encode::D3D12CaptureManager::DestroyInstance();
}

EXTERN_C void WINAPI ReleaseAgsCapture(gfxrecon::encode::AgsDispatchTable*)
{
#ifdef GFXRECON_AGS_SUPPORT
    gfxrecon::encode::D3D12CaptureManager::DestroyInstance();
#endif // GFXRECON_AGS_SUPPORT
}

EXTERN_C void WINAPI ReleaseD3D11Capture(gfxrecon::encode::D3D11DispatchTable*)
{
    gfxrecon::encode::D3D12CaptureManager::DestroyInstance();
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            break;
        case DLL_PROCESS_DETACH:
            if (lpvReserved == nullptr)
            {
            }
            break;
    }

    return TRUE;
}
