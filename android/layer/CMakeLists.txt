cmake_minimum_required(VERSION 3.4.1)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../external/nlohmann-json")
find_package(nlohmann_json REQUIRED)

project(VkLayer_gfxreconstruct)

get_filename_component(GFXRECON_SOURCE_DIR ../.. ABSOLUTE)

include(../framework/cmake-config/PlatformConfig.cmake)
add_subdirectory(../framework/util ${CMAKE_SOURCE_DIR}/../framework/util/build/layer/${ANDROID_ABI})
add_subdirectory(../framework/graphics ${CMAKE_SOURCE_DIR}/../framework/graphics/build/layer/${ANDROID_ABI})
add_subdirectory(../framework/format ${CMAKE_SOURCE_DIR}/../framework/format/build/layer/${ANDROID_ABI})
add_subdirectory(../framework/encode ${CMAKE_SOURCE_DIR}/../framework/encode/build/layer/${ANDROID_ABI})

add_library(VkLayer_gfxreconstruct SHARED "")

target_sources(VkLayer_gfxreconstruct
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/layer/dll_main.cpp
                   ${GFXRECON_SOURCE_DIR}/layer/trace_layer.h
                   ${GFXRECON_SOURCE_DIR}/layer/trace_layer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_layer_func_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_layer_func_table.h
              )

target_include_directories(VkLayer_gfxreconstruct
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${GFXRECON_SOURCE_DIR})

target_link_libraries(VkLayer_gfxreconstruct
                      gfxrecon_encode
                      gfxrecon_graphics
                      gfxrecon_format
                      gfxrecon_util
                      vulkan_registry
                      platform_specific
                      android
                      log)
