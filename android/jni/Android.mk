MY_LOCAL_PATH := $(call my-dir)
LOCAL_PATH := $(MY_LOCAL_PATH)

include $(CLEAR_VARS)
LOCAL_MODULE := platform_specific
LOCAL_EXPORT_CFLAGS := -D_FILE_OFFSET_BITS=64 -DPAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION -DVK_USE_PLATFORM_ANDROID_KHR -fexceptions -std=c++17 -Wno-nullability-completeness
LOCAL_EXPORT_CPPFLAGS := -D_FILE_OFFSET_BITS=64 -DPAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION -DVK_USE_PLATFORM_ANDROID_KHR -fexceptions -std=c++17 -Wno-nullability-completeness
LOCAL_EXPORT_LDFLAGS := -u ANativeActivity_onCreate
include $(BUILD_STATIC_LIBRARY)

LOCAL_PATH := $(MY_LOCAL_PATH)

include $(CLEAR_VARS)
LOCAL_MODULE := vulkan_registry
LOCAL_EXPORT_CFLAGS := -DVK_NO_PROTOTYPES -DVK_ENABLE_BETA_EXTENSIONS
LOCAL_EXPORT_C_INCLUDES := ${GFXRECON_INCLUDE_DIR}/external/Vulkan-Headers/include
include $(BUILD_STATIC_LIBRARY)

LOCAL_PATH := $(MY_LOCAL_PATH)

include $(CLEAR_VARS)
LOCAL_MODULE := vulkan_memory_allocator
LOCAL_EXPORT_C_INCLUDES := ${GFXRECON_INCLUDE_DIR}/external/VulkanMemoryAllocator/include
include $(BUILD_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := native_app_glue
LOCAL_SRC_FILES := ${ANDROID_NDK_HOME}/sources/android/native_app_glue/android_native_app_glue.c
LOCAL_EXPORT_C_INCLUDES := ${ANDROID_NDK_HOME}/sources/android/native_app_glue/
include $(BUILD_STATIC_LIBRARY)

LOCAL_PATH := $(MY_LOCAL_PATH)

include $(LOCAL_PATH)/framework/decode/Android.mk
include $(LOCAL_PATH)/framework/application/Android.mk
include $(LOCAL_PATH)/framework/util/Android.mk
include $(LOCAL_PATH)/framework/format/Android.mk
include $(LOCAL_PATH)/framework/graphics/Android.mk
include $(LOCAL_PATH)/framework/encode/Android.mk

LOCAL_PATH := $(MY_LOCAL_PATH)

# Build libVkLayer_gfxreconstruct.so
include $(CLEAR_VARS)
LOCAL_MODULE := VkLayer_gfxreconstruct

LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/layer/dll_main.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/layer/trace_layer.cpp

LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/
LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework

LOCAL_STATIC_LIBRARIES += gfxrecon_encode gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry platform_specific
LOCAL_LDLIBS += -landroid -llog -lz

include $(BUILD_SHARED_LIBRARY)

# Build libgfxrecon-replay.so
include $(CLEAR_VARS)
LOCAL_MODULE := libgfxrecon-replay

LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/tools/replay/android_main.cpp

LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/
LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework

LOCAL_STATIC_LIBRARIES += gfxrecon_decode gfxrecon_application gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry platform_specific vulkan_memory_allocator native_app_glue
LOCAL_LDLIBS += -landroid -llog -lz

include $(BUILD_SHARED_LIBRARY)
