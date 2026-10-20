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

// A sorted key table that maps a key to the position it had in the array the table was built from. The miss is the
// caller's: Find reports it, nothing here decides what it means.
#ifndef GFXRECON_UTIL_KEY_INDEX_H
#define GFXRECON_UTIL_KEY_INDEX_H

#include "util/defines.h"
#include "util/logging.h"

#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <type_traits>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

GFXRECON_BEGIN_NAMESPACE(detail)

// Not constexpr, so a KeyIndex built at compile time fails to compile when two keys are equal.
inline void KeyIndexHasDuplicateKeys()
{
    GFXRECON_ASSERT(false);
}

GFXRECON_END_NAMESPACE(detail)

// Key to position. Find is a binary search over the keys sorted at construction; the position is the element's
// index in the array the table was built from, and a key not in the table yields kMiss. The array holds keys, or
// elements that key_of maps to keys.
template <typename Key, size_t N>
class KeyIndex
{
  public:
    using key_type = Key;

    static constexpr size_t kSize = N;
    static constexpr size_t kMiss = N;

    template <typename Element, typename KeyOfElement = std::identity>
    constexpr explicit KeyIndex(const std::array<Element, N>& elements, KeyOfElement key_of = {}) :
        entries_(Sorted(elements, key_of))
    {}

    constexpr size_t Find(const Key& key) const
    {
        const auto it = std::lower_bound(
            entries_.begin(), entries_.end(), key, [](const Entry& entry, const Key& k) { return entry.key < k; });
        return (it != entries_.end() && it->key == key) ? it->position : kMiss;
    }

  private:
    struct Entry
    {
        Key    key;
        size_t position;
    };

    template <typename Element, typename KeyOfElement>
    static constexpr std::array<Entry, N> Sorted(const std::array<Element, N>& elements, KeyOfElement key_of)
    {
        std::array<Entry, N> entries{};
        for (size_t position = 0; position < N; ++position)
        {
            entries[position] = Entry{ Key(key_of(elements[position])), position };
        }
        std::sort(entries.begin(), entries.end(), [](const Entry& a, const Entry& b) { return a.key < b.key; });
        for (size_t i = 1; i < N; ++i)
        {
            if (!(entries[i - 1].key < entries[i].key))
            {
                detail::KeyIndexHasDuplicateKeys();
            }
        }
        return entries;
    }

    std::array<Entry, N> entries_;
};

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_UTIL_KEY_INDEX_H
