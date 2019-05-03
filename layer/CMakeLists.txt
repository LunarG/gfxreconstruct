add_library(VkLayer_gfxreconstruct SHARED "")

target_sources(VkLayer_gfxreconstruct
               PRIVATE
                   dll_main.cpp
                   trace_layer.h
                   trace_layer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_layer_func_table.h
                   $<$<BOOL:WIN32>:trace_layer.def>
              )

target_include_directories(VkLayer_gfxreconstruct
                           PUBLIC
                               ${CMAKE_SOURCE_DIR})

target_link_libraries(VkLayer_gfxreconstruct gfxrecon_encode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

# Generate the JSON file for this library
include("GenerateLayerJson")
GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json
                         $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
                         ${CMAKE_CURRENT_SOURCE_DIR}/json/VK_LAYER_LUNARG_gfxreconstruct.json.in
                         $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VK_LAYER_LUNARG_gfxreconstruct.json
                        )

target_build_directives(VkLayer_gfxreconstruct)