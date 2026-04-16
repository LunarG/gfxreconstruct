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

#ifndef GFXRECON_PLUGIN_REPLAY_EVENT_SINK_H
#define GFXRECON_PLUGIN_REPLAY_EVENT_SINK_H

#include <util/defines.h>
#include <util/platform.h>
#include <gfxr/replay_event_plugin.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugin)

class ReplayEventSink
{
  public:
    virtual ~ReplayEventSink() = default;

    uint64_t QueueSubmitBegin(uint64_t queue_id);
    void     QueueSubmitEnd(uint64_t                              submit_index,
                            uint64_t                              queue_id,
                            int32_t                               result,
                            GfxrReplayQueueSubmitCompletionSource completion_source);

    void FrameBegin(uint64_t frame_index);
    void FrameEnd();

    bool IsFrameActive() const { return frame_active_; }

  protected:
    virtual void EmitQueueSubmitBegin(const GfxrReplayQueueSubmitBeginEvent& event) = 0;
    virtual void EmitQueueSubmitEnd(const GfxrReplayQueueSubmitEndEvent& event)     = 0;
    virtual void EmitFrameBegin(const GfxrReplayFrameBeginEvent& event)             = 0;
    virtual void EmitFrameEnd(const GfxrReplayFrameEndEvent& event)                 = 0;

  private:
    GfxrReplayEventHeader CreateEventHeader(GfxrReplayEventType type);

    bool     frame_active_        = false;
    uint64_t current_frame_index_ = 0;

    uint64_t current_submit_index_ = 0;
    uint64_t first_submit_index_   = GFXR_REPLAY_INVALID_SUBMIT_INDEX;
    uint64_t last_submit_index_    = GFXR_REPLAY_INVALID_SUBMIT_INDEX;
};

class NullReplayEventSink final : public ReplayEventSink
{
  protected:
    void EmitQueueSubmitBegin(const GfxrReplayQueueSubmitBeginEvent&) override {}
    void EmitQueueSubmitEnd(const GfxrReplayQueueSubmitEndEvent&) override {}
    void EmitFrameBegin(const GfxrReplayFrameBeginEvent&) override {}
    void EmitFrameEnd(const GfxrReplayFrameEndEvent&) override {}
};

class PluginReplayEventSink final : public ReplayEventSink
{
  public:
    using CloseLibraryFunc = void (*)(util::platform::LibraryHandle library);

    PluginReplayEventSink(util::platform::LibraryHandle library,
                          GfxrReplayPluginV1*           plugin,
                          CloseLibraryFunc              close_library = util::platform::CloseLibrary);
    ~PluginReplayEventSink();

  protected:
    void EmitQueueSubmitBegin(const GfxrReplayQueueSubmitBeginEvent& event) override;
    void EmitQueueSubmitEnd(const GfxrReplayQueueSubmitEndEvent& event) override;
    void EmitFrameBegin(const GfxrReplayFrameBeginEvent& event) override;
    void EmitFrameEnd(const GfxrReplayFrameEndEvent& event) override;

  private:
    void Forward(const GfxrReplayEventHeader& event);

    bool                          disabled_      = false;
    util::platform::LibraryHandle library_       = nullptr;
    GfxrReplayPluginV1*           plugin_        = nullptr;
    CloseLibraryFunc              close_library_ = nullptr;
};

GFXRECON_END_NAMESPACE(plugin)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_PLUGIN_REPLAY_EVENT_SINK_H
