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

// This header declares TypeList, a compile-time list of types, and the algorithms over it:
//   - TypeListCountIf, TypeListKeep, TypeListDrop and TypeListExclude count or filter by a predicate over types;
//   - TypeListFront_t, TypeListSole_t, TypeListSize_v and TypeListContains_v query the list;
//   - TypeListForEach and ApplyFields call a function once per element, or once with every element;
//   - IndexPosition and Visit go from a position an index found at run time to the element at that position.
// A Schema's Field list and an API's generated catalog lists are TypeLists. Only the filters recurse on the list, 32
// elements per step (see TypeListConcat); every other algorithm is flat.
//
// Limitations:
//   - A predicate must be a captureless lambda or an empty struct; see below.
//   - Visit instantiates the visitor for every element of the list, whether or not a call reaches it.
//
// Typical pattern:
//   using Kept = decltype(util::TypeListKeep(List{}, []<typename T>() { return std::is_enum_v<T>; }));
#ifndef GFXRECON_UTIL_TYPE_LIST_H
#define GFXRECON_UTIL_TYPE_LIST_H

#include "util/defines.h"

#include "util/logging.h"

#include <array>
#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

template <typename... Types>
struct TypeList
{};

// IsTypeList_v is true for a TypeList of any length.
template <typename T>
struct IsTypeList : std::false_type
{};

template <typename... Types>
struct IsTypeList<TypeList<Types...>> : std::true_type
{};

template <typename T>
inline constexpr bool IsTypeList_v = IsTypeList<T>::value;

// Every algorithm here that reduces a pack does so through a braced array and a constexpr loop, never a fold
// expression: clang instantiates a fold as nested binary expressions, one level per element, and stops at depth 256,
// while a braced list is one node at any length. A catalog list has more than 256 elements.

template <size_t N>
constexpr size_t CountOf(const std::array<bool, N>& values)
{
    size_t count = 0;
    for (bool value : values)
    {
        count += value ? 1 : 0;
    }
    return count;
}

// A predicate over types is a captureless lambda with a template call operator and no parameters,
// []<typename T>() { return ...; }, the shape TypeListForEach's visitors take; it wraps a concept in one line. The
// algorithms call Predicate{}, not the argument, so the call is a constant expression. A capturing lambda fails to
// compile: it is not default constructible.
// NOTE: a predicate written inside a function template that takes the list MUST be a struct with a template call
// operator, as detail::ContainedIn is. A lambda there carries the whole list in its type, and GCC then writes one
// symbol that long per element: 4.6 s per including file on a 1,365-element list.

GFXRECON_BEGIN_NAMESPACE(detail)

// Not negates a predicate, for TypeListDrop.
template <typename Predicate>
struct Not
{
    template <typename T>
    constexpr bool operator()() const
    {
        return !Predicate{}.template operator()<T>();
    }
};

template <typename... Types, typename Predicate>
constexpr size_t TypeListCountIfImpl(TypeList<Types...>, Predicate)
{
    return CountOf(std::array<bool, sizeof...(Types)>{ Predicate{}.template operator()<Types>()... });
}

template <typename... Types, typename Function>
constexpr void TypeListForEachImpl(TypeList<Types...>, Function&& function)
{
    (void)std::initializer_list<int>{ (function.template operator()<Types>(), 0)... };
}

template <typename... Fields, typename Accessor, typename Function>
decltype(auto) ApplyFieldsImpl(TypeList<Fields...>, Accessor&& accessor, Function&& function)
{
    return std::forward<Function>(function)(accessor(Fields{})...);
}

GFXRECON_END_NAMESPACE(detail)

// Returns how many elements satisfy the predicate. All, any and none are comparisons on this count, so they have no
// algorithm of their own.
template <typename List, typename Predicate>
constexpr size_t TypeListCountIf(List, Predicate)
{
    return detail::TypeListCountIfImpl(List{}, Predicate{});
}

// Calls function.operator()<T>() once per element, in list order.
template <typename List, typename Function>
constexpr void TypeListForEach(Function&& function)
{
    detail::TypeListForEachImpl(List{}, std::forward<Function>(function));
}

// Calls function once, with accessor(Field{}) for every element as its arguments.
template <typename List, typename Accessor, typename Function>
decltype(auto) ApplyFields(Accessor&& accessor, Function&& function)
{
    return detail::ApplyFieldsImpl(List{}, std::forward<Accessor>(accessor), std::forward<Function>(function));
}

GFXRECON_BEGIN_NAMESPACE(detail)

// SameAs<T> is the predicate true of T only, for TypeListContains_v.
template <typename T>
struct SameAs
{
    template <typename U>
    constexpr bool operator()() const
    {
        return std::is_same_v<T, U>;
    }
};

GFXRECON_END_NAMESPACE(detail)

// TypeListContains_v is true when T is in the list. Each query is one pass over the list.
template <typename List, typename T>
inline constexpr bool TypeListContains_v = TypeListCountIf(List{}, detail::SameAs<T>{}) != 0;

GFXRECON_BEGIN_NAMESPACE(detail)

// ContainedIn<List> is the predicate true of the elements of List, for TypeListExclude.
template <typename List>
struct ContainedIn
{
    template <typename T>
    constexpr bool operator()() const
    {
        return TypeListContains_v<List, T>;
    }
};

// TypeListConcat joins lists into one. A step joins 32, 8 or 2 lists and recurses on the rest, so N lists nest about
// N / 31 deep. NOTE: the 32-wide step MUST stay. MSVC stops at 499 nested instantiations, which 8-wide steps alone
// reach near 3,500 lists. The 8-wide and 2-wide steps join what is left when fewer than 32 remain.
template <typename... Lists>
struct TypeListConcat;

template <>
struct TypeListConcat<>
{
    using type = TypeList<>;
};

template <typename... Types>
struct TypeListConcat<TypeList<Types...>>
{
    using type = TypeList<Types...>;
};

template <typename... T0, typename... T1, typename... Rest>
struct TypeListConcat<TypeList<T0...>, TypeList<T1...>, Rest...> : TypeListConcat<TypeList<T0..., T1...>, Rest...>
{};

// clang-format off
template <typename... T0, typename... T1, typename... T2, typename... T3,
          typename... T4, typename... T5, typename... T6, typename... T7,
          typename... Rest>
struct TypeListConcat<TypeList<T0...>, TypeList<T1...>, TypeList<T2...>, TypeList<T3...>,
                      TypeList<T4...>, TypeList<T5...>, TypeList<T6...>, TypeList<T7...>,
                      Rest...>
    : TypeListConcat<TypeList<T0..., T1..., T2..., T3..., T4..., T5..., T6..., T7...>, Rest...>
{};

template <typename... T0,  typename... T1,  typename... T2,  typename... T3,
          typename... T4,  typename... T5,  typename... T6,  typename... T7,
          typename... T8,  typename... T9,  typename... T10, typename... T11,
          typename... T12, typename... T13, typename... T14, typename... T15,
          typename... T16, typename... T17, typename... T18, typename... T19,
          typename... T20, typename... T21, typename... T22, typename... T23,
          typename... T24, typename... T25, typename... T26, typename... T27,
          typename... T28, typename... T29, typename... T30, typename... T31,
          typename... Rest>
struct TypeListConcat<TypeList<T0...>,  TypeList<T1...>,  TypeList<T2...>,  TypeList<T3...>,
                      TypeList<T4...>,  TypeList<T5...>,  TypeList<T6...>,  TypeList<T7...>,
                      TypeList<T8...>,  TypeList<T9...>,  TypeList<T10...>, TypeList<T11...>,
                      TypeList<T12...>, TypeList<T13...>, TypeList<T14...>, TypeList<T15...>,
                      TypeList<T16...>, TypeList<T17...>, TypeList<T18...>, TypeList<T19...>,
                      TypeList<T20...>, TypeList<T21...>, TypeList<T22...>, TypeList<T23...>,
                      TypeList<T24...>, TypeList<T25...>, TypeList<T26...>, TypeList<T27...>,
                      TypeList<T28...>, TypeList<T29...>, TypeList<T30...>, TypeList<T31...>,
                      Rest...>
    : TypeListConcat<TypeList<T0...,  T1...,  T2...,  T3...,  T4...,  T5...,  T6...,  T7...,
                              T8...,  T9...,  T10..., T11..., T12..., T13..., T14..., T15...,
                              T16..., T17..., T18..., T19..., T20..., T21..., T22..., T23...,
                              T24..., T25..., T26..., T27..., T28..., T29..., T30..., T31...>,
                     Rest...>
{};
// clang-format on

// TypeListKeepImpl turns each element into a one-element list when the predicate holds and an empty list when it
// does not, and joins them. For TypeList<A, B, C> and a predicate true of A and C, the join of TypeList<A>,
// TypeList<> and TypeList<C> is TypeList<A, C>.
template <typename... Types, typename Predicate>
constexpr auto TypeListKeepImpl(TypeList<Types...>, Predicate)
{
    return typename TypeListConcat<
        std::conditional_t<Predicate{}.template operator()<Types>(), TypeList<Types>, TypeList<>>...>::type{};
}

template <typename List>
struct TypeListFront;

template <typename First, typename... Rest>
struct TypeListFront<TypeList<First, Rest...>>
{
    using type = First;
};

template <typename List>
struct TypeListSole;

template <typename Type>
struct TypeListSole<TypeList<Type>>
{
    using type = Type;
};

GFXRECON_END_NAMESPACE(detail)

// TypeListFront_t is the first element; an empty list fails to compile.
template <typename List>
using TypeListFront_t = typename detail::TypeListFront<List>::type;

// Returns the elements whose predicate holds, as a value: using Kept = decltype(TypeListKeep(List{}, kPredicate));
template <typename List, typename Predicate>
constexpr auto TypeListKeep(List, Predicate)
{
    return detail::TypeListKeepImpl(List{}, Predicate{});
}

// Returns the elements whose predicate does not hold, as a value.
template <typename List, typename Predicate>
constexpr auto TypeListDrop(List, Predicate)
{
    return TypeListKeep(List{}, detail::Not<Predicate>{});
}

// Returns the elements of List that are not in Excluded.
template <typename List, typename Excluded>
constexpr auto TypeListExclude(List, Excluded)
{
    return TypeListDrop(List{}, detail::ContainedIn<Excluded>{});
}

// TypeListSole_t is the one element of a one-element list; any other length fails to compile.
template <typename List>
using TypeListSole_t = typename detail::TypeListSole<List>::type;

GFXRECON_BEGIN_NAMESPACE(detail)

// InvokerTable holds one invoker per element, in list order; each calls visitor.operator()<Element>(args...). Visit
// indexes it at run time.
template <typename Visitor, typename ArgsList, typename Elements>
struct InvokerTable;

template <typename Visitor, typename... Args, typename... Elements>
struct InvokerTable<Visitor, TypeList<Args...>, TypeList<Elements...>>
{
    static_assert(sizeof...(Elements) > 0, "Visit: the list is empty");

    using Result = decltype(std::declval<Visitor&>().template operator()<TypeListFront_t<TypeList<Elements...>>>(
        std::declval<Args>()...));

    static_assert(
        TypeListCountIf(TypeList<Elements...>{},
                        []<typename Element>() {
                            return std::is_same_v<Result,
                                                  decltype(std::declval<Visitor&>().template operator()<Element>(
                                                      std::declval<Args>()...))>;
                        }) == sizeof...(Elements),
        "Visit: every operator()<Element> must return one type");

    using Invoker = Result (*)(Visitor&, Args&&...);

    template <typename Element>
    static Result Invoke(Visitor& visitor, Args&&... args)
    {
        return visitor.template operator()<Element>(std::forward<Args>(args)...);
    }

    // Taking each address instantiates Invoke<Element>, and with it the visitor's operator()<Element>, for every
    // element of the list, whether or not a call ever reaches it.
    static constexpr std::array<Invoker, sizeof...(Elements)> invokers{ &Invoke<Elements>... };
};

template <typename List>
struct TypeListSize;

template <typename... Types>
struct TypeListSize<TypeList<Types...>> : std::integral_constant<size_t, sizeof...(Types)>
{};

GFXRECON_END_NAMESPACE(detail)

// TypeListSize_v is the element count.
template <typename List>
inline constexpr size_t TypeListSize_v = detail::TypeListSize<List>::value;

// IndexPosition is where an index's Find landed in its list, or its End. Only the index constructs one and only Visit
// reads it. It is a class template, not a type nested in the index: Visit deduces Index from this parameter, and a
// type reached through Index::, aliased or not, is non-deduced ([temp.deduct.type]/5).
template <typename Index>
class IndexPosition
{
  public:
    using index_type = Index;

    constexpr bool operator==(const IndexPosition&) const = default;

  private:
    friend Index;

    template <typename I, typename Visitor, typename... Args>
    friend decltype(auto) Visit(IndexPosition<I> position, Visitor&& visitor, Args&&... args);

    constexpr explicit IndexPosition(size_t position) : position_(position) {}

    size_t position_;
};

// Calls visitor.operator()<Element>(args...) for the element of the index's list at `position`. Asserts in DEBUG that
// `position` is not Index::End(); compare it against End() before the call.
template <typename Index, typename Visitor, typename... Args>
decltype(auto) Visit(IndexPosition<Index> position, Visitor&& visitor, Args&&... args)
{
    using Table = detail::InvokerTable<std::remove_reference_t<Visitor>, TypeList<Args...>, typename Index::list>;
    static_assert(Table::invokers.size() == Index::kSize, "Visit: the index and the invoker table are over one list");
    GFXRECON_ASSERT(position != Index::End());
    return Table::invokers[position.position_](visitor, std::forward<Args>(args)...);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_TYPE_LIST_H
