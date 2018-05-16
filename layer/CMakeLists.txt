set(HEADER_FILES
    trace_layer.h)

set(SOURCE_FILES
    dll_main.cpp
    trace_layer.cpp)

if (WIN32)
    set(SOURCE_FILES ${SOURCE_FILES} trace_layer.def)
endif (WIN32)

add_library(brimstone_layer SHARED ${HEADER_FILES} ${SOURCE_FILES})

if (WIN32)
    target_compile_definitions(brimstone_layer PRIVATE -DWIN32_LEAN_AND_MEAN)
endif (WIN32)

target_include_directories(brimstone_layer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(brimstone_layer brimstone_format brimstone_generated)
