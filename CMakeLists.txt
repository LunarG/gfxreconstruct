cmake_minimum_required(VERSION 2.8)
project(brimstone)

# For vulkan.h
include_directories(${CMAKE_SOURCE_DIR}/external/Vulkan-Docs/src ${CMAKE_SOURCE_DIR}/external/Vulkan-Docs/src/vulkan ${CMAKE_SOURCE_DIR})

add_subdirectory(util)
add_subdirectory(format)
add_subdirectory(generated)
add_subdirectory(layer)
