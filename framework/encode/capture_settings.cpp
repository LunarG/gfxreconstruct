/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// clang-format off
#if defined(__ANDROID__)
// Android Properties
#define GFXRECON_ENV_VAR_PREFIX "debug.gfxrecon."
#define GFXRECON_POSTFIX LOWER
const char CaptureSettings::kDefaultCaptureFileName[] = "/sdcard/gfxrecon_capture" GFXRECON_FILE_EXTENSION;
#else
// Desktop environment settings
#define GFXRECON_ENV_VAR_PREFIX "GFXRECON_"
#define GFXRECON_POSTFIX UPPER
const char CaptureSettings::kDefaultCaptureFileName[] = "gfxrecon_capture" GFXRECON_FILE_EXTENSION;
#endif

#define GFXRECON_PASTER(x,y) x ## _ ## y
#define GFXRECON_EVALUATOR(x,y)  GFXRECON_PASTER(x,y)

#define GFXRECON_OPTION_STR(OPTION) GFXRECON_ENV_VAR_PREFIX GFXRECON_EVALUATOR(OPTION, GFXRECON_POSTFIX)

// Common capture settings
const char kCaptureCompressionTypeEnvVar[]                   = GFXRECON_OPTION_STR(CAPTURE_COMPRESSION_TYPE);
const char kCaptureFileFlushEnvVar[]                         = GFXRECON_OPTION_STR(CAPTURE_FILE_FLUSH);
const char kCaptureFileNameEnvVar[]                          = GFXRECON_OPTION_STR(CAPTURE_FILE_NAME);
const char kCaptureFileUseTimestampEnvVar[]                  = GFXRECON_OPTION_STR(CAPTURE_FILE_USE_TIMESTAMP);
const char kCaptureUseAssetFileEnvVar[]                      = GFXRECON_OPTION_STR(CAPTURE_USE_ASSET_FILE);
const char kLogAllowIndentsEnvVar[]                          = GFXRECON_OPTION_STR(LOG_ALLOW_INDENTS);
const char kLogBreakOnErrorEnvVar[]                          = GFXRECON_OPTION_STR(LOG_BREAK_ON_ERROR);
const char kLogDetailedEnvVar[]                              = GFXRECON_OPTION_STR(LOG_DETAILED);
const char kLogErrorsToStderrEnvVar[]                        = GFXRECON_OPTION_STR(LOG_ERRORS_TO_STDERR);
const char kLogFileNameEnvVar[]                              = GFXRECON_OPTION_STR(LOG_FILE_NAME);
const char kLogFileCreateNewEnvVar[]                         = GFXRECON_OPTION_STR(LOG_FILE_CREATE_NEW);
const char kLogFileFlushAfterWriteEnvVar[]                   = GFXRECON_OPTION_STR(LOG_FILE_FLUSH_AFTER_WRITE);
const char kLogFileKeepFileOpenEnvVar[]                      = GFXRECON_OPTION_STR(LOG_FILE_KEEP_OPEN);
const char kLogLevelEnvVar[]                                 = GFXRECON_OPTION_STR(LOG_LEVEL);
const char kLogTimestampsEnvVar[]                            = GFXRECON_OPTION_STR(LOG_TIMESTAMPS);
const char kLogOutputToConsoleEnvVar[]                       = GFXRECON_OPTION_STR(LOG_OUTPUT_TO_CONSOLE);
const char kLogOutputToOsDebugStringEnvVar[]                 = GFXRECON_OPTION_STR(LOG_OUTPUT_TO_OS_DEBUG_STRING);
const char kMemoryTrackingModeEnvVar[]                       = GFXRECON_OPTION_STR(MEMORY_TRACKING_MODE);
const char kScreenshotDirEnvVar[]                            = GFXRECON_OPTION_STR(SCREENSHOT_DIR);
const char kScreenshotFormatEnvVar[]                         = GFXRECON_OPTION_STR(SCREENSHOT_FORMAT);
const char kScreenshotFramesEnvVar[]                         = GFXRECON_OPTION_STR(SCREENSHOT_FRAMES);
const char kScreenshotIntervalEnvVar[]                       = GFXRECON_OPTION_STR(SCREENSHOT_INTERVAL);
const char kCaptureFramesEnvVar[]                            = GFXRECON_OPTION_STR(CAPTURE_FRAMES);
const char kCaptureDrawCallsEnvVar[]                         = GFXRECON_OPTION_STR(CAPTURE_DRAW_CALLS);
const char kQuitAfterFramesEnvVar[]                          = GFXRECON_OPTION_STR(QUIT_AFTER_CAPTURE_FRAMES);
const char kPageGuardCopyOnMapEnvVar[]                       = GFXRECON_OPTION_STR(PAGE_GUARD_COPY_ON_MAP);
const char kPageGuardSeparateReadEnvVar[]                    = GFXRECON_OPTION_STR(PAGE_GUARD_SEPARATE_READ);
const char kPageGuardPersistentMemoryEnvVar[]                = GFXRECON_OPTION_STR(PAGE_GUARD_PERSISTENT_MEMORY);
const char kPageGuardAlignBufferSizesEnvVar[]                = GFXRECON_OPTION_STR(PAGE_GUARD_ALIGN_BUFFER_SIZES);
const char kPageGuardTrackAhbMemoryEnvVar[]                  = GFXRECON_OPTION_STR(PAGE_GUARD_TRACK_AHB_MEMORY);
const char kPageGuardExternalMemoryEnvVar[]                  = GFXRECON_OPTION_STR(PAGE_GUARD_EXTERNAL_MEMORY);
const char kPageGuardUnblockSIGSEGVEnvVar[]                  = GFXRECON_OPTION_STR(PAGE_GUARD_UNBLOCK_SIGSEGV);
const char kPageGuardSignalHandlerWatcherEnvVar[]            = GFXRECON_OPTION_STR(PAGE_GUARD_SIGNAL_HANDLER_WATCHER);
const char kPageGuardSignalHandlerWatcherMaxRestoresEnvVar[] = GFXRECON_OPTION_STR(PAGE_GUARD_SIGNAL_HANDLER_WATCHER_MAX_RESTORES);
const char kCaptureTriggerEnvVar[]                           = GFXRECON_OPTION_STR(CAPTURE_TRIGGER);
const char kCaptureTriggerFramesEnvVar[]                     = GFXRECON_OPTION_STR(CAPTURE_TRIGGER_FRAMES);
const char kCaptureIUnknownWrappingEnvVar[]                  = GFXRECON_OPTION_STR(CAPTURE_IUNKNOWN_WRAPPING);
const char kCaptureQueueSubmitsEnvVar[]                      = GFXRECON_OPTION_STR(CAPTURE_QUEUE_SUBMITS);
const char kDebugLayerEnvVar[]                               = GFXRECON_OPTION_STR(DEBUG_LAYER);
const char kDebugDeviceLostEnvVar[]                          = GFXRECON_OPTION_STR(DEBUG_DEVICE_LOST);
const char kDisableDxrEnvVar[]                               = GFXRECON_OPTION_STR(DISABLE_DXR);
const char kDisableMetaCommandEnvVar[]                       = GFXRECON_OPTION_STR(DISABLE_METACOMMAND);
const char kAccelStructPaddingEnvVar[]                       = GFXRECON_OPTION_STR(ACCEL_STRUCT_PADDING);
const char kForceCommandSerializationEnvVar[]                = GFXRECON_OPTION_STR(FORCE_COMMAND_SERIALIZATION);
const char kQueueZeroOnlyEnvVar[]                            = GFXRECON_OPTION_STR(QUEUE_ZERO_ONLY);
const char kAllowPipelineCompileRequiredEnvVar[]             = GFXRECON_OPTION_STR(ALLOW_PIPELINE_COMPILE_REQUIRED);
const char kAnnotationExperimentalEnvVar[]                   = GFXRECON_OPTION_STR(RV_ANNOTATION_EXPERIMENTAL);
const char kAnnotationRandEnvVar[]                           = GFXRECON_OPTION_STR(RV_ANNOTATION_RAND);
const char kAnnotationGPUVAEnvVar[]                          = GFXRECON_OPTION_STR(RV_ANNOTATION_GPUVA);
const char kAnnotationDescriptorEnvVar[]                     = GFXRECON_OPTION_STR(RV_ANNOTATION_DESCRIPTOR);
const char kForceFifoPresentModeEnvVar[]                     = GFXRECON_OPTION_STR(FORCE_FIFO_PRESENT_MODE);
const char kIgnoreFrameBoundaryAndroidEnvVar[]               = GFXRECON_OPTION_STR(IGNORE_FRAME_BOUNDARY_ANDROID);
const char kSkipThreadsWithInvalidDataEnvVar[]               = GFXRECON_OPTION_STR(SKIP_THREADS_WITH_INVALID_DATA);
const char kCaptureEnvironmentEnvVar[]                       = GFXRECON_OPTION_STR(CAPTURE_ENVIRONMENT);
const char kCaptureProcessNameEnvVar[]                       = GFXRECON_OPTION_STR(CAPTURE_PROCESS_NAME);

#if defined(__ANDROID__)
// Android-specific capture options
const char kCaptureAndroidTriggerEnvVar[]                    = GFXRECON_OPTION_STR(CAPTURE_ANDROID_TRIGGER);
const char kCaptureAndroidDumpAssetsEnvVar[]                 = GFXRECON_OPTION_STR(CAPTURE_ANDROID_DUMP_ASSETS);
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
const std::string kOptionKeyLogTimestamps                            = std::string(kSettingsFilter) + std::string(LOG_TIMESTAMPS_LOWER);
const std::string kOptionKeyLogOutputToConsole                       = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_CONSOLE_LOWER);
const std::string kOptionKeyLogOutputToOsDebugString                 = std::string(kSettingsFilter) + std::string(LOG_OUTPUT_TO_OS_DEBUG_STRING_LOWER);
const std::string kOptionKeyMemoryTrackingMode                       = std::string(kSettingsFilter) + std::string(MEMORY_TRACKING_MODE_LOWER);
const std::string kOptionKeyScreenshotDir                            = std::string(kSettingsFilter) + std::string(SCREENSHOT_DIR_LOWER);
const std::string kOptionKeyScreenshotFormat                         = std::string(kSettingsFilter) + std::string(SCREENSHOT_FORMAT_LOWER);
const std::string kOptionKeyScreenshotFrames                         = std::string(kSettingsFilter) + std::string(SCREENSHOT_FRAMES_LOWER);
const std::string kOptionKeyScreenshotInterval                       = std::string(kSettingsFilter) + std::string(SCREENSHOT_INTERVAL_LOWER);
const std::string kOptionKeyCaptureFrames                            = std::string(kSettingsFilter) + std::string(CAPTURE_FRAMES_LOWER);
const std::string kOptionKeyCaptureDrawCalls                         = std::string(kSettingsFilter) + std::string(CAPTURE_DRAW_CALLS_LOWER);
const std::string kOptionKeyQuitAfterCaptureFrames                   = std::string(kSettingsFilter) + std::string(QUIT_AFTER_CAPTURE_FRAMES_LOWER);
const std::string kOptionKeyCaptureTrigger                           = std::string(kSettingsFilter) + std::string(CAPTURE_TRIGGER_LOWER);
const std::string kOptionKeyCaptureTriggerFrames                     = std::string(kSettingsFilter) + std::string(CAPTURE_TRIGGER_FRAMES_LOWER);
const std::string kOptionKeyCaptureIUnknownWrapping                  = std::string(kSettingsFilter) + std::string(CAPTURE_IUNKNOWN_WRAPPING_LOWER);
const std::string kOptionKeyCaptureQueueSubmits                      = std::string(kSettingsFilter) + std::string(CAPTURE_QUEUE_SUBMITS_LOWER);
const std::string kOptionKeyCaptureUseAssetFile                      = std::string(kSettingsFilter) + std::string(CAPTURE_USE_ASSET_FILE_LOWER);
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
const std::string kOptionDisableMetaCommand                          = std::string(kSettingsFilter) + std::string(DISABLE_METACOMMAND_LOWER);
const std::string kOptionAccelStructPadding                          = std::string(kSettingsFilter) + std::string(ACCEL_STRUCT_PADDING_LOWER);
const std::string kOptionForceCommandSerialization                   = std::string(kSettingsFilter) + std::string(FORCE_COMMAND_SERIALIZATION_LOWER);
const std::string kOptionQueueZeroOnly                               = std::string(kSettingsFilter) + std::string(QUEUE_ZERO_ONLY_LOWER);
const std::string kOptionAllowPipelineCompileRequired                = std::string(kSettingsFilter) + std::string(ALLOW_PIPELINE_COMPILE_REQUIRED_LOWER);
const std::string kOptionKeyAnnotationExperimental                   = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_EXPERIMENTAL_LOWER);
const std::string kOptionKeyAnnotationRand                           = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_RAND_LOWER);
const std::string kOptionKeyAnnotationGPUVA                          = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_GPUVA_LOWER);
const std::string kOptionKeyAnnotationDescriptor                     = std::string(kSettingsFilter) + std::string(RV_ANNOTATION_DESCRIPTOR_LOWER);
const std::string kOptionForceFifoPresentMode                        = std::string(kSettingsFilter) + std::string(FORCE_FIFO_PRESENT_MODE_LOWER);
const std::string kOptionIgnoreFrameBoundaryAndroid                  = std::string(kSettingsFilter) + std::string(IGNORE_FRAME_BOUNDARY_ANDROID_LOWER);
const std::string kOptionSkipThreadsWithInvalidData                  = std::string(kSettingsFilter) + std::string(SKIP_THREADS_WITH_INVALID_DATA_LOWER);
const std::string kOptionCaptureEnvironment                          = std::string(kSettingsFilter) + std::string(CAPTURE_ENVIRONMENT_LOWER);
const std::string kOptionCaptureProcessName                          = std::string(kSettingsFilter) + std::string(CAPTURE_PROCESS_NAME_LOWER);

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

void CaptureSettings::LoadSettings(CaptureSettings* settings, bool load_log_settings)
{
    if (settings != nullptr)
    {
        OptionsMap capture_settings;

        LoadOptionsFile(&capture_settings);
        LoadOptionsEnvVar(&capture_settings, load_log_settings);
        ProcessOptions(&capture_settings, settings, load_log_settings);

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

        value = util::platform::GetEnv(kCaptureAndroidDumpAssetsEnvVar);
        if (value.empty())
        {
            settings->trace_settings_.runtime_write_assets = false;
        }
        else
        {
            settings->trace_settings_.runtime_write_assets =
                ParseBoolString(value, settings->trace_settings_.runtime_write_assets);
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
        LoadOptionsEnvVar(&capture_settings, true);
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

void CaptureSettings::LoadOptionsEnvVar(OptionsMap* options, bool load_log_settings)
{
    assert(options != nullptr);

    // Capture file environment variables
    LoadSingleOptionEnvVar(options, kCaptureFileNameEnvVar, kOptionKeyCaptureFile);
    LoadSingleOptionEnvVar(options, kCaptureFileUseTimestampEnvVar, kOptionKeyCaptureFileUseTimestamp);
    LoadSingleOptionEnvVar(options, kCaptureCompressionTypeEnvVar, kOptionKeyCaptureCompressionType);
    LoadSingleOptionEnvVar(options, kCaptureFileFlushEnvVar, kOptionKeyCaptureFileForceFlush);

    // Logging environment variables
    if (load_log_settings)
    {
        LoadSingleOptionEnvVar(options, kLogAllowIndentsEnvVar, kOptionKeyLogAllowIndents);
        LoadSingleOptionEnvVar(options, kLogBreakOnErrorEnvVar, kOptionKeyLogBreakOnError);
        LoadSingleOptionEnvVar(options, kLogDetailedEnvVar, kOptionKeyLogDetailed);
        LoadSingleOptionEnvVar(options, kLogErrorsToStderrEnvVar, kOptionKeyLogErrorsToStderr);
        LoadSingleOptionEnvVar(options, kLogFileNameEnvVar, kOptionKeyLogFile);
        LoadSingleOptionEnvVar(options, kLogFileCreateNewEnvVar, kOptionKeyLogFileCreateNew);
        LoadSingleOptionEnvVar(options, kLogFileFlushAfterWriteEnvVar, kOptionKeyLogFileFlushAfterWrite);
        LoadSingleOptionEnvVar(options, kLogFileKeepFileOpenEnvVar, kOptionKeyLogFileKeepOpen);
        LoadSingleOptionEnvVar(options, kLogLevelEnvVar, kOptionKeyLogLevel);
        LoadSingleOptionEnvVar(options, kLogTimestampsEnvVar, kOptionKeyLogTimestamps);
        LoadSingleOptionEnvVar(options, kLogOutputToConsoleEnvVar, kOptionKeyLogOutputToConsole);
        LoadSingleOptionEnvVar(options, kLogOutputToOsDebugStringEnvVar, kOptionKeyLogOutputToOsDebugString);
    }

    // Memory environment variables
    LoadSingleOptionEnvVar(options, kMemoryTrackingModeEnvVar, kOptionKeyMemoryTrackingMode);

    // Trimming environment variables
    LoadSingleOptionEnvVar(options, kCaptureFramesEnvVar, kOptionKeyCaptureFrames);
    LoadSingleOptionEnvVar(options, kCaptureDrawCallsEnvVar, kOptionKeyCaptureDrawCalls);
    LoadSingleOptionEnvVar(options, kQuitAfterFramesEnvVar, kOptionKeyQuitAfterCaptureFrames);
    LoadSingleOptionEnvVar(options, kCaptureTriggerEnvVar, kOptionKeyCaptureTrigger);
    LoadSingleOptionEnvVar(options, kCaptureTriggerFramesEnvVar, kOptionKeyCaptureTriggerFrames);
    LoadSingleOptionEnvVar(options, kCaptureQueueSubmitsEnvVar, kOptionKeyCaptureQueueSubmits);
    LoadSingleOptionEnvVar(options, kCaptureUseAssetFileEnvVar, kOptionKeyCaptureUseAssetFile);

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
    LoadSingleOptionEnvVar(options, kScreenshotIntervalEnvVar, kOptionKeyScreenshotInterval);

    // DirectX environment variables
    LoadSingleOptionEnvVar(options, kDisableDxrEnvVar, kOptionDisableDxr);
    LoadSingleOptionEnvVar(options, kDisableMetaCommandEnvVar, kOptionDisableMetaCommand);
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
    LoadSingleOptionEnvVar(options, kForceFifoPresentModeEnvVar, kOptionForceFifoPresentMode);

    LoadSingleOptionEnvVar(options, kIgnoreFrameBoundaryAndroidEnvVar, kOptionIgnoreFrameBoundaryAndroid);

    LoadSingleOptionEnvVar(options, kSkipThreadsWithInvalidDataEnvVar, kOptionSkipThreadsWithInvalidData);

    LoadSingleOptionEnvVar(options, kCaptureEnvironmentEnvVar, kOptionCaptureEnvironment);
    LoadSingleOptionEnvVar(options, kCaptureProcessNameEnvVar, kOptionCaptureProcessName);
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

void CaptureSettings::ProcessOptions(OptionsMap* options, CaptureSettings* settings, bool process_log_settings)
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

    std::string trim_draw_calls = FindOption(options, kOptionKeyCaptureDrawCalls);
    if (!trim_draw_calls.empty())
    {
        std::vector<util::UintRange> trim_values;
        ParseUintRangeList(trim_draw_calls, &trim_values, "capture draw calls", false, true);
        if (trim_values.size() == 3 || trim_values.size() == 4)
        {
            settings->trace_settings_.trim_draw_calls.submit_index            = trim_values[0].first;
            settings->trace_settings_.trim_draw_calls.command_index           = trim_values[1].first;
            settings->trace_settings_.trim_draw_calls.draw_call_indices.first = trim_values[2].first;
            settings->trace_settings_.trim_draw_calls.draw_call_indices.last  = trim_values[2].last;
            settings->trace_settings_.trim_boundary                           = TrimBoundary::kDrawCalls;

            if (trim_values.size() == 4)
            {
                settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.first = trim_values[3].first;
                settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.last  = trim_values[3].last;
            }
            else
            {
                // bundle_draw_call_indices is the 4th arg. The default is 0 if it doesn't set.
                settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.first = 0;
                settings->trace_settings_.trim_draw_calls.bundle_draw_call_indices.last  = 0;
            }
        }
    }

    std::string trim_queue_submits = FindOption(options, kOptionKeyCaptureQueueSubmits);
    if (!trim_queue_submits.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            ParseUintRangeList(
                trim_queue_submits, &settings->trace_settings_.trim_ranges, "capture queue submits", true, true);
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

    std::string trim_key_option = FindOption(options, kOptionKeyCaptureTrigger);
    if (!trim_key_option.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_key = ParseTrimKeyString(trim_key_option);
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

    std::string trim_key_frames_option = FindOption(options, kOptionKeyCaptureTriggerFrames);
    if (!trim_key_frames_option.empty())
    {
        if (settings->trace_settings_.trim_ranges.empty())
        {
            settings->trace_settings_.trim_key_frames = ParseTrimKeyFramesString(trim_key_frames_option);
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "Settings Loader: Ignoring trim trigger frames setting as trim ranges has been specified.");
        }
    }

    settings->trace_settings_.quit_after_frame_ranges = ParseBoolString(
        FindOption(options, kOptionKeyQuitAfterCaptureFrames), settings->trace_settings_.quit_after_frame_ranges);

    settings->trace_settings_.use_asset_file =
        ParseBoolString(FindOption(options, kOptionKeyCaptureUseAssetFile), settings->trace_settings_.use_asset_file);

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

    if (process_log_settings)
    {
        ProcessLogOptions(options, settings);
    }

    // Screenshot options
    settings->trace_settings_.screenshot_dir =
        FindOption(options, kOptionKeyScreenshotDir, settings->trace_settings_.screenshot_dir);
    ParseUintRangeList(FindOption(options, kOptionKeyScreenshotFrames),
                       &settings->trace_settings_.screenshot_ranges,
                       "screenshot frames");
    settings->trace_settings_.screenshot_interval = ParseIntegerString(
        FindOption(options, kOptionKeyScreenshotInterval), settings->trace_settings_.screenshot_interval);
    if (settings->trace_settings_.screenshot_interval == 0)
    {
        GFXRECON_LOG_WARNING(
            "A screenshot interval of 0 has been specified, which is invalid. An interval of 1 will be used.");
        settings->trace_settings_.screenshot_interval = 1;
    }
    settings->trace_settings_.screenshot_format = ParseScreenshotFormatString(
        FindOption(options, kOptionKeyScreenshotFormat), settings->trace_settings_.screenshot_format);

    // DirectX options
    settings->trace_settings_.disable_dxr =
        ParseBoolString(FindOption(options, kOptionDisableDxr), settings->trace_settings_.disable_dxr);
    settings->trace_settings_.disable_meta_command =
        ParseBoolString(FindOption(options, kOptionDisableMetaCommand), settings->trace_settings_.disable_meta_command);
    settings->trace_settings_.accel_struct_padding = gfxrecon::util::ParseUintString(
        FindOption(options, kOptionAccelStructPadding), settings->trace_settings_.accel_struct_padding);

    // IUnknown wrapping option
    settings->trace_settings_.iunknown_wrapping = ParseBoolString(
        FindOption(options, kOptionKeyCaptureIUnknownWrapping), settings->trace_settings_.iunknown_wrapping);

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
    settings->trace_settings_.force_fifo_present_mode = ParseBoolString(
        FindOption(options, kOptionForceFifoPresentMode), settings->trace_settings_.force_fifo_present_mode);

    settings->trace_settings_.ignore_frame_boundary_android =
        ParseBoolString(FindOption(options, kOptionIgnoreFrameBoundaryAndroid),
                        settings->trace_settings_.ignore_frame_boundary_android);

    // Skip threads with invalid data
    settings->trace_settings_.skip_threads_with_invalid_data =
        ParseBoolString(FindOption(options, kOptionSkipThreadsWithInvalidData),
                        settings->trace_settings_.skip_threads_with_invalid_data);

    // Capture environment variables
    settings->trace_settings_.capture_environment =
        util::strings::SplitString(FindOption(options, kOptionCaptureEnvironment), ',');
    settings->trace_settings_.capture_process_name =
        FindOption(options, kOptionCaptureProcessName, settings->trace_settings_.capture_process_name);
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
    settings->log_settings_.output_timestamps =
        ParseBoolString(FindOption(options, kOptionKeyLogTimestamps), settings->log_settings_.output_timestamps);
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

util::LoggingSeverity CaptureSettings::ParseLogLevelString(const std::string&    value_string,
                                                           util::LoggingSeverity default_value)
{
    util::LoggingSeverity result;

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
                                         const char*                   option_name,
                                         bool                          check_overlap_range,
                                         bool                          allow_zero)
{
    GFXRECON_ASSERT(frames != nullptr);

    if (!value_string.empty())
    {
        std::vector<gfxrecon::util::UintRange> frame_ranges =
            util::GetUintRanges(value_string.c_str(), option_name, check_overlap_range, allow_zero);

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
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
