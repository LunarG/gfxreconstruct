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

#include <iostream>

#include <vulkan/vulkan_core.h>

#include <test_app_base.h>

#include <SDL3/SDL_main.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

GFXRECON_BEGIN_NAMESPACE(test_app)

GFXRECON_BEGIN_NAMESPACE(pipeline_binaries)

class App : public gfxrecon::test::TestAppBase
{
  public:
    App() = default;

  private:
    VkPhysicalDeviceDynamicRenderingFeatures  dynamic_rendering_features_;
    VkPhysicalDevicePipelineBinaryFeaturesKHR pipeline_binary_features_;

    VkQueue graphics_queue_;

    VkPipelineLayout pipeline_layout_;
    VkPipeline       graphics_pipeline_;

    void configure_instance_builder(test::InstanceBuilder& instance_builder) override;
    void configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector) override;

    void configure_device_builder(test::DeviceBuilder&        device_builder,
                                  test::PhysicalDevice const& physical_device) override;
    void create_graphics_pipeline();
    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;
};

void App::configure_instance_builder(test::InstanceBuilder& instance_builder)
{
    instance_builder.require_api_version(VK_API_VERSION_1_1);
}

void App::configure_physical_device_selector(test::PhysicalDeviceSelector& phys_device_selector)
{
    phys_device_selector.add_required_extension("VK_KHR_multiview");
    phys_device_selector.add_required_extension("VK_KHR_maintenance2");
    phys_device_selector.add_required_extension("VK_KHR_create_renderpass2");
    phys_device_selector.add_required_extension("VK_KHR_depth_stencil_resolve");
    phys_device_selector.add_required_extension("VK_KHR_dynamic_rendering");
    phys_device_selector.add_required_extension("VK_KHR_maintenance5");
    phys_device_selector.add_required_extension("VK_KHR_pipeline_binary");
}

void App::configure_device_builder(test::DeviceBuilder& device_builder, test::PhysicalDevice const& physical_device)
{
    dynamic_rendering_features_.sType            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES;
    dynamic_rendering_features_.pNext            = nullptr;
    dynamic_rendering_features_.dynamicRendering = VK_TRUE;
    device_builder.add_pNext(&dynamic_rendering_features_);

    pipeline_binary_features_.sType            = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR;
    pipeline_binary_features_.pNext            = nullptr;
    pipeline_binary_features_.pipelineBinaries = VK_TRUE;
    device_builder.add_pNext(&pipeline_binary_features_);
}

void App::create_graphics_pipeline()
{
    auto vert_module = gfxrecon::test::readShaderFromFile(init.disp, "vert.spv");
    auto frag_module = gfxrecon::test::readShaderFromFile(init.disp, "frag.spv");

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
    pipeline_layout_info.setLayoutCount             = 0;
    pipeline_layout_info.pushConstantRangeCount     = 0;

    auto result = init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout_);
    VERIFY_VK_RESULT("failed to create pipeline layout", result);

    std::vector<VkDynamicState> dynamic_states = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };

    VkPipelineDynamicStateCreateInfo dynamic_info = {};
    dynamic_info.sType                            = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamic_info.dynamicStateCount                = static_cast<uint32_t>(dynamic_states.size());
    dynamic_info.pDynamicStates                   = dynamic_states.data();

    VkPipelineCreateFlags2CreateInfoKHR pipeline_create_flags_2_create_info;
    pipeline_create_flags_2_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR;
    pipeline_create_flags_2_create_info.pNext = NULL;
    pipeline_create_flags_2_create_info.flags = VK_PIPELINE_CREATE_2_CAPTURE_DATA_BIT_KHR;

    VkFormat color_format = VK_FORMAT_R8G8B8A8_UNORM;

    VkPipelineRenderingCreateInfo pipeline_rendering_create_info = {};
    pipeline_rendering_create_info.sType                         = VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO;
    pipeline_rendering_create_info.pNext                         = &pipeline_create_flags_2_create_info;
    pipeline_rendering_create_info.colorAttachmentCount          = 1u;
    pipeline_rendering_create_info.pColorAttachmentFormats       = &color_format;

    VkGraphicsPipelineCreateInfo pipeline_info = {};
    pipeline_info.sType                        = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipeline_info.pNext                        = &pipeline_rendering_create_info;
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
    pipeline_info.renderPass                   = VK_NULL_HANDLE;
    pipeline_info.subpass                      = 0;
    pipeline_info.basePipelineHandle           = VK_NULL_HANDLE;

    result = init.disp.createGraphicsPipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &graphics_pipeline_);
    VERIFY_VK_RESULT("failed to create graphics pipeline", result);

    init.disp.destroyShaderModule(frag_module, nullptr);
    init.disp.destroyShaderModule(vert_module, nullptr);
}

bool App::frame(const int frame_num)
{
    VkResult result = VK_SUCCESS;

    VkPipelineBinaryCreateInfoKHR pipeline_binary_create_info;
    pipeline_binary_create_info.sType               = VK_STRUCTURE_TYPE_PIPELINE_BINARY_CREATE_INFO_KHR;
    pipeline_binary_create_info.pNext               = nullptr;
    pipeline_binary_create_info.pKeysAndDataInfo    = nullptr;
    pipeline_binary_create_info.pipeline            = graphics_pipeline_;
    pipeline_binary_create_info.pPipelineCreateInfo = nullptr;

    VkPipelineBinaryHandlesInfoKHR pipeline_binary_handles_info;
    pipeline_binary_handles_info.sType               = VK_STRUCTURE_TYPE_PIPELINE_BINARY_HANDLES_INFO_KHR;
    pipeline_binary_handles_info.pNext               = nullptr;
    pipeline_binary_handles_info.pipelineBinaryCount = 0u;
    pipeline_binary_handles_info.pPipelineBinaries   = nullptr;
    result = init.disp.createPipelineBinariesKHR(&pipeline_binary_create_info, nullptr, &pipeline_binary_handles_info);
    VERIFY_VK_RESULT("failed to get pipeline binary count", result);

    std::vector<VkPipelineBinaryKHR> pipeline_binaries(pipeline_binary_handles_info.pipelineBinaryCount);
    pipeline_binary_handles_info.pPipelineBinaries = pipeline_binaries.data();
    result = init.disp.createPipelineBinariesKHR(&pipeline_binary_create_info, nullptr, &pipeline_binary_handles_info);
    VERIFY_VK_RESULT("failed to create pipeline binaries", result);

    for (uint32_t i = 0; i < pipeline_binary_handles_info.pipelineBinaryCount; ++i)
    {
        VkPipelineBinaryKeyKHR pipeline_binary_key;
        pipeline_binary_key.sType   = VK_STRUCTURE_TYPE_PIPELINE_BINARY_KEY_KHR;
        pipeline_binary_key.pNext   = nullptr;
        pipeline_binary_key.keySize = 0u;

        VkPipelineBinaryDataInfoKHR pipelineBinaryDataInfo;
        pipelineBinaryDataInfo.sType          = VK_STRUCTURE_TYPE_PIPELINE_BINARY_DATA_INFO_KHR;
        pipelineBinaryDataInfo.pNext          = nullptr;
        pipelineBinaryDataInfo.pipelineBinary = pipeline_binaries[i];

        size_t pipelineBinaryDataSize;
        result = init.disp.getPipelineBinaryDataKHR(
            &pipelineBinaryDataInfo, &pipeline_binary_key, &pipelineBinaryDataSize, nullptr);
        VERIFY_VK_RESULT("failed to get pipeline binary data size", result);

        std::vector<uint8_t> binary_data(pipelineBinaryDataSize);
        result = init.disp.getPipelineBinaryDataKHR(
            &pipelineBinaryDataInfo, &pipeline_binary_key, &pipelineBinaryDataSize, binary_data.data());
        VERIFY_VK_RESULT("failed to get pipeline binary data", result);
    }

    VkReleaseCapturedPipelineDataInfoKHR release_captured_pipeline_data_info;
    release_captured_pipeline_data_info.sType    = VK_STRUCTURE_TYPE_RELEASE_CAPTURED_PIPELINE_DATA_INFO_KHR;
    release_captured_pipeline_data_info.pNext    = NULL;
    release_captured_pipeline_data_info.pipeline = graphics_pipeline_;
    result = init.disp.releaseCapturedPipelineDataKHR(&release_captured_pipeline_data_info, nullptr);

    for (uint32_t i = 0; i < pipeline_binary_handles_info.pipelineBinaryCount; ++i)
    {
        init.disp.destroyPipelineBinaryKHR(pipeline_binaries[i], nullptr);
    }

    return false;
}

void App::cleanup()
{
    init.disp.destroyPipeline(graphics_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
}

void App::setup()
{
    auto graphics_queue = init.device.get_queue(gfxrecon::test::QueueType::graphics);
    if (!graphics_queue.has_value())
        throw std::runtime_error("could not get graphics queue");
    graphics_queue_ = *graphics_queue;

    create_graphics_pipeline();
}

GFXRECON_END_NAMESPACE(pipeline_binaries)

GFXRECON_END_NAMESPACE(test_app)

GFXRECON_END_NAMESPACE(gfxrecon)

int main(int argc, char* argv[])
{
    try
    {
        gfxrecon::test_app::pipeline_binaries::App app{};
        app.run("pipeline binaries");
        return 0;
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
        return -1;
    }
}
