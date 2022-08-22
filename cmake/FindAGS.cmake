# FindAGS
# -----------
#
# Find the AGS includes and library.
#
# This module is derived from the CMake FindZLIB.cmake module.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``AGS::AGS``, if AGS has been found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  AGS_FOUND        : True if AGS was found.
#  AGS_INCLUDE_DIRS : The locatio of the AGS header files.
#  AGS_LIBRARIES    : List of the AGS libraries.
#
# Hints
# ^^^^^
#
# The ``AGS_ROOT`` value may be set to tell this module where to look.

set(_AGS_SEARCH_PATH)

if (AGS_ROOT)
    set(_AGS_SEARCH_ROOT PATHS ${AGS_ROOT} NO_DEFAULT_PATH)
    list(APPEND _AGS_SEARCH_PATH _AGS_SEARCH_ROOT)
endif()

# Normal search.
set(_AGS_x86 "(x86)")
set(_AGS_SEARCH_NORMAL
    PATHS "$ENV{ProgramFiles}/ags"
          "$ENV{ProgramFiles${_AGS_x86}}/ags")
unset(_AGS_x86)
list(APPEND _AGS_SEARCH_PATH _AGS_SEARCH_NORMAL)

set(AGS_NAMES ags)
set(AGS_NAMES_DEBUG agsd)

foreach(search ${_AGS_SEARCH_PATH})
    find_path(AGS_INCLUDE_DIR NAMES amd_ags.h ${${search}} PATH_SUFFIXES include)
endforeach()

# Allow AGS_LIBRARY to be set manually, as the location of the AGS library
if(NOT AGS_LIBRARY)
    foreach(search ${_AGS_SEARCH_PATH})
        find_library(AGS_LIBRARY_RELEASE NAMES ${AGS_NAMES} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
        find_library(AGS_LIBRARY_DEBUG NAMES ${AGS_NAMES_DEBUG} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
    endforeach()

    include(SelectLibraryConfigurations)
    select_library_configurations(AGS)
endif()

unset(AGS_NAMES)
unset(AGS_NAMES_DEBUG)

mark_as_advanced(AGS_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(AGS REQUIRED_VARS AGS_LIBRARY AGS_INCLUDE_DIR)

if(AGS_FOUND)
    set(AGS_INCLUDE_DIRS ${AGS_INCLUDE_DIR})

    if(NOT AGS_LIBRARIES)
        set(AGS_LIBRARIES ${AGS_LIBRARY})
    endif()

    if(NOT TARGET AGS::AGS)
        add_library(AGS::AGS UNKNOWN IMPORTED)
        set_target_properties(AGS::AGS PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${AGS_INCLUDE_DIRS}")

        if(AGS_LIBRARY_RELEASE)
            set_property(TARGET AGS::AGS APPEND PROPERTY
                IMPORTED_CONFIGURATIONS RELEASE)
            set_target_properties(AGS::AGS PROPERTIES
                IMPORTED_LOCATION_RELEASE "${AGS_LIBRARY_RELEASE}")
        endif()

        if(AGS_LIBRARY_DEBUG)
            set_property(TARGET AGS::AGS APPEND PROPERTY
                IMPORTED_CONFIGURATIONS DEBUG)
            set_target_properties(AGS::AGS PROPERTIES
                IMPORTED_LOCATION_DEBUG "${AGS_LIBRARY_DEBUG}")
        endif()

        if(NOT AGS_LIBRARY_RELEASE AND NOT AGS_LIBRARY_DEBUG)
            set_property(TARGET AGS::AGS APPEND PROPERTY
                IMPORTED_LOCATION "${AGS_LIBRARY}")
        endif()
    endif()
endif()
