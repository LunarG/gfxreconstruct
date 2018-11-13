add_library(gfxrecon_util STATIC "")

target_sources(gfxrecon_util
               PRIVATE
                   argument_parser.h
                   argument_parser.cpp
                   compressor.h
                   defines.h
                   file_output_stream.h
                   file_output_stream.cpp
                   logging.h
                   lz4_compressor.h
                   lz4_compressor.cpp
                   lz77_compressor.h
                   lz77_compressor.cpp
                   memory_output_stream.h
                   memory_output_stream.cpp
                   output_stream.h
                   page_guard_manager.h
                   page_guard_manager.cpp
                   page_status_tracker.h
                   platform.h
                   date_time.h
                   file_path.h
              )

target_compile_definitions(gfxrecon_util
                           PUBLIC
                               $<$<BOOL:${LZ4_FOUND}>:ENABLE_LZ4_COMPRESSION>
                               $<$<BOOL:${ZLIB_FOUND}>:ENABLE_LZ77_COMPRESSION>)

target_include_directories(gfxrecon_util
                           PUBLIC
                               $<$<BOOL:${LZ4_FOUND}>:${LZ4_INCLUDE_DIRS}>
                               $<$<BOOL:${ZLIB_FOUND}>:${ZLIB_INCLUDE_DIRS}>
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_util
                          platform_specific
                          $<$<BOOL:${LZ4_FOUND}>:${LZ4_LIBRARIES}>
                          $<$<BOOL:${ZLIB_FOUND}>:${ZLIB_LIBRARIES}>)