set VK_LAYER_PATH="$PWD/vulkan/explicit_layer.d"
set VK_DRIVER_FILES="$PWD/test_apps/VkICD_mock_icd.json"
set VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
set GFXRECON_CAPTURE_FILE_TIMESTAMP=false
set GFXRECON_CAPTURE_FILE=actual.gfxr
set VK_LOADER_LAYERS_DISABLE=~all~
set VK_LOADER_LAYERS_ENABLE=*gfxreconstruct*
set GFXRECON_LOG_LEVEL=info
set VK_LOADER_DEBUG=layer
./gfxrecon-testapp-runner