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

#include "application/android_application.h"
#include "application/android_window.h"
#include "decode/file_processor.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "format/format.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"

#include <android_native_app_glue.h>

#include <cstdlib>
#include <exception>
#include <memory>
#include <string>
#include <vector>

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
        std::string filename = kDefaultCaptureFile;

        if (arg_parser.GetPositionalArgumentsCount() == 1)
        {
            const std::vector<std::string>& positional_arguments = arg_parser.GetPositionalArguments();
            filename                                             = positional_arguments[0];
        }

        try
        {
            gfxrecon::decode::FileProcessor                            file_processor;
            std::unique_ptr<gfxrecon::application::AndroidApplication> application;
            std::unique_ptr<gfxrecon::decode::WindowFactory>           window_factory;

            if (!file_processor.Initialize(filename))
            {
                GFXRECON_WRITE_CONSOLE("Failed to load file %s.", filename.c_str());
            }
            else
            {
                // Setup platform specific application and window factory.
                application    = std::make_unique<gfxrecon::application::AndroidApplication>(kApplicationName, app);
                window_factory = std::make_unique<gfxrecon::application::AndroidWindowFactory>(application.get());

                if (!application->Initialize(&file_processor))
                {
                    GFXRECON_WRITE_CONSOLE(
                        "Failed to initialize platform specific window system management.\nEnsure that the appropriate "
                        "Vulkan platform extensions have been enabled.");
                }
                else
                {
                    gfxrecon::decode::VulkanTrackedObjectInfoTable tracked_object_info_table;
                    gfxrecon::decode::VulkanReplayConsumer         replay_consumer(
                        window_factory.get(), GetReplayOptions(arg_parser, filename, &tracked_object_info_table));
                    gfxrecon::decode::VulkanDecoder        decoder;

                    replay_consumer.SetFatalErrorHandler(
                        [](const char* message) { throw std::runtime_error(message); });

                    decoder.AddConsumer(&replay_consumer);
                    file_processor.AddDecoder(&decoder);
                    application->SetPauseFrame(GetPauseFrame(arg_parser));

                    // Warn if the capture layer is active.
                    CheckActiveLayers(kLayerProperty);

                    // Start the application in the paused state, preventing replay from starting before the app
                    // gained focus event is received.
                    application->SetPaused(true);

                    app->userData = application.get();
                    application->Run();
                }
            }
        }
        catch (std::runtime_error error)
        {
            GFXRECON_WRITE_CONSOLE("Replay failed with error message: %s", error.what());
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
        gfxrecon::application::AndroidApplication* android_application =
            reinterpret_cast<gfxrecon::application::AndroidApplication*>(app->userData);

        switch (cmd)
        {
            case APP_CMD_INIT_WINDOW:
            {
                android_application->InitWindow();
                break;
            }
            case APP_CMD_GAINED_FOCUS:
            {
                android_application->SetPaused(false);
                break;
            }
            case APP_CMD_LOST_FOCUS:
            {
                android_application->SetPaused(true);
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
                auto android_application = reinterpret_cast<gfxrecon::application::AndroidApplication*>(app->userData);
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
                        android_application->GetPaused())
                    {
                        // Treat as swipe right-to-left to advance frame while paused.
                        android_application->PlaySingleFrame();
                    }
                }
                else if (abs(vertical_distance) > kSwipeDistance)
                {
                    // Ignore vertical swipe.
                }
                else
                {
                    // Treat as a tap to toggle pause state.
                    android_application->SetPaused(!android_application->GetPaused());
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
                auto android_application = reinterpret_cast<gfxrecon::application::AndroidApplication*>(app->userData);
                switch (key)
                {
                    case AKEYCODE_SPACE:
                    case AKEYCODE_P:
                        android_application->SetPaused(!android_application->GetPaused());
                        break;
                    default:
                        break;
                }
            }
            else if (action == AKEY_EVENT_ACTION_DOWN)
            {
                auto android_application = reinterpret_cast<gfxrecon::application::AndroidApplication*>(app->userData);
                switch (key)
                {
                    case AKEYCODE_DPAD_RIGHT:
                    case AKEYCODE_N:
                        if (android_application->GetPaused())
                        {
                            android_application->PlaySingleFrame();
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
