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

#include "create_process.h"

#include "hooking_detours.h"
#include "injection.h"
#include "ref_tracker.h"
#include "ref_tracker_counter.h"
#include "util/strings.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

/// Used to mask out sections of code that are called by the runtime (not the app)
static gfxrecon::util::interception::RefTrackerCounter nested_count_;

/// List of all applications which we should not inject into, in lower case
const static LPCSTR kBlackList[] = {
    { "fxc.exe" },
    { "cmd.exe" },
    { "dev.exe" },
    { "steamwebhelper.exe" },
    { "gldriverquery.exe" },
    { "gldriverquery64.exe" },
    { "vulkandriverquery.exe" },
    { "vulkandriverquery64.exe" },
    { "galaxyclient helper.exe" },
    { "gog galaxy notifications renderer.exe" },
    { "galaxyoverlay.exe" },
    { "epicwebhelper.exe" },
    { "epiconlineservicesuserhelper.exe" },
};

/// Function pointers and their typedefs to create process
using CreateProcessAFunc                 = BOOL(WINAPI*)(LPCSTR,
                                         LPSTR,
                                         LPSECURITY_ATTRIBUTES,
                                         LPSECURITY_ATTRIBUTES,
                                         BOOL,
                                         DWORD,
                                         LPVOID,
                                         LPCSTR,
                                         LPSTARTUPINFOA,
                                         LPPROCESS_INFORMATION);
CreateProcessAFunc real_create_process_a = CreateProcessA;
using CreateProcessWFunc                 = BOOL(WINAPI*)(LPCWSTR,
                                         LPWSTR,
                                         LPSECURITY_ATTRIBUTES,
                                         LPSECURITY_ATTRIBUTES,
                                         BOOL,
                                         DWORD,
                                         LPVOID,
                                         LPCWSTR,
                                         LPSTARTUPINFOW,
                                         LPPROCESS_INFORMATION);
CreateProcessWFunc real_create_process_w = CreateProcessW;

/// Counters to track injection hopping
const static int k_max_hop_count_ = 20;
static int       total_hop_count_ = 0;

//----------------------------------------------------------------------------
/// Try to detect blacklisted app
/// \param  app_name
/// \return True if disallowed, false otherwise
//----------------------------------------------------------------------------
static bool CheckBlackList(std::string app_name)
{
    gfxrecon::util::strings::ToLowerCase(app_name);

    const int count = sizeof(kBlackList) / sizeof(kBlackList[0]);

    for (int i = 0; i < count; ++i)
    {
        if (app_name.find(kBlackList[i]) != std::string::npos)
        {
            return true;
        }
    }

    return false;
}

//----------------------------------------------------------------------------
/// Returns true if the input name is on the blacklist of processes not to inject into
/// \param app The path/exe name
/// \return true if the app is blacklisted
//----------------------------------------------------------------------------
static bool BlockInjectionCheckA(LPCSTR app)
{
    return CheckBlackList(app);
}

//----------------------------------------------------------------------------
/// Returns true if the input name is on the blacklist of processes not to inject into
/// \param app The path/exe name
/// \return true if the app is blacklisted
//----------------------------------------------------------------------------
static bool BlockInjectionCheckW(LPCWSTR app)
{
    const std::string app_name = WideStringToString(app);

    return CheckBlackList(app_name);
}

//----------------------------------------------------------------------------
/// Returns true if either of the input names is on the blacklist of processes not to inject into
/// \param app_path Path to app
/// \param cmd_line app command line
/// \return true if either of the the apps is blacklisted
//----------------------------------------------------------------------------
static bool BlockInjectionA(LPCSTR app_path, LPSTR cmd_line)
{
    bool block_injection = false;

    if (app_path != nullptr && strlen(app_path) > 0)
    {
        if (BlockInjectionCheckA(app_path))
        {
            block_injection = true;
        }
    }

    if (cmd_line != nullptr)
    {
        if (BlockInjectionCheckA(static_cast<LPCSTR>(cmd_line)))
        {
            block_injection = true;
        }
    }

    return block_injection;
}

//----------------------------------------------------------------------------
/// Returns true if either of the input names is on the blacklist of processes not to inject into
/// \param app_path Path to app
/// \param cmd_line app command line
/// \return true if either of the the apps is blacklisted
//----------------------------------------------------------------------------
static bool BlockInjectionW(LPCWSTR app_path, LPWSTR cmd_line)
{
    bool block_injection = false;

    if ((app_path != nullptr) && (wcslen(app_path) > 0))
    {
        if (BlockInjectionCheckW(app_path))
        {
            block_injection = true;
        }
    }

    if (cmd_line != nullptr)
    {
        if (BlockInjectionCheckW(static_cast<LPCWSTR>(cmd_line)))
        {
            block_injection = true;
        }
    }

    return block_injection;
}

//----------------------------------------------------------------------------
/// Entry point for the intercepted function
/// \param application_name Application name
/// \param command_line Command line
/// \param process_attributes Process attributes
/// \param thread_attributes Thread attributes
/// \param inherit_handles Inherit handles flag
/// \param creation_flags flags
/// \param environment Environment
/// \param current_directory Current directory
/// \param startup_info Startup info
/// \param process_information Process info
/// \return True or false
//----------------------------------------------------------------------------
BOOL WINAPI Mine_CreateProcessA(LPCSTR                application_name,
                                LPSTR                 command_line,
                                LPSECURITY_ATTRIBUTES process_attributes,
                                LPSECURITY_ATTRIBUTES thread_attributes,
                                BOOL                  inherit_handles,
                                DWORD                 creation_flags,
                                LPVOID                environment,
                                LPCSTR                current_directory,
                                LPSTARTUPINFOA        startup_info,
                                LPPROCESS_INFORMATION process_information)
{
    BOOL ret_val = FALSE;

    if (nested_count_ == 0)
    {
        gfxrecon::util::interception::RefTracker rf(&nested_count_);

        // Get the current hop count
        int hop_count = total_hop_count_;

        const bool block_load = BlockInjectionA(application_name, command_line);

        // Decide if we need to inject into the new process
        if ((hop_count >= k_max_hop_count_) || (block_load == true))
        {
            ret_val = real_create_process_a(application_name,
                                            command_line,
                                            process_attributes,
                                            thread_attributes,
                                            inherit_handles,
                                            creation_flags,
                                            environment,
                                            current_directory,
                                            startup_info,
                                            process_information);
        }
        else
        {
            // Update the current hop count
            total_hop_count_ = hop_count + 1;

            ret_val = gfxrecon::util::interception::LaunchAndInjectA(
                application_name,
                command_line,
                process_attributes,
                thread_attributes,
                inherit_handles,
                creation_flags,
                environment,
                current_directory,
                startup_info,
                process_information,
                gfxrecon::util::interception::GetInterceptorPath(command_line).c_str());
        }
    }
    else
    {
        ret_val = real_create_process_a(application_name,
                                        command_line,
                                        process_attributes,
                                        thread_attributes,
                                        inherit_handles,
                                        creation_flags,
                                        environment,
                                        current_directory,
                                        startup_info,
                                        process_information);
    }

    return ret_val;
}

//----------------------------------------------------------------------------
/// Entry point for the intercepted function
/// \param application_name Application name
/// \param command_line Command line
/// \param process_attributes Process attributes
/// \param thread_attributes Thread attributes
/// \param inherit_handles Inherit handles flag
/// \param creation_flags flags
/// \param environment Environment
/// \param current_directory Current directory
/// \param startup_info Startup info
/// \param process_information Process info
/// \return True or false
//----------------------------------------------------------------------------
BOOL WINAPI Mine_CreateProcessW(LPCWSTR               application_name,
                                LPWSTR                command_line,
                                LPSECURITY_ATTRIBUTES process_attributes,
                                LPSECURITY_ATTRIBUTES thread_attributes,
                                BOOL                  inherit_handles,
                                DWORD                 creation_flags,
                                LPVOID                environment,
                                LPCWSTR               current_directory,
                                LPSTARTUPINFOW        startup_info,
                                LPPROCESS_INFORMATION process_information)
{
    BOOL ret_val = FALSE;

    if (nested_count_ == 0)
    {
        gfxrecon::util::interception::RefTracker rf(&nested_count_);

        // Get the current hop count
        int hop_count = total_hop_count_;

        const bool block_load = BlockInjectionW(application_name, command_line);

        // Decide if we need to inject into the new process
        if ((hop_count >= k_max_hop_count_) || (block_load == true))
        {
            ret_val = real_create_process_w(application_name,
                                            command_line,
                                            process_attributes,
                                            thread_attributes,
                                            inherit_handles,
                                            creation_flags,
                                            environment,
                                            current_directory,
                                            startup_info,
                                            process_information);
        }
        else
        {
            // Update the current hop count
            total_hop_count_ = hop_count + 1;

            ret_val = gfxrecon::util::interception::LaunchAndInjectW(
                application_name,
                command_line,
                process_attributes,
                thread_attributes,
                inherit_handles,
                creation_flags,
                environment,
                current_directory,
                startup_info,
                process_information,
                gfxrecon::util::interception::GetInterceptorPath(command_line).c_str());
        }
    }
    else
    {
        ret_val = real_create_process_w(application_name,
                                        command_line,
                                        process_attributes,
                                        thread_attributes,
                                        inherit_handles,
                                        creation_flags,
                                        environment,
                                        current_directory,
                                        startup_info,
                                        process_information);
    }

    return ret_val;
}

bool HookCreateProcess()
{
    bool hook_success = gfxrecon::util::interception::HookAPICall(&(PVOID&)real_create_process_a, Mine_CreateProcessA);
    assert(hook_success == true);

    hook_success = gfxrecon::util::interception::HookAPICall(&(PVOID&)real_create_process_w, Mine_CreateProcessW);
    assert(hook_success == true);

    return hook_success;
}

bool UnhookCreateProcess()
{
    bool unhook_success =
        gfxrecon::util::interception::UnhookAPICall(&(PVOID&)real_create_process_a, Mine_CreateProcessA);
    assert(unhook_success == true);

    unhook_success = gfxrecon::util::interception::UnhookAPICall(&(PVOID&)real_create_process_w, Mine_CreateProcessW);
    assert(unhook_success == true);

    // Restore Real functions to original values in case they aren't restored correctly by the unhook call
    real_create_process_w = CreateProcessW;
    real_create_process_a = CreateProcessA;

    return unhook_success;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
