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

#ifndef GFXRECON_HOOK_AGS_H
#define GFXRECON_HOOK_AGS_H

#include "encode/ags_dispatch_table.h"

#include "util/interception/real_and_mine_hook.h"

#include <Windows.h>
#include <amd_ags.h>

const char kSystemDllName[]             = "amd_ags_x64_orig.dll";
const char kCaptureDllName[]            = "d3d12_capture.dll";
const char kCaptureDllInitProcName[]    = "InitializeAgsCapture";
const char kCaptureDllDestroyProcName[] = "ReleaseAgsCapture";
const char kHookingDllName[]            = "amd_ags_x64.dll";

class Hook_AGS;

// Helper struct that holds data required for hook management
struct AgsHookInfo
{
    // GFXR DLL with capture implementation, which is only loaded when capture is enabled
    HMODULE capture_dll = nullptr;

    // System DLL providing the Amd Ags X64 API calls to wrap
    HMODULE ags_dll = nullptr;

    // Dispatch table pointing either at the GPU or capture layer
    gfxrecon::encode::AgsDispatchTable dispatch_table = {};

    // Interceptor class in charge of hooking
    Hook_AGS* interceptor = nullptr;
};

//-----------------------------------------------------------------------------
/// This class is responsible for hooking Amd Ags X64 module entry points. It contains
/// a "Mine" implementation for each hooked function.
//-----------------------------------------------------------------------------
class Hook_AGS
{
  public:
    static Hook_AGS* GetInterceptor();

    Hook_AGS() {}
    virtual ~Hook_AGS() {}

    static bool HookInterceptor(bool capture);
    static bool UnhookInterceptor();

    gfxrecon::util::interception::RealAndMineHook<AGS_INITIALIZE> hook_agsInitialize_;
};
#endif // GFXRECON_HOOK_AGS_H
