/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
** Copyright (c) 2019-2021 Advanced Micro Devices, Inc. All rights reserved.
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
  private:
    const static char kDefaultCaptureFileName[];

  public:
    enum MemoryTrackingMode
    {
        // Assume the application does not flush, so write all mapped data on unmap and queue submit.
        kUnassisted = 0,
        // Assume the application will always flush after writing to mapped memory, so only write mapped memory data on
        // flush.
        kAssisted = 1,
        // Use guard pages to determine which regions of memory to write on unmap and queue submit.  This mode replaces
        // the mapped memory value returned by the driver with a shadow allocation that the capture layer can monitor
        // to determine which regions of memory have been modified by the application.
        kPageGuard = 2
    };

    struct TrimRange
    {
        uint32_t first{ 0 }; // First frame to capture.
        uint32_t total{ 0 }; // Total number of frames to capture.
    };

    struct TraceSettings
    {
        std::string                   capture_file{ kDefaultCaptureFileName };
        format::EnabledOptions        capture_file_options;
        bool                          time_stamp_file{ true };
        bool                          force_flush{ false };
        MemoryTrackingMode            memory_tracking_mode{ kPageGuard };
        std::string                   screenshot_dir;
        std::vector<util::FrameRange> screenshot_ranges;
        std::vector<TrimRange>        trim_ranges;
        std::string                   trim_key;
        uint32_t                      trim_key_frames{ 0 };
        bool                          page_guard_copy_on_map{ util::PageGuardManager::kDefaultEnableCopyOnMap };
        bool                          page_guard_separate_read{ util::PageGuardManager::kDefaultEnableSeparateRead };
        bool                          page_guard_persistent_memory{ false };
        bool                          page_guard_align_buffer_sizes{ false };
        bool                          page_guard_track_ahb_memory{ false };
        bool                          debug_layer{ false };
        bool                          debug_device_lost{ false };

        // An optimization for the page_guard memory tracking mode that eliminates the need for shadow memory by
        // overriding vkAllocateMemory so that all host visible allocations use the external memory extension with a
        // memory allocation that the capture layer can monitor to determine which regions of memory have been modified
        // by the application.
        bool page_guard_external_memory{ false };
    };

  public:
    CaptureSettings(const TraceSettings& trace_settings);

    ~CaptureSettings();

    const TraceSettings& GetTraceSettings() const { return trace_settings_; }

    const util::Log::Settings& GetLogSettings() const { return log_settings_; }

    // Load all settings.
    static void LoadSettings(CaptureSettings* settings);

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

    static MemoryTrackingMode ParseMemoryTrackingModeString(const std::string& value_string,
                                                            MemoryTrackingMode default_value);

    static format::CompressionType ParseCompressionTypeString(const std::string&      value_string,
                                                              format::CompressionType default_value);

    static util::Log::Severity ParseLogLevelString(const std::string& value_string, util::Log::Severity default_value);

    static void ParseFramesList(const std::string& value_string, std::vector<util::FrameRange>* frames);

    static void ParseTrimRangeString(const std::string& value_string, std::vector<CaptureSettings::TrimRange>* ranges);

    static std::string ParseTrimKeyString(const std::string& value_string);

    static uint32_t ParseTrimKeyFramesString(const std::string& value_string);

  private:
    TraceSettings       trace_settings_;
    util::Log::Settings log_settings_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CAPTURE_SETTINGS_H
