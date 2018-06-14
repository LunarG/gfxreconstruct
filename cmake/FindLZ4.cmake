# Helper to try to find installed LZ4 libraries and headers
# This should generate 3 items of use when looking for LZ4 in CMake:
#   LZ4_FOUND : indicates that it found LZ4 libraries and headers
#               installed on the local system.
#   LZ4_INCLUDE_DIR : The location of lz4.h
#   LZ4_LIBRARY : The location of the lz4 library.

FIND_PATH(LZ4_INCLUDE_DIR
          NAMES lz4.h)
FIND_LIBRARY(LZ4_LIBRARY
             NAMES lz4)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LZ4 DEFAULT_MSG
                                  LZ4_LIBRARY
                                  LZ4_INCLUDE_DIR)

MARK_AS_ADVANCED(LZ4_INCLUDE_DIR LZ4_LIBRARY)
