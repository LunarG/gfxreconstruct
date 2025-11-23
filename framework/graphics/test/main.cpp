///////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2019 Advanced Micro Devices, Inc.All rights reserved
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
/// \author AMD Developer Tools Team
/// \description gfxrecon_graphics test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <numeric>
#include <catch2/catch.hpp>

#include "graphics/vulkan_shader_group_handle.h"

TEST_CASE("vulkan_shader_group_handle - create empty handles", "[]")
{
    gfxrecon::graphics::shader_group_handle_t one, two;

    // check for all zeros
    uint8_t data[gfxrecon::graphics::shader_group_handle_t::MAX_HANDLE_SIZE] = {};
    REQUIRE(memcmp(one.data, data, gfxrecon::graphics::shader_group_handle_t::MAX_HANDLE_SIZE) == 0);

    REQUIRE(one == two);
    REQUIRE_FALSE(one != two);

    auto three = one;
    REQUIRE(one == three);
}

TEST_CASE("vulkan_shader_group_handle - create handles", "[]")
{
    std::vector<uint8_t> data(32);
    std::iota(data.begin(), data.end(), 0);
    gfxrecon::graphics::shader_group_handle_t one(data.data(), static_cast<uint32_t>(data.size()));

    data[31] = 99;
    gfxrecon::graphics::shader_group_handle_t two(data.data(), static_cast<uint32_t>(data.size()));
    REQUIRE(one != two);

    // check hashing via std::hash
    std::hash<gfxrecon::graphics::shader_group_handle_t> hasher;
    REQUIRE(hasher(one) != hasher(two));
}