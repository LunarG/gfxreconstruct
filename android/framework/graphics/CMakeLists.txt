add_library(gfxrecon_graphics STATIC "")

target_sources(gfxrecon_graphics
               PRIVATE
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/fps_info.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/fps_info.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_device_util.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_device_util.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_util.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_util.cpp
              )

target_include_directories(gfxrecon_graphics
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external/nlohmann/include
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_graphics gfxrecon_util vulkan_registry platform_specific)
