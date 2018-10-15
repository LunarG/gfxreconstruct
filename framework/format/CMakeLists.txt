add_library(brimstone_format STATIC "")

target_sources(brimstone_format
               PRIVATE
                   api_call_id.h
                   format.h
                   format_util.h
                   format_util.cpp
                   platform_types.h
              )

target_include_directories(brimstone_format
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(brimstone_format brimstone_util platform_specific)
