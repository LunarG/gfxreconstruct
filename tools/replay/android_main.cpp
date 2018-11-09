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

#include <android_native_app_glue.h>

#include <exception>
#include <memory>
#include <string>
#include <vector>

const std::string kApplicationName = "GCAP Player";

void    ProcessAppCmd(struct android_app* app, int32_t cmd);
int32_t ProcessInputEvent(struct android_app* app, AInputEvent* event);
void    PrintUsage(const char* exe_name);

void android_main(struct android_app* app)
{
    int return_code = 0;

    brimstone::util::logging::Init();

    // TODO: Retrieve and process arg string from intent extras, and report invalid usage.
    // std::vector<const char*>        args;
    // brimstone::util::ArgumentParser arg_parser(args.size(), args.data(), "", "", 1);
    // const std::vector<std::string>  non_optional_arguments = arg_parser.GetNonOptionalArguments();
    // if (arg_parser.IsInvalid() || non_optional_arguments.size() != 1)
    //{
    //    PrintUsage(kApplicationName);
    //    return_code = -1;
    //}
    // else
    {
        // std::string filename = non_optional_arguments[0];
        std::string filename = "/sdcard/captures/brimstone_out" BRIMSTONE_FILE_EXTENSION;

        try
        {
            brimstone::decode::FileProcessor                            file_processor;
            std::unique_ptr<brimstone::application::AndroidApplication> application;
            std::unique_ptr<brimstone::decode::WindowFactory>           window_factory;

            if (!file_processor.Initialize(filename))
            {
                BRIMSTONE_WRITE_CONSOLE("Failed to load file %s.", filename.c_str());
                return_code = -1;
            }
            else
            {
                // Setup platform specific application and window factory.
                application    = std::make_unique<brimstone::application::AndroidApplication>(kApplicationName, app);
                window_factory = std::make_unique<brimstone::application::AndroidWindowFactory>(application.get());

                if (!application->Initialize(&file_processor))
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

                    // Start the application in the paused state, preventing replay from starting before the app gained
                    // focus event is received.
                    application->SetPaused(true);

                    app->userData     = application.get();
                    app->onAppCmd     = ProcessAppCmd;
                    app->onInputEvent = ProcessInputEvent;

                    application->Run();

                    app->userData = nullptr;
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

    ANativeActivity_finish(app->activity);
}

void ProcessAppCmd(struct android_app* app, int32_t cmd)
{
    if (app->userData != nullptr)
    {
        brimstone::application::AndroidApplication* android_application =
            reinterpret_cast<brimstone::application::AndroidApplication*>(app->userData);

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
        brimstone::application::AndroidApplication* android_application =
            reinterpret_cast<brimstone::application::AndroidApplication*>(app->userData);

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
