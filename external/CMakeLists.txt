# Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved
#
# AMD internal use only.

# CMake for AMD extension ASIC info

cmake_minimum_required(VERSION 3.10.2)
add_library(AMDEXT INTERFACE)
target_include_directories(AMDEXT INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/amd_extensions")