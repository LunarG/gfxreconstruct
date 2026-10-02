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
#include "decode/screenshot_json.h"
#include "decode/screenshot_result.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/image_writer.h"
#include "util/options.h"

#include "vulkan/vulkan.h"

#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_VkFrameBoundaryEXT;
struct Decoded_VkPresentInfoKHR;
struct VulkanQueueInfo;
struct VulkanSemaphoreInfo;
struct VulkanSurfaceKHRInfo;
struct VulkanSwapchainKHRInfo;

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
 *
 * The controller can also keep a result JSON, "<prefix>.json" next to the
 * screenshots, with one entry for each frame boundary of a screenshot frame:
 * what ended the frame, each image it produced, and whether the file of each
 * was written, and if not, why.
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
     *
     * @param write_result_json Whether to keep the result JSON described above.
     */
    explicit ScreenshotController(const ReplayOptions& options, bool write_result_json = false);

    ~ScreenshotController();

    //! Whether any frame was asked for.  Nothing else need be called when false.
    bool Enabled() const { return !ranges_.empty(); }

    //! Whether this frame is one of the frames asked for.
    bool IsScreenshotFrame() const;

    /**
     * @brief Advances to the next frame.  Call once per frame, taken or not.
     *
     * Closes the entry of the frame in the result JSON, if one is open.  The
     * replay result is the result of the call that ended the frame; a failed
     * one is noted, because the pixels may not be what was captured.
     */
    void EndFrame(std::optional<VkResult> replay_result = std::nullopt);

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
     * The outcome is recorded as that of the current output of the result
     * JSON, when a frame is open.
     *
     * @return Whether the file was written.
     */
    bool Finish(const std::string& filename_base, const CpuImage& image, const Rotation& rotation);

    /**
     * @brief Reads an image through source and writes one file for each of its layers.
     *
     * add_output adds the entry of one layer to the open frame of the result
     * JSON, and runs before that layer is written or recorded as not read.  The
     * file of a layer is "<filename_base>_layer_<n>" when the request has more
     * than one layer, and "<filename_base>" otherwise.
     *
     * @return Whether every layer was written.
     */
    bool WriteOutputs(ScreenshotSource&                          source,
                      const ScreenshotRequest&                   request,
                      const std::string&                         filename_base,
                      const std::function<void(uint32_t layer)>& add_output);

    // Everything below records into the result JSON, and does nothing when there is none or when the frame is not a
    // screenshot frame.

    void BeginFrameSwapchain(const char*             call_name,
                             const VulkanQueueInfo*  queue_info,
                             std::optional<VkResult> capture_result,
                             uint64_t                block_index,
                             uint32_t                swapchain_count)
    {
        BeginFrame("vkQueuePresentKHR", call_name, queue_info, capture_result, block_index);
        SetBoundarySwapchain(swapchain_count);
    }

    void BeginFrameCommandBuffer(const char*             call_name,
                                 const VulkanQueueInfo*  queue_info,
                                 std::optional<VkResult> capture_result,
                                 uint64_t                block_index,
                                 format::HandleId        command_buffer_id)
    {
        BeginFrame("commandBufferFrameBoundary", call_name, queue_info, capture_result, block_index);
        SetBoundaryCommandBuffer(command_buffer_id);
    }

    void BeginFrameFrameBoundaryEXT(const char*                       call_name,
                                    const VulkanQueueInfo*            queue_info,
                                    std::optional<VkResult>           capture_result,
                                    uint64_t                          block_index,
                                    const Decoded_VkFrameBoundaryEXT* frame_boundary)
    {
        BeginFrame("VkFrameBoundaryEXT", call_name, queue_info, capture_result, block_index);
        SetBoundaryFrameBoundaryEXT(frame_boundary);
    }

    void BeginFrameFrameBoundaryANDROID(const char*                call_name,
                                        const VulkanQueueInfo*     queue_info,
                                        std::optional<VkResult>    capture_result,
                                        uint64_t                   block_index,
                                        const VulkanSemaphoreInfo* semaphore_info)
    {
        BeginFrame("vkFrameBoundaryANDROID", call_name, queue_info, capture_result, block_index);
        SetBoundaryFrameBoundaryANDROID(semaphore_info);
    }

    //! Records that the whole frame produced no outputs, with a log line and a reason code.  Mirrors SkipOutput.
    void SkipFrame(const char* code, const std::string& message, bool is_error);

    //! Adds an output entry to the open frame and makes it the current output.  image_index records the position of
    //! the image in the boundary's image list when there is one.
    void AddOutput(const char*           source_kind,
                   format::HandleId      image_id,
                   uint32_t              layer,
                   std::optional<size_t> image_index = std::nullopt);

    //! Adds an output entry for one color attachment of a framebuffer rendered by a frame boundary command buffer.
    void AddFramebufferAttachmentOutput(format::HandleId image_id,
                                        format::HandleId framebuffer_id,
                                        size_t           render_pass_index,
                                        size_t           attachment_index,
                                        format::HandleId image_view_id);

    //! Adds an output entry for one swapchain of a present and records the swapchain slot.
    void AddSwapchainOutput(const char*                     source_kind,
                            format::HandleId                image_id,
                            uint32_t                        layer,
                            const Decoded_VkPresentInfoKHR* meta_info,
                            uint32_t                        swapchain_index,
                            format::HandleId                swapchain_id,
                            uint32_t                        image_index,
                            const VulkanSwapchainKHRInfo*   swapchain_info,
                            const VulkanSurfaceKHRInfo*     surface_info);

    //! The image behind the current output, as it was before any scale or rotation.
    void SetOutputImage(VkFormat format, uint32_t width, uint32_t height, VkSurfaceTransformFlagBitsKHR pre_transform);

    //! Records that the current output was not written, with a log line and a reason code.
    void SkipOutput(const char* code, const std::string& message, bool is_error);

  private:
    //! The result JSON with an entry open for the current frame, or null when the frame is not being recorded.
    ScreenshotJson* GetOpenJsonFrame() { return ((json_ != nullptr) && json_->HasOpenFrame()) ? json_.get() : nullptr; }

    //! Opens the entry of the current frame.  boundary_type says what ended the frame, call_name which call did.
    void BeginFrame(const char*             boundary_type,
                    const char*             call_name,
                    const VulkanQueueInfo*  queue_info,
                    std::optional<VkResult> capture_result,
                    uint64_t                block_index);

    // Boundary details of the open frame.
    void SetBoundarySwapchain(uint32_t swapchain_count);
    void SetBoundaryCommandBuffer(format::HandleId command_buffer_id);
    void SetBoundaryFrameBoundaryEXT(const Decoded_VkFrameBoundaryEXT* frame_boundary);
    void SetBoundaryFrameBoundaryANDROID(const VulkanSemaphoreInfo* semaphore_info);

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

    std::unique_ptr<ScreenshotJson> json_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SCREENSHOT_CONTROLLER_H
