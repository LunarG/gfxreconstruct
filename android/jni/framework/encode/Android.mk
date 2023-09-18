include $(CLEAR_VARS)
LOCAL_MODULE := gfxrecon_encode

LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/capture_manager.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/capture_settings.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_api_call_encoders.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_command_buffer_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_handle_wrappers.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_capture_manager.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_handle_wrapper_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_tracker.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/encode/vulkan_state_writer.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.cpp

LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/
LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework

LOCAL_STATIC_LIBRARIES += gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry platform_specific

include $(BUILD_STATIC_LIBRARY)
