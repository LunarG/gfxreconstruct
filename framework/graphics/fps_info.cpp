
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

#include "graphics/fps_info.h"

#include "util/date_time.h"
#include "util/logging.h"

#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

static double GetElapsedSeconds(uint64_t start_time, uint64_t end_time)
{
    return util::datetime::ConvertTimestampToSeconds(util::datetime::DiffTimestamps(start_time, end_time));
}

static void
WriteFpsToConsole(const char* prefix, uint64_t start_frame, uint64_t end_frame, int64_t start_time, int64_t end_time)
{
    assert(end_frame >= start_frame && end_time >= start_time);

    double   diff_time_sec = GetElapsedSeconds(start_time, end_time);
    uint64_t total_frames  = (end_frame - start_frame) + 1;
    double   fps           = (diff_time_sec > 0.0) ? (static_cast<double>(total_frames) / diff_time_sec) : 0.0;
    GFXRECON_WRITE_CONSOLE("%s %f fps, %f seconds, %" PRIu64 " frame%s, framerange %" PRIu64 "-%" PRIu64,
                           prefix,
                           fps,
                           diff_time_sec,
                           total_frames,
                           total_frames > 1 ? "s" : "",
                           start_frame,
                           end_frame);
}

void FpsInfo::SetStartTime()
{
    start_time_ = util::datetime::GetTimestamp();
}

void FpsInfo::Begin(uint64_t start_frame)
{
    // Save the start frame/time information for the FPS result.
    replay_start_frame_ = start_frame;
    begin_frame_        = start_frame;
    replay_start_time_  = util::datetime::GetTimestamp();
}

void FpsInfo::EndAndLog(uint64_t end_frame)
{
    // Get the end frame/time information and calculate FPS.
    int64_t end_time = util::datetime::GetTimestamp();

    bool include_load = begin_frame_ == 1;

    if (include_load)
    {
        if (replay_start_time_ != start_time_)
        {
            GFXRECON_WRITE_CONSOLE("Load time:  %f seconds", GetElapsedSeconds(start_time_, replay_start_time_));
        }
        GFXRECON_WRITE_CONSOLE("Total time: %f seconds", GetElapsedSeconds(start_time_, end_time));
        WriteFpsToConsole(
            "Replay FPS:", replay_start_frame_, end_frame + replay_start_frame_ - 1, replay_start_time_, end_time);
    }
    else
    {
        WriteFpsToConsole("Measurement range FPS:", begin_frame_, end_frame - 1, replay_start_time_, end_time);
    }
}

void FpsInfo::ProcessStateEndMarker(uint64_t frame)
{
    replay_start_frame_ = frame;
    replay_start_time_  = util::datetime::GetTimestamp();
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
