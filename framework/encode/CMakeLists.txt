add_library(gfxrecon_encode STATIC "")

target_sources(gfxrecon_encode
               PRIVATE
                   capture_settings.h
                   capture_settings.cpp
                   custom_encoder_commands.h
                   custom_vulkan_api_call_encoders.h
                   custom_vulkan_api_call_encoders.cpp
                   custom_vulkan_struct_encoders.h
                   custom_vulkan_struct_encoders.cpp
                   custom_vulkan_struct_handle_wrappers.h
                   custom_vulkan_struct_handle_wrappers.cpp
                   descriptor_update_template_info.h
                   parameter_encoder.h
                   struct_pointer_encoder.h
                   trace_manager.h
                   trace_manager.cpp
                   vulkan_handle_wrappers.h
                   vulkan_handle_wrapper_util.h
                   vulkan_state_info.h
                   vulkan_state_table.h
                   vulkan_state_tracker.h
                   vulkan_state_tracker.cpp
                   vulkan_state_tracker_initializers.h
                   vulkan_state_writer.h
                   vulkan_state_writer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_command_buffer_util.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_dispatch_table.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_wrappers.cpp
              )

if (MSVC AND (MSVC_VERSION LESS 1910))
    # This file fails to compile with VS2015, requiring the default section limit of 2^16 to be increased.
    set_source_files_properties(${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp PROPERTIES COMPILE_FLAGS /bigobj)
endif()

target_include_directories(gfxrecon_encode
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

# include xcb libs for keypress trigegr in Linux
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    find_package(XCB)
    target_link_libraries(gfxrecon_encode $<$<BOOL:${XCB_FOUND}>:${_LIBRARY}>)
endif()

target_link_libraries(gfxrecon_encode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(gfxrecon_encode)

add_executable(gfxrecon_encode_test "")

target_sources(gfxrecon_encode_test PRIVATE
        test/main.cpp)

common_build_directives(gfxrecon_encode_test)
common_test_directives(gfxrecon_encode_test)
