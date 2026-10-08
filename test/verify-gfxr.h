#ifndef GFXRECONSTRUCT_VERIFY_GFXR_H
#define GFXRECONSTRUCT_VERIFY_GFXR_H

#include <string>
#include <vector>

void run_in_background(const char* test_name);

/**
 * Run an application with capture enabled, and compare the resulting gfxr file to a known good gfxr
 *
 * @param test_name         - the name of the test to launch
 * @param trimming_frames   - It's not nullptr if it needs to run trimming app. frame info ex: "10" or "10-100"
 *
 * @note expects the following environment variables to be set
 * VK_LAYER_PATH     - path to VkLayer_gfxreconstruct.dll
 * VK_DRIVER_FILES   - path to VkICD_mock_icd.json
 *
 * @note expects the following environment variables to be set with the following values
 * VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
 * GFXRECON_CAPTURE_FILE_TIMESTAMP=false
 * GFXRECON_CAPTURE_FILE=actual.gfxr
 */
void verify_gfxr(const char* test_name, char const* trimming_frames = nullptr, bool trigger_trimming = false);

/**
 * Run an application with capture enabled, then replay the resulting gfxr with gfxrecon-replay, asserting that the
 * replay process exits successfully.
 *
 * Replay is forced offscreen (--swapchain offscreen) so it runs headless against the mock ICD, and any additional
 * arguments are forwarded to the replay tool.
 *
 * @param test_name          - the name of the test app to launch and capture
 * @param extra_replay_args  - additional arguments forwarded verbatim to gfxrecon-replay
 *
 * @note expects the same environment variables as verify_gfxr().
 */
void capture_and_replay(const char* test_name, std::vector<std::string> extra_replay_args = {});

/**
 * Run an application with capture enabled, replay the resulting gfxr with screenshots and --screenshot-results, and
 * compare the json that replay writes about those screenshots to known_good/screenshots/<test_name>.json.
 *
 * Replay runs offscreen in the test directory with the screenshot prefix "<test_name>-screenshots", so the json is
 * "<test_name>-screenshots.json" and the images "<test_name>-screenshots_frame_N...". The json header, which holds
 * versions and the capture path, is left out of the comparison. Every image the json reports as written must exist.
 *
 * @param test_name        - the name of the test app to launch and capture
 * @param screenshot_args  - which frames to screenshot, e.g. {"--screenshot-all"} or {"--screenshots", "1-2"}
 *
 * @note expects the same environment variables as verify_gfxr().
 */
void capture_and_verify_screenshots(const char* test_name, std::vector<std::string> screenshot_args);

#endif // GFXRECONSTRUCT_VERIFY_GFXR_H
