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

#ifndef GFXRECON_DECODE_SCREENSHOT_RESULT_H
#define GFXRECON_DECODE_SCREENSHOT_RESULT_H

#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cstdint>
#include <string>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// Outcome of one screenshot output (a single image file).
enum class ScreenshotStatus
{
    kWritten,
    kSkipped,
    kFailed
};

// Outcome of a whole screenshot frame, derived from the statuses of its outputs.
enum class ScreenshotFrameStatus
{
    kWritten,
    kPartial,
    kSkipped,
    kFailed
};

// Reason codes shared by the frame-level reason and the per-output reason of the screenshot result JSON.
namespace screenshot_reason
{
// Non-error reasons
constexpr char kFrameBoundaryNoImages[]       = "FRAME_BOUNDARY_NO_IMAGES";
constexpr char kFrameBoundaryAndroidNoImage[] = "FRAME_BOUNDARY_ANDROID_NO_IMAGE";
constexpr char kNotColorAttachment[]          = "NOT_COLOR_ATTACHMENT";
constexpr char kNoFramebuffers[]              = "NO_FRAMEBUFFERS";
constexpr char kSwapchainNoImages[]           = "SWAPCHAIN_NO_IMAGES";
constexpr char kZeroSizeImage[]               = "ZERO_SIZE_IMAGE";
constexpr char kNoOutputs[]                   = "NO_OUTPUTS";

// Errors
constexpr char kImageIndexOutOfRange[]         = "IMAGE_INDEX_OUT_OF_RANGE";
constexpr char kUnknownImage[]                 = "UNKNOWN_IMAGE";
constexpr char kUnknownSwapchain[]             = "UNKNOWN_SWAPCHAIN";
constexpr char kUnsupportedFormat[]            = "UNSUPPORTED_FORMAT";
constexpr char kDeviceWaitIdleFailed[]         = "DEVICE_WAIT_IDLE_FAILED";
constexpr char kQueueSubmitFailed[]            = "QUEUE_SUBMIT_FAILED";
constexpr char kMemoryMapFailed[]              = "MEMORY_MAP_FAILED";
constexpr char kFileWriteFailed[]              = "FILE_WRITE_FAILED";
constexpr char kReplayCallFailed[]             = "REPLAY_CALL_FAILED";
constexpr char kMissingDeviceTable[]           = "MISSING_DEVICE_TABLE";
constexpr char kCommandPoolCreateFailed[]      = "COMMAND_POOL_CREATE_FAILED";
constexpr char kCommandBufferAllocateFailed[]  = "COMMAND_BUFFER_ALLOCATE_FAILED";
constexpr char kTransferResourceCreateFailed[] = "TRANSFER_RESOURCE_CREATE_FAILED";

// Non-blocking messages. The output is still written.
constexpr char kFormatFallback[]      = "FORMAT_FALLBACK";
constexpr char kRotationAllocFailed[] = "ROTATION_ALLOC_FAILED";
} // namespace screenshot_reason

struct ScreenshotMessage
{
    std::string code;
    std::string message;
};

// Result of a single screenshot write. Every early return of ScreenshotHandler::WriteImage maps to one reason code.
struct ScreenshotWriteResult
{
    ScreenshotStatus status{ ScreenshotStatus::kFailed };
    std::string      reason_code; // One of the screenshot_reason constants. Empty when the file was written.
    std::string      message;     // The text that went to the log.
    VkResult         vk_result{ VK_SUCCESS }; // Set when a Vulkan call produced the failure.
    std::string      file;                    // Path of the file that was written. Empty otherwise.
    uint32_t         width{ 0 };              // Dimensions of the written image.
    uint32_t         height{ 0 };
    std::vector<ScreenshotMessage> messages; // Non-blocking warnings raised while writing.

    static ScreenshotWriteResult
    Failed(const std::string& code, const std::string& message, VkResult vk_result = VK_SUCCESS)
    {
        ScreenshotWriteResult result;
        result.status      = ScreenshotStatus::kFailed;
        result.reason_code = code;
        result.message     = message;
        result.vk_result   = vk_result;
        return result;
    }

    static ScreenshotWriteResult Skipped(const std::string& code, const std::string& message)
    {
        ScreenshotWriteResult result;
        result.status      = ScreenshotStatus::kSkipped;
        result.reason_code = code;
        result.message     = message;
        return result;
    }
};

inline const char* ScreenshotStatusToString(ScreenshotStatus status)
{
    switch (status)
    {
        case ScreenshotStatus::kWritten:
            return "written";
        case ScreenshotStatus::kSkipped:
            return "skipped";
        case ScreenshotStatus::kFailed:
        default:
            return "failed";
    }
}

inline const char* ScreenshotFrameStatusToString(ScreenshotFrameStatus status)
{
    switch (status)
    {
        case ScreenshotFrameStatus::kWritten:
            return "written";
        case ScreenshotFrameStatus::kPartial:
            return "partial";
        case ScreenshotFrameStatus::kSkipped:
            return "skipped";
        case ScreenshotFrameStatus::kFailed:
        default:
            return "failed";
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SCREENSHOT_RESULT_H
