add_library(gfxrecon_util STATIC "")

target_sources(gfxrecon_util
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/util/argument_parser.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/argument_parser.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/buffer_writer.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/buffer_writer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/date_time.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/date_time.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/defines.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_output_stream.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_path.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/file_path.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/hash.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/image_writer.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/image_writer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/json_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/json_util.cpp
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
                   ${GFXRECON_SOURCE_DIR}/framework/util/monotonic_allocator.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/monotonic_allocator.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/output_stream.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_guard_manager_uffd.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/page_status_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/platform.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/settings_loader.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/settings_loader.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/spirv_helper.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/spirv_parsing_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/spirv_parsing_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/strings.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/strings.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/to_string.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/to_string.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/options.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/options.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/zstd_compressor.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/zstd_compressor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_enum_to_string.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_openxr_enum_to_string.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_enum_to_string.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_enum_to_string.cpp
              )

target_compile_definitions(gfxrecon_util
                           PUBLIC
                               GFXRECON_ENABLE_LZ4_COMPRESSION
                               GFXRECON_ENABLE_ZSTD_COMPRESSION
                               GFXRECON_ENABLE_ZLIB_COMPRESSION
                               GFXRECON_ENABLE_PNG_SCREENSHOT)

                           
target_include_directories(gfxrecon_util
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${GFXRECON_SOURCE_DIR}/external/stb
                               ${GFXRECON_SOURCE_DIR}/external/nlohmann/include
                               ${GFXRECON_SOURCE_DIR}/framework)

if (OPENXR_SUPPORT_ENABLED)
    target_include_directories(gfxrecon_util PUBLIC ${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK/include)
    target_compile_definitions(gfxrecon_util PUBLIC ENABLE_OPENXR_SUPPORT=1)
endif()

target_link_libraries(gfxrecon_util
                          platform_specific
                          vulkan_registry
                          spirv_registry
                          spirv-reflect-static
                          ${GFXRECON_SOURCE_DIR}/external/precompiled/android/lib/${ANDROID_ABI}/liblz4_static.a
                          ${GFXRECON_SOURCE_DIR}/external/precompiled/android/lib/${ANDROID_ABI}/libzstd.a
                          z)
