add_library(gfxrecon_decode STATIC "")

target_sources(gfxrecon_decode
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/decode/annotation_handler.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/api_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/common_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/common_handle_mapping_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/common_object_info_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/common_struct_handle_mappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/common_object_info_table.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/copy_shaders.h
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/custom_openxr_struct_decoders.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/custom_openxr_struct_decoders.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/custom_openxr_struct_decoders_forward.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/custom_openxr_struct_handle_mappers.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/custom_openxr_struct_handle_mappers.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/custom_openxr_struct_to_json.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/custom_openxr_struct_to_json.cpp>
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders_forward.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_handle_mappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_handle_mappers.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/decode_allocator.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/decode_allocator.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/descriptor_update_template_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/descriptor_update_template_decoder.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/file_processor.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/file_processor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/preload_file_processor.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/preload_file_processor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/file_transformer.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/file_transformer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/handle_pointer_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/json_writer.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/json_writer.cpp
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_consumer_base.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_decoder_base.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_decoder_base.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_detection_consumer.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_enum_util.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_feature_util.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_feature_util.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_handle_mapping_util.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_handle_mapping_util.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_json_consumer_base.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_json_consumer_base.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_next_node.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_next_typed_node.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_object_info.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_object_info_table_base.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_common_state.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_session_state.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_session_state.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_swapchain_state.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_swapchain_state.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_consumer_base.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_consumer_base.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_replay_options.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_resource_tracking_consumer.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_resource_tracking_consumer.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_stats_consumer.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_tracked_object_info.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_tracked_object_info_table.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_tracked_object_info.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/decode/openxr_tracked_object_info_table.cpp>
                   ${GFXRECON_SOURCE_DIR}/framework/decode/mark_injected_commands.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/mark_injected_commands.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/pointer_decoder_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/pointer_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/portability.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/portability.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/referenced_resource_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/referenced_resource_table.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/replay_options.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/resource_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/resource_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/screenshot_handler.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/screenshot_handler.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/screenshot_handler_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/screenshot_handler_base.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/string_array_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/string_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/struct_pointer_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/swapchain_image_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/value_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/metadata_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/marker_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_decoder_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_decoder_base.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_default_allocator.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_default_allocator.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_address_replacer.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_address_replacer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_address_replacer_shaders.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_device_address_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_device_address_tracker.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_captured_swapchain.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_captured_swapchain.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_enum_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_handle_mapping_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_handle_mapping_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_object_cleanup_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_object_cleanup_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_object_info.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_object_info_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_object_info_table_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_pnext_node.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_pnext_typed_node.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_realign_allocator.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_realign_allocator.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_rebind_allocator.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_rebind_allocator.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_referenced_resource_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_referenced_resource_consumer_base.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_remap_allocator.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_remap_allocator.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_consumer_base.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_options.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_pre_process_consumer.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_common.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_common.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_draw_calls.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_draw_calls.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_compute_ray_tracing.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_compute_ray_tracing.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_delegate.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_delegate.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_json.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_dump_resources_json.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_resource_allocator.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_resource_initializer.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_resource_initializer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_resource_tracking_consumer.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_resource_tracking_consumer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_swapchain.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_swapchain.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_tracked_object_info.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_tracked_object_info_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_tracked_object_info.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_tracked_object_info_table.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_virtual_swapchain.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_virtual_swapchain.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_offscreen_swapchain.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_offscreen_swapchain.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/window.h
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_consumer.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_decoder.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_decoder.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_enum_to_json.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_enum_to_json.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_json_consumer.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_json_consumer.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_object_info_table.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_replay_consumer.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_replay_consumer.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_decoders.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_decoders.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_decoders_forward.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_handle_mappers.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_handle_mappers.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_next_decoder.cpp>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_to_json.h>
                   $<$<BOOL:${OPENXR_SUPPORT_ENABLED}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_struct_to_json.cpp>
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_consumer.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_pnext_struct_decoder.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_replay_dump_resources.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_replay_dump_resources.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders_forward.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_object_info_table_base2.h
              )

if (OPENXR_SUPPORT_ENABLED)
    target_include_directories(gfxrecon_decode PUBLIC ${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK/include)
    target_compile_definitions(gfxrecon_decode PUBLIC ENABLE_OPENXR_SUPPORT=1)
endif()

target_include_directories(gfxrecon_decode
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${GFXRECON_SOURCE_DIR}/framework
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include)

target_link_libraries(gfxrecon_decode
                      gfxrecon_graphics
                      gfxrecon_format
                      gfxrecon_util
                      vulkan_registry
                      vulkan_memory_allocator
                      platform_specific
                      spirv-reflect-static)
