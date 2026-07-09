/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#include "replay_settings.h"
#include "replay_main_common.h"

#include "application/application.h"
#include "decode/file_processor.h"
#include "util/logging.h"
#include "parse_dump_resources_cli.h"

#include <algorithm>
#include <exception>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#if defined(D3D12_SUPPORT)

extern "C"
{
    __declspec(dllexport) extern const UINT D3D12SDKVersion = 618;
}
extern "C"
{
    __declspec(dllexport) extern const char* D3D12SDKPath = reinterpret_cast<const char*>(u8".\\D3D12\\");
}

#include <conio.h>
void WaitForExit()
{
    DWORD process_list[2];
    DWORD result = GetConsoleProcessList(process_list, ARRAYSIZE(process_list));

    // If the process list contains a single entry, we assume that the console was created when the gfxrecon-replay.exe
    // process started, and will be destroyed when it exits.  In this case, we will wait on user input before exiting
    // and closing the console window to give the user a chance to read any console output.
    if (result <= 1)
    {
        GFXRECON_WRITE_CONSOLE("\nPress any key to close this window . . .");
        while (!_kbhit())
        {
            Sleep(250);
        }
    }
}
#else
void WaitForExit() {}
#endif

const char kLayerEnvVar[] = "VK_INSTANCE_LAYERS";

int main(int argc, const char** argv)
{
    struct LogGuard
    {
        LogGuard()
        {
            gfxrecon::util::Log::Init(gfxrecon::decode::kDefaultLogLevel);
            gfxrecon::util::Log::SetFatalCallback([](const char* message) { throw std::runtime_error(message); });
        }
        ~LogGuard() { gfxrecon::util::Log::Release(); }
    } log_guard;

    int return_code = EXIT_SUCCESS;

    std::vector<std::unique_ptr<gfxrecon::replay::ReplayFeatureBase>> features;
    gfxrecon::replay::LoadFeatures(features);

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintVersion(argv[0], arg_parser) || CheckOptionPrintUsage(argv[0], arg_parser))
    {
        return EXIT_SUCCESS;
    }
    else if (arg_parser.IsOptionSet(kListModulesOption))
    {
        PrintModuleListHeader(argv[0]);
        std::vector<std::string> module_feature_list;
        for (auto& feature : features)
        {
            module_feature_list.push_back(feature->Label());
        }
        std::ranges::sort(module_feature_list);
        for (auto& feature_string : module_feature_list)
        {
            GFXRECON_WRITE_CONSOLE("   %s", feature_string.c_str());
        }

        return EXIT_SUCCESS;
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        return EXIT_FAILURE;
    }
    else
    {
        ProcessDisableDebugPopup(arg_parser);
    }

    gfxrecon::util::Log::Settings log_settings;
    GetLogSettings(arg_parser, log_settings);
    gfxrecon::util::Log::UpdateWithSettings(log_settings);

    try
    {
        const std::string filename = arg_parser.GetPositionalArguments()[0];

        std::unique_ptr<gfxrecon::decode::FileProcessor> file_processor;

        std::string wsi_extension    = GetWsiExtensionName(GetWsiPlatform(arg_parser));
        auto        make_application = [&](gfxrecon::decode::FileProcessor* fp) {
            return std::make_shared<gfxrecon::application::Application>(kApplicationName, fp, wsi_extension, nullptr);
        };

        if (!gfxrecon::replay::RunReplay(file_processor,
                                         features,
                                         arg_parser,
                                         filename,
                                         gfxrecon::util::platform::GetEnv(kLayerEnvVar),
                                         make_application))
        {
            return_code = EXIT_FAILURE;
        }
    }
    catch (const std::runtime_error& error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = EXIT_FAILURE;
    }
    catch (const std::exception& error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = EXIT_FAILURE;
    }
    catch (...)
    {
        GFXRECON_WRITE_CONSOLE("Replay failed due to an unhandled exception");
        return_code = EXIT_FAILURE;
    }

    WaitForExit();

    return return_code;
}
