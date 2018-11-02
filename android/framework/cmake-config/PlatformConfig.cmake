add_library(platform_specific INTERFACE)
target_compile_definitions(platform_specific INTERFACE _FILE_OFFSET_BITS=64 VK_USE_PLATFORM_ANDROID_KHR)

add_library(vulkan_registry INTERFACE)
target_include_directories(vulkan_registry INTERFACE ${BRIMSTONE_SOURCE_DIR}/external/Vulkan-Headers/include)

add_library(volk STATIC "")
target_include_directories(volk PUBLIC ${BRIMSTONE_SOURCE_DIR}/external/volk)
target_sources(volk PRIVATE ${BRIMSTONE_SOURCE_DIR}/external/volk/volk.c)
target_compile_definitions(volk PUBLIC VK_NO_PROTOTYPES)
target_link_libraries(volk PUBLIC vulkan_registry platform_specific)
