/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019-2025 Advanced Micro Devices, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_ENCODE_CAPTURE_SETTINGS_H
#define GFXRECON_ENCODE_CAPTURE_SETTINGS_H

#include "encode/dx12_rv_annotation_util.h"
#include "format/format.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/options.h"

#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Available settings (upper and lower-case)
// clang-format off
#define CAPTURE_COMPRESSION_TYPE_LOWER                       "capture_compression_type"
#define CAPTURE_COMPRESSION_TYPE_UPPER                       "CAPTURE_COMPRESSION_TYPE"
#define CAPTURE_FILE_NAME_LOWER                              "capture_file"
#define CAPTURE_FILE_NAME_UPPER                              "CAPTURE_FILE"
#define CAPTURE_FILE_USE_TIMESTAMP_LOWER                     "capture_file_timestamp"
#define CAPTURE_FILE_USE_TIMESTAMP_UPPER                     "CAPTURE_FILE_TIMESTAMP"
#define CAPTURE_FILE_FLUSH_LOWER                             "capture_file_flush"
#define CAPTURE_FILE_FLUSH_UPPER                             "CAPTURE_FILE_FLUSH"
#define LOG_ALLOW_INDENTS_LOWER                              "log_allow_indents"
#define LOG_ALLOW_INDENTS_UPPER                              "LOG_ALLOW_INDENTS"
#define LOG_BREAK_ON_ERROR_LOWER                             "log_break_on_error"
#define LOG_BREAK_ON_ERROR_UPPER                             "LOG_BREAK_ON_ERROR"
#define LOG_ERRORS_TO_STDERR_LOWER                           "log_errors_to_stderr"
#define LOG_ERRORS_TO_STDERR_UPPER                           "LOG_ERRORS_TO_STDERR"
#define LOG_DETAILED_LOWER                                   "log_detailed"
#define LOG_DETAILED_UPPER                                   "LOG_DETAILED"
#define LOG_FILE_NAME_LOWER                                  "log_file"
#define LOG_FILE_NAME_UPPER                                  "LOG_FILE"
#define LOG_FILE_CREATE_NEW_LOWER                            "log_file_create_new"
#define LOG_FILE_CREATE_NEW_UPPER                            "LOG_FILE_CREATE_NEW"
#define LOG_FILE_FLUSH_AFTER_WRITE_LOWER                     "log_file_flush_after_write"
#define LOG_FILE_FLUSH_AFTER_WRITE_UPPER                     "LOG_FILE_FLUSH_AFTER_WRITE"
#define LOG_FILE_KEEP_OPEN_LOWER                             "log_file_keep_open"
#define LOG_FILE_KEEP_OPEN_UPPER                             "LOG_FILE_KEEP_OPEN"
#define LOG_LEVEL_LOWER                                      "log_level"
#define LOG_LEVEL_UPPER                                      "LOG_LEVEL"
#define LOG_TIMESTAMPS_LOWER                                 "log_timestamps"
#define LOG_TIMESTAMPS_UPPER                                 "LOG_TIMESTAMPS"
#define LOG_OUTPUT_TO_CONSOLE_LOWER                          "log_output_to_console"
#define LOG_OUTPUT_TO_CONSOLE_UPPER                          "LOG_OUTPUT_TO_CONSOLE"
#define LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER                  "log_output_to_os_debug_string"
#define LOG_OUTPUT_TO_OS_DEBUG_STRING_UPPER                  "LOG_OUTPUT_TO_OS_DEBUG_STRING"
#define MEMORY_TRACKING_MODE_LOWER                           "memory_tracking_mode"
#define MEMORY_TRACKING_MODE_UPPER                           "MEMORY_TRACKING_MODE"
#define SCREENSHOT_DIR_LOWER                                 "screenshot_dir"
#define SCREENSHOT_DIR_UPPER                                 "SCREENSHOT_DIR"
#define SCREENSHOT_FORMAT_LOWER                              "screenshot_format"
#define SCREENSHOT_FORMAT_UPPER                              "SCREENSHOT_FORMAT"
#define SCREENSHOT_FRAMES_LOWER                              "screenshot_frames"
#define SCREENSHOT_FRAMES_UPPER                              "SCREENSHOT_FRAMES"
#define SCREENSHOT_INTERVAL_LOWER                            "screenshot_interval"
#define SCREENSHOT_INTERVAL_UPPER                            "SCREENSHOT_INTERVAL"
#define CAPTURE_FRAMES_LOWER                                 "capture_frames"
#define CAPTURE_FRAMES_UPPER                                 "CAPTURE_FRAMES"
#define CAPTURE_DRAW_CALLS_LOWER                             "capture_draw_calls"
#define CAPTURE_DRAW_CALLS_UPPER                             "CAPTURE_DRAW_CALLS"
#define QUIT_AFTER_CAPTURE_FRAMES_LOWER                      "quit_after_capture_frames"
#define QUIT_AFTER_CAPTURE_FRAMES_UPPER                      "QUIT_AFTER_CAPTURE_FRAMES"
#define CAPTURE_TRIGGER_LOWER                                "capture_trigger"
#define CAPTURE_TRIGGER_UPPER                                "CAPTURE_TRIGGER"
#define CAPTURE_TRIGGER_FRAMES_LOWER                         "capture_trigger_frames"
#define CAPTURE_TRIGGER_FRAMES_UPPER                         "CAPTURE_TRIGGER_FRAMES"
#define CAPTURE_ANDROID_TRIGGER_LOWER                        "capture_android_trigger"
#define CAPTURE_ANDROID_TRIGGER_UPPER                        "CAPTURE_ANDROID_TRIGGER"
#define CAPTURE_ANDROID_DUMP_ASSETS_LOWER                    "capture_android_dump_assets"
#define CAPTURE_ANDROID_DUMP_ASSETS_UPPER                    "CAPTURE_ANDROID_DUMP_ASSETS"
#define CAPTURE_IUNKNOWN_WRAPPING_LOWER                      "capture_iunknown_wrapping"
#define CAPTURE_IUNKNOWN_WRAPPING_UPPER                      "CAPTURE_IUNKNOWN_WRAPPING"
#define CAPTURE_QUEUE_SUBMITS_LOWER                          "capture_queue_submits"
#define CAPTURE_QUEUE_SUBMITS_UPPER                          "CAPTURE_QUEUE_SUBMITS"
#define CAPTURE_USE_ASSET_FILE_LOWER                         "capture_use_asset_file"
#define CAPTURE_USE_ASSET_FILE_UPPER                         "CAPTURE_USE_ASSET_FILE"
#define PAGE_GUARD_COPY_ON_MAP_LOWER                         "page_guard_copy_on_map"
#define PAGE_GUARD_COPY_ON_MAP_UPPER                         "PAGE_GUARD_COPY_ON_MAP"
#define PAGE_GUARD_SEPARATE_READ_LOWER                       "page_guard_separate_read"
#define PAGE_GUARD_SEPARATE_READ_UPPER                       "PAGE_GUARD_SEPARATE_READ"
#define PAGE_GUARD_PERSISTENT_MEMORY_LOWER                   "page_guard_persistent_memory"
#define PAGE_GUARD_PERSISTENT_MEMORY_UPPER                   "PAGE_GUARD_PERSISTENT_MEMORY"
#define PAGE_GUARD_ALIGN_BUFFER_SIZES_LOWER                  "page_guard_align_buffer_sizes"
#define PAGE_GUARD_ALIGN_BUFFER_SIZES_UPPER                  "PAGE_GUARD_ALIGN_BUFFER_SIZES"
#define PAGE_GUARD_TRACK_AHB_MEMORY_LOWER                    "page_guard_track_ahb_memory"
#define PAGE_GUARD_TRACK_AHB_MEMORY_UPPER                    "PAGE_GUARD_TRACK_AHB_MEMORY"
#define PAGE_GUARD_EXTERNAL_MEMORY_LOWER                     "page_guard_external_memory"
#define PAGE_GUARD_EXTERNAL_MEMORY_UPPER                     "PAGE_GUARD_EXTERNAL_MEMORY"
#define PAGE_GUARD_UNBLOCK_SIGSEGV_LOWER                     "page_guard_unblock_sigsegv"
#define PAGE_GUARD_UNBLOCK_SIGSEGV_UPPER                     "PAGE_GUARD_UNBLOCK_SIGSEGV"
#define PAGE_GUARD_SIGNAL_HANDLER_WATCHER_LOWER              "page_guard_signal_handler_watcher"
#define PAGE_GUARD_SIGNAL_HANDLER_WATCHER_UPPER              "PAGE_GUARD_SIGNAL_HANDLER_WATCHER"
#define PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES_LOWER "page_guard_signal_handler_watcher_max_restores"
#define PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES_UPPER "PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES"
#define DEBUG_LAYER_LOWER                                    "debug_layer"
#define DEBUG_LAYER_UPPER                                    "DEBUG_LAYER"
#define DEBUG_DEVICE_LOST_LOWER                              "debug_device_lost"
#define DEBUG_DEVICE_LOST_UPPER                              "DEBUG_DEVICE_LOST"
#define DISABLE_DXR_LOWER                                    "disable_dxr"
#define DISABLE_DXR_UPPER                                    "DISABLE_DXR"
#define DISABLE_METACOMMAND_LOWER                            "disable_meta_command"
#define DISABLE_METACOMMAND_UPPER                            "DISABLE_META_COMMAND"
#define ACCEL_STRUCT_PADDING_LOWER                           "accel_struct_padding"
#define ACCEL_STRUCT_PADDING_UPPER                           "ACCEL_STRUCT_PADDING"
#define FORCE_COMMAND_SERIALIZATION_LOWER                    "force_command_serialization"
#define FORCE_COMMAND_SERIALIZATION_UPPER                    "FORCE_COMMAND_SERIALIZATION"
#define QUEUE_ZERO_ONLY_LOWER                                "queue_zero_only"
#define QUEUE_ZERO_ONLY_UPPER                                "QUEUE_ZERO_ONLY"
#define ALLOW_PIPELINE_COMPILE_REQUIRED_LOWER                "allow_pipeline_compile_required"
#define ALLOW_PIPELINE_COMPILE_REQUIRED_UPPER                "ALLOW_PIPELINE_COMPILE_REQUIRED"
#define RV_ANNOTATION_EXPERIMENTAL_LOWER                     "rv_annotation_experimental"
#define RV_ANNOTATION_EXPERIMENTAL_UPPER                     "RV_ANNOTATION_EXPERIMENTAL"
#define RV_ANNOTATION_RAND_LOWER                             "rv_annotation_rand"
#define RV_ANNOTATION_RAND_UPPER                             "RV_ANNOTATION_RAND"
#define RV_ANNOTATION_GPUVA_LOWER                            "rv_annotation_gpuva"
#define RV_ANNOTATION_GPUVA_UPPER                            "RV_ANNOTATION_GPUVA"
#define RV_ANNOTATION_DESCRIPTOR_LOWER                       "rv_annotation_descriptor"
#define RV_ANNOTATION_DESCRIPTOR_UPPER                       "RV_ANNOTATION_DESCRIPTOR"
#define FORCE_FIFO_PRESENT_MODE_LOWER                        "force_fifo_present_mode"
#define FORCE_FIFO_PRESENT_MODE_UPPER                        "FORCE_FIFO_PRESENT_MODE"
#define IGNORE_FRAME_BOUNDARY_ANDROID_LOWER                  "ignore_frame_boundary_android"
#define IGNORE_FRAME_BOUNDARY_ANDROID_UPPER                  "IGNORE_FRAME_BOUNDARY_ANDROID"
#define SKIP_THREADS_WITH_INVALID_DATA_LOWER                 "skip_threads_with_invalid_data"
#define SKIP_THREADS_WITH_INVALID_DATA_UPPER                 "SKIP_THREADS_WITH_INVALID_DATA"
#define CAPTURE_ENVIRONMENT_LOWER                            "capture_environment"
#define CAPTURE_ENVIRONMENT_UPPER                            "CAPTURE_ENVIRONMENT"
#define CAPTURE_PROCESS_NAME_LOWER                           "capture_process_name"
#define CAPTURE_PROCESS_NAME_UPPER                           "CAPTURE_PROCESS_NAME"
// clang-format on

class CaptureSettings
{
  public:
    enum MemoryTrackingMode
    {
        // Assume the application does not flush, so write all mapped data on unmap and queue submit.
        kUnassisted = 0,
        // Assume the application will always flush after writing to mapped memory, so only write mapped memory data on
        // flush.
        kAssisted = 1,
        // Use guard pages to determine which regions of memory to write on unmap and queue submit.  This mode replaces
        // the mapped memory value returned by the driver with a shadow allocation that the capture layer can monitor,
        // using the PROT_NONE + SIGSEGV trick, to determine which regions of memory have been modified by the
        // application.
        kPageGuard = 2,
        // Similar mechanism as page guard. The mapper memory returned by the driver is replaced by a shadow
        // allocation but in this case the memory is monitored using the userfaultfd mechanism provided by the linux
        // kernel.
        kUserfaultfd = 3
    };

    enum RuntimeTriggerState
    {
        // Property for trimmed capture not set at all.
        kNotUsed = 0,
        // Property for trimmed capture set to false.
        kEnabled = 1,
        // Property for trimmed capture set to true.
        kDisabled = 2
    };

    enum class TrimBoundary
    {
        kUnknown,
        kFrames,
        kQueueSubmits,
        kDrawCalls,
    };

    const static char kDefaultCaptureFileName[];

    struct TrimDrawCalls
    {
        // 0-based
        uint32_t        submit_index{ 0 };
        uint32_t        command_index{ 0 };
        util::UintRange draw_call_indices;
        util::UintRange bundle_draw_call_indices;
    };

    struct ResourveValueAnnotationInfo
    {
        // Annotated GPUVA mask definition
        bool     rv_annotation{ false };
        bool     annotation_mask_rand{ false };
        uint16_t gpuva_mask{ RvAnnotationUtil::kGPUVAMask };
        uint16_t descriptor_mask{ RvAnnotationUtil::kDescriptorMask };
    };

    struct TraceSettings
    {
        std::string                  capture_file{ kDefaultCaptureFileName };
        format::EnabledOptions       capture_file_options;
        bool                         time_stamp_file{ true };
        bool                         force_flush{ false };
        MemoryTrackingMode           memory_tracking_mode{ kPageGuard };
        std::string                  screenshot_dir;
        std::vector<util::UintRange> screenshot_ranges;
        uint32_t                     screenshot_interval{ 1 };
        util::ScreenshotFormat       screenshot_format;
        TrimBoundary                 trim_boundary{ TrimBoundary::kUnknown };
        std::vector<util::UintRange> trim_ranges;
        TrimDrawCalls                trim_draw_calls;
        std::string                  trim_key;
        uint32_t                     trim_key_frames{ 0 };
        RuntimeTriggerState          runtime_capture_trigger{ kNotUsed };
        std::string                  capture_process_name{ "" };
        bool                         runtime_write_assets{ false };
        int                          page_guard_signal_handler_watcher_max_restores{ 1 };
        bool                         page_guard_copy_on_map{ util::PageGuardManager::kDefaultEnableCopyOnMap };
        bool                         page_guard_separate_read{ util::PageGuardManager::kDefaultEnableSeparateRead };
        bool                         page_guard_persistent_memory{ false };
        bool                         page_guard_align_buffer_sizes{ true };
        bool                         page_guard_track_ahb_memory{ false };
        bool                         page_guard_unblock_sigsegv{ false };
        bool                         page_guard_signal_handler_watcher{ false };
        bool                         debug_layer{ false };
        bool                         debug_device_lost{ false };
        bool                         disable_dxr{ false };
        bool                         disable_meta_command{ false };
        uint32_t                     accel_struct_padding{ 0 };
        bool                         force_command_serialization{ false };
        bool                         queue_zero_only{ false };
        bool                         allow_pipeline_compile_required{ false };
        bool                         quit_after_frame_ranges{ false };
        bool                         force_fifo_present_mode{ true };
        bool                         use_asset_file{ false };
        bool                         ignore_frame_boundary_android{ false };
        bool                         skip_threads_with_invalid_data{ false };
        std::vector<std::string>     capture_environment;

        // An optimization for the page_guard memory tracking mode that eliminates the need for shadow memory by
        // overriding vkAllocateMemory so that all host visible allocations use the external memory extension with a
        // memory allocation that the capture layer can monitor to determine which regions of memory have been modified
        // by the application.
        bool page_guard_external_memory{ false };

        // IUnknown wrapping option
        bool iunknown_wrapping{ false };

        ResourveValueAnnotationInfo rv_anotation_info{};
    };

  public:
    CaptureSettings() = default;
    CaptureSettings(const TraceSettings& trace_settings);

    ~CaptureSettings();

    const TraceSettings& GetTraceSettings() const { return trace_settings_; }

    const util::Log::Settings& GetLogSettings() const { return log_settings_; }

    // Load all settings.
    static void LoadSettings(CaptureSettings* settings);
    static void LoadRunTimeEnvVarSettings(CaptureSettings* settings);

    // Load only log settings.
    static void LoadLogSettings(CaptureSettings* settings);

  private:
    typedef std::unordered_map<std::string, std::string> OptionsMap;

  private:
    static void
    LoadSingleOptionEnvVar(OptionsMap* options, const std::string& environment_variable, const std::string& option_key);

    static void LoadOptionsEnvVar(OptionsMap* options);

    static void LoadOptionsFile(OptionsMap* options);

    static void ProcessOptions(OptionsMap* options, CaptureSettings* settings);

    static void ProcessLogOptions(OptionsMap* options, CaptureSettings* settings);

    static std::string FindOption(OptionsMap* options, const std::string& key, const std::string& default_value = "");

    static bool ParseBoolString(const std::string& value_string, bool default_value);

    static int ParseIntegerString(const std::string& value_string, int default_value);

    static uint16_t ParseUnsignedInteger16String(const std::string& value_string, uint16_t default_value);

    static MemoryTrackingMode ParseMemoryTrackingModeString(const std::string& value_string,
                                                            MemoryTrackingMode default_value);

#if defined(__ANDROID__)
    static RuntimeTriggerState ParseAndroidRunTimeTrimState(const std::string&  value_string,
                                                            RuntimeTriggerState default_value);
#endif

    static format::CompressionType ParseCompressionTypeString(const std::string&      value_string,
                                                              format::CompressionType default_value);

    static util::Log::Severity ParseLogLevelString(const std::string& value_string, util::Log::Severity default_value);

    static void ParseUintRangeList(const std::string&            value_string,
                                   std::vector<util::UintRange>* frames,
                                   const char*                   option_name,
                                   bool                          check_overlap_range = true,
                                   bool                          allow_zero          = false);

    static std::string ParseTrimKeyString(const std::string& value_string);

    static uint32_t ParseTrimKeyFramesString(const std::string& value_string);

    static util::ScreenshotFormat ParseScreenshotFormatString(const std::string&     value_string,
                                                              util::ScreenshotFormat default_value);

  private:
    TraceSettings       trace_settings_;
    util::Log::Settings log_settings_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CAPTURE_SETTINGS_H
