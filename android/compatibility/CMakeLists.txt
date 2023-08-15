add_library(gfxrecon_compatibility STATIC "")

target_sources(gfxrecon_compatibility
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/compatibility/swapchain_image_tracker.h
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
