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

#ifndef GFXRECON_REPLAY_VULKAN_FEATURE_H
#define GFXRECON_REPLAY_VULKAN_FEATURE_H

#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_tracked_object_info_table.h"
#include "decode/vulkan_pre_process_consumer.h"
#include "generated/generated_vulkan_decoder.h"
#include "generated/generated_vulkan_replay_consumer.h"

#include "replay_feature.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

class ReplayVulkanFeature : public ReplayPreProcessFeature<decode::VulkanReplayConsumer,
                                                           decode::VulkanDecoder,
                                                           decode::VulkanReplayOptions,
                                                           decode::VulkanPreProcessConsumer>
{
  public:
    ReplayVulkanFeature()          = default;
    virtual ~ReplayVulkanFeature() = default;

    // Simple "getter" style methods
    std::string Label() const final { return "Vulkan"; }
    std::string CompiledHeaderVersionString() const final;

    std::vector<util::FeatureOptionDesc> GetOptionDescs() const final;

    void QueryOptions(util::ArgumentParser& arg_parser, const std::string& capture_filename) final;
    void CheckEnvironment() final;
    void QueryFpsInfoOptions(bool& quit_after_range,
                             bool& flush_range,
                             bool& flush_inside_range,
                             bool& preload_range,
                             bool& quit_after_frame) final;
    void CreateConsumer(decode::FileProcessor*                    file_processor,
                        std::shared_ptr<application::Application> application,
                        gfxrecon::graphics::FrameLoopInfo*        frame_loop_info) final;
    void RegisterDecodeComponents(graphics::FpsInfo* fps_info) final;

    void DetectAndSetupRecapture() final;

    void CompletePreProcessingPass() final;

    std::unique_ptr<gfxrecon::plugin::ReplayEventSink> CreateReplayEventSink() final;

    void Destroy() final;

  private:
    decode::VulkanTrackedObjectInfoTable tracked_object_info_table_;
};

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_REPLAY_VULKAN_FEATURE_H
