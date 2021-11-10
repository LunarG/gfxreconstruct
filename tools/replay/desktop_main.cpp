/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "application/application.h"
#include "decode/file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "graphics/fps_info.h"
#include "util/argument_parser.h"
#include "util/logging.h"

#include <exception>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#if defined(WIN32)
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
    int return_code = 0;

    // Default initialize logging to report issues while loading settings.
    gfxrecon::util::Log::Init(gfxrecon::decode::kDefaultLogLevel);

    gfxrecon::util::ArgumentParser arg_parser(argc, argv, kOptions, kArguments);

    if (CheckOptionPrintVersion(argv[0], arg_parser) || CheckOptionPrintUsage(argv[0], arg_parser))
    {
        gfxrecon::util::Log::Release();
        exit(0);
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() != 1))
    {
        PrintUsage(argv[0]);
        gfxrecon::util::Log::Release();
        exit(-1);
    }
    else
    {
        ProcessDisableDebugPopup(arg_parser);
    }

    // Reinitialize logging with values retrieved from command line arguments
    gfxrecon::util::Log::Settings log_settings;
    GetLogSettings(arg_parser, log_settings);
    gfxrecon::util::Log::Release();
    gfxrecon::util::Log::Init(log_settings);

    try
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        std::string                     filename             = positional_arguments[0];

        gfxrecon::decode::FileProcessor file_processor;
        if (!file_processor.Initialize(filename))
        {
            return_code = -1;
        }
        else
        {
            // Select WSI context based on CLI
            auto wsi_platform = GetWsiPlatform(arg_parser);
            auto application = std::make_shared<gfxrecon::application::Application>(kApplicationName, &file_processor, wsi_platform);


// #if defined(WIN32)
// #if defined(VK_USE_PLATFORM_WIN32_KHR)
//             if (wsi_platform == WsiPlatform::kWin32)
//             {
//                 application->InitializeWsiContext(VK_KHR_WIN32_SURFACE_EXTENSION_NAME);
//                 if (!application->GetWsiContext())
//                 {
//                     GFXRECON_WRITE_CONSOLE("Failed to initialize command line selected Win32 WSI context");
//                     return_code = -1;
//                 }
//             }
// #endif
// #else
// #if defined(VK_USE_PLATFORM_WAYLAND_KHR)
//             if (wsi_platform == WsiPlatform::kWayland)
//             {
//                 application->InitializeWsiContext(VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME);
//                 if (!application->GetWsiContext())
//                 {
//                     GFXRECON_WRITE_CONSOLE("Failed to initialize command line selected Wayland WSI context");
//                     return_code = -1;
//                 }
//             }
// #endif
// #if defined(VK_USE_PLATFORM_XCB_KHR)
//             if (wsi_platform == WsiPlatform::kXcb)
//             {
//                 application->InitializeWsiContext(VK_KHR_XCB_SURFACE_EXTENSION_NAME);
//                 if (!application->GetWsiContext())
//                 {
//                     GFXRECON_WRITE_CONSOLE("Failed to initialize command line selected XCB WSI context");
//                     return_code = -1;
//                 }
//             }
// #endif
// #if defined(VK_USE_PLATFORM_XLIB_KHR)
//             if (wsi_platform == WsiPlatform::kXlib)
//             {
//                 application->InitializeWsiContext(VK_KHR_XLIB_SURFACE_EXTENSION_NAME);
//                 if (!application->GetWsiContext())
//                 {
//                     GFXRECON_WRITE_CONSOLE("Failed to initialize command line selected Xlib WSI context");
//                     return_code = -1;
//                 }
//             }
// #endif
// #endif
// #if defined(VK_USE_PLATFORM_HEADLESS)
//             if (wsi_platform == WsiPlatform::kHeadless)
//             {
//                 application->InitializeWsiContext(VK_EXT_HEADLESS_SURFACE_EXTENSION_NAME);
//                 if (!application->GetWsiContext())
//                 {
//                     GFXRECON_WRITE_CONSOLE("Failed to initialize command line selected Headless WSI context");
//                     return_code = -1;
//                 }
//             }
// #endif

            gfxrecon::graphics::FpsInfo                    fps_info;
            gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
            gfxrecon::decode::VulkanReplayConsumer         replay_consumer(
                application, GetVulkanReplayOptions(arg_parser, filename, &tracked_object_info_table));
            gfxrecon::decode::VulkanDecoder decoder;

            replay_consumer.SetFatalErrorHandler([](const char* message) { throw std::runtime_error(message); });
            replay_consumer.SetFpsInfo(&fps_info);

            decoder.AddConsumer(&replay_consumer);
            file_processor.AddDecoder(&decoder);
            application->SetPauseFrame(GetPauseFrame(arg_parser));

            // Warn if the capture layer is active.
            CheckActiveLayers(gfxrecon::util::platform::GetEnv(kLayerEnvVar));

            fps_info.Begin();

            application->Run();

            if ((file_processor.GetCurrentFrameNumber() > 0) &&
                (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
            {
                fps_info.EndAndLog(file_processor.GetCurrentFrameNumber());
            }
            else if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
            {
                GFXRECON_WRITE_CONSOLE("A failure has occurred during replay");
                return_code = -1;
            }
            else
            {
                GFXRECON_WRITE_CONSOLE("File did not contain any frames");
            }
        }
    }
    catch (std::runtime_error error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = -1;
    }
    catch (...)
    {
        GFXRECON_WRITE_CONSOLE("Replay failed due to an unhandled exception");
        return_code = -1;
    }

    WaitForExit();

    gfxrecon::util::Log::Release();

    return return_code;
}
