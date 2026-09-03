/*
** Copyright (c) 2019-2026 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_SCREENSHOT_HANDLER_H
#define GFXRECON_DECODE_SCREENSHOT_HANDLER_H

#include "decode/screenshot_handler_base.h"
#include "decode/screenshot_json.h"
#include "decode/screenshot_result.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_options.h"
#include "decode/vulkan_resource_allocator.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/vulkan_injected_calls.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <array>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_VkFrameBoundaryEXT;

class ScreenshotHandler : public ScreenshotHandlerBase
{
  public:
    explicit ScreenshotHandler(const VulkanReplayOptions& options, const std::string& json_filename) :
        ScreenshotHandlerBase(options.screenshot_format, options.screenshot_ranges, options.screenshot_interval),
        scale_(options.screenshot_scale), width_(options.screenshot_width), height_(options.screenshot_height)
    {
        OpenResultJson(options, json_filename);
    }

    ~ScreenshotHandler();

    // Copies one image layer to a file. The returned result says whether the file was written and, if not, why.
    ScreenshotWriteResult
    WriteImage(const std::string&                         filename_prefix,
               const VulkanDeviceInfo*                    device_info,
               const graphics::VulkanInjectedDeviceCalls& injected_calls,
               const VkPhysicalDeviceMemoryProperties&    memory_properties,
               VulkanResourceAllocator*                   allocator,
               VkImage                                    image,
               VkFormat                                   format,
               uint32_t                                   width,
               uint32_t                                   height,
               uint32_t                                   layer,
               const std::optional<std::array<float, 2>>& copy_scale,
               VkImageLayout                              image_layout,
               VkSurfaceTransformFlagBitsKHR              pre_transform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR);

    void DestroyDeviceResources(VkDevice device, const graphics::VulkanInjectedDeviceCalls& injected_calls);

    // Creates a new frame entry in the output json
    void BeginFrame(const char*             boundary_type,
                    const char*             call_name,
                    const VulkanQueueInfo*  queue_info,
                    std::optional<VkResult> capture_result,
                    uint64_t                block_index);

    // Records that the whole frame produced no outputs, with a log line and a reason code. Mirrors SkipOutput.
    void SkipFrame(const char* code, const std::string& message, bool is_error);

    void EndFrame(std::optional<VkResult> replay_result);

    // Boundary details of the open frame.
    void SetBoundarySwapchain(uint32_t swapchain_count);
    void SetBoundaryCommandBuffer(format::HandleId command_buffer_id);
    void SetBoundaryFrameBoundaryEXT(const Decoded_VkFrameBoundaryEXT* frame_boundary);
    void SetBoundaryFrameBoundaryANDROID(const VulkanSemaphoreInfo* semaphore_info);

    // Adds an output entry to the open frame, if any, and makes it the current output. image_index records the
    // position of the image in the boundary's image list when there is one.
    void AddOutput(const char*           source_kind,
                   format::HandleId      image_id,
                   uint32_t              layer,
                   std::optional<size_t> image_index = std::nullopt);

    // Adds an output entry for one color attachment of a framebuffer rendered by a frame boundary command buffer.
    void AddFramebufferAttachmentOutput(format::HandleId image_id,
                                        format::HandleId framebuffer_id,
                                        size_t           render_pass_index,
                                        size_t           attachment_index,
                                        format::HandleId image_view_id);

    // Adds an output entry for one swapchain of a present and records the swapchain slot.
    void AddSwapchainOutput(const char*                     source_kind,
                            format::HandleId                image_id,
                            uint32_t                        layer,
                            const Decoded_VkPresentInfoKHR* meta_info,
                            uint32_t                        swapchain_index,
                            format::HandleId                swapchain_id,
                            uint32_t                        image_index,
                            const VulkanSwapchainKHRInfo*   swapchain_info,
                            const VulkanSurfaceKHRInfo*     surface_info);

    // Writes the current output: applies the configured scale or size, copies the image and records the outcome.
    ScreenshotWriteResult WriteOutput(const std::string&                         filename_prefix,
                                      const VulkanDeviceInfo*                    device_info,
                                      const graphics::VulkanInjectedDeviceCalls& injected_calls,
                                      const VkPhysicalDeviceMemoryProperties&    memory_properties,
                                      VkImage                                    image,
                                      VkFormat                                   format,
                                      uint32_t                                   width,
                                      uint32_t                                   height,
                                      uint32_t                                   layer,
                                      VkImageLayout                              image_layout,
                                      VkSurfaceTransformFlagBitsKHR              pre_transform);

    // Records that the current output was not written, with a log line and a reason code.
    void SkipOutput(const char* code, const std::string& message, bool is_error);

  private:
    struct CopyResource
    {
        VkCommandPool                         command_pool{ VK_NULL_HANDLE };
        VulkanResourceAllocator*              allocator{ nullptr };
        VkDeviceSize                          buffer_size{ 0 };
        VkDeviceMemory                        buffer_memory{ VK_NULL_HANDLE };
        VkBuffer                              buffer{ VK_NULL_HANDLE };
        VulkanResourceAllocator::MemoryData   buffer_memory_data{ 0 };
        VulkanResourceAllocator::ResourceData buffer_data{ 0 };
        VkDeviceMemory                        convert_image_memory{ VK_NULL_HANDLE };
        VkImage                               convert_image{ VK_NULL_HANDLE };
        VulkanResourceAllocator::MemoryData   convert_image_memory_data{ 0 };
        VulkanResourceAllocator::ResourceData convert_image_data{ 0 };
        VkFormat                              format{ VK_FORMAT_UNDEFINED };
        uint32_t                              width{ 0 };
        uint32_t                              height{ 0 };
        bool                                  flip_x{ false };
        bool                                  flip_y{ false };
        VkMemoryPropertyFlags                 memory_property_flags{ 0 };
    };

    typedef std::unordered_map<VkDevice, CopyResource> CommandPools;

    std::vector<uint32_t> rotated_pixels_buffer_;

  private:
    bool IsSrgbFormat(VkFormat image_format) const;

    VkFormat GetConversionFormat(VkFormat image_format) const;

    VkDeviceSize GetCopyBufferSize(VkDevice                                          device,
                                   const graphics::VulkanInjectedDeviceCalls::Scope& injected,
                                   VkFormat                                          format,
                                   uint32_t                                          width,
                                   uint32_t                                          height) const;

    VkResult CreateCopyResource(VkDevice                                          device,
                                const graphics::VulkanInjectedDeviceCalls::Scope& injected,
                                const VkPhysicalDeviceMemoryProperties&           memory_properties,
                                VkDeviceSize                                      buffer_size,
                                VkFormat                                          image_format,
                                VkFormat                                          screenshot_format,
                                uint32_t                                          width,
                                uint32_t                                          height,
                                uint32_t                                          copy_width,
                                uint32_t                                          copy_height,
                                bool                                              flip_x,
                                bool                                              flip_y,
                                CopyResource*                                     copy_resource) const;

    void DestroyCopyResource(VkDevice device, CopyResource* copy_resource) const;

    // Initializes the output json file.
    void OpenResultJson(const VulkanReplayOptions& options, const std::string& filename);

    // The output JSON with an entry open for the current frame, or null when the frame is not being recorded.
    ScreenshotJson* GetOpenJsonFrame() { return ((json_ != nullptr) && json_->HasOpenFrame()) ? json_.get() : nullptr; }

  private:
    CommandPools copy_resources_;

    // Optional scale and size applied to every output. The scale takes precedence over the size.
    std::optional<std::array<float, 2>> scale_;
    uint32_t                            width_{ 0 };
    uint32_t                            height_{ 0 };

    std::unique_ptr<ScreenshotJson> json_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_SCREENSHOT_HANDLER_H
