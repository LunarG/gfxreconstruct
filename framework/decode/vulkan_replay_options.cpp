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

#include <mutex>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void VulkanReplayOptions::MaybeWaitBeforeFirstSubmit() const
{
    static std::once_flag flag;
    std::call_once(flag, [this]() {
        if (wait_before_first_submit > 0)
        {
            auto current_time    = std::chrono::high_resolution_clock::now();
            auto time_elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time);
            auto wait_before_first_submit_ms = std::chrono::milliseconds(wait_before_first_submit);
            if (time_elapsed_ms < wait_before_first_submit_ms)
            {
                auto time_to_wait = wait_before_first_submit_ms - time_elapsed_ms;
                GFXRECON_LOG_INFO("Waiting %u ms before first queue submit.", time_to_wait);
                std::this_thread::sleep_for(time_to_wait);
            }
        }
    });
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
