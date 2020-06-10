###############################################################################
# Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved
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

cmake_minimum_required(VERSION 3.4.1)

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
