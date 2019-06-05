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

cmake_minimum_required(VERSION 3.1)

option(RUN_TESTS "Run static analysis using clang-tidy" OFF)

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
function(target_test_directives TARGET)
    # Test executable build directives needed for catch 2
    target_link_libraries(${TARGET} PRIVATE catch2)
    target_compile_definitions(${TARGET} PRIVATE $<${MSVC}:_UNICODE>)
    # Running test directives
    if (${RUN_TESTS})
        get_target_property(TARGET_TYPE ${TARGET} TYPE)
        if (NOT ("EXECUTABLE" STREQUAL ${TARGET_TYPE}))
            message(FATAL_ERROR
                    "${TARGET} is not an executable.\n"
                    "Test directives can only be applied to executables.")
        endif()
        add_custom_target(${TARGET}RunTests ALL
                COMMAND "${PYTHON}" ${GFXReconstruct_SOURCE_DIR}/test.py
                    -c $<$<CONFIG:Debug>:debug> $<$<CONFIG:Release>:release>
                    -a ${ARCHITECTURE}
                    --test-exe $<TARGET_FILE:${TARGET}>
                    $<$<NOT:$<STREQUAL:"","${ARGN}">>:"--test-args ${ARGN}">
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
        add_dependencies(${TARGET}RunTests ${TARGET})
    endif()
endfunction()
