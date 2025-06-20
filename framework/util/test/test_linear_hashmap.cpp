/*
** Copyright (c) 2025 LunarG, Inc.
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

#include <catch2/catch.hpp>
#include "util/linear_hashmap.h"
#include <cstdint>

TEST_CASE("linear_hashmap - create empty map", "[]")
{
    gfxrecon::util::linear_hashmap<uint64_t, uint32_t> hashmap;
    REQUIRE(hashmap.empty());
    hashmap.clear();
    REQUIRE(hashmap.capacity() == 0);
    REQUIRE(hashmap.get_storage(nullptr) == 0);
}

TEST_CASE("linear_hashmap - basic usage", "[]")
{
    constexpr uint32_t                                 test_capacity = 100;
    gfxrecon::util::linear_hashmap<uint64_t, uint64_t> hashmap(test_capacity);
    REQUIRE(hashmap.empty());
    REQUIRE(hashmap.get_storage(nullptr) > 0);

    // capacity will be rounded to next pow2
    REQUIRE(hashmap.capacity() >= test_capacity);
    REQUIRE(gfxrecon::util::is_pow_2(hashmap.capacity()));

    REQUIRE_FALSE(hashmap.contains(0));
    REQUIRE_FALSE(hashmap.contains(13));
    REQUIRE_FALSE(hashmap.contains(42));

    hashmap.put(69, 99);
    hashmap.put(13, 12);
    hashmap.put(8, 15);
    REQUIRE(hashmap.size() == 3);

    hashmap.remove(8);
    REQUIRE(hashmap.size() == 2);
    REQUIRE_FALSE(hashmap.contains(8));

    REQUIRE(hashmap.contains(69));
    REQUIRE(hashmap.get(69) == 99);
    REQUIRE(hashmap.contains(13));
    REQUIRE(hashmap.get(13) == 12);

    auto storage = std::make_unique<uint8_t[]>(hashmap.get_storage(nullptr));
    hashmap.get_storage(storage.get());
}

TEST_CASE("linear_hashmap - use a custom_key", "[]")
{
    // custom 32-byte key
    struct custom_key_t
    {
        int            v[8]{};
        constexpr bool operator==(const custom_key_t& other) const
        {
            for (uint32_t i = 0; i < 8; ++i)
            {
                if (v[i] != other.v[i])
                {
                    return false;
                }
            }
            return true;
        }
        constexpr bool operator!=(const custom_key_t& other) const { return !(other == *this); }
    };
    constexpr uint32_t test_capacity = 100;
    auto               hashmap       = gfxrecon::util::linear_hashmap<custom_key_t, uint64_t>(test_capacity);

    custom_key_t k1{ { 1, 2, 3, 4, 5, 6, 7, 8 } };
    hashmap.put(k1, 69);
    REQUIRE(hashmap.contains(k1));
    REQUIRE_FALSE(hashmap.contains(custom_key_t()));
}

TEST_CASE("linear_hashmap - reserve", "[]")
{
    gfxrecon::util::linear_hashmap<uint64_t, uint64_t> hashmap;

    // fix by resizing
    hashmap.reserve(17);
    REQUIRE(hashmap.empty());
    hashmap.put(13, 12);
    REQUIRE(hashmap.contains(13));

    // empty / no capacity specified -> triggers internal resize
    hashmap = {};
    hashmap.put(13, 12);
    REQUIRE(hashmap.contains(13));
}

TEST_CASE("linear_hashmap - probe_length", "[]")
{
    gfxrecon::util::linear_hashmap<uint32_t, uint32_t> hashmap;

    // default load_factor is 0.5
    REQUIRE(hashmap.max_load_factor() == 0.5f);

    // test a load-factor of 0.25
    hashmap.max_load_factor(0.25f);

    constexpr uint32_t test_capacity  = 8192;
    constexpr uint32_t num_insertions = 1024;
    hashmap.reserve(test_capacity);

    float probe_length_sum = 0.f;
    for (uint32_t i = 0; i < num_insertions; i++)
    {
        probe_length_sum += static_cast<float>(hashmap.put(i, 69));
    }
    float avg_probe_length = probe_length_sum / num_insertions;

    // for a load-factor of 0.25, we expect very short probe-lengths
    constexpr float expected_max_avg_probe_length = 0.15f;
    REQUIRE(avg_probe_length <= expected_max_avg_probe_length);

    REQUIRE(hashmap.load_factor() <= 0.25f);
}