add_library(gfxrecon_encode STATIC "")

target_sources(gfxrecon_encode
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/capture_settings.h
                    ${CMAKE_CURRENT_LIST_DIR}/capture_settings.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_encoder_commands.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_api_call_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_api_call_encoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_encoders.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_encoders.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_wrappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_vulkan_struct_handle_wrappers.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/descriptor_update_template_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/parameter_encoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/struct_pointer_encoder.h
                    ${CMAKE_CURRENT_LIST_DIR}/trace_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/trace_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_wrappers.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_handle_wrapper_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_table.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_tracker.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_tracker.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_tracker_initializers.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_writer.h
                    ${CMAKE_CURRENT_LIST_DIR}/vulkan_state_writer.cpp
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
    target_link_libraries(gfxrecon_encode $<$<BOOL:${XCB_FOUND}>:${XCB_LIBRARIES}>)
endif()

target_link_libraries(gfxrecon_encode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(gfxrecon_encode)

add_executable(gfxrecon_encode_test "")

target_sources(gfxrecon_encode_test
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)

common_build_directives(gfxrecon_encode_test)
common_test_directives(gfxrecon_encode_test)
