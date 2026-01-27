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

#ifndef GFXRECON_GRAPHICS_FRAME_LOOP_INFO_H
#define GFXRECON_GRAPHICS_FRAME_LOOP_INFO_H

#include <limits>

#include "util/defines.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class FrameLoopInfo
{
  public:
    explicit FrameLoopInfo(uint32_t loop_frame_idx  = 0,
                           uint32_t loop_iterations = std::numeric_limits<uint32_t>::max()) :
        loop_frame_idx_{ loop_frame_idx },
        loop_iterations_{ loop_iterations }
    {}

    bool     IsLoopRequested() const { return loop_frame_idx_ != 0; }
    bool     IsLooping() const { return is_looping_; }
    void     SetLooping(bool looping) { is_looping_ = looping; }
    uint32_t GetLoopFrameIdx() const { return loop_frame_idx_; }
    uint32_t GetLoopIterations() const { return loop_iterations_; }
    void     DecrementLoopIterations() { loop_iterations_--; }

  private:
    bool     is_looping_{ false };
    uint32_t loop_frame_idx_{ 0 };
    uint32_t loop_iterations_{ std::numeric_limits<uint32_t>::max() };
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_FRAME_LOOP_INFO_H
