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

#define GFXR_HIDE_PRINT_USAGE_DEFINE
#include "tool_settings.h"

#include <format>
#include <vector>

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
const char kArguments[] = "--output,--log-level";

InfoContainer::InfoContainer()
{
    gfxrecon::util::Log::Init();
}

InfoContainer::~InfoContainer()
{
    gfxrecon::util::Log::Release();
}

bool InfoContainer::RegisterApiInterface(std::unique_ptr<InfoApiInterface> api_interface)
{
    for (auto& api_if : api_interfaces_)
    {
        if (api_if->ApiFamilyId() == api_interface->ApiFamilyId())
        {
            GFXRECON_LOG_ERROR(std::format("Duplicate Api Interface for API {} found!\n",
                                           static_cast<uint32_t>(api_interface->ApiFamilyId()))
                                   .c_str());
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

    // Create a shared argument parser so we can share it with the API-specific interfaces
    argument_parser_ = std::make_shared<gfxrecon::util::ArgumentParser>(argc, argv, options, arguments);

    if (argument_parser_->IsOptionSet(kHelpShortOption) || argument_parser_->IsOptionSet(kHelpLongOption))
    {
        PrintUsage();
        output_level_ = InfoApiInterface::InfoOutputLevel::kInfoVersionOnly;
    }
    else if (argument_parser_->IsOptionSet(kVersionOption))
    {
        PrintVersion();
        output_level_ = InfoApiInterface::InfoOutputLevel::kInfoVersionOnly;
    }
    else if (argument_parser_->IsInvalid() || (argument_parser_->GetPositionalArgumentsCount() != 1))
    {
        GFXRECON_LOG_ERROR("Missing required capture file name");

        PrintUsage();
        output_level_ = InfoApiInterface::InfoOutputLevel::kInfoVersionOnly;
        return false;
    }
#if defined(WIN32) && defined(_DEBUG)
    if (arg_parser.IsOptionSet(kNoDebugPopup))
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    }
#endif

    // Update logging with values retrieved from command line arguments
    gfxrecon::util::Log::Settings log_settings;
    GetLogSettings(*argument_parser_.get(), log_settings);
    gfxrecon::util::Log::UpdateWithSettings(log_settings);

    if (argument_parser_->IsOptionSet(kExeInfoOnlyOption))
    {
        output_level_ = InfoApiInterface::InfoOutputLevel::kExeInfo;
    }
    else if (argument_parser_->IsOptionSet(kEnvVarsOnlyOption))
    {
        output_level_ = InfoApiInterface::InfoOutputLevel::kEnvironmentInfo;
    }
    else if (argument_parser_->IsOptionSet(kFileFormatOnlyOption))
    {
        output_level_ = InfoApiInterface::InfoOutputLevel::kFileInfo;
    }
    else if (argument_parser_->IsOptionSet(kVerboseOption))
    {
        output_level_ = InfoApiInterface::InfoOutputLevel::kVerbose;
    }

    if (output_level_ > InfoApiInterface::InfoOutputLevel::kInfoVersionOnly)
    {
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
    }

    return true;
}

bool InfoContainer::ProcessCapture()
{
    if (output_level_ > InfoApiInterface::InfoOutputLevel::kInfoVersionOnly)
    {
        const std::vector<std::string>& positional_arguments = argument_parser_->GetPositionalArguments();
        std::string                     input_filename       = positional_arguments[0];

        if (file_processor_.Initialize(input_filename))
        {
            stat_decoder_.AddConsumer(&stat_consumer_);
            info_decoder_.AddConsumer(&info_consumer_);
            file_processor_.AddDecoder(&stat_decoder_);
            file_processor_.AddDecoder(&info_decoder_);
            file_processor_.SetAnnotationProcessor(&annotation_recorder_);

            if (output_level_ >= InfoApiInterface::InfoOutputLevel::kApiSpecificBegin)
            {
                for (auto& api_if : api_interfaces_)
                {
                    api_if->RegisterApiDecodeComponents(file_processor_);
                }
            }

            // For file info, we want to do a simpler pass.
            // For everything else, we want to parse the file
            if (output_level_ == InfoApiInterface::InfoOutputLevel::kFileInfo)
            {
                if (!file_processor_.ProcessNextFrame())
                {
                    return false;
                }
                if (!file_processor_.UsesFrameMarkers())
                {
                    file_processor_.ProcessNextFrame();
                }
            }
            else if (output_level_ > InfoApiInterface::InfoOutputLevel::kFileInfo)
            {
                file_processor_.ProcessAllFrames();
            }

            if (file_processor_.GetErrorState() != gfxrecon::decode::BlockIOError::kErrorNone)
            {
                WriteOutput("Encountered error while reading capture, info unavailable.");
                return false;
            }

            if (output_level_ >= InfoApiInterface::InfoOutputLevel::kApiSpecificBegin)
            {
                bool api_found = false;
                for (auto& api_if : api_interfaces_)
                {
                    if (api_if->ApiWasDetected())
                    {
                        api_found = true;
                    }
                }

                // If no API data found, force each API to try to spit out info
                if (!api_found)
                {
                    WriteOutput("Unable to detect capture file API(s). Writing all stats.");
                    force_all_api_output_ = true;
                }
            }
        }
    }
    return true;
}

bool InfoContainer::OutputContent()
{
    std::vector<std::string> detected_apis;
    for (auto& api_if : api_interfaces_)
    {
        if (api_if->ApiWasDetected())
        {
            detected_apis.push_back(api_if->ApiLabel());
        }
    }

    switch (output_level_)
    {
        case InfoApiInterface::InfoOutputLevel::kExeInfo:
            PrintExeInfo();
            break;
        case InfoApiInterface::InfoOutputLevel::kEnvironmentInfo:
            PrintEnvironmentVariableInfo();
            break;
        case InfoApiInterface::InfoOutputLevel::kFileInfo:
            PrintFileFormatInfoText();
            break;
        case InfoApiInterface::InfoOutputLevel::kBasic:
            if (!detected_apis.size())
            {
                WriteOutput("Unable to detect capture file API(s). Writing all stats.");
            }
            PrintExeInfo();
            break;
        case InfoApiInterface::InfoOutputLevel::kVerbose:
            json_base_["exe"]         = GetExeInfoJson();
            json_base_["environment"] = GetEnvironmentVariableInfoJson();
            json_base_["file-info"]   = GetFileFormatInfoJson();

            if (!detected_apis.size())
            {
                detected_apis.push_back("Unable to detect captured APIs");
            }
            json_base_["detected-apis"] = detected_apis;

            WriteOutput(json_base_.dump(4, ' ', true).c_str());
            break;
        default:
            break;
    }

    if (output_level_ >= InfoApiInterface::InfoOutputLevel::kApiSpecificBegin)
    {
        for (auto& api_if : api_interfaces_)
        {
            if ((api_if->ApiWasDetected() || force_all_api_output_) &&
                (!api_restricted_output_ || api_if->ApiOutputOverrideDetected()))
            {
                api_if->OutputInfo();

                if (api_restricted_output_)
                {
                    break;
                }
            }
        }
    }
    return true;
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
    WriteOutput("  --log-level <level>\tSpecify highest level message to log. Options are:");
    WriteOutput("                  \t\tdebug, info, warning, error, and fatal. Default is info.");

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
        WriteOutput(api_if->ApiCompiledHeaderVersionString());
    }
}

void InfoContainer::PrintExeInfo()
{
    std::string exe_name     = info_consumer_.GetAppExeName();
    auto        exe_version  = info_consumer_.GetAppVersion();
    std::string company_name = info_consumer_.GetCompanyName();
    std::string file_desc    = info_consumer_.GetFileDescription();
    std::string product_name = info_consumer_.GetProductName();

    WriteOutput("Exe info:");
    WriteOutput(std::format("\tApplication exe name: {}", exe_name));

    WriteOutput(std::format(
        "\tApplication version: {}.{}.{}.{}", exe_version[0], exe_version[1], exe_version[2], exe_version[3]));
    WriteOutput(std::format("\tApplication Company name: {}", company_name));

    // we are combining file description and product name and presenting both only if they are not same
    std::string app_data = file_desc;
    if (strcmp(product_name.c_str(), "N/A") != 0)
    {
        if (strcmp(product_name.c_str(), file_desc.c_str()) != 0)
        {
            app_data += " // ";
            app_data += product_name;
        }
    }
    WriteOutput(std::format("\tProduct name: {}", app_data));
}

nlohmann::json InfoContainer::GetExeInfoJson()
{
    std::string exe_name     = info_consumer_.GetAppExeName();
    auto        exe_version  = info_consumer_.GetAppVersion();
    std::string company_name = info_consumer_.GetCompanyName();
    std::string file_desc    = info_consumer_.GetFileDescription();
    std::string product_name = info_consumer_.GetProductName();

    return {
        { "name", exe_name },
        { "version", std::format("{}.{}.{}.{}", exe_version[0], exe_version[1], exe_version[2], exe_version[3]) },
        { "company", company_name },
        { "product", product_name },
        { "file-description", file_desc },
    };
}

void InfoContainer::PrintEnvironmentVariableInfo()
{
    WriteOutput("Environment variables:");
    for (const auto& var : info_consumer_.GetEnvironmentVariables())
    {
        WriteOutput(std::format("\t{}", var));
    }
}

nlohmann::json InfoContainer::GetEnvironmentVariableInfoJson()
{
    nlohmann::json           environment;
    static const std::string delimiter = "=";

    for (const auto& var : info_consumer_.GetEnvironmentVariables())
    {
        const auto& delimiter_pos = var.find(delimiter);
        std::string key           = var.substr(0, delimiter_pos);
        std::string value         = var.substr(delimiter_pos + 1);
        environment[key]          = value;
    }

    return environment;
}

std::string InfoContainer::GetFrameMarkerString(bool uses_frame_markers, bool needs_update)
{
    return uses_frame_markers ? (needs_update ? "explicit (unsupported)" : "explicit") : "implicit";
}

void InfoContainer::PrintFileFormatInfoText()
{
    WriteOutput("File format info:");
    FileFormatInfo file_format_info(file_processor_);
    WriteOutput(
        std::format("\tFile format version: {}.{}", file_format_info.major_version, file_format_info.minor_version));
    WriteOutput(std::format("\tFrame delimiters: {}",
                            GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate())));
}

nlohmann::json InfoContainer::GetFileFormatInfoJson()
{
    FileFormatInfo file_format_info(file_processor_);

    return {
        { "file-version", std::format("{}.{}", file_format_info.major_version, file_format_info.minor_version) },
        { "frame-delimiters",
          GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate()) },
    };
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
