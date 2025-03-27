###############################################################################
# Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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
# Author: AMD Developer Tools Team
# Description: CMake script for layer amd_ags target
###############################################################################

add_library(ags_capture SHARED "")
set_target_properties(ags_capture PROPERTIES OUTPUT_NAME "amd_ags_x64_capture")
set(LINK_AGS_OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/amd_ags_x64_orig.lib)
target_sources(ags_capture PRIVATE
                ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                ${CMAKE_CURRENT_LIST_DIR}/amd_ags_x64.def
                ${CMAKE_CURRENT_LIST_DIR}/hook_ags.h
                ${CMAKE_CURRENT_LIST_DIR}/hook_ags.cpp
                ${PROJECT_SOURCE_DIR}/version.rc)
target_include_directories(ags_capture PUBLIC 
                           ${CMAKE_BINARY_DIR} 
                           ${PROJECT_SOURCE_DIR})
target_link_libraries(ags_capture gfxrecon_util ${LINK_AGS_OUTPUT})
add_custom_command(TARGET ags_capture PRE_BUILD
                    COMMAND lib /def:${CMAKE_CURRENT_LIST_DIR}/amd_ags_x64_orig.def /out:${LINK_AGS_OUTPUT} /machine:${LINK_ARCH}
                    DEPENDS ${CMAKE_CURRENT_LIST_DIR}/amd_ags_x64_orig.def)


install(FILES $<TARGET_FILE_DIR:ags_capture>/amd_ags_x64_capture.dll DESTINATION ${CMAKE_INSTALL_BINDIR}/d3d12_capture)

