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

#include "encode/capture_settings.h"

#include "util/file_path.h"
#include "util/platform.h"
#include "util/settings_loader.h"

#include <cassert>
#include <cstdlib>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

#if defined(__ANDROID__)
const char kDefaultCaptureFile[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;
const char kCaptureFileEnvVar[]  = "debug.gfxrecon.capture_file";
#else
const char                    kDefaultCaptureFile[]   = "gfxrecon_capture" GFXRECON_FILE_EXTENSION;
const char                    kCaptureFileEnvVar[]    = "GFXRECON_CAPTURE_FILE";
#endif
const char kSettingsFilter[] = "lunarg_gfxrecon.";

#if defined(ENABLE_LZ4_COMPRESSION)
const format::CompressionType kDefaultCompressionType = format::CompressionType::kLz4;
#else
const format::CompressionType kDefaultCompressionType = format::CompressionType::kNone;
#endif

// Capture option names for settings file.
const std::string kOptionKeyCaptureFile        = std::string(kSettingsFilter) + "capture_file";
const std::string kOptionKeyTimestampFile      = std::string(kSettingsFilter) + "timestamp_file";
const std::string kOptionKeyMemoryTrackingMode = std::string(kSettingsFilter) + "memory_tracking_mode";
const std::string kOptionKeyCompressionType    = std::string(kSettingsFilter) + "compression_type";

// Logging options from settings file.
const std::string kOptionLogLevel = std::string(kSettingsFilter) + "log_level";
const std::string kOptionLogFile  = std::string(kSettingsFilter) + "log_file";

CaptureSettings::CaptureSettings() :
    capture_file_(kDefaultCaptureFile), timestamped_filename_(true), memory_tracking_mode_(kPageGuard)
{}

CaptureSettings::~CaptureSettings() {}

void CaptureSettings::LoadSettings(CaptureSettings* settings)
{
    if (settings != nullptr)
    {
        OptionsMap capture_settings;

        LoadOptionsFile(&capture_settings);
        LoadOptionsEnvVar(&capture_settings);
        ProcessOptions(capture_settings, settings);
    }
}

void CaptureSettings::LoadOptionsEnvVar(OptionsMap* options)
{
    assert(options != nullptr);

    std::string env_variable = util::platform::GetEnv(kCaptureFileEnvVar);
    if (!env_variable.empty())
    {
        (*options)[kOptionKeyCaptureFile] = env_variable;
    }
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

void CaptureSettings::ProcessOptions(const OptionsMap& options, CaptureSettings* settings)
{
    assert(settings != nullptr);

    settings->capture_file_ = FindOption(options, kOptionKeyCaptureFile, settings->capture_file_);
    settings->timestamped_filename_ =
        ParseBoolString(FindOption(options, kOptionKeyTimestampFile), settings->timestamped_filename_);
    settings->memory_tracking_mode_ = ParseMemoryTrackingModeString(FindOption(options, kOptionKeyMemoryTrackingMode),
                                                                    settings->memory_tracking_mode_);

    settings->capture_file_options_.compression_type =
        ParseCompressionTypeString(FindOption(options, kOptionKeyCompressionType), kDefaultCompressionType);

    settings->log_settings_.min_severity =
        ParseLogLevelString(FindOption(options, kOptionLogLevel), settings->log_settings_.min_severity);
    settings->log_settings_.file_name = FindOption(options, kOptionLogFile, settings->log_settings_.file_name);
}

std::string
CaptureSettings::FindOption(const OptionsMap& options, const std::string& key, const std::string& default_value)
{
    std::string result = default_value;

    auto entry = options.find(key);
    if (entry != options.end())
    {
        result = entry->second;
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
    else if (util::platform::StringCompareNoCase("lz77", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kLz77;
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
