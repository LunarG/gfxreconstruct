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

#include <draw_dispatch_vdr_app.h>

#include <util/logging.h>

#include <cstring>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(draw_dispatch_vdr)

// SPIR-V of the three shaders, compiled with glslangValidator -V --target-env vulkan1.0
//
// vertex:
//   #version 450
//   layout(location = 0) out vec3 color;
//   void main() {
//       const vec2 positions[3] = vec2[](vec2(0.0, -0.5), vec2(0.5, 0.5), vec2(-0.5, 0.5));
//       const vec3 colors[3]    = vec3[](vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(0.0, 0.0, 1.0));
//       gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
//       color       = colors[gl_VertexIndex];
//   }
static const uint32_t kVertexShader[] = {
    0x07230203, 0x00010000, 0x0008000b, 0x00000036, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0008000f, 0x00000000,
    0x00000004, 0x6e69616d, 0x00000000, 0x0000000d, 0x0000001b, 0x0000002a, 0x00030003, 0x00000002, 0x000001c2,
    0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00060005, 0x0000000b, 0x505f6c67, 0x65567265, 0x78657472,
    0x00000000, 0x00060006, 0x0000000b, 0x00000000, 0x505f6c67, 0x7469736f, 0x006e6f69, 0x00070006, 0x0000000b,
    0x00000001, 0x505f6c67, 0x746e696f, 0x657a6953, 0x00000000, 0x00070006, 0x0000000b, 0x00000002, 0x435f6c67,
    0x4470696c, 0x61747369, 0x0065636e, 0x00070006, 0x0000000b, 0x00000003, 0x435f6c67, 0x446c6c75, 0x61747369,
    0x0065636e, 0x00030005, 0x0000000d, 0x00000000, 0x00060005, 0x0000001b, 0x565f6c67, 0x65747265, 0x646e4978,
    0x00007865, 0x00050005, 0x0000001e, 0x65646e69, 0x6c626178, 0x00000065, 0x00040005, 0x0000002a, 0x6f6c6f63,
    0x00000072, 0x00050005, 0x00000032, 0x65646e69, 0x6c626178, 0x00000065, 0x00030047, 0x0000000b, 0x00000002,
    0x00050048, 0x0000000b, 0x00000000, 0x0000000b, 0x00000000, 0x00050048, 0x0000000b, 0x00000001, 0x0000000b,
    0x00000001, 0x00050048, 0x0000000b, 0x00000002, 0x0000000b, 0x00000003, 0x00050048, 0x0000000b, 0x00000003,
    0x0000000b, 0x00000004, 0x00040047, 0x0000001b, 0x0000000b, 0x0000002a, 0x00040047, 0x0000002a, 0x0000001e,
    0x00000000, 0x00020013, 0x00000002, 0x00030021, 0x00000003, 0x00000002, 0x00030016, 0x00000006, 0x00000020,
    0x00040017, 0x00000007, 0x00000006, 0x00000004, 0x00040015, 0x00000008, 0x00000020, 0x00000000, 0x0004002b,
    0x00000008, 0x00000009, 0x00000001, 0x0004001c, 0x0000000a, 0x00000006, 0x00000009, 0x0006001e, 0x0000000b,
    0x00000007, 0x00000006, 0x0000000a, 0x0000000a, 0x00040020, 0x0000000c, 0x00000003, 0x0000000b, 0x0004003b,
    0x0000000c, 0x0000000d, 0x00000003, 0x00040015, 0x0000000e, 0x00000020, 0x00000001, 0x0004002b, 0x0000000e,
    0x0000000f, 0x00000000, 0x00040017, 0x00000010, 0x00000006, 0x00000002, 0x0004002b, 0x00000008, 0x00000011,
    0x00000003, 0x0004001c, 0x00000012, 0x00000010, 0x00000011, 0x0004002b, 0x00000006, 0x00000013, 0x00000000,
    0x0004002b, 0x00000006, 0x00000014, 0xbf000000, 0x0005002c, 0x00000010, 0x00000015, 0x00000013, 0x00000014,
    0x0004002b, 0x00000006, 0x00000016, 0x3f000000, 0x0005002c, 0x00000010, 0x00000017, 0x00000016, 0x00000016,
    0x0005002c, 0x00000010, 0x00000018, 0x00000014, 0x00000016, 0x0006002c, 0x00000012, 0x00000019, 0x00000015,
    0x00000017, 0x00000018, 0x00040020, 0x0000001a, 0x00000001, 0x0000000e, 0x0004003b, 0x0000001a, 0x0000001b,
    0x00000001, 0x00040020, 0x0000001d, 0x00000007, 0x00000012, 0x00040020, 0x0000001f, 0x00000007, 0x00000010,
    0x0004002b, 0x00000006, 0x00000022, 0x3f800000, 0x00040020, 0x00000026, 0x00000003, 0x00000007, 0x00040017,
    0x00000028, 0x00000006, 0x00000003, 0x00040020, 0x00000029, 0x00000003, 0x00000028, 0x0004003b, 0x00000029,
    0x0000002a, 0x00000003, 0x0004001c, 0x0000002b, 0x00000028, 0x00000011, 0x0006002c, 0x00000028, 0x0000002c,
    0x00000022, 0x00000013, 0x00000013, 0x0006002c, 0x00000028, 0x0000002d, 0x00000013, 0x00000022, 0x00000013,
    0x0006002c, 0x00000028, 0x0000002e, 0x00000013, 0x00000013, 0x00000022, 0x0006002c, 0x0000002b, 0x0000002f,
    0x0000002c, 0x0000002d, 0x0000002e, 0x00040020, 0x00000031, 0x00000007, 0x0000002b, 0x00040020, 0x00000033,
    0x00000007, 0x00000028, 0x00050036, 0x00000002, 0x00000004, 0x00000000, 0x00000003, 0x000200f8, 0x00000005,
    0x0004003b, 0x0000001d, 0x0000001e, 0x00000007, 0x0004003b, 0x00000031, 0x00000032, 0x00000007, 0x0004003d,
    0x0000000e, 0x0000001c, 0x0000001b, 0x0003003e, 0x0000001e, 0x00000019, 0x00050041, 0x0000001f, 0x00000020,
    0x0000001e, 0x0000001c, 0x0004003d, 0x00000010, 0x00000021, 0x00000020, 0x00050051, 0x00000006, 0x00000023,
    0x00000021, 0x00000000, 0x00050051, 0x00000006, 0x00000024, 0x00000021, 0x00000001, 0x00070050, 0x00000007,
    0x00000025, 0x00000023, 0x00000024, 0x00000013, 0x00000022, 0x00050041, 0x00000026, 0x00000027, 0x0000000d,
    0x0000000f, 0x0003003e, 0x00000027, 0x00000025, 0x0004003d, 0x0000000e, 0x00000030, 0x0000001b, 0x0003003e,
    0x00000032, 0x0000002f, 0x00050041, 0x00000033, 0x00000034, 0x00000032, 0x00000030, 0x0004003d, 0x00000028,
    0x00000035, 0x00000034, 0x0003003e, 0x0000002a, 0x00000035, 0x000100fd, 0x00010038
};

// fragment:
//   #version 450
//   layout(location = 0) in vec3 color;
//   layout(location = 0) out vec4 out_color;
//   void main() { out_color = vec4(color, 1.0); }
static const uint32_t kFragmentShader[] = {
    0x07230203, 0x00010000, 0x0008000b, 0x00000013, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0007000f, 0x00000004,
    0x00000004, 0x6e69616d, 0x00000000, 0x00000009, 0x0000000c, 0x00030010, 0x00000004, 0x00000007, 0x00030003,
    0x00000002, 0x000001c2, 0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00050005, 0x00000009, 0x5f74756f,
    0x6f6c6f63, 0x00000072, 0x00040005, 0x0000000c, 0x6f6c6f63, 0x00000072, 0x00040047, 0x00000009, 0x0000001e,
    0x00000000, 0x00040047, 0x0000000c, 0x0000001e, 0x00000000, 0x00020013, 0x00000002, 0x00030021, 0x00000003,
    0x00000002, 0x00030016, 0x00000006, 0x00000020, 0x00040017, 0x00000007, 0x00000006, 0x00000004, 0x00040020,
    0x00000008, 0x00000003, 0x00000007, 0x0004003b, 0x00000008, 0x00000009, 0x00000003, 0x00040017, 0x0000000a,
    0x00000006, 0x00000003, 0x00040020, 0x0000000b, 0x00000001, 0x0000000a, 0x0004003b, 0x0000000b, 0x0000000c,
    0x00000001, 0x0004002b, 0x00000006, 0x0000000e, 0x3f800000, 0x00050036, 0x00000002, 0x00000004, 0x00000000,
    0x00000003, 0x000200f8, 0x00000005, 0x0004003d, 0x0000000a, 0x0000000d, 0x0000000c, 0x00050051, 0x00000006,
    0x0000000f, 0x0000000d, 0x00000000, 0x00050051, 0x00000006, 0x00000010, 0x0000000d, 0x00000001, 0x00050051,
    0x00000006, 0x00000011, 0x0000000d, 0x00000002, 0x00070050, 0x00000007, 0x00000012, 0x0000000f, 0x00000010,
    0x00000011, 0x0000000e, 0x0003003e, 0x00000009, 0x00000012, 0x000100fd, 0x00010038
};

// compute:
//   #version 450
//   layout(local_size_x = 64, local_size_y = 1, local_size_z = 1) in;
//   layout(set = 0, binding = 0) buffer Counters { uint values[]; } counters;
//   void main() { counters.values[gl_GlobalInvocationID.x] += 1u; }
static const uint32_t kIncrementShader[] = {
    0x07230203, 0x00010000, 0x0008000b, 0x0000001c, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0006000f, 0x00000005,
    0x00000004, 0x6e69616d, 0x00000000, 0x0000000f, 0x00060010, 0x00000004, 0x00000011, 0x00000040, 0x00000001,
    0x00000001, 0x00030003, 0x00000002, 0x000001c2, 0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00050005,
    0x00000008, 0x6e756f43, 0x73726574, 0x00000000, 0x00050006, 0x00000008, 0x00000000, 0x756c6176, 0x00007365,
    0x00050005, 0x0000000a, 0x6e756f63, 0x73726574, 0x00000000, 0x00080005, 0x0000000f, 0x475f6c67, 0x61626f6c,
    0x766e496c, 0x7461636f, 0x496e6f69, 0x00000044, 0x00040047, 0x00000007, 0x00000006, 0x00000004, 0x00030047,
    0x00000008, 0x00000003, 0x00050048, 0x00000008, 0x00000000, 0x00000023, 0x00000000, 0x00040047, 0x0000000a,
    0x00000021, 0x00000000, 0x00040047, 0x0000000a, 0x00000022, 0x00000000, 0x00040047, 0x0000000f, 0x0000000b,
    0x0000001c, 0x00040047, 0x0000001b, 0x0000000b, 0x00000019, 0x00020013, 0x00000002, 0x00030021, 0x00000003,
    0x00000002, 0x00040015, 0x00000006, 0x00000020, 0x00000000, 0x0003001d, 0x00000007, 0x00000006, 0x0003001e,
    0x00000008, 0x00000007, 0x00040020, 0x00000009, 0x00000002, 0x00000008, 0x0004003b, 0x00000009, 0x0000000a,
    0x00000002, 0x00040015, 0x0000000b, 0x00000020, 0x00000001, 0x0004002b, 0x0000000b, 0x0000000c, 0x00000000,
    0x00040017, 0x0000000d, 0x00000006, 0x00000003, 0x00040020, 0x0000000e, 0x00000001, 0x0000000d, 0x0004003b,
    0x0000000e, 0x0000000f, 0x00000001, 0x0004002b, 0x00000006, 0x00000010, 0x00000000, 0x00040020, 0x00000011,
    0x00000001, 0x00000006, 0x0004002b, 0x00000006, 0x00000014, 0x00000001, 0x00040020, 0x00000015, 0x00000002,
    0x00000006, 0x0004002b, 0x00000006, 0x0000001a, 0x00000040, 0x0006002c, 0x0000000d, 0x0000001b, 0x0000001a,
    0x00000014, 0x00000014, 0x00050036, 0x00000002, 0x00000004, 0x00000000, 0x00000003, 0x000200f8, 0x00000005,
    0x00050041, 0x00000011, 0x00000012, 0x0000000f, 0x00000010, 0x0004003d, 0x00000006, 0x00000013, 0x00000012,
    0x00060041, 0x00000015, 0x00000016, 0x0000000a, 0x0000000c, 0x00000013, 0x0004003d, 0x00000006, 0x00000017,
    0x00000016, 0x00050080, 0x00000006, 0x00000018, 0x00000017, 0x00000014, 0x00060041, 0x00000015, 0x00000019,
    0x0000000a, 0x0000000c, 0x00000013, 0x0003003e, 0x00000019, 0x00000018, 0x000100fd, 0x00010038
};

void App::configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig* test_config)
{
    instance_builder.set_headless(true);
}

VkShaderModule App::create_shader(const uint32_t* code, size_t size)
{
    const char* bytes = reinterpret_cast<const char*>(code);
    return test::createShaderModule(init.disp, std::vector<char>(bytes, bytes + size));
}

void App::create_buffer(VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory)
{
    VkBufferCreateInfo buffer_info = {};
    buffer_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_info.size               = kBufferSize;
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

void App::create_render_target()
{
    VkImageCreateInfo image_info = {};
    image_info.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    image_info.imageType         = VK_IMAGE_TYPE_2D;
    image_info.format            = VK_FORMAT_R8G8B8A8_UNORM;
    image_info.extent            = { kExtent, kExtent, 1 };
    image_info.mipLevels         = 1;
    image_info.arrayLayers       = 1;
    image_info.samples           = VK_SAMPLE_COUNT_1_BIT;
    image_info.tiling            = VK_IMAGE_TILING_OPTIMAL;
    image_info.usage             = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    image_info.initialLayout     = VK_IMAGE_LAYOUT_UNDEFINED;
    VERIFY_VK_RESULT("failed to create color image", init.disp.createImage(&image_info, nullptr, &color_image_));

    VkMemoryRequirements memory_requirements;
    init.disp.getImageMemoryRequirements(color_image_, &memory_requirements);

    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex =
        find_memory_type(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VERIFY_VK_RESULT("failed to allocate color image memory",
                     init.disp.allocateMemory(&allocate_info, nullptr, &color_memory_));
    VERIFY_VK_RESULT("failed to bind color image memory", init.disp.bindImageMemory(color_image_, color_memory_, 0));

    VkImageViewCreateInfo view_info       = {};
    view_info.sType                       = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    view_info.image                       = color_image_;
    view_info.viewType                    = VK_IMAGE_VIEW_TYPE_2D;
    view_info.format                      = image_info.format;
    view_info.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    view_info.subresourceRange.levelCount = 1;
    view_info.subresourceRange.layerCount = 1;
    VERIFY_VK_RESULT("failed to create color image view", init.disp.createImageView(&view_info, nullptr, &color_view_));

    VkAttachmentDescription attachment = {};
    attachment.format                  = image_info.format;
    attachment.samples                 = VK_SAMPLE_COUNT_1_BIT;
    attachment.loadOp                  = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachment.storeOp                 = VK_ATTACHMENT_STORE_OP_STORE;
    attachment.stencilLoadOp           = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachment.stencilStoreOp          = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachment.initialLayout           = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    attachment.finalLayout             = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkAttachmentReference attachment_ref = { 0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL };

    VkSubpassDescription subpass = {};
    subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments    = &attachment_ref;

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
    framebuffer_info.pAttachments            = &color_view_;
    framebuffer_info.width                   = kExtent;
    framebuffer_info.height                  = kExtent;
    framebuffer_info.layers                  = 1;
    VERIFY_VK_RESULT("failed to create framebuffer",
                     init.disp.createFramebuffer(&framebuffer_info, nullptr, &framebuffer_));
}

void App::create_graphics_pipeline()
{
    vertex_shader_   = create_shader(kVertexShader, sizeof(kVertexShader));
    fragment_shader_ = create_shader(kFragmentShader, sizeof(kFragmentShader));

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

    VkViewport viewport = { 0.0f, 0.0f, float(kExtent), float(kExtent), 0.0f, 1.0f };
    VkRect2D   scissor  = { { 0, 0 }, { kExtent, kExtent } };

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
    rasterization.lineWidth                              = 1.0f;

    VkPipelineMultisampleStateCreateInfo multisample = {};
    multisample.sType                                = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisample.rasterizationSamples                 = VK_SAMPLE_COUNT_1_BIT;

    VkPipelineColorBlendAttachmentState blend_attachment = {};
    blend_attachment.colorWriteMask =
        VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;

    VkPipelineColorBlendStateCreateInfo blend = {};
    blend.sType                               = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    blend.attachmentCount                     = 1;
    blend.pAttachments                        = &blend_attachment;

    VkPipelineLayoutCreateInfo layout_info = {};
    layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    VERIFY_VK_RESULT("failed to create graphics pipeline layout",
                     init.disp.createPipelineLayout(&layout_info, nullptr, &graphics_layout_));

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
    pipeline_info.layout                       = graphics_layout_;
    pipeline_info.renderPass                   = render_pass_;
    VERIFY_VK_RESULT(
        "failed to create graphics pipeline",
        init.disp.createGraphicsPipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &graphics_pipeline_));
}

void App::create_buffers()
{
    // The counters start at zero and only the dispatch writes them.
    create_buffer(VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_SRC_BIT, &counters_, &counters_memory_);
    create_buffer(VK_BUFFER_USAGE_TRANSFER_DST_BIT, &mirror_, &mirror_memory_);

    void* data = nullptr;
    VERIFY_VK_RESULT("failed to map counters", init.disp.mapMemory(counters_memory_, 0, kBufferSize, 0, &data));
    memset(data, 0, kBufferSize);
    init.disp.unmapMemory(counters_memory_);
}

void App::create_compute_pipeline()
{
    compute_shader_ = create_shader(kIncrementShader, sizeof(kIncrementShader));

    VkDescriptorSetLayoutBinding binding = {};
    binding.binding                      = 0;
    binding.descriptorType               = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    binding.descriptorCount              = 1;
    binding.stageFlags                   = VK_SHADER_STAGE_COMPUTE_BIT;

    VkDescriptorSetLayoutCreateInfo set_layout_info = {};
    set_layout_info.sType                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    set_layout_info.bindingCount                    = 1;
    set_layout_info.pBindings                       = &binding;
    VERIFY_VK_RESULT("failed to create descriptor set layout",
                     init.disp.createDescriptorSetLayout(&set_layout_info, nullptr, &set_layout_));

    VkDescriptorPoolSize       pool_size = { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, 1 };
    VkDescriptorPoolCreateInfo pool_info = {};
    pool_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.maxSets                    = 1;
    pool_info.poolSizeCount              = 1;
    pool_info.pPoolSizes                 = &pool_size;
    VERIFY_VK_RESULT("failed to create descriptor pool",
                     init.disp.createDescriptorPool(&pool_info, nullptr, &descriptor_pool_));

    VkDescriptorSetAllocateInfo set_allocate_info = {};
    set_allocate_info.sType                       = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    set_allocate_info.descriptorPool              = descriptor_pool_;
    set_allocate_info.descriptorSetCount          = 1;
    set_allocate_info.pSetLayouts                 = &set_layout_;
    VERIFY_VK_RESULT("failed to allocate descriptor set",
                     init.disp.allocateDescriptorSets(&set_allocate_info, &descriptor_set_));

    VkDescriptorBufferInfo buffer_info = { counters_, 0, kBufferSize };
    VkWriteDescriptorSet   write       = {};
    write.sType                        = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write.dstSet                       = descriptor_set_;
    write.descriptorCount              = 1;
    write.descriptorType               = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    write.pBufferInfo                  = &buffer_info;
    init.disp.updateDescriptorSets(1, &write, 0, nullptr);

    VkPipelineLayoutCreateInfo layout_info = {};
    layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    layout_info.setLayoutCount             = 1;
    layout_info.pSetLayouts                = &set_layout_;
    VERIFY_VK_RESULT("failed to create compute pipeline layout",
                     init.disp.createPipelineLayout(&layout_info, nullptr, &compute_layout_));

    VkComputePipelineCreateInfo pipeline_info = {};
    pipeline_info.sType                       = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    pipeline_info.stage.sType                 = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    pipeline_info.stage.stage                 = VK_SHADER_STAGE_COMPUTE_BIT;
    pipeline_info.stage.module                = compute_shader_;
    pipeline_info.stage.pName                 = "main";
    pipeline_info.layout                      = compute_layout_;
    VERIFY_VK_RESULT("failed to create compute pipeline",
                     init.disp.createComputePipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &compute_pipeline_));
}

void App::record_command_buffers()
{
    VkCommandBufferAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocate_info.commandPool                 = command_pool_;
    allocate_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocate_info.commandBufferCount          = kCommandBufferCount;
    VERIFY_VK_RESULT("failed to allocate command buffers",
                     init.disp.allocateCommandBuffers(&allocate_info, command_buffers_));

    for (VkCommandBuffer command_buffer : command_buffers_)
    {
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        VERIFY_VK_RESULT("failed to begin command buffer", init.disp.beginCommandBuffer(command_buffer, &begin_info));

        // The color target into the layout the render pass expects
        VkImageMemoryBarrier image_barrier        = {};
        image_barrier.sType                       = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
        image_barrier.srcAccessMask               = VK_ACCESS_NONE;
        image_barrier.dstAccessMask               = VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
        image_barrier.oldLayout                   = VK_IMAGE_LAYOUT_UNDEFINED;
        image_barrier.newLayout                   = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
        image_barrier.srcQueueFamilyIndex         = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.dstQueueFamilyIndex         = VK_QUEUE_FAMILY_IGNORED;
        image_barrier.image                       = color_image_;
        image_barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        image_barrier.subresourceRange.levelCount = 1;
        image_barrier.subresourceRange.layerCount = 1;
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

        // 1. Transfer: the counters as the previous execution left them go into the mirror
        VkBufferMemoryBarrier buffer_barrier = {};
        buffer_barrier.sType                 = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
        buffer_barrier.srcAccessMask         = VK_ACCESS_SHADER_WRITE_BIT;
        buffer_barrier.dstAccessMask         = VK_ACCESS_TRANSFER_READ_BIT;
        buffer_barrier.srcQueueFamilyIndex   = VK_QUEUE_FAMILY_IGNORED;
        buffer_barrier.dstQueueFamilyIndex   = VK_QUEUE_FAMILY_IGNORED;
        buffer_barrier.buffer                = counters_;
        buffer_barrier.size                  = kBufferSize;
        init.disp.cmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     1,
                                     &buffer_barrier,
                                     0,
                                     nullptr);

        VkBufferCopy copy_region = { 0, 0, kBufferSize };
        init.disp.cmdCopyBuffer(command_buffer, counters_, mirror_, 1, &copy_region);

        buffer_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
        buffer_barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT;
        init.disp.cmdPipelineBarrier(command_buffer,
                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                     VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                     0,
                                     0,
                                     nullptr,
                                     1,
                                     &buffer_barrier,
                                     0,
                                     nullptr);

        VkClearValue          clear_value       = { { { 0.0f, 0.0f, 0.0f, 1.0f } } };
        VkRenderPassBeginInfo render_pass_begin = {};
        render_pass_begin.sType                 = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
        render_pass_begin.renderPass            = render_pass_;
        render_pass_begin.framebuffer           = framebuffer_;
        render_pass_begin.renderArea.extent     = { kExtent, kExtent };
        render_pass_begin.clearValueCount       = 1;
        render_pass_begin.pClearValues          = &clear_value;

        // 2. A draw
        init.disp.cmdBeginRenderPass(command_buffer, &render_pass_begin, VK_SUBPASS_CONTENTS_INLINE);
        init.disp.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphics_pipeline_);
        init.disp.cmdDraw(command_buffer, 3, 1, 0, 0);
        init.disp.cmdEndRenderPass(command_buffer);

        // 3. The dispatch: one added to every counter
        init.disp.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, compute_pipeline_);
        init.disp.cmdBindDescriptorSets(
            command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, compute_layout_, 0, 1, &descriptor_set_, 0, nullptr);
        init.disp.cmdDispatch(command_buffer, 1, 1, 1);

        // 4. Another draw
        init.disp.cmdBeginRenderPass(command_buffer, &render_pass_begin, VK_SUBPASS_CONTENTS_INLINE);
        init.disp.cmdBindPipeline(command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, graphics_pipeline_);
        init.disp.cmdDraw(command_buffer, 3, 1, 0, 0);
        init.disp.cmdEndRenderPass(command_buffer);

        VERIFY_VK_RESULT("failed to end command buffer", init.disp.endCommandBuffer(command_buffer));
    }
}

void App::verify_counters()
{
    VERIFY_VK_RESULT("failed to wait for the device to become idle", init.disp.deviceWaitIdle());

    // Every counter must read the number of submissions, the mirror one less
    uint32_t failures = 0;
    void*    data     = nullptr;

    VERIFY_VK_RESULT("failed to map counters", init.disp.mapMemory(counters_memory_, 0, kBufferSize, 0, &data));
    const uint32_t* values = static_cast<const uint32_t*>(data);
    for (uint32_t i = 0; i < kCounterCount; ++i)
    {
        failures += (values[i] != kSubmissions);
    }
    GFXRECON_WRITE_CONSOLE("counters after %u submissions: %u", kSubmissions, values[0]);
    init.disp.unmapMemory(counters_memory_);

    VERIFY_VK_RESULT("failed to map mirror", init.disp.mapMemory(mirror_memory_, 0, kBufferSize, 0, &data));
    values = static_cast<const uint32_t*>(data);
    for (uint32_t i = 0; i < kCounterCount; ++i)
    {
        failures += (values[i] != kSubmissions - 1);
    }
    GFXRECON_WRITE_CONSOLE("mirror: %u", values[0]);
    init.disp.unmapMemory(mirror_memory_);

    VERIFY_CONDITION("the counters or their mirror do not match the number of submissions", failures == 0);
}

bool App::frame(const int frame_num)
{
    // Wait for the previous submission of this command buffer before submitting it again
    const uint32_t slot = static_cast<uint32_t>(frame_num) % kCommandBufferCount;
    VERIFY_VK_RESULT("failed to wait for fence", init.disp.waitForFences(1, &fences_[slot], VK_TRUE, UINT64_MAX));
    VERIFY_VK_RESULT("failed to reset fence", init.disp.resetFences(1, &fences_[slot]));

    VkSubmitInfo submit_info       = {};
    submit_info.sType              = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffers_[slot];
    VERIFY_VK_RESULT("failed to submit queue", init.disp.queueSubmit(queue_, 1, &submit_info, fences_[slot]));

    if (static_cast<uint32_t>(frame_num) + 1 < kSubmissions)
    {
        return true;
    }

    verify_counters();
    return false;
}

void App::setup()
{
    // The queue runs both the draws and the dispatch
    auto queue_family_index = init.device.get_queue_index(test::QueueType::graphics);
    if (!queue_family_index)
        throw std::runtime_error("could not find graphics queue");
    VERIFY_CONDITION("the graphics queue family does not support compute",
                     (init.device.queue_families[*queue_family_index].queueFlags & VK_QUEUE_COMPUTE_BIT) != 0);

    auto queue = init.device.get_queue(test::QueueType::graphics);
    if (!queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    queue_ = *queue;

    command_pool_ = test::create_command_pool(init.disp, *queue_family_index);

    create_render_target();
    create_graphics_pipeline();
    create_buffers();
    create_compute_pipeline();
    record_command_buffers();

    for (VkFence& fence : fences_)
    {
        VkFenceCreateInfo fence_info = {};
        fence_info.sType             = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fence_info.flags             = VK_FENCE_CREATE_SIGNALED_BIT;
        VERIFY_VK_RESULT("failed to create fence", init.disp.createFence(&fence_info, nullptr, &fence));
    }
}

void App::cleanup()
{
    for (VkFence fence : fences_)
    {
        init.disp.destroyFence(fence, nullptr);
    }
    init.disp.freeCommandBuffers(command_pool_, kCommandBufferCount, command_buffers_);
    init.disp.destroyCommandPool(command_pool_, nullptr);

    init.disp.destroyPipeline(compute_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(compute_layout_, nullptr);
    init.disp.destroyDescriptorPool(descriptor_pool_, nullptr);
    init.disp.destroyDescriptorSetLayout(set_layout_, nullptr);
    init.disp.destroyShaderModule(compute_shader_, nullptr);

    init.disp.destroyBuffer(mirror_, nullptr);
    init.disp.freeMemory(mirror_memory_, nullptr);
    init.disp.destroyBuffer(counters_, nullptr);
    init.disp.freeMemory(counters_memory_, nullptr);

    init.disp.destroyPipeline(graphics_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(graphics_layout_, nullptr);
    init.disp.destroyShaderModule(fragment_shader_, nullptr);
    init.disp.destroyShaderModule(vertex_shader_, nullptr);

    init.disp.destroyFramebuffer(framebuffer_, nullptr);
    init.disp.destroyRenderPass(render_pass_, nullptr);
    init.disp.destroyImageView(color_view_, nullptr);
    init.disp.destroyImage(color_image_, nullptr);
    init.disp.freeMemory(color_memory_, nullptr);
}

GFXRECON_END_NAMESPACE(draw_dispatch_vdr)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
