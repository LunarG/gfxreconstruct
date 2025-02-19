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
#include "decode/preload_file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "decode/vulkan_pre_process_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "graphics/fps_info.h"
#include "util/argument_parser.h"
#include "util/logging.h"

#if defined(D3D12_SUPPORT)
#include "generated/generated_dx12_decoder.h"
#include "generated/generated_dx12_replay_consumer.h"
#include "decode/dx12_pre_process_consumer.h"
#ifdef GFXRECON_AGS_SUPPORT
#include "decode/custom_ags_consumer_base.h"
#include "decode/custom_ags_decoder.h"
#include "decode/custom_ags_replay_consumer.h"
#endif // GFXRECON_AGS_SUPPORT
#include "decode/dx12_tracking_consumer.h"
#include "graphics/dx12_util.h"
#endif
#include "parse_dump_resources_cli.h"

#include <exception>
#include <memory>
#include <stdexcept>

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

void RunVulkanPreProcessConsumer(const std::string&                      input_filename,
                                 gfxrecon::decode::VulkanReplayOptions&  replay_options,
                                 gfxrecon::decode::VulkanReplayConsumer& replay_consumer)
{
    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::VulkanPreProcessConsumer pre_process_consumer;

        if (replay_options.using_dump_resources_target)
        {
            pre_process_consumer.EnableDumpResources(replay_options.dump_resources_target);
        }

        gfxrecon::decode::VulkanDecoder decoder;
        decoder.AddConsumer(&pre_process_consumer);
        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();

        replay_options.enable_vulkan = pre_process_consumer.WasVulkanAPIDetected();

        if (replay_options.enable_vulkan)
        {
            if (replay_options.using_dump_resources_target)
            {
                replay_options.dump_resources_block_indices = pre_process_consumer.GetDumpResourcesBlockIndices();
            }

            if (replay_options.enable_dump_resources)
            {
                // Process --dump-resources block indices arg.
                if (!gfxrecon::parse_dump_resources::parse_dump_resources_arg(replay_options))
                {
                    GFXRECON_LOG_FATAL("There was an error while parsing dump resources indices. Terminating.");
                    exit(0);
                }
            }
        }
    }
    replay_consumer.InitializeReplayDumpResources();
}

#if defined(D3D12_SUPPORT)
void RunDx12PreProcessConsumer(const std::string&                    input_filename,
                               gfxrecon::decode::DxReplayOptions&    replay_options,
                               gfxrecon::decode::Dx12ReplayConsumer& replay_consumer)
{
    gfxrecon::decode::FileProcessor file_processor;
    if (file_processor.Initialize(input_filename))
    {
        gfxrecon::decode::Dx12PreProcessConsumer pre_process_consumer;

        if (replay_options.enable_dump_resources)
        {
            pre_process_consumer.EnableDumpResources(replay_options.dump_resources_target);
        }

        gfxrecon::decode::Dx12Decoder decoder;
        decoder.AddConsumer(&pre_process_consumer);
        file_processor.AddDecoder(&decoder);
        file_processor.ProcessAllFrames();

        replay_options.enable_d3d12 = pre_process_consumer.WasD3D12APIDetected();

        if (replay_options.enable_d3d12)
        {
            if (replay_options.enable_dump_resources)
            {
                auto track_dump_target = pre_process_consumer.GetTrackDumpTarget();
                GFXRECON_ASSERT(track_dump_target != nullptr);
                replay_consumer.SetDumpTarget(*track_dump_target);
            }
        }
    }
}
#endif

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

        std::unique_ptr<gfxrecon::decode::FileProcessor> file_processor;

        if (arg_parser.IsOptionSet(kPreloadMeasurementRangeOption))
        {
            file_processor = std::make_unique<gfxrecon::decode::PreloadFileProcessor>();
        }
        else
        {
            file_processor = std::make_unique<gfxrecon::decode::FileProcessor>();
        }

        if (!file_processor->Initialize(filename))
        {
            return_code = -1;
        }
        else
        {
            // Select WSI context based on CLI
            std::string wsi_extension = GetWsiExtensionName(GetWsiPlatform(arg_parser));
            auto        application   = std::make_shared<gfxrecon::application::Application>(
                kApplicationName, wsi_extension, file_processor.get());

            gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
            gfxrecon::decode::VulkanReplayOptions          vulkan_replay_options =
                GetVulkanReplayOptions(arg_parser, filename, &tracked_object_info_table);

            uint32_t start_frame = 0;
            uint32_t end_frame   = 0;

            bool     quit_after_frame = false;
            uint32_t quit_frame       = std::numeric_limits<uint32_t>::max();

            bool        has_mfr                            = false;
            bool        quit_after_measurement_frame_range = false;
            bool        flush_measurement_frame_range      = false;
            bool        flush_inside_measurement_range     = false;
            bool        preload_measurement_frame_range    = false;
            std::string measurement_file_name;

            if (vulkan_replay_options.enable_vulkan)
            {
                has_mfr                            = GetMeasurementFrameRange(arg_parser, start_frame, end_frame);
                quit_after_measurement_frame_range = vulkan_replay_options.quit_after_measurement_frame_range;
                flush_measurement_frame_range      = vulkan_replay_options.flush_measurement_frame_range;
                flush_inside_measurement_range     = vulkan_replay_options.flush_inside_measurement_range;
                preload_measurement_frame_range    = vulkan_replay_options.preload_measurement_range;

                if (vulkan_replay_options.quit_after_frame)
                {
                    quit_after_frame = true;
                    GetQuitAfterFrame(arg_parser, quit_frame);
                }
            }

            if (has_mfr)
            {
                GetMeasurementFilename(arg_parser, measurement_file_name);
            }

            gfxrecon::graphics::FpsInfo fps_info(static_cast<uint64_t>(start_frame),
                                                 static_cast<uint64_t>(end_frame),
                                                 has_mfr,
                                                 quit_after_measurement_frame_range,
                                                 flush_measurement_frame_range,
                                                 flush_inside_measurement_range,
                                                 preload_measurement_frame_range,
                                                 measurement_file_name,
                                                 quit_after_frame,
                                                 quit_frame);

            gfxrecon::decode::VulkanReplayConsumer vulkan_replay_consumer(application, vulkan_replay_options);
            gfxrecon::decode::VulkanDecoder        vulkan_decoder;

            RunVulkanPreProcessConsumer(filename, vulkan_replay_options, vulkan_replay_consumer);

            if (vulkan_replay_options.enable_vulkan)
            {
                vulkan_replay_consumer.SetFatalErrorHandler(
                    [](const char* message) { throw std::runtime_error(message); });
                vulkan_replay_consumer.SetFpsInfo(&fps_info);

                vulkan_decoder.AddConsumer(&vulkan_replay_consumer);
                file_processor->AddDecoder(&vulkan_decoder);
            }
            file_processor->SetPrintBlockInfoFlag(vulkan_replay_options.enable_print_block_info,
                                                  vulkan_replay_options.block_index_from,
                                                  vulkan_replay_options.block_index_to);

#if defined(D3D12_SUPPORT)
            gfxrecon::decode::DxReplayOptions    dx_replay_options = GetDxReplayOptions(arg_parser, filename);
            gfxrecon::decode::Dx12ReplayConsumer dx12_replay_consumer(application, dx_replay_options);
            gfxrecon::decode::Dx12Decoder        dx12_decoder;

#ifdef GFXRECON_AGS_SUPPORT
            gfxrecon::decode::AgsReplayConsumer ags_replay_consumer;
            gfxrecon::decode::AgsDecoder        ags_decoder;
#endif // GFXRECON_AGS_SUPPORT

            RunDx12PreProcessConsumer(filename, dx_replay_options, dx12_replay_consumer);

            if (dx_replay_options.enable_d3d12)
            {
                application->InitializeDx12WsiContext();
                if (gfxrecon::graphics::dx12::VerifyAgilitySDKRuntime() == false)
                {
                    GFXRECON_LOG_ERROR(
                        "Did not find Agility SDK runtimes. Verify \\D3D12\\D3D12Core.dll exists in the same "
                        "directory as gfxrecon-replay.exe.");
                }

                dx12_replay_consumer.SetFatalErrorHandler(
                    [](const char* message) { throw std::runtime_error(message); });
                dx12_replay_consumer.SetFpsInfo(&fps_info);

                // check for user option if first pass tracking is enabled
                if (dx_replay_options.enable_d3d12_two_pass_replay)
                {
                    gfxrecon::decode::FileProcessor              file_processor_tracking;
                    gfxrecon::decode::Dx12TrackedObjectInfoTable tracked_object_info_table;
                    auto                                         tracking_consumer =
                        new gfxrecon::decode::DX12TrackingConsumer(dx_replay_options, &tracked_object_info_table);
                    if (file_processor_tracking.Initialize(filename))
                    {
                        dx12_decoder.AddConsumer(tracking_consumer);
                        file_processor_tracking.AddDecoder(&dx12_decoder);
                        file_processor_tracking.ProcessAllFrames();
                        file_processor_tracking.RemoveDecoder(&dx12_decoder);
                        dx12_decoder.RemoveConsumer(tracking_consumer);
                    }
                }
                dx12_decoder.AddConsumer(&dx12_replay_consumer);
                file_processor->AddDecoder(&dx12_decoder);

#ifdef GFXRECON_AGS_SUPPORT
                ags_replay_consumer.AddDx12Consumer(&dx12_replay_consumer);
                ags_decoder.AddConsumer(reinterpret_cast<gfxrecon::decode::AgsConsumerBase*>(&ags_replay_consumer));

                file_processor->AddDecoder(&ags_decoder);
#endif // GFXRECON_AGS_SUPPORT
            }
#endif

            // Warn if the capture layer is active.
            CheckActiveLayers(gfxrecon::util::platform::GetEnv(kLayerEnvVar));

            fps_info.BeginFile();

            application->SetPauseFrame(GetPauseFrame(arg_parser));
            application->SetFpsInfo(&fps_info);
            application->Run();

            // XXX if the final frame ended with a Present, this would be the *next* frame
            // Add one so that it matches the trim range frame number semantic
            fps_info.EndFile(file_processor->GetCurrentFrameNumber() + 1);

            if ((file_processor->GetCurrentFrameNumber() > 0) &&
                (file_processor->GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
            {
                if (file_processor->GetCurrentFrameNumber() < start_frame)
                {
                    GFXRECON_LOG_WARNING(
                        "Measurement range start frame (%u) is greater than the last replayed frame (%u). "
                        "Measurements were never started, cannot calculate measurement range FPS.",
                        start_frame,
                        file_processor->GetCurrentFrameNumber());
                }
                else
                {
#if defined(D3D12_SUPPORT)
                    dx12_replay_consumer.PostReplay();
                    if (!dx_replay_options.screenshot_ranges.empty() && !file_processor->UsesFrameMarkers() &&
                        (dx12_replay_consumer.GetDXGITestPresentCount() > 0))
                    {
                        GFXRECON_LOG_WARNING_ONCE(
                            "This capture contains %" PRIu32
                            " calls to IDXGISwapChain::Present with flag DXGI_PRESENT_TEST and no frame end markers. "
                            "Screenshot frame indexing may have changed since capture.",
                            dx12_replay_consumer.GetDXGITestPresentCount());
                    }
#endif

                    fps_info.LogToConsole();
                }
            }
            else if (file_processor->GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
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
