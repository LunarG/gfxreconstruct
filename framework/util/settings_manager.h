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

    const GfxrSettingsStruct* GetSettingsStruct() const { return &settings_struct_; };

    // Generated methods (see generated_settings_manager.cpp for definitions)
    void UpdateDynamicEnvironmentVariables();

  private:
    SettingsManager(format::ApiFamilyId api_family);

    void EnableD3D12SettingsDefaults();
    bool ReadVulkanCaptureLayerSettingsFile();
    bool ReadEnvironmentVariable(const std::string& setting_string, std::string& value);
    bool SettingValueToBool(const std::string& setting_value);

    // Generated methods (see generated_settings_manager.cpp for definitions)
    void AdjustSettingFromFile(const std::string& key, const std::string& value);
    void ReadEnvironmentVariables();

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
