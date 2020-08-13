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

cmake_minimum_required(VERSION 3.4.1)

option(APPLY_CPP_CODE_STYLE "Apply C++ code style using clang format" OFF)
option(CHECK_CPP_CODE_STYLE "Check C++ code style using clang format" OFF)
option(CHECK_CPP_CODE_STYLE_BASE "Git branch/commit for C++ code style comparison" "HEAD")

if(${APPLY_CPP_CODE_STYLE} OR ${CHECK_CPP_CODE_STYLE})
    find_program(CLANG_FORMAT clang-format DOC "Clang format executable")

    # Python
    if(CMAKE_HOST_WIN32)
        find_program(PYTHON "python.exe" PATHS $ENV{PATH} DOC "Python 3 executable")
        execute_process(COMMAND ${PYTHON} --version OUTPUT_VARIABLE PYTHON_VERSION)
        string(REPLACE "Python " "" "PYTHON_VERSION" "${PYTHON_VERSION}")
        if("${PYTHON_VERSION}" VERSION_LESS "3.0.0")
            message(FATAL_ERROR "Python 3+ is required. Python version ${PYTHON_VERSION} found.")
        endif()
    else()
        find_program(PYTHON python3 DOC "Python 3 executable")
    endif()
endif()

macro(generate_target_source_files TARGET TARGET_SOURCE_FILES)
    get_target_property(${TARGET_SOURCE_FILES} ${TARGET} SOURCES)
    list(FILTER ${TARGET_SOURCE_FILES} EXCLUDE REGEX ".+\.def|generated_.+")
endmacro()

# Apply code style build directives
function(target_code_style_build_directives TARGET)
    generate_target_source_files(${TARGET} TARGET_SRC_FILES TARGET_SOURCE_FILES)
    if(${APPLY_CPP_CODE_STYLE})
        if(CLANG_FORMAT-NOTFOUND STREQUAL ${CLANG_FORMAT})
            message(FATAL_ERROR "Failed to find clang-format in system path")
        endif()
        # If apply code style is on, turn off check code style
        set(CHECK_CPP_CODE_STYLE OFF)
        add_custom_target("${TARGET}ClangFormat"
                COMMAND ${CLANG_FORMAT} -i ${TARGET_SRC_FILES}
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                COMMENT "Run clang format for ${TARGET}"
                COMMAND_EXPAND_LISTS)
        add_dependencies(${TARGET} "${TARGET}ClangFormat")
    endif()
    if(${CHECK_CPP_CODE_STYLE})
        # Call the script to check formatting
        add_custom_target("${TARGET}CodeStyleCheck"
                COMMAND "${PYTHON}" ${CMAKE_SOURCE_DIR}/scripts/check_code_style.py
                --sourcefile ${TARGET_SRC_FILES} --base ${CHECK_CPP_CODE_STYLE_BASE}
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                COMMENT "Check code style for ${TARGET}")
        add_dependencies(${TARGET} "${TARGET}CodeStyleCheck")
    endif()
endfunction()
