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

template <typename T>
struct IsTypeList : std::false_type
{};

template <typename... Types>
struct IsTypeList<TypeList<Types...>> : std::true_type
{};

template <typename T>
concept TypeListType = IsTypeList<T>::value;

// A fold expression over a pack is instantiated as nested binary expressions, one level per element, and clang
// stops at 256; a pack expanded into a braced list is one node at any length. Every algorithm here that reduces
// a pack does so through an array and a constexpr loop, so a catalog-sized list is no different from a field list.
// The array form is the C++17 successor of the initializer_list expansion idiom.

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

// The positions of the true entries, in order; Count is CountOf(values).
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

// A predicate over types is a constexpr callable with a template call operator and no parameters,
// []<typename T>() { return ...; }, the shape TypeListForEach's visitors take; a concept is one in one line. The
// algorithms take it by value and re-create it, which a captureless closure allows, so the call is a constant
// expression.

GFXRECON_BEGIN_NAMESPACE(detail)

// The negation of a predicate, for TypeListDrop.
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

// How many elements satisfy the predicate. All, any and none are comparisons on it.
template <typename List, typename Predicate>
constexpr size_t TypeListCountIf(List, Predicate)
{
    return detail::TypeListCountIfImpl(List{}, Predicate{});
}

template <typename List, typename Function>
constexpr void TypeListForEach(Function&& function)
{
    detail::TypeListForEachImpl(List{}, std::forward<Function>(function));
}

template <typename List, typename Accessor, typename Function>
decltype(auto) ApplyFields(Accessor&& accessor, Function&& function)
{
    return detail::ApplyFieldsImpl(List{}, std::forward<Accessor>(accessor), std::forward<Function>(function));
}

GFXRECON_BEGIN_NAMESPACE(detail)

// TypeListAt without recursion: one base per element, all inherited at once, and the element at I selected by
// deduction against the one base with that position, which the C++20 standard allows through a derived-to-base
// conversion ([temp.deduct.call]/4.3). The layout and the lookup are Boost.Mp11's mp_map_find (Dimov) and the
// multiple-inheritance form in Dionne, "Efficient parameter pack indexing" (2015); libc++ and libstdc++ lay out
// std::tuple the same way. std::tuple_element recurses on MSVC and is not used.
//
// Each Indexed also derives from Holder<T>, so the same object is a set: whether T is in the list is whether
// Holder<T> is a base, one lookup. A repeated element makes Holder<T> an ambiguous base, which still satisfies
// std::is_base_of ([meta.rel]), so duplicates cost nothing.
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
struct IndexerFor;

template <typename... Types>
struct IndexerFor<TypeList<Types...>>
{
    using type = Indexer<std::index_sequence_for<Types...>, Types...>;
};

template <size_t I, typename T>
Indexed<I, T> PickIndexed(Indexed<I, T>); // declared only; its type is the answer

template <size_t I, typename List>
struct TypeListAtImpl;

template <size_t I, typename... Types>
struct TypeListAtImpl<I, TypeList<Types...>>
{
    static_assert(I < sizeof...(Types), "TypeListAt: position past the end of the list");
    using type = typename decltype(PickIndexed<I>(Indexer<std::index_sequence_for<Types...>, Types...>{}))::type;
};

// A constexpr array of positions as an index_sequence. The one value-to-template-argument step is here; a later
// expansion takes the positions as template arguments and evaluates no subscript inside a template argument list,
// which MSVC rejects for a raw array member (C3546).
template <auto Positions, size_t... Is>
std::index_sequence<Positions[Is]...> PositionSequenceImpl(std::index_sequence<Is...>);

template <auto Positions>
using PositionSequence = decltype(PositionSequenceImpl<Positions>(std::make_index_sequence<Positions.size()>{}));

// The elements whose predicate holds: the predicate results as an array, their positions as an array, that array
// as an index_sequence, and one expansion over it. Flat at every step.
template <typename... Types, size_t... Positions>
TypeList<typename TypeListAtImpl<Positions, TypeList<Types...>>::type...>
    Pick(TypeList<Types...>, std::index_sequence<Positions...>); // declared only; its type is the answer

template <typename... Types, typename Predicate>
constexpr auto TypeListKeepImpl(TypeList<Types...>, Predicate)
{
    constexpr std::array<bool, sizeof...(Types)> kSelected{ Predicate{}.template operator()<Types>()... };
    constexpr auto                               kPositions = PositionsOf<CountOf(kSelected)>(kSelected);
    return decltype(Pick(TypeList<Types...>{}, PositionSequence<kPositions>{})){};
}

template <typename List>
struct TypeListSoleImpl;

template <typename Type>
struct TypeListSoleImpl<TypeList<Type>>
{
    using type = Type;
};

template <typename First, typename... Rest>
TypeList<Rest...> TypeListPopFrontImpl(TypeList<First, Rest...>); // declared only; its type is the answer

GFXRECON_END_NAMESPACE(detail)

template <size_t I, typename List>
using TypeListAt = typename detail::TypeListAtImpl<I, List>::type;

// Whether T is in the list: a base-class lookup on the index, not a pass over the list. Measured over the 1,365-entry
// structures catalog, 1,365 queries compile in under a second this way and in six minutes as a count.
template <typename List, typename T>
inline constexpr bool TypeListContainsV = std::is_base_of_v<detail::Holder<T>, typename detail::IndexerFor<List>::type>;

// The list of elements whose predicate holds, as a value: using Kept = decltype(TypeListKeep(List{}, kPredicate));
template <typename List, typename Predicate>
constexpr auto TypeListKeep(List, Predicate)
{
    return detail::TypeListKeepImpl(List{}, Predicate{});
}

template <typename List, typename Predicate>
constexpr auto TypeListDrop(List, Predicate)
{
    return TypeListKeep(List{}, detail::Not<Predicate>{});
}

// The elements of List that are not in Excluded.
template <typename List, typename Excluded>
constexpr auto TypeListExclude(List, Excluded)
{
    return TypeListDrop(List{}, []<typename T>() { return TypeListContainsV<Excluded, T>; });
}

template <typename List>
using TypeListSole = typename detail::TypeListSoleImpl<List>::type;

// The list without its first element. One deduction, so it costs nothing at any length; a list built on a
// placeholder first element is trimmed this way.
template <typename List>
using TypeListPopFront = decltype(detail::TypeListPopFrontImpl(List{}));

GFXRECON_BEGIN_NAMESPACE(detail)

// One invoker per element, in list order; each calls visitor.operator()<Element>(args...). A table of invokers
// indexed at run time is how libc++ and libstdc++ implement std::visit.
template <typename Visitor, typename ArgsList, typename Elements>
struct InvokerTable;

template <typename Visitor, typename... Args, typename... Elements>
struct InvokerTable<Visitor, TypeList<Args...>, TypeList<Elements...>>
{
    static_assert(sizeof...(Elements) > 0, "Visit: the list is empty");

    using Result = decltype(std::declval<Visitor&>().template operator()<TypeListAt<0, TypeList<Elements...>>>(
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

template <typename List>
inline constexpr size_t TypeListSizeV = detail::TypeListSize<List>::value;

// A class template, not a type nested in the index: Visit deduces Index from this parameter, and a type reached
// through Index::, aliased or not, is non-deduced ([temp.deduct.type]/5).
//
// Where an index's Find landed in its list, or its End. The index constructs one; Visit reads it; nothing else
// sees the position.
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

// Calls visitor.operator()<Element>(args...) for the element of the index's list at `position`. The caller has
// compared `position` against Index::End(); the miss is the caller's.
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
