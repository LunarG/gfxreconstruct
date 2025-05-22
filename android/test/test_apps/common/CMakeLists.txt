find_package(SDL3)

add_library(gfxrecon-testapp-base STATIC ${GFXRECON_SOURCE_DIR}/test/test_apps/common/test_app_base.cpp)
target_include_directories(gfxrecon-testapp-base
                           PRIVATE
                               ${GFXRECON_SOURCE_DIR}/external)
target_include_directories(gfxrecon-testapp-base
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/test/test_apps/common
                               ${GFXRECON_SOURCE_DIR}/test/icd)

set(FRAMEWORK_DIR ${GFXRECON_ANDROID_DIR}/framework)
set(GFXRECON_ANDROID_TEST_APPS_DIR ${CMAKE_SOURCE_DIR}/..)
add_subdirectory(${FRAMEWORK_DIR}/util ${FRAMEWORK_DIR}/util/build/${ANDROID_ABI})

target_link_libraries(gfxrecon-testapp-base
    gfxrecon_util
    native_app_glue
    SDL3::SDL3-static
    vulkan_registry)


macro(common_build_directives TARGET)
endmacro()

macro(add_test_app TEST_NAME)
    add_subdirectory(${GFXRECON_SOURCE_DIR}/test/test_apps/${TEST_NAME}
                     ${GFXRECON_ANDROID_TEST_APPS_DIR}/${TEST_NAME}/build/${ANDROID_ABI})
endmacro()

add_test_app(acquired-image)
add_test_app(external-memory-fd-export)
add_test_app(external-memory-fd-import)
add_test_app(host-image-copy)
add_test_app(multisample-depth)
add_test_app(pipeline-binaries)
add_test_app(triangle)
add_test_app(shader-objects)
add_test_app(sparse-resources)
add_test_app(wait-for-present)
