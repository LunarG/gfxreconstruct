find_package(SDL3)

add_library(gfxrecon-testapp-base STATIC ${GFXRECON_SOURCE_DIR}/test/test_apps/common/test_app_base.cpp)
target_include_directories(gfxrecon-testapp-base PRIVATE ${GFXRECON_SOURCE_DIR}/external)
target_include_directories(gfxrecon-testapp-base PUBLIC ${GFXRECON_SOURCE_DIR}/test/test_apps/common ${GFXRECON_SOURCE_DIR}/test/icd ${ANDROID_NDK}/sources/android/native_app_glue)
target_link_libraries(gfxrecon-testapp-base SDL3::SDL3-static vulkan_registry native_app_glue)

