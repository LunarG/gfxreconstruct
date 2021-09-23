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

// #if defined(WIN32)
// #if defined(VK_USE_PLATFORM_WIN32_KHR)
// #include "application/win32_window.h"
// #endif
// #else
// #if defined(VK_USE_PLATFORM_XCB_KHR)
// #include "application/xcb_window.h"
// #endif
// #if defined(VK_USE_PLATFORM_XLIB_KHR)
// #include "application/xlib_window.h"
// #endif
// #if defined(VK_USE_PLATFORM_WAYLAND_KHR)
// #include "application/wayland_window.h"
// #endif
// #endif
// #if defined(VK_USE_PLATFORM_HEADLESS)
// #include "application/headless_window.h"
// #endif

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
            auto wsi_platform = GetWsiPlatform(arg_parser);

            auto application = std::make_unique<gfxrecon::application::Application>(kApplicationName, &file_processor);

            // Setup platform specific application and window factory.
            // TODO : window_factory_ update...
            #if 0
#if defined(WIN32)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
            #if 0
            if (wsi_platform == WsiPlatform::kWin32 || (wsi_platform == WsiPlatform::kAuto && !application))
            {
                auto win32_application = std::make_unique<gfxrecon::application::Win32Application>(kApplicationName);
                if (win32_application->Initialize(&file_processor))
                {
                    window_factory =
                        std::make_unique<gfxrecon::application::Win32WindowFactory>(win32_application.get());
                    application = std::move(win32_application);
                }
            }
            #else

            #endif
#endif
#else
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
            if (wsi_platform == WsiPlatform::kWayland || (wsi_platform == WsiPlatform::kAuto && !application))
            {
                auto wayland_application =
                    std::make_unique<gfxrecon::application::WaylandApplication>(kApplicationName);
                if (wayland_application->Initialize(&file_processor))
                {
                    window_factory =
                        std::make_unique<gfxrecon::application::WaylandWindowFactory>(wayland_application.get());
                    application = std::move(wayland_application);
                }
            }
#endif
#if defined(VK_USE_PLATFORM_XCB_KHR)
            if (wsi_platform == WsiPlatform::kXcb || (wsi_platform == WsiPlatform::kAuto && !application))
            {
                auto xcb_application = std::make_unique<gfxrecon::application::XcbApplication>(kApplicationName);
                if (xcb_application->Initialize(&file_processor))
                {
                    window_factory = std::make_unique<gfxrecon::application::XcbWindowFactory>(xcb_application.get());
                    application    = std::move(xcb_application);
                }
            }
#endif
#if defined(VK_USE_PLATFORM_XLIB_KHR)
            if (wsi_platform == WsiPlatform::kXlib || (wsi_platform == WsiPlatform::kAuto && !application))
            {
                auto xlib_application = std::make_unique<gfxrecon::application::XlibApplication>(kApplicationName);
                if (xlib_application->Initialize(&file_processor))
                {
                    window_factory = std::make_unique<gfxrecon::application::XlibWindowFactory>(xlib_application.get());
                    application    = std::move(xlib_application);
                }
            }
#endif
#endif
#if defined(VK_USE_PLATFORM_HEADLESS)
            #if 0
            if (wsi_platform == WsiPlatform::kHeadless || (wsi_platform == WsiPlatform::kAuto && !application))
            {
                auto headless_application =
                    std::make_unique<gfxrecon::application::HeadlessApplication>(kApplicationName);
                if (headless_application->Initialize(&file_processor))
                {
                    window_factory =
                        std::make_unique<gfxrecon::application::HeadlessWindowFactory>(headless_application.get());
                    application = std::move(headless_application);
                }
            }
            #endif
#endif
            #endif

            if (/*!window_factory || !application*/ !application)
            {
                GFXRECON_WRITE_CONSOLE(
                    "Failed to initialize platform specific window system management.\nEnsure that the appropriate "
                    "Vulkan platform extensions have been enabled.");
                return_code = -1;
            }
            else
            {
                gfxrecon::graphics::FpsInfo                    fps_info;
                gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
                gfxrecon::decode::VulkanReplayConsumer         replay_consumer(
                    application.get(), GetReplayOptions(arg_parser, filename, &tracked_object_info_table));
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
