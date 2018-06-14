set(HEADER_FILES
    defines.h
    file_output_stream.h
    memory_output_stream.h
    output_stream.h
    platform.h)

set(SOURCE_FILES
    file_output_stream.cpp
    memory_output_stream.cpp)

add_library(brimstone_util ${HEADER_FILES} ${SOURCE_FILES})

if (WIN32)
    target_compile_definitions(brimstone_util PRIVATE -DWIN32_LEAN_AND_MEAN)
endif (WIN32)

target_include_directories(brimstone_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
