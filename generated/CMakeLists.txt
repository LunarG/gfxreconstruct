set(HEADER_FILES generated_apicalltrace.inc)

source_group("Header Files" FILES ${HEADER_FILES})

add_library(brimstone_generated INTERFACE)

target_compile_definitions(brimstone_generated INTERFACE LIBRARY_HEADER_ONLY)
target_include_directories(brimstone_generated INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
