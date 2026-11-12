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

#include "util/input_file_store.h"

#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include <algorithm>
#include <cerrno>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <system_error>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

namespace
{
// Prefix shared by every run's scratch directory; the process id follows it.
constexpr const char* kScratchPrefix = "gfxrecon-remote-";

// Removes directories left by runs that never reached Cleanup(), skipping any whose pid is still alive.
void ReapStaleDirectories(const std::filesystem::path& root)
{
    using NativeString = std::filesystem::path::string_type;

    const auto         self   = platform::GetCurrentProcessId();
    const NativeString prefix = std::filesystem::path(kScratchPrefix).native();

    // A range-for would throw on a read error; here it just ends the reap.
    std::error_code error;
    for (std::filesystem::directory_iterator entry(root, error), end; !error && (entry != end); entry.increment(error))
    {
        // string() throws on Windows when the name has a character the ANSI code page cannot represent.
        const NativeString name = entry->path().filename().native();
        if ((name.size() <= prefix.size()) || (name.compare(0, prefix.size(), prefix) != 0) ||
            !std::all_of(name.begin() + prefix.size(), name.end(), [](auto c) { return (c >= '0') && (c <= '9'); }))
        {
            continue;
        }

        // Pure ASCII by now, so string() cannot throw.
        const std::string suffix = entry->path().filename().string().substr(strlen(kScratchPrefix));
        const auto        pid    = static_cast<decltype(self)>(strtoull(suffix.c_str(), nullptr, 10));
        if ((pid == self) || platform::IsProcessRunning(pid))
        {
            continue;
        }

        std::error_code remove_error;
        std::filesystem::remove_all(entry->path(), remove_error);
        if (!remove_error)
        {
            GFXRECON_LOG_INFO("Input file store: removed input files left behind by process %" PRIu64,
                              static_cast<uint64_t>(pid));
        }
    }
}
} // namespace

InputFileStore::InputFileStore(std::string scratch_root) : scratch_root_(std::move(scratch_root)) {}

InputFileStore::~InputFileStore()
{
    Cleanup();
}

bool InputFileStore::EnsureScratchDir()
{
    if (!scratch_dir_.empty())
    {
        return true;
    }

    std::error_code       error;
    std::filesystem::path root = scratch_root_;
    if (root.empty())
    {
        root = std::filesystem::temp_directory_path(error);
        if (error)
        {
            GFXRECON_LOG_ERROR("Input file store: could not determine a temporary directory (%s)",
                               error.message().c_str());
            return false;
        }
    }

    ReapStaleDirectories(root);

    // The pid keeps concurrent replays from colliding and makes an abandoned directory attributable.
    const std::string candidate =
        filepath::Join(root.string(), kScratchPrefix + std::to_string(platform::GetCurrentProcessId()));

    // Not filepath::MakeDirectory: it fails when the directory exists, as it does when a pid is recycled.
    std::filesystem::create_directories(candidate, error);
    if (error)
    {
        GFXRECON_LOG_ERROR(
            "Input file store: could not create directory \"%s\" (%s)", candidate.c_str(), error.message().c_str());
        return false;
    }

    scratch_dir_ = candidate;
    return true;
}

bool InputFileStore::Add(const std::string& name, const std::vector<uint8_t>& data)
{
    // A bare name cannot direct the write outside the scratch directory.
    if (name.empty() || (name == ".") || (name == "..") || (filepath::GetFilename(name) != name))
    {
        GFXRECON_LOG_ERROR("Input file store: \"%s\" is not a bare file name", name.c_str());
        return false;
    }

    if (!EnsureScratchDir())
    {
        return false;
    }

    const std::string path = filepath::Join(scratch_dir_, name);

    // Not buffer_writer::WriteBuffer: with a channel active it would send the file back to the controller.
    FILE*         file       = nullptr;
    const int32_t open_error = platform::FileOpen(&file, path.c_str(), "wb");
    if ((open_error != 0) || (file == nullptr))
    {
        GFXRECON_LOG_ERROR("Input file store: could not open \"%s\" for writing (%s)",
                           path.c_str(),
                           std::generic_category().message(open_error).c_str());
        return false;
    }

    const bool written     = data.empty() || platform::FileWrite(data.data(), data.size(), file);
    const int  write_error = errno;

    // A small file stays in the stdio buffer until close, so a full disk may only show up here.
    const bool closed      = platform::FileClose(file) == 0;
    const int  close_error = errno;

    if (!written || !closed)
    {
        GFXRECON_LOG_ERROR("Input file store: could not write \"%s\" (%s)",
                           path.c_str(),
                           std::generic_category().message(written ? close_error : write_error).c_str());
        return false;
    }

    files_[name] = path;
    return true;
}

std::optional<std::string> InputFileStore::Resolve(const std::string& name) const
{
    const auto entry = files_.find(name);
    if (entry == files_.end())
    {
        return std::nullopt;
    }
    return entry->second;
}

void InputFileStore::Cleanup()
{
    if (!scratch_dir_.empty())
    {
        std::error_code error;
        std::filesystem::remove_all(scratch_dir_, error);
        if (error)
        {
            GFXRECON_LOG_WARNING("Input file store: could not remove directory \"%s\" (%s)",
                                 scratch_dir_.c_str(),
                                 error.message().c_str());
        }
        scratch_dir_.clear();
    }

    files_.clear();
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
