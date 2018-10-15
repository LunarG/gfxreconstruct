add_executable(gcaptoascii "")

target_sources(gcaptoascii
               PRIVATE
                   main.cpp
              )

target_include_directories(gcaptoascii
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gcaptoascii brimstone_decode brimstone_format brimstone_util platform_specific)
