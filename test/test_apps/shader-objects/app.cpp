/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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

#include "shader_objects_app.h"

#include <iostream>

#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(shader_objects)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector, vkmock::TestConfig*)
{
    phys_device_selector.add_required_extension("VK_KHR_multiview");
    phys_device_selector.add_required_extension("VK_KHR_maintenance2");
    phys_device_selector.add_required_extension("VK_KHR_create_renderpass2");
    phys_device_selector.add_required_extension("VK_KHR_depth_stencil_resolve");
    phys_device_selector.add_required_extension("VK_KHR_dynamic_rendering");
    phys_device_selector.add_required_extension("VK_EXT_shader_object");
}

void App::configure_device_builder(test::DeviceBuilder&        device_builder,
                                   test::PhysicalDevice const& physical_device,
                                   vkmock::TestConfig*)
{
    dynamic_rendering_features_.sType            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
    dynamic_rendering_features_.pNext            = nullptr;
    dynamic_rendering_features_.dynamicRendering = VK_TRUE;
    device_builder.add_pNext(&dynamic_rendering_features_);

    shader_object_features_.sType        = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT;
    shader_object_features_.pNext        = nullptr;
    shader_object_features_.shaderObject = VK_TRUE;
    device_builder.add_pNext(&shader_object_features_);

    features2_.sType                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2;
    features2_.pNext                       = nullptr;
    features2_.features.tessellationShader = VK_TRUE;
    features2_.features.geometryShader     = VK_TRUE;
    device_builder.add_pNext(&features2_);
}

void App::create_shader_objects()
{
#ifdef __ANDROID__
    auto vert_shader = gfxrecon::test::readFile("shaders/green.vspv", init.android_app);
    auto tesc_shader = gfxrecon::test::readFile("shaders/green.tcspv", init.android_app);
    auto tese_shader = gfxrecon::test::readFile("shaders/green.tespv", init.android_app);
    auto geom_shader = gfxrecon::test::readFile("shaders/green.gspv", init.android_app);
    auto frag_shader = gfxrecon::test::readFile("shaders/green.fspv", init.android_app);
#else
    auto vert_shader = gfxrecon::test::readFile("shaders/green.vspv");
    auto tesc_shader = gfxrecon::test::readFile("shaders/green.tcspv");
    auto tese_shader = gfxrecon::test::readFile("shaders/green.tespv");
    auto geom_shader = gfxrecon::test::readFile("shaders/green.gspv");
    auto frag_shader = gfxrecon::test::readFile("shaders/green.fspv");
#endif

    VkShaderCreateInfoEXT shader_create_infos[5];
    shader_create_infos[0].sType                  = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT;
    shader_create_infos[0].pNext                  = nullptr;
    shader_create_infos[0].flags                  = VK_SHADER_CREATE_LINK_STAGE_BIT_EXT;
    shader_create_infos[0].stage                  = VK_SHADER_STAGE_VERTEX_BIT;
    shader_create_infos[0].nextStage              = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
    shader_create_infos[0].codeType               = VK_SHADER_CODE_TYPE_SPIRV_EXT;
    shader_create_infos[0].codeSize               = vert_shader.size();
    shader_create_infos[0].pCode                  = vert_shader.data();
    shader_create_infos[0].pName                  = "main";
    shader_create_infos[0].setLayoutCount         = 0u;
    shader_create_infos[0].pSetLayouts            = nullptr;
    shader_create_infos[0].pushConstantRangeCount = 0u;
    shader_create_infos[0].pPushConstantRanges    = nullptr;
    shader_create_infos[0].pSpecializationInfo    = nullptr;

    shader_create_infos[1].sType                  = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT;
    shader_create_infos[1].pNext                  = nullptr;
    shader_create_infos[1].flags                  = VK_SHADER_CREATE_LINK_STAGE_BIT_EXT;
    shader_create_infos[1].stage                  = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
    shader_create_infos[1].nextStage              = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
    shader_create_infos[1].codeType               = VK_SHADER_CODE_TYPE_SPIRV_EXT;
    shader_create_infos[1].codeSize               = tesc_shader.size();
    shader_create_infos[1].pCode                  = tesc_shader.data();
    shader_create_infos[1].pName                  = "main";
    shader_create_infos[1].setLayoutCount         = 0u;
    shader_create_infos[1].pSetLayouts            = nullptr;
    shader_create_infos[1].pushConstantRangeCount = 0u;
    shader_create_infos[1].pPushConstantRanges    = nullptr;
    shader_create_infos[1].pSpecializationInfo    = nullptr;

    shader_create_infos[2].sType                  = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT;
    shader_create_infos[2].pNext                  = nullptr;
    shader_create_infos[2].flags                  = VK_SHADER_CREATE_LINK_STAGE_BIT_EXT;
    shader_create_infos[2].stage                  = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
    shader_create_infos[2].nextStage              = VK_SHADER_STAGE_GEOMETRY_BIT;
    shader_create_infos[2].codeType               = VK_SHADER_CODE_TYPE_SPIRV_EXT;
    shader_create_infos[2].codeSize               = tese_shader.size();
    shader_create_infos[2].pCode                  = tese_shader.data();
    shader_create_infos[2].pName                  = "main";
    shader_create_infos[2].setLayoutCount         = 0u;
    shader_create_infos[2].pSetLayouts            = nullptr;
    shader_create_infos[2].pushConstantRangeCount = 0u;
    shader_create_infos[2].pPushConstantRanges    = nullptr;
    shader_create_infos[2].pSpecializationInfo    = nullptr;

    shader_create_infos[3].sType                  = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT;
    shader_create_infos[3].pNext                  = nullptr;
    shader_create_infos[3].flags                  = VK_SHADER_CREATE_LINK_STAGE_BIT_EXT;
    shader_create_infos[3].stage                  = VK_SHADER_STAGE_GEOMETRY_BIT;
    shader_create_infos[3].nextStage              = VK_SHADER_STAGE_FRAGMENT_BIT;
    shader_create_infos[3].codeType               = VK_SHADER_CODE_TYPE_SPIRV_EXT;
    shader_create_infos[3].codeSize               = geom_shader.size();
    shader_create_infos[3].pCode                  = geom_shader.data();
    shader_create_infos[3].pName                  = "main";
    shader_create_infos[3].setLayoutCount         = 0u;
    shader_create_infos[3].pSetLayouts            = nullptr;
    shader_create_infos[3].pushConstantRangeCount = 0u;
    shader_create_infos[3].pPushConstantRanges    = nullptr;
    shader_create_infos[3].pSpecializationInfo    = nullptr;

    shader_create_infos[4].sType                  = VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT;
    shader_create_infos[4].pNext                  = nullptr;
    shader_create_infos[4].flags                  = VK_SHADER_CREATE_LINK_STAGE_BIT_EXT;
    shader_create_infos[4].stage                  = VK_SHADER_STAGE_FRAGMENT_BIT;
    shader_create_infos[4].nextStage              = 0u;
    shader_create_infos[4].codeType               = VK_SHADER_CODE_TYPE_SPIRV_EXT;
    shader_create_infos[4].codeSize               = frag_shader.size();
    shader_create_infos[4].pCode                  = frag_shader.data();
    shader_create_infos[4].pName                  = "main";
    shader_create_infos[4].setLayoutCount         = 0u;
    shader_create_infos[4].pSetLayouts            = nullptr;
    shader_create_infos[4].pushConstantRangeCount = 0u;
    shader_create_infos[4].pPushConstantRanges    = nullptr;
    shader_create_infos[4].pSpecializationInfo    = nullptr;
    init.disp.createShadersEXT(5u, shader_create_infos, nullptr, shaders_);
}

const int NUM_FRAMES = 20;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

bool App::frame(const int frame_num)
{
    init.disp.waitForFences(1, &sync_.in_flight_fences[current_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreate_swapchain(true);
        return IS_RUNNING(frame_num);
    }
    else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
    {
        throw gfxrecon::test::vulkan_exception("failed to acquire next image", result);
    }

    if (sync_.image_in_flight[image_index] != VK_NULL_HANDLE)
    {
        init.disp.waitForFences(1, &sync_.image_in_flight[image_index], VK_TRUE, UINT64_MAX);
    }
    sync_.image_in_flight[image_index] = sync_.in_flight_fences[current_frame_];

    VkCommandBuffer command_buffer = command_buffers_[current_frame_];

    init.disp.resetCommandBuffer(command_buffer, 0u);

    VkCommandBufferBeginInfo command_buffer_begin_info;
    command_buffer_begin_info.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    command_buffer_begin_info.pNext            = nullptr;
    command_buffer_begin_info.flags            = 0u;
    command_buffer_begin_info.pInheritanceInfo = nullptr;
    init.disp.beginCommandBuffer(command_buffer, &command_buffer_begin_info);

    VkImageMemoryBarrier pre_image_memory_barrier;
    pre_image_memory_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    pre_image_memory_barrier.pNext                           = nullptr;
    pre_image_memory_barrier.srcAccessMask                   = VK_ACCESS_NONE;
    pre_image_memory_barrier.dstAccessMask                   = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    pre_image_memory_barrier.oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
    pre_image_memory_barrier.newLayout                       = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    pre_image_memory_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
    pre_image_memory_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
    pre_image_memory_barrier.image                           = init.swapchain_images[image_index];
    pre_image_memory_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    pre_image_memory_barrier.subresourceRange.baseMipLevel   = 0u;
    pre_image_memory_barrier.subresourceRange.levelCount     = 1u;
    pre_image_memory_barrier.subresourceRange.baseArrayLayer = 0u;
    pre_image_memory_barrier.subresourceRange.layerCount     = 1u;
    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                 VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                 0u,
                                 0u,
                                 nullptr,
                                 0u,
                                 nullptr,
                                 1u,
                                 &pre_image_memory_barrier);

    {
        VkViewport viewport;
        viewport.x        = 0.0f;
        viewport.y        = 0.0f;
        viewport.width    = (float)init.swapchain.extent.width;
        viewport.height   = (float)init.swapchain.extent.height;
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        init.disp.cmdSetViewportWithCountEXT(command_buffer, 1u, &viewport);

        VkRect2D scissor;
        scissor.offset.x = 0;
        scissor.offset.y = 0;
        scissor.extent   = init.swapchain.extent;
        init.disp.cmdSetScissorWithCountEXT(command_buffer, 1u, &scissor);

        init.disp.cmdSetTessellationDomainOriginEXT(command_buffer, VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT);
        init.disp.cmdSetPatchControlPointsEXT(command_buffer, 4u);
        init.disp.cmdSetRasterizerDiscardEnableEXT(command_buffer, VK_FALSE);
        init.disp.cmdSetCullModeEXT(command_buffer, VK_CULL_MODE_NONE);
        init.disp.cmdSetDepthTestEnableEXT(command_buffer, VK_FALSE);
        init.disp.cmdSetDepthWriteEnableEXT(command_buffer, VK_FALSE);
        init.disp.cmdSetStencilTestEnableEXT(command_buffer, VK_FALSE);
        init.disp.cmdSetDepthBiasEnableEXT(command_buffer, VK_FALSE);
        init.disp.cmdSetPolygonModeEXT(command_buffer, VK_POLYGON_MODE_FILL);
        init.disp.cmdSetRasterizationSamplesEXT(command_buffer, VK_SAMPLE_COUNT_1_BIT);
        init.disp.cmdSetAlphaToCoverageEnableEXT(command_buffer, VK_FALSE);
        init.disp.cmdSetPrimitiveTopologyEXT(command_buffer, VK_PRIMITIVE_TOPOLOGY_PATCH_LIST);
        init.disp.cmdSetPrimitiveRestartEnableEXT(command_buffer, VK_FALSE);
        init.disp.cmdSetVertexInputEXT(command_buffer, 0u, NULL, 0u, NULL);

        VkSampleMask sampleMask = 0xFFFFFFFF;
        init.disp.cmdSetSampleMaskEXT(command_buffer, VK_SAMPLE_COUNT_1_BIT, &sampleMask);

        VkBool32 colorBlendEnable = VK_FALSE;
        init.disp.cmdSetColorBlendEnableEXT(command_buffer, 0u, 1u, &colorBlendEnable);

        VkColorComponentFlags colorWriteMask =
            VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
        init.disp.cmdSetColorWriteMaskEXT(command_buffer, 0u, 1u, &colorWriteMask);
    }

    VkShaderStageFlagBits stages[5] = {
        VK_SHADER_STAGE_VERTEX_BIT,
        VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT,
        VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT,
        VK_SHADER_STAGE_GEOMETRY_BIT,
        VK_SHADER_STAGE_FRAGMENT_BIT,
    };
    init.disp.cmdBindShadersEXT(command_buffer, 5u, stages, shaders_);

    VkClearValue clear_value;
    clear_value.color.float32[0] = 0.0f;
    clear_value.color.float32[1] = 0.0f;
    clear_value.color.float32[2] = 0.4f;
    clear_value.color.float32[3] = 1.0f;

    VkRenderingAttachmentInfo color_attachment;
    color_attachment.sType              = VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO;
    color_attachment.pNext              = nullptr;
    color_attachment.imageView          = init.swapchain_image_views[image_index];
    color_attachment.imageLayout        = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    color_attachment.resolveMode        = VK_RESOLVE_MODE_NONE;
    color_attachment.resolveImageView   = VK_NULL_HANDLE;
    color_attachment.resolveImageLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    color_attachment.loadOp             = VK_ATTACHMENT_LOAD_OP_CLEAR;
    color_attachment.storeOp            = VK_ATTACHMENT_STORE_OP_STORE;
    color_attachment.clearValue         = clear_value;

    VkRenderingInfo rendering_info;
    rendering_info.sType                = VK_STRUCTURE_TYPE_RENDERING_INFO;
    rendering_info.pNext                = nullptr;
    rendering_info.flags                = 0u;
    rendering_info.renderArea.offset    = { 0, 0 };
    rendering_info.renderArea.extent    = init.swapchain.extent;
    rendering_info.layerCount           = 1u;
    rendering_info.viewMask             = 0x0;
    rendering_info.colorAttachmentCount = 1u;
    rendering_info.pColorAttachments    = &color_attachment;
    rendering_info.pDepthAttachment     = nullptr;
    rendering_info.pStencilAttachment   = nullptr;

    init.disp.cmdBeginRenderingKHR(command_buffer, &rendering_info);
    init.disp.cmdDraw(command_buffer, 4u, 1u, 0u, 0u);
    init.disp.cmdEndRenderingKHR(command_buffer);

    VkImageMemoryBarrier post_image_memory_barrier;
    post_image_memory_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    post_image_memory_barrier.pNext                           = nullptr;
    post_image_memory_barrier.srcAccessMask                   = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    post_image_memory_barrier.dstAccessMask                   = VK_ACCESS_NONE;
    post_image_memory_barrier.oldLayout                       = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    post_image_memory_barrier.newLayout                       = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
    post_image_memory_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
    post_image_memory_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
    post_image_memory_barrier.image                           = init.swapchain_images[image_index];
    post_image_memory_barrier.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    post_image_memory_barrier.subresourceRange.baseMipLevel   = 0u;
    post_image_memory_barrier.subresourceRange.levelCount     = 1u;
    post_image_memory_barrier.subresourceRange.baseArrayLayer = 0u;
    post_image_memory_barrier.subresourceRange.layerCount     = 1u;
    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                 VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                 0u,
                                 0u,
                                 nullptr,
                                 0u,
                                 nullptr,
                                 1u,
                                 &post_image_memory_barrier);

    init.disp.endCommandBuffer(command_buffer);

    VkSubmitInfo submitInfo = {};
    submitInfo.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore          wait_semaphores[] = { sync_.available_semaphores[current_frame_] };
    VkPipelineStageFlags wait_stages[]     = { VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT };
    submitInfo.waitSemaphoreCount          = 1;
    submitInfo.pWaitSemaphores             = wait_semaphores;
    submitInfo.pWaitDstStageMask           = wait_stages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers    = &command_buffer;

    VkSemaphore signal_semaphores[] = { sync_.finished_semaphore[current_frame_] };
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores    = signal_semaphores;

    init.disp.resetFences(1, &sync_.in_flight_fences[current_frame_]);

    result = init.disp.queueSubmit(graphics_queue_, 1, &submitInfo, sync_.in_flight_fences[current_frame_]);
    VERIFY_VK_RESULT("failed to submit queue", result);

    VkPresentInfoKHR present_info = {};
    present_info.sType            = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    present_info.waitSemaphoreCount = 1;
    present_info.pWaitSemaphores    = signal_semaphores;

    VkSwapchainKHR swapChains[] = { init.swapchain };
    present_info.swapchainCount = 1;
    present_info.pSwapchains    = swapChains;

    present_info.pImageIndices = &image_index;

    result = init.disp.queuePresentKHR(present_queue_, &present_info);
    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR)
    {
        recreate_swapchain(true);
        return frame_num >= NUM_FRAMES;
    }
    VERIFY_VK_RESULT("failed to present queue", result);

    current_frame_ = (current_frame_ + 1) % MAX_FRAMES_IN_FLIGHT;

    return IS_RUNNING(frame_num);
}

void App::cleanup()
{
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
    {
        init.disp.destroySemaphore(sync_.finished_semaphore[i], nullptr);
        init.disp.destroySemaphore(sync_.available_semaphores[i], nullptr);
        init.disp.destroyFence(sync_.in_flight_fences[i], nullptr);
    }

    init.disp.destroyCommandPool(command_pool_, nullptr);
    for (uint32_t i = 0; i < 5; ++i)
    {
        init.disp.destroyShaderEXT(shaders_[i], nullptr);
    }
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(gfxrecon::test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto present_queue = init.device.get_queue(gfxrecon::test::QueueType::present);
    if (!present_queue.has_value())
        throw std::runtime_error("could not get present queue");
    present_queue_ = *present_queue;

    create_shader_objects();

    auto queue_family_index = init.device.get_queue_index(gfxrecon::test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");

    sync_ = gfxrecon::test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);

    VkCommandPoolCreateInfo command_pool_create_info;
    command_pool_create_info.sType            = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    command_pool_create_info.pNext            = nullptr;
    command_pool_create_info.flags            = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    command_pool_create_info.queueFamilyIndex = queue_family_index.value();
    init.disp.createCommandPool(&command_pool_create_info, nullptr, &command_pool_);

    VkCommandBufferAllocateInfo command_buffer_allocate_info;
    command_buffer_allocate_info.sType              = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    command_buffer_allocate_info.pNext              = nullptr;
    command_buffer_allocate_info.commandPool        = command_pool_;
    command_buffer_allocate_info.level              = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    command_buffer_allocate_info.commandBufferCount = MAX_FRAMES_IN_FLIGHT;
    init.disp.allocateCommandBuffers(&command_buffer_allocate_info, command_buffers_);
}

GFXRECON_END_NAMESPACE(shader_objects)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
