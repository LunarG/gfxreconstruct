###############################################################################
# Copyright (c) 2018-2020,2023 LunarG, Inc.
# Copyright (c) 2018-2023 Advanced Micro Devices, Inc. All rights reserved
# All rights reserved
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
                    ${CMAKE_CURRENT_LIST_DIR}/date_time.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/defines.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_output_stream.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_output_stream.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/driver_info.h
                    ${CMAKE_CURRENT_LIST_DIR}/driver_info.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/file_path.h
                    ${CMAKE_CURRENT_LIST_DIR}/file_path.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/hash.h
                    ${CMAKE_CURRENT_LIST_DIR}/image_writer.h
                    ${CMAKE_CURRENT_LIST_DIR}/image_writer.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/json_util.h
                    ${CMAKE_CURRENT_LIST_DIR}/json_util.cpp
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
                    ${CMAKE_CURRENT_LIST_DIR}/monotonic_allocator.h
                    ${CMAKE_CURRENT_LIST_DIR}/monotonic_allocator.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/output_stream.h
                    ${CMAKE_CURRENT_LIST_DIR}/page_guard_manager.h
                    ${CMAKE_CURRENT_LIST_DIR}/page_guard_manager.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/page_guard_manager_uffd.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/page_status_tracker.h
                    ${CMAKE_CURRENT_LIST_DIR}/platform.h
                    ${CMAKE_CURRENT_LIST_DIR}/settings_loader.h
                    ${CMAKE_CURRENT_LIST_DIR}/settings_loader.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/options.h
                    ${CMAKE_CURRENT_LIST_DIR}/options.cpp
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/interception/hooking_detours.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/interception/hooking_detours.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/interception/interception_util.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/interception/interception_util.cpp>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/injection.h>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/injection.cpp>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/load_library.h>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/load_library.cpp>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/real_and_mine_hook.h>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/ref_tracker.cpp>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/ref_tracker.h>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/ref_tracker_counter.cpp>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/ref_tracker_counter.h>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/create_process.cpp>
                    $<$<BOOL:${BUILD_LAUNCHER_AND_INTERCEPTOR}>:${CMAKE_CURRENT_LIST_DIR}/interception/create_process.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/gpu_va_map.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/gpu_va_map.cpp>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/gpu_va_range.h>
                    $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/gpu_va_range.cpp>
                    ${CMAKE_CURRENT_LIST_DIR}/strings.h
                    ${CMAKE_CURRENT_LIST_DIR}/strings.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/to_string.h
                    ${CMAKE_CURRENT_LIST_DIR}/to_string.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/options.h
                    ${CMAKE_CURRENT_LIST_DIR}/options.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/custom_common_to_string.h
                    ${CMAKE_CURRENT_LIST_DIR}/custom_common_to_string.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_enum_to_string.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_enum_to_string.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_openxr_type_util.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_enum_to_string.h
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_enum_to_string.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_stype_util.h
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_loader.h>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_loader.cpp>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_keysyms_loader.h>
                    $<$<BOOL:${XCB_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xcb_keysyms_loader.cpp>
                    $<$<BOOL:${X11_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xlib_loader.h>
                    $<$<BOOL:${X11_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/xlib_loader.cpp>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_loader.h>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_CURRENT_LIST_DIR}/wayland_loader.cpp>
                    $<$<BOOL:${WAYLAND_FOUND}>:${CMAKE_SOURCE_DIR}/framework/generated/generated_wayland_xdg_shell.h>
)


target_include_directories(gfxrecon_util
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework
                               $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_SOURCE_DIR}/external/AgilitySDK/inc>)
target_link_libraries(gfxrecon_util platform_specific vulkan_registry nlohmann_json::nlohmann_json ${CMAKE_DL_LIBS})
target_link_libraries(gfxrecon_util $<$<BOOL:${WIN32}>:version.lib>)

if (UNIX AND NOT APPLE)
    # Check for clock_gettime in libc
    include(CheckLibraryExists)
    check_library_exists(c clock_gettime "" HAVE_GETTIME)
    target_link_libraries(gfxrecon_util pthread)
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

if (APPLE)
    find_library(COREGRAPHICS_LIBRARY CoreGraphics)
    target_link_libraries(gfxrecon_util ${COREGRAPHICS_LIBRARY})
endif()

if (XCB_LIBRARY)
    target_compile_definitions(gfxrecon_util PUBLIC "XCB_LIBRARY=\"${XCB_LIBRARY}\"")
endif()

if (XCB_KEYSYMS_LIBRARY)
    target_compile_definitions(gfxrecon_util PUBLIC "XCB_KEYSYMS_LIBRARY=\"${XCB_KEYSYMS_LIBRARY}\"")
endif()

if (X11_XCB_LIBRARY)
    target_compile_definitions(gfxrecon_util PUBLIC "X11_XCB_LIBRARY=\"${X11_XCB_LIBRARY}\"")
endif()

if (X11_LIBRARY)
    target_compile_definitions(gfxrecon_util PUBLIC "X11_LIBRARY=\"${X11_LIBRARY}\"")
endif()

if (WAYLAND_LIBRARY)
    target_compile_definitions(gfxrecon_util PUBLIC "WAYLAND_LIBRARY=\"${WAYLAND_LIBRARY}\"")
endif()

if (${GFXRECON_AGS_SUPPORT_FINAL})
    target_link_libraries(gfxrecon_util AGS::AGS)
endif()

if (TARGET Detours::Detours)
    target_compile_definitions(gfxrecon_util PUBLIC ENABLE_DETOURS)
    target_link_libraries(gfxrecon_util Detours::Detours)
endif()

if (TARGET LZ4::LZ4)
    target_compile_definitions(gfxrecon_util PUBLIC GFXRECON_ENABLE_LZ4_COMPRESSION)
    target_link_libraries(gfxrecon_util LZ4::LZ4)
endif()

if (TARGET ZLIB::ZLIB)
    target_compile_definitions(gfxrecon_util
                               PUBLIC
                                   GFXRECON_ENABLE_ZLIB_COMPRESSION
                                   GFXRECON_ENABLE_PNG_SCREENSHOT
                                   $<$<BOOL:${WIN32}>:ZLIB_WINAPI>)
    target_link_libraries(gfxrecon_util ZLIB::ZLIB)

    target_include_directories(gfxrecon_util
                               SYSTEM PUBLIC
                                   ${CMAKE_SOURCE_DIR}/external/stb)
endif()

if (TARGET ZSTD::ZSTD)
    target_compile_definitions(gfxrecon_util PUBLIC GFXRECON_ENABLE_ZSTD_COMPRESSION)
    target_link_libraries(gfxrecon_util ZSTD::ZSTD)
endif()

if (OPENXR_SUPPORT_ENABLED)
    target_include_directories(gfxrecon_util PUBLIC ${CMAKE_SOURCE_DIR}/external/OpenXR-SDK/include)
    target_compile_definitions(gfxrecon_util PUBLIC ENABLE_OPENXR_SUPPORT=1)
endif()

common_build_directives(gfxrecon_util)

if (${RUN_TESTS})
    add_executable(gfxrecon_util_test "")
    target_sources(gfxrecon_util_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
            ${CMAKE_CURRENT_LIST_DIR}/../../tools/platform_debug_helper.cpp
            $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/test/dx_pointers.h>
            $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/test/dx12_utils.cpp>
            $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/test/gpu_va_map_tests.cpp>
            $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/test/getwritewatch_tests.cpp>
            $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/test/dx12_utils.h>
            $<$<BOOL:${D3D12_SUPPORT}>:${CMAKE_CURRENT_LIST_DIR}/test/dxgi_pointers.h>)
    target_link_libraries(gfxrecon_util_test
                        PRIVATE
                            gfxrecon_util
                            $<$<BOOL:${D3D12_SUPPORT}>:d3d12.lib>
                            $<$<BOOL:${D3D12_SUPPORT}>:dxgi.lib>)
    if (MSVC)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(gfxrecon_util_test PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(gfxrecon_util_test PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(gfxrecon_util_test)
    common_test_directives(gfxrecon_util_test)
endif()
