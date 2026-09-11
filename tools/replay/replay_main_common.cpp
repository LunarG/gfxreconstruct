/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "replay_main_common.h"

#include "replay_settings.h"

#include "decode/preload_file_processor.h"
#include "graphics/frame_loop_info.h"
#include "util/feature_module_registry.h"

#if defined(__ANDROID__)
#include <android_native_app_glue.h>
#endif

#include <limits>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

// The list that the last LoadFeatures() call filled. GetLoadedFeatures() gives it to the usage
// function of the tool, which cannot receive the list as a parameter.
static const std::vector<std::unique_ptr<ReplayFeatureBase>>* g_loaded_features = nullptr;

void LoadFeatures(std::vector<std::unique_ptr<ReplayFeatureBase>>& features)
{
    for (const auto& creator :
         util::FeatureModuleRegistry<ReplayFeatureBase>::GetSingleton().GetRegisteredFeatureCreators())
    {
        features.push_back(creator());
    }

    g_loaded_features = &features;
}

const std::vector<std::unique_ptr<ReplayFeatureBase>>& GetLoadedFeatures()
{
    static const std::vector<std::unique_ptr<ReplayFeatureBase>> empty;

    return (g_loaded_features != nullptr) ? *g_loaded_features : empty;
}

void RunPreProcessConsumer(const std::string& filename, std::vector<std::unique_ptr<ReplayFeatureBase>>& features)
{
    decode::FileProcessor file_processor;
    if (file_processor.Initialize(filename))
    {
        for (auto& feature : features)
        {
            feature->SetupPreProcessingPass(&file_processor);
        }

        file_processor.ProcessAllFrames();

        for (auto& feature : features)
        {
            feature->CompletePreProcessingPass();
        }
    }
}

bool RunReplay(std::unique_ptr<decode::FileProcessor>&                                          file_processor_out,
               std::vector<std::unique_ptr<ReplayFeatureBase>>&                                 features,
               util::ArgumentParser&                                                            arg_parser,
               const std::string&                                                               filename,
               std::function<std::shared_ptr<application::Application>(decode::FileProcessor*)> make_application)
{
    uint32_t loop_frame        = 0;
    uint32_t loop_count        = graphics::FrameLoopInfo::INFINITE_ITERATIONS;
    bool     enable_frame_loop = GetLoopFrame(arg_parser, loop_frame);
    GetLoopCount(arg_parser, loop_count);

    if (arg_parser.IsOptionSet(kPreloadMeasurementRangeOption) || enable_frame_loop)
    {
        file_processor_out = std::make_unique<decode::PreloadFileProcessor>();
    }
    else
    {
        file_processor_out = std::make_unique<decode::FileProcessor>();
    }

    if (!file_processor_out->Initialize(filename))
    {
        GFXRECON_WRITE_CONSOLE("Failed to load file %s.", filename.c_str());
        return false;
    }

    bool        has_mfr                            = false;
    bool        requires_pre_processing            = false;
    bool        quit_after_frame                   = false;
    uint32_t    quit_frame                         = std::numeric_limits<uint32_t>::max();
    uint32_t    measurement_start_frame            = 0;
    uint32_t    measurement_end_frame              = 0;
    bool        quit_after_measurement_frame_range = false;
    bool        flush_measurement_frame_range      = false;
    bool        flush_inside_measurement_range     = false;
    bool        preload_measurement_frame_range    = false;
    std::string measurement_file_name;

    auto application = make_application(file_processor_out.get());

    graphics::FrameLoopInfo fl_info;
    if (enable_frame_loop)
    {
        fl_info = graphics::FrameLoopInfo(loop_frame, loop_count);
        application->SetFrameLoopInfo(&fl_info);
    }

    for (auto& feature : features)
    {
        feature->QueryOptions(arg_parser, filename);
    }

    has_mfr = GetMeasurementFrameRange(arg_parser, measurement_start_frame, measurement_end_frame);
    GetMeasurementFilename(arg_parser, measurement_file_name);

    for (auto& feature : features)
    {
        feature->SetMeasurementStartFrame(measurement_start_frame);
        feature->QueryFpsInfoOptions(quit_after_measurement_frame_range,
                                     flush_measurement_frame_range,
                                     flush_inside_measurement_range,
                                     preload_measurement_frame_range,
                                     quit_after_frame);
    }
    if (quit_after_frame)
    {
        GetQuitAfterFrame(arg_parser, quit_frame);
    }

    graphics::FpsInfo fps_info(static_cast<uint64_t>(measurement_start_frame),
                               static_cast<uint64_t>(measurement_end_frame),
                               has_mfr,
                               quit_after_measurement_frame_range,
                               flush_measurement_frame_range,
                               flush_inside_measurement_range,
                               preload_measurement_frame_range,
                               measurement_file_name,
                               quit_after_frame,
                               quit_frame);

    std::unique_ptr<gfxrecon::plugin::ReplayEventSink> replay_event_sink;
    for (auto& feature : features)
    {
        feature->CreateConsumer(file_processor_out.get(), application, enable_frame_loop ? &fl_info : nullptr);
        requires_pre_processing |= feature->NeedsPreProcessingPass();

        auto temp_replay_event_sink = feature->CreateReplayEventSink();
        if (temp_replay_event_sink)
        {
            if (!replay_event_sink)
            {
                replay_event_sink = std::move(temp_replay_event_sink);
            }
            else
            {
                GFXRECON_LOG_WARNING("Multiple Replay Event Sink fields encountered.");
            }
        }

        feature->DetectAndSetupRecapture();
    }

    if (replay_event_sink)
    {
        application->SetReplayEventSink(std::move(replay_event_sink));
    }

    // Must be called after each feature has created its consumer.
    for (auto& feature : features)
    {
        feature->LinkCompositionFeatures(features);
    }

    if (requires_pre_processing)
    {
        RunPreProcessConsumer(filename, features);
    }

    for (auto& feature : features)
    {
        feature->RegisterDecodeComponents(&fps_info);
    }

    application->SetPauseFrame(GetPauseFrame(arg_parser));

    for (auto& feature : features)
    {
        feature->CheckEnvironment();
    }

#if defined(__ANDROID__)
    // Start paused; replay begins once APP_CMD_GAINED_FOCUS fires.
    application->SetPaused(true);
#endif

    application->SetFpsInfo(&fps_info);
    application->SetAsyncProcessing(arg_parser.IsOptionSet(kAsyncProcessingOption));

    fps_info.BeginFile();
    application->Run();

    // Add one so that it matches the trim range frame number semantic.
    fps_info.EndFile(file_processor_out->GetCurrentFrameNumber() + 1);

    if ((file_processor_out->GetCurrentFrameNumber() > 0) &&
        (file_processor_out->GetErrorState() == decode::BlockIOError::kErrorNone))
    {
        if (file_processor_out->GetCurrentFrameNumber() < measurement_start_frame)
        {
            GFXRECON_LOG_WARNING("Measurement range start frame (%u) is greater than the last replayed frame (%u). "
                                 "Measurements were never started, cannot calculate measurement range FPS.",
                                 measurement_start_frame,
                                 file_processor_out->GetCurrentFrameNumber());
        }
        else
        {
            fps_info.LogMeasurements();
        }
    }
    else if (file_processor_out->GetErrorState() != decode::BlockIOError::kErrorNone)
    {
        GFXRECON_WRITE_CONSOLE("A failure has occurred during replay");
        return false;
    }
    else
    {
        GFXRECON_WRITE_CONSOLE("File did not contain any frames");
    }

    for (auto& feature : features)
    {
        feature->Destroy();
    }

    return true;
}

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)
