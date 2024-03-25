#ifndef __ANDROIDLOGGING_HPP__
#define __ANDROIDLOGGING_HPP__

#include <android/log.h>

// Android log function wrappers
static const char* kTAG = "GFXReconstruct-ToCpp";
#define LOGI(...) \
  ((void)__android_log_print(ANDROID_LOG_INFO, kTAG, __VA_ARGS__))
#define LOGW(...) \
  ((void)__android_log_print(ANDROID_LOG_WARN, kTAG, __VA_ARGS__))
#define LOGE(...) \
  ((void)__android_log_print(ANDROID_LOG_ERROR, kTAG, __VA_ARGS__))

#endif // __ANDROIDLOGGING_HPP__
