add_library(gfxrecon_decode STATIC "")

target_sources(gfxrecon_decode
               PRIVATE
                   api_decoder.h
                   copy_shaders.h
                   custom_vulkan_struct_decoders.h
                   custom_vulkan_struct_decoders.cpp
                   custom_vulkan_struct_decoders_forward.h
                   custom_vulkan_struct_handle_mappers.h
                   custom_vulkan_struct_handle_mappers.cpp
                   compression_converter.h
                   compression_converter.cpp
                   descriptor_update_template_decoder.h
                   descriptor_update_template_decoder.cpp
                   file_processor.h
                   file_processor.cpp
                   handle_pointer_decoder.h
                   pnext_node.h
                   pnext_typed_node.h
                   pointer_decoder_base.h
                   pointer_decoder.h
                   portability.h
                   portability.cpp
                   resource_util.h
                   resource_util.cpp
                   string_array_decoder.h
                   string_decoder.h
                   struct_pointer_decoder.h
                   swapchain_image_tracker.h
                   value_decoder.h
                   vulkan_ascii_consumer_base.h
                   vulkan_ascii_consumer_base.cpp
                   vulkan_consumer_base.h
                   vulkan_decoder_base.h
                   vulkan_decoder_base.cpp
                   vulkan_default_allocator.h
                   vulkan_default_allocator.cpp
                   vulkan_enum_util.h
                   vulkan_handle_mapping_util.h
                   vulkan_object_info.h
                   vulkan_object_info_table.h
                   vulkan_rebind_allocator.h
                   vulkan_rebind_allocator.cpp
                   vulkan_remap_allocator.h
                   vulkan_remap_allocator.cpp
                   vulkan_replay_consumer_base.h
                   vulkan_replay_consumer_base.cpp
                   vulkan_replay_options.h
                   vulkan_resource_allocator.h
                   vulkan_resource_initializer.h
                   vulkan_resource_initializer.cpp
                   window.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_consumer.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders_forward.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp
              )

if (MSVC AND (MSVC_VERSION LESS 1910))
    # This file fails to compile with VS2015, requiring the default section limit of 2^16 to be increased.
    set_source_files_properties(vulkan_replay_consumer_base.cpp PROPERTIES COMPILE_FLAGS /bigobj)
endif()

target_include_directories(gfxrecon_decode
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_decode gfxrecon_format gfxrecon_util vulkan_registry vulkan_memory_allocator platform_specific gfxrecon_tcp_client)

common_build_directives(gfxrecon_decode)

add_executable(gfxrecon_decode_test "")

target_sources(gfxrecon_decode_test PRIVATE
        test/main.cpp)

common_build_directives(gfxrecon_decode_test)
common_test_directives(gfxrecon_decode_test)

