if (${D3D12_SUPPORT})

    set(DXC_ARCH "")
    if(CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64")
        set(DXC_ARCH "arm64")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(DXC_ARCH "x64")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(DXC_ARCH "x86")
    endif()
    
    # Setup src binaries
    set(DXC_DLL_SRC ${CMAKE_SOURCE_DIR}/external/dxc/bin/${DXC_ARCH}/dxcompiler.dll)
    
    # Setup dst folders for each build config
    set(DXC_DST_DBG ${CMAKE_CURRENT_BINARY_DIR}/Debug)
    set(DXC_DST_REL ${CMAKE_CURRENT_BINARY_DIR}/Release)
    set(DXC_DST_REL_WITH_DBG_INFO ${CMAKE_CURRENT_BINARY_DIR}/RelWithDebInfo)
    set(DXC_DST_MIN_SIZE_REL ${CMAKE_CURRENT_BINARY_DIR}/MinSizeRel)
    set(DXC_DST_INSTALL ${CMAKE_INSTALL_BINDIR})
    
    # Copy dxcompiler.dll to dst build folder
    file(COPY ${DXC_DLL_SRC} DESTINATION ${DXC_DST_DBG})
    file(COPY ${DXC_DLL_SRC} DESTINATION ${DXC_DST_REL})
    file(COPY ${DXC_DLL_SRC} DESTINATION ${DXC_DST_REL_WITH_DBG_INFO})
    file(COPY ${DXC_DLL_SRC} DESTINATION ${DXC_DST_MIN_SIZE_REL})
    
    # Copy dxcompiler.dll to install folder
    install(FILES ${DXC_DLL_SRC} DESTINATION ${DXC_DST_INSTALL})

endif()
