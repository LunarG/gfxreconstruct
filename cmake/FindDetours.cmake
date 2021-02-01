# FindDetours
# -----------
#
# Find the Detours includes and library.
#
# This module is derived from the CMake FindZLIB.cmake module.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``Detours::Detours``, if Detours has been found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  Detours_FOUND        : True if Detours was found.
#  Detours_INCLUDE_DIRS : The locatio of the Detours header files.
#  Detours_LIBRARIES    : List of the Detours libraries.
#
# Hints
# ^^^^^
#
# The ``Detours_ROOT`` value may be set to tell this module where to look.

set(_Detours_SEARCH_PATH)

if (Detours_ROOT)
    set(_Detours_SEARCH_ROOT PATHS ${Detours_ROOT} NO_DEFAULT_PATH)
    list(APPEND _Detours_SEARCH_PATH _Detours_SEARCH_ROOT)
endif()

# Normal search.
set(_Detours_x86 "(x86)")
set(_Detours_SEARCH_NORMAL
    PATHS "$ENV{ProgramFiles}/detours"
          "$ENV{ProgramFiles${_Detours_x86}}/detours")
unset(_Detours_x86)
list(APPEND _Detours_SEARCH_PATH _Detours_SEARCH_NORMAL)

set(Detours_NAMES detours)
set(Detours_NAMES_DEBUG detoursd)

foreach(search ${_Detours_SEARCH_PATH})
    find_path(Detours_INCLUDE_DIR NAMES detours.h ${${search}} PATH_SUFFIXES include)
endforeach()

# Allow Detours_LIBRARY to be set manually, as the location of the detours library
if(NOT Detours_LIBRARY)
    foreach(search ${_Detours_SEARCH_PATH})
        find_library(Detours_LIBRARY_RELEASE NAMES ${Detours_NAMES} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
        find_library(Detours_LIBRARY_DEBUG NAMES ${Detours_NAMES_DEBUG} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
    endforeach()

    include(SelectLibraryConfigurations)
    select_library_configurations(Detours)
endif()

unset(Detours_NAMES)
unset(Detours_NAMES_DEBUG)

mark_as_advanced(Detours_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Detours REQUIRED_VARS Detours_LIBRARY Detours_INCLUDE_DIR)

if(Detours_FOUND)
    set(Detours_INCLUDE_DIRS ${Detours_INCLUDE_DIR})

    if(NOT Detours_LIBRARIES)
        set(Detours_LIBRARIES ${Detours_LIBRARY})
    endif()

    if(NOT TARGET Detours::Detours)
        add_library(Detours::Detours UNKNOWN IMPORTED)
        set_target_properties(Detours::Detours PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${Detours_INCLUDE_DIRS}")

        if(Detours_LIBRARY_RELEASE)
            set_property(TARGET Detours::Detours APPEND PROPERTY
                IMPORTED_CONFIGURATIONS RELEASE)
            set_target_properties(Detours::Detours PROPERTIES
                IMPORTED_LOCATION_RELEASE "${Detours_LIBRARY_RELEASE}")
        endif()

        if(Detours_LIBRARY_DEBUG)
            set_property(TARGET Detours::Detours APPEND PROPERTY
                IMPORTED_CONFIGURATIONS DEBUG)
            set_target_properties(Detours::Detours PROPERTIES
                IMPORTED_LOCATION_DEBUG "${Detours_LIBRARY_DEBUG}")
        endif()

        if(NOT Detours_LIBRARY_RELEASE AND NOT Detours_LIBRARY_DEBUG)
            set_property(TARGET Detours::Detours APPEND PROPERTY
                IMPORTED_LOCATION "${Detours_LIBRARY}")
        endif()
    endif()
endif()
