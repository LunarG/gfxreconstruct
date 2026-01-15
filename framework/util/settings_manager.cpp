/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#include "util/logging.h"
#include "util/settings_manager.h"

#include <array>
#include <cassert>
#include <cerrno>
#include <cstdio>
#include <fstream>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(settings)

std::unique_ptr<SettingsManager> SettingsManager::singleton_;
std::once_flag                   SettingsManager::singleton_flag_;

SettingsManager& SettingsManager::InitSingleton(format::ApiFamilyId api_family)
{
    std::call_once(singleton_flag_, [&]() { singleton_.reset(new SettingsManager(api_family)); });
    return *singleton_;
}

SettingsManager::SettingsManager(format::ApiFamilyId api_family)
{
    switch (api_family)
    {
        case format::ApiFamily_Vulkan:
            ReadVulkanCaptureLayerSettingsFile();
            break;
        case format::ApiFamily_D3D12:
            EnableD3D12SettingsDefaults();
            break;
        default:
            break;
    }
    ReadEnvironmentVariables();
}

SettingsManager::~SettingsManager() {}

// Convert a setting value (received either through a settings file or an environment/property string)
// into a boolean value.
// In this case, any non-zero integer is considered true, and any string value of "true" is considered true.
bool SettingsManager::SettingValueToBool(const std::string& setting_value)
{
    if (util::platform::StringCompareNoCase("true", setting_value.c_str()) == 0 || atoi(setting_value.c_str()) != 0)
    {
        return true;
    }
    return false;
}

// Some D3D defaults are different than Vulkan, those should be initialized here
void SettingsManager::EnableD3D12SettingsDefaults()
{
#ifdef WIN32
    settings_struct_.capture_settings.page_guard_external_memory = true;
#endif
}

// Vulkan alone has the ability to have a layer settings file which can override the defaults.
// This file, though, is considered higher importance than only the default values, meaning it
// can be overridden by environment variables, command-line settings, etc.
// However, read the content if it exists after we have initialized the defaults.
bool SettingsManager::ReadVulkanCaptureLayerSettingsFile()
{
    bool         success           = false;
    const size_t kDefaultTokenSize = 512;
    const char   kCommentDelimiter = '#';
    const size_t kFilterLength     = gfxr_file_layer_prefix_.length();

    std::string settings_filename = FindLayerSettingsFile();
    if (!settings_filename.empty())
    {
        std::ifstream file(settings_filename);

        if (file.good())
        {
            char        key[kDefaultTokenSize]   = { '\0' };
            char        value[kDefaultTokenSize] = { '\0' };
            std::string line;

            std::getline(file, line);
            while (file.good())
            {
                // Strip comments that appear in the line.
                size_t comment_start = line.find_first_of(kCommentDelimiter);
                if (comment_start != std::string::npos)
                {
                    line.erase(comment_start, std::string::npos);
                }

                // This is the same format string that the Vulkan validation layers use.
#if defined(WIN32)
                if (sscanf_s(line.c_str(),
                             " %511[^\r\n\t =] = %511[^\r\n \t]",
                             key,
                             static_cast<uint32_t>(kDefaultTokenSize),
                             value,
                             static_cast<uint32_t>(kDefaultTokenSize)) == 2)
#else
                if (sscanf(line.c_str(), " %511[^\r\n\t =] = %511[^\r\n \t]", key, value) == 2)
#endif
                {
                    // Ignore entries with keys that do not start with the filter prefix.
                    if (platform::StringCompare(key, gfxr_file_layer_prefix_.c_str(), kFilterLength) == 0)
                    {
                        // Call the generated function to adjust the individual setting based on the key
                        // to the incoming value (if appropriate)
                        AdjustSettingFromFile(&key[kFilterLength], RemoveQuotes(value));
                    }
                }

                std::getline(file, line);
            }

            if (file.eof())
            {
                success = true;
            }
            else
            {
                GFXRECON_LOG_ERROR("Invalid file contents in settings file '%s'", settings_filename.c_str());
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Error opening settings file '%s'", settings_filename.c_str());
        }
    }
    return success;
}

// Read the environment/property value as a string.  We worry about converting it based on expected
// type until later.
bool SettingsManager::ReadEnvironmentVariable(const std::string& setting_string, std::string& value)
{
    std::string env_var_name;

#if defined(__ANDROID__)
    env_var_name = android_property_prefix_ + setting_string;
    std::transform(env_var_name.begin(), env_var_name.end(), env_var_name.begin(), ::tolower);
#else
    env_var_name = desktop_env_var_prefix_ + setting_string;
    std::transform(env_var_name.begin(), env_var_name.end(), env_var_name.begin(), ::toupper);
#endif
    std::string env_var_value = util::platform::GetEnv(env_var_name.c_str());
    if (!env_var_value.empty())
    {
        value = RemoveQuotes(env_var_value);
        GFXRECON_LOG_DEBUG("Found environment/property %s with value %s", env_var_name.c_str(), env_var_value.c_str());
        return true;
    }
    return false;
}

#include "generated_settings_manager.cpp"

GFXRECON_END_NAMESPACE(settings)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
