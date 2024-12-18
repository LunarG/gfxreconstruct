#ifndef GFXRECONSTRUCT_VERIFY_GFXR_H
#define GFXRECONSTRUCT_VERIFY_GFXR_H

/*
 * Run an application with capture enabled, and compare the resulting gfxr file to a known good gfxr
 *
 * app_run_directory - the directory to run the application from,  relative to test_apps folder
 * app_path          - the path to the application, relative to app_run_directory
 * known_gfxr_path   - path to the known good gfxr file, relative to the known_good folder
 *
 * expects the following environment variables to be set
 * VK_LAYER_PATH     - path to VkLayer_gfxreconstruct.dll
 * VK_DRIVER_FILES   - path to VkICD_mock_icd.json
 *
 * expects the following environment variables to be set with the following values
 * VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
 * GFXRECON_CAPTURE_FILE_TIMESTAMP=false
 * GFXRECON_CAPTURE_FILE=actual.gfxr
 */
void verify_gfxr(char const* app_directory, char const* app_executable, char const* known_gfxr_path);

#endif // GFXRECONSTRUCT_VERIFY_GFXR_H
