#include <jni.h>
#include <android/log.h>
#include "application/android_window.h"
#include <android/native_window_jni.h>

// Define a log tag for convenience
#define LOG_TAG "gfxrecon: ReplayActivity"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT void JNICALL Java_com_lunarg_gfxreconstruct_replay_ReplayActivity_setSurface(JNIEnv* env,
                                                                                                  jobject obj,
                                                                                                  jobject surface)
{
    gfxrecon::application::tmp_window = ANativeWindow_fromSurface(env, surface);
    LOGI("Created new window %p\n", gfxrecon::application::tmp_window);
}
