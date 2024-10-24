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

#include "util/argument_parser.h"
#include "util/date_time.h"
#include "util/logging.h"
#include "util/file_path.h"
#include "util/interception/interception_util.h"
#include "util/interception/injection.h"

#include <string>
#include <windows.h>
#include <assert.h>
#include <iostream>

// ---------------------------------------------------------------------------
/// Print launcher usage
/// \param launcher_name The name of the launcher
// ---------------------------------------------------------------------------
void PrintUsage(const std::string& launcher_name)
{
    GFXRECON_WRITE_CONSOLE("\n%s - A tool to launch applications for GFXR capture.\n", launcher_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s <app path (and its arguments) surrounded by quotes>", launcher_name.c_str());
}

//----------------------------------------------------------------------------
/// Surround a path to an exe with quotes.
///
/// \param  cmd The command to executable and its parameters.
///
/// \return Original command, but quoted if necessary.
//----------------------------------------------------------------------------
std::string QuoteCommand(const std::string& cmd)
{
    std::string out_str = cmd;

    // Only needed if there are spaces
    if (out_str.find(" ") != std::string::npos)
    {
        std::string quotes = "\"";
        std::string str    = quotes;
        str += out_str;
        str += quotes;

        out_str = str;
    }

    return out_str;
}

//----------------------------------------------------------------------------
/// Given some positional arguments, fill in a CreateProcessInfo struct that
/// contains everything needed for launching an app with CreateProcess()
///
/// \param  positional_arguments GFXR positional arguments
/// \param  process_info outgoing CreateProcessInfo struct
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetProcessInfo(const std::vector<std::string>& positional_arguments, CreateProcessInfo& process_info)
{
    bool success = false;

    if (positional_arguments.size() > 0)
    {
        const std::string user_app = positional_arguments.front();

        const size_t exe_loc = user_app.find(".exe");

        if (exe_loc != std::string::npos)
        {
            const size_t args_loc           = exe_loc + 4;
            process_info.app_path           = user_app.substr(0, args_loc);
            process_info.app_path_plus_args = QuoteCommand(process_info.app_path) + user_app.substr(args_loc);
            process_info.app_dir            = user_app.substr(0, user_app.rfind("\\"));

            success = true;
        }
    }

    return success;
}

//----------------------------------------------------------------------------
/// Verify that all capture components are present in the expected location
///
/// \return True if capture DLLs exist
//----------------------------------------------------------------------------
bool VerifyCaptureComponents(const std::string& interceptor_path)
{
    bool detected_capture_components = false;

    const std::string lib_path_capture = gfxrecon::util::interception::CaptureLibPath();
    const std::string lib_path_d3d12   = gfxrecon::util::interception::D3d12LibPath();
    const std::string lib_path_dxgi    = gfxrecon::util::interception::DxgiLibPath();

    if (gfxrecon::util::filepath::IsFile(lib_path_capture) && gfxrecon::util::filepath::IsFile(lib_path_d3d12) &&
        gfxrecon::util::filepath::IsFile(lib_path_dxgi) && gfxrecon::util::filepath::IsFile(interceptor_path))
    {
        detected_capture_components = true;
    }

    return detected_capture_components;
}

//----------------------------------------------------------------------------
/// Basic app launcher that will inject our interceptor DLL and eventually
/// hook into D3D12 and DXGI
///
/// \param  argc Number of args
/// \param  argv Arg array
///
/// \return Zero if normal exit, else abnormal exit.
//----------------------------------------------------------------------------
int main(int argc, const char** argv)
{
    int return_code = 0;

    gfxrecon::util::Log::Init();

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, "", "");

    if ((arg_parser.IsInvalid() == false) && (arg_parser.GetPositionalArgumentsCount() == 1))
    {
        try
        {
            const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();

            CreateProcessInfo process_info = {};
            bool              success      = GetProcessInfo(positional_arguments, process_info);

            if (success == true)
            {
                char  working_dir[MAX_PATH] = {};
                DWORD curr_dir_len          = GetCurrentDirectory(MAX_PATH, working_dir);

                if (curr_dir_len != 0)
                {
                    // Save off GFXR location in an environment variable, which is read later as our libs are loaded in
                    BOOL set_env_ret =
                        SetEnvironmentVariableA(gfxrecon::util::interception::kGfxrInstallEnv, working_dir);

                    if (set_env_ret != 0)
                    {
                        // If we're using the launcher, we can assume detours will be used
                        set_env_ret = SetEnvironmentVariableA("GFXRECON_USE_DETOURS_HOOKING", "true");

                        if (set_env_ret != 0)
                        {
                            const std::string interceptor_path =
                                gfxrecon::util::interception::InterceptorPath(working_dir, process_info.app_path);

                            if (VerifyCaptureComponents(interceptor_path) == true)
                            {
                                STARTUPINFOA si = {};
                                si.cb           = sizeof(si);

                                PROCESS_INFORMATION pi = {};

                                gfxrecon::util::interception::LaunchAndInjectA(
                                    process_info.app_path.c_str(),
                                    const_cast<LPSTR>(process_info.app_path_plus_args.c_str()),
                                    nullptr,
                                    nullptr,
                                    TRUE,
                                    CREATE_DEFAULT_ERROR_MODE | CREATE_SUSPENDED,
                                    nullptr,
                                    process_info.app_dir.c_str(),
                                    &si,
                                    &pi,
                                    interceptor_path.c_str());
                            }
                            else
                            {
                                GFXRECON_LOG_ERROR(
                                    "Did not find DLLs required to enable capture with gfxrecon-launcher.exe. "
                                    "Verify that gfxrecon_interceptor.dll and the \"d3d12_capture\" directory and "
                                    "exist "
                                    "in the same place as gfxrecon-launcher.exe.");

                                gfxrecon::util::Log::Release();
                            }
                        }
                        else
                        {
                            GFXRECON_LOG_ERROR("Could not set environment variable to enable gfxrecon-launcher.");
                        }
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Could not set environment variable to enable gfxrecon-launcher.");
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR("Could not determine the current directory for gfxrecon-launcher.");
                }
            }
        }
        catch (const std::runtime_error& error)
        {
            GFXRECON_WRITE_CONSOLE("Launcher has encountered a fatal error and cannot continue: %s", error.what());
            return_code = -1;
        }
        catch (...)
        {
            GFXRECON_WRITE_CONSOLE("Launcher failed due to an unhandled exception");
            return_code = -1;
        }
    }
    else
    {
        PrintUsage(argv[0]);
        return_code = -1;
    }

    gfxrecon::util::Log::Release();

    return return_code;
}
