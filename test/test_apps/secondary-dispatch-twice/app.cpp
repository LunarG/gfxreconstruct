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

#include <secondary_dispatch_twice_app.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(secondary_dispatch_twice)

// SPIR-V (glslangValidator -V) of the compute shader below. One workgroup covers the whole storage buffer: every
// invocation adds the value of the uniform buffer plus its own index to its element, so each execution of the
// dispatch changes every element by a different, known amount.
//
//   #version 450
//
//   layout(local_size_x = 16) in;
//
//   layout(set = 0, binding = 0) buffer Data
//   {
//       uint v[16];
//   } data;
//
//   layout(set = 0, binding = 1) uniform Params
//   {
//       uint add;
//   } params;
//
//   void main()
//   {
//       uint i = gl_GlobalInvocationID.x;
//       data.v[i] += params.add + i;
//   }
static const uint32_t kComputeShaderSpirv[] = {
    0x07230203, 0x00010000, 0x0008000b, 0x00000026, 0x00000000, 0x00020011, 0x00000001, 0x0006000b, 0x00000001,
    0x4c534c47, 0x6474732e, 0x3035342e, 0x00000000, 0x0003000e, 0x00000000, 0x00000001, 0x0006000f, 0x00000005,
    0x00000004, 0x6e69616d, 0x00000000, 0x0000000b, 0x00060010, 0x00000004, 0x00000011, 0x00000010, 0x00000001,
    0x00000001, 0x00030003, 0x00000002, 0x000001c2, 0x00040005, 0x00000004, 0x6e69616d, 0x00000000, 0x00030005,
    0x00000008, 0x00000069, 0x00080005, 0x0000000b, 0x475f6c67, 0x61626f6c, 0x766e496c, 0x7461636f, 0x496e6f69,
    0x00000044, 0x00040005, 0x00000012, 0x61746144, 0x00000000, 0x00040006, 0x00000012, 0x00000000, 0x00000076,
    0x00040005, 0x00000014, 0x61746164, 0x00000000, 0x00040005, 0x00000018, 0x61726150, 0x0000736d, 0x00040006,
    0x00000018, 0x00000000, 0x00646461, 0x00040005, 0x0000001a, 0x61726170, 0x0000736d, 0x00040047, 0x0000000b,
    0x0000000b, 0x0000001c, 0x00040047, 0x00000011, 0x00000006, 0x00000004, 0x00030047, 0x00000012, 0x00000003,
    0x00050048, 0x00000012, 0x00000000, 0x00000023, 0x00000000, 0x00040047, 0x00000014, 0x00000021, 0x00000000,
    0x00040047, 0x00000014, 0x00000022, 0x00000000, 0x00030047, 0x00000018, 0x00000002, 0x00050048, 0x00000018,
    0x00000000, 0x00000023, 0x00000000, 0x00040047, 0x0000001a, 0x00000021, 0x00000001, 0x00040047, 0x0000001a,
    0x00000022, 0x00000000, 0x00040047, 0x00000025, 0x0000000b, 0x00000019, 0x00020013, 0x00000002, 0x00030021,
    0x00000003, 0x00000002, 0x00040015, 0x00000006, 0x00000020, 0x00000000, 0x00040020, 0x00000007, 0x00000007,
    0x00000006, 0x00040017, 0x00000009, 0x00000006, 0x00000003, 0x00040020, 0x0000000a, 0x00000001, 0x00000009,
    0x0004003b, 0x0000000a, 0x0000000b, 0x00000001, 0x0004002b, 0x00000006, 0x0000000c, 0x00000000, 0x00040020,
    0x0000000d, 0x00000001, 0x00000006, 0x0004002b, 0x00000006, 0x00000010, 0x00000010, 0x0004001c, 0x00000011,
    0x00000006, 0x00000010, 0x0003001e, 0x00000012, 0x00000011, 0x00040020, 0x00000013, 0x00000002, 0x00000012,
    0x0004003b, 0x00000013, 0x00000014, 0x00000002, 0x00040015, 0x00000015, 0x00000020, 0x00000001, 0x0004002b,
    0x00000015, 0x00000016, 0x00000000, 0x0003001e, 0x00000018, 0x00000006, 0x00040020, 0x00000019, 0x00000002,
    0x00000018, 0x0004003b, 0x00000019, 0x0000001a, 0x00000002, 0x00040020, 0x0000001b, 0x00000002, 0x00000006,
    0x0004002b, 0x00000006, 0x00000024, 0x00000001, 0x0006002c, 0x00000009, 0x00000025, 0x00000010, 0x00000024,
    0x00000024, 0x00050036, 0x00000002, 0x00000004, 0x00000000, 0x00000003, 0x000200f8, 0x00000005, 0x0004003b,
    0x00000007, 0x00000008, 0x00000007, 0x00050041, 0x0000000d, 0x0000000e, 0x0000000b, 0x0000000c, 0x0004003d,
    0x00000006, 0x0000000f, 0x0000000e, 0x0003003e, 0x00000008, 0x0000000f, 0x0004003d, 0x00000006, 0x00000017,
    0x00000008, 0x00050041, 0x0000001b, 0x0000001c, 0x0000001a, 0x00000016, 0x0004003d, 0x00000006, 0x0000001d,
    0x0000001c, 0x0004003d, 0x00000006, 0x0000001e, 0x00000008, 0x00050080, 0x00000006, 0x0000001f, 0x0000001d,
    0x0000001e, 0x00060041, 0x0000001b, 0x00000020, 0x00000014, 0x00000016, 0x00000017, 0x0004003d, 0x00000006,
    0x00000021, 0x00000020, 0x00050080, 0x00000006, 0x00000022, 0x00000021, 0x0000001f, 0x00060041, 0x0000001b,
    0x00000023, 0x00000014, 0x00000016, 0x00000017, 0x0003003e, 0x00000023, 0x00000022, 0x000100fd, 0x00010038
};

// The storage buffer holds one uint per invocation of the single workgroup the dispatch runs
const uint32_t     ELEMENT_COUNT       = 16;
const VkDeviceSize STORAGE_BUFFER_SIZE = ELEMENT_COUNT * sizeof(uint32_t);

// Params::add. The uniform buffer is filled with it, so its size only has to cover the block.
const uint32_t     ADD_VALUE           = 100;
const VkDeviceSize UNIFORM_BUFFER_SIZE = 16;

// How many times the primary executes the secondary
const uint32_t EXECUTION_COUNT = 2;

const int NUM_FRAMES = 2;
#define IS_RUNNING(frame_num) frame_num < NUM_FRAMES;

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

    // Device-local only: the buffers are initialized on the GPU, so nothing of them goes through host memory
    VkMemoryAllocateInfo allocate_info = {};
    allocate_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocate_info.allocationSize       = memory_requirements.size;
    allocate_info.memoryTypeIndex =
        find_memory_type(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VERIFY_VK_RESULT("failed to allocate buffer memory", init.disp.allocateMemory(&allocate_info, nullptr, memory));

    VERIFY_VK_RESULT("failed to bind buffer memory", init.disp.bindBufferMemory(*buffer, *memory, 0));
}

void App::create_buffers()
{
    create_buffer(STORAGE_BUFFER_SIZE,
                  VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                  &storage_buffer_,
                  &storage_buffer_memory_);
    create_buffer(UNIFORM_BUFFER_SIZE,
                  VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                  &uniform_buffer_,
                  &uniform_buffer_memory_);
}

void App::initialize_buffers()
{
    // One-time GPU-side initialization: the storage buffer starts from zero and the uniform buffer holds ADD_VALUE
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

    init.disp.cmdFillBuffer(command_buffer, storage_buffer_, 0, VK_WHOLE_SIZE, 0);
    init.disp.cmdFillBuffer(command_buffer, uniform_buffer_, 0, VK_WHOLE_SIZE, ADD_VALUE);

    VkMemoryBarrier barrier = {};
    barrier.sType           = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
    barrier.srcAccessMask   = VK_ACCESS_TRANSFER_WRITE_BIT;
    barrier.dstAccessMask   = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT | VK_ACCESS_UNIFORM_READ_BIT;
    init.disp.cmdPipelineBarrier(command_buffer,
                                 VK_PIPELINE_STAGE_TRANSFER_BIT,
                                 VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
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
    VkDescriptorSetLayoutBinding bindings[2] = {};
    bindings[0].binding                      = 0;
    bindings[0].descriptorType               = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    bindings[0].descriptorCount              = 1;
    bindings[0].stageFlags                   = VK_SHADER_STAGE_COMPUTE_BIT;
    bindings[1].binding                      = 1;
    bindings[1].descriptorType               = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    bindings[1].descriptorCount              = 1;
    bindings[1].stageFlags                   = VK_SHADER_STAGE_COMPUTE_BIT;

    VkDescriptorSetLayoutCreateInfo layout_info = {};
    layout_info.sType                           = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layout_info.bindingCount                    = 2;
    layout_info.pBindings                       = bindings;
    VERIFY_VK_RESULT("failed to create descriptor set layout",
                     init.disp.createDescriptorSetLayout(&layout_info, nullptr, &descriptor_set_layout_));

    VkDescriptorPoolSize pool_sizes[2] = {};
    pool_sizes[0].type                 = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    pool_sizes[0].descriptorCount      = 1;
    pool_sizes[1].type                 = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    pool_sizes[1].descriptorCount      = 1;

    VkDescriptorPoolCreateInfo pool_info = {};
    pool_info.sType                      = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.maxSets                    = 1;
    pool_info.poolSizeCount              = 2;
    pool_info.pPoolSizes                 = pool_sizes;
    VERIFY_VK_RESULT("failed to create descriptor pool",
                     init.disp.createDescriptorPool(&pool_info, nullptr, &descriptor_pool_));

    VkDescriptorSetAllocateInfo allocate_info = {};
    allocate_info.sType                       = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocate_info.descriptorPool              = descriptor_pool_;
    allocate_info.descriptorSetCount          = 1;
    allocate_info.pSetLayouts                 = &descriptor_set_layout_;
    VERIFY_VK_RESULT("failed to allocate descriptor set",
                     init.disp.allocateDescriptorSets(&allocate_info, &descriptor_set_));

    VkDescriptorBufferInfo buffer_infos[2] = {};
    buffer_infos[0].buffer                 = storage_buffer_;
    buffer_infos[0].range                  = VK_WHOLE_SIZE;
    buffer_infos[1].buffer                 = uniform_buffer_;
    buffer_infos[1].range                  = VK_WHOLE_SIZE;

    VkWriteDescriptorSet writes[2] = {};
    for (uint32_t binding = 0; binding < 2; ++binding)
    {
        writes[binding].sType           = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        writes[binding].dstSet          = descriptor_set_;
        writes[binding].dstBinding      = binding;
        writes[binding].descriptorCount = 1;
        writes[binding].descriptorType  = bindings[binding].descriptorType;
        writes[binding].pBufferInfo     = &buffer_infos[binding];
    }
    init.disp.updateDescriptorSets(2, writes, 0, nullptr);
}

void App::create_compute_pipeline()
{
    VkShaderModuleCreateInfo shader_module_info = {};
    shader_module_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    shader_module_info.codeSize                 = sizeof(kComputeShaderSpirv);
    shader_module_info.pCode                    = kComputeShaderSpirv;
    VERIFY_VK_RESULT("failed to create compute shader module",
                     init.disp.createShaderModule(&shader_module_info, nullptr, &compute_shader_));

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.setLayoutCount             = 1;
    pipeline_layout_info.pSetLayouts                = &descriptor_set_layout_;
    VERIFY_VK_RESULT("failed to create pipeline layout",
                     init.disp.createPipelineLayout(&pipeline_layout_info, nullptr, &pipeline_layout_));

    VkComputePipelineCreateInfo pipeline_info = {};
    pipeline_info.sType                       = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    pipeline_info.stage.sType                 = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    pipeline_info.stage.stage                 = VK_SHADER_STAGE_COMPUTE_BIT;
    pipeline_info.stage.module                = compute_shader_;
    pipeline_info.stage.pName                 = "main";
    pipeline_info.layout                      = pipeline_layout_;
    VERIFY_VK_RESULT("failed to create compute pipeline",
                     init.disp.createComputePipelines(VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &compute_pipeline_));
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

    // The secondary holds the dispatch and the state it needs. It is recorded once and executed EXECUTION_COUNT
    // times by the primary, which is what SIMULTANEOUS_USE is required for.
    {
        VkCommandBufferInheritanceInfo inheritance_info = {};
        inheritance_info.sType                          = VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO;

        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
        begin_info.pInheritanceInfo         = &inheritance_info;
        result                              = init.disp.beginCommandBuffer(secondary, &begin_info);
        VERIFY_VK_RESULT("failed to begin secondary command buffer", result);

        init.disp.cmdBindPipeline(secondary, VK_PIPELINE_BIND_POINT_COMPUTE, compute_pipeline_);
        init.disp.cmdBindDescriptorSets(
            secondary, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_layout_, 0, 1, &descriptor_set_, 0, nullptr);
        init.disp.cmdDispatch(secondary, 1, 1, 1);

        result = init.disp.endCommandBuffer(secondary);
        VERIFY_VK_RESULT("failed to end secondary command buffer", result);
    }

    {
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType                    = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        result                              = init.disp.beginCommandBuffer(primary, &begin_info);
        VERIFY_VK_RESULT("failed to begin primary command buffer", result);

        // The test does not render: transition the acquired image straight to PRESENT_SRC so it can be presented.
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

        // Every execution updates the storage buffer from what the previous one left, so the executions are
        // serialized with a compute-to-compute barrier. Each one is a separate vkCmdExecuteCommands.
        VkMemoryBarrier barrier = {};
        barrier.sType           = VK_STRUCTURE_TYPE_MEMORY_BARRIER;
        barrier.srcAccessMask   = VK_ACCESS_SHADER_WRITE_BIT;
        barrier.dstAccessMask   = VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT;

        for (uint32_t execution = 0; execution < EXECUTION_COUNT; ++execution)
        {
            init.disp.cmdExecuteCommands(primary, 1, &secondary);
            init.disp.cmdPipelineBarrier(primary,
                                         VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                         VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                         0,
                                         1,
                                         &barrier,
                                         0,
                                         nullptr,
                                         0,
                                         nullptr);
        }

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
    init.disp.destroyPipeline(compute_pipeline_, nullptr);
    init.disp.destroyPipelineLayout(pipeline_layout_, nullptr);
    init.disp.destroyShaderModule(compute_shader_, nullptr);

    init.disp.destroyDescriptorPool(descriptor_pool_, nullptr);
    init.disp.destroyDescriptorSetLayout(descriptor_set_layout_, nullptr);

    init.disp.destroyBuffer(storage_buffer_, nullptr);
    init.disp.freeMemory(storage_buffer_memory_, nullptr);
    init.disp.destroyBuffer(uniform_buffer_, nullptr);
    init.disp.freeMemory(uniform_buffer_memory_, nullptr);

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

    create_buffers();
    create_descriptor_set();
    create_compute_pipeline();
    initialize_buffers();
}

GFXRECON_END_NAMESPACE(secondary_dispatch_twice)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)
