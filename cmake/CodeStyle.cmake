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
# The clang-format major version the style file is written for and CI checks with.
# scripts/build.py reads this line, so this is the one place to bump it.
set(CLANG_FORMAT_VERSION "14" CACHE STRING "clang-format major version required by the code style check")

set(check_code_style_script_ "${CMAKE_CURRENT_LIST_DIR}/../scripts/check_code_style.py")

if(${APPLY_CPP_CODE_STYLE} OR ${CHECK_CPP_CODE_STYLE})
    # Only major version CLANG_FORMAT_VERSION is accepted, under either the versioned or
    # the plain name (LLVM's Windows installer ships only clang-format.exe). The search
    # is repeated on every configure so a tool installed later, or a changed
    # CLANG_FORMAT_VERSION, is seen; a CLANG_FORMAT the user set (one that is not our
    # own last result) is kept as is.
    if(NOT CLANG_FORMAT OR CLANG_FORMAT STREQUAL "${CLANG_FORMAT_SEARCH_RESULT}")
        unset(CLANG_FORMAT CACHE)
        find_program(CLANG_FORMAT NAMES clang-format-${CLANG_FORMAT_VERSION} clang-format
                     DOC "Clang format executable (version ${CLANG_FORMAT_VERSION})")
        set(CLANG_FORMAT_SEARCH_RESULT "${CLANG_FORMAT}" CACHE INTERNAL "clang-format found by CodeStyle.cmake")
    endif()
    set(CLANG_FORMAT_PROBLEM "")
    if(CLANG_FORMAT)
        execute_process(COMMAND ${CLANG_FORMAT} --version OUTPUT_VARIABLE CLANG_FORMAT_VERSION_OUTPUT ERROR_QUIET)
        string(REGEX MATCH "clang-format version ([0-9]+)" CLANG_FORMAT_VERSION_MATCH "${CLANG_FORMAT_VERSION_OUTPUT}")
        if(NOT CMAKE_MATCH_1 STREQUAL "${CLANG_FORMAT_VERSION}")
            set(CLANG_FORMAT_PROBLEM "${CLANG_FORMAT} is clang-format ${CMAKE_MATCH_1}, not ${CLANG_FORMAT_VERSION}")
        endif()
    else()
        set(CLANG_FORMAT_PROBLEM "clang-format-${CLANG_FORMAT_VERSION} not found in PATH")
    endif()
    if(CLANG_FORMAT_PROBLEM)
        message(FATAL_ERROR "${CLANG_FORMAT_PROBLEM}. The C++ code style check needs clang-format ${CLANG_FORMAT_VERSION}: "
            "install clang-format-${CLANG_FORMAT_VERSION} (or a clang-format that reports that version), "
            "or set CHECK_CPP_CODE_STYLE and APPLY_CPP_CODE_STYLE to OFF.")
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

    # Skip the following things from clang-format
    #   * Files under the /external/ folder
    #   * Files that end with the ".def" extension
    #   * Files that start with "generated_"
    list(FILTER ${TARGET_SOURCE_FILES} EXCLUDE REGEX "/external/|.+\.def|generated_.+")
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
                    COMMAND "${PYTHON}" ${check_code_style_script_}
                    --sourcefile ${TARGET_SRC_FILES} --base ${CHECK_CPP_CODE_STYLE_BASE}
                    --binary "${CLANG_FORMAT}"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                    COMMENT "Check code style for ${TARGET}")
            add_dependencies(${TARGET} "${TARGET}CodeStyleCheck")
        endif()
    endif()
endfunction()
