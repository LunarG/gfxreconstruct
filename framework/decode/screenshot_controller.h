/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_SCREENSHOT_CONTROLLER_H
#define GFXRECON_DECODE_SCREENSHOT_CONTROLLER_H

#include "decode/replay_options.h"
#include "util/defines.h"
#include "util/image_writer.h"
#include "util/options.h"

#include <functional>
#include <optional>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/**
 * @brief An image that has reached the CPU, ready to become a file.
 *
 * What every API's read-back produces and the only thing the controller needs
 * of it.  Nothing here names a graphics API.
 */
struct CpuImage
{
    uint32_t                       width{ 0 };
    uint32_t                       height{ 0 };
    uint32_t                       pitch{ 0 }; //!< Bytes per row, or 0 for tightly packed rows.
    util::imagewriter::DataFormats format{ util::imagewriter::kFormat_UNSPECIFIED };
    const void*                    pixels{ nullptr };
};

/**
 * @brief How to turn an image the right way up before writing it.
 *
 * Expressed in the image writer's own terms rather than in any API's surface
 * transform, because an API's transform means something only to that API.  The
 * API decides what its transform maps to; this says what to do about it.
 */
struct Rotation
{
    util::imagewriter::ImageRotation rotation{ util::imagewriter::ImageRotation::DEG_0 };
    bool                             mirrored{ false };

    bool IsIdentity() const { return (rotation == util::imagewriter::ImageRotation::DEG_0) && !mirrored; }
};

/**
 * @brief What a caller asks an API's read-back for.
 *
 * The caller has already decided which image to read; this is the shape it
 * wants back.
 */
struct ScreenshotRequest
{
    uint32_t                            width{ 0 };
    uint32_t                            height{ 0 };
    uint32_t                            base_layer{ 0 };
    uint32_t                            layer_count{ 1 };
    std::optional<std::array<float, 2>> scale;    //!< From ScreenshotController::ResolveScale.
    Rotation                            rotation; //!< Applied by Finish, not by the read-back.
};

/**
 * @brief Receives one layer of a read-back image.
 *
 * image.pixels lives no longer than the call, because a read-back hands out
 * the memory it read into and takes it back when it ends.  A caller that needs
 * the pixels afterwards copies them.
 */
using ReadbackCallbackFn = std::function<void(uint32_t layer, const CpuImage& image)>;

/**
 * @brief One API's way of getting a presented image to the CPU.
 *
 * The only part of a screenshot that has to know a graphics API.  Everything
 * above this is shared, and the strategies below it do not resemble each other:
 * one API blits into a converted image, another copies and swizzles on the
 * CPU, and a third draws the conversion.  That is why this is the seam, and
 * why nothing below it is shared.
 */
class ScreenshotSource
{
  public:
    virtual ~ScreenshotSource() = default;

    /**
     * @brief Reads the layers the request asks for and gives each one to the callback.
     *
     * All of the layers are read together, thus one read reaches the GPU once
     * however many layers it asks for.  The callback runs once for each layer
     * that arrives, in the order the layers were read.
     *
     * @return Whether any layer was read.
     */
    virtual bool Readback(const ScreenshotRequest& request, const ReadbackCallbackFn& callback) = 0;
};

/**
 * @brief Everything about a screenshot that is not an API call.
 *
 * Which frames to take, where the files go, what they are called, how big they
 * are, which way up they go, and the one call that writes them.  Each of those
 * used to live in a per-API consumer, thus only Vulkan had all of them.
 */
class ScreenshotController
{
  public:
    /**
     * @brief Reads the options once, and makes the output directory.
     *
     * A directory named by --screenshot-dir that does not exist is created; one
     * that exists as a file is fatal, as it was in the Vulkan consumer this
     * came from.
     */
    explicit ScreenshotController(const ReplayOptions& options);

    //! Whether any frame was asked for.  Nothing else need be called when false.
    bool Enabled() const { return !ranges_.empty(); }

    //! Whether this frame is one of the frames asked for.
    bool IsScreenshotFrame() const;

    //! Advances to the next frame.  Call once per frame, taken or not.
    void EndFrame();

    uint32_t GetCurrentFrame() const { return current_frame_; }

    /**
     * @brief The name of the file for one of this frame's images, no extension.
     *
     * The arguments index and count are only really useful if you have multiple
     * swapchains enabled.  The default values are sufficient for the average
     * use-case.
     *
     * "<prefix>_frame_<n>" for a single image, and
     * "<prefix>_swapchain_<i>_frame_<n>" when a frame presents more than one,
     * so the names stay distinct without changing for the common case.
     */
    std::string FilenameFor(uint32_t index = 0, uint32_t count = 1) const;

    /**
     * @brief The scale to read an image of this size back at.
     *
     * The one place that decides between --screenshot-scale and
     * --screenshot-size: **the scale wins**, and the size is consulted only
     * when no scale was given.  That rule is documented in two places today,
     * with opposite emphasis; this is the authority.
     *
     * @return No value when the image is to be read at its own size.
     */
    std::optional<std::array<float, 2>> ResolveScale(uint32_t width, uint32_t height) const;

    /**
     * @brief Whether --screenshot-prerotation was given.
     *
     * The controller does not read an API's surface transform, because those
     * bits mean something only to that API.  A caller that has one maps it to a
     * Rotation when this is true.
     */
    bool ApplyPreRotation() const { return apply_pre_rotation_; }

    /**
     * @brief Rotates and mirrors if asked, then writes the file.
     *
     * The only caller of RotateAndMirrorPixels and of WriteScreenshotFile.
     *
     * A rotation needs four bytes per pixel, so an image in any other layout
     * is written un-rotated and says so.
     *
     * @return Whether the file was written.
     */
    bool Finish(const std::string& filename_base, const CpuImage& image, const Rotation& rotation);

  private:
    uint32_t                            current_frame_{ 1 };
    size_t                              current_range_{ 0 };
    std::vector<ScreenshotRange>        ranges_;
    uint32_t                            interval_{ 1 };
    util::ScreenshotFormat              format_{ util::ScreenshotFormat::kBmp };
    std::string                         file_prefix_;
    bool                                apply_pre_rotation_{ false };
    std::optional<std::array<float, 2>> scale_;
    uint32_t                            requested_width_{ 0 };
    uint32_t                            requested_height_{ 0 };

    //! Reused between frames, because a rotation needs somewhere to put the result.
    std::vector<uint32_t> rotated_pixels_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SCREENSHOT_CONTROLLER_H
