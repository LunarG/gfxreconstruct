/*
** Copyright (c) 2024 - 2025 Valve Corporation
** Copyright (c) 2024 - 2025 LunarG, Inc.
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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

using PFN_EventBeginCallBack = void (*)(void*);
using PFN_EventEndCallBack   = void (*)(void*);
using PFN_SetEventsCallbacks = void (*)(PFN_EventBeginCallBack, PFN_EventEndCallBack, void*);

void BeginInjectedCommands();

void EndInjectedCommands();

// Interface for registering callbacks so that GFXReconstruct can notify an external library about
// generated API calls that are not included in the capture file.
// Intended usage: GFXR will call PFN_EventΑCallBack once before it starts issuing synthesized
// API calls, and PFN_EventΒCallBack once it is finished.
// A void * pointer allows passing optional data that will be forwarded into both callbacks.
//
// SetInjectedCommandCallbacks can be discovered through dlsym/GetProcAddress.
extern "C" void SetInjectedCommandCallbacks(PFN_EventBeginCallBack begin_fp, PFN_EventEndCallBack end_fp, void* data);

void SignalTrimmingStart();

void SignalTrimmingEnd();

// Interface for registering callbacks so that GFXReconstruct can notify an external library about
// when trimming starts and stops.
// Intended usage: GFXR will call PFN_EventΑCallBack when trimming starts and PFN_EventΒCallBack once
// it is finished.
// A void * pointer allows passing optional data that will be forwarded into both callbacks.
//
// SetSignalTrimmingCallbacks can be discovered through dlsym/GetProcAddress.
extern "C" void SetSignalTrimmingCallbacks(PFN_EventBeginCallBack begin_fp, PFN_EventEndCallBack end_fp, void* data);

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
