/*
** Copyright (c) 2019-2020 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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
#include "util/options.h"

#include "vulkan/vulkan_core.h"

#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#ifndef GFXRECON_PLATFORM_SETTINGS_H
#define GFXRECON_PLATFORM_SETTINGS_H

const char kApplicationName[] = "GFXReconstruct Replay";
const char kCaptureLayer[]    = "VK_LAYER_LUNARG_gfxreconstruct";

const char kHelpShortOption[]                  = "-h";
const char kHelpLongOption[]                   = "--help";
const char kVersionOption[]                    = "--version";
const char kLogLevelArgument[]                 = "--log-level";
const char kLogFileArgument[]                  = "--log-file";
const char kLogDebugView[]                     = "--log-debugview";
const char kNoDebugPopup[]                     = "--no-debug-popup";
const char kOverrideGpuArgument[]              = "--gpu";
const char kPausedOption[]                     = "--paused";
const char kPauseFrameArgument[]               = "--pause-frame";
const char kSkipFailedAllocationShortOption[]  = "--sfa";
const char kSkipFailedAllocationLongOption[]   = "--skip-failed-allocations";
const char kDiscardCachedPsosShortOption[]     = "--dcp";
const char kDiscardCachedPsosLongOption[]      = "--discard-cached-psos";
const char kOmitPipelineCacheDataShortOption[] = "--opcd";
const char kOmitPipelineCacheDataLongOption[]  = "--omit-pipeline-cache-data";
const char kWsiArgument[]                      = "--wsi";
const char kSurfaceIndexArgument[]             = "--surface-index";
const char kMemoryPortabilityShortOption[]     = "-m";
const char kMemoryPortabilityLongOption[]      = "--memory-translation";
const char kSyncOption[]                       = "--sync";
const char kRemoveUnsupportedOption[]          = "--remove-unsupported";
const char kValidateOption[]                   = "--validate";
const char kDebugDeviceLostOption[]            = "--debug-device-lost";
const char kCreateDummyAllocationsOption[]     = "--create-dummy-allocations";
const char kDeniedMessages[]                   = "--denied-messages";
const char kAllowedMessages[]                  = "--allowed-messages";
const char kShaderReplaceArgument[]            = "--replace-shaders";
const char kScreenshotAllOption[]              = "--screenshot-all";
const char kScreenshotRangeArgument[]          = "--screenshots";
const char kScreenshotFormatArgument[]         = "--screenshot-format";
const char kScreenshotDirArgument[]            = "--screenshot-dir";
const char kScreenshotFilePrefixArgument[]     = "--screenshot-prefix";
#if defined(WIN32)
const char kApiFamilyOption[] = "--api";
#endif

enum class WsiPlatform
{
    kAuto,
    kWin32,
    kXlib,
    kXcb,
    kWayland,
    kHeadless
};

const char kWsiPlatformAuto[]     = "auto";
const char kWsiPlatformWin32[]    = "win32";
const char kWsiPlatformXlib[]     = "xlib";
const char kWsiPlatformXcb[]      = "xcb";
const char kWsiPlatformWayland[]  = "wayland";
const char kWsiPlatformHeadless[] = "headless";

const char kMemoryTranslationNone[]    = "none";
const char kMemoryTranslationRemap[]   = "remap";
const char kMemoryTranslationRealign[] = "realign";
const char kMemoryTranslationRebind[]  = "rebind";

#if defined(WIN32)
const char kApiFamilyVulkan[] = "vulkan";
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
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformHeadless, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_HEADLESS)
            wsi_platform = WsiPlatform::kHeadless;
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
#if defined(VK_USE_PLATFORM_HEADLESS)
    wsi_args += ',';
    wsi_args += kWsiPlatformHeadless;
#endif
    return wsi_args;
}

// Modifies settings parameter with values set via command line
static void GetLogSettings(const gfxrecon::util::ArgumentParser& arg_parser,
                           gfxrecon::util::Log::Settings&        log_settings)
{
    // Parse log level
    gfxrecon::util::Log::Severity log_level;
    const std::string&            value_string = arg_parser.GetArgumentValue(kLogLevelArgument);
    if (value_string.empty() || !gfxrecon::util::Log::StringToSeverity(value_string, log_level))
    {
        log_level = gfxrecon::decode::kDefaultLogLevel;
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Ignoring unrecognized log level option value \"%s\"", value_string.c_str());
        }
    }

    // Update settings
    log_settings.min_severity              = log_level;
    log_settings.file_name                 = arg_parser.GetArgumentValue(kLogFileArgument);
    log_settings.output_to_os_debug_string = arg_parser.IsOptionSet(kLogDebugView);
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
            std::vector<gfxrecon::util::FrameRange> frame_ranges = gfxrecon::util::GetFrameRanges(value);

            for (uint32_t i = 0; i < frame_ranges.size(); ++i)
            {
                gfxrecon::decode::ScreenshotRange range = { frame_ranges[i].first, frame_ranges[i].last };
                ranges.push_back(range);
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

static std::vector<int32_t> GetFilteredMsgs(const gfxrecon::util::ArgumentParser& arg_parser,
                                            const char*                           filter_messages)
{
    const auto&          value = arg_parser.GetArgumentValue(filter_messages);
    std::vector<int32_t> msgs;
    if (!value.empty())
    {
        std::vector<std::string> values;
        std::istringstream       value_input;
        value_input.str(value);

        for (std::string val; std::getline(value_input, val, ',');)
        {
            size_t count = std::count_if(val.begin(), val.end(), ::isdigit);
            if (count == val.length())
            {
                msgs.push_back(std::stoi(val));
            }
            else
            {
                GFXRECON_LOG_WARNING("Ignoring invalid filter messages\"%s\", which contains non-numeric values",
                                     val.c_str());
                break;
            }
        }
    }
    return msgs;
}

static void GetReplayOptions(gfxrecon::decode::ReplayOptions& options, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kValidateOption))
    {
        options.enable_validation_layer = true;
    }

    if (arg_parser.IsOptionSet(kDebugDeviceLostOption))
    {
        options.enable_debug_device_lost = true;
    }

    if (arg_parser.IsOptionSet(kSyncOption))
    {
        options.sync_queue_submissions = true;
    }

    if (arg_parser.IsOptionSet(kCreateDummyAllocationsOption))
    {
        options.create_dummy_allocations = true;
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

static void PrintUsage(const char* exe_name);

static bool CheckOptionPrintUsage(const char* exe_name, const gfxrecon::util::ArgumentParser& arg_parser)
{
    if (arg_parser.IsOptionSet(kHelpShortOption) || arg_parser.IsOptionSet(kHelpLongOption))
    {
        PrintUsage(exe_name);
        return true;
    }

    return false;
}

#endif // GFXRECON_PLATFORM_SETTINGS_H
