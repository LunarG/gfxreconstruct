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

#include <secondary_draw_twice_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(secondary_draw_twice)

// SPIR-V (glslangValidator -V) of the vertex shader below: a triangle that covers the whole render target, generated
// from the vertex index, so the draw call needs no vertex buffer.
//
//   #version 450
//
//   void main()
//   {
//       // Fullscreen triangle from the vertex index
//       vec2 pos    = vec2((gl_VertexIndex << 1) & 2, gl_VertexIndex & 2);
//       gl_Position = vec4(pos * 2.0 - 1.0, 0.0, 1.0);
//   }
static const uint32_t kVertexShaderSpirv[] = {
    0x07230203, 0x00010000, 0x0008000b, 0x0000002b, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0007000f, 0x00000000,
    0x00000004, 0x6e69616d, 0x00000000, 0x0000000c, 0x0000001d, 0x00030003, 0x00000002, 0x000001c2, 0x00040005,
    0x00000004, 0x6e69616d, 0x00000000, 0x00030005, 0x00000009, 0x00736f70, 0x00060005, 0x0000000c, 0x565f6c67,
    0x65747265, 0x646e4978, 0x00007865, 0x00060005, 0x0000001b, 0x505f6c67, 0x65567265, 0x78657472, 0x00000000,
    0x00060006, 0x0000001b, 0x00000000, 0x505f6c67, 0x7469736f, 0x006e6f69, 0x00070006, 0x0000001b, 0x00000001,
    0x505f6c67, 0x746e696f, 0x657a6953, 0x00000000, 0x00070006, 0x0000001b, 0x00000002, 0x435f6c67, 0x4470696c,
    0x61747369, 0x0065636e, 0x00070006, 0x0000001b, 0x00000003, 0x435f6c67, 0x446c6c75, 0x61747369, 0x0065636e,
    0x00030005, 0x0000001d, 0x00000000, 0x00040047, 0x0000000c, 0x0000000b, 0x0000002a, 0x00030047, 0x0000001b,
    0x00000002, 0x00050048, 0x0000001b, 0x00000000, 0x0000000b, 0x00000000, 0x00050048, 0x0000001b, 0x00000001,
    0x0000000b, 0x00000001, 0x00050048, 0x0000001b, 0x00000002, 0x0000000b, 0x00000003, 0x00050048, 0x0000001b,
    0x00000003, 0x0000000b, 0x00000004, 0x00020013, 0x00000002, 0x00030021, 0x00000003, 0x00000002, 0x00030016,
    0x00000006, 0x00000020, 0x00040017, 0x00000007, 0x00000006, 0x00000002, 0x00040020, 0x00000008, 0x00000007,
    0x00000007, 0x00040015, 0x0000000a, 0x00000020, 0x00000001, 0x00040020, 0x0000000b, 0x00000001, 0x0000000a,
    0x0004003b, 0x0000000b, 0x0000000c, 0x00000001, 0x0004002b, 0x0000000a, 0x0000000e, 0x00000001, 0x0004002b,
    0x0000000a, 0x00000010, 0x00000002, 0x00040017, 0x00000017, 0x00000006, 0x00000004, 0x00040015, 0x00000018,
    0x00000020, 0x00000000, 0x0004002b, 0x00000018, 0x00000019, 0x00000001, 0x0004001c, 0x0000001a, 0x00000006,
    0x00000019, 0x0006001e, 0x0000001b, 0x00000017, 0x00000006, 0x0000001a, 0x0000001a, 0x00040020, 0x0000001c,
    0x00000003, 0x0000001b, 0x0004003b, 0x0000001c, 0x0000001d, 0x00000003, 0x0004002b, 0x0000000a, 0x0000001e,
    0x00000000, 0x0004002b, 0x00000006, 0x00000020, 0x40000000, 0x0004002b, 0x00000006, 0x00000022, 0x3f800000,
    0x0004002b, 0x00000006, 0x00000025, 0x00000000, 0x00040020, 0x00000029, 0x00000003, 0x00000017, 0x00050036,
    0x00000002, 0x00000004, 0x00000000, 0x00000003, 0x000200f8, 0x00000005, 0x0004003b, 0x00000008, 0x00000009,
    0x00000007, 0x0004003d, 0x0000000a, 0x0000000d, 0x0000000c, 0x000500c4, 0x0000000a, 0x0000000f, 0x0000000d,
    0x0000000e, 0x000500c7, 0x0000000a, 0x00000011, 0x0000000f, 0x00000010, 0x0004006f, 0x00000006, 0x00000012,
    0x00000011, 0x0004003d, 0x0000000a, 0x00000013, 0x0000000c, 0x000500c7, 0x0000000a, 0x00000014, 0x00000013,
    0x00000010, 0x0004006f, 0x00000006, 0x00000015, 0x00000014, 0x00050050, 0x00000007, 0x00000016, 0x00000012,
    0x00000015, 0x0003003e, 0x00000009, 0x00000016, 0x0004003d, 0x00000007, 0x0000001f, 0x00000009, 0x0005008e,
    0x00000007, 0x00000021, 0x0000001f, 0x00000020, 0x00050050, 0x00000007, 0x00000023, 0x00000022, 0x00000022,
    0x00050083, 0x00000007, 0x00000024, 0x00000021, 0x00000023, 0x00050051, 0x00000006, 0x00000026, 0x00000024,
    0x00000000, 0x00050051, 0x00000006, 0x00000027, 0x00000024, 0x00000001, 0x00070050, 0x00000017, 0x00000028,
    0x00000026, 0x00000027, 0x00000025, 0x00000022, 0x00050041, 0x00000029, 0x0000002a, 0x0000001d, 0x0000001e,
    0x0003003e, 0x0000002a, 0x00000028, 0x000100fd, 0x00010038
};

// SPIR-V (glslangValidator -V) of the fragment shader below: it outputs the color of the uniform buffer, which the
// pipeline adds to what the render target already holds.
//
//   #version 450
//
//   layout(set = 0, binding = 0) uniform Params
//   {
//       vec4 color;
//   } params;
//
//   layout(location = 0) out vec4 out_color;
//
//   void main()
//   {
//       out_color = params.color;
//   }
static const uint32_t kFragmentShaderSpirv[] = {
    0x07230203, 0x00010000, 0x0008000b, 0x00000012, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0006000f, 0x00000004,
    0x00000004, 0x6e69616d, 0x00000000, 0x00000009, 0x00030010, 0x00000004, 0x00000007, 0x00030003, 0x00000002,
    0x000001c2, 0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00050005, 0x00000009, 0x5f74756f, 0x6f6c6f63,
    0x00000072, 0x00040005, 0x0000000a, 0x61726150, 0x0000736d, 0x00050006, 0x0000000a, 0x00000000, 0x6f6c6f63,
    0x00000072, 0x00040005, 0x0000000c, 0x61726170, 0x0000736d, 0x00040047, 0x00000009, 0x0000001e, 0x00000000,
    0x00030047, 0x0000000a, 0x00000002, 0x00050048, 0x0000000a, 0x00000000, 0x00000023, 0x00000000, 0x00040047,
    0x0000000c, 0x00000021, 0x00000000, 0x00040047, 0x0000000c, 0x00000022, 0x00000000, 0x00020013, 0x00000002,
    0x00030021, 0x00000003, 0x00000002, 0x00030016, 0x00000006, 0x00000020, 0x00040017, 0x00000007, 0x00000006,
    0x00000004, 0x00040020, 0x00000008, 0x00000003, 0x00000007, 0x0004003b, 0x00000008, 0x00000009, 0x00000003,
    0x0003001e, 0x0000000a, 0x00000007, 0x00040020, 0x0000000b, 0x00000002, 0x0000000a, 0x0004003b, 0x0000000b,
    0x0000000c, 0x00000002, 0x00040015, 0x0000000d, 0x00000020, 0x00000001, 0x0004002b, 0x0000000d, 0x0000000e,
    0x00000000, 0x00040020, 0x0000000f, 0x00000002, 0x00000007, 0x00050036, 0x00000002, 0x00000004, 0x00000000,
    0x00000003, 0x000200f8, 0x00000005, 0x00050041, 0x0000000f, 0x00000010, 0x0000000c, 0x0000000e, 0x0004003d,
    0x00000007, 0x00000011, 0x00000010, 0x0003003e, 0x00000009, 0x00000011, 0x000100fd, 0x00010038
};

// The render target is small, so that dumping it for every execution stays cheap
const uint32_t RENDER_TARGET_SIZE   = 64;
const VkFormat RENDER_TARGET_FORMAT = VK_FORMAT_R8G8B8A8_UNORM;

// Params::color is 0.25 in every component. The uniform buffer is filled with the bit pattern of that float.
const uint32_t     COLOR_COMPONENT_BITS = 0x3e800000;
const VkDeviceSize UNIFORM_BUFFER_SIZE  = 4 * sizeof(float);

// How many times the primary executes the secondary
const uint32_t EXECUTION_COUNT = 2;

const int NUM_FRAMES = 2;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

void App::create_render_target()
{
    VkImageCreateInfo image_info = {};
    image_info.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_info.imageType         = VK_IMAGE_TYPE_2D;
    image_info.format            = RENDER_TARGET_FORMAT;
    image_info.extent            = { RENDER_TARGET_SIZE, RENDER_TARGET_SIZE, 1 };
    image_info.mipLevels         = 1;
    image_info.arrayLayers       = 1;
    image_info.samples           = VK_SAMPLE_COUNT_1_BIT;
    image_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
    image_info.usage             = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    image_info.sharingMode       = VK_SHARING_MODE_EXCLUSIVE;
    image_info.initialLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
    VERIFY_VK_RESULT("failed to create render target", init.disp.createImage(&image_info, nullptr, &render_target_));

    VkMemoryRequirements memory_requirements;
    init.disp.getImageMemoryRequirements(render_target_, &memory_requirements);

    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex =
        find_memory_type(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VERIFY_VK_RESULT("failed to allocate render target memory",
                     init.disp.allocateMemory(&allocate_info, nullptr, &render_target_memory_));
    VERIFY_VK_RESULT("failed to bind render target memory",
                     init.disp.bindImageMemory(render_target_, render_target_memory_, 0));

    VkImageViewCreateInfo view_info = {};
    view_info.sType                 = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    view_info.image                 = render_target_;
    view_info.viewType              = VK_IMAGE_VIEW_TYPE_2D;
    view_info.format                = RENDER_TARGET_FORMAT;
    view_info.subresourceRange      = { VK_IMAGE_ASPECT_COLOR_BIT, 0, 1, 0, 1 };
    VERIFY_VK_RESULT("failed to create render target view",
                     init.disp.createImageView(&view_info, nullptr, &render_target_view_));

    // Every frame starts from a cleared render target, so the executions of a frame always add up from zero
    VkAttachmentDescription attachment = {};
    attachment.format                  = RENDER_TARGET_FORMAT;
    attachment.samples                 = VK_SAMPLE_COUNT_1_BIT;
    attachment.loadOp                  = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachment.storeOp                 = VK_ATTACHMENT_STORE_OP_STORE;
    attachment.stencilLoadOp           = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachment.stencilStoreOp          = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachment.initialLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
    attachment.finalLayout             = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

    VkAttachmentReference color_reference = {};
    color_reference.attachment            = 0;
    color_reference.layout                = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass = {};
    subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments    = &color_reference;

    VkRenderPassCreateInfo render_pass_info = {};
    render_pass_info.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    render_pass_info.attachmentCount        = 1;
    render_pass_info.pAttachments           = &attachment;
    render_pass_info.subpassCount           = 1;
    render_pass_info.pSubpasses             = &subpass;
    VERIFY_VK_RESULT("failed to create render pass",
                     init.disp.createRenderPass(&render_pass_info, nullptr, &render_pass_));

    VkFramebufferCreateInfo framebuffer_info = {};
    framebuffer_info.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    framebuffer_info.renderPass              = render_pass_;
    framebuffer_info.attachmentCount         = 1;
    framebuffer_info.pAttachments            = &render_target_view_;
    framebuffer_info.width                   = RENDER_TARGET_SIZE;
    framebuffer_info.height                  = RENDER_TARGET_SIZE;
    framebuffer_info.layers                  = 1;
    VERIFY_VK_RESULT("failed to create framebuffer",
                     init.disp.createFramebuffer(&framebuffer_info, nullptr, &framebuffer_));
}

void App::create_uniform_buffer()
{
    VkBufferCreateInfo buffer_info = {};
    buffer_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.size               = UNIFORM_BUFFER_SIZE;
    buffer_info.usage              = VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    buffer_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;
    VERIFY_VK_RESULT("failed to create uniform buffer",
                     init.disp.createBuffer(&buffer_info, nullptr, &uniform_buffer_));

    VkMemoryRequirements memory_requirements;
    init.disp.getBufferMemoryRequirements(uniform_buffer_, &memory_requirements);

    // Device-local only: the buffer is initialized on the GPU, so nothing of it goes through host memory
    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex =
        find_memory_type(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VERIFY_VK_RESULT("failed to allocate uniform buffer memory",
                     init.disp.allocateMemory(&allocate_info, nullptr, &uniform_buffer_memory_));

    VERIFY_VK_RESULT("failed to bind uniform buffer memory",
                     init.disp.bindBufferMemory(uniform_buffer_, uniform_buffer_memory_, 0));
}

void App::initialize_uniform_buffer()
{
    // One-time GPU-side initialization of the color
    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandBufferCount          = 1;
    allocate_info.commandPool                 = command_pools_[0];
    VkCommandBuffer command_buffer;
    VERIFY_VK_RESULT("failed to allocate command buffer",
                     init.disp.allocateCommandBuffers(&allocate_info, &command_buffer));

    VkCommandBufferBeginInfo begin_info = {};
    begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
    VERIFY_VK_RESULT("failed to begin command buffer", init.disp.beginCommandBuffer(command_buffer, &begin_info));

    init.disp.cmdFillBuffer(command_buffer, uniform_buffer_, 0, VK_WHOLE_SIZE, COLOR_COMPONENT_BITS);

    VkMemoryBarrier barrier = {};
    barrier.sType           = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
    barrier.srcAccessMask   = VK_ACCESS_TRANSFER_WRITE_BIT;
    barrier.dstAccessMask   = VK_ACCESS_UNIFORM_READ_BIT;
    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                                 0,
                                 1,
                                 &barrier,
                                 0,
                                 nullptr,
                                 0,
                                 nullptr);

    VERIFY_VK_RESULT("failed to end command buffer", init.disp.endCommandBuffer(command_buffer));

    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer;
    VERIFY_VK_RESULT("failed to submit queue", init.disp.queueSubmit(graphics_queue_, 1, &submit_info, VK_NULL_HANDLE));
    VERIFY_VK_RESULT("failed to wait for queue", init.disp.queueWaitIdle(graphics_queue_));

    init.disp.freeCommandBuffers(command_pools_[0], 1, &command_buffer);
}

void App::create_descriptor_set()
{
    VkDescriptorSetLayoutBinding binding = {};
    binding.binding                      = 0;
    binding.descriptorType               = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    binding.descriptorCount              = 1;
    binding.stageFlags                   = VK_SHADER_STAGE_FRAGMENT_BIT;

    VkDescriptorSetLayoutCreateInfo layout_info = {};
    layout_info.sType                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layout_info.bindingCount                    = 1;
    layout_info.pBindings                       = &binding;
    VERIFY_VK_RESULT("failed to create descriptor set layout",
                     init.disp.createDescriptorSetLayout(&layout_info, nullptr, &descriptor_set_layout_));

    VkDescriptorPoolSize pool_size = {};
    pool_size.type                 = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
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

    VkDescriptorBufferInfo buffer_info = {};
    buffer_info.buffer                 = uniform_buffer_;
    buffer_info.range                  = VK_WHOLE_SIZE;

    VkWriteDescriptorSet write = {};
    write.sType                = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write.dstSet               = descriptor_set_;
    write.dstBinding           = 0;
    write.descriptorCount      = 1;
    write.descriptorType       = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    write.pBufferInfo          = &buffer_info;
    init.disp.updateDescriptorSets(1, &write, 0, nullptr);
}

void App::create_graphics_pipeline()
{
    VkShaderModuleCreateInfo vertex_shader_info = {};
    vertex_shader_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    vertex_shader_info.codeSize                 = sizeof(kVertexShaderSpirv);
    vertex_shader_info.pCode                    = kVertexShaderSpirv;
    VERIFY_VK_RESULT("failed to create vertex shader module",
                     init.disp.createShaderModule(&vertex_shader_info, nullptr, &vertex_shader_));

    VkShaderModuleCreateInfo fragment_shader_info = {};
    fragment_shader_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    fragment_shader_info.codeSize                 = sizeof(kFragmentShaderSpirv);
    fragment_shader_info.pCode                    = kFragmentShaderSpirv;
    VERIFY_VK_RESULT("failed to create fragment shader module",
                     init.disp.createShaderModule(&fragment_shader_info, nullptr, &fragment_shader_));

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount             = 1;
    pipeline_layout_info.pSetLayouts                = &descriptor_set_layout_;
    VERIFY_VK_RESULT("failed to create pipeline layout",
                     init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout_));

    VkPipelineShaderStageCreateInfo stages[2] = {};
    stages[0].sType                           = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stages[0].stage                           = VK_SHADER_STAGE_VERTEX_BIT;
    stages[0].module                          = vertex_shader_;
    stages[0].pName                           = "main";
    stages[1].sType                           = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stages[1].stage                           = VK_SHADER_STAGE_FRAGMENT_BIT;
    stages[1].module                          = fragment_shader_;
    stages[1].pName                           = "main";

    VkPipelineVertexInputStateCreateInfo vertex_input = {};
    vertex_input.sType                                = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;

    VkPipelineInputAssemblyStateCreateInfo input_assembly = {};
    input_assembly.sType                                  = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    input_assembly.topology                               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;

    const float      size     = static_cast<float>(RENDER_TARGET_SIZE);
    const VkViewport viewport = { 0.0f, 0.0f, size, size, 0.0f, 1.0f };
    const VkRect2D   scissor  = { { 0, 0 }, { RENDER_TARGET_SIZE, RENDER_TARGET_SIZE } };

    VkPipelineViewportStateCreateInfo viewport_state = {};
    viewport_state.sType                             = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewport_state.viewportCount                     = 1;
    viewport_state.pViewports                        = &viewport;
    viewport_state.scissorCount                      = 1;
    viewport_state.pScissors                         = &scissor;

    VkPipelineRasterizationStateCreateInfo rasterization = {};
    rasterization.sType                                  = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rasterization.polygonMode                            = VK_POLYGON_MODE_FILL;
    rasterization.cullMode                               = VK_CULL_MODE_NONE;
    rasterization.frontFace                              = VK_FRONT_FACE_COUNTER_CLOCKWISE;
    rasterization.lineWidth                              = 1.0f;

    VkPipelineMultisampleStateCreateInfo multisample = {};
    multisample.sType                                = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisample.rasterizationSamples                 = VK_SAMPLE_COUNT_1_BIT;

    // Additive blending: every execution of the draw call adds the uniform color to the render target
    VkPipelineColorBlendAttachmentState blend_attachment = {};
    blend_attachment.blendEnable                         = VK_TRUE;
    blend_attachment.srcColorBlendFactor                 = VK_BLEND_FACTOR_ONE;
    blend_attachment.dstColorBlendFactor                 = VK_BLEND_FACTOR_ONE;
    blend_attachment.colorBlendOp                        = VK_BLEND_OP_ADD;
    blend_attachment.srcAlphaBlendFactor                 = VK_BLEND_FACTOR_ONE;
    blend_attachment.dstAlphaBlendFactor                 = VK_BLEND_FACTOR_ONE;
    blend_attachment.alphaBlendOp                        = VK_BLEND_OP_ADD;
    blend_attachment.colorWriteMask =
        VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;

    VkPipelineColorBlendStateCreateInfo blend = {};
    blend.sType                               = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    blend.attachmentCount                     = 1;
    blend.pAttachments                        = &blend_attachment;

    VkGraphicsPipelineCreateInfo pipeline_info = {};
    pipeline_info.sType                        = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipeline_info.stageCount                   = 2;
    pipeline_info.pStages                      = stages;
    pipeline_info.pVertexInputState            = &vertex_input;
    pipeline_info.pInputAssemblyState          = &input_assembly;
    pipeline_info.pViewportState               = &viewport_state;
    pipeline_info.pRasterizationState          = &rasterization;
    pipeline_info.pMultisampleState            = &multisample;
    pipeline_info.pColorBlendState             = &blend;
    pipeline_info.layout                       = pipeline_layout_;
    pipeline_info.renderPass                   = render_pass_;
    pipeline_info.subpass                      = 0;
    VERIFY_VK_RESULT(
        "failed to create graphics pipeline",
        init.disp.createGraphicsPipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &graphics_pipeline_));
}

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
    allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    VkCommandBuffer primary;
    result = init.disp.allocateCommandBuffers(&allocate_info, &primary);
    VERIFY_VK_RESULT("failed to allocate primary command buffer", result);

    allocate_info.level = VK_COMMAND_BUFFER_LEVEL_SECONDARY;
    VkCommandBuffer secondary;
    result = init.disp.allocateCommandBuffers(&allocate_info, &secondary);
    VERIFY_VK_RESULT("failed to allocate secondary command buffer", result);

    // The secondary holds the draw call and the state it needs, and continues the render pass of the primary. It
    // is recorded once and executed EXECUTION_COUNT times by the primary, which is what SIMULTANEOUS_USE is required
    // for.
    {
        VkCommandBufferInheritanceInfo inheritance_info = {};
        inheritance_info.sType                          = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;
        inheritance_info.renderPass                     = render_pass_;
        inheritance_info.subpass                        = 0;
        inheritance_info.framebuffer                    = framebuffer_;

        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        begin_info.flags =
            VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT | VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
        begin_info.pInheritanceInfo = &inheritance_info;
        result                      = init.disp.beginCommandBuffer(secondary, &begin_info);
        VERIFY_VK_RESULT("failed to begin secondary command buffer", result);

        init.disp.cmdBindPipeline(secondary, VK_PIPELINE_BIND_POINT_GRAPHICS, graphics_pipeline_);
        init.disp.cmdBindDescriptorSets(
            secondary, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline_layout_, 0, 1, &descriptor_set_, 0, nullptr);
        init.disp.cmdDraw(secondary, 3, 1, 0, 0);

        result = init.disp.endCommandBuffer(secondary);
        VERIFY_VK_RESULT("failed to end secondary command buffer", result);
    }

    {
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        result                              = init.disp.beginCommandBuffer(primary, &begin_info);
        VERIFY_VK_RESULT("failed to begin primary command buffer", result);

        // The test renders offscreen: transition the acquired image straight to PRESENT_SRC so it can be presented.
        {
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
            init.disp.cmdPipelineBarrier(primary,
                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                         VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                         0,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr,
                                         1,
                                         &image_barrier);
        }

        VkClearValue clear_value = {};

        VkRenderPassBeginInfo render_pass_begin = {};
        render_pass_begin.sType                 = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        render_pass_begin.renderPass            = render_pass_;
        render_pass_begin.framebuffer           = framebuffer_;
        render_pass_begin.renderArea            = { { 0, 0 }, { RENDER_TARGET_SIZE, RENDER_TARGET_SIZE } };
        render_pass_begin.clearValueCount       = 1;
        render_pass_begin.pClearValues          = &clear_value;

        // One render pass with every execution in it. Each one is a separate vkCmdExecuteCommands.
        init.disp.cmdBeginRenderPass(primary, &render_pass_begin, VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS);
        for (uint32_t execution = 0; execution < EXECUTION_COUNT; ++execution)
        {
            init.disp.cmdExecuteCommands(primary, 1, &secondary);
        }
        init.disp.cmdEndRenderPass(primary);

        result = init.disp.endCommandBuffer(primary);
        VERIFY_VK_RESULT("failed to end primary command buffer", result);
    }

    VkSubmitInfo submitInfo = {};
    submitInfo.sType        = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore          wait_semaphores[] = { sync_.available_semaphores[current_frame_] };
    VkPipelineStageFlags wait_stages[]     = { VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT };
    submitInfo.waitSemaphoreCount          = 1;
    submitInfo.pWaitSemaphores             = wait_semaphores;
    submitInfo.pWaitDstStageMask           = wait_stages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers    = &primary;

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
        recreate_swapchain(true);
        return frame_num >= NUM_FRAMES;
    }
    VERIFY_VK_RESULT("failed to present queue", result);

    current_frame_ = (current_frame_ + 1) % MAX_FRAMES_IN_FLIGHT;

    return IS_RUNNING(frame_num);
}

void App::cleanup()
{
    init.disp.destroyPipeline(graphics_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
    init.disp.destroyShaderModule(vertex_shader_, nullptr);
    init.disp.destroyShaderModule(fragment_shader_, nullptr);

    init.disp.destroyDescriptorPool(descriptor_pool_, nullptr);
    init.disp.destroyDescriptorSetLayout(descriptor_set_layout_, nullptr);

    init.disp.destroyBuffer(uniform_buffer_, nullptr);
    init.disp.freeMemory(uniform_buffer_memory_, nullptr);

    init.disp.destroyFramebuffer(framebuffer_, nullptr);
    init.disp.destroyRenderPass(render_pass_, nullptr);
    init.disp.destroyImageView(render_target_view_, nullptr);
    init.disp.destroyImage(render_target_, nullptr);
    init.disp.freeMemory(render_target_memory_, nullptr);

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

    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    for (auto& command_pool : command_pools_)
    {
        command_pool = test::create_command_pool(init.disp, *queue_family_index);
    }

    sync_ = test::create_sync_objects(init.swapchain, init.disp, MAX_FRAMES_IN_FLIGHT);

    create_render_target();
    create_uniform_buffer();
    create_descriptor_set();
    create_graphics_pipeline();
    initialize_uniform_buffer();
}

GFXRECON_END_NAMESPACE(secondary_draw_twice)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
