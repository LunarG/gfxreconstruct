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

#include "decode/vulkan_replay_options.h"

#include <cinttypes>
#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static void WaitAndEmitEvents(plugin::ReplayEventSink* event_sink, uint32_t duration_ms)
{
    GFXRECON_ASSERT(duration_ms > 0);

    if (event_sink != nullptr)
    {
        event_sink->WaitBegin(duration_ms);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(duration_ms));

    if (event_sink != nullptr)
    {
        event_sink->WaitEnd();
    }
}

void VulkanReplayOptions::MaybeWaitBeforeFirstSubmit(plugin::ReplayEventSink* event_sink) const
{
    static std::once_flag flag;
    std::call_once(flag, [this, event_sink]() {
        if (wait_before_first_submit > 0)
        {
            auto current_time    = std::chrono::high_resolution_clock::now();
            auto time_elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time);
            auto wait_before_first_submit_ms = std::chrono::milliseconds(wait_before_first_submit);
            if (time_elapsed_ms < wait_before_first_submit_ms)
            {
                auto time_to_wait = wait_before_first_submit_ms - time_elapsed_ms;
                GFXRECON_LOG_INFO("Waiting %" PRId64 " ms before first queue submit.",
                                  static_cast<int64_t>(time_to_wait.count()));
                WaitAndEmitEvents(event_sink, static_cast<uint32_t>(time_to_wait.count()));
            }
        }
    });
}

void VulkanReplayOptions::MaybeWaitBeforeFrame(plugin::ReplayEventSink* event_sink) const
{
    if (wait_before_frame > 0)
    {
        GFXRECON_LOG_INFO("Waiting %u ms before starting to replay the frame.", wait_before_frame);
        WaitAndEmitEvents(event_sink, wait_before_frame);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
