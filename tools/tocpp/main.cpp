/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <fstream>
#include <ftw.h>
#include <util/date_time.h>

#include "project_version.h"

#include "decode/file_processor.h"
#include "format/format.h"
#include "generated/generated_vulkan_cpp_consumer.h"
#include "generated/generated_vulkan_cpp_pre_process_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/argument_parser.h"
#include "util/file_path.h"
#include "util/logging.h"

#include "vulkan/vulkan_core.h"

const char kHelpShortOption[] = "-h";
const char kHelpLongOption[]  = "--help";
const char kVersionOption[]   = "--version";

const char kCppTargetShortOption[]     = "-t";
const char kCppTargetLongOption[]      = "--target";
const char kCppTargetPlatformXcb[]     = "xcb";
const char kCppTargetPlatformAndroid[] = "android";

const char kCppOutputShortOption[] = "-o";
const char kCppOutputLongOption[]  = "--output";

const char kCppOutputFrameLimitShortOption[] = "-f";
const char kCppOutputFrameLimitLongOption[]  = "--frame-limit";

const char kCppOutputCommandLimitShortOption[] = "-c";
const char kCppOutputCommandLimitLongOption[]  = "--command-limit";

const char kCppOutputMaxWindowWidthLongOption[]  = "--max-width";
const char kCppOutputMaxWindowHeightLongOption[] = "--max-height";

const char kCppAndroidTemplateOption[] = "--android-template";

const char kOptions[]   = "-h|--help,--version";
const char kArguments[] = "-t|--target,-o|--output,--android-template,-c|--command-limit,-f|--frame-limit,--max-width,--max-height";

#if defined(WIN32)
const char kPathSep = '\\';
#else
const char kPathSep = '/';
#endif

static std::string android_template_root;
static std::string output_dirname;

// Directory structure where the Vulkan source will be generated as VulkanMain.cpp.
const std::string path_vulkanmain = "app/src/main/jni/";

// Directory structure where the image data will be generated in the output directory.
const std::string path_assets = "app/src/main/assets/";

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
        GFXRECON_WRITE_CONSOLE("  GFXReconstruct Version %s", GFXRECON_PROJECT_VERSION_STRING);
        GFXRECON_WRITE_CONSOLE("  Vulkan Header Version %u.%u.%u",
                               VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                               VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

        return true;
    }

    return false;
}

static void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    GFXRECON_WRITE_CONSOLE("\n%s - A tool to convert GFXReconstruct capture files to Vulkan source.\n",
                           app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s\t[-h | --help] [--version]", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\t[-o <dir> | --output <dir>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[-t <platform> | --target <platform>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--android-template <dir>] <file>\n");
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the capture file to convert.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  -o <dir>\t\t\tPath to the directory where the outputs will be generated.");
    GFXRECON_WRITE_CONSOLE("  -t <platform>\t\t\tType of target platform to generate the Vulkan source.");
    GFXRECON_WRITE_CONSOLE("          \t\t\tAvailable platforms are:");
    GFXRECON_WRITE_CONSOLE("          \t\t\t    %s\t\tGenerate for XCB. (default)", kCppTargetPlatformXcb);
    GFXRECON_WRITE_CONSOLE("          \t\t\t    %s\tGenerate for Android.", kCppTargetPlatformAndroid);
    GFXRECON_WRITE_CONSOLE("  --android-template <dir>\tThe path of the android template directory.");
    GFXRECON_WRITE_CONSOLE("          \t\t\t    Usually: 'external/Tocpp-Android-Template'.");
    GFXRECON_WRITE_CONSOLE("  -l <uint>\t\t\tThe maximum amount of frames to generate.");
    GFXRECON_WRITE_CONSOLE("  --max-width <uint>\t\tThe maximum window width the device's screen can handle.");
    GFXRECON_WRITE_CONSOLE("  --max-height <uint>\t\tThe maximum window height the device's screen can handle.");
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

static std::string GetCppTargetPlatform(const gfxrecon::util::ArgumentParser& arg_parser)
{
    std::string platform = arg_parser.GetArgumentValue(kCppTargetShortOption);

    // Choose the 'xcb' platform if the given value is missing or invalid.
    if (gfxrecon::util::platform::StringCompare(kCppTargetPlatformXcb, platform.c_str()) != 0 &&
        gfxrecon::util::platform::StringCompare(kCppTargetPlatformAndroid, platform.c_str()) != 0)
    {
        GFXRECON_LOG_INFO("Target platform is not specified or invalid, fall back to '%s'.", kCppTargetPlatformXcb);
        return std::string(kCppTargetPlatformXcb);
    }

    return platform;
}

static bool outputDirectoryIsValid(std::string& out_dir)
{
    if (out_dir.empty())
    {
        GFXRECON_LOG_ERROR("The output directory is not specified!");
        return false;
    }

    if (gfxrecon::util::filepath::Exists(out_dir))
    {
        if (!gfxrecon::util::filepath::IsDirectory(out_dir))
        {
            GFXRECON_LOG_ERROR("Error while creating directory %s: already exists as file", out_dir.c_str());
            return false;
        }
    }
    else
    {
        int32_t result = gfxrecon::util::platform::MakeDirectory(out_dir.c_str());
        if (result < 0)
        {
            GFXRECON_LOG_ERROR("Error while creating directory %s: could not open", out_dir.c_str());
            return false;
        }
    }

    return true;
}

uint32_t validateAndConvertNumericArgument(const std::string& argument, const std::string& error_msg)
{
    uint32_t number = UINT32_MAX;
    if (!argument.empty())
    {
        size_t charsProcessed = 0;
        number                = std::stoi(argument, &charsProcessed);
        if (charsProcessed != argument.length())
        {
            GFXRECON_LOG_ERROR(error_msg.c_str());
            gfxrecon::util::Log::Release();
            exit(-1);
        }
    }

    return number;
}

static bool androidDirsAreExists(const std::string& android_dir)
{
    if (!gfxrecon::util::filepath::IsDirectory(android_dir))
    {
        return false;
    }

    std::string dir_path = gfxrecon::util::filepath::Join(android_dir, path_vulkanmain);
    if (!gfxrecon::util::filepath::IsDirectory(dir_path))
    {
        return false;
    }

    dir_path = gfxrecon::util::filepath::Join(android_dir, path_assets);
    if (!gfxrecon::util::filepath::IsDirectory(dir_path))
    {
        return false;
    }

    return true;
}

static int copy_file(const char* src_path, const struct stat* sb, int typeflag, struct FTW* ftwbuf)
{
    // Don't copy the directory itself.
    if (ftwbuf->level == 0)
    {
        return 0;
    }

    std::string  file_name(src_path);
    const size_t src_root_found = file_name.find(android_template_root);
    if (src_root_found != std::string::npos)
    {
        // Get the path of the resource without the path of template directory.
        file_name.erase(src_root_found, src_root_found + android_template_root.size());
    }

    std::string dst_path = gfxrecon::util::filepath::Join(output_dirname, file_name);
    switch (typeflag)
    {
        case FTW_D:
        {
            mkdir(dst_path.c_str(), sb->st_mode);
            break;
        }
        case FTW_F:
        {
            std::ifstream src(src_path, std::ios::binary);
            std::ofstream dst(dst_path, std::ios::binary);
            dst << src.rdbuf();
            break;
        }
    }

    if (!gfxrecon::util::filepath::Exists(dst_path))
    {
        GFXRECON_LOG_ERROR("Template file couldn't be created: %s", dst_path.c_str());
    }

    return 0;
}

static std::string getOutputFilename(const std::string& capture_file)
{
    std::string output_filename(capture_file);

    // Get the basename of the capture file.
    const size_t last_slash_idx = output_filename.find_last_of("\\/");
    if (last_slash_idx != std::string::npos)
    {
        output_filename.erase(0, last_slash_idx + 1);
    }

    // Replace the .gfxr extension to .cpp.
    size_t suffix_pos = output_filename.find(GFXRECON_FILE_EXTENSION);
    if (suffix_pos != std::string::npos)
    {
        output_filename = output_filename.substr(0, suffix_pos) + ".cpp";
    }

    return gfxrecon::util::filepath::Join(output_dirname, output_filename);
}

bool PreProcessCapture(gfxrecon::decode::VulkanCppPreProcessConsumer& cpp_consumer,
                       const std::string&                             input_filename,
                       const uint32_t                                 frame_limit)
{
    gfxrecon::decode::FileProcessor file_processor;
    gfxrecon::decode::VulkanDecoder decoder;

    if (!file_processor.Initialize(input_filename))
    {
        GFXRECON_LOG_ERROR("Initialization of file processor has failed");
        return false;
    }

    if (!cpp_consumer.Initialize())
    {
        GFXRECON_LOG_ERROR("Initialization of cpp pre process consumer has failed");
        return false;
    }

    file_processor.AddDecoder(&decoder);
    decoder.AddConsumer(&cpp_consumer);

    bool success;

    do
    {
        success = file_processor.ProcessNextFrame();
    } while (success && file_processor.GetCurrentFrameNumber() <= frame_limit);

    return (file_processor.GetErrorState() == file_processor.kErrorNone);
}

bool ProcessCapture(gfxrecon::decode::VulkanCppConsumer& cpp_consumer,
                    const std::string&                   input_filename,
                    const std::string&                   output_filename,
                    const std::string&                   target_platform,
                    const uint32_t                       frame_limit)
{
    gfxrecon::decode::FileProcessor file_processor;
    gfxrecon::decode::VulkanDecoder decoder;

    if (!file_processor.Initialize(input_filename))
    {
        GFXRECON_LOG_ERROR("Initialization of file processor has failed");
        return false;
    }

    if (!cpp_consumer.Initialize(output_filename, target_platform, output_dirname))
    {
        GFXRECON_LOG_ERROR("Initialization of cpp consumer has failed");
        return false;
    }

    file_processor.AddDecoder(&decoder);
    decoder.AddConsumer(&cpp_consumer);

    bool success;

    do
    {
        success = file_processor.ProcessNextFrame();
    } while (success && file_processor.GetCurrentFrameNumber() <= frame_limit);

    return (file_processor.GetErrorState() == file_processor.kErrorNone);
}

int main(int argc, const char** argv)
{
    std::string                    input_filename;
    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    gfxrecon::util::Log::Init();

    // --output
    output_dirname = arg_parser.GetArgumentValue(kCppOutputShortOption);
    if (output_dirname.size() == 0) {
        output_dirname = arg_parser.GetArgumentValue(kCppOutputLongOption);
    }

    // --target
    std::string target_platform = GetCppTargetPlatform(arg_parser);

    // --android-template
    android_template_root = arg_parser.GetArgumentValue(kCppAndroidTemplateOption);

    // --command-limit
    uint32_t command_limit = 0;
    std::string command_limit_argument = arg_parser.GetArgumentValue(kCppOutputCommandLimitShortOption);
    if (command_limit_argument.size() != 0)
    {
        command_limit_argument = arg_parser.GetArgumentValue(kCppOutputCommandLimitLongOption);
        command_limit = validateAndConvertNumericArgument(command_limit_argument, "The given command limit is invalid!");
    }

    // --frame-limit
    std::string frame_limit_argument = arg_parser.GetArgumentValue(kCppOutputFrameLimitShortOption);
    if (frame_limit_argument.size() == 0) {
        frame_limit_argument = arg_parser.GetArgumentValue(kCppOutputFrameLimitLongOption);
    }

    // --max-width
    std::string max_width_argument = arg_parser.GetArgumentValue(kCppOutputMaxWindowWidthLongOption);

    // --max-height
    std::string max_height_argument = arg_parser.GetArgumentValue(kCppOutputMaxWindowHeightLongOption);

    // Remove the consecutive path separators from the end of the path.
    if (target_platform == "android") {
        while (android_template_root.back() == kPathSep)
        {
            android_template_root.pop_back();
        }
    }

    if (CheckOptionPrintVersion(argv[0], arg_parser) || CheckOptionPrintUsage(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else if (!outputDirectoryIsValid(output_dirname))
    {
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else if (target_platform == "android" && !androidDirsAreExists(android_template_root))
    {
        GFXRECON_LOG_ERROR("The specified path to --android-template option is missing or wrong!");
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        input_filename                                       = positional_arguments[0];
    }

    // Determine the output files.
    std::string output_filename;
    if (target_platform == "android")
    {
        // The maximum number of directories that nftw() will hold open simultaneously.
        const int max_open_fd = 20;

        // Copy the android template into the output dir.
        if (nftw(android_template_root.c_str(), copy_file, max_open_fd, 0) != 0)
        {
            GFXRECON_LOG_ERROR("Error during copying of android template files!");
        }

        output_filename = gfxrecon::util::filepath::Join(output_dirname, path_vulkanmain + "VulkanMain.cpp");
        output_dirname  = gfxrecon::util::filepath::Join(output_dirname, path_assets);
    }
    else // target_platform == "xcb"
    {
        output_filename = getOutputFilename(input_filename);
    }

    uint32_t frame_limit = validateAndConvertNumericArgument(frame_limit_argument, "The given frame limit is invalid!");
    uint32_t max_window_width =
        validateAndConvertNumericArgument(max_width_argument, "The given max width is invalid!");
    uint32_t max_window_height =
        validateAndConvertNumericArgument(max_height_argument, "The given max height is invalid!");

    gfxrecon::decode::VulkanCppResourceTracker    resource_tracker;
    gfxrecon::decode::VulkanCppPreProcessConsumer pre_process_cpp_consumer;
    gfxrecon::decode::VulkanCppConsumer           cpp_consumer;
    bool                                          result;

    pre_process_cpp_consumer.AddResourceTracker(resource_tracker);
    cpp_consumer.AddResourceTracker(resource_tracker);

    // On non-Android platforms, let's not split frames if we can avoid it
    if (command_limit > 0) {
        cpp_consumer.SetMaxCommandLimit(command_limit);
        pre_process_cpp_consumer.SetMaxCommandLimit(command_limit);
    }

    int64_t process_start_time         = gfxrecon::util::datetime::GetTimestamp();
    result                             = PreProcessCapture(pre_process_cpp_consumer, input_filename, frame_limit);
    int64_t  process_end_time          = gfxrecon::util::datetime::GetTimestamp();
    uint32_t pre_process_apicall_count = pre_process_cpp_consumer.GetCurrentApiCallNumber();
    if (result)
    {
        GFXRECON_LOG_INFO("Capture file pre processed %lu calls in %lf seconds",
                          pre_process_apicall_count,
                          gfxrecon::util::datetime::ConvertTimestampToSeconds(
                              gfxrecon::util::datetime::DiffTimestamps(process_start_time, process_end_time)));
    }
    else
    {
        GFXRECON_LOG_INFO("Failed to process capture file")
    }

    cpp_consumer.SetMemoryResourceMap(pre_process_cpp_consumer.GetMemoryImageMappings());
    cpp_consumer.SetWindowSize(pre_process_cpp_consumer.GetCaptureWindowWidth(),
                               pre_process_cpp_consumer.GetCaptureWindowHeight());

    uint32_t window_width  = pre_process_cpp_consumer.GetCaptureWindowWidth();
    uint32_t window_height = pre_process_cpp_consumer.GetCaptureWindowHeight();

    if (window_width > max_window_width)
    {
        GFXRECON_LOG_INFO("Window width (%lu) exceeds the given maximum value (%lu), falling back to maximum value.",
                          window_width,
                          max_window_width);
        window_width = max_window_width;
    }

    if (window_height > max_window_height)
    {
        GFXRECON_LOG_INFO("Window height (%lu) exceeds the given maximum value (%lu), falling back to maximum value.",
                          window_height,
                          max_window_height);
        window_height = max_window_height;
    }

    cpp_consumer.SetWindowSize(window_width, window_height);
    resource_tracker.CalculateGlobalVariables();

    process_start_time = gfxrecon::util::datetime::GetTimestamp();
    result             = ProcessCapture(cpp_consumer, input_filename, output_filename, target_platform, frame_limit);
    process_end_time   = gfxrecon::util::datetime::GetTimestamp();
    uint32_t cpp_consumer_apicall_count = cpp_consumer.GetCurrentApiCallNumber();
    if (result)
    {
        GFXRECON_LOG_INFO("Capture file processed %lu calls in %lf seconds",
                          cpp_consumer_apicall_count,
                          gfxrecon::util::datetime::ConvertTimestampToSeconds(
                              gfxrecon::util::datetime::DiffTimestamps(process_start_time, process_end_time)));
    }
    else
    {
        GFXRECON_LOG_INFO("Failed to process capture file")
    }

    if (pre_process_apicall_count != cpp_consumer_apicall_count)
    {
        GFXRECON_LOG_WARNING("Pre process consumer and cpp consumer apicall count mismatch: %lu != %lu",
                             pre_process_apicall_count,
                             cpp_consumer_apicall_count);
    }

    gfxrecon::util::Log::Release();
    return 0;
}
