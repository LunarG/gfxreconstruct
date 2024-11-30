$is_admin = ([Security.Principal.WindowsPrincipal] `
              [Security.Principal.WindowsIdentity]::GetCurrent() `
            ).IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator);

if ($is_admin) {
    New-ItemProperty -Path "HKLM:\SOFTWARE\Khronos\Vulkan\ImplicitLayers" -Name "$pwd\VkLayer_gfxreconstruct.json" -PropertyType "DWord" -Value 0
    New-ItemProperty -Path "HKLM:\SOFTWARE\Khronos\Vulkan\Drivers" -Name "$pwd\test_apps\VkICD_mock_icd.json" -PropertyType "DWord" -Value 0
} else {
    $env:VK_LAYER_PATH="$pwd"
    $env:VK_DRIVER_FILES="$pwd\test_apps\VkICD_mock_icd.json"
    $env:VK_INSTANCE_LAYERS="VK_LAYER_LUNARG_gfxreconstruct"
}
$env:GFXRECON_CAPTURE_FILE_TIMESTAMP="false"
$env:GFXRECON_CAPTURE_FILE="actual.gfxr"
$env:VK_LOADER_DEBUG="info"
./gfxrecon-testapp-runner.exe