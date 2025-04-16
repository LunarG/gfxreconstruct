cmake_minimum_required(VERSION 3.4.1)

get_filename_component(GFXRECON_SOURCE_DIR ../.. ABSOLUTE)

list(APPEND CMAKE_PREFIX_PATH "${GFXRECON_SOURCE_DIR}/external/nlohmann-json")
find_package(nlohmann_json REQUIRED)

project(VkLayer_gfxreconstruct)

set(CMAKE_CXX_VISIBILITY_PRESET "hidden")
set(CMAKE_VISIBILITY_INLINES_HIDDEN "YES")

include(../framework/cmake-config/PlatformConfig.cmake)

# Generate the OpenXR JSON for Android so that it will get picked up and
# placed in the "assets" folder of the AAR and thus any APK file that
# later includes it.
option(GFXRECON_ENABLE_OPENXR "Enable OpenXR support." ON)
if (GFXRECON_ENABLE_OPENXR)
    file(TO_NATIVE_PATH "./" RELATIVE_PATH_PREFIX)
    string(REPLACE "\\" "\\\\" RELATIVE_PATH_PREFIX "${RELATIVE_PATH_PREFIX}")
    include("FindOpenXRVersion")
    if ((NOT XR_VERSION_MAJOR STREQUAL "") AND (NOT XR_VERSION_MINOR STREQUAL ""))
	    message(STATUS "OpenXR support enabled")
        set(OPENXR_SUPPORT_ENABLED TRUE)
    else()
	    message(FATAL_ERROR "Failed to find OpenXR headers for support.  Continuing with it disabled!")
    endif()
else()
    message(STATUS "OpenXR support disabled!")
endif()

add_subdirectory(../framework/util ${PROJECT_SOURCE_DIR}/../framework/util/build/layer/${ANDROID_ABI})
add_subdirectory(../framework/graphics ${PROJECT_SOURCE_DIR}/../framework/graphics/build/layer/${ANDROID_ABI})
add_subdirectory(../framework/format ${PROJECT_SOURCE_DIR}/../framework/format/build/layer/${ANDROID_ABI})
add_subdirectory(../framework/encode ${PROJECT_SOURCE_DIR}/../framework/encode/build/layer/${ANDROID_ABI})

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


if (GFXRECON_ENABLE_OPENXR)
    include("FindVulkanVersion")

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
        "library_path": "libVkLayer_gfxreconstruct.so",
        "api_version" : "${XR_VERSION}",
        "implementation_version" : "${GFXRECONSTRUCT_LAYER_JSON_VERSION}",
        "description": "GFXReconstruct Capture Layer Version ${GFXRECONSTRUCT_VERSION_STRING}",
        "disable_environment" : "GFXRECON_DISABLE"
    }
}
    ]=]
    openxr_implicit_layer_contents
    )

    # Then expand generator expressions
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/assets/openxr/1/api_layers/implicit.d)
    file(GENERATE OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/assets/openxr/1/api_layers/implicit.d/XrLayer_gfxreconstruct.json CONTENT "${openxr_implicit_layer_contents}")
endif()

target_link_options(VkLayer_gfxreconstruct
    PRIVATE
        LINKER:--version-script=${GFXRECON_SOURCE_DIR}/layer/VkLayer_gfxreconstruct-android.map)
