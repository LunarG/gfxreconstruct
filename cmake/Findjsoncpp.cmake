# Findjsoncpp
# -----------
#
# Find the jsoncpp includes and library.
#
# This module is derived from the CMake FindZLIB.cmake module.
#
# IMPORTED Targets
# ^^^^^^^^^^^^^^^^
#
# This module defines :prop_tgt:`IMPORTED` target ``jsoncpp::jsoncpp``, if jsoncpp has been found.
#
# Result Variables
# ^^^^^^^^^^^^^^^^
#
# This module defines the following variables:
#
#  jsoncpp_FOUND        : True if jsoncpp was found.
#  jsoncpp_INCLUDE_DIRS : The locatio of the jsoncpp header files.
#  jsoncpp_LIBRARIES    : List of the jsoncpp libraries.
#
# Hints
# ^^^^^
#
# The ``jsoncpp_ROOT`` value may be set to tell this module where to look.

set(_jsoncpp_SEARCH_PATH)

if (jsoncpp_ROOT)
    set(_jsoncpp_SEARCH_ROOT PATHS ${jsoncpp_ROOT} NO_DEFAULT_PATH)
    list(APPEND _jsoncpp_SEARCH_PATH _jsoncpp_SEARCH_ROOT)
endif()

# Normal search.
set(_jsoncpp_x86 "(x86)")
set(_jsoncpp_SEARCH_NORMAL
    PATHS "$ENV{ProgramFiles}/jsoncpp"
          "$ENV{ProgramFiles${_jsoncpp_x86}}/jsoncpp")
unset(_jsoncpp_x86)
list(APPEND _jsoncpp_SEARCH_PATH _jsoncpp_SEARCH_NORMAL)

set(jsoncpp_NAMES jsoncpp)
set(jsoncpp_NAMES_DEBUG jsoncppd)

foreach(search ${_jsoncpp_SEARCH_PATH})
    find_path(jsoncpp_INCLUDE_DIR NAMES json/json.h ${${search}} PATH_SUFFIXES include)
endforeach()

# Allow jsoncpp_LIBRARY to be set manually, as the location of the jsoncpp library
if(NOT jsoncpp_LIBRARY)
    foreach(search ${_jsoncpp_SEARCH_PATH})
        find_library(jsoncpp_LIBRARY_RELEASE NAMES ${jsoncpp_NAMES} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
        find_library(jsoncpp_LIBRARY_DEBUG NAMES ${jsoncpp_NAMES_DEBUG} NAMES_PER_DIR ${${search}} PATH_SUFFIXES lib)
    endforeach()

    include(SelectLibraryConfigurations)
    select_library_configurations(jsoncpp)
endif()

unset(jsoncpp_NAMES)
unset(jsoncpp_NAMES_DEBUG)

mark_as_advanced(jsoncpp_INCLUDE_DIR)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(jsoncpp REQUIRED_VARS jsoncpp_LIBRARY jsoncpp_INCLUDE_DIR)

if(jsoncpp_FOUND)
    set(jsoncpp_INCLUDE_DIRS ${jsoncpp_INCLUDE_DIR})

    if(NOT jsoncpp_LIBRARIES)
        set(jsoncpp_LIBRARIES ${jsoncpp_LIBRARY})
    endif()

    if(NOT TARGET jsoncpp::jsoncpp)
        add_library(jsoncpp::jsoncpp UNKNOWN IMPORTED)
        set_target_properties(jsoncpp::jsoncpp PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${jsoncpp_INCLUDE_DIRS}")

        if(jsoncpp_LIBRARY_RELEASE)
            set_property(TARGET jsoncpp::jsoncpp APPEND PROPERTY
                IMPORTED_CONFIGURATIONS RELEASE)
            set_target_properties(jsoncpp::jsoncpp PROPERTIES
                IMPORTED_LOCATION_RELEASE "${jsoncpp_LIBRARY_RELEASE}")
        endif()

        if(jsoncpp_LIBRARY_DEBUG)
            set_property(TARGET jsoncpp::jsoncpp APPEND PROPERTY
                IMPORTED_CONFIGURATIONS DEBUG)
            set_target_properties(jsoncpp::jsoncpp PROPERTIES
                IMPORTED_LOCATION_DEBUG "${jsoncpp_LIBRARY_DEBUG}")
        endif()

        if(NOT jsoncpp_LIBRARY_RELEASE AND NOT jsoncpp_LIBRARY_DEBUG)
            set_property(TARGET jsoncpp::jsoncpp APPEND PROPERTY
                IMPORTED_LOCATION "${jsoncpp_LIBRARY}")
        endif()
    endif()
endif()
