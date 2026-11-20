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

#ifndef GFXRECON_TESTAPP_DRAW_DISPATCH_VDR_H
#define GFXRECON_TESTAPP_DRAW_DISPATCH_VDR_H

#include <test_app_base.h>

#include <application/application.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(test_app)
GFXRECON_BEGIN_NAMESPACE(draw_dispatch_vdr)

const uint32_t     kCounterCount       = 64;
const VkDeviceSize kBufferSize         = kCounterCount * sizeof(uint32_t);
const uint32_t     kCommandBufferCount = 2;  // recorded once, submitted in turn
const uint32_t     kSubmissions        = 10; // frames
const uint32_t     kExtent             = 64;

/**
 * Headless app that generates the DrawDispatch_vdr capture used by the capture based tests of gfxrecon-replay
 * --dump-resources. It exercises a command buffer that is submitted again after it has been dumped.
 *
 * The app records a few command buffers once and submits one of them every frame without re-recording it, the way
 * applications with pre-recorded frames do. Each command buffer holds, in this order:
 *   1. vkCmdCopyBuffer of a 64-counter buffer into a mirror buffer      (a transfer)
 *   2. a render pass with one draw                                       (a draw call)
 *   3. vkCmdDispatch that adds one to every counter                      (a dispatch)
 *   4. a second render pass with one draw                                (a draw call)
 * The counters start at zero and only the dispatch writes them, so after the n-th submission they read n and the
 * mirror reads n - 1. A dump taken after the dispatch of the n-th submission must read n; anything higher means the
 * dispatch ran more than once. The app checks both buffers itself after the last submission and fails if they are
 * off. Rendering goes to an offscreen image, there is no window and no swapchain.
 *
 * Capture (layer manifest from a gfxreconstruct build directory), one command line:
 *   GFXRECON_TESTAPP_HEADLESS=true VK_LAYER_PATH=<build>/layer VK_INSTANCE_LAYERS=VK_LAYER_LUNARG_gfxreconstruct
 *   GFXRECON_CAPTURE_FILE=DrawDispatch_vdr.gfxr GFXRECON_CAPTURE_FILE_TIMESTAMP=false
 *   gfxrecon-test-launcher draw-dispatch-vdr
 *
 * Dump: convert the capture and pick the first vkQueueSubmit that submits a command buffer for the second time.
 * The dump-resources json then names that submit, the vkBeginCommandBuffer of the submitted command buffer and, from
 * its recording, the vkCmdDraw indices, the [vkCmdBeginRenderPass, vkCmdEndRenderPass] pairs, the vkCmdDispatch and
 * the vkCmdCopyBuffer:
 *   gfxrecon-convert --format jsonl --output DrawDispatch_vdr.jsonl DrawDispatch_vdr.gfxr
 *   { "DumpResourcesOptions": { "DumpBeforeCommand": true },
 *     "BeginCommandBuffer": [<bcb>], "QueueSubmit": [<qs>],
 *     "Draw": [[<draw1>, <draw2>]], "RenderPass": [[[<rp1 begin>, <rp1 end>], [<rp2 begin>, <rp2 end>]]],
 *     "Dispatch": [[<dispatch>]], "Transfer": [[<copy>]] }
 *   gfxrecon-replay --dump-resources dump.json --dump-resources-dir out DrawDispatch_vdr.gfxr
 * With N queue submissions before the dumped one, the dispatch's "before" buffer dump reads N in every dword, the
 * "after" dump N + 1 and the transfer dump N. The command buffer is submitted again after the dump, which is what
 * made earlier dump-resources implementations fail: a dispatch clone submitted next to the draw call clones ran the
 * dispatch twice, and snapshot resources freed right after the dump were still referenced by the re-submitted command
 * buffer.
 */
class App : public test::TestAppBase
{
    VkQueue queue_ = VK_NULL_HANDLE;

    // Offscreen color target and its render pass
    VkImage        color_image_  = VK_NULL_HANDLE;
    VkDeviceMemory color_memory_ = VK_NULL_HANDLE;
    VkImageView    color_view_   = VK_NULL_HANDLE;
    VkRenderPass   render_pass_  = VK_NULL_HANDLE;
    VkFramebuffer  framebuffer_  = VK_NULL_HANDLE;

    // Graphics pipeline: a hard-coded triangle, no vertex input, no descriptors
    VkShaderModule   vertex_shader_     = VK_NULL_HANDLE;
    VkShaderModule   fragment_shader_   = VK_NULL_HANDLE;
    VkPipelineLayout graphics_layout_   = VK_NULL_HANDLE;
    VkPipeline       graphics_pipeline_ = VK_NULL_HANDLE;

    // The counters and their mirror
    VkBuffer       counters_        = VK_NULL_HANDLE;
    VkDeviceMemory counters_memory_ = VK_NULL_HANDLE;
    VkBuffer       mirror_          = VK_NULL_HANDLE;
    VkDeviceMemory mirror_memory_   = VK_NULL_HANDLE;

    // Compute pipeline with the counters bound as a storage buffer
    VkShaderModule        compute_shader_   = VK_NULL_HANDLE;
    VkDescriptorSetLayout set_layout_       = VK_NULL_HANDLE;
    VkDescriptorPool      descriptor_pool_  = VK_NULL_HANDLE;
    VkDescriptorSet       descriptor_set_   = VK_NULL_HANDLE;
    VkPipelineLayout      compute_layout_   = VK_NULL_HANDLE;
    VkPipeline            compute_pipeline_ = VK_NULL_HANDLE;

    // The command buffers, recorded once, and one fence for each of them
    VkCommandPool   command_pool_                         = VK_NULL_HANDLE;
    VkCommandBuffer command_buffers_[kCommandBufferCount] = {};
    VkFence         fences_[kCommandBufferCount]          = {};

    VkShaderModule create_shader(const uint32_t* code, size_t size);
    void           create_buffer(VkBufferUsageFlags usage, VkBuffer* buffer, VkDeviceMemory* memory);
    void           create_render_target();
    void           create_graphics_pipeline();
    void           create_buffers();
    void           create_compute_pipeline();
    void           record_command_buffers();
    void           verify_counters();

    void cleanup() override;
    bool frame(const int frame_num) override;
    void setup() override;

    void configure_instance_builder(test::InstanceBuilder& instance_builder, vkmock::TestConfig*) override;
};

GFXRECON_END_NAMESPACE(draw_dispatch_vdr)
GFXRECON_END_NAMESPACE(test_app)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_TESTAPP_DRAW_DISPATCH_VDR_H
