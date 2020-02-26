# FindZSTD
# -------
#
# Find the ZSTD includes and library.
#
# This module is derived from the CMake FindZLIB.cmake module.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``ZSTD::ZSTD``, if ZSTD has been found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  ZSTD_FOUND        : True if ZSTD was found.
#  ZSTD_INCLUDE_DIRS : The location of the ZSTD header files.
#  ZSTD_LIBRARIES    : List of the ZSTD libraries.
#
# Hints
# ^^^^^
#
# The ``ZSTD_ROOT`` value may be set to tell this module where to look.

set(_ZSTD_SEARCH_PATH)

if (ZSTD_ROOT)
    set(_ZSTD_SEARCH_ROOT PATHS ${ZSTD_ROOT} NO_DEFAULT_PATH)
    list(APPEND _ZSTD_SEARCH_PATH _ZSTD_SEARCH_ROOT)
endif()

# Normal search.
set(_ZSTD_x86 "(x86)")
set(_ZSTD_SEARCH_NORMAL
    PATHS "$ENV{ProgramFiles}/zstd"
          "$ENV{ProgramFiles${_ZSTD_x86}}/zstd")
unset(_ZSTD_x86)
list(APPEND _ZSTD_SEARCH_PATH _ZSTD_SEARCH_NORMAL)

set(ZSTD_NAMES zstd zstd_static libzstd libzstd_static)
set(ZSTD_NAMES_DEBUG zstdd zstd_staticd libzstdd libzstd_staticd)

foreach(search ${_ZSTD_SEARCH_PATH})
    find_path(ZSTD_INCLUDE_DIR NAMES zstd.h ${${search}} PATH_SUFFIXES include)
endforeach()

# Allow ZSTD_LIBRARY to be set manually, as the location of the zstd library
if(NOT ZSTD_LIBRARY)
    foreach(search ${_ZSTD_SEARCH_PATH})
        find_library(ZSTD_LIBRARY_RELEASE NAMES ${ZSTD_NAMES} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
        find_library(ZSTD_LIBRARY_DEBUG NAMES ${ZSTD_NAMES_DEBUG} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
    endforeach()

    include(SelectLibraryConfigurations)
    select_library_configurations(ZSTD)
endif()

unset(ZSTD_NAMES)
unset(ZSTD_NAMES_DEBUG)

mark_as_advanced(ZSTD_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ZSTD REQUIRED_VARS ZSTD_LIBRARY ZSTD_INCLUDE_DIR)

if(ZSTD_FOUND)
    set(ZSTD_INCLUDE_DIRS ${ZSTD_INCLUDE_DIR})

    if(NOT ZSTD_LIBRARIES)
        set(ZSTD_LIBRARIES ${ZSTD_LIBRARY})
    endif()

    if(NOT TARGET ZSTD::ZSTD)
        add_library(ZSTD::ZSTD UNKNOWN IMPORTED)
        set_target_properties(ZSTD::ZSTD PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${ZSTD_INCLUDE_DIRS}")

        if(ZSTD_LIBRARY_RELEASE)
            set_property(TARGET ZSTD::ZSTD APPEND PROPERTY
                IMPORTED_CONFIGURATIONS RELEASE)
            set_target_properties(ZSTD::ZSTD PROPERTIES
                IMPORTED_LOCATION_RELEASE "${ZSTD_LIBRARY_RELEASE}")
        endif()

        if(ZSTD_LIBRARY_DEBUG)
            set_property(TARGET ZSTD::ZSTD APPEND PROPERTY
                IMPORTED_CONFIGURATIONS DEBUG)
            set_target_properties(ZSTD::ZSTD PROPERTIES
                IMPORTED_LOCATION_DEBUG "${ZSTD_LIBRARY_DEBUG}")
        endif()

        if(NOT ZSTD_LIBRARY_RELEASE AND NOT ZSTD_LIBRARY_DEBUG)
            set_property(TARGET ZSTD::ZSTD APPEND PROPERTY
                IMPORTED_LOCATION "${ZSTD_LIBRARY}")
        endif()
    endif()
endif()
