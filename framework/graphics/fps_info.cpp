
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

FpsInfo::FpsInfo(uint64_t measurement_start_frame,
                 uint64_t measurement_end_frame,
                 bool     has_measurement_range,
                 bool     quit_after_range,
                 bool     flush_measurement_range) :
    measurement_start_frame_(measurement_start_frame),
    measurement_end_frame_(measurement_end_frame), measurement_start_time_(0), measurement_end_time_(0),
    quit_after_range_(quit_after_range), flush_measurement_range_(flush_measurement_range),
    has_measurement_range_(has_measurement_range), started_measurement_(false), ended_measurement_(false)
{}

void FpsInfo::BeginFile()
{
    replay_start_frame_ = 1;
    replay_start_time_ = start_time_ = util::datetime::GetTimestamp();
}

bool FpsInfo::ShouldWaitIdleBeforeFrame(uint64_t frame)
{
    bool range_beginning = frame == measurement_start_frame_;
    return flush_measurement_range_ && range_beginning;
}

bool FpsInfo::ShouldQuit(uint64_t frame)
{
    return quit_after_range_ && (frame > measurement_end_frame_);
}

void FpsInfo::BeginFrame(uint64_t frame)
{
    if (!started_measurement_)
    {
        if (frame >= measurement_start_frame_)
        {
            measurement_start_time_ = util::datetime::GetTimestamp();
            started_measurement_    = true;
        }
    }
}

void FpsInfo::EndFrame(uint64_t frame)
{
    if (started_measurement_ && !ended_measurement_)
    {
        // Measurement frame range end is non-inclusive, as opposed to trim frame range
        if (frame >= measurement_end_frame_ - 1)
        {
            measurement_end_time_ = util::datetime::GetTimestamp();
            ended_measurement_    = true;
        }
    }
}

bool FpsInfo::ShouldWaitIdleAfterFrame(uint64_t frame)
{
    bool range_ended = frame == measurement_end_frame_;
    return flush_measurement_range_ && range_ended;
}

void FpsInfo::EndFile(uint64_t frame)
{
    if (!ended_measurement_)
    {
        measurement_end_time_  = gfxrecon::util::datetime::GetTimestamp();
        measurement_end_frame_ = frame;
    }
}

void FpsInfo::ProcessStateEndMarker(uint64_t frame_number)
{
    replay_start_frame_ = frame_number;
    replay_start_time_  = util::datetime::GetTimestamp();
}

void FpsInfo::LogToConsole()
{
    if (!has_measurement_range_)
    {
        // No measurement range or no end limit to range, include trimmed
        // range load statistics.

        if (replay_start_time_ != start_time_)
        {
            GFXRECON_WRITE_CONSOLE("Load time:  %f seconds", GetElapsedSeconds(start_time_, replay_start_time_));
        }
        GFXRECON_WRITE_CONSOLE("Total time: %f seconds", GetElapsedSeconds(start_time_, measurement_end_time_));

        WriteFpsToConsole("Replay FPS:",
                          replay_start_frame_,
                          measurement_end_frame_ - 1 + replay_start_frame_ - 1,
                          replay_start_time_,
                          measurement_end_time_);
    }
    else
    {
        // There was a measurement range, emit only statistics about the
        // measurement range
        double   diff_time_sec = GetElapsedSeconds(measurement_start_time_, measurement_end_time_);
        uint64_t total_frames  = measurement_end_frame_ - measurement_start_frame_;
        double   fps           = static_cast<double>(total_frames) / diff_time_sec;
        GFXRECON_WRITE_CONSOLE("Measurement range FPS: %f fps, %f seconds, %lu frame%s, 1 loop, framerange [%lu-%lu)",
                               fps,
                               diff_time_sec,
                               total_frames,
                               total_frames > 1 ? "s" : "",
                               measurement_start_frame_,
                               measurement_end_frame_);
    }
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
