###############################################################################
# Copyright (c) 2018-2020 LunarG, Inc.
# Copyright (c) 2020-2023 Advanced Micro Devices, Inc.
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
# Description: CMake script for layer target
###############################################################################

if (D3D12_SUPPORT)
    set (LINK_ARCH "x64")
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set (LINK_ARCH "x86")
    endif()
    add_subdirectory(d3d12_capture)
    add_subdirectory(d3d12)
    add_subdirectory(dxgi)
    if (${BUILD_LAUNCHER_AND_INTERCEPTOR})
        add_subdirectory(gfxrecon_interceptor)
    endif()

    if (${GFXRECON_AGS_SUPPORT_FINAL})
      add_subdirectory(ags_capture)
    endif()
endif()

add_library(VkLayer_gfxreconstruct SHARED "")

target_sources(VkLayer_gfxreconstruct
               PRIVATE
                   ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                   ${CMAKE_CURRENT_LIST_DIR}/trace_layer.h
                   ${CMAKE_CURRENT_LIST_DIR}/trace_layer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/encode/custom_layer_func_table.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_layer_func_table.h
                   $<$<BOOL:WIN32>:${CMAKE_CURRENT_LIST_DIR}/trace_layer.def>
                   $<$<BOOL:WIN32>:${CMAKE_SOURCE_DIR}/version.rc>
              )

target_include_directories(VkLayer_gfxreconstruct
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_SOURCE_DIR})

target_link_libraries(VkLayer_gfxreconstruct
                        gfxrecon_encode
                        gfxrecon_graphics
                        gfxrecon_format
                        gfxrecon_util
                        vulkan_registry
                        platform_specific
                        openxr_headers)

common_build_directives(VkLayer_gfxreconstruct)

# The json output file needs Unix "/" separators or Windows "\" separators
# On top of that, Windows separators actually need to be doubled because the json format uses backslash escapes
file(TO_NATIVE_PATH "./" RELATIVE_PATH_PREFIX)
string(REPLACE "\\" "\\\\" RELATIVE_PATH_PREFIX "${RELATIVE_PATH_PREFIX}")
include("GenerateLayerJson")

# Generate the Vulkan JSON file that will be generated into the build directory
GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json
        "${RELATIVE_PATH_PREFIX}"
        $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
        ${CMAKE_CURRENT_SOURCE_DIR}/json/VkLayer_gfxreconstruct.json.in
        $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json
        )

if (OPENXR_SUPPORT_ENABLED)
    # Generate the OpenXR JSON file that will be generated into the build directory
    GENERATE_LAYER_JSON_FILE(XrLayer_gfxreconstruct_json
            "${RELATIVE_PATH_PREFIX}"
            $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
            ${CMAKE_CURRENT_SOURCE_DIR}/json/XrLayer_gfxreconstruct.json.in
            $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/XrLayer_gfxreconstruct.json
            )
endif()

if(UNIX)
        # Generate a Vulkan JSON file that can be installed into system directories (w/o the "./" prefix in the library_path)
        set(RELATIVE_PATH_PREFIX "")
        GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json-staging
                "${RELATIVE_PATH_PREFIX}"
                $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
                ${CMAKE_CURRENT_SOURCE_DIR}/json/VkLayer_gfxreconstruct.json.in
                $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json
                )

if (OPENXR_SUPPORT_ENABLED)
        # Generate a OpenXR JSON file that can be installed into system directories (w/o the "./" prefix in the library_path)
        set(RELATIVE_PATH_PREFIX "")
        GENERATE_LAYER_JSON_FILE(XrLayer_gfxreconstruct_json-staging
                "${RELATIVE_PATH_PREFIX}"
                $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
                ${CMAKE_CURRENT_SOURCE_DIR}/json/XrLayer_gfxreconstruct.json.in
                $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/XrLayer_gfxreconstruct.json
                )
endif()
endif()

install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
if (UNIX)
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/vulkan/explicit_layer.d)
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/XrLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/openxr/1/api_layers/explicit_layer.d)
else()
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_BINDIR})
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/XrLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

if (${RUN_TESTS})
    add_executable(VkLayer_gfxreconstruct_test "")

    target_sources(VkLayer_gfxreconstruct_test PRIVATE
            ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp
            ${CMAKE_CURRENT_LIST_DIR}/../tools/platform_debug_helper.cpp)
    target_link_libraries(VkLayer_gfxreconstruct_test PRIVATE VkLayer_gfxreconstruct)
    if (MSVC)
        # Force inclusion of "gfxrecon_disable_popup_result" variable in linking.
        # On 32-bit windows, MSVC prefixes symbols with "_" but on 64-bit windows it doesn't.
        if(CMAKE_SIZEOF_VOID_P EQUAL 4)
            target_link_options(VkLayer_gfxreconstruct_test PUBLIC "LINKER:/Include:_gfxrecon_disable_popup_result")
        else()
            target_link_options(VkLayer_gfxreconstruct_test PUBLIC "LINKER:/Include:gfxrecon_disable_popup_result")
        endif()
    endif()
    common_build_directives(VkLayer_gfxreconstruct_test)
    common_test_directives(VkLayer_gfxreconstruct_test)
endif()
