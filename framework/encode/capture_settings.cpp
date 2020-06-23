/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/capture_settings.h"

#include "util/file_path.h"
#include "util/platform.h"
#include "util/settings_loader.h"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <sstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Available settings (upper and lower-case)
// clang-format off
#define CAPTURE_COMPRESSION_TYPE_LOWER      "capture_compression_type"
#define CAPTURE_COMPRESSION_TYPE_UPPER      "CAPTURE_COMPRESSION_TYPE"
#define CAPTURE_FILE_NAME_LOWER             "capture_file"
#define CAPTURE_FILE_NAME_UPPER             "CAPTURE_FILE"
#define CAPTURE_FILE_USE_TIMESTAMP_LOWER    "capture_file_timestamp"
#define CAPTURE_FILE_USE_TIMESTAMP_UPPER    "CAPTURE_FILE_TIMESTAMP"
#define CAPTURE_FILE_FLUSH_LOWER            "capture_file_flush"
#define CAPTURE_FILE_FLUSH_UPPER            "CAPTURE_FILE_FLUSH"
#define LOG_ALLOW_INDENTS_LOWER             "log_allow_indents"
#define LOG_ALLOW_INDENTS_UPPER             "LOG_ALLOW_INDENTS"
#define LOG_BREAK_ON_ERROR_LOWER            "log_break_on_error"
#define LOG_BREAK_ON_ERROR_UPPER            "LOG_BREAK_ON_ERROR"
#define LOG_ERRORS_TO_STDERR_LOWER          "log_errors_to_stderr"
#define LOG_ERRORS_TO_STDERR_UPPER          "LOG_ERRORS_TO_STDERR"
#define LOG_DETAILED_LOWER                  "log_detailed"
#define LOG_DETAILED_UPPER                  "LOG_DETAILED"
#define LOG_FILE_NAME_LOWER                 "log_file"
#define LOG_FILE_NAME_UPPER                 "LOG_FILE"
#define LOG_FILE_CREATE_NEW_LOWER           "log_file_create_new"
#define LOG_FILE_CREATE_NEW_UPPER           "LOG_FILE_CREATE_NEW"
#define LOG_FILE_FLUSH_AFTER_WRITE_LOWER    "log_file_flush_after_write"
#define LOG_FILE_FLUSH_AFTER_WRITE_UPPER    "LOG_FILE_FLUSH_AFTER_WRITE"
#define LOG_FILE_KEEP_OPEN_LOWER            "log_file_keep_open"
#define LOG_FILE_KEEP_OPEN_UPPER            "LOG_FILE_KEEP_OPEN"
#define LOG_LEVEL_LOWER                     "log_level"
#define LOG_LEVEL_UPPER                     "LOG_LEVEL"
#define LOG_OUTPUT_TO_CONSOLE_LOWER         "log_output_to_console"
#define LOG_OUTPUT_TO_CONSOLE_UPPER         "LOG_OUTPUT_TO_CONSOLE"
#define LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER "log_output_to_os_debug_string"
#define LOG_OUTPUT_TO_OS_DEBUG_STRING_UPPER "LOG_OUTPUT_TO_OS_DEBUG_STRING"
#define MEMORY_TRACKING_MODE_LOWER          "memory_tracking_mode"
#define MEMORY_TRACKING_MODE_UPPER          "MEMORY_TRACKING_MODE"
#define CAPTURE_FRAMES_LOWER                "capture_frames"
#define CAPTURE_FRAMES_UPPER                "CAPTURE_FRAMES"
#define CAPTURE_TRIGGER_LOWER               "capture_trigger"
#define CAPTURE_TRIGGER_UPPER               "CAPTURE_TRIGGER"
#define PAGE_GUARD_COPY_ON_MAP_LOWER        "page_guard_copy_on_map"
#define PAGE_GUARD_COPY_ON_MAP_UPPER        "PAGE_GUARD_COPY_ON_MAP"
#define PAGE_GUARD_SEPARATE_READ_LOWER      "page_guard_separate_read"
#define PAGE_GUARD_SEPARATE_READ_UPPER      "PAGE_GUARD_SEPARATE_READ"
#define PAGE_GUARD_PERSISTENT_MEMORY_LOWER  "page_guard_persistent_memory"
#define PAGE_GUARD_PERSISTENT_MEMORY_UPPER  "PAGE_GUARD_PERSISTENT_MEMORY"
#define PAGE_GUARD_ALIGN_BUFFER_SIZES_LOWER "page_guard_align_buffer_sizes"
#define PAGE_GUARD_ALIGN_BUFFER_SIZES_UPPER "PAGE_GUARD_ALIGN_BUFFER_SIZES"
#define PAGE_GUARD_TRACK_AHB_MEMORY_LOWER   "page_guard_track_ahb_memory"
#define PAGE_GUARD_TRACK_AHB_MEMORY_UPPER   "PAGE_GUARD_TRACK_AHB_MEMORY"
#define PAGE_GUARD_EXTERNAL_MEMORY_LOWER    "page_guard_external_memory"
#define PAGE_GUARD_EXTERNAL_MEMORY_UPPER    "PAGE_GUARD_EXTERNAL_MEMORY"
// clang-format on

#if defined(__ANDROID__)
// Android Properties
#define GFXRECON_ENV_VAR_PREFIX "debug.gfxrecon."

const char CaptureSettings::kDefaultCaptureFileName[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;

const char kCaptureCompressionTypeEnvVar[]    = GFXRECON_ENV_VAR_PREFIX CAPTURE_COMPRESSION_TYPE_LOWER;
const char kCaptureFileFlushEnvVar[]          = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_FLUSH_LOWER;
const char kCaptureFileNameEnvVar[]           = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_NAME_LOWER;
const char kCaptureFileUseTimestampEnvVar[]   = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_USE_TIMESTAMP_LOWER;
const char kLogAllowIndentsEnvVar[]           = GFXRECON_ENV_VAR_PREFIX LOG_ALLOW_INDENTS_LOWER;
const char kLogBreakOnErrorEnvVar[]           = GFXRECON_ENV_VAR_PREFIX LOG_BREAK_ON_ERROR_LOWER;
const char kLogDetailedEnvVar[]               = GFXRECON_ENV_VAR_PREFIX LOG_DETAILED_LOWER;
const char kLogErrorsToStderrEnvVar[]         = GFXRECON_ENV_VAR_PREFIX LOG_ERRORS_TO_STDERR_LOWER;
const char kLogFileNameEnvVar[]               = GFXRECON_ENV_VAR_PREFIX LOG_FILE_NAME_LOWER;
const char kLogFileCreateNewEnvVar[]          = GFXRECON_ENV_VAR_PREFIX LOG_FILE_CREATE_NEW_LOWER;
const char kLogFileFlushAfterWriteEnvVar[]    = GFXRECON_ENV_VAR_PREFIX LOG_FILE_FLUSH_AFTER_WRITE_LOWER;
const char kLogFileKeepFileOpenEnvVar[]       = GFXRECON_ENV_VAR_PREFIX LOG_FILE_KEEP_OPEN_LOWER;
const char kLogLevelEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX LOG_LEVEL_LOWER;
const char kLogOutputToConsoleEnvVar[]        = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_CONSOLE_LOWER;
const char kLogOutputToOsDebugStringEnvVar[]  = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER;
const char kMemoryTrackingModeEnvVar[]        = GFXRECON_ENV_VAR_PREFIX MEMORY_TRACKING_MODE_LOWER;
const char kCaptureFramesEnvVar[]             = GFXRECON_ENV_VAR_PREFIX CAPTURE_FRAMES_LOWER;
const char kCaptureTriggerEnvVar[]            = GFXRECON_ENV_VAR_PREFIX CAPTURE_TRIGGER_LOWER;
const char kPageGuardCopyOnMapEnvVar[]        = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_COPY_ON_MAP_LOWER;
const char kPageGuardSeparateReadEnvVar[]     = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SEPARATE_READ_LOWER;
const char kPageGuardPersistentMemoryEnvVar[] = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_PERSISTENT_MEMORY_LOWER;
const char kPageGuardAlignBufferSizesEnvVar[] = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_ALIGN_BUFFER_SIZES_LOWER;
const char kPageGuardTrackAhbMemoryEnvVar[]   = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_TRACK_AHB_MEMORY_LOWER;
const char kPageGuardExternalMemoryEnvVar[]   = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_EXTERNAL_MEMORY_LOWER;

#else
// Desktop environment settings
#define GFXRECON_ENV_VAR_PREFIX "GFXRECON_"

const char CaptureSettings::kDefaultCaptureFileName[] = "gfxrecon_capture" GFXRECON_FILE_EXTENSION;

const char kCaptureCompressionTypeEnvVar[]    = GFXRECON_ENV_VAR_PREFIX CAPTURE_COMPRESSION_TYPE_UPPER;
const char kCaptureFileFlushEnvVar[]          = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_FLUSH_UPPER;
const char kCaptureFileNameEnvVar[]           = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_NAME_UPPER;
const char kCaptureFileUseTimestampEnvVar[]   = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_USE_TIMESTAMP_UPPER;
const char kLogAllowIndentsEnvVar[]           = GFXRECON_ENV_VAR_PREFIX LOG_ALLOW_INDENTS_UPPER;
const char kLogBreakOnErrorEnvVar[]           = GFXRECON_ENV_VAR_PREFIX LOG_BREAK_ON_ERROR_UPPER;
const char kLogDetailedEnvVar[]               = GFXRECON_ENV_VAR_PREFIX LOG_DETAILED_UPPER;
const char kLogErrorsToStderrEnvVar[]         = GFXRECON_ENV_VAR_PREFIX LOG_ERRORS_TO_STDERR_UPPER;
const char kLogFileNameEnvVar[]               = GFXRECON_ENV_VAR_PREFIX LOG_FILE_NAME_UPPER;
const char kLogFileCreateNewEnvVar[]          = GFXRECON_ENV_VAR_PREFIX LOG_FILE_CREATE_NEW_UPPER;
const char kLogFileFlushAfterWriteEnvVar[]    = GFXRECON_ENV_VAR_PREFIX LOG_FILE_FLUSH_AFTER_WRITE_UPPER;
const char kLogFileKeepFileOpenEnvVar[]       = GFXRECON_ENV_VAR_PREFIX LOG_FILE_KEEP_OPEN_UPPER;
const char kLogLevelEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX LOG_LEVEL_UPPER;
const char kLogOutputToConsoleEnvVar[]        = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_CONSOLE_UPPER;
const char kLogOutputToOsDebugStringEnvVar[]  = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_OS_DEBUG_STRING_UPPER;
const char kMemoryTrackingModeEnvVar[]        = GFXRECON_ENV_VAR_PREFIX MEMORY_TRACKING_MODE_UPPER;
const char kCaptureFramesEnvVar[]             = GFXRECON_ENV_VAR_PREFIX CAPTURE_FRAMES_UPPER;
const char kPageGuardCopyOnMapEnvVar[]        = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_COPY_ON_MAP_UPPER;
const char kPageGuardSeparateReadEnvVar[]     = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SEPARATE_READ_UPPER;
const char kPageGuardPersistentMemoryEnvVar[] = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_PERSISTENT_MEMORY_UPPER;
const char kPageGuardAlignBufferSizesEnvVar[] = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_ALIGN_BUFFER_SIZES_UPPER;
const char kPageGuardTrackAhbMemoryEnvVar[]   = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_TRACK_AHB_MEMORY_UPPER;
const char kPageGuardExternalMemoryEnvVar[]   = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_EXTERNAL_MEMORY_UPPER;
const char kCaptureTriggerEnvVar[]            = GFXRECON_ENV_VAR_PREFIX CAPTURE_TRIGGER_UPPER;
#endif

// Capture options for settings file.
// clang-format off
const char kSettingsFilter[] = "lunarg_gfxreconstruct.";

const std::string kOptionKeyCaptureCompressionType    = std::string(kSettingsFilter) + std::string(CAPTURE_COMPRESSION_TYPE_LOWER);
const std::string kOptionKeyCaptureFile               = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_NAME_LOWER);
const std::string kOptionKeyCaptureFileForceFlush     = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_FLUSH_LOWER);
const std::string kOptionKeyCaptureFileUseTimestamp   = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_USE_TIMESTAMP_LOWER);
const std::string kOptionKeyLogAllowIndents           = std::string(kSettingsFilter) + std::string(LOG_ALLOW_INDENTS_LOWER);
const std::string kOptionKeyLogBreakOnError           = std::string(kSettingsFilter) + std::string(LOG_BREAK_ON_ERROR_LOWER);
const std::string kOptionKeyLogDetailed               = std::string(kSettingsFilter) + std::string(LOG_DETAILED_LOWER);
const std::string kOptionKeyLogErrorsToStderr         = std::string(kSettingsFilter) + std::string(LOG_ERRORS_TO_STDERR_LOWER);
const std::string kOptionKeyLogFile                   = std::string(kSettingsFilter) + std::string(LOG_FILE_NAME_LOWER);
const std::string kOptionKeyLogFileCreateNew          = std::string(kSettingsFilter) + std::string(LOG_FILE_CREATE_NEW_LOWER);
const std::string kOptionKeyLogFileFlushAfterWrite    = std::string(kSettingsFilter) + std::string(LOG_FILE_FLUSH_AFTER_WRITE_LOWER);
const std::string kOptionKeyLogFileKeepOpen           = std::string(kSettingsFilter) + std::string(LOG_FILE_KEEP_OPEN_LOWER);
const std::string kOptionKeyLogLevel                  = std::string(kSettingsFilter) + std::string(LOG_LEVEL_LOWER);
const std::string kOptionKeyLogOutputToConsole        = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_CONSOLE_LOWER);
const std::string kOptionKeyLogOutputToOsDebugString  = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER);
const std::string kOptionKeyMemoryTrackingMode        = std::string(kSettingsFilter) + std::string(MEMORY_TRACKING_MODE_LOWER);
const std::string kOptionKeyCaptureFrames             = std::string(kSettingsFilter) + std::string(CAPTURE_FRAMES_LOWER);
const std::string kOptionKeyCaptureTrigger            = std::string(kSettingsFilter) + std::string(CAPTURE_TRIGGER_LOWER);
const std::string kOptionKeyPageGuardCopyOnMap        = std::string(kSettingsFilter) + std::string(PAGE_GUARD_COPY_ON_MAP_LOWER);
const std::string kOptionKeyPageGuardSeparateRead     = std::string(kSettingsFilter) + std::string(PAGE_GUARD_SEPARATE_READ_LOWER);
const std::string kOptionKeyPageGuardPersistentMemory = std::string(kSettingsFilter) + std::string(PAGE_GUARD_PERSISTENT_MEMORY_LOWER);
const std::string kOptionKeyPageGuardAlignBufferSizes = std::string(kSettingsFilter) + std::string(PAGE_GUARD_ALIGN_BUFFER_SIZES_LOWER);
const std::string kOptionKeyPageGuardTrackAhbMemory   = std::string(kSettingsFilter) + std::string(PAGE_GUARD_TRACK_AHB_MEMORY_LOWER);
const std::string kOptionKeyPageGuardExternalMemory   = std::string(kSettingsFilter) + std::string(PAGE_GUARD_EXTERNAL_MEMORY_LOWER);

#if defined(ENABLE_LZ4_COMPRESSION)
const format::CompressionType kDefaultCompressionType = format::CompressionType::kLz4;
#else
const format::CompressionType kDefaultCompressionType = format::CompressionType::kNone;
#endif
// clang-format on

CaptureSettings::CaptureSettings() {}

CaptureSettings::~CaptureSettings() {}

void CaptureSettings::LoadSettings(CaptureSettings* settings)
{
    if (settings != nullptr)
    {
        OptionsMap capture_settings;

        LoadOptionsFile(&capture_settings);
        LoadOptionsEnvVar(&capture_settings);
        ProcessOptions(&capture_settings, settings);

        // Valid options are removed as they are read from the OptionsMap.  Therefore, if anything
        // is remaining in it after we're done, it's an invalid setting.
        if (!capture_settings.empty())
        {
            for (auto iter = capture_settings.begin(); iter != capture_settings.end(); ++iter)
            {
                GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized option \"%s\" with value \"%s\"",
                                     iter->first.c_str(),
                                     iter->second.c_str());
            }
        }
    }
}

void CaptureSettings::LoadSingleOptionEnvVar(OptionsMap*        options,
                                             const std::string& environment_variable,
                                             const std::string& option_key)
{
    std::string value = util::platform::GetEnv(environment_variable.c_str());
    if (!value.empty())
    {
        std::string entry = util::settings::RemoveQuotes(value);
        GFXRECON_LOG_INFO(
            "Settings Loader: Found option \"%s\" with value \"%s\"", environment_variable.c_str(), entry.c_str());
        (*options)[option_key] = entry;
    }
}

void CaptureSettings::LoadOptionsEnvVar(OptionsMap* options)
{
    assert(options != nullptr);

    // Capture file environment variables
    LoadSingleOptionEnvVar(options, kCaptureFileNameEnvVar, kOptionKeyCaptureFile);
    LoadSingleOptionEnvVar(options, kCaptureFileUseTimestampEnvVar, kOptionKeyCaptureFileUseTimestamp);
    LoadSingleOptionEnvVar(options, kCaptureCompressionTypeEnvVar, kOptionKeyCaptureCompressionType);
    LoadSingleOptionEnvVar(options, kCaptureFileFlushEnvVar, kOptionKeyCaptureFileForceFlush);

    // Logging environment variables
    LoadSingleOptionEnvVar(options, kLogAllowIndentsEnvVar, kOptionKeyLogAllowIndents);
    LoadSingleOptionEnvVar(options, kLogBreakOnErrorEnvVar, kOptionKeyLogBreakOnError);
    LoadSingleOptionEnvVar(options, kLogDetailedEnvVar, kOptionKeyLogDetailed);
    LoadSingleOptionEnvVar(options, kLogErrorsToStderrEnvVar, kOptionKeyLogErrorsToStderr);
    LoadSingleOptionEnvVar(options, kLogFileNameEnvVar, kOptionKeyLogFile);
    LoadSingleOptionEnvVar(options, kLogFileCreateNewEnvVar, kOptionKeyLogFileCreateNew);
    LoadSingleOptionEnvVar(options, kLogFileFlushAfterWriteEnvVar, kOptionKeyLogFileFlushAfterWrite);
    LoadSingleOptionEnvVar(options, kLogFileKeepFileOpenEnvVar, kOptionKeyLogFileKeepOpen);
    LoadSingleOptionEnvVar(options, kLogLevelEnvVar, kOptionKeyLogLevel);
    LoadSingleOptionEnvVar(options, kLogOutputToConsoleEnvVar, kOptionKeyLogOutputToConsole);
    LoadSingleOptionEnvVar(options, kLogOutputToOsDebugStringEnvVar, kOptionKeyLogOutputToOsDebugString);

    // Memory environment variables
    LoadSingleOptionEnvVar(options, kMemoryTrackingModeEnvVar, kOptionKeyMemoryTrackingMode);

    // Trimming environment variables
    LoadSingleOptionEnvVar(options, kCaptureFramesEnvVar, kOptionKeyCaptureFrames);
    LoadSingleOptionEnvVar(options, kCaptureTriggerEnvVar, kOptionKeyCaptureTrigger);

    // Page guard environment variables
    LoadSingleOptionEnvVar(options, kPageGuardCopyOnMapEnvVar, kOptionKeyPageGuardCopyOnMap);
    LoadSingleOptionEnvVar(options, kPageGuardSeparateReadEnvVar, kOptionKeyPageGuardSeparateRead);
    LoadSingleOptionEnvVar(options, kPageGuardPersistentMemoryEnvVar, kOptionKeyPageGuardPersistentMemory);
    LoadSingleOptionEnvVar(options, kPageGuardAlignBufferSizesEnvVar, kOptionKeyPageGuardAlignBufferSizes);
    LoadSingleOptionEnvVar(options, kPageGuardTrackAhbMemoryEnvVar, kOptionKeyPageGuardTrackAhbMemory);
    LoadSingleOptionEnvVar(options, kPageGuardExternalMemoryEnvVar, kOptionKeyPageGuardExternalMemory);
}

void CaptureSettings::LoadOptionsFile(OptionsMap* options)
{
    assert(options != nullptr);

    std::string settings_filename = util::settings::FindLayerSettingsFile();

    if (!settings_filename.empty())
    {
        GFXRECON_LOG_INFO("Found layer settings file: %s", settings_filename.c_str());

        int32_t result = util::settings::LoadLayerSettingsFile(settings_filename, kSettingsFilter, options);

        if (result == 0)
        {
            GFXRECON_LOG_INFO("Successfully loaded settings from file");
        }
        else
        {
            GFXRECON_LOG_INFO("Failed to load settings from file (errno = %d)", result);
        }
    }
}

void CaptureSettings::ProcessOptions(OptionsMap* options, CaptureSettings* settings)
{
    assert(settings != nullptr);

    // Capture file options
    settings->trace_settings_.capture_file_options.compression_type =
        ParseCompressionTypeString(FindOption(options, kOptionKeyCaptureCompressionType), kDefaultCompressionType);
    settings->trace_settings_.capture_file =
        FindOption(options, kOptionKeyCaptureFile, settings->trace_settings_.capture_file);
    settings->trace_settings_.time_stamp_file = ParseBoolString(FindOption(options, kOptionKeyCaptureFileUseTimestamp),
                                                                settings->trace_settings_.time_stamp_file);
    settings->trace_settings_.force_flush =
        ParseBoolString(FindOption(options, kOptionKeyCaptureFileForceFlush), settings->trace_settings_.force_flush);

    // Memory tracking options
    settings->trace_settings_.memory_tracking_mode = ParseMemoryTrackingModeString(
        FindOption(options, kOptionKeyMemoryTrackingMode), settings->trace_settings_.memory_tracking_mode);

    // Trimming options:
    // trim ranges and trim hotkey are exclusive
    // with trim key will be parsed only
    // if trim ranges is empty, else it will be ignored
    ParseTrimRangeString(FindOption(options, kOptionKeyCaptureFrames), &settings->trace_settings_.trim_ranges);
    std::string trim_key_option = FindOption(options, kOptionKeyCaptureTrigger);
    if (!trim_key_option.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_key = ParseTrimKeyString(trim_key_option);
        }
        else
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignore trim key setting as trim ranges has been specified.");
        }
    }

    // Page guard environment variables
    settings->trace_settings_.page_guard_copy_on_map = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardCopyOnMap), settings->trace_settings_.page_guard_copy_on_map);
    settings->trace_settings_.page_guard_separate_read = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardSeparateRead), settings->trace_settings_.page_guard_separate_read);
    settings->trace_settings_.page_guard_persistent_memory =
        ParseBoolString(FindOption(options, kOptionKeyPageGuardPersistentMemory),
                        settings->trace_settings_.page_guard_persistent_memory);
    settings->trace_settings_.page_guard_align_buffer_sizes =
        ParseBoolString(FindOption(options, kOptionKeyPageGuardAlignBufferSizes),
                        settings->trace_settings_.page_guard_align_buffer_sizes);
    settings->trace_settings_.page_guard_track_ahb_memory = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardTrackAhbMemory), settings->trace_settings_.page_guard_track_ahb_memory);
    settings->trace_settings_.page_guard_external_memory = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardExternalMemory), settings->trace_settings_.page_guard_external_memory);

    // Log options
    settings->log_settings_.use_indent =
        ParseBoolString(FindOption(options, kOptionKeyLogAllowIndents), settings->log_settings_.use_indent);
    settings->log_settings_.break_on_error =
        ParseBoolString(FindOption(options, kOptionKeyLogBreakOnError), settings->log_settings_.break_on_error);
    settings->log_settings_.output_detailed_log_info =
        ParseBoolString(FindOption(options, kOptionKeyLogDetailed), settings->log_settings_.output_detailed_log_info);
    settings->log_settings_.file_name = FindOption(options, kOptionKeyLogFile, settings->log_settings_.file_name);
    settings->log_settings_.create_new =
        ParseBoolString(FindOption(options, kOptionKeyLogFileCreateNew), settings->log_settings_.create_new);
    settings->log_settings_.flush_after_write = ParseBoolString(FindOption(options, kOptionKeyLogFileFlushAfterWrite),
                                                                settings->log_settings_.flush_after_write);
    settings->log_settings_.leave_file_open =
        ParseBoolString(FindOption(options, kOptionKeyLogFileKeepOpen), settings->log_settings_.leave_file_open);
    settings->log_settings_.output_errors_to_stderr = ParseBoolString(FindOption(options, kOptionKeyLogErrorsToStderr),
                                                                      settings->log_settings_.output_errors_to_stderr);
    settings->log_settings_.write_to_console =
        ParseBoolString(FindOption(options, kOptionKeyLogOutputToConsole), settings->log_settings_.write_to_console);
    settings->log_settings_.output_to_os_debug_string = ParseBoolString(
        FindOption(options, kOptionKeyLogOutputToOsDebugString), settings->log_settings_.output_to_os_debug_string);
    settings->log_settings_.min_severity =
        ParseLogLevelString(FindOption(options, kOptionKeyLogLevel), settings->log_settings_.min_severity);
}

std::string CaptureSettings::FindOption(OptionsMap* options, const std::string& key, const std::string& default_value)
{
    assert(options != nullptr);

    std::string result = default_value;

    auto entry = options->find(key);
    if (entry != options->end())
    {
        result = entry->second;
        GFXRECON_LOG_DEBUG("Settings Loader: Found option \"%s\" with value \"%s\"", key.c_str(), result.c_str());

        // Erase the option as it comes in so that we should have no valid options remaining in the
        // map when we're done.
        options->erase(key);
    }

    return result;
}

bool CaptureSettings::ParseBoolString(const std::string& value_string, bool default_value)
{
    bool result = default_value;

    // Checking for "false" or zero, or "true" or a non-zero number.
    if ((util::platform::StringCompareNoCase("true", value_string.c_str()) == 0) || (atoi(value_string.c_str()) != 0))
    {
        result = true;
    }
    else if ((util::platform::StringCompareNoCase("false", value_string.c_str()) == 0) || (value_string == "0"))
    {
        result = false;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized Boolean option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
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

util::Log::Severity CaptureSettings::ParseLogLevelString(const std::string&  value_string,
                                                         util::Log::Severity default_value)
{
    util::Log::Severity result = default_value;

    if (util::platform::StringCompareNoCase("debug", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kDebugSeverity;
    }
    else if (util::platform::StringCompareNoCase("info", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kInfoSeverity;
    }
    else if (util::platform::StringCompareNoCase("warning", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kWarningSeverity;
    }
    else if (util::platform::StringCompareNoCase("error", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kErrorSeverity;
    }
    else if (util::platform::StringCompareNoCase("fatal", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kFatalSeverity;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized log level option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

void CaptureSettings::ParseTrimRangeString(const std::string&                       value_string,
                                           std::vector<CaptureSettings::TrimRange>* ranges)
{
    assert(ranges != nullptr);

    if (!value_string.empty())
    {
        std::istringstream value_string_input;
        value_string_input.str(value_string);

        for (std::string range; std::getline(value_string_input, range, ',');)
        {
            if (range.empty() || (std::count(range.begin(), range.end(), '-') > 1))
            {
                GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid capture frame range \"%s\"", range.c_str());
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
                    GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid capture frame range \"%s\", which contains "
                                         "non-numeric values",
                                         range.c_str());
                    invalid = true;
                    break;
                }
            }

            if (!invalid)
            {
                CaptureSettings::TrimRange trim_range;

                if (values.size() == 1)
                {
                    if (std::count(range.begin(), range.end(), '-') == 0)
                    {
                        trim_range.first = std::stoi(values[0]);
                        trim_range.total = 1;
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid capture frame range \"%s\"",
                                             range.c_str());
                        continue;
                    }
                }
                else if (values.size() == 2)
                {
                    trim_range.first = std::stoi(values[0]);

                    uint32_t last = std::stoi(values[1]);
                    if (last >= trim_range.first)
                    {
                        trim_range.total = (last - trim_range.first) + 1;
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING(
                            "Settings Loader: Ignoring invalid capture frame range \"%s\", where first "
                            "frame is greater than last frame",
                            range.c_str());
                        continue;
                    }
                }
                else
                {
                    GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid capture frame range \"%s\"", range.c_str());
                    continue;
                }

                // Check for invalid start frame of 0.
                if (trim_range.first == 0)
                {
                    GFXRECON_LOG_WARNING(
                        "Settings Loader: Ignoring invalid capture frame range \"%s\", with first frame equal to zero",
                        range.c_str());
                    continue;
                }

                uint32_t next_allowed = 0;

                // Check that start frame is outside the bounds of the previous range.
                if (!ranges->empty())
                {
                    // This produces the number of the frame after the last frame in the range.
                    next_allowed = ranges->back().first + ranges->back().total;
                }

                if (trim_range.first >= next_allowed)
                {
                    ranges->emplace_back(trim_range);
                }
                else
                {
                    GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid capture frame range \"%s\", "
                                         "where start frame precedes the end of the previous range \"%u-%u\"",
                                         range.c_str(),
                                         ranges->back().first,
                                         (next_allowed - 1));
                }
            }
        }
    }
}

std::string CaptureSettings::ParseTrimKeyString(const std::string& value_string)
{
    std::string trim_key;
    if (!value_string.empty())
    {
        trim_key = value_string;
        // Remove whitespace.
        trim_key.erase(std::remove_if(trim_key.begin(), trim_key.end(), ::isspace), trim_key.end());
    }
    else
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid trim trigger key \"%s\"", trim_key.c_str());
    }
    return trim_key;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
