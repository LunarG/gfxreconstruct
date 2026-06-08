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

#include "decode/decode_api_detection.h"
#include "decode/info_decoder.h"
#include "decode/info_consumer.h"
#include "decode/file_processor.h"
#include "decode/stat_consumer.h"
#include "decode/stat_consumer_base.h"
#include "decode/stat_decoder_base.h"
#include "format/format.h"
#include "format/format_util.h"

#if defined(D3D12_SUPPORT)
#include "graphics/dx12_util.h"
#endif

#include "util/argument_parser.h"
#include "util/feature_module_registry.h"
#include "util/logging.h"
#include "util/platform.h"
#include "util/strings.h"
#include "util/to_string.h"

#include "info_feature.h"
#include "tool_settings.h"

#include <cassert>
#include <cstdarg>
#include <cstdlib>
#include <limits>
#include <set>
#include <string>
#include <unordered_map>
#include <iostream>

#include <nlohmann/json.hpp>

const char kExeInfoOnlyOption[]    = "--exe-info-only";
const char kEnvVarsOnlyOption[]    = "--env-vars-only";
const char kFileFormatOnlyOption[] = "--file-format-only";
const char kVerboseOption[]        = "--verbose";
const char kOutputFileArgument[]   = "--output";

const char kOptions[]   = "-h|--help,--version,--no-debug-popup,--exe-info-only,--env-vars-only,--file-format-only,--"
                          "enum-gpu-indices,--verbose";
const char kArguments[] = "--output,--log-level";

#if defined(D3D12_SUPPORT)
const char kEnumGpuIndices[] = "--enum-gpu-indices";
#endif

const char kUnrecognizedFormatString[] = "<unrecognized-format>";

const int kDefaultIndent = 12;

static std::vector<std::unique_ptr<gfxrecon::info::InfoFeature>> g_info_features;

// Global variables defining where we should output results to
static std::ofstream g_output_file;

// Write the output where it needs to go
void WriteOutput(const char* format_string, ...)
{
    va_list args_list;
    va_start(args_list, format_string);

    try
    {
        // We have to make a copy because the first call to std::vsnprintf adjusts
        // the argument list.
        va_list args_copy;
        va_copy(args_copy, args_list);
        // Determine how much space is needed in the new string
        const int32_t sz = std::vsnprintf(nullptr, 0, format_string, args_list) + 1;
        va_end(args_list);

        // Create a result string and clear it with spaces and then copy the formatted
        // string results into it.
        std::string result_string(sz, ' ');
        std::vsnprintf(&result_string.front(), sz, format_string, args_copy);
        va_end(args_copy);
        if (g_output_file.is_open())
        {
            g_output_file << result_string.c_str() << std::endl;
        }
        else
        {
            GFXRECON_WRITE_CONSOLE(result_string.c_str());
        }
    }
    catch (...)
    {
        va_end(args_list);
    }
}

struct ApiAgnosticStats
{
    gfxrecon::format::CompressionType compression_type;
    uint32_t                          trim_start_frame{ 0 };
    uint32_t                          frame_count{ 0 };
    gfxrecon::decode::BlockIOError    error_state;
    uint32_t                          blank_frame_count{ 0 };
    bool                              uses_frame_markers{ false };
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

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    WriteOutput("\n%s - Print statistics for a GFXReconstruct capture file.\n", app_name.c_str());
    WriteOutput("Usage:");
    WriteOutput("  %s [-h | --help] [--version] [--exe-info-only] [--verbose] [--output <file>] <capture-file>\n",
                app_name.c_str());
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
    WriteOutput("  --log-level <level>\tSpecify highest level message to log. Options are:");
    WriteOutput("                  \t\tdebug, info, warning, error, and fatal. Default is info.");

#if defined(D3D12_SUPPORT)
    WriteOutput("  %s\tPrint GPU indices and exit", kEnumGpuIndices);
#endif
}

void GatherApiAgnosticStats(ApiAgnosticStats&                api_agnostic_stats,
                            gfxrecon::decode::FileProcessor& file_processor,
                            gfxrecon::decode::StatConsumer&  stat_consumer)
{
    api_agnostic_stats.error_state = file_processor.GetErrorState();

    // File options.
    gfxrecon::format::CompressionType compression_type = gfxrecon::format::CompressionType::kNone;

    auto file_options = file_processor.GetFileOptions();
    for (const auto& option : file_options)
    {
        if (option.key == gfxrecon::format::FileOption::kCompressionType)
        {
            compression_type = static_cast<gfxrecon::format::CompressionType>(option.value);
        }
    }
    api_agnostic_stats.compression_type = compression_type;
    api_agnostic_stats.trim_start_frame = stat_consumer.GetTrimmedStartFrame();
    GFXRECON_NARROWING_ASSIGN(api_agnostic_stats.frame_count, file_processor.GetCurrentFrameNumber());
    api_agnostic_stats.uses_frame_markers = file_processor.UsesFrameMarkers();
}

nlohmann::json GetGfxrOperationsJson(const AnnotationRecorder& annotation_recorder)
{
    nlohmann::json annotations_json = nlohmann::json::array();
    for (const auto& annotation_info : annotation_recorder.operation_annotations_)
    {
        annotations_json.push_back(nlohmann::json::parse(annotation_info));
    }
    return annotations_json;
}

void PrintAnnotationsText(const AnnotationRecorder& annotation_recorder)
{
    // If the capture file had target annotations, display them in an info block
    if (!annotation_recorder.operation_annotations_.empty())
    {
        static const std::map<std::string, std::string> kTargetAnnotations = {
            { gfxrecon::format::kOperationAnnotationGfxreconstructVersion, "GFXR version" },
            { gfxrecon::format::kOperationAnnotationTimestamp, "Capture timestamp" },
            { gfxrecon::format::kOperationAnnotationVulkanVersion, "Vulkan version" },
            { gfxrecon::format::kOperationAnnotationCaptureParameters, "Non-default capture options" },
        };

        WriteOutput("");
        WriteOutput("Annotations:");
        for (const auto& annotation_info : annotation_recorder.operation_annotations_)
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
                        WriteOutput("\t%s: %s", target->second.c_str(), out.c_str());
                    }
                    else
                    {
                        WriteOutput("\t%s: %s", target->second.c_str(), item.value().get<std::string>().c_str());
                    }
                }
            }
        }
    }
}

inline std::string GetFrameMarkerString(bool uses_frame_markers, bool needs_update)
{
    return uses_frame_markers ? (needs_update ? "explicit (unsupported)" : "explicit") : "implicit";
}

nlohmann::json GetFileFormatInfoJson(const gfxrecon::decode::FileProcessor& file_processor)
{
    FileFormatInfo file_format_info(file_processor);

    std::string file_format_version =
        std::to_string(file_format_info.major_version) + "." + std::to_string(file_format_info.minor_version);
    std::string frame_marker_string =
        GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate());

    return {
        { "file-version", file_format_version },
        { "frame-delimiters", frame_marker_string },
    };
}

void PrintFileFormatInfoText(const gfxrecon::decode::FileProcessor& file_processor)
{
    FileFormatInfo file_format_info(file_processor);
    WriteOutput("\tFile format version: %u.%u", file_format_info.major_version, file_format_info.minor_version);
    WriteOutput("\tFrame delimiters: %s",
                GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate()).c_str());
}

nlohmann::json GetExeInfoJson(const gfxrecon::decode::InfoConsumer& info_consumer)
{
    auto        exe_version  = info_consumer.GetAppVersion();
    std::string file_desc    = info_consumer.GetFileDescription();
    std::string product_name = info_consumer.GetProductName();
    std::string version      = std::to_string(exe_version[0]) + "." + std::to_string(exe_version[1]) + "." +
                          std::to_string(exe_version[2]) + "." + std::to_string(exe_version[3]);

    return {
        { "name", info_consumer.GetAppExeName() },
        { "version", version },
        { "company", info_consumer.GetCompanyName() },
        { "product", product_name },
        { "file-description", file_desc },
    };
}

void PrintExeInfoText(const gfxrecon::decode::InfoConsumer& info_consumer)
{
    auto        exe_version  = info_consumer.GetAppVersion();
    std::string file_desc    = info_consumer.GetFileDescription();
    std::string product_name = info_consumer.GetProductName();

    WriteOutput("Exe info:");
    WriteOutput("\tApplication exe name: %s", info_consumer.GetAppExeName().c_str());

    WriteOutput("\tApplication version: %d.%d.%d.%d", exe_version[0], exe_version[1], exe_version[2], exe_version[3]);
    WriteOutput("\tApplication Company name: %s", info_consumer.GetCompanyName());

    // we are combining file description and product name and presenting both only if they are not same
    std::string app_data = file_desc;
    if (strcmp(product_name.c_str(), "N/A") != 0)
    {
        if (strcmp(product_name.c_str(), file_desc.c_str()) != 0)
        {
            app_data += " // ";
            app_data += info_consumer.GetProductName();
        }
    }
    WriteOutput("\tProduct name: %s", app_data.c_str());
}

nlohmann::json GetEnvironmentVariableInfoJson(const std::vector<std::string>& environment_variables)
{
    nlohmann::json environment;

    static const std::string delimiter = "=";
    for (const auto& var : environment_variables)
    {
        const auto& delimiter_pos = var.find(delimiter);
        std::string key           = var.substr(0, delimiter_pos);
        std::string value         = var.substr(delimiter_pos + 1);
        environment[key]          = value;
    }

    return environment;
}

void PrintEnvironmentVariableInfoText(gfxrecon::decode::InfoConsumer& info_consumer)
{
    WriteOutput("Environment variables:");
    for (const auto& var : info_consumer.GetEnvironmentVariables())
    {
        WriteOutput("\t%s", var.c_str());
    }
}

void PrintDetectedApiInfoText(uint32_t detected_api_count)
{
    if (detected_api_count == 0)
    {
        WriteOutput("Unable to detect capture file API(s). Writing all stats.");
    }
}

nlohmann::json GetApiAgnosticStatsJson(const gfxrecon::decode::FileProcessor& file_processor,
                                       const ApiAgnosticStats&                api_agnostic_stats)
{
    // Compression type.
    std::string compression_type_name = gfxrecon::format::GetCompressionTypeName(api_agnostic_stats.compression_type);
    if (compression_type_name.empty())
    {
        compression_type_name = kUnrecognizedFormatString;
    }

    uint32_t total_count = api_agnostic_stats.blank_frame_count + api_agnostic_stats.frame_count;
    if (file_processor.GetCurrentFrameNumber() == 0)
    {
        total_count = 0;
    }

    return { { "compression",
               {
                   { "format", compression_type_name },
               } },
             { "frames",
               {
                   { "blank-count", api_agnostic_stats.blank_frame_count },
                   { "actual-count", api_agnostic_stats.frame_count },
                   { "total-count", total_count },
                   { "start-frame", api_agnostic_stats.trim_start_frame },
                   { "end-frame", api_agnostic_stats.trim_start_frame + api_agnostic_stats.frame_count - 1 },
               } } };
}

void PrintApiAgnosticStatsText(const gfxrecon::decode::FileProcessor& file_processor,
                               const ApiAgnosticStats&                api_agnostic_stats,
                               bool                                   vulkan_found)
{
    // Compression type.
    std::string compression_type_name = gfxrecon::format::GetCompressionTypeName(api_agnostic_stats.compression_type);
    if (compression_type_name.empty())
    {
        compression_type_name = kUnrecognizedFormatString;
    }

    WriteOutput("");
    WriteOutput("File info:");
    WriteOutput("\tCompression format: %s", compression_type_name.c_str());

    if (api_agnostic_stats.trim_start_frame == 0)
    {
        // Not a trimmed file.
        WriteOutput("\tTotal frames: %u", api_agnostic_stats.frame_count);
    }
    else
    {
        if (api_agnostic_stats.blank_frame_count)
        {
            WriteOutput("\tBlank frames: %u", api_agnostic_stats.blank_frame_count);
            WriteOutput("\tCaptured frames: %u", api_agnostic_stats.frame_count);
        }

        uint32_t total_count = api_agnostic_stats.blank_frame_count + api_agnostic_stats.frame_count;
        if (file_processor.GetCurrentFrameNumber() == 0)
        {
            total_count = 0;
        }

        if (vulkan_found)
        {
            WriteOutput("\tTotal frames: %u (trimmed frame range %u-%u)",
                        total_count,
                        api_agnostic_stats.trim_start_frame,
                        api_agnostic_stats.trim_start_frame + api_agnostic_stats.frame_count - 1);
        }
        else
        {
            WriteOutput("\tTotal frames: %u", total_count);
            WriteOutput("\tApplication frame range: %u-%u",
                        api_agnostic_stats.trim_start_frame,
                        api_agnostic_stats.trim_start_frame + api_agnostic_stats.frame_count - 1);
        }
    }
}

// A short pass to get exe info. Only processes the first blocks of a capture file.
bool GatherAndPrintExeInfo(const std::string& input_filename)
{
    gfxrecon::decode::InfoConsumer  info_consumer(true);
    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::InfoDecoder info_decoder;
        info_decoder.AddConsumer(&info_consumer);
        file_processor.AddDecoder(&info_decoder);
        if (file_processor.ProcessNextFrame() && !file_processor.UsesFrameMarkers())
        {
            file_processor.ProcessNextFrame();
        }
        if (file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone)
        {
            PrintExeInfoText(info_consumer);
        }
    }

    return file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone;
}

// A short pass to get file format info. Only processes the first two frames of a capture file.
bool GatherAndPrintFileFormatInfo(const std::string& input_filename)
{
    const gfxrecon::decode::InfoConsumer::NoMaxBlockTag no_max_tag;
    gfxrecon::decode::InfoConsumer                      info_consumer(no_max_tag);
    gfxrecon::decode::FileProcessor                     file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::InfoDecoder info_decoder;
        info_decoder.AddConsumer(&info_consumer);
        file_processor.AddDecoder(&info_decoder);
        if (file_processor.ProcessNextFrame() && !file_processor.UsesFrameMarkers())
        {
            file_processor.ProcessNextFrame();
        }
        if (file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone)
        {
            WriteOutput("File format info:");
            PrintFileFormatInfoText(file_processor);
        }
    }

    return file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone;
}

bool GatherAndPrintEnvVars(const std::string& input_filename)
{
    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::InfoConsumer info_consumer;
        gfxrecon::decode::InfoDecoder  info_decoder;
        info_decoder.AddConsumer(&info_consumer);
        file_processor.AddDecoder(&info_decoder);
        if (file_processor.ProcessNextFrame() && !file_processor.UsesFrameMarkers())
        {
            file_processor.ProcessNextFrame();
        }
        if (file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone)
        {
            PrintEnvironmentVariableInfoText(info_consumer);
        }
        else
        {
            GFXRECON_LOG_ERROR("Encountered error while reading capture. Unable to report environment variables.");
        }
    }

    return file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone;
}

bool GatherAndPrintAllInfo(const std::string& input_filename, bool output_json)
{
    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::StatDecoderBase stat_decoder;
        gfxrecon::decode::StatConsumer    stat_consumer;
        stat_decoder.AddConsumer(&stat_consumer);
        file_processor.AddDecoder(&stat_decoder);

        gfxrecon::decode::InfoConsumer info_consumer;
        gfxrecon::decode::InfoDecoder  info_decoder;
        info_decoder.AddConsumer(&info_consumer);
        file_processor.AddDecoder(&info_decoder);

        AnnotationRecorder annotation_recorder;
        file_processor.SetAnnotationProcessor(&annotation_recorder);

        for (auto& feature : g_info_features)
        {
            feature->RegisterDecodeComponents(file_processor, info_consumer);
        }

        file_processor.ProcessAllFrames();
        if (file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone)
        {
            uint32_t                 blank_frame_count    = 0;
            bool                     force_all_api_output = false;
            bool                     api_found            = false;
            std::vector<std::string> detected_apis;

            // TODO: This is a temporary workaround until we unify the output
            bool vulkan_found = false;

            ApiAgnosticStats api_agnostic_stats = {};
            GatherApiAgnosticStats(api_agnostic_stats, file_processor, stat_consumer);

            for (auto& feature : g_info_features)
            {
                blank_frame_count += feature->GetBlankFrameCount();
                uint32_t api_start_frame = feature->GetFrameStart();
                if (api_agnostic_stats.trim_start_frame < api_start_frame)
                {
                    api_agnostic_stats.trim_start_frame = api_start_frame;
                }

                if (feature->WasDetected())
                {
                    detected_apis.push_back(feature->Label());
                    api_found = true;

                    if (!strcmp("Vulkan", feature->Label().c_str()))
                    {
                        vulkan_found = true;
                    }
                }
            }

            if (api_agnostic_stats.blank_frame_count < blank_frame_count)
            {
                api_agnostic_stats.blank_frame_count = blank_frame_count;
            }

            // If no API data found, force each API to try to spit out info
            if (!api_found)
            {
                GFXRECON_LOG_WARNING("Unable to detect capture file API(s). Writing all stats.");
                force_all_api_output = true;
            }

            if (output_json)
            {
                nlohmann::json json_content;

                json_content["exe"]               = GetExeInfoJson(info_consumer);
                const auto& environment_variables = info_consumer.GetEnvironmentVariables();
                if (!environment_variables.empty())
                {
                    json_content["environment"] = GetEnvironmentVariableInfoJson(environment_variables);
                }
                json_content["file-info"] = GetFileFormatInfoJson(file_processor);
                if (api_agnostic_stats.error_state == gfxrecon::decode::BlockIOError::kErrorNone)
                {
                    json_content["detected-apis"] = detected_apis;
                    json_content["general-info"]  = GetApiAgnosticStatsJson(file_processor, api_agnostic_stats);

                    for (auto& feature : g_info_features)
                    {
                        if ((feature->WasDetected() || force_all_api_output))
                        {
                            std::string api_lower = feature->Label();
                            std::transform(api_lower.begin(), api_lower.end(), api_lower.begin(), [](unsigned char c) {
                                return std::tolower(c);
                            });

                            json_content[api_lower] = feature->GenerateJson();
                        }
                    }

                    if (!annotation_recorder.operation_annotations_.empty())
                    {
                        json_content["gfxr-operations"] = GetGfxrOperationsJson(annotation_recorder);
                    }
                }

                WriteOutput(json_content.dump(4, ' ', true).c_str());
            }
            else
            {
                PrintDetectedApiInfoText(detected_apis.size());
                PrintExeInfoText(info_consumer);
                if (api_agnostic_stats.error_state == gfxrecon::decode::BlockIOError::kErrorNone)
                {
                    PrintApiAgnosticStatsText(file_processor, api_agnostic_stats, vulkan_found);

                    for (auto& feature : g_info_features)
                    {
                        if ((feature->WasDetected() || force_all_api_output))
                        {
                            WriteOutput(feature->GenerateText().c_str());
                        }
                    }

                    PrintAnnotationsText(annotation_recorder);
                }
                else if (api_agnostic_stats.error_state != gfxrecon::decode::BlockIOError::kErrorNone)
                {
                    WriteOutput("A failure has occurred during file processing");
                    gfxrecon::util::Log::Release();
                    exit(-1);
                }
                else
                {
                    WriteOutput("File did not contain any frames");
                }
            }
        }
        else
        {
            WriteOutput("Encountered error while reading capture. Stats unavailable.");
        }
    }

    return file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone;
}

#if defined(D3D12_SUPPORT)

static std::string GetEnumGpuIndicesText()
{
    gfxrecon::graphics::dx12::IDXGIFactory1ComPtr factory1   = nullptr;
    std::string                                   return_val = "";

    HRESULT result = CreateDXGIFactory1(IID_PPV_ARGS(&factory1));

    if (SUCCEEDED(result))
    {
        gfxrecon::graphics::dx12::ActiveAdapterMap adapters{};
        gfxrecon::graphics::dx12::TrackAdapters(
            result, reinterpret_cast<void**>(&factory1.GetInterfacePtr()), adapters);

        return_val = "GPU index\tGPU name\tSubSys ID\n";
        for (size_t index = 0; index < adapters.size(); ++index)
        {
            for (auto adapter : adapters)
            {
                if (index == adapter.second.adapter_idx)
                {
                    std::string replay_adapter_str =
                        gfxrecon::util::WCharArrayToString(adapter.second.internal_desc.Description);

                    return_val +=
                        gfxrecon::util::to_hex_fixed_width<uint32_t>(adapter.second.adapter_idx, false, false) + "\t" +
                        replay_adapter_str + "\t" + std::to_string(adapter.second.internal_desc.SubSysId) + "\n";
                    break;
                }
            }
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to enumerate GPU indices");
    }
    return return_val;
}

#endif // D3D12_SUPPORT

int main(int argc, const char** argv)
{
    gfxrecon::util::Log::Init();

    // Save the app name first
    const std::string app_name = std::filesystem::path{ argv[0] }.filename().string();

    // Query the module registry for registered modules, and
    // call each generator here and put the unique_ptr into our
    // internal unique_ptr vector.
    for (const auto& registered_creator :
         gfxrecon::util::FeatureModuleRegistry<gfxrecon::info::InfoFeature>::GetSingleton()
             .GetRegisteredFeatureCreators())
    {
        g_info_features.push_back(std::move(registered_creator()));
    }

    // Add any API-specific command-line arguments/options
    std::string arguments = kArguments;
    std::string options   = kOptions;

#if defined(D3D12_SUPPORT)
    options += " ";
    options += kEnumGpuIndices;
#endif

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, options, arguments);

    if (CheckOptionPrintUsage(app_name.c_str(), arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsOptionSet(kVersionOption))
    {
        GFXRECON_WRITE_CONSOLE("%s version info:", app_name.c_str());
        GFXRECON_WRITE_CONSOLE("  GFXReconstruct Version %s", GetProjectVersionString());
        for (auto& feature : g_info_features)
        {
            GFXRECON_WRITE_CONSOLE(feature->CompiledHeaderVersionString().c_str());
        }

        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(app_name.c_str());
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else
    {
#if defined(WIN32) && defined(_DEBUG)
        if (arg_parser.IsOptionSet(kNoDebugPopup))
        {
            _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
        }
#endif
    }

    // Update logging with values retrieved from command line arguments
    gfxrecon::util::Log::Settings log_settings;
    GetLogSettings(arg_parser, log_settings);
    gfxrecon::util::Log::UpdateWithSettings(log_settings);

    const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
    std::string                     input_filename       = positional_arguments[0];
    bool                            success              = false;

    if (arg_parser.IsArgumentSet(kOutputFileArgument))
    {
        std::string output_filename = arg_parser.GetArgumentValue(kOutputFileArgument);
        g_output_file.open(output_filename);
    }

    if (arg_parser.IsOptionSet(kExeInfoOnlyOption))
    {
        success = GatherAndPrintExeInfo(input_filename);
    }
    else if (arg_parser.IsOptionSet(kEnvVarsOnlyOption))
    {
        success = GatherAndPrintEnvVars(input_filename);
    }
    else if (arg_parser.IsOptionSet(kFileFormatOnlyOption))
    {
        success = GatherAndPrintFileFormatInfo(input_filename);
    }
#if defined(D3D12_SUPPORT)
    else if (arg_parser.IsOptionSet(kEnumGpuIndices))
    {
        WriteOutput(GetEnumGpuIndicesText().c_str());
    }
#endif // D3D12_SUPPORT
    else
    {
        success = GatherAndPrintAllInfo(input_filename, arg_parser.IsOptionSet(kVerboseOption));
    }

    gfxrecon::util::Log::Release();
    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
