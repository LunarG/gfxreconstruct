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

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(schema)

GFXRECON_BEGIN_NAMESPACE(detail)

template <typename First, typename...>
struct FirstOf
{
    using type = First;
};

// The key type is the first descriptor's; a fold checks the rest agree. std::common_type_t recurses pairwise and
// exceeds MSVC's depth on a catalog-sized list.
// WIP: `HasStructureType... Descriptors` is a fold too, and exceeds clang's nesting limit over the catalog; the
// expansion below fails on a descriptor without a structure_type, at the member, until the flat-forms pass gives
// the check a better message (findings section 6, fold expressions nest).
template <typename... Descriptors>
constexpr auto StructureTypes(util::TypeList<Descriptors...>)
{
    using Key = std::remove_cv_t<decltype(FirstOf<Descriptors...>::type::structure_type)>;
    // WIP: a fold over a catalog-sized pack exceeds clang's nesting limit; the flat form is the next turn's
    // (findings section 6, fold expressions nest).
    // static_assert((std::same_as<Key, std::remove_cv_t<decltype(Descriptors::structure_type)>> && ...),
    //               "StructureTypeIndex: one structure type enum per list");
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
    using key_type = typename decltype(detail::StructureTypes(List{}))::value_type;

    static constexpr size_t kSize = util::TypeListSizeV<List>;

    static constexpr position Find(key_type key) { return position{ kKeys.Find(key) }; }
    static constexpr position End() { return position{ kSize }; }

  private:
    static constexpr util::KeyIndex<key_type, kSize> kKeys{ detail::StructureTypes(List{}) };
};

GFXRECON_END_NAMESPACE(schema)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SCHEMA_STRUCTURE_TYPE_INDEX_H
