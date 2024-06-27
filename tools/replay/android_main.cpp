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

#include "application/android_context.h"
#include "application/android_window.h"
#include "decode/file_processor.h"
#include "decode/preload_file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "format/format.h"

#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"
#include "parse_dump_resources_cli.h"

#include <android_native_app_glue.h>
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

std::string GetIntentExtra(struct android_app* app, const char* key);
void        ProcessAppCmd(struct android_app* app, int32_t cmd);
int32_t     ProcessInputEvent(struct android_app* app, AInputEvent* event);
void        DestroyActivity(struct android_app* app);

void android_main(struct android_app* app)
{
    gfxrecon::util::Log::Init();

    // Keep screen on while window is active.
    ANativeActivity_setWindowFlags(app->activity, AWINDOW_FLAG_KEEP_SCREEN_ON, 0);

    std::string                    args = GetIntentExtra(app, kArgsExtentKey);
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
            std::unique_ptr<gfxrecon::decode::FileProcessor> file_processor =
                arg_parser.IsOptionSet(kPreloadMeasurementRangeOption)
                    ? std::make_unique<gfxrecon::decode::PreloadFileProcessor>()
                    : std::make_unique<gfxrecon::decode::FileProcessor>();

            if (!file_processor->Initialize(filename))
            {
                GFXRECON_WRITE_CONSOLE("Failed to load file %s.", filename.c_str());
            }
            else
            {
                auto application =
                    std::make_shared<gfxrecon::application::Application>(kApplicationName, file_processor.get());
                application->InitializeWsiContext(VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, app);

                gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
                gfxrecon::decode::VulkanReplayOptions          replay_options =
                    GetVulkanReplayOptions(arg_parser, filename, &tracked_object_info_table);

                // Process --dump-resources arg. We do it here so that other gfxr tools that use
                // the VulkanReplayOptions class won't have to link in the json library.
                if (!gfxrecon::parse_dump_resources::parse_dump_resources_arg(replay_options))
                {
                    GFXRECON_LOG_FATAL("There was an error while parsing dump resource indices. Terminating");
                    return;
                }

                gfxrecon::decode::VulkanReplayConsumer replay_consumer(application, replay_options);
                gfxrecon::decode::VulkanDecoder        decoder;
                uint32_t                               start_frame, end_frame;
                bool        has_mfr = GetMeasurementFrameRange(arg_parser, start_frame, end_frame);
                std::string measurement_file_name;

                if (has_mfr)
                {
                    GetMeasurementFilename(arg_parser, measurement_file_name);
                }

                gfxrecon::graphics::FpsInfo fps_info(static_cast<uint64_t>(start_frame),
                                                     static_cast<uint64_t>(end_frame),
                                                     has_mfr,
                                                     replay_options.quit_after_measurement_frame_range,
                                                     replay_options.flush_measurement_frame_range,
                                                     replay_options.flush_inside_measurement_range,
                                                     replay_options.preload_measurement_range,
                                                     measurement_file_name);

                replay_consumer.SetFatalErrorHandler([](const char* message) { throw std::runtime_error(message); });
                replay_consumer.SetFpsInfo(&fps_info);

                decoder.AddConsumer(&replay_consumer);
                file_processor->AddDecoder(&decoder);
                application->SetPauseFrame(GetPauseFrame(arg_parser));

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
                        fps_info.LogToConsole();
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
            }
        }
        catch (std::runtime_error error)
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

    DestroyActivity(app);
    raise(SIGTERM);
}

// Retrieve the program argument string from the intent extras
std::string GetIntentExtra(struct android_app* app, const char* key)
{
    std::string value;
    JavaVM*     jni_vm       = nullptr;
    jobject     jni_activity = nullptr;
    JNIEnv*     env          = nullptr;

    if ((app != nullptr) && (app->activity != nullptr))
    {
        jni_vm       = app->activity->vm;
        jni_activity = app->activity->clazz;
    }

    if ((jni_vm != nullptr) && (jni_activity != 0) && (jni_vm->AttachCurrentThread(&env, nullptr) == JNI_OK))
    {
        jclass    activity_class = env->GetObjectClass(jni_activity);
        jmethodID get_intent     = env->GetMethodID(activity_class, "getIntent", "()Landroid/content/Intent;");
        jobject   intent         = env->CallObjectMethod(jni_activity, get_intent);

        if (intent)
        {
            jclass    intent_class = env->GetObjectClass(intent);
            jmethodID get_string_extra =
                env->GetMethodID(intent_class, "getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;");

            jvalue extra_key;
            extra_key.l = env->NewStringUTF(key);

            jstring extra = static_cast<jstring>(env->CallObjectMethodA(intent, get_string_extra, &extra_key));

            if (extra)
            {
                const char* utf_chars = env->GetStringUTFChars(extra, nullptr);

                value = utf_chars;

                env->ReleaseStringUTFChars(extra, utf_chars);
                env->DeleteLocalRef(extra);
            }

            env->DeleteLocalRef(extra_key.l);
            env->DeleteLocalRef(intent);
        }

        jni_vm->DetachCurrentThread();
    }

    return value;
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
                application->SetPaused(false);
                break;
            }
            case APP_CMD_LOST_FOCUS:
            {
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

void DestroyActivity(struct android_app* app)
{
    ANativeActivity_finish(app->activity);

    // Wait for APP_CMD_DESTROY
    while (app->destroyRequested == 0)
    {
        struct android_poll_source* source = nullptr;
        int                         events = 0;
        int                         result = ALooper_pollAll(-1, nullptr, &events, reinterpret_cast<void**>(&source));

        if ((result >= 0) && (source))
        {
            source->process(app, source);
        }
        else
        {
            break;
        }
    }
}
