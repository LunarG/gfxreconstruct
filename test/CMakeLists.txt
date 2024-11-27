###############################################################################
# Copyright (c) 2018-2024 LunarG, Inc.
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
# Description: CMake script for gfxrecon tests
###############################################################################

add_subdirectory(icd)
add_subdirectory(test_apps)

enable_testing()
set(INSTALL_GTEST OFF)
find_package(GoogleTest REQUIRED)
include(GoogleTest)
add_executable(gfxrecon-testapp-runner
        test_cases/triangle.cpp
        test_cases/multisample-depth.cpp
        test_cases/shader-objects.cpp
        test_cases/pipeline-binaries.cpp
        verify-gfxr.cpp
)
add_dependencies(gfxrecon-testapp-runner gfxrecon-testapps VkICD_mock_icd)
target_include_directories(gfxrecon-testapp-runner PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(gfxrecon-testapp-runner
        nlohmann_json::nlohmann_json
        GTest::gtest GTest::gtest_main)
gtest_discover_tests(gfxrecon-testapp-runner)
install(TARGETS gfxrecon-testapp-runner RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
