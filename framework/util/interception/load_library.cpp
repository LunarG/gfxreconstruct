/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

/// Function pointers and their typedefs to load library
typedef int (*pFuncPtr)(void);

typedef BOOL(WINAPI* FreeLibrary_type)(HMODULE lib_module);
static FreeLibrary_type Real_FreeLibrary = FreeLibrary;

typedef HMODULE(WINAPI* LoadLibraryA_type)(LPCSTR lib_file_name);
static LoadLibraryA_type Real_LoadLibraryA = LoadLibraryA;

typedef HMODULE(WINAPI* LoadLibraryExA_type)(LPCSTR lib_file_name, HANDLE file, DWORD flags);
static LoadLibraryExA_type Real_LoadLibraryExA = LoadLibraryExA;

typedef HMODULE(WINAPI* LoadLibraryW_type)(LPCWSTR lib_file_name);
static LoadLibraryW_type Real_LoadLibraryW = LoadLibraryW;

typedef HMODULE(WINAPI* LoadLibraryExW_type)(LPCWSTR lib_file_name, HANDLE file, DWORD flags);
static LoadLibraryExW_type Real_LoadLibraryExW = LoadLibraryExW;

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
/// Load our custom DLL
/// \param  lib_file_name DLL name
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool LoadCustomDll(LPCSTR lib_file_name)
{
    HMODULE lib = LoadLibraryA(lib_file_name);

    return lib != NULL;
}

//----------------------------------------------------------------------------
/// Load our library (A)
/// \param  lib_file_name DLL name
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool LoadHookedDll(LPCSTR lib_file_name)
{
    bool success = false;

    if (strcmp(lib_file_name, "dxgi.dll") == 0)
    {
        success = LoadCustomDll(GFXR_DXGI_PATH);
    }
    else if (strcmp(lib_file_name, "d3d12.dll") == 0)
    {
        success = LoadCustomDll(GFXR_D3D12_PATH);
    }

    return success;
}

//----------------------------------------------------------------------------
/// Load our library (W)
/// \param  lib_file_name DLL name
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool LoadHookedDllW(LPCWSTR lib_file_name)
{
    bool success = false;

    if (wcscmp(lib_file_name, L"dxgi.dll") == 0)
    {
        success = LoadCustomDll(GFXR_DXGI_PATH);
    }
    else if (wcscmp(lib_file_name, L"d3d12.dll") == 0)
    {
        success = LoadCustomDll(GFXR_D3D12_PATH);
    }

    return success;
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

    BOOL b = Real_FreeLibrary(lib_module);

    return b;
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

        res = Real_LoadLibraryA(lib_file_name);

        DWORD real_error = GetLastError();

        if (MyLstrcmp(lib_file_name, "comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            LoadHookedDll(lib_file_name);
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

        res = Real_LoadLibraryExA(lib_file_name, file, flags);

        DWORD real_error = GetLastError();

        if (MyLstrcmp(lib_file_name, "comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            LoadHookedDll(lib_file_name);
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

        res = Real_LoadLibraryW(lib_file_name);

        DWORD real_error = GetLastError();

        if (MyLstrcmpW(lib_file_name, L"comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            LoadHookedDllW(lib_file_name);
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

        res = Real_LoadLibraryExW(lib_file_name, file, flags);

        DWORD real_error = GetLastError();

        if (MyLstrcmpW(lib_file_name, L"comctl32.dll") != 0)
        {
            CheckForDebuggerAttach();
        }

        if (inside_load_library_ == 1)
        {
            LoadHookedDllW(lib_file_name);
        }

        SetLastError(real_error);
    }

    return res;
}

//----------------------------------------------------------------------------
/// Hook the load library functions
//----------------------------------------------------------------------------
void HookLoadLibrary()
{
    bool hookSuccess = HookAPICall(&(PVOID&)Real_LoadLibraryA, gfxrecon::util::interception::LoadLibraryA);
    assert(hookSuccess == true);

    hookSuccess = HookAPICall(&(PVOID&)Real_LoadLibraryExA, gfxrecon::util::interception::LoadLibraryExA);
    assert(hookSuccess == true);

    hookSuccess = HookAPICall(&(PVOID&)Real_LoadLibraryW, gfxrecon::util::interception::LoadLibraryW);
    assert(hookSuccess == true);

    hookSuccess = HookAPICall(&(PVOID&)Real_LoadLibraryExW, gfxrecon::util::interception::LoadLibraryExW);
    assert(hookSuccess == true);

    hookSuccess = HookAPICall(&(PVOID&)Real_FreeLibrary, gfxrecon::util::interception::FreeLibrary);
    assert(hookSuccess == true);

    // Load "dxgi.dll" at the beginning since we sometimes miss loading it
    LoadLibraryA("dxgi.dll");
}

//----------------------------------------------------------------------------
/// Unhook the load library functions
//----------------------------------------------------------------------------
void UnhookLoadLibrary()
{
    bool unhookSuccess = UnhookAPICall(&(PVOID&)Real_LoadLibraryA, gfxrecon::util::interception::LoadLibraryA);
    assert(unhookSuccess == true);

    unhookSuccess = UnhookAPICall(&(PVOID&)Real_LoadLibraryExA, gfxrecon::util::interception::LoadLibraryExA);
    assert(unhookSuccess == true);

    unhookSuccess = UnhookAPICall(&(PVOID&)Real_LoadLibraryW, gfxrecon::util::interception::LoadLibraryW);
    assert(unhookSuccess == true);

    unhookSuccess = UnhookAPICall(&(PVOID&)Real_LoadLibraryExW, gfxrecon::util::interception::LoadLibraryExW);
    assert(unhookSuccess == true);

    unhookSuccess = UnhookAPICall(&(PVOID&)Real_FreeLibrary, gfxrecon::util::interception::FreeLibrary);
    assert(unhookSuccess == true);

    // Restore Real functions to original values in case they aren't restored correctly by the unhook call
    Real_LoadLibraryA   = LoadLibraryA;
    Real_LoadLibraryExA = LoadLibraryExA;
    Real_LoadLibraryW   = LoadLibraryW;
    Real_LoadLibraryExW = LoadLibraryExW;
    Real_FreeLibrary    = FreeLibrary;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
