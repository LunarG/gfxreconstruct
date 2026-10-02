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

#include <frame_looping_image_contents_app.h>

#include <cmath>
#include <cstring>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(frame_looping_image_contents)

struct Vertex
{
    float position[2];
};

// The content image is a ring of coloured texels that the shader walks around one step per frame. The
// ring is longer than the capture so that no two frames of the capture, and no repetition of a looped
// frame, land on the same colour.
const uint32_t RING_SIZE = 12;

const VkFormat     CONTENT_IMAGE_FORMAT = VK_FORMAT_R8G8B8A8_UNORM;
const VkDeviceSize CONTENT_IMAGE_SIZE   = RING_SIZE * 4;

// One triangle, held still across the whole capture. Only the texels move, so anything that changes
// from frame to frame changed because the image contents changed.
const Vertex VERTICES[3] = { { { 0.0f, -0.9f } }, { { 0.9f, 0.9f } }, { { -0.9f, 0.9f } } };

const VkDeviceSize VERTEX_BUFFER_SIZE = sizeof(VERTICES);

const int NUM_FRAMES = 10;

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    if (test_config)
    {
        test_config->device_api_version_override = VK_MAKE_API_VERSION(0, 1, 3, 296);
    }

    TestAppBase::configure_instance_builder(instance_builder, test_config);
}

void App::create_buffer(VkDeviceSize size, VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory)
{
    VkBufferCreateInfo buffer_info = {};
    buffer_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.size               = size;
    buffer_info.usage              = usage;
    buffer_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;
    VERIFY_VK_RESULT("failed to create buffer", init.disp.createBuffer(&buffer_info, nullptr, buffer));

    VkMemoryRequirements memory_requirements;
    init.disp.getBufferMemoryRequirements(*buffer, &memory_requirements);

    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex      = find_memory_type(
        memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    VERIFY_VK_RESULT("failed to allocate buffer memory", init.disp.allocateMemory(&allocate_info, nullptr, memory));

    VERIFY_VK_RESULT("failed to bind buffer memory", init.disp.bindBufferMemory(*buffer, *memory, 0));
}

void App::create_vertex_buffer()
{
    create_buffer(VERTEX_BUFFER_SIZE, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, &vertex_buffer_, &vertex_buffer_memory_);

    void* data = nullptr;
    VERIFY_VK_RESULT("failed to map vertex buffer",
                     init.disp.mapMemory(vertex_buffer_memory_, 0, VERTEX_BUFFER_SIZE, 0, &data));
    memcpy(data, VERTICES, sizeof(VERTICES));
    init.disp.unmapMemory(vertex_buffer_memory_);
}

void App::create_image(VkImageUsageFlags usage, VkImage* image, VkDeviceMemory* memory)
{
    VkImageCreateInfo image_info = {};
    image_info.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_info.imageType         = VK_IMAGE_TYPE_2D;
    image_info.format            = CONTENT_IMAGE_FORMAT;
    image_info.extent            = { RING_SIZE, 1, 1 };
    image_info.mipLevels         = 1;
    image_info.arrayLayers       = 1;
    image_info.samples           = VK_SAMPLE_COUNT_1_BIT;
    image_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
    image_info.usage             = usage;
    image_info.sharingMode       = VK_SHARING_MODE_EXCLUSIVE;
    image_info.initialLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
    VERIFY_VK_RESULT("failed to create image", init.disp.createImage(&image_info, nullptr, image));

    VkMemoryRequirements memory_requirements;
    init.disp.getImageMemoryRequirements(*image, &memory_requirements);

    // Device local, so that the only way the host can reach the texels is the one upload in setup.
    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex =
        find_memory_type(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VERIFY_VK_RESULT("failed to allocate image memory", init.disp.allocateMemory(&allocate_info, nullptr, memory));

    VERIFY_VK_RESULT("failed to bind image memory", init.disp.bindImageMemory(*image, *memory, 0));
}

void App::create_images()
{
    create_image(VK_IMAGE_USAGE_SAMPLED_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT,
                 &content_image_,
                 &content_image_memory_);

    create_image(
        VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT, &scratch_image_, &scratch_image_memory_);

    VkImageViewCreateInfo view_info           = {};
    view_info.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    view_info.image                           = content_image_;
    view_info.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
    view_info.format                          = CONTENT_IMAGE_FORMAT;
    view_info.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    view_info.subresourceRange.baseMipLevel   = 0;
    view_info.subresourceRange.levelCount     = 1;
    view_info.subresourceRange.baseArrayLayer = 0;
    view_info.subresourceRange.layerCount     = 1;
    VERIFY_VK_RESULT("failed to create image view",
                     init.disp.createImageView(&view_info, nullptr, &content_image_view_));
}

void App::upload_initial_image_contents()
{
    // A different hue per ring position, so a rotation gives the triangle a colour it has not had on
    // any other frame and no two frames can be confused for each other.
    uint8_t texels[CONTENT_IMAGE_SIZE] = {};
    for (uint32_t i = 0; i < RING_SIZE; ++i)
    {
        const float hue = static_cast<float>(i) / static_cast<float>(RING_SIZE);

        uint8_t* texel = &texels[i * 4];
        for (uint32_t channel = 0; channel < 3; ++channel)
        {
            const float k     = std::fmod((5.0f - 2.0f * channel) + hue * 6.0f, 6.0f);
            const float value = 1.0f - 0.85f * std::max(0.0f, std::min(1.0f, std::min(k, 4.0f - k)));
            texel[channel]    = static_cast<uint8_t>(value * 255.0f + 0.5f);
        }
        texel[3] = 255;
    }

    // Only the initial contents come from the host. Everything after this is GPU work, which is what
    // makes a repetition's image depend on the replayer having restored the image.
    VkBuffer       staging_buffer        = VK_NULL_HANDLE;
    VkDeviceMemory staging_buffer_memory = VK_NULL_HANDLE;
    create_buffer(CONTENT_IMAGE_SIZE, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, &staging_buffer, &staging_buffer_memory);

    void* data = nullptr;
    VERIFY_VK_RESULT("failed to map staging buffer",
                     init.disp.mapMemory(staging_buffer_memory, 0, CONTENT_IMAGE_SIZE, 0, &data));
    memcpy(data, texels, sizeof(texels));
    init.disp.unmapMemory(staging_buffer_memory);

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    VkCommandPool upload_command_pool = test::create_command_pool(init.disp, *queue_family_index);

    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = upload_command_pool;
    VkCommandBuffer command_buffer;
    VERIFY_VK_RESULT("failed to allocate command buffer",
                     init.disp.allocateCommandBuffers(&allocate_info, &command_buffer));

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VERIFY_VK_RESULT("failed to begin command buffer", init.disp.beginCommandBuffer(command_buffer, &begin_info));

    VkImageMemoryBarrier image_barrier        = {};
    image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    image_barrier.srcQueueFamilyIndex         = VK_QUEUE_FAMILY_IGNORED;
    image_barrier.dstQueueFamilyIndex         = VK_QUEUE_FAMILY_IGNORED;
    image_barrier.image                       = content_image_;
    image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
    image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
    image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
    image_barrier.newLayout                   = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    image_barrier.srcAccessMask               = VK_ACCESS_NONE;
    image_barrier.dstAccessMask               = VK_ACCESS_TRANSFER_WRITE_BIT;
    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 0,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr,
                                 1,
                                 &image_barrier);

    VkBufferImageCopy upload_region               = {};
    upload_region.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
    upload_region.imageSubresource.mipLevel       = 0;
    upload_region.imageSubresource.baseArrayLayer = 0;
    upload_region.imageSubresource.layerCount     = 1;
    upload_region.imageOffset                     = { 0, 0, 0 };
    upload_region.imageExtent                     = { RING_SIZE, 1, 1 };
    init.disp.cmdCopyBufferToImage(
        command_buffer, staging_buffer, content_image_, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &upload_region);

    // Leave the image in the layout every frame expects to find it in, so that a looped frame can be
    // handed the image back in that same layout.
    image_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
    image_barrier.newLayout     = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
    image_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
    image_barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                                 0,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr,
                                 1,
                                 &image_barrier);

    VERIFY_VK_RESULT("failed to end command buffer", init.disp.endCommandBuffer(command_buffer));

    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer;
    VERIFY_VK_RESULT("failed to submit queue", init.disp.queueSubmit(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE));
    VERIFY_VK_RESULT("failed to wait for queue", init.disp.queueWaitIdle(graphics_queue_));

    init.disp.destroyCommandPool(upload_command_pool, nullptr);
    init.disp.destroyBuffer(staging_buffer, nullptr);
    init.disp.freeMemory(staging_buffer_memory, nullptr);
}

void App::create_descriptor_set()
{
    // The shader reaches the image with texelFetch, so none of the filtering or addressing state here
    // is used. A combined image sampler still needs a sampler, so this is the plainest one that works.
    VkSamplerCreateInfo sampler_info     = {};
    sampler_info.sType                   = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    sampler_info.magFilter               = VK_FILTER_NEAREST;
    sampler_info.minFilter               = VK_FILTER_NEAREST;
    sampler_info.mipmapMode              = VK_SAMPLER_MIPMAP_MODE_NEAREST;
    sampler_info.addressModeU            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.addressModeV            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.addressModeW            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.mipLodBias              = 0.0f;
    sampler_info.anisotropyEnable        = VK_FALSE;
    sampler_info.maxAnisotropy           = 1.0f;
    sampler_info.compareEnable           = VK_FALSE;
    sampler_info.compareOp               = VK_COMPARE_OP_NEVER;
    sampler_info.minLod                  = 0.0f;
    sampler_info.maxLod                  = 0.0f;
    sampler_info.unnormalizedCoordinates = VK_FALSE;
    VERIFY_VK_RESULT("failed to create sampler", init.disp.createSampler(&sampler_info, nullptr, &sampler_));

    VkDescriptorSetLayoutBinding binding = {};
    binding.binding                      = 0;
    binding.descriptorType               = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    binding.descriptorCount              = 1;
    binding.stageFlags                   = VK_SHADER_STAGE_FRAGMENT_BIT;

    VkDescriptorSetLayoutCreateInfo layout_info = {};
    layout_info.sType                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layout_info.bindingCount                    = 1;
    layout_info.pBindings                       = &binding;
    VERIFY_VK_RESULT("failed to create descriptor set layout",
                     init.disp.createDescriptorSetLayout(&layout_info, nullptr, &descriptor_set_layout_));

    VkDescriptorPoolSize pool_size = {};
    pool_size.type                 = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    pool_size.descriptorCount      = 1;

    VkDescriptorPoolCreateInfo pool_info = {};
    pool_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.maxSets                    = 1;
    pool_info.poolSizeCount              = 1;
    pool_info.pPoolSizes                 = &pool_size;
    VERIFY_VK_RESULT("failed to create descriptor pool",
                     init.disp.createDescriptorPool(&pool_info, nullptr, &descriptor_pool_));

    VkDescriptorSetAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocate_info.descriptorPool              = descriptor_pool_;
    allocate_info.descriptorSetCount          = 1;
    allocate_info.pSetLayouts                 = &descriptor_set_layout_;
    VERIFY_VK_RESULT("failed to allocate descriptor set",
                     init.disp.allocateDescriptorSets(&allocate_info, &descriptor_set_));

    // The descriptor is written once and keeps pointing at the same image for the whole capture. Only
    // the texels behind it change.
    VkDescriptorImageInfo descriptor_image_info = {};
    descriptor_image_info.sampler               = sampler_;
    descriptor_image_info.imageView             = content_image_view_;
    descriptor_image_info.imageLayout           = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

    VkWriteDescriptorSet write = {};
    write.sType                = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write.dstSet               = descriptor_set_;
    write.dstBinding           = 0;
    write.dstArrayElement      = 0;
    write.descriptorCount      = 1;
    write.descriptorType       = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    write.pImageInfo           = &descriptor_image_info;
    init.disp.updateDescriptorSets(1, &write, 0, nullptr);
}

void App::create_render_pass()
{
    VkAttachmentDescription color_attachment = {};
    color_attachment.format                  = init.swapchain.image_format;
    color_attachment.samples                 = VK_SAMPLE_COUNT_1_BIT;
    color_attachment.loadOp                  = VK_ATTACHMENT_LOAD_OP_CLEAR;
    color_attachment.storeOp                 = VK_ATTACHMENT_STORE_OP_STORE;
    color_attachment.stencilLoadOp           = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    color_attachment.stencilStoreOp          = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    color_attachment.initialLayout           = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    color_attachment.finalLayout             = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkAttachmentReference color_attachment_ref = {};
    color_attachment_ref.attachment            = 0;
    color_attachment_ref.layout                = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass = {};
    subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments    = &color_attachment_ref;

    VkRenderPassCreateInfo render_pass_info = {};
    render_pass_info.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_info.attachmentCount        = 1;
    render_pass_info.pAttachments           = &color_attachment;
    render_pass_info.subpassCount           = 1;
    render_pass_info.pSubpasses             = &subpass;
    render_pass_info.dependencyCount        = 0;

    auto result = init.disp.createRenderPass(&render_pass_info, nullptr, &render_pass_);
    VERIFY_VK_RESULT("failed to create render pass", result);
}

void App::create_graphics_pipeline()
{
#ifdef __ANDROID__
    auto vert_module = gfxrecon::test::readShaderFromFile(
        init.disp, "frame-looping-image-contents/shaders/vert.spv", init.android_app);
    auto frag_module = gfxrecon::test::readShaderFromFile(
        init.disp, "frame-looping-image-contents/shaders/frag.spv", init.android_app);
#else
    auto vert_module = gfxrecon::test::readShaderFromFile(init.disp, "frame-looping-image-contents/shaders/vert.spv");
    auto frag_module = gfxrecon::test::readShaderFromFile(init.disp, "frame-looping-image-contents/shaders/frag.spv");
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

    VkVertexInputBindingDescription binding_description = {};
    binding_description.binding                         = 0;
    binding_description.stride                          = sizeof(Vertex);
    binding_description.inputRate                       = VK_VERTEX_INPUT_RATE_VERTEX;

    VkVertexInputAttributeDescription attribute_description = {};
    attribute_description.location                          = 0;
    attribute_description.binding                           = 0;
    attribute_description.format                            = VK_FORMAT_R32G32_SFLOAT;
    attribute_description.offset                            = offsetof(Vertex, position);

    VkPipelineVertexInputStateCreateInfo vertex_input_info = {};
    vertex_input_info.sType                                = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertex_input_info.vertexBindingDescriptionCount        = 1;
    vertex_input_info.pVertexBindingDescriptions           = &binding_description;
    vertex_input_info.vertexAttributeDescriptionCount      = 1;
    vertex_input_info.pVertexAttributeDescriptions         = &attribute_description;

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
    rasterizer.cullMode                               = VK_CULL_MODE_NONE;
    rasterizer.frontFace                              = VK_FRONT_FACE_CLOCKWISE;
    rasterizer.depthBiasEnable                        = VK_FALSE;

    VkPipelineMultisampleStateCreateInfo multisampling = {};
    multisampling.sType                                = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisampling.sampleShadingEnable                  = VK_FALSE;
    multisampling.rasterizationSamples                 = VK_SAMPLE_COUNT_1_BIT;

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
    pipeline_layout_info.setLayoutCount             = 1;
    pipeline_layout_info.pSetLayouts                = &descriptor_set_layout_;
    pipeline_layout_info.pushConstantRangeCount     = 0;

    auto result = init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout_);
    VERIFY_VK_RESULT("failed to create pipeline layout", result);

    std::vector<VkDynamicState> dynamic_states = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };

    VkPipelineDynamicStateCreateInfo dynamic_info = {};
    dynamic_info.sType                            = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_info.dynamicStateCount                = static_cast<uint32_t>(dynamic_states.size());
    dynamic_info.pDynamicStates                   = dynamic_states.data();

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
    pipeline_info.subpass                      = 0;
    pipeline_info.basePipelineHandle           = VK_NULL_HANDLE;

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
        VkImageView attachments[] = { init.swapchain_image_views[i] };

        VkFramebufferCreateInfo framebuffer_info = {};
        framebuffer_info.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
        framebuffer_info.renderPass              = render_pass_;
        framebuffer_info.attachmentCount         = 1;
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

    for (auto framebuffer : framebuffers_)
    {
        init.disp.destroyFramebuffer(framebuffer, nullptr);
    }

    TestAppBase::recreate_swapchain(false);

    create_framebuffers();
}

bool App::frame(const int frame_num)
{
    // frame_num counts from zero, so this renders frames 0 through NUM_FRAMES - 1 and the capture is
    // exactly NUM_FRAMES frames long.
    const bool keep_running = (frame_num + 1) < NUM_FRAMES;

    init.disp.waitForFences(1, &sync_.in_flight_fences[current_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        recreate_swapchain();
        return keep_running;
    }
    else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
    {
        throw test::vulkan_exception("failed to acquire next image", result);
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

        // Rotate the ring by one texel. The new contents are a function of the old ones, which is the
        // only reason a repetition of this frame would drift away from the captured image. The copy
        // goes through a scratch image because the source and destination regions of a single
        // vkCmdCopyImage are not allowed to overlap within one image.
        VkImageMemoryBarrier content_barrier        = {};
        content_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        content_barrier.srcQueueFamilyIndex         = VK_QUEUE_FAMILY_IGNORED;
        content_barrier.dstQueueFamilyIndex         = VK_QUEUE_FAMILY_IGNORED;
        content_barrier.image                       = content_image_;
        content_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        content_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
        content_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;

        VkImageMemoryBarrier scratch_barrier = content_barrier;
        scratch_barrier.image                = scratch_image_;

        // Order this frame's rotation behind the previous frame's rotation and behind the previous
        // frame's draw, which sampled the image. Without this the frames in flight would race on the
        // content image and the rendering would stop being a function of the frame number.
        //
        // The content image's old layout is the same on every frame -- the upload in setup leaves it
        // in VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL and the last barrier of each frame puts it back
        // -- so a repetition of this frame finds the image exactly as the first run of it did. The
        // scratch image is fully overwritten by the save copy, so its old contents are discarded.
        content_barrier.oldLayout     = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        content_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        content_barrier.srcAccessMask = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_TRANSFER_WRITE_BIT;
        content_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

        scratch_barrier.oldLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
        scratch_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        scratch_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        scratch_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;

        VkImageMemoryBarrier rotate_barriers[2] = { content_barrier, scratch_barrier };
        init.disp.cmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT | VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     2,
                                     rotate_barriers);

        VkImageCopy save_region               = {};
        save_region.srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        save_region.srcSubresource.layerCount = 1;
        save_region.dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        save_region.dstSubresource.layerCount = 1;
        save_region.extent                    = { RING_SIZE, 1, 1 };
        init.disp.cmdCopyImage(command_buffer,
                               content_image_,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               scratch_image_,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               1,
                               &save_region);

        content_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        content_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        content_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        content_barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;

        scratch_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        scratch_barrier.newLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
        scratch_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        scratch_barrier.dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT;

        rotate_barriers[0] = content_barrier;
        rotate_barriers[1] = scratch_barrier;
        init.disp.cmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     2,
                                     rotate_barriers);

        // Texels 1 through RING_SIZE - 1 move down one slot and texel 0 wraps around to the end.
        VkImageCopy rotate_regions[2]               = {};
        rotate_regions[0].srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        rotate_regions[0].srcSubresource.layerCount = 1;
        rotate_regions[0].srcOffset                 = { 1, 0, 0 };
        rotate_regions[0].dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        rotate_regions[0].dstSubresource.layerCount = 1;
        rotate_regions[0].dstOffset                 = { 0, 0, 0 };
        rotate_regions[0].extent                    = { RING_SIZE - 1, 1, 1 };
        rotate_regions[1].srcSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        rotate_regions[1].srcSubresource.layerCount = 1;
        rotate_regions[1].srcOffset                 = { 0, 0, 0 };
        rotate_regions[1].dstSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        rotate_regions[1].dstSubresource.layerCount = 1;
        rotate_regions[1].dstOffset                 = { static_cast<int32_t>(RING_SIZE - 1), 0, 0 };
        rotate_regions[1].extent                    = { 1, 1, 1 };
        init.disp.cmdCopyImage(command_buffer,
                               scratch_image_,
                               VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                               content_image_,
                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                               2,
                               rotate_regions);

        content_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
        content_barrier.newLayout     = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        content_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        content_barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;
        init.disp.cmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     0,
                                     nullptr,
                                     1,
                                     &content_barrier);

        {
            VkImageMemoryBarrier image_barrier        = {};
            image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barrier.image                       = init.swapchain_images[image_index];
            image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
            image_barrier.newLayout                   = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barrier.srcAccessMask               = VK_ACCESS_NONE;
            image_barrier.dstAccessMask               = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &image_barrier);
        }

        VkRenderPassBeginInfo render_pass_info = {};
        render_pass_info.sType                 = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        render_pass_info.renderPass            = render_pass_;
        render_pass_info.framebuffer           = framebuffers_[image_index];
        render_pass_info.renderArea.offset     = { 0, 0 };
        render_pass_info.renderArea.extent     = init.swapchain.extent;
        VkClearValue clearColor{ { { 0.0f, 0.0f, 0.0f, 1.0f } } };
        render_pass_info.clearValueCount = 1;
        render_pass_info.pClearValues    = &clearColor;

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

        // Always the same descriptor and the same three vertices, and the shader always reads the same
        // texel, so the rotation is what gives the triangle its colour.
        init.disp.cmdBindDescriptorSets(
            command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_layout_, 0, 1, &descriptor_set_, 0, nullptr);

        VkDeviceSize vertex_buffer_offset = 0;
        init.disp.cmdBindVertexBuffers(command_buffer, 0, 1, &vertex_buffer_, &vertex_buffer_offset);

        init.disp.cmdDraw(command_buffer, 3, 1, 0, 0);

        init.disp.cmdEndRenderPass(command_buffer);

        {
            VkImageMemoryBarrier image_barrier        = {};
            image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            image_barrier.image                       = init.swapchain_images[image_index];
            image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
            image_barrier.newLayout                   = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
            image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            image_barrier.subresourceRange.layerCount = VK_REMAINING_ARRAY_LAYERS;
            image_barrier.subresourceRange.levelCount = VK_REMAINING_MIP_LEVELS;
            image_barrier.srcAccessMask               = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            image_barrier.dstAccessMask               = VK_ACCESS_NONE;
            init.disp.cmdPipelineBarrier(command_buffer,
                                         VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         0,
                                         0,
                                         nullptr,
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

    VkSemaphore signal_semaphores[] = { sync_.finished_semaphore[image_index] };
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
        return keep_running;
    }
    VERIFY_VK_RESULT("failed to present queue", result);

    current_frame_ = (current_frame_ + 1) % MAX_FRAMES_IN_FLIGHT;

    return keep_running;
}

void App::cleanup()
{
    for (size_t i = 0; i < sync_.finished_semaphore.size(); ++i)
    {
        init.disp.destroySemaphore(sync_.finished_semaphore[i], nullptr);
    }
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++)
    {
        init.disp.destroySemaphore(sync_.available_semaphores[i], nullptr);
        init.disp.destroyFence(sync_.in_flight_fences[i], nullptr);
    }

    for (auto command_pool : command_pools_)
    {
        init.disp.destroyCommandPool(command_pool, nullptr);
    }

    for (auto framebuffer : framebuffers_)
    {
        init.disp.destroyFramebuffer(framebuffer, nullptr);
    }

    init.disp.destroyPipeline(graphics_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
    init.disp.destroyRenderPass(render_pass_, nullptr);

    init.disp.destroyDescriptorPool(descriptor_pool_, nullptr);
    init.disp.destroyDescriptorSetLayout(descriptor_set_layout_, nullptr);
    init.disp.destroySampler(sampler_, nullptr);

    init.disp.destroyImageView(content_image_view_, nullptr);
    init.disp.destroyImage(content_image_, nullptr);
    init.disp.freeMemory(content_image_memory_, nullptr);
    init.disp.destroyImage(scratch_image_, nullptr);
    init.disp.freeMemory(scratch_image_memory_, nullptr);

    init.disp.destroyBuffer(vertex_buffer_, nullptr);
    init.disp.freeMemory(vertex_buffer_memory_, nullptr);
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    auto present_queue = init.device.get_queue(test::QueueType::present);
    if (!present_queue.has_value())
        throw std::runtime_error("could not get present queue");
    present_queue_ = *present_queue;

    create_vertex_buffer();

    create_images();
    upload_initial_image_contents();
    create_descriptor_set();

    create_render_pass();
    create_graphics_pipeline();

    create_framebuffers();

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    for (auto& command_pool : command_pools_)
    {
        command_pool = test::create_command_pool(init.disp, *queue_family_index);
    }

    sync_ = test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);
}

GFXRECON_END_NAMESPACE(frame_looping_image_contents)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
