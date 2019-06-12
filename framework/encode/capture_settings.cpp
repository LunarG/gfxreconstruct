/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
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

#include <cassert>
#include <cstdlib>

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
// clang-format on

#if defined(__ANDROID__)
const char CaptureSettings::kDefaultCaptureFileName[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;

// Android Properties
#define GFXRECON_ENV_VAR_PREFIX "debug.gfxrecon."
const char kCaptureCompressionTypeEnvVar[]   = GFXRECON_ENV_VAR_PREFIX CAPTURE_COMPRESSION_TYPE_LOWER;
const char kCaptureFileFlushEnvVar[]         = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_FLUSH_LOWER;
const char kCaptureFileNameEnvVar[]          = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_NAME_LOWER;
const char kCaptureFileUseTimestampEnvVar[]  = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_USE_TIMESTAMP_LOWER;
const char kLogAllowIndentsEnvVar[]          = GFXRECON_ENV_VAR_PREFIX LOG_ALLOW_INDENTS_LOWER;
const char kLogBreakOnErrorEnvVar[]          = GFXRECON_ENV_VAR_PREFIX LOG_BREAK_ON_ERROR_LOWER;
const char kLogDetailedEnvVar[]              = GFXRECON_ENV_VAR_PREFIX LOG_DETAILED_LOWER;
const char kLogErrorsToStderrEnvVar[]        = GFXRECON_ENV_VAR_PREFIX LOG_ERRORS_TO_STDERR_LOWER;
const char kLogFileNameEnvVar[]              = GFXRECON_ENV_VAR_PREFIX LOG_FILE_NAME_LOWER;
const char kLogFileCreateNewEnvVar[]         = GFXRECON_ENV_VAR_PREFIX LOG_FILE_CREATE_NEW_LOWER;
const char kLogFileFlushAfterWriteEnvVar[]   = GFXRECON_ENV_VAR_PREFIX LOG_FILE_FLUSH_AFTER_WRITE_LOWER;
const char kLogFileKeepFileOpenEnvVar[]      = GFXRECON_ENV_VAR_PREFIX LOG_FILE_KEEP_OPEN_LOWER;
const char kLogLevelEnvVar[]                 = GFXRECON_ENV_VAR_PREFIX LOG_LEVEL_LOWER;
const char kLogOutputToConsoleEnvVar[]       = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_CONSOLE_LOWER;
const char kLogOutputToOsDebugStringEnvVar[] = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER;
const char kMemoryTrackingModeEnvVar[]       = GFXRECON_ENV_VAR_PREFIX MEMORY_TRACKING_MODE_LOWER;
#else
const char CaptureSettings::kDefaultCaptureFileName[] = "gfxrecon_capture" GFXRECON_FILE_EXTENSION;

// Desktop environment settings
#define GFXRECON_ENV_VAR_PREFIX "GFXRECON_"
const char kCaptureCompressionTypeEnvVar[]   = GFXRECON_ENV_VAR_PREFIX CAPTURE_COMPRESSION_TYPE_UPPER;
const char kCaptureFileFlushEnvVar[]         = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_FLUSH_UPPER;
const char kCaptureFileNameEnvVar[]          = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_NAME_UPPER;
const char kCaptureFileUseTimestampEnvVar[]  = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_USE_TIMESTAMP_UPPER;
const char kLogAllowIndentsEnvVar[]          = GFXRECON_ENV_VAR_PREFIX LOG_ALLOW_INDENTS_UPPER;
const char kLogBreakOnErrorEnvVar[]          = GFXRECON_ENV_VAR_PREFIX LOG_BREAK_ON_ERROR_UPPER;
const char kLogDetailedEnvVar[]              = GFXRECON_ENV_VAR_PREFIX LOG_DETAILED_UPPER;
const char kLogErrorsToStderrEnvVar[]        = GFXRECON_ENV_VAR_PREFIX LOG_ERRORS_TO_STDERR_UPPER;
const char kLogFileNameEnvVar[]              = GFXRECON_ENV_VAR_PREFIX LOG_FILE_NAME_UPPER;
const char kLogFileCreateNewEnvVar[]         = GFXRECON_ENV_VAR_PREFIX LOG_FILE_CREATE_NEW_UPPER;
const char kLogFileFlushAfterWriteEnvVar[]   = GFXRECON_ENV_VAR_PREFIX LOG_FILE_FLUSH_AFTER_WRITE_UPPER;
const char kLogFileKeepFileOpenEnvVar[]      = GFXRECON_ENV_VAR_PREFIX LOG_FILE_KEEP_OPEN_UPPER;
const char kLogLevelEnvVar[]                 = GFXRECON_ENV_VAR_PREFIX LOG_LEVEL_UPPER;
const char kLogOutputToConsoleEnvVar[]       = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_CONSOLE_UPPER;
const char kLogOutputToOsDebugStringEnvVar[] = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_OS_DEBUG_STRING_UPPER;
const char kMemoryTrackingModeEnvVar[]       = GFXRECON_ENV_VAR_PREFIX MEMORY_TRACKING_MODE_UPPER;
#endif

// Capture options for settings file.
// clang-format off
const char kSettingsFilter[] = "lunarg_gfxrecon.";
const std::string kOptionKeyCaptureCompressionType   = std::string(kSettingsFilter) + std::string(CAPTURE_COMPRESSION_TYPE_LOWER);
const std::string kOptionKeyCaptureFile              = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_NAME_LOWER);
const std::string kOptionKeyCaptureFileForceFlush    = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_FLUSH_LOWER);
const std::string kOptionKeyCaptureFileUseTimestamp  = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_USE_TIMESTAMP_LOWER);
const std::string kOptionKeyLogAllowIndents          = std::string(kSettingsFilter) + std::string(LOG_ALLOW_INDENTS_LOWER);
const std::string kOptionKeyLogBreakOnError          = std::string(kSettingsFilter) + std::string(LOG_BREAK_ON_ERROR_LOWER);
const std::string kOptionKeyLogDetailed              = std::string(kSettingsFilter) + std::string(LOG_DETAILED_LOWER);
const std::string kOptionKeyLogErrorsToStderr        = std::string(kSettingsFilter) + std::string(LOG_ERRORS_TO_STDERR_LOWER);
const std::string kOptionKeyLogFile                  = std::string(kSettingsFilter) + std::string(LOG_FILE_NAME_LOWER);
const std::string kOptionKeyLogFileCreateNew         = std::string(kSettingsFilter) + std::string(LOG_FILE_CREATE_NEW_LOWER);
const std::string kOptionKeyLogFileFlushAfterWrite   = std::string(kSettingsFilter) + std::string(LOG_FILE_FLUSH_AFTER_WRITE_LOWER);
const std::string kOptionKeyLogFileKeepOpen          = std::string(kSettingsFilter) + std::string(LOG_FILE_KEEP_OPEN_LOWER);
const std::string kOptionKeyLogLevel                 = std::string(kSettingsFilter) + std::string(LOG_LEVEL_LOWER);
const std::string kOptionKeyLogOutputToConsole       = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_CONSOLE_LOWER);
const std::string kOptionKeyLogOutputToOsDebugString = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER);
const std::string kOptionKeyMemoryTrackingMode       = std::string(kSettingsFilter) + std::string(MEMORY_TRACKING_MODE_LOWER);
// clang-format on

#if defined(ENABLE_LZ4_COMPRESSION)
const format::CompressionType kDefaultCompressionType = format::CompressionType::kLz4;
#else
const format::CompressionType kDefaultCompressionType = format::CompressionType::kNone;
#endif

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
        GFXRECON_LOG_INFO(
            "Settings Loader: Found option \"%s\" with value \"%s\"", environment_variable.c_str(), value.c_str());
        (*options)[option_key] = value;
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
    settings->trace_settings_.memory_tracking_mode = ParseMemoryTrackingModeString(
        FindOption(options, kOptionKeyMemoryTrackingMode), settings->trace_settings_.memory_tracking_mode);
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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
