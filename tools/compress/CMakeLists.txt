add_executable(gcapcompress "")

target_sources(gcapcompress
               PRIVATE
                   main.cpp
              )

target_link_libraries(gcapcompress brimstone_decode brimstone_format brimstone_util platform_specific)
