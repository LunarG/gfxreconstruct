/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/ags_dispatch_table.h"
#include "encode/dx12_dll_initializer.h"
#include "util/defines.h"
#include "util/file_path.h"
#include "util/platform.h"
#include "hook_ags.h"

#include <cassert>
#include <array>
#include <string>
#include <windows.h>

static gfxrecon::encode::DxDllInitializer<gfxrecon::encode::AgsDispatchTable> dll_initializer;

inline const gfxrecon::encode::AgsDispatchTable& GetDispatchTable()
{
    return dll_initializer.GetDispatchTable();
}

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

static void LoadAgsCaptureProcs(HMODULE system_dll, encode::AgsDispatchTable* dispatch_table)
{
    if (system_dll != nullptr && dispatch_table != nullptr)
    {
        dispatch_table->agsInitialize =
            reinterpret_cast<decltype(agsInitialize)*>(GetProcAddress(system_dll, "agsInitialize"));
        dispatch_table->agsDeInitialize =
            reinterpret_cast<decltype(agsDeInitialize)*>(GetProcAddress(system_dll, "agsDeInitialize"));
        dispatch_table->agsCheckDriverVersion =
            reinterpret_cast<decltype(agsCheckDriverVersion)*>(GetProcAddress(system_dll, "agsCheckDriverVersion"));
        dispatch_table->agsDriverExtensionsDX12_CreateDevice =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_CreateDevice)*>(
                GetProcAddress(system_dll, "agsDriverExtensionsDX12_CreateDevice"));
        dispatch_table->agsDriverExtensionsDX12_DestroyDevice =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_DestroyDevice)*>(
                GetProcAddress(system_dll, "agsDriverExtensionsDX12_DestroyDevice"));
        dispatch_table->agsGetVersionNumber =
            reinterpret_cast<decltype(agsGetVersionNumber)*>(GetProcAddress(system_dll, "agsGetVersionNumber"));
        dispatch_table->agsSetDisplayMode =
            reinterpret_cast<decltype(agsSetDisplayMode)*>(GetProcAddress(system_dll, "agsSetDisplayMode"));
        dispatch_table->agsDriverExtensionsDX12_PushMarker =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_PushMarker)*>(
                GetProcAddress(system_dll, "agsDriverExtensionsDX12_PushMarker"));
        dispatch_table->agsDriverExtensionsDX12_PopMarker =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_PopMarker)*>(
                GetProcAddress(system_dll, "agsDriverExtensionsDX12_PopMarker"));
        dispatch_table->agsDriverExtensionsDX12_SetMarker =
            reinterpret_cast<decltype(agsDriverExtensionsDX12_SetMarker)*>(
                GetProcAddress(system_dll, "agsDriverExtensionsDX12_SetMarker"));
    }
}

static bool Initialize()
{
    static bool initialized = false;
    if (initialized == false)
    {
        initialized =
            dll_initializer.Initialize(kSystemDllName, kCaptureDllName, kCaptureDllInitProcName, LoadAgsCaptureProcs);
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
        Hook_AGS::HookInterceptor(dll_initializer.IsCaptureEnabled());
        hooked = true;
    }
}

EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsInitialize(int                     agsVersion,
                                                          const AGSConfiguration* config,
                                                          AGSContext**            context,
                                                          AGSGPUInfo*             gpuInfo)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsInitialize(agsVersion, config, context, gpuInfo);
    }

    return AGS_FAILURE;
}

// When this API function is called, it means the app is trying to use AGS v5.x.x versions
EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsInit(AGSContext**            context,
                                                    const AGSConfiguration* config,
                                                    AGSGPUInfo*             gpuInfo)
{
    if (gfxrecon::Initialize())
    {
        GetDispatchTable().agsInitNotSupported();
    }

    return AGS_FAILURE;
}

// The system may check the entry point of this function if the app is trying to use AGS v5.x.x versions
EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsDeInit(AGSContext**            context,
                                                      const AGSConfiguration* config,
                                                      AGSGPUInfo*             gpuInfo)
{
    return AGS_FAILURE;
}

EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsDeInitialize(AGSContext* context)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsDeInitialize(context);
    }

    return AGS_FAILURE;
}

EXTERN_C AGSDriverVersionResult AMD_AGS_API gfxrecon_agsCheckDriverVersion(const char*  radeonSoftwareVersionReported,
                                                                           unsigned int radeonSoftwareVersionRequired)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsCheckDriverVersion(radeonSoftwareVersionReported, radeonSoftwareVersionRequired);
    }

    return AGS_SOFTWAREVERSIONCHECK_UNDEFINED;
}

EXTERN_C AGSReturnCode AMD_AGS_API
gfxrecon_agsDriverExtensionsDX12_CreateDevice(AGSContext*                        context,
                                              const AGSDX12DeviceCreationParams* creationParams,
                                              const AGSDX12ExtensionParams*      extensionParams,
                                              AGSDX12ReturnedParams*             returnedParams)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsDriverExtensionsDX12_CreateDevice(
            context, creationParams, extensionParams, returnedParams);
    }

    return AGS_FAILURE;
}

EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsDriverExtensionsDX12_DestroyDevice(AGSContext*   context,
                                                                                  ID3D12Device* device,
                                                                                  unsigned int* deviceReferences)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsDriverExtensionsDX12_DestroyDevice(context, device, deviceReferences);
    }

    return AGS_FAILURE;
}

EXTERN_C int AMD_AGS_API gfxrecon_agsGetVersionNumber()
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsGetVersionNumber();
    }

    return AGS_UNSPECIFIED_VERSION;
}

EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsSetDisplayMode(AGSContext*               context,
                                                              int                       deviceIndex,
                                                              int                       displayIndex,
                                                              const AGSDisplaySettings* settings)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsSetDisplayMode(context, deviceIndex, displayIndex, settings);
    }

    return AGS_FAILURE;
}

EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsDriverExtensionsDX12_PushMarker(AGSContext*                context,
                                                                               ID3D12GraphicsCommandList* commandList,
                                                                               const char*                data)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsDriverExtensionsDX12_PushMarker(context, commandList, data);
    }

    return AGS_FAILURE;
}

EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsDriverExtensionsDX12_PopMarker(AGSContext*                context,
                                                                              ID3D12GraphicsCommandList* commandList)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsDriverExtensionsDX12_PopMarker(context, commandList);
    }

    return AGS_FAILURE;
}

EXTERN_C AGSReturnCode AMD_AGS_API gfxrecon_agsDriverExtensionsDX12_SetMarker(AGSContext*                context,
                                                                              ID3D12GraphicsCommandList* commandList,
                                                                              const char*                data)
{
    if (gfxrecon::Initialize())
    {
        return GetDispatchTable().agsDriverExtensionsDX12_SetMarker(context, commandList, data);
    }

    return AGS_FAILURE;
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
