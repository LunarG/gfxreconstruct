find_package(SDL3)

add_library(gfxrecon-testapp-base STATIC test_app_base.cpp)
target_include_directories(gfxrecon-testapp-base PRIVATE ${PROJECT_SOURCE_DIR}/external)
target_include_directories(gfxrecon-testapp-base PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../../icd)
target_link_libraries(gfxrecon-testapp-base SDL3::SDL3-static vulkan_registry)
