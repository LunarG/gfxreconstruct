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

#include <cassert>
#include <cstdlib>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
// clang-format off
#if defined(__ANDROID__)
const char CaptureSettings::kDefaultCaptureFileName[] = "/sdcard/gfxrecon_capture.gfxr";

// Android Properties
const char kCaptureCompressionTypeEnvVar[]             = "debug.gfxrecon.capture_compression_type";
const char kCaptureFileEnvVar[]                        = "debug.gfxrecon.capture_file";
const char kCaptureFileTimestampEnvVar[]               = "debug.gfxrecon.capture_file_timestamp";
const char kCaptureForceFlushEnvVar[]                  = "debug.gfxrecon.capture_force_flush";
const char kLogAllowIndentsEnvVar[]                    = "debug.gfxrecon.log_allow_indents";
const char kLogBreakOnErrorEnvVar[]                    = "debug.gfxrecon.log_break_on_error";
const char kLogDetailedEnvVar[]                        = "debug.gfxrecon.log_detailed";
const char kLogErrorsToStderrEnvVar[]                  = "debug.gfxrecon.log_errors_to_stderr";
const char kLogFileEnvVar[]                            = "debug.gfxrecon.log_file";
const char kLogFileCreateNewEnvVar[]                   = "debug.gfxrecon.log_file_create_new";
const char kLogFileFlushAfterWriteEnvVar[]             = "debug.gfxrecon.log_file_flush_after_write";
const char kLogFileKeepOpenEnvVar[]                    = "debug.gfxrecon.log_file_keep_open";
const char kLogLevelEnvVar[]                           = "debug.gfxrecon.log_level";
const char kLogOutputToConsoleEnvVar[]                 = "debug.gfxrecon.log_output_to_console";
const char kLogOutputToOsDebugStringEnvVar[]           = "debug.gfxrecon.log_output_to_os_debug_string";
const char kMemoryTrackingModeEnvVar[]                 = "debug.gfxrecon.memory_tracking_mode";
#else // !__ANDROID__
const char CaptureSettings::kDefaultCaptureFileName[] = "gfxrecon_capture.gfxr";

// Desktop Environment Variables
const char kCaptureCompressionTypeEnvVar[]             = "GFXRECON_CAPTURE_COMPRESSION_TYPE";
const char kCaptureFileEnvVar[]                        = "GFXRECON_CAPTURE_FILE";
const char kCaptureFileTimestampEnvVar[]               = "GFXRECON_CAPTURE_FILE_TIMESTAMP";
const char kCaptureForceFlushEnvVar[]                  = "GFXRECON_CAPTURE_FORCE_FLUSH";
const char kLogAllowIndentsEnvVar[]                    = "GFXRECON_LOG_ALLOW_INDENTS";
const char kLogBreakOnErrorEnvVar[]                    = "GFXRECON_LOG_BREAK_ON_ERROR";
const char kLogDetailedEnvVar[]                        = "GFXRECON_LOG_DETAILED";
const char kLogErrorsToStderrEnvVar[]                  = "GFXRECON_LOG_ERRORS_TO_STDERR";
const char kLogFileEnvVar[]                            = "GFXRECON_LOG_FILE";
const char kLogFileCreateNewEnvVar[]                   = "GFXRECON_LOG_FILE_CREATE_NEW";
const char kLogFileFlushAfterWriteEnvVar[]             = "GFXRECON_LOG_FILE_FLUSH_AFTER_WRITE";
const char kLogFileKeepOpenEnvVar[]                    = "GFXRECON_LOG_FILE_KEEP_OPEN";
const char kLogLevelEnvVar[]                           = "GFXRECON_LOG_LEVEL";
const char kLogOutputToConsoleEnvVar[]                 = "GFXRECON_LOG_OUTPUT_TO_CONSOLE";
const char kLogOutputToOsDebugStringEnvVar[]           = "GFXRECON_LOG_OUTPUT_TO_OS_DEBUG_STRING";
const char kMemoryTrackingModeEnvVar[]                 = "GFXRECON_MEMORY_TRACKING_MODE";
#endif

// Settings file values
const std::string kOptionKeyCaptureCompressionType     = std::string("lunarg_gfxrecon.capture_compression_type");
const std::string kOptionKeyCaptureFile                = std::string("lunarg_gfxrecon.capture_file");
const std::string kOptionKeyCaptureFileTimestamp       = std::string("lunarg_gfxrecon.capture_file_timestamp");
const std::string kOptionKeyCaptureForceFlush          = std::string("lunarg_gfxrecon.capture_force_flush");
const std::string kOptionKeyLogAllowIndents            = std::string("lunarg_gfxrecon.log_allow_indents");
const std::string kOptionKeyLogBreakOnError            = std::string("lunarg_gfxrecon.log_break_on_error");
const std::string kOptionKeyLogDetailed                = std::string("lunarg_gfxrecon.log_detailed");
const std::string kOptionKeyLogErrorsToStderr          = std::string("lunarg_gfxrecon.log_errors_to_stderr");
const std::string kOptionKeyLogFile                    = std::string("lunarg_gfxrecon.log_file");
const std::string kOptionKeyLogFileCreateNew           = std::string("lunarg_gfxrecon.log_file_create_new");
const std::string kOptionKeyLogFileFlushAfterWrite     = std::string("lunarg_gfxrecon.log_file_flush_after_write");
const std::string kOptionKeyLogFileKeepOpen            = std::string("lunarg_gfxrecon.log_file_keep_open");
const std::string kOptionKeyLogLevel                   = std::string("lunarg_gfxrecon.log_level");
const std::string kOptionKeyLogOutputToConsole         = std::string("lunarg_gfxrecon.log_output_to_console");
const std::string kOptionKeyLogOutputToOsDebugString   = std::string("lunarg_gfxrecon.log_output_to_os_debug_string");
const std::string kOptionKeyMemoryTrackingMode         = std::string("lunarg_gfxrecon.memory_tracking_mode");

static format::CompressionType ParseCaptureCompressionTypeString(
    const std::string& value_string,
    format::CompressionType default_value)
{
    format::CompressionType result = default_value;
#ifdef ENABLE_LZ4_COMPRESSION
    if (util::platform::StringCompareNoCase("lz4", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kLz4;
    }
#endif // ENABLE_LZ4_COMPRESSION
#ifdef ENABLE_LZ77_COMPRESSION
    if (util::platform::StringCompareNoCase("lz77", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kLz77;
    }
#endif // ENABLE_LZ77_COMPRESSION
    if (util::platform::StringCompareNoCase("none", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kNone;
    }
    return result;
}

static util::Log::Severity ParseLogLevelString(
    const std::string& value_string,
    util::Log::Severity default_value)
{
    util::Log::Severity result = default_value;
    if (util::platform::StringCompareNoCase("command", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kCommandSeverity;
    }
    if (util::platform::StringCompareNoCase("debug", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kDebugSeverity;
    }
    if (util::platform::StringCompareNoCase("info", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kInfoSeverity;
    }
    if (util::platform::StringCompareNoCase("warning", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kWarningSeverity;
    }
    if (util::platform::StringCompareNoCase("error", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kErrorSeverity;
    }
    if (util::platform::StringCompareNoCase("fatal", value_string.c_str()) == 0)
    {
        result = util::Log::Severity::kFatalSeverity;
    }
    return result;
}

static CaptureSettings::MemoryTrackingMode ParseMemoryTrackingModeString(
    const std::string& value_string,
    CaptureSettings::MemoryTrackingMode default_value)
{
    CaptureSettings::MemoryTrackingMode result = default_value;
    if (util::platform::StringCompareNoCase("unassisted", value_string.c_str()) == 0)
    {
        result = CaptureSettings::MemoryTrackingMode::kUnassisted;
    }
    if (util::platform::StringCompareNoCase("assisted", value_string.c_str()) == 0)
    {
        result = CaptureSettings::MemoryTrackingMode::kAssisted;
    }
    if (util::platform::StringCompareNoCase("page_guard", value_string.c_str()) == 0)
    {
        result = CaptureSettings::MemoryTrackingMode::kPageGuard;
    }
    return result;
}

void CaptureSettings::LoadOptionsEnvVar(OptionsMap* options)
{
    assert(options != nullptr);
    LoadSingleOptionEnvVar(options,
                           kCaptureCompressionTypeEnvVar,
                           kOptionKeyCaptureCompressionType);
    LoadSingleOptionEnvVar(options,
                           kCaptureFileEnvVar,
                           kOptionKeyCaptureFile);
    LoadSingleOptionEnvVar(options,
                           kCaptureFileTimestampEnvVar,
                           kOptionKeyCaptureFileTimestamp);
    LoadSingleOptionEnvVar(options,
                           kCaptureForceFlushEnvVar,
                           kOptionKeyCaptureForceFlush);
    LoadSingleOptionEnvVar(options,
                           kLogAllowIndentsEnvVar,
                           kOptionKeyLogAllowIndents);
    LoadSingleOptionEnvVar(options,
                           kLogBreakOnErrorEnvVar,
                           kOptionKeyLogBreakOnError);
    LoadSingleOptionEnvVar(options,
                           kLogDetailedEnvVar,
                           kOptionKeyLogDetailed);
    LoadSingleOptionEnvVar(options,
                           kLogErrorsToStderrEnvVar,
                           kOptionKeyLogErrorsToStderr);
    LoadSingleOptionEnvVar(options,
                           kLogFileEnvVar,
                           kOptionKeyLogFile);
    LoadSingleOptionEnvVar(options,
                           kLogFileCreateNewEnvVar,
                           kOptionKeyLogFileCreateNew);
    LoadSingleOptionEnvVar(options,
                           kLogFileFlushAfterWriteEnvVar,
                           kOptionKeyLogFileFlushAfterWrite);
    LoadSingleOptionEnvVar(options,
                           kLogFileKeepOpenEnvVar,
                           kOptionKeyLogFileKeepOpen);
    LoadSingleOptionEnvVar(options,
                           kLogLevelEnvVar,
                           kOptionKeyLogLevel);
    LoadSingleOptionEnvVar(options,
                           kLogOutputToConsoleEnvVar,
                           kOptionKeyLogOutputToConsole);
    LoadSingleOptionEnvVar(options,
                           kLogOutputToOsDebugStringEnvVar,
                           kOptionKeyLogOutputToOsDebugString);
    LoadSingleOptionEnvVar(options,
                           kMemoryTrackingModeEnvVar,
                           kOptionKeyMemoryTrackingMode);
}

void CaptureSettings::ProcessOptions(OptionsMap* options, CaptureSettings* settings)
{
    assert(settings != nullptr);

    format::CompressionType capture_compression_type_default;
#ifdef ENABLE_LZ4_COMPRESSION
    capture_compression_type_default = format::CompressionType::kLz4;
#else
    capture_compression_type_default = format::CompressionType::kNone;
#endif
    settings->trace_settings_.capture_file_options.compression_type =
        ParseCaptureCompressionTypeString(FindOption(options, kOptionKeyCaptureCompressionType), capture_compression_type_default);
    settings->trace_settings_.capture_file =
        FindOption(options, kOptionKeyCaptureFile, kDefaultCaptureFileName);
    settings->trace_settings_.time_stamp_file =
        ParseBoolString(FindOption(options, kOptionKeyCaptureFileTimestamp), true);
    settings->trace_settings_.force_flush =
        ParseBoolString(FindOption(options, kOptionKeyCaptureForceFlush), false);
    settings->log_settings_.use_indent =
        ParseBoolString(FindOption(options, kOptionKeyLogAllowIndents), settings->log_settings_.use_indent);
    settings->log_settings_.break_on_error =
        ParseBoolString(FindOption(options, kOptionKeyLogBreakOnError), settings->log_settings_.break_on_error);
    settings->log_settings_.output_detailed_log_info =
        ParseBoolString(FindOption(options, kOptionKeyLogDetailed), settings->log_settings_.output_detailed_log_info);
    settings->log_settings_.output_errors_to_stderr =
        ParseBoolString(FindOption(options, kOptionKeyLogErrorsToStderr), settings->log_settings_.output_errors_to_stderr);
    settings->log_settings_.file_name =
        FindOption(options, kOptionKeyLogFile, settings->log_settings_.file_name);
    settings->log_settings_.create_new =
        ParseBoolString(FindOption(options, kOptionKeyLogFileCreateNew), settings->log_settings_.create_new);
    settings->log_settings_.flush_after_write =
        ParseBoolString(FindOption(options, kOptionKeyLogFileFlushAfterWrite), settings->log_settings_.flush_after_write);
    settings->log_settings_.leave_file_open =
        ParseBoolString(FindOption(options, kOptionKeyLogFileKeepOpen), settings->log_settings_.leave_file_open);
    settings->log_settings_.min_severity =
        ParseLogLevelString(FindOption(options, kOptionKeyLogLevel), settings->log_settings_.min_severity);
    settings->log_settings_.write_to_console =
        ParseBoolString(FindOption(options, kOptionKeyLogOutputToConsole), settings->log_settings_.write_to_console);
    settings->log_settings_.output_to_os_debug_string =
        ParseBoolString(FindOption(options, kOptionKeyLogOutputToOsDebugString), settings->log_settings_.output_to_os_debug_string);

    CaptureSettings::MemoryTrackingMode memory_tracking_mode_default = CaptureSettings::MemoryTrackingMode::kPageGuard;
    settings->trace_settings_.memory_tracking_mode =
        ParseMemoryTrackingModeString(FindOption(options, kOptionKeyMemoryTrackingMode), memory_tracking_mode_default);
}

// clang-format on

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
