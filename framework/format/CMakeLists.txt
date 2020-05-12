add_library(gfxrecon_format STATIC "")

target_sources(gfxrecon_format
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/api_call_id.h
                    ${CMAKE_CURRENT_LIST_DIR}/format.h
                    ${CMAKE_CURRENT_LIST_DIR}/format_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/format_util.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/platform_types.h
              )

target_include_directories(gfxrecon_format
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(gfxrecon_format)

add_executable(gfxrecon_format_test "")

target_sources(gfxrecon_format_test
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)

common_build_directives(gfxrecon_format_test)
common_test_directives(gfxrecon_format_test)
