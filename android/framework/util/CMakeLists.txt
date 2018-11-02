add_library(brimstone_util STATIC "")

target_sources(brimstone_util
               PRIVATE
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/argument_parser.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/argument_parser.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/compressor.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/defines.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/file_output_stream.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/file_output_stream.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/logging.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/lz4_compressor.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/lz4_compressor.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/lz77_compressor.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/lz77_compressor.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/memory_output_stream.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/memory_output_stream.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/output_stream.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/page_guard_manager.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/page_guard_manager.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/page_status_tracker.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/util/platform.h
              )

target_compile_definitions(brimstone_util
                           PUBLIC
                               $<$<BOOL:${LZ4_FOUND}>:ENABLE_LZ4_COMPRESSION>
                               $<$<BOOL:${ZLIB_FOUND}>:ENABLE_LZ77_COMPRESSION>)

target_include_directories(brimstone_util
                           PUBLIC
                               $<$<BOOL:${LZ4_FOUND}>:${LZ4_INCLUDE_DIRS}>
                               $<$<BOOL:${ZLIB_FOUND}>:${ZLIB_INCLUDE_DIRS}>
                               ${BRIMSTONE_SOURCE_DIR}/framework)

target_link_libraries(brimstone_util
                          platform_specific
                          $<$<BOOL:${LZ4_FOUND}>:${LZ4_LIBRARIES}>
                          $<$<BOOL:${ZLIB_FOUND}>:${ZLIB_LIBRARIES}>)