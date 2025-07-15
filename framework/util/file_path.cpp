/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018,2022-2024 LunarG, Inc.
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

std::string
InsertFilenamePostfix(const std::string& filename, const std::string& postfix, const std::string& new_extension)
{
    std::string file_part;
    size_t      sep_index = filename.rfind('.');

    if (sep_index != std::string::npos)
    {
        file_part = filename.substr(0, sep_index);

        return file_part + postfix + new_extension;
    }

    return filename + postfix;
}

std::string GetBasedir(const std::string& path)
{
    std::string basedir    = "";
    size_t      suffix_pos = path.rfind(kPathSepStr);
#if defined(WIN32)
    size_t alt_suffix_pos = path.rfind(kAltPathSepStr);
    if (suffix_pos != std::string::npos)
    {
        if (alt_suffix_pos != std::string::npos)
        {
            suffix_pos = std::max(suffix_pos, alt_suffix_pos);
        }
    }
    else
    {
        suffix_pos = alt_suffix_pos;
    }
#endif
    if (suffix_pos != std::string::npos)
    {
        basedir = path.substr(0, suffix_pos);
    }
    return basedir;
}

std::string GetFilename(const std::string& path)
{
    size_t suffix_pos = path.rfind(kPathSepStr);
#if defined(WIN32)
    size_t alt_suffix_pos = path.rfind(kAltPathSepStr);
    if (suffix_pos != std::string::npos)
    {
        if (alt_suffix_pos != std::string::npos)
        {
            suffix_pos = std::max(suffix_pos, alt_suffix_pos);
        }
    }
    else
    {
        suffix_pos = alt_suffix_pos;
    }
#endif
    if (suffix_pos != std::string::npos)
    {
        return path.substr(suffix_pos + 1);
    }
    return path;
}

std::string GetFilenameStem(const std::string& path)
{
    std::string filename = GetFilename(path);
    size_t      ext_pos  = filename.rfind(".");
    if (ext_pos != std::string::npos)
    {
        return filename.substr(0, ext_pos);
    }
    return filename;
}

std::string GetFilenameExtension(const std::string& path)
{
    std::string filename = GetFilename(path);
    size_t      ext_pos  = filename.rfind(".");
    if (ext_pos != std::string::npos)
    {
        return filename.substr(ext_pos);
    }
    return "";
}

bool MakeDirectory(const std::string& path)
{
#if defined(WIN32)
    return _mkdir(path.c_str()) == 0;
#else
    return mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IRWXO | S_ISVTX) == 0;
#endif
    return false;
}

std::string GenerateTimestampedFilename(const std::string& filename, bool use_gmt)
{
    std::string timestamp = "_";
    timestamp += util::datetime::GetDateTimeString(use_gmt);

    std::string result_filename = InsertFilenamePostfix(filename, timestamp);

    return result_filename;
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

void GetFileInfo(FileInfo& file_info, const std::string& file_path)
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

                        file_info.AppVersion[0] = (ver_info->dwFileVersionMS >> 16) & exe_version_mask;
                        file_info.AppVersion[1] = (ver_info->dwFileVersionMS >> 0) & exe_version_mask;
                        file_info.AppVersion[2] = (ver_info->dwFileVersionLS >> 16) & exe_version_mask;
                        file_info.AppVersion[3] = (ver_info->dwFileVersionLS >> 0) & exe_version_mask;

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

                            UpdateExeFileInfo(it.first, ver_ret_val, file_info);
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
        GetFileInfo(file_info, filepath);
        strncpy_s(file_info.AppName,
                  sizeof(file_info.AppName),
                  filepath.substr(filepath.find_last_of("/\\") + 1).c_str(),
                  filepath.substr(filepath.find_last_of("/\\") + 1).length());
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed to retrieve the application executable name");
    }
#elif defined(__ANDROID__) || defined(__linux__)
    std::ifstream cmdlineFile("/proc/self/cmdline");
    if (cmdlineFile.is_open())
    {
        cmdlineFile.getline(file_info.AppName, sizeof(file_info.AppName), '\0');
        if (strlen(file_info.AppName) > 0)
        {
            GetFileInfo(file_info, file_info.AppName);
        }
        else
        {
            GFXRECON_LOG_WARNING("Application name is empty");
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("Failed to open '/proc/self/cmdline' to get the application executable name");
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

bool EqualStr(const std::string& str1, const std::string& str2, bool case_sensitive)
{
    bool equal = true;

    // Case sensitive compare
    if (case_sensitive == true)
    {
        if (str1 != str2)
        {
            equal = false;
        }
    }

    // Case insensitive compare
    else
    {
        const size_t str1_len = str1.size();
        const size_t str2_len = str2.size();

        if (str1_len != str2_len)
        {
            equal = false;
        }
        else
        {
            for (uint32_t i = 0; i < str1_len; ++i)
            {
                if (tolower(str1[i]) != tolower(str2[i]))
                {
                    equal = false;
                    break;
                }
            }
        }
    }

    return equal;
}

std::string FindModulePath(const std::string& target_module, bool case_sensitive)
{
    std::string target_module_path = "";

#if defined(WIN32)
    HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());

    if (process != nullptr)
    {
        const int max_module_count          = 1024;
        HMODULE   modules[max_module_count] = {};
        DWORD     size                      = 0;

        // Enumerate all the app's loaded modules
        if (EnumProcessModules(process, modules, sizeof(modules), &size))
        {
            for (uint32_t i = 0; i < (size / sizeof(HMODULE)); i++)
            {
                TCHAR enumerated_module[MAX_PATH] = {};

                // Get individual module info
                if (GetModuleFileNameEx(
                        process, modules[i], enumerated_module, sizeof(enumerated_module) / sizeof(TCHAR)))
                {
                    const std::string curr_module_path = enumerated_module;
                    const std::string curr_module_name =
                        curr_module_path.substr(curr_module_path.find_last_of(util::filepath::kAltPathLastSepStr) + 1)
                            .c_str();

                    if (EqualStr(curr_module_name, target_module, case_sensitive))
                    {
                        target_module_path = curr_module_path;

                        break;
                    }
                }
            }
        }

        CloseHandle(process);
    }
#endif

    return target_module_path;
}

GFXRECON_END_NAMESPACE(filepath)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
