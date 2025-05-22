/*
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

#include "multisample_depth_app.h"

#define VMA_IMPLEMENTATION
#include <vk_mem_alloc.h>

#include <iostream>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(multisample_depth)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

void App::configure_swapchain_builder(gfxrecon::test::SwapchainBuilder& swapchain_builder, vkmock::TestConfig*)
{
    swapchain_builder.add_image_usage_flags(VK_IMAGE_USAGE_TRANSFER_DST_BIT);
}

void App::create_allocator()
{
    VmaVulkanFunctions vulkan_functions    = {};
    vulkan_functions.vkGetInstanceProcAddr = init.inst_disp.fp_vkGetInstanceProcAddr;
    vulkan_functions.vkGetDeviceProcAddr   = init.disp.fp_vkGetDeviceProcAddr;

    VmaAllocatorCreateInfo allocator_create_info = {};
    allocator_create_info.physicalDevice         = init.physical_device;
    allocator_create_info.device                 = init.device;
    allocator_create_info.instance               = init.instance;
    allocator_create_info.pVulkanFunctions       = &vulkan_functions;
    vmaCreateAllocator(&allocator_create_info, &allocator_);
}

void App::create_render_targets()
{
    render_targets_.resize(init.swapchain_image_views.size());
    render_target_allocations_.resize(init.swapchain_image_views.size());
    render_target_views_.resize(init.swapchain_image_views.size());

    for (size_t i = 0; i < init.swapchain_image_views.size(); i++)
    {
        VkExtent3D extent = {};
        VkResult   result;

        VkImageCreateInfo image_create_info = {};
        image_create_info.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        image_create_info.imageType         = VK_IMAGE_TYPE_2D;
        image_create_info.format            = init.swapchain.image_format;
        image_create_info.extent.height     = init.swapchain.extent.height;
        image_create_info.extent.width      = init.swapchain.extent.width;
        image_create_info.extent.depth      = 1;
        image_create_info.mipLevels         = 1;
        image_create_info.arrayLayers       = 1;
        image_create_info.samples           = VK_SAMPLE_COUNT_2_BIT;
        image_create_info.usage             = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;

        VmaAllocationCreateInfo allocation_info = {};
        allocation_info.usage                   = VMA_MEMORY_USAGE_AUTO;

        result = vmaCreateImage(allocator_,
                                &image_create_info,
                                &allocation_info,
                                &render_targets_[i],
                                &render_target_allocations_[i],
                                nullptr);
        VERIFY_VK_RESULT("failed to create render target", result);

        VkImageViewCreateInfo image_view_create_info       = {};
        image_view_create_info.sType                       = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        image_view_create_info.image                       = render_targets_[i];
        image_view_create_info.viewType                    = VK_IMAGE_VIEW_TYPE_2D;
        image_view_create_info.format                      = image_create_info.format;
        image_view_create_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        image_view_create_info.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
        image_view_create_info.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
        result = init.disp.createImageView(&image_view_create_info, nullptr, &render_target_views_[i]);
        VERIFY_VK_RESULT("failed to create render target view", result);
    }
}

void App::create_depth_buffers()
{
    depth_images_.resize(init.swapchain_image_views.size());
    depth_image_allocations_.resize(init.swapchain_image_views.size());
    depth_image_views_.resize(init.swapchain_image_views.size());

    for (size_t i = 0; i < init.swapchain_image_views.size(); i++)
    {
        VkExtent3D extent = {};
        VkResult   result;

        VkImageCreateInfo image_create_info = {};
        image_create_info.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        image_create_info.imageType         = VK_IMAGE_TYPE_2D;
        image_create_info.format            = VK_FORMAT_D16_UNORM;
        image_create_info.extent.height     = init.swapchain.extent.height;
        image_create_info.extent.width      = init.swapchain.extent.width;
        image_create_info.extent.depth      = 1;
        image_create_info.mipLevels         = 1;
        image_create_info.arrayLayers       = 1;
        image_create_info.samples           = VK_SAMPLE_COUNT_2_BIT;
        image_create_info.usage             = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;

        VmaAllocationCreateInfo allocation_info = {};
        allocation_info.usage                   = VMA_MEMORY_USAGE_AUTO;

        result = vmaCreateImage(
            allocator_, &image_create_info, &allocation_info, &depth_images_[i], &depth_image_allocations_[i], nullptr);
        VERIFY_VK_RESULT("failed to create depth buffer image", result);

        VkImageViewCreateInfo image_view_create_info       = {};
        image_view_create_info.sType                       = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        image_view_create_info.image                       = depth_images_[i];
        image_view_create_info.viewType                    = VK_IMAGE_VIEW_TYPE_2D;
        image_view_create_info.format                      = image_create_info.format;
        image_view_create_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
        image_view_create_info.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
        image_view_create_info.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
        result = init.disp.createImageView(&image_view_create_info, nullptr, &depth_image_views_[i]);
        VERIFY_VK_RESULT("failed to create depth buffer image view", result);
    }
}

void App::create_render_pass()
{
    VkAttachmentDescription attachments[2];
    attachments[0]                = {};
    attachments[0].format         = init.swapchain.image_format;
    attachments[0].samples        = VK_SAMPLE_COUNT_2_BIT;
    attachments[0].loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[0].storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    attachments[0].stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachments[0].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[0].initialLayout  = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    attachments[0].finalLayout    = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    attachments[1]                = {};
    attachments[1].format         = VK_FORMAT_D16_UNORM;
    attachments[1].samples        = VK_SAMPLE_COUNT_2_BIT;
    attachments[1].loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[1].storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    attachments[1].stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachments[1].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[1].initialLayout  = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    attachments[1].finalLayout    = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkAttachmentReference color_attachment_ref = {};
    color_attachment_ref.attachment            = 0;
    color_attachment_ref.layout                = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkAttachmentReference depth_attachment_ref = {};
    depth_attachment_ref.attachment            = 1;
    depth_attachment_ref.layout                = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass    = {};
    subpass.pipelineBindPoint       = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount    = 1;
    subpass.pColorAttachments       = &color_attachment_ref;
    subpass.pDepthStencilAttachment = &depth_attachment_ref;

    VkRenderPassCreateInfo render_pass_info = {};
    render_pass_info.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_info.attachmentCount        = 2;
    render_pass_info.pAttachments           = attachments;
    render_pass_info.subpassCount           = 1;
    render_pass_info.pSubpasses             = &subpass;

    auto result = init.disp.createRenderPass(&render_pass_info, nullptr, &render_pass_);
    VERIFY_VK_RESULT("failed to create render pass", result);
}

void App::create_graphics_pipeline()
{
#ifdef __ANDROID__
    auto vert_module =
        gfxrecon::test::readShaderFromFile(init.disp, "multisample-depth/shaders/vert.spv", init.android_app);
    auto frag_module =
        gfxrecon::test::readShaderFromFile(init.disp, "multisample-depth/shaders/frag.spv", init.android_app);
#else
    auto vert_module = gfxrecon::test::readShaderFromFile(init.disp, "multisample-depth/shaders/vert.spv");
    auto frag_module = gfxrecon::test::readShaderFromFile(init.disp, "multisample-depth/shaders/frag.spv");
#endif

    VkPipelineShaderStageCreateInfo vert_stage_info = {};
    vert_stage_info.sType                           = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    vert_stage_info.stage                           = VK_SHADER_STAGE_VERTEX_BIT;
    vert_stage_info.module                          = vert_module;
    vert_stage_info.pName                           = "main";

    VkPipelineShaderStageCreateInfo frag_stage_info = {};
    frag_stage_info.sType                           = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    frag_stage_info.stage                           = VK_SHADER_STAGE_FRAGMENT_BIT;
    frag_stage_info.module                          = frag_module;
    frag_stage_info.pName                           = "main";

    VkPipelineShaderStageCreateInfo shader_stages[] = { vert_stage_info, frag_stage_info };

    VkPipelineVertexInputStateCreateInfo vertex_input_info = {};
    vertex_input_info.sType                                = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertex_input_info.vertexBindingDescriptionCount        = 0;
    vertex_input_info.vertexAttributeDescriptionCount      = 0;

    VkPipelineInputAssemblyStateCreateInfo input_assembly = {};
    input_assembly.sType                                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    input_assembly.topology                               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    input_assembly.primitiveRestartEnable                 = VK_FALSE;

    VkViewport viewport = {};
    viewport.x          = 0.0f;
    viewport.y          = 0.0f;
    viewport.width      = (float)init.swapchain.extent.width;
    viewport.height     = (float)init.swapchain.extent.height;
    viewport.minDepth   = 0.0f;
    viewport.maxDepth   = 1.0f;

    VkRect2D scissor = {};
    scissor.offset   = { 0, 0 };
    scissor.extent   = init.swapchain.extent;

    VkPipelineViewportStateCreateInfo viewport_state = {};
    viewport_state.sType                             = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewport_state.viewportCount                     = 1;
    viewport_state.pViewports                        = &viewport;
    viewport_state.scissorCount                      = 1;
    viewport_state.pScissors                         = &scissor;

    VkPipelineRasterizationStateCreateInfo rasterizer = {};
    rasterizer.sType                                  = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rasterizer.depthClampEnable                       = VK_FALSE;
    rasterizer.rasterizerDiscardEnable                = VK_FALSE;
    rasterizer.polygonMode                            = VK_POLYGON_MODE_FILL;
    rasterizer.lineWidth                              = 1.0f;
    rasterizer.cullMode                               = VK_CULL_MODE_BACK_BIT;
    rasterizer.frontFace                              = VK_FRONT_FACE_CLOCKWISE;
    rasterizer.depthBiasEnable                        = VK_FALSE;

    VkPipelineMultisampleStateCreateInfo multisampling = {};
    multisampling.sType                                = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisampling.sampleShadingEnable                  = VK_FALSE;
    multisampling.rasterizationSamples                 = VK_SAMPLE_COUNT_2_BIT;

    VkPipelineColorBlendAttachmentState colorBlendAttachment = {};
    colorBlendAttachment.colorWriteMask =
        VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    colorBlendAttachment.blendEnable = VK_FALSE;

    VkPipelineColorBlendStateCreateInfo color_blending = {};
    color_blending.sType                               = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    color_blending.logicOpEnable                       = VK_FALSE;
    color_blending.logicOp                             = VK_LOGIC_OP_COPY;
    color_blending.attachmentCount                     = 1;
    color_blending.pAttachments                        = &colorBlendAttachment;
    color_blending.blendConstants[0]                   = 0.0f;
    color_blending.blendConstants[1]                   = 0.0f;
    color_blending.blendConstants[2]                   = 0.0f;
    color_blending.blendConstants[3]                   = 0.0f;

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount             = 0;
    pipeline_layout_info.pushConstantRangeCount     = 0;

    auto result = init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout_);
    VERIFY_VK_RESULT("failed to create pipeline layout", result);

    std::vector<VkDynamicState> dynamic_states = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };

    VkPipelineDynamicStateCreateInfo dynamic_info = {};
    dynamic_info.sType                            = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_info.dynamicStateCount                = static_cast<uint32_t>(dynamic_states.size());
    dynamic_info.pDynamicStates                   = dynamic_states.data();

    VkPipelineDepthStencilStateCreateInfo depth_stencil = {};
    depth_stencil.sType                                 = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
    depth_stencil.depthTestEnable                       = true;
    depth_stencil.depthWriteEnable                      = true;
    depth_stencil.depthCompareOp                        = VK_COMPARE_OP_LESS;

    VkGraphicsPipelineCreateInfo pipeline_info = {};
    pipeline_info.sType                        = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipeline_info.stageCount                   = 2;
    pipeline_info.pStages                      = shader_stages;
    pipeline_info.pVertexInputState            = &vertex_input_info;
    pipeline_info.pInputAssemblyState          = &input_assembly;
    pipeline_info.pViewportState               = &viewport_state;
    pipeline_info.pRasterizationState          = &rasterizer;
    pipeline_info.pMultisampleState            = &multisampling;
    pipeline_info.pColorBlendState             = &color_blending;
    pipeline_info.pDynamicState                = &dynamic_info;
    pipeline_info.layout                       = pipeline_layout_;
    pipeline_info.renderPass                   = render_pass_;
    pipeline_info.pDepthStencilState           = &depth_stencil;

    result = init.disp.createGraphicsPipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &graphics_pipeline_);
    VERIFY_VK_RESULT("failed to create graphics pipeline", result);

    init.disp.destroyShaderModule(frag_module, nullptr);
    init.disp.destroyShaderModule(vert_module, nullptr);
}

void App::create_framebuffers()
{
    framebuffers_.resize(init.swapchain_image_views.size());

    for (size_t i = 0; i < init.swapchain_image_views.size(); i++)
    {
        VkImageView attachments[] = { render_target_views_[i], depth_image_views_[i] };

        VkFramebufferCreateInfo framebuffer_info = {};
        framebuffer_info.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebuffer_info.renderPass              = render_pass_;
        framebuffer_info.attachmentCount         = 2;
        framebuffer_info.pAttachments            = attachments;
        framebuffer_info.width                   = init.swapchain.extent.width;
        framebuffer_info.height                  = init.swapchain.extent.height;
        framebuffer_info.layers                  = 1;

        auto result = init.disp.createFramebuffer(&framebuffer_info, nullptr, &framebuffers_[i]);
        VERIFY_VK_RESULT("failed to create framebuffer", result);
    }
}

void App::recreate_swapchain()
{
    init.disp.deviceWaitIdle();

    for (size_t i = 0; i < init.swapchain_image_views.size(); i++)
    {
        init.disp.destroyFramebuffer(framebuffers_[i], nullptr);
        init.disp.destroyImageView(depth_image_views_[i], nullptr);
        vmaDestroyImage(allocator_, depth_images_[i], depth_image_allocations_[i]);
        init.disp.destroyImageView(render_target_views_[i], nullptr);
        vmaDestroyImage(allocator_, render_targets_[i], render_target_allocations_[i]);
    }

    TestAppBase::recreate_swapchain(false);

    create_render_targets();
    create_depth_buffers();
    create_framebuffers();
}

const int NUM_FRAMES = 10;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

bool App::frame(const int frame_num)
{
    init.disp.waitForFences(1, &sync_.in_flight_fences[current_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreate_swapchain();
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

    init.disp.resetCommandPool(command_pools_[current_frame_], 0);
    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pools_[current_frame_];
    VkCommandBuffer command_buffer;
    result = init.disp.allocateCommandBuffers(&allocate_info, &command_buffer);
    VERIFY_VK_RESULT("failed to allocate command buffer", result);

    {
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        result                              = init.disp.beginCommandBuffer(command_buffer, &begin_info);
        VERIFY_VK_RESULT("failed to create command buffer", result);

        {
            VkImageMemoryBarrier image_barriers[2];
            image_barriers[0]                             = {};
            image_barriers[0].sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barriers[0].image                       = render_targets_[image_index];
            image_barriers[0].oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
            image_barriers[0].newLayout                   = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            image_barriers[0].subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barriers[0].subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barriers[0].subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barriers[0].srcAccessMask               = VK_ACCESS_NONE;
            image_barriers[0].dstAccessMask               = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            image_barriers[1]                             = {};
            image_barriers[1].sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barriers[1].image                       = depth_images_[image_index];
            image_barriers[1].oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
            image_barriers[1].newLayout                   = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
            image_barriers[1].subresourceRange.aspectMask = VK_IMAGE_ASPECT_DEPTH_BIT;
            image_barriers[1].subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barriers[1].subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barriers[1].srcAccessMask               = VK_ACCESS_NONE;
            image_barriers[1].dstAccessMask =
                VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT |
                                             VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT |
                                             VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         2,
                                         image_barriers);
        }

        VkRenderPassBeginInfo render_pass_info = {};
        render_pass_info.sType                 = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        render_pass_info.renderPass            = render_pass_;
        render_pass_info.framebuffer           = framebuffers_[image_index];
        render_pass_info.renderArea.offset     = { 0, 0 };
        render_pass_info.renderArea.extent     = init.swapchain.extent;
        VkClearValue clearColors[]             = { { { { 0.0f, 0.0f, 0.0f, 1.0f } } }, { { 1.0f } } };
        render_pass_info.clearValueCount       = 2;
        render_pass_info.pClearValues          = clearColors;

        VkViewport viewport = {};
        viewport.x          = 0.0f;
        viewport.y          = 0.0f;
        viewport.width      = (float)init.swapchain.extent.width;
        viewport.height     = (float)init.swapchain.extent.height;
        viewport.minDepth   = 0.0f;
        viewport.maxDepth   = 1.0f;

        VkRect2D scissor = {};
        scissor.offset   = { 0, 0 };
        scissor.extent   = init.swapchain.extent;

        init.disp.cmdSetViewport(command_buffer, 0, 1, &viewport);
        init.disp.cmdSetScissor(command_buffer, 0, 1, &scissor);

        init.disp.cmdBeginRenderPass(command_buffer, &render_pass_info, VK_SUBPASS_CONTENTS_INLINE);

        init.disp.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphics_pipeline_);

        init.disp.cmdDraw(command_buffer, 3, 1, 0, 0);

        init.disp.cmdEndRenderPass(command_buffer);

        {
            VkMemoryBarrier memory_barrier = {};
            memory_barrier.sType           = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
            memory_barrier.srcAccessMask   = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT |
                                           VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT |
                                           VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            memory_barrier.dstAccessMask              = VK_ACCESS_NONE;
            VkImageMemoryBarrier image_barrier        = {};
            image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barrier.image                       = init.swapchain_images[image_index];
            image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
            image_barrier.newLayout                   = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
            image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barrier.srcAccessMask               = VK_ACCESS_NONE;
            image_barrier.dstAccessMask               = VK_ACCESS_NONE;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT |
                                             VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT |
                                             VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         0,
                                         1,
                                         &memory_barrier,
                                         0,
                                         nullptr,
                                         1,
                                         &image_barrier);
        }

        result = init.disp.endCommandBuffer(command_buffer);
        VERIFY_VK_RESULT("failed to end command buffer", result);
    }

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
        recreate_swapchain();
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

    for (auto command_pool : command_pools_)
    {
        init.disp.destroyCommandPool(command_pool, nullptr);
    }

    for (size_t i = 0; i < init.swapchain_image_views.size(); i++)
    {
        init.disp.destroyFramebuffer(framebuffers_[i], nullptr);
        init.disp.destroyImageView(depth_image_views_[i], nullptr);
        vmaDestroyImage(allocator_, depth_images_[i], depth_image_allocations_[i]);
        init.disp.destroyImageView(render_target_views_[i], nullptr);
        vmaDestroyImage(allocator_, render_targets_[i], render_target_allocations_[i]);
    }

    init.disp.destroyPipeline(graphics_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
    init.disp.destroyRenderPass(render_pass_, nullptr);

    vmaDestroyAllocator(allocator_);
}

void App::setup()
{
    create_allocator();

    auto graphics_queue = init.device.get_queue(gfxrecon::test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto present_queue = init.device.get_queue(gfxrecon::test::QueueType::present);
    if (!present_queue.has_value())
        throw std::runtime_error("could not get present queue");
    present_queue_ = *present_queue;

    create_render_targets();
    create_depth_buffers();

    create_render_pass();
    create_graphics_pipeline();

    create_framebuffers();

    auto queue_family_index = init.device.get_queue_index(gfxrecon::test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    for (auto& command_pool : command_pools_)
    {
        command_pool = gfxrecon::test::create_command_pool(init.disp, *queue_family_index);
    }

    sync_ = gfxrecon::test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);
}

GFXRECON_END_NAMESPACE(multisample_depth)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
