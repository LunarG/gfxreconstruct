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

// Settings file values
const char kSettingsFilter[] = "lunarg_gfxrecon.";

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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
