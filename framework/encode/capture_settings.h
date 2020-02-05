/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_ENCODE_CAPTURE_SETTINGS_H
#define GFXRECON_ENCODE_CAPTURE_SETTINGS_H

#include "format/format.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"

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
        std::string            capture_file{ kDefaultCaptureFileName };
        format::EnabledOptions capture_file_options;
        bool                   time_stamp_file{ true };
        bool                   force_flush{ false };
        MemoryTrackingMode     memory_tracking_mode{ kPageGuard };
        std::vector<TrimRange> trim_ranges;
        std::string            trim_key;
        bool                   page_guard_copy_on_map{ util::PageGuardManager::kDefaultEnableCopyOnMap };
        bool                   page_guard_separate_read{ util::PageGuardManager::kDefaultEnableSeparateRead };
        bool                   page_guard_persistent_memory{ false };
        bool                   page_guard_align_buffer_sizes{ false };
        bool                   page_guard_track_ahb_memory{ false };

        // An optimization for the page_guard memory tracking mode that eliminates the need for shadow memory by
        // overriding vkAllocateMemory so that all host visible allocations use the external memory extension with a
        // memory allocation that the capture layer can monitor to determine which regions of memory have been modified
        // by the application.
        bool page_guard_external_memory{ false };
    };

  public:
    CaptureSettings();

    ~CaptureSettings();

    const TraceSettings& GetTraceSettings() const { return trace_settings_; }

    const util::Log::Settings& GetLogSettings() const { return log_settings_; }

    static void LoadSettings(CaptureSettings* settings);

  private:
    typedef std::unordered_map<std::string, std::string> OptionsMap;

  private:
    static void
    LoadSingleOptionEnvVar(OptionsMap* options, const std::string& environment_variable, const std::string& option_key);

    static void LoadOptionsEnvVar(OptionsMap* options);

    static void LoadOptionsFile(OptionsMap* options);

    static void ProcessOptions(OptionsMap* options, CaptureSettings* settings);

    static std::string FindOption(OptionsMap* options, const std::string& key, const std::string& default_value = "");

    static bool ParseBoolString(const std::string& value_string, bool default_value);

    static MemoryTrackingMode ParseMemoryTrackingModeString(const std::string& value_string,
                                                            MemoryTrackingMode default_value);

    static format::CompressionType ParseCompressionTypeString(const std::string&      value_string,
                                                              format::CompressionType default_value);

    static util::Log::Severity ParseLogLevelString(const std::string& value_string, util::Log::Severity default_value);

    static void ParseTrimRangeString(const std::string& value_string, std::vector<CaptureSettings::TrimRange>* ranges);

    static std::string ParseTrimKeyString(const std::string& value_string);

  private:
    TraceSettings       trace_settings_;
    util::Log::Settings log_settings_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_CAPTURE_SETTINGS_H
