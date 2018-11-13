add_library(gfxrecon_util STATIC "")

target_sources(gfxrecon_util
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/util/argument_parser.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/argument_parser.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/defines.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_output_stream.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/logging.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/lz4_compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/lz4_compressor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/lz77_compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/lz77_compressor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/memory_output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/memory_output_stream.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_status_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/platform.h
              )

target_compile_definitions(gfxrecon_util
                           PUBLIC
                               $<$<BOOL:${LZ4_FOUND}>:ENABLE_LZ4_COMPRESSION>
                               $<$<BOOL:${ZLIB_FOUND}>:ENABLE_LZ77_COMPRESSION>)

target_include_directories(gfxrecon_util
                           PUBLIC
                               $<$<BOOL:${LZ4_FOUND}>:${LZ4_INCLUDE_DIRS}>
                               $<$<BOOL:${ZLIB_FOUND}>:${ZLIB_INCLUDE_DIRS}>
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_util
                          platform_specific
                          $<$<BOOL:${LZ4_FOUND}>:${LZ4_LIBRARIES}>
                          $<$<BOOL:${ZLIB_FOUND}>:${ZLIB_LIBRARIES}>)