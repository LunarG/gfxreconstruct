/*
** Copyright (c) 2019-2020 LunarG, Inc.
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

#include "project_version.h"

#if defined(WIN32)
#include "decode/dx_replay_options.h"
#endif
#include "decode/file_processor.h"
#include "decode/vulkan_default_allocator.h"
#include "decode/vulkan_realign_allocator.h"
#include "decode/vulkan_rebind_allocator.h"
#include "decode/vulkan_remap_allocator.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_tracking_consumer.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"

#include "vulkan/vulkan_core.h"

#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#ifndef GFXRECON_REPLAY_SETTINGS_H
#define GFXRECON_REPLAY_SETTINGS_H

const char kApplicationName[] = "GFXReconstruct Replay";
const char kCaptureLayer[]    = "VK_LAYER_LUNARG_gfxreconstruct";

const char kHelpShortOption[]                  = "-h";
const char kHelpLongOption[]                   = "--help";
const char kVersionOption[]                    = "--version";
const char kNoDebugPopup[]                     = "--no-debug-popup";
const char kOverrideGpuArgument[]              = "--gpu";
const char kPausedOption[]                     = "--paused";
const char kPauseFrameArgument[]               = "--pause-frame";
const char kSkipFailedAllocationShortOption[]  = "--sfa";
const char kSkipFailedAllocationLongOption[]   = "--skip-failed-allocations";
const char kOmitPipelineCacheDataShortOption[] = "--opcd";
const char kOmitPipelineCacheDataLongOption[]  = "--omit-pipeline-cache-data";
const char kWsiArgument[]                      = "--wsi";
const char kSurfaceIndexArgument[]             = "--surface-index";
const char kMemoryPortabilityShortOption[]     = "-m";
const char kMemoryPortabilityLongOption[]      = "--memory-translation";
const char kSyncOption[]                       = "--sync";
const char kRemoveUnsupportedOption[]          = "--remove-unsupported";
const char kValidateOption[]                   = "--validate";
const char kShaderReplaceArgument[]            = "--replace-shaders";
const char kScreenshotAllOption[]              = "--screenshot-all";
const char kScreenshotRangeArgument[]          = "--screenshots";
const char kScreenshotFormatArgument[]         = "--screenshot-format";
const char kScreenshotDirArgument[]            = "--screenshot-dir";
const char kScreenshotFilePrefixArgument[]     = "--screenshot-prefix";
#if defined(WIN32)
const char kApiFamilyOption[] = "--api";
#endif

const char kOptions[] = "-h|--help,--version,--no-debug-popup,--paused,--sync,--sfa|--skip-failed-allocations,--"
                        "opcd|--omit-pipeline-cache-data,--remove-unsupported,--validate,--screenshot-all";
const char kArguments[] =
    "--gpu,--pause-frame,--wsi,--surface-index,-m|--memory-translation,--replace-shaders,--screenshots,--"
    "screenshot-format,--screenshot-dir,--screenshot-prefix"
#if defined(WIN32)
    ",--api"
#endif
    ;

enum class WsiPlatform
{
    kAuto,
    kWin32,
    kXlib,
    kXcb,
    kWayland
};

const char kWsiPlatformAuto[]    = "auto";
const char kWsiPlatformWin32[]   = "win32";
const char kWsiPlatformXlib[]    = "xlib";
const char kWsiPlatformXcb[]     = "xcb";
const char kWsiPlatformWayland[] = "wayland";

const char kMemoryTranslationNone[]    = "none";
const char kMemoryTranslationRemap[]   = "remap";
const char kMemoryTranslationRealign[] = "realign";
const char kMemoryTranslationRebind[]  = "rebind";

#if defined(WIN32)
const char kApiFamilyVulkan[] = "vulkan";
const char kApiFamilyD3D12[]  = "d3d12";
const char kApiFamilyAll[]    = "all";
#endif

const char kScreenshotFormatBmp[] = "bmp";

#if defined(__ANDROID__)
const char kDefaultScreenshotDir[] = "/sdcard";
#else
const char kDefaultScreenshotDir[] = "";
#endif

static void ProcessDisableDebugPopup(const gfxrecon::util::ArgumentParser& arg_parser)
{
#if defined(WIN32) && defined(_DEBUG)
    if (arg_parser.IsOptionSet(kNoDebugPopup))
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    }
#endif
}

static void CheckActiveLayers(const std::string& list)
{
    if (!list.empty())
    {
        // Check for the presence of the layer name in the list of active layers.
        size_t start = list.find(kCaptureLayer);

        if (start != std::string::npos)
        {
            size_t end         = start + gfxrecon::util::platform::StringLength(kCaptureLayer);
            bool   match_start = false;
            bool   match_end   = false;

            // For an exact match, the start of the layer name is either at the start of the list or comes after a path
            // separator.
            if ((start == 0) || ((list[start - 1] == ';') || (list[start - 1] == ':')))
            {
                match_start = true;
            }

            // For an exact match, the end of the layer name is either at the end of the list or comes before a path
            // separator.
            if ((list.length() == end) || ((list[end] == ';') || (list[end] == ':')))
            {
                match_end = true;
            }

            if (match_start && match_end)
            {
                GFXRECON_LOG_WARNING("Replay tool has detected that the capture layer is enabled");
            }
        }
    }
}

static gfxrecon::decode::VulkanResourceAllocator* CreateDefaultAllocator()
{
    return new gfxrecon::decode::VulkanDefaultAllocator(
        "Try replay with the '-m remap' or '-m rebind' options to enable memory translation.");
}

static gfxrecon::decode::VulkanResourceAllocator* CreateRemapAllocator()
{
    return new gfxrecon::decode::VulkanRemapAllocator(
        "Try replay with the '-m rebind' option to enable advanced memory translation.");
}

static gfxrecon::decode::VulkanResourceAllocator* CreateRebindAllocator()
{
    return new gfxrecon::decode::VulkanRebindAllocator();
}

static gfxrecon::decode::CreateResourceAllocator
InitRealignAllocatorCreateFunc(const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    // Enable first pass of replay to generate resource tracking information.
    GFXRECON_WRITE_CONSOLE("First pass of replay resource tracking for realign memory portability mode. This may take "
                           "some time. Please wait...");

    gfxrecon::decode::FileProcessor file_processor_resource_tracking;
    gfxrecon::decode::VulkanDecoder decoder;

    auto resource_tracking_consumer =
        new gfxrecon::decode::VulkanResourceTrackingConsumer(replay_options, tracked_object_info_table);

    if (file_processor_resource_tracking.Initialize(filename))
    {
        decoder.AddConsumer(resource_tracking_consumer);
        file_processor_resource_tracking.AddDecoder(&decoder);
        file_processor_resource_tracking.ProcessAllFrames();
        file_processor_resource_tracking.RemoveDecoder(&decoder);
        decoder.RemoveConsumer(resource_tracking_consumer);
    }

    // Sort the bound resources according to the binding offsets.
    resource_tracking_consumer->SortMemoriesBoundResourcesByOffset();

    // calculate the replay binding offset of the bound resources and replay memory allocation size
    resource_tracking_consumer->CalculateReplayBindingOffsetAndMemoryAllocationSize();

    GFXRECON_WRITE_CONSOLE("First pass of replay resource tracking done.");

    return [tracked_object_info_table]() -> gfxrecon::decode::VulkanResourceAllocator* {
        return new gfxrecon::decode::VulkanRealignAllocator(
            tracked_object_info_table, "Try replay with the '-m rebind' option to enable advanced memory translation.");
    };
}

static uint32_t GetPauseFrame(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    pause_frame = 0;
    const auto& value       = arg_parser.GetArgumentValue(kPauseFrameArgument);

    if (arg_parser.IsOptionSet(kPausedOption))
    {
        pause_frame = 1;
    }
    else if (!value.empty())
    {
        pause_frame = std::stoi(value);
    }

    return pause_frame;
}

static WsiPlatform GetWsiPlatform(const gfxrecon::util::ArgumentParser& arg_parser)
{
    WsiPlatform wsi_platform = WsiPlatform::kAuto;
    const auto& value        = arg_parser.GetArgumentValue(kWsiArgument);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformAuto, value.c_str()) == 0)
        {
            wsi_platform = WsiPlatform::kAuto;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformWin32, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_WIN32_KHR)
            wsi_platform = WsiPlatform::kWin32;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformXlib, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_XLIB_KHR)
            wsi_platform = WsiPlatform::kXlib;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option %s, which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformXcb, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_XCB_KHR)
            wsi_platform = WsiPlatform::kXcb;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformWayland, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
            wsi_platform = WsiPlatform::kWayland;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized wsi option \"%s\"", value.c_str());
        }
    }

    return wsi_platform;
}

static std::string GetWsiArgString()
{
    std::string wsi_args = kWsiPlatformAuto;
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformWin32;
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformXlib;
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformXcb;
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformWayland;
#endif
    return wsi_args;
}

static gfxrecon::decode::ScreenshotFormat GetScreenshotFormat(const gfxrecon::util::ArgumentParser& arg_parser)
{
    gfxrecon::decode::ScreenshotFormat format = gfxrecon::decode::ScreenshotFormat::kBmp;
    const auto&                        value  = arg_parser.GetArgumentValue(kScreenshotFormatArgument);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kScreenshotFormatBmp, value.c_str()) == 0)
        {
            format = gfxrecon::decode::ScreenshotFormat::kBmp;
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized screenshot format option \"%s\"", value.c_str());
        }
    }

    return format;
}

static std::string GetScreenshotDir(const gfxrecon::util::ArgumentParser& arg_parser)
{
    const auto& value = arg_parser.GetArgumentValue(kScreenshotDirArgument);

    if (!value.empty())
    {
        return value;
    }

    return kDefaultScreenshotDir;
}

static std::vector<gfxrecon::decode::ScreenshotRange>
GetScreenshotRanges(const gfxrecon::util::ArgumentParser& arg_parser)
{
    std::vector<gfxrecon::decode::ScreenshotRange> ranges;

    if (arg_parser.IsOptionSet(kScreenshotAllOption))
    {
        gfxrecon::decode::ScreenshotRange screenshot_range;
        screenshot_range.first = 1;
        screenshot_range.last  = std::numeric_limits<uint32_t>::max();
        ranges.emplace_back(std::move(screenshot_range));
    }
    else
    {
        const auto& value = arg_parser.GetArgumentValue(kScreenshotRangeArgument);
        if (!value.empty())
        {
            std::istringstream value_input;
            value_input.str(value);

            for (std::string range; std::getline(value_input, range, ',');)
            {
                if (range.empty() || (std::count(range.begin(), range.end(), '-') > 1))
                {
                    GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\"", range.c_str());
                    continue;
                }

                // Remove whitespace.
                range.erase(std::remove_if(range.begin(), range.end(), ::isspace), range.end());

                // Split string on '-' delimiter.
                bool                     invalid = false;
                std::vector<std::string> values;
                std::istringstream       range_input;
                range_input.str(range);

                for (std::string value; std::getline(range_input, value, '-');)
                {
                    if (value.empty())
                    {
                        break;
                    }

                    // Check that the value string only contains numbers.
                    size_t count = std::count_if(value.begin(), value.end(), ::isdigit);
                    if (count == value.length())
                    {
                        values.push_back(value);
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING(
                            "Ignoring invalid screenshot frame range \"%s\", which contains non-numeric values",
                            range.c_str());
                        invalid = true;
                        break;
                    }
                }

                if (!invalid)
                {
                    gfxrecon::decode::ScreenshotRange screenshot_range;

                    if (values.size() == 1)
                    {
                        if (std::count(range.begin(), range.end(), '-') == 0)
                        {
                            screenshot_range.first = std::stoi(values[0]);
                            screenshot_range.last  = screenshot_range.first;
                        }
                        else
                        {
                            GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\"", range.c_str());
                            continue;
                        }
                    }
                    else if (values.size() == 2)
                    {
                        screenshot_range.first = std::stoi(values[0]);
                        screenshot_range.last  = std::stoi(values[1]);
                        if (screenshot_range.first > screenshot_range.last)
                        {
                            GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\", where first frame is "
                                                 "greater than last frame",
                                                 range.c_str());
                            continue;
                        }
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\"", range.c_str());
                        continue;
                    }

                    // Check for invalid start frame of 0.
                    if (screenshot_range.first == 0)
                    {
                        GFXRECON_LOG_WARNING(
                            "Ignoring invalid screenshot frame range \"%s\", with first frame equal to zero",
                            range.c_str());
                        continue;
                    }

                    uint32_t next_allowed = 0;

                    // Check that first frame is outside the bounds of the previous range.
                    if (!ranges.empty())
                    {
                        // The number of the frame after the last frame of the last range.
                        next_allowed = ranges.back().last + 1;
                    }

                    if (screenshot_range.first >= next_allowed)
                    {
                        ranges.emplace_back(std::move(screenshot_range));
                    }
                    else
                    {
                        const auto& back = ranges.back();
                        GFXRECON_LOG_WARNING("Ignoring invalid screenshot frame range \"%s\", "
                                             "where start frame precedes the end of the previous range \"%u-%u\"",
                                             range.c_str(),
                                             back.first,
                                             back.last);
                    }
                }
            }
        }
    }

    return ranges;
}

static gfxrecon::decode::CreateResourceAllocator
GetCreateResourceAllocatorFunc(const gfxrecon::util::ArgumentParser&           arg_parser,
                               const std::string&                              filename,
                               const gfxrecon::decode::VulkanReplayOptions&    replay_options,
                               gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::CreateResourceAllocator func  = CreateDefaultAllocator;
    const auto&                               value = arg_parser.GetArgumentValue(kMemoryPortabilityShortOption);

    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRebind, value.c_str()) == 0)
        {
            func = CreateRebindAllocator;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRemap, value.c_str()) == 0)
        {
            func = CreateRemapAllocator;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationRealign, value.c_str()) == 0)
        {
            func = InitRealignAllocatorCreateFunc(filename, replay_options, tracked_object_info_table);
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kMemoryTranslationNone, value.c_str()) != 0)
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized memory translation option \"%s\"", value.c_str());
        }
    }

    return func;
}

#if defined(WIN32)
static bool IsApiFamilyIdEnabled(const gfxrecon::util::ArgumentParser& arg_parser, gfxrecon::format::ApiFamilyId api)
{
    const std::string& value = arg_parser.GetArgumentValue(kApiFamilyOption);

    // If the --api argument was specified, parse the option.
    if (!value.empty())
    {
        if (gfxrecon::util::platform::StringCompareNoCase(kApiFamilyAll, value.c_str()) == 0)
        {
            return true;
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kApiFamilyVulkan, value.c_str()) == 0)
        {
            return (api == gfxrecon::format::ApiFamilyId::ApiFamily_Vulkan);
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kApiFamilyD3D12, value.c_str()) == 0)
        {
            return (api == gfxrecon::format::ApiFamilyId::ApiFamily_D3D12);
        }
        else
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized API option \"%s\"", value.c_str());
            return true;
        }
    }
    // If the --api argument was not specified, default so that all APIs are enabled.
    else
    {
        return true;
    }
}
#endif

static void GetReplayOptions(gfxrecon::decode::ReplayOptions& options, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kValidateOption))
    {
        options.enable_validation_layer = true;
    }

    if (arg_parser.IsOptionSet(kSyncOption))
    {
        options.sync_queue_submissions = true;
    }
}

static gfxrecon::decode::VulkanReplayOptions
GetVulkanReplayOptions(const gfxrecon::util::ArgumentParser&           arg_parser,
                       const std::string&                              filename,
                       gfxrecon::decode::VulkanTrackedObjectInfoTable* tracked_object_info_table)
{
    gfxrecon::decode::VulkanReplayOptions replay_options;
    GetReplayOptions(replay_options, arg_parser);

#if defined(WIN32)
    replay_options.enable_vulkan = IsApiFamilyIdEnabled(arg_parser, gfxrecon::format::ApiFamily_Vulkan);
#else
    replay_options.enable_vulkan = true;
#endif

    const auto& override_gpu = arg_parser.GetArgumentValue(kOverrideGpuArgument);
    if (!override_gpu.empty())
    {
        replay_options.override_gpu_index = std::stoi(override_gpu);
    }

    if (arg_parser.IsOptionSet(kRemoveUnsupportedOption))
    {
        replay_options.remove_unsupported_features = true;
    }

    if (arg_parser.IsOptionSet(kSkipFailedAllocationLongOption) ||
        arg_parser.IsOptionSet(kSkipFailedAllocationShortOption))
    {
        replay_options.skip_failed_allocations = true;
    }

    if (arg_parser.IsOptionSet(kOmitPipelineCacheDataLongOption) ||
        arg_parser.IsOptionSet(kOmitPipelineCacheDataShortOption))
    {
        replay_options.omit_pipeline_cache_data = true;
    }

    replay_options.replace_dir = arg_parser.GetArgumentValue(kShaderReplaceArgument);
    replay_options.create_resource_allocator =
        GetCreateResourceAllocatorFunc(arg_parser, filename, replay_options, tracked_object_info_table);

    replay_options.screenshot_ranges      = GetScreenshotRanges(arg_parser);
    replay_options.screenshot_format      = GetScreenshotFormat(arg_parser);
    replay_options.screenshot_dir         = GetScreenshotDir(arg_parser);
    replay_options.screenshot_file_prefix = arg_parser.GetArgumentValue(kScreenshotFilePrefixArgument);

    std::string surface_index = arg_parser.GetArgumentValue(kSurfaceIndexArgument);
    if (!surface_index.empty())
    {
        replay_options.surface_index = std::stoi(surface_index);
    }

    return replay_options;
}

#if defined(WIN32)
static gfxrecon::decode::DxReplayOptions GetDxReplayOptions(const gfxrecon::util::ArgumentParser& arg_parser)
{
    gfxrecon::decode::DxReplayOptions replay_options;
    GetReplayOptions(replay_options, arg_parser);

    replay_options.enable_d3d12 = IsApiFamilyIdEnabled(arg_parser, gfxrecon::format::ApiFamily_D3D12);

    return replay_options;
}
#endif

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

    GFXRECON_WRITE_CONSOLE("\n%s - A tool to replay GFXReconstruct capture files.\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s\t[-h | --help] [--version] [--gpu <index>]", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t\t\t[--pause-frame <N>] [--paused] [--sync] [--screenshot-all]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshots <N1(-N2),...>] [--screenshot-format <format>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--screenshot-dir <dir>] [--screenshot-prefix <file-prefix>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--sfa | --skip-failed-allocations] [--replace-shaders <dir>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--opcd | --omit-pipeline-cache-data] [--wsi <platform>]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[--surface-index <N>] [--remove-unsupported] [--validate]");
    GFXRECON_WRITE_CONSOLE("\t\t\t[-m <mode> | --memory-translation <mode>]");
#if defined(WIN32) && defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--api <api>] [--no-debug-popup] <file>\n");
#elif defined(WIN32)
    GFXRECON_WRITE_CONSOLE("\t\t\t[--api <api>] <file>\n");
#else
    GFXRECON_WRITE_CONSOLE("\t\t\t<file>\n");
#endif
    GFXRECON_WRITE_CONSOLE("Required arguments:");
    GFXRECON_WRITE_CONSOLE("  <file>\t\tPath to the capture file to replay.");
    GFXRECON_WRITE_CONSOLE("\nOptional arguments:");
    GFXRECON_WRITE_CONSOLE("  -h\t\t\tPrint usage information and exit (same as --help).");
    GFXRECON_WRITE_CONSOLE("  --version\t\tPrint version information and exit.");
    GFXRECON_WRITE_CONSOLE("  --gpu <index>\t\tUse the specified device for replay, where index");
    GFXRECON_WRITE_CONSOLE("          \t\tis the zero-based index to the array of physical devices");
    GFXRECON_WRITE_CONSOLE("          \t\treturned by vkEnumeratePhysicalDevices.  Replay may fail");
    GFXRECON_WRITE_CONSOLE("          \t\tif the specified device is not compatible with the");
    GFXRECON_WRITE_CONSOLE("          \t\toriginal capture devices.");
    GFXRECON_WRITE_CONSOLE("  --pause-frame <N>\tPause after replaying frame number N.");
    GFXRECON_WRITE_CONSOLE("  --paused\t\tPause after replaying the first frame (same");
    GFXRECON_WRITE_CONSOLE("          \t\tas --pause-frame 1).");
    GFXRECON_WRITE_CONSOLE("  --screenshot-all");
    GFXRECON_WRITE_CONSOLE("          \t\tGenerate screenshots for all frames.  When this");
    GFXRECON_WRITE_CONSOLE("          \t\toption is specified, --screenshots is ignored.");
    GFXRECON_WRITE_CONSOLE("  --screenshots <N1[-N2][,...]>");
    GFXRECON_WRITE_CONSOLE("          \t\tGenerate screenshots for the specified frames.");
    GFXRECON_WRITE_CONSOLE("          \t\tTarget frames are specified as a comma separated");
    GFXRECON_WRITE_CONSOLE("          \t\tlist of frame ranges.  A frame range can be specified");
    GFXRECON_WRITE_CONSOLE("          \t\tas a single value, to specify a single frame, or as");
    GFXRECON_WRITE_CONSOLE("          \t\ttwo hyphenated values, to specify the first and last");
    GFXRECON_WRITE_CONSOLE("          \t\tframes to process.  Frame ranges should be specified in");
    GFXRECON_WRITE_CONSOLE("          \t\tascending order and cannot overlap.  Note that frame");
    GFXRECON_WRITE_CONSOLE("          \t\tnumbering is 1-based (i.e. the first frame is frame 1).");
    GFXRECON_WRITE_CONSOLE("          \t\tExample: 200,301-305 will generate six screenshots.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-format <format>");
    GFXRECON_WRITE_CONSOLE("          \t\tImage file format to use for screenshot generation.");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable formats are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tBitmap file format.  This is the default format.",
                           kScreenshotFormatBmp);
    GFXRECON_WRITE_CONSOLE("  --screenshot-dir <dir>");
    GFXRECON_WRITE_CONSOLE("          \t\tDirectory to write screenshots.  Default is the current");
    GFXRECON_WRITE_CONSOLE("          \t\tworking directory.");
    GFXRECON_WRITE_CONSOLE("  --screenshot-prefix <file-prefix>");
    GFXRECON_WRITE_CONSOLE("          \t\tPrefix to apply to the screenshot file name.  Default is ");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot\", producing file names similar to");
    GFXRECON_WRITE_CONSOLE("          \t\t\"screenshot_frame8049.bmp\".");
    GFXRECON_WRITE_CONSOLE("  --sfa\t\t\tSkip vkAllocateMemory, vkAllocateCommandBuffers, and");
    GFXRECON_WRITE_CONSOLE("       \t\t\tvkAllocateDescriptorSets calls that failed during");
    GFXRECON_WRITE_CONSOLE("       \t\t\tcapture (same as --skip-failed-allocations).");
    GFXRECON_WRITE_CONSOLE("  --replace-shaders <dir> Replace the shader code in each CreateShaderModule");
    GFXRECON_WRITE_CONSOLE("       \t\t\twith the contents of the file <dir>/sh<handle_id> if found, where");
    GFXRECON_WRITE_CONSOLE("       \t\t\t<handle_id> is the handle id of the CreateShaderModule call.");
    GFXRECON_WRITE_CONSOLE("       \t\t\tSee gfxrecon-extract.");
    GFXRECON_WRITE_CONSOLE("  --opcd\t\tOmit pipeline cache data from calls to");
    GFXRECON_WRITE_CONSOLE("        \t\tvkCreatePipelineCache and skip calls to");
    GFXRECON_WRITE_CONSOLE("        \t\tvkGetPipelineCacheData (same as");
    GFXRECON_WRITE_CONSOLE("        \t\t--omit-pipeline-cache-data).");
    GFXRECON_WRITE_CONSOLE("  --wsi <platform>\tForce replay to use the specified wsi platform.");
    GFXRECON_WRITE_CONSOLE("                  \tAvailable platforms are: %s", GetWsiArgString().c_str());
    GFXRECON_WRITE_CONSOLE("  --surface-index <N>\tRestrict rendering to the Nth surface object created.");
    GFXRECON_WRITE_CONSOLE("                  \tUsed with captures that include multiple surfaces.  Default");
    GFXRECON_WRITE_CONSOLE("                  \tis -1 (render to all surfaces).");
    GFXRECON_WRITE_CONSOLE("  --sync\t\tSynchronize after each queue submission with vkQueueWaitIdle.");
    GFXRECON_WRITE_CONSOLE("  --remove-unsupported\tRemove unsupported extensions and features from instance");
    GFXRECON_WRITE_CONSOLE("                      \tand device creation parameters.");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("  --validate\t\tEnables the Khronos Vulkan validation layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tVulkan capture or the Direct3D debug layer when replaying a");
    GFXRECON_WRITE_CONSOLE("            \t\tDirect3D 12 capture.");
#else
    GFXRECON_WRITE_CONSOLE("  --validate\t\tEnables the Khronos Vulkan validation layer.");
#endif
    GFXRECON_WRITE_CONSOLE("  -m <mode>\t\tEnable memory translation for replay on GPUs with memory");
    GFXRECON_WRITE_CONSOLE("          \t\ttypes that are not compatible with the capture GPU's");
    GFXRECON_WRITE_CONSOLE("          \t\tmemory types.  Available modes are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tNo memory translation is performed.  This", kMemoryTranslationNone);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tis the default behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tAttempt to map capture memory types to", kMemoryTranslationRemap);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tcompatible replay memory types, without");
    GFXRECON_WRITE_CONSOLE("          \t\t         \taltering memory allocation behavior.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tAdjust memory allocation sizes and", kMemoryTranslationRealign);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tresource binding offsets based on");
    GFXRECON_WRITE_CONSOLE("          \t\t         \treplay memory properties.");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tChange memory allocation behavior based", kMemoryTranslationRebind);
    GFXRECON_WRITE_CONSOLE("          \t\t         \ton resource usage and replay memory");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tproperties.  Resources may be bound");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tto different allocations with different");
    GFXRECON_WRITE_CONSOLE("          \t\t         \toffsets.  Uses VMA to manage allocations");
    GFXRECON_WRITE_CONSOLE("          \t\t         \tand suballocations.");
#if defined(WIN32)
    GFXRECON_WRITE_CONSOLE("  --api <api>\t\tUse the specified API for replay (Windows only).");
    GFXRECON_WRITE_CONSOLE("          \t\tAvailable values are:");
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tReplay with the Vulkan API enabled.", kApiFamilyVulkan);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\tReplay with the Direct3D API enabled.", kApiFamilyD3D12);
    GFXRECON_WRITE_CONSOLE("          \t\t    %s\t\tReplay with both the Vulkan and Direct3D 12 APIs", kApiFamilyAll);
    GFXRECON_WRITE_CONSOLE("          \t\t         \tenabled. This is the default.");
#if defined(_DEBUG)
    GFXRECON_WRITE_CONSOLE("  --no-debug-popup\tDisable the 'Abort, Retry, Ignore' message box");
    GFXRECON_WRITE_CONSOLE("       \t\t\tdisplayed when abort() is called (Windows debug only).");
#endif
#endif
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

#endif // GFXRECON_REPLAY_SETTINGS_H
