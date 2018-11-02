add_library(brimstone_application STATIC "")

target_sources(brimstone_application
               PRIVATE
                   ${BRIMSTONE_SOURCE_DIR}/framework/application/android_application.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/application/android_application.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/application/android_window.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/application/android_window.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/application/application.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/application/application.cpp
              )

target_include_directories(brimstone_application
                           PUBLIC
                               ${BRIMSTONE_SOURCE_DIR}/framework
                               ${ANDROID_NDK}/sources/android/native_app_glue)

target_link_libraries(brimstone_application
                      brimstone_decode
                      brimstone_format
                      brimstone_util
                      volk
                      vulkan_registry
                      platform_specific)
