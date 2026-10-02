add_subdirectory(util)
add_subdirectory(plugin)
add_subdirectory(graphics)
add_subdirectory(format)
add_subdirectory(encode)
add_subdirectory(schema)
add_subdirectory(decode)
add_subdirectory(application)

if (${RUN_TESTS})
    add_executable(gfxrecon_framework_test "")
    target_sources(gfxrecon_framework_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
            $<$<BOOL:${GFXRECON_ENABLE_VULKAN}>:${CMAKE_CURRENT_LIST_DIR}/test/test_arm_data_graph_structs.cpp>
            $<$<BOOL:${GFXRECON_ENABLE_VULKAN}>:${CMAKE_CURRENT_LIST_DIR}/test/test_static_array_len.cpp>
            $<$<BOOL:${GFXRECON_ENABLE_VULKAN}>:${CMAKE_CURRENT_LIST_DIR}/test/test_vulkan_schema.cpp>
            $<$<BOOL:${GFXRECON_ENABLE_VULKAN}>:${CMAKE_CURRENT_LIST_DIR}/test/test_vulkan_pnext_encoder.cpp>
            $<$<BOOL:${GFXRECON_ENABLE_VULKAN}>:${CMAKE_CURRENT_LIST_DIR}/test/schema_fill.h>
            $<$<BOOL:${GFXRECON_ENABLE_VULKAN}>:${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_schema_checks.cpp>
            ${CMAKE_CURRENT_LIST_DIR}/../tools/platform_debug_helper.cpp)
    target_link_libraries(gfxrecon_framework_test PRIVATE gfxrecon_encode gfxrecon_decode)
    if (MSVC)
        # The schema tests instantiate per-structure templates over the whole catalog; the default COFF section
        # limit is too small for them, as it is for gfxrecon_encode and gfxrecon_decode.
        target_compile_options(gfxrecon_framework_test PRIVATE /bigobj)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(gfxrecon_framework_test PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(gfxrecon_framework_test PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(gfxrecon_framework_test)
    common_test_directives(gfxrecon_framework_test)
endif()
