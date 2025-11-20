
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
#include "nlohmann/json.hpp"
#include "util/json_util.h"

#include <cinttypes>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

FpsInfo::FpsInfo(uint64_t               measurement_start_frame,
                 uint64_t               measurement_end_frame,
                 bool                   has_measurement_range,
                 bool                   quit_after_range,
                 bool                   flush_measurement_range,
                 bool                   flush_inside_measurement_range,
                 bool                   preload_measurement_range,
                 const std::string_view measurement_file_name,
                 bool                   quit_after_frame,
                 uint64_t               quit_frame) :
    start_time_(0),
    replay_start_time_(0), replay_end_time_(0), measurement_start_time_(0), measurement_end_time_(0),
    measurement_start_boot_time_(0), measurement_end_boot_time_(0), measurement_start_process_time_(0),
    measurement_end_process_time_(0), replay_start_frame_(0), measurement_start_frame_(measurement_start_frame),
    measurement_end_frame_(measurement_end_frame), has_measurement_range_(has_measurement_range),
    quit_after_range_(quit_after_range), flush_measurement_range_(flush_measurement_range),
    flush_inside_measurement_range_(flush_inside_measurement_range), started_measurement_(false),
    ended_measurement_(false), frame_start_time_(0), frame_durations_(), measurement_file_name_(measurement_file_name),
    preload_measurement_range_(preload_measurement_range), quit_after_frame_(quit_after_frame), quit_frame_(quit_frame)
{
    if (has_measurement_range_)
    {
        if (util::filepath::IsFile(measurement_file_name_))
        {
            GFXRECON_LOG_WARNING("Removing existing file at measurement file location: %s",
                                 measurement_file_name_.c_str());
            std::remove(measurement_file_name_.c_str());
        }
    }
}

void FpsInfo::BeginFile()
{
    replay_start_frame_ = 1;
    replay_start_time_ = start_time_ = static_cast<uint64_t>(util::datetime::GetTimestamp());
}

bool FpsInfo::ShouldWaitIdleBeforeFrame(uint64_t frame)
{
    bool range_beginning = frame == measurement_start_frame_;
    return flush_measurement_range_ && range_beginning;
}

bool FpsInfo::ShouldQuit(uint64_t frame)
{
    return (quit_after_range_ && (frame > measurement_end_frame_)) || (quit_after_frame_ && frame > quit_frame_);
}

void FpsInfo::BeginFrame(uint64_t frame)
{
    if (!started_measurement_)
    {
        if (frame >= measurement_start_frame_)
        {
            measurement_start_boot_time_    = util::datetime::GetBootTime();
            measurement_start_time_         = util::datetime::GetTimestamp();
            measurement_start_process_time_ = util::datetime::GetProcessTime();
            started_measurement_            = true;
            GFXRECON_WRITE_CONSOLE("================== Start timer (Frame: %llu) ==================", frame);
            frame_durations_.clear();
        }
    }

    frame_start_time_ = util::datetime::GetTimestamp();
}

void FpsInfo::EndFrame(uint64_t frame)
{
    if (started_measurement_ && !ended_measurement_)
    {
        int64_t frame_end_time = util::datetime::GetTimestamp();
        frame_durations_.push_back(util::datetime::DiffTimestamps(frame_start_time_, frame_end_time));

        // Measurement frame range end is non-inclusive, as opposed to trim frame range
        if (frame >= measurement_end_frame_ - 1)
        {
            measurement_end_boot_time_    = util::datetime::GetBootTime();
            measurement_end_process_time_ = util::datetime::GetProcessTime();
            measurement_end_time_         = frame_end_time;
            ended_measurement_            = true;
            GFXRECON_WRITE_CONSOLE("================== End timer (Frame: %llu) ==================", frame);
        }
    }
}

bool FpsInfo::ShouldWaitIdleAfterFrame(uint64_t frame)
{
    bool range_ended  = frame == measurement_end_frame_;
    bool inside_range = frame >= measurement_start_frame_ && frame <= measurement_end_frame_;
    return (flush_measurement_range_ && range_ended) || (flush_inside_measurement_range_ && inside_range);
}

void FpsInfo::EndFile(uint64_t frame)
{
    replay_end_time_ = gfxrecon::util::datetime::GetTimestamp();

    if (!ended_measurement_)
    {
        measurement_end_boot_time_    = util::datetime::GetBootTime();
        measurement_end_process_time_ = util::datetime::GetProcessTime();
        measurement_end_time_         = replay_end_time_;
        measurement_end_frame_        = frame;
        GFXRECON_WRITE_CONSOLE("================== End timer (Frame: %llu) ==================", frame);
    }
}

void FpsInfo::ProcessStateEndMarker(uint64_t frame_number)
{
    replay_start_frame_  = static_cast<int64_t>(frame_number);
    replay_start_time_   = static_cast<uint64_t>(util::datetime::GetTimestamp());
    started_measurement_ = false; // End of loading trimmed state, so we reset the measurement if it started too soon
}

void FpsInfo::LogMeasurements()
{
    double start_time_monotonic = util::datetime::ConvertTimestampToSeconds(measurement_start_time_);
    double end_time_monotonic   = util::datetime::ConvertTimestampToSeconds(measurement_end_time_);

    double   load_time       = util::datetime::GetElapsedSeconds(start_time_, replay_start_time_);
    double   total_time      = util::datetime::GetElapsedSeconds(start_time_, replay_end_time_);
    double   measured_time   = util::datetime::GetElapsedSeconds(measurement_start_time_, measurement_end_time_);
    uint64_t measured_frames = measurement_end_frame_ - measurement_start_frame_;
    double   measured_fps    = (measured_time > 0.0) ? static_cast<double>(measured_frames) / measured_time : 0.0;

    GFXRECON_WRITE_CONSOLE("Load time:  %f seconds (frame %lu)", load_time, replay_start_frame_);
    GFXRECON_WRITE_CONSOLE("Total time: %f seconds", total_time);
    GFXRECON_WRITE_CONSOLE("Measured FPS: %f fps, %f seconds, %lu frame%s, 1 loop, framerange [%lu-%lu)",
                           measured_fps,
                           measured_time,
                           measured_frames,
                           measured_frames > 1 ? "s" : "",
                           measurement_start_frame_,
                           measurement_end_frame_);

    // Save measurements to file
    if (has_measurement_range_)
    {
        nlohmann::json file_content = { { "frame_range",
                                          { { "start_frame", measurement_start_frame_ },
                                            { "end_frame", measurement_end_frame_ },
                                            { "frame_count", measured_frames },
                                            { "start_time_boot", measurement_start_boot_time_ },
                                            { "start_time_process", measurement_start_process_time_ },
                                            { "start_time_monotonic", start_time_monotonic },
                                            { "end_time_boot", measurement_end_boot_time_ },
                                            { "end_time_process", measurement_end_process_time_ },
                                            { "end_time_monotonic", end_time_monotonic },
                                            { "duration", measured_time },
                                            { "fps", measured_fps },
                                            { "frame_durations", frame_durations_ } } } };

        FILE*   file_pointer = nullptr;
        int32_t result       = util::platform::FileOpen(&file_pointer, measurement_file_name_.c_str(), "w");
        if (result == 0)
        {
            const std::string json_string = file_content.dump(util::kJsonIndentWidth);

            const bool success = util::platform::FileWrite(json_string.data(), json_string.size(), file_pointer);
            util::platform::FileClose(file_pointer);

            // It either writes a fully valid file, or it doesn't write anything !
            if (!success)
            {
                GFXRECON_LOG_ERROR("Failed to write to measurements file '%s'.", measurement_file_name_.c_str());

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

uint64_t FpsInfo::ShouldPreloadFrames(uint64_t current_frame) const
{
    uint64_t result = 0;
    if (preload_measurement_range_ && current_frame == measurement_start_frame_)
    {
        result = measurement_end_frame_ - measurement_start_frame_;
    }
    return result;
}

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
