/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#include "application/android_context.h"
#include "application/android_window.h"
#include "decode/file_processor.h"
#include "decode/preload_file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "decode/vulkan_pre_process_consumer.h"
#include "format/format.h"

// Includes for recapture
#include "encode/vulkan_capture_manager.h"
#include "recapture_vulkan_entry.h"

#if ENABLE_OPENXR_SUPPORT
#include "decode/openxr_tracked_object_info_table.h"
#include "generated/generated_openxr_decoder.h"
#include "generated/generated_openxr_replay_consumer.h"
#endif
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "util/android/activity.h"
#include "util/android/intent.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"
#include "parse_dump_resources_cli.h"
#include "replay_pre_processing.h"
#include "util/android/intent.h"

#include <android/log.h>
#include <android/window.h>

#include <cstdlib>
#include <exception>
#include <memory>
#include <string>
#include <vector>
#include <utility>

const char kArgsExtentKey[]      = "args";
const char kDefaultCaptureFile[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;
const char kLayerProperty[]      = "debug.vulkan.layers";

const int32_t kSwipeDistance = 200;

void        ProcessAppCmd(struct android_app* app, int32_t cmd);
int32_t     ProcessInputEvent(struct android_app* app, AInputEvent* event);

static std::unique_ptr<gfxrecon::decode::FileProcessor> file_processor;

extern "C"
{
    uint64_t MainGetCurrentBlockIndex()
    {
        if (file_processor != nullptr)
        {
            return file_processor->GetCurrentBlockIndex();
        }
        else
        {
            return 0;
        }
    }

    bool MainGetLoadingTrimmedState()
    {
        if (file_processor != nullptr)
        {
            return file_processor->GetLoadingTrimmedState();
        }
        else
        {
            return false;
        }
    }
}

void android_main(struct android_app* app)
{
    GFXRECON_WRITE_CONSOLE("====== Entering android_main");
    gfxrecon::util::Log::Init();

    // Keep screen on while window is active.
    ANativeActivity_setWindowFlags(app->activity, AWINDOW_FLAG_KEEP_SCREEN_ON, 0);

    std::string                    args = gfxrecon::util::GetIntentExtra(app, kArgsExtentKey);
    gfxrecon::util::ArgumentParser arg_parser(false, args.c_str(), kOptions, kArguments);

    app->onAppCmd     = ProcessAppCmd;
    app->onInputEvent = ProcessInputEvent;

    bool run = true;

    if (CheckOptionPrintUsage(kApplicationName, arg_parser) || CheckOptionPrintVersion(kApplicationName, arg_parser))
    {
        run = false;
    }
    else if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() > 1))
    {
        PrintUsage(kApplicationName);
        run = false;
    }

    if (run)
    {
        // Reinitialize logging with values retrieved from command line arguments
        gfxrecon::util::Log::Settings log_settings;
        GetLogSettings(arg_parser, log_settings);
        gfxrecon::util::Log::Release();
        gfxrecon::util::Log::Init(log_settings);

        std::string filename = kDefaultCaptureFile;

        if (arg_parser.GetPositionalArgumentsCount() == 1)
        {
            const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
            filename                                             = positional_arguments[0];
        }

        try
        {
            file_processor = arg_parser.IsOptionSet(kPreloadMeasurementRangeOption)
                                 ? std::make_unique<gfxrecon::decode::PreloadFileProcessor>()
                                 : std::make_unique<gfxrecon::decode::FileProcessor>();

            if (!file_processor->Initialize(filename))
            {
                GFXRECON_WRITE_CONSOLE("Failed to load file %s.", filename.c_str());
            }
            else
            {
                auto application = std::make_shared<gfxrecon::application::Application>(
                    kApplicationName, file_processor.get(), VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, app);

                gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
                gfxrecon::decode::VulkanReplayOptions          replay_options =
                    GetVulkanReplayOptions(arg_parser, filename, &tracked_object_info_table);

                gfxrecon::decode::VulkanReplayConsumer vulkan_replay_consumer(application, replay_options);
                gfxrecon::decode::VulkanDecoder        vulkan_decoder;

                if (replay_options.capture)
                {
                    gfxrecon::vulkan_recapture::RecaptureVulkanEntry::InitSingleton();

                    // Set replay to use the GetInstanceProcAddr function from RecaptureVulkanEntry so that replay first
                    // calls into the capture layer instead of directly into the loader and Vulkan runtime.
                    // Also sets the capture manager's instance and device creation callbacks.
                    vulkan_replay_consumer.SetupForRecapture(gfxrecon::vulkan_recapture::GetInstanceProcAddr,
                                                             gfxrecon::vulkan_recapture::dispatch_CreateInstance,
                                                             gfxrecon::vulkan_recapture::dispatch_CreateDevice);
                }

                ApiReplayOptions  api_replay_options;
                ApiReplayConsumer api_replay_consumer;
                api_replay_options.vk_replay_options   = &replay_options;
                api_replay_consumer.vk_replay_consumer = &vulkan_replay_consumer;

                if (IsRunPreProcessConsumer(api_replay_options))
                {
                    RunPreProcessConsumer(filename, api_replay_options, api_replay_consumer);
                }

                uint32_t measurement_start_frame;
                uint32_t measurement_end_frame;
                bool     has_mfr = GetMeasurementFrameRange(arg_parser, measurement_start_frame, measurement_end_frame);

                std::string measurement_file_name;
                GetMeasurementFilename(arg_parser, measurement_file_name);

                bool     quit_after_frame = false;
                uint32_t quit_frame;

                if (replay_options.quit_after_frame)
                {
                    quit_after_frame = true;
                    GetQuitAfterFrame(arg_parser, quit_frame);
                }

                gfxrecon::graphics::FpsInfo fps_info(static_cast<uint64_t>(measurement_start_frame),
                                                     static_cast<uint64_t>(measurement_end_frame),
                                                     has_mfr,
                                                     replay_options.quit_after_measurement_frame_range,
                                                     replay_options.flush_measurement_frame_range,
                                                     replay_options.flush_inside_measurement_range,
                                                     replay_options.preload_measurement_range,
                                                     measurement_file_name,
                                                     quit_after_frame,
                                                     quit_frame);

                vulkan_replay_consumer.SetFatalErrorHandler(
                    [](const char* message) { throw std::runtime_error(message); });

                vulkan_decoder.AddConsumer(&vulkan_replay_consumer);

                file_processor->AddDecoder(&vulkan_decoder);

                file_processor->SetPrintBlockInfoFlag(replay_options.enable_print_block_info,
                                                      replay_options.block_index_from,
                                                      replay_options.block_index_to);

                application->SetPauseFrame(GetPauseFrame(arg_parser));

#if ENABLE_OPENXR_SUPPORT
                gfxrecon::decode::OpenXrReplayOptions  openxr_replay_options = {};
                gfxrecon::decode::OpenXrDecoder        openxr_decoder;
                gfxrecon::decode::OpenXrReplayConsumer openxr_replay_consumer(application, openxr_replay_options);
                openxr_replay_consumer.SetVulkanReplayConsumer(&vulkan_replay_consumer);
                openxr_replay_consumer.SetAndroidApp(app);
                openxr_decoder.AddConsumer(&openxr_replay_consumer);
                file_processor->AddDecoder(&openxr_decoder);
#endif

                // Warn if the capture layer is active.
                CheckActiveLayers(kLayerProperty);

                // Start the application in the paused state, preventing replay from starting before the app
                // gained focus event is received.
                application->SetPaused(true);

                app->userData = application.get();
                application->SetFpsInfo(&fps_info);

                fps_info.BeginFile();

                application->Run();

                // Add one so that it matches the trim range frame number semantic
                fps_info.EndFile(file_processor->GetCurrentFrameNumber() + 1);

                if ((file_processor->GetCurrentFrameNumber() > 0) &&
                    (file_processor->GetErrorState() == gfxrecon::decode::FileProcessor::kErrorNone))
                {
                    if (file_processor->GetCurrentFrameNumber() < measurement_start_frame)
                    {
                        GFXRECON_LOG_WARNING(
                            "Measurement range start frame (%u) is greater than the last replayed frame (%u). "
                            "Measurements were never started, cannot calculate measurement range FPS.",
                            measurement_start_frame,
                            file_processor->GetCurrentFrameNumber());
                    }
                    else
                    {
                        fps_info.LogMeasurements();
                    }
                }
                else if (file_processor->GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
                {
                    GFXRECON_WRITE_CONSOLE("A failure has occurred during replay");
                }
                else
                {
                    GFXRECON_WRITE_CONSOLE("File did not contain any frames");
                }

                if (replay_options.capture)
                {
                    gfxrecon::vulkan_recapture::RecaptureVulkanEntry::DestroySingleton();
                }
            }
        }
        catch (std::runtime_error& error)
        {
            GFXRECON_WRITE_CONSOLE("Replay failed with error message: %s", error.what());
        }
        catch (const std::exception& error)
        {
            GFXRECON_WRITE_CONSOLE("Replay has encountered a fatal error and cannot continue: %s", error.what());
        }
        catch (...)
        {
            GFXRECON_WRITE_CONSOLE("Replay failed due to an unhandled exception");
        }

        // Ensure user data is cleared after either a successful run or an exception.
        app->userData = nullptr;
    }

    gfxrecon::util::Log::Release();

    gfxrecon::util::DestroyActivity(app);
    raise(SIGTERM);
}

void ProcessAppCmd(struct android_app* app, int32_t cmd)
{
    if (app->userData != nullptr)
    {
        using namespace gfxrecon::application;
        auto application = reinterpret_cast<Application*>(app->userData);
        assert(application);

        switch (cmd)
        {
            case APP_CMD_INIT_WINDOW:
            {
                auto android_context = reinterpret_cast<AndroidContext*>(
                    application->GetWsiContext(VK_KHR_ANDROID_SURFACE_EXTENSION_NAME));
                assert(android_context);
                android_context->InitWindow();
                break;
            }
            case APP_CMD_GAINED_FOCUS:
            {
                GFXRECON_LOG_INFO("Application gained focus.")
                application->SetPaused(false);
                break;
            }
            case APP_CMD_LOST_FOCUS:
            {
                GFXRECON_LOG_INFO("Application lost focus.")
                application->SetPaused(true);
                break;
            }
        }
    }
}

int32_t ProcessInputEvent(struct android_app* app, AInputEvent* event)
{
    if (app->userData != nullptr)
    {
        int32_t type = AInputEvent_getType(event);

        if (type == AINPUT_EVENT_TYPE_MOTION)
        {
            static int32_t start_pointer_id = 0;
            static int32_t start_x          = 0;
            static int32_t start_y          = 0;

            int32_t action = AMotionEvent_getAction(event);

            if (action == AMOTION_EVENT_ACTION_UP)
            {
                auto application = reinterpret_cast<gfxrecon::application::Application*>(app->userData);
                assert(application);
                int32_t horizontal_distance = 0;
                int32_t vertical_distance   = 0;

                if (start_pointer_id == AMotionEvent_getPointerId(event, 0))
                {
                    horizontal_distance = AMotionEvent_getX(event, 0) - start_x;
                    vertical_distance   = AMotionEvent_getY(event, 0) - start_y;
                }

                if (abs(horizontal_distance) > kSwipeDistance)
                {
                    if ((horizontal_distance < 0) && (abs(horizontal_distance) > abs(vertical_distance)) &&
                        application->GetPaused())
                    {
                        // Treat as swipe right-to-left to advance frame while paused.
                        application->PlaySingleFrame();
                    }
                }
                else if (abs(vertical_distance) > kSwipeDistance)
                {
                    // Ignore vertical swipe.
                }
                else
                {
                    // Treat as a tap to toggle pause state.
                    application->SetPaused(!application->GetPaused());
                }

                return 1;
            }
            else if (action == AMOTION_EVENT_ACTION_DOWN)
            {
                start_pointer_id = AMotionEvent_getPointerId(event, 0);
                start_x          = AMotionEvent_getX(event, 0);
                start_y          = AMotionEvent_getY(event, 0);
                return 1;
            }
        }
        else if (type == AINPUT_EVENT_TYPE_KEY)
        {
            int32_t key    = AKeyEvent_getKeyCode(event);
            int32_t action = AKeyEvent_getAction(event);

            // Key input can be simulated with 'adb shell input keyevent <keycode>'. Relevant keycodes are:
            //  Space = 62
            //  P     = 44
            //  Right = 22
            //  N     = 42
            if (action == AKEY_EVENT_ACTION_UP)
            {
                auto application = reinterpret_cast<gfxrecon::application::Application*>(app->userData);
                assert(application);
                switch (key)
                {
                    case AKEYCODE_SPACE:
                    case AKEYCODE_P:
                        application->SetPaused(!application->GetPaused());
                        break;
                    default:
                        break;
                }
            }
            else if (action == AKEY_EVENT_ACTION_DOWN)
            {
                auto application = reinterpret_cast<gfxrecon::application::Application*>(app->userData);
                assert(application);
                switch (key)
                {
                    case AKEYCODE_DPAD_RIGHT:
                    case AKEYCODE_N:
                        if (application->GetPaused())
                        {
                            application->PlaySingleFrame();
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return 0;
}
