add_library(gfxrecon_graphics STATIC "")

target_sources(gfxrecon_graphics
               PRIVATE
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_util.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_util.cpp
              )

target_include_directories(gfxrecon_graphics
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_graphics gfxrecon_util vulkan_registry platform_specific)
