# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

get_filename_component(GFXRECON_SOURCE_DIR ../../.. ABSOLUTE)

set(CMAKE_MODULE_PATH "${GFXRECON_SOURCE_DIR}/external/cmake-modules")

set(GFXRECONSTRUCT_PROJECT_VERSION_MAJOR 0)
set(GFXRECONSTRUCT_PROJECT_VERSION_MINOR 8)
set(GFXRECONSTRUCT_PROJECT_VERSION_PATCH 0)

set(GFXRECON_PROJECT_VERSION_DESIGNATION "-unknown")
set(GFXRECON_PROJECT_VERSION_SHA1 "unknown-build-source")

include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
set(GIT_BRANCH "")

if (GIT_REFSPEC)
    string(REGEX REPLACE ".*/(.+)$" "\\1" GIT_BRANCH ${GIT_REFSPEC})
    string(COMPARE EQUAL ${GIT_BRANCH} "master" GIT_IS_MASTER)

    if (GIT_IS_MASTER)
        git_get_exact_tag(GIT_TAG)
        if (GIT_TAG)
            set(GIT_BRANCH ${GIT_TAG})
        else()
            set(GIT_BRANCH "")
        endif()
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
    else()
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "-dev")
    endif()
endif()

if (GIT_SHA1)
    string(SUBSTRING ${GIT_SHA1} 0 7 GFXRECON_PROJECT_VERSION_SHA1)

    if (GIT_BRANCH)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GIT_BRANCH} ":" ${GFXRECON_PROJECT_VERSION_SHA1})
    endif()

    git_local_changes(GIT_LOCAL_STATE)
    string(COMPARE EQUAL ${GIT_LOCAL_STATE} "DIRTY" GIT_DIRTY)
    if (GIT_DIRTY)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GFXRECON_PROJECT_VERSION_SHA1} "*")
    endif()
endif()

configure_file("${GFXRECON_SOURCE_DIR}/project_version.h.in" "${CMAKE_BINARY_DIR}/project_version.h")

add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

include(../../framework/cmake-config/PlatformConfig.cmake)
add_subdirectory(../../framework/util ${CMAKE_SOURCE_DIR}/../../framework/util/build)
add_subdirectory(../../framework/format ${CMAKE_SOURCE_DIR}/../../framework/format/build)
add_subdirectory(../../framework/decode ${CMAKE_SOURCE_DIR}/../../framework/decode/build)
add_subdirectory(../../framework/application ${CMAKE_SOURCE_DIR}/../../framework/application/build)

add_library(gfxrecon-replay
            SHARED
                ${GFXRECON_SOURCE_DIR}/tools/replay/replay_settings.h
                ${GFXRECON_SOURCE_DIR}/tools/replay/android_main.cpp)

target_include_directories(gfxrecon-replay
                           PUBLIC
                               ${ANDROID_NDK}/sources/android/native_app_glue
                               ${CMAKE_BINARY_DIR})

target_link_libraries(
        gfxrecon-replay
        gfxrecon_application
        gfxrecon_decode
        gfxrecon_format
        gfxrecon_util
        platform_specific
        native_app_glue
        android
        log)
