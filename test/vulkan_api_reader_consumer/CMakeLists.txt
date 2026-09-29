cmake_minimum_required(VERSION 3.16.3)
project(GFXReconstructVulkanApiReaderConsumer LANGUAGES CXX)

find_package(GFXReconstructVulkanApiReader CONFIG REQUIRED)

add_executable(vulkan_api_reader_consumer main.cpp)
target_compile_features(vulkan_api_reader_consumer PRIVATE cxx_std_20)
target_link_libraries(vulkan_api_reader_consumer PRIVATE GFXReconstruct::vulkan_api_reader)

find_package(VulkanHeaders CONFIG QUIET)
if (TARGET Vulkan::Headers)
    target_link_libraries(vulkan_api_reader_consumer PRIVATE Vulkan::Headers)
else()
    find_path(VULKAN_HEADERS_INCLUDE_DIR vulkan/vulkan.h REQUIRED)
    target_include_directories(vulkan_api_reader_consumer PRIVATE ${VULKAN_HEADERS_INCLUDE_DIR})
endif()
