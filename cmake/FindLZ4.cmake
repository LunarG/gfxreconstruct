# FindLZ4
# -------
#
# Build LZ4 from a pinned upstream source revision.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``LZ4::LZ4``.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  LZ4_FOUND : True if LZ4 was found.
if(TARGET LZ4::LZ4)
    set(LZ4_FOUND TRUE)
    return()
endif()

set(GFXRECON_LZ4_REPOSITORY "https://github.com/lz4/lz4.git")
set(GFXRECON_LZ4_VERSION    "1.10.0")
set(GFXRECON_LZ4_TAG        "ebb370ca83af193212df4dcbadcc5d87bc0de2f0")

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
