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
#include "util/info_output.h"
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

// Output Data Flags
const uint32_t kOutputFlag_FileInfo        = 0x0001;
const uint32_t kOutputFlag_ExeInfo         = 0x0002;
const uint32_t kOutputFlag_EnvironmentInfo = 0x0004;
const uint32_t kOutputFlag_AnnotationInfo  = 0x0008;
const uint32_t kOutputFlag_VulkanInfo      = 0x1000;
const uint32_t kOutputFlag_DxInfo          = 0x2000;
const uint32_t kOutputFlag_OpenXRInfo      = 0x4000;
const uint32_t kOutputFlag_All             = 0xFFFFFFFF;

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - Print statistics for a GFXReconstruct capture file.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE(
        "  %s [-h | --help] [--version] [--exe-info-only] [--verbose] [--output <file>] <capture-file>\n",
        app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <capture-file>\tThe GFXReconstruct capture file to be processed.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --exe-info-only\tQuickly exit after extracting captured application's executable name");
    GFXRECON_WRITE_CONSOLE("  --file-format-only\tQuickly exit after extracting file format information");
    GFXRECON_WRITE_CONSOLE(
        "  --env-vars-only\tQuickly exit after extracting captured application's environment variables");
#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("        \t\tdisplayed when abort() is called (Windows debug only).");
#endif
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("  --enum-gpu-indices\tPrint GPU indices and exit");
#endif
    GFXRECON_WRITE_CONSOLE("  --verbose\t\tOutput more information in JSON format");
    GFXRECON_WRITE_CONSOLE(
        "  --output\t\tOutput generated information to the provided file. If not defined output goes to std::out");
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

        GFXRECON_WRITE_CONSOLE("%s version info:", app_name.c_str());
        GFXRECON_WRITE_CONSOLE("  GFXReconstruct Version %s", GetProjectVersionString());
        GFXRECON_WRITE_CONSOLE("  Vulkan Header Version %s",
                               gfxrecon::decode::VulkanStatsConsumer::GetCurrentHeaderVersionString().c_str());

        return true;
    }

    return false;
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

class FileInfoRecorder : public gfxrecon::util::InfoOutputInterface
{
  public:
    FileInfoRecorder() {}
    ~FileInfoRecorder() {}

    void GatherFileInfo(const gfxrecon::decode::FileProcessor& fp,
                        bool                                   vulkan_present,
                        bool                                   d3d_present,
                        bool                                   openxr_present)
    {
        const gfxrecon::format::FileHeader& file_header  = fp.GetFileHeader();
        auto                                file_options = fp.GetFileOptions();

        vulkan_present_ = vulkan_present;
        d3d_present_    = d3d_present;
        openxr_present_ = openxr_present;

        file_version_string_ =
            std::to_string(file_header.major_version) + "." + std::to_string(file_header.minor_version);
        file_uses_frame_markers_     = fp.UsesFrameMarkers();
        file_supports_frame_markers_ = fp.FileSupportsFrameMarkers();
        file_error_state_            = fp.GetErrorState();
        file_total_frame_count_      = fp.GetCurrentFrameNumber();

        if (file_uses_frame_markers_)
        {
            // Check if this is pre-marker file support
            if (file_header.major_version == 0 && file_header.minor_version == 0 && !file_supports_frame_markers_)
            {
                file_frame_marker_type_ = "explicit (unsupported)";
            }
            else
            {
                file_frame_marker_type_ = "explicit";
            }
        }
        else
        {
            file_frame_marker_type_ = "implicit";
        }

        for (const auto& option : file_options)
        {
            if (option.key == gfxrecon::format::FileOption::kCompressionType)
            {
                file_compression_type_ = static_cast<gfxrecon::format::CompressionType>(option.value);
            }
        }

        if (file_total_frame_count_ == 0)
        {
            last_warning_message_ = "File did not contain any frames";
        }
    }

    void GatherFrameInfo(gfxrecon::decode::StatConsumer&              stat_consumer,
                         const gfxrecon::decode::VulkanStatsConsumer& vulkan_stat_consumer,
                         uint32_t                                     blank_frame_count)
    {
        trim_start_frame_  = stat_consumer.GetTrimmedStartFrame();
        blank_frame_count_ = blank_frame_count;
        if (trim_start_frame_ < vulkan_stat_consumer.GetTrimmedStartFrame())
        {
            trim_start_frame_ = vulkan_stat_consumer.GetTrimmedStartFrame();
        }
        trim_end_frame_ = trim_start_frame_ + (file_total_frame_count_ - 1);
    }

    bool         HasErrorMessage() { return last_error_message_.size() > 0; }
    std::string& GetLastErrorMessage() { return last_error_message_; }
    bool         HasWarningMessage() { return last_warning_message_.size() > 0; }
    std::string& GetLastWarningMessage() { return last_warning_message_; }

    std::pair<const std::string, const nlohmann::json*> GenerateJson() const override
    {
        nlohmann::json* capture_file_base = new nlohmann::json;

        (*capture_file_base)["file-version"]     = file_version_string_;
        (*capture_file_base)["frame-delimiters"] = file_frame_marker_type_;
        (*capture_file_base)["compression"]["format"] =
            gfxrecon::format::GetCompressionTypeName(file_compression_type_);
        (*capture_file_base)["frames"]["blank-count"]  = blank_frame_count_;
        (*capture_file_base)["frames"]["actual-count"] = file_total_frame_count_;
        (*capture_file_base)["frames"]["total-count"]  = blank_frame_count_ + file_total_frame_count_;
        (*capture_file_base)["frames"]["start-frame"]  = trim_start_frame_;
        (*capture_file_base)["frames"]["end-frame"]    = trim_end_frame_;
        return std::make_pair("capture-file", capture_file_base);
    }

    const std::vector<std::string> GenerateStrings() const override
    {
        std::vector<std::string> out_strings;

        out_strings.push_back("");
        out_strings.push_back("File info:");

        out_strings.push_back("\tCompression format:   " +
                              gfxrecon::format::GetCompressionTypeName(file_compression_type_));
        if (trim_start_frame_ == 0)
        {
            // Not a trimmed file.
            out_strings.push_back("\tTotal frames:         " + std::to_string(file_total_frame_count_));
        }
        else
        {
            if (blank_frame_count_)
            {
                out_strings.push_back("\tBlank frames:         " + std::to_string(blank_frame_count_));
                out_strings.push_back("\tCaptured frames:      " + std::to_string(file_total_frame_count_));
            }

            // Print out the total frames and range based on the API (since we have 2 different ways of showing it)
            if (vulkan_present_)
            {
                out_strings.push_back("\tTotal frames:         " + std::to_string(file_total_frame_count_) +
                                      " (trimmed frame range " + std::to_string(trim_start_frame_) + "-" +
                                      std::to_string(trim_end_frame_) + ")");
            }
            else
            {
                out_strings.push_back("\tTotal frames:         " +
                                      std::to_string(file_total_frame_count_ + blank_frame_count_));
                out_strings.push_back("\tApplication frame range: " + std::to_string(trim_start_frame_) + "-" +
                                      std::to_string(trim_end_frame_));
            }
        }

        out_strings.push_back("\tFile format version:  " + file_version_string_);
        out_strings.push_back("\tFrame delimiters:     " + file_frame_marker_type_);

        return out_strings;
    }

  private:
    std::string                       file_version_string_;
    bool                              file_uses_frame_markers_     = false;
    bool                              file_supports_frame_markers_ = false;
    std::string                       file_frame_marker_type_;
    gfxrecon::decode::BlockIOError    file_error_state_;
    gfxrecon::format::CompressionType file_compression_type_{ gfxrecon::format::CompressionType::kNone };
    uint32_t                          file_total_frame_count_{ 0 };
    uint32_t                          trim_start_frame_{ 0 };
    uint32_t                          trim_end_frame_{ 0 };
    uint32_t                          blank_frame_count_{ 0 };
    bool                              vulkan_present_{ false };
    bool                              d3d_present_{ false };
    bool                              openxr_present_{ false };

    std::string last_error_message_;
    std::string last_warning_message_;
};

class ExecutableInfoRecorder : public gfxrecon::util::InfoOutputInterface
{
  public:
    ExecutableInfoRecorder() {}
    ~ExecutableInfoRecorder() {}

    void GatherInfo(const gfxrecon::decode::InfoConsumer& info_consumer, bool dx_present)
    {
        dx_present_       = dx_present;
        exe_name_         = info_consumer.GetAppExeName();
        file_description_ = info_consumer.GetFileDescription();
        company_name_     = info_consumer.GetCompanyName();
        product_name_     = info_consumer.GetProductName();

        auto exe_version_array = info_consumer.GetAppVersion();
        exe_version_ = std::to_string(exe_version_array[0]) + "." + std::to_string(exe_version_array[1]) + "." +
                       std::to_string(exe_version_array[2]) + "." + std::to_string(exe_version_array[3]);

        driver_description_ = "Not available";
        if (gfxrecon::util::platform::StringLength(info_consumer.GetDriverDesc()) > 0)
        {
            driver_description_ = info_consumer.GetDriverDesc();
        }
    }

    std::pair<const std::string, const nlohmann::json*> GenerateJson() const override
    {
        nlohmann::json* exe_base        = new nlohmann::json;
        (*exe_base)["name"]             = exe_name_;
        (*exe_base)["version"]          = exe_version_;
        (*exe_base)["company"]          = company_name_;
        (*exe_base)["product"]          = product_name_;
        (*exe_base)["file-description"] = file_description_;
        if (dx_present_)
        {
            (*exe_base)["driver-description"] = driver_description_;
        }
        return std::make_pair("exe", exe_base);
    }

    const std::vector<std::string> GenerateStrings() const override
    {
        std::vector<std::string> out_strings;

        out_strings.push_back("");
        out_strings.push_back("Exe info:");
        out_strings.push_back("\tApplication exe name:     " + exe_name_);
        out_strings.push_back("\tApplication version:      " + exe_version_);
        out_strings.push_back("\tApplication Company name: " + company_name_);

        // we are combining file description and product name and presenting both only if they are not same
        std::string app_data = file_description_;
        if (strcmp(product_name_.c_str(), "N/A") != 0)
        {
            if (strcmp(product_name_.c_str(), file_description_.c_str()) != 0)
            {
                app_data += " // ";
                app_data += product_name_;
            }
        }
        out_strings.push_back("\tProduct name:             " + app_data);

        if (dx_present_)
        {
            out_strings.push_back("");
            out_strings.push_back("Driver info:");
            if (driver_description_ != "Not available")
            {
                out_strings.push_back(std::string("\t") + driver_description_);
            }
            else
            {
                out_strings.push_back("\tDriver info not available.");
            }
        }

        return out_strings;
    }

  private:
    std::string exe_name_;
    std::string exe_version_;
    std::string company_name_;
    std::string product_name_;
    std::string file_description_;
    std::string driver_description_;
    bool        dx_present_{ false };
};

class EnvironmentInfoRecorder : public gfxrecon::util::InfoOutputInterface
{
  public:
    EnvironmentInfoRecorder() {}
    ~EnvironmentInfoRecorder() {}

    void GatherInfo(const gfxrecon::decode::InfoConsumer& info_consumer)
    {
        std::string delimiter = "=";
        for (const std::string& var : info_consumer.GetEnvironmentVariables())
        {
            const auto& delimiter_pos = var.find(delimiter);
            std::string key           = var.substr(0, delimiter_pos);
            std::string value         = var.substr(delimiter_pos + 1);
            environment_vars_[key]    = value;
        }
    }

    std::pair<const std::string, const nlohmann::json*> GenerateJson() const override
    {
        nlohmann::json* env_var_base = new nlohmann::json;

        for (const auto& [key, value] : environment_vars_)
        {
            (*env_var_base)[key] = value;
        }
        return std::make_pair("environment", env_var_base);
    }

    const std::vector<std::string> GenerateStrings() const override
    {
        std::vector<std::string> out_strings;

        out_strings.push_back("Environment variables:");
        for (const auto& [key, value] : environment_vars_)
        {
            out_strings.push_back("\t" + key + " = " + value);
        }

        return out_strings;
    }

  private:
    std::unordered_map<std::string, std::string> environment_vars_;
};

class AnnotationRecorder : public gfxrecon::decode::AnnotationHandler, public gfxrecon::util::InfoOutputInterface
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
            { "Default replay options", gfxrecon::format::kAnnotationLabelReplayOptions, "" },
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

    const uint32_t GetNumValidAnnotations() const { return num_valid_annotations_; }

    std::pair<const std::string, const nlohmann::json*> GenerateJson() const override
    {
        nlohmann::json* annotation_base = new nlohmann::json;
        for (const auto& annotation_info : expected_annotations_)
        {
            if (annotation_info.data.size() > 0)
            {
                nlohmann::json annotation;
                annotation["description"] = annotation_info.desc;
                annotation["data"]        = annotation_info.data;
                annotation_base->push_back(annotation);
            }
        }
        return std::make_pair("annotations", annotation_base);
    }

    const std::vector<std::string> GenerateStrings() const override
    {
        std::vector<std::string> out_strings;
        out_strings.push_back("");
        out_strings.push_back("Annotations:");

        for (const auto& annotation_info : expected_annotations_)
        {
            if (annotation_info.data.size() > 0)
            {
                out_strings.push_back("\t" + annotation_info.desc + ": " + annotation_info.data);
            }
        }
        return out_strings;
    }

  private:
    std::string ParseJsonForAnnotationData(const nlohmann::json& json_obj, const std::string& key)
    {
        const int   kDefaultIndent         = 12;
        std::string out                    = "";
        auto        search_result_iterator = json_obj.find(key);
        if (search_result_iterator != json_obj.end())
        {
            const nlohmann::json& value = *search_result_iterator;
            if (value.is_object())
            {
                out += "\n\t" + value.dump(kDefaultIndent);
                out.pop_back();
                out += "\t}";
            }
            else
            {
                out = value;
            }
        }

        return out;
    }

    uint32_t                    num_valid_annotations_{ 0 };
    std::vector<AnnotationInfo> expected_annotations_;
};

#if defined(D3D12_SUPPORT)
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

            GFXRECON_WRITE_CONSOLE("GPU index\tGPU name\tSubSys ID");
            for (size_t index = 0; index < adapters.size(); ++index)
            {
                for (auto adapter : adapters)
                {
                    if (index == adapter.second.adapter_idx)
                    {
                        std::string replay_adapter_str =
                            gfxrecon::util::WCharArrayToString(adapter.second.internal_desc.Description);

                        GFXRECON_WRITE_CONSOLE("%-9x\t%s\t%u",
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

void GatherAndPrintInfo(uint32_t                    output_flags,
                        gfxrecon::util::InfoWriter& info_writer,
                        const std::string&          input_filename)
{
    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        bool process_frames = (output_flags & kOutputFlag_AnnotationInfo) != 0;

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
        if (output_flags & kOutputFlag_VulkanInfo)
        {
            file_processor.AddDecoder(&vulkan_decoder);
            process_frames = true;
        }

#if defined(D3D12_SUPPORT)
        gfxrecon::decode::Dx12DetectionConsumer dx12_detection_consumer(
            gfxrecon::decode::Dx12DetectionConsumer::kNoBlockLimit);
        gfxrecon::decode::Dx12StatsConsumer dx12_consumer;
        gfxrecon::decode::Dx12Decoder       dx12_decoder;
        dx12_decoder.AddConsumer(&dx12_detection_consumer);
        dx12_decoder.AddConsumer(&dx12_consumer);
        if (output_flags & kOutputFlag_DxInfo)
        {
            file_processor.AddDecoder(&dx12_decoder);
            process_frames = true;
        }
#endif

#if ENABLE_OPENXR_SUPPORT
        gfxrecon::decode::OpenXrDetectionConsumer openxr_detection_consumer;
        gfxrecon::decode::OpenXrStatsConsumer     openxr_stats_consumer;
        gfxrecon::decode::OpenXrDecoder           openxr_decoder;

        openxr_decoder.AddConsumer(&openxr_detection_consumer);
        openxr_decoder.AddConsumer(&openxr_stats_consumer);
        if (output_flags & kOutputFlag_OpenXRInfo)
        {
            file_processor.AddDecoder(&openxr_decoder);
            process_frames = true;
        }
#endif

        if (process_frames)
        {
            file_processor.ProcessAllFrames();
        }

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

            ExecutableInfoRecorder exe_info_recorder;
            exe_info_recorder.GatherInfo(info_consumer, dx12_present);
            if (output_flags & kOutputFlag_ExeInfo)
            {
                info_writer.AddInfoOutputItem(&exe_info_recorder);
            }

            FileInfoRecorder file_info_recorder;
            file_info_recorder.GatherFileInfo(file_processor, vulkan_present, dx12_present, openxr_present);
            file_info_recorder.GatherFrameInfo(stat_consumer, vulkan_stats_consumer, blank_frame_count);
            if (output_flags & kOutputFlag_FileInfo)
            {
                info_writer.AddInfoOutputItem(&file_info_recorder);
            }
            if (file_info_recorder.HasErrorMessage())
            {
                info_writer.AddError(file_info_recorder.GetLastErrorMessage());
            }
            if (file_info_recorder.HasWarningMessage())
            {
                info_writer.AddWarning(file_info_recorder.GetLastWarningMessage());
            }

            EnvironmentInfoRecorder env_var_info_recorder;
            env_var_info_recorder.GatherInfo(info_consumer);
            if (output_flags & kOutputFlag_EnvironmentInfo)
            {
                info_writer.AddInfoOutputItem(&env_var_info_recorder);
            }

            // If no APIs were detected, print stats for all APIs.
            bool print_all_apis = !vulkan_present;
#if defined(D3D12_SUPPORT)
            print_all_apis = print_all_apis && !dx12_present;
#endif
#if ENABLE_OPENXR_SUPPORT
            print_all_apis = print_all_apis && !openxr_present;
#endif

            if (print_all_apis)
            {
                info_writer.AddWarning("Unable to detect capture file API(s). Writing all stats.");
            }

            if ((output_flags & kOutputFlag_VulkanInfo) && (vulkan_present || print_all_apis))
            {
                info_writer.AddInfoOutputItem(&vulkan_stats_consumer);
            }

#if defined(D3D12_SUPPORT)
            if ((output_flags & kOutputFlag_DxInfo) && (dx12_present || print_all_apis))
            {
                info_writer.AddInfoOutputItem(&dx12_consumer);
            }
#endif
#if ENABLE_OPENXR_SUPPORT
            if ((output_flags & kOutputFlag_OpenXRInfo) && (openxr_present || print_all_apis))
            {
                info_writer.AddInfoOutputItem(&openxr_stats_consumer);
            }
#endif

            if ((output_flags & kOutputFlag_AnnotationInfo) && annotation_recorder.GetNumValidAnnotations() > 0)
            {
                info_writer.AddInfoOutputItem(&annotation_recorder);
            }

            // Write out the generated output
            info_writer.GenerateOutput();
        }
        else
        {
            GFXRECON_WRITE_CONSOLE("ERROR: Encountered error while reading capture. Stats unavailable.");
            switch (file_processor.GetErrorState())
            {
                case gfxrecon::decode::BlockIOError::kEndOfFile:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Premature encounter of end-of-file");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorInvalidFileDescriptor:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Invalid file descriptor");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorOpeningFile:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Failed to open file");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorReadingFile:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Failed to read file");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorReadingFileHeader:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Failed reading file header");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorReadingBlockHeader:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Failed reading a block header");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorReadingCompressedBlockHeader:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Failed reading a compressed block header");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorReadingBlockData:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Failed reading block data");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorReadingCompressedBlockData:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Failed reading compressed block data");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorInvalidFourCC:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Invalid FourCC");
                    break;
                case gfxrecon::decode::BlockIOError::kErrorUnsupportedCompressionType:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Unsupported compression type");
                    break;
                default:
                    GFXRECON_WRITE_CONSOLE("        Reason given: Unknown error");
                    break;
            }
        }
    }
}

int main(int argc, const char** argv)
{
    gfxrecon::util::InfoWriter info_writer;
    uint32_t                   output_flags = kOutputFlag_All;

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

    if (arg_parser.IsArgumentSet(kOutputFileArgument))
    {
        std::string output_filename = arg_parser.GetArgumentValue(kOutputFileArgument);
        info_writer.SetFileTarget(output_filename);
    }
    if (arg_parser.IsOptionSet(kVerboseOption))
    {
        info_writer.SetOutputFormat(gfxrecon::util::kInfoOutputFmt_Json);
    }
    else
    {
        // FOr standard output, environment content is not written by default.
        output_flags &= (~kOutputFlag_EnvironmentInfo);
    }

    if (arg_parser.IsOptionSet(kExeInfoOnlyOption))
    {
        output_flags = kOutputFlag_ExeInfo;
    }
    else if (arg_parser.IsOptionSet(kEnvVarsOnlyOption))
    {
        output_flags = kOutputFlag_EnvironmentInfo;
    }
    else if (arg_parser.IsOptionSet(kFileFormatOnlyOption))
    {
        output_flags = kOutputFlag_FileInfo;
    }
    GatherAndPrintInfo(output_flags, info_writer, input_filename);

    gfxrecon::util::Log::Release();
    return 0;
}
