add_subdirectory(replay)
add_subdirectory(compress)
add_subdirectory(info)
add_subdirectory(extract)
add_subdirectory(optimize)
add_subdirectory(capture)
add_subdirectory(gfxrecon)

# TOASCII build is currently disabled pending resolution of some issues
set(BUILD_TOASCII TRUE)
if(${BUILD_TOASCII})
add_subdirectory(toascii)
endif()
