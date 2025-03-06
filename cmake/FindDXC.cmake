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
#  DXC_DLL_PATH     : Location of the DXC DLL.

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
    
        set(DXC_SDK_DIR "${CMAKE_BINARY_DIR}/external/DXC")
        set(DXC_SDK_URL "https://github.com/microsoft/DirectXShaderCompiler/releases/download/v1.8.2407/dxc_2024_07_31.zip")
        
        # Suppress warning on newer versions of CMake related to FetchContent file timestamp behavior.
        if (${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.24")
            cmake_policy(SET CMP0135 NEW)
        endif()

        message(STATUS "Fetching DXC files from ${DXC_SDK_URL}")
        include(FetchContent)
        FetchContent_Declare(
          DXC_SDK
          URL        ${DXC_SDK_URL}
          SOURCE_DIR ${DXC_SDK_DIR}
        )
        FetchContent_MakeAvailable(DXC_SDK)
        
        if(DEFINED CACHE{DXC_INCLUDE_DIR} AND NOT EXISTS "${DXC_INCLUDE_DIR}/dxcapi.h")
            message("Current DXC_INCLUDE_DIR '${DXC_INCLUDE_DIR}' does not contain 'dxcapi.h'. Resetting DXC_INCLUDE_DIR.")
            unset(DXC_INCLUDE_DIR CACHE)
        endif()
        find_path(DXC_INCLUDE_DIR NAME "dxcapi.h" PATHS "${DXC_SDK_DIR}/inc" NO_DEFAULT_PATH)
        mark_as_advanced(DXC_INCLUDE_DIR)

        # If the cached library path doesn't exist or arch doesn't match, unset variable.
        if(DEFINED CACHE{DXC_LIBRARY_PATH} AND NOT EXISTS "${DXC_LIBRARY_PATH}")
            message("Current DXC_LIBRARY_PATH '${DXC_LIBRARY_PATH}' does not exist. Resetting DXC_LIBRARY_PATH.")
            unset(DXC_LIBRARY_PATH CACHE) 
        endif()
        find_library(DXC_LIBRARY_PATH NAME "dxcompiler.lib" PATHS "${DXC_SDK_DIR}/lib/${DXC_ARCH}" NO_DEFAULT_PATH)
        mark_as_advanced(DXC_LIBRARY_PATH)
        
        # If the cached DLL path doesn't exist or arch doesn't match, unset variable.
        if(DEFINED CACHE{DXC_DLL_PATH} AND NOT EXISTS "${DXC_DLL_PATH}")
            message("Current DXC_DLL_PATH '${DXC_DLL_PATH}' does not exist. Resetting DXC_DLL_PATH.")
            unset(DXC_DLL_PATH CACHE) 
        endif()
        find_file(DXC_DLL_PATH NAME "dxcompiler.dll" PATHS "${DXC_SDK_DIR}/bin/${DXC_ARCH}" NO_DEFAULT_PATH)
        mark_as_advanced(DXC_DLL_PATH)
        
    endif()

    include(FindPackageHandleStandardArgs)
    find_package_handle_standard_args(DXC REQUIRED_VARS DXC_LIBRARY_PATH DXC_DLL_PATH DXC_INCLUDE_DIR)

endif() # D3D12_SUPPORT
