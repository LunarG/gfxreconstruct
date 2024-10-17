/*
** Copyright (c) 2019-2020 LunarG, Inc.
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

#include "decode/vulkan_resource_initializer.h"
#include "decode/vulkan_object_info.h"

#include "decode/copy_shaders.h"
#include "decode/decoder_util.h"
#include "util/platform.h"

#include <algorithm>
#include <cassert>
#include <limits>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanResourceInitializer::VulkanResourceInitializer(const VulkanDeviceInfo*                 device_info,
                                                     VkDeviceSize                            max_copy_size,
                                                     const VkPhysicalDeviceMemoryProperties& memory_properties,
                                                     bool                                    have_shader_stencil_write,
                                                     VulkanResourceAllocator*                resource_allocator,
                                                     const encode::VulkanDeviceTable*        device_table) :
    device_(device_info->handle),
    staging_memory_(VK_NULL_HANDLE), staging_memory_data_(0), staging_buffer_(VK_NULL_HANDLE), staging_buffer_data_(0),
    draw_sampler_(VK_NULL_HANDLE), draw_pool_(VK_NULL_HANDLE), draw_set_layout_(VK_NULL_HANDLE),
    draw_set_(VK_NULL_HANDLE), max_copy_size_(max_copy_size), have_shader_stencil_write_(have_shader_stencil_write),
    resource_allocator_(resource_allocator), device_table_(device_table), device_info_(device_info)
{
    assert((device_info != nullptr) && (device_info->handle != VK_NULL_HANDLE) &&
           (memory_properties.memoryTypeCount > 0) && (memory_properties.memoryHeapCount > 0) &&
           (resource_allocator != nullptr) && (device_table != nullptr));

    size_t type_size = memory_properties.memoryTypeCount * sizeof(memory_properties.memoryTypes[0]);
    size_t heap_size = memory_properties.memoryHeapCount * sizeof(memory_properties.memoryHeaps[0]);

    memory_properties_.memoryTypeCount = memory_properties.memoryTypeCount;
    memory_properties_.memoryHeapCount = memory_properties.memoryHeapCount;

    util::platform::MemoryCopy(&memory_properties_.memoryTypes, type_size, &memory_properties.memoryTypes, type_size);
    util::platform::MemoryCopy(&memory_properties_.memoryHeaps, heap_size, &memory_properties.memoryHeaps, heap_size);
}

VulkanResourceInitializer::~VulkanResourceInitializer()
{
    for (const auto& entry : command_exec_objects_)
    {
        device_table_->DestroyCommandPool(device_, entry.second.command_pool, nullptr);
    }

    if (staging_buffer_ != VK_NULL_HANDLE)
    {
        resource_allocator_->DestroyBufferDirect(staging_buffer_, nullptr, staging_buffer_data_);
    }

    if (staging_memory_ != VK_NULL_HANDLE)
    {
        resource_allocator_->FreeMemoryDirect(staging_memory_, nullptr, staging_memory_data_);
    }

    device_table_->DestroySampler(device_, draw_sampler_, nullptr);
    device_table_->DestroyDescriptorPool(device_, draw_pool_, nullptr);
    device_table_->DestroyDescriptorSetLayout(device_, draw_set_layout_, nullptr);
}

VkResult VulkanResourceInitializer::LoadData(VkDeviceSize                          size,
                                             const uint8_t*                        data,
                                             VulkanResourceAllocator::ResourceData allocator_data)
{
    void*    mapped_memory = nullptr;
    VkResult result        = resource_allocator_->MapResourceMemoryDirect(size, 0, &mapped_memory, allocator_data);

    if (result == VK_SUCCESS)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);
        size_t copy_size = static_cast<size_t>(size);
        util::platform::MemoryCopy(mapped_memory, copy_size, data, copy_size);
        resource_allocator_->UnmapResourceMemoryDirect(allocator_data);
    }

    return result;
}

VkResult VulkanResourceInitializer::InitializeBuffer(VkDeviceSize        data_size,
                                                     const uint8_t*      data,
                                                     uint32_t            queue_family_index,
                                                     VkBuffer            buffer,
                                                     VkBufferUsageFlags  usage,
                                                     uint32_t            region_count,
                                                     const VkBufferCopy* regions)
{
    // TODO: handle usage cases without TRANSFER_DST.
    GFXRECON_UNREFERENCED_PARAMETER(usage);

    VkQueue                               queue               = VK_NULL_HANDLE;
    VkCommandBuffer                       command_buffer      = VK_NULL_HANDLE;
    VkDeviceMemory                        staging_memory      = VK_NULL_HANDLE;
    VkBuffer                              staging_buffer      = VK_NULL_HANDLE;
    VulkanResourceAllocator::MemoryData   staging_memory_data = 0;
    VulkanResourceAllocator::ResourceData staging_buffer_data = 0;

    VkResult result = GetCommandExecObjects(queue_family_index, &queue, &command_buffer);

    if (result == VK_SUCCESS)
    {
        result = AcquireInitializedStagingBuffer(
            data_size, data, &staging_memory, &staging_buffer, &staging_memory_data, &staging_buffer_data);

        if (result == VK_SUCCESS)
        {
            result = BeginCommandBuffer(command_buffer);

            if (result == VK_SUCCESS)
            {
                device_table_->CmdCopyBuffer(command_buffer, staging_buffer, buffer, region_count, regions);
                device_table_->EndCommandBuffer(command_buffer);

                result = ExecuteCommandBuffer(queue, command_buffer);
            }

            ReleaseStagingBuffer(staging_memory, staging_buffer, staging_memory_data, staging_buffer_data);
        }
    }

    return result;
}

VkResult VulkanResourceInitializer::InitializeImage(VkDeviceSize             data_size,
                                                    const uint8_t*           data,
                                                    uint32_t                 queue_family_index,
                                                    VkImage                  image,
                                                    VkImageType              type,
                                                    VkFormat                 format,
                                                    const VkExtent3D&        extent,
                                                    VkImageAspectFlagBits    aspect,
                                                    VkSampleCountFlagBits    sample_count,
                                                    VkImageUsageFlags        usage,
                                                    VkImageLayout            initial_layout,
                                                    VkImageLayout            final_layout,
                                                    uint32_t                 layer_count,
                                                    uint32_t                 level_count,
                                                    const VkBufferImageCopy* level_copies)
{
    VkDeviceMemory                        staging_memory      = VK_NULL_HANDLE;
    VkBuffer                              staging_buffer      = VK_NULL_HANDLE;
    VulkanResourceAllocator::MemoryData   staging_memory_data = 0;
    VulkanResourceAllocator::ResourceData staging_buffer_data = 0;

    VkResult result = AcquireInitializedStagingBuffer(
        data_size, data, &staging_memory, &staging_buffer, &staging_memory_data, &staging_buffer_data);

    if (result == VK_SUCCESS)
    {
        result = LoadData(data_size, data, staging_buffer_data);

        if (result == VK_SUCCESS)
        {
            bool use_transfer = ((usage & VK_IMAGE_USAGE_TRANSFER_DST_BIT) == VK_IMAGE_USAGE_TRANSFER_DST_BIT) &&
                                (sample_count == VK_SAMPLE_COUNT_1_BIT);
            bool use_color_write =
                ((usage & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) == VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) &&
                (aspect == VK_IMAGE_ASPECT_COLOR_BIT);
            bool use_depth_write = ((usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) ==
                                    VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) &&
                                   (aspect == VK_IMAGE_ASPECT_DEPTH_BIT);
            bool use_stencil_write = ((usage & VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) ==
                                      VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT) &&
                                     (aspect == VK_IMAGE_ASPECT_STENCIL_BIT) && have_shader_stencil_write_;

            if (!use_transfer && (use_color_write || use_depth_write || use_stencil_write) &&
                (type == VK_IMAGE_TYPE_2D))
            {
                result = PixelShaderImageCopy(queue_family_index,
                                              staging_buffer,
                                              image,
                                              type,
                                              format,
                                              extent,
                                              aspect,
                                              sample_count,
                                              initial_layout,
                                              final_layout,
                                              layer_count,
                                              level_count,
                                              level_copies);
            }
            else
            {
                result = BufferToImageCopy(queue_family_index,
                                           staging_buffer,
                                           image,
                                           format,
                                           aspect,
                                           initial_layout,
                                           final_layout,
                                           layer_count,
                                           level_count,
                                           level_copies);
            }
        }

        ReleaseStagingBuffer(staging_memory, staging_buffer, staging_memory_data, staging_buffer_data);
    }

    return result;
}

VkResult VulkanResourceInitializer::TransitionImage(uint32_t              queue_family_index,
                                                    VkImage               image,
                                                    VkFormat              format,
                                                    VkImageAspectFlagBits aspect,
                                                    VkImageLayout         initial_layout,
                                                    VkImageLayout         final_layout,
                                                    uint32_t              layer_count,
                                                    uint32_t              level_count)
{
    VkQueue         queue          = VK_NULL_HANDLE;
    VkCommandBuffer command_buffer = VK_NULL_HANDLE;

    VkResult result = GetCommandExecObjects(queue_family_index, &queue, &command_buffer);

    if (result == VK_SUCCESS)
    {
        result = BeginCommandBuffer(command_buffer);

        if (result == VK_SUCCESS)
        {
            VkImageLayout      old_layout        = initial_layout;
            VkImageAspectFlags transition_aspect = GetImageTransitionAspect(format, aspect, &old_layout);

            VkImageMemoryBarrier memory_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
            memory_barrier.pNext                           = nullptr;
            memory_barrier.srcAccessMask                   = 0;
            memory_barrier.dstAccessMask                   = 0;
            memory_barrier.oldLayout                       = old_layout;
            memory_barrier.newLayout                       = final_layout;
            memory_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            memory_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            memory_barrier.image                           = image;
            memory_barrier.subresourceRange.aspectMask     = transition_aspect;
            memory_barrier.subresourceRange.baseMipLevel   = 0;
            memory_barrier.subresourceRange.levelCount     = level_count;
            memory_barrier.subresourceRange.baseArrayLayer = 0;
            memory_barrier.subresourceRange.layerCount     = layer_count;

            device_table_->CmdPipelineBarrier(command_buffer,
                                              VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                              VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                              0,
                                              0,
                                              nullptr,
                                              0,
                                              nullptr,
                                              1,
                                              &memory_barrier);

            device_table_->EndCommandBuffer(command_buffer);

            result = ExecuteCommandBuffer(queue, command_buffer);
        }
    }

    return result;
}

VkResult VulkanResourceInitializer::GetCommandExecObjects(uint32_t         queue_family_index,
                                                          VkQueue*         queue,
                                                          VkCommandBuffer* command_buffer)
{
    assert((queue != nullptr) && (command_buffer != nullptr));

    VkResult result = VK_SUCCESS;
    auto     iter   = command_exec_objects_.find(queue_family_index);

    if (iter != command_exec_objects_.end())
    {
        (*queue)          = iter->second.queue;
        (*command_buffer) = iter->second.command_buffer;
    }
    else
    {
        VkCommandPool command_pool = VK_NULL_HANDLE;

        VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
        create_info.pNext                   = nullptr;
        create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        create_info.queueFamilyIndex        = queue_family_index;

        result = device_table_->CreateCommandPool(device_, &create_info, nullptr, &command_pool);

        if (result == VK_SUCCESS)
        {
            VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
            alloc_info.pNext                       = nullptr;
            alloc_info.commandPool                 = command_pool;
            alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
            alloc_info.commandBufferCount          = 1;

            result = device_table_->AllocateCommandBuffers(device_, &alloc_info, command_buffer);

            if (result == VK_SUCCESS)
            {
                *queue = GetDeviceQueue(device_table_, device_info_, queue_family_index, 0);
                command_exec_objects_.emplace(queue_family_index,
                                              CommandExecObjects{ *queue, command_pool, *command_buffer });
            }
            else
            {
                device_table_->DestroyCommandPool(device_, command_pool, nullptr);
            }
        }
    }

    return result;
}

VkResult VulkanResourceInitializer::GetDrawDescriptorObjects(VkSampler*             sampler,
                                                             VkDescriptorSetLayout* set_layout,
                                                             VkDescriptorSet*       set)
{
    assert((sampler != nullptr) && (set_layout != nullptr) && (set != nullptr));

    VkResult result = VK_SUCCESS;

    if (draw_set_ == VK_NULL_HANDLE)
    {
        VkSamplerCreateInfo sampler_info     = { VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO };
        sampler_info.pNext                   = nullptr;
        sampler_info.flags                   = 0;
        sampler_info.magFilter               = VK_FILTER_NEAREST;
        sampler_info.minFilter               = VK_FILTER_NEAREST;
        sampler_info.mipmapMode              = VK_SAMPLER_MIPMAP_MODE_NEAREST;
        sampler_info.addressModeU            = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        sampler_info.addressModeV            = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        sampler_info.addressModeW            = VK_SAMPLER_ADDRESS_MODE_REPEAT;
        sampler_info.mipLodBias              = 0.0f;
        sampler_info.anisotropyEnable        = VK_FALSE;
        sampler_info.maxAnisotropy           = 0.0f;
        sampler_info.compareEnable           = VK_FALSE;
        sampler_info.compareOp               = VK_COMPARE_OP_NEVER;
        sampler_info.minLod                  = 0.0f;
        sampler_info.maxLod                  = 0.0f;
        sampler_info.borderColor             = VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK;
        sampler_info.unnormalizedCoordinates = VK_FALSE;

        result = device_table_->CreateSampler(device_, &sampler_info, nullptr, &draw_sampler_);

        if (result == VK_SUCCESS)
        {
            VkDescriptorPoolSize pool_size[2];
            pool_size[0].type            = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
            pool_size[0].descriptorCount = 1;
            pool_size[1].type            = VK_DESCRIPTOR_TYPE_SAMPLER;
            pool_size[1].descriptorCount = 1;

            VkDescriptorPoolCreateInfo pool_info = { VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO };
            pool_info.pNext                      = nullptr;
            pool_info.flags                      = 0;
            pool_info.maxSets                    = 1;
            pool_info.poolSizeCount              = 2;
            pool_info.pPoolSizes                 = pool_size;

            result = device_table_->CreateDescriptorPool(device_, &pool_info, nullptr, &draw_pool_);
        }

        if (result == VK_SUCCESS)
        {
            VkDescriptorSetLayoutBinding set_binding[2];
            set_binding[0].binding            = 0;
            set_binding[0].descriptorType     = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
            set_binding[0].descriptorCount    = 1;
            set_binding[0].stageFlags         = VK_SHADER_STAGE_FRAGMENT_BIT;
            set_binding[0].pImmutableSamplers = nullptr;
            set_binding[1].binding            = 1;
            set_binding[1].descriptorType     = VK_DESCRIPTOR_TYPE_SAMPLER;
            set_binding[1].descriptorCount    = 1;
            set_binding[1].stageFlags         = VK_SHADER_STAGE_FRAGMENT_BIT;
            set_binding[1].pImmutableSamplers = nullptr;

            VkDescriptorSetLayoutCreateInfo set_layout_info = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO };
            set_layout_info.pNext                           = nullptr;
            set_layout_info.flags                           = 0;
            set_layout_info.bindingCount                    = 2;
            set_layout_info.pBindings                       = set_binding;

            result = device_table_->CreateDescriptorSetLayout(device_, &set_layout_info, nullptr, &draw_set_layout_);
        }

        if (result == VK_SUCCESS)
        {
            VkDescriptorSetAllocateInfo set_info = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO };
            set_info.pNext                       = nullptr;
            set_info.descriptorPool              = draw_pool_;
            set_info.descriptorSetCount          = 1;
            set_info.pSetLayouts                 = &draw_set_layout_;

            result = device_table_->AllocateDescriptorSets(device_, &set_info, &draw_set_);
        }

        if (result != VK_SUCCESS)
        {
            if (draw_sampler_ != VK_NULL_HANDLE)
            {
                device_table_->DestroySampler(device_, draw_sampler_, nullptr);
                draw_sampler_ = VK_NULL_HANDLE;
            }

            if (draw_pool_ != VK_NULL_HANDLE)
            {
                device_table_->DestroyDescriptorPool(device_, draw_pool_, nullptr);
                draw_pool_ = VK_NULL_HANDLE;
            }

            if (draw_set_layout_ != VK_NULL_HANDLE)
            {
                device_table_->DestroyDescriptorSetLayout(device_, draw_set_layout_, nullptr);
                draw_set_layout_ = VK_NULL_HANDLE;
            }
        }
    }

    if (result == VK_SUCCESS)
    {
        assert((draw_sampler_ != VK_NULL_HANDLE) && (draw_set_layout_ != VK_NULL_HANDLE) &&
               (draw_set_ != VK_NULL_HANDLE));

        (*sampler)    = draw_sampler_;
        (*set_layout) = draw_set_layout_;
        (*set)        = draw_set_;
    }

    return result;
}

VkResult VulkanResourceInitializer::CreateDrawObjects(VkFormat              format,
                                                      const VkExtent3D&     extent,
                                                      VkImageAspectFlagBits aspect,
                                                      VkSampleCountFlagBits sample_count,
                                                      VkImageLayout         initial_layout,
                                                      VkImageLayout         final_layout,
                                                      VkDescriptorSetLayout set_layout,
                                                      VkRenderPass*         pass,
                                                      VkPipelineLayout*     pipeline_layout,
                                                      VkPipeline*           pipeline)
{
    assert((set_layout != VK_NULL_HANDLE) && (pass != nullptr) && (pipeline_layout != nullptr) &&
           (pipeline != nullptr));

    VkRenderPass     draw_pass            = VK_NULL_HANDLE;
    VkPipelineLayout draw_pipeline_layout = VK_NULL_HANDLE;
    VkPipeline       draw_pipeline        = VK_NULL_HANDLE;

    VkAttachmentDescription attachment;
    attachment.flags   = 0;
    attachment.format  = format;
    attachment.samples = sample_count;

    if (aspect != VK_IMAGE_ASPECT_STENCIL_BIT)
    {
        attachment.loadOp         = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        attachment.storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
        attachment.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_LOAD;
        attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
    }
    else
    {
        attachment.loadOp         = VK_ATTACHMENT_LOAD_OP_LOAD;
        attachment.storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
        attachment.stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        attachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_STORE;
    }

    attachment.initialLayout = initial_layout;

    if ((final_layout != VK_IMAGE_LAYOUT_UNDEFINED) && (final_layout != VK_IMAGE_LAYOUT_PREINITIALIZED))
    {
        attachment.finalLayout = final_layout;
    }
    else
    {
        attachment.finalLayout = (aspect == VK_IMAGE_ASPECT_COLOR_BIT)
                                     ? VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL
                                     : VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
    }

    VkAttachmentReference reference = { 0, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL };

    VkSubpassDescription subpass;
    subpass.flags                = 0;
    subpass.pipelineBindPoint    = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.inputAttachmentCount = 0;
    subpass.pInputAttachments    = nullptr;

    if (aspect == VK_IMAGE_ASPECT_COLOR_BIT)
    {
        subpass.colorAttachmentCount    = 1;
        subpass.pColorAttachments       = &reference;
        subpass.pDepthStencilAttachment = nullptr;
    }
    else
    {
        reference.layout                = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;
        subpass.colorAttachmentCount    = 0;
        subpass.pColorAttachments       = nullptr;
        subpass.pDepthStencilAttachment = &reference;
    }

    subpass.pResolveAttachments     = nullptr;
    subpass.preserveAttachmentCount = 0;
    subpass.pPreserveAttachments    = nullptr;

    VkRenderPassCreateInfo render_pass_info = { VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO };
    render_pass_info.pNext                  = nullptr;
    render_pass_info.flags                  = 0;
    render_pass_info.attachmentCount        = 1;
    render_pass_info.pAttachments           = &attachment;
    render_pass_info.subpassCount           = 1;
    render_pass_info.pSubpasses             = &subpass;
    render_pass_info.dependencyCount        = 0;
    render_pass_info.pDependencies          = nullptr;

    VkResult result = device_table_->CreateRenderPass(device_, &render_pass_info, nullptr, &draw_pass);

    if (result == VK_SUCCESS)
    {
        VkShaderModule vs_module = VK_NULL_HANDLE;
        VkShaderModule ps_module = VK_NULL_HANDLE;
        std::string    ps_name;

        size_t code_size = sizeof(g_VSMain);
        assert((code_size % 4) == 0);

        VkShaderModuleCreateInfo vs_info = { VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO };
        vs_info.pNext                    = VK_NULL_HANDLE;
        vs_info.flags                    = 0;
        vs_info.codeSize                 = code_size;
        vs_info.pCode                    = reinterpret_cast<const uint32_t*>(g_VSMain);

        result = device_table_->CreateShaderModule(device_, &vs_info, nullptr, &vs_module);

        if (result == VK_SUCCESS)
        {
            const uint32_t* ps_code = nullptr;

            if (aspect == VK_IMAGE_ASPECT_COLOR_BIT)
            {
                ps_name   = "PSMainColor";
                code_size = sizeof(g_PSMainColor);
                ps_code   = reinterpret_cast<const uint32_t*>(g_PSMainColor);
            }
            else if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
            {
                ps_name   = "PSMainDepth";
                code_size = sizeof(g_PSMainDepth);
                ps_code   = reinterpret_cast<const uint32_t*>(g_PSMainDepth);
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_STENCIL_BIT);
                ps_name   = "PSMainStencil";
                code_size = sizeof(g_PSMainStencil);
                ps_code   = reinterpret_cast<const uint32_t*>(g_PSMainStencil);
            }

            assert((code_size % 4) == 0);

            VkShaderModuleCreateInfo ps_info = { VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO };
            ps_info.pNext                    = VK_NULL_HANDLE;
            ps_info.flags                    = 0;
            ps_info.codeSize                 = code_size;
            ps_info.pCode                    = ps_code;

            result = device_table_->CreateShaderModule(device_, &ps_info, nullptr, &ps_module);
        }

        if (result == VK_SUCCESS)
        {
            VkPipelineLayoutCreateInfo pipeline_layout_info = { VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO };
            pipeline_layout_info.pNext                      = nullptr;
            pipeline_layout_info.flags                      = 0;
            pipeline_layout_info.setLayoutCount             = 1;
            pipeline_layout_info.pSetLayouts                = &set_layout;
            pipeline_layout_info.pushConstantRangeCount     = 0;
            pipeline_layout_info.pPushConstantRanges        = nullptr;

            result =
                device_table_->CreatePipelineLayout(device_, &pipeline_layout_info, nullptr, &draw_pipeline_layout);
        }

        if (result == VK_SUCCESS)
        {
            VkPipelineShaderStageCreateInfo stage_infos[2];
            stage_infos[0].sType               = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            stage_infos[0].pNext               = nullptr;
            stage_infos[0].flags               = 0;
            stage_infos[0].stage               = VK_SHADER_STAGE_VERTEX_BIT;
            stage_infos[0].module              = vs_module;
            stage_infos[0].pName               = "VSMain";
            stage_infos[0].pSpecializationInfo = nullptr;
            stage_infos[1].sType               = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
            stage_infos[1].pNext               = nullptr;
            stage_infos[1].flags               = 0;
            stage_infos[1].stage               = VK_SHADER_STAGE_FRAGMENT_BIT;
            stage_infos[1].module              = ps_module;
            stage_infos[1].pName               = ps_name.c_str();
            stage_infos[1].pSpecializationInfo = nullptr;

            VkPipelineVertexInputStateCreateInfo vertex_state_info = {
                VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO
            };
            vertex_state_info.pNext                           = nullptr;
            vertex_state_info.flags                           = 0;
            vertex_state_info.vertexBindingDescriptionCount   = 0;
            vertex_state_info.pVertexBindingDescriptions      = nullptr;
            vertex_state_info.vertexAttributeDescriptionCount = 0;
            vertex_state_info.pVertexAttributeDescriptions    = nullptr;

            VkPipelineInputAssemblyStateCreateInfo input_assembly_info = {
                VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO
            };
            input_assembly_info.pNext                  = nullptr;
            input_assembly_info.flags                  = 0;
            input_assembly_info.topology               = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
            input_assembly_info.primitiveRestartEnable = VK_FALSE;

            VkViewport viewport     = { 0.0f, 0.0f, static_cast<float>(extent.width), static_cast<float>(extent.height),
                                        0.0f, 1.0f };
            VkRect2D   scissor_rect = { { 0, 0 }, { extent.width, extent.height } };

            VkPipelineViewportStateCreateInfo viewport_info = { VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO };
            viewport_info.pNext                             = nullptr;
            viewport_info.flags                             = 0;
            viewport_info.viewportCount                     = 1;
            viewport_info.pViewports                        = &viewport;
            viewport_info.scissorCount                      = 1;
            viewport_info.pScissors                         = &scissor_rect;

            VkPipelineRasterizationStateCreateInfo rs_info = {
                VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO
            };
            rs_info.pNext                   = nullptr;
            rs_info.flags                   = 0;
            rs_info.depthClampEnable        = VK_FALSE;
            rs_info.rasterizerDiscardEnable = VK_FALSE;
            rs_info.polygonMode             = VK_POLYGON_MODE_FILL;
            rs_info.cullMode                = VK_CULL_MODE_FRONT_BIT;
            rs_info.frontFace               = VK_FRONT_FACE_COUNTER_CLOCKWISE;
            rs_info.depthBiasEnable         = VK_FALSE;
            rs_info.depthBiasConstantFactor = 0.0f;
            rs_info.depthBiasClamp          = 0.0f;
            rs_info.depthBiasSlopeFactor    = 0.0f;
            rs_info.lineWidth               = 1.0f;

            VkPipelineMultisampleStateCreateInfo ms_info = { VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO };
            ms_info.pNext                                = nullptr;
            ms_info.flags                                = 0;
            ms_info.rasterizationSamples                 = sample_count;
            ms_info.sampleShadingEnable                  = VK_FALSE;
            ms_info.minSampleShading                     = 0.0f;
            ms_info.pSampleMask                          = nullptr;
            ms_info.alphaToCoverageEnable                = VK_FALSE;
            ms_info.alphaToOneEnable                     = VK_FALSE;

            VkPipelineDepthStencilStateCreateInfo ds_info = {
                VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO
            };
            ds_info.pNext                 = nullptr;
            ds_info.flags                 = 0;
            ds_info.depthCompareOp        = VK_COMPARE_OP_ALWAYS;
            ds_info.depthBoundsTestEnable = VK_FALSE;
            ds_info.minDepthBounds        = 0.0f;
            ds_info.maxDepthBounds        = 0.0f;

            if (aspect != VK_IMAGE_ASPECT_STENCIL_BIT)
            {
                ds_info.depthTestEnable   = VK_TRUE;
                ds_info.depthWriteEnable  = VK_TRUE;
                ds_info.stencilTestEnable = VK_FALSE;
            }
            else
            {
                ds_info.depthTestEnable   = VK_FALSE;
                ds_info.depthWriteEnable  = VK_FALSE;
                ds_info.stencilTestEnable = VK_TRUE;

                ds_info.front.failOp      = VK_STENCIL_OP_REPLACE;
                ds_info.front.passOp      = VK_STENCIL_OP_REPLACE;
                ds_info.front.depthFailOp = VK_STENCIL_OP_REPLACE;
                ds_info.front.compareOp   = VK_COMPARE_OP_ALWAYS;
                ds_info.front.compareMask = 0xffffffff;
                ds_info.front.writeMask   = 0xffffffff;
                ds_info.front.reference   = 1;

                ds_info.back = ds_info.front;
            }

            VkPipelineColorBlendAttachmentState bs_attachment = {};
            bs_attachment.blendEnable                         = VK_FALSE;
            bs_attachment.colorWriteMask                      = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT |
                                           VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;

            VkPipelineColorBlendStateCreateInfo bs_info = { VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO };
            bs_info.pNext                               = nullptr;
            bs_info.flags                               = 0;
            bs_info.logicOpEnable                       = VK_FALSE;
            bs_info.logicOp                             = VK_LOGIC_OP_NO_OP;
            bs_info.attachmentCount                     = 1;
            bs_info.pAttachments                        = &bs_attachment;
            bs_info.blendConstants[0]                   = 0.0f;
            bs_info.blendConstants[1]                   = 0.0f;
            bs_info.blendConstants[2]                   = 0.0f;
            bs_info.blendConstants[3]                   = 0.0f;

            VkDynamicState                   dyn_state[] = { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };
            VkPipelineDynamicStateCreateInfo dyn_info    = { VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO };
            dyn_info.pNext                               = nullptr;
            dyn_info.flags                               = 0;
            dyn_info.dynamicStateCount                   = 2;
            dyn_info.pDynamicStates                      = dyn_state;

            VkGraphicsPipelineCreateInfo pipeline_info = { VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO };
            pipeline_info.pNext                        = nullptr;
            pipeline_info.flags                        = 0;
            pipeline_info.stageCount                   = 2;
            pipeline_info.pStages                      = stage_infos;
            pipeline_info.pVertexInputState            = &vertex_state_info;
            pipeline_info.pInputAssemblyState          = &input_assembly_info;
            pipeline_info.pTessellationState           = nullptr;
            pipeline_info.pViewportState               = &viewport_info;
            pipeline_info.pRasterizationState          = &rs_info;
            pipeline_info.pMultisampleState            = &ms_info;
            pipeline_info.pDepthStencilState           = &ds_info;
            pipeline_info.pColorBlendState             = &bs_info;
            pipeline_info.pDynamicState                = &dyn_info;
            pipeline_info.layout                       = draw_pipeline_layout;
            pipeline_info.renderPass                   = draw_pass;
            pipeline_info.subpass                      = 0;
            pipeline_info.basePipelineHandle           = VK_NULL_HANDLE;
            pipeline_info.basePipelineIndex            = -1;

            result = device_table_->CreateGraphicsPipelines(
                device_, VK_NULL_HANDLE, 1, &pipeline_info, nullptr, &draw_pipeline);
        }

        device_table_->DestroyShaderModule(device_, ps_module, nullptr);
        device_table_->DestroyShaderModule(device_, vs_module, nullptr);
    }

    if (result == VK_SUCCESS)
    {
        (*pass)            = draw_pass;
        (*pipeline_layout) = draw_pipeline_layout;
        (*pipeline)        = draw_pipeline;
    }
    else
    {
        DestroyDrawObjects(draw_pass, draw_pipeline_layout, draw_pipeline);
    }

    return result;
}

void VulkanResourceInitializer::DestroyDrawObjects(VkRenderPass     pass,
                                                   VkPipelineLayout pipeline_layout,
                                                   VkPipeline       pipeline)
{
    device_table_->DestroyPipeline(device_, pipeline, nullptr);
    device_table_->DestroyPipelineLayout(device_, pipeline_layout, nullptr);
    device_table_->DestroyRenderPass(device_, pass, nullptr);
}

VkResult VulkanResourceInitializer::CreateStagingImage(const VkImageCreateInfo*               image_create_info,
                                                       VkDeviceMemory*                        memory,
                                                       VkImage*                               image,
                                                       VulkanResourceAllocator::MemoryData*   allocator_memory_data,
                                                       VulkanResourceAllocator::ResourceData* allocator_image_data)
{
    assert((memory != nullptr) && (image != nullptr) && (allocator_memory_data != nullptr) &&
           (allocator_image_data != nullptr));

    VkImage                               staging_image      = VK_NULL_HANDLE;
    VulkanResourceAllocator::ResourceData staging_image_data = 0;

    VkResult result =
        resource_allocator_->CreateImageDirect(image_create_info, nullptr, &staging_image, &staging_image_data);

    if (result == VK_SUCCESS)
    {
        VkDeviceMemory                      staging_memory      = VK_NULL_HANDLE;
        VulkanResourceAllocator::MemoryData staging_memory_data = 0;
        VkMemoryRequirements                memory_reqs;

        device_table_->GetImageMemoryRequirements(device_, staging_image, &memory_reqs);

        uint32_t memory_type_index =
            GetMemoryTypeIndex(memory_reqs.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);

        assert(memory_type_index != std::numeric_limits<uint32_t>::max());

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.pNext                = nullptr;
        alloc_info.memoryTypeIndex      = memory_type_index;
        alloc_info.allocationSize       = memory_reqs.size;

        result = resource_allocator_->AllocateMemoryDirect(&alloc_info, nullptr, &staging_memory, &staging_memory_data);

        if (result == VK_SUCCESS)
        {
            VkMemoryPropertyFlags flags;
            result = resource_allocator_->BindImageMemoryDirect(
                staging_image, staging_memory, 0, staging_image_data, staging_memory_data, &flags);
        }

        if (result == VK_SUCCESS)
        {
            (*memory)                = staging_memory;
            (*image)                 = staging_image;
            (*allocator_memory_data) = staging_memory_data;
            (*allocator_image_data)  = staging_image_data;
        }
        else
        {
            DestroyStagingImage(staging_memory, staging_image, staging_memory_data, staging_image_data);
        }
    }

    return result;
}

void VulkanResourceInitializer::DestroyStagingImage(VkDeviceMemory                        memory,
                                                    VkImage                               image,
                                                    VulkanResourceAllocator::MemoryData   allocator_memory_data,
                                                    VulkanResourceAllocator::ResourceData allocator_image_data)
{
    if (image != VK_NULL_HANDLE)
    {
        resource_allocator_->DestroyImageDirect(image, nullptr, allocator_image_data);
    }

    if (memory != VK_NULL_HANDLE)
    {
        resource_allocator_->FreeMemoryDirect(memory, nullptr, allocator_memory_data);
    }
}

VkResult VulkanResourceInitializer::CreateFramebufferResources(const VkImageViewCreateInfo* view_create_info,
                                                               uint32_t                     width,
                                                               uint32_t                     height,
                                                               VkRenderPass                 render_pass,
                                                               VkImageView*                 view,
                                                               VkFramebuffer*               framebuffer)
{
    assert((view != nullptr) && (framebuffer != nullptr));

    VkImageView image_view = VK_NULL_HANDLE;
    VkResult    result     = device_table_->CreateImageView(device_, view_create_info, nullptr, &image_view);

    if (result == VK_SUCCESS)
    {
        VkFramebufferCreateInfo framebuffer_info = { VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO };
        framebuffer_info.pNext                   = nullptr;
        framebuffer_info.flags                   = 0;
        framebuffer_info.renderPass              = render_pass;
        framebuffer_info.attachmentCount         = 1;
        framebuffer_info.pAttachments            = &image_view;
        framebuffer_info.width                   = width;
        framebuffer_info.height                  = height;
        framebuffer_info.layers                  = 1;

        result = device_table_->CreateFramebuffer(device_, &framebuffer_info, nullptr, framebuffer);

        if (result == VK_SUCCESS)
        {
            (*view) = image_view;
        }
        else
        {
            device_table_->DestroyImageView(device_, image_view, nullptr);
        }
    }

    return result;
}

void VulkanResourceInitializer::DestroyFramebufferResources(VkImageView view, VkFramebuffer framebuffer)
{
    device_table_->DestroyFramebuffer(device_, framebuffer, nullptr);
    device_table_->DestroyImageView(device_, view, nullptr);
}

VkResult VulkanResourceInitializer::AcquireStagingBuffer(VkDeviceMemory*                        memory,
                                                         VkBuffer*                              buffer,
                                                         VkDeviceSize                           size,
                                                         VulkanResourceAllocator::MemoryData*   allocator_memory_data,
                                                         VulkanResourceAllocator::ResourceData* allocator_buffer_data)
{
    assert((memory != nullptr) && (buffer != nullptr) && (size > 0) && (allocator_memory_data != nullptr) &&
           (allocator_buffer_data != nullptr));

    VkResult result = VK_SUCCESS;

    // Create the reusable staging_buffer_ object, with size equal to max_copy_size_, on first acquire, if the requested
    // size is less than or equal to max_copy_size_.  It the requested size is larger than max_copy_size_, create a
    // temporary staging buffer that will be destroyed on release.
    if ((staging_buffer_ == VK_NULL_HANDLE) || (size > max_copy_size_))
    {
        VkBuffer                              staging_buffer      = VK_NULL_HANDLE;
        VulkanResourceAllocator::ResourceData staging_buffer_data = 0;

        VkBufferCreateInfo create_info    = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
        create_info.pNext                 = nullptr;
        create_info.flags                 = 0;
        create_info.size                  = std::max(size, max_copy_size_);
        create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
        create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
        create_info.queueFamilyIndexCount = 0;
        create_info.pQueueFamilyIndices   = nullptr;

        result = resource_allocator_->CreateBufferDirect(&create_info, nullptr, &staging_buffer, &staging_buffer_data);

        if (result == VK_SUCCESS)
        {
            VkMemoryRequirements memory_requirements;
            device_table_->GetBufferMemoryRequirements(device_, staging_buffer, &memory_requirements);

            uint32_t memory_type_index =
                GetMemoryTypeIndex(memory_requirements.memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);

            assert(memory_type_index != std::numeric_limits<uint32_t>::max());

            // Allocate the memory for the buffer.
            VkDeviceMemory                      staging_memory      = VK_NULL_HANDLE;
            VulkanResourceAllocator::MemoryData staging_memory_data = 0;

            VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
            alloc_info.pNext                = nullptr;
            alloc_info.allocationSize       = memory_requirements.size;
            alloc_info.memoryTypeIndex      = memory_type_index;

            result =
                resource_allocator_->AllocateMemoryDirect(&alloc_info, nullptr, &staging_memory, &staging_memory_data);

            if (result == VK_SUCCESS)
            {
                VkMemoryPropertyFlags flags;
                result = resource_allocator_->BindBufferMemoryDirect(
                    staging_buffer, staging_memory, 0, staging_buffer_data, staging_memory_data, &flags);
            }

            if (result == VK_SUCCESS)
            {
                (*memory)                = staging_memory;
                (*buffer)                = staging_buffer;
                (*allocator_memory_data) = staging_memory_data;
                (*allocator_buffer_data) = staging_buffer_data;

                if (size <= max_copy_size_)
                {
                    staging_memory_      = staging_memory;
                    staging_buffer_      = staging_buffer;
                    staging_memory_data_ = staging_memory_data;
                    staging_buffer_data_ = staging_buffer_data;
                }
            }
            else
            {
                resource_allocator_->DestroyBufferDirect(staging_buffer, nullptr, staging_buffer_data);

                if ((*memory) != VK_NULL_HANDLE)
                {
                    resource_allocator_->FreeMemoryDirect(staging_memory, nullptr, staging_memory_data);
                }
            }
        }
    }
    else
    {
        (*memory)                = staging_memory_;
        (*buffer)                = staging_buffer_;
        (*allocator_memory_data) = staging_memory_data_;
        (*allocator_buffer_data) = staging_buffer_data_;
    }

    return result;
}

VkResult
VulkanResourceInitializer::AcquireInitializedStagingBuffer(VkDeviceSize                           data_size,
                                                           const uint8_t*                         data,
                                                           VkDeviceMemory*                        staging_memory,
                                                           VkBuffer*                              staging_buffer,
                                                           VulkanResourceAllocator::MemoryData*   staging_memory_data,
                                                           VulkanResourceAllocator::ResourceData* staging_buffer_data)
{
    VkResult result =
        AcquireStagingBuffer(staging_memory, staging_buffer, data_size, staging_memory_data, staging_buffer_data);

    if (result == VK_SUCCESS)
    {
        assert((staging_memory != nullptr) && (staging_memory_data != nullptr));

        result = LoadData(data_size, data, *staging_buffer_data);
    }

    return result;
}

void VulkanResourceInitializer::ReleaseStagingBuffer(VkDeviceMemory                        memory,
                                                     VkBuffer                              buffer,
                                                     VulkanResourceAllocator::MemoryData   staging_memory_data,
                                                     VulkanResourceAllocator::ResourceData staging_buffer_data)
{
    if (buffer != staging_buffer_)
    {
        if (buffer != VK_NULL_HANDLE)
        {
            resource_allocator_->DestroyBufferDirect(buffer, nullptr, staging_buffer_data);
        }

        if (memory != VK_NULL_HANDLE)
        {
            resource_allocator_->FreeMemoryDirect(memory, nullptr, staging_memory_data);
        }
    }
}

void VulkanResourceInitializer::UpdateDrawDescriptorSet(VkDescriptorSet set, VkImageView view, VkSampler sampler)
{
    VkDescriptorImageInfo image_write_info;
    image_write_info.sampler     = sampler;
    image_write_info.imageView   = view;
    image_write_info.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;

    VkWriteDescriptorSet write_set[2];
    write_set[0].sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write_set[0].pNext            = nullptr;
    write_set[0].dstSet           = set;
    write_set[0].dstBinding       = 0;
    write_set[0].dstArrayElement  = 0;
    write_set[0].descriptorCount  = 1;
    write_set[0].descriptorType   = VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE;
    write_set[0].pImageInfo       = &image_write_info;
    write_set[0].pBufferInfo      = nullptr;
    write_set[0].pTexelBufferView = nullptr;
    write_set[1].sType            = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
    write_set[1].pNext            = nullptr;
    write_set[1].dstSet           = set;
    write_set[1].dstBinding       = 1;
    write_set[1].dstArrayElement  = 0;
    write_set[1].descriptorCount  = 1;
    write_set[1].descriptorType   = VK_DESCRIPTOR_TYPE_SAMPLER;
    write_set[1].pImageInfo       = &image_write_info;
    write_set[1].pBufferInfo      = nullptr;
    write_set[1].pTexelBufferView = nullptr;

    device_table_->UpdateDescriptorSets(device_, 2, write_set, 0, nullptr);
}

VkResult VulkanResourceInitializer::BeginCommandBuffer(VkCommandBuffer command_buffer)
{
    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.pNext                    = nullptr;
    begin_info.flags                    = 0;
    begin_info.pInheritanceInfo         = nullptr;

    return device_table_->BeginCommandBuffer(command_buffer, &begin_info);
}

VkResult VulkanResourceInitializer::ExecuteCommandBuffer(VkQueue queue, VkCommandBuffer command_buffer)
{
    VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = 0;
    submit_info.pWaitSemaphores      = nullptr;
    submit_info.pWaitDstStageMask    = nullptr;
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &command_buffer;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

    VkResult result = device_table_->QueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);

    if (result == VK_SUCCESS)
    {
        result = device_table_->QueueWaitIdle(queue);
    }

    return result;
}

VkImageAspectFlags VulkanResourceInitializer::GetImageTransitionAspect(VkFormat              format,
                                                                       VkImageAspectFlagBits aspect,
                                                                       VkImageLayout*        old_layout)
{
    VkImageAspectFlags transition_aspect = aspect;

    if ((transition_aspect == VK_IMAGE_ASPECT_DEPTH_BIT) || (transition_aspect == VK_IMAGE_ASPECT_STENCIL_BIT))
    {
        // Depth and stencil aspects need to be transitioned together, so get full aspect
        // mask for a combined depth-stencil image.
        if ((format == VK_FORMAT_D16_UNORM_S8_UINT) || (format == VK_FORMAT_D24_UNORM_S8_UINT) ||
            (format == VK_FORMAT_D32_SFLOAT_S8_UINT))
        {
            transition_aspect = VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;

            if (old_layout != nullptr)
            {
                // The same depth-stencil image will be processed twice (once for each aspect), and will no longer have
                // the expected initial layout on the second transition.
                (*old_layout) = VK_IMAGE_LAYOUT_UNDEFINED;
            }
        }
    }

    return transition_aspect;
}

uint32_t VulkanResourceInitializer::GetMemoryTypeIndex(uint32_t type_bits, VkMemoryPropertyFlags property_flags)
{
    uint32_t memory_type_index = std::numeric_limits<uint32_t>::max();

    for (uint32_t i = 0; i < memory_properties_.memoryTypeCount; ++i)
    {
        if ((type_bits & (1 << i)) &&
            ((memory_properties_.memoryTypes[i].propertyFlags & property_flags) == property_flags))
        {
            memory_type_index = i;
            break;
        }
    }

    return memory_type_index;
}

VkResult VulkanResourceInitializer::BufferToImageCopy(uint32_t                 queue_family_index,
                                                      VkBuffer                 source,
                                                      VkImage                  destination,
                                                      VkFormat                 format,
                                                      VkImageAspectFlagBits    aspect,
                                                      VkImageLayout            initial_layout,
                                                      VkImageLayout            final_layout,
                                                      uint32_t                 layer_count,
                                                      uint32_t                 level_count,
                                                      const VkBufferImageCopy* level_copies)
{
    VkQueue         queue          = VK_NULL_HANDLE;
    VkCommandBuffer command_buffer = VK_NULL_HANDLE;

    VkResult result = GetCommandExecObjects(queue_family_index, &queue, &command_buffer);

    if (result == VK_SUCCESS)
    {
        VkImageLayout      old_layout        = initial_layout;
        VkImageAspectFlags transition_aspect = GetImageTransitionAspect(format, aspect, &old_layout);

        result = BeginCommandBuffer(command_buffer);

        if (result == VK_SUCCESS)
        {
            VkImageMemoryBarrier memory_barrier            = { VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER };
            memory_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
            memory_barrier.pNext                           = nullptr;
            memory_barrier.srcAccessMask                   = 0;
            memory_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_WRITE_BIT;
            memory_barrier.oldLayout                       = old_layout;
            memory_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
            memory_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            memory_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
            memory_barrier.image                           = destination;
            memory_barrier.subresourceRange.aspectMask     = transition_aspect;
            memory_barrier.subresourceRange.baseMipLevel   = 0;
            memory_barrier.subresourceRange.levelCount     = level_count;
            memory_barrier.subresourceRange.baseArrayLayer = 0;
            memory_barrier.subresourceRange.layerCount     = layer_count;

            device_table_->CmdPipelineBarrier(command_buffer,
                                              VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                              VK_PIPELINE_STAGE_TRANSFER_BIT,
                                              0,
                                              0,
                                              nullptr,
                                              0,
                                              nullptr,
                                              1,
                                              &memory_barrier);

            device_table_->CmdCopyBufferToImage(
                command_buffer, source, destination, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, level_count, level_copies);

            if ((final_layout != VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) && (final_layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                (final_layout != VK_IMAGE_LAYOUT_PREINITIALIZED))
            {
                memory_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
                memory_barrier.dstAccessMask = 0;
                memory_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                memory_barrier.newLayout     = final_layout;

                device_table_->CmdPipelineBarrier(command_buffer,
                                                  VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                  VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                  0,
                                                  0,
                                                  nullptr,
                                                  0,
                                                  nullptr,
                                                  1,
                                                  &memory_barrier);
            }

            device_table_->EndCommandBuffer(command_buffer);

            result = ExecuteCommandBuffer(queue, command_buffer);
        }
    }

    return result;
}

VkResult VulkanResourceInitializer::PixelShaderImageCopy(uint32_t                 queue_family_index,
                                                         VkBuffer                 source,
                                                         VkImage                  destination,
                                                         VkImageType              type,
                                                         VkFormat                 format,
                                                         const VkExtent3D&        extent,
                                                         VkImageAspectFlagBits    aspect,
                                                         VkSampleCountFlagBits    sample_count,
                                                         VkImageLayout            initial_layout,
                                                         VkImageLayout            final_layout,
                                                         uint32_t                 layer_count,
                                                         uint32_t                 level_count,
                                                         const VkBufferImageCopy* level_copies)
{
    VkQueue               queue          = VK_NULL_HANDLE;
    VkCommandBuffer       command_buffer = VK_NULL_HANDLE;
    VkSampler             sampler        = VK_NULL_HANDLE;
    VkDescriptorSetLayout set_layout     = VK_NULL_HANDLE;
    VkDescriptorSet       set            = VK_NULL_HANDLE;

    VkResult result = GetCommandExecObjects(queue_family_index, &queue, &command_buffer);

    if (result == VK_SUCCESS)
    {
        result = GetDrawDescriptorObjects(&sampler, &set_layout, &set);
    }

    if (result == VK_SUCCESS)
    {
        VkRenderPass     render_pass     = VK_NULL_HANDLE;
        VkPipelineLayout pipeline_layout = VK_NULL_HANDLE;
        VkPipeline       pipeline        = VK_NULL_HANDLE;

        result = CreateDrawObjects(format,
                                   extent,
                                   aspect,
                                   sample_count,
                                   initial_layout,
                                   final_layout,
                                   set_layout,
                                   &render_pass,
                                   &pipeline_layout,
                                   &pipeline);

        if (result == VK_SUCCESS)
        {
            VkImageCreateInfo image_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
            image_info.pNext                 = nullptr;
            image_info.flags                 = 0;
            image_info.imageType             = type;
            image_info.format                = format;
            image_info.extent                = extent;
            image_info.mipLevels             = level_count;
            image_info.arrayLayers           = layer_count;
            image_info.samples               = VK_SAMPLE_COUNT_1_BIT;
            image_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
            image_info.usage                 = VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT;
            image_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
            image_info.queueFamilyIndexCount = 0;
            image_info.pQueueFamilyIndices   = nullptr;
            image_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

            VkImage                               staging_image       = VK_NULL_HANDLE;
            VkDeviceMemory                        staging_memory      = VK_NULL_HANDLE;
            VulkanResourceAllocator::ResourceData staging_image_data  = 0;
            VulkanResourceAllocator::MemoryData   staging_memory_data = 0;

            result = CreateStagingImage(
                &image_info, &staging_memory, &staging_image, &staging_memory_data, &staging_image_data);

            if (result == VK_SUCCESS)
            {
                result = BufferToImageCopy(queue_family_index,
                                           source,
                                           staging_image,
                                           format,
                                           aspect,
                                           VK_IMAGE_LAYOUT_UNDEFINED,
                                           VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL,
                                           layer_count,
                                           level_count,
                                           level_copies);

                if (result == VK_SUCCESS)
                {
                    VkViewport viewport     = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };
                    VkRect2D   scissor_rect = { { 0, 0 }, { 0, 0 } };

                    for (uint32_t level = 0; level < level_count; ++level)
                    {
                        const VkBufferImageCopy& level_copy = level_copies[level];
                        assert((level_copy.imageSubresource.baseArrayLayer) == 0 &&
                               (level_copy.imageSubresource.layerCount == layer_count));

                        viewport.width             = static_cast<float>(level_copy.imageExtent.width);
                        viewport.height            = static_cast<float>(level_copy.imageExtent.height);
                        scissor_rect.extent.width  = level_copy.imageExtent.width;
                        scissor_rect.extent.height = level_copy.imageExtent.height;

                        VkImageViewCreateInfo view_info         = { VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO };
                        view_info.pNext                         = nullptr;
                        view_info.flags                         = 0;
                        view_info.image                         = staging_image;
                        view_info.viewType                      = VK_IMAGE_VIEW_TYPE_2D;
                        view_info.format                        = format;
                        view_info.components.r                  = VK_COMPONENT_SWIZZLE_IDENTITY;
                        view_info.components.g                  = VK_COMPONENT_SWIZZLE_IDENTITY;
                        view_info.components.b                  = VK_COMPONENT_SWIZZLE_IDENTITY;
                        view_info.components.a                  = VK_COMPONENT_SWIZZLE_IDENTITY;
                        view_info.subresourceRange.aspectMask   = aspect;
                        view_info.subresourceRange.baseMipLevel = level;
                        view_info.subresourceRange.levelCount   = 1;
                        view_info.subresourceRange.layerCount   = 1;

                        for (uint32_t layer = 0; layer < layer_count; ++layer)
                        {
                            VkFramebuffer framebuffer      = VK_NULL_HANDLE;
                            VkImageView   destination_view = VK_NULL_HANDLE;
                            VkImageView   staging_view     = VK_NULL_HANDLE;

                            view_info.subresourceRange.baseArrayLayer = layer;

                            result = device_table_->CreateImageView(device_, &view_info, nullptr, &staging_view);

                            if (result == VK_SUCCESS)
                            {
                                UpdateDrawDescriptorSet(set, staging_view, sampler);

                                view_info.image = destination;
                                result          = CreateFramebufferResources(&view_info,
                                                                    level_copy.imageExtent.width,
                                                                    level_copy.imageExtent.height,
                                                                    render_pass,
                                                                    &destination_view,
                                                                    &framebuffer);
                            }

                            if (result == VK_SUCCESS)
                            {
                                result = BeginCommandBuffer(command_buffer);

                                if (result == VK_SUCCESS)
                                {
                                    VkRenderPassBeginInfo begin_info    = { VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO };
                                    begin_info.pNext                    = nullptr;
                                    begin_info.renderPass               = render_pass;
                                    begin_info.framebuffer              = framebuffer;
                                    begin_info.renderArea.offset.x      = 0;
                                    begin_info.renderArea.offset.y      = 0;
                                    begin_info.renderArea.extent.width  = level_copy.imageExtent.width;
                                    begin_info.renderArea.extent.height = level_copy.imageExtent.height;
                                    begin_info.clearValueCount          = 0;
                                    begin_info.pClearValues             = nullptr;

                                    device_table_->CmdBeginRenderPass(
                                        command_buffer, &begin_info, VK_SUBPASS_CONTENTS_INLINE);
                                    device_table_->CmdBindPipeline(
                                        command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline);
                                    device_table_->CmdBindDescriptorSets(command_buffer,
                                                                         VK_PIPELINE_BIND_POINT_GRAPHICS,
                                                                         pipeline_layout,
                                                                         0,
                                                                         1,
                                                                         &set,
                                                                         0,
                                                                         nullptr);
                                    device_table_->CmdSetViewport(command_buffer, 0, 1, &viewport);
                                    device_table_->CmdSetScissor(command_buffer, 0, 1, &scissor_rect);
                                    device_table_->CmdDraw(command_buffer, 3, 1, 0, 0);
                                    device_table_->CmdEndRenderPass(command_buffer);
                                    device_table_->EndCommandBuffer(command_buffer);

                                    result = ExecuteCommandBuffer(queue, command_buffer);
                                }
                            }

                            DestroyFramebufferResources(destination_view, framebuffer);
                            device_table_->DestroyImageView(device_, staging_view, nullptr);

                            if (result != VK_SUCCESS)
                            {
                                break;
                            }
                        }
                    }
                }

                DestroyStagingImage(staging_memory, staging_image, staging_memory_data, staging_image_data);
            }

            DestroyDrawObjects(render_pass, pipeline_layout, pipeline);
        }
    }

    return result;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
