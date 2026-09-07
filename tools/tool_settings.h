/*
** Copyright (c) 2019-2026 LunarG, Inc.
** Copyright (c) 2021-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/file_processor.h"

#include "decode/replay_options.h"
#include "format/format.h"

#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"
#include "util/options.h"
#include "util/strings.h"

// The window-system helpers below name the Vulkan surface extensions, because the WSI contexts
// of application::Application use those names as their keys for every API that it replays.
#include "vulkan/vulkan_core.h"

#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

#ifndef GFXRECON_PLATFORM_SETTINGS_H
#define GFXRECON_PLATFORM_SETTINGS_H

const char kApplicationName[] = "GFXReconstruct Replay";

const char kLogLevelArgument[]                   = "--log-level";
const char kLogTimestampsOption[]                = "--log-timestamps";
const char kLogFileArgument[]                    = "--log-file";
const char kLogDebugView[]                       = "--log-debugview";
const char kNoDebugPopup[]                       = "--no-debug-popup";
const char kCpuMaskArgument[]                    = "--cpu-mask";
const char kOverrideGpuArgument[]                = "--gpu";
const char kPausedOption[]                       = "--paused";
const char kPauseFrameArgument[]                 = "--pause-frame";
const char kLoopFrameArgument[]                  = "--loop-frame";
const char kLoopCountArgument[]                  = "--loop-count";
const char kWsiArgument[]                        = "--wsi";
const char kSyncOption[]                         = "--sync";
const char kRemoveUnsupportedOption[]            = "--remove-unsupported";
const char kValidateOption[]                     = "--validate";
const char kDebugDeviceLostOption[]              = "--debug-device-lost";
const char kCreateDummyAllocationsOption[]       = "--create-dummy-allocations";
const char kOmitNullHardwareBuffersLongOption[]  = "--omit-null-hardware-buffers";
const char kOmitNullHardwareBuffersShortOption[] = "--onhb";
const char kScreenshotAllOption[]                = "--screenshot-all";
const char kScreenshotRangeArgument[]            = "--screenshots";
const char kScreenshotIntervalArgument[]         = "--screenshot-interval";
const char kScreenshotFormatArgument[]           = "--screenshot-format";
const char kScreenshotDirArgument[]              = "--screenshot-dir";
const char kScreenshotFilePrefixArgument[]       = "--screenshot-prefix";
const char kScreenshotSizeArgument[]             = "--screenshot-size";
const char kScreenshotScaleArgument[]            = "--screenshot-scale";
const char kForceWindowedShortArgument[]         = "--fw";
const char kForceWindowedLongArgument[]          = "--force-windowed";
const char kForceWindowWithOriginShortArgument[] = "--fwo";
const char kForceWindowWithOriginLongArgument[]  = "--force-windowed-origin";
const char kOutput[]                             = "--output";
const char kMeasurementRangeArgument[]           = "--measurement-frame-range";
const char kMeasurementFileArgument[]            = "--measurement-file";
const char kQuitAfterMeasurementRangeOption[]    = "--quit-after-measurement-range";
const char kQuitAfterFrameArgument[]             = "--quit-after-frame";
const char kFlushMeasurementRangeOption[]        = "--flush-measurement-range";
const char kFlushInsideMeasurementRangeOption[]  = "--flush-inside-measurement-range";
const char kFormatArgument[]                     = "--format";
const char kIncludeBinariesOption[]              = "--include-binaries";
const char kExpandFlagsOption[]                  = "--expand-flags";
const char kFilePerFrameOption[]                 = "--file-per-frame";
const char kFrameRange[]                         = "--frame-range";
const char kPrintBlockInfoAllOption[]            = "--pbi-all";
const char kPrintBlockInfosArgument[]            = "--pbis";
const char kNumPipelineCreationJobs[]            = "--pipeline-creation-jobs";
const char kPreloadMeasurementRangeOption[]      = "--preload-measurement-range";
const char kWaitBeforeFirstSubmit[]              = "--wait-before-first-submit";
const char kWaitBeforeFrame[]                    = "--wait-before-frame";
const char kAsyncProcessingOption[]              = "--async-processing";
const char kDumpResourcesArgument[]              = "--dump-resources";
const char kDumpResourcesDirArgument[]           = "--dump-resources-dir";
const char kDumpResourcesImageFormatArgument[]   = "--dump-resources-image-format";
const char kFrameWarmUpSpirv[]                   = "--frame-warm-up-spirv";
const char kFrameWarmUpLoad[]                    = "--frame-warm-up-load";

enum class WsiPlatform
{
    kAuto,
    kWin32,
    kXlib,
    kXcb,
    kWayland,
    kMetal,
    kDisplay,
    kHeadless
};

const char kWsiPlatformAuto[]     = "auto";
const char kWsiPlatformWin32[]    = "win32";
const char kWsiPlatformXlib[]     = "xlib";
const char kWsiPlatformXcb[]      = "xcb";
const char kWsiPlatformWayland[]  = "wayland";
const char kWsiPlatformMetal[]    = "metal";
const char kWsiPlatformDisplay[]  = "display";
const char kWsiPlatformHeadless[] = "headless";

#if defined(__ANDROID__)
const char kDefaultScreenshotDir[]    = "/sdcard";
const char kDefaultDumpResourcesDir[] = "/sdcard";
#else
const char kDefaultScreenshotDir[]                  = "";
const char kDefaultDumpResourcesDir[]               = "";
const bool kDefaultDumpResourcesModifiableStateOnly = false;
#endif

static void ProcessDisableDebugPopup(const gfxrecon::util::ArgumentParser& arg_parser)
{
#if defined(_WIN32) && defined(_DEBUG)
    if (arg_parser.IsOptionSet(kNoDebugPopup))
    {
        _set_abort_behavior(0, _WRITE_ABORT_MSG | _CALL_REPORTFAULT);
    }
#endif
}

static uint32_t GetPauseFrame(const gfxrecon::util::ArgumentParser& arg_parser)
{
    uint32_t    pause_frame = std::numeric_limits<uint32_t>::max();
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
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformMetal, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_METAL_EXT)
            wsi_platform = WsiPlatform::kMetal;
#else
            GFXRECON_LOG_WARNING("Ignoring wsi option \"%s\", which is not enabled on this system", value.c_str());
#endif
        }
        else if (gfxrecon::util::platform::StringCompareNoCase(kWsiPlatformDisplay, value.c_str()) == 0)
        {
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
            wsi_platform = WsiPlatform::kDisplay;
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

/// @brief Selects the WSI extension name based on the WSI platform.
/// @param wsi_platform The WSI platform to select the extension name for.
/// @return If WsiPlatform::kAuto, returns the first available WSI extension name.
///         Otherwise, returns the WSI extension name for the specified platform.
static std::string GetFirstWsiExtensionName(WsiPlatform wsi_platform)
{
    switch (wsi_platform)
    {
        // Return the first available WSI extension name
        case WsiPlatform::kAuto:
#if defined(VK_USE_PLATFORM_WIN32_KHR)
        case WsiPlatform::kWin32:
        {
            return VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
        case WsiPlatform::kXlib:
        {
            return VK_KHR_XLIB_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
        case WsiPlatform::kXcb:
        {
            return VK_KHR_XCB_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
        case WsiPlatform::kWayland:
        {
            return VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_METAL_EXT)
        case WsiPlatform::kMetal:
        {
            return VK_EXT_METAL_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
        case WsiPlatform::kHeadless:
        {
            return VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME;
        }
#endif
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
        case WsiPlatform::kDisplay:
        {
            return VK_KHR_DISPLAY_EXTENSION_NAME;
        }
#endif
        default:
        {
            GFXRECON_ASSERT(false && "Failed to get WSI extension name");
            return std::string();
        }
    }
}

/// @brief Selects the WSI extension name based on the WSI platform.
/// @param wsi_platform The WSI platform to select the extension name for.
/// @return If WsiPlatform::kAuto, returns an empty string.
///         Otherwise, returns the WSI extension name for the specified platform.
static std::string GetWsiExtensionName(WsiPlatform wsi_platform)
{
    switch (wsi_platform)
    {
        case WsiPlatform::kAuto:
        {
            return std::string();
        }
        default:
        {
            return GetFirstWsiExtensionName(wsi_platform);
        }
    }
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
#if defined(VK_USE_PLATFORM_METAL_EXT)
    wsi_args += ',';
    wsi_args += kWsiPlatformMetal;
#endif
#if defined(VK_USE_PLATFORM_DISPLAY_KHR)
    wsi_args += ',';
    wsi_args += kWsiPlatformDisplay;
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
    gfxrecon::util::LoggingSeverity log_level;
    const std::string&              value_string = arg_parser.GetArgumentValue(kLogLevelArgument);
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
    log_settings.output_timestamps         = arg_parser.IsOptionSet(kLogTimestampsOption);
    log_settings.file_name                 = arg_parser.GetArgumentValue(kLogFileArgument);
    log_settings.output_to_os_debug_string = arg_parser.IsOptionSet(kLogDebugView);
    if (log_settings.file_name.size() > 0)
    {
        log_settings.write_to_file = true;
    }
}

static void GetMeasurementFilename(const gfxrecon::util::ArgumentParser& arg_parser, std::string& file_name)
{
    file_name = arg_parser.GetArgumentValue(kMeasurementFileArgument);
    if (file_name.empty())
    {
#if defined(__ANDROID__)
        file_name = "/sdcard/gfxrecon-measurements.json";
#else
        file_name = "./gfxrecon-measurements.json";
#endif
    }
}

static gfxrecon::util::ScreenshotFormat GetScreenshotFormat(const gfxrecon::util::ArgumentParser& arg_parser)
{
    gfxrecon::util::ScreenshotFormat format = gfxrecon::util::ScreenshotFormat::kBmp;
    const auto&                      value  = arg_parser.GetArgumentValue(kScreenshotFormatArgument);

    if (!value.empty())
    {
        if (!gfxrecon::util::platform::StringCompareNoCase(gfxrecon::util::kScreenshotFormatBmp, value.c_str()))
        {
            format = gfxrecon::util::ScreenshotFormat::kBmp;
        }
        else if (!gfxrecon::util::platform::StringCompareNoCase(gfxrecon::util::kScreenshotFormatPng, value.c_str()))
        {
            format = gfxrecon::util::ScreenshotFormat::kPng;
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

static std::string GetDumpResourcesDir(const gfxrecon::util::ArgumentParser& arg_parser)
{
    const auto& value = arg_parser.GetArgumentValue(kDumpResourcesDirArgument);

    if (!value.empty())
    {
        return value;
    }

    return kDefaultDumpResourcesDir;
}

static void GetScreenshotSize(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& width, uint32_t& height)
{
    const auto& value = arg_parser.GetArgumentValue(kScreenshotSizeArgument);

    if (!value.empty())
    {
        std::size_t x = value.find("x");
        if (x != std::string::npos)
        {
            try
            {
                width  = std::stoul(value.substr(0, x));
                height = std::stoul(value.substr(x + 1));
            }
            catch (std::exception&)
            {
                GFXRECON_LOG_WARNING("Ignoring invalid screenshot width x height option. Expected format is "
                                     "--screenshot-size [width]x[height]");
                width = height = 0;
            }
        }
        else
        {
            width = height = 0;
        }
    }
    else
    {
        width = height = 0;
    }
}

static std::optional<std::array<float, 2>> GetScreenshotScale(const gfxrecon::util::ArgumentParser& arg_parser)
{
    const auto& value = arg_parser.GetArgumentValue(kScreenshotScaleArgument);

    if (!value.empty())
    {
        try
        {
            std::array<float, 2> scale = { 1.0f, 1.0f };
            std::size_t          pos   = 0;
            scale[0]                   = std::stof(value, &pos);

            // skip comma separator
            if (pos < value.size() && value[pos] == ',')
            {
                scale[1] = std::stof(value.substr(pos + 1));
            }
            else
            {
                // single value provided — apply uniformly
                scale[1] = scale[0];
            }
            return scale;
        }
        catch (std::exception&)
        {
            GFXRECON_LOG_WARNING(
                "Ignoring invalid screenshot scale option. Expected format is --screenshot-scale [x,y]");
        }
    }
    return {};
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
            std::vector<gfxrecon::util::UintRange> frame_ranges =
                gfxrecon::util::GetUintRanges(value.c_str(), "screenshot frames");

            for (uint32_t i = 0; i < frame_ranges.size(); ++i)
            {
                gfxrecon::decode::ScreenshotRange range{};
                range.first = frame_ranges[i].first;
                range.last  = frame_ranges[i].last;
                ranges.push_back(range);
            }
        }
    }

    return ranges;
}

static bool GetQuitAfterFrame(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& quit_frame)
{
    const std::string& value = arg_parser.GetArgumentValue(kQuitAfterFrameArgument);
    if (!value.empty())
    {
        if (std::count_if(value.begin(), value.end(), ::isdigit) != value.length())
        {
            GFXRECON_LOG_WARNING("Ignoring invalid quit after frame \"%s\", which contains non-numeric values",
                                 value.c_str());
            return false;
        }

        quit_frame = std::stoi(value);
        return true;
    }

    return false;
}

static bool GetLoopFrame(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& frame_number)
{
    const std::string& value = arg_parser.GetArgumentValue(kLoopFrameArgument);

    bool valid = !value.empty();

    if (valid)
    {
        if (std::count_if(value.begin(), value.end(), ::isdigit) != value.length())
        {
            GFXRECON_LOG_WARNING("Ignoring invalid loop frame argument \"%s\", which contains non-numeric values",
                                 value.c_str());
            valid = false;
        }
    }

    if (valid)
    {
        frame_number = std::stoi(value);
        if (frame_number == 0)
        {
            GFXRECON_LOG_WARNING("Ignoring invalid loop frame argument \"%s\", which must be greater than zero",
                                 value.c_str());
            valid = false;
        }
    }

    return valid;
}

static bool GetLoopCount(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& loop_count)
{
    const std::string& value = arg_parser.GetArgumentValue(kLoopCountArgument);
    if (!value.empty())
    {
        if (std::count_if(value.begin(), value.end(), ::isdigit) != value.length())
        {
            GFXRECON_LOG_WARNING("Ignoring invalid loop count \"%s\", which contains non-numeric values",
                                 value.c_str());
            return false;
        }

        uint32_t parsed_loop_count = static_cast<uint32_t>(std::stoul(value));
        if (parsed_loop_count == 0)
        {
            GFXRECON_LOG_WARNING("Ignoring invalid loop count \"%s\", which must be greater than zero", value.c_str());
            return false;
        }

        loop_count = parsed_loop_count;
        return true;
    }

    return false;
}

static bool
GetMeasurementFrameRange(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& start_frame, uint32_t& end_frame)
{
    start_frame = 1;
    end_frame   = std::numeric_limits<uint32_t>::max();

    const auto& value = arg_parser.GetArgumentValue(kMeasurementRangeArgument);
    if (value.empty())
    {
        return false;
    }

    std::vector<std::string> values = gfxrecon::util::strings::SplitString(value, '-');

    if (values.size() != 2)
    {
        GFXRECON_LOG_FATAL("Invalid measurement frame range \"%s\". Must have format: <start_frame>-<end_frame>",
                           value.c_str());
    }

    for (std::string& num : values)
    {
        gfxrecon::util::strings::RemoveWhitespace(num);

        // Check that the range string only contains numbers.
        const size_t count = std::count_if(num.begin(), num.end(), ::isdigit);
        if (count != num.length())
        {
            GFXRECON_LOG_FATAL("Invalid measurement frame range \"%s\", which contains non-numeric values",
                               value.c_str());
        }
    }

    uint32_t start_frame_arg = std::stoi(values[0]);
    uint32_t end_frame_arg   = std::stoi(values[1]);

    if (start_frame_arg >= end_frame_arg)
    {
        GFXRECON_LOG_FATAL("Invalid measurement frame range \"%s\", where first frame is greater than or equal "
                           "to the last frame",
                           value.c_str());
    }

    if (start_frame_arg == 0)
    {
        GFXRECON_LOG_FATAL("Invalid measurement frame range \"%s\", where first frame is 0 which is invalid in "
                           "GFXReconstruct (frame count starts at 1)",
                           value.c_str());
    }

    start_frame = start_frame_arg;
    end_frame   = end_frame_arg;

    return true;
}

static void IsForceWindowed(gfxrecon::decode::ReplayOptions& options, const gfxrecon::util::ArgumentParser& arg_parser)
{
    auto value = arg_parser.GetArgumentValue(kForceWindowedShortArgument);

    if (value.empty())
    {
        value = arg_parser.GetArgumentValue(kForceWindowedLongArgument);
    }
    if (!value.empty())
    {
        options.force_windowed = true;

        std::istringstream value_input;
        value_input.str(value);
        std::string val;

        std::getline(value_input, val, ',');
        options.windowed_width = std::stoi(val);
        std::getline(value_input, val, ',');
        options.windowed_height = std::stoi(val);
    }
}

static void SetWindowOrigin(gfxrecon::decode::ReplayOptions& options, const gfxrecon::util::ArgumentParser& arg_parser)
{
    auto value = arg_parser.GetArgumentValue(kForceWindowWithOriginShortArgument);

    if (value.empty())
    {
        value = arg_parser.GetArgumentValue(kForceWindowWithOriginLongArgument);
    }
    if (!value.empty())
    {
        options.force_windowed_origin = true;

        std::istringstream value_input;
        value_input.str(value);
        std::string val;

        std::getline(value_input, val, ',');
        options.window_topleft_x = std::stoi(val);
        std::getline(value_input, val, ',');
        options.window_topleft_y = std::stoi(val);
    }
}

static void GetWaitBeforeFirstSubmit(const gfxrecon::util::ArgumentParser& arg_parser,
                                     uint32_t&                             wait_before_first_submit)
{
    const auto& value = arg_parser.GetArgumentValue(kWaitBeforeFirstSubmit);

    if (!value.empty())
    {
        try
        {
            wait_before_first_submit = std::stoul(value);
        }
        catch (std::exception&)
        {
            GFXRECON_LOG_WARNING(
                "Ignoring invalid wait before first submit option. Expected format is unsigned integer");
        }
    }
}

static void GetFrameWarmUpLoad(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& frame_warm_up_load)
{
    const auto& value = arg_parser.GetArgumentValue(kFrameWarmUpLoad);

    if (!value.empty())
    {
        try
        {
            frame_warm_up_load = std::stoul(value);
        }
        catch (std::exception&)
        {
            GFXRECON_LOG_WARNING(
                "Ignoring invalid frame warm up load option: \"%s\". Expected format is unsigned integer",
                value.c_str());
        }
    }
}

static void GetFrameWarmUpOptions(const gfxrecon::util::ArgumentParser& arg_parser,
                                  std::string&                          frame_warm_up_spirv,
                                  uint32_t&                             frame_warm_up_load)
{
    frame_warm_up_spirv = arg_parser.GetArgumentValue(kFrameWarmUpSpirv);
    GetFrameWarmUpLoad(arg_parser, frame_warm_up_load);

    if (frame_warm_up_load > 0 && frame_warm_up_spirv.empty())
    {
        GFXRECON_LOG_FATAL(
            "Frame warm up load option is set to %u, but no SPIR-V file is specified. Expected format is "
            "--frame-warm-up-spirv [spirv-file]",
            frame_warm_up_load);
    }
    else if (!frame_warm_up_spirv.empty() && frame_warm_up_load == 0)
    {
        GFXRECON_LOG_WARNING("Frame warm up SPIR-V file is specified as \"%s\", but frame warm up is disabled because "
                             "`--frame-warm-up-load` is 0. Specify a non-zero load to enable frame warm up.",
                             frame_warm_up_spirv.c_str());
    }
}

static void GetWaitBeforeFrame(const gfxrecon::util::ArgumentParser& arg_parser, uint32_t& wait_before_frame)
{
    const auto& value = arg_parser.GetArgumentValue(kWaitBeforeFrame);

    if (!value.empty())
    {
        try
        {
            wait_before_frame = std::stoul(value);
        }
        catch (std::exception&)
        {
            GFXRECON_LOG_WARNING(
                "Ignoring invalid wait before frame option: \"%s\". Expected format is unsigned integer",
                value.c_str());
        }
    }
}

static void GetReplayOptions(gfxrecon::decode::ReplayOptions&      options,
                             const gfxrecon::util::ArgumentParser& arg_parser,
                             const std::string&                    filename)
{
    options.capture_filename = filename;

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

    if (arg_parser.IsOptionSet(kRemoveUnsupportedOption))
    {
        options.remove_unsupported_features = true;
    }

    if (arg_parser.IsOptionSet(kOmitNullHardwareBuffersLongOption) ||
        arg_parser.IsOptionSet(kOmitNullHardwareBuffersShortOption))
    {
        options.omit_null_hardware_buffers = true;
    }

    if (arg_parser.IsOptionSet(kQuitAfterMeasurementRangeOption))
    {
        options.quit_after_measurement_frame_range = true;
    }

    if (arg_parser.IsOptionSet(kFlushMeasurementRangeOption))
    {
        options.flush_measurement_frame_range = true;
    }

    if (arg_parser.IsOptionSet(kFlushInsideMeasurementRangeOption))
    {
        options.flush_inside_measurement_range = true;
    }

    if (arg_parser.IsOptionSet(kPrintBlockInfoAllOption))
    {
        options.enable_print_block_info = true;
    }
    else if (arg_parser.IsArgumentSet(kPrintBlockInfosArgument))
    {
        options.enable_print_block_info = true;
        const auto& value               = arg_parser.GetArgumentValue(kPrintBlockInfosArgument);

        if (!value.empty())
        {
            std::vector<gfxrecon::util::UintRange> block_ranges =
                gfxrecon::util::GetUintRanges(value.c_str(), "Print block information");
            options.block_index_from = block_ranges[0].first;
            options.block_index_to   = block_ranges[1].first;
        }
    }

    if (arg_parser.IsArgumentSet(kNumPipelineCreationJobs))
    {
        options.num_pipeline_creation_jobs = std::stoi(arg_parser.GetArgumentValue(kNumPipelineCreationJobs));
    }

    options.cpu_mask = arg_parser.GetArgumentValue(kCpuMaskArgument);
    if (!options.cpu_mask.empty())
    {
        if (gfxrecon::util::platform::SetCpuAffinity(options.cpu_mask))
        {
            GFXRECON_LOG_INFO("CPU mask successfully set: %s", gfxrecon::util::platform::GetCpuAffinity().c_str());
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to set CPU mask: %s", options.cpu_mask.c_str());
            GFXRECON_LOG_ERROR("Resuming with CPU mask: %s", gfxrecon::util::platform::GetCpuAffinity().c_str());
        }
    }

    const auto& override_gpu = arg_parser.GetArgumentValue(kOverrideGpuArgument);
    if (!override_gpu.empty())
    {
        options.override_gpu_index = std::stoi(override_gpu);
    }

    if (arg_parser.IsArgumentSet(kQuitAfterFrameArgument))
    {
        options.quit_after_frame = true;
    }

    IsForceWindowed(options, arg_parser);
    SetWindowOrigin(options, arg_parser);

    // API-independent screenshot options
    options.screenshot_ranges = GetScreenshotRanges(arg_parser);
    if (arg_parser.IsArgumentSet(kScreenshotIntervalArgument))
    {
        options.screenshot_interval = std::stoi(arg_parser.GetArgumentValue(kScreenshotIntervalArgument));
        if (options.screenshot_interval == 0)
        {
            GFXRECON_LOG_WARNING("A screenshot interval of 0 is invalid. Using default value of 1.");
            options.screenshot_interval = 1;
        }
    }
    options.screenshot_format      = GetScreenshotFormat(arg_parser);
    options.screenshot_dir         = GetScreenshotDir(arg_parser);
    options.screenshot_file_prefix = arg_parser.GetArgumentValue(kScreenshotFilePrefixArgument);
}

#endif // GFXRECON_PLATFORM_SETTINGS_H
