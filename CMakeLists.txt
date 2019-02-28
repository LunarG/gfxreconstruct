cmake_minimum_required(VERSION 3.1)
project(GFXReconstruct)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include("FindVulkanVersion")

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

add_library(linux_specific INTERFACE)
target_compile_definitions(linux_specific INTERFACE _FILE_OFFSET_BITS=64 PAGE_GUARD_ENABLE_X86_64_UCONTEXT
    $<$<BOOL:${X11_FOUND}>:VK_USE_PLATFORM_XLIB_KHR>
    $<$<BOOL:${X11_Xrandr_FOUND}>:VK_USE_PLATFORM_XLIB_XRANDR_EXT>
    $<$<BOOL:${XCB_FOUND}>:VK_USE_PLATFORM_XCB_KHR>
    $<$<BOOL:${WAYLAND_FOUND}>:VK_USE_PLATFORM_WAYLAND_KHR>)

add_library(platform_specific INTERFACE)
target_link_libraries(platform_specific INTERFACE
    $<$<BOOL:${WIN32}>:windows_specific>
    $<$<NOT:$<BOOL:${WIN32}>>:linux_specific>)

add_library(vulkan_registry INTERFACE)
target_include_directories(vulkan_registry INTERFACE ${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include)

add_library(volk STATIC "")
target_include_directories(volk PUBLIC ${CMAKE_SOURCE_DIR}/external/volk)
target_sources(volk PRIVATE ${CMAKE_SOURCE_DIR}/external/volk/volk.c)
target_compile_definitions(volk PUBLIC VK_NO_PROTOTYPES)
target_link_libraries(volk PUBLIC vulkan_registry platform_specific $<$<NOT:$<BOOL:${WIN32}>>:dl>)

add_subdirectory(framework)
add_subdirectory(layer)
add_subdirectory(tools)
