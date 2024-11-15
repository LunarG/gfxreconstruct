/*
** Copyright (c) 2024 Valve Corporation
** Copyright (c) 2024 LunarG, Inc.
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

#include "util/defines.h"
#include "util/logging.h"
#include "mark_injected_commands.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static void BeginEndInjectedCommandsNoop(void* data)
{
    GFXRECON_UNREFERENCED_PARAMETER(data);
}

#ifdef GFXRECON_DEBUG_BUILD
static bool injecting_api_calls_g = false;
#endif

static PFN_BeginInjectedCommands BeginInjectCommands_fp = BeginEndInjectedCommandsNoop;
static PFN_EndInjectedCommands   EndInjectCommands_fp   = BeginEndInjectedCommandsNoop;
static void*                     InjectCommandsData_ptr = nullptr;

extern "C" void
SetInjectedCommandCallbacks(PFN_BeginInjectedCommands begin_fp, PFN_EndInjectedCommands end_fp, void* data)
{
    BeginInjectCommands_fp = begin_fp != nullptr ? begin_fp : BeginEndInjectedCommandsNoop;
    EndInjectCommands_fp   = end_fp != nullptr ? end_fp : BeginEndInjectedCommandsNoop;
    InjectCommandsData_ptr = data;
}

void BeginInjectedCommands()
{
#ifdef GFXRECON_DEBUG_BUILD
    // Nested BeginInjectedCommands/EndInjectedCommands
    GFXRECON_ASSERT(!injecting_api_calls_g);
    injecting_api_calls_g = true;
#endif

    BeginInjectCommands_fp(InjectCommandsData_ptr);
}

void EndInjectedCommands()
{
#ifdef GFXRECON_DEBUG_BUILD
    // Nested BeginInjectedCommands/EndInjectedCommands
    GFXRECON_ASSERT(injecting_api_calls_g);
    injecting_api_calls_g = false;
#endif

    EndInjectCommands_fp(InjectCommandsData_ptr);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
