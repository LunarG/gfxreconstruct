add_library(gfxrecon_util STATIC "")

target_sources(gfxrecon_util
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/util/argument_parser.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/argument_parser.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/date_time.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/defines.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_output_stream.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_path.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_path.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/hash.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/hash.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/keyboard.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/keyboard.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/logging.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/logging.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/lz4_compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/lz4_compressor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/zlib_compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/zlib_compressor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/memory_output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/memory_output_stream.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_status_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/platform.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/settings_loader.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/settings_loader.cpp
              )

target_compile_definitions(gfxrecon_util
                           PUBLIC
                               ENABLE_LZ4_COMPRESSION
                               ENABLE_ZLIB_COMPRESSION)

target_include_directories(gfxrecon_util
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_util
                          platform_specific
                          ${GFXRECON_SOURCE_DIR}/external/precompiled/android/lib/${ANDROID_ABI}/liblz4_static.a
                          z)
