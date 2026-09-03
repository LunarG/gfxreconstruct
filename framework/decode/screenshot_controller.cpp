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

#include "decode/screenshot_controller.h"

#include "decode/vulkan_object_info.h"
#include "decode/window.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cstdlib>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

ScreenshotController::ScreenshotController(const ReplayOptions& options, bool write_result_json) :
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

    if (!options.screenshot_dir.empty())
    {
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

    if (write_result_json)
    {
        const std::string json_filename = file_prefix_ + ".json";

        json_ = std::make_unique<ScreenshotJson>(options);
        if (!json_->Open(json_filename))
        {
            GFXRECON_LOG_WARNING("Screenshot results will not be recorded: could not open %s", json_filename.c_str());
            json_.reset();
        }
    }
}

ScreenshotController::~ScreenshotController()
{
    if (json_ != nullptr)
    {
        // The frame counter starts at 1, so the number of frames seen is one less than the current frame.
        json_->Close(current_frame_ - 1);
    }
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

void ScreenshotController::EndFrame(std::optional<VkResult> replay_result)
{
    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        GFXRECON_ASSERT(IsScreenshotFrame());

        if (replay_result)
        {
            json->SetReplayResult(replay_result.value());

            if (replay_result.value() < 0)
            {
                json->AddFrameMessage(
                    screenshot_reason::kReplayCallFailed,
                    "The call that ended the frame failed in replay; the screenshot content may not be valid",
                    replay_result);
            }
        }

        json->EndFrame();
    }

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
    ScreenshotWriteResult result;

    if (image.pixels == nullptr)
    {
        GFXRECON_LOG_ERROR("Screenshot could not be created: the image was not read back");
        result = ScreenshotWriteResult::Failed(screenshot_reason::kReadbackFailed,
                                               "Screenshot could not be created: the image was not read back");
    }
    else
    {
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
                GFXRECON_LOG_WARNING_ONCE(
                    "A screenshot in this format cannot be rotated, thus it is written unrotated.");
                result.messages.push_back({ screenshot_reason::kRotationUnsupported,
                                            "A screenshot in this format cannot be rotated; it is written unrotated" });
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

        std::string filename;
        if (util::imagewriter::WriteScreenshotFile(
                filename_base, format_, width, height, write_from, pitch, image.format, &filename))
        {
            result.status = ScreenshotStatus::kWritten;
            result.file   = filename;
            result.width  = width;
            result.height = height;
        }
        else
        {
            // WriteScreenshotFile has already logged the failure.
            result.status      = ScreenshotStatus::kFailed;
            result.reason_code = screenshot_reason::kFileWriteFailed;
            result.message     = "Screenshot could not be created: failed to write file " + filename;
        }
    }

    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->SetOutputResult(result);
    }

    return result.status == ScreenshotStatus::kWritten;
}

bool ScreenshotController::WriteOutputs(ScreenshotSource&                          source,
                                        const ScreenshotRequest&                   request,
                                        const std::string&                         filename_base,
                                        const std::function<void(uint32_t layer)>& add_output)
{
    uint32_t layers_read    = 0;
    uint32_t layers_written = 0;

    const auto filename_for = [&](uint32_t layer) {
        return (request.layer_count > 1) ? filename_base + "_layer_" + std::to_string(layer) : filename_base;
    };

    const bool zero_size = (request.width == 0) || (request.height == 0);

    // A zero-sized image is nothing to read, and the read-back would only say so again.
    if (!zero_size)
    {
        source.Readback(request, [&](uint32_t layer, const CpuImage& image) {
            add_output(layer);

            if (Finish(filename_for(layer), image, request.rotation))
            {
                ++layers_written;
            }

            ++layers_read;
        });
    }

    // The layers are read in order, thus the ones after the last that arrived were not read.
    for (uint32_t layer = request.base_layer + layers_read; layer < request.base_layer + request.layer_count; ++layer)
    {
        add_output(layer);

        if (zero_size)
        {
            SkipOutput(screenshot_reason::kZeroSizeImage,
                       "Cannot create a screenshot for a 0 size image (width=" + std::to_string(request.width) +
                           ", height=" + std::to_string(request.height) + ")",
                       false);
        }
        else
        {
            SkipOutput(screenshot_reason::kReadbackFailed, "The image could not be read back", true);
        }
    }

    return layers_written == request.layer_count;
}

void ScreenshotController::BeginFrame(const char*             boundary_type,
                                      const char*             call_name,
                                      const VulkanQueueInfo*  queue_info,
                                      std::optional<VkResult> capture_result,
                                      uint64_t                block_index)
{
    if ((json_ == nullptr) || !IsScreenshotFrame())
    {
        return;
    }

    std::optional<format::HandleId> queue_id;
    if (queue_info != nullptr)
    {
        queue_id = queue_info->capture_id;
    }

    json_->BeginFrame(current_frame_, block_index, boundary_type, call_name, queue_id, capture_result);
}

void ScreenshotController::SkipFrame(const char* code, const std::string& message, bool is_error)
{
    if (is_error)
    {
        GFXRECON_LOG_ERROR("Frame %u: no screenshot written (%s): %s", current_frame_, code, message.c_str());
    }
    else
    {
        GFXRECON_LOG_WARNING("Frame %u: no screenshot written (%s): %s", current_frame_, code, message.c_str());
    }

    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->SetFrameReason(code, message, is_error);
    }
}

void ScreenshotController::SetBoundarySwapchain(uint32_t swapchain_count)
{
    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->SetBoundarySwapchain(swapchain_count);
    }
}

void ScreenshotController::SetBoundaryCommandBuffer(format::HandleId command_buffer_id)
{
    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->SetBoundaryCommandBuffer(command_buffer_id);
    }
}

void ScreenshotController::SetBoundaryFrameBoundaryEXT(const Decoded_VkFrameBoundaryEXT* frame_boundary)
{
    ScreenshotJson* json = GetOpenJsonFrame();
    if ((json == nullptr) || (frame_boundary == nullptr) || (frame_boundary->decoded_value == nullptr))
    {
        return;
    }

    json->SetBoundaryFrameBoundaryEXT(
        *frame_boundary->decoded_value, frame_boundary->pImages.GetPointer(), frame_boundary->pImages.GetLength());
}

void ScreenshotController::SetBoundaryFrameBoundaryANDROID(const VulkanSemaphoreInfo* semaphore_info)
{
    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        std::optional<format::HandleId> semaphore_id;
        if (semaphore_info != nullptr)
        {
            semaphore_id = semaphore_info->capture_id;
        }
        json->SetBoundaryFrameBoundaryANDROID(semaphore_id);
    }
}

void ScreenshotController::AddOutput(const char*           source_kind,
                                     format::HandleId      image_id,
                                     uint32_t              layer,
                                     std::optional<size_t> image_index)
{
    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->AddOutput(source_kind, image_id, layer);
        if (image_index)
        {
            json->SetOutputImageIndex(image_index.value());
        }
    }
}

void ScreenshotController::AddFramebufferAttachmentOutput(format::HandleId image_id,
                                                          format::HandleId framebuffer_id,
                                                          size_t           render_pass_index,
                                                          size_t           attachment_index,
                                                          format::HandleId image_view_id)
{
    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->AddOutput("framebufferAttachment", image_id, 0);
        json->SetOutputFramebufferAttachment(framebuffer_id, render_pass_index, attachment_index, image_view_id);
    }
}

void ScreenshotController::AddSwapchainOutput(const char*                     source_kind,
                                              format::HandleId                image_id,
                                              uint32_t                        layer,
                                              const Decoded_VkPresentInfoKHR* meta_info,
                                              uint32_t                        swapchain_index,
                                              format::HandleId                swapchain_id,
                                              uint32_t                        image_index,
                                              const VulkanSwapchainKHRInfo*   swapchain_info,
                                              const VulkanSurfaceKHRInfo*     surface_info)
{
    ScreenshotJson* json = GetOpenJsonFrame();
    if (json == nullptr)
    {
        return;
    }

    json->AddOutput(source_kind, image_id, layer);
    json->SetOutputSwapchain(swapchain_id, swapchain_index, image_index);

    if (swapchain_info != nullptr)
    {
        std::optional<std::string> surface_extension;
        std::optional<VkExtent2D>  window_size;

        if ((surface_info != nullptr) && (surface_info->window != nullptr))
        {
            surface_extension = surface_info->window->GetWsiExtension();
            window_size       = surface_info->window->GetSize();
        }

        json->SetOutputPresentInfo(meta_info,
                                   swapchain_index,
                                   swapchain_info->surface_id,
                                   surface_extension,
                                   window_size,
                                   { swapchain_info->width, swapchain_info->height });
    }
}

void ScreenshotController::SetOutputImage(VkFormat                      format,
                                          uint32_t                      width,
                                          uint32_t                      height,
                                          VkSurfaceTransformFlagBitsKHR pre_transform)
{
    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->SetOutputImage(format, width, height, pre_transform);
    }
}

void ScreenshotController::SkipOutput(const char* code, const std::string& message, bool is_error)
{
    if (is_error)
    {
        GFXRECON_LOG_ERROR(
            "Screenshot for frame %u could not be created (%s): %s", current_frame_, code, message.c_str());
    }
    else
    {
        GFXRECON_LOG_WARNING("Screenshot for frame %u skipped (%s): %s", current_frame_, code, message.c_str());
    }

    if (ScreenshotJson* json = GetOpenJsonFrame())
    {
        json->SetOutputSkipped(code, message, is_error);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
