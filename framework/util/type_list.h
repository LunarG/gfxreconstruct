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
//   - TypeListAt_t, TypeListSole_t, TypeListPopFront_t, TypeListSize_v and TypeListContains_v query the list;
//   - TypeListForEach and ApplyFields call a function once per element, or once with every element;
//   - IndexPosition and Visit go from a position an index found at run time to the element at that position.
// A Schema's Field list and the catalog lists (binding/vulkan_catalog.h) are TypeLists. No algorithm recurses on the
// list, so a catalog list costs no more per element than a Field list.
//
// Limitations:
//   - A predicate must be a captureless lambda; see below.
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

// Returns the positions of the true entries, in order. Count must be CountOf(values).
template <size_t Count, size_t N>
constexpr std::array<size_t, Count> PositionsOf(const std::array<bool, N>& values)
{
    std::array<size_t, Count> positions{};
    size_t                    next = 0;
    for (size_t i = 0; i < N; ++i)
    {
        if (values[i])
        {
            positions[next++] = i;
        }
    }
    return positions;
}

// A predicate over types is a captureless lambda with a template call operator and no parameters,
// []<typename T>() { return ...; }, the shape TypeListForEach's visitors take; it wraps a concept in one line. The
// algorithms call Predicate{}, not the argument, so the call is a constant expression. A capturing lambda fails to
// compile: it is not default constructible.

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
// Calls function.operator()<T>() once per element, in list order.
template <typename List, typename Function>
constexpr void TypeListForEach(Function&& function)
{
    detail::TypeListForEachImpl(List{}, std::forward<Function>(function));
}

// Calls function once, with accessor(Field{}) for every element as its arguments.
// Calls function once, with accessor(Field{}) for every element as its arguments.
template <typename List, typename Accessor, typename Function>
decltype(auto) ApplyFields(Accessor&& accessor, Function&& function)
{
    return detail::ApplyFieldsImpl(List{}, std::forward<Accessor>(accessor), std::forward<Function>(function));
}

GFXRECON_BEGIN_NAMESPACE(detail)

// TypeListAt_t without recursion: the multiple-inheritance indexer of Agustín Bergé's "True Story: Efficient Packing"
// (talesofcpp.fusionfenix.com/post-22), benchmarked in Louis Dionne's "Efficient parameter pack indexing" (2015).
// The obvious forms, a recursive walk or a fold, nest one level per element and fail to compile past clang's limit of
// 256 on a catalog-sized list; this form is flat, one base per element, so a lookup is one deduction at any length.
// C++26 pack indexing and the __type_pack_element builtin do the same, but not on every toolchain we build with.
//
// Indexer derives from Indexed<I, T> for every element: for TypeList<A, B, C> its bases are Indexed<0, A>,
// Indexed<1, B> and Indexed<2, C>. PickIndexed<1>(Indexer{}) deduces T from the one base of the form Indexed<1, T>,
// so decltype of the call is Indexed<1, B>, and its ::type is B. std::tuple_element is not used: it recurses on MSVC.
//
// Each Indexed also derives from Holder<T>, so the same Indexer is a set: TypeListContains_v<List, B> is one
// is_base_of<Holder<B>, Indexer> test. A repeated element makes Holder<T> an ambiguous base, which std::is_base_of
// still reports as a base ([meta.rel]), so a list with duplicates works.
template <typename T>
struct Holder
{};

template <size_t I, typename T>
struct Indexed : Holder<T>
{
    using type = T;
};

template <typename Sequence, typename... Types>
struct Indexer;

template <size_t... Is, typename... Types>
struct Indexer<std::index_sequence<Is...>, Types...> : Indexed<Is, Types>...
{};

template <typename List>
struct IndexerOf;

template <typename... Types>
struct IndexerOf<TypeList<Types...>>
{
    using type = Indexer<std::index_sequence_for<Types...>, Types...>;
};

template <size_t I, typename T>
Indexed<I, T> PickIndexed(Indexed<I, T>); // declared only; its type is the answer

template <size_t I, typename List>
struct TypeListAt;

template <size_t I, typename... Types>
struct TypeListAt<I, TypeList<Types...>>
{
    static_assert(I < sizeof...(Types), "TypeListAt_t: position past the end of the list");
    using type = typename decltype(PickIndexed<I>(Indexer<std::index_sequence_for<Types...>, Types...>{}))::type;
};

// PositionSequence turns a constexpr array of positions into an index_sequence. The one value-to-template-argument
// step is here; a later expansion takes the positions as template arguments and evaluates no subscript inside a
// template argument list, which MSVC rejects for a raw array member (C3546).
template <auto Positions, size_t... Is>
std::index_sequence<Positions[Is]...> PositionSequence(std::index_sequence<Is...>);

template <auto Positions>
using PositionSequence_t = decltype(PositionSequence<Positions>(std::make_index_sequence<Positions.size()>{}));

// TypeListKeep keeps the elements whose predicate holds, in four flat steps. Each step is one constexpr evaluation or
// one pack expansion, so the instantiation depth is the same at any list length; the textbook filter recurses once
// per element, and its depth grows with the list. For TypeList<A, B, C> and a predicate true of A and C:
//   1. kSelected, the predicate result per element:     { true, false, true }
//   2. kPositions, the positions of the true entries:   { 0, 2 }
//   3. PositionSequence_t<kPositions>:                  std::index_sequence<0, 2>
//   4. Pick, TypeListAt_t at each position:             TypeList<A, C>
template <typename... Types, size_t... Positions>
TypeList<typename TypeListAt<Positions, TypeList<Types...>>::type...>
    Pick(TypeList<Types...>, std::index_sequence<Positions...>); // declared only; its type is the answer

template <typename... Types, typename Predicate>
constexpr auto TypeListKeepImpl(TypeList<Types...>, Predicate)
{
    constexpr std::array<bool, sizeof...(Types)> kSelected{ Predicate{}.template operator()<Types>()... };
    constexpr auto                               kPositions = PositionsOf<CountOf(kSelected)>(kSelected);
    return decltype(Pick(TypeList<Types...>{}, PositionSequence_t<kPositions>{})){};
}

template <typename List>
struct TypeListSole;

template <typename Type>
struct TypeListSole<TypeList<Type>>
{
    using type = Type;
};

template <typename First, typename... Rest>
TypeList<Rest...> TypeListPopFront(TypeList<First, Rest...>); // declared only; its type is the answer

GFXRECON_END_NAMESPACE(detail)

template <size_t I, typename List>
using TypeListAt_t = typename detail::TypeListAt<I, List>::type;

// TypeListContains_v is true when T is in the list: one base-class lookup on the Indexer, not a pass over the list.
// NOTE: MUST NOT be rewritten as a TypeListCountIf -- a count is a pass over the list per query, so TypeListExclude,
// which queries once per element, would compile in time quadratic in the list length.
template <typename List, typename T>
inline constexpr bool TypeListContains_v = std::is_base_of_v<detail::Holder<T>, typename detail::IndexerOf<List>::type>;

// Returns the elements whose predicate holds, as a value: using Kept = decltype(TypeListKeep(List{}, kPredicate));
template <typename List, typename Predicate>
constexpr auto TypeListKeep(List, Predicate)
{
    return detail::TypeListKeepImpl(List{}, Predicate{});
}

// Returns the elements whose predicate does not hold, as a value.
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
    return TypeListDrop(List{}, []<typename T>() { return TypeListContains_v<Excluded, T>; });
}

// TypeListSole_t is the one element of a one-element list; any other length fails to compile.
// TypeListSole_t is the one element of a one-element list; any other length fails to compile.
template <typename List>
using TypeListSole_t = typename detail::TypeListSole<List>::type;

// TypeListPopFront_t is the list without its first element: one deduction at any length.
// GFXRECON_INVENTORY_TYPE_LIST_BEGIN uses it to drop the placeholder its list opens on.
template <typename List>
using TypeListPopFront_t = decltype(detail::TypeListPopFront(List{}));

GFXRECON_BEGIN_NAMESPACE(detail)

// InvokerTable holds one invoker per element, in list order; each calls visitor.operator()<Element>(args...). Visit
// indexes it at run time.
template <typename Visitor, typename ArgsList, typename Elements>
struct InvokerTable;

template <typename Visitor, typename... Args, typename... Elements>
struct InvokerTable<Visitor, TypeList<Args...>, TypeList<Elements...>>
{
    static_assert(sizeof...(Elements) > 0, "Visit: the list is empty");

    using Result = decltype(std::declval<Visitor&>().template operator()<TypeListAt_t<0, TypeList<Elements...>>>(
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
