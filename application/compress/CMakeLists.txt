add_executable(gcapcompress "")

target_sources(gcapcompress
               PRIVATE
                   main.cpp
              )

target_include_directories(gcapcompress
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(gcapcompress brimstone_format platform_specific)
