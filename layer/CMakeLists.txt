add_library(brimstone_layer SHARED)

target_sources(brimstone_layer
               PRIVATE
                   trace_layer.h
                   dll_main.cpp
                   trace_layer.cpp
                   $<$<BOOL:WIN32>:trace_layer.def>
              )

target_include_directories(brimstone_layer
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(brimstone_layer brimstone_format brimstone_generated vulkan_registry platform_specific)

# Generate the JSON file for this library
include("GenerateLayerJson")
GENERATE_LAYER_JSON_FILE(brimstone_layer_json
                         $<TARGET_FILE_NAME:brimstone_layer>
                         ${CMAKE_CURRENT_SOURCE_DIR}/json/VK_LAYER_LUNARG_brimstone.json.in
                         $<TARGET_FILE_DIR:brimstone_layer>/VK_LAYER_LUNARG_brimstone.json
                        )
