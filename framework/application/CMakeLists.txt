###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2019-2020 Advanced Micro Devices, Inc.
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
# Description: CMake script for framework util target
###############################################################################

add_library(gfxrecon_application STATIC "")

target_sources(gfxrecon_application
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/application.h
                    ${CMAKE_CURRENT_LIST_DIR}/application.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/wsi_context.h
                    ${CMAKE_CURRENT_LIST_DIR}/wsi_context.cpp
                    $<$<BOOL:${HEADLESS}>:${CMAKE_CURRENT_LIST_DIR}/headless_context.h>
                    $<$<BOOL:${HEADLESS}>:${CMAKE_CURRENT_LIST_DIR}/headless_window.h>
                    $<$<BOOL:${HEADLESS}>:${CMAKE_CURRENT_LIST_DIR}/headless_context.cpp>
                    $<$<BOOL:${HEADLESS}>:${CMAKE_CURRENT_LIST_DIR}/headless_window.cpp>
                    $<$<BOOL:${BUILD_WSI_DISPLAY_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/display_context.h>
                    $<$<BOOL:${BUILD_WSI_DISPLAY_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/display_window.h>
                    $<$<BOOL:${BUILD_WSI_DISPLAY_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/display_context.cpp>
                    $<$<BOOL:${BUILD_WSI_DISPLAY_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/display_window.cpp>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_context.h>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_window.h>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_context.cpp>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_window.cpp>
                    $<$<BOOL:${X11_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xlib_context.h>
                    $<$<BOOL:${X11_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xlib_window.h>
                    $<$<BOOL:${X11_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xlib_context.cpp>
                    $<$<BOOL:${X11_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xlib_window.cpp>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_context.h>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_window.h>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_context.cpp>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_window.cpp>
                    $<$<BOOL:${WIN32}>:${CMAKE_CURRENT_LIST_DIR}/win32_context.h>
                    $<$<BOOL:${WIN32}>:${CMAKE_CURRENT_LIST_DIR}/win32_window.h>
                    $<$<BOOL:${WIN32}>:${CMAKE_CURRENT_LIST_DIR}/win32_context.cpp>
                    $<$<BOOL:${WIN32}>:${CMAKE_CURRENT_LIST_DIR}/win32_window.cpp>
                    $<$<BOOL:${APPLE}>:${CMAKE_CURRENT_LIST_DIR}/metal_context.h>
                    $<$<BOOL:${APPLE}>:${CMAKE_CURRENT_LIST_DIR}/metal_window.h>
                    $<$<BOOL:${APPLE}>:${CMAKE_CURRENT_LIST_DIR}/metal_context.mm>
                    $<$<BOOL:${APPLE}>:${CMAKE_CURRENT_LIST_DIR}/metal_window.mm>
              )

target_include_directories(gfxrecon_application
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(gfxrecon_application
                      gfxrecon_decode
                      gfxrecon_graphics
                      gfxrecon_format
                      gfxrecon_util
                      vulkan_registry
                      openxr_headers
                      platform_specific
                     )

common_build_directives(gfxrecon_application)

if (APPLE)
    find_library(APPKIT_LIBRARY AppKit)
    find_library(QUARTZCORE_LIBRARY QuartzCore)
    target_compile_options(gfxrecon_application PRIVATE -fobjc-arc)
    target_link_libraries(gfxrecon_application ${APPKIT_LIBRARY} ${QUARTZCORE_LIBRARY})
endif(APPLE)

if (${RUN_TESTS})
    add_executable(gfxrecon_application_test "")
    target_sources(gfxrecon_application_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
            ${CMAKE_CURRENT_LIST_DIR}/../../tools/platform_debug_helper.cpp)
    target_link_libraries(gfxrecon_application_test PRIVATE gfxrecon_application)
    if (MSVC)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(gfxrecon_application_test PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(gfxrecon_application_test PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(gfxrecon_application_test)
    common_test_directives(gfxrecon_application_test)
endif()
