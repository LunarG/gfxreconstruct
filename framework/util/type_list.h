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

#ifndef GFXRECON_UTIL_TYPE_LIST_H
#define GFXRECON_UTIL_TYPE_LIST_H

#include "util/defines.h"

#include <concepts>
#include <tuple>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <typename... Types>
struct TypeList
{};

template <typename T>
struct IsTypeList : std::false_type
{};

template <typename... Types>
struct IsTypeList<TypeList<Types...>> : std::true_type
{};

template <typename T>
concept TypeListType = IsTypeList<T>::value;

template <typename List, typename T>
struct TypeListContains : std::false_type
{};

template <typename T, typename... Types>
struct TypeListContains<TypeList<Types...>, T> : std::bool_constant<(std::same_as<Types, T> || ...)>
{};

template <typename List, typename T>
inline constexpr bool TypeListContainsV = TypeListContains<List, T>::value;

template <typename... Types, typename Function>
constexpr void ForEachTypeImpl(TypeList<Types...>, Function&& function)
{
    (function.template operator()<Types>(), ...);
}

template <typename List, typename Function>
constexpr void ForEachType(Function&& function)
{
    ForEachTypeImpl(List{}, std::forward<Function>(function));
}

template <typename... Fields, typename Accessor, typename Function>
decltype(auto) ApplyFieldsImpl(TypeList<Fields...>, Accessor&& accessor, Function&& function)
{
    return std::forward<Function>(function)(accessor(Fields{})...);
}

template <typename List, typename Accessor, typename Function>
decltype(auto) ApplyFields(Accessor&& accessor, Function&& function)
{
    return ApplyFieldsImpl(List{}, std::forward<Accessor>(accessor), std::forward<Function>(function));
}

template <typename List, typename Accessor>
decltype(auto) ApplyFieldsToTuple(Accessor&& accessor)
{
    return ApplyFields<List>(std::forward<Accessor>(accessor), [](auto&&... values) {
        return std::forward_as_tuple(std::forward<decltype(values)>(values)...);
    });
}

template <typename List, typename Accessor>
auto ApplyFieldsToValueTuple(Accessor&& accessor)
{
    return ApplyFields<List>(std::forward<Accessor>(accessor),
                             [](auto&&... values) { return std::make_tuple(std::forward<decltype(values)>(values)...); });
}

GFXRECON_BEGIN_NAMESPACE(detail)

template <typename... Types>
struct TypeListFragment
{
    using type = TypeList<Types...>;
};

template <typename... Left, typename... Right>
constexpr auto operator+(TypeListFragment<Left...>, TypeListFragment<Right...>) -> TypeListFragment<Left..., Right...>
{
    return {};
}

template <template <typename> class Predicate, typename... Types>
constexpr auto TypeListKeepImpl(TypeList<Types...>) -> typename decltype((
    TypeListFragment<>{} + ... +
    std::conditional_t<Predicate<Types>::value, TypeListFragment<Types>, TypeListFragment<>>{}))::type;

template <template <typename> class Predicate, typename... Types>
constexpr auto TypeListDropImpl(TypeList<Types...>) -> typename decltype((
    TypeListFragment<>{} + ... +
    std::conditional_t<Predicate<Types>::value, TypeListFragment<>, TypeListFragment<Types>>{}))::type;

template <typename List>
struct TypeListSoleImpl;

template <typename Type>
struct TypeListSoleImpl<TypeList<Type>>
{
    using type = Type;
};

GFXRECON_END_NAMESPACE(detail)

template <typename List, template <typename> class Predicate>
using TypeListKeep = decltype(detail::TypeListKeepImpl<Predicate>(List{}));

template <typename List, template <typename> class Predicate>
using TypeListDrop = decltype(detail::TypeListDropImpl<Predicate>(List{}));

template <typename List>
using TypeListSole = typename detail::TypeListSoleImpl<List>::type;

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_TYPE_LIST_H
