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
    set(GFXRECON_INSTALL_LAYER_INSTALL_DIR ${GFXRECON_INSTALL_TESTDIR}/vulkan/explicit_layer.d/)

    add_subdirectory(icd)
    if(NOT CMAKE_SYSTEM_NAME MATCHES "Android")
        add_subdirectory(android_mock)
    endif()
    add_subdirectory(test_apps)

    enable_testing()
    set(INSTALL_GTEST OFF)
    find_package(GoogleTest REQUIRED)
    include(GoogleTest)

    set(GFXRECON_TESTCASES
        test_cases/ahb.cpp
        test_cases/debug-utils.cpp
        test_cases/isolate-render-passes.cpp
        test_cases/serialize-compute-and-transfer.cpp
        test_cases/triangle.cpp
        test_cases/multisample-depth.cpp
        test_cases/shader-objects.cpp
        test_cases/pipeline-binaries.cpp
        test_cases/acquired-image.cpp
        test_cases/set-environment.cpp
        test_cases/deep-pnext-chain.cpp
        verify-gfxr.cpp)

    if(CMAKE_SYSTEM_NAME MATCHES "Linux|BSD|GNU")
        list(APPEND GFXRECON_TESTCASES test_cases/external-memory-fd.cpp)
        list(APPEND GFXRECON_TESTCASES test_cases/wait-for-present.cpp)
        list(APPEND GFXRECON_TESTCASES test_cases/trigger-trimming.cpp)
    endif()

    add_executable(gfxrecon-testapp-runner ${GFXRECON_TESTCASES})

    add_dependencies(gfxrecon-testapp-runner gfxrecon-test-launcher VkICD_mock_icd gfxrecon-convert gfxrecon-replay VkLayer_gfxreconstruct)
    target_include_directories(gfxrecon-testapp-runner PRIVATE ${CMAKE_CURRENT_LIST_DIR})
    target_link_libraries(gfxrecon-testapp-runner
            gfxrecon_util
            GTest::gtest GTest::gtest_main)
    # ctest starts each test case from the install test directory. The harness finds the launcher,
    # the tools, the resources and the known-good files relative to the current directory, so
    # install before you run ctest. Discovery also runs the binary in that directory, so it must
    # wait until ctest runs (PRE_TEST) and not happen at build time, when the install directory
    # does not exist yet. Every case gets the "smoke" label. Later labels select tests by driver
    # and by cost. TEST_LIST names the variable that holds the discovered cases at ctest time.
    gtest_discover_tests(gfxrecon-testapp-runner
        WORKING_DIRECTORY ${GFXRECON_INSTALL_TESTDIR}
        DISCOVERY_MODE PRE_TEST
        DISCOVERY_TIMEOUT 60
        TEST_LIST GFXRECON_TESTAPP_TESTS
        PROPERTIES
            LABELS "smoke"
            TIMEOUT 120)

    # One loader environment for every test case. Each entry is NAME=value. It selects the mock ICD
    # and the capture layer, and it makes the test apps headless. ctest applies it through
    # test_environment.cmake, so a plain ctest run works. The run-tests scripts export the same
    # list, so a single app run gets the same environment.
    set(GFXRECON_TEST_APPS_DIR ${GFXRECON_INSTALL_TESTDIR}/test_apps)
    if (WIN32)
        set(GFXRECON_TEST_LAYER_DIR ${GFXRECON_INSTALL_TESTDIR})
        set(GFXRECON_TEST_MOCK_ICD_LIBRARY ${GFXRECON_TEST_APPS_DIR}/VkICD_mock_icd.dll)
    elseif (APPLE)
        set(GFXRECON_TEST_LAYER_DIR ${GFXRECON_INSTALL_LAYER_INSTALL_DIR})
        set(GFXRECON_TEST_MOCK_ICD_LIBRARY ${GFXRECON_TEST_APPS_DIR}/libVkICD_mock_icd.dylib)
    else ()
        set(GFXRECON_TEST_LAYER_DIR ${GFXRECON_INSTALL_LAYER_INSTALL_DIR})
        set(GFXRECON_TEST_MOCK_ICD_LIBRARY ${GFXRECON_TEST_APPS_DIR}/libVkICD_mock_icd.so)
    endif ()
    set(GFXRECON_TEST_ENVIRONMENT
        "VK_LAYER_PATH=${GFXRECON_TEST_LAYER_DIR}"
        "VK_IMPLICIT_LAYER_PATH="
        "VK_DRIVER_FILES=${GFXRECON_TEST_APPS_DIR}/VkICD_mock_icd.json"
        "VK_ICD_FILENAMES=${GFXRECON_TEST_APPS_DIR}/VkICD_mock_icd.json"
        "VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct"
        "GFXRECON_CAPTURE_FILE_TIMESTAMP=false"
        "GFXRECON_TESTAPP_HEADLESS=true"
        "GFXRECON_TESTAPP_MOCK_ICD=${GFXRECON_TEST_MOCK_ICD_LIBRARY}")
    if (APPLE)
        list(APPEND GFXRECON_TEST_ENVIRONMENT
            "DYLD_LIBRARY_PATH=${GFXRECON_TEST_LAYER_DIR}:${GFXRECON_TEST_APPS_DIR}"
            "VK_LOADER_LAYERS_DISABLE=~implicit~"
            "VK_LOADER_LAYERS_ENABLE=VK_LAYER_LUNARG_gfxreconstruct"
            "DISPLAY=:0")
    elseif (UNIX)
        list(APPEND GFXRECON_TEST_ENVIRONMENT
            "LD_LIBRARY_PATH=${GFXRECON_TEST_LAYER_DIR}:${GFXRECON_TEST_APPS_DIR}"
            "VK_LOADER_LAYERS_DISABLE=~all~"
            "VK_LOADER_LAYERS_ENABLE=*gfxreconstruct*"
            "DISPLAY=:0")
    else ()
        list(APPEND GFXRECON_TEST_ENVIRONMENT
            "VK_LOADER_LAYERS_DISABLE=~all~"
            "VK_LOADER_LAYERS_ENABLE=*gfxreconstruct*")
    endif ()

    # ctest reads this file after the discovery file, so it sees GFXRECON_TESTAPP_TESTS.
    configure_file(test_environment.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/test_environment.cmake @ONLY)
    set_property(DIRECTORY APPEND PROPERTY TEST_INCLUDE_FILES ${CMAKE_CURRENT_BINARY_DIR}/test_environment.cmake)

    # The same list as export lines for the run-tests script.
    set(GFXRECON_TEST_ENVIRONMENT_EXPORTS "")
    foreach (entry IN LISTS GFXRECON_TEST_ENVIRONMENT)
        string(FIND "${entry}" "=" separator)
        string(SUBSTRING "${entry}" 0 ${separator} name)
        math(EXPR value_start "${separator} + 1")
        string(SUBSTRING "${entry}" ${value_start} -1 value)
        if (WIN32)
            string(APPEND GFXRECON_TEST_ENVIRONMENT_EXPORTS "$env:${name}=\"${value}\"\n")
        else ()
            string(APPEND GFXRECON_TEST_ENVIRONMENT_EXPORTS "export ${name}=\"${value}\"\n")
        endif ()
    endforeach ()

    # The run-tests script exports the environment and then calls ctest. It needs this build
    # directory and, for a multi-config generator, the configuration. configure_file fills the
    # directory, the ctest path and the exports. file(GENERATE) fills the configuration.
    set(GFXRECON_TEST_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
    if (APPLE)
        set(GFXRECON_RUN_TESTS_SCRIPT run-tests_macos.sh)
    elseif (UNIX)
        set(GFXRECON_RUN_TESTS_SCRIPT run-tests.sh)
    else ()
        set(GFXRECON_RUN_TESTS_SCRIPT run-tests.ps1)
    endif ()
    configure_file(${GFXRECON_RUN_TESTS_SCRIPT}.in
                   ${CMAKE_CURRENT_BINARY_DIR}/scripts/${GFXRECON_RUN_TESTS_SCRIPT}.configured
                   @ONLY)
    file(GENERATE
         OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/scripts/$<CONFIG>/${GFXRECON_RUN_TESTS_SCRIPT}
         INPUT ${CMAKE_CURRENT_BINARY_DIR}/scripts/${GFXRECON_RUN_TESTS_SCRIPT}.configured)
    install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/scripts/$<CONFIG>/${GFXRECON_RUN_TESTS_SCRIPT}
            DESTINATION ${GFXRECON_INSTALL_TESTDIR})

    install(TARGETS gfxrecon-testapp-runner RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    install(DIRECTORY known_good DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    install(TARGETS gfxrecon-convert RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    install(TARGETS gfxrecon-replay RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    if (UNIX)
        install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json DESTINATION ${GFXRECON_INSTALL_LAYER_INSTALL_DIR})
        install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${GFXRECON_INSTALL_LAYER_INSTALL_DIR} LIBRARY DESTINATION ${GFXRECON_INSTALL_LAYER_INSTALL_DIR})
    else ()
        install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json DESTINATION ${GFXRECON_INSTALL_TESTDIR})
        install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${GFXRECON_INSTALL_TESTDIR} LIBRARY DESTINATION ${GFXRECON_INSTALL_TESTDIR})
    endif ()

endif ()
