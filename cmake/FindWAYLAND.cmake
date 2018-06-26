# Helper to try to find installed Wayland libraries and headers
# This should generate 3 items of use when looking for Wayland in CMake:
#   WAYLAND_FOUND : indicates that it found XCB libraries and headers
#               installed on the local system.
#   WAYLAND_INCLUDE_DIR : The location of xcb/xcb.h
#   WAYLAND_LIBRARY : The location of the xcb library.

FIND_PATH(WAYLAND_INCLUDE_DIR
          NAMES wayland-client.h)
FIND_LIBRARY(WAYLAND_LIBRARY
             NAMES wayland-client)

include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(WAYLAND DEFAULT_MSG
                                  WAYLAND_LIBRARY
                                  WAYLAND_INCLUDE_DIR)

MARK_AS_ADVANCED(WAYLAND_INCLUDE_DIR WAYLAND_LIBRARY)
