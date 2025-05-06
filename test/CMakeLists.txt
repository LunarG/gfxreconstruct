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


cmake_minimum_required(VERSION 3.24.0)

if (NOT DEFINED ENV{GFXRECON_NO_TEST_APPS})
    set(GFXRECON_INSTALL_TESTDIR ${CMAKE_INSTALL_PREFIX}/test)

    add_subdirectory(icd)
    add_subdirectory(test_apps)

    enable_testing()
    set(INSTALL_GTEST OFF)
    find_package(GoogleTest REQUIRED)
    include(GoogleTest)

    set(GFXRECON_TESTCASES
        test_cases/triangle.cpp
        test_cases/multisample-depth.cpp
        test_cases/shader-objects.cpp
        test_cases/pipeline-binaries.cpp
        test_cases/acquired-image.cpp
        verify-gfxr.cpp)
    
    if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU")
        list(APPEND GFXRECON_TESTCASES test_cases/external-memory-fd.cpp)
        list(APPEND GFXRECON_TESTCASES test_cases/wait-for-present.cpp)
    endif()
    
    add_executable(gfxrecon-testapp-runner ${GFXRECON_TESTCASES})

    add_dependencies(gfxrecon-testapp-runner gfxrecon-test-launcher VkICD_mock_icd gfxrecon-convert VkLayer_gfxreconstruct)
    target_include_directories(gfxrecon-testapp-runner PRIVATE ${CMAKE_CURRENT_LIST_DIR})
    target_link_libraries(gfxrecon-testapp-runner
            gfxrecon_util
            GTest::gtest GTest::gtest_main)
    gtest_discover_tests(gfxrecon-testapp-runner)

    install(TARGETS gfxrecon-testapp-runner RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    install(DIRECTORY known_good DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    install(TARGETS gfxrecon-convert RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    if (APPLE)
        install(PROGRAMS run-tests_macos.sh DESTINATION ${GFXRECON_INSTALL_TESTDIR})
        install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json DESTINATION ${GFXRECON_INSTALL_TESTDIR}/vulkan/explicit_layer.d)
        install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR}/vulkan/explicit_layer.d LIBRARY DESTINATION ${GFXRECON_INSTALL_TESTDIR}/vulkan/explicit_layer.d)
    elseif (UNIX)
        install(PROGRAMS run-tests.sh DESTINATION ${GFXRECON_INSTALL_TESTDIR})
        install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json DESTINATION ${GFXRECON_INSTALL_TESTDIR}/vulkan/explicit_layer.d)
        install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR}/vulkan/explicit_layer.d LIBRARY DESTINATION ${GFXRECON_INSTALL_TESTDIR}/vulkan/explicit_layer.d)
    else ()
        install(PROGRAMS run-tests.ps1 DESTINATION ${GFXRECON_INSTALL_TESTDIR})
        install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json DESTINATION ${GFXRECON_INSTALL_TESTDIR})
        install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR} LIBRARY DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    endif ()

endif ()
