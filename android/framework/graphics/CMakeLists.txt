add_library(gfxrecon_graphics STATIC "")

target_sources(gfxrecon_graphics
               PRIVATE
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/fps_info.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/fps_info.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_check_buffer_references.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_check_buffer_references.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_device_util.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_device_util.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_instance_util.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_instance_util.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_resources_util.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_resources_util.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_util.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_util.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_struct_deep_copy.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_struct_get_pnext.h
                    ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_dispatch_table.h
                    ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_deep_copy.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_deep_copy_stype.cpp
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_struct_extract_handles.h
                    ${GFXRECON_SOURCE_DIR}/framework/graphics/vulkan_struct_extract_handles.cpp
              )

if (OPENXR_SUPPORT_ENABLED)
    target_include_directories(gfxrecon_graphics PUBLIC ${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK/include)
    target_compile_definitions(gfxrecon_graphics PUBLIC ENABLE_OPENXR_SUPPORT=1)
endif()

target_include_directories(gfxrecon_graphics
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_graphics gfxrecon_util vulkan_registry platform_specific)
