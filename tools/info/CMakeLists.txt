add_executable(gfxrecon-info "")

target_sources(gfxrecon-info
               PRIVATE
                   main.cpp
              )

target_include_directories(gfxrecon-info PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-info gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)

common_build_directives(gfxrecon-info)

install(TARGETS gfxrecon-info RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
