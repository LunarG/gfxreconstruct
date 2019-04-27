add_library(gfxrecon_application STATIC "")

target_sources(gfxrecon_application
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_application.h
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_application.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_window.h
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_window.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/application/application.h
                   ${GFXRECON_SOURCE_DIR}/framework/application/application.cpp
              )

target_include_directories(gfxrecon_application
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/framework
                               ${ANDROID_NDK}/sources/android/native_app_glue)

target_link_libraries(gfxrecon_application
                      gfxrecon_decode
                      gfxrecon_format
                      gfxrecon_util
                      vulkan_registry
                      platform_specific)
