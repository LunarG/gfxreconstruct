###############################################################################
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
# Description: CMake code static analysis build directives
###############################################################################

cmake_minimum_required(VERSION 3.1)

option(RUN_STATIC_ANALYSIS "Run static analysis using clang-tidy" OFF)

find_program(CLANG_TIDY clang-tidy DOC "Clang tidy executable")

# Apply static analysis build directives (Linux only)
function(target_static_analysis_build_directives TARGET)
    if(${RUN_STATIC_ANALYSIS})
        if(CLANG_TIDY-NOTFOUND STREQUAL ${CLANG_TIDY})
            message(FATAL_ERROR "Failed to find clang-tidy in system path")
        endif()

        get_target_property(TARGET_SOURCE_FILES ${TARGET} SOURCES)
        list(FILTER TARGET_SOURCE_FILES EXCLUDE REGEX ".+\.def|generated_.+")

        set(CLANG_TIDY_ARGS "-checks=")
        string(APPEND CLANG_TIDY_ARGS clang-analyzer-core*,)
        string(APPEND CLANG_TIDY_ARGS clang-analyzer-cplusplus*,)
        string(APPEND CLANG_TIDY_ARGS llvm-include-order,)
        string(APPEND CLANG_TIDY_ARGS performance*,)
        string(APPEND CLANG_TIDY_ARGS readability*)
        if(${WIN32})
            message(WARNING "Static analysis not supported in Windows platform yet.")
        else()
            add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CLANG_TIDY}
            ARGS
                ${TARGET_SOURCE_FILES}
                ${CLANG_TIDY_ARGS}
                "-p=${CMAKE_BINARY_DIR}" 
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
        endif()
    endif()
endfunction()
