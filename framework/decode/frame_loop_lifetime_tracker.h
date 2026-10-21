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

#ifndef GFXRECON_DECODE_FRAME_LOOP_LIFETIME_TRACKER_H
#define GFXRECON_DECODE_FRAME_LOOP_LIFETIME_TRACKER_H

#include "format/format.h"
#include "graphics/frame_loop_info.h"
#include "util/defines.h"

#include <cstdint>
#include <span>
#include <unordered_set>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class FrameLoopLifetimeTracker
{
  public:
    /// How a call allocating or freeing several handles has to be replayed.
    struct CallReplay
    {
        /// The indices of the handles whose allocation or free has to be replayed, in increasing order.
        std::vector<uint32_t> indices;

        /// The number of handles of the call.
        size_t handle_count{ 0 };

        /// Whether the call is not replayed at all, as none of its handles is.
        /// Allocate and free calls do not accept a count of zero, so they cannot be replayed without any handle.
        bool IsSkipped() const { return indices.empty() && (handle_count > 0); }

        /// Whether the call has to be restricted to the handles at `indices`, as only some of its handles are.
        bool IsRestricted() const { return !indices.empty() && (indices.size() < handle_count); }
    };

    explicit FrameLoopLifetimeTracker(graphics::FrameLoopInfo& frame_loop_info) : frame_loop_info_(frame_loop_info) {}

    /// @brief Tracks the handles allocated by a call within the frame loop.
    /// The decision is made per handle, as a single call may allocate handles with different lifetimes.
    CallReplay OnAllocate(std::span<const format::HandleId> handles);

    /// @brief Tracks the handles freed by a call within the frame loop.
    /// The decision is made per handle, as a single call may free handles with different lifetimes.
    CallReplay OnFree(std::span<const format::HandleId> handles);

    /// @brief Tracks the reset of a pool, which frees all the handles allocated from it.
    /// @return Whether the reset has to be replayed.
    bool OnPoolReset(const std::unordered_set<format::HandleId>& handles);

    /// @brief Tracks a replayed destroy of a pool, which frees all the handles allocated from it.
    void OnPoolDestroy(const std::unordered_set<format::HandleId>& handles);

    void OnFrameEnd();

  private:
    graphics::FrameLoopInfo& frame_loop_info_;

    /// Tracks handles that are allocated in iteration 1, fate not known yet.
    /// These handles may either become transient (if a subsequent free occurs within the same iteration)
    /// or persistent (if they survive beyond the current iteration).
    std::unordered_set<format::HandleId> pending_;

    /// Tracks handles that are allocated and freed within the same loop iteration.
    std::unordered_set<format::HandleId> transient_;

    /// Tracks handles that are allocated within and freed after the loop.
    std::unordered_set<format::HandleId> persistent_;

    /// Tracks handles that were allocated before and freed within the loop.
    /// Destruction for these handles is deferred to the final iteration of the loop.
    std::unordered_set<format::HandleId> deferred_destroy_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FRAME_LOOP_LIFETIME_TRACKER_H
