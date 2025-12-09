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

void SettingsManager::EnableD3D12SettingsDefaults()
{
#ifdef WIN32
    settings_struct_->capture_settings.page_guard_external_memory = true;
#endif
}

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

#include "generated_settings_manager.cpp"

GFXRECON_END_NAMESPACE(settings)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
