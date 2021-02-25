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

#include "hooking_detours.h"

#include "util/options.h"
#include "util/platform.h"

#include <assert.h>
#include <string>

#include "detours.h"

#ifdef _DEBUG
#pragma comment(lib, "detoursd")
#else
#pragma comment(lib, "detours")
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

//----------------------------------------------------------------------------
/// Initialize detours only once
//----------------------------------------------------------------------------
static void Initialize()
{
    static bool initialized = false;

    if (initialized == false)
    {
        initialized = true;
        DetourRestoreAfterWith();
    }
}

bool WINAPI HookAPICall(PVOID* real_fn, PVOID mine_fn)
{
    Initialize();

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(real_fn, mine_fn);
    LONG error = DetourTransactionCommit();

    return error == NO_ERROR;
}

bool WINAPI UnhookAPICall(PVOID* real_fn, PVOID mine_fn)
{
    Initialize();

    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(real_fn, mine_fn);
    LONG error = DetourTransactionCommit();

    return error == NO_ERROR;
}

bool UseDetoursHooking()
{
    bool use_detours = false;

    std::string value = gfxrecon::util::platform::GetEnv("GFXRECON_USE_DETOURS_HOOKING");

    if (gfxrecon::util::ParseBoolString(value, false) == true)
    {
        use_detours = true;
    }

    return use_detours;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
