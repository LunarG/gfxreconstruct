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

#include "decode/vulkan_screenshot_json.h"

#include "decode/window.h"

#include "decode/vulkan_pnext_node.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include PROJECT_VERSION_HEADER_FILE
#include "util/logging.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanScreenshotJson::VulkanScreenshotJson(const ReplayOptions& options, const ScreenshotController& controller) :
    controller_(controller)
{
    header_["schemaVersion"]   = kSchemaVersion;
    header_["gfxreconVersion"] = GetProjectVersionString();
    header_["vulkanVersion"]   = std::to_string(VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                               std::to_string(VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE)) + "." +
                               std::to_string(VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));
    header_["api"]         = "vulkan";
    header_["captureFile"] = options.capture_filename;

    auto& json_options = header_["options"];

    auto& ranges = json_options["ranges"];
    ranges       = nlohmann::ordered_json::array();
    for (const auto& range : options.screenshot_ranges)
    {
        nlohmann::ordered_json json_range;
        json_range["first"] = range.first;
        json_range["last"]  = range.last;
        ranges.push_back(json_range);
    }

    json_options["interval"] = options.screenshot_interval;
    json_options["format"]   = (options.screenshot_format == util::ScreenshotFormat::kPng) ? util::kScreenshotFormatPng
                                                                                           : util::kScreenshotFormatBmp;
    json_options["dir"]      = options.screenshot_dir;
    json_options["prefix"]   = options.screenshot_file_prefix.empty() ? std::string(kDefaultScreenshotFilePrefix)
                                                                      : options.screenshot_file_prefix;

    if (options.screenshot_scale)
    {
        json_options["scale"] = { options.screenshot_scale.value()[0], options.screenshot_scale.value()[1] };
    }
    else
    {
        json_options["scale"] = nullptr;
    }

    if (options.screenshot_width > 0 && options.screenshot_height > 0)
    {
        json_options["size"]["width"]  = options.screenshot_width;
        json_options["size"]["height"] = options.screenshot_height;
    }
    else
    {
        json_options["size"] = nullptr;
    }

    json_options["applyPrerotation"]           = options.screenshot_apply_prerotation;
    json_options["ignoreFrameBoundaryAndroid"] = options.screenshot_ignore_frameBoundaryAndroid;

    const std::string filename = controller_.FilePrefix() + ".json";
    if (!Open(filename))
    {
        GFXRECON_LOG_WARNING("Screenshot results will not be recorded: could not open %s", filename.c_str());
    }
}

VulkanScreenshotJson::~VulkanScreenshotJson()
{
    // The frame counter starts at 1, so the number of frames seen is one less than the current frame.
    Close(controller_.GetCurrentFrame() - 1);
}

bool VulkanScreenshotJson::Open(const std::string& filename)
{
    GFXRECON_ASSERT(file_ == nullptr);

    int ret = util::platform::FileOpen(&file_, filename.c_str(), "w");
    if (ret || file_ == nullptr)
    {
        file_ = nullptr;
#if defined(_WIN32)
        GFXRECON_LOG_ERROR("Could not open screenshot result json file %s", filename.c_str());
#else
        GFXRECON_LOG_ERROR("Could not open screenshot result json file %s (%s)", filename.c_str(), strerror(ret));
#endif
        return false;
    }

    first_block_ = true;

    util::platform::FileWrite("[\n", 2, file_);

    nlohmann::ordered_json header_block;
    header_block["header"] = header_;
    WriteBlock(header_block);

    return true;
}

void VulkanScreenshotJson::Close(uint32_t frames_seen)
{
    if (file_ == nullptr)
    {
        return;
    }

    CloseFrame();

    nlohmann::ordered_json summary_block;
    auto&                  summary = summary_block["summary"];
    summary["framesSeen"]          = frames_seen;
    summary["framesRequested"]     = frames_requested_;
    summary["framesWritten"]       = frames_written_;
    summary["framesPartial"]       = frames_partial_;
    summary["framesSkipped"]       = frames_skipped_;
    summary["framesFailed"]        = frames_failed_;
    summary["filesWritten"]        = files_written_;
    WriteBlock(summary_block);

    util::platform::FileWrite("\n]", 2, file_);
    util::platform::FileClose(file_);
    file_ = nullptr;
}

void VulkanScreenshotJson::BeginFrame(const char*             boundary_type,
                                      const char*             call_name,
                                      const VulkanQueueInfo*  queue_info,
                                      std::optional<VkResult> capture_result,
                                      uint64_t                block_index)
{
    if ((file_ == nullptr) || !controller_.IsScreenshotFrame())
    {
        return;
    }

    GFXRECON_ASSERT(!frame_open_);
    CloseFrame();

    std::optional<format::HandleId> queue_id;
    if (queue_info != nullptr)
    {
        queue_id = queue_info->capture_id;
    }

    frame_.clear();
    frame_open_            = true;
    frame_reason_is_error_ = false;
    outputs_written_       = 0;
    outputs_skipped_       = 0;
    outputs_failed_        = 0;

    frame_["frame"]      = controller_.GetCurrentFrame();
    frame_["blockIndex"] = block_index;

    auto& boundary   = frame_["boundary"];
    boundary["type"] = boundary_type;
    boundary["call"] = call_name;
    if (queue_id)
    {
        boundary["queueId"] = queue_id.value();
    }
    else
    {
        boundary["queueId"] = nullptr;
    }
    if (capture_result)
    {
        boundary["captureResult"] = util::ToString(capture_result.value());
    }
    else
    {
        boundary["captureResult"] = nullptr;
    }
    boundary["replayResult"] = nullptr;

    frame_["status"]   = ScreenshotFrameStatusToString(ScreenshotFrameStatus::kSkipped);
    frame_["outputs"]  = nlohmann::ordered_json::array();
    frame_["messages"] = nlohmann::ordered_json::array();
}

void VulkanScreenshotJson::EndFrame(std::optional<VkResult> replay_result)
{
    if (!frame_open_)
    {
        return;
    }

    if (replay_result)
    {
        frame_["boundary"]["replayResult"] = util::ToString(replay_result.value());

        if (replay_result.value() < 0)
        {
            AddFrameMessage(screenshot_reason::kReplayCallFailed,
                            "The call that ended the frame failed in replay; the screenshot content may not be valid",
                            replay_result);
        }
    }

    CloseFrame();
}

void VulkanScreenshotJson::SetBoundarySwapchain(uint32_t swapchain_count)
{
    if (!frame_open_)
    {
        return;
    }
    frame_["boundary"]["swapchainCount"] = swapchain_count;
}

void VulkanScreenshotJson::SetBoundaryCommandBuffer(format::HandleId command_buffer_id)
{
    if (!frame_open_)
    {
        return;
    }
    frame_["boundary"]["commandBufferId"] = command_buffer_id;
}

void VulkanScreenshotJson::SetBoundaryFrameBoundaryEXT(const Decoded_VkFrameBoundaryEXT* frame_boundary)
{
    if (!frame_open_ || (frame_boundary == nullptr) || (frame_boundary->decoded_value == nullptr))
    {
        return;
    }

    const VkFrameBoundaryEXT& info        = *frame_boundary->decoded_value;
    const format::HandleId*   image_ids   = frame_boundary->pImages.GetPointer();
    const size_t              image_count = frame_boundary->pImages.GetLength();

    auto& boundary_json = frame_["boundary"]["frameBoundaryEXT"];
    boundary_json["flags"] =
        util::ToString<VkFrameBoundaryFlagBitsEXT>(static_cast<VkFlags>(info.flags), util::kToString_Default, 0, 4);
    boundary_json["frameID"]    = info.frameID;
    boundary_json["imageCount"] = info.imageCount;

    auto& images = boundary_json["images"];
    images       = nlohmann::ordered_json::array();
    for (size_t i = 0; (i < image_count) && (image_ids != nullptr); ++i)
    {
        images.push_back(image_ids[i]);
    }

    boundary_json["bufferCount"] = info.bufferCount;
    boundary_json["tagName"]     = info.tagName;
    boundary_json["tagSize"]     = info.tagSize;
}

void VulkanScreenshotJson::SetBoundaryFrameBoundaryANDROID(const VulkanSemaphoreInfo* semaphore_info)
{
    if (!frame_open_)
    {
        return;
    }
    if (semaphore_info != nullptr)
    {
        frame_["boundary"]["semaphoreId"] = semaphore_info->capture_id;
    }
    else
    {
        frame_["boundary"]["semaphoreId"] = nullptr;
    }
}

void VulkanScreenshotJson::SkipFrame(const char* code, const std::string& message, bool is_error)
{
    const uint32_t frame = controller_.GetCurrentFrame();

    if (is_error)
    {
        GFXRECON_LOG_ERROR("Frame %u: no screenshot written (%s): %s", frame, code, message.c_str());
    }
    else
    {
        GFXRECON_LOG_WARNING("Frame %u: no screenshot written (%s): %s", frame, code, message.c_str());
    }

    if (frame_open_)
    {
        InsertReason(frame_, code, message, std::nullopt);
        frame_reason_is_error_ = is_error;
    }
}

void VulkanScreenshotJson::AddFrameMessage(const std::string&      code,
                                           const std::string&      message,
                                           std::optional<VkResult> vk_result)
{
    GFXRECON_ASSERT(frame_open_);
    nlohmann::ordered_json entry;
    entry["code"]    = code;
    entry["message"] = message;
    if (vk_result)
    {
        entry["vkResult"] = util::ToString(vk_result.value());
    }
    frame_["messages"].push_back(entry);
}

void VulkanScreenshotJson::CloseFrame()
{
    if (!frame_open_)
    {
        return;
    }

    const ScreenshotFrameStatus status =
        ComputeFrameStatus(outputs_written_, outputs_skipped_, outputs_failed_, frame_reason_is_error_);
    frame_["status"] = ScreenshotFrameStatusToString(status);

    if ((outputs_written_ + outputs_skipped_ + outputs_failed_) == 0 && frame_.find("reason") == frame_.end())
    {
        InsertReason(frame_, screenshot_reason::kNoOutputs, "The frame boundary produced no outputs", std::nullopt);
    }

    // Move status and reason next to the boundary block so that the entry reads top-down: what ended the frame, how
    // it went, then the outputs.
    nlohmann::ordered_json ordered;
    for (const char* key : { "frame", "blockIndex", "boundary", "status", "reason" })
    {
        const auto it = frame_.find(key);
        if (it != frame_.end())
        {
            ordered[key] = *it;
        }
    }
    for (auto it = frame_.begin(); it != frame_.end(); ++it)
    {
        if (ordered.find(it.key()) == ordered.end())
        {
            ordered[it.key()] = it.value();
        }
    }

    ++frames_requested_;
    files_written_ += outputs_written_;
    switch (status)
    {
        case ScreenshotFrameStatus::kWritten:
            ++frames_written_;
            break;
        case ScreenshotFrameStatus::kPartial:
            ++frames_partial_;
            break;
        case ScreenshotFrameStatus::kSkipped:
            ++frames_skipped_;
            break;
        case ScreenshotFrameStatus::kFailed:
            ++frames_failed_;
            break;
    }

    WriteBlock(ordered);

    frame_.clear();
    frame_open_ = false;
}

VulkanScreenshotJson::OutputSource VulkanScreenshotJson::ImageSource(const char*           source_kind,
                                                                     format::HandleId      image_id,
                                                                     std::optional<size_t> image_index) const
{
    OutputSource output_source;

    if (!frame_open_)
    {
        return output_source;
    }

    auto& source   = output_source.source;
    source["kind"] = source_kind;
    if (image_id != format::kNullHandleId)
    {
        source["imageId"] = image_id;
    }
    else
    {
        source["imageId"] = nullptr;
    }

    // Each output sets its own layer. The key is added here for its position in the entry.
    source["layer"] = 0;

    if (image_index)
    {
        source["imageIndex"] = image_index.value();
    }

    return output_source;
}

VulkanScreenshotJson::OutputSource
VulkanScreenshotJson::FramebufferAttachmentSource(format::HandleId image_id,
                                                  format::HandleId framebuffer_id,
                                                  size_t           render_pass_index,
                                                  size_t           attachment_index,
                                                  format::HandleId image_view_id) const
{
    OutputSource output_source = ImageSource("framebufferAttachment", image_id);

    if (!frame_open_)
    {
        return output_source;
    }

    auto& source              = output_source.source;
    source["framebufferId"]   = framebuffer_id;
    source["renderPassIndex"] = render_pass_index;
    source["attachmentIndex"] = attachment_index;
    source["imageViewId"]     = image_view_id;

    return output_source;
}

VulkanScreenshotJson::OutputSource VulkanScreenshotJson::SwapchainSource(const char*                     source_kind,
                                                                         format::HandleId                image_id,
                                                                         const Decoded_VkPresentInfoKHR* meta_info,
                                                                         uint32_t                      swapchain_index,
                                                                         format::HandleId              swapchain_id,
                                                                         uint32_t                      image_index,
                                                                         const VulkanSwapchainKHRInfo* swapchain_info,
                                                                         const VulkanSurfaceKHRInfo* surface_info) const
{
    OutputSource output_source = ImageSource(source_kind, image_id);

    if (!frame_open_)
    {
        return output_source;
    }

    auto& source             = output_source.source;
    source["swapchainId"]    = swapchain_id;
    source["swapchainIndex"] = swapchain_index;
    source["imageIndex"]     = image_index;

    if (swapchain_info != nullptr)
    {
        std::optional<std::string> surface_extension;
        std::optional<VkExtent2D>  window_size;

        if ((surface_info != nullptr) && (surface_info->window != nullptr))
        {
            surface_extension = surface_info->window->GetWsiExtension();
            window_size       = surface_info->window->GetSize();
        }

        SetOutputPresentInfo(output_source.present,
                             meta_info,
                             swapchain_index,
                             swapchain_info->surface_id,
                             surface_extension,
                             window_size,
                             { swapchain_info->width, swapchain_info->height });
    }

    return output_source;
}

void VulkanScreenshotJson::SetOutputPresentInfo(nlohmann::ordered_json&           present,
                                                const Decoded_VkPresentInfoKHR*   meta_info,
                                                uint32_t                          swapchain_index,
                                                format::HandleId                  surface_id,
                                                const std::optional<std::string>& surface_extension,
                                                const std::optional<VkExtent2D>&  window_size,
                                                const VkExtent2D&                 swapchain_extent)
{
    GFXRECON_ASSERT((meta_info != nullptr) && (meta_info->decoded_value != nullptr));

    const uint32_t   i     = swapchain_index;
    const PNextNode* pnext = meta_info->pNext;

    present["surfaceId"] = surface_id;

    if (surface_extension)
    {
        present["surfaceExtension"] = surface_extension.value();
    }
    else
    {
        present["surfaceExtension"] = nullptr;
    }

    if (window_size)
    {
        present["replayWindowSize"] = { window_size->width, window_size->height };
    }
    else
    {
        present["replayWindowSize"] = nullptr;
    }

    present["swapchainExtent"] = { swapchain_extent.width, swapchain_extent.height };

    // VkSwapchainPresentModeInfoKHR (also covers the EXT alias).
    present["presentMode"] = nullptr;
    if (const auto* mode_info = GetPNextMetaStruct<Decoded_VkSwapchainPresentModeInfoKHR>(pnext);
        (mode_info != nullptr) && (mode_info->decoded_value != nullptr) &&
        (mode_info->decoded_value->pPresentModes != nullptr) && (i < mode_info->pPresentModes.GetLength()))
    {
        present["presentMode"] = util::ToString(mode_info->pPresentModes.GetPointer()[i]);
    }

    // VkPresentRegionsKHR: damage rectangles for incremental present.
    present["regions"] = nullptr;
    if (const auto* regions_info = GetPNextMetaStruct<Decoded_VkPresentRegionsKHR>(pnext);
        (regions_info != nullptr) && (regions_info->decoded_value != nullptr) &&
        (regions_info->decoded_value->pRegions != nullptr) && (i < regions_info->pRegions->GetLength()))
    {
        const VkPresentRegionKHR& region  = regions_info->pRegions->GetPointer()[i];
        auto&                     regions = present["regions"];
        regions                           = nlohmann::ordered_json::array();
        if (region.pRectangles != nullptr)
        {
            for (uint32_t r = 0; r < region.rectangleCount; ++r)
            {
                const VkRectLayerKHR&  rect = region.pRectangles[r];
                nlohmann::ordered_json rect_json;
                rect_json["offset"] = { rect.offset.x, rect.offset.y };
                rect_json["extent"] = { rect.extent.width, rect.extent.height };
                rect_json["layer"]  = rect.layer;
                regions.push_back(rect_json);
            }
        }
    }

    // VkDisplayPresentInfoKHR: the only present struct that carries real placement rectangles.
    present["displayPresentInfo"] = nullptr;
    if (const auto* display_info = GetPNextMetaStruct<Decoded_VkDisplayPresentInfoKHR>(pnext);
        (display_info != nullptr) && (display_info->decoded_value != nullptr))
    {
        const VkDisplayPresentInfoKHR& info    = *display_info->decoded_value;
        auto&                          display = present["displayPresentInfo"];
        display["srcRect"]["offset"]           = { info.srcRect.offset.x, info.srcRect.offset.y };
        display["srcRect"]["extent"]           = { info.srcRect.extent.width, info.srcRect.extent.height };
        display["dstRect"]["offset"]           = { info.dstRect.offset.x, info.dstRect.offset.y };
        display["dstRect"]["extent"]           = { info.dstRect.extent.width, info.dstRect.extent.height };
        display["persistent"]                  = (info.persistent != VK_FALSE);
    }

    // VkDeviceGroupPresentInfoKHR
    present["deviceMask"]             = nullptr;
    present["deviceGroupPresentMode"] = nullptr;
    if (const auto* group_info = GetPNextMetaStruct<Decoded_VkDeviceGroupPresentInfoKHR>(pnext);
        (group_info != nullptr) && (group_info->decoded_value != nullptr))
    {
        if ((group_info->decoded_value->pDeviceMasks != nullptr) && (i < group_info->pDeviceMasks.GetLength()))
        {
            present["deviceMask"] = group_info->pDeviceMasks.GetPointer()[i];
        }
        present["deviceGroupPresentMode"] = util::ToString(group_info->decoded_value->mode);
    }

    // VkPresentIdKHR / VkPresentId2KHR
    present["presentId"] = nullptr;
    if (const auto* id_info = GetPNextMetaStruct<Decoded_VkPresentIdKHR>(pnext);
        (id_info != nullptr) && (id_info->decoded_value != nullptr) &&
        (id_info->decoded_value->pPresentIds != nullptr) && (i < id_info->pPresentIds.GetLength()))
    {
        present["presentId"] = id_info->pPresentIds.GetPointer()[i];
    }
    else if (const auto* id2_info = GetPNextMetaStruct<Decoded_VkPresentId2KHR>(pnext);
             (id2_info != nullptr) && (id2_info->decoded_value != nullptr) &&
             (id2_info->decoded_value->pPresentIds != nullptr) && (i < id2_info->pPresentIds.GetLength()))
    {
        present["presentId"] = id2_info->pPresentIds.GetPointer()[i];
    }

    // VkPresentTimesInfoGOOGLE
    present["presentTime"] = nullptr;
    if (const auto* times_info = GetPNextMetaStruct<Decoded_VkPresentTimesInfoGOOGLE>(pnext);
        (times_info != nullptr) && (times_info->decoded_value != nullptr) &&
        (times_info->decoded_value->pTimes != nullptr) && (i < times_info->pTimes->GetLength()))
    {
        const VkPresentTimeGOOGLE& time              = times_info->pTimes->GetPointer()[i];
        present["presentTime"]["presentID"]          = time.presentID;
        present["presentTime"]["desiredPresentTime"] = time.desiredPresentTime;
    }

    // VkSwapchainPresentFenceInfoKHR (also covers the EXT alias).
    present["presentFenceId"] = nullptr;
    if (const auto* fence_info = GetPNextMetaStruct<Decoded_VkSwapchainPresentFenceInfoKHR>(pnext);
        (fence_info != nullptr) && (i < fence_info->pFences.GetLength()))
    {
        present["presentFenceId"] = fence_info->pFences.GetPointer()[i];
    }
}

void VulkanScreenshotJson::RecordOutput(const OutputSource&          source,
                                        uint32_t                     layer,
                                        const OutputImage&           image,
                                        const ScreenshotWriteResult& result)
{
    AppendOutput(source, layer, &image, result);
}

void VulkanScreenshotJson::SkipOutput(const OutputSource& source,
                                      const OutputImage*  image,
                                      uint32_t            layer,
                                      const char*         code,
                                      const std::string&  message,
                                      bool                is_error)
{
    const uint32_t frame = controller_.GetCurrentFrame();

    if (is_error)
    {
        GFXRECON_LOG_ERROR("Screenshot for frame %u could not be created (%s): %s", frame, code, message.c_str());
    }

    AppendOutput(source,
                 layer,
                 image,
                 is_error ? ScreenshotWriteResult::Failed(code, message)
                          : ScreenshotWriteResult::Skipped(code, message));
}

void VulkanScreenshotJson::AppendOutput(const OutputSource&          source,
                                        uint32_t                     layer,
                                        const OutputImage*           image,
                                        const ScreenshotWriteResult& result)
{
    if (!frame_open_)
    {
        return;
    }

    nlohmann::ordered_json entry;

    auto& entry_source    = entry["source"];
    entry_source          = source.source;
    entry_source["layer"] = layer;

    if (image != nullptr)
    {
        entry_source["format"]       = util::ToString(image->format);
        entry_source["extent"]       = { image->width, image->height };
        entry_source["preTransform"] = util::ToString(image->pre_transform);
    }

    if (!source.present.is_null())
    {
        entry["present"] = source.present;
    }

    if (result.status == ScreenshotStatus::kWritten)
    {
        entry["file"] = result.file;
    }
    else
    {
        entry["file"] = nullptr;
    }

    entry["status"] = ScreenshotStatusToString(result.status);

    if (result.status != ScreenshotStatus::kWritten)
    {
        InsertReason(entry, result.reason_code, result.message, std::nullopt);
    }
    else
    {
        auto& written     = entry["written"];
        written["width"]  = result.width;
        written["height"] = result.height;
    }

    if (!result.messages.empty())
    {
        auto& messages = entry["messages"];
        messages       = nlohmann::ordered_json::array();
        for (const auto& message : result.messages)
        {
            nlohmann::ordered_json json_message;
            json_message["code"]    = message.code;
            json_message["message"] = message.message;
            messages.push_back(json_message);
        }
    }

    frame_["outputs"].push_back(std::move(entry));

    switch (result.status)
    {
        case ScreenshotStatus::kWritten:
            ++outputs_written_;
            break;
        case ScreenshotStatus::kSkipped:
            ++outputs_skipped_;
            break;
        case ScreenshotStatus::kFailed:
            ++outputs_failed_;
            break;
    }
}

ScreenshotFrameStatus
VulkanScreenshotJson::ComputeFrameStatus(uint32_t written, uint32_t skipped, uint32_t failed, bool reason_is_error)
{
    const uint32_t total = written + skipped + failed;

    if (total == 0)
    {
        return reason_is_error ? ScreenshotFrameStatus::kFailed : ScreenshotFrameStatus::kSkipped;
    }

    if (written == total)
    {
        return ScreenshotFrameStatus::kWritten;
    }

    if (written > 0)
    {
        return ScreenshotFrameStatus::kPartial;
    }

    return (failed > 0) ? ScreenshotFrameStatus::kFailed : ScreenshotFrameStatus::kSkipped;
}

void VulkanScreenshotJson::InsertReason(nlohmann::ordered_json& entry,
                                        const std::string&      code,
                                        const std::string&      message,
                                        std::optional<VkResult> vk_result)
{
    auto& reason      = entry["reason"];
    reason["code"]    = code;
    reason["message"] = message;
    if (vk_result)
    {
        reason["vkResult"] = util::ToString(vk_result.value());
    }
}

void VulkanScreenshotJson::WriteBlock(const nlohmann::ordered_json& block)
{
    GFXRECON_ASSERT(file_ != nullptr);

    if (!first_block_)
    {
        util::platform::FileWrite(",\n", 2, file_);
    }
    first_block_ = false;

    const std::string text = block.dump(util::kJsonIndentWidth, ' ', false, nlohmann::json::error_handler_t::replace);
    util::platform::FileWrite(text.c_str(), text.size(), file_);
    util::platform::FileFlush(file_);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
