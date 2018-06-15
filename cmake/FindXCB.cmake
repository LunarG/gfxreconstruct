# Helper to try to find installed XCB libraries and headers
# This should generate 3 items of use when looking for XCB in CMake:
#   XCB_FOUND : indicates that it found XCB libraries and headers
#               installed on the local system.
#   XCB_INCLUDE_DIR : The location of xcb/xcb.h
#   XCB_LIBRARY : The location of the xcb library.

FIND_PATH(XCB_INCLUDE_DIR
          NAMES xcb/xcb.h)
FIND_LIBRARY(XCB_LIBRARY
             NAMES xcb)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(XCB DEFAULT_MSG
                                  XCB_LIBRARY
                                  XCB_INCLUDE_DIR)

MARK_AS_ADVANCED(XCB_INCLUDE_DIR XCB_LIBRARY)
