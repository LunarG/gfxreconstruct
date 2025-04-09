/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/screenshot_handler_base.h"

#include "util/image_writer.h"
#include "util/logging.h"
#include "util/platform.h"

#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

ScreenshotHandlerBase::ScreenshotHandlerBase(util::ScreenshotFormat              screenshot_format,
                                             const std::vector<ScreenshotRange>& screenshot_ranges,
                                             uint32_t                            screenshot_interval) :
    current_frame_number_(1),
    screenshot_format_(screenshot_format), screenshot_ranges_(screenshot_ranges),
    screenshot_interval_(screenshot_interval), current_range_index_(0)
{}

ScreenshotHandlerBase::ScreenshotHandlerBase(util::ScreenshotFormat         screenshot_format,
                                             std::vector<ScreenshotRange>&& screenshot_ranges,
                                             uint32_t                       screenshot_interval) :
    current_frame_number_(1),
    screenshot_format_(screenshot_format), screenshot_ranges_(std::move(screenshot_ranges)),
    screenshot_interval_(screenshot_interval), current_range_index_(0)
{}

void ScreenshotHandlerBase::EndFrame()
{
    if (current_range_index_ < screenshot_ranges_.size())
    {
        const auto& current_range = screenshot_ranges_[current_range_index_];
        if (current_range.last == current_frame_number_)
        {
            ++current_range_index_;
        }
    }

    ++current_frame_number_;
}

bool ScreenshotHandlerBase::IsScreenshotFrame() const
{
    if (current_range_index_ < screenshot_ranges_.size())
    {
        const auto& current_range = screenshot_ranges_[current_range_index_];
        if ((current_range.first <= current_frame_number_) && (current_range.last >= current_frame_number_) &&
            ((current_frame_number_ - current_range.first) % screenshot_interval_ == 0))
        {
            return true;
        }
    }

    return false;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
