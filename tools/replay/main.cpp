/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <cstdio>
#include <exception>
#include <memory>
#include <string>

#include "application/application.h"
#include "decode/file_processor.h"
#include "decode/window.h"
#include "format/format.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "util/argument_parser.h"
#include "util/logging.h"

#if defined(WIN32)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
#include "application/win32_application.h"
#include "application/win32_window.h"
#endif
#else
#if defined(VK_USE_PLATFORM_XCB_KHR)
#include "application/xcb_application.h"
#include "application/xcb_window.h"
#endif
#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
#include "application/wayland_application.h"
#include "application/wayland_window.h"
#endif
#endif

const std::string kApplicationName = "GCAP Player";

void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");
    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }
    BRIMSTONE_WRITE_CONSOLE("\n%s\tis a trace replay tool designed to playback trace binary files.\n",
                            app_name.c_str());
    BRIMSTONE_WRITE_CONSOLE("Usage:");
    BRIMSTONE_WRITE_CONSOLE("\t%s <file>\n", app_name.c_str());
    BRIMSTONE_WRITE_CONSOLE("\t<file>\t\tThe filename (including path if necessary) of the ");
    BRIMSTONE_WRITE_CONSOLE("\t\t\t\ttrace file to replay");
}

int main(int argc, const char** argv)
{
    int return_code = 0;

    brimstone::util::logging::Init();

    brimstone::decode::FileProcessor file_processor;
    std::string                      filename;

    brimstone::util::ArgumentParser arg_parser(argc, argv, "", "", 1);
    const std::vector<std::string>  non_optional_arguments = arg_parser.GetNonOptionalArguments();
    if (arg_parser.IsInvalid() || non_optional_arguments.size() != 1)
    {
        PrintUsage(argv[0]);
        return_code = -1;
    }
    else
    {
        filename = non_optional_arguments[0];

        try
        {
            std::unique_ptr<brimstone::application::Application> application;
            std::unique_ptr<brimstone::decode::WindowFactory>    window_factory;

            if (!file_processor.Initialize(filename))
            {
                BRIMSTONE_WRITE_CONSOLE("Failed to load file %s.", filename.c_str());
                return_code = -1;
            }
            else
            {
                // Setup platform specific application and window factory.
#if defined(WIN32)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
                brimstone::application::Win32Application* win32_application =
                    new brimstone::application::Win32Application(kApplicationName);
                application    = std::unique_ptr<brimstone::application::Application>(win32_application);
                window_factory = std::make_unique<brimstone::application::Win32WindowFactory>(win32_application);
#endif
#else
#if defined(VK_USE_PLATFORM_XCB_KHR)
                brimstone::application::XcbApplication* xcb_application =
                    new brimstone::application::XcbApplication(kApplicationName);
                application    = std::unique_ptr<brimstone::application::Application>(xcb_application);
                window_factory = std::make_unique<brimstone::application::XcbWindowFactory>(xcb_application);
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
                brimstone::application::WaylandApplication* wayland_application =
                    new brimstone::application::WaylandApplication(kApplicationName);
                application    = std::unique_ptr<brimstone::application::Application>(wayland_application);
                window_factory = std::make_unique<brimstone::application::WaylandWindowFactory>(wayland_application);
#endif
#endif

                if (!window_factory || !application || !application->Initialize(&file_processor))
                {
                    BRIMSTONE_WRITE_CONSOLE(
                        "Failed to initialize platform specific window system management.\nEnsure that the appropriate "
                        "Vulkan platform extensions have been enabled.");
                    return_code = -1;
                }
                else
                {
                    brimstone::decode::VulkanDecoder        decoder;
                    brimstone::decode::VulkanReplayConsumer replay_consumer(window_factory.get());

                    replay_consumer.SetFatalErrorHandler(
                        [](const char* message) { throw std::runtime_error(message); });

                    decoder.AddConsumer(&replay_consumer);
                    file_processor.AddDecoder(&decoder);

                    application->Run();
                }
            }
        }
        catch (std::runtime_error error)
        {
            BRIMSTONE_WRITE_CONSOLE("Replay failed with error message: %s", error.what());
            return_code = -1;
        }
        catch (...)
        {
            BRIMSTONE_WRITE_CONSOLE("Replay failed due to an unhandled exception");
            return_code = -1;
        }
    }

    brimstone::util::logging::Release();

    return return_code;
}
