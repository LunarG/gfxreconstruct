add_library(brimstone_format INTERFACE)

#target_sources(brimstone_format
#               INTERFACE
#                   api_call_id.h
#                   format.h
#              )

target_include_directories(brimstone_format
                           INTERFACE
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(brimstone_format INTERFACE platform_specific)
