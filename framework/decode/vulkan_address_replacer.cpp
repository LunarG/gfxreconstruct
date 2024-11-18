/*
** Copyright (c) 2024 LunarG, Inc.
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

#include "decode/vulkan_address_replacer.h"
#include "decode/vulkan_address_replacer_shaders.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

inline uint32_t div_up(uint32_t nom, uint32_t denom)
{
    return (nom + denom - 1) / denom;
}

uint32_t get_memory_type_index(const VkPhysicalDeviceMemoryProperties& memory_properties,
                               uint32_t                                type_bits,
                               VkMemoryPropertyFlags                   property_flags)
{
    uint32_t memory_type_index = std::numeric_limits<uint32_t>::max();

    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        if ((type_bits & (1 << i)) &&
            ((memory_properties.memoryTypes[i].propertyFlags & property_flags) == property_flags))
        {
            memory_type_index = i;
            break;
        }
    }

    return memory_type_index;
}

//! 16 bytes
struct hashmap_t
{
    VkDeviceAddress storage;
    uint32_t        size;
    uint32_t        capacity;
};

struct replacer_params_t
{
    hashmap_t hashmap;

    // input-/output-arrays can be identical when sbt-alignments/strides match
    VkDeviceAddress input_handles, output_handles;
    uint32_t        num_handles;
};

decode::VulkanAddressReplacer::buffer_context_t::~buffer_context_t()
{
    if (resource_allocator_ != nullptr)
    {
        if (buffer_ != VK_NULL_HANDLE)
        {
            resource_allocator_->DestroyBufferDirect(buffer_, nullptr, allocator_data_);
        }
        if (device_memory_ != VK_NULL_HANDLE)
        {
            resource_allocator_->FreeMemoryDirect(device_memory_, nullptr, allocator_data_);
        }
    }
}

VulkanAddressReplacer::VulkanAddressReplacer(const VulkanDeviceInfo*              device_info,
                                             const encode::VulkanDeviceTable*     device_table,
                                             const decode::CommonObjectInfoTable& object_table) :
    device_table_(device_table), object_table_(&object_table)
{
    GFXRECON_ASSERT(device_info != nullptr && device_table != nullptr)

    device_             = device_info->handle;
    resource_allocator_ = device_info->allocator.get();

    const VulkanPhysicalDeviceInfo* physical_device_info = object_table.GetVkPhysicalDeviceInfo(device_info->parent_id);

    if (physical_device_info != nullptr && physical_device_info->replay_device_info->raytracing_properties)
    {
        const auto& replay_props = *physical_device_info->replay_device_info->raytracing_properties;

        if (physical_device_info->shaderGroupHandleSize != replay_props.shaderGroupHandleSize ||
            physical_device_info->shaderGroupHandleAlignment != replay_props.shaderGroupHandleAlignment ||
            physical_device_info->shaderGroupBaseAlignment != replay_props.shaderGroupBaseAlignment)
        {
            valid_sbt_alignment_ = false;
        }

        assert(physical_device_info->replay_device_info != nullptr);
        assert(physical_device_info->replay_device_info->memory_properties.has_value());
        memory_properties_ = *physical_device_info->replay_device_info->memory_properties;
    }

    VkPushConstantRange push_constant_range = {};
    push_constant_range.stageFlags          = VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;
    push_constant_range.offset              = 0;
    push_constant_range.size                = sizeof(replacer_params_t);

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.pNext                      = nullptr;
    pipeline_layout_info.flags                      = 0;
    pipeline_layout_info.setLayoutCount             = 0;
    pipeline_layout_info.pSetLayouts                = nullptr;
    pipeline_layout_info.pushConstantRangeCount     = 1;
    pipeline_layout_info.pPushConstantRanges        = &push_constant_range;

    VkResult result = device_table_->CreatePipelineLayout(device_, &pipeline_layout_info, nullptr, &pipeline_layout_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanAddressReplacer: failed in vkCreatePipelineLayout");
    }
    VkShaderModule           compute_module = VK_NULL_HANDLE;
    VkShaderModuleCreateInfo ps_info        = {};
    ps_info.sType                           = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    ps_info.pNext                           = VK_NULL_HANDLE;
    ps_info.flags                           = 0;
    ps_info.codeSize                        = g_replacer_sbt_comp.size();
    ps_info.pCode                           = reinterpret_cast<const uint32_t*>(g_replacer_sbt_comp.data());

    result = device_table_->CreateShaderModule(device_, &ps_info, nullptr, &compute_module);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanAddressReplacer: failed in vkCreateShaderModule");
    }
    VkPipelineShaderStageCreateInfo stage_info = {};
    stage_info.sType                           = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stage_info.pNext                           = nullptr;
    stage_info.flags                           = 0;
    stage_info.stage                           = VK_SHADER_STAGE_COMPUTE_BIT;
    stage_info.module                          = compute_module;
    stage_info.pName                           = "main";
    stage_info.pSpecializationInfo             = nullptr;

    VkComputePipelineCreateInfo pipeline_create_info = {};
    pipeline_create_info.sType                       = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    pipeline_create_info.layout                      = pipeline_layout_;
    pipeline_create_info.stage                       = stage_info;

    result = device_table_->CreateComputePipelines(
        device_, VK_NULL_HANDLE, 1, &pipeline_create_info, VK_NULL_HANDLE, &pipeline_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: pipeline creation failed");
    }

    if (compute_module != VK_NULL_HANDLE)
    {
        device_table_->DestroyShaderModule(device_, compute_module, nullptr);
    }
}

VulkanAddressReplacer::~VulkanAddressReplacer()
{
    if (pipeline_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipeline(device_, pipeline_, nullptr);
    }

    if (pipeline_layout_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipelineLayout(device_, pipeline_layout_, nullptr);
    }
}

void VulkanAddressReplacer::ProcessCmdTraceRays(
    const VulkanCommandBufferInfo*                                                              command_buffer_info,
    VkStridedDeviceAddressRegionKHR*                                                            raygen_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            miss_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            hit_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            callable_sbt,
    const decode::VulkanDeviceAddressTracker&                                                   address_tracker,
    const std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t>& group_handle_map)
{
    // figure out if the captured group-handles are valid for replay
    // NOTE: we expect this map to be populated here, but not for older captures (before #1844) using trimming.
    bool valid_group_handles = !group_handle_map.empty();

    for (const auto& [lhs, rhs] : group_handle_map)
    {
        if (lhs != rhs)
        {
            valid_group_handles = false;
            break;
        }
    }

    // hack to force address-replacement
    valid_group_handles = false;

    if (!valid_sbt_alignment_ || !valid_group_handles)
    {
        auto address_remap = [&address_tracker](VkStridedDeviceAddressRegionKHR* address_region) {
            if (address_region->size > 0)
            {
                auto buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(address_region->deviceAddress);
                GFXRECON_ASSERT(buffer_info != nullptr);

                if (buffer_info->replay_address != 0)
                {
                    uint64_t offset = address_region->deviceAddress - buffer_info->capture_address;

                    // in-place address-remap
                    address_region->deviceAddress = buffer_info->replay_address + offset;
                }
                else
                {
                    GFXRECON_LOG_WARNING_ONCE(
                        "OverrideCmdTraceRaysKHR: missing buffer_info->replay_address, remap failed")
                }
            }
        };

        // in-place remap: capture-addresses -> replay-addresses
        address_remap(raygen_sbt);
        address_remap(miss_sbt);
        address_remap(hit_sbt);
        address_remap(callable_sbt);

        if (valid_sbt_alignment_)
        {
            // prepare linear hashmap
            handle_hashmap_.clear();

            for (const auto& [lhs, rhs] : group_handle_map)
            {
                handle_hashmap_.put(lhs, rhs);
            }

            // input-handles
            constexpr uint32_t max_num_handles = 4;
            if (!create_buffer(max_num_handles * sizeof(VkDeviceAddress), input_handle_buffer_))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
            }
            auto     input_addresses = reinterpret_cast<VkDeviceAddress*>(input_handle_buffer_.mapped_data);
            uint32_t idx             = 0;

            for (const auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
            {
                if (region != nullptr)
                {
                    input_addresses[idx++] = region->deviceAddress;
                }
            }
            if (!create_buffer(handle_hashmap_.get_storage(nullptr), hashmap_storage_))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap-storage-buffer creation failed");
            }
            handle_hashmap_.get_storage(hashmap_storage_.mapped_data);

            replacer_params_t replacer_params = {};
            replacer_params.hashmap.storage   = hashmap_storage_.device_address_;
            replacer_params.hashmap.size      = handle_hashmap_.size();
            replacer_params.hashmap.capacity  = handle_hashmap_.capacity();

            replacer_params.input_handles = replacer_params.output_handles = input_handle_buffer_.device_address_;
            replacer_params.num_handles                                    = group_handle_map.size();

            device_table_->CmdBindPipeline(command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_);

            // TODO: using push-constant might not work, need to re-establish previous data :(
            device_table_->CmdPushConstants(command_buffer_info->handle,
                                            pipeline_layout_,
                                            VK_SHADER_STAGE_COMPUTE_BIT,
                                            0,
                                            sizeof(replacer_params_t),
                                            &replacer_params);
            // run a single workgroup
            constexpr uint32_t wg_size = 32;
            device_table_->CmdDispatch(command_buffer_info->handle, div_up(replacer_params.num_handles, wg_size), 1, 1);

            // TODO: memory-barrier

            // set previous push-constant data
            device_table_->CmdPushConstants(command_buffer_info->handle,
                                            command_buffer_info->push_constant_pipeline_layout,
                                            command_buffer_info->push_constant_stage_flags,
                                            0,
                                            command_buffer_info->push_constant_data.size(),
                                            command_buffer_info->push_constant_data.data());
        }
        else
        {
            // TODO: remove TODO/warning when issue #1526 is solved
            GFXRECON_LOG_WARNING_ONCE("OverrideCmdTraceRaysKHR: invalid shader-binding-table (handle-size and/or "
                                      "alignments mismatch) -> TODO: run SBT re-assembly");

            // find/create shadow-SBT-buffer
            auto& buf_context = shadow_sbt_map_[raygen_sbt];
            if (!create_buffer(1024, buf_context))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: shadow shader-binding-table creation failed");
            }

            //            auto it = shadow_sbt_map_.find(raygen_sbt);
            //            if (it != shadow_sbt_map_.end())
            //            {
            //                shadow_sbt_map_
            //            }
            //            else
            //            {
            //                // TODO: calculate new sbt-size
            //                //                buffer_create_info.size = ;
            //            }

            // TODO: populate shadow-buffer
            // TODO: remap addresses to shadow-buffer
        }
    }
}
bool VulkanAddressReplacer::create_buffer(size_t num_bytes, VulkanAddressReplacer::buffer_context_t& buffer_context)
{
    // nothing to do
    if (num_bytes <= buffer_context.num_bytes)
    {
        return true;
    }

    if (buffer_context.buffer_ != VK_NULL_HANDLE)
    {
        resource_allocator_->DestroyBufferDirect(buffer_context.buffer_, nullptr, buffer_context.allocator_data_);
        resource_allocator_->FreeMemoryDirect(buffer_context.device_memory_, nullptr, buffer_context.allocator_data_);
    }

    VkBufferCreateInfo buffer_create_info = {};
    buffer_create_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.usage = VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;
    buffer_create_info.size  = num_bytes;

    VkResult result = resource_allocator_->CreateBufferDirect(
        &buffer_create_info, nullptr, &buffer_context.buffer_, &buffer_context.allocator_data_);
    if (result != VK_SUCCESS)
    {
        return false;
    }

    VkMemoryRequirements memory_requirements;
    device_table_->GetBufferMemoryRequirements(device_, buffer_context.buffer_, &memory_requirements);

    uint32_t memory_type_index =
        get_memory_type_index(memory_properties_,
                              memory_requirements.memoryTypeBits,
                              VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT);

    if (memory_type_index == std::numeric_limits<uint32_t>::max())
    {
        /* fallback to coherent */
        memory_type_index =
            get_memory_type_index(memory_properties_,
                                  memory_requirements.memoryTypeBits,
                                  VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    }

    assert(memory_type_index != std::numeric_limits<uint32_t>::max());

    VkMemoryAllocateInfo alloc_info = {};
    alloc_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    alloc_info.allocationSize       = num_bytes;
    alloc_info.memoryTypeIndex      = memory_type_index;
    result                          = resource_allocator_->AllocateMemoryDirect(
        &alloc_info, nullptr, &buffer_context.device_memory_, &buffer_context.memory_data_);

    if (result != VK_SUCCESS)
    {
        return false;
    }

    VkMemoryPropertyFlags memory_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    result                             = resource_allocator_->BindBufferMemory(buffer_context.buffer_,
                                                   buffer_context.device_memory_,
                                                   0,
                                                   buffer_context.allocator_data_,
                                                   buffer_context.memory_data_,
                                                   &memory_flags);
    if (result != VK_SUCCESS)
    {
        return false;
    }

    // check vulkan-version, select KHR/non-KHR
    VkBufferDeviceAddressInfo address_info = {};
    address_info.sType                     = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
    address_info.buffer                    = buffer_context.buffer_;
    buffer_context.device_address_         = device_table_->GetBufferDeviceAddress(device_, &address_info);

    // map buffer
    result = resource_allocator_->MapResourceMemoryDirect(
        buffer_context.num_bytes, 0, &buffer_context.mapped_data, buffer_context.allocator_data_);
    return result == VK_SUCCESS;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
