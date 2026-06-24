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

#ifndef GFXRECON_REPLAY_OPENXR_FEATURE_H
#define GFXRECON_REPLAY_OPENXR_FEATURE_H

#include "replay_feature.h"

#if ENABLE_OPENXR_SUPPORT

#include "decode/openxr_tracked_object_info_table.h"
#include "generated/generated_openxr_decoder.h"
#include "generated/generated_openxr_replay_consumer.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(replay)

class ReplayOpenXrFeature
    : public ReplayFeature<decode::OpenXrReplayConsumer, decode::OpenXrDecoder, decode::OpenXrReplayOptions>
{
  public:
    ReplayOpenXrFeature()          = default;
    virtual ~ReplayOpenXrFeature() = default;

    // Simple "getter" style methods
    std::string Label() const final { return "OpenXR"; }

    void QueryOptions(util::ArgumentParser& arg_parser, const std::string& capture_filename) final;
    void CreateConsumer(decode::FileProcessor*                    file_processor,
                        std::shared_ptr<application::Application> application,
                        gfxrecon::graphics::FrameLoopInfo*        frame_loop_info) final;
    void RegisterDecodeComponents(graphics::FpsInfo* fps_info) final;

    void LinkCompositionFeatures(const std::vector<std::unique_ptr<ReplayFeatureBase>>& features) final;

  private:
    decode::OpenXrTrackedObjectInfoTable tracked_object_info_table_;
};

GFXRECON_END_NAMESPACE(replay)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_REPLAY_OPENXR_FEATURE_H
