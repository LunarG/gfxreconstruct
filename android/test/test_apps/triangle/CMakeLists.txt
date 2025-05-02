# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

get_filename_component(GFXRECON_SOURCE_DIR ../../../.. ABSOLUTE)

# because the NDK sets CMAKE_FIND_ROOT_PATH_MODE_*  to ONLY, it ignores
# us setting CMAKE_PREFIX_PATH.  So just set the package DIR directly.
set(nlohmann_json_DIR "${GFXRECON_SOURCE_DIR}/external/nlohmann-json/share/cmake/nlohmann_json")
find_package(nlohmann_json REQUIRED CONFIG PATHS "${nlohmann_json_DIR}" NO_DEFAULT_PATH)

set(CMAKE_MODULE_PATH "${GFXRECON_SOURCE_DIR}/cmake" "${GFXRECON_SOURCE_DIR}/external/cmake-modules")

project(gfxrecon-testapp-triangle)

add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

add_subdirectory(../common ${CMAKE_SOURCE_DIR}/../common/build/testapps/triangle/${ANDROID_ABI})

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

include(../../../framework/cmake-config/PlatformConfig.cmake)

add_library(gfxrecon-testapp-triangle
            SHARED
                ${GFXRECON_SOURCE_DIR}/test/test_apps/triangle/app.cpp)

target_include_directories(gfxrecon-testapp-triangle
                           PUBLIC
                               ${ANDROID_NDK}/sources/android/native_app_glue
                               ${GFXRECON_SOURCE_DIR}/external/precompiled/android/include
                               ${CMAKE_BINARY_DIR})

target_link_libraries(
        gfxrecon-testapp-triangle
        gfxrecon-testapp-base
        native_app_glue
        android
        log)

target_link_options(gfxrecon-testapp-triangle
    PRIVATE
        LINKER:--version-script=${CMAKE_CURRENT_SOURCE_DIR}/triangle.map)
