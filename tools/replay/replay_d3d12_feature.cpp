/*
** Copyright (c) 2020-2026 LunarG, Inc.
** Copyright (c) 2022-2024 Advanced Micro Devices, Inc. All rights reserved.
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

#if defined(D3D12_SUPPORT)

// This needs to be included before d3d12.h so that IIDs are defined and not just declared.
#include <initguid.h>

#include "replay_d3d12_feature.h"

#include "decode/dx_replay_options.h"
#include "generated/generated_dx12_decoder.h"

#include "tool_feature_options.h"
#include "replay_settings.h"

#include "util/api_version_info.h"
#include "util/feature_module_registry.h"
#include "util/logging.h"
#include "util/options.h"
#include "util/strings.h"

#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

// Register this class as a feature in a module registry
GFXR_UTIL_REGISTER_FEATURE_CREATOR(ReplayFeatureBase, ReplayD3d12Feature)

// ----------------------------------------------------------------------------
// D3D12-only command-line settings.
//
// The names, the values, and the code that reads them stay with this Feature, so that
// tools/tool_settings.h and tools/replay/replay_settings.h keep only the settings that every
// replay Feature shares.
// ----------------------------------------------------------------------------

const char kDiscardCachedPsosShortOption[]     = "--dcp";
const char kDiscardCachedPsosLongOption[]      = "--discard-cached-psos";
const char kUseCachedPsosOption[]              = "--use-cached-psos";
const char kDeniedMessages[]                   = "--denied-messages";
const char kAllowedMessages[]                  = "--allowed-messages";
const char kDxTwoPassReplay[]                  = "--dx12-two-pass-replay";
const char kDxOverrideObjectNames[]            = "--dx12-override-object-names";
const char kDxAgsMarkRenderPasses[]            = "--dx12-ags-inject-markers";
const char kBatchingMemoryUsageArgument[]      = "--batching-memory-usage";
const char kDumpResourcesModifiableStateOnly[] = "--dump-resources-modifiable-state-only";
const char kDumpResourcesBeforeDrawOption[]    = "--dump-resources-before-draw";

// Only this Feature reads the two --dump-resources names above. The replay tool keeps them in
// its shared option list, next to --dump-resources and --dump-resources-dir. Each platform
// accepted the two names before the Features had their own command-line entries. An application
// can depend on that behavior, so each platform must continue to accept them. A build without
// this Feature parses the two names and then ignores them.

static std::vector<int32_t> GetFilteredMsgs(const gfxrecon::util::ArgumentParser& arg_parser,
                                            const char*                           filter_messages)
{
    const auto&          value = arg_parser.GetArgumentValue(filter_messages);
    std::vector<int32_t> msgs;
    if (!value.empty())
    {
        std::vector<std::string> values;
        std::istringstream       value_input;
        value_input.str(value);

        for (std::string val; std::getline(value_input, val, ',');)
        {
            size_t count = std::count_if(val.begin(), val.end(), ::isdigit);
            if (count == val.length())
            {
                msgs.push_back(std::stoi(val));
            }
            else
            {
                GFXRECON_LOG_WARNING("Ignoring invalid filter messages\"%s\", which contains non-numeric values",
                                     val.c_str());
                break;
            }
        }
    }
    return msgs;
}

static gfxrecon::decode::DxReplayOptions GetDxReplayOptions(const gfxrecon::util::ArgumentParser& arg_parser,
                                                            const std::string&                    filename)
{
    gfxrecon::decode::DxReplayOptions replay_options;
    GetReplayOptions(replay_options, arg_parser, filename);

    replay_options.DeniedDebugMessages  = GetFilteredMsgs(arg_parser, kDeniedMessages);
    replay_options.AllowedDebugMessages = GetFilteredMsgs(arg_parser, kAllowedMessages);

    if (arg_parser.IsOptionSet(kDxTwoPassReplay))
    {
        replay_options.enable_d3d12_two_pass_replay = true;
    }

    if (arg_parser.IsOptionSet(kDiscardCachedPsosLongOption) || arg_parser.IsOptionSet(kDiscardCachedPsosShortOption))
    {
        GFXRECON_LOG_WARNING("The parameters --dcp and --discard-cached-psos have been deprecated in favor for "
                             "--use-cached-psos");
    }

    if (arg_parser.IsOptionSet(kUseCachedPsosOption))
    {
        replay_options.use_cached_psos = true;
    }

    if (arg_parser.IsOptionSet(kDxOverrideObjectNames))
    {
        replay_options.override_object_names = true;
    }

    if (arg_parser.IsOptionSet(kDxAgsMarkRenderPasses))
    {
#ifdef GFXRECON_AGS_SUPPORT
        replay_options.ags_inject_markers = true;
#else
        GFXRECON_LOG_ERROR("Unsupported option --dx12-ags-inject-markers");
#endif
    }

    const std::string& dump_resources = arg_parser.GetArgumentValue(kDumpResourcesArgument);
    if (!dump_resources.empty() && dump_resources.find_first_not_of("0123456789,") == std::string::npos)
    {
        std::vector<std::string> values = gfxrecon::util::strings::SplitString(dump_resources, ',');
        if (values.size() == 3)
        {
            replay_options.dump_resources_target.submit_index    = std::stoi(values[0]);
            replay_options.dump_resources_target.command_index   = std::stoi(values[1]);
            replay_options.dump_resources_target.draw_call_index = std::stoi(values[2]);
            replay_options.enable_dump_resources                 = true;
            replay_options.using_dump_resources_target           = true;
        }
    }

    replay_options.dump_resources_output_dir            = GetDumpResourcesDir(arg_parser);
    replay_options.dump_resources_before                = arg_parser.IsOptionSet(kDumpResourcesBeforeDrawOption);
    replay_options.dump_resources_modifiable_state_only = arg_parser.IsOptionSet(kDumpResourcesModifiableStateOnly);

    const std::string& memory_usage = arg_parser.GetArgumentValue(kBatchingMemoryUsageArgument);
    if (!memory_usage.empty())
    {
        int memory_usage_int = std::stoi(memory_usage);
        if (memory_usage_int >= 0 && memory_usage_int <= 100)
        {
            replay_options.memory_usage = static_cast<uint32_t>(memory_usage_int);
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "The parameter to --batching-memory-usage is out of range [0, 100], will use 80 as default value.");
        }
    }
    return replay_options;
}

// ----------------------------------------------------------------------------
// End of the D3D12-only command-line settings.
// ----------------------------------------------------------------------------

std::string ReplayD3d12Feature::CompiledHeaderVersionString() const
{
    return util::GetD3D12SdkVersionString();
}

std::vector<util::FeatureOptionDesc> ReplayD3d12Feature::GetOptionDescs() const
{
    return { { "",
               { "Permit the use of cached PSOs when replay creates graphics or compute",
                 "pipelines. A cached PSO can decrease the PSO creation time, but it can",
                 "also cause replay errors." },
               false,
               kUseCachedPsosOption },
             { "",
               { "Generate a unique name for each ID3D12Object and assign that name to",
                 "the object. This helps you to debug a replay." },
               false,
               kDxOverrideObjectNames },
             { "",
               { "Label each API call with the block index of the trace. Radeon GPU",
                 "Detective can dump the label for debugging." },
               false,
               kDxAgsMarkRenderPasses },
             { "<pct>",
               { "The maximum memory consumption while replay loads a trimmed capture",
                 "file. The accepted values are 0 to 100, and the default is 80. A value",
                 "of 0 disables batching, and a value of 100 permits the use of all",
                 "available system memory and GPU memory." },
               true,
               kBatchingMemoryUsageArgument },
             // The entries below have no description, so they stay out of the usage text. They keep
             // the same undocumented behavior that the shared option strings gave them.
             { "", {}, false, AliasNames(kDiscardCachedPsosShortOption, kDiscardCachedPsosLongOption) },
             { "", {}, false, kDxTwoPassReplay },
             { "", {}, true, kDeniedMessages },
             { "", {}, true, kAllowedMessages } };
}

void ReplayD3d12Feature::QueryOptions(gfxrecon::util::ArgumentParser& arg_parser, const std::string& capture_filename)
{
    capture_filename_    = capture_filename;
    replay_options_      = GetDxReplayOptions(arg_parser, capture_filename);
    is_enabled_          = replay_options_.enable_d3d12;
    needs_pre_processor_ = is_enabled_ && replay_options_.enable_dump_resources;
}

void ReplayD3d12Feature::QueryFpsInfoOptions(
    bool& quit_after_range, bool& flush_range, bool& flush_inside_range, bool& preload_range, bool& quit_after_frame)
{
    if (is_enabled_)
    {
        quit_after_range   = replay_options_.quit_after_measurement_frame_range;
        flush_range        = replay_options_.flush_measurement_frame_range;
        flush_inside_range = replay_options_.flush_inside_measurement_range;
        quit_after_frame   = replay_options_.quit_after_frame;
        // preload_range intentionally not set: DxReplayOptions has no preload_measurement_range field
    }
}

void ReplayD3d12Feature::CreateConsumer(decode::FileProcessor*                    file_processor,
                                        std::shared_ptr<application::Application> application,
                                        gfxrecon::graphics::FrameLoopInfo*        frame_loop_info)
{
    GFXRECON_UNREFERENCED_PARAMETER(frame_loop_info);

    if (is_enabled_)
    {
        InitConsumer(file_processor, application);
        application->InitializeDx12WsiContext();
        if (graphics::dx12::VerifyAgilitySDKRuntime() == false)
        {
            GFXRECON_LOG_ERROR("Did not find Agility SDK runtimes. Verify \\D3D12\\D3D12Core.dll exists in the same "
                               "directory as gfxrecon-replay.exe.");
        }

        replay_consumer_ = std::make_unique<decode::Dx12ReplayConsumer>(application_, replay_options_);
        FinalizeConsumer();
    }
}

void ReplayD3d12Feature::RegisterDecodeComponents(graphics::FpsInfo* fps_info)
{
    if (is_enabled_)
    {
        // Check for user option if first pass tracking is enabled
        if (replay_options_.enable_d3d12_two_pass_replay)
        {
            decode::FileProcessor              file_processor_tracking;
            decode::Dx12TrackedObjectInfoTable tracked_object_info_table;
            auto                               tracking_consumer =
                std::make_unique<decode::DX12TrackingConsumer>(replay_options_, &tracked_object_info_table);
            if (file_processor_tracking.Initialize(capture_filename_))
            {
                decoder_->AddConsumer(tracking_consumer.get());
                file_processor_tracking.AddDecoder(decoder_.get());
                file_processor_tracking.ProcessAllFrames();
                file_processor_tracking.RemoveDecoder(decoder_.get());
                decoder_->RemoveConsumer(tracking_consumer.get());
            }
        }

        RegisterConsumerAndDecoder(fps_info);

#ifdef GFXRECON_AGS_SUPPORT
        ags_replay_consumer_.AddDx12Consumer(replay_consumer_.get());
        ags_decoder_.AddConsumer(reinterpret_cast<gfxrecon::decode::AgsConsumerBase*>(&ags_replay_consumer_));
        file_processor_->AddDecoder(&ags_decoder_);
#endif // GFXRECON_AGS_SUPPORT
    }
}

void ReplayD3d12Feature::CompletePreProcessingPass()
{
    if (needs_pre_processor_)
    {
        replay_options_.enable_d3d12 = pre_processor_consumer_->WasD3D12APIDetected();
        if (replay_options_.enable_d3d12)
        {
            auto track_dump_target = pre_processor_consumer_->GetTrackDumpTarget();
            GFXRECON_ASSERT(track_dump_target != nullptr);
            replay_consumer_->SetDumpTarget(*track_dump_target);
        }

        TeardownPreProcess();
    }
}

void ReplayD3d12Feature::Destroy()
{
    if (is_enabled_ && (file_processor_->GetCurrentFrameNumber() >= measurement_start_frame_) &&
        (file_processor_->GetErrorState() == gfxrecon::decode::BlockIOError::kErrorNone))
    {
        replay_consumer_->PostReplay();
        if (!replay_options_.screenshot_ranges.empty() && !file_processor_->UsesFrameMarkers() &&
            (replay_consumer_->GetDXGITestPresentCount() > 0))
        {
            GFXRECON_LOG_WARNING_ONCE(
                "This capture contains %" PRIu32
                " calls to IDXGISwapChain::Present with flag DXGI_PRESENT_TEST and no frame end markers. "
                "Screenshot frame indexing may have changed since capture.",
                replay_consumer_->GetDXGITestPresentCount());
        }
    }
    replay_consumer_.reset();
}

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // D3D12_SUPPORT
