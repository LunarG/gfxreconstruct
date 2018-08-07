add_subdirectory(replay)
add_subdirectory(toascii)

add_library(brimstone_application STATIC)

target_sources(brimstone_application
               PRIVATE
                    application.h
                    application.cpp
                    $<$<BOOL:${XCB_FOUND}>:xcb_application.h xcb_window.h xcb_application.cpp xcb_window.cpp>
                    $<$<BOOL:${WAYLAND_FOUND}>:wayland_application.h wayland_window.h wayland_application.cpp wayland_window.cpp>
                    $<$<BOOL:${WIN32}>:win32_application.h win32_window.h win32_application.cpp win32_window.cpp>
              )

target_include_directories(brimstone_application
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(brimstone_application
                      brimstone_format
                      vulkan_registry
                      platform_specific
                      $<$<BOOL:${XCB_FOUND}>:${XCB_LIBRARY}>
                      $<$<BOOL:${WAYLAND_FOUND}>:${WAYLAND_LIBRARY}>
                     )
