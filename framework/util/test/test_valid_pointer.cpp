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
#include "util/platform.h"

using namespace gfxrecon::util::platform;

TEST_CASE("valid_pointer - stack", "[]")
{
    int   ans = 42;
    void* p   = &ans;
    REQUIRE(PointerIsValid(p));
}

TEST_CASE("valid_pointer - null", "[]")
{
    void* p = nullptr;
    REQUIRE_FALSE(PointerIsValid(p));
}

TEST_CASE("valid_pointer - invalid", "[]")
{
    // This is an address that is very likely to be invalid in any process.
    void* p = reinterpret_cast<void*>(0x123);
    REQUIRE_FALSE(PointerIsValid(p));
}

TEST_CASE("valid_pointer - heap", "[]")
{
    int* p = new int(42);
    REQUIRE(PointerIsValid(p));
    delete p;
}
