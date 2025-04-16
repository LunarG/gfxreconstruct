# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html
option(GFXRECON_ENABLE_OPENXR "Enable OpenXR support." ON)
get_filename_component(GFXRECON_SOURCE_DIR ../../.. ABSOLUTE)

if (GFXRECON_ENABLE_OPENXR)
# Only supported when OpenXr support

get_filename_component(GFXRECON_SOURCE_DIR ../../.. ABSOLUTE)
include(../../framework/cmake-config/PlatformConfig.cmake)

cmake_minimum_required(VERSION 3.4.1)


# Enable OpenXR support for quest_replay or fail
include("FindOpenXRVersion")
if ((NOT XR_VERSION_MAJOR STREQUAL "") AND (NOT XR_VERSION_MINOR STREQUAL ""))
    message(STATUS "OpenXR support enabled")
    set(OPENXR_SUPPORT_ENABLED TRUE)
else()
    message(FATAL_ERROR "Failed to find OpenXR headers for support.  Continuing with it disabled!")
endif()

add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

add_subdirectory(../../framework/util ${PROJECT_SOURCE_DIR}/../../framework/util/build/tools/quest_replay/${ANDROID_ABI})
add_subdirectory(../../framework/graphics ${PROJECT_SOURCE_DIR}/../../framework/graphics/build/tools/quest_replay/${ANDROID_ABI})
add_subdirectory(../../framework/format ${PROJECT_SOURCE_DIR}/../../framework/format/build/tools/quest_replay/${ANDROID_ABI})
add_subdirectory(../../framework/decode ${PROJECT_SOURCE_DIR}/../../framework/decode/build/tools/quest_replay/${ANDROID_ABI})
add_subdirectory(../../framework/application ${PROJECT_SOURCE_DIR}/../../framework/application/build/tools/quest_replay/${ANDROID_ABI})
add_subdirectory(${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK ${PROJECT_SOURCE_DIR}/../../framework/application/build/tools/quest_replay_openxr/${ANDROID_ABI})

add_library(gfxrecon-quest-replay
            SHARED
                ${GFXRECON_SOURCE_DIR}/tools/tool_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/parse_dump_resources_cli.cpp
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/android_main.cpp)

target_include_directories(gfxrecon-quest-replay
                           PUBLIC
                               ${ANDROID_NDK}/sources/android/native_app_glue
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${CMAKE_BINARY_DIR})

target_include_directories(gfxrecon-quest-replay PUBLIC ${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK/include)
target_compile_definitions(gfxrecon-quest-replay PUBLIC ENABLE_OPENXR_SUPPORT=1)

target_link_libraries(
        gfxrecon-quest-replay
        nlohmann_json
        gfxrecon_application
        gfxrecon_decode
        gfxrecon_graphics
        gfxrecon_format
        gfxrecon_util
        platform_specific
        native_app_glue
        android
        log
        OpenXR::openxr_loader)
else()
    message(WARNING "OpenXR support disabled!")
endif()
