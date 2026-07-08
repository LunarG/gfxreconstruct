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

# Optional OpenXR support, off by default; enable with -DGFXRECON_ENABLE_OPENXR=ON,
# wired up from Gradle via the EnableOpenXR project property (see build.gradle).
# This mirrors the root CMakeLists.txt's desktop option of the same name: enabling
# it fundamentally changes how framework/util, encode, decode, format, application,
# and graphics compile (they all branch on OPENXR_SUPPORT_ENABLED internally) for
# every target in this configure pass, not just the Quest activity below -- so it's
# named after the API it brings in, not the one Android target that currently
# consumes it. Quest is the only supported XR hardware target for now, so the
# option also gates building the Quest replay activity itself, which is
# arm64-v8a-only (that's all Quest hardware is) and skipped on other ABIs even when
# the option is on.
#
# OPENXR_SUPPORT_ENABLED must be resolved before the framework subdirectories
# below are added, since they read it at that point to decide whether to compile
# in their OpenXR-related sources -- it can't be set afterwards.
option(GFXRECON_ENABLE_OPENXR "Enable OpenXR support (and the Meta Quest replay activity)." OFF)
set(GFXRECON_BUILD_QUEST_REPLAY FALSE)
if(GFXRECON_ENABLE_OPENXR AND ANDROID_ABI STREQUAL "arm64-v8a")
    include("FindOpenXRVersion")
    if ((NOT XR_VERSION_MAJOR STREQUAL "") AND (NOT XR_VERSION_MINOR STREQUAL ""))
        message(STATUS "OpenXR support enabled for gfxrecon-quest-replay")
        # This is the flag framework/util, encode, decode, format, application, and
        # graphics all check internally to decide whether to compile in their
        # OpenXR-related sources -- setting our own flag alone isn't enough.
        set(OPENXR_SUPPORT_ENABLED TRUE)
        set(GFXRECON_BUILD_QUEST_REPLAY TRUE)
    else()
        message(FATAL_ERROR "GFXRECON_ENABLE_OPENXR is ON but OpenXR headers were not found")
    endif()
endif()

add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/util util)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/plugin plugin)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/graphics graphics)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/format format)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/decode decode)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/encode encode)
add_subdirectory(${GFXRECON_SOURCE_DIR}/framework/application application)
add_subdirectory(${GFXRECON_SOURCE_DIR}/android/framework/application-multi-win application-multi-win)
set(GFXRECON_OPTIONAL_OPENXR_LIBS "")
if(GFXRECON_BUILD_QUEST_REPLAY)
    add_subdirectory(${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK OpenXR-SDK)

    # OPENXR_SUPPORT_ENABLED being on affects the shared framework libraries for
    # this whole configure pass, not just gfxrecon-quest-replay: gfxrecon_decode /
    # gfxrecon_encode now reference OpenXR loader entry points (xrCreateInstance,
    # etc.), so every target linking them -- including the non-Quest activities --
    # must also link the loader or they'll fail with undefined symbols.
    set(GFXRECON_OPTIONAL_OPENXR_LIBS OpenXR::openxr_loader)
endif()

set(GFXRECON_REPLAY_SOURCES
        ${GFXRECON_SOURCE_DIR}/tools/tool_settings.h
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

add_library(gfxrecon-replay SHARED ${GFXRECON_REPLAY_SOURCES})

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
        project_version
        ${GFXRECON_OPTIONAL_OPENXR_LIBS})

target_link_options(gfxrecon-replay PRIVATE "-Wl,-z,max-page-size=16384")

add_library(gfxrecon-multiwin-replay SHARED ${GFXRECON_REPLAY_SOURCES})

target_include_directories(gfxrecon-multiwin-replay
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${GFXRECON_SOURCE_DIR}/tools
                               ${GFXRECON_SOURCE_DIR}
                               ${CMAKE_BINARY_DIR})

target_link_libraries(
        gfxrecon-multiwin-replay
        gfxrecon_application_multiwin
        gfxrecon_decode
        gfxrecon_encode
        gfxrecon_graphics
        gfxrecon_format
        platform_specific
        ${GFXRECON_OPTIONAL_OPENXR_LIBS})

target_link_options(gfxrecon-multiwin-replay PRIVATE "-Wl,-z,max-page-size=16384")

if(GFXRECON_BUILD_QUEST_REPLAY)
    add_library(gfxrecon-quest-replay SHARED ${GFXRECON_REPLAY_SOURCES})

    target_include_directories(gfxrecon-quest-replay
                               PUBLIC
                                   ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                                   ${GFXRECON_SOURCE_DIR}/tools
                                   ${GFXRECON_SOURCE_DIR}
                                   ${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK/include
                                   ${CMAKE_BINARY_DIR})

    target_compile_definitions(gfxrecon-quest-replay PUBLIC ENABLE_OPENXR_SUPPORT=1)

    target_link_libraries(
            gfxrecon-quest-replay
            gfxrecon_application
            gfxrecon_decode
            gfxrecon_encode
            gfxrecon_graphics
            gfxrecon_format
            platform_specific
            OpenXR::openxr_loader)

    target_link_options(gfxrecon-quest-replay PRIVATE "-Wl,-z,max-page-size=16384")
endif()
