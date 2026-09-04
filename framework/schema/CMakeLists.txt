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

# The field model and its algorithms. Header-only and API-agnostic: it names no Vulkan type, no decoded
# representation and no operation, so capture and replay can both reach it without reaching each other.
#
# Generated content is not here. An API's descriptors, Field descriptors and schemas are generated into
# framework/generated and listed by the target that compiles them.

add_library(gfxrecon_schema INTERFACE)

target_include_directories(gfxrecon_schema
                           INTERFACE
                               ${GFXRECON_SOURCE_DIR}/framework)

# util supplies defines.h and the TypeList facility; format supplies the wire types encoding.h maps kinds onto.
target_link_libraries(gfxrecon_schema
                      INTERFACE
                          gfxrecon_util
                          gfxrecon_format)

# The headers are listed on a target of their own rather than on gfxrecon_schema. INTERFACE sources are a usage
# requirement, so listing them there would add all three to every target that links this one, transitively -- every
# tool, not just the targets that read them. A custom target puts them in the IDE and in no build.
add_custom_target(gfxrecon_schema_headers
                  SOURCES
                      ${CMAKE_CURRENT_LIST_DIR}/field_model.h
                      ${CMAKE_CURRENT_LIST_DIR}/schema_util.h
                      ${CMAKE_CURRENT_LIST_DIR}/encoding.h)
