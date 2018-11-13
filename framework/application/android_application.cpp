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

#include <jni.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

AndroidApplication::AndroidApplication(const std::string& name, struct android_app* app) :
    Application(name), window_(nullptr), android_app_(app)
{
    assert(app != nullptr);
}

bool AndroidApplication::Initialize(decode::FileProcessor* file_processor)
{

    SetFileProcessor(file_processor);

    return true;
}

void AndroidApplication::ProcessEvents(bool wait_for_input)
{
    // Process all pending events.
    for (;;)
    {
        int                         result = 0;
        int                         events = 0;
        struct android_poll_source* source = nullptr;

        if (wait_for_input)
        {
            result         = ALooper_pollAll(-1, nullptr, &events, reinterpret_cast<void**>(&source));
            wait_for_input = false;
        }
        else
        {
            result = ALooper_pollAll(0, nullptr, &events, reinterpret_cast<void**>(&source));
        }

        if (result >= 0)
        {
            if (source)
            {
                source->process(android_app_, source);
            }

            if (android_app_->destroyRequested != 0)
            {
                StopRunning();
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void AndroidApplication::InitWindow()
{
    window_ = std::make_unique<AndroidWindow>(this, android_app_->window);
}

void AndroidApplication::SetOrientation(ScreenOrientation orientation)
{
    JavaVM* jni_vm       = nullptr;
    jobject jni_activity = nullptr;
    JNIEnv* env          = nullptr;

    if ((android_app_ != nullptr) && (android_app_->activity != nullptr))
    {
        jni_vm       = android_app_->activity->vm;
        jni_activity = android_app_->activity->clazz;
    }

    if ((jni_vm != nullptr) && (jni_activity != 0) && (jni_vm->AttachCurrentThread(&env, nullptr) == JNI_OK))
    {
        jclass    object_class    = env->GetObjectClass(jni_activity);
        jmethodID set_orientation = env->GetMethodID(object_class, "setRequestedOrientation", "(I)V");

        env->CallVoidMethod(jni_activity, set_orientation, orientation);

        jni_vm->DetachCurrentThread();
    }
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
