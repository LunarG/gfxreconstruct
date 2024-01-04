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
#ifdef __ANDROID__
#include <ftw.h>
#else
#include <filesystem>
#endif
#include <util/date_time.h>

#include "project_version.h"

#include "decode/file_processor.h"
#include "decode/vulkan_cpp_utilities.h"
#include "format/format.h"
#include "generated/generated_vulkan_cpp_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/argument_parser.h"
#include "util/file_path.h"
#include "util/logging.h"

#include "vulkan/vulkan_core.h"

struct CommandLineArgument
{
    bool       required;
    bool       expects_argument;
    const char short_option[8];
    const char long_option[32];
    const char additional[16];
    const char restrictions[64];
    const char description[512];
};

CommandLineArgument g_help_argument = {
    false, false, "-h", "--help", "\t\t\t\t\t", "", "Print usage information and exit."
};
CommandLineArgument g_version_argument = {
    false, false, "-v", "--version", "\t\t\t\t", "", "Print version information and exit."
};
CommandLineArgument g_android_template_argument = {
    false,
    true,
    "-a",
    "--android-template",
    "<dir>\t\t\t",
    " (Only valid for Android targets)",
    "Directory path containing the Android application template files."
};
CommandLineArgument g_target_argument = { true,
                                          true,
                                          "-t",
                                          "--target",
                                          "<platform>\t\t\t",
#if defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__) || defined(__MINGW64__)
                                          " (Defaults to win32)",
#elif defined(__APPLE__)
                                          " (Defaults to macos)",
#elif defined(__ANDROID__)
                                          " (Defaults to android)",
#else
                                          " (Defaults to xcb)",
#endif
                                          "The type of platform for the intended target Vulkan source.\n"
                                          "\t\t\t\t\t\t\t  Available Platforms:\n"
                                          "\t\t\t\t\t\t\t     android    Generate for Android.\n"
                                          "\t\t\t\t\t\t\t     xcb        Generate for XCB." };
CommandLineArgument g_output_argument = {
    true, true, "-o", "--output", "<dir>\t\t\t\t", "", "Directory path where the output will be generated into."
};
CommandLineArgument g_max_window_dimensions_argument = {
    false, true, "-d", "--max-window-dimensions", "<width,height>\t", "", "Maximum dimensions of the created window."
};
CommandLineArgument g_frame_limit_argument = {
    false,
    true,
    "-f",
    "--frame-limit",
    "<number>\t\t\t",
    "",
    "Maximum number of frames to convert to C++ code from the capture file."
};
CommandLineArgument g_command_limit_argument = {
    false,
    true,
    "-c",
    "--command-limit",
    "<number>\t\t\t",
    " (Defaults to 1000)",
    "Maximum number of API commands recorded per C++ file.  The intent is to"
    " adjust compilation load per file."
};

CommandLineArgument g_captured_swapchain_argument = {
    false,
    false,
    "-s",
    "--captured-swapchain",
    "\t\t\t\t",
    "",
    "Use the swapchain as it was captured during toCpp replay instead of using the \"Virtual Swapchain\" paths."
};

std::vector<CommandLineArgument> g_argument_list;

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
    // We can just check for the short option because the argument parser will assign even
    // the long option to either one for easier detecting.
    if (arg_parser.IsOptionSet(g_version_argument.short_option))
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
    GFXRECON_WRITE_CONSOLE("  %s [arguments] <capture_file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("     <capture_file> must be a valid GFXReconstruct capture file\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("     Required Arguments:");

    for (auto& argument : g_argument_list)
    {
        if (argument.required)
        {
            GFXRECON_WRITE_CONSOLE("\t[%s | %s] %s %s%s",
                                   argument.short_option,
                                   argument.long_option,
                                   argument.additional,
                                   argument.description,
                                   argument.restrictions);
        }
    }

    GFXRECON_WRITE_CONSOLE("\n     Optional Arguments:");
    for (auto& argument : g_argument_list)
    {
        if (!argument.required)
        {
            GFXRECON_WRITE_CONSOLE("\t[%s | %s] %s %s%s",
                                   argument.short_option,
                                   argument.long_option,
                                   argument.additional,
                                   argument.description,
                                   argument.restrictions);
        }
    }
}

static bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    // We can just check for the short option because the argument parser will assign even
    // the long option to either one for easier detecting.
    if (arg_parser.IsOptionSet(g_help_argument.short_option))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

static gfxrecon::decode::GfxToCppPlatform GetCppTargetPlatform(const gfxrecon::util::ArgumentParser& arg_parser)
{
    gfxrecon::decode::GfxToCppPlatform platform_enum = gfxrecon::decode::GfxToCppPlatform::PLATFORM_COUNT;
    std::string                        platform;

    // We can just check for the short argument because the argument parser will assign even
    // the long argument to either one for easier detecting.
    if (arg_parser.IsArgumentSet(g_target_argument.short_option))
    {
        platform = arg_parser.GetArgumentValue(g_target_argument.short_option);
        printf("Platform set to %s\n", platform.c_str());
    }

    if (platform.length() > 0)
    {
        // Choose the appropriate platform
        const uint32_t max_count = static_cast<uint32_t>(sizeof(gfxrecon::decode::kValidTargetPlatforms) /
                                                         sizeof(gfxrecon::decode::PlatformTargets));
        for (uint32_t ii = 0; ii < max_count; ++ii)
        {
            if (gfxrecon::util::platform::StringCompare(gfxrecon::decode::kValidTargetPlatforms[ii].platformName,
                                                        platform.c_str()) == 0)
            {
                platform_enum = gfxrecon::decode::kValidTargetPlatforms[ii].platformEnum;
                break;
            }
        }
    }

    // If no platform was found, default to a given one for the platform
    if (platform_enum >= gfxrecon::decode::GfxToCppPlatform::PLATFORM_COUNT)
    {
#if defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__) || defined(__MINGW64__)
        GFXRECON_LOG_INFO("Target platform is not specified or invalid, fall back to 'win32'.");
        platform_enum = gfxrecon::decode::GfxToCppPlatform::PLATFORM_WIN32;
#elif defined(__APPLE__)
        GFXRECON_LOG_INFO("Target platform is not specified or invalid, fall back to 'macos'.");
        platform_enum = gfxrecon::decode::GfxToCppPlatform::PLATFORM_MACOS;
#elif defined(__ANDROID__)
        GFXRECON_LOG_INFO("Target platform is not specified or invalid, fall back to 'android'.");
        platform_enum = gfxrecon::decode::GfxToCppPlatform::PLATFORM_ANDROID;
#else
        GFXRECON_LOG_INFO("Target platform is not specified or invalid, fall back to 'xcb'.");
        platform_enum = gfxrecon::decode::GfxToCppPlatform::PLATFORM_XCB;
#endif
    }

    return platform_enum;
}

static bool OutputDirectoryIsValid(std::string& out_dir)
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

void ValidateAndConvertDimensionArgument(const std::string& argument, std::vector<uint32_t>& dimensions)
{
    if (!argument.empty())
    {
        std::stringstream argument_stream(argument);
        std::string       str;
        while (std::getline(argument_stream, str, ','))
        {
            size_t processed = 0;
            dimensions.push_back(std::stoi(str, &processed));
        }
    }
}

uint32_t ValidateAndConvertNumericArgument(const std::string& argument, const std::string& error_msg)
{
    uint32_t number = UINT32_MAX;
    if (!argument.empty())
    {
        size_t processed = 0;
        number           = std::stoi(argument, &processed);
        if (processed != argument.length())
        {
            GFXRECON_LOG_ERROR(error_msg.c_str());
            gfxrecon::util::Log::Release();
            exit(-1);
        }
    }

    return number;
}

static bool AndroidDirsExist(const std::string& android_dir)
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

#ifdef __ANDROID__
static int CopyDirectoryContents(const char* src_path, const struct stat* sb, int typeflag, struct FTW* ftwbuf)
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
#endif // __ANDROID__

static std::string GetOutputFilename(const std::string& capture_file)
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

bool ProcessCapture(gfxrecon::decode::VulkanCppConsumer&      cpp_consumer,
                    const std::string&                        input_filename,
                    const std::string&                        output_filename,
                    const gfxrecon::decode::GfxToCppPlatform& target_platform,
                    const uint32_t                            frame_limit)
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
    std::string input_filename;

    // Generate the entire list of valid arguments/options
    std::string arguments_string;
    std::string options_string;
    g_argument_list.push_back(g_help_argument);
    g_argument_list.push_back(g_version_argument);
    g_argument_list.push_back(g_target_argument);
    g_argument_list.push_back(g_output_argument);
    g_argument_list.push_back(g_android_template_argument);
    g_argument_list.push_back(g_max_window_dimensions_argument);
    g_argument_list.push_back(g_frame_limit_argument);
    g_argument_list.push_back(g_command_limit_argument);
    g_argument_list.push_back(g_captured_swapchain_argument);

    for (auto& argument : g_argument_list)
    {
        if (argument.expects_argument)
        {
            if (arguments_string.length() > 0)
            {
                arguments_string += ",";
            }
            arguments_string += argument.short_option + std::string("|") + argument.long_option;
        }
        else
        {
            if (options_string.length() > 0)
            {
                options_string += ",";
            }
            options_string += argument.short_option + std::string("|") + argument.long_option;
        }
    }
    gfxrecon::util::ArgumentParser arg_parser(argc, argv, options_string, arguments_string);

    gfxrecon::util::Log::Init();

    // --output
    output_dirname = arg_parser.GetArgumentValue(g_output_argument.short_option);

    // --target
    gfxrecon::decode::GfxToCppPlatform target_platform = GetCppTargetPlatform(arg_parser);

    // --android-template
    android_template_root = arg_parser.GetArgumentValue(g_android_template_argument.short_option);

    // --command-limit
    uint32_t    command_limit          = 0;
    std::string command_limit_argument = arg_parser.GetArgumentValue(g_command_limit_argument.short_option);
    if (command_limit_argument.size() != 0)
    {
        command_limit =
            ValidateAndConvertNumericArgument(command_limit_argument, "The given command limit is invalid!");
    }

    // --frame-limit
    std::string frame_limit_argument = arg_parser.GetArgumentValue(g_frame_limit_argument.short_option);

    // --max-window-dimensions
    std::string max_dimensions_argument = arg_parser.GetArgumentValue(g_max_window_dimensions_argument.short_option);

    // Remove the consecutive path separators from the end of the path.
    if (target_platform == gfxrecon::decode::GfxToCppPlatform::PLATFORM_ANDROID)
    {
        while (android_template_root.back() == kPathSep)
        {
            android_template_root.pop_back();
        }
    }

    if (CheckOptionPrintVersion(argv[0], arg_parser))
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
    else if (!OutputDirectoryIsValid(output_dirname))
    {
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else if (target_platform == gfxrecon::decode::GfxToCppPlatform::PLATFORM_ANDROID &&
             !AndroidDirsExist(android_template_root))
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
    if (target_platform == gfxrecon::decode::GfxToCppPlatform::PLATFORM_ANDROID)
    {
        // The maximum number of directories that nftw() will hold open simultaneously.
        const int max_open_fd = 20;

        // Copy the android template into the output dir.
#ifdef __ANDROID__
        if (nftw(android_template_root.c_str(), CopyDirectoryContents, max_open_fd, 0) != 0)
        {
            GFXRECON_LOG_ERROR("Error during copying of android template files!");
        }
#else
        if (!gfxrecon::util::filepath::Exists(output_dirname))
        {
            GFXRECON_LOG_ERROR("Android template target directory was not found: %s", output_dirname.c_str());
        }
        else
        {
            const std::filesystem::copy_options copy_options =
                std::filesystem::copy_options::update_existing | std::filesystem::copy_options::recursive;
            std::filesystem::copy(android_template_root.c_str(), output_dirname, copy_options);
        }
#endif // __ANDROID__

        output_filename = gfxrecon::util::filepath::Join(output_dirname, path_vulkanmain + "VulkanMain.cpp");
        output_dirname  = gfxrecon::util::filepath::Join(output_dirname, path_assets);
    }
    else // target_platform == gfxrecon::decode::GfxToCppPlatform::PLATFORM_XCB
    {
        output_filename = GetOutputFilename(input_filename);
    }

    uint32_t frame_limit = ValidateAndConvertNumericArgument(frame_limit_argument, "The given frame limit is invalid!");

    std::vector<uint32_t> dimensions;
    ValidateAndConvertDimensionArgument(max_dimensions_argument, dimensions);

    gfxrecon::decode::VulkanCppResourceTracker resource_tracker;
    gfxrecon::decode::VulkanCppConsumer        cpp_consumer;
    bool                                       result;

    cpp_consumer.AddResourceTracker(resource_tracker);

    // --captured-swapchain
    if (arg_parser.IsOptionSet(g_captured_swapchain_argument.short_option))
    {
        cpp_consumer.DisableVirtualSwapchain();
    }

    // On non-Android platforms, let's not split frames if we can avoid it
    if (command_limit > 0)
    {
        cpp_consumer.SetMaxCommandLimit(command_limit);
    }

    int64_t process_start_time = gfxrecon::util::datetime::GetTimestamp();
    result = ProcessCapture(cpp_consumer, input_filename, output_filename, target_platform, frame_limit);
    int64_t  process_end_time           = gfxrecon::util::datetime::GetTimestamp();
    uint32_t cpp_consumer_apicall_count = cpp_consumer.GetCurrentApiCallNumber();
    if (result)
    {
        GFXRECON_LOG_INFO("Capture file processed %u calls in %lf seconds",
                          cpp_consumer_apicall_count,
                          gfxrecon::util::datetime::ConvertTimestampToSeconds(
                              gfxrecon::util::datetime::DiffTimestamps(process_start_time, process_end_time)));
    }
    else
    {
        GFXRECON_LOG_INFO("Failed to process capture file")
    }

    gfxrecon::util::Log::Release();
    return 0;
}
