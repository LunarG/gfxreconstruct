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

// The correspondence between an API element and its decoded representation.
//
// ApiElementTraits is keyed on the API element and says what decode uses to represent it. The other direction needs
// no trait: a decoded wrapper names its element as api_element, so an operation handed a wrapper reads it there. The
// namespace answers "traits for whom" -- these are what gfxrecon::decode knows about an API element, not everything
// that is known about it.
//
// Neither carries a schema, a Consumer interface, a Consumer member pointer, or compatibility invocation behavior. A
// decoded wrapper names no schema type of its own, so the wrapper stays usable as the graph's currency.
//
// The primary templates are API-agnostic, so each API's generated specializations are separate content, and this
// header pulls in the content for every enabled API. That is what makes it safe to include on its own. The concepts
// below are satisfied by a specialization, so a translation unit holding the declarations without the
// specializations would silently answer no rather than fail, and two such translation units would resolve the same
// constrained call to different functions. Including the content here removes that state rather than asking every
// caller to avoid it.

#ifndef GFXRECON_DECODE_API_ELEMENT_TRAITS_H
#define GFXRECON_DECODE_API_ELEMENT_TRAITS_H

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Keyed on an API type descriptor or a command tag.
template <typename ApiElement>
struct ApiElementTraits;

template <typename ApiElement>
concept HasDecodedType = requires
{
    typename ApiElementTraits<ApiElement>::decoded_type;
};

template <typename ApiElement>
concept HasDecodedValueType = requires
{
    typename ApiElementTraits<ApiElement>::decoded_value_type;
};

// The concrete Decoded_Vk* and args:: declarations remain real types. This alias provides generic access without
// changing their type identity, linkage, or forward declarations.
template <typename ApiElement>
requires HasDecodedType<ApiElement>
using Decoded = typename ApiElementTraits<ApiElement>::decoded_type;

// A structure's decoded value type is its element type, which its API type descriptor already carries, so only a
// command declares one: a command's formal API-signature storage is not the element type of anything.
template <typename ApiElement>
requires HasDecodedValueType<ApiElement>
using DecodedValue = typename ApiElementTraits<ApiElement>::decoded_value_type;

// A decoded wrapper names the API element it represents, as api_element, the way it names its native type as
// struct_type. An operation handed a wrapper reaches the schema and the traits through that member, so no inverse
// trait is generated; the generated checks assert that each wrapper's element resolves back to the wrapper.
template <typename Wrapper>
concept HasApiElement = requires
{
    typename Wrapper::api_element;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

// THE ENTRY POINT. Include this rather than an API's generated traits header: both doors work, but one door is
// what keeps the specializations and the declarations from ever coming apart.
//
// Reaching the specializations means reaching every enabled API's type descriptors and every decoded wrapper and
// args declaration. That is inherent: the trait keys are the descriptors and the values are the wrappers. It does
// not reach a Field descriptor or a Schema: those live in separate generated files that only an Action's member
// traits and the field walk include, so naming Decoded<> here costs the wrappers, which any decode header already
// pays for, and not the schema.
//
// Each generated header includes this one back; the include guard makes that a no-op, and the primary templates
// above are declared before this point, so either include order works.
#if defined(GFXRECON_ENABLE_VULKAN)
#include "generated/generated_vulkan_decode_api_element_traits.h"
#endif

#endif // GFXRECON_DECODE_API_ELEMENT_TRAITS_H
