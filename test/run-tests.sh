export VK_LAYER_PATH="$PWD"
export VK_DRIVER_FILES="$PWD/test_apps/VkICD_mock_icd.json"
export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
export GFXRECON_CAPTURE_FILE_TIMESTAMP=false
export GFXRECON_CAPTURE_FILE=actual.gfxr
./gfxrecon-testapp-runner.exe