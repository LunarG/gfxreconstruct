/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "application/application.h"
#include "decode/file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "graphics/fps_info.h"
#include "util/argument_parser.h"
#include "util/logging.h"

#if defined(D3D12_SUPPORT)
#include "decode/dx12_tracked_object_info_table.h"
#include "generated/generated_dx12_decoder.h"
#include "generated/generated_dx12_replay_consumer.h"
#ifdef GFXRECON_AGS_SUPPORT
#include "decode/custom_ags_consumer_base.h"
#include "decode/custom_ags_decoder.h"
#include "decode/custom_ags_replay_consumer.h"
#endif // GFXRECON_AGS_SUPPORT
#include "graphics/dx12_util.h"
#endif

#include <exception>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include <utility>

#if defined(D3D12_SUPPORT)

extern "C"
{
    __declspec(dllexport) extern const UINT D3D12SDKVersion = 610;
}
extern "C"
{
    __declspec(dllexport) extern const char* D3D12SDKPath = u8".\\D3D12\\";
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
            gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
            gfxrecon::decode::VulkanReplayOptions          vulkan_replay_options =
                GetVulkanReplayOptions(arg_parser, filename, &tracked_object_info_table);
            gfxrecon::decode::VulkanSwapchain::VulkanWindowList vulkan_windows;

#if defined(D3D12_SUPPORT)
            gfxrecon::decode::Dx12TrackedObjectInfoTable dx_tracked_object_info_table;
            gfxrecon::decode::DxReplayOptions            dx_replay_options =
                GetDxReplayOptions(arg_parser, filename, &dx_tracked_object_info_table);
            gfxrecon::decode::Dx12ReplayConsumer::DxWindowList dx_windows;
#endif

            // Select WSI context based on CLI
            std::string wsi_extension = GetWsiExtensionName(GetWsiPlatform(arg_parser));
            auto        application   = std::make_shared<gfxrecon::application::Application>(
                kApplicationName, wsi_extension, &file_processor, vulkan_replay_options.enable_vulkan);

#if defined(D3D12_SUPPORT)
            if (dx_replay_options.enable_d3d12)
            {
                application->InitializeDx12WsiContext();
                if (gfxrecon::graphics::dx12::VerifyAgilitySDKRuntime() == false)
                {
                    GFXRECON_LOG_ERROR(
                        "Did not find Agility SDK runtimes. Verify \\D3D12\\D3D12Core.dll exists in the same "
                        "directory as gfxrecon-replay.exe.");
                }
            }
#endif

            uint32_t start_frame = 0;
            uint32_t end_frame   = 0;

            bool        has_mfr                            = false;
            bool        quit_after_measurement_frame_range = false;
            bool        flush_measurement_frame_range      = false;
            bool        flush_inside_measurement_range     = false;
            std::string measurement_file_name;

            if (vulkan_replay_options.enable_vulkan)
            {
                has_mfr                            = GetMeasurementFrameRange(arg_parser, start_frame, end_frame);
                quit_after_measurement_frame_range = vulkan_replay_options.quit_after_measurement_frame_range;
                flush_measurement_frame_range      = vulkan_replay_options.flush_measurement_frame_range;
                flush_inside_measurement_range     = vulkan_replay_options.flush_inside_measurement_range;
            }

            if (has_mfr)
            {
                GetMeasurementFilename(arg_parser, measurement_file_name);
            }

            uint32_t loop_count    = 0;
            uint64_t loop_duration = 0;
            GetLoopingEndOptions(arg_parser, loop_count, loop_duration);

            gfxrecon::graphics::FpsInfo fps_info(static_cast<uint64_t>(start_frame),
                                                 static_cast<uint64_t>(end_frame),
                                                 has_mfr,
                                                 quit_after_measurement_frame_range,
                                                 flush_measurement_frame_range,
                                                 flush_inside_measurement_range,
                                                 loop_count,
                                                 loop_duration,
                                                 measurement_file_name);

            // Warn if the capture layer is active.
            CheckActiveLayers(gfxrecon::util::platform::GetEnv(kLayerEnvVar));

            fps_info.BeginFile();

            application->SetPauseFrame(GetPauseFrame(arg_parser));
            application->SetFpsInfo(&fps_info);

            while (true)
            {
                // Loop setup
                fps_info.BeginLoop();

                gfxrecon::decode::VulkanReplayConsumer vulkan_replay_consumer(application, vulkan_replay_options);
                vulkan_replay_consumer.SetInactiveWindows(vulkan_windows);

                gfxrecon::decode::VulkanDecoder vulkan_decoder;

                if (vulkan_replay_options.enable_vulkan)
                {
                    vulkan_replay_consumer.SetFatalErrorHandler(
                        [](const char* message) { throw std::runtime_error(message); });

                    vulkan_decoder.AddConsumer(&vulkan_replay_consumer);
                    file_processor.AddDecoder(&vulkan_decoder);
                }

#if defined(D3D12_SUPPORT)
                gfxrecon::decode::Dx12ReplayConsumer dx12_replay_consumer(application, dx_replay_options);
                dx12_replay_consumer.SetInactiveWindows(dx_windows);

                gfxrecon::decode::Dx12Decoder dx12_decoder;

#ifdef GFXRECON_AGS_SUPPORT
                gfxrecon::decode::AgsReplayConsumer ags_replay_consumer;
                gfxrecon::decode::AgsDecoder        ags_decoder;
#endif // GFXRECON_AGS_SUPPORT

                if (dx_replay_options.enable_d3d12)
                {
                    dx12_replay_consumer.SetFatalErrorHandler(
                        [](const char* message) { throw std::runtime_error(message); });

                    dx12_decoder.AddConsumer(&dx12_replay_consumer);
                    file_processor.AddDecoder(&dx12_decoder);

#ifdef GFXRECON_AGS_SUPPORT
                    ags_replay_consumer.AddDx12Consumer(&dx12_replay_consumer);
                    ags_decoder.AddConsumer(reinterpret_cast<gfxrecon::decode::AgsConsumerBase*>(&ags_replay_consumer));

                    file_processor.AddDecoder(&ags_decoder);
#endif // GFXRECON_AGS_SUPPORT
                }
#endif

                // Main replay processing
                application->Run();

                vulkan_windows = vulkan_replay_consumer.GetInactiveWindows();
#if defined(D3D12_SUPPORT)
                dx_windows = dx12_replay_consumer.GetInactiveWindows();
#endif

                // Error checking and loop cleanup
                if ((file_processor.GetCurrentFrameNumber() > 0) &&
                    (file_processor.GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
                {
                    if (file_processor.GetCurrentFrameNumber() < start_frame)
                    {
                        GFXRECON_LOG_WARNING(
                            "Measurement range start frame (%u) is greater than the last replayed frame (%u). "
                            "Measurements were never started, cannot calculate measurement range FPS.",
                            start_frame,
                            file_processor.GetCurrentFrameNumber());
                    }
                    else
                    {
#if defined(D3D12_SUPPORT)
                        dx12_replay_consumer.PostReplay();
#endif
                    }
                }
                else if (file_processor.GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
                {
                    GFXRECON_WRITE_CONSOLE("A failure has occurred during replay");
                    return_code = -1;
                    break;
                }
                else
                {
                    GFXRECON_WRITE_CONSOLE("File did not contain any frames");
                    break;
                }

                fps_info.EndLoop();

                if (vulkan_replay_options.enable_vulkan)
                {
                    vulkan_decoder.RemoveConsumer(&vulkan_replay_consumer);
                    file_processor.RemoveDecoder(&vulkan_decoder);
                }

#if defined(D3D12_SUPPORT)
                if (dx_replay_options.enable_d3d12)
                {
                    dx12_decoder.RemoveConsumer(&dx12_replay_consumer);
                    file_processor.RemoveDecoder(&dx12_decoder);
                }
#endif

                // Looping processing
                if (!file_processor.EntireFileWasProcessed())
                {
                    GFXRECON_WRITE_CONSOLE("File was not completely processed, aborting looping early")
                    application->SetWasFinalLoop(true);
                    break;
                }

                uint32_t loop_number = file_processor.GetCurrentLoopNumber() + 1;

                if (fps_info.ShouldLoop(loop_number))
                {
                    GFXRECON_LOG_INFO("Looping, starting loop number %" PRIu32, loop_number);
                    file_processor.Loop();
                }
                else
                {
                    application->SetWasFinalLoop(true);
                    break;
                }
            }

            // XXX if the final frame ended with a Present, this would be the *next* frame
            // Add one so that it matches the trim range frame number semantic
            fps_info.EndFile(file_processor.GetCurrentFrameNumber() + 1);

            fps_info.LogToConsole();
        }
    }
    catch (const std::runtime_error& error)
    {
        GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        return_code = -1;
    }
    catch (const std::exception& error)
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
