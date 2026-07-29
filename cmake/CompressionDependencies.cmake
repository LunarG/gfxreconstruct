###############################################################################
# Copyright (c) 2026 LunarG, Inc.
# All rights reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#
# Author: LunarG Team
# Description: Acquisition of the LZ4, zstd, and zlib compression libraries
###############################################################################
#
# This module makes the following targets available, when the corresponding
# library is present.  Consumers should test for the target rather than for a
# _FOUND variable, because a library may legitimately be absent:
#
#   LZ4::LZ4    : the LZ4 compression library
#   ZSTD::ZSTD  : the Zstandard compression library
#   ZLIB::ZLIB  : the zlib compression library
#
# By default the libraries are built from the pinned upstream sources listed
# below.  Setting GFXRECON_COMPRESSION_FROM_SOURCE to OFF instead searches for
# libraries already present on the system, which is what Linux distribution
# packagers and air-gapped builds want.  Note that building from source
# requires network access at CMake configure time; see BUILD.md for the
# FetchContent variables that support offline builds.
#
###############################################################################

include_guard(GLOBAL)

# Windows on ARM links ARM64X libraries, which are produced by building each
# library twice (once as ARM64 and once as ARM64EC) and splicing the results
# together with "link.exe /lib /machine:arm64x".  CMake cannot express that, so
# these configurations continue to consume the pre-compiled binaries checked in
# under external/precompiled/win64-arm.  That folder's README.txt documents how
# they are produced.
if (GFXR_ARM_WINDOWS_BUILD)
    set(GFXRECON_COMPRESSION_FROM_SOURCE_DEFAULT OFF)
else ()
    set(GFXRECON_COMPRESSION_FROM_SOURCE_DEFAULT ON)
endif ()

option(GFXRECON_COMPRESSION_FROM_SOURCE
       "Build LZ4, zstd, and zlib from pinned upstream sources instead of searching for installed libraries"
       ${GFXRECON_COMPRESSION_FROM_SOURCE_DEFAULT})

# Pinned upstream revisions.  GIT_TAG is set to an immutable commit hash rather
# than a tag name so that CMake does not need to contact the remote on every
# build to check whether the ref moved.  The release each hash corresponds to is
# noted in the trailing comment.  To update a library, change both the hash and
# the comment here, then update the version recorded in
# LICENSE_ThirdParty.txt and external/README.md.
set(GFXRECON_LZ4_REPOSITORY "https://github.com/lz4/lz4.git")
set(GFXRECON_LZ4_TAG        "ebb370ca83af193212df4dcbadcc5d87bc0de2f0") # v1.10.0
set(GFXRECON_LZ4_VERSION    "1.10.0")

set(GFXRECON_ZSTD_REPOSITORY "https://github.com/facebook/zstd.git")
set(GFXRECON_ZSTD_TAG        "ac66b19e6bd6b83238bf008eecc1298105298532") # v1.5.7
set(GFXRECON_ZSTD_VERSION    "1.5.7")

set(GFXRECON_ZLIB_REPOSITORY "https://github.com/madler/zlib.git")
set(GFXRECON_ZLIB_TAG        "216c70c020aa53f0c40920d155f808b6b59c9acb") # v1.3.2
set(GFXRECON_ZLIB_VERSION    "1.3.2")

if (GFXRECON_COMPRESSION_FROM_SOURCE)

    include(FetchContent)

    # The upstream projects declare their build settings with option(), which
    # normally ignores a plain set() from the including project.  CMP0077 NEW
    # makes option() defer to the value set here.
    set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

    # zstd installs its library, headers, pkg-config file, and CMake package
    # files unconditionally, which would add them to the GFXReconstruct install
    # tree.  Declaring the dependency EXCLUDE_FROM_ALL leaves those install
    # rules out of the generated install script.  LZ4 and zlib do not need this;
    # LZ4 skips its install rules when it detects that it is a sub-project, and
    # zlib provides the ZLIB_INSTALL option used below.  FetchContent gained
    # EXCLUDE_FROM_ALL in CMake 3.28, so on older versions the zstd install
    # rules are still emitted.
    set(GFXRECON_FETCHCONTENT_EXCLUDE_ARGS "")
    if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.28")
        list(APPEND GFXRECON_FETCHCONTENT_EXCLUDE_ARGS EXCLUDE_FROM_ALL)
    endif ()

    #--------------------------------------------------------------------------
    # LZ4
    #
    # LZ4 detects that it is being built as a sub-project and responds by
    # building only a static library and skipping its install() rules, so
    # neither needs to be requested here.  In particular BUILD_SHARED_LIBS must
    # not be set, because it is a global setting that would also apply to
    # GFXReconstruct's own libraries.
    #--------------------------------------------------------------------------
    set(LZ4_BUILD_CLI OFF)

    message(STATUS "Fetching LZ4 ${GFXRECON_LZ4_VERSION} from ${GFXRECON_LZ4_REPOSITORY}")
    FetchContent_Declare(lz4
                         GIT_REPOSITORY ${GFXRECON_LZ4_REPOSITORY}
                         GIT_TAG        ${GFXRECON_LZ4_TAG}
                         SOURCE_SUBDIR  build/cmake)
    FetchContent_MakeAvailable(lz4)

    if (NOT TARGET lz4_static)
        message(FATAL_ERROR
                "LZ4 was fetched but the expected 'lz4_static' target was not created. The upstream "
                "CMake configuration may have changed; see cmake/CompressionDependencies.cmake.")
    endif ()
    add_library(LZ4::LZ4 ALIAS lz4_static)

    #--------------------------------------------------------------------------
    # Zstandard
    #
    # zstd builds both a shared and a static library by default and always
    # builds its command line programs, so all of that is turned off here.
    # Only the single-shot ZSTD_compress/ZSTD_decompress API is used, so
    # neither multi-threading nor decode support for pre-1.0 frame formats is
    # required.
    #--------------------------------------------------------------------------
    set(ZSTD_BUILD_STATIC ON)
    set(ZSTD_BUILD_SHARED OFF)
    set(ZSTD_BUILD_PROGRAMS OFF)
    set(ZSTD_BUILD_TESTS OFF)
    set(ZSTD_BUILD_CONTRIB OFF)
    set(ZSTD_LEGACY_SUPPORT OFF)
    set(ZSTD_MULTITHREAD_SUPPORT OFF)

    message(STATUS "Fetching zstd ${GFXRECON_ZSTD_VERSION} from ${GFXRECON_ZSTD_REPOSITORY}")
    FetchContent_Declare(zstd
                         GIT_REPOSITORY ${GFXRECON_ZSTD_REPOSITORY}
                         GIT_TAG        ${GFXRECON_ZSTD_TAG}
                         SOURCE_SUBDIR  build/cmake
                         ${GFXRECON_FETCHCONTENT_EXCLUDE_ARGS})
    FetchContent_MakeAvailable(zstd)

    if (NOT TARGET libzstd_static)
        message(FATAL_ERROR
                "zstd was fetched but the expected 'libzstd_static' target was not created. The upstream "
                "CMake configuration may have changed; see cmake/CompressionDependencies.cmake.")
    endif ()
    add_library(ZSTD::ZSTD ALIAS libzstd_static)

    #--------------------------------------------------------------------------
    # zlib
    #
    # Android provides zlib as a platform library, so it is used there instead
    # of building a second copy that would collide with the one already linked
    # into the platform.  Elsewhere zlib is built from source as a static
    # library.  Note that upstream defines ZLIB::ZLIB itself as an alias for its
    # *shared* library, so that name is only free to use here because the shared
    # library is disabled.
    #--------------------------------------------------------------------------
    if (ANDROID)
        add_library(gfxrecon_zlib_ndk INTERFACE)
        target_link_libraries(gfxrecon_zlib_ndk INTERFACE z)
        add_library(ZLIB::ZLIB ALIAS gfxrecon_zlib_ndk)
    else ()
        set(ZLIB_BUILD_STATIC ON)
        set(ZLIB_BUILD_SHARED OFF)
        set(ZLIB_BUILD_TESTING OFF)
        set(ZLIB_INSTALL OFF)

        message(STATUS "Fetching zlib ${GFXRECON_ZLIB_VERSION} from ${GFXRECON_ZLIB_REPOSITORY}")
        FetchContent_Declare(zlib
                             GIT_REPOSITORY ${GFXRECON_ZLIB_REPOSITORY}
                             GIT_TAG        ${GFXRECON_ZLIB_TAG})
        FetchContent_MakeAvailable(zlib)

        if (NOT TARGET zlibstatic)
            message(FATAL_ERROR
                    "zlib was fetched but the expected 'zlibstatic' target was not created. The upstream "
                    "CMake configuration may have changed; see cmake/CompressionDependencies.cmake.")
        endif ()
        add_library(ZLIB::ZLIB ALIAS zlibstatic)
    endif ()

else () # NOT GFXRECON_COMPRESSION_FROM_SOURCE

    #--------------------------------------------------------------------------
    # Search for libraries already present on the system, or among the
    # pre-compiled binaries under external/precompiled that the root
    # CMakeLists.txt adds to CMAKE_PREFIX_PATH.  cmake/FindLZ4.cmake and
    # cmake/FindZSTD.cmake provide the LZ4 and zstd searches; zlib uses the
    # find module supplied with CMake.
    #--------------------------------------------------------------------------
    find_package(LZ4)
    find_package(ZSTD)

    if (BUILD_STATIC)
        find_library(ZLIB NAMES libz.a REQUIRED PATH_SUFFIXES lib lib/x86_64-linux-gnu lib64)
    else ()
        find_package(ZLIB)
    endif ()

endif () # GFXRECON_COMPRESSION_FROM_SOURCE

option(LZ4_OPTIONAL "Allow building without LZ4-compression" OFF)

if (NOT TARGET LZ4::LZ4)
    if (LZ4_OPTIONAL)
        message(STATUS "LZ4 library not found, but declared optional. LZ4 support is disabled.")
    else ()
        message(FATAL_ERROR "LZ4 library not found. Please install LZ4 or allow building without it by setting LZ4_OPTIONAL to ON.")
    endif () # LZ4_OPTIONAL
endif () # NOT TARGET LZ4::LZ4
