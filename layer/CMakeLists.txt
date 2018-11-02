add_library(brimstone_layer SHARED "")

target_sources(brimstone_layer
               PRIVATE
                   custom_vulkan_api_call_encoders.h
                   custom_vulkan_api_call_encoders.cpp
                   dll_main.cpp
                   trace_layer.h
                   trace_layer.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp
                   $<$<BOOL:WIN32>:trace_layer.def>
              )

target_include_directories(brimstone_layer
                           PUBLIC
                               ${CMAKE_SOURCE_DIR})

target_link_libraries(brimstone_layer brimstone_encode brimstone_format brimstone_util vulkan_registry platform_specific)

# Generate the JSON file for this library
include("GenerateLayerJson")
GENERATE_LAYER_JSON_FILE(brimstone_layer_json
                         $<TARGET_FILE_NAME:brimstone_layer>
                         ${CMAKE_CURRENT_SOURCE_DIR}/json/VK_LAYER_LUNARG_brimstone.json.in
                         $<TARGET_FILE_DIR:brimstone_layer>/VK_LAYER_LUNARG_brimstone.json
                        )
