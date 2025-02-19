add_custom_target(gfxrecon-capture.py ALL
                  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/gfxrecon-capture.py
                  COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/gfxrecon-capture.py ${CMAKE_CURRENT_BINARY_DIR}/gfxrecon-capture.py)

install(FILES gfxrecon-capture.py DESTINATION ${CMAKE_INSTALL_BINDIR} PERMISSIONS
        OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
