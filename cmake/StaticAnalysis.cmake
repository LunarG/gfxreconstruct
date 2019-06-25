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
# Description: CMake static analysis build directives
###############################################################################

cmake_minimum_required(VERSION 3.1)

option(RUN_STATIC_ANALYSIS "Run static analysis using clang-tidy" OFF)

find_program(CLANG_TIDY clang-tidy DOC "Clang tidy executable")

# Prepend a prefix to each elements in list of elements
function(prepend_to_list_items OUT_LIST IN_LIST PREFIX)
    set(TMP_LIST "")
    foreach(ITEM ${IN_LIST})
        list(APPEND TMP_LIST ${PREFIX}${ITEM})
    endforeach()
    set(${OUT_LIST} ${TMP_LIST} PARENT_SCOPE)
endfunction()

# Apply static analysis build directives
function(target_static_analysis_build_directives TARGET)
    if(${RUN_STATIC_ANALYSIS})
        get_target_property(TARGET_SOURCE_FILES ${TARGET} SOURCES)
        list(FILTER TARGET_SOURCE_FILES EXCLUDE REGEX ".+\.def")
        if(CLANG_TIDY-NOTFOUND STREQUAL ${CLANG_TIDY})
            message(FATAL_ERROR "Failed to find clang-tidy in system path")
        endif()
        get_target_property(SOURCES ${TARGET} SOURCES)
        get_target_property(INCLUDE_DIRECTORIES ${TARGET} INCLUDE_DIRECTORIES)
        prepend_to_list_items(
            TARGET_INCLUDE_DIRS ${INCLUDE_DIRECTORIES} "-I")
        add_custom_command(TARGET ${TARGET} POST_BUILD
            COMMAND ${CLANG_TIDY}
            ARGS ${SOURCES}
                -checks=clang-analyzer-core*,clang-analyzer-cplusplus*,-llvm-include-order,performance*,readability*
                -- ${TARGET_INCLUDE_DIRS}
            WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR})
    endif()
endfunction()
