cmake_minimum_required(VERSION 3.25)

project(D3D12MemoryAllocator VERSION 3.2.0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(D3D12MA_LIBRARY_SOURCE_FILES
    src/D3D12MemAlloc.cpp
    "${PROJECT_SOURCE_DIR}/include/D3D12MemAlloc.h"
)

if(WIN32 AND ${CMAKE_GENERATOR} MATCHES "Visual Studio.*")
    set(D3D12MA_LIBRARY_SOURCE_FILES ${D3D12MA_LIBRARY_SOURCE_FILES} src/D3D12MemAlloc.natvis)
endif()

add_library(D3D12MemoryAllocator ${D3D12MA_LIBRARY_SOURCE_FILES})

set_target_properties(
    D3D12MemoryAllocator PROPERTIES

    CXX_EXTENSIONS OFF
    # Use C++14
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON

    # OUTPUT_NAME "D3D12MA"
    # Postfix for different profiles
    # DEBUG_POSTFIX "d"
    # RELWITHDEBINFO_POSTFIX "rd"
    # MINSIZEREL_POSTFIX "s"
)

target_include_directories(D3D12MemoryAllocator
                           PUBLIC
                               $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                               $<INSTALL_INTERFACE:./include>
                               $<$<BOOL:${D3D12_SUPPORT}>:${D3D12_INCLUDE_DIRECTORIES}>
)

target_link_libraries(D3D12MemoryAllocator PUBLIC
    d3d12.lib
    dxgi.lib
    dxguid.lib
)

if(BUILD_SHARED_LIBS)
    target_compile_definitions(D3D12MemoryAllocator PRIVATE
        D3D12MA_EXPORTS
    )

    target_compile_definitions(D3D12MemoryAllocator INTERFACE
        D3D12MA_IMPORTS
    )
endif()

set(D3D12MA_GENERATED_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated")
set(D3D12MA_VERSION_CONFIG "${D3D12MA_GENERATED_DIR}/${PROJECT_NAME}ConfigVersion.cmake")
set(D3D12MA_PROJECT_CONFIG "${D3D12MA_GENERATED_DIR}/${PROJECT_NAME}Config.cmake")
set(D3D12MA_TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(D3D12MA_CONFIG_INSTALL_DIR "share/cmake/${PROJECT_NAME}")
#set(D3D12MA_NAMESPACE "GPUOpen::")
set(D3D12MA_VERSION ${PROJECT_VERSION})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${D3D12MA_VERSION_CONFIG}" VERSION ${D3D12MA_VERSION} COMPATIBILITY SameMajorVersion
)
configure_file("${PROJECT_SOURCE_DIR}/src/cmake/config.cmake.in" "${D3D12MA_PROJECT_CONFIG}" @ONLY)

# Install cmake config files
install(
  FILES "${D3D12MA_PROJECT_CONFIG}" "${D3D12MA_VERSION_CONFIG}"
  DESTINATION "${D3D12MA_CONFIG_INSTALL_DIR}")

install(
  EXPORT "${D3D12MA_TARGETS_EXPORT_NAME}"
  NAMESPACE "${D3D12MA_NAMESPACE}"
  DESTINATION "${D3D12MA_CONFIG_INSTALL_DIR}")

install(TARGETS D3D12MemoryAllocator
        EXPORT ${D3D12MA_TARGETS_EXPORT_NAME}
		RUNTIME DESTINATION "bin"
        	ARCHIVE DESTINATION "lib"
        	LIBRARY DESTINATION "lib")
install(FILES "${PROJECT_SOURCE_DIR}/include/D3D12MemAlloc.h" DESTINATION "include")
