/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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
#if ENABLE_OPENXR_SUPPORT
#include "encode/openxr_capture_manager.h"
#endif // ENABLE_OPENXR_SUPPORT
#include "encode/vulkan_capture_manager.h"
#include "layer/layer_vulkan_entry.h"
#include "generated/generated_vulkan_layer_func_table.h"

#if defined(WIN32)

#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL success = TRUE;

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            gfxrecon::vulkan_layer::LayerVulkanEntry::InitSingleton();
            gfxrecon::encode::VulkanCaptureManager::SetLayerFuncs(gfxrecon::vulkan_layer::dispatch_CreateInstance,
                                                                  gfxrecon::vulkan_layer::dispatch_CreateDevice);
#if ENABLE_OPENXR_SUPPORT
            gfxrecon::encode::OpenXrCaptureManager::SetLayerFuncs(
                gfxrecon::openxr_layer::dispatch_CreateApiLayerInstance);
#endif // ENABLE_OPENXR_SUPPOR
            break;
        case DLL_PROCESS_DETACH:
            gfxrecon::vulkan_layer::LayerVulkanEntry::DestroySingleton();
            // TODO: We assume that lpvReserved will always be NULL, because FreeLibrary should be
            //       invoked by the loader from vkDestroyInstance.  If this is not always the case,
            //       we will need to split destroy_layer into a shutdown function, responsible for
            //       performing any finalization work, that would always run and a destroy function,
            //       responsible for releasing resources, that would only run when the process was
            //       not terminating.
            if (lpvReserved == nullptr)
            {
                // TODO: Ensure that the trace is finalized.
            }
            break;
    }

    return success;
}

#else // WIN32

__attribute__((constructor)) static void create_trace_layer()
{
    gfxrecon::vulkan_layer::LayerVulkanEntry::InitSingleton();
    gfxrecon::encode::VulkanCaptureManager::SetLayerFuncs(gfxrecon::vulkan_layer::dispatch_CreateInstance,
                                                          gfxrecon::vulkan_layer::dispatch_CreateDevice);
#if ENABLE_OPENXR_SUPPORT
    gfxrecon::encode::OpenXrCaptureManager::SetLayerFuncs(gfxrecon::openxr_layer::dispatch_CreateApiLayerInstance);
#endif // ENABLE_OPENXR_SUPPORT
}

__attribute__((destructor)) static void destroy_trace_layer()
{
    gfxrecon::vulkan_layer::LayerVulkanEntry::DestroySingleton();
    // TODO: Ensure that the trace is finalized.
}

#endif // WIN32
