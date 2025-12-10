/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2019-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/capture_settings.h"

#include "util/file_path.h"
#include "util/strings.h"
#include "util/options.h"
#include "util/platform.h"
#include "util/settings_manager.h"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

#if defined(GFXRECON_ENABLE_LZ4_COMPRESSION)
const format::CompressionType kDefaultCompressionType = format::CompressionType::kLz4;
#else
const format::CompressionType kDefaultCompressionType = format::CompressionType::kNone;
#endif

CaptureSettings::CaptureSettings(format::ApiFamilyId api_family)
{
    auto& settings_mgr = util::settings::SettingsManager::InitSingleton(api_family);

    trace_settings_ = {};
    log_settings_   = {};
}

CaptureSettings::~CaptureSettings() {}

void CaptureSettings::LoadAllSettings(CaptureSettings* settings, bool load_log_settings)
{
    if (settings != nullptr)
    {
        LoadGeneralSettings(settings, load_log_settings);
        LoadDynamicSettings(settings, true);
    }
}

void CaptureSettings::LoadDynamicSettings(CaptureSettings* settings, bool initial_call)
{
    if (settings != nullptr)
    {
        util::settings::SettingsManager& settings_mgr = util::settings::SettingsManager::GetSingleton();

        // Update the values for the dynamic environment variables based on any environment
        // settings changes
        settings_mgr.UpdateDynamicEnvironmentVariables();

        const GfxrSettingsStruct* settings_struct = settings_mgr.GetSettingsStruct();
        bool                      trigger_defined = false;

        // Always try the non-platform specific trigger first to see if it exists.
        // NOTE: We have to use dynamic settings for this because it can change during execution.
        trigger_defined = settings_struct->capture_settings.capture_dynamic_trigger;
        if (!trigger_defined)
        {
#if defined(__ANDROID__)
            trigger_defined = settings_struct->capture_settings.capture_android_trigger;
#endif
        }

        if (settings->trace_settings_.runtime_capture_trigger != RuntimeTriggerState::kNotUsed || trigger_defined)
        {
            CaptureSettings::RuntimeTriggerState new_result =
                trigger_defined ? RuntimeTriggerState::kEnabled : RuntimeTriggerState::kDisabled;
            if (new_result != settings->trace_settings_.runtime_capture_trigger)
            {
                GFXRECON_LOG_INFO("Runtime settings: Dynamic trigger was set to %s",
                                  new_result == RuntimeTriggerState::kEnabled ? "enabled" : "disabled");

                settings->trace_settings_.runtime_capture_trigger = new_result;
            }

            if (settings->trace_settings_.runtime_capture_trigger != RuntimeTriggerState::kNotUsed)
            {
                settings->trace_settings_.trim_boundary = TrimBoundary::kFrames;
            }
        }
        else
        {
            settings->trace_settings_.runtime_capture_trigger = RuntimeTriggerState::kNotUsed;
        }

        // Always try the non-platform specific trigger first to see if it exists.
        // NOTE: We have to use dynamic settings for this because it can change during execution.
        trigger_defined = settings_struct->capture_settings.capture_dynamic_trigger_dump_assets;
        if (!trigger_defined)
        {
#if defined(__ANDROID__)
            trigger_defined = settings_struct->capture_settings.capture_android_dump_assets;
#endif
        }
        settings->trace_settings_.runtime_write_assets = trigger_defined;
    }
}

void CaptureSettings::LoadLogSettings(CaptureSettings* settings)
{
    if (settings != nullptr)
    {
        ProcessLogOptions(settings);
    }
}

void CaptureSettings::LoadGeneralSettings(CaptureSettings* settings, bool process_log_settings)
{
    GFXRECON_ASSERT(settings != nullptr);
    util::settings::SettingsManager& settings_mgr = util::settings::SettingsManager::GetSingleton();
    std::string                      temp_string;
    bool                             temp_bool;
    int32_t                          temp_int;

    const GfxrSettingsStruct* settings_struct = settings_mgr.GetSettingsStruct();

    // Capture file options
    if (!settings_struct->capture_settings.capture_compression_type.empty())
    {
        settings->trace_settings_.capture_file_options.compression_type = ParseCompressionTypeString(
            settings_struct->capture_settings.capture_compression_type, kDefaultCompressionType);
    }
    else
    {
        GFXRECON_LOG_ERROR_ONCE("Missing known setting capture_compression_type (should at least have default)");
    }

    settings->trace_settings_.capture_file    = settings_struct->capture_settings.capture_file;
    settings->trace_settings_.force_flush     = settings_struct->capture_settings.capture_file_flush;
    settings->trace_settings_.time_stamp_file = settings_struct->capture_settings.capture_file_timestamp;

    // Memory tracking options
    settings->trace_settings_.memory_tracking_mode = ParseMemoryTrackingModeString(
        settings_struct->capture_settings.memory_tracking_mode, settings->trace_settings_.memory_tracking_mode);

    // Trimming options:
    // Trim frame ranges, trim queue submit ranges, and trim frame hotkey are mutually exclusive.
    // Precedence is frame ranges, queue submit ranges, then frame hotkey.
    if (!settings_struct->capture_settings.capture_frames.empty())
    {
        ParseUintRangeList(
            settings_struct->capture_settings.capture_frames, &settings->trace_settings_.trim_ranges, "capture frames");
        if (!settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_boundary = TrimBoundary::kFrames;
        }
    }

    if (!settings_struct->capture_settings.capture_draw_calls.empty())
    {
        std::vector<util::UintRange> trim_values;
        ParseUintRangeList(temp_string, &trim_values, "capture draw calls");
        if (!trim_values.empty())
        {
            if (trim_values.size() == 3 || trim_values.size() == 4)
            {
                settings->trace_settings_.trim_draw_calls.submit_index            = trim_values[0].first;
                settings->trace_settings_.trim_draw_calls.command_index           = trim_values[1].first;
                settings->trace_settings_.trim_draw_calls.draw_call_indices.first = trim_values[2].first;
                settings->trace_settings_.trim_draw_calls.draw_call_indices.last  = trim_values[2].last;
                settings->trace_settings_.trim_boundary                           = TrimBoundary::kDrawCalls;

                if (trim_values.size() == 4)
                {
                    settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.first = trim_values[3].first;
                    settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.last  = trim_values[3].last;
                }
                else
                {
                    // bundle_draw_call_indices is the 4th arg. The default is 0 if it doesn't set.
                    settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.first = 0;
                    settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.last  = 0;
                }
            }
        }
    }

    if (!settings_struct->capture_settings.capture_queue_submits.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            ParseUintRangeList(settings_struct->capture_settings.capture_queue_submits,
                               &settings->trace_settings_.trim_ranges,
                               "capture queue submits",
                               true,
                               true);
            if (settings->trace_settings_.trim_ranges.empty())
            {
                settings->trace_settings_.trim_boundary = TrimBoundary::kQueueSubmits;
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring trim queue submit ranges setting as trim frame ranges "
                                 "has been specified.");
        }
    }

#if defined(__linux__) || defined(__APPLE__) || defined(WIN32)
    if (!settings_struct->capture_settings.capture_trigger.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_key = ParseTrimKeyString(settings_struct->capture_settings.capture_trigger);
            if (!settings->trace_settings_.trim_key.empty())
            {
                settings->trace_settings_.trim_boundary = TrimBoundary::kFrames;
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring trim key setting as trim ranges has been specified.");
        }
    }
#endif // defined(__linux__) || defined(__APPLE__) || defined(WIN32)

    if (!settings_struct->capture_settings.capture_trigger_frames.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_key_frames =
                ParseTrimKeyFramesString(settings_struct->capture_settings.capture_trigger_frames);
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Settings Loader: Ignoring trim trigger frames setting as trim ranges has been specified.");
        }
    }

    settings->trace_settings_.quit_after_frame_ranges = settings_struct->capture_settings.quit_after_capture_frames;
    settings->trace_settings_.use_asset_file          = settings_struct->capture_settings.capture_use_asset_file;

    settings->trace_settings_.page_guard_align_buffer_sizes =
        settings_struct->capture_settings.page_guard_align_buffer_sizes;
    settings->trace_settings_.page_guard_copy_on_map = settings_struct->capture_settings.page_guard_copy_on_map;
#if defined(WIN32)
    settings->trace_settings_.page_guard_external_memory = settings_struct->capture_settings.page_guard_external_memory;
#else
    settings->trace_settings_.page_guard_external_memory  = false;
#endif
    settings->trace_settings_.page_guard_persistent_memory =
        settings_struct->capture_settings.page_guard_persistent_memory;
    settings->trace_settings_.page_guard_separate_read = settings_struct->capture_settings.page_guard_separate_read;
    settings->trace_settings_.page_guard_signal_handler_watcher =
        settings_struct->capture_settings.page_guard_signal_handler_watcher;
    settings->trace_settings_.page_guard_signal_handler_watcher_max_restores =
        settings_struct->capture_settings.page_guard_signal_handler_watcher_max_restores;
#if defined(__ANDROID__)
    settings->trace_settings_.page_guard_track_ahb_memory =
        settings_struct->capture_settings.page_guard_track_ahb_memory;
#else
    settings->trace_settings_.page_guard_track_ahb_memory = false;
#endif
    settings->trace_settings_.page_guard_unblock_sigsegv = settings_struct->capture_settings.page_guard_unblock_sigsegv;

    // Debug options
    settings->trace_settings_.debug_layer       = settings_struct->capture_settings.debug_layer;
    settings->trace_settings_.debug_device_lost = settings_struct->capture_settings.debug_device_lost;

    // Load logging options if required here
    if (process_log_settings)
    {
        ProcessLogOptions(settings);
    }

    // Screenshot options
    settings->trace_settings_.screenshot_dir = settings_struct->capture_settings.screenshot_dir;

    if (!settings_struct->capture_settings.screenshot_frames.empty())
    {
        ParseUintRangeList(settings_struct->capture_settings.screenshot_frames,
                           &settings->trace_settings_.screenshot_ranges,
                           "screenshot frames");
    }

    settings->trace_settings_.screenshot_interval = settings_struct->capture_settings.screenshot_interval;
    if (settings->trace_settings_.screenshot_interval == 0)
    {
        GFXRECON_LOG_WARNING(
            "A screenshot interval of 0 has been specified, which is invalid. An interval of 1 will be used.");
        settings->trace_settings_.screenshot_interval = 1;
    }

    if (!settings_struct->capture_settings.screenshot_format.empty())
    {
        settings->trace_settings_.screenshot_format = ParseScreenshotFormatString(
            settings_struct->capture_settings.screenshot_format, settings->trace_settings_.screenshot_format);
    }

    // DirectX options
    settings->trace_settings_.disable_dxr          = settings_struct->capture_settings.disable_dxr;
    settings->trace_settings_.disable_meta_command = settings_struct->capture_settings.disable_meta_command;
    settings->trace_settings_.accel_struct_padding = settings_struct->capture_settings.accel_struct_padding;
    settings->trace_settings_.iunknown_wrapping    = settings_struct->capture_settings.capture_iunknown_wrapping;

    // RV options
    settings->trace_settings_.rv_anotation_info.rv_annotation =
        settings_struct->capture_settings.rv_annotation_experimental;
    settings->trace_settings_.rv_anotation_info.annotation_mask_rand =
        settings_struct->capture_settings.rv_annotation_rand;

    if (!settings_struct->capture_settings.rv_annotation_gpuva.empty())
    {
        settings->trace_settings_.rv_anotation_info.gpuva_mask =
            ParseUnsignedInteger16String(settings_struct->capture_settings.rv_annotation_gpuva,
                                         settings->trace_settings_.rv_anotation_info.gpuva_mask);
    }

    if (!settings_struct->capture_settings.rv_annotation_descriptor.empty())
    {
        settings->trace_settings_.rv_anotation_info.descriptor_mask =
            ParseUnsignedInteger16String(settings_struct->capture_settings.rv_annotation_descriptor,
                                         settings->trace_settings_.rv_anotation_info.descriptor_mask);
    }

    // General options (alphabetical)
    settings->trace_settings_.allow_pipeline_compile_required =
        settings_struct->capture_settings.allow_pipeline_compile_required;

#if defined(__linux__) || defined(__APPLE__) || defined(WIN32)
    if (!settings_struct->capture_settings.capture_environment.empty())
    {
        settings->trace_settings_.capture_environment =
            util::strings::SplitString(settings_struct->capture_settings.capture_environment, ',');
    }
#else
    settings->log_settings_.capture_environment           = false;
#endif // defined(__linux__) || defined(__APPLE__) || defined(WIN32)

    settings->trace_settings_.capture_process_name = settings_struct->capture_settings.capture_process_name;
    settings->trace_settings_.force_command_serialization =
        settings_struct->capture_settings.force_command_serialization;
    settings->trace_settings_.force_fifo_present_mode = settings_struct->capture_settings.force_fifo_present_mode;

#if defined(__ANDROID__)
    settings->trace_settings_.ignore_frame_boundary_android =
        settings_struct->capture_settings.ignore_frame_boundary_android;
#endif // defined(__ANDROID__)

    settings->trace_settings_.queue_zero_only = settings_struct->capture_settings.queue_zero_only;
    settings->trace_settings_.skip_threads_with_invalid_data =
        settings_struct->capture_settings.skip_threads_with_invalid_data;
}

void CaptureSettings::ProcessLogOptions(CaptureSettings* settings)
{
    util::settings::SettingsManager& settings_mgr = util::settings::SettingsManager::GetSingleton();
    std::string                      temp_string;
    bool                             temp_bool;

    const GfxrSettingsStruct* settings_struct = settings_mgr.GetSettingsStruct();

    // Log options
    settings->log_settings_.use_indent               = settings_struct->capture_settings.log_allow_indents;
    settings->log_settings_.break_on_error           = settings_struct->capture_settings.log_break_on_error;
    settings->log_settings_.output_detailed_log_info = settings_struct->capture_settings.log_detailed;
    settings->log_settings_.output_errors_to_stderr  = settings_struct->capture_settings.log_errors_to_stderr;
    settings->log_settings_.file_name                = settings_struct->capture_settings.log_file;
    if (settings->log_settings_.file_name.length() > 0)
    {
        settings->log_settings_.write_to_file = true;
    }

    settings->log_settings_.create_new        = settings_struct->capture_settings.log_file_create_new;
    settings->log_settings_.flush_after_write = settings_struct->capture_settings.log_file_flush_after_write;
    settings->log_settings_.leave_file_open   = settings_struct->capture_settings.log_file_keep_open;
    settings->log_settings_.min_severity =
        ParseLogLevelString(settings_struct->capture_settings.log_level, settings->log_settings_.min_severity);
    settings->log_settings_.write_to_console = settings_struct->capture_settings.log_output_to_console;

#if defined(WIN32)
    settings->log_settings_.output_to_os_debug_string = settings_struct->capture_settings.log_output_to_os_debug_string;
#else
    settings->log_settings_.output_to_os_debug_string     = false;
#endif // WIN32

    settings->log_settings_.output_timestamps = settings_struct->capture_settings.log_timestamps;
}

uint16_t CaptureSettings::ParseUnsignedInteger16String(const std::string& value_string, uint16_t default_value)
{
    std::string::const_iterator it = value_string.begin();
    if (((value_string.compare(0, 2, "0x") == 0) || (value_string.compare(0, 2, "0X") == 0)))
    {
        it += 2;
    }
    while (it != value_string.end() && std::isxdigit(*it))
    {
        ++it;
    }
    const bool is_hex_integer = !value_string.empty() && it == value_string.end();

    if (!is_hex_integer && !value_string.empty())
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized Unsigned Integer16 option value \"%s\"",
                             value_string.c_str());
    }
    // Must be hex format
    uint32_t value = 0;
    if (is_hex_integer == true)
    {
        value = strtoul(value_string.c_str(), nullptr, 16);

        if (value > (~static_cast<uint32_t>(0x0) >> (32 - RvAnnotationUtil::kMaskSizeOfBits)))
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring oversized option value \"%s\"", value_string.c_str());
        }
    }
    // Return low 16bits
    return is_hex_integer ? static_cast<uint16_t>(value) : default_value;
}

int CaptureSettings::ParseIntegerString(const std::string& value_string, int default_value)
{
    std::string::const_iterator it = value_string.begin();
    while (it != value_string.end() && (std::isdigit(*it) || *it == '-' || *it == '+')) ++it;
    const bool is_integer = !value_string.empty() && it == value_string.end();

    if (!is_integer && !value_string.empty())
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized Integer option value \"%s\"",
                             value_string.c_str());
    }

    return is_integer ? atoi(value_string.c_str()) : default_value;
}

CaptureSettings::MemoryTrackingMode
CaptureSettings::ParseMemoryTrackingModeString(const std::string&                  value_string,
                                               CaptureSettings::MemoryTrackingMode default_value)
{
    CaptureSettings::MemoryTrackingMode result = default_value;

    if (util::platform::StringCompareNoCase("page_guard", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kPageGuard;
    }
    else if (util::platform::StringCompareNoCase("userfaultfd", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kUserfaultfd;
    }
    else if (util::platform::StringCompareNoCase("assisted", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kAssisted;
    }
    else if (util::platform::StringCompareNoCase("unassisted", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kUnassisted;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized memory tracking mode option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

format::CompressionType CaptureSettings::ParseCompressionTypeString(const std::string&      value_string,
                                                                    format::CompressionType default_value)
{
    format::CompressionType result = default_value;

    if (util::platform::StringCompareNoCase("none", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kNone;
    }
    else if (util::platform::StringCompareNoCase("lz4", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kLz4;
    }
    else if (util::platform::StringCompareNoCase("zlib", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kZlib;
    }
    else if (util::platform::StringCompareNoCase("zstd", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kZstd;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized compression type option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

util::LoggingSeverity CaptureSettings::ParseLogLevelString(const std::string&    value_string,
                                                           util::LoggingSeverity default_value)
{
    util::LoggingSeverity result;

    if (!util::Log::StringToSeverity(value_string, result))
    {
        result = default_value;
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized log level option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

void CaptureSettings::ParseUintRangeList(const std::string&            value_string,
                                         std::vector<util::UintRange>* frames,
                                         const char*                   option_name,
                                         bool                          check_overlap_range,
                                         bool                          allow_zero)
{
    GFXRECON_ASSERT(frames != nullptr);

    if (!value_string.empty())
    {
        std::vector<gfxrecon::util::UintRange> frame_ranges =
            util::GetUintRanges(value_string.c_str(), option_name, check_overlap_range, allow_zero);

        for (uint32_t i = 0; i < frame_ranges.size(); ++i)
        {
            util::UintRange range{};
            range.first = frame_ranges[i].first;
            range.last  = frame_ranges[i].last;
            frames->push_back(range);
        }
    }
}

std::string CaptureSettings::ParseTrimKeyString(const std::string& value_string)
{
    std::string trim_key;
    if (!value_string.empty())
    {
        trim_key = value_string;
        gfxrecon::util::strings::RemoveWhitespace(trim_key);
    }
    else
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid trim trigger key \"%s\"", trim_key.c_str());
    }
    return trim_key;
}

uint32_t CaptureSettings::ParseTrimKeyFramesString(const std::string& value_string)
{
    uint32_t frames = 0;
    size_t   digits = std::count_if(value_string.begin(), value_string.end(), ::isdigit);
    bool     valid  = false;
    if (digits == value_string.length())
    {
        int value = std::stoi(value_string);
        if (value > 0)
        {
            frames = static_cast<uint32_t>(value);
            valid  = true;
        }
    }
    if (!valid)
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid trim trigger key frames \"%s\"", value_string.c_str());
    }
    return frames;
}

util::ScreenshotFormat CaptureSettings::ParseScreenshotFormatString(const std::string&     value_string,
                                                                    util::ScreenshotFormat default_value)
{
    util::ScreenshotFormat result = default_value;

    if (util::platform::StringCompareNoCase("bmp", value_string.c_str()) == 0)
    {
        result = util::ScreenshotFormat::kBmp;
    }
    else if (util::platform::StringCompareNoCase("png", value_string.c_str()) == 0)
    {
        result = util::ScreenshotFormat::kPng;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized screenshot format option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)