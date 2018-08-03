add_executable(grectoascii)

target_sources(grectoascii
               PRIVATE
                   main.cpp
              )

target_include_directories(grectoascii
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(grectoascii brimstone_format platform_specific)
