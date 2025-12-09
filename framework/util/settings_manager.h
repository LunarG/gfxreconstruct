/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#ifndef GFXRECON_SETTINGS_MANAGER_H
#define GFXRECON_SETTINGS_MANAGER_H

#include "format/api_call_id.h"
#include "util/defines.h"

#include "util/settings_common.h"
#include "util/settings_loader.h"
#include "util/generated_settings_struct.h"

#include <algorithm>
#include <cstdint>
#include <list>
#include <memory>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(settings)

class SettingsManager
{
  public:
    static SettingsManager& InitSingleton(format::ApiFamilyId api_family);
    static SettingsManager& GetSingleton() { return *singleton_; }
    ~SettingsManager();

    void UpdateDynamicEnvironmentVariables();

    const GfxrSettingsStruct* GetSettingsStruct() const { return &settings_struct_; };

    bool ProcessCommandLine(GfxrToolType                    tool_type,
                            const std::vector<std::string>& command_line_args,
                            std::vector<std::string>&       extra_args)
    {
        bool found_all = true;

        for (size_t cur_arg = 0; cur_arg < command_line_args.size(); ++cur_arg)
        {
            if (command_line_args[cur_arg].at(0) == '-')
            {
                if (!ProcessOptionArgument(tool_type, command_line_args, cur_arg))
                {
                    found_all = false;
                }
            }
            else
            {
                extra_args.push_back(command_line_args[cur_arg]);
            }
        }
        return found_all;
    }

  private:
    SettingsManager(format::ApiFamilyId api_family);

    void AdjustSettingFromFile(const std::string& key, const std::string& value);

    void EnableD3D12SettingsDefaults();
    bool ReadVulkanCaptureLayerSettingsFile();
    void ReadEnvironmentVariables();

    bool ReadEnvironmentVariable(const std::string& setting_string, std::string& value)
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
            GFXRECON_LOG_DEBUG(
                "Found environment/property %s with value %s", env_var_name.c_str(), env_var_value.c_str());
            return true;
        }
        return false;
    }

    bool
    ProcessOptionArgument(GfxrToolType tool_type, const std::vector<std::string>& command_line_args, size_t& cur_arg);

    bool HasArgumentParameter(const std::vector<std::string>& command_line_args, size_t& cur_arg)
    {
        if ((cur_arg + 1) < command_line_args.size())
        {
            // We have space, but does the next argument start with a dash '-', if
            // so, it's another argument, not the parameter for this argument.
            if (command_line_args[cur_arg + 1].at(0) != '-')
            {
                return true;
            }
        }
        return false;
    }

    bool SettingValueToBool(const std::string& setting_value)
    {
        if (util::platform::StringCompareNoCase("true", setting_value.c_str()) == 0 || atoi(setting_value.c_str()) != 0)
        {
            return true;
        }
        return false;
    }

    // Singleton items
    static std::unique_ptr<SettingsManager> singleton_;
    static std::once_flag                   singleton_flag_;

    // General members
    GfxrSettingsStruct settings_struct_;

    // Various prefixes used before settings
    const std::string gfxr_file_layer_prefix_{ "lunarg_gfxreconstruct." };
    std::string       android_property_prefix_{ "debug.gfxrecon." };
    std::string       desktop_env_var_prefix_{ "GFXRECON_" };
};

GFXRECON_END_NAMESPACE(settings)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_SETTINGS_MANAGER_H
