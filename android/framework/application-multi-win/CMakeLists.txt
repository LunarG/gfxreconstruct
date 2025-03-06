add_library(gfxrecon_application_multiwin STATIC "")

target_compile_definitions(gfxrecon_application_multiwin
                            PUBLIC
                                GFXR_MULTI_WINDOW_REPLAY=1
                          )

target_sources(gfxrecon_application_multiwin
               PUBLIC
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_context.h
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_context.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_window.h
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_window.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/application/application.h
                   ${GFXRECON_SOURCE_DIR}/framework/application/application.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/application/wsi_context.h
                   ${GFXRECON_SOURCE_DIR}/framework/application/wsi_context.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/application/android_jni.cpp
              )

if (OPENXR_SUPPORT_ENABLED)
    target_include_directories(gfxrecon_application_multiwin PUBLIC ${GFXRECON_SOURCE_DIR}/external/OpenXR-SDK/include)
    target_compile_definitions(gfxrecon_application_multiwin PUBLIC ENABLE_OPENXR_SUPPORT=1)
endif()

target_include_directories(gfxrecon_application_multiwin
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/framework
                               ${ANDROID_NDK}/sources/android/native_app_glue)

target_link_libraries(gfxrecon_application_multiwin
                      gfxrecon_decode
                      gfxrecon_graphics
                      gfxrecon_format
                      gfxrecon_util
                      vulkan_registry
                      platform_specific)
