/*
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#include "util/driver_info.h"
#include "util/file_path.h"
#include "util/date_time.h"
#include "format/format.h"

#if defined(WIN32)
#include "amd_ags.h"
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winver.h>
#include <windows.h>
#include <psapi.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#include <unordered_map>
#include <fstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(driverinfo)

std::string FindLoadedDriverModule(const std::vector<std::string>& known_user_mode_drivers)
{
#if defined(WIN32)
    HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());

    if (process != nullptr)
    {
        const int max_module_count          = 1024;
        HMODULE   modules[max_module_count] = {};
        DWORD     size                      = 0;

        // Get a list of all the modules in this process.
        if (EnumProcessModules(process, modules, sizeof(modules), &size))
        {
            for (uint32_t i = 0; i < (size / sizeof(HMODULE)); i++)
            {
                TCHAR enumerated_module[MAX_PATH] = {};

                if (GetModuleFileNameEx(
                        process, modules[i], enumerated_module, sizeof(enumerated_module) / sizeof(TCHAR)))
                {
                    std::string const module_path = enumerated_module;
                    std::string const module_name = module_path.substr(module_path.find_last_of("/\\") + 1).c_str();

                    for (uint32_t j = 0; j < known_user_mode_drivers.size(); j++)
                    {
                        if (known_user_mode_drivers[j] == module_name)
                        {
                            return module_path;
                        }
                    }
                }
            }
        }

        CloseHandle(process);
    }
#endif
    return "";
}

bool AMD_GetAGSInfo(std::string& driver_info)
{
    bool driver_info_read = false;
#if defined(WIN32)
    AGSConfiguration ags_config   = {};
    AGSContext*      ags_context  = nullptr;
    AGSGPUInfo       ags_gpu_info = {};

    if (agsInitialize(AGS_MAKE_VERSION(AMD_AGS_VERSION_MAJOR, AMD_AGS_VERSION_MINOR, AMD_AGS_VERSION_PATCH),
                      &ags_config,
                      &ags_context,
                      &ags_gpu_info) == AGS_SUCCESS)
    {
        // Read Radeon Software version
        if (ags_gpu_info.radeonSoftwareVersion != "")
        {
            driver_info +=
                "Radeon software version: " + static_cast<std::string>(ags_gpu_info.radeonSoftwareVersion) + "\n\t";
        }

        // Read driver version
        if (ags_gpu_info.driverVersion != "")
        {
            driver_info += "Release version: " + static_cast<std::string>(ags_gpu_info.driverVersion) + "\n\t";
        }

        driver_info_read = true;

        agsDeInitialize(ags_context);
    }
#endif
    return driver_info_read;
}

bool AMD_GetUMDInfo(const std::string& active_driver_path, std::string& driver_info)
{
    bool umd_read = false;
#if defined(WIN32)

    if (active_driver_path.empty() == false)
    {
        filepath::FileInfo file_info = {};
        strncpy_s(file_info.AppName,
                  sizeof(file_info.AppName),
                  active_driver_path.substr(active_driver_path.find_last_of("/\\") + 1).c_str(),
                  active_driver_path.substr(active_driver_path.find_last_of("/\\") + 1).length());

        GetApplicationFileExeVersion(file_info, active_driver_path);
        if (file_info.FileVersion != "")
        {
            driver_info += "UMD version (" + static_cast<std::string>(file_info.AppName) +
                           "): " + static_cast<std::string>(file_info.FileVersion) + "\n\t ";
        }

        umd_read = true;
    }
#endif
    return umd_read;
}

bool AMD_IsDriverActive(const std::string& umd_path)
{
    return (umd_path.find(amd_d3d12_driver_32) != std::string::npos) ||
           (umd_path.find(amd_d3d12_driver_64) != std::string::npos);
}

bool GetDriverInfo(std::string& driver_info, format::ApiFamilyId api_family)
{
    static std::string cached_driver_info = "";

    bool driver_info_available = false;

    // If driver info has not been retrieved, then get it
    if (cached_driver_info.empty())
    {
        std::vector<std::string> known_user_mode_drivers;

        if (api_family == format::ApiFamilyId::ApiFamily_D3D12)
        {
            known_user_mode_drivers.push_back(amd_d3d12_driver_32);
            known_user_mode_drivers.push_back(amd_d3d12_driver_64);
        }

        std::string active_driver_path = FindLoadedDriverModule(known_user_mode_drivers);

        if (AMD_IsDriverActive(active_driver_path))
        {
            if (AMD_GetAGSInfo(cached_driver_info))
            {
                if (AMD_GetUMDInfo(active_driver_path, cached_driver_info))
                {
                    driver_info = cached_driver_info;

                    driver_info_available = true;
                }
            }
        }
    }

    // If driver info has already been retrieved, then return that one
    else
    {
        driver_info = cached_driver_info;

        driver_info_available = true;
    }

    return driver_info_available;
}

GFXRECON_END_NAMESPACE(driverinfo)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
