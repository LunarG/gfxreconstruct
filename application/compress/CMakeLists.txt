add_executable(greccompress "")

target_sources(greccompress
               PRIVATE
                   main.cpp
              )

target_include_directories(greccompress
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(greccompress brimstone_format platform_specific)
