/*
** Copyright (c) 2025 LunarG, Inc.
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

#include "util/android/intent.h"

#include <android_native_app_glue.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)

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

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
