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

// An API element is the C++ type for one type of the API. It holds the name in the API description, the C type
// (element_type) and the category. Each derives from the base below for its category. A command's API element is an
// empty tag and does not satisfy ApiElement.

#ifndef GFXRECON_SCHEMA_API_ELEMENT_H
#define GFXRECON_SCHEMA_API_ELEMENT_H

#include "util/defines.h"
#include "util/fixed_string.h"
#include "util/type_list.h"

#include <concepts>
#include <string_view>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// Category is the category the API description gives the type (Vulkan: the registry's category attribute), with two
// exceptions:
//   - Scalar: the types the API description declares over a C type (Vulkan: the registry's basetype types), plus the
//     C types it does not mark (uint32_t, float, char).
//   - Void: void, plus the platform types curation gives no C definition (ANativeWindow, and deref_HWND for the type
//     HWND points at).
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

GFXRECON_END_NAMESPACE(category)

// A semantic token states a fact about an API element that its category cannot. An API element lists its tokens in
// semantics.
GFXRECON_BEGIN_NAMESPACE(semantic)

// Bitvalues: the enum is a bits enum (Vulkan: the registry's bitvalues; its group is declared type="bitmask").
struct Bitvalues
{};

GFXRECON_END_NAMESPACE(semantic)

// ApiElementBase holds the members every API element carries; semantics is empty unless the API element declares its
// own. An API element whose category or element_type departs from what the API description says keeps the source: a
// type declared over a C type states source_category (Vulkan: "basetype"); a deref_ element, declared for the type a
// platform typedef points at, states the typedef as source_type (::HWND). Neither member exists where the schema
// says what the source says.
template <util::FixedString Name, typename ElementType, typename Category>
struct ApiElementBase
{
    static constexpr std::string_view name = Name.view();
    using element_type                     = ElementType;
    using category                         = Category;
    using semantics                        = util::TypeList<>;
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

// ApiElementTypedStruct is the base for a structure with a structure type member (Vulkan: sType). structure_type is
// the value of that member for this structure (Vulkan: the registry's values attribute).
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

// flags_type is the API element the typedef is declared over (Vulkan: VkFlags or VkFlags64). bitvalues is the bits
// enum API element, or EmptyBitvalues or EmptyBitvalues64 when the API description gives no bits enum.
template <util::FixedString Name, typename ElementType, typename FlagsType, typename Bitvalues>
struct ApiElementBitmask : ApiElementBase<Name, ElementType, category::Bitmask>
{
    using flags_type = FlagsType;
    using bitvalues  = Bitvalues;
};

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_API_ELEMENT_H
