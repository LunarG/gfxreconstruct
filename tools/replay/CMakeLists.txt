add_executable(gcapplay "")

target_sources(gcapplay
               PRIVATE
                   main.cpp
              )

target_include_directories(gcapplay
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gcapplay brimstone_application brimstone_decode brimstone_format brimstone_util platform_specific)
