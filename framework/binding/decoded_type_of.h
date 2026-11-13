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

// DecodedTypeOf maps an API element, or a command API element, to the type decode stores it in: a Decoded_ wrapper or
// an args structure. That type is decode's choice, not the registry's, so it is a binding, not an API element member.
// The other direction needs no binding: a wrapper holds its API element as api_element.
//
// This header declares the template and nothing more. An API's specializations are an inventory visitor in
// binding/<api>_decoded_type.h, which is the header API code includes; with this header alone,
// ApiElementWithDecodedType is false for every API element.
// NOTE: a translation unit that evaluates ApiElementWithDecodedType before including binding/<api>_decoded_type.h
// gets false, silently, and the compiler is not required to diagnose the late specialization.

#ifndef GFXRECON_BINDING_DECODED_TYPE_OF_H
#define GFXRECON_BINDING_DECODED_TYPE_OF_H

#include "schema/api_element.h"
#include "util/defines.h"

#include <concepts>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// Keyed on an API element or a command API element. Undefined: an API element without a specialization is an
// incomplete type, and ApiElementWithDecodedType is false for it.
template <typename ApiElement>
struct DecodedTypeOf;

template <typename ApiElement>
concept ApiElementWithDecodedType = requires
{
    typename DecodedTypeOf<ApiElement>::type;
};

template <ApiElementWithDecodedType ApiElement>
using DecodedTypeOf_t = typename DecodedTypeOf<ApiElement>::type;

// DecodedWrapper is the concept a Decoded_ wrapper satisfies.
template <typename Wrapper>
concept DecodedWrapper = requires(Wrapper& wrapper)
{
    typename Wrapper::struct_type;
    requires schema::ApiElement<typename Wrapper::api_element>;
    {
        wrapper.decoded_value
        } -> std::convertible_to<typename Wrapper::struct_type*>;
};

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_DECODED_TYPE_OF_H
