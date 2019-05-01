add_library(gfxrecon_util STATIC "")

target_sources(gfxrecon_util
               PRIVATE
                   argument_parser.h
                   argument_parser.cpp
                   compressor.h
                   date_time.h
                   defines.h
                   file_output_stream.h
                   file_output_stream.cpp
                   file_path.h
                   file_path.cpp
                   logging.h
                   logging.cpp
                   lz4_compressor.h
                   lz4_compressor.cpp
                   zlib_compressor.h
                   zlib_compressor.cpp
                   memory_output_stream.h
                   memory_output_stream.cpp
                   output_stream.h
                   page_guard_manager.h
                   page_guard_manager.cpp
                   page_status_tracker.h
                   platform.h
                   settings_loader.h
                   settings_loader.cpp
              )

target_include_directories(gfxrecon_util
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_util platform_specific ${CMAKE_DL_LIBS})

if (UNIX AND NOT APPLE)
    # Check for clock_gettime in libc
    check_library_exists(c clock_gettime "" HAVE_GETTIME)
    if (NOT HAVE_GETTIME)
        # If not in libc, check librt
        check_library_exists(rt clock_gettime "" HAVE_GETTIME)
        if (HAVE_GETTIME)
            target_link_libraries(gfxrecon_util rt)
        else()
            message(WARNING "Function clock_gettime not found in either libc or librt")
        endif()
    endif()
endif()

if (TARGET LZ4::LZ4)
    target_compile_definitions(gfxrecon_util PUBLIC ENABLE_LZ4_COMPRESSION)
    target_link_libraries(gfxrecon_util LZ4::LZ4)
endif()

if (TARGET ZLIB::ZLIB)
    target_compile_definitions(gfxrecon_util
                               PUBLIC
                                   ENABLE_ZLIB_COMPRESSION
                                   $<$<BOOL:${WIN32}>:ZLIB_WINAPI>)
    target_link_libraries(gfxrecon_util ZLIB::ZLIB)
endif()

cpp_code_style_build_directives(gfxrecon_util)