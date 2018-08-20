add_library(brimstone_util STATIC "")

target_sources(brimstone_util
               PRIVATE
                   defines.h
                   file_output_stream.h
                   memory_output_stream.h
                   output_stream.h
                   platform.h
                   logging.h
                   compressor.h
                   lz4_compressor.h
                   lz77_compressor.h
                   argument_parser.h
                   file_output_stream.cpp
                   memory_output_stream.cpp
                   compressor.cpp
                   lz4_compressor.cpp
                   lz77_compressor.cpp
                   argument_parser.cpp
              )

target_compile_definitions(brimstone_util
                           PUBLIC
                               $<$<BOOL:${LZ4_FOUND}>:ENABLE_LZ4_COMPRESSION>
                               $<$<BOOL:${ZLIB_FOUND}>:ENABLE_LZ77_COMPRESSION>)

target_include_directories(brimstone_util
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(brimstone_util
                          platform_specific
                          $<$<BOOL:${LZ4_FOUND}>:${LZ4_LIBRARY}>
                          $<$<BOOL:${ZLIB_FOUND}>:${ZLIB_LIBRARIES}>)