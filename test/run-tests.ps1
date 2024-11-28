$env:VK_LAYER_PATH="$pwd"
$env:VK_DRIVER_FILES="$pwd\test_apps\VkICD_mock_icd.json"
$env:VK_INSTANCE_LAYERS="VK_LAYER_LUNARG_gfxreconstruct"
$env:GFXRECON_CAPTURE_FILE_TIMESTAMP="false"
$env:GFXRECON_CAPTURE_FILE="actual.gfxr"
./gfxrecon-testapp-runner.exe