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

// An API element: one named thing in the API, a structure, a union, a handle, an enumerated type, a scalar typedef, a
// command.

#ifndef GFXRECON_SCHEMA_API_ELEMENT_H
#define GFXRECON_SCHEMA_API_ELEMENT_H

#include "util/defines.h"
#include "util/fixed_string.h"

#include <concepts>
#include <string_view>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// The registry's category attribute, plus Scalar and Void for the C types the registry does not mark.
struct Category
{};

GFXRECON_BEGIN_NAMESPACE(category)

struct Struct : Category
{};
struct Union : Category
{};
struct Enum : Category
{};
struct Bitmask : Category
{};
struct Handle : Category
{};
struct Funcpointer : Category
{};
struct Scalar : Category
{};
struct Void : Category
{};

// Interim, until plan 2.4 stage 3. An opaque element becomes Void or a deref_ element with source_type; text becomes
// a Char or WChar scalar with a length token on the field, and the text attribute word a binding on the element.
struct Opaque : Category
{};
struct Text : Category
{};
struct Char : Text
{};
struct WChar : Text
{};

GFXRECON_END_NAMESPACE(category)

// The generator emits ApiElementBase directly for the interim categories only; every other element derives from its
// category's base below.
template <util::FixedString Name, typename ElementType, typename Category>
struct ApiElementBase
{
    static constexpr std::string_view name = Name.view();
    using element_type                     = ElementType;
    using category                         = Category;
};

template <typename T>
concept ApiElement = requires
{
    typename T::element_type;
    typename T::category;
    {
        T::name
        } -> std::convertible_to<std::string_view>;
};

template <util::FixedString Name, typename ElementType>
struct ApiElementScalar : ApiElementBase<Name, ElementType, category::Scalar>
{};

template <util::FixedString Name, typename ElementType>
struct ApiElementHandle : ApiElementBase<Name, ElementType, category::Handle>
{};

template <util::FixedString Name, typename ElementType>
struct ApiElementStruct : ApiElementBase<Name, ElementType, category::Struct>
{};

template <util::FixedString Name, typename ElementType>
struct ApiElementUnion : ApiElementBase<Name, ElementType, category::Union>
{};

template <util::FixedString Name, typename ElementType>
struct ApiElementFuncpointer : ApiElementBase<Name, ElementType, category::Funcpointer>
{};

template <util::FixedString Name, typename ElementType>
struct ApiElementVoid : ApiElementBase<Name, ElementType, category::Void>
{};

// A structure with a structure type: the value of its sType member, the registry's values attribute.
template <util::FixedString Name, typename ElementType, auto kStructureType>
struct ApiElementTypedStruct : ApiElementBase<Name, ElementType, category::Struct>
{
    static constexpr auto structure_type = kStructureType;
};

template <util::FixedString Name, typename ElementType, typename Table>
struct ApiElementEnum : ApiElementBase<Name, ElementType, category::Enum>
{
    using enumerants = Table;
};

// flags_type: the VkFlags or VkFlags64 element the typedef is declared over. bitvalues: the bits enum element, or
// EmptyBitvalues or EmptyBitvalues64 when the registry names none.
template <util::FixedString Name, typename ElementType, typename FlagsType, typename Bitvalues>
struct ApiElementBitmask : ApiElementBase<Name, ElementType, category::Bitmask>
{
    using flags_type = FlagsType;
    using bitvalues  = Bitvalues;
};

// The extension chain, as an element. A pNext member points at a node whose type is chosen at run time by its
// structure type, and C spells that target void. The element is API-neutral because OpenXR's next chain is the same
// thing, so it lives here and not in an API's element namespace.
struct ExtensionChain : ApiElementVoid<"ExtensionChain", void>
{};

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_API_ELEMENT_H
