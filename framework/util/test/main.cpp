///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
// Copyright (c) 2022 Valve Corporation
// Copyright (c) 2022 LunarG, Inc.
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
/// @file gfxrecon_util test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include "util/to_string.h"
#include "util/logging.h"

TEST_CASE("JSONEscape", "[to_string]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);

    std::string escaped;

    escaped = "";
    gfxrecon::util::JSONEscape("", escaped);
    REQUIRE(escaped == "");

    escaped = "";
    gfxrecon::util::JSONEscape("a", escaped);
    REQUIRE(escaped == "a");

    escaped = "";
    gfxrecon::util::JSONEscape("a.b", escaped);
    REQUIRE(escaped == "a.b");

    escaped = "";
    gfxrecon::util::JSONEscape("\"", escaped);
    REQUIRE(escaped == "\\\"");

    escaped = "";
    gfxrecon::util::JSONEscape("\"\"", escaped);
    REQUIRE(escaped == "\\\"\\\"");

    escaped = "";
    gfxrecon::util::JSONEscape("\"\"\"", escaped);
    REQUIRE(escaped == "\\\"\\\"\\\"");

    escaped = "";
    gfxrecon::util::JSONEscape("\"\"\"\"", escaped);
    REQUIRE(escaped == "\\\"\\\"\\\"\\\"");

    escaped = "";
    gfxrecon::util::JSONEscape("\t", escaped);
    REQUIRE(escaped == "\\t");

    escaped = "";
    gfxrecon::util::JSONEscape("\r", escaped);
    REQUIRE(escaped == "\\r");

    escaped = "";
    gfxrecon::util::JSONEscape("\n", escaped);
    REQUIRE(escaped == "\\n");

    escaped = "";
    gfxrecon::util::JSONEscape("\f", escaped);
    REQUIRE(escaped == "\\f");

    escaped = "";
    gfxrecon::util::JSONEscape("\b", escaped);
    REQUIRE(escaped == "\\b");

    escaped = "";
    gfxrecon::util::JSONEscape("/", escaped);
    REQUIRE(escaped == "/");

    escaped = "";
    gfxrecon::util::JSONEscape("\\", escaped);
    REQUIRE(escaped == "\\\\");

    escaped = "";
    gfxrecon::util::JSONEscape("/home/tracer/captures/app1/capture.gfxr", escaped);
    REQUIRE(escaped == "/home/tracer/captures/app1/capture.gfxr");

    escaped = "";
    gfxrecon::util::JSONEscape("\\home\\tracer\\captures\\app1\\capture.gfxr", escaped);
    REQUIRE(escaped == "\\\\home\\\\tracer\\\\captures\\\\app1\\\\capture.gfxr");

    gfxrecon::util::Log::Release();
}
