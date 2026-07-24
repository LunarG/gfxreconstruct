add_subdirectory(util)
add_subdirectory(plugin)
add_subdirectory(graphics)
add_subdirectory(format)
add_subdirectory(encode)
add_subdirectory(decode)
add_subdirectory(application)

if (${RUN_TESTS})
    add_executable(gfxrecon_framework_test "")
    target_sources(gfxrecon_framework_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
            $<$<BOOL:${GFXRECON_ENABLE_VULKAN}>:${CMAKE_CURRENT_LIST_DIR}/test/test_arm_data_graph_structs.cpp>
            ${CMAKE_CURRENT_LIST_DIR}/../tools/platform_debug_helper.cpp)
    target_link_libraries(gfxrecon_framework_test PRIVATE gfxrecon_encode gfxrecon_decode)
    if (MSVC)
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
