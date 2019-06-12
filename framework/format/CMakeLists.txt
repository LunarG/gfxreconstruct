add_library(gfxrecon_format STATIC "")

target_sources(gfxrecon_format
               PRIVATE
                   api_call_id.h
                   format.h
                   format_util.h
                   format_util.cpp
                   platform_types.h
              )

target_include_directories(gfxrecon_format
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(gfxrecon_format)

add_executable(gfxrecon_format_test "")

target_sources(gfxrecon_format_test PRIVATE
        test/main.cpp)

common_build_directives(gfxrecon_format_test)
target_test_directives(gfxrecon_format_test)
