add_executable(gcapcompress "")

target_sources(gcapcompress
               PRIVATE
                   main.cpp
              )

target_include_directories(gcapcompress
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gcapcompress brimstone_decode brimstone_format brimstone_util platform_specific)
