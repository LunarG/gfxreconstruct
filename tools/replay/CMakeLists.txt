add_executable(gfxrecon-replay "")

target_sources(gfxrecon-replay
               PRIVATE
                   replay_settings.h
                   replay_settings.cpp
                   desktop_main.cpp
              )

target_include_directories(gfxrecon-replay PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-replay gfxrecon_application gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific gfxrecon_tcp_client)

common_build_directives(gfxrecon-replay)

install(TARGETS gfxrecon-replay RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
