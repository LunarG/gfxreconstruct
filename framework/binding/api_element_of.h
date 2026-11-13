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

// ApiElementOf maps an API's C type -- a structure, union or enum, flag-bits enums included -- to its API element. It
// is the inverse of the API element's element_type, which C++ cannot compute by lookup. The specializations are keyed
// on the API's own C types, which do not collide across APIs.
//
// This header declares the template and nothing more. An API's specializations are an inventory visitor in
// binding/<api>_api_element_of.h, which is the header API code includes; with this header alone,
// ApiTypeWithApiElement is false for every type.
// NOTE: a translation unit that evaluates ApiTypeWithApiElement before including binding/<api>_api_element_of.h gets
// false, silently, and the compiler is not required to diagnose the late specialization.

#ifndef GFXRECON_BINDING_API_ELEMENT_OF_H
#define GFXRECON_BINDING_API_ELEMENT_OF_H

#include "schema/schema.h"
#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

template <typename ApiType>
struct ApiElementOf;

template <typename ApiType>
concept ApiTypeWithApiElement = requires
{
    typename ApiElementOf<ApiType>::type;
};

template <ApiTypeWithApiElement ApiType>
using ApiElementOf_t = typename ApiElementOf<ApiType>::type;

// TypedStructApiType matches an API structure whose API element carries a structure type.
template <typename ApiStruct>
concept TypedStructApiType =
    ApiTypeWithApiElement<ApiStruct> && schema::TypedStructApiElement<ApiElementOf_t<ApiStruct>>;

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_API_ELEMENT_OF_H
