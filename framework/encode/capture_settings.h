/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
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
    };

    const static char kDefaultCaptureFileName[];

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
        util::ScreenshotFormat       screenshot_format;
        TrimBoundary                 trim_boundary{ TrimBoundary::kUnknown };
        std::vector<util::UintRange> trim_ranges;
        std::string                  trim_key;
        uint32_t                     trim_key_frames{ 0 };
        RuntimeTriggerState          runtime_capture_trigger{ kNotUsed };
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
        uint32_t                     accel_struct_padding{ 0 };
        bool                         force_command_serialization{ false };
        bool                         queue_zero_only{ false };
        bool                         allow_pipeline_compile_required{ false };
        bool                         quit_after_frame_ranges{ false };
        bool                         use_asset_file{ false };

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

    static void
    ParseUintRangeList(const std::string& value_string, std::vector<util::UintRange>* frames, const char* option_name);

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
