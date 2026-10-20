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

// The index over a list of structure descriptors by their structure_type, for the sieves that discriminate on it.
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

// The structure_type of each descriptor, as an array parallel to the list. Every descriptor carries one, and the
// key type is the first descriptor's, which every other descriptor's must agree with. When a descriptor has no
// structure_type, the assertion's message prints the list of those that do not; the filter that builds the list
// is instantiated only then.
template <typename... Descriptors>
constexpr auto StructureTypesOf(util::TypeList<Descriptors...>)
{
    using List                       = util::TypeList<Descriptors...>;
    constexpr auto kHasStructureType = []<typename Descriptor>() { return HasStructureType<Descriptor>; };
    if constexpr (util::TypeListCountIf(List{}, kHasStructureType) != sizeof...(Descriptors))
    {
        static_assert(std::same_as<decltype(util::TypeListDrop(List{}, kHasStructureType)), util::TypeList<>>,
                      "StructureTypeIndex: descriptors without a structure_type");
    }
    using Key                  = std::remove_cv_t<decltype(util::TypeListAt<0, List>::structure_type)>;
    constexpr auto kHasKeyType = []<typename Descriptor>() {
        return std::is_same_v<Key, std::remove_cv_t<decltype(Descriptor::structure_type)>>;
    };
    static_assert(util::TypeListCountIf(List{}, kHasKeyType) == sizeof...(Descriptors),
                  "StructureTypeIndex: one structure type enum per list");
    return std::array<Key, sizeof...(Descriptors)>{ Descriptors::structure_type... };
}

GFXRECON_END_NAMESPACE(detail)

// Find(structure_type) is a position in List, or End(). Visit takes the position; the miss is the caller's. A range
// over the list, with begin()/end() and a position that advances, is a natural addition; no customer yet.
template <util::TypeListType List>
class StructureTypeIndex
{
  public:
    using list     = List;
    using position = util::IndexPosition<StructureTypeIndex>;
    using key_type = typename decltype(detail::StructureTypesOf(List{}))::value_type;

    static constexpr size_t kSize = util::TypeListSizeV<List>;

    static constexpr position Find(key_type key) { return position{ kKeys.Find(key) }; }
    static constexpr position End() { return position{ kSize }; }

  private:
    static constexpr util::KeyIndex<key_type, kSize> kKeys{ detail::StructureTypesOf(List{}) };
};

// Visits the descriptor in List whose structure_type is key: on_find.operator()<Descriptor>(args...) when found,
// on_miss(args...) when not. The two take the same arguments and return the same type. Every descriptor's
// operator() is instantiated, so on_find's constraint must hold for all of List.
template <typename List, typename Key, typename OnFind, typename OnMiss, typename... Args>
decltype(auto) StructureTypeVisit(const Key& key, OnFind&& on_find, OnMiss&& on_miss, Args&&... args)
{
    using Index = StructureTypeIndex<List>;
    static_assert(std::is_same_v<Key, typename Index::key_type>, "StructureTypeVisit: key type mismatch");

    if (const auto position = Index::Find(key); position != Index::End())
    {
        auto visitor = [&on_find]<HasStructureType Descriptor>(Args&&... arg_pack) {
            return on_find.template operator()<Descriptor>(std::forward<Args>(arg_pack)...);
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
