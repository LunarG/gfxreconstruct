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
#include "decode/mark_injected_commands.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//! RAII helper to mark injected commands in scope
struct mark_injected_commands_helper_t
{
    mark_injected_commands_helper_t()
    {
        // mark injected commands
        decode::BeginInjectedCommands();
    }

    ~mark_injected_commands_helper_t()
    {
        // mark end of injected commands
        decode::EndInjectedCommands();
    }
};

inline uint32_t aligned_size(uint32_t size, uint32_t alignment)
{
    return (size + alignment - 1) & ~(alignment - 1);
}

inline uint32_t div_up(uint32_t nom, uint32_t denom)
{
    GFXRECON_ASSERT(denom > 0)
    return (nom + denom - 1) / denom;
}

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
    _device_table(device_table)
{
    GFXRECON_ASSERT(device_info != nullptr && device_table != nullptr)

    const VulkanPhysicalDeviceInfo* physical_device_info = object_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    _device                                              = device_info->handle;
    _resource_allocator                                  = device_info->allocator.get();
    _get_device_address_fn_ = physical_device_info->parent_api_version >= VK_API_VERSION_1_2
                                  ? device_table->GetBufferDeviceAddress
                                  : device_table->GetBufferDeviceAddressKHR;

    _get_acceleration_build_sizes_fn              = device_table->GetAccelerationStructureBuildSizesKHR;
    _create_acceleration_structure_fn             = device_table->CreateAccelerationStructureKHR;
    _get_acceleration_structure_device_address_fn = device_table->GetAccelerationStructureDeviceAddressKHR;

    if (physical_device_info != nullptr && physical_device_info->capture_raytracing_properties &&
        physical_device_info->replay_device_info->raytracing_properties)
    {
        _capture_ray_properties = *physical_device_info->capture_raytracing_properties;
        _replay_ray_properties  = *physical_device_info->replay_device_info->raytracing_properties;

        if (_capture_ray_properties.shaderGroupHandleSize != _replay_ray_properties.shaderGroupHandleSize ||
            _capture_ray_properties.shaderGroupHandleAlignment != _replay_ray_properties.shaderGroupHandleAlignment ||
            _capture_ray_properties.shaderGroupBaseAlignment != _replay_ray_properties.shaderGroupBaseAlignment)
        {
            _valid_sbt_alignment = false;
        }

        GFXRECON_ASSERT(physical_device_info->replay_device_info != nullptr);
        GFXRECON_ASSERT(physical_device_info->replay_device_info->memory_properties.has_value());
        _memory_properties = *physical_device_info->replay_device_info->memory_properties;
    }
}

VulkanAddressReplacer::~VulkanAddressReplacer()
{
    mark_injected_commands_helper_t mark_injected_commands_helper;

    // explicitly free resources here, in order to mark destruction API-calls as injected
    _pipeline_context_sbt = {};
    _pipeline_context_bda = {};
    _shadow_sbt_map       = {};

    if (_pipeline_bda != VK_NULL_HANDLE)
    {
        _device_table->DestroyPipeline(_device, _pipeline_bda, nullptr);
    }
    if (_pipeline_sbt != VK_NULL_HANDLE)
    {
        _device_table->DestroyPipeline(_device, _pipeline_sbt, nullptr);
    }
    if (_pipeline_layout != VK_NULL_HANDLE)
    {
        _device_table->DestroyPipelineLayout(_device, _pipeline_layout, nullptr);
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
    GFXRECON_ASSERT(_device_table != nullptr);

    // NOTE: we expect this map to be populated here, but not for older captures (before #1844) using trimming.
    if (group_handle_map.empty())
    {
        // the capture appears to be older and is missing information we require here -> bail out
        return;
    }

    // figure out if the captured group-handles are valid for replay
    bool valid_group_handles = true;

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
    //    valid_group_handles = false;

    if (!_valid_sbt_alignment || !valid_group_handles)
    {
        // mark injected commands
        mark_injected_commands_helper_t mark_injected_commands_helper;

        if (_pipeline_sbt == VK_NULL_HANDLE)
        {
            if (!init_pipeline())
            {
                GFXRECON_LOG_WARNING_ONCE("ProcessCmdTraceRays: internal pipeline-creation failed")
                return;
            }
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
                    GFXRECON_LOG_INFO_ONCE(
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
        _hashmap_sbt.clear();

        for (const auto& [lhs, rhs] : group_handle_map)
        {
            _hashmap_sbt.put(lhs, rhs);
        }

        if (!create_buffer(_hashmap_sbt.get_storage(nullptr), _pipeline_context_sbt.hashmap_storage))
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap-storage-buffer creation failed");
        }
        _hashmap_sbt.get_storage(_pipeline_context_sbt.hashmap_storage.mapped_data);

        // input-handles
        constexpr uint32_t max_num_handles = 4;
        if (!create_buffer(max_num_handles * sizeof(VkDeviceAddress), _pipeline_context_sbt.input_handle_buffer))
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
        }
        auto input_addresses =
            reinterpret_cast<VkDeviceAddress*>(_pipeline_context_sbt.input_handle_buffer.mapped_data);
        uint32_t num_addresses = 0;

        for (const auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
        {
            if (region != nullptr && region->size)
            {
                input_addresses[num_addresses++] = region->deviceAddress;
            }
        }

        replacer_params_t replacer_params = {};
        replacer_params.hashmap.storage   = _pipeline_context_sbt.hashmap_storage.device_address;
        replacer_params.hashmap.size      = _hashmap_sbt.size();
        replacer_params.hashmap.capacity  = _hashmap_sbt.capacity();

        replacer_params.input_handles = _pipeline_context_sbt.input_handle_buffer.device_address;
        replacer_params.num_handles   = num_addresses;

        if (_valid_sbt_alignment)
        {
            GFXRECON_LOG_INFO_ONCE("Replay adjusted mismatching raytracing shader-group-handles");

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
            GFXRECON_LOG_INFO_ONCE(
                "Replay adjusted a mismatching raytracing shader-binding-table using a shadow-buffer");

            // output-handles
            if (!create_buffer(max_num_handles * sizeof(VkDeviceAddress), _pipeline_context_sbt.output_handle_buffer))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
                return;
            }
            // output to shadow-sbt-buffer
            replacer_params.output_handles = _pipeline_context_sbt.output_handle_buffer.device_address;

            // find/create shadow-SBT-buffer
            uint32_t sbt_offset         = 0;
            auto&    shadow_buf_context = _shadow_sbt_map[command_buffer_info->handle];

            const uint32_t handle_size_aligned = aligned_size(_replay_ray_properties.shaderGroupHandleSize,
                                                              _replay_ray_properties.shaderGroupHandleAlignment);

            for (auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
            {
                if (region != nullptr)
                {
                    uint32_t num_handles_limit = region->size / region->stride;
                    uint32_t group_size        = aligned_size(num_handles_limit * handle_size_aligned,
                                                       _replay_ray_properties.shaderGroupBaseAlignment);
                    sbt_offset += group_size;

                    // adjust group-size
                    region->size   = group_size;
                    region->stride = handle_size_aligned;
                }
            }
            // raygen: stride == size
            raygen_sbt->size = raygen_sbt->stride = _replay_ray_properties.shaderGroupBaseAlignment;

            if (!create_buffer(sbt_offset, shadow_buf_context, VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: shadow shader-binding-table creation failed");
                return;
            }

            auto output_addresses =
                reinterpret_cast<VkDeviceAddress*>(_pipeline_context_sbt.output_handle_buffer.mapped_data);
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

        _device_table->CmdBindPipeline(command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, _pipeline_sbt);

        // NOTE: using push-constants here requires us to re-establish the previous data, if any
        _device_table->CmdPushConstants(command_buffer_info->handle,
                                        _pipeline_layout,
                                        VK_SHADER_STAGE_COMPUTE_BIT,
                                        0,
                                        sizeof(replacer_params_t),
                                        &replacer_params);
        // run a single workgroup
        constexpr uint32_t wg_size = 32;
        _device_table->CmdDispatch(command_buffer_info->handle, div_up(replacer_params.num_handles, wg_size), 1, 1);

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
            _device_table->CmdPushConstants(command_buffer_info->handle,
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
    GFXRECON_ASSERT(_device_table != nullptr);

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

        // check capture/replay acceleration-structure buffer-sizes
        {
            VkAccelerationStructureBuildSizesInfoKHR build_size_info = {};
            build_size_info.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR;

            std::vector<uint32_t> primitive_counts(build_geometry_info.geometryCount);
            for (uint32_t j = 0; j < build_geometry_info.geometryCount; ++j)
            {
                primitive_counts[j] = range_info->primitiveCount;
            }
            _get_acceleration_build_sizes_fn(_device,
                                             VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR,
                                             &build_geometry_info,
                                             primitive_counts.data(),
                                             &build_size_info);

            // retrieve VkAccelerationStructureKHR -> VkBuffer -> check/correct size
            auto* acceleration_structure_info =
                address_tracker.GetAccelerationStructureByHandle(build_geometry_info.dstAccelerationStructure);
            GFXRECON_ASSERT(acceleration_structure_info != nullptr)
            auto* buffer_info = address_tracker.GetBufferByHandle(acceleration_structure_info->buffer);
            GFXRECON_ASSERT(buffer_info != nullptr)

            // fails on some!? captures
            auto* scratch_buffer_info =
                address_tracker.GetBufferByCaptureDeviceAddress(build_geometry_info.scratchData.deviceAddress);
            //            GFXRECON_ASSERT(scratch_buffer_info != nullptr)

            if (buffer_info != nullptr && buffer_info->size < build_size_info.accelerationStructureSize)
            {
                GFXRECON_LOG_WARNING("VulkanAddressReplacer::ProcessCmdBuildAccelerationStructuresKHR: buffer-size is "
                                     "too small (%d < %d)",
                                     buffer_info->size,
                                     build_size_info.accelerationStructureSize);

                auto& replacment_as = _shadow_as_map[build_geometry_info.dstAccelerationStructure];

                if (replacment_as.handle == VK_NULL_HANDLE)
                {
                    // create a replacement acceleration-structure with proper sized buffer
                    bool success = create_buffer(build_size_info.accelerationStructureSize,
                                                 replacment_as.storage,
                                                 VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR,
                                                 false);

                    if (!success)
                    {
                        GFXRECON_LOG_ERROR("ProcessCmdBuildAccelerationStructuresKHR: shadow-buffer creation failed");
                        return;
                    }

                    VkAccelerationStructureCreateInfoKHR as_create_info = {};
                    as_create_info.sType  = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR;
                    as_create_info.buffer = replacment_as.storage.buffer;
                    as_create_info.size   = build_size_info.accelerationStructureSize;
                    as_create_info.type   = build_geometry_info.type;

                    VkResult res =
                        _create_acceleration_structure_fn(_device, &as_create_info, nullptr, &replacment_as.handle);

                    if (res != VK_SUCCESS || replacment_as.handle == VK_NULL_HANDLE)
                    {
                        GFXRECON_LOG_ERROR(
                            "ProcessCmdBuildAccelerationStructuresKHR: shadow acceleration-structure creation failed");
                        return;
                    }
                    VkAccelerationStructureDeviceAddressInfoKHR acceleration_address_info = {};
                    acceleration_address_info.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR;
                    acceleration_address_info.accelerationStructure = replacment_as.handle;
                    replacment_as.address =
                        _get_acceleration_structure_device_address_fn(_device, &acceleration_address_info);
                    GFXRECON_ASSERT(replacment_as.address != 0)

                    // hot swap acceleration-structure handle
                    build_geometry_info.dstAccelerationStructure = replacment_as.handle;
                }

                // determine required size of scratch-buffer
                uint32_t scratch_size = build_geometry_info.mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR
                                            ? build_size_info.buildScratchSize
                                            : build_size_info.updateScratchSize;

                //                if (scratch_buffer_info != nullptr && scratch_buffer_info->size < scratch_size)
                {
                    // create a replacement scratch-buffer
                    bool success = create_buffer(scratch_size, replacment_as.scratch, 0, false);

                    if (!success)
                    {
                        GFXRECON_LOG_ERROR("ProcessCmdBuildAccelerationStructuresKHR: scratch-buffer creation failed");
                        return;
                    }

                    // hot swap scratch-buffer
                    build_geometry_info.scratchData.deviceAddress = replacment_as.scratch.device_address;
                }
            }
        }

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
        _hashmap_bda.clear();
        auto acceleration_structure_map = address_tracker.GetAccelerationStructureDeviceAddressMap();
        for (const auto& [capture_address, replay_address] : acceleration_structure_map)
        {
            if (force_replace || capture_address != replay_address)
            {
                // store addresses we will need to replace
                _hashmap_bda.put(capture_address, replay_address);
            }
        }

        if (!_hashmap_bda.empty())
        {
            // mark injected commands
            mark_injected_commands_helper_t mark_injected_commands_helper;

            if (_pipeline_bda == VK_NULL_HANDLE)
            {
                if (!init_pipeline())
                {
                    GFXRECON_LOG_WARNING_ONCE(
                        "ProcessCmdBuildAccelerationStructuresKHR: internal pipeline-creation failed")
                    return;
                }
            }

            if (!create_buffer(_hashmap_bda.get_storage(nullptr), _pipeline_context_bda.hashmap_storage))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap-storage-buffer creation failed");
            }
            _hashmap_bda.get_storage(_pipeline_context_bda.hashmap_storage.mapped_data);

            uint32_t num_bytes = addresses_to_replace.size() * sizeof(VkDeviceAddress);

            if (!create_buffer(num_bytes, _pipeline_context_bda.input_handle_buffer))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
            }
            memcpy(_pipeline_context_bda.input_handle_buffer.mapped_data, addresses_to_replace.data(), num_bytes);

            replacer_params_t replacer_params = {};
            replacer_params.hashmap.storage   = _pipeline_context_bda.hashmap_storage.device_address;
            replacer_params.hashmap.size      = _hashmap_bda.size();
            replacer_params.hashmap.capacity  = _hashmap_bda.capacity();

            // in-place
            replacer_params.input_handles  = _pipeline_context_bda.input_handle_buffer.device_address;
            replacer_params.output_handles = _pipeline_context_bda.input_handle_buffer.device_address;

            replacer_params.num_handles = addresses_to_replace.size();

            _device_table->CmdBindPipeline(command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, _pipeline_bda);

            // NOTE: using push-constants here requires us to re-establish the previous data, if any
            _device_table->CmdPushConstants(command_buffer_info->handle,
                                            _pipeline_layout,
                                            VK_SHADER_STAGE_COMPUTE_BIT,
                                            0,
                                            sizeof(replacer_params_t),
                                            &replacer_params);
            // run a single workgroup
            constexpr uint32_t wg_size = 32;
            _device_table->CmdDispatch(command_buffer_info->handle, div_up(replacer_params.num_handles, wg_size), 1, 1);

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
                _device_table->CmdPushConstants(command_buffer_info->handle,
                                                command_buffer_info->push_constant_pipeline_layout,
                                                command_buffer_info->push_constant_stage_flags,
                                                0,
                                                command_buffer_info->push_constant_data.size(),
                                                command_buffer_info->push_constant_data.data());
            }
        } // !hashmap_bda_.empty()
    }
}

bool VulkanAddressReplacer::init_pipeline()
{
    if (_pipeline_sbt != VK_NULL_HANDLE)
    {
        // assume already initialized
        return true;
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

    VkResult result = _device_table->CreatePipelineLayout(_device, &pipeline_layout_info, nullptr, &_pipeline_layout);

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
            _device_table->CreateShaderModule(_device, &shader_module_create_info, nullptr, &compute_module);

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

        result = _device_table->CreateComputePipelines(
            _device, VK_NULL_HANDLE, 1, &pipeline_create_info, VK_NULL_HANDLE, &out_pipeline);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: pipeline creation failed");
        }

        if (compute_module != VK_NULL_HANDLE)
        {
            _device_table->DestroyShaderModule(_device, compute_module, nullptr);
        }
        return result;
    };

    // create SBT pipeline
    if (create_pipeline(_pipeline_layout, g_replacer_sbt_comp, _pipeline_sbt) != VK_SUCCESS)
    {
        return false;
    }

    // create BDA pipeline
    if (create_pipeline(_pipeline_layout, g_replacer_bda_comp, _pipeline_bda) != VK_SUCCESS)
    {
        return false;
    }
    return true;
}

bool VulkanAddressReplacer::create_buffer(size_t                                   num_bytes,
                                          VulkanAddressReplacer::buffer_context_t& buffer_context,
                                          uint32_t                                 usage_flags,
                                          bool                                     use_host_mem)
{
    // nothing to do
    if (num_bytes <= buffer_context.num_bytes)
    {
        return true;
    }

    // free previous resources
    buffer_context                    = {};
    buffer_context.resource_allocator = _resource_allocator;
    buffer_context.num_bytes          = num_bytes;

    VkBufferCreateInfo buffer_create_info = {};
    buffer_create_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.usage =
        VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | usage_flags;
    buffer_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_create_info.queueFamilyIndexCount = 0;
    buffer_create_info.size                  = num_bytes;

    VkResult result = _resource_allocator->CreateBufferDirect(
        &buffer_create_info, nullptr, &buffer_context.buffer, &buffer_context.allocator_data);
    if (result != VK_SUCCESS)
    {
        return false;
    }

    VkMemoryRequirements memory_requirements;
    _device_table->GetBufferMemoryRequirements(_device, buffer_context.buffer, &memory_requirements);

    VkMemoryPropertyFlags memory_property_flags =
        use_host_mem ? VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT
                     : VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;

    uint32_t memory_type_index =
        graphics::GetMemoryTypeIndex(_memory_properties, memory_requirements.memoryTypeBits, memory_property_flags);

    if (memory_type_index == std::numeric_limits<uint32_t>::max())
    {
        /* fallback to coherent */
        memory_type_index =
            graphics::GetMemoryTypeIndex(_memory_properties, memory_requirements.memoryTypeBits, memory_property_flags);
    }

    GFXRECON_ASSERT(memory_type_index != std::numeric_limits<uint32_t>::max());

    VkMemoryAllocateInfo alloc_info = {};
    alloc_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    alloc_info.allocationSize       = memory_requirements.size;
    alloc_info.memoryTypeIndex      = memory_type_index;

    VkMemoryAllocateFlagsInfo alloc_flags_info = {};
    alloc_flags_info.sType                     = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
    alloc_flags_info.flags                     = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT;
    alloc_info.pNext                           = &alloc_flags_info;

    result = _resource_allocator->AllocateMemoryDirect(
        &alloc_info, nullptr, &buffer_context.device_memory, &buffer_context.memory_data);

    if (result != VK_SUCCESS)
    {
        return false;
    }

    VkMemoryPropertyFlags memory_flags = VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT;
    result                             = _resource_allocator->BindBufferMemory(buffer_context.buffer,
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
    buffer_context.device_address          = _get_device_address_fn_(_device, &address_info);
    GFXRECON_ASSERT(buffer_context.device_address != 0);

    if (use_host_mem)
    {
        // map buffer
        result = _resource_allocator->MapResourceMemoryDirect(
            VK_WHOLE_SIZE, 0, &buffer_context.mapped_data, buffer_context.allocator_data);
        return result == VK_SUCCESS;
    }
    return true;
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

    _device_table->CmdPipelineBarrier(
        command_buffer, src_stage, dst_stage, VkDependencyFlags(0), 0, nullptr, 1, &barrier, 0, nullptr);
}

void VulkanAddressReplacer::DestroyShadowResources(VkAccelerationStructureKHR handle)
{
    auto remove_it = _shadow_as_map.find(handle);

    if (remove_it != _shadow_as_map.end())
    {
        mark_injected_commands_helper_t mark_injected_commands_helper;
        _shadow_as_map.erase(remove_it);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
