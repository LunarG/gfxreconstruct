# FindZLIB
# --------
#
# Build zlib from a pinned upstream source revision.
#
# Targets
# ^^^^^^^
#
# This module defines ``ZLIB::ZLIB``.  On Android it is an IMPORTED INTERFACE
# target that links the zlib supplied by the NDK.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  ZLIB_FOUND : True if zlib was found.

if(TARGET ZLIB::ZLIB)
    set(ZLIB_FOUND TRUE)
    return()
endif()

if(ANDROID)
    # Provided by the NDK, so there is nothing to fetch or search for
    add_library(ZLIB::ZLIB INTERFACE IMPORTED)
    set_target_properties(ZLIB::ZLIB PROPERTIES INTERFACE_LINK_LIBRARIES "z")

    set(ZLIB_FOUND TRUE)

    message(STATUS "Using the zlib provided by the Android NDK")

    return()
endif()

set(GFXRECON_ZLIB_REPOSITORY "https://github.com/madler/zlib.git")
set(GFXRECON_ZLIB_VERSION    "1.3.2")
set(GFXRECON_ZLIB_TAG        "216c70c020aa53f0c40920d155f808b6b59c9acb")

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
