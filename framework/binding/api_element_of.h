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

// A binding joins a schema entity to a C++ type that exists without the schema. This one maps a structure the API's
// headers declare to its API element, the inverse of the API element's element_type, which C++ cannot invert by
// lookup. The rows are keyed on the API's types, which never collide across APIs.
//
// This header declares the binding and nothing more. An API's rows are a visitor invoked across its inventory in
// binding/<api>_api_element_of.h, which is the header API code includes; with this one alone, ApiTypeWithApiElement
// answers no for every type.

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

// The structure's API element carries a structure type.
template <typename ApiStruct>
concept TypedStructApiType =
    ApiTypeWithApiElement<ApiStruct> && schema::TypedStructApiElement<ApiElementOf_t<ApiStruct>>;

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_API_ELEMENT_OF_H
