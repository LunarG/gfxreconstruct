add_library(brimstone_util "")

target_sources(brimstone_util
               PRIVATE
                   defines.h
                   file_output_stream.h
                   graphics_memory_allocator.h
                   graphics_memory.h
                   memory_output_stream.h
                   output_stream.h
                   passthrough_memory_allocator.h
                   platform.h
                   logging.h
                   metadata.h
                   file_output_stream.cpp
                   memory_output_stream.cpp
                   metadata.cpp
                   passthrough_memory_allocator.cpp
              )

if (WIN32)
    target_compile_definitions(brimstone_util PRIVATE -DWIN32_LEAN_AND_MEAN)
endif (WIN32)

target_include_directories(brimstone_util
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include
                               ${CMAKE_SOURCE_DIR}
                          )
