set(HEADER_FILES
    api_call_id.h
    decoder.h
    file_processor.h
    format.h
    parameter_encoder.h
    pointer_decoder.h
    trace_manager.h
    trace_pnext_util.h
    value_decoder.h
    vulkan_decoder.h)

set(SOURCE_FILES
    file_processor.cpp
    trace_manager.cpp
    vulkan_decoder.cpp)

add_library(brimstone_format ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(brimstone_format PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(brimstone_format brimstone_util)
