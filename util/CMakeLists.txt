add_library(brimstone_util "")

target_sources(brimstone_util
               PRIVATE
                   defines.h
                   file_output_stream.h
                   memory_output_stream.h
                   output_stream.h
                   platform.h
                   logging.h
                   file_output_stream.cpp
                   memory_output_stream.cpp
              )

if (WIN32)
    target_compile_definitions(brimstone_util PRIVATE -DWIN32_LEAN_AND_MEAN)
endif (WIN32)

target_include_directories(brimstone_util
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include
                               ${CMAKE_SOURCE_DIR}
                          )
