cmake_minimum_required(VERSION 3.4.1)

get_filename_component(BRIMSTONE_SOURCE_DIR ../.. ABSOLUTE)

include(../framework/cmake-config/PlatformConfig.cmake)
add_subdirectory(../framework/util ${CMAKE_SOURCE_DIR}/../framework/util/build)
add_subdirectory(../framework/format ${CMAKE_SOURCE_DIR}/../framework/format/build)
add_subdirectory(../framework/encode ${CMAKE_SOURCE_DIR}/../framework/encode/build)

add_library(VkLayer_brimstone SHARED "")

target_sources(VkLayer_brimstone
               PRIVATE
                   ${BRIMSTONE_SOURCE_DIR}/layer/custom_vulkan_api_call_encoders.h
                   ${BRIMSTONE_SOURCE_DIR}/layer/custom_vulkan_api_call_encoders.cpp
                   ${BRIMSTONE_SOURCE_DIR}/layer/dll_main.cpp
                   ${BRIMSTONE_SOURCE_DIR}/layer/trace_layer.h
                   ${BRIMSTONE_SOURCE_DIR}/layer/trace_layer.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_api_call_encoders.cpp
              )

target_include_directories(VkLayer_brimstone
                           PUBLIC
                               ${BRIMSTONE_SOURCE_DIR})

target_link_libraries(VkLayer_brimstone
                      brimstone_encode
                      brimstone_format
                      brimstone_util
                      vulkan_registry
                      platform_specific)
