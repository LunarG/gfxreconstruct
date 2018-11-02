add_library(brimstone_format STATIC "")

target_sources(brimstone_format
               PRIVATE
                   ${BRIMSTONE_SOURCE_DIR}/framework/format/api_call_id.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/format/format.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/format/format_util.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/format/format_util.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/format/platform_types.h
              )

target_include_directories(brimstone_format
                           PUBLIC
                               ${BRIMSTONE_SOURCE_DIR}/framework)

target_link_libraries(brimstone_format brimstone_util vulkan_registry platform_specific)
