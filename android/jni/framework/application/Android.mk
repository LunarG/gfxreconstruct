include $(CLEAR_VARS)
LOCAL_MODULE := gfxrecon_application

LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/application/android_context.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/application/android_window.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/application/application.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/application/wsi_context.cpp

LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework
LOCAL_C_INCLUDES += ${ANDROID_NDK_HOME}/sources/android/native_app_glue/

LOCAL_STATIC_LIBRARIES += gfxrecon_decode gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry platform_specific

include $(BUILD_STATIC_LIBRARY)
