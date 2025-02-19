$is_admin = ([Security.Principal.WindowsPrincipal] `
              [Security.Principal.WindowsIdentity]::GetCurrent() `
            ).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator);

if ($is_admin) {
    New-Item -Path "HKLM:\SOFTWARE\Khronos"
    New-Item -Path "HKLM:\SOFTWARE\Khronos\Vulkan"
    New-Item -Path "HKLM:\SOFTWARE\Khronos\Vulkan\ImplicitLayers"
    New-ItemProperty -Path "HKLM:\SOFTWARE\Khronos\Vulkan\ImplicitLayers" -Name "$pwd\VkLayer_gfxreconstruct.json" -PropertyType "DWord" -Value 0
    New-Item -Path "HKLM:\SOFTWARE\Khronos\Vulkan\Drivers"
    New-ItemProperty -Path "HKLM:\SOFTWARE\Khronos\Vulkan\Drivers" -Name "$pwd\test_apps\VkICD_mock_icd.json" -PropertyType "DWord" -Value 0
} else {
    $env:VK_LAYER_PATH="$pwd"
    $env:VK_IMPLICIT_LAYER_PATH=""
    $env:VK_DRIVER_FILES="$pwd\test_apps\VkICD_mock_icd.json"
    $env:VK_INSTANCE_LAYERS="VK_LAYER_LUNARG_gfxreconstruct"
}
$env:VK_LOADER_LAYERS_DISABLE="~all~"
$env:VK_LOADER_LAYERS_ENABLE="*gfxreconstruct*"
$env:GFXRECON_CAPTURE_FILE_TIMESTAMP="false"
$env:GFXRECON_CAPTURE_FILE="actual.gfxr"
$env:GFXRECON_TESTAPP_HEADLESS="true"
$env:GFXRECON_TESTAPP_MOCK_ICD="$pwd\test_apps\VkICD_mock_icd.dll"
$env:GFXRECON_LOG_LEVEL=""
$env:VK_LOADER_DEBUG=""
./gfxrecon-testapp-runner.exe