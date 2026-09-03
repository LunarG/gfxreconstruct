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
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

// Decoded representation traits. An API type descriptor or a command tag is the direct traits key.
//
// TraitsFor contains representation types and intrinsic identifiers. It does not contain schemas, Consumer
// interfaces, Consumer member pointers, or compatibility invocation behavior. A header that needs only a decoded
// representation can include this declaration without including field schemas.

#ifndef GFXRECON_DECODE_DECODED_REPRESENTATION_TRAITS_H
#define GFXRECON_DECODE_DECODED_REPRESENTATION_TRAITS_H

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

template <typename ApiElement>
struct TraitsFor;

template <typename ApiElement>
concept HasDecodedType = requires { typename TraitsFor<ApiElement>::decoded_type; };

template <typename ApiElement>
concept HasDecodedValueType = requires { typename TraitsFor<ApiElement>::decoded_value_type; };

template <typename ApiElement>
concept HasCallId = requires { TraitsFor<ApiElement>::call_id; };

// The concrete Decoded_Vk* and Decoded_vk* declarations remain real types. This alias provides generic access
// without changing their type identity, linkage, or forward declarations.
template <typename ApiElement>
    requires HasDecodedType<ApiElement>
using Decoded = typename TraitsFor<ApiElement>::decoded_type;

template <typename ApiElement>
    requires HasDecodedValueType<ApiElement>
using DecodedValue = typename TraitsFor<ApiElement>::decoded_value_type;

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DECODED_REPRESENTATION_TRAITS_H
