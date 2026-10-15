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

// The call-id binding: a command's descriptor to the ApiCallId the classic encoding writes for the command on the
// wire. The registry gives a command no such number, and a second encoding could number commands differently, so
// this is a binding and not a schema fact.
//
// This header declares the binding and nothing more. An API's rows are a visitor invoked across its inventory in
// binding/<api>_call_id.h, which is the header API code includes; with this one alone, HasCallId answers no for
// every command.

#ifndef GFXRECON_BINDING_CALL_ID_OF_H
#define GFXRECON_BINDING_CALL_ID_OF_H

#include "format/api_call_id.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// Keyed on a command descriptor. Declared, not defined, so an absent row is an incomplete type and HasCallId reads as
// unsatisfied.
template <typename Command>
struct CallId;

template <typename Command>
concept HasCallId = requires
{
    CallId<Command>::value;
};

template <HasCallId Command>
inline constexpr format::ApiCallId CallIdOf = CallId<Command>::value;

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_CALL_ID_OF_H
