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

inline uint32_t aligned_size(uint32_t size, uint32_t alignment)
{
    return (size + alignment - 1) & ~(alignment - 1);
}

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
    if (resource_allocator != nullptr)
    {
        if (buffer != VK_NULL_HANDLE)
        {
            resource_allocator->DestroyBufferDirect(buffer, nullptr, allocator_data);
        }
        if (device_memory != VK_NULL_HANDLE)
        {
            resource_allocator->FreeMemoryDirect(device_memory, nullptr, memory_data);
        }
    }
}

VulkanAddressReplacer::VulkanAddressReplacer(const VulkanDeviceInfo*              device_info,
                                             const encode::VulkanDeviceTable*     device_table,
                                             const decode::CommonObjectInfoTable& object_table) :
    device_table_(device_table)
{
    GFXRECON_ASSERT(device_info != nullptr && device_table != nullptr)

    const VulkanPhysicalDeviceInfo* physical_device_info = object_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    device_                                              = device_info->handle;
    resource_allocator_                                  = device_info->allocator.get();
    get_device_address_fn_ = physical_device_info->parent_api_version >= VK_API_VERSION_1_2
                                 ? device_table->GetBufferDeviceAddress
                                 : device_table->GetBufferDeviceAddressKHR;

    if (physical_device_info != nullptr && physical_device_info->capture_raytracing_properties &&
        physical_device_info->replay_device_info->raytracing_properties)
    {
        capture_ray_properties_ = *physical_device_info->capture_raytracing_properties;
        replay_ray_properties_  = *physical_device_info->replay_device_info->raytracing_properties;

        if (capture_ray_properties_.shaderGroupHandleSize != replay_ray_properties_.shaderGroupHandleSize ||
            capture_ray_properties_.shaderGroupHandleAlignment != replay_ray_properties_.shaderGroupHandleAlignment ||
            capture_ray_properties_.shaderGroupBaseAlignment != replay_ray_properties_.shaderGroupBaseAlignment)
        {
            valid_sbt_alignment_ = false;
        }

        assert(physical_device_info->replay_device_info != nullptr);
        assert(physical_device_info->replay_device_info->memory_properties.has_value());
        memory_properties_ = *physical_device_info->replay_device_info->memory_properties;
    }
}

VulkanAddressReplacer::VulkanAddressReplacer(VulkanAddressReplacer&& other) noexcept : VulkanAddressReplacer()
{
    swap(*this, other);
}

VulkanAddressReplacer::~VulkanAddressReplacer()
{
    if (pipeline_bda_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipeline(device_, pipeline_bda_, nullptr);
    }
    if (pipeline_sbt_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipeline(device_, pipeline_sbt_, nullptr);
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
    GFXRECON_ASSERT(device_table_ != nullptr);

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

    // TODO: testing only -> remove when closing issue #1526
    //    valid_sbt_alignment_ = false;
    //    valid_group_handles  = false;

    if (!valid_sbt_alignment_ || !valid_group_handles)
    {
        if (pipeline_sbt_ == VK_NULL_HANDLE)
        {
            init_pipeline();
        }
        std::unordered_set<VkBuffer> buffer_set;

        auto address_remap = [&address_tracker, &buffer_set](VkStridedDeviceAddressRegionKHR* address_region) {
            if (address_region->size > 0)
            {
                auto buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(address_region->deviceAddress);
                GFXRECON_ASSERT(buffer_info != nullptr);

                if (buffer_info->replay_address != 0)
                {
                    // keep track of used handles
                    buffer_set.insert(buffer_info->handle);

                    uint64_t offset = address_region->deviceAddress - buffer_info->capture_address;

                    // in-place address-remap
                    address_region->deviceAddress = buffer_info->replay_address + offset;
                }
                else
                {
                    GFXRECON_LOG_WARNING_ONCE(
                        "VulkanAddressReplacer::ProcessCmdTraceRays: missing buffer_info->replay_address, remap failed")
                }
            }
        };

        // in-place remap: capture-addresses -> replay-addresses
        address_remap(raygen_sbt);
        address_remap(miss_sbt);
        address_remap(hit_sbt);
        address_remap(callable_sbt);

        // prepare linear hashmap
        hashmap_sbt_.clear();

        for (const auto& [lhs, rhs] : group_handle_map)
        {
            hashmap_sbt_.put(lhs, rhs);
        }

        if (!create_buffer(hashmap_sbt_.get_storage(nullptr), pipeline_context_sbt_.hashmap_storage))
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap-storage-buffer creation failed");
        }
        hashmap_sbt_.get_storage(pipeline_context_sbt_.hashmap_storage.mapped_data);

        // input-handles
        constexpr uint32_t max_num_handles = 4;
        if (!create_buffer(max_num_handles * sizeof(VkDeviceAddress), pipeline_context_sbt_.input_handle_buffer))
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
        }
        auto input_addresses =
            reinterpret_cast<VkDeviceAddress*>(pipeline_context_sbt_.input_handle_buffer.mapped_data);
        uint32_t num_addresses = 0;

        for (const auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
        {
            if (region != nullptr && region->size)
            {
                input_addresses[num_addresses++] = region->deviceAddress;
            }
        }

        replacer_params_t replacer_params = {};
        replacer_params.hashmap.storage   = pipeline_context_sbt_.hashmap_storage.device_address;
        replacer_params.hashmap.size      = hashmap_sbt_.size();
        replacer_params.hashmap.capacity  = hashmap_sbt_.capacity();

        replacer_params.input_handles = pipeline_context_sbt_.input_handle_buffer.device_address;
        replacer_params.num_handles   = num_addresses;

        if (valid_sbt_alignment_)
        {
            // rewrite group-handles in-place
            replacer_params.output_handles = replacer_params.input_handles;

            // pre memory-barrier
            for (const auto& buf : buffer_set)
            {
                barrier(command_buffer_info->handle,
                        buf,
                        VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR,
                        VK_ACCESS_SHADER_READ_BIT,
                        VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_SHADER_WRITE_BIT);
            }
        }
        else
        {
            // output-handles
            if (!create_buffer(max_num_handles * sizeof(VkDeviceAddress), pipeline_context_sbt_.output_handle_buffer))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
            }
            // output to shadow-sbt-buffer
            replacer_params.output_handles = pipeline_context_sbt_.output_handle_buffer.device_address;

            // find/create shadow-SBT-buffer
            uint32_t sbt_offset         = 0;
            auto&    shadow_buf_context = shadow_sbt_map_[command_buffer_info->handle];

            const uint32_t handle_size_aligned = aligned_size(replay_ray_properties_.shaderGroupHandleSize,
                                                              replay_ray_properties_.shaderGroupHandleAlignment);

            for (auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
            {
                if (region != nullptr)
                {
                    uint32_t num_handles_limit = region->size / region->stride;
                    uint32_t group_size        = aligned_size(num_handles_limit * handle_size_aligned,
                                                       replay_ray_properties_.shaderGroupBaseAlignment);
                    sbt_offset += group_size;

                    // adjust group-size
                    region->size   = group_size;
                    region->stride = handle_size_aligned;
                }
            }
            // raygen: stride == size
            raygen_sbt->size = raygen_sbt->stride = replay_ray_properties_.shaderGroupBaseAlignment;

            if (!create_buffer(sbt_offset, shadow_buf_context, VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: shadow shader-binding-table creation failed");
            }

            auto output_addresses =
                reinterpret_cast<VkDeviceAddress*>(pipeline_context_sbt_.output_handle_buffer.mapped_data);
            uint32_t out_index = 0;
            sbt_offset         = 0;
            for (auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
            {
                if (region != nullptr)
                {
                    // assign shadow-sbt-address
                    region->deviceAddress = shadow_buf_context.device_address + sbt_offset;
                    sbt_offset += region->size;
                    output_addresses[out_index++] = region->deviceAddress;
                }
            }
        }

        device_table_->CmdBindPipeline(command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_sbt_);

        // NOTE: using push-constants here requires us to re-establish the previous data, if any
        device_table_->CmdPushConstants(command_buffer_info->handle,
                                        pipeline_layout_,
                                        VK_SHADER_STAGE_COMPUTE_BIT,
                                        0,
                                        sizeof(replacer_params_t),
                                        &replacer_params);
        // run a single workgroup
        constexpr uint32_t wg_size = 32;
        device_table_->CmdDispatch(command_buffer_info->handle, div_up(replacer_params.num_handles, wg_size), 1, 1);

        // post memory-barrier
        for (const auto& buf : buffer_set)
        {
            barrier(command_buffer_info->handle,
                    buf,
                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_SHADER_WRITE_BIT,
                    VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR,
                    VK_ACCESS_SHADER_READ_BIT);
        }

        // set previous push-constant data
        if (!command_buffer_info->push_constant_data.empty())
        {
            device_table_->CmdPushConstants(command_buffer_info->handle,
                                            command_buffer_info->push_constant_pipeline_layout,
                                            command_buffer_info->push_constant_stage_flags,
                                            0,
                                            command_buffer_info->push_constant_data.size(),
                                            command_buffer_info->push_constant_data.data());
        }
    } // !valid_sbt_alignment_ || !valid_group_handles
}

void VulkanAddressReplacer::ProcessCmdBuildAccelerationStructuresKHR(
    const VulkanCommandBufferInfo*               command_buffer_info,
    uint32_t                                     info_count,
    VkAccelerationStructureBuildGeometryInfoKHR* build_geometry_infos,
    VkAccelerationStructureBuildRangeInfoKHR**   build_range_infos,
    const VulkanDeviceAddressTracker&            address_tracker)
{
    GFXRECON_ASSERT(device_table_ != nullptr);

    // TODO: testing only -> remove when closing issue #1526
    constexpr bool force_replace = false;

    std::unordered_set<VkBuffer> buffer_set;
    auto                         address_remap = [&address_tracker, &buffer_set](VkDeviceAddress& capture_address) {
        auto buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(capture_address);

        if (buffer_info != nullptr && buffer_info->replay_address != 0)
        {
            // keep track of used handles
            buffer_set.insert(buffer_info->handle);

            uint64_t offset = capture_address - buffer_info->capture_address;

            // in-place address-remap via const-cast
            capture_address = buffer_info->replay_address + offset;
        }
        else
        {
            GFXRECON_LOG_WARNING(
                "ProcessCmdBuildAccelerationStructuresKHR: missing buffer_info->replay_address, remap failed");
        }
    };

    std::vector<VkDeviceAddress> addresses_to_replace;

    for (uint32_t i = 0; i < info_count; ++i)
    {
        auto& build_geometry_info = build_geometry_infos[i];
        auto  range_info          = build_range_infos[i];

        // check/correct scratch-address
        address_remap(build_geometry_info.scratchData.deviceAddress);

        for (uint32_t j = 0; j < build_geometry_info.geometryCount; ++j)
        {
            auto geometry = const_cast<VkAccelerationStructureGeometryKHR*>(build_geometry_info.pGeometries != nullptr
                                                                                ? build_geometry_info.pGeometries + j
                                                                                : build_geometry_info.ppGeometries[j]);
            switch (geometry->geometryType)
            {
                case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
                {
                    auto& triangles = geometry->geometry.triangles;
                    address_remap(triangles.vertexData.deviceAddress);
                    address_remap(triangles.indexData.deviceAddress);
                    break;
                }
                case VK_GEOMETRY_TYPE_AABBS_KHR:
                {
                    auto& aabbs = geometry->geometry.aabbs;
                    address_remap(aabbs.data.deviceAddress);
                    break;
                }
                case VK_GEOMETRY_TYPE_INSTANCES_KHR:
                {
                    auto& instances = geometry->geometry.instances;
                    address_remap(instances.data.deviceAddress);

                    // replace VkAccelerationStructureInstanceKHR::accelerationStructureReference inside buffer
                    for (uint32_t k = 0; k < range_info->primitiveCount; ++k)
                    {
                        VkDeviceAddress accel_structure_reference =
                            instances.data.deviceAddress + k * sizeof(VkAccelerationStructureInstanceKHR) +
                            offsetof(VkAccelerationStructureInstanceKHR, accelerationStructureReference);
                        addresses_to_replace.push_back(accel_structure_reference);
                    }
                    break;
                }
                default:
                    GFXRECON_LOG_ERROR(
                        "OverrideCmdBuildAccelerationStructuresKHR: unhandled case in switch-statement: %d",
                        geometry->geometryType);
                    break;
            }
        }
    }

    if (!addresses_to_replace.empty())
    {
        // prepare linear hashmap
        hashmap_bda_.clear();
        auto acceleration_structure_map = address_tracker.GetAccelerationStructureDeviceAddressMap();
        for (const auto& [capture_address, replay_address] : acceleration_structure_map)
        {
            if (force_replace || capture_address != replay_address)
            {
                // store addresses we will need to replace
                hashmap_bda_.put(capture_address, replay_address);
            }
        }

        if (!hashmap_bda_.empty())
        {
            if (pipeline_bda_ == VK_NULL_HANDLE)
            {
                init_pipeline();
            }

            if (!create_buffer(hashmap_bda_.get_storage(nullptr), pipeline_context_bda_.hashmap_storage))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap-storage-buffer creation failed");
            }
            hashmap_bda_.get_storage(pipeline_context_bda_.hashmap_storage.mapped_data);

            uint32_t num_bytes = addresses_to_replace.size() * sizeof(VkDeviceAddress);

            if (!create_buffer(num_bytes, pipeline_context_bda_.input_handle_buffer))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
            }
            memcpy(pipeline_context_bda_.input_handle_buffer.mapped_data, addresses_to_replace.data(), num_bytes);

            replacer_params_t replacer_params = {};
            replacer_params.hashmap.storage   = pipeline_context_bda_.hashmap_storage.device_address;
            replacer_params.hashmap.size      = hashmap_bda_.size();
            replacer_params.hashmap.capacity  = hashmap_bda_.capacity();

            // in-place
            replacer_params.input_handles  = pipeline_context_bda_.input_handle_buffer.device_address;
            replacer_params.output_handles = pipeline_context_bda_.input_handle_buffer.device_address;

            replacer_params.num_handles = addresses_to_replace.size();

            device_table_->CmdBindPipeline(command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_bda_);

            // NOTE: using push-constants here requires us to re-establish the previous data, if any
            device_table_->CmdPushConstants(command_buffer_info->handle,
                                            pipeline_layout_,
                                            VK_SHADER_STAGE_COMPUTE_BIT,
                                            0,
                                            sizeof(replacer_params_t),
                                            &replacer_params);
            // run a single workgroup
            constexpr uint32_t wg_size = 32;
            device_table_->CmdDispatch(command_buffer_info->handle, div_up(replacer_params.num_handles, wg_size), 1, 1);

            // post memory-barrier
            for (const auto& buf : buffer_set)
            {
                barrier(command_buffer_info->handle,
                        buf,
                        VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_SHADER_WRITE_BIT,
                        VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR,
                        VK_ACCESS_SHADER_READ_BIT);
            }

            // set previous push-constant data
            if (!command_buffer_info->push_constant_data.empty())
            {
                device_table_->CmdPushConstants(command_buffer_info->handle,
                                                command_buffer_info->push_constant_pipeline_layout,
                                                command_buffer_info->push_constant_stage_flags,
                                                0,
                                                command_buffer_info->push_constant_data.size(),
                                                command_buffer_info->push_constant_data.data());
            }
        }
    }
}

void VulkanAddressReplacer::init_pipeline()
{
    if (pipeline_sbt_ != VK_NULL_HANDLE)
    {
        return;
    }
    VkPushConstantRange push_constant_range = {};
    push_constant_range.stageFlags          = VK_SHADER_STAGE_COMPUTE_BIT;
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

    auto create_pipeline = [this](VkPipelineLayout layout, const auto& spirv, VkPipeline& out_pipeline) -> VkResult {
        VkShaderModule           compute_module            = VK_NULL_HANDLE;
        VkShaderModuleCreateInfo shader_module_create_info = {};
        shader_module_create_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        shader_module_create_info.pNext                    = VK_NULL_HANDLE;
        shader_module_create_info.flags                    = 0;
        shader_module_create_info.codeSize                 = spirv.size();
        shader_module_create_info.pCode                    = reinterpret_cast<const uint32_t*>(spirv.data());

        VkResult result =
            device_table_->CreateShaderModule(device_, &shader_module_create_info, nullptr, &compute_module);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_FATAL("VulkanAddressReplacer: failed in vkCreateShaderModule");
            return result;
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
        pipeline_create_info.layout                      = layout;
        pipeline_create_info.stage                       = stage_info;

        result = device_table_->CreateComputePipelines(
            device_, VK_NULL_HANDLE, 1, &pipeline_create_info, VK_NULL_HANDLE, &out_pipeline);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: pipeline creation failed");
        }

        if (compute_module != VK_NULL_HANDLE)
        {
            device_table_->DestroyShaderModule(device_, compute_module, nullptr);
        }
        return result;
    };

    // create SBT pipeline
    create_pipeline(pipeline_layout_, g_replacer_sbt_comp, pipeline_sbt_);

    // create BDA pipeline
    create_pipeline(pipeline_layout_, g_replacer_bda_comp, pipeline_bda_);
}

bool VulkanAddressReplacer::create_buffer(size_t                                   num_bytes,
                                          VulkanAddressReplacer::buffer_context_t& buffer_context,
                                          uint32_t                                 usage_flags)
{
    // nothing to do
    if (num_bytes <= buffer_context.num_bytes)
    {
        return true;
    }

    // free previous resources
    buffer_context                    = {};
    buffer_context.resource_allocator = resource_allocator_;
    buffer_context.num_bytes          = num_bytes;

    VkBufferCreateInfo buffer_create_info = {};
    buffer_create_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.usage =
        VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | usage_flags;
    buffer_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_create_info.queueFamilyIndexCount = 0;
    buffer_create_info.size                  = num_bytes;

    VkResult result = resource_allocator_->CreateBufferDirect(
        &buffer_create_info, nullptr, &buffer_context.buffer, &buffer_context.allocator_data);
    if (result != VK_SUCCESS)
    {
        return false;
    }

    VkMemoryRequirements memory_requirements;
    device_table_->GetBufferMemoryRequirements(device_, buffer_context.buffer, &memory_requirements);

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
    alloc_info.allocationSize       = memory_requirements.size;
    alloc_info.memoryTypeIndex      = memory_type_index;

    VkMemoryAllocateFlagsInfo alloc_flags_info = {};
    alloc_flags_info.sType                     = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
    alloc_flags_info.flags                     = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT;
    alloc_info.pNext                           = &alloc_flags_info;

    result = resource_allocator_->AllocateMemoryDirect(
        &alloc_info, nullptr, &buffer_context.device_memory, &buffer_context.memory_data);

    if (result != VK_SUCCESS)
    {
        return false;
    }

    VkMemoryPropertyFlags memory_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    result                             = resource_allocator_->BindBufferMemory(buffer_context.buffer,
                                                   buffer_context.device_memory,
                                                   0,
                                                   buffer_context.allocator_data,
                                                   buffer_context.memory_data,
                                                   &memory_flags);
    if (result != VK_SUCCESS)
    {
        return false;
    }

    // get device-address
    VkBufferDeviceAddressInfo address_info = {};
    address_info.sType                     = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
    address_info.buffer                    = buffer_context.buffer;
    buffer_context.device_address          = get_device_address_fn_(device_, &address_info);

    // map buffer
    result = resource_allocator_->MapResourceMemoryDirect(
        VK_WHOLE_SIZE, 0, &buffer_context.mapped_data, buffer_context.allocator_data);
    return result == VK_SUCCESS;
}

void VulkanAddressReplacer::barrier(VkCommandBuffer      command_buffer,
                                    VkBuffer             buffer,
                                    VkPipelineStageFlags src_stage,
                                    VkAccessFlags        src_access,
                                    VkPipelineStageFlags dst_stage,
                                    VkAccessFlags        dst_access)
{
    VkBufferMemoryBarrier barrier = {};
    barrier.sType                 = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    barrier.buffer                = buffer;
    barrier.offset                = 0;
    barrier.size                  = VK_WHOLE_SIZE;
    barrier.srcQueueFamilyIndex = barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.srcAccessMask                                     = src_access;
    barrier.dstAccessMask                                     = dst_access;

    device_table_->CmdPipelineBarrier(
        command_buffer, src_stage, dst_stage, VkDependencyFlags(0), 0, nullptr, 1, &barrier, 0, nullptr);
}

void swap(VulkanAddressReplacer& lhs, VulkanAddressReplacer& rhs) noexcept
{
    std::swap(lhs.device_table_, rhs.device_table_);
    std::swap(lhs.memory_properties_, rhs.memory_properties_);
    std::swap(lhs.capture_ray_properties_, rhs.capture_ray_properties_);
    std::swap(lhs.replay_ray_properties_, rhs.replay_ray_properties_);
    std::swap(lhs.valid_sbt_alignment_, rhs.valid_sbt_alignment_);
    std::swap(lhs.device_, rhs.device_);
    std::swap(lhs.get_device_address_fn_, rhs.get_device_address_fn_);
    std::swap(lhs.resource_allocator_, rhs.resource_allocator_);
    std::swap(lhs.pipeline_layout_, rhs.pipeline_layout_);
    std::swap(lhs.pipeline_sbt_, rhs.pipeline_sbt_);
    std::swap(lhs.pipeline_bda_, rhs.pipeline_bda_);
    std::swap(lhs.pipeline_context_sbt_, rhs.pipeline_context_sbt_);
    std::swap(lhs.pipeline_context_bda_, rhs.pipeline_context_bda_);
    std::swap(lhs.hashmap_sbt_, rhs.hashmap_sbt_);
    std::swap(lhs.hashmap_bda_, rhs.hashmap_bda_);
    std::swap(lhs.shadow_sbt_map_, rhs.shadow_sbt_map_);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
