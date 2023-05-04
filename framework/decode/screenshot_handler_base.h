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

#ifndef GFXRECON_DECODE_SCREENSHOT_HANDLER_BASE_H
#define GFXRECON_DECODE_SCREENSHOT_HANDLER_BASE_H

#include "util/defines.h"
#include "util/options.h"

#include "decode/replay_options.h"

#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class ScreenshotHandlerBase
{
  public:
    ScreenshotHandlerBase(util::ScreenshotFormat              screenshot_format,
                          const std::vector<ScreenshotRange>& screenshot_ranges);

    ScreenshotHandlerBase(util::ScreenshotFormat screenshot_format, std::vector<ScreenshotRange>&& screenshot_ranges);

    uint32_t GetCurrentFrame() const { return current_frame_number_; }

    void EndFrame();

    bool IsScreenshotFrame() const;

  protected:
    uint32_t                     current_frame_number_;
    util::ScreenshotFormat       screenshot_format_;
    std::vector<ScreenshotRange> screenshot_ranges_;
    size_t                       current_range_index_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SCREENSHOT_HANDLER_BASE_H
