add_library(brimstone_util STATIC)

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

target_include_directories(brimstone_util
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(brimstone_util platform_specific)
