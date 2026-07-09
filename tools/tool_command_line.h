/*
** Copyright (c) 2019-2026 LunarG, Inc.
** Copyright (c) 2021-2025 Advanced Micro Devices, Inc. All rights reserved.
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

// Common "-h/--help" and "--version" handling shared by all of the command-line tools. Kept
// separate from tool_settings.h (which pulls in the full replay decode/option stack) so that
// lightweight tools can get consistent usage/version output without the heavier dependencies.

#ifndef GFXRECON_TOOL_COMMAND_LINE_H
#define GFXRECON_TOOL_COMMAND_LINE_H

#include PROJECT_VERSION_HEADER_FILE

#include "util/argument_parser.h"
#include "util/logging.h"

#include "vulkan/vulkan_core.h"

#if ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#endif

#include <filesystem>
#include <string>

const char kHelpShortOption[] = "-h";
const char kHelpLongOption[]  = "--help";
const char kVersionOption[]   = "--version";

/// Prints the "<app name> version info:" / "GFXReconstruct Version x.x.x" lines common to every
/// tool's --version output. Tools that report additional version information (e.g. per-API
/// header versions) print it after calling this.
inline void PrintVersionHeader(const char* exe_name)
{
    std::string app_name = std::filesystem::path(exe_name).stem().string();

    GFXRECON_WRITE_CONSOLE("%s version info:", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("  GFXReconstruct Version %s", GetProjectVersionString());
}

static bool CheckOptionPrintVersion(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kVersionOption))
    {
        PrintVersionHeader(exe_name);
        GFXRECON_WRITE_CONSOLE("  Vulkan Header Version %u.%u.%u",
                               VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

#if ENABLE_OPENXR_SUPPORT
        GFXRECON_WRITE_CONSOLE("  OpenXR Header Version %u.%u.%u",
                               XR_VERSION_MAJOR(XR_CURRENT_API_VERSION),
                               XR_VERSION_MINOR(XR_CURRENT_API_VERSION),
                               XR_VERSION_PATCH(XR_CURRENT_API_VERSION));
#endif

        return true;
    }

    return false;
}

static void PrintUsage(const char* exe_name);

static bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

#endif // GFXRECON_TOOL_COMMAND_LINE_H
