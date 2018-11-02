add_executable(gcapplay "")

target_sources(gcapplay
               PRIVATE
                   main.cpp
              )

target_link_libraries(gcapplay brimstone_application brimstone_decode brimstone_format brimstone_util platform_specific)
