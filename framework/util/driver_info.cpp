/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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
#if GFXRECON_AGS_SUPPORT
#include "amd_ags.h"
#endif // GFXRECON_AGS_SUPPORT
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
    for (uint32_t i = 0; i < known_user_mode_drivers.size(); i++)
    {
        std::string umd_path = util::filepath::FindModulePath(known_user_mode_drivers[i], true);

        if (umd_path.empty() == false)
        {
            return umd_path;
        }
    }

    return "";
}

bool AMD_GetAGSInfo(std::string& driver_info)
{
    bool driver_info_read = false;
#if GFXRECON_AGS_SUPPORT
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
                "AMD Radeon software version: " + static_cast<std::string>(ags_gpu_info.radeonSoftwareVersion) + "\n\t";
        }

        // Read driver version
        if (ags_gpu_info.driverVersion != "")
        {
            driver_info += "AMD driver version: " + static_cast<std::string>(ags_gpu_info.driverVersion) + "\n\t";
        }

        driver_info_read = true;

        agsDeInitialize(ags_context);
    }
#endif // GFXRECON_AGS_SUPPORT
    return driver_info_read;
}

bool AMD_GetUMDInfo(const std::string& active_driver_path, std::string& driver_info)
{
    bool umd_read = false;
#if defined(WIN32) && !defined(_M_ARM64)

    if (active_driver_path.empty() == false)
    {
        filepath::FileInfo file_info = {};
        strncpy_s(file_info.AppName,
                  sizeof(file_info.AppName),
                  active_driver_path.substr(active_driver_path.find_last_of("/\\") + 1).c_str(),
                  active_driver_path.substr(active_driver_path.find_last_of("/\\") + 1).length());

        GetFileInfo(file_info, active_driver_path);
        if (file_info.FileVersion != "")
        {
            driver_info += "AMD UMD version (" + static_cast<std::string>(file_info.AppName) +
                           "): " + static_cast<std::string>(file_info.FileVersion) + "\n\t";
        }

        umd_read = true;
    }
#endif
    return umd_read;
}

#if defined(WIN32)
int GetRegSubkeys(HKEY& dx_key_handle, DWORD& num_of_adapters, DWORD& sub_key_max_length)
{
    // Fetch registry data
    LSTATUS return_code =
        ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\DirectX", 0, KEY_READ, &dx_key_handle);

    if (return_code != ERROR_SUCCESS)
    {
        return EXIT_FAILURE;
    }

    // Find all subkeys

    return_code = ::RegQueryInfoKey(dx_key_handle,
                                    nullptr,
                                    nullptr,
                                    nullptr,
                                    &num_of_adapters,
                                    &sub_key_max_length,
                                    nullptr,
                                    nullptr,
                                    nullptr,
                                    nullptr,
                                    nullptr,
                                    nullptr);
    sub_key_max_length += 1; // include the null character

    return return_code;
}

LSTATUS GetRegData(HKEY                     dx_key_handle,
                   DWORD                    num_of_adapters,
                   DWORD                    sub_key_max_length,
                   std::string&             driver_info,
                   const std::vector<LUID>& adapter_luids)
{
    LSTATUS     return_code        = ERROR_SUCCESS;
    std::string driver_version     = "";
    std::string UMD_version        = "";
    uint64_t    driver_version_raw = 0;
    uint64_t    UMD_version_raw    = 0;

    char* sub_key_name = new char[sub_key_max_length];
    for (DWORD i = 0; i < num_of_adapters; ++i)
    {
        DWORD sub_key_length = sub_key_max_length;

        return_code =
            ::RegEnumKeyEx(dx_key_handle, i, sub_key_name, &sub_key_length, nullptr, nullptr, nullptr, nullptr);

        if (return_code == ERROR_SUCCESS)
        {
            LUID  adapterLUID = {};
            DWORD qword_size  = MAX_PATH;

            return_code = ::RegGetValue(
                dx_key_handle, sub_key_name, ("AdapterLuid"), RRF_RT_QWORD, nullptr, &adapterLUID, &qword_size);

            bool adapter_match = false;
            if (return_code == ERROR_SUCCESS) // If we were able to retrieve the registry values
                                              // and if the vendor ID and device ID match
            {
                for (auto adapter_info : adapter_luids)
                {
                    if (adapterLUID.HighPart == adapter_info.HighPart && adapterLUID.LowPart == adapter_info.LowPart)
                    {
                        adapter_match = true;
                    }

                    if (adapter_match == true)
                    {
                        // Retrieve the driver version

                        if (::RegGetValue(dx_key_handle,
                                          sub_key_name,
                                          "DriverVersion",
                                          RRF_RT_QWORD,
                                          nullptr,
                                          &driver_version_raw,
                                          &qword_size) == ERROR_SUCCESS)
                        {
                            driver_version = ConvertDataToVersionNumber(driver_version_raw);
                        }

                        if (::RegGetValue(dx_key_handle,
                                          sub_key_name,
                                          "UMDVersion",
                                          RRF_RT_QWORD,
                                          nullptr,
                                          &UMD_version_raw,
                                          &qword_size) == ERROR_SUCCESS)
                        {
                            UMD_version = ConvertDataToVersionNumber(UMD_version_raw);
                        }
                        driver_info += "System driver version: " + driver_version +
                                       "\n\tSystem UMD version: " + UMD_version + "\n";
                    }
                }
            }
        }
    }

    return_code = ::RegCloseKey(dx_key_handle);

    delete[] sub_key_name;

    return return_code;
}

bool GetDriverInfo(std::string& driver_info, format::ApiFamilyId api_family, std::vector<LUID>& adapter_luids)
{
    static std::string cached_driver_info    = "";
    bool               driver_info_available = false;

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
        if (RegistryDxDriverVersion(cached_driver_info, adapter_luids))
        {
            driver_info = cached_driver_info;

            driver_info_available = true;
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

bool RegistryDxDriverVersion(std::string& driver_info, const std::vector<LUID>& adapter_luids)
{
    bool driver_info_found = false;

    HKEY    dx_key_handle      = nullptr;
    DWORD   num_of_adapters    = 0;
    DWORD   sub_key_max_length = 0;
    LSTATUS return_code        = GetRegSubkeys(dx_key_handle, num_of_adapters, sub_key_max_length);
    if (return_code == ERROR_SUCCESS)
    {
        return_code = GetRegData(dx_key_handle, num_of_adapters, sub_key_max_length, driver_info, adapter_luids);
        if (return_code == ERROR_SUCCESS)
        {
            driver_info_found = true;
        }
    }

    return driver_info_found;
}

#endif

std::string ConvertDataToVersionNumber(uint64_t data)
{
    uint16_t    version[4] = {};
    std::string str_version;
    version[0]  = (uint16_t)((data & 0xFFFF000000000000) >> 16 * 3);
    version[1]  = (uint16_t)((data & 0x0000FFFF00000000) >> 16 * 2);
    version[2]  = (uint16_t)((data & 0x00000000FFFF0000) >> 16 * 1);
    version[3]  = (uint16_t)((data & 0x000000000000FFFF));
    str_version = std::to_string(version[0]) + "." + std::to_string(version[1]) + "." + std::to_string(version[2]) +
                  "." + std::to_string(version[3]);

    return str_version;
}

bool AMD_IsDriverActive(const std::string& umd_path)
{
    return (umd_path.find(amd_d3d12_driver_32) != std::string::npos) ||
           (umd_path.find(amd_d3d12_driver_64) != std::string::npos);
}

GFXRECON_END_NAMESPACE(driverinfo)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
