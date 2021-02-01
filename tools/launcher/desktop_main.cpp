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

//----------------------------------------------------------------------------
/// Surrounds a string with quotes if it has any spaces
/// \param  str_app String to modify
/// \return The original quoted string
//----------------------------------------------------------------------------
std::string AddQuotesIfStringHasSpaces(const std::string& str_app)
{
    std::string out_str = str_app;

    // if the argument has a space add quotes
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
/// Given a path to an executable, figure out its root
/// \param  str_app
/// \return App directory str
//----------------------------------------------------------------------------
std::string ConstructAppDir(const std::string& str_app)
{
    std::string str_dir = "";

    size_t pos = str_app.find_last_of("\\");

    if (pos != std::string::npos)
    {
        str_dir = str_app.substr(0, (int)pos);

        if (str_app[0] == '\"')
        {
            str_dir += "\"";
        }
    }

    return str_dir;
}

// ---------------------------------------------------------------------------
/// Print launcher usage
/// \param launcher_name The name of the launcher
// ---------------------------------------------------------------------------
void PrintUsage(const std::string& launcher_name)
{
    GFXRECON_WRITE_CONSOLE("\n%s - A tool to launch applications for GFXR capture.\n", launcher_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("  %s <application>", launcher_name.c_str());
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

            std::string str_app      = positional_arguments.front();
            std::string str_dir      = ConstructAppDir(str_app);
            std::string str_cmd_line = AddQuotesIfStringHasSpaces(str_app.c_str());

            PROCESS_INFORMATION pi = {};
            ZeroMemory(&pi, sizeof(pi));

            STARTUPINFOA si = {};
            si.cb           = sizeof(si);

            CreateProcessA(str_app.c_str(),
                           const_cast<LPSTR>(str_cmd_line.c_str()),
                           nullptr,
                           nullptr,
                           TRUE,
                           CREATE_DEFAULT_ERROR_MODE | CREATE_SUSPENDED,
                           nullptr,
                           str_dir.c_str(),
                           &si,
                           &pi);

            const std::string interceptor_path = GFXR_INTERCEPTOR_PATH;

            gfxrecon::util::interception::InjectDllIntoProcess(interceptor_path.c_str(), pi.hProcess);

            ResumeThread(pi.hThread);
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
