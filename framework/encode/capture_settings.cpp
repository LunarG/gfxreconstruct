/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
** Copyright (c) 2019-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/capture_settings.h"

#include "util/file_path.h"
#include "util/strings.h"
#include "util/options.h"
#include "util/platform.h"
#include "util/settings_loader.h"

#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <sstream>

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
#define CAPTURE_FRAMES_LOWER                                 "capture_frames"
#define CAPTURE_FRAMES_UPPER                                 "CAPTURE_FRAMES"
#define QUIT_AFTER_CAPTURE_FRAMES_LOWER                      "quit_after_capture_frames"
#define QUIT_AFTER_CAPTURE_FRAMES_UPPER                      "QUIT_AFTER_CAPTURE_FRAMES"
#define CAPTURE_TRIGGER_LOWER                                "capture_trigger"
#define CAPTURE_TRIGGER_UPPER                                "CAPTURE_TRIGGER"
#define CAPTURE_TRIGGER_FRAMES_LOWER                         "capture_trigger_frames"
#define CAPTURE_TRIGGER_FRAMES_UPPER                         "CAPTURE_TRIGGER_FRAMES"
#define CAPTURE_ANDROID_TRIGGER_LOWER                        "capture_android_trigger"
#define CAPTURE_ANDROID_TRIGGER_UPPER                        "CAPTURE_ANDROID_TRIGGER"
#define CAPTURE_IUNKNOWN_WRAPPING_LOWER                      "capture_iunknown_wrapping"
#define CAPTURE_IUNKNOWN_WRAPPING_UPPER                      "CAPTURE_IUNKNOWN_WRAPPING"
#define CAPTURE_QUEUE_SUBMITS_LOWER                          "capture_queue_submits"
#define CAPTURE_QUEUE_SUBMITS_UPPER                          "CAPTURE_QUEUE_SUBMITS"
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
#define EXPERIMENTAL_RAYTRACING_FASTFORWARDING_LOWER         "experimental_raytracing_fastforwarding"
#define EXPERIMENTAL_RAYTRACING_FASTFORWARDING_UPPER         "EXPERIMENTAL_RAYTRACING_FASTFORWARDING"
#define BUFFER_USAGES_TO_IGNORE_LOWER                        "buffer_usages_to_ignore"
#define BUFFER_USAGES_TO_IGNORE_UPPER                        "BUFFER_USAGES_TO_IGNORE"



#if defined(__ANDROID__)
// Android Properties
#define GFXRECON_ENV_VAR_PREFIX "debug.gfxrecon."

const char CaptureSettings::kDefaultCaptureFileName[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;

const char kCaptureCompressionTypeEnvVar[]                   = GFXRECON_ENV_VAR_PREFIX CAPTURE_COMPRESSION_TYPE_LOWER;
const char kCaptureFileFlushEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_FLUSH_LOWER;
const char kCaptureFileNameEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_NAME_LOWER;
const char kCaptureFileUseTimestampEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_USE_TIMESTAMP_LOWER;
const char kLogAllowIndentsEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX LOG_ALLOW_INDENTS_LOWER;
const char kLogBreakOnErrorEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX LOG_BREAK_ON_ERROR_LOWER;
const char kLogDetailedEnvVar[]                              = GFXRECON_ENV_VAR_PREFIX LOG_DETAILED_LOWER;
const char kLogErrorsToStderrEnvVar[]                        = GFXRECON_ENV_VAR_PREFIX LOG_ERRORS_TO_STDERR_LOWER;
const char kLogFileNameEnvVar[]                              = GFXRECON_ENV_VAR_PREFIX LOG_FILE_NAME_LOWER;
const char kLogFileCreateNewEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX LOG_FILE_CREATE_NEW_LOWER;
const char kLogFileFlushAfterWriteEnvVar[]                   = GFXRECON_ENV_VAR_PREFIX LOG_FILE_FLUSH_AFTER_WRITE_LOWER;
const char kLogFileKeepFileOpenEnvVar[]                      = GFXRECON_ENV_VAR_PREFIX LOG_FILE_KEEP_OPEN_LOWER;
const char kLogLevelEnvVar[]                                 = GFXRECON_ENV_VAR_PREFIX LOG_LEVEL_LOWER;
const char kLogOutputToConsoleEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_CONSOLE_LOWER;
const char kLogOutputToOsDebugStringEnvVar[]                 = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER;
const char kMemoryTrackingModeEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX MEMORY_TRACKING_MODE_LOWER;
const char kScreenshotDirEnvVar[]                            = GFXRECON_ENV_VAR_PREFIX SCREENSHOT_DIR_LOWER;
const char kScreenshotFormatEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX SCREENSHOT_FORMAT_LOWER;
const char kScreenshotFramesEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX SCREENSHOT_FRAMES_LOWER;
const char kCaptureFramesEnvVar[]                            = GFXRECON_ENV_VAR_PREFIX CAPTURE_FRAMES_LOWER;
const char kQuitAfterFramesEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX QUIT_AFTER_CAPTURE_FRAMES_LOWER;
const char kCaptureTriggerEnvVar[]                           = GFXRECON_ENV_VAR_PREFIX CAPTURE_TRIGGER_LOWER;
const char kCaptureTriggerFramesEnvVar[]                     = GFXRECON_ENV_VAR_PREFIX CAPTURE_TRIGGER_FRAMES_LOWER;
const char kCaptureIUnknownWrappingEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX CAPTURE_IUNKNOWN_WRAPPING_LOWER;
const char kCaptureQueueSubmitsEnvVar[]                      = GFXRECON_ENV_VAR_PREFIX CAPTURE_QUEUE_SUBMITS_LOWER;
const char kPageGuardCopyOnMapEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_COPY_ON_MAP_LOWER;
const char kPageGuardSeparateReadEnvVar[]                    = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SEPARATE_READ_LOWER;
const char kPageGuardPersistentMemoryEnvVar[]                = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_PERSISTENT_MEMORY_LOWER;
const char kPageGuardAlignBufferSizesEnvVar[]                = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_ALIGN_BUFFER_SIZES_LOWER;
const char kPageGuardTrackAhbMemoryEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_TRACK_AHB_MEMORY_LOWER;
const char kPageGuardExternalMemoryEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_EXTERNAL_MEMORY_LOWER;
const char kPageGuardUnblockSIGSEGVEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_UNBLOCK_SIGSEGV_LOWER;
const char kPageGuardSignalHandlerWatcherEnvVar[]            = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SIGNAL_HANDLER_WATCHER_LOWER;
const char kPageGuardSignalHandlerWatcherMaxRestoresEnvVar[] = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES_LOWER;
const char kDebugLayerEnvVar[]                               = GFXRECON_ENV_VAR_PREFIX DEBUG_LAYER_LOWER;
const char kDebugDeviceLostEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX DEBUG_DEVICE_LOST_LOWER;
const char kCaptureAndroidTriggerEnvVar[]                    = GFXRECON_ENV_VAR_PREFIX CAPTURE_ANDROID_TRIGGER_LOWER;
const char kDisableDxrEnvVar[]                               = GFXRECON_ENV_VAR_PREFIX DISABLE_DXR_LOWER;
const char kAccelStructPaddingEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX ACCEL_STRUCT_PADDING_LOWER;
const char kForceCommandSerializationEnvVar[]                = GFXRECON_ENV_VAR_PREFIX FORCE_COMMAND_SERIALIZATION_LOWER;
const char kQueueZeroOnlyEnvVar[]                            = GFXRECON_ENV_VAR_PREFIX QUEUE_ZERO_ONLY_LOWER;
const char kAllowPipelineCompileRequiredEnvVar[]             = GFXRECON_ENV_VAR_PREFIX ALLOW_PIPELINE_COMPILE_REQUIRED_LOWER;
const char kAnnotationExperimentalEnvVar[]                   = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_EXPERIMENTAL_LOWER;
const char kAnnotationRandEnvVar[]                           = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_RAND_LOWER;
const char kAnnotationGPUVAEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_GPUVA_LOWER;
const char kAnnotationDescriptorEnvVar[]                     = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_DESCRIPTOR_LOWER;
const char kExperimentalRaytracingFastforwardingEnvVar[]     = GFXRECON_ENV_VAR_PREFIX EXPERIMENTAL_RAYTRACING_FASTFORWARDING_UPPER;
const char kBufferUsagesToIgnoreEnvVar[]                     = GFXRECON_ENV_VAR_PREFIX BUFFER_USAGES_TO_IGNORE_LOWER;

#else
// Desktop environment settings
#define GFXRECON_ENV_VAR_PREFIX "GFXRECON_"

const char CaptureSettings::kDefaultCaptureFileName[] = "gfxrecon_capture" GFXRECON_FILE_EXTENSION;

const char kCaptureCompressionTypeEnvVar[]                   = GFXRECON_ENV_VAR_PREFIX CAPTURE_COMPRESSION_TYPE_UPPER;
const char kCaptureFileFlushEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_FLUSH_UPPER;
const char kCaptureFileNameEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_NAME_UPPER;
const char kCaptureFileUseTimestampEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX CAPTURE_FILE_USE_TIMESTAMP_UPPER;
const char kLogAllowIndentsEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX LOG_ALLOW_INDENTS_UPPER;
const char kLogBreakOnErrorEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX LOG_BREAK_ON_ERROR_UPPER;
const char kLogDetailedEnvVar[]                              = GFXRECON_ENV_VAR_PREFIX LOG_DETAILED_UPPER;
const char kLogErrorsToStderrEnvVar[]                        = GFXRECON_ENV_VAR_PREFIX LOG_ERRORS_TO_STDERR_UPPER;
const char kLogFileNameEnvVar[]                              = GFXRECON_ENV_VAR_PREFIX LOG_FILE_NAME_UPPER;
const char kLogFileCreateNewEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX LOG_FILE_CREATE_NEW_UPPER;
const char kLogFileFlushAfterWriteEnvVar[]                   = GFXRECON_ENV_VAR_PREFIX LOG_FILE_FLUSH_AFTER_WRITE_UPPER;
const char kLogFileKeepFileOpenEnvVar[]                      = GFXRECON_ENV_VAR_PREFIX LOG_FILE_KEEP_OPEN_UPPER;
const char kLogLevelEnvVar[]                                 = GFXRECON_ENV_VAR_PREFIX LOG_LEVEL_UPPER;
const char kLogOutputToConsoleEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_CONSOLE_UPPER;
const char kLogOutputToOsDebugStringEnvVar[]                 = GFXRECON_ENV_VAR_PREFIX LOG_OUTPUT_TO_OS_DEBUG_STRING_UPPER;
const char kMemoryTrackingModeEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX MEMORY_TRACKING_MODE_UPPER;
const char kScreenshotDirEnvVar[]                            = GFXRECON_ENV_VAR_PREFIX SCREENSHOT_DIR_UPPER;
const char kScreenshotFormatEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX SCREENSHOT_FORMAT_UPPER;
const char kScreenshotFramesEnvVar[]                         = GFXRECON_ENV_VAR_PREFIX SCREENSHOT_FRAMES_UPPER;
const char kCaptureFramesEnvVar[]                            = GFXRECON_ENV_VAR_PREFIX CAPTURE_FRAMES_UPPER;
const char kQuitAfterFramesEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX QUIT_AFTER_CAPTURE_FRAMES_UPPER;
const char kPageGuardCopyOnMapEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_COPY_ON_MAP_UPPER;
const char kPageGuardSeparateReadEnvVar[]                    = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SEPARATE_READ_UPPER;
const char kPageGuardPersistentMemoryEnvVar[]                = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_PERSISTENT_MEMORY_UPPER;
const char kPageGuardAlignBufferSizesEnvVar[]                = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_ALIGN_BUFFER_SIZES_UPPER;
const char kPageGuardTrackAhbMemoryEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_TRACK_AHB_MEMORY_UPPER;
const char kPageGuardExternalMemoryEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_EXTERNAL_MEMORY_UPPER;
const char kPageGuardUnblockSIGSEGVEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_UNBLOCK_SIGSEGV_UPPER;
const char kPageGuardSignalHandlerWatcherEnvVar[]            = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SIGNAL_HANDLER_WATCHER_UPPER;
const char kPageGuardSignalHandlerWatcherMaxRestoresEnvVar[] = GFXRECON_ENV_VAR_PREFIX PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES_UPPER;
const char kCaptureTriggerEnvVar[]                           = GFXRECON_ENV_VAR_PREFIX CAPTURE_TRIGGER_UPPER;
const char kCaptureTriggerFramesEnvVar[]                     = GFXRECON_ENV_VAR_PREFIX CAPTURE_TRIGGER_FRAMES_UPPER;
const char kCaptureIUnknownWrappingEnvVar[]                  = GFXRECON_ENV_VAR_PREFIX CAPTURE_IUNKNOWN_WRAPPING_UPPER;
const char kCaptureQueueSubmitsEnvVar[]                      = GFXRECON_ENV_VAR_PREFIX CAPTURE_QUEUE_SUBMITS_UPPER;
const char kDebugLayerEnvVar[]                               = GFXRECON_ENV_VAR_PREFIX DEBUG_LAYER_UPPER;
const char kDebugDeviceLostEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX DEBUG_DEVICE_LOST_UPPER;
const char kDisableDxrEnvVar[]                               = GFXRECON_ENV_VAR_PREFIX DISABLE_DXR_UPPER;
const char kAccelStructPaddingEnvVar[]                       = GFXRECON_ENV_VAR_PREFIX ACCEL_STRUCT_PADDING_UPPER;
const char kForceCommandSerializationEnvVar[]                = GFXRECON_ENV_VAR_PREFIX FORCE_COMMAND_SERIALIZATION_UPPER;
const char kQueueZeroOnlyEnvVar[]                            = GFXRECON_ENV_VAR_PREFIX QUEUE_ZERO_ONLY_UPPER;
const char kAllowPipelineCompileRequiredEnvVar[]             = GFXRECON_ENV_VAR_PREFIX ALLOW_PIPELINE_COMPILE_REQUIRED_UPPER;
const char kAnnotationExperimentalEnvVar[]                   = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_EXPERIMENTAL_UPPER;
const char kAnnotationRandEnvVar[]                           = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_RAND_UPPER;
const char kAnnotationGPUVAEnvVar[]                          = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_GPUVA_UPPER;
const char kAnnotationDescriptorEnvVar[]                     = GFXRECON_ENV_VAR_PREFIX RV_ANNOTATION_DESCRIPTOR_UPPER;
const char kExperimentalRaytracingFastforwardingEnvVar[]     = GFXRECON_ENV_VAR_PREFIX EXPERIMENTAL_RAYTRACING_FASTFORWARDING_UPPER;
const char kBufferUsagesToIgnoreEnvVar[]                     = GFXRECON_ENV_VAR_PREFIX BUFFER_USAGES_TO_IGNORE_UPPER;

#endif

// Capture options for settings file.
const char kSettingsFilter[] = "lunarg_gfxreconstruct.";

const std::string kOptionKeyCaptureCompressionType                   = std::string(kSettingsFilter) + std::string(CAPTURE_COMPRESSION_TYPE_LOWER);
const std::string kOptionKeyCaptureFile                              = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_NAME_LOWER);
const std::string kOptionKeyCaptureFileForceFlush                    = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_FLUSH_LOWER);
const std::string kOptionKeyCaptureFileUseTimestamp                  = std::string(kSettingsFilter) + std::string(CAPTURE_FILE_USE_TIMESTAMP_LOWER);
const std::string kOptionKeyLogAllowIndents                          = std::string(kSettingsFilter) + std::string(LOG_ALLOW_INDENTS_LOWER);
const std::string kOptionKeyLogBreakOnError                          = std::string(kSettingsFilter) + std::string(LOG_BREAK_ON_ERROR_LOWER);
const std::string kOptionKeyLogDetailed                              = std::string(kSettingsFilter) + std::string(LOG_DETAILED_LOWER);
const std::string kOptionKeyLogErrorsToStderr                        = std::string(kSettingsFilter) + std::string(LOG_ERRORS_TO_STDERR_LOWER);
const std::string kOptionKeyLogFile                                  = std::string(kSettingsFilter) + std::string(LOG_FILE_NAME_LOWER);
const std::string kOptionKeyLogFileCreateNew                         = std::string(kSettingsFilter) + std::string(LOG_FILE_CREATE_NEW_LOWER);
const std::string kOptionKeyLogFileFlushAfterWrite                   = std::string(kSettingsFilter) + std::string(LOG_FILE_FLUSH_AFTER_WRITE_LOWER);
const std::string kOptionKeyLogFileKeepOpen                          = std::string(kSettingsFilter) + std::string(LOG_FILE_KEEP_OPEN_LOWER);
const std::string kOptionKeyLogLevel                                 = std::string(kSettingsFilter) + std::string(LOG_LEVEL_LOWER);
const std::string kOptionKeyLogOutputToConsole                       = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_CONSOLE_LOWER);
const std::string kOptionKeyLogOutputToOsDebugString                 = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER);
const std::string kOptionKeyMemoryTrackingMode                       = std::string(kSettingsFilter) + std::string(MEMORY_TRACKING_MODE_LOWER);
const std::string kOptionKeyScreenshotDir                            = std::string(kSettingsFilter) + std::string(SCREENSHOT_DIR_LOWER);
const std::string kOptionKeyScreenshotFormat                         = std::string(kSettingsFilter) + std::string(SCREENSHOT_FORMAT_LOWER);
const std::string kOptionKeyScreenshotFrames                         = std::string(kSettingsFilter) + std::string(SCREENSHOT_FRAMES_LOWER);
const std::string kOptionKeyCaptureFrames                            = std::string(kSettingsFilter) + std::string(CAPTURE_FRAMES_LOWER);
const std::string kOptionKeyQuitAfterCaptureFrames                   = std::string(kSettingsFilter) + std::string(QUIT_AFTER_CAPTURE_FRAMES_LOWER);
const std::string kOptionKeyCaptureTrigger                           = std::string(kSettingsFilter) + std::string(CAPTURE_TRIGGER_LOWER);
const std::string kOptionKeyCaptureTriggerFrames                     = std::string(kSettingsFilter) + std::string(CAPTURE_TRIGGER_FRAMES_LOWER);
const std::string kOptionKeyCaptureIUnknownWrapping                  = std::string(kSettingsFilter) + std::string(CAPTURE_IUNKNOWN_WRAPPING_LOWER);
const std::string kOptionKeyCaptureQueueSubmits                      = std::string(kSettingsFilter) + std::string(CAPTURE_QUEUE_SUBMITS_LOWER);
const std::string kOptionKeyPageGuardCopyOnMap                       = std::string(kSettingsFilter) + std::string(PAGE_GUARD_COPY_ON_MAP_LOWER);
const std::string kOptionKeyPageGuardSeparateRead                    = std::string(kSettingsFilter) + std::string(PAGE_GUARD_SEPARATE_READ_LOWER);
const std::string kOptionKeyPageGuardPersistentMemory                = std::string(kSettingsFilter) + std::string(PAGE_GUARD_PERSISTENT_MEMORY_LOWER);
const std::string kOptionKeyPageGuardAlignBufferSizes                = std::string(kSettingsFilter) + std::string(PAGE_GUARD_ALIGN_BUFFER_SIZES_LOWER);
const std::string kOptionKeyPageGuardTrackAhbMemory                  = std::string(kSettingsFilter) + std::string(PAGE_GUARD_TRACK_AHB_MEMORY_LOWER);
const std::string kOptionKeyPageGuardExternalMemory                  = std::string(kSettingsFilter) + std::string(PAGE_GUARD_EXTERNAL_MEMORY_LOWER);
const std::string kOptionKeyPageGuardUnblockSigSegV                  = std::string(kSettingsFilter) + std::string(PAGE_GUARD_UNBLOCK_SIGSEGV_LOWER);
const std::string kOptionKeyPageGuardSignalHandlerWatcher            = std::string(kSettingsFilter) + std::string(PAGE_GUARD_SIGNAL_HANDLER_WATCHER_LOWER);
const std::string kOptionKeyPageGuardSignalHandlerWatcherMaxRestores = std::string(kSettingsFilter) + std::string(PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES_LOWER);
const std::string kDebugLayer                                        = std::string(kSettingsFilter) + std::string(DEBUG_LAYER_LOWER);
const std::string kDebugDeviceLost                                   = std::string(kSettingsFilter) + std::string(DEBUG_DEVICE_LOST_LOWER);
const std::string kOptionDisableDxr                                  = std::string(kSettingsFilter) + std::string(DISABLE_DXR_LOWER);
const std::string kOptionAccelStructPadding                          = std::string(kSettingsFilter) + std::string(ACCEL_STRUCT_PADDING_LOWER);
const std::string kOptionForceCommandSerialization                   = std::string(kSettingsFilter) + std::string(FORCE_COMMAND_SERIALIZATION_LOWER);
const std::string kOptionQueueZeroOnly                               = std::string(kSettingsFilter) + std::string(QUEUE_ZERO_ONLY_LOWER);
const std::string kOptionAllowPipelineCompileRequired                = std::string(kSettingsFilter) + std::string(ALLOW_PIPELINE_COMPILE_REQUIRED_LOWER);
const std::string kOptionKeyAnnotationExperimental                   = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_EXPERIMENTAL_LOWER);
const std::string kOptionKeyAnnotationRand                           = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_RAND_LOWER);
const std::string kOptionKeyAnnotationGPUVA                          = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_GPUVA_LOWER);
const std::string kOptionKeyAnnotationDescriptor                     = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_DESCRIPTOR_LOWER);
const std::string kOptionExperimentalRaytracingFastforwarding        = std::string(kSettingsFilter) + std::string(EXPERIMENTAL_RAYTRACING_FASTFORWARDING_LOWER);
const std::string kOptionBufferUsagesToIgnore                        = std::string(kSettingsFilter) + std::string(BUFFER_USAGES_TO_IGNORE_LOWER);

#if defined(GFXRECON_ENABLE_LZ4_COMPRESSION)
const format::CompressionType kDefaultCompressionType = format::CompressionType::kLz4;
#else
const format::CompressionType kDefaultCompressionType = format::CompressionType::kNone;
#endif
// clang-format on

CaptureSettings::CaptureSettings(const TraceSettings& trace_settings)
{
    trace_settings_ = trace_settings;
    log_settings_   = {};
}

CaptureSettings::~CaptureSettings() {}

void CaptureSettings::LoadSettings(CaptureSettings* settings)
{
    if (settings != nullptr)
    {
        OptionsMap capture_settings;

        LoadOptionsFile(&capture_settings);
        LoadOptionsEnvVar(&capture_settings);
        ProcessOptions(&capture_settings, settings);

        LoadRunTimeEnvVarSettings(settings);

        // Valid options are removed as they are read from the OptionsMap.  Therefore, if anything
        // is remaining in it after we're done, it's an invalid setting.
        if (!capture_settings.empty())
        {
            for (auto iter = capture_settings.begin(); iter != capture_settings.end(); ++iter)
            {
                GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized option \"%s\" with value \"%s\"",
                                     iter->first.c_str(),
                                     iter->second.c_str());
            }
        }
    }
}

void CaptureSettings::LoadRunTimeEnvVarSettings(CaptureSettings* settings)
{
#if defined(__ANDROID__)
    if (settings != nullptr)
    {
        OptionsMap  capture_settings;
        std::string value = util::platform::GetEnv(kCaptureAndroidTriggerEnvVar);
        settings->trace_settings_.runtime_capture_trigger =
            ParseAndroidRunTimeTrimState(value, settings->trace_settings_.runtime_capture_trigger);
        if (settings->trace_settings_.runtime_capture_trigger != RuntimeTriggerState::kNotUsed)
        {
            settings->trace_settings_.trim_boundary = TrimBoundary::kFrames;
        }
    }
#endif
}

void CaptureSettings::LoadLogSettings(CaptureSettings* settings)
{
    if (settings != nullptr)
    {
        OptionsMap capture_settings;

        LoadOptionsFile(&capture_settings);
        LoadOptionsEnvVar(&capture_settings);
        ProcessLogOptions(&capture_settings, settings);
    }
}

void CaptureSettings::LoadSingleOptionEnvVar(OptionsMap*        options,
                                             const std::string& environment_variable,
                                             const std::string& option_key)
{
    std::string value = util::platform::GetEnv(environment_variable.c_str());
    if (!value.empty())
    {
        std::string entry = util::settings::RemoveQuotes(value);
        GFXRECON_LOG_INFO(
            "Settings Loader: Found option \"%s\" with value \"%s\"", environment_variable.c_str(), entry.c_str());
        (*options)[option_key] = entry;
    }
}

void CaptureSettings::LoadOptionsEnvVar(OptionsMap* options)
{
    assert(options != nullptr);

    // Capture file environment variables
    LoadSingleOptionEnvVar(options, kCaptureFileNameEnvVar, kOptionKeyCaptureFile);
    LoadSingleOptionEnvVar(options, kCaptureFileUseTimestampEnvVar, kOptionKeyCaptureFileUseTimestamp);
    LoadSingleOptionEnvVar(options, kCaptureCompressionTypeEnvVar, kOptionKeyCaptureCompressionType);
    LoadSingleOptionEnvVar(options, kCaptureFileFlushEnvVar, kOptionKeyCaptureFileForceFlush);

    // Logging environment variables
    LoadSingleOptionEnvVar(options, kLogAllowIndentsEnvVar, kOptionKeyLogAllowIndents);
    LoadSingleOptionEnvVar(options, kLogBreakOnErrorEnvVar, kOptionKeyLogBreakOnError);
    LoadSingleOptionEnvVar(options, kLogDetailedEnvVar, kOptionKeyLogDetailed);
    LoadSingleOptionEnvVar(options, kLogErrorsToStderrEnvVar, kOptionKeyLogErrorsToStderr);
    LoadSingleOptionEnvVar(options, kLogFileNameEnvVar, kOptionKeyLogFile);
    LoadSingleOptionEnvVar(options, kLogFileCreateNewEnvVar, kOptionKeyLogFileCreateNew);
    LoadSingleOptionEnvVar(options, kLogFileFlushAfterWriteEnvVar, kOptionKeyLogFileFlushAfterWrite);
    LoadSingleOptionEnvVar(options, kLogFileKeepFileOpenEnvVar, kOptionKeyLogFileKeepOpen);
    LoadSingleOptionEnvVar(options, kLogLevelEnvVar, kOptionKeyLogLevel);
    LoadSingleOptionEnvVar(options, kLogOutputToConsoleEnvVar, kOptionKeyLogOutputToConsole);
    LoadSingleOptionEnvVar(options, kLogOutputToOsDebugStringEnvVar, kOptionKeyLogOutputToOsDebugString);

    // Memory environment variables
    LoadSingleOptionEnvVar(options, kMemoryTrackingModeEnvVar, kOptionKeyMemoryTrackingMode);

    // Trimming environment variables
    LoadSingleOptionEnvVar(options, kCaptureFramesEnvVar, kOptionKeyCaptureFrames);
    LoadSingleOptionEnvVar(options, kQuitAfterFramesEnvVar, kOptionKeyQuitAfterCaptureFrames);
    LoadSingleOptionEnvVar(options, kCaptureTriggerEnvVar, kOptionKeyCaptureTrigger);
    LoadSingleOptionEnvVar(options, kCaptureTriggerFramesEnvVar, kOptionKeyCaptureTriggerFrames);
    LoadSingleOptionEnvVar(options, kCaptureQueueSubmitsEnvVar, kOptionKeyCaptureQueueSubmits);

    // Page guard environment variables
    LoadSingleOptionEnvVar(options, kPageGuardCopyOnMapEnvVar, kOptionKeyPageGuardCopyOnMap);
    LoadSingleOptionEnvVar(options, kPageGuardSeparateReadEnvVar, kOptionKeyPageGuardSeparateRead);
    LoadSingleOptionEnvVar(options, kPageGuardPersistentMemoryEnvVar, kOptionKeyPageGuardPersistentMemory);
    LoadSingleOptionEnvVar(options, kPageGuardAlignBufferSizesEnvVar, kOptionKeyPageGuardAlignBufferSizes);
    LoadSingleOptionEnvVar(options, kPageGuardTrackAhbMemoryEnvVar, kOptionKeyPageGuardTrackAhbMemory);
    LoadSingleOptionEnvVar(options, kPageGuardExternalMemoryEnvVar, kOptionKeyPageGuardExternalMemory);
    LoadSingleOptionEnvVar(options, kPageGuardUnblockSIGSEGVEnvVar, kOptionKeyPageGuardUnblockSigSegV);
    LoadSingleOptionEnvVar(options, kPageGuardSignalHandlerWatcherEnvVar, kOptionKeyPageGuardSignalHandlerWatcher);
    LoadSingleOptionEnvVar(
        options, kPageGuardSignalHandlerWatcherMaxRestoresEnvVar, kOptionKeyPageGuardSignalHandlerWatcherMaxRestores);

    // Debug environment variables
    LoadSingleOptionEnvVar(options, kDebugLayerEnvVar, kDebugLayer);
    LoadSingleOptionEnvVar(options, kDebugDeviceLostEnvVar, kDebugDeviceLost);

    // Screenshot environment variables
    LoadSingleOptionEnvVar(options, kScreenshotDirEnvVar, kOptionKeyScreenshotDir);
    LoadSingleOptionEnvVar(options, kScreenshotFormatEnvVar, kOptionKeyScreenshotFormat);
    LoadSingleOptionEnvVar(options, kScreenshotFramesEnvVar, kOptionKeyScreenshotFrames);

    // DirectX environment variables
    LoadSingleOptionEnvVar(options, kDisableDxrEnvVar, kOptionDisableDxr);
    LoadSingleOptionEnvVar(options, kAccelStructPaddingEnvVar, kOptionAccelStructPadding);

    // IUnknown wrapping environment variable
    LoadSingleOptionEnvVar(options, kCaptureIUnknownWrappingEnvVar, kOptionKeyCaptureIUnknownWrapping);

    LoadSingleOptionEnvVar(options, kForceCommandSerializationEnvVar, kOptionForceCommandSerialization);
    LoadSingleOptionEnvVar(options, kQueueZeroOnlyEnvVar, kOptionQueueZeroOnly);
    LoadSingleOptionEnvVar(options, kAllowPipelineCompileRequiredEnvVar, kOptionAllowPipelineCompileRequired);

    // Annotated GPUVA mask
    LoadSingleOptionEnvVar(options, kAnnotationExperimentalEnvVar, kOptionKeyAnnotationExperimental);
    LoadSingleOptionEnvVar(options, kAnnotationRandEnvVar, kOptionKeyAnnotationRand);
    LoadSingleOptionEnvVar(options, kAnnotationGPUVAEnvVar, kOptionKeyAnnotationGPUVA);
    LoadSingleOptionEnvVar(options, kAnnotationDescriptorEnvVar, kOptionKeyAnnotationDescriptor);

    LoadSingleOptionEnvVar(
        options, kExperimentalRaytracingFastforwardingEnvVar, kOptionExperimentalRaytracingFastforwarding);
    LoadSingleOptionEnvVar(options, kBufferUsagesToIgnoreEnvVar, kOptionBufferUsagesToIgnore);
}

void CaptureSettings::LoadOptionsFile(OptionsMap* options)
{
    assert(options != nullptr);

    std::string settings_filename = util::settings::FindLayerSettingsFile();

    if (!settings_filename.empty())
    {
        GFXRECON_LOG_INFO("Found layer settings file: %s", settings_filename.c_str());

        int32_t result = util::settings::LoadLayerSettingsFile(settings_filename, kSettingsFilter, options);

        if (result == 0)
        {
            GFXRECON_LOG_INFO("Successfully loaded settings from file");
        }
        else
        {
            GFXRECON_LOG_INFO("Failed to load settings from file (errno = %d)", result);
        }
    }
}

void CaptureSettings::ProcessOptions(OptionsMap* options, CaptureSettings* settings)
{
    assert(settings != nullptr);

    // Capture file options
    settings->trace_settings_.capture_file_options.compression_type =
        ParseCompressionTypeString(FindOption(options, kOptionKeyCaptureCompressionType), kDefaultCompressionType);
    settings->trace_settings_.capture_file =
        FindOption(options, kOptionKeyCaptureFile, settings->trace_settings_.capture_file);
    settings->trace_settings_.time_stamp_file = ParseBoolString(FindOption(options, kOptionKeyCaptureFileUseTimestamp),
                                                                settings->trace_settings_.time_stamp_file);
    settings->trace_settings_.force_flush =
        ParseBoolString(FindOption(options, kOptionKeyCaptureFileForceFlush), settings->trace_settings_.force_flush);

    // Memory tracking options
    settings->trace_settings_.memory_tracking_mode = ParseMemoryTrackingModeString(
        FindOption(options, kOptionKeyMemoryTrackingMode), settings->trace_settings_.memory_tracking_mode);

    // Trimming options:
    // Trim frame ranges, trim queue submit ranges, and trim frame hotkey are mutually exclusive.
    // Precedence is frame ranges, queue submit ranges, then frame hotkey.
    std::string trim_frames = FindOption(options, kOptionKeyCaptureFrames);
    if (!trim_frames.empty())
    {
        ParseUintRangeList(trim_frames, &settings->trace_settings_.trim_ranges, "capture frames");
        if (!settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_boundary = TrimBoundary::kFrames;
        }
    }

    std::string trim_queue_submits = FindOption(options, kOptionKeyCaptureQueueSubmits);
    if (!trim_queue_submits.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            ParseUintRangeList(trim_queue_submits, &settings->trace_settings_.trim_ranges, "capture queue submits");
            if (!settings->trace_settings_.trim_ranges.empty())
            {
                settings->trace_settings_.trim_boundary = TrimBoundary::kQueueSubmits;
            }
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Settings Loader: Ignoring trim queue submit ranges setting as trim frame ranges has been specified.");
        }
    }

    std::string trim_key_option        = FindOption(options, kOptionKeyCaptureTrigger);
    std::string trim_key_frames_option = FindOption(options, kOptionKeyCaptureTriggerFrames);
    if (!trim_key_option.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_key = ParseTrimKeyString(trim_key_option);
            if (!trim_key_frames_option.empty())
            {
                settings->trace_settings_.trim_key_frames = ParseTrimKeyFramesString(trim_key_frames_option);
            }
            if (!settings->trace_settings_.trim_key.empty())
            {
                settings->trace_settings_.trim_boundary = TrimBoundary::kFrames;
            }
        }
        else
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring trim key setting as trim ranges has been specified.");
        }
    }

    settings->trace_settings_.quit_after_frame_ranges = ParseBoolString(
        FindOption(options, kOptionKeyQuitAfterCaptureFrames), settings->trace_settings_.quit_after_frame_ranges);

    // Page guard environment variables
    settings->trace_settings_.page_guard_copy_on_map = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardCopyOnMap), settings->trace_settings_.page_guard_copy_on_map);
    settings->trace_settings_.page_guard_separate_read = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardSeparateRead), settings->trace_settings_.page_guard_separate_read);
    settings->trace_settings_.page_guard_persistent_memory =
        ParseBoolString(FindOption(options, kOptionKeyPageGuardPersistentMemory),
                        settings->trace_settings_.page_guard_persistent_memory);
    settings->trace_settings_.page_guard_align_buffer_sizes =
        ParseBoolString(FindOption(options, kOptionKeyPageGuardAlignBufferSizes),
                        settings->trace_settings_.page_guard_align_buffer_sizes);
    settings->trace_settings_.page_guard_track_ahb_memory = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardTrackAhbMemory), settings->trace_settings_.page_guard_track_ahb_memory);
    settings->trace_settings_.page_guard_external_memory = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardExternalMemory), settings->trace_settings_.page_guard_external_memory);
    settings->trace_settings_.page_guard_unblock_sigsegv = ParseBoolString(
        FindOption(options, kOptionKeyPageGuardUnblockSigSegV), settings->trace_settings_.page_guard_unblock_sigsegv);
    settings->trace_settings_.page_guard_signal_handler_watcher =
        ParseBoolString(FindOption(options, kOptionKeyPageGuardSignalHandlerWatcher),
                        settings->trace_settings_.page_guard_signal_handler_watcher);
    settings->trace_settings_.page_guard_signal_handler_watcher_max_restores =
        ParseIntegerString(FindOption(options, kOptionKeyPageGuardSignalHandlerWatcherMaxRestores),
                           settings->trace_settings_.page_guard_signal_handler_watcher_max_restores);

    // Debug options
    settings->trace_settings_.debug_layer =
        ParseBoolString(FindOption(options, kDebugLayer), settings->trace_settings_.debug_layer);
    settings->trace_settings_.debug_device_lost =
        ParseBoolString(FindOption(options, kDebugDeviceLost), settings->trace_settings_.debug_device_lost);

    ProcessLogOptions(options, settings);

    // Screenshot options
    settings->trace_settings_.screenshot_dir =
        FindOption(options, kOptionKeyScreenshotDir, settings->trace_settings_.screenshot_dir);
    ParseUintRangeList(FindOption(options, kOptionKeyScreenshotFrames),
                       &settings->trace_settings_.screenshot_ranges,
                       "screenshot frames");
    settings->trace_settings_.screenshot_format = ParseScreenshotFormatString(
        FindOption(options, kOptionKeyScreenshotFormat), settings->trace_settings_.screenshot_format);

    // DirectX options
    settings->trace_settings_.disable_dxr =
        ParseBoolString(FindOption(options, kOptionDisableDxr), settings->trace_settings_.disable_dxr);
    settings->trace_settings_.accel_struct_padding = gfxrecon::util::ParseUintString(
        FindOption(options, kOptionAccelStructPadding), settings->trace_settings_.accel_struct_padding);

    // IUnknown wrapping option
    settings->trace_settings_.iunknown_wrapping =
        ParseBoolString(FindOption(options, kOptionKeyCaptureIUnknownWrapping), settings->trace_settings_.disable_dxr);

    settings->trace_settings_.force_command_serialization = ParseBoolString(
        FindOption(options, kOptionForceCommandSerialization), settings->trace_settings_.force_command_serialization);

    settings->trace_settings_.queue_zero_only =
        ParseBoolString(FindOption(options, kOptionQueueZeroOnly), settings->trace_settings_.queue_zero_only);

    settings->trace_settings_.allow_pipeline_compile_required =
        ParseBoolString(FindOption(options, kOptionAllowPipelineCompileRequired),
                        settings->trace_settings_.allow_pipeline_compile_required);

    settings->trace_settings_.rv_anotation_info.rv_annotation =
        ParseBoolString(FindOption(options, kOptionKeyAnnotationExperimental),
                        settings->trace_settings_.rv_anotation_info.rv_annotation);
    settings->trace_settings_.rv_anotation_info.annotation_mask_rand =
        ParseBoolString(FindOption(options, kOptionKeyAnnotationRand),
                        settings->trace_settings_.rv_anotation_info.annotation_mask_rand);
    settings->trace_settings_.rv_anotation_info.gpuva_mask = ParseUnsignedInteger16String(
        FindOption(options, kOptionKeyAnnotationGPUVA), settings->trace_settings_.rv_anotation_info.gpuva_mask);
    settings->trace_settings_.rv_anotation_info.descriptor_mask =
        ParseUnsignedInteger16String(FindOption(options, kOptionKeyAnnotationDescriptor),
                                     settings->trace_settings_.rv_anotation_info.descriptor_mask);
    settings->trace_settings_.experimental_raytracing_fastforwarding =
        ParseBoolString(FindOption(options, kOptionExperimentalRaytracingFastforwarding),
                        settings->trace_settings_.experimental_raytracing_fastforwarding);
    settings->trace_settings_.buffer_usages_to_ignore =
        ParseBufferUsages(FindOption(options, kOptionBufferUsagesToIgnore));
}

void CaptureSettings::ProcessLogOptions(OptionsMap* options, CaptureSettings* settings)
{
    // Log options
    settings->log_settings_.use_indent =
        ParseBoolString(FindOption(options, kOptionKeyLogAllowIndents), settings->log_settings_.use_indent);
    settings->log_settings_.break_on_error =
        ParseBoolString(FindOption(options, kOptionKeyLogBreakOnError), settings->log_settings_.break_on_error);
    settings->log_settings_.output_detailed_log_info =
        ParseBoolString(FindOption(options, kOptionKeyLogDetailed), settings->log_settings_.output_detailed_log_info);
    settings->log_settings_.file_name = FindOption(options, kOptionKeyLogFile, settings->log_settings_.file_name);
    settings->log_settings_.create_new =
        ParseBoolString(FindOption(options, kOptionKeyLogFileCreateNew), settings->log_settings_.create_new);
    settings->log_settings_.flush_after_write = ParseBoolString(FindOption(options, kOptionKeyLogFileFlushAfterWrite),
                                                                settings->log_settings_.flush_after_write);
    settings->log_settings_.leave_file_open =
        ParseBoolString(FindOption(options, kOptionKeyLogFileKeepOpen), settings->log_settings_.leave_file_open);
    settings->log_settings_.output_errors_to_stderr = ParseBoolString(FindOption(options, kOptionKeyLogErrorsToStderr),
                                                                      settings->log_settings_.output_errors_to_stderr);
    settings->log_settings_.write_to_console =
        ParseBoolString(FindOption(options, kOptionKeyLogOutputToConsole), settings->log_settings_.write_to_console);
    settings->log_settings_.output_to_os_debug_string = ParseBoolString(
        FindOption(options, kOptionKeyLogOutputToOsDebugString), settings->log_settings_.output_to_os_debug_string);
    settings->log_settings_.min_severity =
        ParseLogLevelString(FindOption(options, kOptionKeyLogLevel), settings->log_settings_.min_severity);
}

std::string CaptureSettings::FindOption(OptionsMap* options, const std::string& key, const std::string& default_value)
{
    assert(options != nullptr);

    std::string result = default_value;

    auto entry = options->find(key);
    if (entry != options->end())
    {
        result = entry->second;
        GFXRECON_LOG_DEBUG("Settings Loader: Found option \"%s\" with value \"%s\"", key.c_str(), result.c_str());

        // Erase the option as it comes in so that we should have no valid options remaining in the
        // map when we're done.
        options->erase(key);
    }

    return result;
}

bool CaptureSettings::ParseBoolString(const std::string& value_string, bool default_value)
{
    return gfxrecon::util::ParseBoolString(value_string, default_value);
}

uint16_t CaptureSettings::ParseUnsignedInteger16String(const std::string& value_string, uint16_t default_value)
{
    std::string::const_iterator it = value_string.begin();
    if (((value_string.compare(0, 2, "0x") == 0) || (value_string.compare(0, 2, "0X") == 0)))
    {
        it += 2;
    }
    while (it != value_string.end() && std::isxdigit(*it))
    {
        ++it;
    }
    const bool is_hex_integer = !value_string.empty() && it == value_string.end();

    if (!is_hex_integer && !value_string.empty())
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized Unsigned Integer16 option value \"%s\"",
                             value_string.c_str());
    }
    // Must be hex format
    uint32_t value = 0;
    if (is_hex_integer == true)
    {
        value = strtoul(value_string.c_str(), nullptr, 16);

        if (value > (~static_cast<uint32_t>(0x0) >> (32 - RvAnnotationUtil::kMaskSizeOfBits)))
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring oversized option value \"%s\"", value_string.c_str());
        }
    }
    // Return low 16bits
    return is_hex_integer ? static_cast<uint16_t>(value) : default_value;
}

int CaptureSettings::ParseIntegerString(const std::string& value_string, int default_value)
{
    std::string::const_iterator it = value_string.begin();
    while (it != value_string.end() && (std::isdigit(*it) || *it == '-' || *it == '+')) ++it;
    const bool is_integer = !value_string.empty() && it == value_string.end();

    if (!is_integer && !value_string.empty())
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized Integer option value \"%s\"",
                             value_string.c_str());
    }

    return is_integer ? atoi(value_string.c_str()) : default_value;
}

CaptureSettings::MemoryTrackingMode
CaptureSettings::ParseMemoryTrackingModeString(const std::string&                  value_string,
                                               CaptureSettings::MemoryTrackingMode default_value)
{
    CaptureSettings::MemoryTrackingMode result = default_value;

    if (util::platform::StringCompareNoCase("page_guard", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kPageGuard;
    }
    else if (util::platform::StringCompareNoCase("userfaultfd", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kUserfaultfd;
    }
    else if (util::platform::StringCompareNoCase("assisted", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kAssisted;
    }
    else if (util::platform::StringCompareNoCase("unassisted", value_string.c_str()) == 0)
    {
        result = MemoryTrackingMode::kUnassisted;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized memory tracking mode option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

#if defined(__ANDROID__)
CaptureSettings::RuntimeTriggerState
CaptureSettings::ParseAndroidRunTimeTrimState(const std::string&                   value_string,
                                              CaptureSettings::RuntimeTriggerState default_value)
{
    static CaptureSettings::RuntimeTriggerState result = default_value;

    if (value_string.empty())
    {
        result = RuntimeTriggerState::kNotUsed;
    }
    else
    {
        CaptureSettings::RuntimeTriggerState new_result = gfxrecon::util::ParseBoolString(value_string, false)
                                                              ? RuntimeTriggerState::kEnabled
                                                              : RuntimeTriggerState::kDisabled;

        if (new_result != result)
        {
            GFXRECON_LOG_INFO("Runtime settings: Option %s was set to %s",
                              kCaptureAndroidTriggerEnvVar,
                              new_result == RuntimeTriggerState::kEnabled ? "enabled" : "disabled");

            result = new_result;
        }
    }

    return result;
}
#endif

format::CompressionType CaptureSettings::ParseCompressionTypeString(const std::string&      value_string,
                                                                    format::CompressionType default_value)
{
    format::CompressionType result = default_value;

    if (util::platform::StringCompareNoCase("none", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kNone;
    }
    else if (util::platform::StringCompareNoCase("lz4", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kLz4;
    }
    else if (util::platform::StringCompareNoCase("zlib", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kZlib;
    }
    else if (util::platform::StringCompareNoCase("zstd", value_string.c_str()) == 0)
    {
        result = format::CompressionType::kZstd;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized compression type option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

util::Log::Severity CaptureSettings::ParseLogLevelString(const std::string&  value_string,
                                                         util::Log::Severity default_value)
{
    util::Log::Severity result;

    if (!util::Log::StringToSeverity(value_string, result))
    {
        result = default_value;
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized log level option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

void CaptureSettings::ParseUintRangeList(const std::string&            value_string,
                                         std::vector<util::UintRange>* frames,
                                         const char*                   option_name)
{
    GFXRECON_ASSERT(frames != nullptr);

    if (!value_string.empty())
    {
        std::vector<gfxrecon::util::UintRange> frame_ranges = util::GetUintRanges(value_string.c_str(), option_name);

        for (uint32_t i = 0; i < frame_ranges.size(); ++i)
        {
            util::UintRange range{};
            range.first = frame_ranges[i].first;
            range.last  = frame_ranges[i].last;
            frames->push_back(range);
        }
    }
}

std::string CaptureSettings::ParseTrimKeyString(const std::string& value_string)
{
    std::string trim_key;
    if (!value_string.empty())
    {
        trim_key = value_string;
        gfxrecon::util::strings::RemoveWhitespace(trim_key);
    }
    else
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid trim trigger key \"%s\"", trim_key.c_str());
    }
    return trim_key;
}

uint32_t CaptureSettings::ParseTrimKeyFramesString(const std::string& value_string)
{
    uint32_t frames = 0;
    size_t   digits = std::count_if(value_string.begin(), value_string.end(), ::isdigit);
    bool     valid  = false;
    if (digits == value_string.length())
    {
        int value = std::stoi(value_string);
        if (value > 0)
        {
            frames = static_cast<uint32_t>(value);
            valid  = true;
        }
    }
    if (!valid)
    {
        GFXRECON_LOG_WARNING("Settings Loader: Ignoring invalid trim trigger key frames \"%s\"", value_string.c_str());
    }
    return frames;
}

util::ScreenshotFormat CaptureSettings::ParseScreenshotFormatString(const std::string&     value_string,
                                                                    util::ScreenshotFormat default_value)
{
    util::ScreenshotFormat result = default_value;

    if (util::platform::StringCompareNoCase("bmp", value_string.c_str()) == 0)
    {
        result = util::ScreenshotFormat::kBmp;
    }
    else if (util::platform::StringCompareNoCase("png", value_string.c_str()) == 0)
    {
        result = util::ScreenshotFormat::kPng;
    }
    else
    {
        if (!value_string.empty())
        {
            GFXRECON_LOG_WARNING("Settings Loader: Ignoring unrecognized screenshot format option value \"%s\"",
                                 value_string.c_str());
        }
    }

    return result;
}

uint64_t StringToBufferUsage(std::string& str)
{
    if (str == "transfer_src") // VK_BUFFER_USAGE_TRANSFER_SRC_BIT
        return 0x00000001;
    if (str == "transfer_dst") // VK_BUFFER_USAGE_TRANSFER_DST_BIT
        return 0x00000002;
    if (str == "uniform_texel") // VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT
        return 0x00000004;
    if (str == "storage_texel") // VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT
        return 0x00000008;
    if (str == "uniform") // VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT
        return 0x00000010;
    if (str == "storage") // VK_BUFFER_USAGE_STORAGE_BUFFER_BIT
        return 0x00000020;
    if (str == "index") // VK_BUFFER_USAGE_INDEX_BUFFER_BIT
        return 0x00000040;
    if (str == "vertex") // VK_BUFFER_USAGE_VERTEX_BUFFER_BIT
        return 0x00000080;
    if (str == "indirect") // VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT
        return 0x00000100;
    if (str == "shader_address") // VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT
        return 0x00020000;
    if (str == "acc_input") // VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR
        return 0x00080000;
    if (str == "acc_storage") // VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR
        return 0x00100000;
    if (str == "shader_binding") // VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR
        return 0x00000400;
    if (str == "resource_descriptor") // VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT
        return 0x00400000;
    if (str == "push_descriptors") // VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT
        return 0x04000000;
    if (str == "ignore_all")
        return 0;

    GFXRECON_LOG_WARNING("Unimplemented usage %s", str.c_str());
    return UINT64_MAX;
}

std::vector<uint64_t> CaptureSettings::ParseBufferUsages(const std::string& value_string)
{
    std::string trimmed;
    if (!value_string.empty())
    {
        trimmed = value_string;
        gfxrecon::util::strings::RemoveWhitespace(trimmed);
    }
    else
    {
        return {};
    }
    std::vector<uint64_t>    result;
    std::vector<std::string> values = util::strings::SplitString(trimmed, ',');
    for (auto& val : values)
    {
        uint64_t                 mask = 0;
        std::vector<std::string> vals = util::strings::SplitString(val, '|');
        for (auto& v : vals)
        {
            mask |= StringToBufferUsage(v);
            GFXRECON_LOG_DEBUG("multiple opt %s", v.c_str());
        }
        result.push_back(mask);
    }
    return result;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
