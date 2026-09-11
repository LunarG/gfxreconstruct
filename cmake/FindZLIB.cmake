# FindZLIB
# --------
#
# Find the ZLIB includes and library.
#
# This module intentionally shadows the FindZLIB.cmake module supplied with
# CMake, so that zlib is acquired the same way as LZ4 and Zstandard.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``ZLIB::ZLIB``, if zlib has been found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  ZLIB_FOUND          : True if zlib was found.
#  ZLIB_INCLUDE_DIRS   : The location of the zlib header files.
#  ZLIB_LIBRARIES      : List of the zlib libraries.
#  ZLIB_VERSION        : The version of zlib that was found.
#
# Hints
# ^^^^^
#
# The ``ZLIB_ROOT`` value may be set to tell this module where to look.

if(TARGET ZLIB::ZLIB)
    set(ZLIB_FOUND TRUE)
    return()
endif()

option(GFXRECON_COMPRESSION_FROM_SOURCE
       "Build LZ4, zstd, and zlib from pinned upstream sources instead of searching for installed libraries"
       ON)

set(GFXRECON_ZLIB_REPOSITORY "https://github.com/madler/zlib.git")
set(GFXRECON_ZLIB_VERSION    "1.3.2")
set(GFXRECON_ZLIB_TAG        "216c70c020aa53f0c40920d155f808b6b59c9acb")

if(ANDROID)
    # Provided by the NDK, so there is nothing to fetch or search for
    add_library(ZLIB::ZLIB INTERFACE IMPORTED)
    set_target_properties(ZLIB::ZLIB PROPERTIES INTERFACE_LINK_LIBRARIES "z")

    set(ZLIB_FOUND TRUE)
    set(ZLIB_LIBRARIES z)
    set(ZLIB_INCLUDE_DIRS "")

    message(STATUS "Using the zlib provided by the Android NDK")

    return()
endif()

if(GFXRECON_COMPRESSION_FROM_SOURCE)
    include(FetchContent)

    set(ZLIB_BUILD_STATIC ON)
    set(ZLIB_BUILD_SHARED OFF)
    set(ZLIB_BUILD_TESTING OFF)
    set(ZLIB_INSTALL OFF)

    message(STATUS "Building zlib ${GFXRECON_ZLIB_VERSION} from source (${GFXRECON_ZLIB_REPOSITORY})")
    FetchContent_Declare(zlib
                         GIT_REPOSITORY ${GFXRECON_ZLIB_REPOSITORY}
                         GIT_TAG        ${GFXRECON_ZLIB_TAG})
    FetchContent_MakeAvailable(zlib)

    if(NOT TARGET zlibstatic)
        message(FATAL_ERROR
                "zlib was fetched but the expected 'zlibstatic' target was not created. The upstream "
                "CMake configuration may have changed; see cmake/FindZLIB.cmake.")
    endif()

    add_library(ZLIB::ZLIB ALIAS zlibstatic)

    set(ZLIB_FOUND TRUE)
    set(ZLIB_VERSION "${GFXRECON_ZLIB_VERSION}")
    set(ZLIB_VERSION_STRING "${GFXRECON_ZLIB_VERSION}")
    set(ZLIB_LIBRARIES ZLIB::ZLIB)
    set(ZLIB_INCLUDE_DIRS "${zlib_SOURCE_DIR}" "${zlib_BINARY_DIR}")

    return()
endif()

include("${CMAKE_ROOT}/Modules/FindZLIB.cmake")
