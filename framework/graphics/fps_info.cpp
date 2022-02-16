
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

FpsInfo::FpsInfo(uint64_t measurement_start_frame,
                 uint64_t measurement_end_frame,
                 bool     quit_after_range,
                 bool     flush_measurement_range) :
    file_processor_(nullptr),
    measurement_start_frame_(measurement_start_frame), measurement_end_frame_(measurement_end_frame),
    measurement_start_time_(0), measurement_end_time_(0), quit_after_range_(quit_after_range),
    flush_measurement_range_(flush_measurement_range)
{}

void FpsInfo::SetFileProcessor(gfxrecon::decode::FileProcessor* file_processor)
{
    file_processor_ = file_processor;
}

void FpsInfo::ProcessStateEndMarker(uint64_t frame)
{
    measurement_start_frame_ = frame;
    measurement_start_time_  = util::datetime::GetTimestamp();
}

bool FpsInfo::ShouldQuit()
{
    return quit_after_range_ && (file_processor_->GetCurrentFrameNumber() >= measurement_end_frame_);
}

void FpsInfo::HandleMeasurementRange()
{
    if (file_processor_ == nullptr)
    {
        GFXRECON_LOG_WARNING("File processor is not set in FpsInfo object. Cannot calculate FPS statistics.");
        return;
    }

    if (file_processor_->GetCurrentFrameNumber() == measurement_start_frame_)
    {
        if (flush_measurement_range_)
        {
            file_processor_->WaitDecodersIdle();
        }

        measurement_start_time_ = gfxrecon::util::datetime::GetTimestamp();
    }
    else if (file_processor_->GetCurrentFrameNumber() == measurement_end_frame_)
    {
        // End before replay -> non inclusive range
        if (flush_measurement_range_)
        {
            file_processor_->WaitDecodersIdle();
        }

        measurement_end_time_ = gfxrecon::util::datetime::GetTimestamp();
    }
}

void FpsInfo::WriteMeasurementRangeFpsToConsole()
{
    if (file_processor_ == nullptr)
    {
        GFXRECON_LOG_WARNING("File processor is not set in FpsInfo object. Cannot calculate FPS statistics.");
        return;
    }

    if (file_processor_->GetErrorState() != gfxrecon::decode::FileProcessor::kErrorNone)
    {
        GFXRECON_LOG_ERROR("A failure has occurred during replay, cannot calculate measurement range FPS.");
        return;
    }

    if (measurement_start_frame_ >= measurement_end_frame_)
    {
        GFXRECON_LOG_WARNING("Measurement start frame (%u) is greater than or equal to the end frame (%u). "
                             "Cannot calculate measurement range FPS.",
                             measurement_start_frame_,
                             measurement_end_frame_);

        return;
    }

    if (file_processor_->GetCurrentFrameNumber() < measurement_start_frame_)
    {
        GFXRECON_LOG_WARNING("Measurement range start frame (%u) is greater than the last replayed frame (%u). "
                             "Measurements were never started, cannot calculate measurement range FPS.",
                             measurement_start_frame_,
                             file_processor_->GetCurrentFrameNumber());
        return;
    }

    // Here we clip the range for convenience.
    if (file_processor_->GetCurrentFrameNumber() < measurement_end_frame_)
    {
        file_processor_->WaitDecodersIdle();
        measurement_end_time_  = gfxrecon::util::datetime::GetTimestamp();
        measurement_end_frame_ = file_processor_->GetCurrentFrameNumber() + 1;
    }

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

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)
