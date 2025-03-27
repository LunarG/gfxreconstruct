###############################################################################
# Copyright (c) 2022 Advanced Micro Devices, Inc.
# All rights reserved
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to
# deal in the Software without restriction, including without limitation the
# rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
# sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
# IN THE SOFTWARE.
#
# Author: LunarG Team
# Author: AMD Developer Tools Team
# Description: CMake commands to setup Agility SDK binaries
###############################################################################

if (${D3D12_SUPPORT})

   set(GFXR_ARM_WINDOWS_BUILD FALSE)
   if(CMAKE_GENERATOR_PLATFORM STREQUAL "ARM64")
       set(GFXR_ARM_WINDOWS_BUILD TRUE)
   endif()

    # Setup src 64-bit binaries
    set(AGILITY_SDK_CONFIG_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/x64/d3dconfig.exe)
    set(AGILITY_SDK_LAYERS_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/x64/d3d12SDKLayers.dll)
    set(AGILITY_SDK_RUNTIME_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/x64/D3D12Core.dll)

    # Use 32-bit binaries if needed
    if(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(AGILITY_SDK_CONFIG_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/win32/d3dconfig.exe)
        set(AGILITY_SDK_LAYERS_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/win32/d3d12SDKLayers.dll)
        set(AGILITY_SDK_RUNTIME_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/win32/D3D12Core.dll)
    endif()

    # Use ARM 64-bit binaries if needed
    if(GFXR_ARM_WINDOWS_BUILD)
        set(AGILITY_SDK_CONFIG_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/arm64/d3dconfig.exe)
        set(AGILITY_SDK_LAYERS_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/arm64/d3d12SDKLayers.dll)
        set(AGILITY_SDK_RUNTIME_SRC ${PROJECT_SOURCE_DIR}/external/AgilitySDK/bin/arm64/D3D12Core.dll)
    endif()

    # Setup dst folders for each build config
    set(AGILITY_SDK_DST_DBG ${CMAKE_CURRENT_BINARY_DIR}/Debug/D3D12)
    set(AGILITY_SDK_DST_REL ${CMAKE_CURRENT_BINARY_DIR}/Release/D3D12)
    set(AGILITY_SDK_DST_REL_WITH_DBG_INFO ${CMAKE_CURRENT_BINARY_DIR}/RelWithDebInfo/D3D12)
    set(AGILITY_SDK_DST_MIN_SIZE_REL ${CMAKE_CURRENT_BINARY_DIR}/MinSizeRel/D3D12)
    set(AGILITY_SDK_DST_INSTALL ${CMAKE_INSTALL_BINDIR}/D3D12)

    # Copy d3dconfig.exe to dst build folder
    file(COPY ${AGILITY_SDK_CONFIG_SRC} DESTINATION ${AGILITY_SDK_DST_DBG})
    file(COPY ${AGILITY_SDK_CONFIG_SRC} DESTINATION ${AGILITY_SDK_DST_REL})
    file(COPY ${AGILITY_SDK_CONFIG_SRC} DESTINATION ${AGILITY_SDK_DST_REL_WITH_DBG_INFO})
    file(COPY ${AGILITY_SDK_CONFIG_SRC} DESTINATION ${AGILITY_SDK_DST_MIN_SIZE_REL})

    # Copy d3d12SDKLayers.dll to dst build folder
    file(COPY ${AGILITY_SDK_LAYERS_SRC} DESTINATION ${AGILITY_SDK_DST_DBG})
    file(COPY ${AGILITY_SDK_LAYERS_SRC} DESTINATION ${AGILITY_SDK_DST_REL})
    file(COPY ${AGILITY_SDK_LAYERS_SRC} DESTINATION ${AGILITY_SDK_DST_REL_WITH_DBG_INFO})
    file(COPY ${AGILITY_SDK_LAYERS_SRC} DESTINATION ${AGILITY_SDK_DST_MIN_SIZE_REL})

    # Copy D3D12Core.dll to dst build folder
    file(COPY ${AGILITY_SDK_RUNTIME_SRC} DESTINATION ${AGILITY_SDK_DST_DBG})
    file(COPY ${AGILITY_SDK_RUNTIME_SRC} DESTINATION ${AGILITY_SDK_DST_REL})
    file(COPY ${AGILITY_SDK_RUNTIME_SRC} DESTINATION ${AGILITY_SDK_DST_REL_WITH_DBG_INFO})
    file(COPY ${AGILITY_SDK_RUNTIME_SRC} DESTINATION ${AGILITY_SDK_DST_MIN_SIZE_REL})

    # Copy D3D12Core.dll to install folder
    install(FILES ${AGILITY_SDK_RUNTIME_SRC} DESTINATION ${AGILITY_SDK_DST_INSTALL})
    install(FILES ${AGILITY_SDK_LAYERS_SRC} DESTINATION ${AGILITY_SDK_DST_INSTALL})

endif()
