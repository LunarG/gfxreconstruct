/**
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

#include "decode/frame_loop_lifetime_tracker.h"

#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

FrameLoopLifetimeTracker::CallReplay FrameLoopLifetimeTracker::OnAllocate(std::span<const format::HandleId> handles)
{
    CallReplay replay;
    replay.handle_count = handles.size();

    for (uint32_t i = 0; i < handles.size(); ++i)
    {
        const format::HandleId handle = handles[i];

        if (!frame_loop_info_.IsLooping())
        {
            // Nothing to track when not looping.
            replay.indices.push_back(i);
        }
        else if (frame_loop_info_.IsFirstIteration())
        {
            // We do not know yet whether this handle will become:
            // - transient (freed within the frame loop range)
            // - or persistent (survives beyond the frame loop range).
            pending_.insert(handle);
            replay.indices.push_back(i);
        }
        else if (transient_.count(handle) > 0)
        {
            // Transient handles are freed within the frame loop range,
            // so we need to allocate them again.
            replay.indices.push_back(i);
        }
        else
        {
            // Persistent handles are not allocated again.
            GFXRECON_ASSERT(persistent_.count(handle) > 0);
        }
    }

    return replay;
}

FrameLoopLifetimeTracker::CallReplay FrameLoopLifetimeTracker::OnFree(std::span<const format::HandleId> handles)
{
    // Handles should not be pending in non-first iterations.
    GFXRECON_ASSERT(frame_loop_info_.IsFirstIteration() || pending_.empty());

    CallReplay replay;
    replay.handle_count = handles.size();

    for (uint32_t i = 0; i < handles.size(); ++i)
    {
        const format::HandleId handle = handles[i];

        if (!frame_loop_info_.IsLooping())
        {
            // Nothing to track when not looping.
            replay.indices.push_back(i);
        }
        else if (frame_loop_info_.IsFirstIteration())
        {
            GFXRECON_ASSERT(!frame_loop_info_.IsFinalIteration());

            if (pending_.erase(handle) > 0)
            {
                // Handle was allocated in the current iteration and is now freed.
                transient_.insert(handle);
                replay.indices.push_back(i);
            }
            else
            {
                // Handle was allocated before the frame loop started,
                // so it might still be needed in subsequent iterations.
                // Defer destruction until last iteration.
                deferred_destroy_.insert(handle);
            }
        }
        else if (transient_.count(handle) > 0)
        {
            // When repeating a frame, transient handles are created and freed within the same iteration.
            // This applies to all repeated iterations, including the final one.
            replay.indices.push_back(i);
        }
        else if (frame_loop_info_.IsFinalIteration() && (deferred_destroy_.erase(handle) > 0))
        {
            // In the last iteration, we can safely free the handles that were deferred for destruction.
            replay.indices.push_back(i);
        }
    }

    return replay;
}

bool FrameLoopLifetimeTracker::OnPoolReset(const std::unordered_set<format::HandleId>& handles)
{
    if (frame_loop_info_.IsLooping() && !frame_loop_info_.IsFinalIteration())
    {
        for (auto handle : handles)
        {
            if ((pending_.count(handle) > 0) || (persistent_.count(handle) > 0) ||
                (deferred_destroy_.count(handle) > 0))
            {
                // Repetitions keep using this handle without allocating it again,
                // so the reset is deferred to the final iteration.
                return false;
            }
        }
    }

    // A reset frees the handles of the pool the same way a destroy does.
    OnPoolDestroy(handles);
    return true;
}

void FrameLoopLifetimeTracker::OnPoolDestroy(const std::unordered_set<format::HandleId>& handles)
{
    if (!frame_loop_info_.IsLooping())
    {
        // Nothing to track when not looping.
        return;
    }

    for (auto handle : handles)
    {
        if ((pending_.erase(handle) > 0) || (persistent_.erase(handle) > 0))
        {
            // The handle no longer exists, so any later allocation of it has to be replayed.
            transient_.insert(handle);
        }

        // A handle allocated before the frame loop is now freed for real,
        // so its deferred destruction must not be replayed.
        deferred_destroy_.erase(handle);
    }
}

void FrameLoopLifetimeTracker::OnFrameEnd()
{
    if (frame_loop_info_.IsFirstIteration())
    {
        persistent_.insert(pending_.begin(), pending_.end());
        pending_.clear();
    }
    else if (frame_loop_info_.IsFinalIteration())
    {
        persistent_.clear();
        transient_.clear();
        GFXRECON_ASSERT(deferred_destroy_.empty());
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
