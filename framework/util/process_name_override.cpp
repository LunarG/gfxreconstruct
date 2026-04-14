/*
** Copyright (c) 2026 Advanced Micro Devices, Inc. All rights reserved.
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

#include <windows.h> 
#include <string>
#include <filesystem>
#include "util/to_string.h"
#include "util/logging.h"
#include "util/interception/hooking_detours.h"
#include "util/process_name_override.h"

namespace 
{
// App Name set by callback from replay consumer
std::string s_app_name{}; 

// Helper function to construct the modified application path based on the original application path and the new application name.
std::string GetModifiedApplicationPath(DWORD (*real_getmodule_filename_a)(HMODULE, LPSTR, DWORD), std::string app_name)
{
    if(app_name.empty() || real_getmodule_filename_a == nullptr)
    {
        return {};
    }
    std::string result{}; 
    char application_name[MAX_PATH]{};
    DWORD length = real_getmodule_filename_a(nullptr, application_name, sizeof(application_name));
    if(length > 0 && length < MAX_PATH)
    {
        std::filesystem::path application_current_path(application_name);
        application_current_path = application_current_path.parent_path();
        application_current_path /= app_name;
        result = application_current_path.string();
    }
    return result;
}
} // anonymous namespace

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

DWORD (*real_getmodule_filename_a)(HMODULE, LPSTR, DWORD) = GetModuleFileNameA;
DWORD (*real_getmodule_filename_w)(HMODULE, LPWSTR, DWORD) = GetModuleFileNameW;


// Based on MSDN documentation for GetModuleFileNameA/W, if hModule is null, the function returns the path of the executable of the current process. 
// By hooking this function, we can override the process name that is reported to the driver. 
// https://learn.microsoft.com/en-us/windows/win32/api/libloaderapi/nf-libloaderapi-getmodulefilenamew
DWORD HookGetModuleFilenameA(HMODULE hModule, LPSTR lpFilename, DWORD nSize)
{
    if (hModule == nullptr && !s_app_name.empty() && nSize > 0)
    {
        GFXRECON_LOG_INFO_ONCE("Overriding process name to: %s", s_app_name.c_str());
        std::string full_app_path = GetModifiedApplicationPath(real_getmodule_filename_a, s_app_name);

        // If the provided buffer is too small, return the required size and set the last error to ERROR_INSUFFICIENT_BUFFER, as per the documentation for GetModuleFileNameA/W.
        if (full_app_path.size() >= nSize) 
        {
            // ensure null termination. 
            lpFilename[nSize - 1] = '\0';
            // Copy as much of the app name as will fit in the buffer, leaving space for the null terminator.
            memcpy_s(lpFilename, nSize - 2, full_app_path.c_str(), nSize - 1);
            SetLastError(ERROR_INSUFFICIENT_BUFFER); 
            return nSize;
        }
        else
        {
            snprintf(lpFilename, full_app_path.size() + 1, "%s", full_app_path.c_str());
            return full_app_path.size(); 
        }
        
    }
    return real_getmodule_filename_a(hModule, lpFilename, nSize);
}

DWORD HookGetModuleFilenameW(HMODULE hModule, LPWSTR lpFilename, DWORD nSize) 
{
    if (hModule == nullptr && !s_app_name.empty() && nSize > 0)
    {
        GFXRECON_LOG_INFO_ONCE("Overriding process name to: %s", s_app_name.c_str());
        std::string  full_app_path = GetModifiedApplicationPath(real_getmodule_filename_a, s_app_name);
        std::wstring w_full_app_path = gfxrecon::util::StringToWideString(full_app_path); 
        if (w_full_app_path.size() >= nSize)
        {
            // ensure null termination. 
            lpFilename[nSize - 1] = '\0';
            // Copy as much of the app name as will fit in the buffer, leaving space for the null terminator.
            memcpy_s(lpFilename, (nSize - 2) * sizeof(wchar_t), w_full_app_path.c_str(), (nSize - 1) * sizeof(wchar_t));
            SetLastError(ERROR_INSUFFICIENT_BUFFER); 
            return nSize;
        }
        else
        {
            swprintf(lpFilename, w_full_app_path.size() + 1, L"%s", w_full_app_path.c_str());
            return w_full_app_path.size(); 
        }
    }
    return real_getmodule_filename_w(hModule, lpFilename, nSize);
}

void ProcessNameOverrideCallback(char const* app_name, size_t app_name_size)
{
    if(app_name && app_name_size > 0)
    {
        s_app_name.resize(app_name_size); 
        memcpy(&s_app_name[0], app_name, app_name_size);
    }
}

void InitializeProcessNameOverride()
{
    bool success = false; 
    success = gfxrecon::util::interception::HookAPICall(&(PVOID&)real_getmodule_filename_a, HookGetModuleFilenameA);
    if (!success)
    {
        GFXRECON_LOG_WARNING("Failed to hook GetModuleFileNameA. Process name override will not work.");
    }
    success = gfxrecon::util::interception::HookAPICall(&(PVOID&)real_getmodule_filename_w, HookGetModuleFilenameW);
    if (!success)
    {
        GFXRECON_LOG_WARNING("Failed to hook GetModuleFileNameW. Process name override will not work.");
    }
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)