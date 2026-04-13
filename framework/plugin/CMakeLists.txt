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

# Interface
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

# Sink
set(GFXR_REPLAY_PLUGIN_LOADER_TARGET_NAME gfxrecon_replay_plugin_loader)
add_library(${GFXR_REPLAY_PLUGIN_LOADER_TARGET_NAME}
    STATIC
        ${CMAKE_CURRENT_LIST_DIR}/replay_event_sink.cpp
        ${CMAKE_CURRENT_LIST_DIR}/replay_event_sink.h)
target_include_directories(${GFXR_REPLAY_PLUGIN_LOADER_TARGET_NAME}
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/../)
target_link_libraries(${GFXR_REPLAY_PLUGIN_LOADER_TARGET_NAME}
    PUBLIC
        ${GFXR_REPLAY_PLUGIN_ABI_TARGET_NAME}
    PRIVATE
        gfxrecon_util)

# Tests
if(${RUN_TESTS})
    set(TEST_TARGET_NAME gfxrecon_replay_plugin_loader_test)
    add_executable(${TEST_TARGET_NAME} "")
    target_sources(${TEST_TARGET_NAME}
        PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
            ${CMAKE_CURRENT_LIST_DIR}/../../tools/platform_debug_helper.cpp)
    target_link_libraries(${TEST_TARGET_NAME}
        PUBLIC
            ${GFXR_REPLAY_PLUGIN_LOADER_TARGET_NAME} vulkan_registry)
    if(MSVC)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(${TEST_TARGET_NAME}
                PUBLIC
                    "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(${TEST_TARGET_NAME}
                PUBLIC
                    "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(${TEST_TARGET_NAME})
    common_test_directives(${TEST_TARGET_NAME})
endif()

# Sample
set(TARGET_NAME gfxrecon_print_replay_plugin)
add_library(${TARGET_NAME}
    MODULE
        ${CMAKE_CURRENT_LIST_DIR}/sample/replay_event_plugin.cpp)
target_link_libraries(${TARGET_NAME}
    PRIVATE
        ${GFXR_REPLAY_PLUGIN_ABI_TARGET_NAME})
common_build_directives(${TARGET_NAME})
install(FILES ${GFXR_REPLAY_PLUGIN_PUBLIC_HEADER} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/gfxr)
