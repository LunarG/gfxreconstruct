###############################################################################
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
# Description: CMake code style build directives
###############################################################################

option(APPLY_CPP_CODE_STYLE "Apply C++ code style using clang format" OFF)
option(CHECK_CPP_CODE_STYLE "Check C++ code style using clang format" OFF)
option(CHECK_CPP_CODE_STYLE_BASE "Git branch/commit for C++ code style comparison" "HEAD")

if(${APPLY_CPP_CODE_STYLE} OR ${CHECK_CPP_CODE_STYLE})
    find_program(CLANG_FORMAT clang-format-14 DOC "Clang format executable")

    if(CLANG_FORMAT-NOTFOUND STREQUAL ${CLANG_FORMAT})
        message(FATAL_ERROR "Failed to find clang-format-14 in system path! Install clang-format-14 or set both APPLY_CPP_CODE_STYLE and CHECK_CPP_CODE_STYLE to OFF")
    endif()
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
    if(${APPLY_CPP_CODE_STYLE} OR ${CHECK_CPP_CODE_STYLE})
        generate_target_source_files(${TARGET} TARGET_SRC_FILES TARGET_SOURCE_FILES)
        if(${APPLY_CPP_CODE_STYLE})
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
    endif()
endfunction()
