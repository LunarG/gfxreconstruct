/*
** Copyright (c) 2020-2024 LunarG, Inc.
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
#include "decode/stat_consumer.h"
#include "decode/stat_consumer_base.h"
#include "decode/stat_decoder_base.h"
#include "decode/file_processor.h"
#include "format/format.h"
#include "format/format_util.h"

#if ENABLE_OPENXR_SUPPORT
#include "decode/openxr_detection_consumer.h"
#include "decode/openxr_stats_consumer.h"
#include "generated/generated_openxr_decoder.h"
#endif

#include "decode/info_decoder.h"
#include "decode/info_consumer.h"
#include "decode/vulkan_detection_consumer.h"
#include "decode/vulkan_stats_consumer.h"
#include "generated/generated_vulkan_decoder.h"

#if defined(D3D12_SUPPORT)
#include "decode/dx12_stats_consumer.h"
#include "generated/generated_dx12_decoder.h"
#include "decode/dx12_detection_consumer.h"
#include "graphics/dx12_util.h"
#endif

#include "util/argument_parser.h"
#include "util/strings.h"
#include "util/logging.h"
#include "util/to_string.h"
#include "util/platform.h"

#if ENABLE_OPENXR_SUPPORT
#include "openxr/openxr.h"
#endif
#include "vulkan/vulkan.h"

#include <cassert>
#include <cstdarg>
#include <cstdlib>
#include <limits>
#include <set>
#include <string>
#include <unordered_map>

#include <nlohmann/json.hpp>

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

const char kUnrecognizedFormatString[] = "<unrecognized-format>";

const int kDefaultIndent = 12;

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

std::string ParseJsonForAnnotationData(const nlohmann::json& json_obj, const std::string& key)
{
    std::string out                    = "";
    auto        search_result_iterator = json_obj.find(key);
    if (search_result_iterator != json_obj.end())
    {
        const nlohmann::json& value = *search_result_iterator;
        if (value.is_object())
        {
            // Write the value of this object
            out += value.dump();
        }
        else
        {
            out = value;
        }
    }

    return out;
}

class AnnotationRecorder : public gfxrecon::decode::AnnotationHandler
{
  public:
    struct AnnotationInfo
    {
        std::string desc;
        std::string key;
        std::string data;
    };

    AnnotationRecorder()
    {
        // Define all possible Annotation fields and let them record the info as encountered
        AnnotationRecorder::AnnotationInfo expected_annotations[] = {
            { "GFXR version", gfxrecon::format::kOperationAnnotationGfxreconstructVersion, "" },
            { "Capture timestamp", gfxrecon::format::kOperationAnnotationTimestamp, "" },
            { "Vulkan version", gfxrecon::format::kOperationAnnotationVulkanVersion, "" },
            { "Non-default capture options", gfxrecon::format::kOperationAnnotationCaptureParameters, "" }
        };
        expected_annotations_.assign(expected_annotations, expected_annotations + 5);
    }

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
                    // Loop through all possible annotations and see if their key is found in
                    // the JSON content of this annotation
                    for (auto& expected_annotation : expected_annotations_)
                    {
                        // If a target annotation, cache it
                        std::string annotation = ParseJsonForAnnotationData(json_obj, expected_annotation.key);
                        if (!annotation.empty())
                        {
                            expected_annotation.data = annotation;
                            num_valid_annotations_++;
                        }
                    }
                }
            }
        }
    }

    const uint32_t                     GetNumValidAnnotations() const { return num_valid_annotations_; }
    const std::vector<AnnotationInfo>& GetAnnotationData() const { return expected_annotations_; }

  private:
    uint32_t                    num_valid_annotations_{ 0 };
    std::vector<AnnotationInfo> expected_annotations_;
};

struct ApiAgnosticStats
{
    gfxrecon::format::CompressionType compression_type;
    uint32_t                          trim_start_frame;
    uint32_t                          frame_count;
    gfxrecon::decode::BlockIOError    error_state;
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

std::string AdapterTypeToString(gfxrecon::format::AdapterType type)
{
    switch (type)
    {
        case gfxrecon::format::AdapterType::kUnknownAdapter:
            return "Unknown type (DXGI 1.0)";
        case gfxrecon::format::AdapterType::kSoftwareAdapter:
            return "Software";
        case gfxrecon::format::AdapterType::kHardwareAdapter:
            return "Hardware";
        default:
            return "Unknown";
    }
}

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
}

static bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

static bool CheckOptionPrintVersion(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kVersionOption))
    {
        std::string app_name     = exe_name;
        size_t      dir_location = app_name.find_last_of("/\\");

        if (dir_location >= 0)
        {
            app_name.replace(0, dir_location + 1, "");
        }

        WriteOutput("%s version info:", app_name.c_str());
        WriteOutput("  GFXReconstruct Version %s", GetProjectVersionString());
        WriteOutput("  Vulkan Header Version %u.%u.%u",
                    VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                    VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                    VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

        return true;
    }

    return false;
}

static std::string GetVkVersionString(uint32_t api_version)
{
    uint32_t major = VK_API_VERSION_MAJOR(api_version);
    uint32_t minor = VK_API_VERSION_MINOR(api_version);
    uint32_t patch = VK_API_VERSION_PATCH(api_version);

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

static std::string GetXrVersionString(uint32_t api_version)
{
    uint32_t major = XR_VERSION_MAJOR(api_version);
    uint32_t minor = XR_VERSION_MINOR(api_version);
    uint32_t patch = XR_VERSION_PATCH(api_version);

    return std::to_string(major) + "." + std::to_string(minor) + "." + std::to_string(patch);
}

void GatherApiAgnosticStats(ApiAgnosticStats&                api_agnostic_stats,
                            gfxrecon::decode::FileProcessor& file_processor,
                            gfxrecon::decode::StatConsumer&  stat_consumer,
                            uint32_t                         blank_frame_count)
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
    api_agnostic_stats.compression_type   = compression_type;
    api_agnostic_stats.trim_start_frame   = stat_consumer.GetTrimmedStartFrame();
    api_agnostic_stats.frame_count        = file_processor.GetCurrentFrameNumber();
    api_agnostic_stats.uses_frame_markers = file_processor.UsesFrameMarkers();
    api_agnostic_stats.blank_frame_count  = blank_frame_count;
}

void PrintAnnotationsJson(const std::vector<AnnotationRecorder::AnnotationInfo> all_annotation_infos,
                          nlohmann::json&                                       json_output)
{
    // If the capture file had target annotations, display them in an info block
    if (!all_annotation_infos.empty())
    {
        json_output["annotations"] = nlohmann::json::array();
        for (const auto& annotation_info : all_annotation_infos)
        {
            if (annotation_info.data.size() > 0)
            {
                nlohmann::json annotation;
                annotation["description"] = annotation_info.desc;
                annotation["data"]        = annotation_info.data;
                json_output["annotations"].push_back(annotation);
            }
        }
    }
}

void PrintAnnotationsText(const std::vector<AnnotationRecorder::AnnotationInfo> all_annotation_infos)
{
    // If the capture file had target annotations, display them in an info block
    if (!all_annotation_infos.empty())
    {
        WriteOutput("");
        WriteOutput("Annotations:");

        for (const auto& annotation_info : all_annotation_infos)
        {
            if (annotation_info.data.size() > 0)
            {
                WriteOutput("\t%s: %s", annotation_info.desc.c_str(), annotation_info.data.c_str());
            }
        }
    }
}

inline std::string GetFrameMarkerString(bool uses_frame_markers, bool needs_update)
{
    return uses_frame_markers ? (needs_update ? "explicit (unsupported)" : "explicit") : "implicit";
}

void PrintFileFormatInfoJson(const gfxrecon::decode::FileProcessor& file_processor, nlohmann::json& json_output)
{
    FileFormatInfo file_format_info(file_processor);
    json_output["capture-file"]["file-version"] =
        std::to_string(file_format_info.major_version) + "." + std::to_string(file_format_info.minor_version);
    json_output["capture-file"]["frame-delimiters"] =
        GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate());
}

void PrintFileFormatInfoText(const gfxrecon::decode::FileProcessor& file_processor)
{
    FileFormatInfo file_format_info(file_processor);
    WriteOutput("\tFile format version: %u.%u", file_format_info.major_version, file_format_info.minor_version);
    WriteOutput("\tFrame delimiters: %s",
                GetFrameMarkerString(file_format_info.uses_frame_markers, file_format_info.NeedsUpdate()).c_str());
}

void PrintDriverInfoJson(const gfxrecon::decode::InfoConsumer& driver_info_consumer, nlohmann::json& json_output)
{
    if (gfxrecon::util::platform::StringLength(driver_info_consumer.GetDriverDesc()) > 0)
    {
        json_output["driver"] = driver_info_consumer.GetDriverDesc();
    }
    else
    {
        json_output["driver"] = "Not available";
    }
}

void PrintDriverInfoText(const gfxrecon::decode::InfoConsumer& driver_info_consumer)
{
    WriteOutput("");
    WriteOutput("Driver info:");
    if (gfxrecon::util::platform::StringLength(driver_info_consumer.GetDriverDesc()) > 0)
    {
        WriteOutput("\t%s", driver_info_consumer.GetDriverDesc());
    }
    else
    {
        WriteOutput("\tDriver info not available.");
        WriteOutput("");
    }
}

void PrintExeInfoJson(const gfxrecon::decode::InfoConsumer& info_consumer, nlohmann::json& json_output)
{
    auto        exe_version  = info_consumer.GetAppVersion();
    std::string file_desc    = info_consumer.GetFileDescription();
    std::string product_name = info_consumer.GetProductName();

    json_output["exe"]["name"]    = info_consumer.GetAppExeName();
    json_output["exe"]["version"] = std::to_string(exe_version[0]) + "." + std::to_string(exe_version[1]) + "." +
                                    std::to_string(exe_version[2]) + "." + std::to_string(exe_version[3]);
    json_output["exe"]["company"]          = info_consumer.GetCompanyName();
    json_output["exe"]["product"]          = product_name;
    json_output["exe"]["file-description"] = file_desc;
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

void PrintEnvironmentVariableInfoJson(gfxrecon::decode::InfoConsumer& info_consumer, nlohmann::json& json_output)
{
    std::string delimiter = "=";
    for (const std::string& var : info_consumer.GetEnvironmentVariables())
    {
        const auto& delimiter_pos       = var.find(delimiter);
        std::string key                 = var.substr(0, delimiter_pos);
        std::string value               = var.substr(delimiter_pos + 1);
        json_output["environment"][key] = value;
    }
}

void PrintEnvironmentVariableInfoText(gfxrecon::decode::InfoConsumer& info_consumer)
{
    WriteOutput("Environment variables:");
    for (const std::string& var : info_consumer.GetEnvironmentVariables())
    {
        WriteOutput("\t%s", var.c_str());
    }
}

void PrintDetectedApiInfoJson(bool vulkan_present, bool dx12_present, bool openxr_present, nlohmann::json& json_output)
{
    std::vector<std::string> apis;
    if (vulkan_present)
    {
        apis.push_back("Vulkan");
    }
    if (dx12_present)
    {
        apis.push_back("D3D12");
    }
    if (openxr_present)
    {
        apis.push_back("OpenXr");
    }
    if (apis.size() == 0)
    {
        apis.push_back("Unable to detect capture file APIs. Writing all stats.");
    }
    json_output["apis_detected"] = apis;
}

void PrintDetectedApiInfoText(bool vulkan_present, bool dx12_present, bool openxr_present)
{
    if (!vulkan_present && !dx12_present && !openxr_present)
    {
        WriteOutput("Unable to detect capture file API(s). Writing all stats.");
    }
}

void PrintApiAgnosticStatsJson(const ApiAgnosticStats& api_agnostic_stats,
                               bool                    vulkan_present,
                               bool                    dx12_present,
                               nlohmann::json&         json_output)
{
    // Compression type.
    std::string compression_type_name = gfxrecon::format::GetCompressionTypeName(api_agnostic_stats.compression_type);
    if (compression_type_name.empty())
    {
        compression_type_name = kUnrecognizedFormatString;
    }

    json_output["capture-file"]["compression"]["format"]  = compression_type_name;
    json_output["capture-file"]["frames"]["blank-count"]  = api_agnostic_stats.blank_frame_count;
    json_output["capture-file"]["frames"]["actual-count"] = api_agnostic_stats.frame_count;
    json_output["capture-file"]["frames"]["total-count"] =
        api_agnostic_stats.blank_frame_count + api_agnostic_stats.frame_count;
    json_output["capture-file"]["frames"]["start-frame"] = api_agnostic_stats.trim_start_frame;
    json_output["capture-file"]["frames"]["end-frame"] =
        api_agnostic_stats.trim_start_frame + api_agnostic_stats.frame_count - 1;
}

void PrintApiAgnosticStatsText(const ApiAgnosticStats& api_agnostic_stats, bool vulkan_present, bool dx12_present)
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

        // Print out the total frames and range based on the API (since we have 2 different ways of showing it)
        if (vulkan_present)
        {
            WriteOutput("\tTotal frames: %u (trimmed frame range %u-%u)",
                        api_agnostic_stats.frame_count,
                        api_agnostic_stats.trim_start_frame,
                        api_agnostic_stats.trim_start_frame + api_agnostic_stats.frame_count - 1);
        }
        else
        {
            WriteOutput("\tTotal frames: %u", api_agnostic_stats.blank_frame_count + api_agnostic_stats.frame_count);

            WriteOutput("\tApplication frame range: %u-%u",
                        api_agnostic_stats.trim_start_frame,
                        api_agnostic_stats.trim_start_frame + api_agnostic_stats.frame_count - 1);
        }
    }
}

void PrintVulkanDeviceMemoryStatsJson(uint64_t        alloc_count,
                                      uint64_t        min_alloc,
                                      uint64_t        max_alloc,
                                      uint32_t        gfx_pipelines,
                                      uint32_t        comp_pipelines,
                                      uint32_t        rt_pipelines,
                                      nlohmann::json& json_output)
{
    json_output["memory-alloc"]["count"]             = alloc_count;
    json_output["memory-alloc"]["min-size"]          = min_alloc;
    json_output["memory-alloc"]["max-size"]          = max_alloc;
    json_output["pipeline-info"]["graphics-count"]   = gfx_pipelines;
    json_output["pipeline-info"]["compute-count"]    = comp_pipelines;
    json_output["pipeline-info"]["raytracing-count"] = rt_pipelines;
}

void PrintVulkanDeviceMemoryStatsText(uint64_t alloc_count,
                                      uint64_t min_alloc,
                                      uint64_t max_alloc,
                                      uint32_t gfx_pipelines,
                                      uint32_t comp_pipelines,
                                      uint32_t rt_pipelines)
{
    WriteOutput("\nVulkan device memory allocation info:");
    WriteOutput("\tTotal allocations:   %" PRIu64, alloc_count);

    if (alloc_count > 0)
    {
        WriteOutput("\tMin allocation size: %" PRIu64, min_alloc);
        WriteOutput("\tMax allocation size: %" PRIu64, max_alloc);
    }

    WriteOutput("\nVulkan pipeline info:");
    WriteOutput("\tTotal graphics pipelines:   %" PRIu64, gfx_pipelines);
    WriteOutput("\tTotal compute pipelines:    %" PRIu64, comp_pipelines);
    WriteOutput("\tTotal raytracing pipelines: %" PRIu64, rt_pipelines);
}

void PrintVulkanDeviceType(VkPhysicalDeviceType device_type, std::string& device_string)
{
    switch (device_type)
    {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:
            device_string = "VK_PHYSICAL_DEVICE_TYPE_OTHER";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            device_string = "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            device_string = "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            device_string = "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            device_string = "VK_PHYSICAL_DEVICE_TYPE_CPU";
            break;
        default:
            device_string = " Unknown (";
            device_string += std::to_string(device_type);
            device_string += ")";
            break;
    }
}

void PrintVulkanStatsJson(const gfxrecon::decode::FileProcessor&       file_processor,
                          const gfxrecon::decode::VulkanStatsConsumer& vulkan_stats_consumer,
                          nlohmann::json&                              json_output)
{

    uint32_t inst_count    = vulkan_stats_consumer.GetInstanceCount();
    auto     instance_info = vulkan_stats_consumer.GetInstanceInfo();
    auto     pd_info       = vulkan_stats_consumer.GetPhysicalDeviceInfo();
    auto     dev_info      = vulkan_stats_consumer.GetDeviceInfo();

    json_output["vulkan"]["header-version"] = std::to_string(VK_API_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                              std::to_string(VK_API_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                                              std::to_string(VK_API_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
    json_output["vulkan"]["instances"] = nlohmann::json::array();

    uint32_t       inst_index = 0;
    nlohmann::json instance_array;
    for (auto& it : instance_info)
    {
        nlohmann::json instance_json;

        instance_json["application-info"]["application"]["name"]    = it.second.app_info.app_name;
        instance_json["application-info"]["application"]["version"] = it.second.app_info.app_version;
        instance_json["application-info"]["engine"]["name"]         = it.second.app_info.engine_name;
        instance_json["application-info"]["engine"]["version"]      = it.second.app_info.engine_version;
        instance_json["application-info"]["api-version"] = GetVkVersionString(it.second.app_info.api_version);

        if (it.second.enabled_extensions.size() > 0)
        {
            instance_json["extensions"] = nlohmann::json::array();
            for (uint32_t ext = 0; ext < it.second.enabled_extensions.size(); ++ext)
            {
                instance_json["extensions"].push_back(it.second.enabled_extensions[ext]);
            }
        }

        instance_json["application-info"]["resolutions"] = nlohmann::json::array();
        for (const auto& resolution : it.second.resolutions)
        {
            instance_json["application-info"]["resolutions"].push_back(std::to_string(resolution.width) + "x" +
                                                                       std::to_string(resolution.height));
        }

        instance_json["physical-devices"] = nlohmann::json::array();
        uint32_t pd_index                 = 0;
        for (auto pd : it.second.used_physical_devices)
        {
            nlohmann::json pd_json;
            auto           properties =
                vulkan_stats_consumer.GetDeviceProperties(reinterpret_cast<gfxrecon::format::HandleId>(pd));
            if (properties != nullptr)
            {
                pd_json["name"] = properties->deviceName;
                std::string device_type_string;
                PrintVulkanDeviceType(properties->deviceType, device_type_string);
                pd_json["type"]        = device_type_string;
                pd_json["api-version"] = GetVkVersionString(properties->apiVersion);

                pd_json["id"]             = properties->deviceID;
                pd_json["vendor"]         = properties->vendorID;
                pd_json["driver-version"] = properties->driverVersion;
                std::string uuid_string   = gfxrecon::util::uuid_to_string(VK_UUID_SIZE, properties->pipelineCacheUUID);
                pd_json["uuid"]           = uuid_string;

                pd_json["vulkan-devices"] = nlohmann::json::array();

                for (auto dev : pd_info[pd].devices)
                {
                    nlohmann::json dev_json;

                    if (dev_info[dev].enabled_extensions.size() > 0)
                    {
                        dev_json["extensions"] = nlohmann::json::array();
                        for (uint32_t ext = 0; ext < dev_info[dev].enabled_extensions.size(); ++ext)
                        {
                            dev_json["extensions"].push_back(dev_info[dev].enabled_extensions[ext]);
                        }
                    }

                    // For Verbose, we right out each devices alloc info.
                    PrintVulkanDeviceMemoryStatsJson(dev_info[dev].allocation_count,
                                                     dev_info[dev].min_allocation_size,
                                                     dev_info[dev].max_allocation_size,
                                                     dev_info[dev].graphics_pipelines,
                                                     dev_info[dev].compute_pipelines,
                                                     dev_info[dev].raytracing_pipelines,
                                                     dev_json);

                    pd_json["vulkan-devices"].push_back(dev_json);
                }

                instance_json["physical-devices"].push_back(pd_json);
            }
        }

        json_output["vulkan"]["instances"].push_back(instance_json);
    }

    if (file_processor.GetCurrentFrameNumber() == 0)
    {
        json_output["capture-file"]["frames"]["total-count"] = 0;
        WriteOutput("\nFile did not contain any frames");
    }
}

void PrintVulkanStatsText(const gfxrecon::decode::FileProcessor&       file_processor,
                          const gfxrecon::decode::VulkanStatsConsumer& vulkan_stats_consumer)
{

    uint32_t inst_count    = vulkan_stats_consumer.GetInstanceCount();
    auto     instance_info = vulkan_stats_consumer.GetInstanceInfo();
    auto     pd_info       = vulkan_stats_consumer.GetPhysicalDeviceInfo();
    auto     dev_info      = vulkan_stats_consumer.GetDeviceInfo();

    // Find the best instance (use the last one if nothing else looks good)
    VkInstance best_instance = vulkan_stats_consumer.GetLastCreatedInstance();
    uint32_t   max_allocs    = 0;
    uint32_t   max_pipelines = 0;
    for (auto& it : instance_info)
    {
        uint32_t used_allocs    = 0;
        uint32_t used_pipelines = 0;
        for (auto pd : it.second.used_physical_devices)
        {
            for (auto dev : pd_info[pd].devices)
            {
                used_allocs += dev_info[dev].allocation_count;
                used_pipelines += dev_info[dev].graphics_pipelines + dev_info[dev].compute_pipelines +
                                  dev_info[dev].raytracing_pipelines;
            }
        }
        if (used_allocs > max_allocs && used_pipelines > max_pipelines)
        {
            best_instance = it.second.instance_id;
            max_allocs    = used_allocs;
            max_pipelines = used_pipelines;
        }
    }
    auto& best_instance_info = instance_info[best_instance];

    WriteOutput("\nVulkan application info:");
    WriteOutput("\tApplication name:    %s", best_instance_info.app_info.app_name.c_str());
    WriteOutput("\tApplication version: %u", best_instance_info.app_info.app_version);
    WriteOutput("\tEngine name:         %s", best_instance_info.app_info.engine_name.c_str());
    WriteOutput("\tEngine version:      %u", best_instance_info.app_info.engine_version);
    WriteOutput("\tTarget API version:  %u (%s)",
                best_instance_info.app_info.api_version,
                GetVkVersionString(best_instance_info.app_info.api_version).c_str());
    std::string resolutions = "\tUsed resolutions:    ";
    for (const auto& resolution : best_instance_info.resolutions)
    {
        resolutions += std::to_string(resolution.width) + "x" + std::to_string(resolution.height) + " ";
    }
    WriteOutput(resolutions.c_str());

    WriteOutput("\nVulkan physical device info:");
    uint32_t pd_index = 0;
    for (auto pd : best_instance_info.used_physical_devices)
    {
        auto properties = vulkan_stats_consumer.GetDeviceProperties(reinterpret_cast<gfxrecon::format::HandleId>(pd));
        if (properties != nullptr)
        {
            WriteOutput("\tDevice name:         %s", properties->deviceName);
            WriteOutput("\tDevice ID:           0x%x", properties->deviceID);
            WriteOutput("\tVendor ID:           0x%x", properties->vendorID);
            WriteOutput("\tDriver version:      %u (0x%x)", properties->driverVersion, properties->driverVersion);
            WriteOutput("\tAPI version:         %u (%s)",
                        properties->apiVersion,
                        GetVkVersionString(properties->apiVersion).c_str());
        }
    }

    // For Verbose, we right out each devices alloc info.
    PrintVulkanDeviceMemoryStatsText(vulkan_stats_consumer.GetTotalAllocationCount(),
                                     vulkan_stats_consumer.GetTotalMinAllocationSize(),
                                     vulkan_stats_consumer.GetTotalMaxAllocationSize(),
                                     vulkan_stats_consumer.GetTotalGraphicsPipelineCount(),
                                     vulkan_stats_consumer.GetTotalComputePipelineCount(),
                                     vulkan_stats_consumer.GetTotalRayTracingPipelineCount());

    // TODO: This is the number of recorded draw calls, which will not reflect the number of draw calls
    // executed when recorded once to a command buffer that is submitted/replayed more than once.
    // WriteOutput("\nDraw/dispatch call info:");
    // WriteOutput("\tTotal draw calls: %" PRIu64, stats_consumer.GetTotalDrawCount());
    // WriteOutput("\tTotal dispatch calls: %" PRIu64, stats_consumer.GetTotalDispatchCount());

    // Print Physical device info
    const gfxrecon::decode::VulkanStatsConsumer::PhysicalDeviceProperties& physical_device_properties =
        vulkan_stats_consumer.GetPhysicalDeviceProperties();

    WriteOutput("\nPhysical device properties:");
    for (const auto& props : physical_device_properties)
    {
        WriteOutput("  Device: %" PRIu64, props.first);
        WriteOutput("\tAPI version:         0x%x (%s)",
                    props.second.apiVersion,
                    GetVkVersionString(props.second.apiVersion).c_str());
        WriteOutput("\tDriver version:      0x%x", props.second.driverVersion);
        WriteOutput("\tVendor ID:           0x%x", props.second.vendorID);
        WriteOutput("\tDevice ID:           0x%x", props.second.deviceID);
        WriteOutput("\tDevice name:         %s", props.second.deviceName);
    }

    if (file_processor.GetCurrentFrameNumber() == 0)
    {
        WriteOutput("\nFile did not contain any frames");
    }
}

#if defined(D3D12_SUPPORT)
void PrintDx12RuntimeInfoJson(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer, nlohmann::json& json_output)
{
    gfxrecon::format::Dx12RuntimeInfo runtime_info = dx12_consumer.GetDx12RuntimeInfo();

    std::string runtime_src = "N/A";
    std::string runtime_ver = "N/A";

    if (runtime_src.empty() == false)
    {
        runtime_src = runtime_info.src;
        runtime_ver = std::to_string(runtime_info.version[0]) + "." + std::to_string(runtime_info.version[1]) + "." +
                      std::to_string(runtime_info.version[2]) + "." + std::to_string(runtime_info.version[3]);
    }

    json_output["runtime"]["version"] = runtime_ver;
    json_output["runtime"]["source"]  = runtime_src;
}

void PrintDx12RuntimeInfoText(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer)
{
    gfxrecon::format::Dx12RuntimeInfo runtime_info = dx12_consumer.GetDx12RuntimeInfo();

    std::string runtime_src = "N/A";
    std::string runtime_ver = "N/A";

    if (runtime_src.empty() == false)
    {
        runtime_src = runtime_info.src;
        runtime_ver = std::to_string(runtime_info.version[0]) + "." + std::to_string(runtime_info.version[1]) + "." +
                      std::to_string(runtime_info.version[2]) + "." + std::to_string(runtime_info.version[3]);
    }

    WriteOutput("D3D12 runtime info:");
    WriteOutput("\tVersion: %s", runtime_ver.c_str());
    WriteOutput("\tSource: %s", runtime_src.c_str());
    WriteOutput("");
}

void PrintDx12AdapterInfoJson(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer, nlohmann::json& json_output)
{
    const std::vector<gfxrecon::format::DxgiAdapterDesc> adapters = dx12_consumer.GetAdapters();

    if (adapters.empty() == false)
    {
        std::unordered_map<int64_t, std::string> adapter_workload;
        dx12_consumer.CalcAdapterWorkload(adapter_workload, adapters);

        json_output["adapters"] = nlohmann::json::array();
        for (const auto& adapter : adapters)
        {
            const int64_t luid = (adapter.LuidHighPart << 31) | adapter.LuidLowPart;

            std::string adapter_workload_pct = "";

            if (adapter_workload.count(luid) > 0)
            {
                if (adapter_workload[luid] != "")
                {
                    adapter_workload_pct = "(" + adapter_workload[luid] + "% of GPU submissions)";
                }
            }
            else if (adapter_workload.size() > 0)
            {
                adapter_workload_pct = "(0% of GPU submissions)";
            }

            std::string adapter_type =
                AdapterTypeToString(gfxrecon::graphics::dx12::ExtractAdapterType(adapter.extra_info));

            nlohmann::json json_adapter;
            json_adapter["description"]["details"]          = gfxrecon::util::WCharArrayToString(adapter.Description);
            json_adapter["description"]["workload-percent"] = adapter_workload_pct;
            json_adapter["vendor-id"]                       = adapter.VendorId;
            json_adapter["device-id"]                       = adapter.DeviceId;
            json_adapter["subsys-id"]                       = adapter.SubSysId;
            json_adapter["revision"]                        = adapter.Revision;
            json_adapter["memory"]["dedicated"]["video"]    = adapter.DedicatedVideoMemory;
            json_adapter["memory"]["dedicated"]["system"]   = adapter.DedicatedSystemMemory;
            json_adapter["memory"]["shared"]                = adapter.SharedSystemMemory;
            json_adapter["memory"]["luid"]["low"]           = adapter.LuidLowPart;
            json_adapter["memory"]["luid"]["high"]          = adapter.LuidHighPart;
            json_adapter["adapter-type"]                    = adapter_type;
            json_output["adapters"].push_back(json_adapter);
        }
    }
    else
    {
        json_output["adapters"] = "not available";
    }
}

void PrintDx12AdapterInfoText(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer)
{
    WriteOutput("D3D12 adapter info:");

    const std::vector<gfxrecon::format::DxgiAdapterDesc> adapters = dx12_consumer.GetAdapters();

    if (adapters.empty() == false)
    {
        std::unordered_map<int64_t, std::string> adapter_workload;
        dx12_consumer.CalcAdapterWorkload(adapter_workload, adapters);

        for (const auto& adapter : adapters)
        {
            const int64_t luid = (adapter.LuidHighPart << 31) | adapter.LuidLowPart;

            std::string adapter_workload_pct = "";

            if (adapter_workload.count(luid) > 0)
            {
                if (adapter_workload[luid] != "")
                {
                    adapter_workload_pct = "(" + adapter_workload[luid] + "% of GPU submissions)";
                }
            }
            else if (adapter_workload.size() > 0)
            {
                adapter_workload_pct = "(0% of GPU submissions)";
            }

            std::string adapter_type =
                AdapterTypeToString(gfxrecon::graphics::dx12::ExtractAdapterType(adapter.extra_info));

            WriteOutput("\tDescription: %s %s",
                        gfxrecon::util::WCharArrayToString(adapter.Description).c_str(),
                        adapter_workload_pct.c_str());
            WriteOutput("\tVendor ID: 0x%x", adapter.VendorId);
            WriteOutput("\tDevice ID: 0x%x", adapter.DeviceId);
            WriteOutput("\tSubsys ID: 0x%x", adapter.SubSysId);
            WriteOutput("\tRevision: %u", adapter.Revision);
            WriteOutput("\tDedicated Video Memory: %" PRIu64, adapter.DedicatedVideoMemory);
            WriteOutput("\tDedicated System Memory: %" PRIu64, adapter.DedicatedSystemMemory);
            WriteOutput("\tShared System Memory: %" PRIu64, adapter.SharedSystemMemory);
            WriteOutput("\tLUID LowPart: 0x%x", adapter.LuidLowPart);
            WriteOutput("\tLUID HighPart: 0x%x", adapter.LuidHighPart);
            WriteOutput("\tAdapter type: %s", adapter_type.c_str());
            WriteOutput("");
        }
    }
    else
    {
        WriteOutput("\tAdapter info not available.");
        WriteOutput("");
    }
}

void PrintDx12SwapchainInfoJson(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer, nlohmann::json& json_output)
{
    if (dx12_consumer.FoundSwapchainInfo())
    {
        json_output["swapchain"]["dimensions"] = dx12_consumer.GetSwapchainDimensions();
    }
    else
    {
        json_output["swapchain"]["dimensions"] = "unavailable";
    }
}

void PrintDx12SwapchainInfoText(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer)
{
    WriteOutput("D3D12 swapchain info:");

    if (dx12_consumer.FoundSwapchainInfo())
    {
        WriteOutput("\tDimensions: %s", dx12_consumer.GetSwapchainDimensions().c_str());
    }
    else
    {
        WriteOutput("\tDimensions not available.");
    }

    WriteOutput("");
}

void PrintDxrEiInfoJson(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer, nlohmann::json& json_output)
{
    json_output["ei-workload"]  = dx12_consumer.ContainsEiWorkload() ? "yes" : "no";
    json_output["dxr-workload"] = dx12_consumer.ContainsDxrWorkload() ? "yes" : "no";
    if (dx12_consumer.ContainsEiWorkload() || dx12_consumer.ContainsDxrWorkload())
    {
        json_output["dxr/ei-optimized"] = dx12_consumer.ContainsOptFillMem() ? "yes" : "no";
    }
}

void PrintDxrEiInfoText(gfxrecon::decode::Dx12StatsConsumer& dx12_consumer)
{
    if (dx12_consumer.ContainsEiWorkload())
    {
        WriteOutput("D3D12 EI workload: yes");
    }
    else
    {
        WriteOutput("D3D12 EI workload: no");
    }

    WriteOutput("");

    if (dx12_consumer.ContainsDxrWorkload())
    {
        WriteOutput("D3D12 DXR workload: yes");
    }
    else
    {
        WriteOutput("D3D12 DXR workload: no");
    }

    if (dx12_consumer.ContainsEiWorkload() || dx12_consumer.ContainsDxrWorkload())
    {
        WriteOutput("");

        if (dx12_consumer.ContainsOptFillMem())
        {
            WriteOutput("D3D12 DXR/EI optimized: yes");
        }
        else
        {
            WriteOutput("D3D12 DXR/EI optimized: no");
        }
    }
}

void PrintD3D12StatsJson(gfxrecon::decode::FileProcessor&     file_processor,
                         gfxrecon::decode::Dx12StatsConsumer& dx12_consumer,
                         const ApiAgnosticStats&              api_agnostic_stats,
                         gfxrecon::decode::InfoConsumer&      info_consumer,
                         const AnnotationRecorder&            annotation_recoder,
                         nlohmann::json*                      json_output)
{
    if (dx12_consumer.GetDXGITestPresentCount() > 0 && api_agnostic_stats.uses_frame_markers == false)
    {
        json_output["d3d12"]["total-present-count"] = dx12_consumer.GetDXGITestPresentCount();
    }

    PrintDriverInfoJson(info_consumer, json_output["d3d12"]);
    PrintDx12RuntimeInfoJson(dx12_consumer, json_output["d3d12"]);
    PrintDx12AdapterInfoJson(dx12_consumer, json_output["d3d12"]);
    PrintDx12SwapchainInfoJson(dx12_consumer, json_output["d3d12"]);
    PrintDxrEiInfoJson(dx12_consumer, json_output["d3d12"]);
}

void PrintD3D12StatsText(gfxrecon::decode::FileProcessor&     file_processor,
                         gfxrecon::decode::Dx12StatsConsumer& dx12_consumer,
                         const ApiAgnosticStats&              api_agnostic_stats,
                         gfxrecon::decode::InfoConsumer&      info_consumer,
                         const AnnotationRecorder&            annotation_recoder)
{
    if (dx12_consumer.GetDXGITestPresentCount() > 0 && api_agnostic_stats.uses_frame_markers == false)
    {
        WriteOutput("\tTest present count: %u", dx12_consumer.GetDXGITestPresentCount());
    }

    PrintDriverInfoText(info_consumer);
    PrintDx12RuntimeInfoText(dx12_consumer);
    PrintDx12AdapterInfoText(dx12_consumer);
    PrintDx12SwapchainInfoText(dx12_consumer);
    PrintDxrEiInfoText(dx12_consumer);
}

static bool CheckOptionEnumGpuIndices(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kEnumGpuIndices))
    {
        IDXGIFactory1* factory1 = nullptr;

        HRESULT result = CreateDXGIFactory1(IID_IDXGIFactory1, reinterpret_cast<void**>(&factory1));

        if (SUCCEEDED(result))
        {
            gfxrecon::graphics::dx12::ActiveAdapterMap adapters{};
            gfxrecon::graphics::dx12::TrackAdapters(result, reinterpret_cast<void**>(&factory1), adapters);

            WriteOutput("GPU index\tGPU name\tSubSys ID");
            for (size_t index = 0; index < adapters.size(); ++index)
            {
                for (auto adapter : adapters)
                {
                    if (index == adapter.second.adapter_idx)
                    {
                        std::string replay_adapter_str =
                            gfxrecon::util::WCharArrayToString(adapter.second.internal_desc.Description);

                        WriteOutput("%-9x\t%s\t%u",
                                    adapter.second.adapter_idx,
                                    replay_adapter_str.c_str(),
                                    adapter.second.internal_desc.SubSysId);
                        adapter.second.adapter->Release();
                        break;
                    }
                }
            }
            factory1->Release();
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to enumerate GPU indices");
        }

        return true;
    }

    return false;
}
#endif

#if ENABLE_OPENXR_SUPPORT
void PrintOpenXrStatsJson(const gfxrecon::decode::FileProcessor&       file_processor,
                          const gfxrecon::decode::OpenXrStatsConsumer& openxr_stats_consumer,
                          nlohmann::json&                              json_output)
{
    auto instance_info = openxr_stats_consumer.GetInstanceInfo();

    json_output["openxr"]["header-version"] = std::to_string(XR_VERSION_MAJOR(XR_CURRENT_API_VERSION)) + "." +
                                              std::to_string(XR_VERSION_MINOR(XR_CURRENT_API_VERSION)) + "." +
                                              std::to_string(XR_VERSION_PATCH(XR_CURRENT_API_VERSION));
    json_output["openxr"]["instances"] = nlohmann::json::array();

    uint32_t       inst_index = 0;
    nlohmann::json instance_array;
    for (auto& it : instance_info)
    {
        nlohmann::json instance_json;

        instance_json["application-info"]["application"]["name"]    = it.second.app_name;
        instance_json["application-info"]["application"]["version"] = it.second.app_version;
        instance_json["application-info"]["engine"]["name"]         = it.second.engine_name;
        instance_json["application-info"]["engine"]["version"]      = it.second.engine_version;
        instance_json["application-info"]["api-version"]            = GetXrVersionString(it.second.api_version);

        if (it.second.enabled_extensions.size() > 0)
        {
            instance_json["extensions"] = nlohmann::json::array();
            for (uint32_t ext = 0; ext < it.second.enabled_extensions.size(); ++ext)
            {
                instance_json["extensions"].push_back(it.second.enabled_extensions[ext]);
            }
        }

        json_output["openxr"]["instances"].push_back(instance_json);
    }
}

void PrintOpenXrStatsText(const gfxrecon::decode::FileProcessor&       file_processor,
                          const gfxrecon::decode::OpenXrStatsConsumer& openxr_stats_consumer)
{
    auto instance_info = openxr_stats_consumer.GetInstanceInfo();

    WriteOutput("");
    WriteOutput("OpenXR info:");

    WriteOutput("\tHeader Version:             %u.%u.%u",
                XR_VERSION_MAJOR(XR_CURRENT_API_VERSION),
                XR_VERSION_MINOR(XR_CURRENT_API_VERSION),
                XR_VERSION_PATCH(XR_CURRENT_API_VERSION));

    WriteOutput("\tNumber of OpenXR Instances: %d", instance_info.size());

    // For non-verbose standard output, just print first application/instance info
    WriteOutput("\nOpenXR application info:");
    WriteOutput("\tApplication name:    %s", instance_info[0].app_name.c_str());
    WriteOutput("\tApplication version: %u", instance_info[0].app_version);
    WriteOutput("\tEngine name:         %s", instance_info[0].engine_name.c_str());
    WriteOutput("\tEngine version:      %u", instance_info[0].engine_version);
    WriteOutput("\tTarget API version:  %u (%s)",
                instance_info[0].api_version,
                GetXrVersionString(instance_info[0].api_version).c_str());
}
#endif // ENABLE_OPENXR_SUPPORT

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
        file_processor.ProcessAllFrames();

        PrintExeInfoText(info_consumer);
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
        bool success = file_processor.ProcessNextFrame();
        if (success && !file_processor.UsesFrameMarkers())
        {
            file_processor.ProcessNextFrame();
        }
        WriteOutput("File format info:");
        PrintFileFormatInfoText(file_processor);
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
        file_processor.ProcessAllFrames();
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

        gfxrecon::decode::VulkanDetectionConsumer vulkan_detection_consumer(
            gfxrecon::decode::VulkanDetectionConsumer::kNoBlockLimit);
        gfxrecon::decode::VulkanStatsConsumer vulkan_stats_consumer;
        gfxrecon::decode::VulkanDecoder       vulkan_decoder;
        vulkan_decoder.AddConsumer(&vulkan_detection_consumer);
        vulkan_decoder.AddConsumer(&vulkan_stats_consumer);
        file_processor.AddDecoder(&vulkan_decoder);

#if defined(D3D12_SUPPORT)
        gfxrecon::decode::Dx12DetectionConsumer dx12_detection_consumer(
            gfxrecon::decode::Dx12DetectionConsumer::kNoBlockLimit);
        gfxrecon::decode::Dx12StatsConsumer dx12_consumer;
        gfxrecon::decode::Dx12Decoder       dx12_decoder;
        dx12_decoder.AddConsumer(&dx12_detection_consumer);
        dx12_decoder.AddConsumer(&dx12_consumer);
        file_processor.AddDecoder(&dx12_decoder);
#endif

#if ENABLE_OPENXR_SUPPORT
        gfxrecon::decode::OpenXrDetectionConsumer openxr_detection_consumer;
        gfxrecon::decode::OpenXrStatsConsumer     openxr_stats_consumer;
        gfxrecon::decode::OpenXrDecoder           openxr_decoder;

        openxr_decoder.AddConsumer(&openxr_detection_consumer);
        openxr_decoder.AddConsumer(&openxr_stats_consumer);
        file_processor.AddDecoder(&openxr_decoder);
#endif

        file_processor.ProcessAllFrames();
        if (file_processor.GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone)
        {
            uint32_t blank_frame_count = 0;
            bool     vulkan_present    = vulkan_detection_consumer.WasVulkanAPIDetected();
            bool     dx12_present      = false;
            bool     openxr_present    = false;
#if defined(D3D12_SUPPORT)
            blank_frame_count = dx12_consumer.GetDummyFrameCount();
            dx12_present      = dx12_detection_consumer.WasD3D12APIDetected();
#endif
#if ENABLE_OPENXR_SUPPORT
            openxr_present = openxr_detection_consumer.WasOpenXrAPIDetected();
#endif

            ApiAgnosticStats api_agnostic_stats = {};
            GatherApiAgnosticStats(api_agnostic_stats, file_processor, stat_consumer, blank_frame_count);
            if (api_agnostic_stats.trim_start_frame < vulkan_stats_consumer.GetTrimmedStartFrame())
            {
                api_agnostic_stats.trim_start_frame = vulkan_stats_consumer.GetTrimmedStartFrame();
            }

            // If no APIs were detected, print stats for all APIs.
            bool missing_api_info = !vulkan_present;
#if defined(D3D12_SUPPORT)
            missing_api_info = missing_api_info && !dx12_present;
#endif
#if ENABLE_OPENXR_SUPPORT
            missing_api_info = missing_api_info && !openxr_present;
#endif
            // If we're missing API info, force printing everything
            if (missing_api_info)
            {
                vulkan_present = true;
                dx12_present   = true;
                openxr_present = true;
            }

            if (output_json)
            {
                nlohmann::json json_content;

                PrintDetectedApiInfoJson(vulkan_present, dx12_present, openxr_present, json_content);
                PrintExeInfoJson(info_consumer, json_content);
                PrintFileFormatInfoJson(file_processor, json_content);
                PrintEnvironmentVariableInfoJson(info_consumer, json_content);
                if (api_agnostic_stats.error_state == gfxrecon::decode::BlockIOError::kErrorNone)
                {
                    PrintApiAgnosticStatsJson(api_agnostic_stats, vulkan_present, dx12_present, json_content);

                    if (vulkan_present)
                    {
                        PrintVulkanStatsJson(file_processor, vulkan_stats_consumer, json_content);
                    }

#if defined(D3D12_SUPPORT)
                    if (dx12_present)
                    {
                        PrintD3D12StatsJson(file_processor,
                                            dx12_consumer,
                                            api_agnostic_stats,
                                            info_consumer,
                                            annotation_recorder,
                                            json_content);
                    }
#endif
#if ENABLE_OPENXR_SUPPORT
                    if (openxr_present)
                    {
                        PrintOpenXrStatsJson(file_processor, openxr_stats_consumer, json_content);
                    }
#endif
                    if (annotation_recorder.GetNumValidAnnotations())
                    {
                        PrintAnnotationsJson(annotation_recorder.GetAnnotationData(), json_content);
                    }
                }
                else if (api_agnostic_stats.error_state != gfxrecon::decode::BlockIOError::kErrorNone)
                {
                    WriteOutput("A failure has occurred during file processing");
                    gfxrecon::util::Log::Release();
                    exit(-1);
                }
                else
                {
                    json_content["capture-file"]["frames"]["total-count"] = 0;
                    WriteOutput("File did not contain any frames");
                }
                WriteOutput(json_content.dump(4, ' ', true).c_str());
            }
            else
            {
                PrintDetectedApiInfoText(vulkan_present, dx12_present, openxr_present);
                PrintExeInfoText(info_consumer);
                if (api_agnostic_stats.error_state == gfxrecon::decode::BlockIOError::kErrorNone)
                {
                    PrintApiAgnosticStatsText(api_agnostic_stats, vulkan_present, dx12_present);

                    if (vulkan_present)
                    {
                        PrintVulkanStatsText(file_processor, vulkan_stats_consumer);
                    }

#if defined(D3D12_SUPPORT)
                    if (dx12_present)
                    {
                        PrintD3D12StatsText(
                            file_processor, dx12_consumer, api_agnostic_stats, info_consumer, annotation_recorder);
                    }
#endif
#if ENABLE_OPENXR_SUPPORT
                    if (openxr_present)
                    {
                        PrintOpenXrStatsText(file_processor, openxr_stats_consumer);
                    }
#endif

                    if (annotation_recorder.GetNumValidAnnotations())
                    {
                        PrintAnnotationsText(annotation_recorder.GetAnnotationData());
                    }
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

int main(int argc, const char** argv)
{
    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintUsage(argv[0], arg_parser) || CheckOptionPrintVersion(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
#if defined(D3D12_SUPPORT)
    else if (CheckOptionEnumGpuIndices(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
#endif
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
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
    else
    {
        success = GatherAndPrintAllInfo(input_filename, arg_parser.IsOptionSet(kVerboseOption));
    }

    gfxrecon::util::Log::Release();
    return success ? EXIT_SUCCESS : EXIT_FAILURE;
}
