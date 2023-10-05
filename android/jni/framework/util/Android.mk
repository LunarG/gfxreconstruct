include $(CLEAR_VARS)
LOCAL_MODULE    := lz4_static
LOCAL_SRC_FILES := ${GFXRECON_SOURCE_DIR}/external/precompiled/android/lib/${TARGET_ARCH_ABI}/liblz4_static.a
$(warning $(LOCAL_SRC_FILES))
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := gfxrecon_util

LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/argument_parser.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/date_time.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/file_output_stream.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/file_path.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/hash.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/image_writer.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/keyboard.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/logging.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/lz4_compressor.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/zlib_compressor.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/memory_output_stream.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/monotonic_allocator.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/settings_loader.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/strings.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/util/options.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_enum_to_string.cpp

LOCAL_CFLAGS += -DGFXRECON_ENABLE_LZ4_COMPRESSION -DGFXRECON_ENABLE_ZLIB_COMPRESSION -DGFXRECON_ENABLE_PNG_SCREENSHOT

LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/external/precompiled/android/include
LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/external/stb
LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework

LOCAL_STATIC_LIBRARIES += platform_specific vulkan_registry lz4_static

include $(BUILD_STATIC_LIBRARY)
