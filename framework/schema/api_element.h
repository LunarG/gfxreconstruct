/*
** Copyright (c) 2026 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to
** deal in the Software without restriction, including without limitation the
** rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
** sell copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:
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

// What an API element is. An API element is the schema's name for one named thing in the API: a structure, a union,
// a handle, an enumerated type, a scalar typedef, a command. The generated element namespaces derive every element
// from the base here, so one base check tells an element from anything else, and an element is the leaf of a field's
// declaration (schema/field.h). This header is what a generated types header includes, so it names nothing a field
// needs.

#ifndef GFXRECON_SCHEMA_API_ELEMENT_H
#define GFXRECON_SCHEMA_API_ELEMENT_H

#include "format/format.h"
#include "util/defines.h"

#include "util/fixed_string.h"

#include <concepts>
#include <string_view>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// An element's base states the three facts every element carries, in the Field<Name, Declaration> order: the name
// first, then the API's own type, then the category. The derived bases below fix the category and fill the one
// member that category carries, so an element's body states only what no category carries.
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

// A structure with a structure type: the value of its sType member, the registry's values attribute.
template <util::FixedString Name, typename ElementType, auto kStructureType>
struct ApiElementTypedStruct : ApiElementBase<Name, ElementType, format::category::Struct>
{
    static constexpr auto structure_type = kStructureType;
};

// An enumerated type and its enumerant table.
template <util::FixedString Name, typename ElementType, typename Table>
struct ApiElementEnum : ApiElementBase<Name, ElementType, format::category::Enum>
{
    using enumerants = Table;
};

// A bits enumeration: its table and the flags typedef the registry pairs it with, VkFlags or VkFlags64. The
// category is Enum for a C enum and Flags64 for a 64-bit bits type, which C declares as a typedef of VkFlags64.
template <util::FixedString Name, typename ElementType, typename Category, typename Table, typename Bitmask>
struct ApiElementFlagBits : ApiElementBase<Name, ElementType, Category>
{
    using enumerants = Table;
    using bitmask    = Bitmask;
};

// A flags typedef: the category is Flags or Flags64 by width, and bitvalues names its bits enumeration.
template <util::FixedString Name, typename ElementType, typename Category, typename BitValues>
struct ApiElementBitmask : ApiElementBase<Name, ElementType, Category>
{
    using bitvalues = BitValues;
};

// The extension chain, as an element. A pNext member points at a node whose type is chosen at run time by its
// structure type, and C spells that target void. The element is API-neutral because OpenXR's next chain is the same
// thing, so it lives here and not in an API's element namespace.
struct ExtensionChain : ApiElementBase<"ExtensionChain", void, format::category::Void>
{};

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_API_ELEMENT_H
