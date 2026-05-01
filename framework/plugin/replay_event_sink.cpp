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

#include "replay_event_sink.h"

#include <util/date_time.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(plugin)

static size_t GetSizeOfStruct(GfxrReplayEventType type)
{
    switch (type)
    {
        case GFXR_REPLAY_EVENT_QUEUE_SUBMIT_BEGIN:
            return sizeof(GfxrReplayQueueSubmitBeginEvent);
        case GFXR_REPLAY_EVENT_QUEUE_SUBMIT_END:
            return sizeof(GfxrReplayQueueSubmitEndEvent);
        case GFXR_REPLAY_EVENT_FRAME_BEGIN:
            return sizeof(GfxrReplayFrameBeginEvent);
        case GFXR_REPLAY_EVENT_FRAME_END:
            return sizeof(GfxrReplayFrameEndEvent);
        default:
            GFXRECON_ASSERT(false && "Unknown event type");
            return 0;
    }
}

GfxrReplayEventHeader ReplayEventSink::CreateEventHeader(GfxrReplayEventType type)
{
    GfxrReplayEventHeader header = {};
    header.abi_version           = GFXR_REPLAY_PLUGIN_ABI_VERSION;
    header.struct_size           = GetSizeOfStruct(type);
    header.type                  = type;
    header.timestamp_ns          = static_cast<uint64_t>(util::datetime::GetTimestamp());
    header.frame_index           = current_frame_index_;
    return header;
}

uint64_t ReplayEventSink::QueueSubmitBegin(format::HandleId queue_id)
{
    GFXRECON_ASSERT(frame_active_);

    GfxrReplayQueueSubmitBeginEvent event = {};
    event.header                          = CreateEventHeader(GFXR_REPLAY_EVENT_QUEUE_SUBMIT_BEGIN);

    last_submit_index_ = current_submit_index_;
    if (first_submit_index_ == GFXR_REPLAY_INVALID_SUBMIT_INDEX)
    {
        first_submit_index_ = current_submit_index_;
    }

    event.submit_index = current_submit_index_;
    event.queue_id     = static_cast<uint64_t>(queue_id);

    EmitQueueSubmitBegin(event);

    return event.submit_index;
}

void ReplayEventSink::QueueSubmitEnd(uint64_t                              submit_index,
                                     format::HandleId                      queue_id,
                                     int32_t                               result,
                                     GfxrReplayQueueSubmitCompletionSource completion_source)
{
    GFXRECON_ASSERT(frame_active_);

    GfxrReplayQueueSubmitEndEvent event = {};
    event.header                        = CreateEventHeader(GFXR_REPLAY_EVENT_QUEUE_SUBMIT_END);

    event.submit_index      = submit_index;
    event.queue_id          = static_cast<uint64_t>(queue_id);
    event.result            = result;
    event.completion_source = completion_source;

    EmitQueueSubmitEnd(event);

    ++current_submit_index_;
}

void ReplayEventSink::FrameBegin(uint64_t frame_index)
{
    GFXRECON_ASSERT(!frame_active_);

    current_frame_index_ = frame_index;

    GfxrReplayFrameBeginEvent event = {};
    event.header                    = CreateEventHeader(GFXR_REPLAY_EVENT_FRAME_BEGIN);

    EmitFrameBegin(event);

    frame_active_ = true;
}

void ReplayEventSink::FrameEnd()
{
    GFXRECON_ASSERT(frame_active_);

    GfxrReplayFrameEndEvent event = {};
    event.header                  = CreateEventHeader(GFXR_REPLAY_EVENT_FRAME_END);
    event.first_submit_index      = first_submit_index_;
    event.last_submit_index       = last_submit_index_;

    EmitFrameEnd(event);

    frame_active_       = false;
    first_submit_index_ = GFXR_REPLAY_INVALID_SUBMIT_INDEX;
    last_submit_index_  = GFXR_REPLAY_INVALID_SUBMIT_INDEX;
}

PluginReplayEventSink::PluginReplayEventSink(util::platform::LibraryHandle library,
                                             GfxrReplayPluginV1*           plugin,
                                             CloseLibraryFunc              close_library) :
    library_(library),
    plugin_(plugin), close_library_(close_library), disabled_(false)
{
    GFXRECON_ASSERT(library != nullptr);
    GFXRECON_ASSERT(plugin != nullptr);
    GFXRECON_ASSERT(plugin->on_event != nullptr);
    GFXRECON_ASSERT(close_library != nullptr);
}

PluginReplayEventSink::~PluginReplayEventSink()
{
    if (plugin_ != nullptr)
    {
        plugin_->destroy(plugin_);
    }
    if (library_ != nullptr)
    {
        close_library_(library_);
    }
}

void PluginReplayEventSink::EmitQueueSubmitBegin(const GfxrReplayQueueSubmitBeginEvent& event)
{
    Forward(event.header);
}

void PluginReplayEventSink::EmitQueueSubmitEnd(const GfxrReplayQueueSubmitEndEvent& event)
{
    Forward(event.header);
}

void PluginReplayEventSink::EmitFrameBegin(const GfxrReplayFrameBeginEvent& event)
{
    Forward(event.header);
}

void PluginReplayEventSink::EmitFrameEnd(const GfxrReplayFrameEndEvent& event)
{
    Forward(event.header);
}

void PluginReplayEventSink::Forward(const GfxrReplayEventHeader& event)
{
    if (disabled_)
    {
        return;
    }

    GfxrReplayPluginResult result = plugin_->on_event(plugin_, &event);
    if (result != GFXR_REPLAY_PLUGIN_RESULT_OK)
    {
        GFXRECON_LOG_ERROR("Plugin event handler returned error result %u for event type %u", result, event.type);
        GFXRECON_LOG_WARNING("Disabling plugin due to error result");
        disabled_ = true;
    }
}

GFXRECON_END_NAMESPACE(plugin)
GFXRECON_END_NAMESPACE(gfxrecon)
