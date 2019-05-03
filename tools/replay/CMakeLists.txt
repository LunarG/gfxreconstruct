add_executable(gfxrecon-replay "")

target_sources(gfxrecon-replay
               PRIVATE
                   replay_settings.h
                   desktop_main.cpp
              )

target_link_libraries(gfxrecon-replay gfxrecon_application gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)

target_build_directives(gfxrecon-replay)