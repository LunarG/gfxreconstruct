###############################################################################
# Copyright (c) 2026 LunarG, Inc.
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

set(GFXR_REPLAY_PLUGIN_ABI_TARGET_NAME gfxrecon_replay_plugin_abi)
set(GFXR_REPLAY_PLUGIN_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/public)
set(GFXR_REPLAY_PLUGIN_PUBLIC_HEADER ${GFXR_REPLAY_PLUGIN_INCLUDE_DIR}/gfxr/replay_event_plugin.h)

add_library(${GFXR_REPLAY_PLUGIN_ABI_TARGET_NAME} INTERFACE)
target_include_directories(${GFXR_REPLAY_PLUGIN_ABI_TARGET_NAME}
    INTERFACE
        $<BUILD_INTERFACE:${GFXR_REPLAY_PLUGIN_INCLUDE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_sources(${GFXR_REPLAY_PLUGIN_ABI_TARGET_NAME}
    INTERFACE
        ${GFXR_REPLAY_PLUGIN_PUBLIC_HEADER})

set(TARGET_NAME gfxrecon_print_replay_plugin)
add_library(${TARGET_NAME} MODULE
        ${CMAKE_CURRENT_LIST_DIR}/sample/replay_event_plugin.cpp)
target_link_libraries(${TARGET_NAME}
    PRIVATE
        ${GFXR_REPLAY_PLUGIN_ABI_TARGET_NAME})
common_build_directives(${TARGET_NAME})

install(FILES ${GFXR_REPLAY_PLUGIN_PUBLIC_HEADER}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/gfxr)
