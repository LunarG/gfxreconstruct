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

#include "decode/vulkan_direct_driver_resolver.h"
#include "format/format.h"
#include "util/platform.h"

#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

using namespace gfxrecon;
using namespace gfxrecon::decode;

namespace
{

// A fake library loader. The operations are plain function pointers, so the state is static.
struct FakeLoader
{
    std::vector<std::string> opened;
    std::vector<std::string> resolved;
    int                      close_count{ 0 };
    std::string              known_path;   // The only path that opens.
    std::string              known_symbol; // The only symbol that resolves.
};

FakeLoader g_fake;
int        g_fake_handle_storage = 0;
int        g_fake_symbol_storage = 0;

util::platform::LibraryHandle FakeOpen(const char* path)
{
    g_fake.opened.emplace_back(path);
    if (g_fake.known_path == path)
    {
        return reinterpret_cast<util::platform::LibraryHandle>(&g_fake_handle_storage);
    }
    return nullptr;
}

void* FakeGetProcAddress(util::platform::LibraryHandle library, const char* symbol)
{
    REQUIRE(library == reinterpret_cast<util::platform::LibraryHandle>(&g_fake_handle_storage));
    g_fake.resolved.emplace_back(symbol);
    if (g_fake.known_symbol == symbol)
    {
        return &g_fake_symbol_storage;
    }
    return nullptr;
}

void FakeClose(util::platform::LibraryHandle library)
{
    REQUIRE(library == reinterpret_cast<util::platform::LibraryHandle>(&g_fake_handle_storage));
    ++g_fake.close_count;
}

const DirectDriverLoadOps kFakeOps = { FakeOpen, FakeGetProcAddress, FakeClose };

void ResetFake(const std::string& known_path, const std::string& known_symbol)
{
    g_fake              = FakeLoader{};
    g_fake.known_path   = known_path;
    g_fake.known_symbol = known_symbol;
}

DirectDriverInfo MakeInfo(const std::string& module_path, const std::string& symbol_name, uint32_t flags)
{
    DirectDriverInfo info;
    info.header.driver_count = 1;
    info.header.flags        = flags;
    info.module_path         = module_path;
    info.symbol_name         = symbol_name;
    return info;
}

const uint32_t kFound = format::kDirectDriverInfoModuleFound | format::kDirectDriverInfoSymbolFound;

} // namespace

TEST_CASE("ResolveDirectDriver uses the recorded path and symbol", "[direct_driver]")
{
    ResetFake("/capture/libdriver.so", "vk_icdGetInstanceProcAddr");
    auto result =
        ResolveDirectDriver(MakeInfo("/capture/libdriver.so", "vk_icdGetInstanceProcAddr", kFound), "", kFakeOps);

    REQUIRE(result.Succeeded());
    CHECK(result.library != nullptr);
    CHECK(result.library_path == "/capture/libdriver.so");
    CHECK(result.symbol_name == "vk_icdGetInstanceProcAddr");
    CHECK(result.message.empty());
    CHECK(g_fake.opened == std::vector<std::string>{ "/capture/libdriver.so" });
    CHECK(g_fake.resolved == std::vector<std::string>{ "vk_icdGetInstanceProcAddr" });
    CHECK(g_fake.close_count == 0);
}

TEST_CASE("ResolveDirectDriver prefers the override path", "[direct_driver]")
{
    ResetFake("/replay/libother.so", "vk_icdGetInstanceProcAddr");
    auto result = ResolveDirectDriver(
        MakeInfo("/capture/libdriver.so", "vk_icdGetInstanceProcAddr", kFound), "/replay/libother.so", kFakeOps);

    REQUIRE(result.Succeeded());
    CHECK(result.library_path == "/replay/libother.so");
    CHECK(g_fake.opened == std::vector<std::string>{ "/replay/libother.so" });
}

TEST_CASE("ResolveDirectDriver probes the common names when the recorded name fails", "[direct_driver]")
{
    // The capture recorded a vendor name. The remapped library exports the standard name instead.
    ResetFake("/replay/libother.so", "vk_icdGetInstanceProcAddr");
    auto result =
        ResolveDirectDriver(MakeInfo("/capture/libdriver.so", "vendor_gipa", kFound), "/replay/libother.so", kFakeOps);

    REQUIRE(result.Succeeded());
    CHECK(result.symbol_name == "vk_icdGetInstanceProcAddr");
    CHECK(g_fake.resolved == std::vector<std::string>{ "vendor_gipa", "vk_icdGetInstanceProcAddr" });
}

TEST_CASE("ResolveDirectDriver probes both common names when no symbol was recorded", "[direct_driver]")
{
    ResetFake("/capture/libdriver.so", "vkGetInstanceProcAddr");
    auto result =
        ResolveDirectDriver(MakeInfo("/capture/libdriver.so", "", format::kDirectDriverInfoModuleFound), "", kFakeOps);

    REQUIRE(result.Succeeded());
    CHECK(result.symbol_name == "vkGetInstanceProcAddr");
    CHECK(g_fake.resolved == std::vector<std::string>{ "vk_icdGetInstanceProcAddr", "vkGetInstanceProcAddr" });
}

TEST_CASE("ResolveDirectDriver refuses an entry point inside the executable", "[direct_driver]")
{
    ResetFake("/capture/app", "vk_icdGetInstanceProcAddr");
    auto result = ResolveDirectDriver(
        MakeInfo("/capture/app", "", format::kDirectDriverInfoModuleFound | format::kDirectDriverInfoInExecutable),
        "",
        kFakeOps);

    REQUIRE_FALSE(result.Succeeded());
    CHECK(result.library == nullptr);
    CHECK(result.message.find("/capture/app") != std::string::npos);
    CHECK(result.message.find("--direct-driver-lib") != std::string::npos);
    CHECK(g_fake.opened.empty());
}

TEST_CASE("ResolveDirectDriver accepts an override for an entry point inside the executable", "[direct_driver]")
{
    ResetFake("/replay/libother.so", "vk_icdGetInstanceProcAddr");
    auto result = ResolveDirectDriver(
        MakeInfo("/capture/app", "", format::kDirectDriverInfoModuleFound | format::kDirectDriverInfoInExecutable),
        "/replay/libother.so",
        kFakeOps);

    REQUIRE(result.Succeeded());
    CHECK(result.library_path == "/replay/libother.so");
}

TEST_CASE("ResolveDirectDriver fails when no path is known", "[direct_driver]")
{
    ResetFake("", "");
    auto result = ResolveDirectDriver(MakeInfo("", "", 0), "", kFakeOps);

    REQUIRE_FALSE(result.Succeeded());
    CHECK(result.message.find("did not record a module path") != std::string::npos);
    CHECK(g_fake.opened.empty());
}

TEST_CASE("ResolveDirectDriver reports a library that does not open", "[direct_driver]")
{
    ResetFake("/somewhere/else.so", "vk_icdGetInstanceProcAddr");
    auto result =
        ResolveDirectDriver(MakeInfo("/capture/libdriver.so", "vk_icdGetInstanceProcAddr", kFound), "", kFakeOps);

    REQUIRE_FALSE(result.Succeeded());
    CHECK(result.library == nullptr);
    CHECK(result.message.find("could not open") != std::string::npos);
    CHECK(result.message.find("/capture/libdriver.so") != std::string::npos);
    CHECK(g_fake.close_count == 0);
}

TEST_CASE("ResolveDirectDriver closes a library without an entry point", "[direct_driver]")
{
    ResetFake("/capture/libdriver.so", "something_else");
    auto result = ResolveDirectDriver(MakeInfo("/capture/libdriver.so", "vendor_gipa", kFound), "", kFakeOps);

    REQUIRE_FALSE(result.Succeeded());
    CHECK(result.library == nullptr);
    CHECK(g_fake.close_count == 1);
    CHECK(g_fake.resolved.size() == 3);
    CHECK(result.message.find("vendor_gipa") != std::string::npos);
    CHECK(result.message.find("vk_icdGetInstanceProcAddr") != std::string::npos);
    CHECK(result.message.find("vkGetInstanceProcAddr") != std::string::npos);
}

TEST_CASE("ResolveDirectDriver default operations open a real library", "[direct_driver]")
{
#if defined(_WIN32)
    const char* library = "kernel32.dll";
    const char* symbol  = "GetTickCount";
#elif defined(__APPLE__)
    const char* library = "libSystem.B.dylib";
    const char* symbol  = "cos";
#else
    const char* library = "libm.so.6";
    const char* symbol  = "cos";
#endif

    DirectDriverLoadOps ops    = GetDefaultDirectDriverLoadOps();
    auto                result = ResolveDirectDriver(MakeInfo(library, symbol, kFound), "", ops);

    REQUIRE(result.Succeeded());
    CHECK(result.symbol_name == symbol);
    REQUIRE(result.library != nullptr);
    ops.close_library(result.library);
}
