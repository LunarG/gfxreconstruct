/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "util/interception/load_library.h"
#include "util/interception/create_process.h"
#include "util/interception/injection.h"

#include <Windows.h>
#include <string>

extern "C" __declspec(dllexport) void InjectDLL(HWND wnd, HINSTANCE instance, LPSTR cmd_line, INT cmd_show)
{
    gfxrecon::util::interception::Inject(cmd_line);
}

//----------------------------------------------------------------------------
/// This DLL gets injected into victim application and then is able to
/// detect all calls to LoadLibrary which will enable us to load in our
/// own implementations for D3D12 and DXGI.
/// \param  hModule A handle to the DLL module.
/// \param  ul_reason_for_call The reason code that indicates why the DLL entry-point function is being called.
/// \param  lpReserved
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
BOOL APIENTRY DllMain(HMODULE module, DWORD ul_reason_for_call, LPVOID reserved)
{
    char module_name[MAX_PATH] = {};
    GetModuleFileNameA(NULL, module_name, MAX_PATH);

    if (strstr(module_name, "rundll") != NULL)
    {
        return TRUE;
    }

    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            gfxrecon::util::interception::HookCreateProcess();
            gfxrecon::util::interception::HookLoadLibrary();
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }

    return TRUE;
}
