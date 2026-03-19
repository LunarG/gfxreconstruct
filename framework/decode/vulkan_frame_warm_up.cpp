/*
** Copyright (c) 2026 LunarG, Inc.
** Copyright (c) 2026 Google
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

#include "vulkan_frame_warm_up.h"

#include "generated/generated_vulkan_enum_to_string.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_resources_util.h"
#include "util/callbacks.h"
#include "util/logging.h"
#include "util/platform.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanFrameWarmUp::VulkanFrameWarmUp(const VulkanDeviceInfo*              device_info,
                                     const graphics::VulkanDeviceTable*   device_table,
                                     const graphics::VulkanInstanceTable* instance_table,
                                     CommonObjectInfoTable&               object_table,
                                     const std::string&                   spirv_path,
                                     uint32_t                             warm_up_load) :
    device_table_(device_table),
    spirv_path_(spirv_path), warm_up_load_(warm_up_load)
{
    util::MarkInjectedCommandsHelper mark_injected_commands_helper;

    GFXRECON_ASSERT(device_info != nullptr);
    GFXRECON_ASSERT(device_table != nullptr);
    GFXRECON_ASSERT(instance_table != nullptr);

    device_ = device_info->handle;
    GFXRECON_ASSERT(device_ != VK_NULL_HANDLE);

    device_table->GetDeviceQueue(device_, 0, 0, &queue_);
    GFXRECON_ASSERT(queue_ != VK_NULL_HANDLE);

    VkCommandPoolCreateInfo cmd_pool_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    cmd_pool_info.queueFamilyIndex        = 0;
    cmd_pool_info.flags                   = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT;
    VkResult result = device_table->CreateCommandPool(device_, &cmd_pool_info, nullptr, &command_pool_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: failed in vkCreateCommandPool: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    size_t                  spirv_size = 0;
    std::unique_ptr<char[]> spirv_code;
    FILE*                   fp = nullptr;

    int32_t open_result = util::platform::FileOpen(&fp, spirv_path_.c_str(), "rb");
    if (open_result == 0)
    {
        bool seek_result = util::platform::FileSeek(fp, 0L, util::platform::FileSeekEnd);
        if (!seek_result)
        {
            GFXRECON_LOG_FATAL("VulkanFrameWarmUp: failed to seek SPIR-V file \"%s\" for frame warm up.",
                               spirv_path_.c_str());
        }

        int64_t tell_result = util::platform::FileTell(fp);
        if (tell_result < 0)
        {
            GFXRECON_LOG_FATAL("VulkanFrameWarmUp: failed to tell SPIR-V file \"%s\" for frame warm up.",
                               spirv_path_.c_str());
        }
        spirv_size = static_cast<size_t>(tell_result);
        // SPIR-V should be a non-empty array of 32-bit words.
        if (spirv_size == 0 || spirv_size % 4 != 0)
        {
            GFXRECON_LOG_FATAL("VulkanFrameWarmUp: invalid SPIR-V file \"%s\" for frame warm up.", spirv_path_.c_str());
        }

        spirv_code  = std::make_unique<char[]>(spirv_size);
        seek_result = util::platform::FileSeek(fp, 0L, util::platform::FileSeekSet);
        if (!seek_result)
        {
            GFXRECON_LOG_FATAL("VulkanFrameWarmUp: failed to seek SPIR-V file \"%s\" for frame warm up.",
                               spirv_path_.c_str());
        }

        bool read_result = util::platform::FileRead(spirv_code.get(), spirv_size, fp);
        if (!read_result)
        {
            GFXRECON_LOG_FATAL("VulkanFrameWarmUp: failed to read SPIR-V file \"%s\" for frame warm up.",
                               spirv_path_.c_str());
        }

        util::platform::FileClose(fp);
    }
    else
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: failed to open SPIR-V file \"%s\" for frame warm up: %d.",
                           spirv_path_.c_str(),
                           open_result);
    }

    VkShaderModuleCreateInfo sm_create_info = { VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO };
    sm_create_info.codeSize                 = spirv_size;
    sm_create_info.pCode                    = (uint32_t*)spirv_code.get();
    result = device_table->CreateShaderModule(device_, &sm_create_info, nullptr, &shader_module_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkCreateShaderModule: %s",
                           util::ToString<VkResult>(result).c_str());
    }

    const uint32_t     num_invocations = warm_up_load_ * 1000 * 64 * 1 * 1; // Dispatch(X,Y,Z) * local_size(X,Y,Z)
    const VkDeviceSize buffer_size     = sizeof(float) * num_invocations;

    VkBufferCreateInfo buffer_info = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    buffer_info.size               = buffer_size;
    buffer_info.usage              = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT;
    buffer_info.sharingMode        = VK_SHARING_MODE_EXCLUSIVE;
    result                         = device_table->CreateBuffer(device_, &buffer_info, nullptr, &buffer_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkCreateBuffer: %s", util::ToString<VkResult>(result).c_str());
    }

    VulkanPhysicalDeviceInfo* physical_device_info = object_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    GFXRECON_ASSERT(physical_device_info != nullptr);

    VkPhysicalDeviceMemoryProperties capture_memory_properties = physical_device_info->capture_memory_properties;

    VkMemoryRequirements mem_requirements;
    device_table->GetBufferMemoryRequirements(device_, buffer_, &mem_requirements);

    VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    alloc_info.allocationSize       = mem_requirements.size;

    bool found = graphics::FindMemoryTypeIndex(capture_memory_properties,
                                               mem_requirements.memoryTypeBits,
                                               VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                               &alloc_info.memoryTypeIndex,
                                               nullptr);

    if (!found)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed to find suitable memory type for bits: 0x%X",
                           mem_requirements.memoryTypeBits);
    }

    result = device_table->AllocateMemory(device_, &alloc_info, nullptr, &buffer_memory_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkAllocateMemory: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    result = device_table->BindBufferMemory(device_, buffer_, buffer_memory_, 0);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkBindBufferMemory: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkDescriptorSetLayoutBinding layout_binding = {};
    layout_binding.binding                      = 0;
    layout_binding.descriptorType               = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    layout_binding.descriptorCount              = 1;
    layout_binding.stageFlags                   = VK_SHADER_STAGE_COMPUTE_BIT;

    VkDescriptorSetLayoutCreateInfo layout_info = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO };
    layout_info.bindingCount                    = 1;
    layout_info.pBindings                       = &layout_binding;
    result = device_table->CreateDescriptorSetLayout(device_, &layout_info, nullptr, &descriptor_set_layout_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkCreateDescriptorSetLayout: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkPipelineLayoutCreateInfo pl_create_info = { VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO };
    pl_create_info.setLayoutCount             = 1;
    pl_create_info.pSetLayouts                = &descriptor_set_layout_; // Link the layout
    result = device_table->CreatePipelineLayout(device_, &pl_create_info, nullptr, &pipeline_layout_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkCreatePipelineLayout: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkDescriptorPoolSize pool_size = {};
    pool_size.type                 = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    pool_size.descriptorCount      = 1;

    VkDescriptorPoolCreateInfo pool_info = { VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO };
    pool_info.poolSizeCount              = 1;
    pool_info.pPoolSizes                 = &pool_size;
    pool_info.maxSets                    = 1;
    result = device_table->CreateDescriptorPool(device_, &pool_info, nullptr, &descriptor_pool_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkCreateDescriptorPool: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkDescriptorSetAllocateInfo set_alloc_info = { VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO };
    set_alloc_info.descriptorPool              = descriptor_pool_;
    set_alloc_info.descriptorSetCount          = 1;
    set_alloc_info.pSetLayouts                 = &descriptor_set_layout_;
    result = device_table->AllocateDescriptorSets(device_, &set_alloc_info, &descriptor_set_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkAllocateDescriptorSets: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkDescriptorBufferInfo buffer_info_for_descriptor = {};
    buffer_info_for_descriptor.buffer                 = buffer_;
    buffer_info_for_descriptor.offset                 = 0;
    buffer_info_for_descriptor.range                  = buffer_size;

    VkWriteDescriptorSet descriptor_write = { VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET };
    descriptor_write.dstSet               = descriptor_set_;
    descriptor_write.dstBinding           = 0;
    descriptor_write.dstArrayElement      = 0;
    descriptor_write.descriptorType       = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
    descriptor_write.descriptorCount      = 1;
    descriptor_write.pBufferInfo          = &buffer_info_for_descriptor;
    device_table->UpdateDescriptorSets(device_, 1, &descriptor_write, 0, nullptr);

    VkComputePipelineCreateInfo cp_create_info = { VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO };
    cp_create_info.stage.sType                 = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    cp_create_info.stage.stage                 = VK_SHADER_STAGE_COMPUTE_BIT;
    cp_create_info.stage.module                = shader_module_;
    cp_create_info.stage.pName                 = "main";
    cp_create_info.layout                      = pipeline_layout_;
    result = device_table->CreateComputePipelines(device_, VK_NULL_HANDLE, 1, &cp_create_info, nullptr, &pipeline_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkCreateComputePipelines: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkSemaphoreCreateInfo semaphore_info = { VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO };
    result = device_table->CreateSemaphore(device_, &semaphore_info, nullptr, &semaphore_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkCreateSemaphore: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkCommandBufferAllocateInfo cmd_buf_alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    cmd_buf_alloc_info.commandPool                 = command_pool_;
    cmd_buf_alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    cmd_buf_alloc_info.commandBufferCount          = 1;
    result = device_table->AllocateCommandBuffers(device_, &cmd_buf_alloc_info, &command_buffer_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkAllocateCommandBuffers: %s.",
                           util::ToString<VkResult>(result).c_str());
    }

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.flags                    = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
    device_table->BeginCommandBuffer(command_buffer_, &begin_info);
    device_table->CmdBindPipeline(command_buffer_, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_);
    device_table->CmdBindDescriptorSets(
        command_buffer_, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_layout_, 0, 1, &descriptor_set_, 0, nullptr);
    device_table->CmdDispatch(command_buffer_, warm_up_load_ * 64, 1, 1);
    device_table->EndCommandBuffer(command_buffer_);
}

VulkanFrameWarmUp::~VulkanFrameWarmUp()
{
    util::MarkInjectedCommandsHelper mark_injected_commands_helper;

    if (device_table_ != nullptr && device_ != VK_NULL_HANDLE)
    {
        if (semaphore_ != VK_NULL_HANDLE)
        {
            device_table_->DestroySemaphore(device_, semaphore_, nullptr);
        }
        if (buffer_memory_ != VK_NULL_HANDLE)
        {
            device_table_->FreeMemory(device_, buffer_memory_, nullptr);
        }
        if (buffer_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyBuffer(device_, buffer_, nullptr);
        }
        if (pipeline_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyPipeline(device_, pipeline_, nullptr);
        }
        if (pipeline_layout_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyPipelineLayout(device_, pipeline_layout_, nullptr);
        }
        if (descriptor_set_layout_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyDescriptorSetLayout(device_, descriptor_set_layout_, nullptr);
        }
        if (descriptor_pool_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyDescriptorPool(device_, descriptor_pool_, nullptr);
        }
        if (shader_module_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyShaderModule(device_, shader_module_, nullptr);
        }
        if (command_buffer_ != VK_NULL_HANDLE)
        {
            device_table_->FreeCommandBuffers(device_, command_pool_, 1, &command_buffer_);
        }
        if (command_pool_ != VK_NULL_HANDLE)
        {
            device_table_->DestroyCommandPool(device_, command_pool_, nullptr);
        }
    }
}

VulkanFrameWarmUp::VulkanFrameWarmUp(VulkanFrameWarmUp&& other) noexcept :
    device_table_(other.device_table_), warm_up_load_(other.warm_up_load_), device_(other.device_),
    queue_(other.queue_), command_pool_(other.command_pool_), command_buffer_(other.command_buffer_),
    shader_module_(other.shader_module_), descriptor_pool_(other.descriptor_pool_),
    descriptor_set_layout_(other.descriptor_set_layout_), descriptor_set_(other.descriptor_set_),
    pipeline_layout_(other.pipeline_layout_), pipeline_(other.pipeline_), buffer_(other.buffer_),
    buffer_memory_(other.buffer_memory_), semaphore_(other.semaphore_)
{
    other.device_table_          = nullptr;
    other.device_                = VK_NULL_HANDLE;
    other.queue_                 = VK_NULL_HANDLE;
    other.command_pool_          = VK_NULL_HANDLE;
    other.command_buffer_        = VK_NULL_HANDLE;
    other.shader_module_         = VK_NULL_HANDLE;
    other.descriptor_pool_       = VK_NULL_HANDLE;
    other.descriptor_set_layout_ = VK_NULL_HANDLE;
    other.descriptor_set_        = VK_NULL_HANDLE;
    other.pipeline_layout_       = VK_NULL_HANDLE;
    other.pipeline_              = VK_NULL_HANDLE;
    other.buffer_                = VK_NULL_HANDLE;
    other.buffer_memory_         = VK_NULL_HANDLE;
    other.semaphore_             = VK_NULL_HANDLE;
}

VkSemaphore VulkanFrameWarmUp::WarmUp(const std::span<graphics::VulkanSemaphore> wait_semaphores)
{
    util::MarkInjectedCommandsHelper mark_injected_commands_helper;

    std::vector<VkSemaphore>          semaphore_handles(wait_semaphores.size());
    std::vector<uint64_t>             semaphore_values(wait_semaphores.size());
    std::vector<VkPipelineStageFlags> wait_dst_stages(wait_semaphores.size(), VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT);

    for (uint32_t i = 0; i < wait_semaphores.size(); ++i)
    {
        semaphore_handles[i] = wait_semaphores[i].semaphore;
        semaphore_values[i]  = wait_semaphores[i].timeline_value;
    }

    VkTimelineSemaphoreSubmitInfo timeline_info = {};
    timeline_info.sType                         = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
    timeline_info.waitSemaphoreValueCount       = wait_semaphores.size();
    timeline_info.pWaitSemaphoreValues          = wait_semaphores.empty() ? nullptr : semaphore_values.data();

    VkSubmitInfo submit_info = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    // submit_info.pNext              = &timeline_info;
    submit_info.waitSemaphoreCount = wait_semaphores.size();
    submit_info.pWaitSemaphores    = wait_semaphores.empty() ? nullptr : semaphore_handles.data();
    submit_info.pWaitDstStageMask  = wait_semaphores.empty() ? nullptr : wait_dst_stages.data();

    submit_info.commandBufferCount = 1;
    submit_info.pCommandBuffers    = &command_buffer_;
    // next_semaphore_index > 0 means we know how many of them we need from previous frame render
    submit_info.signalSemaphoreCount = 1;
    submit_info.pSignalSemaphores    = &semaphore_;

    VkResult result = device_table_->QueueSubmit(queue_, 1, &submit_info, VK_NULL_HANDLE);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanFrameWarmUp: Failed in vkQueueSubmit: %s.", util::ToString<VkResult>(result).c_str());
    }

    return semaphore_;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
