###############################################################################
# Copyright (c) 2018-2023 LunarG, Inc.
# Copyright (c) 2018-2023 Valve Corporation.
# Copyright (c) 2020-2023 Advanced Micro Devices, Inc.
# All rights reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#
###############################################################################
add_executable(gfxrecon-convert "")

target_sources(gfxrecon-convert
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/../tool_settings.h
                    ${CMAKE_CURRENT_LIST_DIR}/main.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/../platform_debug_helper.cpp
                    $<$<BOOL:WIN32>:${PROJECT_SOURCE_DIR}/version.rc>
              )

if (MSVC)
      # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
      # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
      if(CMAKE_SIZEOF_VOID_P EQUAL 4)
         target_link_options(gfxrecon-convert PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
      else()
            target_link_options(gfxrecon-convert PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
      endif()
endif()

target_include_directories(gfxrecon-convert PUBLIC ${CMAKE_BINARY_DIR} ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(gfxrecon-convert gfxrecon_decode gfxrecon_graphics gfxrecon_format gfxrecon_util platform_specific project_version)

common_build_directives(gfxrecon-convert)

install(TARGETS gfxrecon-convert RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
