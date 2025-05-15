###############################################################################
# Copyright (c) 2025 LunarG, Inc.
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
# Description: CMake script for wait for present test app
###############################################################################

add_library(gfxrecon-testapp-wait-for-present app.cpp)

target_include_directories(gfxrecon-testapp-wait-for-present PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(gfxrecon-testapp-wait-for-present gfxrecon-testapp-base)

common_build_directives(gfxrecon-testapp-wait-for-present)

# Gradle is taking care of copying the resources in the APK
if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
    install(TARGETS gfxrecon-testapp-wait-for-present RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR}/wait-for-present)
    install(DIRECTORY ${GFXRECON_TESTAPPS_RES_DIR}/wait-for-present DESTINATION ${GFXRECON_INSTALL_TESTAPPDIR})
endif()
