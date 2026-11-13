###############################################################################
# Copyright (c) 2026 LunarG, Inc.
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
# Description: CMake script for framework binding target
###############################################################################

add_library(gfxrecon_binding INTERFACE)

target_include_directories(gfxrecon_binding
                           INTERFACE
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_binding
                      INTERFACE
                          gfxrecon_format
                          gfxrecon_schema)

add_custom_target(gfxrecon_binding_headers
                  SOURCES
                      ${CMAKE_CURRENT_LIST_DIR}/call_id_of.h
                      ${CMAKE_CURRENT_LIST_DIR}/decoded_type_of.h
                      ${CMAKE_CURRENT_LIST_DIR}/api_element_of.h
                      ${CMAKE_CURRENT_LIST_DIR}/enumerants.h
                      ${CMAKE_CURRENT_LIST_DIR}/structure_type.h
                      ${CMAKE_CURRENT_LIST_DIR}/vulkan_call_id.h
                      ${CMAKE_CURRENT_LIST_DIR}/vulkan_catalog.h
                      ${CMAKE_CURRENT_LIST_DIR}/vulkan_decoded_type.h
                      ${CMAKE_CURRENT_LIST_DIR}/vulkan_api_element_of.h
                      ${CMAKE_CURRENT_LIST_DIR}/vulkan_wire_type.h
                      ${CMAKE_CURRENT_LIST_DIR}/wire_type_of.h)
