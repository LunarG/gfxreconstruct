add_executable(gfxrecon-toascii "")

target_sources(gfxrecon-toascii
               PRIVATE
                   main.cpp
              )

target_link_libraries(gfxrecon-toascii gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)

target_build_directives(gfxrecon-toascii)