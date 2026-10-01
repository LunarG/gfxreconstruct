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

// The enumerants of an enum as data, and the one lookup over them. Enumerants<Enum>::entries is generated; the index
// and the name table are built from it here, at compile time.
#ifndef GFXRECON_UTIL_ENUMERANTS_H
#define GFXRECON_UTIL_ENUMERANTS_H

#include "util/defines.h"
#include "util/key_index.h"

#include <array>
#include <concepts>
#include <cstddef>
#include <string_view>
#include <type_traits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

// One enumerant: its value and the name the API spells it with.
template <typename Enum>
struct Enumerant
{
    Enum             value;
    std::string_view name;
};

// The enumerants of one enum in registry order. Generated, one specialization per enum, holding `entries` and
// nothing else. An alias adds no entry, so each value appears once.
template <typename Enum>
struct Enumerants;

template <typename Enum>
concept HasEnumerants = std::is_enum_v<Enum> && requires
{
    {
        Enumerants<Enum>::entries.size()
        } -> std::convertible_to<size_t>;
};

// The sorted index over Enumerants<Enum>::entries; a position found through it reads the entry it came from.
template <HasEnumerants Enum>
struct EnumerantLookup
{
    static constexpr size_t kSize = Enumerants<Enum>::entries.size();

    using Index = KeyIndex<Enum, kSize>;

    static constexpr Index index{ Enumerants<Enum>::entries, [](const Enumerant<Enum>& entry) { return entry.value; } };
};

// The name of an enumerant, or an empty view when value is not one. What a miss means is the caller's.
template <HasEnumerants Enum>
constexpr std::string_view NameOf(Enum value)
{
    using Lookup          = EnumerantLookup<Enum>;
    const size_t position = Lookup::index.Find(value);
    return (position == Lookup::Index::kMiss) ? std::string_view{} : Enumerants<Enum>::entries[position].name;
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_ENUMERANTS_H
