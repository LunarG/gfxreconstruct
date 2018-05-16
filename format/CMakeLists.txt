set(HEADER_FILES
    api_call_id.h
    format.h
    parameter_encoder.h
    trace_manager.h
    trace_pnext_util.h)

set(SOURCE_FILES
    trace_manager.cpp)

add_library(brimstone_format ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(brimstone_format PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(brimstone_format brimstone_util)
