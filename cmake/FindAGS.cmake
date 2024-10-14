# FindAGS
# -----------
#
# Find the AGS includes and library.
#
# This module is derived from the CMake FindZLIB.cmake module.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  AGS_FOUND           : True if AGS was found.
#  AGS_INCLUDE_DIR     : The location of the AGS header file.
#  AGS_LIBRARY_RELEASE : Location of the AGS library for release builds.
#  AGS_LIBRARY_DEBUG   : Location of the AGS library for debug builds.

# Find the build architecture.
set(AGS_ARCH "")
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(AGS_ARCH "x64")
else()
    message(WARNING "AGS support requires an x64 build.")
endif()

# Find the MSVC version.
set(AGS_MSVC_TOOLSET "")
if(${MSVC_TOOLSET_VERSION} EQUAL 141)
    set(AGS_MSVC_TOOLSET "2017")
elseif(${MSVC_TOOLSET_VERSION} EQUAL 142)
    set(AGS_MSVC_TOOLSET "2019")
elseif(${MSVC_TOOLSET_VERSION} EQUAL 143)
    set(AGS_MSVC_TOOLSET "2022")
else()
    message(WARNING "AGS support requires MSVC version 2017, 2019, or 2022.")
endif()

# If CMAKE_MSVC_RUNTIME_LIBRARY is set, use that to determine MSVC runtime. Otherwise default to /MD.
set(AGS_MSVC_RUNTIME "MD")
if(CMAKE_MSVC_RUNTIME_LIBRARY AND
    (("${CMAKE_MSVC_RUNTIME_LIBRARY}" STREQUAL "MultiThreaded") OR
     ("${CMAKE_MSVC_RUNTIME_LIBRARY}" STREQUAL "MultiThreadedDebug")))
    set(AGS_MSVC_RUNTIME "MT")
endif()

if(AGS_ARCH AND AGS_MSVC_TOOLSET AND AGS_MSVC_RUNTIME)

    set(AGS_SDK_DIR "${CMAKE_BINARY_DIR}/external/AGS_SDK")
    set(AGS_SDK_GIT "https://github.com/GPUOpen-LibrariesAndSDKs/AGS_SDK.git")
    set(AGS_SDK_COMMIT "f686755b60a18521eb2fe7b40d7b3e35125cf151") # Release 6.2.0
    
    message(STATUS "Fetching AGS_SDK files from ${AGS_SDK_GIT}")
    include(FetchContent)
    FetchContent_Declare(
      AGS_SDK
      GIT_REPOSITORY   ${AGS_SDK_GIT}
      GIT_TAG          ${AGS_SDK_COMMIT}
      SOURCE_DIR       ${AGS_SDK_DIR}
    )
    FetchContent_MakeAvailable(AGS_SDK)

    set(AGS_SEARCH_PATH "${AGS_SDK_DIR}/ags_lib")

    find_path(AGS_INCLUDE_DIR NAMES amd_ags.h PATHS ${AGS_SEARCH_PATH} PATH_SUFFIXES inc)
    mark_as_advanced(AGS_INCLUDE_DIR)

    set(AGS_LIBRARY_NAME "amd_ags_${AGS_ARCH}_${AGS_MSVC_TOOLSET}_${AGS_MSVC_RUNTIME}")
    
    # If cached library strings don't match, unset variables.
    if(AGS_LIBRARY_RELEASE AND NOT ${AGS_LIBRARY_RELEASE} MATCHES "${AGS_LIBRARY_NAME}")
        message("Current AGS_LIBRARY_RELEASE '${AGS_LIBRARY_RELEASE}' does not match required library name "
                "'${AGS_LIBRARY_NAME}'. Resetting AGS_LIBRARY_RELEASE.")
        unset(AGS_LIBRARY_RELEASE CACHE)
    endif()
    if(AGS_LIBRARY_DEBUG AND NOT ${AGS_LIBRARY_DEBUG} MATCHES "${AGS_LIBRARY_NAME}d")
        message("Current AGS_LIBRARY_DEBUG '${AGS_LIBRARY_DEBUG}' does not match required library name "
                "'${AGS_LIBRARY_NAME}d'. Resetting AGS_LIBRARY_DEBUG.")
        unset(AGS_LIBRARY_DEBUG CACHE)
    endif()
    
    find_library(AGS_LIBRARY_RELEASE NAMES ${AGS_LIBRARY_NAME} PATHS ${AGS_SEARCH_PATH} PATH_SUFFIXES lib)
    find_library(AGS_LIBRARY_DEBUG NAMES "${AGS_LIBRARY_NAME}d" PATHS ${AGS_SEARCH_PATH} PATH_SUFFIXES lib)
    
    include(FindPackageHandleStandardArgs)
    find_package_handle_standard_args(AGS REQUIRED_VARS AGS_LIBRARY_RELEASE AGS_LIBRARY_DEBUG AGS_INCLUDE_DIR)
    
endif()
