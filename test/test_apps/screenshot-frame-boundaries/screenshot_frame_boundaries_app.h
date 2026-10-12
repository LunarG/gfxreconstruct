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

#ifndef GFXRECON_TESTAPP_SCREENSHOT_FRAME_BOUNDARIES_APP_H
#define GFXRECON_TESTAPP_SCREENSHOT_FRAME_BOUNDARIES_APP_H

#include <test_app_base.h>

#include <util/defines.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(screenshot_frame_boundaries)

// GFXReconstruct's own frame boundary entry point (framework/format/VK_ANDROID_frame_boundary.h). The capture layer
// serves it from vkGetDeviceProcAddr on every platform, so the app declares it rather than include the framework.
typedef void(VKAPI_PTR* PFN_FrameBoundaryANDROID)(VkDevice device, VkSemaphore semaphore, VkImage image);

/**
 * @brief Renders offscreen and ends each frame with one of the frame boundaries that replay screenshots besides
 *        vkQueuePresentKHR.
 *
 * Each frame records a render pass into colour image 0 and a dynamic rendering into colour image 1, both with a
 * depth attachment, then marks the end of the frame in the way the selected boundary asks for. Replay, run with
 * --screenshots and --screenshot-results, then reads those images back and records what it did in a json file.
 */
class App : public gfxrecon::test::TestAppBase
{
  public:
    enum class Boundary
    {
        // vkCmdInsertDebugUtilsLabelEXT with the VR frame delimiter inside the submitted command buffer.
        kCommandBufferLabel,
        // VkFrameBoundaryEXT in the pNext chain of the submit.
        kFrameBoundaryEXT,
        // vkFrameBoundaryANDROID after the submit.
        kFrameBoundaryANDROID,
    };

    explicit App(Boundary boundary) : boundary_(boundary) {}

  private:
    struct Image
    {
        VkImage        image{ VK_NULL_HANDLE };
        VkDeviceMemory memory{ VK_NULL_HANDLE };
        VkImageView    view{ VK_NULL_HANDLE };
    };

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config) override;
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                            vkmock::TestConfig*           test_config) override;
    void configure_device_builder(test::DeviceBuilder&        device_builder,
                                  test::PhysicalDevice const& physical_device,
                                  vkmock::TestConfig*         test_config) override;
    void setup() override;
    bool frame(const int frame_num) override;
    void cleanup() override;

    Image create_image(VkFormat format, VkImageUsageFlags usage, VkImageAspectFlags aspect);
    void  destroy_image(Image& image);
    void  create_render_pass();
    void  create_framebuffer();
    void  record_rendering(VkCommandBuffer command_buffer);
    void  submit(VkCommandBuffer command_buffer, const void* submit_pnext, bool use_submit2);

    Boundary boundary_;

    VkQueue       graphics_queue_{ VK_NULL_HANDLE };
    VkCommandPool command_pool_{ VK_NULL_HANDLE };
    Image         color_images_[2];
    Image         depth_image_;
    VkRenderPass  render_pass_{ VK_NULL_HANDLE };
    VkFramebuffer framebuffer_{ VK_NULL_HANDLE };
    VkSemaphore   semaphore_{ VK_NULL_HANDLE };

    PFN_FrameBoundaryANDROID frame_boundary_android_{ nullptr };

    // Chained into VkDeviceCreateInfo by the device builder, so they have to outlive its build().
    VkPhysicalDeviceVulkan13Features         vulkan13_features_{};
    VkPhysicalDeviceFrameBoundaryFeaturesEXT frame_boundary_features_{};
};

GFXRECON_END_NAMESPACE(screenshot_frame_boundaries)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_SCREENSHOT_FRAME_BOUNDARIES_APP_H
