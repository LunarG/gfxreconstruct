find_package(SDL3)

add_library(gfxrecon-testapp-base STATIC ${GFXRECON_SOURCE_DIR}/test/test_apps/common/test_app_base.cpp)
target_include_directories(gfxrecon-testapp-base
                           PRIVATE
                               ${GFXRECON_SOURCE_DIR}/external)
target_include_directories(gfxrecon-testapp-base
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/test/test_apps/common
                               ${GFXRECON_SOURCE_DIR}/test/icd)

set(FRAMEWORK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../framework)
add_subdirectory(${FRAMEWORK_DIR}/util ${CMAKE_SOURCE_DIR}/../framework/util/build/layer/${ANDROID_ABI})

target_link_libraries(gfxrecon-testapp-base
                      gfxrecon_util
                      native_app_glue
                      SDL3::SDL3-static
                      vulkan_registry)

