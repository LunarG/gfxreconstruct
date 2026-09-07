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

#ifndef GFXRECON_REPLAY_FEATURE_H
#define GFXRECON_REPLAY_FEATURE_H

#if defined(__ANDROID__)
// Forward declaration to avoid pulling NDK headers into this header.
struct android_app;
#endif

#include "util/strings.h"

#include "application/application.h"
#include "decode/file_processor.h"
#include "graphics/fps_info.h"
#include "graphics/frame_loop_info.h"
#include "util/argument_parser.h"
#include "util/feature_base.h"
#include "util/logging.h"

#include <memory>
#include <stdexcept>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

class ReplayFeatureBase : public util::FeatureBase
{
  public:
    virtual ~ReplayFeatureBase() = default;

    // Options queries
    virtual void QueryOptions(util::ArgumentParser& arg_parser, const std::string& capture_filename) {}

    // Examines the environment of the process for conditions that make replay of this API
    // unreliable, and writes a warning for each one. The replay tool calls this function for
    // every Feature before it starts the replay. The default does nothing.
    virtual void CheckEnvironment() {}

    // Composition methods (for an API like OpenXR which uses other graphics APIs to
    // compose final images). Called after CreateConsumer for all features so that
    // compositing features can obtain consumer pointers from graphics features.
    virtual void LinkCompositionFeatures(const std::vector<std::unique_ptr<ReplayFeatureBase>>& /*features*/) {}

    // Replay Event Sink method
    virtual std::unique_ptr<gfxrecon::plugin::ReplayEventSink> CreateReplayEventSink()
    {
        // This is a stub.
        return std::unique_ptr<gfxrecon::plugin::ReplayEventSink>{};
    }

    // Recapture methods (capturing while replaying)
    virtual void DetectAndSetupRecapture() {}

    // Frame and FPS methods
    void         SetMeasurementStartFrame(uint32_t frame) { measurement_start_frame_ = frame; }
    virtual void QueryFpsInfoOptions(bool& quit_after_range,
                                     bool& flush_range,
                                     bool& flush_inside_range,
                                     bool& preload_range,
                                     bool& quit_after_frame)
    {}

    // Pre-processing functionality
    bool         NeedsPreProcessingPass() { return needs_pre_processor_; }
    virtual void SetupPreProcessingPass(decode::FileProcessor* file_processor) {}
    virtual void CompletePreProcessingPass() {}

    // Decode/Consumer functions
    virtual void  CreateConsumer(decode::FileProcessor*                    file_processor,
                                 std::shared_ptr<application::Application> application,
                                 gfxrecon::graphics::FrameLoopInfo*        frame_loop_info) = 0;
    virtual void* GetConsumer() { return nullptr; }
    virtual void  RegisterDecodeComponents(graphics::FpsInfo* fps_info) = 0;

    // Cleanup
    virtual void Destroy() {}

  protected:
    std::string                               capture_filename_;
    std::shared_ptr<application::Application> application_;
    decode::FileProcessor*                    file_processor_{ nullptr };
    bool                                      needs_pre_processor_{ false };
    bool                                      is_enabled_{ false };
    uint32_t                                  measurement_start_frame_{ 0 };
};

// Template base for features with a typed consumer, decoder, and options object.
// Provides GetConsumer(), Destroy(), and protected helpers used by CreateConsumer
// and RegisterDecodeComponents implementations.
template <typename ConsumerT, typename DecoderT, typename OptionsT>
class ReplayFeature : public ReplayFeatureBase
{
  public:
    void*     GetConsumer() override { return replay_consumer_.get(); }
    DecoderT* GetDecoder() { return decoder_.get(); }
    void      Destroy() override
    {
        if (replay_consumer_)
        {
            replay_consumer_.reset();
        }
    }

  protected:
    OptionsT                   replay_options_;
    std::unique_ptr<ConsumerT> replay_consumer_;
    std::unique_ptr<DecoderT>  decoder_;

    void InitConsumer(decode::FileProcessor* file_processor, std::shared_ptr<application::Application> application)
    {
        file_processor_ = file_processor;
        application_    = application;

        // Make the decoder here, and not in RegisterConsumerAndDecoder(). A feature can use the
        // decoder between these two calls. The D3D12 two-pass tracking pass is one example. A
        // decoder that is made late is a null pointer for all such code.
        decoder_ = std::make_unique<DecoderT>();
    }

    void FinalizeConsumer() {}

    // Adds the consumer to the decoder, then adds the decoder to the file processor.
    // InitConsumer() already made a decoder of the default type. Supply decoder only to
    // replace that decoder with a different type, as the Vulkan feature does for the
    // isolate_render_passes option.
    void RegisterConsumerAndDecoder(graphics::FpsInfo* fps_info, std::unique_ptr<DecoderT> decoder = nullptr)
    {
        if (decoder != nullptr)
        {
            decoder_ = std::move(decoder);
        }

        // InitConsumer() must run first. A feature that does not call it has no decoder.
        GFXRECON_ASSERT(decoder_ != nullptr);

        replay_consumer_->SetFpsInfo(fps_info);
        decoder_->AddConsumer(replay_consumer_.get());
        file_processor_->AddDecoder(decoder_.get());
    }
};

// Template base for features that also need a pre-processing pass.
// Provides typed pre-processor members and splits setup into three helpers so the
// derived class can configure the consumer (e.g. EnableDumpResources) between
// construction and registration:
//   InitPreProcess()          -- constructs pre_processor_consumer_ / pre_processor_decoder_
//   FinalizePreProcess(fp)    -- wires them into the file processor
//   TeardownPreProcess()      -- resets them after the pass completes
// Also provides a complete SetupPreProcessingPass() using those helpers plus the
// shared dump-resources target opt-in, so most derived classes need no override.
template <typename ConsumerT, typename DecoderT, typename OptionsT, typename PreConsumerT>
class ReplayPreProcessFeature : public ReplayFeature<ConsumerT, DecoderT, OptionsT>
{
  public:
    void SetupPreProcessingPass(decode::FileProcessor* file_processor) override
    {
        if (this->needs_pre_processor_)
        {
            InitPreProcess();
            if (this->replay_options_.using_dump_resources_target)
            {
                pre_processor_consumer_->EnableDumpResources(this->replay_options_.dump_resources_target);
            }
            FinalizePreProcess(file_processor);
        }
    }

  protected:
    std::unique_ptr<PreConsumerT> pre_processor_consumer_;
    std::unique_ptr<DecoderT>     pre_processor_decoder_;

    void InitPreProcess()
    {
        pre_processor_consumer_ = std::make_unique<PreConsumerT>();
        pre_processor_decoder_  = std::make_unique<DecoderT>();
    }

    void FinalizePreProcess(decode::FileProcessor* file_processor)
    {
        pre_processor_decoder_->AddConsumer(pre_processor_consumer_.get());
        file_processor->AddDecoder(pre_processor_decoder_.get());
    }

    void TeardownPreProcess()
    {
        pre_processor_decoder_.reset();
        pre_processor_consumer_.reset();
    }
};

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_REPLAY_FEATURE_H
