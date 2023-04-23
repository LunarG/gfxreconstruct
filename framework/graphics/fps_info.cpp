
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
#include "util/platform.h"
#include "util/json_util.h"

#include "nlohmann/json.hpp"
#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

static double GetElapsedSeconds(uint64_t start_time, uint64_t end_time)
{
    return util::datetime::ConvertTimestampToSeconds(util::datetime::DiffTimestamps(start_time, end_time));
}

FpsInfo::FpsInfo(uint64_t               measurement_start_frame,
                 uint64_t               measurement_end_frame,
                 bool                   has_measurement_range,
                 bool                   quit_after_range,
                 bool                   flush_measurement_range,
                 bool                   flush_inside_measurement_range,
                 uint32_t               looping_end_after_count,
                 uint64_t               looping_end_after_duration,
                 const std::string_view measurement_file_name) :
    measurement_start_frame_(measurement_start_frame),
    measurement_end_frame_(measurement_end_frame), measurement_start_time_(0), measurement_end_time_(0),
    quit_after_range_(quit_after_range), flush_measurement_range_(flush_measurement_range),
    flush_inside_measurement_range_(flush_inside_measurement_range), has_measurement_range_(has_measurement_range),
    looping_end_after_count_(looping_end_after_count), looping_end_after_duration_(looping_end_after_duration),
    started_measurement_(false), ended_measurement_(false), loop_start_time_(0), loop_end_time_(0), total_loop_time_(0),
    load_start_time_(0), load_end_time_(0), total_load_time_(0), replay_start_time_(0), replay_end_time_(0),
    total_replay_time_(0), frame_start_time_(0), frame_durations_(), measurement_file_name_(measurement_file_name)
{
    if (has_measurement_range_)
    {
        GFXRECON_ASSERT(!measurement_file_name_.empty());
    }
}

void FpsInfo::BeginFile()
{
    replay_start_frame_ = 1;
}

void FpsInfo::BeginLoop()
{
    uint64_t now = util::datetime::GetTimestamp();

    loop_start_time_ = now;

    load_start_time_ = now;
    load_end_time_   = now;

    replay_start_time_ = now;
}

void FpsInfo::EndLoad(uint64_t capture_file_frame)
{
    uint64_t now = util::datetime::GetTimestamp();

    replay_start_frame_ = capture_file_frame;
    replay_start_time_  = now;

    load_end_time_ = now;
}

void FpsInfo::EndLoop()
{
    uint64_t now = util::datetime::GetTimestamp();

    replay_end_time_ = now;
    loop_end_time_   = now;

    total_replay_time_ += util::datetime::DiffTimestamps(replay_start_time_, replay_end_time_);
    total_load_time_ += util::datetime::DiffTimestamps(load_start_time_, load_end_time_);
    total_loop_time_ += util::datetime::DiffTimestamps(loop_start_time_, loop_end_time_);
}

void FpsInfo::EndFile(uint64_t frame)
{
    uint64_t now = util::datetime::GetTimestamp();

    if (!ended_measurement_)
    {
        measurement_end_time_  = now;
        measurement_end_frame_ = frame;
    }
}

void FpsInfo::BeginFrame(uint64_t frame)
{
    if (!started_measurement_)
    {
        if (frame >= measurement_start_frame_)
        {
            measurement_start_time_ = util::datetime::GetTimestamp();
            started_measurement_    = true;
            frame_durations_.clear();
        }
    }

    frame_start_time_ = util::datetime::GetTimestamp();
}

void FpsInfo::EndFrame(uint64_t frame)
{
    if (started_measurement_ && !ended_measurement_)
    {
        frame_durations_.push_back(util::datetime::DiffTimestamps(frame_start_time_, util::datetime::GetTimestamp()));

        // Measurement frame range end is non-inclusive, as opposed to trim frame range
        if (frame >= measurement_end_frame_ - 1)
        {
            measurement_end_time_ = util::datetime::GetTimestamp();
            ended_measurement_    = true;

            // Save measurements to file
            if (!measurement_file_name_.empty())
            {
                double   start_time   = util::datetime::ConvertTimestampToSeconds(measurement_start_time_);
                double   end_time     = util::datetime::ConvertTimestampToSeconds(measurement_end_time_);
                double   diff_time    = GetElapsedSeconds(measurement_start_time_, measurement_end_time_);
                uint64_t total_frames = measurement_end_frame_ - measurement_start_frame_;
                double   fps          = static_cast<double>(total_frames) / diff_time;

                nlohmann::json file_content = { { "frame_range",
                                                  { { "start_frame", measurement_start_frame_ },
                                                    { "end_frame", measurement_end_frame_ },
                                                    { "frame_count", total_frames },
                                                    { "start_time_monotonic", start_time },
                                                    { "end_time_monotonic", end_time },
                                                    { "duration", diff_time },
                                                    { "fps", fps },
                                                    { "frame_durations", frame_durations_ } } } };

                FILE*   file_pointer = nullptr;
                int32_t result       = util::platform::FileOpen(&file_pointer, measurement_file_name_.c_str(), "w");
                if (result == 0)
                {
                    const std::string json_string = file_content.dump(util::kJsonIndentWidth);

                    const size_t size_written =
                        util::platform::FileWrite(json_string.data(), 1, json_string.size(), file_pointer);
                    util::platform::FileClose(file_pointer);

                    // It either writes a fully valid file, or it doesn't write anything !
                    if (size_written != json_string.size())
                    {
                        GFXRECON_LOG_ERROR("Failed to write to measurements file '%s'.",
                                           measurement_file_name_.c_str());

                        // Try to delete the partial file from disk using <cstdio>
                        const int remove_result = std::remove(measurement_file_name_.c_str());
                        if (remove_result != 0)
                        {
                            GFXRECON_LOG_ERROR("Failed to remove measurements file '%s' (Error %i).",
                                               measurement_file_name_.c_str(),
                                               remove_result);
                        }
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR(
                        "Failed to open measurements file '%s' (Error %i).", measurement_file_name_.c_str(), result);
                    GFXRECON_LOG_ERROR("%s", std::strerror(result));
                }
            }
        }
    }
}

bool FpsInfo::ShouldWaitIdleBeforeFrame(uint64_t frame)
{
    bool range_beginning = frame == measurement_start_frame_;
    return flush_measurement_range_ && range_beginning;
}

bool FpsInfo::ShouldWaitIdleAfterFrame(uint64_t frame)
{
    bool range_ended  = frame == measurement_end_frame_;
    bool inside_range = frame >= measurement_start_frame_ && frame <= measurement_end_frame_;
    return (flush_measurement_range_ && range_ended) || (flush_inside_measurement_range_ && inside_range);
}

bool FpsInfo::ShouldQuit(uint64_t frame)
{
    return quit_after_range_ && (frame > measurement_end_frame_);
}

bool FpsInfo::ShouldLoop(uint32_t loop_number)
{
    bool should_loop = true;

    bool looping_count_satisfied    = false;
    bool looping_duration_satisfied = false;

    if (looping_end_after_count_ > 0)
    {
        if (loop_number >= looping_end_after_count_)
        {
            looping_count_satisfied = true;
            GFXRECON_LOG_DEBUG("Ending condition satisfied: loop count (%" PRIu32 ")", looping_end_after_count_);
        }
    }

    if (looping_end_after_duration_ > 0)
    {
        double current_duration = util::datetime::ConvertTimestampToSeconds(total_loop_time_);

        if (current_duration >= looping_end_after_duration_)
        {
            looping_duration_satisfied = true;
            GFXRECON_LOG_DEBUG("Ending condition satisfied: looping duration (%" PRIu64 ")",
                               looping_end_after_duration_);
        }
    }

    if (looping_count_satisfied || looping_duration_satisfied)
    {
        should_loop = false;
    }

    return should_loop;
}

void FpsInfo::LogToConsole()
{
    if (!has_measurement_range_)
    {
        // No measurement range or no end limit to range, include trimmed
        // range load statistics.
        if (total_load_time_ > 0)
        {
            GFXRECON_WRITE_CONSOLE("Load time: %f seconds",
                                   util::datetime::ConvertTimestampToSeconds(total_load_time_));
        }

        GFXRECON_WRITE_CONSOLE("Total time: %f seconds", util::datetime::ConvertTimestampToSeconds(total_loop_time_));

        uint64_t replay_end_frame = measurement_end_frame_ - 1 + replay_start_frame_ - 1;

        double   diff_time_sec = util::datetime::ConvertTimestampToSeconds(total_replay_time_);
        uint64_t total_frames  = (replay_end_frame - replay_start_frame_) + 1;
        double   fps           = (diff_time_sec > 0.0) ? (static_cast<double>(total_frames) / diff_time_sec) : 0.0;

        GFXRECON_WRITE_CONSOLE("Replay FPS: %f fps, %f seconds, %" PRIu64 " frame%s, framerange %" PRIu64 "-%" PRIu64,
                               fps,
                               diff_time_sec,
                               total_frames,
                               total_frames > 1 ? "s" : "",
                               replay_start_frame_,
                               replay_end_frame);
    }
    else
    {
        // There was a measurement range, emit only statistics about the
        // measurement range
        double   diff_time_sec = GetElapsedSeconds(measurement_start_time_, measurement_end_time_);
        uint64_t total_frames  = measurement_end_frame_ - measurement_start_frame_;
        double   fps           = (diff_time_sec > 0.0) ? (static_cast<double>(total_frames) / diff_time_sec) : 0.0;
        GFXRECON_WRITE_CONSOLE("Measurement range FPS: %f fps, %f seconds, %" PRIu64 " frame%s, framerange [%" PRIu64
                               "-%" PRIu64 ")",
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
