/*
** Copyright (c) 2026 Arm Limited and/or its affiliates <open-source-office@arm.com>
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
#include "util/options.h"

using namespace gfxrecon::util;

TEST_CASE("Unsigned ranges accept the entire uint32 domain", "[options][skip-index]")
{
    const auto ranges = GetUintRanges("0, 7,10-20,2147483648,4294967295", "--skip-index", false, true);
    REQUIRE(ranges.size() == 5);
    REQUIRE(ranges[0].first == 0);
    REQUIRE(ranges[1].first == 7);
    REQUIRE(ranges[2].first == 10);
    REQUIRE(ranges[2].last == 20);
    REQUIRE(ranges[3].last == 2147483648U);
    REQUIRE(ranges[4].last == UINT32_MAX);
}

TEST_CASE("Malformed unsigned ranges are ignored without losing valid entries", "[options][skip-index]")
{
    const auto value  = GENERATE("",
                                " ",
                                "-1",
                                "+1",
                                "1x",
                                "1-",
                                "1-2x",
                                "-1-2",
                                "2-1",
                                "1--2",
                                "*",
                                "4294967296",
                                "0-4294967296",
                                "99999999999999999999999999999");
    const auto ranges = GetUintRanges((std::string(value) + ",7").c_str(), "--skip-index", false, true);
    REQUIRE(ranges.size() == 1);
    REQUIRE(ranges[0].first == 7);
    REQUIRE(ranges[0].last == 7);
}

TEST_CASE("Existing frame range restrictions remain in effect", "[options][skip-index]")
{
    REQUIRE(GetUintRanges("0", "frames").empty());
    REQUIRE(GetUintRanges("0-1", "frames").empty());
    REQUIRE(GetUintRanges("3-5,4-6", "frames").size() == 1);
    REQUIRE(GetUintRanges("4294967295,1", "frames").size() == 1);
    REQUIRE(GetUintRanges("3-5,4-6,0", "--skip-index", false, true).size() == 3);
}
