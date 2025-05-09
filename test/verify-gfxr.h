#ifndef GFXRECONSTRUCT_VERIFY_GFXR_H
#define GFXRECONSTRUCT_VERIFY_GFXR_H

void run_in_background(const char* test_name);

/*
 * Run an application with capture enabled, and compare the resulting gfxr file to a known good gfxr
 *
 * test_name         - the name of the test to launch
 * known_gfxr_path   - path to the known good gfxr file, relative to the known_good folder
 * trimming_frames   - It's not nullptr if it needs to run trimming app. frame info ex: "10" or "10-100"
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
void verify_gfxr(const char* test_name, char const* known_gfxr_path, char const* trimming_frames = nullptr);

#endif // GFXRECONSTRUCT_VERIFY_GFXR_H
