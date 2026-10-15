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

// The decoded-type binding: an API element, a structure's API type descriptor or a command descriptor, to the type
// decode represents it with. Which wrapper represents an element is the C++ back end's decision, so this is a binding
// and not a schema fact. The other direction needs no binding: a decoded wrapper names its element as api_element.
//
// This header declares the binding and nothing more. An API's rows are a visitor invoked across its inventory in
// binding/<api>_decoded_type.h, which is the header API code includes; with this one alone, HasDecodedType answers
// no for every element. A translation unit that evaluates the concept on a concrete type without the rows resolves a
// constrained call differently from one that has them, and nothing diagnoses that, since a specialization declared
// after a use that implicitly instantiated the primary is ill-formed, no diagnostic required (C++20 standard,
// [temp.expl.spec]/7). The API rows header is the include.

#ifndef GFXRECON_BINDING_DECODED_TYPE_OF_H
#define GFXRECON_BINDING_DECODED_TYPE_OF_H

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(binding)

// Keyed on an API type descriptor or a command descriptor. Declared, not defined, so an absent row is an incomplete
// type and HasDecodedType reads as unsatisfied.
template <typename ApiElement>
struct DecodedType;

template <typename ApiElement>
concept HasDecodedType = requires
{
    typename DecodedType<ApiElement>::type;
};

// The concrete Decoded_Vk* and args:: declarations remain real types. This alias provides generic access without
// changing their type identity, linkage, or forward declarations.
template <HasDecodedType ApiElement>
using DecodedTypeOf = typename DecodedType<ApiElement>::type;

// A decoded wrapper names the API element it represents, as api_element, the way it names its native type as
// struct_type. An operation handed a wrapper reaches the schema and the bindings through that member, so no inverse
// binding is generated; the generated checks assert that each wrapper's element resolves back to the wrapper.
template <typename Wrapper>
concept HasApiElement = requires
{
    typename Wrapper::api_element;
};

GFXRECON_END_NAMESPACE(binding)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_BINDING_DECODED_TYPE_OF_H
