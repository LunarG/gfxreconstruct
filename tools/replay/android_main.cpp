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

#include "application/android_application.h"
#include "application/android_window.h"
#include "decode/file_processor.h"
#include "format/format.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"
#include "util/argument_parser.h"
#include "util/logging.h"
#include "util/platform.h"

#include <android_native_app_glue.h>

#include <exception>
#include <memory>
#include <string>
#include <vector>

const char kApplicationName[]    = "GFXReconstruct Replay";
const char kArgsExtentKey[]      = "args";
const char kDefaultCaptureFile[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;
const char kLayerProperty[]      = "debug.vulkan.layers";
const char kCaptureLayer[]       = "VK_LAYER_LUNARG_gfxreconstruct";

std::string GetIntentExtra(struct android_app* app, const char* key);
void        ProcessAppCmd(struct android_app* app, int32_t cmd);
int32_t     ProcessInputEvent(struct android_app* app, AInputEvent* event);
void        CheckActiveLayers();
void        DestroyActivity(struct android_app* app);
void        PrintUsage(const char* exe_name);

void android_main(struct android_app* app)
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kInfoSeverity);

    std::string                    args = GetIntentExtra(app, kArgsExtentKey);
    gfxrecon::util::ArgumentParser arg_parser(false, args.c_str(), "", "", 0);

    app->onAppCmd     = ProcessAppCmd;
    app->onInputEvent = ProcessInputEvent;

    if (arg_parser.IsInvalid() || (arg_parser.GetPositionalArgumentsCount() > 1))
    {
        PrintUsage(kApplicationName);
    }
    else
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
                    gfxrecon::decode::VulkanDecoder        decoder;
                    gfxrecon::decode::VulkanReplayConsumer replay_consumer(window_factory.get());

                    replay_consumer.SetFatalErrorHandler(
                        [](const char* message) { throw std::runtime_error(message); });

                    decoder.AddConsumer(&replay_consumer);
                    file_processor.AddDecoder(&decoder);

                    // Warn if the capture layer is active.
                    CheckActiveLayers();

                    // Start the application in the paused state, preventing replay from starting before the app gained
                    // focus event is received.
                    application->SetPaused(true);

                    app->userData = application.get();
                    application->Run();
                    app->userData = nullptr;
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
    if ((app->userData != nullptr) && (AInputEvent_getType(event) == AINPUT_EVENT_TYPE_MOTION))
    {
        gfxrecon::application::AndroidApplication* android_application =
            reinterpret_cast<gfxrecon::application::AndroidApplication*>(app->userData);

        // TODO: Distinguish between tap and swipe actions; swipe to advance to next frame when paused.
        int32_t action = AMotionEvent_getAction(event);
        if (action == AMOTION_EVENT_ACTION_UP)
        {
            android_application->SetPaused(!android_application->GetPaused());
            return 1;
        }
    }

    return 0;
}

void CheckActiveLayers()
{
    std::string result = gfxrecon::util::platform::GetEnv(kLayerProperty);

    if (!result.empty())
    {
        if (result.find(kCaptureLayer) != std::string::npos)
        {
            GFXRECON_LOG_WARNING("Replay tool has detected that the capture layer is enabled");
        }
    }
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

void PrintUsage(const char* exe_name)
{
    std::string app_name     = exe_name;
    size_t      dir_location = app_name.find_last_of("/\\");

    if (dir_location >= 0)
    {
        app_name.replace(0, dir_location + 1, "");
    }

    GFXRECON_WRITE_CONSOLE("\n%s\tis a replay tool designed to playback GFXReconstruct capture files.\n",
                           app_name.c_str());
    GFXRECON_WRITE_CONSOLE("Usage:");
    GFXRECON_WRITE_CONSOLE("\t%s <file>\n", app_name.c_str());
    GFXRECON_WRITE_CONSOLE("\t<file>\t\tThe filename (including path if necessary) of the ");
    GFXRECON_WRITE_CONSOLE("\t\t\t\tcapture file to replay");
}
