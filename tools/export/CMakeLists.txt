add_executable(gfxrecon-export "")

target_sources(gfxrecon-export
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/../tool_settings.h
                    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/../platform_debug_helper.cpp
              )

if (MSVC)
      # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
      # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
      if(NOT CMAKE_CL_64)
         target_link_options(gfxrecon-replay PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
      else()
            target_link_options(gfxrecon-replay PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
      endif()
endif()

target_include_directories(gfxrecon-export PUBLIC ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(gfxrecon-export gfxrecon_decode gfxrecon_graphics gfxrecon_format gfxrecon_util platform_specific)

common_build_directives(gfxrecon-export)

install(TARGETS gfxrecon-export RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
