# Helper to try to find installed LZ4 libraries and headers
# This should generate 3 items of use when looking for LZ4 in CMake:
#   LZ4_FOUND        : indicates that it found LZ4 libraries and headers
#                      installed on the local system.
#   LZ4_INCLUDE_DIRS : The discoverd include directories (including the location of lz4.h)
#   LZ4_LIBRARIES    : The locations of the static lz4 libraries.
#

# Look for the top-level directory definition for the LZ4 items.  Just look for
# a bunch of different possibilities because there is no standard.
if (DEFINED ENV{LZ4_DIR})
    set(LZ4_SEARCH_PATH $ENV{LZ4_DIR})
endif()
if (DEFINED ENV{LZ4_PATH})
    set(LZ4_SEARCH_PATH $ENV{LZ4_PATH})
endif()
if (DEFINED ENV{LZ4_FOLDER})
    set(LZ4_SEARCH_PATH $ENV{LZ4_FOLDER})
endif()
if (DEFINED ENV{LZ4_ROOT})
    set(LZ4_SEARCH_PATH $ENV{LZ4_ROOT})
endif()
if (DEFINED ENV{LZ4_BASE})
    set(LZ4_SEARCH_PATH $ENV{LZ4_BASE})
endif()
if (DEFINED ENV{LZ4_ROOT_DIR})
    set(LZ4_SEARCH_PATH $ENV{LZ4_ROOT_DIR})
endif()
if (DEFINED ENV{LZ4_ROOT_PATH})
    set(LZ4_SEARCH_PATH $ENV{LZ4_ROOT_PATH})
endif()
if (DEFINED ENV{LZ4_ROOT_FOLDER})
    set(LZ4_SEARCH_PATH $ENV{LZ4_ROOT_FOLDER})
endif()
if (DEFINED ENV{LZ4_BASE_DIR})
    set(LZ4_SEARCH_PATH $ENV{LZ4_BASE_DIR})
endif()
if (DEFINED ENV{LZ4_BASE_PATH})
    set(LZ4_SEARCH_PATH $ENV{LZ4_BASE_PATH})
endif()
if (DEFINED ENV{LZ4_BASE_FOLDER})
    set(LZ4_SEARCH_PATH $ENV{LZ4_BASE_FOLDER})
endif()

# Look for lz4.h in some standard paths based on the found search above
FIND_PATH(LZ4_INCLUDE_DIRS
          NAMES lz4.h
          HINTS
             ${LZ4_SEARCH_PATH} ${LZ4_SEARCH_PATH}/include  # LZ4 generated install binary folders
             ${LZ4_SEARCH_PATH}/lib                         # LZ4 build folder
        )

# Look for liblz4 static library in some standard paths based on the found search above
FIND_LIBRARY(LZ4_LIBRARIES
             NAMES lz4 liblz4 liblz4_static
             HINTS
                 ${LZ4_SEARCH_PATH} ${LZ4_SEARCH_PATH}/static ${LZ4_SEARCH_PATH}/lib # LZ4 generated install library folders
                 ${LZ4_SEARCH_PATH}/visual                                           # LZ4 visual studio build folder (top-level)
            )

if (WIN32 AND LZ4_SEARCH_PATH)
    # The build for LZ4 on Windows is in an odd location, it is under a
    # sub-directory based on the version of visual studio used.  So, use
    # a recursive search to find the generated liblz4.lib file.
    if (NOT LZ4_LIBRARIES)
        FUNCTION(SEARCH_FOR_LZ4LIB lz4_search_paths lz4_library_filename lz4_return_list)
            FOREACH(lz4_search_path ${lz4_search_paths})
                # POINT A
                SEARCH_FOR_LZ4LIB_INNER(${lz4_search_path} ${lz4_library_filename} lz4_inner_return)
                SET(lz4_path_all_list ${lz4_path_all_list} ${lz4_inner_return})
            ENDFOREACH()
            SET(${lz4_return_list} ${lz4_path_all_list} PARENT_SCOPE)
        ENDFUNCTION(SEARCH_FOR_LZ4LIB)
        FUNCTION(SEARCH_FOR_LZ4LIB_INNER lz4_search_path lz4_library_filename lz4_return_list)
            FILE(GLOB_RECURSE lz4_new_list ${lz4_search_path}/${lz4_library_filename})
            SET(lz4_dir_list "")
            FOREACH(lz4_file_path ${lz4_new_list})
                SET(lz4_dir_list ${lz4_dir_list} ${lz4_file_path})
            ENDFOREACH()
            LIST(REMOVE_DUPLICATES lz4_dir_list)
            SET(${lz4_return_list} ${lz4_dir_list} PARENT_SCOPE)
        ENDFUNCTION(SEARCH_FOR_LZ4LIB_INNER)
        SEARCH_FOR_LZ4LIB(${LZ4_SEARCH_PATH} liblz4_static.lib LZ4_LIBRARIES)
        if (NOT LZ4_LIBRARIES)
            SEARCH_FOR_LZ4LIB(${LZ4_SEARCH_PATH} liblz4.lib LZ4_LIBRARIES)
        endif()
    endif()
endif()

# MESSAGE(STATUS "Lz4 Include = ${LZ4_INCLUDE_DIRS}")
# MESSAGE(STATUS "Lz4 Library = ${LZ4_LIBRARIES}")

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LZ4 DEFAULT_MSG
                                  LZ4_LIBRARIES
                                  LZ4_INCLUDE_DIRS)

if (LZ4_FOUND)
  include(CheckIncludeFile)
  include(CMakePushCheckState)
endif()
