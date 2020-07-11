/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "replay_settings.h"

#include "application/application.h"
#include "decode/file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "util/argument_parser.h"
#include "util/date_time.h"
#include "util/logging.h"

#include <exception>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

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

const char kLayerEnvVar[] = "VK_INSTANCE_LAYERS";

int main(int argc, const char** argv)
{
    int return_code = 0;

    gfxrecon::util::Log::Init();

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

    try
    {
        const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
        std::string                     filename             = positional_arguments[0];

        gfxrecon::decode::FileProcessor                     file_processor;
        std::unique_ptr<gfxrecon::application::Application> application;
        std::unique_ptr<gfxrecon::decode::WindowFactory>    window_factory;

        if (!file_processor.Initialize(filename))
        {
            return_code = -1;
        }
        else
        {
            auto wsi_platform = GetWsiPlatform(arg_parser);

            // Setup platform specific application and window factory.
#if defined(WIN32)
#if defined(VK_USE_PLATFORM_WIN32_KHR)
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
#endif

            if (!window_factory || !application)
            {
                GFXRECON_WRITE_CONSOLE(
                    "Failed to initialize platform specific window system management.\nEnsure that the appropriate "
                    "Vulkan platform extensions have been enabled.");
                return_code = -1;
            }
            else
            {
                gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
                gfxrecon::decode::VulkanReplayConsumer         replay_consumer(
                    window_factory.get(), GetReplayOptions(arg_parser, filename, &tracked_object_info_table));
                gfxrecon::decode::VulkanDecoder decoder;

                replay_consumer.SetFatalErrorHandler([](const char* message) { throw std::runtime_error(message); });

                decoder.AddConsumer(&replay_consumer);
                file_processor.AddDecoder(&decoder);
                application->SetPauseFrame(GetPauseFrame(arg_parser));

                // Warn if the capture layer is active.
                CheckActiveLayers(kLayerEnvVar);

                // Grab the start frame/time information for the FPS result.
                uint32_t start_frame = 1;
                int64_t  start_time  = gfxrecon::util::datetime::GetTimestamp();

                application->Run();

                if ((file_processor.GetCurrentFrameNumber() > 0) &&
                    (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
                {
                    // Grab the end frame/time information and calculate FPS.
                    int64_t end_time      = gfxrecon::util::datetime::GetTimestamp();
                    double  diff_time_sec = gfxrecon::util::datetime::ConvertTimestampToSeconds(
                        gfxrecon::util::datetime::DiffTimestamps(start_time, end_time));
                    uint32_t end_frame    = file_processor.GetCurrentFrameNumber();
                    uint32_t total_frames = (end_frame - start_frame) + 1;
                    double   fps          = static_cast<double>(total_frames) / diff_time_sec;
                    GFXRECON_WRITE_CONSOLE("%f fps, %f seconds, %u frame%s, 1 loop, framerange %u-%u",
                                           fps,
                                           diff_time_sec,
                                           total_frames,
                                           total_frames > 1 ? "s" : "",
                                           start_frame,
                                           end_frame);
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

    gfxrecon::util::Log::Release();

    return return_code;
}
