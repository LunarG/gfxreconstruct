##############################################################################
# Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Author: AMD Developer Tools Team
# Description: CMake test build directives
###############################################################################

cmake_minimum_required(VERSION 3.4.1)

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
            if(CMAKE_HOST_WIN32)
                set(TEST_ARCHIVE_DIR build/packages/windows/${ARCHITECTURE})
                file(MAKE_DIRECTORY ${TEST_ARCHIVE_DIR})
                add_custom_target(GenerateTestPackage ALL
                    COMMAND cmake -E tar "vcf" ${TEST_ARCHIVE_DIR}/${TEST_ARCHIVE}.zip --format=zip --
                        ${TEST_ARCHIVE_FILES}
                    DEPENDS ${TEST_ARCHIVE_FILES}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMENT "Generate Windows test package")
            elseif(CMAKE_HOST_UNIX)
                set(TEST_ARCHIVE_DIR build/packages/linux/${ARCHITECTURE})
                file(MAKE_DIRECTORY ${TEST_ARCHIVE_DIR})
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
