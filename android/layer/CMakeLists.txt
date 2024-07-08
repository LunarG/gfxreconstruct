cmake_minimum_required(VERSION 3.4.1)

# Force on OpenXR support for Android
set(OPENXR_SUPPORT_ENABLED TRUE)

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
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_layer_func_table.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_layer_func_table.h
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

# Generate the JSON for Android
if (OPENXR_SUPPORT_ENABLED)
    file(TO_NATIVE_PATH "./" RELATIVE_PATH_PREFIX)
    string(REPLACE "\\" "\\\\" RELATIVE_PATH_PREFIX "${RELATIVE_PATH_PREFIX}")

    include("FindVulkanVersion")
    include("FindOpenXRVersion")

    set(XR_VERSION ${XR_VERSION_MAJOR}.${XR_VERSION_MINOR}.${XR_VERSION_PATCH})
    math(EXPR GFXRECONSTRUCT_LAYER_JSON_VERSION "${GFXRECONSTRUCT_PROJECT_VERSION_MAJOR} << 22 | ${GFXRECONSTRUCT_PROJECT_VERSION_MINOR} << 12 | ${GFXRECONSTRUCT_PROJECT_VERSION_PATCH}")
    set(GFXRECONSTRUCT_VERSION_STRING ${GFXRECONSTRUCT_PROJECT_VERSION_MAJOR}.${GFXRECONSTRUCT_PROJECT_VERSION_MINOR}.${GFXRECONSTRUCT_PROJECT_VERSION_PATCH}${GFXRECON_PROJECT_VERSION_DESIGNATION})

    # Firstly, expand variables
    string(CONFIGURE 
    [=[
    {
        "file_format_version": "1.0.0",
        "api_layer": {
            "name": "XR_APILAYER_LUNARG_gfxreconstruct",
            "library_path": "./VkLayer_gfxreconstruct.so",
            "api_version" : "${XR_VERSION}",
            "implementation_version" : "${GFXRECONSTRUCT_LAYER_JSON_VERSION}",
            "description": "GFXReconstruct Capture Layer Version ${GFXRECONSTRUCT_VERSION_STRING}",
            "disable_environment" : "GFXRECON_DISABLE"
        }
    }
    ]=]
    output_intermediate
    )

    # Then expand generator expressions
    MESSAGE("**********Outputing file to ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/XrLayer_gfxreconstruct.json")
    file(GENERATE OUTPUT ${CMAKE_BINARY_DIR}/XrLayer_gfxreconstruct.json CONTENT "${output_intermediate}")
    add_custom_command(TARGET VkLayer_gfxreconstruct POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy "${CMAKE_BINARY_DIR}/XrLayer_gfxreconstruct.json" "$<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/XrLayer_gfxreconstruct.json"
    COMMENT "Copying to output directory")
endif()

