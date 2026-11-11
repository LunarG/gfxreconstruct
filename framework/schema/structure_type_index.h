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

// StructureTypeIndex indexes a list of structure API elements by their structure_type. The pNext decoder and encoder
// and the deep-copy dispatch call StructureTypeVisit over it to reach the API element for a run-time sType. Two API
// elements with the same structure_type fail to compile: the index is a constexpr util::KeyIndex.
#ifndef GFXRECON_SCHEMA_STRUCTURE_TYPE_INDEX_H
#define GFXRECON_SCHEMA_STRUCTURE_TYPE_INDEX_H

#include "schema/schema.h"
#include "util/defines.h"
#include "util/key_index.h"
#include "util/type_list.h"

#include <array>
#include <concepts>
#include <cstddef>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

GFXRECON_BEGIN_NAMESPACE(detail)

// Returns the structure_type of each API element, as an array parallel to the list. Every API element must have one,
// of the first API element's enum type, or this fails to compile. When one has none, the failing static_assert
// condition lists the API elements without one; the filter that builds that list is instantiated only then.
template <typename... Elements>
constexpr auto StructureTypesOf(util::TypeList<Elements...>)
{
    using List                       = util::TypeList<Elements...>;
    constexpr auto kHasStructureType = []<typename Element>() { return TypedStructApiElement<Element>; };
    if constexpr (util::TypeListCountIf(List{}, kHasStructureType) != sizeof...(Elements))
    {
        static_assert(std::same_as<decltype(util::TypeListDrop(List{}, kHasStructureType)), util::TypeList<>>,
                      "StructureTypeIndex: API elements without a structure_type");
    }
    using Key                  = std::remove_cv_t<decltype(util::TypeListAt_t<0, List>::structure_type)>;
    constexpr auto kHasKeyType = []<typename Element>() {
        return std::is_same_v<Key, std::remove_cv_t<decltype(Element::structure_type)>>;
    };
    static_assert(util::TypeListCountIf(List{}, kHasKeyType) == sizeof...(Elements),
                  "StructureTypeIndex: one structure type enum per list");
    return std::array<Key, sizeof...(Elements)>{ Elements::structure_type... };
}

GFXRECON_END_NAMESPACE(detail)

// Find returns the position of a structure_type in List, or End(). util::Visit takes a position that is not End().
template <typename List>
requires util::IsTypeList_v<List>
class StructureTypeIndex
{
  public:
    using list     = List;
    using position = util::IndexPosition<StructureTypeIndex>;
    using key_type = typename decltype(detail::StructureTypesOf(List{}))::value_type;

    static constexpr size_t kSize = util::TypeListSize_v<List>;

    static constexpr position Find(key_type key) { return position{ kKeys.Find(key) }; }
    static constexpr position End() { return position{ kSize }; }

  private:
    static constexpr util::KeyIndex<key_type, kSize> kKeys{ detail::StructureTypesOf(List{}) };
};

// Visits the API element in List whose structure_type is key: on_find.operator()<Element>(args...) when found,
// on_miss(args...) when not. The two take the same arguments and return the same type. Every API element's
// operator() is instantiated, so on_find's constraint must hold for all of List.
template <typename List, typename Key, typename OnFind, typename OnMiss, typename... Args>
decltype(auto) StructureTypeVisit(const Key& key, OnFind&& on_find, OnMiss&& on_miss, Args&&... args)
{
    using Index = StructureTypeIndex<List>;
    static_assert(std::is_same_v<Key, typename Index::key_type>, "StructureTypeVisit: key type mismatch");

    if (const auto position = Index::Find(key); position != Index::End())
    {
        auto visitor = [&on_find]<TypedStructApiElement Element>(Args&&... arg_pack) {
            return on_find.template operator()<Element>(std::forward<Args>(arg_pack)...);
        };
        return util::Visit(position, visitor, std::forward<Args>(args)...);
    }
    else
    {
        return on_miss(std::forward<Args>(args)...);
    }
}
GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_STRUCTURE_TYPE_INDEX_H
