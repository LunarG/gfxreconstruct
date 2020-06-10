add_executable(gfxrecon-compress "")

target_sources(gfxrecon-compress
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

target_include_directories(gfxrecon-compress PUBLIC ${CMAKE_BINARY_DIR})

target_link_libraries(gfxrecon-compress gfxrecon_decode gfxrecon_format gfxrecon_util platform_specific)

common_build_directives(gfxrecon-compress)

install(TARGETS gfxrecon-compress RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
