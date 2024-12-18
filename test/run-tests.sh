export VK_LAYER_PATH="$PWD/vulkan/explicit_layer.d"
export VK_DRIVER_FILES="$PWD/test_apps/VkICD_mock_icd.json"
export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
export GFXRECON_CAPTURE_FILE_TIMESTAMP=false
export GFXRECON_CAPTURE_FILE=actual.gfxr
export VK_LOADER_LAYERS_DISABLE=~all~
export VK_LOADER_LAYERS_ENABLE=*gfxreconstruct*
# export GFXRECON_LOG_LEVEL=info
# export VK_LOADER_DEBUG=layer
./gfxrecon-testapp-runner