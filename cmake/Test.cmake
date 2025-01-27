##############################################################################
# Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved
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
# Description: CMake test build directives
###############################################################################

cmake_minimum_required(VERSION 3.24)

option(RUN_TESTS "Run unit tests" OFF)

if (${RUN_TESTS})
    # Python
    if(CMAKE_HOST_WIN32)
        find_program(PYTHON python.exe DOC "Python executable")
        execute_process(COMMAND ${PYTHON} --version OUTPUT_VARIABLE PYTHON_VERSION)
        string(REPLACE "Python " "" PYTHON_VERSION ${PYTHON_VERSION})
        if(${PYTHON_VERSION} VERSION_LESS "3.0.0")
            message(FATAL_ERROR "Python 3+ is required.")
        endif()
    else()
        find_program(PYTHON python3 DOC "Python executable")
    endif()

    # Build architecture
    if(${CMAKE_SIZEOF_VOID_P} EQUAL 8)
        set(ARCHITECTURE "x64")
    endif()
    if(${CMAKE_SIZEOF_VOID_P} EQUAL 4)
        set(ARCHITECTURE "x86")
    endif()

    # Add test post build step to an executable test target
    function(common_test_directives TARGET)
        # Test executable build directives needed for catch 2
        target_link_libraries(${TARGET} PRIVATE catch2)
        target_compile_definitions(${TARGET} PRIVATE $<$<BOOL:${MSVC}>:_UNICODE>)
        # Running test directives
        if (${RUN_TESTS})
            get_target_property(TARGET_TYPE ${TARGET} TYPE)
            if (NOT ("EXECUTABLE" STREQUAL ${TARGET_TYPE}))
                message(FATAL_ERROR
                        "${TARGET} is not an executable.\n"
                        "Test directives can only be applied to executables.")
            endif()
            add_custom_target(${TARGET}RunTests ALL
                    COMMAND "${PYTHON}" ${GFXReconstruct_SOURCE_DIR}/scripts/test.py
                        -c $<$<CONFIG:Debug>:debug> $<$<CONFIG:Release>:release>
                        -a ${ARCHITECTURE}
                        --test-exe $<TARGET_FILE:${TARGET}>
                        $<$<NOT:$<STREQUAL:"","${ARGN}">>:"--test-args ${ARGN}">
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
            add_dependencies(${TARGET}RunTests ${TARGET})
        endif()
    endfunction()

    option(GENERATE_TEST_ARCHIVE
        "Generate an archive that contains all test scripts and binaries" OFF)

    # Test archive files for a top level CMakeLists
    set_property(GLOBAL PROPERTY TEST_ARCHIVE_FILES "")

    # Add a file to the test package
    function(add_test_package_file FILE)
        get_property(TEST_ARCHIVE_FILES GLOBAL PROPERTY TEST_ARCHIVE_FILES)
        set_property(GLOBAL PROPERTY TEST_ARCHIVE_FILES "${TEST_ARCHIVE_FILES};${FILE}")
    endfunction()

    # Add a target binary output to the test archive
    function(add_target_to_test_package TARGET)
        add_test_package_file("$<TARGET_FILE:${TARGET}>")
    endfunction()

    # Generate a test archive
    #
    # This macro uses target generator expressions, it must be called after the
    # targets have been added.
    function(generate_test_package TEST_ARCHIVE)
        get_property(TEST_ARCHIVE_FILES GLOBAL PROPERTY TEST_ARCHIVE_FILES)
        if(${GENERATE_TEST_ARCHIVE})
            set(TEST_ARCHIVE_DIR ${CMAKE_INSTALL_PREFIX})
            file(MAKE_DIRECTORY ${TEST_ARCHIVE_DIR})
            if(CMAKE_HOST_WIN32)
                add_custom_target(GenerateTestPackage ALL
                    COMMAND cmake -E tar "vcf" ${TEST_ARCHIVE_DIR}/${TEST_ARCHIVE}.zip --format=zip --
                        ${TEST_ARCHIVE_FILES}
                    DEPENDS ${TEST_ARCHIVE_FILES}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMENT "Generate Windows test package")
            elseif(CMAKE_HOST_UNIX)
                add_custom_target(GenerateTestPackage ALL
                    COMMAND cmake -E tar "cf" ${TEST_ARCHIVE_DIR}/${TEST_ARCHIVE}.tar --format=gnutar --
                        ${TEST_ARCHIVE_FILES}
                    DEPENDS ${TEST_ARCHIVE_FILES}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMENT "Generate Linux test package")
            else()
                message(FATAL_ERROR "Unsupported test package generation platform")
            endif()
        endif()
    endfunction()
else()
    function(common_test_directives TARGET)
    endfunction()

    function(add_test_package_file FILE)
    endfunction()

    function(add_target_to_test_package TARGET)
    endfunction()

    function(generate_test_package TEST_ARCHIVE)
    endfunction()
endif()
