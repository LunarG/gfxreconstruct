# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

project(gfxrecon-replay)

get_filename_component(GFXRECON_SOURCE_DIR ../../.. ABSOLUTE)

# because the NDK sets CMAKE_FIND_ROOT_PATH_MODE_*  to ONLY, it ignores
# us setting CMAKE_PREFIX_PATH.  So just set the package DIR directly.
set(nlohmann_json_DIR "${GFXRECON_SOURCE_DIR}/external/nlohmann-json/share/cmake/nlohmann_json")
find_package(nlohmann_json REQUIRED CONFIG PATHS "${nlohmann_json_DIR}" NO_DEFAULT_PATH)

include(../../framework/cmake-config/PlatformConfig.cmake)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/util util)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/plugin plugin)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/graphics graphics)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/format format)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/decode decode)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/encode encode)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/application application)

add_library(gfxrecon-replay
            SHARED
                ${GFXRECON_SOURCE_DIR}/tools/tool_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/tool_feature_options.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/recapture_vulkan_entry.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/recapture_vulkan_entry.h
                ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_recapture_func_table.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_feature.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_main_common.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_main_common.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_openxr_feature.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_openxr_feature.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_vulkan_feature.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_vulkan_feature.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/android_main.cpp)

target_include_directories(gfxrecon-replay
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${GFXRECON_SOURCE_DIR}/tools
                               ${GFXRECON_SOURCE_DIR}
                               ${CMAKE_BINARY_DIR})

target_link_libraries(
        gfxrecon-replay
        gfxrecon_application
        gfxrecon_decode
        gfxrecon_encode
        gfxrecon_graphics
        gfxrecon_format
        platform_specific
        project_version)

target_link_options(gfxrecon-replay PRIVATE "-Wl,-z,max-page-size=16384")
