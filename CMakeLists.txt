cmake_minimum_required(VERSION 3.1)
project(brimstone)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include("FindVulkanVersion")

add_library(windows_specific INTERFACE)
target_compile_definitions(windows_specific INTERFACE WIN32_LEAN_AND_MEAN NOMINMAX)

add_library(platform_specific INTERFACE)
target_link_libraries(platform_specific INTERFACE $<$<BOOL:${WIN32}>:windows_specific>)

add_library(vulkan_registry INTERFACE)
target_include_directories(vulkan_registry INTERFACE ${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include)

add_library(volk STATIC)
target_include_directories(volk PUBLIC ${CMAKE_SOURCE_DIR}/external/volk)
target_sources(volk PRIVATE ${CMAKE_SOURCE_DIR}/external/volk/volk.c)
target_compile_definitions(volk PUBLIC VK_NO_PROTOTYPES)
target_link_libraries(volk PUBLIC vulkan_registry $<$<NOT:$<BOOL:${WIN32}>>:dl>)

find_package(LZ4)
find_package(XCB)
find_package(WAYLAND)

add_subdirectory(util)
add_subdirectory(format)
add_subdirectory(generated)
add_subdirectory(layer)
add_subdirectory(application)
