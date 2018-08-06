add_executable(grecplay)

target_sources(grecplay
               PRIVATE
                   main.cpp
              )

target_include_directories(grecplay
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(grecplay brimstone_format platform_specific)
