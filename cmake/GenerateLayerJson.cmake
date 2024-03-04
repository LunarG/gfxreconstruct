# Generate the JSON file for this library
function(GENERATE_LAYER_JSON_FILE TARGET RELATIVE_PATH_PREFIX LAYER_BINARY IN_FILE OUT_FILE)
    # Run each .json.in file through the generator
    # We need to create the generator.cmake script so that the generator can be run at compile time, instead of configure time
    # Running at compile time lets us use cmake generator expressions (TARGET_FILE_NAME and TARGET_FILE_DIR, specifically)
    file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/generator.cmake" "configure_file(\"\${INPUT_FILE}\" \"\${OUTPUT_FILE}\" @ONLY)")

    # Combine major, minor, and patch version values into a single integer.
    math(EXPR GFXRECONSTRUCT_LAYER_JSON_VERSION "${GFXRECONSTRUCT_PROJECT_VERSION_MAJOR} << 22 | ${GFXRECONSTRUCT_PROJECT_VERSION_MINOR} << 12 | ${GFXRECONSTRUCT_PROJECT_VERSION_PATCH}")

    set(CONFIG_DEFINES
        -DINPUT_FILE=${IN_FILE}
        -DVK_VERSION=${VK_VERSION}
        -DVK_VERSION=${VULKAN_VERSION_MAJOR}.${VULKAN_VERSION_MINOR}.${VULKAN_VERSION_PATCH}
        -DXR_VERSION=${XR_VERSION}
        -DXR_VERSION=${XR_VERSION_MAJOR}.${XR_VERSION_MINOR}.${XR_VERSION_PATCH}
        -DGFXRECONSTRUCT_VERSION=${GFXRECONSTRUCT_LAYER_JSON_VERSION}
        -DGFXRECONSTRUCT_VERSION_STRING=${GFXRECONSTRUCT_PROJECT_VERSION_MAJOR}.${GFXRECONSTRUCT_PROJECT_VERSION_MINOR}.${GFXRECONSTRUCT_PROJECT_VERSION_PATCH}${GFXRECON_PROJECT_VERSION_DESIGNATION}
        -DOUTPUT_FILE=${OUT_FILE}
        -DRELATIVE_LAYER_BINARY=${RELATIVE_PATH_PREFIX}${LAYER_BINARY}
    )
    add_custom_target(${TARGET} ALL COMMAND ${CMAKE_COMMAND} ${CONFIG_DEFINES} -P "${CMAKE_CURRENT_BINARY_DIR}/generator.cmake")
endfunction()
