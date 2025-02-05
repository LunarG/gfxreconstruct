###############################################################################
# Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved
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
# Description: CMake code static analysis build directives
###############################################################################

cmake_minimum_required(VERSION 3.16)

if(NOT (${CMAKE_GENERATOR} MATCHES "^.*Makefiles$|^Ninja$"))
    if(NOT ("" STREQUAL "${CMAKE_CXX_CLANG_TIDY}"))
        find_program(CLANG_TIDY clang-tidy DOC "Clang tidy executable")
        # TODO(SWLGFXREC-37) For now just use some basic clang compile options.
        #       This will be changed in a future commit to get the clang tidy
        #       options from the current CMake compile options
        set(CLANG_TIDY_COMPILE_OPTIONS "-x c++")
    endif()
endif()

function(target_lint_build_directives TARGET)
    # CMake will run clang-tidy using JSON DB if the generator is Ninja or
    # *Makefiles and CMAKE_CXX_CLANG_TIDY is defined.
    # Add lint clang-tidy post build command for other generators if
    # CMAKE_CXX_CLANG_TIDY is defined.
    # This command uses the clang/gcc compliation flags.
    if(NOT (${CMAKE_GENERATOR} MATCHES "^.*Makefiles$|^Ninja$"))
        if(NOT ("" STREQUAL "${CMAKE_CXX_CLANG_TIDY}"))
            add_custom_command(TARGET ${TARGET} POST_BUILD
                COMMAND ${CLANG_TIDY}
                ARGS
                    ${CXX_CLANG_TIDY_ARGS}
                    $<SHELL_PATH:$<TARGET_PROPERTY:${TARGET},SOURCES>>
                    --
                    "${CLANG_TIDY_COMPILE_OPTIONS}"
                    -D\"$<JOIN:$<TARGET_PROPERTY:${TARGET},COMPILE_DEFINITIONS>," -D">\"
                    -I\"$<JOIN:$<SHELL_PATH:$<TARGET_PROPERTY:${TARGET},INCLUDE_DIRECTORIES>>," -I">\"
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                COMMAND_EXPAND_LISTS
                COMMENT "Run clang-tidy linter on ${TARGET} sources")
        endif()
    endif()
endfunction()
