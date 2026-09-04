/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "decode/screenshot_controller.h"

#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cstdlib>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

ScreenshotController::ScreenshotController(const ReplayOptions& options) :
    ranges_(options.screenshot_ranges), interval_(options.screenshot_interval), format_(options.screenshot_format),
    file_prefix_(options.screenshot_file_prefix), apply_pre_rotation_(options.screenshot_apply_prerotation),
    scale_(options.screenshot_scale), requested_width_(options.screenshot_width),
    requested_height_(options.screenshot_height)
{
    // An interval of zero would divide by zero in IsScreenshotFrame.  The
    // option parser already reports and corrects this; guard anyway, because
    // this class is also constructed from options built in a test.
    if (interval_ == 0)
    {
        interval_ = 1;
    }

    if (file_prefix_.empty())
    {
        file_prefix_ = kDefaultScreenshotFilePrefix;
    }

    if (options.screenshot_dir.empty())
    {
        return;
    }

    if (util::filepath::Exists(options.screenshot_dir))
    {
        if (!util::filepath::IsDirectory(options.screenshot_dir))
        {
            GFXRECON_WRITE_CONSOLE("Error while creating directory %s: Already exists as file",
                                   options.screenshot_dir.c_str());
            exit(-1);
        }
    }
    else if (util::platform::MakeDirectory(options.screenshot_dir.c_str()) < 0)
    {
        GFXRECON_WRITE_CONSOLE("Error while creating directory %s: Could not open", options.screenshot_dir.c_str());
        exit(-1);
    }

    file_prefix_ = util::filepath::Join(options.screenshot_dir, file_prefix_);
}

bool ScreenshotController::IsScreenshotFrame() const
{
    if (current_range_ >= ranges_.size())
    {
        return false;
    }

    const ScreenshotRange& range = ranges_[current_range_];

    return (range.first <= current_frame_) && (range.last >= current_frame_) &&
           (((current_frame_ - range.first) % interval_) == 0);
}

void ScreenshotController::EndFrame()
{
    if ((current_range_ < ranges_.size()) && (ranges_[current_range_].last == current_frame_))
    {
        ++current_range_;
    }

    ++current_frame_;
}

std::string ScreenshotController::FilenameFor(uint32_t index, uint32_t count) const
{
    std::string filename = file_prefix_;

    // Only named when there is more than one, so the usual case keeps the name
    // it has always had.
    if (count > 1)
    {
        filename += "_swapchain_" + std::to_string(index);
    }

    filename += "_frame_" + std::to_string(current_frame_);

    return filename;
}

std::optional<std::array<float, 2>> ScreenshotController::ResolveScale(uint32_t width, uint32_t height) const
{
    if (scale_)
    {
        return scale_;
    }

    if ((requested_width_ > 0) && (requested_height_ > 0) && (width > 0) && (height > 0))
    {
        return std::array<float, 2>{ static_cast<float>(requested_width_) / static_cast<float>(width),
                                     static_cast<float>(requested_height_) / static_cast<float>(height) };
    }

    return {};
}

bool ScreenshotController::Finish(const std::string& filename_base, const CpuImage& image, const Rotation& rotation)
{
    if (image.pixels == nullptr)
    {
        GFXRECON_LOG_ERROR("Screenshot could not be created: the image was not read back");
        return false;
    }

    uint32_t    width      = image.width;
    uint32_t    height     = image.height;
    uint32_t    pitch      = image.pitch;
    const void* write_from = image.pixels;

    if (!rotation.IsIdentity())
    {
        // RotateAndMirrorPixels moves whole 32-bit pixels, thus it can only
        // serve a four-byte layout.  Anything else is written the way it came,
        // which is better than writing it wrongly turned.
        if (util::imagewriter::DataFormatsSizes(image.format) != 4)
        {
            GFXRECON_LOG_WARNING_ONCE("A screenshot in this format cannot be rotated, thus it is written unrotated.");
        }
        else
        {
            const bool quarter_turn = (rotation.rotation == util::imagewriter::ImageRotation::DEG_90) ||
                                      (rotation.rotation == util::imagewriter::ImageRotation::DEG_270);

            const uint32_t rotated_width  = quarter_turn ? image.height : image.width;
            const uint32_t rotated_height = quarter_turn ? image.width : image.height;

            rotated_pixels_.resize(static_cast<size_t>(rotated_width) * rotated_height);

            util::imagewriter::RotateAndMirrorPixels(rotation.rotation,
                                                     rotation.mirrored,
                                                     static_cast<const uint32_t*>(image.pixels),
                                                     rotated_pixels_.data(),
                                                     image.width,
                                                     image.height,
                                                     rotated_width,
                                                     rotated_height);

            width      = rotated_width;
            height     = rotated_height;
            pitch      = rotated_width * 4;
            write_from = rotated_pixels_.data();
        }
    }

    return util::imagewriter::WriteScreenshotFile(
        filename_base, format_, width, height, write_from, pitch, image.format);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
