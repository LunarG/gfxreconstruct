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

// KeyIndex, the key-to-position table, and Visit over a TypeList at a position an index returned.

#include <catch2/catch.hpp>

#include "util/key_index.h"
#include "util/type_list.h"

#include <array>
#include <cstdint>
#include <string_view>
#include <type_traits>
#include <utility>

namespace
{
using namespace gfxrecon;

// Sparse values, like VkStructureType, so a dense jump table is not an option and the sorted table is what runs.
enum class Color : uint32_t
{
    Red   = 1,
    Green = 1000,
    Blue  = 1000000005,
};

struct RedTag
{
    static constexpr Color value = Color::Red;
    static constexpr int   id    = 1;
};
struct GreenTag
{
    static constexpr Color value = Color::Green;
    static constexpr int   id    = 2;
};
struct BlueTag
{
    static constexpr Color value = Color::Blue;
    static constexpr int   id    = 3;
};

// Deliberately out of value order: the index sorts, the list need not, and positions are list positions. The keys
// array is written in the list's order by whoever owns the list; here, by hand.
using Colors = util::TypeList<BlueTag, RedTag, GreenTag>;
using Keys   = util::KeyIndex<Color, 3>;

constexpr Keys kColors{ std::array<Color, 3>{ BlueTag::value, RedTag::value, GreenTag::value } };

static_assert(std::same_as<Keys::key_type, Color>);
static_assert(Keys::kSize == 3);
static_assert(Keys::kMiss == 3);

static_assert(kColors.Find(Color::Blue) == 0);
static_assert(kColors.Find(Color::Red) == 1);
static_assert(kColors.Find(Color::Green) == 2);
static_assert(kColors.Find(static_cast<Color>(7)) == Keys::kMiss);

// The list-aware index a Visit needs: the list, the size, a position type, and Find and End returning it. This is
// the shape schema::StructureTypeIndex has; here it is written by hand over kColors.
struct ColorsIndex
{
    using list     = Colors;
    using position = util::IndexPosition<ColorsIndex>;

    static constexpr size_t kSize = Keys::kSize;

    static constexpr position Find(Color key) { return position{ kColors.Find(key) }; }
    static constexpr position End() { return position{ kSize }; }
};

static_assert(ColorsIndex::Find(Color::Red) != ColorsIndex::End());
static_assert(ColorsIndex::Find(static_cast<Color>(7)) == ColorsIndex::End());

// An element array with a projection: the key is read from each element.
struct Named
{
    int              key;
    std::string_view name;
};
constexpr std::array<Named, 3>   kNamed{ { { 9, "nine" }, { 5, "five" }, { 7, "seven" } } };
constexpr util::KeyIndex<int, 3> kNamedIndex{ kNamed, [](const Named& element) { return element.key; } };

// A list wider than clang's 256-level expression nesting limit, so every TypeList algorithm is shown flat.
template <size_t I>
struct Tag
{
    static constexpr size_t value = I;
};

template <size_t... Is>
util::TypeList<Tag<Is>...> MakeTags(std::index_sequence<Is...>);

constexpr size_t kWide = 300;
using Wide             = decltype(MakeTags(std::make_index_sequence<kWide>{}));

constexpr auto kIsEven = []<typename T>() { return (T::value % 2) == 0; };

using Evens = decltype(util::TypeListKeep(Wide{}, kIsEven));
using Odds  = decltype(util::TypeListDrop(Wide{}, kIsEven));

static_assert(util::TypeListSizeV<Wide> == kWide);
static_assert(util::TypeListCountIf(Wide{}, kIsEven) == kWide / 2);
static_assert(util::TypeListCountIf(Wide{}, util::detail::Not<decltype(kIsEven)>{}) == kWide / 2);
static_assert(std::same_as<util::TypeListAt<0, Wide>, Tag<0>>);
static_assert(std::same_as<util::TypeListAt<kWide - 1, Wide>, Tag<kWide - 1>>);
static_assert(util::TypeListSizeV<Evens> == kWide / 2);
static_assert(util::TypeListSizeV<Odds> == kWide / 2);
static_assert(std::same_as<util::TypeListAt<1, Evens>, Tag<2>>);
static_assert(std::same_as<util::TypeListAt<1, Odds>, Tag<3>>);
static_assert(util::TypeListContainsV<Wide, Tag<kWide - 1>>);
static_assert(
    util::TypeListSizeV<decltype(util::TypeListExclude(Wide{}, util::TypeList<Tag<1>, Tag<3>, Tag<kWide>>{}))> ==
    kWide - 2);
static_assert(!util::TypeListContainsV<Wide, Tag<kWide>>);
} // namespace

TEST_CASE("KeyIndex finds a key's position or reports a miss", "[util][keyindex]")
{
    CHECK(kColors.Find(Color::Red) == 1);
    CHECK(kColors.Find(Color::Green) == 2);
    CHECK(kColors.Find(Color::Blue) == 0);

    // A value no element carries misses, whether it sorts before, between or after the keys.
    CHECK(kColors.Find(static_cast<Color>(0)) == Keys::kMiss);
    CHECK(kColors.Find(static_cast<Color>(7)) == Keys::kMiss);
    CHECK(kColors.Find(static_cast<Color>(2000000000)) == Keys::kMiss);
}

TEST_CASE("KeyIndex builds from elements through a key projection", "[util][keyindex]")
{
    static_assert(kNamedIndex.Find(9) == 0);
    static_assert(kNamedIndex.Find(5) == 1);
    static_assert(kNamedIndex.Find(7) == 2);
    CHECK(kNamedIndex.Find(6) == kNamedIndex.kMiss);
    CHECK(kNamed[kNamedIndex.Find(5)].name == "five");
}

TEST_CASE("Visit hands the element at a position to the visitor", "[util][typelist]")
{
    auto match = []<typename Element>() { return Element::id; };

    CHECK(util::Visit(ColorsIndex::Find(Color::Red), match) == RedTag::id);
    CHECK(util::Visit(ColorsIndex::Find(Color::Green), match) == GreenTag::id);
    CHECK(util::Visit(ColorsIndex::Find(Color::Blue), match) == BlueTag::id);
}

TEST_CASE("Visit passes the caller's functor and arguments through", "[util][typelist]")
{
    int  handled = 0;
    auto match   = [&]<typename Element>(uint32_t scale) {
        ++handled;
        return static_cast<uint32_t>(Element::value) * scale;
    };

    CHECK(util::Visit(ColorsIndex::Find(Color::Green), match, 2u) == 2000u);
    CHECK(handled == 1);
}

TEST_CASE("An index's positions compare, and a miss is End", "[util][typelist]")
{
    const auto red  = ColorsIndex::Find(Color::Red);
    const auto miss = ColorsIndex::Find(static_cast<Color>(3));

    CHECK(red == ColorsIndex::Find(Color::Red));
    CHECK(red != ColorsIndex::End());
    CHECK(miss == ColorsIndex::End());
    CHECK(red != miss);
}

TEST_CASE("TypeListForEach walks a list wider than the fold limit, in order", "[util][typelist]")
{
    size_t count = 0;
    size_t sum   = 0;
    util::TypeListForEach<Wide>([&]<typename T>() {
        CHECK(T::value == count);
        ++count;
        sum += T::value;
    });
    CHECK(count == kWide);
    CHECK(sum == (kWide * (kWide - 1)) / 2);
}
