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
###############################################################################

# The arrangement layer. format defines the primitives a capture can represent and how each is encoded; this
# defines how they are arranged -- which API type a Field names, how it is packaged, and which store member holds
# it. Header-only and API-agnostic: it names no Vulkan type, no decoded representation and no operation, so capture
# and replay can both reach it without reaching each other.
#
# Generated content is not here. An API's descriptors, Field descriptors and schemas are generated into
# framework/generated and listed by the target that compiles them.

add_library(gfxrecon_binding INTERFACE)

target_include_directories(gfxrecon_binding
                           INTERFACE
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_binding
                      INTERFACE
                          gfxrecon_schema)

add_custom_target(gfxrecon_binding_headers
                  SOURCES
                      ${CMAKE_CURRENT_LIST_DIR}/descriptor_for.h
                      ${CMAKE_CURRENT_LIST_DIR}/structure_type.h)
