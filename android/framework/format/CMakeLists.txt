add_library(gfxrecon_format STATIC "")

target_sources(gfxrecon_format
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/format/api_call_id.h
                   ${GFXRECON_SOURCE_DIR}/framework/format/format.h
                   ${GFXRECON_SOURCE_DIR}/framework/format/format_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/format/format_util.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/format/platform_types.h
                   ${GFXRECON_SOURCE_DIR}/framework/format/platform_types_d3d_overrides.h
              )

if (OPENXR_SUPPORT_ENABLED)
    target_include_directories(gfxrecon_format PUBLIC ${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK/include)
    target_compile_definitions(gfxrecon_format PUBLIC ENABLE_OPENXR_SUPPORT=1)
endif()

target_include_directories(gfxrecon_format
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_format gfxrecon_util vulkan_registry platform_specific)
