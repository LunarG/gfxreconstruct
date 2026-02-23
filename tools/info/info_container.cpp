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

#include PROJECT_VERSION_HEADER_FILE

#include "util/logging.h"

#include "info_container.h"

#include <format>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(info)

const char kHelpShortOption[]      = "-h";
const char kHelpLongOption[]       = "--help";
const char kVersionOption[]        = "--version";
const char kNoDebugPopup[]         = "--no-debug-popup";
const char kExeInfoOnlyOption[]    = "--exe-info-only";
const char kEnvVarsOnlyOption[]    = "--env-vars-only";
const char kFileFormatOnlyOption[] = "--file-format-only";
const char kEnumGpuIndices[]       = "--enum-gpu-indices";
const char kVerboseOption[]        = "--verbose";
const char kOutputFileArgument[]   = "--output";

const char kOptions[]   = "-h|--help,--version,--no-debug-popup,--exe-info-only,--env-vars-only,--file-format-only,--"
                          "enum-gpu-indices,--verbose";
const char kArguments[] = "--output";

InfoContainer::InfoContainer()
{
    gfxrecon::util::Log::Init();
}

InfoContainer::~InfoContainer()
{
    gfxrecon::util::Log::Release();
}

bool InfoContainer::CheckOptionPrintUsage(const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage();
        return true;
    }

    return false;
}

bool InfoContainer::CheckOptionPrintVersion(const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kVersionOption))
    {
        WriteOutput(std::format("{} version info:", app_name_));
        WriteOutput(std::format("  GFXReconstruct Version {}", GetProjectVersionString()));
        WriteOutput(std::format("  Vulkan Header Version {}.{}.{}",
                                VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                                VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                                VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE)));

        return true;
    }

    return false;
}

bool InfoContainer::RegisterApiInterface(std::unique_ptr<InfoApiInterface> api_interface)
{
    for (auto& api_if : api_interfaces_)
    {
        if (api_if->ApiFamilyId() == api_interface->ApiFamilyId())
        {
            WriteOutput(std::format("ERROR: Duplicate Api Interface for API {} found!\n",
                                    static_cast<uint32_t>(api_interface->ApiFamilyId())));
            return false;
        }
    }
    api_interfaces_.push_back(std::move(api_interface));
    return true;
}

bool InfoContainer::ProcessCommandLine(int32_t argc, const char** argv)
{
    // Save the app name first
    std::string app_name     = argv[0];
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    app_name_ = app_name;

    // Add any API-specific command-line arguments/options
    std::string arguments = kArguments;
    std::string options   = kOptions;
    for (auto& api_if : api_interfaces_)
    {
        api_if->UpdatePossibleCommandLineOptionsArgs(options, arguments);
    }

    // Temporary: We need to have the argument parser work with main.cpp for now while we
    // transition.  Long run this should only be a local definition.
    argument_parser_ = std::make_shared<gfxrecon::util::ArgumentParser>(argc, argv, options, arguments);

    if (argument_parser_->IsOptionSet(kHelpShortOption) || argument_parser_->IsOptionSet(kHelpLongOption))
    {
        PrintUsage();
    }
    else if (argument_parser_->IsOptionSet(kVersionOption))
    {
        PrintVersion();
    }
    else if (argument_parser_->IsInvalid() || (argument_parser_->GetPositionalArgumentsCount() != 1))
    {
        PrintUsage();
        return false;
    }

    // Check for API-specific items
    for (auto& api_if : api_interfaces_)
    {
        if (!api_if->CheckCommandLine(argument_parser_))
        {
            PrintUsage();
            return false;
        }
        if (api_if->ApiOutputOverrideDetected())
        {
            api_restricted_output_ = true;
        }
        else
        {
            api_if->SetOutputLevel(output_level_);
        }
    }

    if (argument_parser_->IsArgumentSet(kOutputFileArgument))
    {
        output_file_.open(argument_parser_->GetArgumentValue(kOutputFileArgument));
    }

    return true;
}

bool InfoContainer::ProcessCapture()
{
    // Print-only API-specific items
    if (api_restricted_output_)
    {
        for (auto& api_if : api_interfaces_)
        {
            if (!api_if->CheckCommandLine(argument_parser_))
            {
                PrintUsage();
                return false;
            }
            if (api_if->ApiOutputOverrideDetected())
            {
                api_restricted_output_ = true;
            }
            else
            {
                api_if->SetOutputLevel(output_level_);
            }
        }
    }
    return true;
}

bool InfoContainer::OutputContent()
{
    // Print-only API-specific items
    if (api_restricted_output_)
    {
        for (auto& api_if : api_interfaces_)
        {
            if (api_if->ApiOutputOverrideDetected())
            {
                api_if->OutputInfo();
                break;
            }
        }
    }
    else
    {
    }
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
    WriteOutput("  --verbose\t\tOutput more information in JSON format");
    WriteOutput(
        "  --output\t\tOutput generated information to the provided file. If not defined output goes to std::out");

    std::string api_specific_usage;
    for (auto& api_if : api_interfaces_)
    {
        api_if->UpdateCommandLineUsage(api_specific_usage);
    }
    WriteOutput(api_specific_usage);
}

void InfoContainer::PrintVersion()
{
    WriteOutput(std::format("{} version info:\n  GFXReconstruct Version {}", app_name_, GetProjectVersionString()));
    for (auto& api_if : api_interfaces_)
    {
        WriteOutput(std::format("   {} Header Version {}", api_if->ApiLabel(), api_if->ApiHeaderVersionString()));
    }
}

void InfoContainer::WriteOutput(const std::string& message)
{
    if (output_file_.is_open())
    {
        output_file_ << message << std::endl;
    }
    else
    {
        GFXRECON_WRITE_CONSOLE(message.c_str());
    }
}

GFXRECON_END_NAMESPACE(info)
GFXRECON_END_NAMESPACE(gfxrecon)
