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

// This needs to be included before d3d12.h so that IIDs are defined and not just declared.
#include <initguid.h>

#include "encode/d3d12_dispatch_table.h"
#include "encode/trace_manager.h"

EXTERN_C bool InitializeDxgiCapture(gfxrecon::encode::DxgiDispatchTable*)
{
    if (gfxrecon::encode::TraceManager::CreateInstance())
    {
        // TODO: Initialize dispatch table
        return true;
    }

    return false;
}

EXTERN_C bool InitializeD3D12Capture(gfxrecon::encode::D3D12DispatchTable*)
{
    if (gfxrecon::encode::TraceManager::CreateInstance())
    {
        // TODO: Initialize dispatch table
        return true;
    }

    return false;
}

EXTERN_C void WINAPI ReleaseDxgiCapture(gfxrecon::encode::DxgiDispatchTable*)
{
    gfxrecon::encode::TraceManager::DestroyInstance();
}

EXTERN_C void WINAPI ReleaseD3D12Capture(gfxrecon::encode::D3D12DispatchTable*)
{
    gfxrecon::encode::TraceManager::DestroyInstance();
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
