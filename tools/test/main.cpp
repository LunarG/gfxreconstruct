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
/// @file Tests that run the tool executables and check their exit codes

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <string>

namespace
{

// Runs a tool on one file and returns what std::system reports, which is non-zero when the tool exits non-zero.
int RunTool(const std::filesystem::path& tool, const std::filesystem::path& file)
{
    REQUIRE(std::filesystem::exists(tool));

    std::string command = "\"" + tool.string() + "\" \"" + file.string() + "\"";
#if defined(_WIN32)
    // cmd.exe strips the first and last quote of a command that starts with one.
    command = "\"" + command + "\"";
#endif
    return std::system(command.c_str());
}

// A file that exists but does not start with a capture file header.
std::filesystem::path WriteBadCapture(const std::string& name)
{
    const std::filesystem::path path = std::filesystem::temp_directory_path() / name;
    std::ofstream               file(path, std::ios::binary | std::ios::trunc);
    file << "not a capture file";
    return path;
}

std::filesystem::path MissingCapture(const std::string& name)
{
    const std::filesystem::path path = std::filesystem::temp_directory_path() / name;
    std::filesystem::remove(path);
    return path;
}

} // namespace

TEST_CASE("convert fails when the capture cannot be read", "[convert]")
{
    const std::filesystem::path tool = GFXRECON_CONVERT_PATH;

    SECTION("missing file")
    {
        CHECK(RunTool(tool, MissingCapture("gfxrecon_tools_test_convert_missing.gfxr")) != 0);
    }

    SECTION("bad header")
    {
        const std::filesystem::path capture = WriteBadCapture("gfxrecon_tools_test_convert_bad.gfxr");
        CHECK(RunTool(tool, capture) != 0);
        std::filesystem::remove(capture);
    }
}

TEST_CASE("extract fails when the capture cannot be read", "[extract]")
{
    const std::filesystem::path tool = GFXRECON_EXTRACT_PATH;

    SECTION("missing file")
    {
        CHECK(RunTool(tool, MissingCapture("gfxrecon_tools_test_extract_missing.gfxr")) != 0);
    }

    SECTION("bad header")
    {
        const std::filesystem::path capture = WriteBadCapture("gfxrecon_tools_test_extract_bad.gfxr");
        CHECK(RunTool(tool, capture) != 0);
        std::filesystem::remove(capture);
    }
}
