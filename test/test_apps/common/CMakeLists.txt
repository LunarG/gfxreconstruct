add_library(gfxrecon-testapp-base STATIC test_app_base.cpp)
target_include_directories(gfxrecon-testapp-base PRIVATE ${PROJECT_SOURCE_DIR}/external)
target_include_directories(gfxrecon-testapp-base PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../../icd)

set(GFXRECON_TESTAPP_BASE_LINK_LIBRARIES
    gfxrecon_application
    gfxrecon_util
    gfxrecon_android_mock
)

target_link_libraries(gfxrecon-testapp-base
    PUBLIC
        ${GFXRECON_TESTAPP_BASE_LINK_LIBRARIES}
)

