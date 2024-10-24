if (${D3D12_SUPPORT} AND "${DXC_FOUND}")

    # Setup dst folders for each build config
    set(DXC_DST_DBG ${CMAKE_CURRENT_BINARY_DIR}/Debug)
    set(DXC_DST_REL ${CMAKE_CURRENT_BINARY_DIR}/Release)
    set(DXC_DST_REL_WITH_DBG_INFO ${CMAKE_CURRENT_BINARY_DIR}/RelWithDebInfo)
    set(DXC_DST_MIN_SIZE_REL ${CMAKE_CURRENT_BINARY_DIR}/MinSizeRel)
    set(DXC_DST_INSTALL ${CMAKE_INSTALL_BINDIR})
    
    # Copy dxcompiler.dll to dst build folder
    file(COPY ${DXC_DLL_PATH} DESTINATION ${DXC_DST_DBG})
    file(COPY ${DXC_DLL_PATH} DESTINATION ${DXC_DST_REL})
    file(COPY ${DXC_DLL_PATH} DESTINATION ${DXC_DST_REL_WITH_DBG_INFO})
    file(COPY ${DXC_DLL_PATH} DESTINATION ${DXC_DST_MIN_SIZE_REL})
    
    # Copy dxcompiler.dll to install folder
    install(FILES ${DXC_DLL_PATH} DESTINATION ${DXC_DST_INSTALL})

endif()
