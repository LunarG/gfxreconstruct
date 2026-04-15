add_library(gfxrecon_replay_event_plugin_loader STATIC "")

target_sources(gfxrecon_replay_event_plugin_loader
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/util/replay_event_plugin_loader.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/replay_event_plugin_loader.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/util/replay_event_sink.h
                   ${GFXRECON_SOURCE_DIR}/framework/util/replay_event_sink.cpp)

target_link_libraries(gfxrecon_util
                      platform_specific
                      vulkan_registry
                      spirv_registry
                      spirv-reflect-static
                      nlohmann_json::nlohmann_json
                      android
                      log
                      ${GFXRECON_SOURCE_DIR}/external/precompiled/android/lib/${ANDROID_ABI}/liblz4_static.a
                      ${GFXRECON_SOURCE_DIR}/external/precompiled/android/lib/${ANDROID_ABI}/libzstd.a
                      z)
