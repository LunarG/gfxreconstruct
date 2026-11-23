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

// A Schema is the ordered Field list for one API element; this header holds the algorithms over it.
// NOTE: a Schema specialization is visible only where the API's schema definitions are included; elsewhere
// HasSchemaFields is false and WalkFields rejects the API element.

#ifndef GFXRECON_SCHEMA_SCHEMA_H
#define GFXRECON_SCHEMA_SCHEMA_H

#include "util/defines.h"
#include "schema/field.h"
#include "util/type_list.h"

#include <concepts>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// Schema<ApiElement> is specialized in generated/generated_<api>_schema.h: Fields for a structure or command,
// Alternatives for a union. A command keys on its command API element, a structure on its API element.
template <typename ApiElement>
struct Schema;

// TypedStructApiElement matches an API element with an enum structure_type: a structure the API discriminates by the
// type value in its first member carries that value on its API element.
template <typename Element>
concept TypedStructApiElement = requires
{
    Element::structure_type;
}
&&std::is_enum_v<std::remove_cv_t<decltype(Element::structure_type)>>;

// BitvaluesApiElement matches a bits enum: an enum API element that carries the Bitvalues token.
template <typename Element>
concept BitvaluesApiElement =
    EnumApiElement<Element> && util::TypeListContains_v<typename Element::semantics, semantic::Bitvalues>;

// HasSchemaFields is true when Schema<ApiElement> lists Fields. A union's Schema lists Alternatives, not Fields, so a
// union does not satisfy it; generated/generated_<api>_schema_checks.cpp asserts that.
template <typename ApiElement>
concept HasSchemaFields = requires
{
    typename Schema<ApiElement>::Fields;
    requires util::IsTypeList_v<typename Schema<ApiElement>::Fields>;
};

// kIsReturnField treats an absent is_return member as false, so only a command's return Field states it.
inline constexpr auto kIsReturnField = []<typename Field>() {
    return requires
    {
        requires Field::is_return;
    };
};

template <HasSchemaFields ApiElement>
using ReturnFields_t = decltype(util::TypeListKeep(typename Schema<ApiElement>::Fields{}, kIsReturnField));

// HasCommandSchema is true when the Schema has exactly one is_return Field, which makes it a command Schema; a
// structure Schema has none.
template <typename ApiElement>
concept HasCommandSchema = HasSchemaFields<ApiElement> && requires
{
    typename util::TypeListSole_t<ReturnFields_t<ApiElement>>;
};

template <HasCommandSchema ApiElement>
using ReturnField_t = util::TypeListSole_t<ReturnFields_t<ApiElement>>;

template <HasCommandSchema ApiElement>
using ParameterFields_t = decltype(util::TypeListDrop(typename Schema<ApiElement>::Fields{}, kIsReturnField));

template <typename Action, typename Storage, typename Field>
concept FieldActionFor = requires(Action& action, Storage& storage, Field field)
{
    action.Apply(storage, field);
};

// Calls action.Apply(storage, Field{}) for each Field in Schema order; overload resolution selects the Apply from the
// Field's declaration shape. If no overload accepts a Field, the static_assert below stops the compile and the
// diagnostic shows the Field.
template <HasSchemaFields ApiElement, typename Action, typename Storage>
void WalkFields(Action& action, Storage& storage)
{
    util::TypeListForEach<typename Schema<ApiElement>::Fields>([&]<typename Field>() {
        if constexpr (FieldActionFor<Action, Storage, Field>)
        {
            action.Apply(storage, Field{});
        }
        else
        {
            static_assert(FieldActionFor<Action, Storage, Field>, "Action must support Apply(Storage&, Field)");
        }
    });
}

GFXRECON_BEGIN_NAMESPACE(detail)

template <typename ApiElement, typename Function, typename Storage, typename... Fields>
constexpr bool InvocableFromFieldsImpl(util::TypeList<Fields...>)
{
    return requires(Function && function, Storage & storage)
    {
        {
            std::forward<Function>(function)(Fields::GetRef(storage)...)
            } -> std::same_as<ApiTypeOf_t<typename ReturnField_t<ApiElement>::api_element>>;
    };
}

GFXRECON_END_NAMESPACE(detail)

template <typename ApiElement, typename Function, typename Storage>
concept InvocableFromFields = HasCommandSchema<ApiElement> &&
    detail::InvocableFromFieldsImpl<ApiElement, Function, Storage>(ParameterFields_t<ApiElement>{});

// Calls function(Parameter::GetRef(storage)...) with the command's parameters in Schema order and returns its result.
// InvocableFromFields requires the result to be the return Field's C type.
template <HasCommandSchema ApiElement, typename Function, typename Storage>
requires InvocableFromFields<ApiElement, Function, Storage>
decltype(auto) InvokeFromFields(Function&& function, Storage& storage)
{
    return util::ApplyFields<ParameterFields_t<ApiElement>>(
        [&]<typename Field>(Field) -> decltype(auto) { return Field::GetRef(storage); },
        std::forward<Function>(function));
}

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_SCHEMA_H
