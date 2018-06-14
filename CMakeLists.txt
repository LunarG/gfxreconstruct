cmake_minimum_required(VERSION 2.8)
project(brimstone)

# For vulkan.h
include_directories(${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include ${CMAKE_SOURCE_DIR})

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(util)
add_subdirectory(format)
add_subdirectory(generated)
add_subdirectory(layer)
