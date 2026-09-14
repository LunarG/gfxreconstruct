# FindZSTD
# -------
#
# Build Zstandard from a pinned upstream source revision.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``ZSTD::ZSTD``.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  ZSTD_FOUND : True if ZSTD was found.
if(TARGET ZSTD::ZSTD)
    set(ZSTD_FOUND TRUE)
    return()
endif()

set(GFXRECON_ZSTD_REPOSITORY "https://github.com/facebook/zstd.git")
set(GFXRECON_ZSTD_VERSION    "1.5.7")
set(GFXRECON_ZSTD_TAG        "ac66b19e6bd6b83238bf008eecc1298105298532")

include(FetchContent)

# zstd declares its build settings with option(), which ignores a plain set()
# from the including project unless CMP0077 is NEW.
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set(ZSTD_BUILD_STATIC ON)
set(ZSTD_BUILD_SHARED OFF)
set(ZSTD_BUILD_PROGRAMS OFF)
set(ZSTD_BUILD_TESTS OFF)
set(ZSTD_BUILD_CONTRIB OFF)
set(ZSTD_LEGACY_SUPPORT OFF)
set(ZSTD_MULTITHREAD_SUPPORT OFF)

set(_ZSTD_FETCH_EXCLUDE_ARGS "")
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.28")
    list(APPEND _ZSTD_FETCH_EXCLUDE_ARGS EXCLUDE_FROM_ALL)
endif()

message(STATUS "Building zstd ${GFXRECON_ZSTD_VERSION} from source (${GFXRECON_ZSTD_REPOSITORY})")
FetchContent_Declare(zstd
                     GIT_REPOSITORY ${GFXRECON_ZSTD_REPOSITORY}
                     GIT_TAG        ${GFXRECON_ZSTD_TAG}
                     SOURCE_SUBDIR  build/cmake
                     ${_ZSTD_FETCH_EXCLUDE_ARGS})
FetchContent_MakeAvailable(zstd)

unset(_ZSTD_FETCH_EXCLUDE_ARGS)

if(NOT TARGET libzstd_static)
    message(FATAL_ERROR
            "zstd was fetched but the expected 'libzstd_static' target was not created. The upstream "
            "CMake configuration may have changed; see cmake/FindZSTD.cmake.")
endif()

add_library(ZSTD::ZSTD ALIAS libzstd_static)

set(ZSTD_FOUND TRUE)
