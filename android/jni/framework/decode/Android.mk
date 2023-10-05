include $(CLEAR_VARS)
LOCAL_MODULE := gfxrecon_decode

LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_handle_mappers.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/decode_allocator.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/descriptor_update_template_decoder.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/file_processor.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/file_transformer.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/portability.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/referenced_resource_table.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/resource_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/screenshot_handler.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/screenshot_handler_base.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_decoder_base.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_default_allocator.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_captured_swapchain.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_feature_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_handle_mapping_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_object_cleanup_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_realign_allocator.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_rebind_allocator.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_referenced_resource_consumer_base.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_remap_allocator.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_consumer_base.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_resource_initializer.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_resource_tracking_consumer.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_swapchain.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_offscreen_swapchain.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_tracked_object_info.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_tracked_object_info_table.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_virtual_swapchain.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_feature_util.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_referenced_resource_consumer.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.cpp
LOCAL_SRC_FILES += ${GFXRECON_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp

LOCAL_C_INCLUDES += ${GFXRECON_INCLUDE_DIR}/framework

LOCAL_STATIC_LIBRARIES += gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry vulkan_memory_allocator platform_specific
LOCAL_CFLAGS := -DGFXRECON_ENABLE_PNG_SCREENSHOT

include $(BUILD_STATIC_LIBRARY)
