#ifndef GFXRECONSTRUCT_VERIFY_GFXR_H
#define GFXRECONSTRUCT_VERIFY_GFXR_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

void run_in_background(const char* test_name);

struct ConvertedBlock
{
    std::string function;
    /// "state" or "frame"
    std::string marker;
    /// "BeginMarker" or "EndMarker" for a marker block.
    std::string marker_type;
};

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
void verify_gfxr(const char* test_name, const char* trimming_frames = nullptr, bool trigger_trimming = false);

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
 * Run a test app with capture enabled, producing a gfxr next to the test runner for a later replay.
 *
 * Without trimming the capture is <test_name>_<test_suite>_<test_case>.gfxr. With it the capture layer adds the
 * range to that name, as <test_name>_<test_suite>_<test_case>_frame[s]_<range>.gfxr.
 *
 * @param test_name       - the name of the test app to launch and capture
 * @param trimming_frames - the frames to capture, e.g. "10" or "10-100", or nullptr to capture every frame. A range
 *                          has to start past the first frame for the capture to hold a state block.
 *
 * @note expects the same environment variables as verify_gfxr().
 */
void capture_app(const char* test_name, const char* trimming_frames = nullptr);

/**
 * Convert the gfxr that capture_app() produced for test_name and save the counts of specified Vulkan commands. These
 * are the calls the app itself made, without the ones a replay adds on top of them.
 *
 * @param test_name       - the name of the test app whose capture to count
 * @param function_names  - the Vulkan commands to count, e.g. { "vkQueueSubmit" }
 * @param[out] counts     - how often each of function_names was recorded, keyed by command name
 * @param trimming_frames - the range capture_app() was called with, or nullptr if it was called without one
 */
void count_calls_in_capture(const char*                      test_name,
                            const std::vector<std::string>&  function_names,
                            std::map<std::string, uint32_t>& counts,
                            const char*                      trimming_frames = nullptr);

/**
 * Convert the trace and return its blocks in file order.
 *
 * @param test_name       - the name of the test app whose capture to convert
 * @param[out] blocks     - the blocks of the converted capture, in file order
 * @param trimming_frames - the range capture_app() was called with, or nullptr if it was called without one
 */
void convert_capture(const char* test_name, std::vector<ConvertedBlock>& blocks, const char* trimming_frames = nullptr);

/**
 * Replay the gfxr that capture_app() produced for test_name, headless (--swapchain offscreen) against the mock ICD
 * with extra_replay_args forwarded to gfxrecon-replay. It then saves the counts of specified Vulkan commands.
 *
 * @param test_name         - the name of the test app whose capture to replay
 * @param extra_replay_args - additional arguments forwarded verbatim to gfxrecon-replay
 * @param recapture_suffix  - distinguishes this replay's recapture from another's, e.g. "_replay_baseline"
 * @param function_names    - the Vulkan commands to count, e.g. { "vkCmdPipelineBarrier" }
 * @param[out] counts       - how often each of function_names was recorded, keyed by command name
 * @param trimming_frames   - the range capture_app() was called with, or nullptr if it was called without one
 *
 * @note expects the same environment variables as verify_gfxr().
 */
void count_calls_in_recapture(const char*                      test_name,
                              std::vector<std::string>         extra_replay_args,
                              const std::string&               recapture_suffix,
                              const std::vector<std::string>&  function_names,
                              std::map<std::string, uint32_t>& counts,
                              const char*                      trimming_frames = nullptr);

/**
 * Replay and convert the recapture of that replay and return its blocks in file order.
 *
 * @param test_name         - the name of the test app whose capture to replay
 * @param extra_replay_args - additional arguments forwarded verbatim to gfxrecon-replay
 * @param recapture_suffix  - distinguishes this replay's recapture from another's, e.g. "_replay_baseline"
 * @param[out] blocks       - the blocks of the converted recapture, in file order
 * @param trimming_frames   - the range capture_app() was called with, or nullptr if it was called without one
 *
 * @note expects the same environment variables as verify_gfxr().
 */
void convert_recapture(const char*                  test_name,
                       std::vector<std::string>     extra_replay_args,
                       const std::string&           recapture_suffix,
                       std::vector<ConvertedBlock>& blocks,
                       const char*                  trimming_frames = nullptr);

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
