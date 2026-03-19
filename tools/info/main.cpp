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

#define GFXR_HIDE_PRINT_USAGE_DEFINE
#include "tool_settings.h"

#include "util/argument_parser.h"
#include "util/defines.h"
#include "decode/file_processor.h"
#include "decode/info_consumer.h"
#include "decode/info_decoder.h"
#include "decode/stat_consumer.h"
#include "decode/stat_decoder_base.h"
#include "decode/stat_consumer_base.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/feature_module_registry.h"

#include "info_feature.h"

#include <nlohmann/json.hpp>

#include <algorithm>
#include <format>
#include <memory>
#include <vector>

const char kExeInfoOnlyOption[]    = "--exe-info-only";
const char kEnvVarsOnlyOption[]    = "--env-vars-only";
const char kFileFormatOnlyOption[] = "--file-format-only";
const char kEnumGpuIndices[]       = "--enum-gpu-indices";
const char kVerboseOption[]        = "--verbose";
const char kOutputFileArgument[]   = "--output";

const char kOptions[]   = "-h|--help,--version,--no-debug-popup,--exe-info-only,--env-vars-only,--file-format-only,--"
                          "enum-gpu-indices,--verbose";
const char kArguments[] = "--output,--log-level";

const char kUnrecognizedFormatString[] = "<unrecognized-format>";
const int  kDefaultIndent              = 12;

class InfoGenerator
{
  public:
    InfoGenerator();
    ~InfoGenerator();

    bool ProcessCommandLine(int32_t argc, const char** argv);

    bool ProcessCapture();

    bool OutputContent();

  private:
    void PrintUsage();
    void PrintVersion();

    void           PrintExeInfo();
    nlohmann::json GetExeInfoJson();

    void           PrintEnvironmentVariableInfo();
    nlohmann::json GetEnvironmentVariableInfoJson();

    std::string    GetFrameMarkerString(bool uses_frame_markers, bool needs_update);
    void           PrintFileFormatInfoText();
    nlohmann::json GetFileFormatInfoJson();

    void           GatherApiAgnosticStats();
    void           PrintApiAgnosticStatsText();
    nlohmann::json GetApiAgnosticStatsJson();

    void           PrintGfxrOperationsText();
    nlohmann::json GetGfxrOperationsJson();

    void WriteOutput(const std::string& message);

    class AnnotationRecorder : public gfxrecon::decode::AnnotationHandler
    {
      public:
        std::vector<std::string> operation_annotations_;

        virtual void ProcessAnnotation(uint64_t                         block_index,
                                       gfxrecon::format::AnnotationType type,
                                       const std::string&               label,
                                       const std::string&               data) override
        {
            if (type == gfxrecon::format::AnnotationType::kJson &&
                label.compare(gfxrecon::format::kAnnotationLabelOperation) == 0)
            {
                if (data.size() > 0)
                {
                    // Inspect annotations spotted in the capture file
                    nlohmann::json json_obj = nlohmann::json::parse(data);
                    if (json_obj.is_discarded())
                    {
                        GFXRECON_LOG_WARNING("Invalid JSON in annotation: \"%s\"", data.c_str());
                    }
                    else
                    {
                        operation_annotations_.push_back(data);
                    }
                }
            }
        }
    };

    struct ApiAgnosticStats
    {
        gfxrecon::format::CompressionType compression_type;
        uint32_t                          trim_start_frame;
        uint32_t                          frame_count;
        uint32_t                          blank_frame_count;
        bool                              uses_frame_markers;
    };

    struct FileFormatInfo
    {
        uint32_t major_version               = 0;
        uint32_t minor_version               = 0;
        bool     uses_frame_markers          = false;
        bool     file_supports_frame_markers = false;

        FileFormatInfo(const gfxrecon::decode::FileProcessor& file_processor)
        {
            const gfxrecon::format::FileHeader& file_header = file_processor.GetFileHeader();
            major_version                                   = file_header.major_version;
            minor_version                                   = file_header.minor_version;
            uses_frame_markers                              = file_processor.UsesFrameMarkers();
            file_supports_frame_markers                     = file_processor.FileSupportsFrameMarkers();
        }

        bool NeedsUpdate() const
        {
            return major_version == 0 && minor_version == 0 && uses_frame_markers && !file_supports_frame_markers;
        }
    };

    struct OutputSelections
    {
        bool output_nothing{ false };
        bool file_info{ false };
        bool exe_info{ false };
        bool environment_info{ false };
        bool general_info{ true };
        bool api_specific_info{ false };
    };

    std::string                                                    app_name_;
    std::vector<std::unique_ptr<gfxrecon::info::InfoFeature>>      info_features_;
    std::vector<std::string>                                       detected_apis_;
    OutputSelections                                               output_selections_;
    uint32_t                                                       blank_frame_count_{ 0 };
    uint32_t                                                       start_frame_{ 0 };
    bool                                                           use_single_line_frame_output_{ false };
    bool                                                           force_all_api_output_{ false };
    gfxrecon::decode::FileProcessor                                file_processor_;
    gfxrecon::decode::StatDecoderBase                              stat_decoder_;
    gfxrecon::decode::StatConsumer                                 stat_consumer_;
    gfxrecon::decode::InfoConsumer                                 info_consumer_;
    gfxrecon::decode::InfoDecoder                                  info_decoder_;
    AnnotationRecorder                                             annotation_recorder_;
    ApiAgnosticStats                                               api_agnostic_stats_;
    std::unique_ptr<gfxrecon::util::ArgumentParser>                argument_parser_;
    bool                                                           output_json_format_{ false };
    nlohmann::json                                                 json_base_;
    std::ofstream                                                  output_file_;
};

InfoGenerator::InfoGenerator()
{
    gfxrecon::util::Log::Init();

    // Query the module registry for registered modules, and
    // call each generator here and put the unique_ptr into our
    // internal unique_ptr vector.
    for (const auto& registered_creator :
         gfxrecon::util::FeatureModuleRegistry<gfxrecon::info::InfoFeature>::GetSingleton()
             .GetRegisteredFeatureCreators())
    {
        info_features_.push_back(std::move(registered_creator()));
    }
}

InfoGenerator::~InfoGenerator()
{
    gfxrecon::util::Log::Release();
}

bool InfoGenerator::ProcessCommandLine(int32_t argc, const char** argv)
{
    // Save the app name first
    const std::string app_name_ = std::filesystem::path{ argv[0] }.filename().string();

    // Add any API-specific command-line arguments/options
    std::string arguments = kArguments;
    std::string options   = kOptions;
    for (auto& api_gen : info_features_)
    {
        api_gen->UpdateValidCommandLineOptionsArgs(options, arguments);
    }

    // Create a shared argument parser so we can share it with the API-specific generators
    argument_parser_ = std::make_unique<gfxrecon::util::ArgumentParser>(argc, argv, options, arguments);

    if (argument_parser_->IsOptionSet(kHelpShortOption) || argument_parser_->IsOptionSet(kHelpLongOption))
    {
        PrintUsage();
        output_selections_.output_nothing = true;
        output_selections_.general_info   = false;
        return true;
    }
    else if (argument_parser_->IsOptionSet(kVersionOption))
    {
        PrintVersion();
        output_selections_.output_nothing = true;
        output_selections_.general_info   = false;
        return true;
        return true;
    }
    else if (argument_parser_->IsInvalid() || (argument_parser_->GetPositionalArgumentsCount() != 1))
    {
        GFXRECON_LOG_ERROR("Missing required capture file name");

        PrintUsage();
        output_selections_.output_nothing = true;
        output_selections_.general_info   = false;
        return true;
        return false;
    }

#if defined(WIN32) && defined(_DEBUG)
    if (argument_parser_->IsOptionSet(kNoDebugPopup))
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
        output_selections_.general_info = false;
        output_selections_.exe_info     = true;
    }
    else if (argument_parser_->IsOptionSet(kEnvVarsOnlyOption))
    {
        output_selections_.general_info     = false;
        output_selections_.environment_info = true;
    }
    else if (argument_parser_->IsOptionSet(kFileFormatOnlyOption))
    {
        output_selections_.general_info = false;
        output_selections_.file_info    = true;
    }
    else if (argument_parser_->IsOptionSet(kVerboseOption))
    {
        output_selections_.exe_info         = true;
        output_selections_.file_info        = true;
        output_selections_.environment_info = true;
        output_json_format_                 = true;
    }

    // Check for API-specific items
    for (auto& api_gen : info_features_)
    {
        if (!api_gen->CheckCommandLine(argument_parser_.get()))
        {
            PrintUsage();
            return false;
        }
        if (api_gen->RestrictingOutput())
        {
            output_selections_                   = {};
            output_selections_.general_info      = false;
            output_selections_.api_specific_info = true;
        }
    }

    if (argument_parser_->IsArgumentSet(kOutputFileArgument))
    {
        output_file_.open(argument_parser_->GetArgumentValue(kOutputFileArgument));
        if (!output_file_.is_open())
        {
            GFXRECON_LOG_ERROR(
                (std::string("Failed to open file ") + argument_parser_->GetArgumentValue(kOutputFileArgument) + "\n")
                    .c_str());
        }
    }

    return true;
}

bool InfoGenerator::ProcessCapture()
{
    if (!output_selections_.output_nothing)
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

            // For only some of the shortcut command-line options, we want to do a simpler pass.
            if (output_selections_.file_info || output_selections_.environment_info || output_selections_.exe_info)
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
            // For everything else, we want to parse the entire file.
            else if (output_selections_.general_info || output_selections_.api_specific_info)
            {
                for (auto& api_gen : info_features_)
                {
                    api_gen->RegisterApiDecodeComponents(file_processor_);
                }

                file_processor_.ProcessAllFrames();
            }

            if (file_processor_.GetErrorState() != gfxrecon::decode::BlockIOError::kErrorNone)
            {
                GFXRECON_LOG_ERROR("Encountered error while reading capture, Stats unavailable.");
                return false;
            }

            // Look to see what APIs we detected.  If none were found, we want to output
            // whatever we can from every possible API since we might have just failed to
            // detect it manually.
            if (output_selections_.general_info || output_selections_.api_specific_info)
            {
                std::string driver_info = "Driver info not available.";
                if (gfxrecon::util::platform::StringLength(info_consumer_.GetDriverDesc()) > 0)
                {
                    driver_info = info_consumer_.GetDriverDesc();
                }

                bool api_found = false;
                for (auto& api_gen : info_features_)
                {
                    if (api_gen->ApiWasDetected())
                    {
                        detected_apis_.push_back(api_gen->ApiLabel());
                        blank_frame_count_ += api_gen->GetBlankFrameCount();
                        uint32_t api_start_frame = api_gen->GetFrameStart();
                        if (api_start_frame > start_frame_)
                        {
                            start_frame_ = api_start_frame;
                        }
                        api_gen->SetFrameMarkerUsage(file_processor_.UsesFrameMarkers());
                        api_gen->SetDriverInfoString(driver_info);
                        api_found = true;

                        if (api_gen->ApiDesiresSingleLineFrameOutput())
                        {
                            use_single_line_frame_output_ = true;
                        }
                    }
                }

                // If no API data found, force each API to try to spit out info
                if (!api_found)
                {
                    GFXRECON_LOG_WARNING("Unable to detect capture file API(s). Writing all stats.");
                    force_all_api_output_ = true;
                }
                GatherApiAgnosticStats();
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool InfoGenerator::OutputContent()
{
    if (output_selections_.exe_info)
    {
        if (output_json_format_)
        {
            json_base_["exe"] = GetExeInfoJson();
        }
        else
        {
            PrintExeInfo();
        }
    }
    if (output_selections_.environment_info)
    {
        if (output_json_format_)
        {
            json_base_["environment"] = GetEnvironmentVariableInfoJson();
        }
        else
        {
            PrintEnvironmentVariableInfo();
        }
    }
    if (output_selections_.file_info)
    {
        if (output_json_format_)
        {
            json_base_["file-info"] = GetFileFormatInfoJson();
        }
        else
        {
            PrintFileFormatInfoText();
        }
    }
    if (output_selections_.general_info || output_selections_.api_specific_info)
    {
        if (output_json_format_)
        {
            if (!detected_apis_.size())
            {
                detected_apis_.push_back("Unable to detect captured APIs");
            }
            json_base_["detected-apis"] = detected_apis_;
            json_base_["general-info"]  = GetApiAgnosticStatsJson();
        }
        else
        {
            PrintApiAgnosticStatsText();
        }

        for (auto& api_gen : info_features_)
        {
            if ((api_gen->ApiWasDetected() || force_all_api_output_))
            {
                if (output_json_format_)
                {
                    std::string api_lower = api_gen->ApiLabel();
                    std::transform(api_lower.begin(), api_lower.end(), api_lower.begin(), [](unsigned char c) {
                        return std::tolower(c);
                    });

                    json_base_[api_lower] = api_gen->GenerateJson();
                }
                else
                {
                    WriteOutput(api_gen->GenerateText());
                }
            }
        }

        if (file_processor_.GetCurrentFrameNumber() == 0)
        {
            GFXRECON_LOG_WARNING("File did not contain any frames");
        }

        if (output_json_format_)
        {
            if (!annotation_recorder_.operation_annotations_.empty())
            {
                json_base_["gfxr-operations"] = GetGfxrOperationsJson();
            }
        }
        else
        {
            PrintGfxrOperationsText();
        }
    }

    if (!output_selections_.output_nothing && output_json_format_)
    {
        WriteOutput(json_base_.dump(4, ' ', true).c_str());
    }

    return true;
}

void InfoGenerator::PrintUsage()
{
    WriteOutput((std::string("\n") + app_name_ + " - Print statistics for a GFXReconstruct capture file.").c_str());
    WriteOutput((std::string("Usage:\n  ") + app_name_ +
                 " [-h | --help] [--version] [--exe-info-only] [--verbose] [--output <file>] <capture-file>")
                    .c_str());
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
        "  --output\t\tOutput generated information to the provided file. If not defined output goes to stdout");
    WriteOutput("  --log-level <level>\tSpecify highest level message to log. Options are:");
    WriteOutput("                  \t\tdebug, info, warning, error, and fatal. Default is info.");

    for (auto& api_gen : info_features_)
    {
        WriteOutput(api_gen->GetCommandLineUsage());
    }
}

void InfoGenerator::PrintVersion()
{
    WriteOutput((app_name_ + " version info:\n  GFXReconstruct Version " + GetProjectVersionString()).c_str());
    for (auto& api_gen : info_features_)
    {
        WriteOutput(api_gen->ApiCompiledHeaderVersionString());
    }
}

void InfoGenerator::PrintExeInfo()
{
    std::string exe_name     = info_consumer_.GetAppExeName();
    auto        exe_version  = info_consumer_.GetAppVersion();
    std::string company_name = info_consumer_.GetCompanyName();
    std::string file_desc    = info_consumer_.GetFileDescription();
    std::string product_name = info_consumer_.GetProductName();

    WriteOutput("Exe info:");
    WriteOutput(std::string("\tApplication exe name: ") + exe_name);

    WriteOutput(std::string("\tApplication version: ") + std::to_string(exe_version[0]) + "." +
                std::to_string(exe_version[1]) + "." + std::to_string(exe_version[2]) + "." +
                std::to_string(exe_version[3]));
    WriteOutput(std::string("\tApplication Company name: ") + company_name);

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
    WriteOutput(std::string("\tProduct name: ") + app_data);
}

nlohmann::json InfoGenerator::GetExeInfoJson()
{
    std::string exe_name     = info_consumer_.GetAppExeName();
    auto        exe_version  = info_consumer_.GetAppVersion();
    std::string company_name = info_consumer_.GetCompanyName();
    std::string file_desc    = info_consumer_.GetFileDescription();
    std::string product_name = info_consumer_.GetProductName();

    std::string version_string = std::to_string(exe_version[0]) + "." + std::to_string(exe_version[1]) + "." +
                                 std::to_string(exe_version[2]) + "." + std::to_string(exe_version[3]);

    return {
        { "name", exe_name },        { "version", version_string },     { "company", company_name },
        { "product", product_name }, { "file-description", file_desc },
    };
}

void InfoGenerator::PrintEnvironmentVariableInfo()
{
    WriteOutput("Environment variables:");
    for (const auto& var : info_consumer_.GetEnvironmentVariables())
    {
        WriteOutput(std::string("\t") + var);
    }
}

nlohmann::json InfoGenerator::GetEnvironmentVariableInfoJson()
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

std::string InfoGenerator::GetFrameMarkerString(bool uses_frame_markers, bool needs_update)
{
    return uses_frame_markers ? (needs_update ? "explicit (unsupported)" : "explicit") : "implicit";
}

void InfoGenerator::PrintFileFormatInfoText()
{
    WriteOutput("File format info:");
    FileFormatInfo file_format_info(file_processor_);
    WriteOutput(std::string("\tFile format version: ") + std::to_string(file_format_info.major_version) + "." +
                std::to_string(file_format_info.minor_version));
    WriteOutput(std::string("\tFrame delimiters: " +
                            GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate())));
}

nlohmann::json InfoGenerator::GetFileFormatInfoJson()
{
    FileFormatInfo file_format_info(file_processor_);

    return {
        { "file-version",
          std::to_string(file_format_info.major_version) + "." + std::to_string(file_format_info.minor_version) },
        { "frame-delimiters",
          GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate()) },
    };
}

void InfoGenerator::GatherApiAgnosticStats()
{
    // File options.
    gfxrecon::format::CompressionType compression_type = gfxrecon::format::CompressionType::kNone;

    auto file_options = file_processor_.GetFileOptions();
    for (const auto& option : file_options)
    {
        if (option.key == gfxrecon::format::FileOption::kCompressionType)
        {
            compression_type = static_cast<gfxrecon::format::CompressionType>(option.value);
        }
    }
    api_agnostic_stats_.compression_type = compression_type;
    api_agnostic_stats_.trim_start_frame = stat_consumer_.GetTrimmedStartFrame();
    if (start_frame_ > api_agnostic_stats_.trim_start_frame)
    {
        api_agnostic_stats_.trim_start_frame = start_frame_;
    }
    api_agnostic_stats_.uses_frame_markers = file_processor_.UsesFrameMarkers();
    api_agnostic_stats_.blank_frame_count  = blank_frame_count_;
    GFXRECON_NARROWING_ASSIGN(api_agnostic_stats_.frame_count, file_processor_.GetCurrentFrameNumber());
}

void InfoGenerator::PrintApiAgnosticStatsText()
{
    // Compression type.
    std::string compression_type_name = gfxrecon::format::GetCompressionTypeName(api_agnostic_stats_.compression_type);
    if (compression_type_name.empty())
    {
        compression_type_name = kUnrecognizedFormatString;
    }

    WriteOutput("");
    WriteOutput("File info:");
    WriteOutput("\tCompression format: " + compression_type_name);

    if (api_agnostic_stats_.trim_start_frame == 0)
    {
        // Not a trimmed file.
        WriteOutput(std::string("\tTotal frames: ") + std::to_string(api_agnostic_stats_.frame_count));
    }
    else
    {
        if (api_agnostic_stats_.blank_frame_count)
        {
            WriteOutput(std::string("\tBlank frames: ") + std::to_string(api_agnostic_stats_.blank_frame_count));
            WriteOutput(std::string("\tCaptured frames: ") + std::to_string(api_agnostic_stats_.frame_count));
        }

        // Print out the total frames and range based on the API (since we have 2 different ways of showing it)
        if (use_single_line_frame_output_)
        {
            WriteOutput(std::string("\tTotal frames: ") + std::to_string(api_agnostic_stats_.frame_count) +
                        " (trimmed frame range " + std::to_string(api_agnostic_stats_.trim_start_frame) + "-" +
                        std::to_string(api_agnostic_stats_.trim_start_frame + api_agnostic_stats_.frame_count - 1));
        }
        else
        {

            uint32_t total_count = api_agnostic_stats_.blank_frame_count + api_agnostic_stats_.frame_count;
            if (file_processor_.GetCurrentFrameNumber() == 0)
            {
                total_count = 0;
            }

            WriteOutput(std::string("\tTotal frames: ") + std::to_string(total_count));

            WriteOutput(std::string("\tApplication frame range: ") +
                        std::to_string(api_agnostic_stats_.trim_start_frame) + "-" +
                        std::to_string(api_agnostic_stats_.trim_start_frame + api_agnostic_stats_.frame_count - 1));
        }
    }
}

nlohmann::json InfoGenerator::GetApiAgnosticStatsJson()
{
    // Compression type.
    std::string compression_type_name = gfxrecon::format::GetCompressionTypeName(api_agnostic_stats_.compression_type);
    if (compression_type_name.empty())
    {
        compression_type_name = kUnrecognizedFormatString;
    }

    uint32_t total_count = api_agnostic_stats_.blank_frame_count + api_agnostic_stats_.frame_count;
    uint32_t end_frame   = 0;
    if (file_processor_.GetCurrentFrameNumber() == 0)
    {
        total_count = 0;
    }
    else
    {
        end_frame = api_agnostic_stats_.trim_start_frame + api_agnostic_stats_.frame_count - 1;
    }

    return { { "compression",
               {
                   { "format", compression_type_name },
               } },
             { "frames",
               {
                   { "blank-count", api_agnostic_stats_.blank_frame_count },
                   { "actual-count", api_agnostic_stats_.frame_count },
                   { "total-count", total_count },
                   { "start-frame", api_agnostic_stats_.trim_start_frame },
                   { "end-frame", end_frame },
               } } };
}

void InfoGenerator::PrintGfxrOperationsText()
{
    // If the capture file had target annotations, display them in an info block
    if (!annotation_recorder_.operation_annotations_.empty())
    {
        static const std::map<std::string, std::string> kTargetAnnotations = {
            { gfxrecon::format::kOperationAnnotationGfxreconstructVersion, "GFXR version" },
            { gfxrecon::format::kOperationAnnotationTimestamp, "Capture timestamp" },
            { gfxrecon::format::kOperationAnnotationVulkanVersion, "Vulkan version" },
            { gfxrecon::format::kOperationAnnotationCaptureParameters, "Non-default capture options" },
        };

        WriteOutput("");
        WriteOutput("Annotations:");
        for (const auto& annotation_info : annotation_recorder_.operation_annotations_)
        {
            nlohmann::json json_obj = nlohmann::json::parse(annotation_info);
            for (const auto& item : json_obj.items())
            {
                const auto target = kTargetAnnotations.find(item.key());
                if (target != kTargetAnnotations.end())
                {
                    if (item.value().is_object())
                    {
                        // Convert the JSON annotation object into multiline output.
                        // Unfortunately, this puts the last brace on a new line at column 0.
                        // So insert a tab right in  front of it.
                        std::string out = "\n\t" + item.value().dump(kDefaultIndent);
                        out.insert(out.size() - 1, 1, '\t');
                        WriteOutput(std::string("\t") + target->second + ": " + out);
                    }
                    else
                    {
                        WriteOutput(std::string("\t") + target->second + ": " + item.value().get<std::string>());
                    }
                }
            }
        }
    }
}

nlohmann::json InfoGenerator::GetGfxrOperationsJson()
{
    nlohmann::json annotations_json = nlohmann::json::array();
    for (const auto& annotation_info : annotation_recorder_.operation_annotations_)
    {
        annotations_json.push_back(nlohmann::json::parse(annotation_info));
    }
    return annotations_json;
}

void InfoGenerator::WriteOutput(const std::string& message)
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

int main(int argc, const char** argv)
{
    InfoGenerator info_generator;

    if (info_generator.ProcessCommandLine(argc, argv) && info_generator.ProcessCapture() &&
        info_generator.OutputContent())
    {
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}
