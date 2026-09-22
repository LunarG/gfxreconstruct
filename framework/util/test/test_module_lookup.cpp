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

#include <catch2/catch.hpp>

#include "util/module_lookup.h"
#include "util/platform.h"

#include <cctype>
#include <string>

#if defined(_WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

using namespace gfxrecon::util::platform;

namespace test_local
{

// A function that lives in the test executable. The tests take its address, so the compiler must emit it.
int LocalFunction(int value)
{
    return value + 1;
}

// A system library and one of its exports. Each platform names a library that every process can load.
#if defined(_WIN32)
const char kSystemLibrary[]    = "kernel32.dll";
const char kSystemSymbol[]     = "GetTickCount";
const char kExpectedPathPart[] = "kernel32";
#elif defined(__APPLE__)
const char kSystemLibrary[]    = "libSystem.B.dylib";
const char kSystemSymbol[]     = "cos";
const char kExpectedPathPart[] = "libsystem_m";
#else
const char kSystemLibrary[]    = "libm.so.6";
const char kSystemSymbol[]     = "cos";
const char kExpectedPathPart[] = "libm";
#endif

std::string ToLower(std::string text)
{
    for (char& c : text)
    {
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
    }
    return text;
}

} // namespace test_local

TEST_CASE("module_lookup - executable path", "[module_lookup]")
{
    const std::string path = GetExecutablePath();
    REQUIRE_FALSE(path.empty());
    REQUIRE(test_local::ToLower(path).find("gfxrecon_util_test") != std::string::npos);
}

TEST_CASE("module_lookup - null address", "[module_lookup]")
{
    ModuleAddressInfo info;
    info.module_path = "unchanged";
    REQUIRE_FALSE(GetModuleAddressInfo(nullptr, {}, &info));
    REQUIRE(info.module_path == "unchanged");
}

TEST_CASE("module_lookup - null info", "[module_lookup]")
{
    REQUIRE_FALSE(GetModuleAddressInfo(reinterpret_cast<const void*>(&test_local::LocalFunction), {}, nullptr));
}

TEST_CASE("module_lookup - symbol in a system library", "[module_lookup]")
{
    LibraryHandle library = OpenLibrary(test_local::kSystemLibrary);
    REQUIRE(library != nullptr);

    const void* address = gfxrecon::util::platform::GetProcAddress(library, test_local::kSystemSymbol);
    REQUIRE(address != nullptr);

    ModuleAddressInfo info;
    // The wrong name comes first. The lookup must skip it and match the second name.
    REQUIRE(GetModuleAddressInfo(address, { "gfxrecon_no_such_symbol", test_local::kSystemSymbol }, &info));

    CHECK(test_local::ToLower(info.module_path).find(test_local::kExpectedPathPart) != std::string::npos);
    CHECK(info.symbol_name == test_local::kSystemSymbol);
    CHECK(info.module_offset != 0);
    CHECK_FALSE(info.in_executable);

    CloseLibrary(library);
}

TEST_CASE("module_lookup - no candidate matches", "[module_lookup]")
{
    LibraryHandle library = OpenLibrary(test_local::kSystemLibrary);
    REQUIRE(library != nullptr);

    const void* address = gfxrecon::util::platform::GetProcAddress(library, test_local::kSystemSymbol);
    REQUIRE(address != nullptr);

    ModuleAddressInfo info;
    REQUIRE(GetModuleAddressInfo(address, { "gfxrecon_no_such_symbol" }, &info));
    CHECK(info.symbol_name.empty());
    CHECK_FALSE(info.module_path.empty());

    CloseLibrary(library);
}

TEST_CASE("module_lookup - function in the executable", "[module_lookup]")
{
    ModuleAddressInfo info;
    REQUIRE(GetModuleAddressInfo(reinterpret_cast<const void*>(&test_local::LocalFunction), {}, &info));

    CHECK(info.in_executable);
    CHECK(info.module_path == GetExecutablePath());
    CHECK(info.symbol_name.empty());

    // Keep the function alive.
    REQUIRE(test_local::LocalFunction(1) == 2);
}
