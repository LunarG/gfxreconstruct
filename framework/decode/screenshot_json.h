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

#ifndef GFXRECON_DECODE_SCREENSHOT_JSON_H
#define GFXRECON_DECODE_SCREENSHOT_JSON_H

#include "decode/screenshot_result.h"
#include "decode/vulkan_replay_options.h"
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

struct Decoded_VkPresentInfoKHR;

class ScreenshotJson
{
  public:
    static constexpr uint32_t kSchemaVersion = 1;

    explicit ScreenshotJson(const VulkanReplayOptions& options);
    ~ScreenshotJson();

    bool Open(const std::string& filename);
    void Close(uint32_t frames_seen);
    bool HasOpenFrame() const { return frame_open_; }

    void BeginFrame(uint32_t                        frame,
                    uint64_t                        block_index,
                    const char*                     boundary_type,
                    const char*                     call,
                    std::optional<format::HandleId> queue_id,
                    std::optional<VkResult>         capture_result);

    void EndFrame();

    void SetReplayResult(VkResult replay_result);

    void SetBoundarySwapchain(uint32_t swapchain_count);
    void SetBoundaryCommandBuffer(format::HandleId command_buffer_id);
    void
    SetBoundaryFrameBoundaryEXT(const VkFrameBoundaryEXT& info, const format::HandleId* image_ids, size_t image_count);
    void SetBoundaryFrameBoundaryANDROID(std::optional<format::HandleId> semaphore_id);

    // Records why the frame produced no outputs at all.
    void SetFrameReason(const std::string& code, const std::string& message, bool is_error);

    // Appends a non-blocking message to the open frame.
    void AddFrameMessage(const std::string& code, const std::string& message, std::optional<VkResult> vk_result);

    // Appends an output entry to the open frame and makes it the current output
    void AddOutput(const char* source_kind, format::HandleId image_id, uint32_t layer);

    // Source details of the current output. Each applies to one source kind.
    void SetOutputSwapchain(format::HandleId swapchain_id, uint32_t swapchain_index, uint32_t image_index);
    void SetOutputImageIndex(size_t image_index);
    void SetOutputFramebufferAttachment(format::HandleId framebuffer_id,
                                        size_t           render_pass_index,
                                        size_t           attachment_index,
                                        format::HandleId image_view_id);

    void SetOutputImage(VkFormat format, uint32_t width, uint32_t height, VkSurfaceTransformFlagBitsKHR pre_transform);

    // Everything from VkPresentInfoKHR and its pNext chain that applies to the swapchain at swapchain_index, plus
    // what replay knows about the surface. surface_extension and window_size are absent when replay has no window.
    void SetOutputPresentInfo(const Decoded_VkPresentInfoKHR*   meta_info,
                              uint32_t                          swapchain_index,
                              format::HandleId                  surface_id,
                              const std::optional<std::string>& surface_extension,
                              const std::optional<VkExtent2D>&  window_size,
                              const VkExtent2D&                 swapchain_extent);

    // Outcome of the current output: either the result of a write attempt, or a skip decided before any write.
    void SetOutputResult(const ScreenshotWriteResult& result);
    void SetOutputSkipped(const std::string&      code,
                          const std::string&      message,
                          bool                    is_error,
                          std::optional<VkResult> vk_result = std::nullopt);

  private:
    // The output most recently added to the open frame.
    nlohmann::ordered_json& CurrentOutput();

    // Records the status of the current output in the JSON and remembers it for the frame counters.
    void SetCurrentOutputStatus(ScreenshotStatus status);

    // Adds the status of the current output, if any, to the frame counters.
    void CommitCurrentOutputStatus();

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
    FILE*                  file_{ nullptr };
    bool                   first_block_{ true };
    bool                   frame_open_{ false };
    bool                   frame_reason_is_error_{ false };
    nlohmann::ordered_json header_;
    nlohmann::ordered_json frame_;

    // Status of the output most recently added to the open frame, counted when the next output is added or the frame
    // ends. An output that never receives a status counts as failed.
    std::optional<ScreenshotStatus> current_output_status_;

    // Outputs of the open frame by status.
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

#endif // GFXRECON_DECODE_SCREENSHOT_JSON_H
