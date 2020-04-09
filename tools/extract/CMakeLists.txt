add_executable(gfxrecon-extract "")

target_sources(gfxrecon-extract
               PRIVATE
                   main.cpp
              )

target_include_directories(gfxrecon-extract PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-extract gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)

common_build_directives(gfxrecon-extract)
