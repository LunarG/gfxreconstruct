/*
** Copyright (c) 2026 LunarG, Inc.
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
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

// CallId maps a command API element to the format::ApiCallId the capture file records for the command. It is a
// binding, not an API element member: the registry gives a command no such number.
//
// This header declares the template and nothing more. An API's specializations are an inventory visitor in
// binding/<api>_call_id.h, which is the header API code includes; with this header alone, CommandWithCallId is false
// for every command.
// NOTE: a translation unit that evaluates CommandWithCallId before including binding/<api>_call_id.h gets false,
// silently, and the compiler is not required to diagnose the late specialization.

#ifndef GFXRECON_BINDING_CALL_ID_OF_H
#define GFXRECON_BINDING_CALL_ID_OF_H

#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// Keyed on a command API element. Undefined: a command without a specialization is an incomplete type, and
// CommandWithCallId is false for it.
template <typename Command>
struct CallId;

template <typename Command>
concept CommandWithCallId = requires
{
    CallId<Command>::value;
};

template <CommandWithCallId Command>
inline constexpr format::ApiCallId CallId_v = CallId<Command>::value;

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_CALL_ID_OF_H
