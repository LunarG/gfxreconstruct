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
# Description: CMake code style build directives
###############################################################################

cmake_minimum_required(VERSION 3.1)

option(APPLY_CPP_CODE_STYLE "Apply C++ code style using clang format" OFF)

find_program(CLANG_FORMAT clang-format DOC "Clang format executable")

# Apply code style build directives
macro(target_code_style_build_directives TARGET)
    if(${APPLY_CPP_CODE_STYLE})
        if(CLANG_FORMAT-NOTFOUND STREQUAL ${CLANG_FORMAT})
            message(FATAL_ERROR "Failed to find clang-format in system path")
        endif()
        get_target_property(TARGET_SOURCE_FILES ${TARGET} SOURCES)
        list(FILTER TARGET_SOURCE_FILES EXCLUDE REGEX ".+\.def|generated_.+")
        add_custom_target("${TARGET}ClangFormat"
                COMMAND ${CLANG_FORMAT} -i ${TARGET_SOURCE_FILES}
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                COMMENT "Run clang format for ${TARGET}"
                COMMAND_EXPAND_LISTS)
        add_dependencies(${TARGET} "${TARGET}ClangFormat")
    endif()
endmacro()
