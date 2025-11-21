add_executable(gfxrecon-tocpp "")

target_sources(gfxrecon-tocpp
               PRIVATE
                   main.cpp
              )

target_include_directories(gfxrecon-tocpp PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-tocpp gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific project_version)

common_build_directives(gfxrecon-tocpp)

install(TARGETS gfxrecon-tocpp RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
