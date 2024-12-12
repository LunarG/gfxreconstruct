/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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

#include "application/android_context.h"
#include "application/application.h"
#include "application/android_window.h"

#include <jni.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(application)

AndroidContext::AndroidContext(Application* application, struct android_app* app) :
    WsiContext(application), android_app_(app)
{
    assert(android_app_);
    window_factory_ = std::make_unique<AndroidWindowFactory>(this);
}

AndroidContext::~AndroidContext() {}

void AndroidContext::ProcessEvents(bool wait_for_input)
{
    assert(application_);
    assert(android_app_);
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
                application_->StopRunning();
                break;
            }
        }
        else
        {
            break;
        }
    }
}

void AndroidContext::InitWindow()
{
    window_ = std::make_unique<AndroidWindow>(this, android_app_->window);
}

void AndroidContext::SetOrientation(ScreenOrientation orientation)
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

void AndroidContext::requestNativeWindow(int width, int height)
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
        jclass    object_class     = env->GetObjectClass(jni_activity);
        jmethodID createsufaceview = env->GetMethodID(object_class, "addNewView", "(II)V");
        env->CallVoidMethod(jni_activity, createsufaceview, width, height);
        jni_vm->DetachCurrentThread();
    }
}

void AndroidContext::destroyNativeWindow(int window_index)
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
        jclass    object_class      = env->GetObjectClass(jni_activity);
        jmethodID removesurfaceview = env->GetMethodID(object_class, "removeOneView", "(I)V");
        env->CallVoidMethod(jni_activity, removesurfaceview, window_index);
        jni_vm->DetachCurrentThread();
    }
}

GFXRECON_END_NAMESPACE(application)
GFXRECON_END_NAMESPACE(gfxrecon)
