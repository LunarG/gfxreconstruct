###############################################################################
# Copyright (c) 2018-2025 LunarG, Inc.
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
# Author: LunarG Team
# Author: AMD Developer Tools Team
# Description: CMake script for shader-objects test app
###############################################################################

add_library(gfxrecon-testapp-shader-objects app.cpp)

target_include_directories(gfxrecon-testapp-shader-objects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gfxrecon-testapp-shader-objects gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-shader-objects)

install(TARGETS gfxrecon-testapp-shader-objects RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/shader-objects)
install(DIRECTORY shaders DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/shader-objects)

add_dependencies(gfxrecon-testapps gfxrecon-testapp-shader-objects)