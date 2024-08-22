/*
** Copyright (c) 2023 LunarG, Inc.
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
#include "graphics/vulkan_resources_util.h"
#include "decode/vulkan_acceleration_structure_builder.h"
#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanAccelerationStructureBuilder::VulkanAccelerationStructureBuilder(
    const encode::VulkanDeviceTable*                 device_table,
    const PhysicalDeviceInfo*                        physical_device_info,
    VkDevice                                         device,
    VulkanResourceAllocator*                         allocator,
    const VkPhysicalDeviceMemoryProperties&          memory_properties,
    VkPhysicalDeviceRayTracingPipelinePropertiesKHR  ray_tracing_pipeline_properties,
    VkPhysicalDeviceAccelerationStructureFeaturesKHR acceleration_structure_features,
    VulkanBufferTracker*                             buffer_tracker) :
    device_(device),
    physical_device_info_(physical_device_info), allocator_(allocator),
    physical_device_memory_properties_(memory_properties),
    raytracing_pipeline_properties_(ray_tracing_pipeline_properties.shaderGroupHandleSize,
                                    ray_tracing_pipeline_properties.shaderGroupHandleAlignment),
    acceleration_structure_features_(acceleration_structure_features), buffer_tracker_(buffer_tracker),
    buffers_(buffer_tracker_->GetBuffers()),
    internal_buffer_manager_(
        device_table, physical_device_info, device_, allocator_, physical_device_memory_properties_)
{
    InitializeFunctionPointers(device_table);
    InitializeInternalExecObjects();
}

VulkanAccelerationStructureBuilder::~VulkanAccelerationStructureBuilder()
{
    for (auto& entry : acceleration_structures_)
    {
        if (entry->replacement_acceleration_struct_)
        {
            functions_.destroy_acceleration_structure(
                device_, *entry->replacement_acceleration_struct_->handles_.begin(), nullptr);
        }
    }
}

// On creation of the acceleration structure, start tracking it by handle and original device address
void VulkanAccelerationStructureBuilder::OnCreateAccelerationStructure(VkAccelerationStructureKHR     handle,
                                                                       VkDeviceAddress                device_address,
                                                                       VkAccelerationStructureTypeKHR type)
{
    auto result = std::find_if(acceleration_structures_.begin(),
                               acceleration_structures_.end(),
                               [&device_address](const std::unique_ptr<AccelerationStructureEntry>& entry) {
                                   return entry->original_address_ == device_address;
                               });
    if (result == acceleration_structures_.end())
    {
        acceleration_structures_.emplace_back(std::make_unique<AccelerationStructureEntry>(
            device_address, 0, handle, type, VkAccelerationStructureBuildSizesInfoKHR()));
    }
    else
    {
        result->get()->handles_.insert(handle);
    }
}

// On destroy acceleration structure, clean up the internal replacement structure
void VulkanAccelerationStructureBuilder::OnDestroyAccelerationStructure(
    const AccelerationStructureKHRInfo* acceleration_structure_info)
{
    auto result =
        std::find_if(acceleration_structures_.begin(),
                     acceleration_structures_.end(),
                     [&acceleration_structure_info](const std::unique_ptr<AccelerationStructureEntry>& entry) {
                         return entry->IsAlias(acceleration_structure_info->handle);
                     });

    GFXRECON_ASSERT(result != acceleration_structures_.end());

    if (result->get()->replacement_acceleration_struct_ && result->get()->handles_.size() == 1)
    {
        const auto& real_as = result->get()->replacement_acceleration_struct_;
        functions_.destroy_acceleration_structure(device_, *real_as->handles_.begin(), nullptr);
        acceleration_structures_.erase(result);
    }
    else
    {
        result->get()->handles_.erase(acceleration_structure_info->handle);
    }
}

void VulkanAccelerationStructureBuilder::ProcessBuildVulkanAccelerationStructuresMetaCommand(
    uint32_t                                                      info_count,
    VkAccelerationStructureBuildGeometryInfoKHR*                  geometry_infos,
    VkAccelerationStructureBuildRangeInfoKHR**                    range_infos,
    std::vector<std::vector<VkAccelerationStructureInstanceKHR>>& instance_buffers_data)
{
    BeginCommandBuffer();
    CmdBuildAccelerationStructures(cmd_execute_obj_.command_buffer_, info_count, geometry_infos, range_infos);
    ExecuteCommandBuffer();
}

void VulkanAccelerationStructureBuilder::ProcessCopyVulkanAccelerationStructuresMetaCommand(
    uint32_t info_count, VkCopyAccelerationStructureInfoKHR* copy_infos)
{
    BeginCommandBuffer();
    for (uint32_t i = 0; i < info_count; ++i)
    {
        CmdCopyAccelerationStructure(cmd_execute_obj_.command_buffer_, &copy_infos[i]);
    }
    ExecuteCommandBuffer();
}

void VulkanAccelerationStructureBuilder::ProcessVulkanAccelerationStructuresWritePropertiesMetaCommand(
    VkQueryType query_type, VkAccelerationStructureKHR acceleration_structure)
{
    BeginCommandBuffer();

    VkQueryPool query_pool;

    VkQueryPoolCreateInfo pool_info{};
    pool_info.sType              = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
    pool_info.flags              = 0;
    pool_info.queryType          = VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR;
    pool_info.queryCount         = 1;
    pool_info.pipelineStatistics = 0;
    pool_info.pNext              = nullptr;

    functions_.create_query_pool(cmd_execute_obj_.device_, &pool_info, nullptr, &query_pool);

    CmdWriteAccelerationStructuresProperties(
        cmd_execute_obj_.command_buffer_, 1, &acceleration_structure, query_type, query_pool, 0);

    ExecuteCommandBuffer();

    DeviceInfo device_info;
    device_info.handle = cmd_execute_obj_.device_;
    QueryPoolInfo query_pool_info;
    query_pool_info.handle = query_pool;
    OnGetQueryPoolResults(&device_info, &query_pool_info);
}

void VulkanAccelerationStructureBuilder::OnDestroyBuffer(const BufferInfo* buffer_info)
{
    scratch_double_buffer_.scratches_previous.erase(buffer_info->capture_id);
    scratch_double_buffer_.scratches_current.erase(buffer_info->capture_id);
}

// overwrites acceleration structure capture device address with runtime device address
bool VulkanAccelerationStructureBuilder::UpdateAccelerationStructDeviceAddress(VkDeviceAddress& address)
{
    if (address == 0)
        return true;
    // Try to find the entry in the internal map by capture address of the acceleration structure
    auto as = std::find_if(acceleration_structures_.begin(), acceleration_structures_.end(), [&](const auto& entry) {
        if (entry->original_address_ == address || entry->new_address_ == address)
        {
            return true;
        }
        else if (entry->replacement_acceleration_struct_ &&
                 entry->replacement_acceleration_struct_->new_address_ == address)
        {
            return true;
        }
        return false;
    });

    if (as != acceleration_structures_.end())
    {
        // If the entry has a replacement acceleration structure, we need to use it's handles
        // and addresses instead of the capture time structure
        if ((*as)->replacement_acceleration_struct_)
        {
            address = (*as)->replacement_acceleration_struct_->new_address_;
        }
        else
        {
            address = (*as)->new_address_;
        }
        return true;
    }
    else
    {
        GFXRECON_LOG_DEBUG("Acceleration structure address not found: %" PRIu64, address);
        return false;
    }
}

void VulkanAccelerationStructureBuilder::UpdateDescriptorSets(uint32_t              descriptor_write_count,
                                                              VkWriteDescriptorSet* descriptor_writes,
                                                              uint32_t              descriptor_copy_count,
                                                              VkCopyDescriptorSet*  descriptor_copies)
{
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_copy_count);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_copies);

    // Check whether this descriptor update contains acceleration structures
    VkWriteDescriptorSetAccelerationStructureKHR* acceleration_structure_write = nullptr;
    uint32_t                                      index                        = 0;
    for (uint32_t i = 0; i < descriptor_write_count; ++i)
    {
        if (descriptor_writes[i].descriptorType != VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
        {
            continue;
        }
        // Find the relevant data in the pNext chain
        const VkBaseOutStructure* structure = reinterpret_cast<const VkBaseOutStructure*>(descriptor_writes[i].pNext);
        while (structure != nullptr)
        {
            if (structure->sType == VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR)
            {
                acceleration_structure_write = const_cast<VkWriteDescriptorSetAccelerationStructureKHR*>(
                    reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(structure));
                index = i;
                break;
            }
            else
            {
                structure = structure->pNext;
            }
        }
    }

    if (!acceleration_structure_write)
    {
        return;
    }

    // Replace the handles here, or store the updates for later
    for (uint32_t i = 0; i < acceleration_structure_write->accelerationStructureCount; ++i)
    {
        AccelerationStructureEntry* entry =
            GetAccelerationStructureEntry(acceleration_structure_write->pAccelerationStructures[i]);
        if (!entry)
        {
            GFXRECON_LOG_DEBUG("Trying to update the descriptor with untracked acceleration structure");
            throw std::runtime_error("Trying to update the descriptor with untracked acceleration structure");
        }
        if (entry->replacement_acceleration_struct_)
        {
            // Replace the handle with the actual handle, in which the built structure is
            const_cast<VkAccelerationStructureKHR*>(acceleration_structure_write->pAccelerationStructures)[i] =
                *entry->replacement_acceleration_struct_->handles_.begin();
        }
        else if (entry->new_address_ == 0)
        {
            // In case the handle is written to shader before the acceleration structure is built
            // We will store the data we need to update, and do it on queue submit
            // This way, the handle would be replaced by actual
            cached_descriptor_write_.emplace(*entry->handles_.begin(), descriptor_writes[index]);
        }
    }
}

void VulkanAccelerationStructureBuilder::UpdateDescriptorSetWithTemplateKHR(
    VkDescriptorSet                                    descriptor_set,
    const VkDescriptorUpdateTemplateEntryKHR&          template_update_entry,
    gfxrecon::decode::DescriptorUpdateTemplateDecoder* data)
{
    const size_t accel_struct_count = data->GetAccelerationStructureKHRCount();
    for (size_t i = 0; i < accel_struct_count; ++i)
    {
        VkAccelerationStructureKHR& accel_struct = data->GetAccelerationStructureKHRPointer()[i];

        AccelerationStructureEntry* entry = GetAccelerationStructureEntry(accel_struct);
        if (!entry)
        {
            GFXRECON_LOG_DEBUG("Trying to update the descriptor with untracked acceleration structure");
            throw std::runtime_error("Trying to update the descriptor with untracked acceleration structure");
        }
        if (entry->replacement_acceleration_struct_)
        {
            // Replace the handle with the actual handle, in which the built structure is
            accel_struct = *entry->replacement_acceleration_struct_->handles_.begin();
        }
        else if (entry->new_address_ == 0)
        {
            // In case the handle is written to shader before the acceleration structure is built
            // We will store the data we need to update, and do it on queue submit
            // This way, the handle would be replaced by actual
            cached_descriptor_write_.emplace(std::piecewise_construct,
                                             std::forward_as_tuple(*entry->handles_.begin()),
                                             std::forward_as_tuple(descriptor_set, template_update_entry, data));
        }
    }
}

// Store the update for the BLAS device addresses in the geometry for TLAS to contain actual addresses
void VulkanAccelerationStructureBuilder::UpdateInstanceBuffer(
    VkCommandBuffer                                  command_buffer,
    VkAccelerationStructureGeometryInstancesDataKHR& instances,
    const VkAccelerationStructureBuildRangeInfoKHR&  build_range)
{
    if (instances.arrayOfPointers)
    {
        throw std::runtime_error("Unsupported instances.arrayOfPointers");
    }
    // Update the device address of the buffer itself in the geometry info
    buffer_tracker_->UpdateBufferDeviceAddress(instances.data.deviceAddress);

    if (build_range.primitiveCount == 0)
    {
        return;
    }

    // Find the buffer by updated address, and record offset if any
    BufferInfo*  instance_buffer = buffer_tracker_->GetBufferByReplayDeviceAddress(instances.data.deviceAddress);
    VkDeviceSize offset =
        instances.data.deviceAddress - buffer_tracker_->GetBufferDeviceAddress(instance_buffer->handle);

    // This is a workaround for FillMemoryCommand overwriting any substitutions we may insert for BLAS device addresses
    // Instead of writing at command recording time, store the update and write on vkQueueSubmit, after
    // FillMemory command
    instance_buffer_updates_[command_buffer].push_back(
        std::make_tuple(instance_buffer->allocator_data, offset, build_range));

    auto instance_buffers_staging_update_itr = instance_buffer_staging_updates_.find(command_buffer);

    if (instance_buffers_staging_update_itr != instance_buffer_staging_updates_.end())
    {
        auto& staging_update_vector = instance_buffers_staging_update_itr->second;

        for (auto it = staging_update_vector.begin(); it != staging_update_vector.end(); it++)
        {
            VkBuffer dst_buffer = std::get<2>(*it);
            if (dst_buffer == instance_buffer->handle)
            {
                GFXRECON_LOG_DEBUG("Stagging write of instance buffer has been detected");
                VulkanResourceAllocator::ResourceData src_buffer_allocator_data = std::get<0>(*it);
                VkDeviceSize                          src_offset                = std::get<1>(*it);

                instance_buffer_updates_[command_buffer].pop_back();
                instance_buffer_updates_[command_buffer].push_back(
                    std::make_tuple(src_buffer_allocator_data, src_offset, build_range));

                staging_update_vector.erase(it);
                break;
            }
        }
    }
}

// Perform the actual update of the BLAS device addresses
void VulkanAccelerationStructureBuilder::UpdateInstanceBufferContent(
    VulkanResourceAllocator::ResourceData    instance_buffer_allocator_data,
    VkDeviceSize                             offset,
    VkAccelerationStructureBuildRangeInfoKHR build_range)
{
    uint8_t* data;
    uint32_t size = build_range.primitiveCount * sizeof(VkAccelerationStructureInstanceKHR);

    VkResult mapping_result =
        allocator_->MapResourceMemoryDirect(size, 0, (void**)&data, instance_buffer_allocator_data);
    GFXRECON_ASSERT(mapping_result == VK_SUCCESS);
    data += offset + build_range.primitiveOffset;

    VkAccelerationStructureInstanceKHR* instance_data = reinterpret_cast<VkAccelerationStructureInstanceKHR*>(data);

    // All or nothing strategy - we should always find a device address
    // This way, we do not perform a modificaction of real device memory until we are sure that it is valid
    std::vector<VkAccelerationStructureInstanceKHR> copy(instance_data, instance_data + build_range.primitiveCount);
    bool                                            success = true;
    for (uint32_t instance_index = 0; success && (instance_index < build_range.primitiveCount); ++instance_index)
    {
        success = UpdateAccelerationStructDeviceAddress(copy[instance_index].accelerationStructureReference);
    }
    if (success)
    {
        util::platform::MemoryCopy(instance_data, size, copy.data(), size);
    }
    else
    {
        GFXRECON_LOG_DEBUG("Some of the instance buffer BLAS addresses failed to update");
    }
    allocator_->UnmapResourceMemoryDirect(instance_buffer_allocator_data);
}

void VulkanAccelerationStructureBuilder::InitializeFunctionPointers(const encode::VulkanDeviceTable* device_table)
{
    functions_.get_acceleration_structure_build_sizes       = device_table->GetAccelerationStructureBuildSizesKHR,
    functions_.create_acceleration_structure                = device_table->CreateAccelerationStructureKHR,
    functions_.cmd_build_acceleration_structures            = device_table->CmdBuildAccelerationStructuresKHR;
    functions_.get_acceleration_structure_device_address    = device_table->GetAccelerationStructureDeviceAddressKHR;
    functions_.cmd_copy_acceleration_structure              = device_table->CmdCopyAccelerationStructureKHR;
    functions_.cmd_write_acceleration_structures_properties = device_table->CmdWriteAccelerationStructuresPropertiesKHR;
    functions_.destroy_acceleration_structure               = device_table->DestroyAccelerationStructureKHR;
    functions_.create_command_pool                          = device_table->CreateCommandPool;
    functions_.destroy_command_pool                         = device_table->DestroyCommandPool;
    functions_.allocate_command_buffers                     = device_table->AllocateCommandBuffers;
    functions_.free_command_buffers                         = device_table->FreeCommandBuffers;
    functions_.get_device_queue                             = device_table->GetDeviceQueue;
    functions_.begin_command_buffer                         = device_table->BeginCommandBuffer;
    functions_.end_command_buffer                           = device_table->EndCommandBuffer;
    functions_.reset_command_buffer                         = device_table->ResetCommandBuffer;
    functions_.queue_submit                                 = device_table->QueueSubmit;
    functions_.queue_wait_idle                              = device_table->QueueWaitIdle;
    functions_.update_descriptor_sets                       = device_table->UpdateDescriptorSets;
    functions_.get_query_pool_results                       = device_table->GetQueryPoolResults;
    functions_.cmd_copy_query_pool_results                  = device_table->CmdCopyQueryPoolResults;
    functions_.cmd_pipeline_barrier                         = device_table->CmdPipelineBarrier;
    functions_.create_query_pool                            = device_table->CreateQueryPool;
}

void VulkanAccelerationStructureBuilder::InitializeInternalExecObjects()
{
    VkResult result;

    cmd_execute_obj_.device_               = device_;
    cmd_execute_obj_.free_command_buffers_ = functions_.free_command_buffers;
    cmd_execute_obj_.destroy_command_pool_ = functions_.destroy_command_pool;

    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO, nullptr };
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = 0;

    result = functions_.create_command_pool(device_, &create_info, nullptr, &cmd_execute_obj_.pool_);
    GFXRECON_ASSERT(result == VK_SUCCESS);

    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.pNext                       = nullptr;
    alloc_info.commandPool                 = cmd_execute_obj_.pool_;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;

    result = functions_.allocate_command_buffers(device_, &alloc_info, &cmd_execute_obj_.command_buffer_);
    GFXRECON_ASSERT(result == VK_SUCCESS);

    functions_.get_device_queue(device_, 0, 0, &cmd_execute_obj_.queue_);
    cmd_execute_obj_.initialized_ = true;
}

void VulkanAccelerationStructureBuilder::BeginCommandBuffer()
{
    functions_.reset_command_buffer(cmd_execute_obj_.command_buffer_, 0);

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.pNext                    = nullptr;
    begin_info.flags                    = 0;
    begin_info.pInheritanceInfo         = nullptr;

    VkResult result = functions_.begin_command_buffer(cmd_execute_obj_.command_buffer_, &begin_info);
    GFXRECON_ASSERT(result == VK_SUCCESS);
}

void VulkanAccelerationStructureBuilder::ExecuteCommandBuffer()
{
    functions_.end_command_buffer(cmd_execute_obj_.command_buffer_);

    VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = 0;
    submit_info.pWaitSemaphores      = nullptr;
    submit_info.pWaitDstStageMask    = nullptr;
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &cmd_execute_obj_.command_buffer_;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

    OnQueueSubmit(cmd_execute_obj_.queue_, 1, &submit_info);
    VkResult result = functions_.queue_submit(cmd_execute_obj_.queue_, 1, &submit_info, VK_NULL_HANDLE);
    GFXRECON_ASSERT(result == VK_SUCCESS);
    result = functions_.queue_wait_idle(cmd_execute_obj_.queue_);
    GFXRECON_ASSERT(result == VK_SUCCESS);
}

// For each geometry build info, we want to get the actual addresses of the geometry buffers
void VulkanAccelerationStructureBuilder::UpdateDeviceAddress(
    VkCommandBuffer                              command_buffer,
    VkAccelerationStructureBuildGeometryInfoKHR& build_geometry,
    VkAccelerationStructureBuildRangeInfoKHR*    range_infos)
{
    for (uint32_t geometry_index = 0; geometry_index < build_geometry.geometryCount; ++geometry_index)
    {
        auto& geometry_data =
            const_cast<VkAccelerationStructureGeometryKHR*>(build_geometry.pGeometries)[geometry_index];
        if (geometry_data.sType != VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR)
        {
            continue;
        }
        switch (geometry_data.geometryType)
        {
            case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
            {
                auto& triangles = geometry_data.geometry.triangles;
                buffer_tracker_->UpdateBufferDeviceAddress(triangles.vertexData.deviceAddress);
                buffer_tracker_->UpdateBufferDeviceAddress(triangles.indexData.deviceAddress);
                buffer_tracker_->UpdateBufferDeviceAddress(triangles.transformData.deviceAddress);
                break;
            }
            case VK_GEOMETRY_TYPE_INSTANCES_KHR:
            {
                auto& instances = geometry_data.geometry.instances;
                UpdateInstanceBuffer(command_buffer, instances, range_infos[geometry_index]);
                break;
            }
            case VK_GEOMETRY_TYPE_AABBS_KHR:
            {
                auto& aabbs = geometry_data.geometry.aabbs;
                buffer_tracker_->UpdateBufferDeviceAddress(aabbs.data.deviceAddress);
                break;
            }
            default:
            {
                GFXRECON_LOG_ERROR("Unexpected geometry type");
                break;
            }
        }
    }
}

VulkanAccelerationStructureBuilder::AccelerationStructureEntry*
VulkanAccelerationStructureBuilder::GetAccelerationStructureEntry(VkAccelerationStructureKHR acceleration_struct)
{
    auto entry = std::find_if(acceleration_structures_.begin(), acceleration_structures_.end(), [&](auto& entry) {
        return entry->IsAlias(acceleration_struct);
    });
    if (entry != acceleration_structures_.end())
    {
        return entry->get();
    }
    else
    {
        return nullptr;
    }
}

void VulkanAccelerationStructureBuilder::CmdBuildAccelerationStructures(
    VkCommandBuffer                              command_buffer,
    uint32_t                                     info_count,
    VkAccelerationStructureBuildGeometryInfoKHR* geometry_infos,
    VkAccelerationStructureBuildRangeInfoKHR**   range_infos)
{
    // The main issue is that on different devices or driver versions, the
    // size for scratch and storage buffer can be different.
    // Therefore, we create the replacement structure with buffers of the replay-time
    // required sizes. This concerns both build modes, as well as copy
    for (uint32_t i = 0; i < info_count; ++i)
    {
        const auto& mode = geometry_infos[i].mode;

        AccelerationStructureEntry* dst_entry =
            GetAccelerationStructureEntry(geometry_infos[i].dstAccelerationStructure);
        GFXRECON_ASSERT(dst_entry);
        VkAccelerationStructureBuildSizesInfoKHR size_info =
            GetAccelerationStructureSizeInfo(&geometry_infos[i], range_infos[i]);
        VkDeviceSize scratch_size = 0;
        if (mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR)
        {
            // We want to allocate the storage for replacement only once
            if (!dst_entry->replacement_acceleration_struct_)
            {
                // Create the replacement entry and link it to original one
                std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper> storage =
                    internal_buffer_manager_.CreateBuffer(size_info.accelerationStructureSize,
                                                          VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR |
                                                              VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT);
                VkAccelerationStructureKHR replacement_as =
                    CreateAccelerationStructure(geometry_infos[i], range_infos[i], size_info, storage->info_.handle);

                // Store acceleration structure data
                auto replacement_as_address                 = GetAccelerationStructureDeviceAddress(replacement_as);
                dst_entry->replacement_acceleration_struct_ = std::make_unique<AccelerationStructureEntry>(
                    0, replacement_as_address, replacement_as, geometry_infos[i].type, size_info);
                dst_entry->replacement_acceleration_struct_->storage_ = std::move(storage);

                dst_entry->new_address_ =
                    GetAccelerationStructureDeviceAddress(geometry_infos[i].dstAccelerationStructure);
            }
            // Update the handle in the geometry info to point to actual structure
            geometry_infos[i].dstAccelerationStructure = *dst_entry->replacement_acceleration_struct_->handles_.begin();
            scratch_size                               = size_info.buildScratchSize;
        }
        else if (mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR)
        {
            // In case of update, we potentially need to update both handles
            // The src entry MUST have been built earlier, hence it must have a replacement structure
            auto src_entry = GetAccelerationStructureEntry(geometry_infos[i].srcAccelerationStructure);
            GFXRECON_ASSERT(src_entry);
            GFXRECON_ASSERT(src_entry->replacement_acceleration_struct_.get() != nullptr);
            GFXRECON_ASSERT(*src_entry->replacement_acceleration_struct_->handles_.begin() != 0);

            // Build the destination structure, if not already built
            if (!dst_entry->replacement_acceleration_struct_)
            {
                std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper> storage =
                    internal_buffer_manager_.CreateBuffer(size_info.accelerationStructureSize,
                                                          VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR |
                                                              VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT);
                VkAccelerationStructureKHR replacement_as =
                    CreateAccelerationStructure(geometry_infos[i], range_infos[i], size_info, storage->info_.handle);

                // Store acceleration structure data
                auto replacement_as_address                 = GetAccelerationStructureDeviceAddress(replacement_as);
                dst_entry->replacement_acceleration_struct_ = std::make_unique<AccelerationStructureEntry>(
                    0, replacement_as_address, replacement_as, geometry_infos[i].type, size_info);
                dst_entry->replacement_acceleration_struct_->storage_ = std::move(storage);

                dst_entry->new_address_ =
                    GetAccelerationStructureDeviceAddress(geometry_infos[i].dstAccelerationStructure);
            }
            geometry_infos[i].srcAccelerationStructure = *src_entry->replacement_acceleration_struct_->handles_.begin();
            geometry_infos[i].dstAccelerationStructure = *dst_entry->replacement_acceleration_struct_->handles_.begin();
            scratch_size                               = size_info.updateScratchSize;
        }

        UpdateScratchDeviceAddress(geometry_infos[i], scratch_size);
        UpdateDeviceAddress(command_buffer, geometry_infos[i], range_infos[i]);
    }

    functions_.cmd_build_acceleration_structures(command_buffer, info_count, geometry_infos, range_infos);
}

void VulkanAccelerationStructureBuilder::UpdateScratchDeviceAddress(
    VkAccelerationStructureBuildGeometryInfoKHR& geometry_infos, VkDeviceSize scratch_size)
{ // Check whether the scratch with this original device address is already allocated and fits the size
    VkDeviceAddress capture_scratch_address = geometry_infos.scratchData.deviceAddress;

    format::HandleId capture_id = format::kNullHandleId;
    // When fastforwarding, the scratch buffers could be destroyed and not be recreated in state recreation
    BufferInfo* original_scratch_entry = buffer_tracker_->GetBufferByCaptureDeviceAddress(capture_scratch_address);
    if (original_scratch_entry)
    {
        capture_id = original_scratch_entry->capture_id;
    }

    auto scratch_entries = scratch_double_buffer_.scratches_current.find(capture_id);

    if (scratch_entries != scratch_double_buffer_.scratches_current.end())
    {
        auto scratch_entry =
            std::find_if(scratch_entries->second.begin(),
                         scratch_entries->second.end(),
                         [scratch_size, capture_scratch_address](
                             const std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper>& entry) {
                             return entry->allocator_->GetBufferSize(entry->info_.allocator_data) >= scratch_size &&
                                    entry->info_.capture_address == capture_scratch_address;
                         });
        if (scratch_entry != scratch_entries->second.end())
        {
            geometry_infos.scratchData.deviceAddress = (*scratch_entry)->info_.replay_address;
        }
        else
        {
            const auto& new_scratch = scratch_entries->second.emplace_back(internal_buffer_manager_.CreateBuffer(
                scratch_size, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT));
            new_scratch->info_.capture_address       = geometry_infos.scratchData.deviceAddress;
            geometry_infos.scratchData.deviceAddress = new_scratch->info_.replay_address;
        }
    }
    else
    {
        auto [it, inserted] = scratch_double_buffer_.scratches_current.emplace(
            capture_id, std::vector<std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper>>());
        auto& new_scratch = it->second.emplace_back(internal_buffer_manager_.CreateBuffer(
            scratch_size, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT));
        new_scratch->info_.capture_address       = geometry_infos.scratchData.deviceAddress;
        geometry_infos.scratchData.deviceAddress = new_scratch->info_.replay_address;
    }
}

void VulkanAccelerationStructureBuilder::CmdCopyAccelerationStructure(VkCommandBuffer command_buffer,
                                                                      VkCopyAccelerationStructureInfoKHR* copy_info)
{
    VkCopyAccelerationStructureInfoKHR modified_info = *copy_info;

    if (VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR == modified_info.mode)
    {
        // Replace the handle to be of the real built structure
        auto original_entry  = GetAccelerationStructureEntry(modified_info.src);
        auto compacted_entry = GetAccelerationStructureEntry(modified_info.dst);

        // Handling for results (only in case of vkCmdCopyQueryPoolResults)
        if (!compacted_sizes_unprocessed_.empty())
        {
            for (auto it = compacted_sizes_unprocessed_.begin(); it != compacted_sizes_unprocessed_.end(); ++it)
            {
                auto& unprocessed = it->second;

                for (uint64_t i = 0; i < unprocessed.size(); i++)
                {
                    auto& [compacted_first_query, buffer, vector_of_acc_str]{ unprocessed[i] };

                    std::vector<uint64_t> vector_of_acc_str_sizes(vector_of_acc_str.size(), 0);
                    uint64_t              buffer_size = vector_of_acc_str_sizes.size() * sizeof(uint64_t);

                    void*    mapped;
                    VkResult mapping_result =
                        allocator_->MapResourceMemoryDirect(buffer_size, 0, &mapped, buffer->info_.allocator_data);
                    GFXRECON_ASSERT(mapping_result == VK_SUCCESS);

                    util::platform::MemoryCopy(vector_of_acc_str_sizes.data(), buffer_size, mapped, buffer_size);

                    allocator_->UnmapResourceMemoryDirect(buffer->info_.allocator_data);

                    // This assert may get hit if the acceleration structures were not build and the optimized sizes are
                    // not known. This situation can happen if gpu is mocked and the assert can be triggered in debug
                    // mode only
                    GFXRECON_ASSERT(vector_of_acc_str_sizes != std::vector<uint64_t>(vector_of_acc_str.size(), 0));

                    // add results to compacted_sizes_processed map
                    std::unordered_map<VkAccelerationStructureKHR, VkDeviceSize> processing_result;
                    std::transform(vector_of_acc_str.begin(),
                                   vector_of_acc_str.end(),
                                   vector_of_acc_str_sizes.begin(),
                                   std::inserter(processing_result, processing_result.end()),
                                   [](VkAccelerationStructureKHR acc_str, uint64_t acc_str_size) {
                                       return std::make_pair(acc_str, acc_str_size);
                                   });
                    compacted_sizes_processed_.insert(processing_result.begin(), processing_result.end());
                }
            }
            compacted_sizes_unprocessed_.clear();
        }

        // create replacement acceleration structure for dst with previously determined compacted size
        if (!compacted_entry->replacement_acceleration_struct_)
        {
            GFXRECON_ASSERT(compacted_sizes_processed_.count(*original_entry->handles_.begin()));
            VkDeviceSize compacted_as_size{ compacted_sizes_processed_[*original_entry->handles_.begin()] };
            compacted_sizes_processed_.erase(*original_entry->handles_.begin());

            // Creating a buffer of size 0 is not allowed, however if gpu is mocked it will not report optimized size
            // properly. In that case - use the source size
            if (!compacted_as_size)
            {
                compacted_as_size =
                    original_entry->replacement_acceleration_struct_->size_info_.accelerationStructureSize;
            }

            std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper> storage =
                internal_buffer_manager_.CreateBuffer(compacted_as_size,
                                                      VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR |
                                                          VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT);
            VkAccelerationStructureBuildSizesInfoKHR size_info{};
            size_info.accelerationStructureSize = compacted_as_size;

            VkAccelerationStructureBuildGeometryInfoKHR geometry{};
            geometry.type = compacted_entry->type_;

            VkAccelerationStructureKHR replacement_as =
                CreateAccelerationStructure(geometry, nullptr, size_info, storage->info_.handle);

            // Store acceleration structure data
            auto replacement_as_address                       = GetAccelerationStructureDeviceAddress(replacement_as);
            compacted_entry->replacement_acceleration_struct_ = std::make_unique<AccelerationStructureEntry>(
                0, replacement_as_address, replacement_as, compacted_entry->type_, size_info);
            compacted_entry->replacement_acceleration_struct_->storage_ = std::move(storage);

            compacted_entry->new_address_ = GetAccelerationStructureDeviceAddress(modified_info.dst);
        }

        modified_info.src = *original_entry->replacement_acceleration_struct_->handles_.begin();
        modified_info.dst = *compacted_entry->replacement_acceleration_struct_->handles_.begin();
    }
    // TODO: non-compacting copy
    functions_.cmd_copy_acceleration_structure(command_buffer, &modified_info);
}

void VulkanAccelerationStructureBuilder::CmdWriteAccelerationStructuresProperties(
    VkCommandBuffer             command_buffer,
    uint32_t                    count,
    VkAccelerationStructureKHR* acceleration_structures,
    VkQueryType                 query_type,
    VkQueryPool                 pool,
    uint32_t                    first_query)
{
    std::vector<VkAccelerationStructureKHR> acc_str_to_process{};

    for (uint32_t index = 0; index < count; ++index)
    {
        VkAccelerationStructureKHR capture_handle = acceleration_structures[index];
        auto                       entry          = GetAccelerationStructureEntry(capture_handle);
        GFXRECON_ASSERT(entry->replacement_acceleration_struct_);

        acceleration_structures[index] = *entry->replacement_acceleration_struct_->handles_.begin();
        acc_str_to_process.push_back(capture_handle);
    }

    functions_.cmd_write_acceleration_structures_properties(
        command_buffer, count, acceleration_structures, query_type, pool, first_query);

    if (VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR == query_type)
    {
        std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper> staging_buffer_entry =
            internal_buffer_manager_.CreateBuffer(
                sizeof(uint64_t) * count,
                VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT));
        // keep track of relation between AS to be compacted and the query pool that handles the results (the order of
        // AS is also important)
        auto [it, inserted] = compacted_sizes_unprocessed_.emplace(
            pool,
            std::vector<std::tuple<uint32_t,
                                   std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper>,
                                   std::vector<VkAccelerationStructureKHR>>>());
        it->second.push_back({ first_query, std::move(staging_buffer_entry), acc_str_to_process });
    }
}

VkDeviceAddress VulkanAccelerationStructureBuilder::GetActualDeviceAddress(VkAccelerationStructureKHR handle)
{
    AccelerationStructureEntry* entry = GetAccelerationStructureEntry(handle);
    if (entry->replacement_acceleration_struct_)
    {
        return entry->replacement_acceleration_struct_->new_address_;
    }
    return GetAccelerationStructureDeviceAddress(handle);
}

VkDeviceAddress VulkanAccelerationStructureBuilder::GetAccelerationStructureDeviceAddress(
    VkAccelerationStructureKHR acceleration_structure)
{
    VkAccelerationStructureDeviceAddressInfoKHR info{
        .sType                 = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR,
        .pNext                 = nullptr,
        .accelerationStructure = acceleration_structure
    };
    VkDeviceAddress address = functions_.get_acceleration_structure_device_address(device_, &info);
    return address;
}

VkAccelerationStructureKHR VulkanAccelerationStructureBuilder::CreateAccelerationStructure(
    VkAccelerationStructureBuildGeometryInfoKHR&    geometry_info,
    VkAccelerationStructureBuildRangeInfoKHR*       range_info,
    const VkAccelerationStructureBuildSizesInfoKHR& size_info,
    VkBuffer                                        storage)
{
    VkAccelerationStructureCreateInfoKHR create_info = {
        .sType  = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR,
        .buffer = storage,
        .size   = size_info.accelerationStructureSize,
        .type   = geometry_info.type,
    };
    VkAccelerationStructureKHR acceleration_structure;
    functions_.create_acceleration_structure(device_, &create_info, nullptr, &acceleration_structure);
    return acceleration_structure;
}

VkAccelerationStructureBuildSizesInfoKHR VulkanAccelerationStructureBuilder::GetAccelerationStructureSizeInfo(
    VkAccelerationStructureBuildGeometryInfoKHR* geometry_info, VkAccelerationStructureBuildRangeInfoKHR* range_info)
{
    std::vector<uint32_t> primitive_counts(geometry_info->geometryCount);
    for (uint32_t i = 0; i < geometry_info->geometryCount; ++i)
    {
        primitive_counts[i] = range_info[i].primitiveCount;
    }
    VkAccelerationStructureBuildSizesInfoKHR size_info{ VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR,
                                                        nullptr };
    functions_.get_acceleration_structure_build_sizes(
        device_, VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR, geometry_info, primitive_counts.data(), &size_info);
    return size_info;
}

// inject vkCmdCopyQueryPoolResults command that copies the results to internal buffer in the expected format
// processing of the results happens in CmdCopyAccelerationStructure
void VulkanAccelerationStructureBuilder::OnCmdCopyQueryPoolResults(const CommandBufferInfo* command_buffer_info,
                                                                   const QueryPoolInfo*     query_pool_info)
{
    if (!compacted_sizes_unprocessed_.count(query_pool_info->handle))
    {
        return;
    }

    std::vector<std::tuple<uint32_t,
                           std::unique_ptr<VulkanInternalBufferManager::BufferInfoWrapper>,
                           std::vector<VkAccelerationStructureKHR>>>& unprocessed =
        compacted_sizes_unprocessed_[query_pool_info->handle];

    for (uint64_t i = 0; i < unprocessed.size(); i++)
    {
        auto& [compacted_first_query, buffer, vector_of_acc_str]{ unprocessed[i] };

        functions_.cmd_copy_query_pool_results(command_buffer_info->handle,
                                               query_pool_info->handle,
                                               compacted_first_query,
                                               vector_of_acc_str.size(),
                                               buffer->info_.handle,
                                               0,
                                               8,
                                               VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT);

        VkBufferMemoryBarrier buffer_memory_barrier{};
        buffer_memory_barrier.sType         = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
        buffer_memory_barrier.pNext         = nullptr;
        buffer_memory_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        buffer_memory_barrier.dstAccessMask = VK_ACCESS_HOST_READ_BIT;
        buffer_memory_barrier.buffer        = buffer->info_.handle;
        buffer_memory_barrier.offset        = 0;
        buffer_memory_barrier.size          = vector_of_acc_str.size();

        functions_.cmd_pipeline_barrier(command_buffer_info->handle,
                                        VK_PIPELINE_STAGE_TRANSFER_BIT,
                                        VK_PIPELINE_STAGE_HOST_BIT,
                                        0,
                                        0,
                                        nullptr,
                                        1,
                                        &buffer_memory_barrier,
                                        0,
                                        nullptr);
    }
}

// inject vkGetQueryPoolResults command to retrieve data in the desired format and write results in correlation to AS in
// processed map
void VulkanAccelerationStructureBuilder::OnGetQueryPoolResults(const DeviceInfo*    device_info,
                                                               const QueryPoolInfo* query_pool_info)
{
    if (!compacted_sizes_unprocessed_.count(query_pool_info->handle))
    {
        return;
    }

    auto& unprocessed = compacted_sizes_unprocessed_[query_pool_info->handle];

    for (uint64_t i = 0; i < unprocessed.size(); i++)
    {
        auto& [compacted_first_query, buffer, vector_of_acc_str]{ unprocessed[i] };

        std::vector<uint64_t> vector_of_acc_str_sizes(vector_of_acc_str.size(), 0);
        auto                  buffer_size = vector_of_acc_str_sizes.size() * sizeof(uint64_t);

        functions_.get_query_pool_results(device_info->handle,
                                          query_pool_info->handle,
                                          compacted_first_query,
                                          vector_of_acc_str.size(),
                                          vector_of_acc_str_sizes.size() * sizeof(uint64_t),
                                          vector_of_acc_str_sizes.data(),
                                          8,
                                          VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT);

        GFXRECON_ASSERT(vector_of_acc_str_sizes != std::vector<uint64_t>(vector_of_acc_str.size(), 0));

        // add results to compacted_sizes_processed map
        std::unordered_map<VkAccelerationStructureKHR, VkDeviceSize> processing_result;
        std::transform(vector_of_acc_str.begin(),
                       vector_of_acc_str.end(),
                       vector_of_acc_str_sizes.begin(),
                       std::inserter(processing_result, processing_result.end()),
                       [](VkAccelerationStructureKHR acc_str, uint64_t acc_str_size) {
                           return std::make_pair(acc_str, acc_str_size);
                       });
        compacted_sizes_processed_.insert(processing_result.begin(), processing_result.end());
    }
    compacted_sizes_unprocessed_.erase(query_pool_info->handle);
}

void VulkanAccelerationStructureBuilder::OnQueueSubmit(VkQueue             queue,
                                                       uint32_t            submitCount,
                                                       const VkSubmitInfo* pSubmits)
{
    // TODO: Updating buffers content on queue submit is not reliable, prone to synchronizaiton issues,
    //       non-host visible memory access issues and impacts performance. TODO in postprocessing.
    if (queue_with_buffer_write_ != VK_NULL_HANDLE)
    {
        functions_.queue_wait_idle(queue_with_buffer_write_);
        queue_with_buffer_write_ = VK_NULL_HANDLE;
    }

    bool wait = false;
    // Perform the actual update of the bottom level acceleration structures in the instance buffers
    for (int i = 0; i < submitCount; ++i)
    {
        auto submission = pSubmits[i];
        for (int cmd_buffer_index = 0; cmd_buffer_index < submission.commandBufferCount; ++cmd_buffer_index)
        {
            auto submitted_buffer = submission.pCommandBuffers[cmd_buffer_index];

            // if instance_buffer_staging_updates_ for this command buffer is not empty it means that the staging
            // instance buffer write was referring to an acceleration structure meant to be built at a later time,
            // therefore no action needed for it
            auto instance_buffer_staging_update_it = instance_buffer_staging_updates_.find(submitted_buffer);
            if (instance_buffer_staging_update_it != instance_buffer_staging_updates_.end())
            {
                instance_buffer_staging_updates_.erase(instance_buffer_staging_update_it);
            }

            auto instance_buffers_update_itr = instance_buffer_updates_.find(submitted_buffer);
            if (instance_buffers_update_itr != instance_buffer_updates_.end())
            {
                auto instance_buffers_update = instance_buffers_update_itr->second;
                for (auto [resource_data, offset, range_info] : instance_buffers_update)
                {
                    UpdateInstanceBufferContent(resource_data, offset, range_info);
                }
                instance_buffer_updates_.erase(instance_buffers_update_itr);
                wait = true;
            }
        }
    }

    for (const auto& descriptor_update_buffers : deferred_inspection_buffers_)
    {
        for (uint32_t buffer_idx = 0; buffer_idx < descriptor_update_buffers.size_; ++buffer_idx)
        {
            if (descriptor_update_buffers.infos_[buffer_idx]->usage &
                VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR)
            {
                continue;
            }


            uint8_t* data;
            VkResult mapping_result = allocator_->MapResourceMemoryDirect(
                allocator_->GetBufferSize(descriptor_update_buffers.infos_[buffer_idx]->allocator_data),
                0,
                (void**)&data,
                descriptor_update_buffers.infos_[buffer_idx]->allocator_data);

            if (mapping_result != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING_ONCE("Mapping of descriptor update buffer has failed");
                GFXRECON_LOG_DEBUG("Mapping of descriptor update buffer (capture id %u) has failed",
                                   descriptor_update_buffers.infos_[buffer_idx]->capture_id);
                continue;
            }

            data += descriptor_update_buffers.offsets_[buffer_idx];

            VkDeviceAddress* device_addresses = reinterpret_cast<uint64_t*>(data);

            // All or nothing - if we are looking in the wrong buffer, we do not want to update
            // the contents until we are sure
            uint32_t count   = descriptor_update_buffers.ranges_[buffer_idx] / sizeof(VkDeviceAddress);
            bool     success = true;
            std::vector<VkDeviceAddress> copy(device_addresses, device_addresses + count);
            for (uint32_t i = 0; success && (i < count); ++i)
            {
                success = UpdateAccelerationStructDeviceAddress(copy[i]);
            }
            if (success)
            {
                uint32_t size = sizeof(VkDeviceAddress) * count;
                util::platform::MemoryCopy(data, size, copy.data(), size);
                wait = true;
            }
            allocator_->UnmapResourceMemoryDirect(descriptor_update_buffers.infos_[buffer_idx]->allocator_data);
        }
    }

    if (wait)
    {
        queue_with_buffer_write_ = queue;
    }

    deferred_inspection_buffers_.clear();
    // Update the descriptor set with the actual handle, if any such update is stored
    for (auto it = cached_descriptor_write_.begin(); it != cached_descriptor_write_.end();)
    {
        AccelerationStructureEntry* entry = GetAccelerationStructureEntry(it->first);
        if (entry->replacement_acceleration_struct_)
        {
            auto handle = std::find(
                it->second.acc_structs_data.begin(), it->second.acc_structs_data.end(), *entry->handles_.begin());
            *handle = *entry->replacement_acceleration_struct_->handles_.begin();
            functions_.update_descriptor_sets(device_, 1, &it->second.write_, 0, nullptr);
            it = cached_descriptor_write_.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // TODO: SBT tracking and update should be handled by postprocessor+metacommand
    // Update shader group handles if the submission contains vkCmdTraceRays command
    for (int i = 0; i < submitCount; ++i)
    {
        VkSubmitInfo submission = pSubmits[i];
        for (int cmd_buffer_index = 0; cmd_buffer_index < submission.commandBufferCount; ++cmd_buffer_index)
        {
            VkCommandBuffer submitted_buffer = submission.pCommandBuffers[cmd_buffer_index];

            // Every command buffer containing CmdTraceRays has been recorded into trace_rays_ map along with the
            // shader binding table data. These SBTs will contain shader group handles that need an update
            for (auto& sbt_data : trace_rays_[submitted_buffer])
            {
                UpdateShaderBindingTable(sbt_data.raygen);
                UpdateShaderBindingTable(sbt_data.hit);
                UpdateShaderBindingTable(sbt_data.miss);
                UpdateShaderBindingTable(sbt_data.callable);
            }
            trace_rays_.erase(submitted_buffer);
        }
    }
}

void VulkanAccelerationStructureBuilder::UpdateShaderBindingTable(const VkStridedDeviceAddressRegionKHR& sbt_entry)
{
    // early exit - address/size can be 0, nothing to update
    if (!sbt_entry.size || !sbt_entry.deviceAddress)
    {
        return;
    }
    uint8_t*          mapped_sbt_buffer;
    const BufferInfo* sbt_buffer = buffer_tracker_->GetBufferByReplayDeviceAddress(sbt_entry.deviceAddress);
    VkResult          mapping_result =
        allocator_->MapResourceMemoryDirect(sbt_entry.size, 0, (void**)&mapped_sbt_buffer, sbt_buffer->allocator_data);
    GFXRECON_ASSERT(mapping_result == VK_SUCCESS);

    // sbt device address may be offsetted, account for that in
    const size_t sbt_offset = sbt_entry.deviceAddress - sbt_buffer->replay_address;

    // points to the sbt within mapped buffer
    uint8_t* sbt_start_address = mapped_sbt_buffer + sbt_offset;

    // goes over all the known shader group handles tracked in the trace
    // compares them with the values in the mapped buffer at provided offset
    // and replaces if there's a match
    auto update_entry = [&](VkDeviceSize handle_offset) {
        uint8_t* handle_address = sbt_start_address + handle_offset;
        for (const auto& entry : shader_group_handle_entries_)
        {
            // Assume shaderGroupHandleSize and shaderGroupHandleAlignment are the same
            // TODO: shader group size/alignment might change on different platforms
            GFXRECON_ASSERT(entry.original_data_.size() == entry.runtime_data_.size());
            GFXRECON_ASSERT(entry.original_data_.size() ==
                            raytracing_pipeline_properties_.shader_group_handle_size_aligned);
            if (0 == memcmp(entry.original_data_.data(), handle_address, entry.original_data_.size()))
            {
                memcpy(handle_address, entry.runtime_data_.data(), entry.original_data_.size());
            }
        }
    };

    // stride may be 0 if there's just a single value in the sbt
    if (sbt_entry.stride > 0)
    {
        for (VkDeviceSize handle_offset = 0; handle_offset < sbt_entry.size; handle_offset += sbt_entry.stride)
        {
            update_entry(handle_offset);
        }
    }
    else
    {
        update_entry(0);
    }

    allocator_->UnmapResourceMemoryDirect(sbt_buffer->allocator_data);
}

void VulkanAccelerationStructureBuilder::OnCmdTraceRaysKHR(VkCommandBuffer                  command_buffer,
                                                           VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                                           VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                                           VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                                           VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable)
{
    // SBT's device addresses can change, update them based on buffer_tracker_->GetBufferDeviceAddress calls recorded
    // earlier Device addresses are not guaranteed to be valid - some tables could be left out, process only the regions
    // with specified size
    if (pRaygenShaderBindingTable->size)
    {
        buffer_tracker_->UpdateBufferDeviceAddress(pRaygenShaderBindingTable->deviceAddress);
    }
    if (pMissShaderBindingTable->size)
    {
        buffer_tracker_->UpdateBufferDeviceAddress(pMissShaderBindingTable->deviceAddress);
    }
    if (pHitShaderBindingTable->size)
    {
        buffer_tracker_->UpdateBufferDeviceAddress(pHitShaderBindingTable->deviceAddress);
    }
    if (pCallableShaderBindingTable->size)
    {
        buffer_tracker_->UpdateBufferDeviceAddress(pCallableShaderBindingTable->deviceAddress);
    }

    // Shader group handles stored in SBT's will require update as well, this should be done before QueueSubmit
    // Store SBT data for later replacement
    CmdTraceRaysEntry new_entry{
        *pRaygenShaderBindingTable, *pMissShaderBindingTable, *pHitShaderBindingTable, *pCallableShaderBindingTable
    };
    trace_rays_[command_buffer].push_back(new_entry);
}

void VulkanAccelerationStructureBuilder::RegisterShaderGroupHandleEntry(uint32_t group_count,
                                                                        size_t   data_size,
                                                                        uint8_t* original_data,
                                                                        uint8_t* runtime_data)
{
    const auto single_entry_size = data_size / group_count;
    for (uint32_t group_index = 0; group_index < group_count; ++group_index)
    {
        shader_group_handle_entries_.emplace_back(original_data + (single_entry_size * group_index),
                                                  runtime_data + (single_entry_size * group_index),
                                                  single_entry_size);
    }
}

void VulkanAccelerationStructureBuilder::RegisterInstanceBufferStagingUpdate(
    VkCommandBuffer                       command_buffer,
    VulkanResourceAllocator::ResourceData src_buffer_allocator_data,
    VkDeviceSize                          src_offset,
    VkBuffer                              dst_buffer)
{
    instance_buffer_staging_updates_[command_buffer].push_back(
        std::make_tuple(src_buffer_allocator_data, src_offset, dst_buffer));
}

void VulkanAccelerationStructureBuilder::PostQueuePresent()
{
    scratch_double_buffer_.scratches_previous.clear();
    std::swap(scratch_double_buffer_.scratches_previous, scratch_double_buffer_.scratches_current);
}

void VulkanAccelerationStructureBuilder::StoreDeferredDeviceAddressBufferUpdates(
    const std::vector<BufferInfo*>&                   buffer_infos,
    const std::vector<const VkDescriptorBufferInfo*>& descriptor_buffer_infos)
{
    DescriptorUpdateBufferEntries& buffers = deferred_inspection_buffers_.emplace_back(buffer_infos.size());

    for (uint32_t i = 0; i < buffer_infos.size(); ++i)
    {
        buffers.infos_[i]   = buffer_infos[i];
        buffers.offsets_[i] = descriptor_buffer_infos[i]->offset;
        if (descriptor_buffer_infos[i]->range == VK_WHOLE_SIZE)
        {
            buffers.ranges_[i] = allocator_->GetBufferSize(buffer_infos[i]->allocator_data);
        }
        else
        {
            buffers.ranges_[i] = descriptor_buffer_infos[i]->range;
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)