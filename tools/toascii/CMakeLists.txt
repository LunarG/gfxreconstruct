add_executable(gcaptoascii "")

target_sources(gcaptoascii
               PRIVATE
                   main.cpp
              )

target_link_libraries(gcaptoascii brimstone_decode brimstone_format brimstone_util platform_specific)
