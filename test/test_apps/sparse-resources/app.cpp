/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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

#include "sparse_resources_app.h"

#include <iostream>

#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(sparse_resources)

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    instance_builder.require_api_version(VK_MAKE_VERSION(1, 3, 0));
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector,
                                             vkmock::TestConfig*           test_config)
{
    VkPhysicalDeviceFeatures feats = {};
    feats.sparseBinding            = true;
    feats.sparseResidencyBuffer    = true;
    feats.sparseResidencyAliased   = true;
    feats.sparseResidencyImage2D   = true;
    phys_device_selector.set_required_features(feats);

    phys_device_selector.add_required_extension("VK_KHR_maintenance2");

    phys_device_selector.prefer_gpu_device_type(test::PreferredDeviceType::discrete);
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
    auto vert_module = gfxrecon::test::readShaderFromFile(init.disp, "shaders/tri.vert.spv");
    auto frag_module = gfxrecon::test::readShaderFromFile(init.disp, "shaders/tri.frag.spv");

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
    rasterizer.frontFace                              = VK_FRONT_FACE_COUNTER_CLOCKWISE;
    rasterizer.depthBiasEnable                        = VK_FALSE;

    VkPipelineMultisampleStateCreateInfo multisampling = {};
    multisampling.sType                                = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisampling.sampleShadingEnable                  = VK_FALSE;
    multisampling.rasterizationSamples                 = VK_SAMPLE_COUNT_1_BIT;

    VkPipelineColorBlendAttachmentState color_blend_attachment = {};
    color_blend_attachment.colorWriteMask =
        VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    color_blend_attachment.blendEnable = VK_FALSE;

    VkPipelineColorBlendStateCreateInfo color_blending = {};
    color_blending.sType                               = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    color_blending.logicOpEnable                       = VK_FALSE;
    color_blending.logicOp                             = VK_LOGIC_OP_COPY;
    color_blending.attachmentCount                     = 1;
    color_blending.pAttachments                        = &color_blend_attachment;
    color_blending.blendConstants[0]                   = 0.0f;
    color_blending.blendConstants[1]                   = 0.0f;
    color_blending.blendConstants[2]                   = 0.0f;
    color_blending.blendConstants[3]                   = 0.0f;

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount             = 1;
    pipeline_layout_info.pSetLayouts                = &descriptor_layout_;
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

void App::create_descriptor_set()
{
    VkDescriptorPoolSize pool_sizes[3] = {};
    pool_sizes[0].type                 = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
    pool_sizes[0].descriptorCount      = 1;
    pool_sizes[1].type                 = VK_DESCRIPTOR_TYPE_SAMPLER;
    pool_sizes[1].descriptorCount      = 1;
    pool_sizes[2].type                 = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    pool_sizes[2].descriptorCount      = 1;

    VkDescriptorPoolCreateInfo pool_info = {};
    pool_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.pNext                      = nullptr;
    pool_info.flags                      = 0;
    pool_info.maxSets                    = 1;
    pool_info.poolSizeCount              = 3;
    pool_info.pPoolSizes                 = pool_sizes;
    VkResult result                      = init.disp.createDescriptorPool(&pool_info, nullptr, &descriptor_pool_);
    VERIFY_VK_RESULT("Failed to create descriptor pool", result);

    // Create immutable sampler
    VkSamplerCreateInfo sampler_info     = {};
    sampler_info.sType                   = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    sampler_info.pNext                   = nullptr;
    sampler_info.flags                   = 0;
    sampler_info.magFilter               = VK_FILTER_NEAREST;
    sampler_info.minFilter               = VK_FILTER_NEAREST;
    sampler_info.mipmapMode              = VK_SAMPLER_MIPMAP_MODE_NEAREST;
    sampler_info.addressModeU            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.addressModeV            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.addressModeW            = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE;
    sampler_info.mipLodBias              = 0.0;
    sampler_info.anisotropyEnable        = VK_FALSE;
    sampler_info.maxAnisotropy           = 1.0;
    sampler_info.compareEnable           = VK_FALSE;
    sampler_info.compareOp               = VK_COMPARE_OP_NEVER;
    sampler_info.minLod                  = 0.0;
    sampler_info.maxLod                  = 1.0;
    sampler_info.borderColor             = {};
    sampler_info.unnormalizedCoordinates = VK_FALSE;

    result = init.disp.createSampler(&sampler_info, nullptr, &sampler_);
    VERIFY_VK_RESULT("Failed to create sampler.", result);

    VkDescriptorSetLayoutBinding bindings[3] = {};
    bindings[0].binding                      = 0;
    bindings[0].descriptorType               = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
    bindings[0].descriptorCount              = 1;
    bindings[0].stageFlags                   = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
    bindings[0].pImmutableSamplers           = nullptr;
    bindings[1].binding                      = 1;
    bindings[1].descriptorType               = VK_DESCRIPTOR_TYPE_SAMPLER;
    bindings[1].descriptorCount              = 1;
    bindings[1].stageFlags                   = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
    bindings[1].pImmutableSamplers           = &sampler_;
    bindings[2].binding                      = 2;
    bindings[2].descriptorType               = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    bindings[2].descriptorCount              = 1;
    bindings[2].stageFlags                   = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
    bindings[2].pImmutableSamplers           = nullptr;

    VkDescriptorSetLayoutCreateInfo layout_info = {};
    layout_info.sType                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layout_info.pNext                           = nullptr;
    layout_info.flags                           = 0;
    layout_info.bindingCount                    = 3;
    layout_info.pBindings                       = bindings;
    result = init.disp.createDescriptorSetLayout(&layout_info, nullptr, &descriptor_layout_);
    VERIFY_VK_RESULT("Failed to create descriptor set layout", result);

    VkDescriptorSetAllocateInfo alloc_info = {};
    alloc_info.sType                       = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    alloc_info.pNext                       = nullptr;
    alloc_info.descriptorPool              = descriptor_pool_;
    alloc_info.descriptorSetCount          = 1;
    alloc_info.pSetLayouts                 = &descriptor_layout_;

    result = init.disp.allocateDescriptorSets(&alloc_info, &descriptor_set_);
    VERIFY_VK_RESULT("Failed to allocate descriptor sets", result);
}

void App::determine_memory_heaps()
{
    VkPhysicalDeviceMemoryProperties props = init.physical_device.memory_properties;

    // Search for largest device-only memory heap
    VkDeviceSize largest_seen = 0;
    for (int i = 0; i < props.memoryTypeCount; ++i)
    {
        VkMemoryType type         = props.memoryTypes[i];
        bool         device_local = type.propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
        VkMemoryHeap heap         = props.memoryHeaps[type.heapIndex];

        if ((type.propertyFlags & VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT) &&
            (type.propertyFlags & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) &&
            (type.propertyFlags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
        {
            staging_memory_type_ = i;
        }
        else if (heap.flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT)
        {
            if (heap.size > largest_seen)
            {
                device_memory_type_ = i;
                largest_seen        = heap.size;
            }
        }
    }

    // Also determine sparse binding block size by creating
    // dummy object
    VkBufferCreateInfo buffer_info    = {};
    buffer_info.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.pNext                 = nullptr;
    buffer_info.flags                 = VK_BUFFER_CREATE_SPARSE_BINDING_BIT;
    buffer_info.size                  = 1;
    buffer_info.usage                 = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
    uint32_t idx                      = init.device.get_queue_index(test::QueueType::graphics).value();
    buffer_info.queueFamilyIndexCount = 1;
    buffer_info.pQueueFamilyIndices   = &idx;
    VkBuffer dummy;
    VkResult result = init.disp.createBuffer(&buffer_info, nullptr, &dummy);
    VERIFY_VK_RESULT("failed to create dummy buffer", result);

    VkMemoryRequirements mem_reqs = {};
    init.disp.getBufferMemoryRequirements(dummy, &mem_reqs);
    sparse_binding_granularity_ = mem_reqs.alignment;
    init.disp.destroyBuffer(dummy, nullptr);
}

void App::create_staging_buffer()
{
    // Create buffer object
    VkBufferCreateInfo buffer_info    = {};
    buffer_info.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.pNext                 = nullptr;
    buffer_info.flags                 = 0;
    buffer_info.size                  = STAGING_BUFFER_SIZE;
    buffer_info.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    buffer_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_info.queueFamilyIndexCount = 1;
    uint32_t idx                      = init.device.get_queue_index(test::QueueType::graphics).value();
    buffer_info.pQueueFamilyIndices   = &idx;
    VkResult result                   = init.disp.createBuffer(&buffer_info, nullptr, &staging_buffer_);
    VERIFY_VK_RESULT("failed to create staging buffer", result);

    // Allocate and bind buffer memory
    VkMemoryRequirements mem_reqs = {};
    init.disp.getBufferMemoryRequirements(staging_buffer_, &mem_reqs);
    VkMemoryAllocateInfo alloc_info = {};
    alloc_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    alloc_info.pNext                = nullptr;
    alloc_info.allocationSize       = mem_reqs.size;
    alloc_info.memoryTypeIndex      = staging_memory_type_;
    result                          = init.disp.allocateMemory(&alloc_info, nullptr, &staging_backing_memory_);
    VERIFY_VK_RESULT("failed to allocate staging buffer memory", result);
    result = init.disp.bindBufferMemory(staging_buffer_, staging_backing_memory_, 0);
    VERIFY_VK_RESULT("failed to bind staging buffer memory", result);

    // Map buffer
    init.disp.mapMemory(staging_backing_memory_, 0, STAGING_BUFFER_SIZE, 0, (void**)&staging_buffer_ptr_);
}

void App::create_sparse_bound_buffer()
{
    // Create buffer object
    VkBufferCreateInfo buffer_info    = {};
    buffer_info.sType                 = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.pNext                 = nullptr;
    buffer_info.flags                 = VK_BUFFER_CREATE_SPARSE_BINDING_BIT;
    buffer_info.size                  = 2 * sparse_binding_granularity_;
    buffer_info.usage                 = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    buffer_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_info.queueFamilyIndexCount = 1;
    uint32_t idx                      = init.device.get_queue_index(test::QueueType::graphics).value();
    buffer_info.pQueueFamilyIndices   = &idx;
    VkResult result                   = init.disp.createBuffer(&buffer_info, nullptr, &sparse_bound_buffer_);
    VERIFY_VK_RESULT("failed to create sparse buffer", result);

    // Allocate and bind buffer memory
    VkMemoryRequirements mem_reqs = {};
    init.disp.getBufferMemoryRequirements(sparse_bound_buffer_, &mem_reqs);
    VkMemoryAllocateInfo alloc_info = {};
    alloc_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    alloc_info.pNext                = nullptr;
    alloc_info.allocationSize       = 2 * sparse_binding_granularity_;
    alloc_info.memoryTypeIndex      = device_memory_type_;
    result                          = init.disp.allocateMemory(&alloc_info, nullptr, &sparse_buffer_backing_memory_);
    VERIFY_VK_RESULT("failed to allocate sparse buffer memory", result);

    // Update descriptor set
    VkDescriptorBufferInfo desc_buffer = {};
    desc_buffer.buffer                 = sparse_bound_buffer_;
    desc_buffer.offset                 = 0;
    desc_buffer.range                  = sizeof(Uniforms);

    VkWriteDescriptorSet write = {};
    write.sType                = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write.pNext                = nullptr;
    write.dstSet               = descriptor_set_;
    write.dstBinding           = 2;
    write.dstArrayElement      = 0;
    write.descriptorCount      = 1;
    write.descriptorType       = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    write.pImageInfo           = nullptr;
    write.pBufferInfo          = &desc_buffer;
    write.pTexelBufferView     = nullptr;
    init.disp.updateDescriptorSets(1, &write, 0, nullptr);
}

void App::create_images()
{
    // Get VkSparseImageFormatProperties for 2D R8G8B8A8_SRGB images
    VkPhysicalDevice pd         = init.physical_device.physical_device;
    uint32_t         prop_count = 0;
    init.inst_disp.getPhysicalDeviceSparseImageFormatProperties(pd,
                                                                IMAGE_FORMAT,
                                                                VK_IMAGE_TYPE_2D,
                                                                VK_SAMPLE_COUNT_1_BIT,
                                                                VK_IMAGE_USAGE_TRANSFER_DST_BIT |
                                                                    VK_IMAGE_USAGE_SAMPLED_BIT,
                                                                VK_IMAGE_TILING_OPTIMAL,
                                                                &prop_count,
                                                                nullptr);
    std::vector<VkSparseImageFormatProperties> props;
    props.resize(prop_count);
    init.inst_disp.getPhysicalDeviceSparseImageFormatProperties(pd,
                                                                IMAGE_FORMAT,
                                                                VK_IMAGE_TYPE_2D,
                                                                VK_SAMPLE_COUNT_1_BIT,
                                                                VK_IMAGE_USAGE_TRANSFER_DST_BIT |
                                                                    VK_IMAGE_USAGE_SAMPLED_BIT,
                                                                VK_IMAGE_TILING_OPTIMAL,
                                                                &prop_count,
                                                                props.data());

    // Create sparsely bound image object
    {
        VkImageCreateInfo image_info     = {};
        image_info.sType                 = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
        image_info.pNext                 = nullptr;
        image_info.flags                 = VK_IMAGE_CREATE_SPARSE_BINDING_BIT;
        image_info.imageType             = VK_IMAGE_TYPE_2D;
        image_info.format                = IMAGE_FORMAT;
        image_info.extent.width          = image_size_;
        image_info.extent.height         = image_size_;
        image_info.extent.depth          = 1;
        image_info.mipLevels             = mip_levels_;
        image_info.arrayLayers           = 1;
        image_info.samples               = VK_SAMPLE_COUNT_1_BIT;
        image_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
        image_info.usage                 = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
        image_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
        image_info.queueFamilyIndexCount = 1;
        uint32_t idx                     = init.device.get_queue_index(test::QueueType::graphics).value();
        image_info.pQueueFamilyIndices   = &idx;
        image_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;
        VkResult result                  = init.disp.createImage(&image_info, nullptr, &sparse_bind_image_);
        VERIFY_VK_RESULT("failed to create image", result);
    }

    // Get memory requirements
    VkMemoryRequirements total_reqs = {};
    {
        VkMemoryRequirements sparse_bind_image_reqs = {};
        init.disp.getImageMemoryRequirements(sparse_bind_image_, &sparse_bind_image_reqs);

        total_reqs.memoryTypeBits = sparse_bind_image_reqs.memoryTypeBits;
        total_reqs.size           = sparse_bind_image_reqs.size;
        total_reqs.alignment      = sparse_bind_image_reqs.alignment;
    }

    // Allocate image backing memory
    {
        VkMemoryAllocateInfo alloc_info = {};
        alloc_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
        alloc_info.pNext                = nullptr;
        alloc_info.allocationSize       = total_reqs.size;
        alloc_info.memoryTypeIndex      = device_memory_type_;
        VkResult result                 = init.disp.allocateMemory(&alloc_info, nullptr, &image_backing_memory_);
        VERIFY_VK_RESULT("Failed to allocate image memory", result);
    }

    // Create sparsely bound image view object
    {
        VkImageViewCreateInfo view_info           = {};
        view_info.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
        view_info.pNext                           = nullptr;
        view_info.flags                           = 0;
        view_info.image                           = sparse_bind_image_;
        view_info.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
        view_info.format                          = IMAGE_FORMAT;
        view_info.components                      = {};
        view_info.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
        view_info.subresourceRange.baseMipLevel   = 0;
        view_info.subresourceRange.levelCount     = mip_levels_;
        view_info.subresourceRange.baseArrayLayer = 0;
        view_info.subresourceRange.layerCount     = 1;
        VkResult result = init.disp.createImageView(&view_info, nullptr, &sparse_bind_image_view_);
        VERIFY_VK_RESULT("Failed to create image view", result);
    }

    // Update descriptor set
    VkDescriptorImageInfo desc_image = {};
    desc_image.sampler               = 0;
    desc_image.imageView             = sparse_bind_image_view_;
    desc_image.imageLayout           = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;

    VkWriteDescriptorSet write = {};
    write.sType                = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write.pNext                = nullptr;
    write.dstSet               = descriptor_set_;
    write.dstBinding           = 0;
    write.dstArrayElement      = 0;
    write.descriptorCount      = 1;
    write.descriptorType       = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
    write.pImageInfo           = &desc_image;
    write.pBufferInfo          = nullptr;
    write.pTexelBufferView     = nullptr;
    init.disp.updateDescriptorSets(1, &write, 0, nullptr);
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

    // Create fences
    {
        VkFenceCreateInfo info = {};
        info.sType             = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        info.pNext             = nullptr;
        info.flags             = 0;
        init.disp.createFence(&info, nullptr, &immediate_fence_);
    }

    auto queue_family_index = init.device.get_queue_index(gfxrecon::test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics index");
    for (int i = 0; i < MAX_FRAMES_IN_FLIGHT; ++i)
    {
        VkCommandPool& command_pool = command_pools_[i];
        command_pool                = gfxrecon::test::create_command_pool(init.disp, *queue_family_index);

        VkCommandBufferAllocateInfo allocate_info = {};
        allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        allocate_info.commandBufferCount          = 1;
        allocate_info.commandPool                 = command_pool;
        VkResult result = init.disp.allocateCommandBuffers(&allocate_info, &command_buffers_[i]);
        VERIFY_VK_RESULT("failed to allocate command buffer", result);
    }

    sync_ = gfxrecon::test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);

    determine_memory_heaps();
    create_descriptor_set();
    create_render_pass();
    create_graphics_pipeline();
    create_framebuffers();
    create_staging_buffer();
    create_sparse_bound_buffer();
    create_images();
}

bool App::frame(const int frame_num)
{
    init.disp.waitForFences(1, &sync_.in_flight_fences[current_in_flight_frame_], VK_TRUE, UINT64_MAX);

    uint32_t image_index = 0;
    VkResult result      = init.disp.acquireNextImageKHR(
        init.swapchain, UINT64_MAX, sync_.available_semaphores[current_in_flight_frame_], VK_NULL_HANDLE, &image_index);

    if (result == VK_ERROR_OUT_OF_DATE_KHR)
    {
        TestAppBase::recreate_swapchain(true);
        return true;
    }
    else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR)
    {
        throw gfxrecon::test::vulkan_exception("failed to acquire next image", result);
    }

    if (sync_.image_in_flight[current_in_flight_frame_] != VK_NULL_HANDLE)
    {
        init.disp.waitForFences(1, &sync_.image_in_flight[current_in_flight_frame_], VK_TRUE, UINT64_MAX);
    }
    sync_.image_in_flight[current_in_flight_frame_] = sync_.in_flight_fences[current_in_flight_frame_];

    init.disp.resetCommandPool(command_pools_[current_in_flight_frame_], 0);
    VkCommandBuffer command_buffer = command_buffers_[current_in_flight_frame_];

    {
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        result                              = init.disp.beginCommandBuffer(command_buffer, &begin_info);
        VERIFY_VK_RESULT("failed to begin command buffer", result);

        // Bind sparse memory
        const int frames_per_switch = 20;
        bool      do_memory_bind    = (current_frame_ % frames_per_switch) == 0;
        if (do_memory_bind)
        {
            bool reverse_bind = (current_frame_ / frames_per_switch) % 2 == 1;
            bool upload_data  = current_frame_ <= frames_per_switch;

            // Sparse buffer bind
            VkSparseMemoryBind sparse_buffer_bind = {};
            sparse_buffer_bind.resourceOffset     = 0;
            sparse_buffer_bind.size               = sparse_binding_granularity_;
            sparse_buffer_bind.memory             = sparse_buffer_backing_memory_;
            sparse_buffer_bind.memoryOffset       = 0;
            if (reverse_bind)
                sparse_buffer_bind.memoryOffset = sparse_binding_granularity_;
            sparse_buffer_bind.flags = 0;

            VkSparseBufferMemoryBindInfo buf_bind_info = {};
            buf_bind_info.buffer                       = sparse_bound_buffer_;
            buf_bind_info.bindCount                    = 1;
            buf_bind_info.pBinds                       = &sparse_buffer_bind;

            VkBindSparseInfo sparse_info = {};
            sparse_info.sType            = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
            sparse_info.pNext            = nullptr;
            sparse_info.bufferBindCount  = 1;
            sparse_info.pBufferBinds     = &buf_bind_info;

            result = init.disp.queueBindSparse(graphics_queue_, 1, &sparse_info, immediate_fence_);
            VERIFY_VK_RESULT("Failed to bind sparse memory", result);

            result = init.disp.waitForFences(1, &immediate_fence_, VK_TRUE, ~0);
            VERIFY_VK_RESULT("Failed to wait for sparse binding fence.", result);
            result = init.disp.resetFences(1, &immediate_fence_);
            VERIFY_VK_RESULT("failed to reset sparse binding fence", result);

            VkSparseMemoryBind sparse_image_bind = {};
            sparse_image_bind.resourceOffset     = 0;
            sparse_image_bind.size               = sparse_binding_granularity_;
            sparse_image_bind.memory             = image_backing_memory_;
            sparse_image_bind.memoryOffset       = 0;
            sparse_image_bind.flags              = 0;

            VkSparseImageOpaqueMemoryBindInfo im_bind_info = {};
            im_bind_info.image                             = sparse_bind_image_;
            im_bind_info.bindCount                         = 1;
            im_bind_info.pBinds                            = &sparse_image_bind;

            sparse_info.bufferBindCount      = 0;
            sparse_info.pBufferBinds         = nullptr;
            sparse_info.imageOpaqueBindCount = 1;
            sparse_info.pImageOpaqueBinds    = &im_bind_info;
            // sparse_info.imageBindCount = 1;
            // sparse_info.pImageBinds = &res_bind_info;
            result = init.disp.queueBindSparse(graphics_queue_, 1, &sparse_info, immediate_fence_);
            VERIFY_VK_RESULT("Failed to bind sparse memory", result);

            result = init.disp.waitForFences(1, &immediate_fence_, VK_TRUE, ~0);
            VERIFY_VK_RESULT("Failed to wait for sparse binding fence.", result);
            result = init.disp.resetFences(1, &immediate_fence_);
            VERIFY_VK_RESULT("failed to reset sparse binding fence", result);

            // Upload image data after bind
            if (upload_data)
            {
                // Write uniform data to staging buffer for sparse bound uniform buffer
                {
                    float* rot_ptr = (float*)staging_buffer_ptr_;
                    rot_ptr[0]     = 3.1415926 / 2.0;
                    if (current_frame_ == frames_per_switch)
                        rot_ptr[0] = 3.0 * 3.1415926 / 2.0;

                    VkBufferCopy region = {};
                    region.srcOffset    = 0;
                    region.dstOffset    = 0;
                    region.size         = sizeof(Uniforms);
                    init.disp.cmdCopyBuffer(command_buffer, staging_buffer_, sparse_bound_buffer_, 1, &region);

                    // Memory barrier to make this write available/visible
                    VkBufferMemoryBarrier barrier = {};
                    barrier.sType                 = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
                    barrier.pNext                 = nullptr;
                    barrier.srcAccessMask         = VK_ACCESS_TRANSFER_WRITE_BIT;
                    barrier.dstAccessMask         = VK_ACCESS_SHADER_READ_BIT;
                    barrier.buffer                = sparse_bound_buffer_;
                    barrier.offset                = 0;
                    barrier.size                  = 2 * sizeof(Uniforms);
                    init.disp.cmdPipelineBarrier(command_buffer,
                                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                 VK_PIPELINE_STAGE_VERTEX_SHADER_BIT,
                                                 0,
                                                 0,
                                                 nullptr,
                                                 1,
                                                 &barrier,
                                                 0,
                                                 nullptr);
                }

                // Write pixels to staging buffer for sparse bound image
                uint32_t image_staging_offset = 2 * sizeof(Uniforms);
                uint8_t* image_staging_ptr    = staging_buffer_ptr_ + image_staging_offset;
                for (int y = 0; y < image_size_; ++y)
                {
                    for (int x = 0; x < image_size_; ++x)
                    {
                        // Pointer to first byte of current pixel
                        // This is an R8G8B8A8 format
                        uint8_t* first_byte = image_staging_ptr + 4 * (y * image_size_ + x);
                        if (x % 2 + y % 2 == 1)
                        {
                            first_byte[0] = 0xFF;
                            first_byte[2] = 0xFF;
                        }
                    }
                }
                image_staging_ptr += 4 * image_size_ * image_size_;

                // Write pixels to staging buffer for sparse resident image
                for (int y = 0; y < image_size_; ++y)
                {
                    for (int x = 0; x < image_size_; ++x)
                    {
                        // Pointer to first byte of current pixel
                        // This is an R8G8B8A8 format
                        uint8_t* first_byte = image_staging_ptr + 4 * (y * image_size_ + x);
                        if (x % 2 + y % 2 == 1)
                        {
                            first_byte[0] = 0xFF;
                        }
                    }
                }

                // Memory barrier to transition into transfer dst optimal
                {
                    VkImageMemoryBarrier image_barrier        = {};
                    image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                    image_barrier.image                       = sparse_bind_image_;
                    image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
                    image_barrier.newLayout                   = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                    image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
                    image_barrier.subresourceRange.layerCount = 1;
                    image_barrier.subresourceRange.levelCount = 1;
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
                }

                // Copy image data from staging buffer
                VkBufferImageCopy image_copy = {};
                image_copy.bufferOffset      = image_staging_offset;
                if (current_frame_ == frames_per_switch)
                    image_copy.bufferOffset = image_staging_offset + 4 * image_size_ * image_size_;
                image_copy.bufferRowLength                 = 0;
                image_copy.bufferImageHeight               = 0;
                image_copy.imageSubresource.aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT;
                image_copy.imageSubresource.mipLevel       = 0;
                image_copy.imageSubresource.baseArrayLayer = 0;
                image_copy.imageSubresource.layerCount     = 1;
                image_copy.imageOffset.x                   = 0;
                image_copy.imageOffset.y                   = 0;
                image_copy.imageOffset.z                   = 0;
                image_copy.imageExtent.width               = image_size_;
                image_copy.imageExtent.height              = image_size_;
                image_copy.imageExtent.depth               = 1;

                init.disp.cmdCopyBufferToImage(command_buffer,
                                               staging_buffer_,
                                               sparse_bind_image_,
                                               VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                               1,
                                               &image_copy);

                // Memory barrier to transition into read-only optimal
                {
                    VkImageMemoryBarrier image_barrier        = {};
                    image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                    image_barrier.image                       = sparse_bind_image_;
                    image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                    image_barrier.newLayout                   = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
                    image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
                    image_barrier.subresourceRange.layerCount = 1;
                    image_barrier.subresourceRange.levelCount = 1;
                    image_barrier.srcAccessMask               = VK_ACCESS_TRANSFER_WRITE_BIT;
                    image_barrier.dstAccessMask               = VK_ACCESS_SHADER_READ_BIT;
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
                }
            }
        }

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
        VkClearValue clearColor{ { { 0.0f, 0.0f, 1.0f, 1.0f } } };
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
        init.disp.cmdBindDescriptorSets(
            command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_layout_, 0, 1, &descriptor_set_, 0, nullptr);
        init.disp.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphics_pipeline_);

        init.disp.cmdDraw(command_buffer, 6, 1, 0, 0);

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
                                         VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
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

    VkSemaphore          wait_semaphores[] = { sync_.available_semaphores[current_in_flight_frame_] };
    VkPipelineStageFlags wait_stages[]     = {
            VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
            VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
    };
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores    = wait_semaphores;
    submitInfo.pWaitDstStageMask  = wait_stages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers    = &command_buffer;

    VkSemaphore signal_semaphores[] = { sync_.finished_semaphore[current_in_flight_frame_] };
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores    = signal_semaphores;

    init.disp.resetFences(1, &sync_.in_flight_fences[current_in_flight_frame_]);

    result = init.disp.queueSubmit(graphics_queue_, 1, &submitInfo, sync_.in_flight_fences[current_in_flight_frame_]);
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
        TestAppBase::recreate_swapchain(true);
        return true;
    }
    VERIFY_VK_RESULT("failed to present queue", result);

    last_in_flight_frame_    = current_in_flight_frame_;
    current_in_flight_frame_ = (current_in_flight_frame_ + 1) % MAX_FRAMES_IN_FLIGHT;
    current_frame_ += 1;

    return frame_num < FRAMES_UNTIL_EXIT;
    // return true;
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

    for (auto framebuffer : framebuffers_)
    {
        init.disp.destroyFramebuffer(framebuffer, nullptr);
    }

    init.disp.destroyPipeline(graphics_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
    init.disp.destroyRenderPass(render_pass_, nullptr);

    init.disp.destroyBuffer(staging_buffer_, nullptr);
    init.disp.destroyBuffer(sparse_bound_buffer_, nullptr);

    init.disp.destroyImageView(sparse_bind_image_view_, nullptr);
    init.disp.destroyImage(sparse_bind_image_, nullptr);
    init.disp.destroySampler(sampler_, nullptr);

    init.disp.destroyFence(immediate_fence_, nullptr);

    init.disp.freeMemory(image_backing_memory_, nullptr);
    init.disp.freeMemory(staging_backing_memory_, nullptr);
    init.disp.freeMemory(sparse_buffer_backing_memory_, nullptr);

    init.disp.destroyDescriptorPool(descriptor_pool_, nullptr);
    init.disp.destroyDescriptorSetLayout(descriptor_layout_, nullptr);
}

GFXRECON_END_NAMESPACE(sparse_resources)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
