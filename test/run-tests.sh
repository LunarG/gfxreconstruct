VK_LAYER_PATH="$PWD/vulkan/explicit_layer.d" \
VK_DRIVER_FILES="$PWD/test_apps/VkICD_mock_icd.json" \
VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct \
GFXRECON_CAPTURE_FILE_TIMESTAMP=false \
GFXRECON_CAPTURE_FILE=actual.gfxr \
VK_LOADER_LAYERS_DISABLE=~all~ \
VK_LOADER_LAYERS_ENABLE=*gfxreconstruct* \
GFXRECON_LOG_LEVEL=info \
VK_LOADER_DEBUG=layer \
./gfxrecon-testapp-runner