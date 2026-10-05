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
# Author: LunarG Team
# Description: CMake script for the frame looping test apps
###############################################################################

add_library(gfxrecon-testapp-frame-looping-buffer-contents frame-looping-buffer-contents.cpp)

target_include_directories(gfxrecon-testapp-frame-looping-buffer-contents PUBLIC
${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gfxrecon-testapp-frame-looping-buffer-contents
    PUBLIC
        gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-frame-looping-buffer-contents)

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-frame-looping-buffer-contents RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/frame-looping-buffer-contents)
endif()

add_library(gfxrecon-testapp-frame-looping-image-contents frame-looping-image-contents.cpp)

target_include_directories(gfxrecon-testapp-frame-looping-image-contents PUBLIC
${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gfxrecon-testapp-frame-looping-image-contents
    PUBLIC
        gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-frame-looping-image-contents)

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-frame-looping-image-contents RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/frame-looping-image-contents)
endif()

add_library(gfxrecon-testapp-frame-looping-event-state frame-looping-event-state.cpp)

target_include_directories(gfxrecon-testapp-frame-looping-event-state PUBLIC
${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gfxrecon-testapp-frame-looping-event-state
    PUBLIC
        gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-frame-looping-event-state)

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-frame-looping-event-state RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/frame-looping-event-state)
endif()

add_library(gfxrecon-testapp-frame-looping-fence-state frame-looping-fence-state.cpp)

target_include_directories(gfxrecon-testapp-frame-looping-fence-state PUBLIC
${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gfxrecon-testapp-frame-looping-fence-state
    PUBLIC
        gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-frame-looping-fence-state)

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-frame-looping-fence-state RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/frame-looping-fence-state)
endif()

add_library(gfxrecon-testapp-frame-looping-semaphore-state frame-looping-semaphore-state.cpp)

target_include_directories(gfxrecon-testapp-frame-looping-semaphore-state PUBLIC
${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gfxrecon-testapp-frame-looping-semaphore-state
    PUBLIC
        gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-frame-looping-semaphore-state)

if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-frame-looping-semaphore-state RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/frame-looping-semaphore-state)
endif()
