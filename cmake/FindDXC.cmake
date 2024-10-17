# FindDXC
# -----------
#
# Find the DXC includes and library.
#
# This module defines the following variables:
#
#  DXC_FOUND        : True if DXC was found.
#  DXC_INCLUDE_DIR  : The location of the DXC header file.
#  DXC_LIBRARY_PATH : Location of the DXC library.

if (${D3D12_SUPPORT})

    # Find the build architecture.
    set(DXC_ARCH "")
    if(CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64")
        set(DXC_ARCH "arm64")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(DXC_ARCH "x64")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(DXC_ARCH "x86")
    endif()

    if(DXC_ARCH)

        set(DXC_SDK_DIR "${CMAKE_SOURCE_DIR}/external/dxc")

        find_path(DXC_INCLUDE_DIR NAMES "dxcapi.h" PATHS "${DXC_SDK_DIR}/inc")
        mark_as_advanced(DXC_INCLUDE_DIR)

        # If cached library strings don't match, unset variables.
        if(DXC_LIBRARY_PATH AND NOT ${DXC_LIBRARY_PATH} MATCHES "${DXC_ARCH}")
            message("Current DXC_LIBRARY_PATH '${DXC_LIBRARY_PATH}' does not match required library architecture "
                    "'${DXC_ARCH}'. Resetting DXC_LIBRARY_PATH.")
            unset(DXC_LIBRARY_PATH CACHE)
        endif()
        
        find_library(DXC_LIBRARY_PATH NAMES "dxcompiler.lib" PATHS "${DXC_SDK_DIR}/lib/${DXC_ARCH}")
        
    endif()

    include(FindPackageHandleStandardArgs)
    find_package_handle_standard_args(DXC REQUIRED_VARS DXC_LIBRARY_PATH DXC_INCLUDE_DIR)

endif() # D3D12_SUPPORT
