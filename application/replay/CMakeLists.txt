add_executable(gcapplay "")

target_sources(gcapplay
               PRIVATE
                   main.cpp
              )

target_include_directories(gcapplay
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(gcapplay brimstone_util brimstone_format brimstone_application platform_specific)
