
/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_FPS_INFO_H
#define GFXRECON_GRAPHICS_FPS_INFO_H

#include "util/defines.h"
#include "decode/file_processor.h"

#include <limits>
#include <string_view>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class FpsInfo
{
  public:
    FpsInfo(uint64_t               measurement_start_frame = 1,
            uint64_t               measurement_end_frame   = std::numeric_limits<uint64_t>::max(),
            bool                   has_measurement_range   = false,
            bool                   quit_after_range        = false,
            bool                   flush_measurement_range = false,
            const std::string_view measurement_file_name   = "");

    void LogToConsole();

    void BeginFile();
    bool ShouldWaitIdleBeforeFrame(uint64_t file_processor_frame);
    bool ShouldWaitIdleAfterFrame(uint64_t file_processor_frame);
    bool ShouldQuit(uint64_t file_processor_frame);
    void BeginFrame(uint64_t file_processor_frame);
    void EndFrame(uint64_t file_processor_frame);
    void EndFile(uint64_t end_file_processor_frame);
    void ProcessStateEndMarker(uint64_t file_processor_frame);

  private:
    uint64_t start_time_;

    uint64_t measurement_start_frame_;
    uint64_t measurement_end_frame_;

    int64_t measurement_start_time_;
    int64_t measurement_end_time_;

    uint64_t replay_start_time_;
    int64_t  replay_start_frame_;

    bool has_measurement_range_;
    bool quit_after_range_;
    bool flush_measurement_range_;

    bool started_measurement_;
    bool ended_measurement_;

    int64_t              frame_start_time_;
    std::vector<int64_t> frame_durations_;

    std::string measurement_file_name_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_FPS_INFO_H
