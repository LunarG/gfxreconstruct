# FindAGS
# -----------
#
# Find the AGS includes and library.
#
# This module defines the following variables:
#
#  AGS_FOUND           : True if AGS was found.
#  AGS_INCLUDE_DIR     : The location of the AGS header file.
#  AGS_LIBRARY_RELEASE : Location of the AGS library for release builds.
#  AGS_LIBRARY_DEBUG   : Location of the AGS library for debug builds.

function(FindAgsLibrary AGS_SEARCH_PATH AGS_LIBRARY_NAME AGS_LIBRARY_VAR)
    if(${AGS_LIBRARY_VAR})
        if(NOT EXISTS "${${AGS_LIBRARY_VAR}}")
            message("Current ${AGS_LIBRARY_VAR} '${${AGS_LIBRARY_VAR}}' does not exist. Resetting ${AGS_LIBRARY_VAR}.")
            unset(${AGS_LIBRARY_VAR} CACHE)
        elseif(NOT ${${AGS_LIBRARY_VAR}} MATCHES "${AGS_LIBRARY_NAME}")
            message("Current ${AGS_LIBRARY_VAR} '${${AGS_LIBRARY_VAR}}' does not match required library name "
                    "'${AGS_LIBRARY_NAME}'. Resetting ${AGS_LIBRARY_VAR}.")
            unset(${AGS_LIBRARY_VAR} CACHE)
        endif()
    endif()
    find_library(${AGS_LIBRARY_VAR} NAMES ${AGS_LIBRARY_NAME} PATHS ${AGS_SEARCH_PATH} PATH_SUFFIXES lib NO_DEFAULT_PATH)
endfunction()

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
    
    if(AGS_INCLUDE_DIR AND NOT EXISTS "${AGS_INCLUDE_DIR}/amd_ags.h")
        message("Current AGS_INCLUDE_DIR '${AGS_INCLUDE_DIR}' does not contain 'amd_ags.h'. Resetting AGS_INCLUDE_DIR.")
        unset(AGS_INCLUDE_DIR CACHE)
    endif()

    find_path(AGS_INCLUDE_DIR NAMES amd_ags.h PATHS ${AGS_SEARCH_PATH} PATH_SUFFIXES inc)
    mark_as_advanced(AGS_INCLUDE_DIR)

    set(AGS_LIBRARY_NAME_RELEASE "amd_ags_${AGS_ARCH}_${AGS_MSVC_TOOLSET}_${AGS_MSVC_RUNTIME}")
    set(AGS_LIBRARY_NAME_DEBUG "${AGS_LIBRARY_NAME_RELEASE}d")
    
    FindAgsLibrary(${AGS_SEARCH_PATH} ${AGS_LIBRARY_NAME_RELEASE} AGS_LIBRARY_RELEASE)
    FindAgsLibrary(${AGS_SEARCH_PATH} ${AGS_LIBRARY_NAME_DEBUG} AGS_LIBRARY_DEBUG)
    
    include(FindPackageHandleStandardArgs)
    find_package_handle_standard_args(AGS REQUIRED_VARS AGS_LIBRARY_RELEASE AGS_LIBRARY_DEBUG AGS_INCLUDE_DIR)
    
endif()
