add_executable(gfxrecon-export "")

target_sources(gfxrecon-export
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/../tool_settings.h
                    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
              )

target_include_directories(gfxrecon-export PUBLIC ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(gfxrecon-export gfxrecon_decode gfxrecon_graphics gfxrecon_format gfxrecon_util platform_specific)

common_build_directives(gfxrecon-export)

install(TARGETS gfxrecon-export RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
