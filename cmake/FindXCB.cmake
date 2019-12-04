# Helper to try to find installed XCB libraries and headers
# This should generate 3 items of use when looking for XCB in CMake:
#   XCB_FOUND : indicates that it found XCB libraries and headers
#               installed on the local system.
#   XCB_INCLUDE_DIR : The location of xcb/xcb.h
#   XCB_LIBRARIES : The location of the xcb libraries.

FIND_PATH(XCB_INCLUDE_DIR
          NAMES xcb/xcb.h)

FIND_LIBRARY(XCB_LIBRARY
             NAMES xcb)
list(APPEND XCB_LIBRARIES ${XCB_LIBRARY})

FIND_LIBRARY(XCB_KEYSYMS_LIBRARY
             NAMES xcb-keysyms)
list(APPEND XCB_LIBRARIES ${XCB_KEYSYMS_LIBRARY})

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(XCB DEFAULT_MSG
                                  XCB_LIBRARIES
                                  XCB_INCLUDE_DIR)
