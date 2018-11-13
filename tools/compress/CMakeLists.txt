add_executable(gfxrecon-compress "")

target_sources(gfxrecon-compress
               PRIVATE
                   main.cpp
              )

target_link_libraries(gfxrecon-compress gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)
