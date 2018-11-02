# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.4.1)

add_library(native_app_glue STATIC
        ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# Export ANativeActivity_onCreate(),
# Refer to: https://github.com/android-ndk/ndk/issues/381.
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

get_filename_component(BRIMSTONE_SOURCE_DIR ../../.. ABSOLUTE)

include(../../framework/cmake-config/PlatformConfig.cmake)
add_subdirectory(../../framework/util ${CMAKE_SOURCE_DIR}/../../framework/util/build)
add_subdirectory(../../framework/format ${CMAKE_SOURCE_DIR}/../../framework/format/build)
add_subdirectory(../../framework/decode ${CMAKE_SOURCE_DIR}/../../framework/decode/build)
add_subdirectory(../../framework/application ${CMAKE_SOURCE_DIR}/../../framework/application/build)

add_library(brimstone_replay SHARED ${BRIMSTONE_SOURCE_DIR}/tools/replay/android_main.cpp)

target_include_directories(brimstone_replay
                           PUBLIC
                               ${ANDROID_NDK}/sources/android/native_app_glue)

target_link_libraries(
        brimstone_replay
        brimstone_application
        brimstone_decode
        brimstone_format
        brimstone_util
        platform_specific
        native_app_glue
        android
        log)
