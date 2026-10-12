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

#include <vulkan/vulkan_core.h>

#include "screenshot_frame_boundaries_app.h"

#include <stdexcept>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(screenshot_frame_boundaries)

static const uint32_t kFrameCount  = 3;
static const uint32_t kImageSize   = 64;
static const VkFormat kColorFormat = VK_FORMAT_B8G8R8A8_UNORM;
static const VkFormat kDepthFormat = VK_FORMAT_D32_SFLOAT;

// The label that capture and replay recognise as the end of a frame: graphics::kVulkanVrFrameDelimiterString.
static const char kFrameDelimiterLabel[] = "vr-marker,frame_end,type,application";

/// Moves an image from an undefined layout into new_layout: the content of the previous frame is not needed.
static void image_barrier(vkb::DispatchTable const& disp,
                          VkCommandBuffer           command_buffer,
                          VkImage                   image,
                          VkImageAspectFlags        aspect,
                          VkImageLayout             new_layout,
                          VkAccessFlags             dst_access,
                          VkPipelineStageFlags      dst_stage)
{
    VkImageMemoryBarrier barrier = {};
    barrier.sType                = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barrier.srcAccessMask        = VK_ACCESS_NONE;
    barrier.dstAccessMask        = dst_access;
    barrier.oldLayout            = VK_IMAGE_LAYOUT_UNDEFINED;
    barrier.newLayout            = new_layout;
    barrier.srcQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex  = VK_QUEUE_FAMILY_IGNORED;
    barrier.image                = image;
    barrier.subresourceRange     = { aspect, 0, 1, 0, 1 };

    disp.cmdPipelineBarrier(
        command_buffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, dst_stage, 0, 0, nullptr, 0, nullptr, 1, &barrier);
}

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config != nullptr)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    // Vulkan 1.3 for core dynamic rendering and vkQueueSubmit2. No swapchain: every frame ends with the selected
    // boundary and never with a present.
    instance_builder.require_api_version(VK_MAKE_VERSION(1, 3, 0));
    instance_builder.enable_extension(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
    instance_builder.set_headless(true);

    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                             vkmock::TestConfig*           test_config)
{
    if (boundary_ == Boundary::kFrameBoundaryEXT)
    {
        phys_device_selector.add_required_extension(VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME);
    }
}

void App::configure_device_builder(test::DeviceBuilder&        device_builder,
                                   test::PhysicalDevice const& physical_device,
                                   vkmock::TestConfig*         test_config)
{
    vulkan13_features_.sType            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES;
    vulkan13_features_.pNext            = nullptr;
    vulkan13_features_.dynamicRendering = VK_TRUE;
    vulkan13_features_.synchronization2 = VK_TRUE;
    device_builder.add_pNext(&vulkan13_features_);

    if (boundary_ == Boundary::kFrameBoundaryEXT)
    {
        frame_boundary_features_.sType         = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT;
        frame_boundary_features_.pNext         = nullptr;
        frame_boundary_features_.frameBoundary = VK_TRUE;
        device_builder.add_pNext(&frame_boundary_features_);
    }
}

App::Image App::create_image(VkFormat format, VkImageUsageFlags usage, VkImageAspectFlags aspect)
{
    Image image;

    VkImageCreateInfo image_info = {};
    image_info.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_info.imageType         = VK_IMAGE_TYPE_2D;
    image_info.format            = format;
    image_info.extent            = { kImageSize, kImageSize, 1 };
    image_info.mipLevels         = 1;
    image_info.arrayLayers       = 1;
    image_info.samples           = VK_SAMPLE_COUNT_1_BIT;
    // Optimal tiling: the readback of a linear image needs the row pitch, which the mock ICD does not report.
    image_info.tiling        = VK_IMAGE_TILING_OPTIMAL;
    image_info.usage         = usage;
    image_info.sharingMode   = VK_SHARING_MODE_EXCLUSIVE;
    image_info.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;

    auto result = init.disp.createImage(&image_info, nullptr, &image.image);
    VERIFY_VK_RESULT("failed to create image", result);

    VkMemoryRequirements requirements;
    init.disp.getImageMemoryRequirements(image.image, &requirements);

    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = requirements.size;
    allocate_info.memoryTypeIndex = find_memory_type(requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

    result = init.disp.allocateMemory(&allocate_info, nullptr, &image.memory);
    VERIFY_VK_RESULT("failed to allocate image memory", result);

    result = init.disp.bindImageMemory(image.image, image.memory, 0);
    VERIFY_VK_RESULT("failed to bind image memory", result);

    VkImageViewCreateInfo view_info = {};
    view_info.sType                 = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    view_info.image                 = image.image;
    view_info.viewType              = VK_IMAGE_VIEW_TYPE_2D;
    view_info.format                = format;
    view_info.subresourceRange      = { aspect, 0, 1, 0, 1 };

    result = init.disp.createImageView(&view_info, nullptr, &image.view);
    VERIFY_VK_RESULT("failed to create image view", result);

    return image;
}

void App::destroy_image(Image& image)
{
    init.disp.destroyImageView(image.view, nullptr);
    init.disp.destroyImage(image.image, nullptr);
    init.disp.freeMemory(image.memory, nullptr);
    image = {};
}

void App::create_render_pass()
{
    VkAttachmentDescription attachments[2] = {};

    // The colour attachment is cleared and stored, and stays in the layout the frame's barrier put it in.
    attachments[0].format         = kColorFormat;
    attachments[0].samples        = VK_SAMPLE_COUNT_1_BIT;
    attachments[0].loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[0].storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    attachments[0].stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachments[0].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[0].initialLayout  = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    attachments[0].finalLayout    = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    // The depth attachment has no colour attachment usage, so replay records it as skipped rather than written.
    attachments[1].format         = kDepthFormat;
    attachments[1].samples        = VK_SAMPLE_COUNT_1_BIT;
    attachments[1].loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[1].storeOp        = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[1].stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachments[1].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[1].initialLayout  = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    attachments[1].finalLayout    = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkAttachmentReference color_reference = { 0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL };
    VkAttachmentReference depth_reference = { 1, VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL };

    VkSubpassDescription subpass    = {};
    subpass.pipelineBindPoint       = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount    = 1;
    subpass.pColorAttachments       = &color_reference;
    subpass.pDepthStencilAttachment = &depth_reference;

    VkRenderPassCreateInfo render_pass_info = {};
    render_pass_info.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_info.attachmentCount        = 2;
    render_pass_info.pAttachments           = attachments;
    render_pass_info.subpassCount           = 1;
    render_pass_info.pSubpasses             = &subpass;

    auto result = init.disp.createRenderPass(&render_pass_info, nullptr, &render_pass_);
    VERIFY_VK_RESULT("failed to create render pass", result);
}

void App::create_framebuffer()
{
    VkImageView attachments[] = { color_images_[0].view, depth_image_.view };

    VkFramebufferCreateInfo framebuffer_info = {};
    framebuffer_info.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebuffer_info.renderPass              = render_pass_;
    framebuffer_info.attachmentCount         = 2;
    framebuffer_info.pAttachments            = attachments;
    framebuffer_info.width                   = kImageSize;
    framebuffer_info.height                  = kImageSize;
    framebuffer_info.layers                  = 1;

    auto result = init.disp.createFramebuffer(&framebuffer_info, nullptr, &framebuffer_);
    VERIFY_VK_RESULT("failed to create framebuffer", result);
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    command_pool_ = test::create_command_pool(init.disp, *queue_family_index);

    // Replay copies the colour images out, which asks for transfer source usage: screenshots do not add it.
    for (auto& image : color_images_)
    {
        image = create_image(kColorFormat,
                             VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT,
                             VK_IMAGE_ASPECT_COLOR_BIT);
    }
    depth_image_ = create_image(kDepthFormat, VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT, VK_IMAGE_ASPECT_DEPTH_BIT);

    create_render_pass();
    create_framebuffer();

    if (boundary_ == Boundary::kFrameBoundaryANDROID)
    {
        VkSemaphoreCreateInfo semaphore_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO, nullptr, 0 };
        auto                  result         = init.disp.createSemaphore(&semaphore_info, nullptr, &semaphore_);
        VERIFY_VK_RESULT("failed to create semaphore", result);

        // Only the capture layer implements vkFrameBoundaryANDROID. It is not an exported symbol, and the instance
        // level query does not know it, so the device level query is the one way to reach it.
        frame_boundary_android_ = reinterpret_cast<PFN_FrameBoundaryANDROID>(
            init.device.fp_vkGetDeviceProcAddr(init.device, "vkFrameBoundaryANDROID"));
        VERIFY_CONDITION("vkFrameBoundaryANDROID is not available: is the GFXReconstruct capture layer enabled?",
                         frame_boundary_android_ != nullptr);
    }
}

void App::record_rendering(VkCommandBuffer command_buffer)
{
    for (const auto& image : color_images_)
    {
        image_barrier(init.disp,
                      command_buffer,
                      image.image,
                      VK_IMAGE_ASPECT_COLOR_BIT,
                      VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
                      VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT,
                      VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT);
    }
    image_barrier(init.disp,
                  command_buffer,
                  depth_image_.image,
                  VK_IMAGE_ASPECT_DEPTH_BIT,
                  VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL,
                  VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT,
                  VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT);

    VkClearValue clear_values[2] = {};
    clear_values[0].color        = { { 1.0f, 0.0f, 0.0f, 1.0f } };
    clear_values[1].depthStencil = { 1.0f, 0 };
    const VkRect2D render_area   = { { 0, 0 }, { kImageSize, kImageSize } };

    // A render pass into colour image 0, with the depth image.
    VkRenderPassBeginInfo render_pass_info = {};
    render_pass_info.sType                 = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    render_pass_info.renderPass            = render_pass_;
    render_pass_info.framebuffer           = framebuffer_;
    render_pass_info.renderArea            = render_area;
    render_pass_info.clearValueCount       = 2;
    render_pass_info.pClearValues          = clear_values;

    init.disp.cmdBeginRenderPass(command_buffer, &render_pass_info, VK_SUBPASS_CONTENTS_INLINE);
    init.disp.cmdEndRenderPass(command_buffer);

    // A dynamic rendering into colour image 1, with the same depth image.
    VkRenderingAttachmentInfo color_attachment = {};
    color_attachment.sType                     = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
    color_attachment.imageView                 = color_images_[1].view;
    color_attachment.imageLayout               = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    color_attachment.resolveMode               = VK_RESOLVE_MODE_NONE;
    color_attachment.loadOp                    = VK_ATTACHMENT_LOAD_OP_CLEAR;
    color_attachment.storeOp                   = VK_ATTACHMENT_STORE_OP_STORE;
    color_attachment.clearValue                = clear_values[0];

    VkRenderingAttachmentInfo depth_attachment = {};
    depth_attachment.sType                     = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
    depth_attachment.imageView                 = depth_image_.view;
    depth_attachment.imageLayout               = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    depth_attachment.resolveMode               = VK_RESOLVE_MODE_NONE;
    depth_attachment.loadOp                    = VK_ATTACHMENT_LOAD_OP_CLEAR;
    depth_attachment.storeOp                   = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    depth_attachment.clearValue                = clear_values[1];

    VkRenderingInfo rendering_info      = {};
    rendering_info.sType                = VK_STRUCTURE_TYPE_RENDERING_INFO;
    rendering_info.renderArea           = render_area;
    rendering_info.layerCount           = 1;
    rendering_info.colorAttachmentCount = 1;
    rendering_info.pColorAttachments    = &color_attachment;
    rendering_info.pDepthAttachment     = &depth_attachment;

    init.disp.cmdBeginRendering(command_buffer, &rendering_info);
    init.disp.cmdEndRendering(command_buffer);
}

void App::submit(VkCommandBuffer command_buffer, const void* submit_pnext, bool use_submit2)
{
    VkResult result;

    if (use_submit2)
    {
        VkCommandBufferSubmitInfo command_buffer_info = {};
        command_buffer_info.sType                     = VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO;
        command_buffer_info.commandBuffer             = command_buffer;

        VkSubmitInfo2 submit_info          = {};
        submit_info.sType                  = VK_STRUCTURE_TYPE_SUBMIT_INFO_2;
        submit_info.pNext                  = submit_pnext;
        submit_info.commandBufferInfoCount = 1;
        submit_info.pCommandBufferInfos    = &command_buffer_info;

        result = init.disp.queueSubmit2(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE);
    }
    else
    {
        VkSubmitInfo submit_info       = {};
        submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        submit_info.pNext              = submit_pnext;
        submit_info.commandBufferCount = 1;
        submit_info.pCommandBuffers    = &command_buffer;

        result = init.disp.queueSubmit(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE);
    }
    VERIFY_VK_RESULT("failed to submit queue", result);

    result = init.disp.queueWaitIdle(graphics_queue_);
    VERIFY_VK_RESULT("failed to wait for the queue", result);
}

bool App::frame(const int frame_num)
{
    auto result = init.disp.resetCommandPool(command_pool_, 0);
    VERIFY_VK_RESULT("failed to reset command pool", result);

    VkCommandBufferAllocateInfo allocate_info = {
        VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO, nullptr, command_pool_, VK_COMMAND_BUFFER_LEVEL_PRIMARY, 1
    };
    VkCommandBuffer command_buffer;
    result = init.disp.allocateCommandBuffers(&allocate_info, &command_buffer);
    VERIFY_VK_RESULT("failed to allocate command buffer", result);

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO, nullptr, 0, nullptr };
    result                              = init.disp.beginCommandBuffer(command_buffer, &begin_info);
    VERIFY_VK_RESULT("failed to begin command buffer", result);

    record_rendering(command_buffer);

    if (boundary_ == Boundary::kCommandBufferLabel)
    {
        // The label makes the submitted command buffer the frame boundary. Replay then screenshots every
        // attachment the command buffer rendered to.
        VkDebugUtilsLabelEXT label = {
            VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT, nullptr, kFrameDelimiterLabel, { 0.0f, 0.0f, 0.0f, 1.0f }
        };
        init.disp.cmdInsertDebugUtilsLabelEXT(command_buffer, &label);
    }

    result = init.disp.endCommandBuffer(command_buffer);
    VERIFY_VK_RESULT("failed to end command buffer", result);

    const uint32_t frame = static_cast<uint32_t>(frame_num);

    switch (boundary_)
    {
        case Boundary::kCommandBufferLabel:
            submit(command_buffer, nullptr, false);
            break;

        case Boundary::kFrameBoundaryEXT:
        {
            // Frame 0 names one image on vkQueueSubmit, frame 1 both images on vkQueueSubmit2, frame 2 no image.
            const VkImage images[] = { color_images_[0].image, color_images_[1].image };

            VkFrameBoundaryEXT frame_boundary = {};
            frame_boundary.sType              = VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT;
            frame_boundary.flags              = VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT;
            frame_boundary.frameID            = frame;
            frame_boundary.imageCount         = (frame == 0) ? 1 : (frame == 1) ? 2 : 0;
            frame_boundary.pImages            = (frame_boundary.imageCount > 0) ? images : nullptr;

            submit(command_buffer, &frame_boundary, frame == 1);
            break;
        }

        case Boundary::kFrameBoundaryANDROID:
        {
            submit(command_buffer, nullptr, false);

            // Frame 0 names a semaphore and an image, frame 1 neither, frame 2 an image only.
            const VkSemaphore semaphore = (frame == 0) ? semaphore_ : VK_NULL_HANDLE;
            const VkImage     image     = (frame == 0)   ? color_images_[0].image
                                          : (frame == 2) ? color_images_[1].image
                                                         : VK_NULL_HANDLE;
            frame_boundary_android_(init.device, semaphore, image);
            break;
        }
    }

    return (frame + 1) < kFrameCount;
}

void App::cleanup()
{
    if (semaphore_ != VK_NULL_HANDLE)
    {
        init.disp.destroySemaphore(semaphore_, nullptr);
    }
    init.disp.destroyFramebuffer(framebuffer_, nullptr);
    init.disp.destroyRenderPass(render_pass_, nullptr);
    for (auto& image : color_images_)
    {
        destroy_image(image);
    }
    destroy_image(depth_image_);
    init.disp.destroyCommandPool(command_pool_, nullptr);
}

GFXRECON_END_NAMESPACE(screenshot_frame_boundaries)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
