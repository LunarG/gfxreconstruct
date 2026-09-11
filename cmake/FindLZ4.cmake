# FindLZ4
# -------
#
# Find the LZ4 includes and library.
#
# This module is derived from the CMake FindZLIB.cmake module.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``LZ4::LZ4``, if LZ4 has been found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  LZ4_FOUND        : True if LZ4 was found.
#  LZ4_INCLUDE_DIRS : The locatio of the LZ4 header files.
#  LZ4_LIBRARIES    : List of the LZ4 libraries.
#
# Hints
# ^^^^^
#
# The ``LZ4_ROOT`` value may be set to tell this module where to look.
if(TARGET LZ4::LZ4)
    set(LZ4_FOUND TRUE)
    return()
endif()

option(GFXRECON_COMPRESSION_FROM_SOURCE
       "Build LZ4, zstd, and zlib from pinned upstream sources instead of searching for installed libraries"
       ON)

set(GFXRECON_LZ4_REPOSITORY "https://github.com/lz4/lz4.git")
set(GFXRECON_LZ4_VERSION    "1.10.0")
set(GFXRECON_LZ4_TAG        "ebb370ca83af193212df4dcbadcc5d87bc0de2f0")

if(GFXRECON_COMPRESSION_FROM_SOURCE)
    include(FetchContent)

    set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

    set(LZ4_BUILD_CLI OFF)

    message(STATUS "Building LZ4 ${GFXRECON_LZ4_VERSION} from source (${GFXRECON_LZ4_REPOSITORY})")
    FetchContent_Declare(lz4
                         GIT_REPOSITORY ${GFXRECON_LZ4_REPOSITORY}
                         GIT_TAG        ${GFXRECON_LZ4_TAG}
                         SOURCE_SUBDIR  build/cmake)
    FetchContent_MakeAvailable(lz4)

    if(NOT TARGET lz4_static)
        message(FATAL_ERROR
                "LZ4 was fetched but the expected 'lz4_static' target was not created. The upstream "
                "CMake configuration may have changed; see cmake/FindLZ4.cmake.")
    endif()

    add_library(LZ4::LZ4 ALIAS lz4_static)

    set(LZ4_FOUND TRUE)
    set(LZ4_VERSION "${GFXRECON_LZ4_VERSION}")
    set(LZ4_LIBRARIES LZ4::LZ4)
    set(LZ4_INCLUDE_DIRS "${lz4_SOURCE_DIR}/lib")

    return()
endif()

set(_LZ4_SEARCH_PATH)

if (LZ4_ROOT)
    set(_LZ4_SEARCH_ROOT PATHS ${LZ4_ROOT} NO_DEFAULT_PATH)
    list(APPEND _LZ4_SEARCH_PATH _LZ4_SEARCH_ROOT)
endif()

# Normal search.
set(_LZ4_x86 "(x86)")
set(_LZ4_SEARCH_NORMAL
    PATHS "$ENV{ProgramFiles}/lz4"
          "$ENV{ProgramFiles${_LZ4_x86}}/lz4")
unset(_LZ4_x86)
list(APPEND _LZ4_SEARCH_PATH _LZ4_SEARCH_NORMAL)

set(LZ4_NAMES lz4 lz4_static liblz4 liblz4_static)
if(BUILD_STATIC)
    set(LZ4_NAMES liblz4.a ${LZ4_NAMES})
endif()
set(LZ4_NAMES_DEBUG lz4d lz4_staticd liblz4d liblz4_staticd)

foreach(search ${_LZ4_SEARCH_PATH})
    find_path(LZ4_INCLUDE_DIR NAMES lz4.h ${${search}} PATH_SUFFIXES include)
endforeach()

# Allow LZ4_LIBRARY to be set manually, as the location of the lz4 library
if(NOT LZ4_LIBRARY)
    foreach(search ${_LZ4_SEARCH_PATH})
        find_library(LZ4_LIBRARY_RELEASE NAMES ${LZ4_NAMES} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
        find_library(LZ4_LIBRARY_DEBUG NAMES ${LZ4_NAMES_DEBUG} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
    endforeach()

    include(SelectLibraryConfigurations)
    select_library_configurations(LZ4)
endif()

unset(LZ4_NAMES)
unset(LZ4_NAMES_DEBUG)

mark_as_advanced(LZ4_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(LZ4 REQUIRED_VARS LZ4_LIBRARY LZ4_INCLUDE_DIR)

if(LZ4_FOUND)
    set(LZ4_INCLUDE_DIRS ${LZ4_INCLUDE_DIR})

    if(NOT LZ4_LIBRARIES)
        set(LZ4_LIBRARIES ${LZ4_LIBRARY})
    endif()

    if(NOT TARGET LZ4::LZ4)
        add_library(LZ4::LZ4 UNKNOWN IMPORTED)
        set_target_properties(LZ4::LZ4 PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${LZ4_INCLUDE_DIRS}")

        if(LZ4_LIBRARY_RELEASE)
            set_property(TARGET LZ4::LZ4 APPEND PROPERTY
                IMPORTED_CONFIGURATIONS RELEASE)
            set_target_properties(LZ4::LZ4 PROPERTIES
                IMPORTED_LOCATION_RELEASE "${LZ4_LIBRARY_RELEASE}")
        endif()

        if(LZ4_LIBRARY_DEBUG)
            set_property(TARGET LZ4::LZ4 APPEND PROPERTY
                IMPORTED_CONFIGURATIONS DEBUG)
            set_target_properties(LZ4::LZ4 PROPERTIES
                IMPORTED_LOCATION_DEBUG "${LZ4_LIBRARY_DEBUG}")
        endif()

        if(NOT LZ4_LIBRARY_RELEASE AND NOT LZ4_LIBRARY_DEBUG)
            set_property(TARGET LZ4::LZ4 APPEND PROPERTY
                IMPORTED_LOCATION "${LZ4_LIBRARY}")
        endif()
    endif()
endif()
