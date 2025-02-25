VK_LAYER_PATH="$PWD/vulkan/explicit_layer.d" \
VK_IMPLICIT_LAYER_PATH="" \
LD_LIBRARY_PATH="$PWD/vulkan/explicit_layer.d:$PWD/test_apps" \
VK_DRIVER_FILES="$PWD/test_apps/VkICD_mock_icd.json" \
VK_ICD_FILENAMES="$PWD/test_apps/VkICD_mock_icd.json" \
VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct \
GFXRECON_CAPTURE_FILE_TIMESTAMP=false \
GFXRECON_CAPTURE_FILE=actual.gfxr \
VK_LOADER_LAYERS_DISABLE=~all~ \
VK_LOADER_LAYERS_ENABLE=*gfxreconstruct* \
DISPLAY=:0 \
GFXRECON_TESTAPP_HEADLESS=true \
GFXRECON_TESTAPP_MOCK_ICD="$PWD/test_apps/libVkICD_mock_icd.so" \
./gfxrecon-testapp-runner

#GFXRECON_LOG_LEVEL="info" \
#VK_LOADER_DEBUG="all" \