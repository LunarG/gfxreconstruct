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

#include "decode/screenshot_json.h"

#include "decode/vulkan_pnext_node.h"
#include "generated/generated_vulkan_enum_to_string.h"
#include "generated/generated_vulkan_struct_decoders.h"
#include PROJECT_VERSION_HEADER_FILE
#include "util/logging.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

ScreenshotJson::ScreenshotJson(const VulkanReplayOptions& options)
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
}

ScreenshotJson::~ScreenshotJson()
{
    if (file_ != nullptr)
    {
        // Close without a summary: the owner did not get to a clean shutdown.
        util::platform::FileWrite("\n]", 2, file_);
        util::platform::FileClose(file_);
        file_ = nullptr;
    }
}

bool ScreenshotJson::Open(const std::string& filename)
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

void ScreenshotJson::Close(uint32_t frames_seen)
{
    if (file_ == nullptr)
    {
        return;
    }

    if (frame_open_)
    {
        EndFrame();
    }

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

void ScreenshotJson::BeginFrame(uint32_t                        frame,
                                uint64_t                        block_index,
                                const char*                     boundary_type,
                                const char*                     call,
                                std::optional<format::HandleId> queue_id,
                                std::optional<VkResult>         capture_result)
{
    GFXRECON_ASSERT(!frame_open_);

    if (frame_open_)
    {
        EndFrame();
    }

    frame_.clear();
    frame_open_            = true;
    frame_reason_is_error_ = false;
    current_output_status_.reset();
    outputs_written_ = 0;
    outputs_skipped_ = 0;
    outputs_failed_  = 0;

    frame_["frame"]      = frame;
    frame_["blockIndex"] = block_index;

    auto& boundary   = frame_["boundary"];
    boundary["type"] = boundary_type;
    boundary["call"] = call;
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

void ScreenshotJson::SetReplayResult(VkResult replay_result)
{
    GFXRECON_ASSERT(frame_open_);
    frame_["boundary"]["replayResult"] = util::ToString(replay_result);
}

void ScreenshotJson::SetBoundarySwapchain(uint32_t swapchain_count)
{
    GFXRECON_ASSERT(frame_open_);
    frame_["boundary"]["swapchainCount"] = swapchain_count;
}

void ScreenshotJson::SetBoundaryCommandBuffer(format::HandleId command_buffer_id)
{
    GFXRECON_ASSERT(frame_open_);
    frame_["boundary"]["commandBufferId"] = command_buffer_id;
}

void ScreenshotJson::SetBoundaryFrameBoundaryEXT(const VkFrameBoundaryEXT& info,
                                                 const format::HandleId*   image_ids,
                                                 size_t                    image_count)
{
    GFXRECON_ASSERT(frame_open_);

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

void ScreenshotJson::SetBoundaryFrameBoundaryANDROID(std::optional<format::HandleId> semaphore_id)
{
    GFXRECON_ASSERT(frame_open_);
    if (semaphore_id)
    {
        frame_["boundary"]["semaphoreId"] = semaphore_id.value();
    }
    else
    {
        frame_["boundary"]["semaphoreId"] = nullptr;
    }
}

void ScreenshotJson::SetFrameReason(const std::string& code, const std::string& message, bool is_error)
{
    GFXRECON_ASSERT(frame_open_);
    InsertReason(frame_, code, message, std::nullopt);
    frame_reason_is_error_ = is_error;
}

void ScreenshotJson::AddFrameMessage(const std::string&      code,
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

void ScreenshotJson::EndFrame()
{
    if (!frame_open_)
    {
        return;
    }

    CommitCurrentOutputStatus();

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

void ScreenshotJson::AddOutput(const char* source_kind, format::HandleId image_id, uint32_t layer)
{
    GFXRECON_ASSERT(frame_open_);

    CommitCurrentOutputStatus();

    auto& outputs = frame_["outputs"];
    outputs.push_back(nlohmann::ordered_json::object());

    auto& source   = outputs.back()["source"];
    source["kind"] = source_kind;
    if (image_id != format::kNullHandleId)
    {
        source["imageId"] = image_id;
    }
    else
    {
        source["imageId"] = nullptr;
    }
    source["layer"] = layer;
}

nlohmann::ordered_json& ScreenshotJson::CurrentOutput()
{
    GFXRECON_ASSERT(frame_open_);
    auto& outputs = frame_["outputs"];
    GFXRECON_ASSERT(!outputs.empty());
    return outputs.back();
}

void ScreenshotJson::SetOutputSwapchain(format::HandleId swapchain_id, uint32_t swapchain_index, uint32_t image_index)
{
    auto& source             = CurrentOutput()["source"];
    source["swapchainId"]    = swapchain_id;
    source["swapchainIndex"] = swapchain_index;
    source["imageIndex"]     = image_index;
}

void ScreenshotJson::SetOutputImageIndex(size_t image_index)
{
    CurrentOutput()["source"]["imageIndex"] = image_index;
}

void ScreenshotJson::SetOutputFramebufferAttachment(format::HandleId framebuffer_id,
                                                    size_t           render_pass_index,
                                                    size_t           attachment_index,
                                                    format::HandleId image_view_id)
{
    auto& source              = CurrentOutput()["source"];
    source["framebufferId"]   = framebuffer_id;
    source["renderPassIndex"] = render_pass_index;
    source["attachmentIndex"] = attachment_index;
    source["imageViewId"]     = image_view_id;
}

void ScreenshotJson::SetOutputImage(VkFormat                      format,
                                    uint32_t                      width,
                                    uint32_t                      height,
                                    VkSurfaceTransformFlagBitsKHR pre_transform)
{
    auto& source           = CurrentOutput()["source"];
    source["format"]       = util::ToString(format);
    source["extent"]       = { width, height };
    source["preTransform"] = util::ToString(pre_transform);
}

void ScreenshotJson::SetOutputPresentInfo(const Decoded_VkPresentInfoKHR*   meta_info,
                                          uint32_t                          swapchain_index,
                                          format::HandleId                  surface_id,
                                          const std::optional<std::string>& surface_extension,
                                          const std::optional<VkExtent2D>&  window_size,
                                          const VkExtent2D&                 swapchain_extent)
{
    GFXRECON_ASSERT((meta_info != nullptr) && (meta_info->decoded_value != nullptr));

    const uint32_t   i     = swapchain_index;
    const PNextNode* pnext = meta_info->pNext;

    auto& present = CurrentOutput()["present"];

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

void ScreenshotJson::SetOutputResult(const ScreenshotWriteResult& result)
{
    auto& entry = CurrentOutput();

    if (result.status == ScreenshotStatus::kWritten)
    {
        entry["file"] = result.file;
    }
    else
    {
        entry["file"] = nullptr;
    }

    SetCurrentOutputStatus(result.status);

    if (result.status != ScreenshotStatus::kWritten)
    {
        InsertReason(entry,
                     result.reason_code,
                     result.message,
                     (result.vk_result != VK_SUCCESS) ? std::optional<VkResult>(result.vk_result) : std::nullopt);
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
}

void ScreenshotJson::SetOutputSkipped(const std::string&      code,
                                      const std::string&      message,
                                      bool                    is_error,
                                      std::optional<VkResult> vk_result)
{
    auto& entry   = CurrentOutput();
    entry["file"] = nullptr;
    SetCurrentOutputStatus(is_error ? ScreenshotStatus::kFailed : ScreenshotStatus::kSkipped);
    InsertReason(entry, code, message, vk_result);
}

void ScreenshotJson::SetCurrentOutputStatus(ScreenshotStatus status)
{
    CurrentOutput()["status"] = ScreenshotStatusToString(status);
    current_output_status_    = status;
}

void ScreenshotJson::CommitCurrentOutputStatus()
{
    if (frame_["outputs"].empty())
    {
        return;
    }

    switch (current_output_status_.value_or(ScreenshotStatus::kFailed))
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

    current_output_status_.reset();
}

ScreenshotFrameStatus
ScreenshotJson::ComputeFrameStatus(uint32_t written, uint32_t skipped, uint32_t failed, bool reason_is_error)
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

void ScreenshotJson::InsertReason(nlohmann::ordered_json& entry,
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

void ScreenshotJson::WriteBlock(const nlohmann::ordered_json& block)
{
    GFXRECON_ASSERT(file_ != nullptr);

    if (!first_block_)
    {
        util::platform::FileWrite(",\n", 2, file_);
    }
    first_block_ = false;

    const std::string text = block.dump(util::kJsonIndentWidth);
    util::platform::FileWrite(text.c_str(), text.size(), file_);
    util::platform::FileFlush(file_);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
