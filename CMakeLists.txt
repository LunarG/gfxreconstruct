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

cmake_minimum_required(VERSION 3.4.1)
project(GFXReconstruct)

set_property(GLOBAL PROPERTY TEST_SCRIPT ${CMAKE_ROOT})

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" "${CMAKE_SOURCE_DIR}/external/cmake-modules")

# Version info
set(GFXRECONSTRUCT_PROJECT_VERSION_MAJOR 0)
set(GFXRECONSTRUCT_PROJECT_VERSION_MINOR 9)
set(GFXRECONSTRUCT_PROJECT_VERSION_PATCH 2)

set(GFXRECON_PROJECT_VERSION_DESIGNATION "-unknown")
set(GFXRECON_PROJECT_VERSION_SHA1 "unknown-build-source")

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
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
    else()
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "-dev")
    endif()
elseif(GIT_TAG)
    string(REGEX MATCH "^v[0-9]+\.[0-9]+\.[0-9]+$" GIT_IS_VERSION_RELEASE_TAG ${GIT_TAG})
    if (GIT_IS_VERSION_RELEASE_TAG)
        set(GIT_BRANCH ${GIT_TAG})
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
    endif()
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

# Code checks
include("CodeStyle")
include("Test")
include("Lint")
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
endif(MSVC)

# GFXReconstruct provided find modules
find_package(LZ4)
find_package(ZSTD)
if(UNIX)
    find_package(XCB)
    find_package(WAYLAND)
endif(UNIX)

# CMake provided find modules
find_package(ZLIB)
if(UNIX)
    find_package(X11)
endif(UNIX)

add_library(windows_specific INTERFACE)
target_compile_definitions(windows_specific INTERFACE WIN32_LEAN_AND_MEAN NOMINMAX VK_USE_PLATFORM_WIN32_KHR)
target_compile_options(windows_specific INTERFACE /WX)

add_library(linux_specific INTERFACE)
target_compile_definitions(linux_specific INTERFACE _FILE_OFFSET_BITS=64 PAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION
    $<$<BOOL:${X11_FOUND}>:VK_USE_PLATFORM_XLIB_KHR>
    $<$<BOOL:${X11_Xrandr_FOUND}>:VK_USE_PLATFORM_XLIB_XRANDR_EXT>
    $<$<BOOL:${XCB_FOUND}>:VK_USE_PLATFORM_XCB_KHR>
    $<$<BOOL:${WAYLAND_FOUND}>:VK_USE_PLATFORM_WAYLAND_KHR>)
target_compile_options(linux_specific INTERFACE -Werror)

add_library(platform_specific INTERFACE)
target_link_libraries(platform_specific INTERFACE
    $<$<BOOL:${WIN32}>:windows_specific>
    $<$<NOT:$<BOOL:${WIN32}>>:linux_specific>)

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
add_subdirectory(layer)
add_subdirectory(tools)

if (${RUN_TESTS})
    add_test_package_file(${CMAKE_CURRENT_LIST_DIR}/scripts/build.py)
    add_test_package_file(${CMAKE_CURRENT_LIST_DIR}/scripts/test.py)
    generate_test_package(gfx_reconstruct_test)
endif()
