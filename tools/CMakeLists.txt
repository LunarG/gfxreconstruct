add_subdirectory(replay)
add_subdirectory(compress)
add_subdirectory(info)

if(GFXRECON_TOCPP_SUPPORT)
add_subdirectory(tocpp)
endif()

add_subdirectory(extract)
add_subdirectory(optimize)
add_subdirectory(capture-vulkan)
add_subdirectory(capture)
add_subdirectory(gfxrecon)
add_subdirectory(convert)

if(MSVC)
    add_subdirectory(launcher)
endif()
