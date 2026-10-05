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

// The lookup over an enumerant table. The tables are generated schema content, one per enumerated type, each holding
// only entries; an entry names the type's API type descriptor, which gives the value type and the type's name. The
// index is built from entries here, at compile time.
#ifndef GFXRECON_UTIL_ENUMERANTS_H
#define GFXRECON_UTIL_ENUMERANTS_H

#include "schema/binding/descriptor_for.h"
#include "schema/schema.h"
#include "util/defines.h"
#include "util/key_index.h"

#include <array>
#include <cstddef>
#include <string_view>
#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// One enumerant of the type Descriptor describes: its value and the name the API spells it with.
template <typename Descriptor>
struct Enumerant
{
    using descriptor = Descriptor;

    typename Descriptor::element_type value;
    std::string_view                  name;
};

// The descriptor of the type whose enumerants Table holds.
template <typename Table>
using EnumerantDescriptorOf = typename std::remove_cv_t<decltype(Table::entries)>::value_type::descriptor;

// The sorted index over Table::entries; a position found through it reads the entry it came from.
template <typename Table>
struct EnumerantLookup
{
    using value_type = typename EnumerantDescriptorOf<Table>::element_type;

    static constexpr size_t kSize = Table::entries.size();

    using Index = KeyIndex<value_type, kSize>;

    static constexpr Index index{ Table::entries,
                                  [](const Enumerant<EnumerantDescriptorOf<Table>>& entry) { return entry.value; } };
};

// The name of an enumerant in Table, or an empty view when value is not one. What a miss means is the caller's.
template <typename Table>
constexpr std::string_view NameIn(typename EnumerantDescriptorOf<Table>::element_type value)
{
    using Lookup          = EnumerantLookup<Table>;
    const size_t position = Lookup::index.Find(value);
    return (position == Lookup::Index::kMiss) ? std::string_view{} : Table::entries[position].name;
}

// The table of an enum bound to an enumerated descriptor.
template <typename Enum>
concept HasEnumerantTable =
    schema::binding::HasDescriptor<Enum> && schema::HasEnumerants<typename schema::binding::DescriptorFor<Enum>::type>;

template <HasEnumerantTable Enum>
using EnumerantTableOf = typename schema::binding::DescriptorFor<Enum>::type::enumerants;

template <HasEnumerantTable Enum>
constexpr std::string_view NameOf(Enum value)
{
    return NameIn<EnumerantTableOf<Enum>>(value);
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_ENUMERANTS_H
