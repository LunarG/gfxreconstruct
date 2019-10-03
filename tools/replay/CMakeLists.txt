add_executable(gfxrecon-replay "")

target_sources(gfxrecon-replay
               PRIVATE
                   replay_settings.h
                   desktop_main.cpp
              )

if(WIN32)
target_compile_definitions(gfxrecon-replay PUBLIC TUNING_MODULE_SUPPORT)
endif()

target_include_directories(gfxrecon-replay PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-replay gfxrecon_application gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)

common_build_directives(gfxrecon-replay)
