###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2019-2020 Advanced Micro Devices, Inc.
# All rights reserved
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
# Author: LunarG Team
# Author: AMD Developer Tools Team
# Description: CMake script for framework util target
###############################################################################

add_library(gfxrecon_util STATIC "")

target_sources(gfxrecon_util
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/argument_parser.h
                    ${CMAKE_CURRENT_LIST_DIR}/argument_parser.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/compressor.h
                    ${CMAKE_CURRENT_LIST_DIR}/date_time.h
                    ${CMAKE_CURRENT_LIST_DIR}/defines.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_output_stream.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_output_stream.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/file_path.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_path.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/hash.h
                    ${CMAKE_CURRENT_LIST_DIR}/hash.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/keyboard.h
                    ${CMAKE_CURRENT_LIST_DIR}/keyboard.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/logging.h
                    ${CMAKE_CURRENT_LIST_DIR}/logging.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/lz4_compressor.h
                    ${CMAKE_CURRENT_LIST_DIR}/lz4_compressor.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/zlib_compressor.h
                    ${CMAKE_CURRENT_LIST_DIR}/zlib_compressor.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/zstd_compressor.h
                    ${CMAKE_CURRENT_LIST_DIR}/zstd_compressor.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/memory_output_stream.h
                    ${CMAKE_CURRENT_LIST_DIR}/memory_output_stream.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/output_stream.h
                    ${CMAKE_CURRENT_LIST_DIR}/page_guard_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/page_guard_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/page_status_tracker.h
                    ${CMAKE_CURRENT_LIST_DIR}/platform.h
                    ${CMAKE_CURRENT_LIST_DIR}/settings_loader.h
                    ${CMAKE_CURRENT_LIST_DIR}/settings_loader.cpp
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_loader.h>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_loader.cpp>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_keysyms_loader.h>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_keysyms_loader.cpp>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_loader.h>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_loader.cpp>
)

target_include_directories(gfxrecon_util
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_util platform_specific ${CMAKE_DL_LIBS})

if (UNIX AND NOT APPLE)
    # Check for clock_gettime in libc
    include(CheckLibraryExists)
    check_library_exists(c clock_gettime "" HAVE_GETTIME)
    if (NOT HAVE_GETTIME)
        # If not in libc, check librt
        check_library_exists(rt clock_gettime "" HAVE_GETTIME)
        if (HAVE_GETTIME)
            target_link_libraries(gfxrecon_util rt)
        else()
            message(WARNING "Function clock_gettime not found in either libc or librt")
        endif()
    endif()
endif()

if (TARGET LZ4::LZ4)
    target_compile_definitions(gfxrecon_util PUBLIC ENABLE_LZ4_COMPRESSION)
    target_link_libraries(gfxrecon_util LZ4::LZ4)
endif()

if (TARGET ZLIB::ZLIB)
    target_compile_definitions(gfxrecon_util
                               PUBLIC
                                   ENABLE_ZLIB_COMPRESSION
                                   $<$<BOOL:${WIN32}>:ZLIB_WINAPI>)
    target_link_libraries(gfxrecon_util ZLIB::ZLIB)
endif()

if (TARGET ZSTD::ZSTD)
    target_compile_definitions(gfxrecon_util PUBLIC ENABLE_ZSTD_COMPRESSION)
    target_link_libraries(gfxrecon_util ZSTD::ZSTD)
endif()

common_build_directives(gfxrecon_util)

if (${RUN_TESTS})
    add_executable(gfxrecon_util_test "")
    target_sources(gfxrecon_util_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)
    common_build_directives(gfxrecon_util_test)
    common_test_directives(gfxrecon_util_test)
endif()
