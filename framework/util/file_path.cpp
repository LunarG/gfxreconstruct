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

#include "util/file_path.h"

#include "util/date_time.h"

#if defined(WIN32)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <winver.h>
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif
#include <unordered_map>
#include <fstream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(filepath)

bool Exists(const std::string& path)
{
#if defined(WIN32)
    return (GetFileAttributesA(path.c_str()) != INVALID_FILE_ATTRIBUTES);
#else
    struct stat info;
    return (stat(path.c_str(), &info) == 0);
#endif
}

bool FilesEqual(const std::string& first, const std::string& second)
{
    std::ifstream first_stream(first, std::ifstream::binary);
    std::ifstream second_stream(second, std::ifstream::binary);

    return std::equal(std::istreambuf_iterator<char>(first_stream.rdbuf()),
                      std::istreambuf_iterator<char>(),
                      std::istreambuf_iterator<char>(second_stream.rdbuf()));
}

bool IsFile(const std::string& path)
{
    bool is_file = false;

#if defined(WIN32)
    DWORD attribs = GetFileAttributesA(path.c_str());
    if ((attribs != INVALID_FILE_ATTRIBUTES) && ((attribs & FILE_ATTRIBUTE_DIRECTORY) != FILE_ATTRIBUTE_DIRECTORY))
    {
        is_file = true;
    }
#else
    struct stat info;
    if ((stat(path.c_str(), &info) == 0) && (S_ISREG(info.st_mode)))
    {
        is_file = true;
    }
#endif

    return is_file;
}

bool IsDirectory(const std::string& path)
{
    bool is_dir = false;

#if defined(WIN32)
    DWORD attribs = GetFileAttributesA(path.c_str());
    if ((attribs != INVALID_FILE_ATTRIBUTES) && ((attribs & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY))
    {
        is_dir = true;
    }
#else
    struct stat info;
    if ((stat(path.c_str(), &info) == 0) && (S_ISDIR(info.st_mode)))
    {
        is_dir = true;
    }
#endif

    return is_dir;
}

std::string Join(const std::string& lhs, const std::string& rhs)
{
    std::string joined;

    if (!lhs.empty())
    {
        joined = lhs;

        if (!rhs.empty())
        {
            bool lhs_has_sep = (lhs.back() == kPathSep);
            bool rhs_has_sep = (rhs.front() == kPathSep);

#if defined(WIN32)
            // For Windows, we can accept either path separator.
            lhs_has_sep = lhs_has_sep || (lhs.back() == kAltPathSep);
            rhs_has_sep = rhs_has_sep || (rhs.front() == kAltPathSep);
#endif

            if (lhs_has_sep && rhs_has_sep)
            {
                // Both strings to be joined have a separator, so strip the separator from rhs.
                joined += rhs.substr(1, std::string::npos);
            }
            else
            {
                // Only one string has a path seprator and both can be joined without modification, or neither string
                // has a path separator and it has to be added.
                if (!lhs_has_sep && !rhs_has_sep)
                {
                    joined += kPathSep;
                }

                joined += rhs;
            }
        }
    }
    else if (!rhs.empty())
    {
        // When lhs is empty, we can use rhs without additional processing.
        joined = rhs;
    }

    return joined;
}

std::string InsertFilenamePostfix(const std::string& filename, const std::string& postfix)
{
    std::string file_extension;
    std::string file_part;
    size_t      sep_index = filename.rfind('.');

    if (sep_index != std::string::npos)
    {
        file_extension = filename.substr(sep_index);
        file_part      = filename.substr(0, sep_index);

        return file_part + postfix + file_extension;
    }

    return filename + postfix;
}

std::string GenerateTimestampedFilename(const std::string& filename, bool use_gmt)
{
    std::string timestamp = "_";
    timestamp += util::datetime::GetDateTimeString(use_gmt);
    return InsertFilenamePostfix(filename, timestamp);
}

bool GetWindowsSystemLibrariesPath(std::string& base_path)
{
#if defined(WIN32)
    std::string windows_dir = util::platform::GetEnv("WINDIR");

    char module_name[MAX_PATH] = {};
    GetModuleFileNameA(nullptr, module_name, MAX_PATH);

    DWORD bin_type = 0;
    bool  success  = GetBinaryTypeA(module_name, &bin_type) == TRUE;

    if (success == true)
    {
        if (bin_type == SCS_64BIT_BINARY)
        {
            windows_dir += "\\System32";
        }
        else if (bin_type == SCS_32BIT_BINARY)
        {
            windows_dir += "\\SysWOW64";
        }

        base_path = windows_dir;
    }

    return success;
#else
    return false;
#endif
}

void UpdateExeFileInfo(ExeInfoMember member, const std::string& value, FileInfo& info)
{
#if defined(WIN32)
    if (member == kExeInfoCompanyName)
    {
        strncpy_s(info.CompanyName, sizeof(info.CompanyName), value.c_str(), value.length());
    }
    else if (member == kExeInfoFileDescription)
    {
        strncpy_s(info.FileDescription, sizeof(info.FileDescription), value.c_str(), value.length());
    }
    else if (member == kExeInfoFileVersion)
    {
        strncpy_s(info.FileVersion, sizeof(info.FileVersion), value.c_str(), value.length());
    }
    else if (member == kExeInfoInternalName)
    {
        strncpy_s(info.InternalName, sizeof(info.InternalName), value.c_str(), value.length());
    }
    else if (member == kExeInfoOriginalFilename)
    {
        strncpy_s(info.OriginalFilename, sizeof(info.OriginalFilename), value.c_str(), value.length());
    }
    else if (member == kExeInfoProductName)
    {
        strncpy_s(info.ProductName, sizeof(info.ProductName), value.c_str(), value.length());
    }
    else if (member == kExeInfoProductVersion)
    {
        strncpy_s(info.ProductVersion, sizeof(info.ProductVersion), value.c_str(), value.length());
    }
#endif
}

bool QueryStringFileInfo(
    const void* ver_data, std::string& ver_ret_val, uint32_t& query_size, uint32_t len, const char* predef_strings)
{
    bool found = false;
#if defined(WIN32)
    PSTR ver_ret_val_;
    char query_str[4096] = {};
    sprintf_s(query_str, "\\StringFileInfo\\%04X%04X\\%s", GetUserDefaultLangID(), len, predef_strings);
    found = VerQueryValue((LPSTR)ver_data, query_str, (LPVOID*)&ver_ret_val_, &query_size);
    if (found)
    {
        ver_ret_val = ver_ret_val_;
    }
#endif
    return found;
}

void GetApplicationFileExeVersion(FileInfo& exe_info, const std::string& file_path)
{
#if defined(WIN32)
    DWORD ver_size = GetFileVersionInfoSize(file_path.c_str(), nullptr);

    if (ver_size > 0)
    {
        std::vector<uint8_t> ver_data(ver_size);

        if (file_path.empty() == false)
        {
            if (GetFileVersionInfo(file_path.c_str(), 0, ver_size, ver_data.data()))
            {
                LPBYTE buffer     = nullptr;
                UINT   query_size = 0;

                if (VerQueryValue(ver_data.data(), "\\", (VOID FAR * FAR*)&buffer, &query_size))
                {
                    if (query_size > 0)
                    {
                        static constexpr int code_page_idx_1  = 1252;
                        static constexpr int code_page_idx_2  = 1200;
                        static constexpr int exe_version_mask = 0xffff;

                        VS_FIXEDFILEINFO* ver_info = reinterpret_cast<VS_FIXEDFILEINFO*>(buffer);

                        exe_info.AppVersion[0] = (ver_info->dwFileVersionMS >> 16) & exe_version_mask;
                        exe_info.AppVersion[1] = (ver_info->dwFileVersionMS >> 0) & exe_version_mask;
                        exe_info.AppVersion[2] = (ver_info->dwFileVersionLS >> 16) & exe_version_mask;
                        exe_info.AppVersion[3] = (ver_info->dwFileVersionLS >> 0) & exe_version_mask;

                        static const std::unordered_map<ExeInfoMember, const char*> query_map{
                            { kExeInfoCompanyName, "CompanyName" },
                            { kExeInfoFileDescription, "FileDescription" },
                            { kExeInfoFileVersion, "FileVersion" },
                            { kExeInfoInternalName, "InternalName" },
                            { kExeInfoOriginalFilename, "OriginalFilename" },
                            { kExeInfoProductName, "ProductName" },
                            { kExeInfoProductVersion, "ProductVersion" },
                        };

                        for (auto& it : query_map)
                        {
                            std::string ver_ret_val = "N/A";
                            BOOL        found       = QueryStringFileInfo(
                                ver_data.data(), ver_ret_val, query_size, code_page_idx_1, it.second);

                            if (!found)
                            {
                                found = QueryStringFileInfo(
                                    ver_data.data(), ver_ret_val, query_size, code_page_idx_2, it.second);
                            }

                            UpdateExeFileInfo(it.first, ver_ret_val, exe_info);
                        }
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING(
                            "VerQueryValue - no value is available for the specified version-information name");
                    }
                }
                else
                {
                    GFXRECON_LOG_WARNING(
                        "VerQueryValue - specified name does not exist or the specified resource is not valid");
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("GetFileVersionInfo failed");
            }
        }
    }
#endif
}

void GetApplicationInfo(FileInfo& file_info)
{
#if defined(WIN32)
    char        module_name[MAX_PATH] = {};
    auto        size_path             = GetModuleFileNameA(nullptr, module_name, MAX_PATH);
    std::string filepath              = "";
    if (size_path > 0)
    {
        filepath = module_name;
        GetApplicationFileExeVersion(file_info, filepath);
        strncpy_s(file_info.AppName,
                  sizeof(file_info.AppName),
                  filepath.substr(filepath.find_last_of("/\\") + 1).c_str(),
                  filepath.substr(filepath.find_last_of("/\\") + 1).length());
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed to retrieve the application executable name");
    }
#endif
}

void CheckReplayerName(const std::string& exe_info_name)
{
#if defined(WIN32)
    static bool warning_printed = false;

    if (!warning_printed)
    {
        char module_name[MAX_PATH] = {};
        auto size_path             = GetModuleFileNameA(nullptr, module_name, MAX_PATH);
        if (size_path > 0)
        {
            warning_printed                   = true;
            std::string filepath              = module_name;
            std::string current_replayer_name = filepath.substr(filepath.find_last_of(kAltPathLastSepStr) + 1).c_str();

            if (current_replayer_name != exe_info_name)
            {
                GFXRECON_LOG_WARNING("Mismatch:");
                GFXRECON_LOG_WARNING("Captured application name: %s", exe_info_name.c_str());
                GFXRECON_LOG_WARNING("Replayer process name: %s", current_replayer_name.c_str());
                GFXRECON_LOG_WARNING(
                    "This can lead to diverging driver behavior between the replayer and captured application");
                GFXRECON_LOG_WARNING(
                    "Recommendation: Rename gfxrecon-replay.exe to match the application's executable name");
            }
            else
            {
                GFXRECON_LOG_DEBUG("Match: replayer process name vs captured application name");
            }
        }
    }

#endif
}

GFXRECON_END_NAMESPACE(filepath)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
