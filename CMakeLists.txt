cmake_minimum_required(VERSION 3.0)
project(brimstone)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(util)
add_subdirectory(format)
add_subdirectory(generated)
add_subdirectory(layer)
add_subdirectory(application)
