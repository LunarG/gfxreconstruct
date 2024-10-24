/*
** Copyright (c) 2021-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "load_library.h"

#include "hooking_detours.h"
#include "injection.h"
#include "ref_tracker.h"
#include "ref_tracker_counter.h"
#include "util/options.h"
#include "util/platform.h"
#include "util/file_path.h"
#include "util/interception/interception_util.h"

#include <Windows.h>
#include <Shlwapi.h>
#include <assert.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

/// Default paths to steam overlay so that we don't inject into it
static const char*    dll_steam_overlay_32_   = "C:\\Program Files (x86)\\Steam\\gameoverlayrenderer.dll";
static const char*    dll_steam_overlay_64_   = "C:\\Program Files (x86)\\Steam\\gameoverlayrenderer64.dll";
static const wchar_t* dll_steam_overlay_32_W_ = L"C:\\Program Files (x86)\\Steam\\gameoverlayrenderer.dll";
static const wchar_t* dll_steam_overlay_64_W_ = L"C:\\Program Files (x86)\\Steam\\gameoverlayrenderer64.dll";

/// Reference counter indicating recursion depth of LoadLibrary calls. LoadLibrary can be used
/// recursively (LoadLibrary can spawn other LoadLibrary calls) and we're only interested in the
/// first call to LoadLibrary (reference count == 1).
static RefTrackerCounter inside_load_library_;

/// Function pointer typedef for UpdateHooks
using UpdateHooksFunc = bool (*)(void);

/// Function pointers and their typedefs to load library
using FreeLibraryFunc                    = BOOL(WINAPI*)(HMODULE);
static FreeLibraryFunc real_free_library = FreeLibrary;

using ReadlLoadLibraryAFunc                      = HMODULE(WINAPI*)(LPCSTR);
static ReadlLoadLibraryAFunc real_load_library_a = LoadLibraryA;

using RealLoadLibraryExAFunc                         = HMODULE(WINAPI*)(LPCSTR, HANDLE, DWORD);
static RealLoadLibraryExAFunc real_load_library_ex_a = LoadLibraryExA;

using RealLoadLibraryWFunc                      = HMODULE(WINAPI*)(LPCWSTR);
static RealLoadLibraryWFunc real_load_library_w = LoadLibraryW;

using RealLoadLibraryExWFunc                         = HMODULE(WINAPI*)(LPCWSTR, HANDLE, DWORD);
static RealLoadLibraryExWFunc real_load_library_ex_w = LoadLibraryExW;

//----------------------------------------------------------------------------
/// Pause application to allow debugger to attach
/// This functionality only happens once - on the first call to LoadLibrary.
/// This function uses MessageBox - which will load comctl32.dll if necessary
/// To avoid recursion problems, only call it when a different DLL is being loaded.
//----------------------------------------------------------------------------
static void CheckForDebuggerAttach()
{
    std::string value = gfxrecon::util::platform::GetEnv("GFXRECON_DEBUG_MESSAGE_BOX");

    if (gfxrecon::util::ParseBoolString(value, false) == true)
    {
        static bool already_checked = false; // only pause application once.

        if (already_checked == false)
        {
            char module_name[MAX_PATH];
            GetModuleFileNameA(nullptr, module_name, MAX_PATH);

            std::string module_name_str = module_name;
            size_t      idx             = module_name_str.find_last_of("\\") + 1;
            module_name_str             = module_name_str.substr(idx);

#ifdef UNICODE
            std::wstring wstr(module_name_str.begin(), module_name_str.end());
            MessageBox(0, L"Attach", wstr.c_str(), 0);
#else
            MessageBox(0, "Attach", module_name_str.c_str(), 0);
#endif

            already_checked = true;
        }
    }
}

//----------------------------------------------------------------------------
/// Compare 2 character strings. Local version used here because lstrcmp is called
/// from LoadLibrary, and pulls in Kernel32.dll. If this dll hasn't been loaded
/// before the LoadLibrary functions have been hooked, it will lead to the same
/// recursion problems seen with MessageBox and conctl32.dll
/// \param str1 Input string
/// \param str2 Input string
/// \return 0 if strings are the same, non-zero if different.
//----------------------------------------------------------------------------
static int MyLstrcmp(LPCSTR str1, LPCSTR str2)
{
    int result = -1;

    if ((str1 != nullptr) && (str2 != nullptr))
    {
        while (*str1 == *str2++)
        {
            if (*str1++ == 0)
            {
                return 0;
            }
        }

        result = (*(const unsigned char*)str1 - *(const unsigned char*)(str2 - 1));
    }

    return result;
}

//----------------------------------------------------------------------------
/// Compare 2 wide character strings. Local version used here because lstrcmpW is called
/// from LoadLibrary, and pulls in Kernel32.dll. If this dll hasn't been loaded
/// before the LoadLibrary functions have been hooked, it will lead to the same
/// recursion problems seen with MessageBox and conctl32.dll
/// \param str1 Input string
/// \param str2 Input string
// \return 0 if strings are the same, non-zero if different.
//----------------------------------------------------------------------------
static int MyLstrcmpW(LPCWSTR str1, LPCWSTR str2)
{
    // TODO: Evaluate whether std::wcscmp gets called from LoadLibrary

    int result = -1;

    if ((str1 != nullptr) && (str2 != nullptr))
    {
        while (*str1 == *str2++)
        {
            if (*str1++ == 0)
            {
                return 0;
            }
        }

        result = (*str1 - *(str2 - 1));
    }

    return result;
}

//----------------------------------------------------------------------------
/// Determine if this call to load library is for steam overlay
/// \param  lib_file_name DLL name
/// \return True if overlay, false otherwise.
//----------------------------------------------------------------------------
static bool IsSteamOverlayDll(const char* lib_file_name)
{
    return (MyLstrcmp(lib_file_name, dll_steam_overlay_32_) == 0) ||
           (MyLstrcmp(lib_file_name, dll_steam_overlay_64_) == 0);
}

//----------------------------------------------------------------------------
/// Determine if this call to load library is for steam overlay
/// \param  lib_file_name DLL name
/// \return True if overlay, false otherwise.
//----------------------------------------------------------------------------
static bool IsSteamOverlayDllW(const wchar_t* lib_file_name)
{
    return (MyLstrcmpW(lib_file_name, dll_steam_overlay_32_W_) == 0) ||
           (MyLstrcmpW(lib_file_name, dll_steam_overlay_64_W_) == 0);
}

//----------------------------------------------------------------------------
/// Call into our own D3D12 and DXGI to update hooks
/// \param  hLib Module to library to hookup.
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool HookupLibrary(HMODULE hLib)
{
    bool ret_val = false;

    UpdateHooksFunc func = reinterpret_cast<UpdateHooksFunc>(GetProcAddress(hLib, "UpdateHooks"));

    if (func != nullptr)
    {
        ret_val = func();
    }

    return ret_val;
}

//----------------------------------------------------------------------------
/// Load and hookup a GFXR library with a system library
/// \param  system_lib The name of system library DLL
/// \param  gfxr_lib_path The path to GFXR version of the library
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
HMODULE HookInterceptionLibrary(const char* system_lib, const char* gfxr_lib_path)
{
    HMODULE gfxr_lib_handle = NULL;

    HMODULE system_library = GetModuleHandleA(system_lib);

    if (system_library != NULL)
    {
        gfxr_lib_handle = LoadLibraryA(gfxr_lib_path);
    }

    if (gfxr_lib_handle != NULL)
    {
        HookupLibrary(gfxr_lib_handle);
    }

    return gfxr_lib_handle;
}

//----------------------------------------------------------------------------
/// Load and hook our own custom versions of D3D12 and DXGI
//----------------------------------------------------------------------------
void HookInterceptionLibraries()
{
    static HMODULE gfxr_d3d12_module = NULL;
    static HMODULE gfxr_dxgi_module  = NULL;

    if (gfxr_d3d12_module == NULL)
    {
        const std::string gfxr_d3d12_path = gfxrecon::util::interception::D3d12LibPath();

        gfxr_d3d12_module = HookInterceptionLibrary(gfxrecon::util::interception::kD3d12Lib, gfxr_d3d12_path.c_str());
    }

    if (gfxr_dxgi_module == NULL)
    {
        const std::string gfxr_dxgi_path = gfxrecon::util::interception::DxgiLibPath();

        gfxr_dxgi_module = HookInterceptionLibrary(gfxrecon::util::interception::kDxgiLib, gfxr_dxgi_path.c_str());
    }
}

//----------------------------------------------------------------------------
/// Mine entry point for intercepted function
/// \param lib_module_handle Library module
/// \return True if success false if fail.
//----------------------------------------------------------------------------
static BOOL WINAPI FreeLibrary(HMODULE lib_module)
{
    char module_name[MAX_PATH];
    GetModuleFileNameA(lib_module, module_name, MAX_PATH);

    return real_free_library(lib_module);
}

//----------------------------------------------------------------------------
/// Mine entry point for intercepted function
/// \param lib_file_name Library file name
/// \return Loaded module.
//----------------------------------------------------------------------------
static HMODULE WINAPI LoadLibraryA(LPCSTR lib_file_name)
{
    HMODULE res = 0;

    if (IsSteamOverlayDll(lib_file_name) == false)
    {
        RefTracker rf(&inside_load_library_);

        res = real_load_library_a(lib_file_name);

        DWORD real_error = GetLastError();

        if (MyLstrcmp(lib_file_name, "comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            HookInterceptionLibraries();
        }

        SetLastError(real_error);
    }

    return res;
}

//----------------------------------------------------------------------------
/// Mine entry point for intercepted function
/// \param lib_file_name Library file name
/// \param file File handle
/// \param flags load flags
/// \return Loaded module.
//----------------------------------------------------------------------------
static HMODULE WINAPI LoadLibraryExA(LPCSTR lib_file_name, HANDLE file, DWORD flags)
{
    HMODULE res = 0;

    if (IsSteamOverlayDll(lib_file_name) == false)
    {
        RefTracker rf(&inside_load_library_);

        res = real_load_library_ex_a(lib_file_name, file, flags);

        DWORD real_error = GetLastError();

        if (MyLstrcmp(lib_file_name, "comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            HookInterceptionLibraries();
        }

        SetLastError(real_error);
    }

    return res;
}

//----------------------------------------------------------------------------
/// Mine entry point for intercepted function
/// \param lib_file_name Library file name
/// \return Loaded module.
//----------------------------------------------------------------------------
static HMODULE WINAPI LoadLibraryW(LPCWSTR lib_file_name)
{
    HMODULE res = 0;

    if (IsSteamOverlayDllW(lib_file_name) == false)
    {
        RefTracker rf(&inside_load_library_);

        res = real_load_library_w(lib_file_name);

        DWORD real_error = GetLastError();

        if (MyLstrcmpW(lib_file_name, L"comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            HookInterceptionLibraries();
        }

        SetLastError(real_error);
    }

    return res;
}

//----------------------------------------------------------------------------
/// Mine entry point for intercepted function
/// \param lib_file_name Library file name
/// \param file File handle
/// \param flags load flags
/// \return Loaded module.
//----------------------------------------------------------------------------
static HMODULE WINAPI LoadLibraryExW(LPCWSTR lib_file_name, HANDLE file, DWORD flags)
{
    HMODULE res = 0;

    if (IsSteamOverlayDllW(lib_file_name) == false)
    {
        RefTracker rf(&inside_load_library_);

        res = real_load_library_ex_w(lib_file_name, file, flags);

        DWORD real_error = GetLastError();

        if (MyLstrcmpW(lib_file_name, L"comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            HookInterceptionLibraries();
        }

        SetLastError(real_error);
    }

    return res;
}

void HookLoadLibrary()
{
    bool hook_success = HookAPICall(&(PVOID&)real_load_library_a, gfxrecon::util::interception::LoadLibraryA);
    assert(hook_success == true);

    hook_success = HookAPICall(&(PVOID&)real_load_library_ex_a, gfxrecon::util::interception::LoadLibraryExA);
    assert(hook_success == true);

    hook_success = HookAPICall(&(PVOID&)real_load_library_w, gfxrecon::util::interception::LoadLibraryW);
    assert(hook_success == true);

    hook_success = HookAPICall(&(PVOID&)real_load_library_ex_w, gfxrecon::util::interception::LoadLibraryExW);
    assert(hook_success == true);

    hook_success = HookAPICall(&(PVOID&)real_free_library, gfxrecon::util::interception::FreeLibrary);
    assert(hook_success == true);

    // TODO: Load "dxgi.dll" at the beginning since we sometimes miss loading it
    LoadLibraryA("dxgi.dll");
}

void UnhookLoadLibrary()
{
    bool unhook_success = UnhookAPICall(&(PVOID&)real_load_library_a, gfxrecon::util::interception::LoadLibraryA);
    assert(unhook_success == true);

    unhook_success = UnhookAPICall(&(PVOID&)real_load_library_ex_a, gfxrecon::util::interception::LoadLibraryExA);
    assert(unhook_success == true);

    unhook_success = UnhookAPICall(&(PVOID&)real_load_library_w, gfxrecon::util::interception::LoadLibraryW);
    assert(unhook_success == true);

    unhook_success = UnhookAPICall(&(PVOID&)real_load_library_ex_w, gfxrecon::util::interception::LoadLibraryExW);
    assert(unhook_success == true);

    unhook_success = UnhookAPICall(&(PVOID&)real_free_library, gfxrecon::util::interception::FreeLibrary);
    assert(unhook_success == true);

    // Restore Real functions to original values in case they aren't restored correctly by the unhook call
    real_load_library_a    = LoadLibraryA;
    real_load_library_ex_a = LoadLibraryExA;
    real_load_library_w    = LoadLibraryW;
    real_load_library_ex_w = LoadLibraryExW;
    real_free_library      = FreeLibrary;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
