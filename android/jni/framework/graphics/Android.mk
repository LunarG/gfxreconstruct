include $(CLEAR_VARS)
LOCAL_MODULE := gfxrecon_graphics

LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/graphics/fps_info.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_device_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_util.cpp

LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework
LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework/graphics
LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/external/nlohmann/include

LOCAL_STATIC_LIBRARIES += platform_specific vulkan_registry gfxrecon_util

include $(BUILD_STATIC_LIBRARY)
