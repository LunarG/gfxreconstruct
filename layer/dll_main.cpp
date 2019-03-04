/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "encode/trace_manager.h"
#include "layer/trace_layer.h"

#if defined(WIN32)

#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL success = TRUE;

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            gfxrecon::encode::TraceManager::SetLayerFuncs(gfxrecon::dispatch_CreateInstance,
                                                          gfxrecon::dispatch_CreateDevice);
            break;
        case DLL_PROCESS_DETACH:
            // TODO: We assume that lpvReserved will always be NULL, because FreeLibrary should be
            //       invoked by the loader from vkDestroyInstance.  If this is not always the case,
            //       we will need to split destroy_layer into a shutdown function, responsible for
            //       performing any finalization work, that would always run and a destroy funtion,
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
    gfxrecon::encode::TraceManager::SetLayerFuncs(gfxrecon::dispatch_CreateInstance, gfxrecon::dispatch_CreateDevice);
}

__attribute__((destructor)) static void destroy_trace_layer()
{
    // TODO: Ensure that the trace is finalized.
}

#endif // WIN32
