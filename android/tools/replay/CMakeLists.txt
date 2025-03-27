# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

project(gfxrecon-replay)

get_filename_component(GFXRECON_SOURCE_DIR ../../.. ABSOLUTE)

# because the NDK sets CMAKE_FIND_ROOT_PATH_MODE_*  to ONLY, it ignores
# us setting CMAKE_PREFIX_PATH.  So just set the package DIR directly.
set(nlohmann_json_DIR "${GFXRECON_SOURCE_DIR}/external/nlohmann-json/share/cmake/nlohmann_json")
find_package(nlohmann_json REQUIRED CONFIG PATHS "${nlohmann_json_DIR}" NO_DEFAULT_PATH)

add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

include(../../framework/cmake-config/PlatformConfig.cmake)
add_subdirectory(../../framework/util ${PROJECT_SOURCE_DIR}/../../framework/util/build/tools/replay/${ANDROID_ABI})
add_subdirectory(../../framework/graphics ${PROJECT_SOURCE_DIR}/../../framework/graphics/build/tools/replay/${ANDROID_ABI})
add_subdirectory(../../framework/format ${PROJECT_SOURCE_DIR}/../../framework/format/build/tools/replay/${ANDROID_ABI})
add_subdirectory(../../framework/decode ${PROJECT_SOURCE_DIR}/../../framework/decode/build/tools/replay/${ANDROID_ABI})
add_subdirectory(../../framework/application ${PROJECT_SOURCE_DIR}/../../framework/application/build/tools/replay/${ANDROID_ABI})

add_library(gfxrecon-replay
            SHARED
                ${GFXRECON_SOURCE_DIR}/tools/tool_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_pre_processing.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/android_main.cpp)

target_include_directories(gfxrecon-replay
                           PUBLIC
                               ${ANDROID_NDK}/sources/android/native_app_glue
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${CMAKE_BINARY_DIR})

target_link_libraries(
        gfxrecon-replay
        gfxrecon_application
        gfxrecon_decode
        gfxrecon_graphics
        gfxrecon_format
        gfxrecon_util
        platform_specific
        native_app_glue
        android
        log)
