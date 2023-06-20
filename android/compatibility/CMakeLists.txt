add_library(gfxrecon_compatibility STATIC "")

target_sources(gfxrecon_compatibility
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/compatibility/vulkan_swapchain.h
                   ${GFXRECON_SOURCE_DIR}/compatibility/vulkan_captured_swapchain.h
                   ${GFXRECON_SOURCE_DIR}/compatibility/vulkan_captured_swapchain.cpp
                   ${GFXRECON_SOURCE_DIR}/compatibility/vulkan_virtual_swapchain.h
                   ${GFXRECON_SOURCE_DIR}/compatibility/vulkan_virtual_swapchain.cpp
              )

target_include_directories(gfxrecon_compatibility
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_compatibility gfxrecon_graphics gfxrecon_format gfxrecon_util vulkan_registry vulkan_memory_allocator platform_specific)
