export VK_LAYER_PATH="$PWD/vulkan/explicit_layer.d"
export VK_IMPLICIT_LAYER_PATH=""
export LD_LIBRARY_PATH="$PWD/vulkan/explicit_layer.d:$PWD/test_apps"
export VK_DRIVER_FILES="$PWD/test_apps/VkICD_mock_icd.json"
export VK_ICD_FILENAMES="$PWD/test_apps/VkICD_mock_icd.json"
export VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
export GFXRECON_CAPTURE_FILE_TIMESTAMP=false
export GFXRECON_CAPTURE_FILE=actual.gfxr
export VK_LOADER_LAYERS_DISABLE=~all~
export VK_LOADER_LAYERS_ENABLE=*gfxreconstruct*
export DISPLAY=:0
export GFXRECON_TESTAPP_HEADLESS=true
export GFXRECON_TESTAPP_MOCK_ICD="$PWD/test_apps/libVkICD_mock_icd.so"
#export GFXRECON_LOG_LEVEL="info"
#export VK_LOADER_DEBUG="all"

SINGLE_TEST_APP_NAME=$1
if [ -z "$SINGLE_TEST_APP_NAME" ]; then
    ./gfxrecon-testapp-runner 
else
    TEST_APPS_DIR=`pwd`/test_apps
    pushd $TEST_APPS_DIR/$SINGLE_TEST_APP_NAME
    $TEST_APPS_DIR/launcher/gfxrecon-test-launcher $SINGLE_TEST_APP_NAME
    popd
fi
