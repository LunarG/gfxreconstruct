/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#include "util/defines.h"

#include "info_api_interface.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

InfoContainer::InfoContainer() {}

~InfoContainer::InfoContainer() {}

bool InfoContainer::RegisterApiInterface(InfoApiInterface* api_interface)
{
    return false;
}

bool InfoContainer::ProcessCommandLine((int argc, const char** argv))
{
    // Save the app name first
    std::string app_name     = argv[0];
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    app_name_ = app_name;

    return false;
}

bool InfoContainer::ProcessCapture()
{
    return false;
}

bool InfoContainer::OutputContent()
{
    return false;
}

void InfoContainer::PrintUsage()
{
    WriteOutput(std::format("\n{} - Print statistics for a GFXReconstruct capture file.", app_name_));
    WriteOutput(std::format(
        "Usage:\n  {} [-h | --help] [--version] [--exe-info-only] [--verbose] [--output <file>] <capture-file>",
        app_name_));
    WriteOutput("Required arguments:");
    WriteOutput("  <capture-file>\tThe GFXReconstruct capture file to be processed.");
    WriteOutput("\nOptional arguments:");
    WriteOutput("  -h\t\t\tPrint usage information and exit (same as --help).");
    WriteOutput("  --version\t\tPrint version information and exit.");
    WriteOutput("  --exe-info-only\tQuickly exit after extracting captured application's executable name");
    WriteOutput("  --file-format-only\tQuickly exit after extracting file format information");
    WriteOutput("  --env-vars-only\tQuickly exit after extracting captured application's environment variables");
#if defined(WIN32) && defined(_DEBUG)
    WriteOutput("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    WriteOutput("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
#if defined(WIN32)
    WriteOutput("  --enum-gpu-indices\tPrint GPU indices and exit");
#endif
    WriteOutput("  --verbose\t\tOutput more information in JSON format");
    WriteOutput(
        "  --output\t\tOutput generated information to the provided file. If not defined output goes to std::out");
}

void InfoContainer::PrintVersion()
{
    WriteOutput(std::format("{} version info:\n  GFXReconstruct Version {}", app_name_, GetProjectVersionString()));
    for (auto& api_if : api_interfaces_)
    {
        WriteOutput(std::format("   {} Header Version {}", api_if->ApiLabel(), api_if->ApiHeaderVersion()));
    }
}

void InfoContainer::WriteOutput(const std::string& message)
{
    GFXRECON_WRITE_CONSOLE(message.c_str());
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)
