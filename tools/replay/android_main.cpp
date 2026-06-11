/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
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
#include "replay_main_common.h"

#include "application/android_context.h"
#include "application/android_window.h"
#include "decode/file_processor.h"
#include "format/format.h"
#include "util/android/activity.h"
#include "util/android/intent.h"
#include "util/logging.h"
#include "util/platform.h"
#include "parse_dump_resources_cli.h"

#include <android/log.h>
#include <android/window.h>

#include <cstdlib>
#include <exception>
#include <memory>
#include <string>
#include <vector>

const char kArgsExtentKey[]      = "args";
const char kDefaultCaptureFile[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;
const char kLayerProperty[]      = "debug.vulkan.layers";

const int32_t kSwipeDistance = 200;

void    ProcessAppCmd(struct android_app* app, int32_t cmd);
int32_t ProcessInputEvent(struct android_app* app, AInputEvent* event);

// Globals required by the extern "C" query callbacks called from outside this TU.
static std::unique_ptr<gfxrecon::decode::FileProcessor>                  g_file_processor;
static std::vector<std::unique_ptr<gfxrecon::replay::ReplayFeatureBase>> g_features;

extern "C"
{
    uint64_t MainGetCurrentBlockIndex()
    {
        return g_file_processor ? g_file_processor->GetCurrentBlockIndex() : 0;
    }

    bool MainGetLoadingTrimmedState()
    {
        return g_file_processor ? g_file_processor->GetLoadingTrimmedState() : false;
    }
}

void android_main(struct android_app* app)
{
    gfxrecon::util::Log::Init();
    GFXRECON_WRITE_CONSOLE("====== Entering android_main");

    // Keep screen on while window is active.
    ANativeActivity_setWindowFlags(app->activity, AWINDOW_FLAG_KEEP_SCREEN_ON, 0);

    gfxrecon::replay::LoadFeatures(g_features);

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
        gfxrecon::util::Log::Settings log_settings;
        GetLogSettings(arg_parser, log_settings);
        gfxrecon::util::Log::UpdateWithSettings(log_settings);

        std::string filename = kDefaultCaptureFile;
        if (arg_parser.GetPositionalArgumentsCount() == 1)
        {
            filename = arg_parser.GetPositionalArguments()[0];
        }

        try
        {
            auto make_application = [&](gfxrecon::decode::FileProcessor* fp) {
                return std::make_shared<gfxrecon::application::Application>(
                    kApplicationName, fp, VK_KHR_ANDROID_SURFACE_EXTENSION_NAME, app);
            };

            gfxrecon::replay::RunReplay(
                g_file_processor, g_features, arg_parser, filename, kLayerProperty, make_application);
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

    GFXRECON_WRITE_CONSOLE("====== Exiting android_main");

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
