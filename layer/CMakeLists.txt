add_library(brimstone_layer SHARED "")

target_sources(brimstone_layer
               PRIVATE
                   trace_layer.h
                   dll_main.cpp
                   trace_layer.cpp
                   $<$<BOOL:WIN32>:trace_layer.def>
              )

if (WIN32)
    target_compile_definitions(brimstone_layer PRIVATE -DWIN32_LEAN_AND_MEAN)
endif (WIN32)

target_include_directories(brimstone_layer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(brimstone_layer brimstone_format brimstone_generated brimstone_util)
