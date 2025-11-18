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

SettingsManager* SettingsManager::singleton_          = nullptr;
uint32_t         SettingsManager::singleton_refcount_ = 0;

SettingsManager* SettingsManager::InitSingleton(format::ApiFamilyId api_family)
{
    GFXRECON_ASSERT(singleton_ == nullptr);
    GFXRECON_ASSERT(singleton_refcount_ == 0);
    singleton_          = new SettingsManager(api_family);
    singleton_refcount_ = 1;

    return singleton_;
}

SettingsManager* SettingsManager::GetSingleton()
{
    GFXRECON_ASSERT(singleton_ != nullptr);
    GFXRECON_ASSERT(singleton_refcount_ != 0);
    singleton_refcount_++;
    return singleton_;
}

void SettingsManager::ReleaseSingleton(bool final_time)
{
    if (singleton_)
    {
        singleton_refcount_--;
        if (singleton_refcount_ == 0)
        {
            delete singleton_;
            singleton_ = nullptr;
        }
        else if (final_time)
        {
            GFXRECON_ASSERT(false && "SettingsManager singleton should have 0 ref count for final release.");
        }
    }
    else
    {
        GFXRECON_ASSERT(singleton_refcount_ == 0);
    }
}

SettingsManager::SettingsManager(format::ApiFamilyId api_family)
{
    if (api_family == format::ApiFamily_Vulkan)
    {
        ReadVulkanCaptureLayerSettingsFile();
    }
    ReadEnvironmentVariables();
}

SettingsManager::~SettingsManager() {}

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
                    // Ignore entries with keys that do not start with the filter prefix as well as
                    // values that do not exist (they can fall back to another setting source).
                    if (!AdjustSettingFromFile(&key[kFilterLength], RemoveQuotes(value)))
                    {
                        success = false;
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
