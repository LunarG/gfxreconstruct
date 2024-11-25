#ifndef GFXRECONSTRUCT_VERIFY_GFXR_H
#define GFXRECONSTRUCT_VERIFY_GFXR_H

/*
 * Run an application with capture enabled, and compare the resulting gfxr file to a known good gfxr
 *
 * app_run_directory - the directory to run the application from,  relative to APP_PATH_BASE env var
 * app_path          - the path to the application, relative to app_run_directory
 * capture_file      - path to the capture file, relative to the app_run_directory. GFXRECON_CAPTURE_FILE gets set to this, with timestamp disabled
 * known_gfxr_path   - path to the known good gfxr file, relative to the KNOWN_GFXR_PATH_BASE env var
 *
 * expects the following environment variables to be set
 * APP_PATH_BASE        - absolute path to a folder containing all test apps
 * KNOWN_GFXR_PATH_BASE = absolute path to a folder containing all known good gfxr files
 * MOCK_DRIVER_PATH     = absolute path to the driver file json to use
 * GFXR_LAYER_PATH      = absolute path to the gfxr layer.  VK_LAYER_PATH is set to this
 * GFXR_CONVERT_PATH    = absolute path to the gfxr conver tool
 */
void verify_gfxr(char const* app_run_directory,
                 char const* app_path,
                 char const* capture_file,
                 char const* known_gfxr_path);

#endif // GFXRECONSTRUCT_VERIFY_GFXR_H
