/*
** Copyright (c) 2026 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_VULKAN_SCREENSHOT_JSON_H
#define GFXRECON_DECODE_VULKAN_SCREENSHOT_JSON_H

#include "decode/replay_options.h"
#include "decode/screenshot_controller.h"
#include "decode/screenshot_result.h"
#include "decode/vulkan_object_info.h"
#include "format/format.h"
#include "util/defines.h"
#include "util/json_util.h"

#include "vulkan/vulkan.h"

#include <array>
#include <cstdint>
#include <cstdio>
#include <optional>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_VkFrameBoundaryEXT;
struct Decoded_VkPresentInfoKHR;

/**
 * @brief The record of every screenshot the Vulkan consumer takes, or does not take.
 *
 * Written as "<prefix>.json" next to the screenshots: a header block, one block for each frame the
 * ScreenshotController asked for, and a summary block. A frame block says which boundary ended the
 * frame, which images it presented, and for each image whether a file was written and if not, why.
 *
 * A frame is open between BeginFrame and EndFrame. Every other call is a no-op when no frame is
 * open, so the consumer records unconditionally and only the frames asked for reach the file.
 */
class VulkanScreenshotJson
{
  public:
    static constexpr uint32_t kSchemaVersion = 1;

    // The "source" and "present" parts of an output entry: what is read, not how it went. Built once for an image
    // and used for each of its layers.
    struct OutputSource
    {
        nlohmann::ordered_json source;
        // Used to store presentation information for swapchain images
        nlohmann::ordered_json present;
    };

    // The image an output was read back from.
    struct OutputImage
    {
        VkFormat                      format{ VK_FORMAT_UNDEFINED };
        uint32_t                      width{ 0 };
        uint32_t                      height{ 0 };
        VkSurfaceTransformFlagBitsKHR pre_transform{ VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR };
    };

    // Opens the file. Records nothing when it cannot be opened, and says so once.
    VulkanScreenshotJson(const ReplayOptions& options, const ScreenshotController& controller);

    // Closes the open frame, if any, and writes the summary.
    ~VulkanScreenshotJson();

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

    // Records that the whole frame produced no outputs, with a log line and a reason code. Mirrors SkipOutput.
    void SkipFrame(const char* code, const std::string& message, bool is_error);

    // Closes the frame entry. The controller's own EndFrame is still the caller's to make.
    void EndFrame(std::optional<VkResult> replay_result);

    // Describes an image as the source of outputs. image_index records the position of the image in the boundary's
    // image list when there is one.
    OutputSource ImageSource(const char*           source_kind,
                             format::HandleId      image_id,
                             std::optional<size_t> image_index = std::nullopt) const;

    // Describes one color attachment of a framebuffer rendered by a frame boundary command buffer.
    OutputSource FramebufferAttachmentSource(format::HandleId image_id,
                                             format::HandleId framebuffer_id,
                                             size_t           render_pass_index,
                                             size_t           attachment_index,
                                             format::HandleId image_view_id) const;

    // Describes one attachment of a vkCmdBeginRendering rendered by a frame boundary command buffer. attachment_kind
    // is "color", "depth" or "stencil"; attachment_index is the position among the color attachments.
    OutputSource DynamicRenderingAttachmentSource(format::HandleId      image_id,
                                                  size_t                rendering_index,
                                                  const char*           attachment_kind,
                                                  std::optional<size_t> attachment_index,
                                                  format::HandleId      image_view_id) const;

    // Describes one swapchain of a present, with everything from VkPresentInfoKHR and its pNext chain that applies
    // to that swapchain, plus what replay knows about the surface.
    OutputSource SwapchainSource(const char*                     source_kind,
                                 format::HandleId                image_id,
                                 const Decoded_VkPresentInfoKHR* meta_info,
                                 uint32_t                        swapchain_index,
                                 format::HandleId                swapchain_id,
                                 uint32_t                        image_index,
                                 const VulkanSwapchainKHRInfo*   swapchain_info,
                                 const VulkanSurfaceKHRInfo*     surface_info) const;

    // Adds the output of one layer that was read back from image to the open frame, with the outcome
    // ScreenshotController::Finish reported for it.
    void RecordOutput(const OutputSource&          source,
                      uint32_t                     layer,
                      const OutputImage&           image,
                      const ScreenshotWriteResult& result);

    // Adds an output that was not written to the open frame, with a log line and a reason code.
    void SkipOutput(const OutputSource& source,
                    const OutputImage*  image,
                    uint32_t            layer,
                    const char*         code,
                    const std::string&  message,
                    bool                is_error);

    void AddFrameMessage(const std::string&      code,
                         const std::string&      message,
                         std::optional<VkResult> vk_result = std::nullopt);

  private:
    bool Open(const std::string& filename);

    void Close(uint32_t frames_seen);

    // Opens the entry of the current frame. boundary_type says what ended the frame, call_name which call did.
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

    // Writes the open frame's block and adds it to the counters.
    void CloseFrame();

    // Fills the "present" part of a swapchain's output. surface_extension and window_size are absent when replay has
    // no window.
    static void SetOutputPresentInfo(nlohmann::ordered_json&           present,
                                     const Decoded_VkPresentInfoKHR*   meta_info,
                                     uint32_t                          swapchain_index,
                                     format::HandleId                  surface_id,
                                     const std::optional<std::string>& surface_extension,
                                     const std::optional<VkExtent2D>&  window_size,
                                     const VkExtent2D&                 swapchain_extent);

    // Adds one finished output entry to the open frame and to the frame counters. image is null for an output that
    // was not read back.
    void AppendOutput(const OutputSource&          source,
                      uint32_t                     layer,
                      const OutputImage*           image,
                      const ScreenshotWriteResult& result);

    static void InsertReason(nlohmann::ordered_json& entry,
                             const std::string&      code,
                             const std::string&      message,
                             std::optional<VkResult> vk_result);

    void WriteBlock(const nlohmann::ordered_json& block);

    // Computes the status of a frame from the number of its outputs in each status. reason_is_error classifies a
    // frame without any outputs
    static ScreenshotFrameStatus
    ComputeFrameStatus(uint32_t written, uint32_t skipped, uint32_t failed, bool reason_is_error);

  private:
    const ScreenshotController& controller_;
    FILE*                       file_{ nullptr };
    bool                        first_block_{ true };
    bool                        frame_open_{ false };
    bool                        frame_reason_is_error_{ false };
    nlohmann::ordered_json      header_;
    nlohmann::ordered_json      frame_;

    // Outputs of the open frame in each status.
    uint32_t outputs_written_{ 0 };
    uint32_t outputs_skipped_{ 0 };
    uint32_t outputs_failed_{ 0 };

    uint32_t frames_requested_{ 0 };
    uint32_t frames_written_{ 0 };
    uint32_t frames_partial_{ 0 };
    uint32_t frames_skipped_{ 0 };
    uint32_t frames_failed_{ 0 };
    uint32_t files_written_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_SCREENSHOT_JSON_H
