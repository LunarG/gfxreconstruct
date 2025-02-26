/*
** Copyright (c) 2025 LunarG, Inc.
** Copyright (c) 2025 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#ifdef GFXR_MULTI_WINDOW_REPLAY

#include <jni.h>
#include <android/log.h>
#include "application/android_window.h"
#include <android/native_window_jni.h>
#include "util/logging.h"

extern "C" JNIEXPORT void JNICALL Java_com_lunarg_gfxreconstruct_replay_ReplayActivity_setSurface(JNIEnv* env,
                                                                                                  jobject obj,
                                                                                                  jobject surface)
{
    gfxrecon::application::tmp_window = ANativeWindow_fromSurface(env, surface);
    GFXRECON_LOG_INFO("Created new window %p from surface %p", gfxrecon::application::tmp_window, surface);
}

#endif // GFXR_MULTI_WINDOW_REPLAY