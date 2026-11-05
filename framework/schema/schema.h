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

// A Schema is the arrangement: the canonical, ordered Field list for one API element, and the algorithms over it.
// It composes schema/field.h with the schema-independent TypeList facility, and defines no API element and
// no Field -- those are generated content.

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

// One traits-class template maps an API element to its canonical field list. A command keys on its command API element
// and a structure on its API element.
template <typename ApiElement>
struct Schema;

// A structure the API discriminates by a type value in its first member carries that value on its API element.
template <typename Element>
concept TypedStructApiElement = requires
{
    Element::structure_type;
}
&&std::is_enum_v<std::remove_cv_t<decltype(Element::structure_type)>>;

// A bits enum, the registry's bitvalues: an enum whose group the registry declares type="bitmask".
template <typename Element>
concept BitvaluesApiElement = EnumApiElement<Element> && requires
{
    requires Element::kBitvalues;
};

// A union's Schema lists Alternatives, not Fields, so a union does not satisfy this; the generated checks assert it.
template <typename ApiElement>
concept HasSchemaFields = requires
{
    typename Schema<ApiElement>::Fields;
    requires util::IsTypeList_v<typename Schema<ApiElement>::Fields>;
};

// The return predicate treats an absent is_return member as false.
inline constexpr auto kIsReturnField = []<typename Field>() {
    return requires
    {
        requires Field::is_return;
    };
};

template <HasSchemaFields ApiElement>
using ReturnFields_t = decltype(util::TypeListKeep(typename Schema<ApiElement>::Fields{}, kIsReturnField));

// A command schema is invalid when the partition finds zero or more than one return Field. The same validation
// distinguishes a command schema from a structure schema.
template <typename ApiElement>
concept HasCommandSchema = HasSchemaFields<ApiElement> && requires
{
    typename util::TypeListSole_t<ReturnFields_t<ApiElement>>;
};

template <HasCommandSchema ApiElement>
using ReturnField_t = util::TypeListSole_t<ReturnFields_t<ApiElement>>;

template <HasCommandSchema ApiElement>
using ParameterFields_t = decltype(util::TypeListDrop(typename Schema<ApiElement>::Fields{}, kIsReturnField));

template <typename Action, typename Field, typename Storage>
concept FieldActionFor = requires(Action& action, Field field, Storage& storage)
{
    action.Apply(field, storage);
};

// One field walk serves every operation family. The Action supplies one Apply overload set, and overload resolution
// selects the implementation from the field's logical category and shape.
template <HasSchemaFields ApiElement, typename Action, typename Storage>
void WalkFields(Action& action, Storage& storage)
{
    util::TypeListForEach<typename Schema<ApiElement>::Fields>([&]<typename Field>() {
        if constexpr (FieldActionFor<Action, Field, Storage>)
        {
            action.Apply(Field{}, storage);
        }
        else
        {
            static_assert(FieldActionFor<Action, Field, Storage>, "Action must support Apply(Field, Storage&)");
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
            std::forward<Function>(function)(GetRef(storage, Fields{})...)
            } -> std::same_as<ApiTypeOf_t<typename ReturnField_t<ApiElement>::api_element>>;
    };
}

GFXRECON_END_NAMESPACE(detail)

template <typename ApiElement, typename Function, typename Storage>
concept InvocableFromFields = HasCommandSchema<ApiElement> &&
    detail::InvocableFromFieldsImpl<ApiElement, Function, Storage>(ParameterFields_t<ApiElement>{});

// The positional invocation step. This expands to the same positional call that the hand-written replay path already
// makes, in canonical parameter order.
template <HasCommandSchema ApiElement, typename Function, typename Storage>
requires InvocableFromFields<ApiElement, Function, Storage>
decltype(auto) InvokeFromFields(Function&& function, Storage& storage)
{
    return util::ApplyFields<ParameterFields_t<ApiElement>>(
        [&](auto field) -> decltype(auto) { return GetRef(storage, field); }, std::forward<Function>(function));
}

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_SCHEMA_H
