add_subdirectory(replay)
add_subdirectory(compress)
add_subdirectory(info)
add_subdirectory(extract)
add_subdirectory(optimize)
add_subdirectory(capture-vulkan)
add_subdirectory(gfxrecon)

if(MSVC)
    add_subdirectory(launcher)
endif()

# TOASCII build is currently disabled pending resolution of some issues
if(BUILD_TOASCII OR BUILD_D3D12)
add_subdirectory(toascii)
endif()
