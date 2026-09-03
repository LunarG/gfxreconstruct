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

// Schema algorithms. This header composes the field-model vocabulary with the schema-independent TypeList facility.
// It defines no API type descriptor and no Field descriptor; those are generated content.

#ifndef GFXRECON_SCHEMA_SCHEMA_UTIL_H
#define GFXRECON_SCHEMA_SCHEMA_UTIL_H

#include "util/defines.h"
#include "schema/field_model.h"
#include "util/type_list.h"

#include <concepts>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

// One traits-class template maps an API element to its canonical field list. A command keys on its command tag; a
// structure keys on its native type.
template <typename ApiElement>
struct Schema;

template <typename ApiElement>
concept HasSchema = requires {
    typename Schema<ApiElement>::Fields;
    requires util::TypeListType<typename Schema<ApiElement>::Fields>;
};

// The return predicate treats an absent is_return member as false.
template <typename Field>
struct IsReturnField : std::bool_constant<requires { requires Field::is_return; }>
{};

template <HasSchema ApiElement>
using ReturnMatches = util::TypeListKeep<typename Schema<ApiElement>::Fields, IsReturnField>;

// A command schema is invalid when the partition finds zero or more than one return Field. The same validation
// distinguishes a command schema from a structure schema.
template <typename ApiElement>
concept HasCommandSchema =
    HasSchema<ApiElement> && requires { typename util::TypeListSole<ReturnMatches<ApiElement>>; };

template <HasCommandSchema ApiElement>
using Return = util::TypeListSole<ReturnMatches<ApiElement>>;

template <HasCommandSchema ApiElement>
using ReturnType = ElementType<typename Return<ApiElement>::api_type>;

template <HasCommandSchema ApiElement>
using ParameterFields = util::TypeListDrop<typename Schema<ApiElement>::Fields, IsReturnField>;

template <typename Action, typename Field, typename FieldStore>
concept FieldActionFor = requires(Action& action, Field field, FieldStore& store) { action.Apply(field, store); };

// One field walk serves every operation family. The Action supplies one Apply overload set, and overload resolution
// selects the implementation from the field's logical kind and shape.
template <HasSchema ApiElement, typename Action, typename FieldStore>
void WalkFields(Action& action, FieldStore& store)
{
    util::ForEachType<typename Schema<ApiElement>::Fields>([&]<typename Field>() {
        if constexpr (FieldActionFor<Action, Field, FieldStore>)
        {
            action.Apply(Field{}, store);
        }
        else
        {
            static_assert(FieldActionFor<Action, Field, FieldStore>, "Action must support Apply(Field, FieldStore&)");
        }
    });
}

GFXRECON_BEGIN_NAMESPACE(detail)

template <typename ApiElement, typename Function, typename FieldStore, typename... Fields>
constexpr bool InvocableFromFieldsImpl(util::TypeList<Fields...>)
{
    return requires(Function&& function, FieldStore& store) {
        { std::forward<Function>(function)(GetRef(store, Fields{})...) } -> std::same_as<ReturnType<ApiElement>>;
    };
}

GFXRECON_END_NAMESPACE(detail)

template <typename ApiElement, typename Function, typename FieldStore>
concept InvocableFromFields =
    HasCommandSchema<ApiElement> &&
    detail::InvocableFromFieldsImpl<ApiElement, Function, FieldStore>(ParameterFields<ApiElement>{});

// The positional invocation step. This expands to the same positional call that the hand-written replay path already
// makes, in canonical parameter order.
template <HasCommandSchema ApiElement, typename Function, typename FieldStore>
    requires InvocableFromFields<ApiElement, Function, FieldStore>
decltype(auto) InvokeFromFields(Function&& function, FieldStore& store)
{
    return util::ApplyFields<ParameterFields<ApiElement>>(
        [&](auto field) -> decltype(auto) { return GetRef(store, field); }, std::forward<Function>(function));
}

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_SCHEMA_UTIL_H
