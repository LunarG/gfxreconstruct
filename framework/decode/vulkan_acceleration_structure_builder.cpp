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
#include <set>
#include <map>
#include <set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanAccelerationStructureBuilder::VulkanAccelerationStructureBuilder(
    Functions                                        functions,
    VkDevice                                         device,
    VulkanResourceAllocator*                         allocator,
    const VkPhysicalDeviceMemoryProperties&          memory_properties,
    VkPhysicalDeviceRayTracingPipelinePropertiesKHR  ray_tracing_pipeline_properties,
    VkPhysicalDeviceAccelerationStructureFeaturesKHR acceleration_structure_features) :
    functions_(functions),
    device_(device), allocator_(allocator), physical_device_memory_properties_(memory_properties),
    ray_tracing_pipeline_properties_(ray_tracing_pipeline_properties),
    acceleration_structure_features_(acceleration_structure_features),
    raytracing_pipeline_properties_(ray_tracing_pipeline_properties.shaderGroupHandleSize,
                                    ray_tracing_pipeline_properties.shaderGroupHandleAlignment)
{}

VulkanAccelerationStructureBuilder::~VulkanAccelerationStructureBuilder()
{
    for (auto& entry : acceleration_structures_)
    {
        if (entry->replacement_acceleration_struct_)
        {
            functions_.destroy_acceleration_structure(
                device_, entry->replacement_acceleration_struct_->handle_, nullptr);
        }
    }
}

// On creation of the acceleration structure, start tracking it by handle and original device address
void VulkanAccelerationStructureBuilder::OnCreateAccelerationStructure(VkAccelerationStructureKHR     handle,
                                                                       VkDeviceAddress                device_address,
                                                                       VkAccelerationStructureTypeKHR type)
{
    acceleration_structures_.emplace_back(std::make_unique<AccelerationStructureEntry>(
        device_address, 0, handle, type, VkAccelerationStructureBuildSizesInfoKHR()));
}

// On destroy acceleration structure, clean up the internal replacement structure
void VulkanAccelerationStructureBuilder::OnDestroyAccelerationStructure(
    const AccelerationStructureKHRInfo* acceleration_structure_info)
{
    auto result =
        std::find_if(acceleration_structures_.begin(),
                     acceleration_structures_.end(),
                     [&acceleration_structure_info](const std::unique_ptr<AccelerationStructureEntry>& entry) {
                         return acceleration_structure_info->handle == entry->handle_;
                     });

    GFXRECON_ASSERT(result != acceleration_structures_.end());

    if (result->get()->replacement_acceleration_struct_)
    {
        const auto& real_as = result->get()->replacement_acceleration_struct_;
        functions_.destroy_acceleration_structure(device_, real_as->handle_, nullptr);
    }

    acceleration_structures_.erase(result);
}

void VulkanAccelerationStructureBuilder::ProcessBuildVulkanAccelerationStructuresMetaCommand(
    uint32_t                                                      info_count,
    VkAccelerationStructureBuildGeometryInfoKHR*                  geometry_infos,
    VkAccelerationStructureBuildRangeInfoKHR**                    range_infos,
    std::vector<std::vector<VkAccelerationStructureInstanceKHR>>& instance_buffers_data)
{
    static const VkBufferUsageFlags usage = VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT |
                                            VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR;
    // Retrieve / initialize the command executable structures
    if (!cmd_execute_obj_.initialized_)
    {
        InitializeInternalExecObjects();
    }
    VkCommandBuffer command_buffer = cmd_execute_obj_.command_buffer_;

    BeginCommandBuffer();

    std::set<VkDeviceAddress> state_recreation_device_addresses;

    // We need to create and populate the geometry buffers for TLAS
    // Discard them after build
    for (uint32_t i = 0; i < info_count; ++i)
    {
        for (uint32_t g = 0; g < geometry_infos[i].geometryCount; ++g)
        {
            if (geometry_infos[i].pGeometries[g].geometryType != VK_GEOMETRY_TYPE_INSTANCES_KHR)
            {
                continue;
            }

            VkDeviceSize buffer_size = range_infos[i][g].primitiveCount * sizeof(VkAccelerationStructureInstanceKHR);

            auto entry = CreateBuffer(
                buffer_size, usage, VK_MEMORY_PROPERTY_HOST_COHERENT_BIT | VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
            entry->original_address_ = geometry_infos[i].pGeometries[g].geometry.instances.data.deviceAddress;
            entry->new_address_      = GetBufferDeviceAddress(entry->handle_);

            void* mapped;
            allocator_->MapResourceMemoryDirect(buffer_size, 0, &mapped, entry->allocator_data_);
            util::platform::MemoryCopy(mapped, buffer_size, instance_buffers_data[i].data(), buffer_size);
            allocator_->UnmapResourceMemoryDirect(entry->allocator_data_);

            // We add their original device address, that remains unchanged to the set, to delete them right after we
            // finished building
            state_recreation_device_addresses.insert(entry->original_address_);
            // We still need to add them to the global tracking so that builder finds them later
            buffers_.push_back(std::move(entry));
        }
    }

    CmdBuildAccelerationStructures(command_buffer, info_count, geometry_infos, range_infos);

    ExecuteCommandBuffer();

    // After
    buffers_.erase(std::remove_if(buffers_.begin(),
                                  buffers_.end(),
                                  [&state_recreation_device_addresses](const std::unique_ptr<BufferEntry>& entry) {
                                      return state_recreation_device_addresses.count(entry->original_address_) != 0;
                                  }),
                   buffers_.end());
}

void VulkanAccelerationStructureBuilder::ProcessCopyVulkanAccelerationStructuresMetaCommand(
    uint32_t info_count, VkCopyAccelerationStructureInfoKHR* copy_infos)
{
    if (cmd_execute_obj_.initialized_)
    {
        InitializeInternalExecObjects();
    }
    VkCommandBuffer command_buffer = cmd_execute_obj_.command_buffer_;
    BeginCommandBuffer();

    for (uint32_t i = 0; i < info_count; ++i)
    {
        CmdCopyAccelerationStructure(command_buffer, &copy_infos[i]);
    }

    ExecuteCommandBuffer();
}

void VulkanAccelerationStructureBuilder::SetBufferInfo(BufferInfo*     buffer_info,
                                                       VkDeviceAddress original_address,
                                                       VkDeviceAddress new_address)
{
    if (new_address == 0)
    {
        new_address = GetBufferDeviceAddress(buffer_info->handle);
    }
    auto existing_buffer = std::find_if(
        buffers_.begin(), buffers_.end(), [&](const auto& entry) { return entry->handle_ == buffer_info->handle; });

    // Handle reuse, update the data in the entry
    if (existing_buffer != buffers_.end())
    {
        (*existing_buffer)->original_address_ = original_address;
        (*existing_buffer)->new_address_      = new_address;
        (*existing_buffer)->capture_id_       = buffer_info->capture_id;
        (*existing_buffer)->handle_           = buffer_info->handle;
        (*existing_buffer)->allocator_data_   = buffer_info->allocator_data;
    }
    else
    {
        buffers_.push_back(std::make_unique<BufferEntry>(original_address, new_address, allocator_, buffer_info));
    }
}

void VulkanAccelerationStructureBuilder::OnDestroyBuffer(const BufferInfo* buffer_info)
{
    // On buffer destruction, we want to stop tracking them
    buffers_.erase(std::remove_if(buffers_.begin(),
                                  buffers_.end(),
                                  [&buffer_info](const std::unique_ptr<BufferEntry>& entry) {
                                      return entry->capture_id_ == buffer_info->capture_id;
                                  }),
                   buffers_.end());
}

std::unique_ptr<VulkanAccelerationStructureBuilder::BufferEntry> VulkanAccelerationStructureBuilder::CreateBuffer(
    VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags mem_prop_flags)
{
    VkBuffer buffer;

    VkBufferCreateInfo create_info    = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.size                  = size;
    create_info.usage                 = usage;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;

    VulkanResourceAllocator::ResourceData buffer_allocator_data;
    allocator_->CreateBuffer(&create_info, nullptr, format::kNullHandleId, &buffer, &buffer_allocator_data);

    VkMemoryRequirements requirements{};
    functions_.get_buffer_memory_requirements(device_, buffer, &requirements);

    uint32_t              mem_type_index = 1;
    VkMemoryPropertyFlags desired_flags{ mem_prop_flags };
    VkMemoryPropertyFlags found_flags{};

    graphics::FindMemoryTypeIndex(
        physical_device_memory_properties_, requirements.memoryTypeBits, desired_flags, &mem_type_index, &found_flags);

    VkMemoryAllocateInfo allocate_info{ .sType           = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO,
                                        .allocationSize  = requirements.size,
                                        .memoryTypeIndex = mem_type_index };

    VkDeviceMemory                      memory{};
    VulkanResourceAllocator::MemoryData memory_allocator_data{};
    allocator_->AllocateMemory(&allocate_info, nullptr, format::kNullHandleId, &memory, &memory_allocator_data);

    allocator_->BindBufferMemory(buffer, memory, 0, buffer_allocator_data, memory_allocator_data, &found_flags);

    auto entry             = std::make_unique<BufferEntry>(0, GetBufferDeviceAddress(buffer), allocator_);
    entry->allocator_data_ = buffer_allocator_data;
    entry->handle_         = buffer;

    return entry;
}

VkDeviceAddress VulkanAccelerationStructureBuilder::GetBufferDeviceAddress(VkBuffer buffer)
{
    VkBufferDeviceAddressInfo info;
    info.sType  = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
    info.pNext  = nullptr;
    info.buffer = buffer;
    return functions_.get_buffer_device_address(device_, &info);
}

// overwrites acceleration structure capture device address with runtime device address
void VulkanAccelerationStructureBuilder::UpdateAccelerationStructDeviceAddress(VkDeviceAddress& address)
{
    if (address == 0)
        return;
    // Try to find the entry in the internal map by capture address of the acceleration structure
    auto as = std::find_if(acceleration_structures_.begin(), acceleration_structures_.end(), [&](const auto& entry) {
        return entry->original_address_ == address;
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
        return;
    }

    // If we are updating the instance buffer that was already updated, we would find the new
    // device addresses instead of old
    as = std::find_if(acceleration_structures_.begin(), acceleration_structures_.end(), [&](const auto& entry) {
        return entry->replacement_acceleration_struct_->new_address_ == address;
    });
    if (as == acceleration_structures_.end())
    {
        GFXRECON_LOG_DEBUG("Acceleration structure address not found: " PRIx64, address);
    }
}

void VulkanAccelerationStructureBuilder::UpdateBufferDeviceAddress(VkDeviceAddress& address)
{
    if (address == 0)
        return;
    auto buffer = std::find_if(
        buffers_.begin(), buffers_.end(), [&](const auto& entry) { return entry->original_address_ == address; });
    if (buffer != buffers_.end())
    {
        address = (*buffer)->new_address_;
        return;
    }
    else
    {
        VkDeviceSize offset;
        buffer = std::find_if(buffers_.begin(), buffers_.end(), [&](const auto& entry) {
            auto buffer_size = allocator_->GetBufferSize(entry->allocator_data_);
            return entry->original_address_ < address && (entry->original_address_ + buffer_size) > address;
        });
        GFXRECON_ASSERT(buffer != buffers_.end());
        offset  = address - (*buffer)->original_address_;
        address = (*buffer)->new_address_ + offset;
    }
}

VulkanAccelerationStructureBuilder::BufferEntry*
VulkanAccelerationStructureBuilder::GetBufferByRuntimeDeviceAddress(VkDeviceAddress runtime_address)
{
    // Try to find buffer by runtime device address
    auto buffer = std::find_if(
        buffers_.begin(), buffers_.end(), [&](const auto& entry) { return entry->new_address_ == runtime_address; });
    if (buffer == buffers_.end())
    {
        // If the above fails, the buffer still could be found
        // Try to search for such a buffer that the device address falls into range of the
        // addresses the buffer occupies
        buffer = std::find_if(buffers_.begin(), buffers_.end(), [&](const auto& entry) {
            auto buffer_size = allocator_->GetBufferSize(entry->allocator_data_);
            return entry->new_address_ < runtime_address && (entry->new_address_ + buffer_size) > runtime_address;
        });
    }
    GFXRECON_ASSERT(buffer != buffers_.end());
    return buffer->get();
}

VulkanAccelerationStructureBuilder::BufferEntry*
VulkanAccelerationStructureBuilder::GetBufferByCaptureDeviceAddress(VkDeviceAddress original_address)
{
    auto buffer = std::find_if(buffers_.begin(), buffers_.end(), [&](const std::unique_ptr<BufferEntry>& entry) {
        return entry->original_address_ == original_address;
    });
    GFXRECON_ASSERT(buffer != buffers_.end());
    return buffer->get();
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
                entry->replacement_acceleration_struct_->handle_;
        }
        else if (entry->new_address_ == 0)
        {
            // In case the handle is written to shader before the acceleration structure is built
            // We will store the data we need to update, and do it on queue submit
            // This way, the handle would be replaced by actual
            cached_descriptor_write.emplace(entry->handle_, descriptor_writes[index]);
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
            accel_struct = entry->replacement_acceleration_struct_->handle_;
        }
        else if (entry->new_address_ == 0)
        {
            // In case the handle is written to shader before the acceleration structure is built
            // We will store the data we need to update, and do it on queue submit
            // This way, the handle would be replaced by actual
            cached_descriptor_write.emplace(std::piecewise_construct,
                                            std::forward_as_tuple(entry->handle_),
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
    UpdateBufferDeviceAddress(instances.data.deviceAddress);

    if (build_range.primitiveCount == 0)
    {
        return;
    }

    // Find the buffer by updated address, and record offset if any
    auto         instance_buffer = GetBufferByRuntimeDeviceAddress(instances.data.deviceAddress);
    VkDeviceSize offset          = instances.data.deviceAddress - GetBufferDeviceAddress(instance_buffer->handle_);

    // This is a workaround for FillMemoryCommand overwriting any substitutions we may insert for BLAS device addresses
    // Instead of writing at command recording time, store the update and write on vkQueueSubmit, after
    // FillMemory command
    instance_buffer_updates_[command_buffer].push_back(
        std::make_tuple(instance_buffer->allocator_data_, offset, build_range));
}

// Perform the actual update of the BLAS device addresses
void VulkanAccelerationStructureBuilder::UpdateInstanceBufferContent(
    VulkanResourceAllocator::ResourceData    instance_buffer_allocator_data,
    VkDeviceSize                             offset,
    VkAccelerationStructureBuildRangeInfoKHR build_range)
{
    uint8_t* data;
    allocator_->MapResourceMemoryDirect(sizeof(VkAccelerationStructureInstanceKHR) * build_range.primitiveCount,
                                        0,
                                        (void**)&data,
                                        instance_buffer_allocator_data);
    data += offset + build_range.primitiveOffset;

    VkAccelerationStructureInstanceKHR* instance_data = reinterpret_cast<VkAccelerationStructureInstanceKHR*>(data);
    for (uint32_t instance_index = 0; instance_index < build_range.primitiveCount; ++instance_index)
    {
        UpdateAccelerationStructDeviceAddress(instance_data[instance_index].accelerationStructureReference);
    }
    allocator_->UnmapResourceMemoryDirect(instance_buffer_allocator_data);
}

void VulkanAccelerationStructureBuilder::InitializeInternalExecObjects()
{
    VkResult result;

    cmd_execute_obj_.device_               = device_;
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

    OnQueueSubmit(1, &submit_info);
    VkResult result = functions_.queue_submit(cmd_execute_obj_.queue_, 1, &submit_info, VK_NULL_HANDLE);

    if (result == VK_SUCCESS)
    {
        result = functions_.queue_wait_idle(cmd_execute_obj_.queue_);
    }
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
                UpdateBufferDeviceAddress(triangles.indexData.deviceAddress);
                UpdateBufferDeviceAddress(triangles.transformData.deviceAddress);
                UpdateBufferDeviceAddress(triangles.vertexData.deviceAddress);
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
                UpdateBufferDeviceAddress(aabbs.data.deviceAddress);
                break;
            }
            default:
            {
                GFXRECON_LOG_DEBUG("Unexpected geometry type");
                break;
            }
        }
    }
}

VulkanAccelerationStructureBuilder::AccelerationStructureEntry*
VulkanAccelerationStructureBuilder::GetAccelerationStructureEntry(VkAccelerationStructureKHR acceleration_struct)
{
    auto entry = std::find_if(acceleration_structures_.begin(), acceleration_structures_.end(), [&](auto& entry) {
        return entry->handle_ == acceleration_struct;
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
                std::unique_ptr<BufferEntry> storage = CreateBuffer(
                    size_info.accelerationStructureSize, VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR);
                VkAccelerationStructureKHR replacement_as =
                    CreateAccelerationStructure(geometry_infos[i], range_infos[i], size_info, storage->handle_);

                // Store acceleration structure data
                auto replacement_as_address                 = GetAccelerationStructureDeviceAddress(replacement_as);
                dst_entry->replacement_acceleration_struct_ = std::make_unique<AccelerationStructureEntry>(
                    0, replacement_as_address, replacement_as, geometry_infos[i].type, size_info);
                dst_entry->replacement_acceleration_struct_->storage_ = std::move(storage);

                dst_entry->new_address_ = replacement_as_address;
            }
            // Update the handle in the geometry info to point to actual structure
            geometry_infos[i].dstAccelerationStructure = dst_entry->replacement_acceleration_struct_->handle_;
            scratch_size                               = size_info.buildScratchSize;
        }
        else if (mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR)
        {
            // In case of update, we potentially need to update both handles
            // The src entry MUST have been built earlier, hence it must have a replacement structure
            auto src_entry = GetAccelerationStructureEntry(geometry_infos[i].srcAccelerationStructure);
            GFXRECON_ASSERT(src_entry);
            GFXRECON_ASSERT(src_entry->replacement_acceleration_struct_.get() != nullptr);
            GFXRECON_ASSERT(src_entry->replacement_acceleration_struct_->handle_ != 0);

            // Build the destination structure, if not already built
            if (!dst_entry->replacement_acceleration_struct_)
            {
                std::unique_ptr<BufferEntry> storage = CreateBuffer(
                    size_info.accelerationStructureSize, VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR);
                VkAccelerationStructureKHR replacement_as =
                    CreateAccelerationStructure(geometry_infos[i], range_infos[i], size_info, storage->handle_);

                // Store acceleration structure data
                auto replacement_as_address                 = GetAccelerationStructureDeviceAddress(replacement_as);
                dst_entry->replacement_acceleration_struct_ = std::make_unique<AccelerationStructureEntry>(
                    0, replacement_as_address, replacement_as, geometry_infos[i].type, size_info);
                dst_entry->replacement_acceleration_struct_->storage_ = std::move(storage);

                dst_entry->new_address_ = replacement_as_address;
            }
            geometry_infos[i].srcAccelerationStructure = src_entry->replacement_acceleration_struct_->handle_;
            geometry_infos[i].dstAccelerationStructure = dst_entry->replacement_acceleration_struct_->handle_;
            scratch_size                               = size_info.updateScratchSize;
        }

        // If there is no scratch - create one
        if (!dst_entry->replacement_acceleration_struct_->scratch_)
        {
            dst_entry->replacement_acceleration_struct_->scratch_ = CreateBuffer(
                scratch_size, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT);
        }
        // If there is a scratch, but size will not fit into existing scratch, recreate
        else if (allocator_->GetBufferSize(dst_entry->replacement_acceleration_struct_->scratch_->allocator_data_) <
                 scratch_size)
        {
            dst_entry->replacement_acceleration_struct_->scratch_ = CreateBuffer(
                scratch_size, VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT);
        }
        // Put the actual scratch address into geometry info, and update other geometry buffers addresses
        geometry_infos[i].scratchData.deviceAddress =
            (dst_entry->replacement_acceleration_struct_->scratch_)->new_address_;
        UpdateDeviceAddress(command_buffer, geometry_infos[i], range_infos[i]);
    }
    functions_.cmd_build_acceleration_structures(command_buffer, info_count, geometry_infos, range_infos);
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
        if (!compacted_sizes_unprocessed.empty())
        {
            for (auto it = compacted_sizes_unprocessed.begin(); it != compacted_sizes_unprocessed.end(); ++it)
            {
                auto& unprocessed = it->second;

                for (uint64_t i = 0; i < unprocessed.size(); i++)
                {
                    auto& [compacted_first_query, buffer, vector_of_acc_str]{ unprocessed[i] };

                    std::vector<uint64_t> vector_of_acc_str_sizes(vector_of_acc_str.size(), 0);
                    uint64_t              buffer_size = vector_of_acc_str_sizes.size() * sizeof(uint64_t);

                    void* mapped;

                    allocator_->MapResourceMemoryDirect(buffer_size, 0, &mapped, buffer->allocator_data_);

                    util::platform::MemoryCopy(vector_of_acc_str_sizes.data(), buffer_size, mapped, buffer_size);

                    allocator_->UnmapResourceMemoryDirect(buffer->allocator_data_);

                    assert(vector_of_acc_str_sizes != std::vector<uint64_t>(vector_of_acc_str.size(), 0));

                    // add results to compacted_sizes_processed map
                    std::unordered_map<VkAccelerationStructureKHR, VkDeviceSize> processing_result;
                    std::transform(vector_of_acc_str.begin(),
                                   vector_of_acc_str.end(),
                                   vector_of_acc_str_sizes.begin(),
                                   std::inserter(processing_result, processing_result.end()),
                                   [](VkAccelerationStructureKHR acc_str, uint64_t acc_str_size) {
                                       return std::make_pair(acc_str, acc_str_size);
                                   });
                    compacted_sizes_processed.insert(processing_result.begin(), processing_result.end());
                }
            }
            compacted_sizes_unprocessed.clear();
        }

        // create replacement acceleration structure for dst with previously determined compacted size
        if (!compacted_entry->replacement_acceleration_struct_)
        {
            assert(compacted_sizes_processed.count(original_entry->handle_));
            VkDeviceSize size_of_acc{ compacted_sizes_processed[original_entry->handle_] };
            compacted_sizes_processed.erase(original_entry->handle_);

            std::unique_ptr<BufferEntry> storage =
                CreateBuffer(size_of_acc, VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR);
            VkAccelerationStructureBuildSizesInfoKHR size_info{};
            size_info.accelerationStructureSize = size_of_acc;

            VkAccelerationStructureBuildGeometryInfoKHR geometry{};
            geometry.type = compacted_entry->type_;

            VkAccelerationStructureKHR replacement_as =
                CreateAccelerationStructure(geometry, nullptr, size_info, storage->handle_);

            // Store acceleration structure data
            auto replacement_as_address                       = GetAccelerationStructureDeviceAddress(replacement_as);
            compacted_entry->replacement_acceleration_struct_ = std::make_unique<AccelerationStructureEntry>(
                0, replacement_as_address, replacement_as, compacted_entry->type_, size_info);
            compacted_entry->replacement_acceleration_struct_->storage_ = std::move(storage);

            compacted_entry->new_address_ = replacement_as_address;
        }

        modified_info.src = original_entry->replacement_acceleration_struct_->handle_;
        modified_info.dst = compacted_entry->replacement_acceleration_struct_->handle_;
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
        assert(entry->replacement_acceleration_struct_);

        acceleration_structures[index] = entry->replacement_acceleration_struct_->handle_;
        acc_str_to_process.push_back(capture_handle);
    }

    functions_.cmd_write_acceleration_structures_properties(
        command_buffer, count, acceleration_structures, query_type, pool, first_query);

    if (VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR == query_type)
    {
        std::unique_ptr<BufferEntry> stagging_buffer_entry =
            CreateBuffer(sizeof(uint64_t) * count,
                         VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                         (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT));

        // keep track of relation between AS to be compacted and the query pool that handles the results (the order of
        // AS is also important)
        auto [it, inserted] = compacted_sizes_unprocessed.emplace(
            pool,
            std::vector<std::tuple<uint32_t, std::unique_ptr<BufferEntry>, std::vector<VkAccelerationStructureKHR>>>());
        it->second.push_back({ first_query, std::move(stagging_buffer_entry), acc_str_to_process });
    }
}

VkDeviceAddress VulkanAccelerationStructureBuilder::GetAccelerationStructureDeviceAddress(
    VkAccelerationStructureKHR acceleration_structure)
{
    VkAccelerationStructureDeviceAddressInfoKHR info{
        .sType                 = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR,
        .pNext                 = nullptr,
        .accelerationStructure = acceleration_structure
    };
    return functions_.get_acceleration_structure_device_address(device_, &info);
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
    if (!compacted_sizes_unprocessed.count(query_pool_info->handle))
    {
        return;
    }

    std::vector<std::tuple<uint32_t, std::unique_ptr<BufferEntry>, std::vector<VkAccelerationStructureKHR>>>&
        unprocessed = compacted_sizes_unprocessed[query_pool_info->handle];

    for (uint64_t i = 0; i < unprocessed.size(); i++)
    {
        auto& [compacted_first_query, buffer, vector_of_acc_str]{ unprocessed[i] };

        functions_.cmd_copy_query_pool_results(command_buffer_info->handle,
                                               query_pool_info->handle,
                                               compacted_first_query,
                                               vector_of_acc_str.size(),
                                               buffer->handle_,
                                               0,
                                               8,
                                               VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT);

        VkBufferMemoryBarrier buffer_memory_barrier{};
        buffer_memory_barrier.sType         = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
        buffer_memory_barrier.pNext         = nullptr;
        buffer_memory_barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
        buffer_memory_barrier.dstAccessMask = VK_ACCESS_HOST_READ_BIT;
        buffer_memory_barrier.buffer        = buffer->handle_;
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
    if (!compacted_sizes_unprocessed.count(query_pool_info->handle))
    {
        return;
    }

    auto& unprocessed = compacted_sizes_unprocessed[query_pool_info->handle];

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

        assert(vector_of_acc_str_sizes != std::vector<uint64_t>(vector_of_acc_str.size(), 0));

        // add results to compacted_sizes_processed map
        std::unordered_map<VkAccelerationStructureKHR, VkDeviceSize> processing_result;
        std::transform(vector_of_acc_str.begin(),
                       vector_of_acc_str.end(),
                       vector_of_acc_str_sizes.begin(),
                       std::inserter(processing_result, processing_result.end()),
                       [](VkAccelerationStructureKHR acc_str, uint64_t acc_str_size) {
                           return std::make_pair(acc_str, acc_str_size);
                       });
        compacted_sizes_processed.insert(processing_result.begin(), processing_result.end());
    }
}

void VulkanAccelerationStructureBuilder::OnQueueSubmit(uint32_t submitCount, const VkSubmitInfo* pSubmits)
{
    // Perform the actual update of the bottom level acceleration structures in the instance buffers
    for (int i = 0; i < submitCount; ++i)
    {
        auto submission = pSubmits[i];
        for (int cmd_buffer_index = 0; cmd_buffer_index < submission.commandBufferCount; ++cmd_buffer_index)
        {
            auto submitted_buffer = submission.pCommandBuffers[cmd_buffer_index];

            auto instance_buffers_update_itr = instance_buffer_updates_.find(submitted_buffer);
            if (instance_buffers_update_itr != instance_buffer_updates_.end())
            {
                auto instance_buffers_update = instance_buffers_update_itr->second;
                for (auto [resource_data, offset, range_info] : instance_buffers_update)
                {
                    UpdateInstanceBufferContent(resource_data, offset, range_info);
                }
                instance_buffer_updates_.erase(instance_buffers_update_itr);
            }
        }
    }

    // Update the descriptor set with the actual handle, if any such update is stored
    for (auto it = cached_descriptor_write.begin(); it != cached_descriptor_write.end();)
    {
        auto entry = GetAccelerationStructureEntry(it->first);
        if (entry->replacement_acceleration_struct_)
        {
            auto handle =
                std::find(it->second.acc_structs_data.begin(), it->second.acc_structs_data.end(), entry->handle_);
            *handle = entry->replacement_acceleration_struct_->handle_;
            functions_.update_descriptor_sets(device_, 1, &it->second.write_, 0, nullptr);
            it = cached_descriptor_write.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // Update shader group handles if the submission contains vkCmdTraceRays command
    for (int i = 0; i < submitCount; ++i)
    {
        auto submission = pSubmits[i];
        for (int cmd_buffer_index = 0; cmd_buffer_index < submission.commandBufferCount; ++cmd_buffer_index)
        {
            auto submitted_buffer = submission.pCommandBuffers[cmd_buffer_index];

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
    uint8_t*           mapped_sbt_buffer;
    const BufferEntry* sbt_buffer = GetBufferByRuntimeDeviceAddress(sbt_entry.deviceAddress);
    allocator_->MapResourceMemoryDirect(sbt_entry.size, 0, (void**)&mapped_sbt_buffer, sbt_buffer->allocator_data_);

    // sbt device address may be offsetted, account for that in
    const size_t sbt_offset = sbt_entry.deviceAddress - sbt_buffer->new_address_;

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
            assert(entry.original_data_.size() == entry.runtime_data_.size());
            assert(entry.original_data_.size() == raytracing_pipeline_properties_.shader_group_handle_size_aligned);
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

    allocator_->UnmapResourceMemoryDirect(sbt_buffer->allocator_data_);
}

void VulkanAccelerationStructureBuilder::OnCmdTraceRaysKHR(VkCommandBuffer                  command_buffer,
                                                           VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
                                                           VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
                                                           VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
                                                           VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable)
{
    // SBT's device addresses can change, update them based on GetBufferDeviceAddress calls recorded earlier
    UpdateBufferDeviceAddress(pRaygenShaderBindingTable->deviceAddress);
    UpdateBufferDeviceAddress(pMissShaderBindingTable->deviceAddress);
    UpdateBufferDeviceAddress(pHitShaderBindingTable->deviceAddress);
    UpdateBufferDeviceAddress(pCallableShaderBindingTable->deviceAddress);

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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)