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
#include "util/logging.h"

#include <filesystem>
#include <fstream>
#include <iterator>
#include <string>

using gfxrecon::util::Log;
using gfxrecon::util::LoggingSeverity;
using gfxrecon::util::logging::LoggingManager;

namespace
{

std::string ReadFile(const std::filesystem::path& path)
{
    std::ifstream file(path);
    return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
}

} // namespace

TEST_CASE("The log file target writes each message when it closes the file after each", "[logging]")
{
    const std::filesystem::path path = std::filesystem::temp_directory_path() / "gfxrecon_util_test_closed_log.txt";

    // Log::Init resets the file target, so it goes first.
    Log::Init(LoggingSeverity::kError);
    LoggingManager::GetSingleton().UpdateFileTarget(true, path.string(), true, false, true);
    CHECK_NOTHROW([] { GFXRECON_LOG_ERROR("first message"); }());
    CHECK_NOTHROW([] { GFXRECON_LOG_ERROR("second message"); }());
    LoggingManager::GetSingleton().UpdateFileTarget(false, "", false, false, false);

    const std::string log = ReadFile(path);
    CHECK(log.find("first message") != std::string::npos);
    CHECK(log.find("second message") != std::string::npos);

    std::error_code ignored;
    std::filesystem::remove(path, ignored);
}

TEST_CASE("A log file that cannot be opened does not stop logging", "[logging]")
{
    const std::filesystem::path path =
        std::filesystem::temp_directory_path() / "gfxrecon_util_test_no_such_dir" / "log.txt";

    Log::Init(LoggingSeverity::kError);

    SECTION("kept open")
    {
        CHECK_NOTHROW(LoggingManager::GetSingleton().UpdateFileTarget(true, path.string(), true, true, false));
        CHECK_NOTHROW([] { GFXRECON_LOG_ERROR("message for a file that is not there"); }());
    }

    SECTION("closed after each message")
    {
        CHECK_NOTHROW(LoggingManager::GetSingleton().UpdateFileTarget(true, path.string(), true, false, false));
        CHECK_NOTHROW([] { GFXRECON_LOG_ERROR("message for a file that is not there"); }());
    }

    LoggingManager::GetSingleton().UpdateFileTarget(false, "", false, false, false);
    CHECK_FALSE(std::filesystem::exists(path));
}
