add_executable(gcaptoascii "")

target_sources(gcaptoascii
               PRIVATE
                   main.cpp
              )

target_include_directories(gcaptoascii
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(gcaptoascii brimstone_format platform_specific)
