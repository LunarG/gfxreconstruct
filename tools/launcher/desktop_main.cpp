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

#include "util/argument_parser.h"
#include "util/date_time.h"
#include "util/logging.h"

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
/// Given some positional arguments, fill in a CreateProcessInfo struct that
/// contains everything needed for launching an app with CreateProcess()
/// \param  positional_arguments GFXR positional arguments
/// \param  process_info outgoing CreateProcessInfo struct
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
            process_info.app_path_plus_args = process_info.app_path + user_app.substr(args_loc);
            process_info.app_dir            = user_app.substr(0, user_app.rfind("\\"));

            success = true;
        }
    }

    return success;
}

//----------------------------------------------------------------------------
/// Basic app launcher that will inject our interceptor DLL and eventually
/// hook into D3D12 and DXGI
/// \param  argc Number of args
/// \param  argv Arg array
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
                STARTUPINFOA si = {};
                si.cb           = sizeof(si);

                PROCESS_INFORMATION pi = {};
                ZeroMemory(&pi, sizeof(pi));

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
                    &pi);
            }
        }
        catch (std::runtime_error error)
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
