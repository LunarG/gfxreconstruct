add_library(VkLayer_gfxreconstruct SHARED "")

target_sources(VkLayer_gfxreconstruct
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/dll_main.cpp
                    ${CMAKE_CURRENT_LIST_DIR}/trace_layer.h
                    ${CMAKE_CURRENT_LIST_DIR}/trace_layer.cpp
                    ${CMAKE_SOURCE_DIR}/framework/generated/generated_layer_func_table.h
                    $<$<BOOL:WIN32>:${CMAKE_CURRENT_LIST_DIR}/trace_layer.def>
              )

target_include_directories(VkLayer_gfxreconstruct
                           PUBLIC
                               ${CMAKE_BINARY_DIR}
                               ${CMAKE_SOURCE_DIR})

target_link_libraries(VkLayer_gfxreconstruct gfxrecon_encode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)

common_build_directives(VkLayer_gfxreconstruct)

# The json output file needs Unix "/" separators or Windows "\" separators
# On top of that, Windows separators actually need to be doubled because the json format uses backslash escapes
file(TO_NATIVE_PATH "./" RELATIVE_PATH_PREFIX)
string(REPLACE "\\" "\\\\" RELATIVE_PATH_PREFIX "${RELATIVE_PATH_PREFIX}")
include("GenerateLayerJson")
# Generate the JSON file that will be generated into the build directory
GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json
        "${RELATIVE_PATH_PREFIX}"
        $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
        ${CMAKE_CURRENT_SOURCE_DIR}/json/VkLayer_gfxreconstruct.json.in
        $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json
        )
GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json-for-auto-test
        "${RELATIVE_PATH_PREFIX}"
        $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
        ${CMAKE_CURRENT_SOURCE_DIR}/json/VkLayer_gfxreconstruct.json.in
        $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VK_LAYER_LUNARG_gfxreconstruct.json
        )

if(UNIX)
        # Generate a JSON file that can be installed into system directories (w/o the "./" prefix in the library_path)
        set(RELATIVE_PATH_PREFIX "")
        GENERATE_LAYER_JSON_FILE(VkLayer_gfxreconstruct_json-staging
                "${RELATIVE_PATH_PREFIX}"
                $<TARGET_FILE_NAME:VkLayer_gfxreconstruct>
                ${CMAKE_CURRENT_SOURCE_DIR}/json/VkLayer_gfxreconstruct.json.in
                $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json
                )
endif()
add_test_package_file($<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json)
add_test_package_file($<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VK_LAYER_LUNARG_gfxreconstruct.json)

install(TARGETS VkLayer_gfxreconstruct RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
if (UNIX)
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/staging-json/VkLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/vulkan/explicit_layer.d)
else()
    install(FILES $<TARGET_FILE_DIR:VkLayer_gfxreconstruct>/VkLayer_gfxreconstruct.json DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

add_executable(VkLayer_gfxreconstruct_test "")

target_sources(VkLayer_gfxreconstruct_test
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)

common_build_directives(VkLayer_gfxreconstruct_test)
common_test_directives(VkLayer_gfxreconstruct_test)
