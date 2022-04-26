###############################################################################
# Copyright (c) 2018-2022 LunarG, Inc.
# Copyright (c) 2019-2020 Advanced Micro Devices, Inc.
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

cmake_minimum_required(VERSION 3.10.2)
project(GFXReconstruct)

set_property(GLOBAL PROPERTY TEST_SCRIPT ${CMAKE_ROOT})

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" "${CMAKE_SOURCE_DIR}/external/cmake-modules")

# Version info
set(GFXRECONSTRUCT_PROJECT_VERSION_MAJOR 0)
set(GFXRECONSTRUCT_PROJECT_VERSION_MINOR 9)
set(GFXRECONSTRUCT_PROJECT_VERSION_PATCH 14)

set(GFXRECON_PROJECT_VERSION_SHA1 "unknown-build-source")

option(BUILD_STATIC "Build static binaries for HPC clusters (will not build the tracer library)" OFF)

if (NOT DEFINED HEADLESS)
    set(HEADLESS TRUE)
endif()

include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
git_get_exact_tag(GIT_TAG)
set(GIT_BRANCH "")

if (GIT_REFSPEC)
    string(REGEX REPLACE ".*/(.+)$" "\\1" GIT_BRANCH ${GIT_REFSPEC})
    string(COMPARE EQUAL ${GIT_BRANCH} "master" GIT_IS_MASTER)
    string(REGEX MATCH "^sdk-[0-9]+\.[0-9]+\.[0-9]+$" GIT_IS_SDK ${GIT_BRANCH})

    if (GIT_IS_MASTER OR GIT_IS_SDK)
        if (GIT_TAG)
            set(GIT_BRANCH ${GIT_TAG})
        else()
            set(GIT_BRANCH "")
        endif()
        if(NOT DEFINED GFXRECON_PROJECT_VERSION_DESIGNATION)
            set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
        endif()
    elseif(NOT DEFINED GFXRECON_PROJECT_VERSION_DESIGNATION)
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "-dev")
    endif()
elseif(GIT_TAG)
    string(REGEX MATCH "^v[0-9]+\.[0-9]+\.[0-9]+$" GIT_IS_VERSION_RELEASE_TAG ${GIT_TAG})
    if (GIT_IS_VERSION_RELEASE_TAG)
        set(GIT_BRANCH ${GIT_TAG})
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
    endif()
elseif(NOT DEFINED GFXRECON_PROJECT_VERSION_DESIGNATION)
    set(GFXRECON_PROJECT_VERSION_DESIGNATION "-unknown")
endif()

if (GIT_SHA1)
    string(SUBSTRING ${GIT_SHA1} 0 7 GFXRECON_PROJECT_VERSION_SHA1)

    if (GIT_BRANCH)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GIT_BRANCH} ":" ${GFXRECON_PROJECT_VERSION_SHA1})
    endif()

    git_local_changes(GIT_LOCAL_STATE)
    string(COMPARE EQUAL ${GIT_LOCAL_STATE} "DIRTY" GIT_DIRTY)
    if (GIT_DIRTY)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GFXRECON_PROJECT_VERSION_SHA1} "*")
    endif()
endif()

configure_file("${CMAKE_SOURCE_DIR}/project_version.h.in" "${CMAKE_BINARY_DIR}/project_version.h")

option(BUILD_WERROR "Build with warnings as errors" ON)

# Code checks
include("CodeStyle")
include("Lint")
include("Test")
include("FindVulkanVersion")

# Apply misc build directives to the given target
macro(common_build_directives TARGET)
    target_code_style_build_directives(${TARGET})
    target_lint_build_directives(${TARGET})
    add_target_to_test_package(${TARGET})
endmacro()

if(MSVC)
    # Default to using the precompiled LZ4 and ZLIB binaries for VisualStudio builds.
    set (PRECOMPILED_ARCH "64")
    if(NOT CMAKE_CL_64)
        set (PRECOMPILED_ARCH "32")
    endif(NOT CMAKE_CL_64)
    set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH}
       "${CMAKE_SOURCE_DIR}/external/precompiled/win${PRECOMPILED_ARCH}"
       "${CMAKE_SOURCE_DIR}/external/precompiled/win${PRECOMPILED_ARCH}")

    # Enable LARGEADDRESSAWARE to increase memory address space for 32-bit executables
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /LARGEADDRESSAWARE")
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "aarch64")
    set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH}
       "${CMAKE_SOURCE_DIR}/external/precompiled/linux/lib/arm64-v8a")
elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm")
    set(CMAKE_PREFIX_PATH
        ${CMAKE_PREFIX_PATH}
       "${CMAKE_SOURCE_DIR}/external/precompiled/linux/lib/arm")
endif()

# GFXReconstruct provided find modules
find_package(LZ4)
find_package(ZSTD)
if(UNIX)
    option(BUILD_WSI_XCB_SUPPORT "Build XCB WSI support" ON)
    option(BUILD_WSI_WAYLAND_SUPPORT "Build Wayland WSI support" ON)
    option(BUILD_WSI_DISPLAY_SUPPORT "Build direct-to-display swapchain support" ON)

    if(BUILD_WSI_XCB_SUPPORT)
        find_package(XCB)
    endif()

    if(BUILD_WSI_WAYLAND_SUPPORT)
        find_package(WAYLAND)
    endif()
endif(UNIX)

# CMake provided find modules
if(BUILD_STATIC)
    find_library(ZLIB NAMES libz.a REQUIRED PATH_SUFFIXES lib lib/x86_64-linux-gnu lib64)
else()
    find_package(ZLIB)
endif()
if(UNIX)
    option(BUILD_WSI_XLIB_SUPPORT "Build Xlib WSI support" ON)
    if(BUILD_WSI_XLIB_SUPPORT)
        find_package(X11)
    endif()
endif(UNIX)

add_library(windows_specific INTERFACE)
target_compile_definitions(windows_specific INTERFACE WIN32_LEAN_AND_MEAN NOMINMAX VK_USE_PLATFORM_WIN32_KHR
$<$<BOOL:${HEADLESS}>:VK_USE_PLATFORM_HEADLESS>)

add_library(linux_specific INTERFACE)
target_compile_definitions(linux_specific INTERFACE _FILE_OFFSET_BITS=64 PAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION
    $<$<BOOL:${X11_FOUND}>:VK_USE_PLATFORM_XLIB_KHR>
    $<$<BOOL:${X11_Xrandr_FOUND}>:VK_USE_PLATFORM_XLIB_XRANDR_EXT>
    $<$<BOOL:${XCB_FOUND}>:VK_USE_PLATFORM_XCB_KHR>
    $<$<BOOL:${WAYLAND_FOUND}>:VK_USE_PLATFORM_WAYLAND_KHR>
    $<$<BOOL:${BUILD_WSI_DISPLAY_SUPPORT}>:VK_USE_PLATFORM_DISPLAY_KHR>
    $<$<BOOL:${HEADLESS}>:VK_USE_PLATFORM_HEADLESS>)

add_library(macos_specific INTERFACE)
target_compile_definitions(macos_specific INTERFACE _FILE_OFFSET_BITS=64 PAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION
    $<$<BOOL:${BUILD_WSI_DISPLAY_SUPPORT}>:VK_USE_PLATFORM_DISPLAY_KHR>
    $<$<BOOL:${HEADLESS}>:VK_USE_PLATFORM_HEADLESS>)

add_library(platform_specific INTERFACE)
target_link_libraries(platform_specific INTERFACE
    $<$<BOOL:${WIN32}>:windows_specific>
    $<STREQUAL:${CMAKE_SYSTEM_NAME},Darwin>:macos_specific>
    $<STREQUAL:${CMAKE_SYSTEM_NAME},Linux>:linux_specific>)

if(BUILD_WERROR)
    if(MSVC)
        target_compile_options(platform_specific INTERFACE /WX)
    else()
        target_compile_options(platform_specific INTERFACE -Werror)
    endif()
endif()

add_library(vulkan_registry INTERFACE)
target_include_directories(vulkan_registry INTERFACE ${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include)
target_compile_definitions(vulkan_registry INTERFACE VK_NO_PROTOTYPES VK_ENABLE_BETA_EXTENSIONS)

add_library(vulkan_memory_allocator INTERFACE)
target_include_directories(vulkan_memory_allocator INTERFACE ${CMAKE_SOURCE_DIR}/external/VulkanMemoryAllocator/include)

if (${RUN_TESTS})
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE external)
endif()

add_subdirectory(framework)
if(NOT BUILD_STATIC)
    add_subdirectory(layer)
endif()
add_subdirectory(tools)

if (${RUN_TESTS})
    add_test_package_file(${CMAKE_CURRENT_LIST_DIR}/scripts/build.py)
    add_test_package_file(${CMAKE_CURRENT_LIST_DIR}/scripts/test.py)
    generate_test_package(gfx_reconstruct_test)
endif()
