/*
** Copyright (c) 2019 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "encode/vulkan_state_writer.h"

#include "encode/struct_pointer_encoder.h"
#include "format/format_util.h"
#include "util/logging.h"

#include <algorithm>
#include <cassert>
#include <limits>
#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateWriter::VulkanStateWriter(util::FileOutputStream*                               output_stream,
                                     util::Compressor*                                     compressor,
                                     format::ThreadId                                      thread_id,
                                     const std::unordered_map<DispatchKey, InstanceTable>* instance_tables,
                                     const std::unordered_map<DispatchKey, DeviceTable>*   device_tables) :
    output_stream_(output_stream),
    compressor_(compressor), thread_id_(thread_id), encoder_(&parameter_stream_), instance_tables_(instance_tables),
    device_tables_(device_tables)
{
    assert(output_stream != nullptr);
    assert(compressor != nullptr);
    assert(instance_tables != nullptr);
    assert(device_tables != nullptr);
}

VulkanStateWriter::~VulkanStateWriter() {}

void VulkanStateWriter::WriteState(const VulkanStateTable& state_table)
{
    // clang-format off

    // Instance, device, and queue creation.
    StandardCreateWrite<InstanceWrapper>(state_table);
    StandardCreateWrite<PhysicalDeviceWrapper>(state_table);
    WriteDeviceState(state_table);
    StandardCreateWrite<QueueWrapper>(state_table);

    // Utility object creation.
    StandardCreateWrite<DebugReportCallbackEXTWrapper>(state_table);
    StandardCreateWrite<DebugUtilsMessengerEXTWrapper>(state_table);
    StandardCreateWrite<ValidationCacheEXTWrapper>(state_table);

    // Synchronization primitive creation.
    StandardCreateWrite<SemaphoreWrapper>(state_table);
    StandardCreateWrite<FenceWrapper>(state_table);
    StandardCreateWrite<EventWrapper>(state_table);

    // WSI object creation.
    StandardCreateWrite<DisplayKHRWrapper>(state_table);
    StandardCreateWrite<DisplayModeKHRWrapper>(state_table);
    StandardCreateWrite<SurfaceKHRWrapper>(state_table);
    StandardCreateWrite<SwapchainKHRWrapper>(state_table);

    // Command creation.
    StandardCreateWrite<CommandPoolWrapper>(state_table);
    StandardCreateWrite<CommandBufferWrapper>(state_table);
    StandardCreateWrite<ObjectTableNVXWrapper>(state_table);
    StandardCreateWrite<IndirectCommandsLayoutNVXWrapper>(state_table);  // TODO: If we intend to support this, we need to reserve command space after creation.

    // Query object creation.
    StandardCreateWrite<QueryPoolWrapper>(state_table);
    StandardCreateWrite<AccelerationStructureNVWrapper>(state_table);

    // Resource creation.
    StandardCreateWrite<DeviceMemoryWrapper>(state_table);
    WriteBufferState(state_table);
    StandardCreateWrite<BufferViewWrapper>(state_table);
    WriteImageState(state_table);
    StandardCreateWrite<ImageViewWrapper>(state_table);
    StandardCreateWrite<SamplerWrapper>(state_table);
    StandardCreateWrite<SamplerYcbcrConversionWrapper>(state_table);

    // Render object creation.
    StandardCreateWrite<RenderPassWrapper>(state_table);
    WriteFramebufferState(state_table);
    StandardCreateWrite<ShaderModuleWrapper>(state_table);
    StandardCreateWrite<DescriptorSetLayoutWrapper>(state_table);
    WritePipelineLayoutState(state_table);
    StandardCreateWrite<PipelineCacheWrapper>(state_table);
    WritePipelineState(state_table);

    // Descriptor creation.
    StandardCreateWrite<DescriptorPoolWrapper>(state_table);
    StandardCreateWrite<DescriptorUpdateTemplateWrapper>(state_table);
    StandardCreateWrite<DescriptorSetWrapper>(state_table);

    // clang-format on
}

void VulkanStateWriter::WriteDeviceState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const DeviceWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write device creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Idle device to ensure all pending work is complete prior to writing state snapshot.
        auto tables_entry = device_tables_->find(GetDispatchKey(wrapper->handle));
        if (tables_entry != device_tables_->end())
        {
            VkResult result = tables_entry->second.DeviceWaitIdle(wrapper->handle);
            if (result != VK_SUCCESS)
            {
                GFXRECON_LOG_WARNING("Device wait idle failed during state snapshot generation");
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Attempting to retrieve a device dispatch table for an unrecognized device handle");
        }
    });
}

void VulkanStateWriter::WriteBufferState(const VulkanStateTable& state_table)
{
    std::unordered_map<VkDevice, BufferSnapshotData> buffers;

    state_table.VisitWrappers([&](const BufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write buffer creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Perform memory binding.
        if (wrapper->bind_memory != VK_NULL_HANDLE)
        {
            encoder_.EncodeHandleIdValue(wrapper->bind_device);
            encoder_.EncodeHandleIdValue(wrapper->handle);
            encoder_.EncodeHandleIdValue(wrapper->bind_memory);
            encoder_.EncodeVkDeviceSizeValue(wrapper->bind_offset);
            encoder_.EncodeEnumValue(VK_SUCCESS);

            WriteFunctionCall(format::ApiCall_vkBindBufferMemory, &parameter_stream_);
            parameter_stream_.Reset();

            // Group buffers with memory bindings by device for memory snapshot.
            BufferSnapshotData&   snapshot_data = buffers[wrapper->bind_device];
            VkMemoryPropertyFlags properties =
                GetMemoryProperties(wrapper->bind_device, wrapper->bind_memory, state_table);
            const DeviceMemoryWrapper* memory_wrapper =
                state_table.GetDeviceMemoryWrapper(format::ToHandleId(wrapper->bind_memory));

            BufferSnapshotEntry entry;
            entry.buffer_wrapper = wrapper;
            entry.memory_wrapper = memory_wrapper;

            if ((properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
            {
                entry.is_host_visible = true;
            }
            else
            {
                entry.is_host_visible = false;
                ++snapshot_data.num_device_local_buffers;
                if (snapshot_data.max_device_local_buffer_size < wrapper->created_size)
                {
                    snapshot_data.max_device_local_buffer_size = wrapper->created_size;
                }
            }

            // If host visible memory is already mapped, and the entire allocation is not mapped, a staging copy will be
            // used to ensure that the entire allocation is accessible for the state snapshot.
            if (entry.is_host_visible && ((memory_wrapper->mapped_data == nullptr) ||
                                          ((memory_wrapper->mapped_offset == 0) &&
                                           ((memory_wrapper->mapped_size == memory_wrapper->allocation_size) ||
                                            (memory_wrapper->mapped_size == VK_WHOLE_SIZE)))))
            {
                snapshot_data.map_copy_wrappers.emplace_back(entry);
            }
            else
            {
                if (snapshot_data.max_staging_copy_size < wrapper->created_size)
                {
                    snapshot_data.max_staging_copy_size = wrapper->created_size;
                }

                snapshot_data.staging_copy_wrappers[wrapper->queue_family_index].emplace_back(entry);
            }
        }
    });

    // Write snapshot of buffer memory content.
    for (auto buffers_entry : buffers)
    {
        auto tables_entry = device_tables_->find(GetDispatchKey(buffers_entry.first));
        if (tables_entry != device_tables_->end())
        {
            ProcessBufferMemory(buffers_entry.first, buffers_entry.second, state_table, tables_entry->second);
        }
        else
        {
            GFXRECON_LOG_ERROR("Attempting to retrieve a device dispatch table for an unrecognized device handle");
        }
    }
}

void VulkanStateWriter::WriteImageState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const ImageWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write image creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Perform memory binding.
        if (wrapper->bind_memory != VK_NULL_HANDLE)
        {
            encoder_.EncodeHandleIdValue(wrapper->bind_device);
            encoder_.EncodeHandleIdValue(wrapper->handle);
            encoder_.EncodeHandleIdValue(wrapper->bind_memory);
            encoder_.EncodeVkDeviceSizeValue(wrapper->bind_offset);
            encoder_.EncodeEnumValue(VK_SUCCESS);

            WriteFunctionCall(format::ApiCall_vkBindImageMemory, &parameter_stream_);

            parameter_stream_.Reset();
        }
    });
}

void VulkanStateWriter::WriteFramebufferState(const VulkanStateTable& state_table)
{
    std::unordered_map<format::HandleId, const FramebufferWrapper*> temp_render_passes;

    state_table.VisitWrappers([&](const FramebufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write buffer creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        const RenderPassWrapper* render_pass_wrapper =
            state_table.GetRenderPassWrapper(format::ToHandleId(wrapper->render_pass));
        if ((render_pass_wrapper == nullptr) || (render_pass_wrapper->handle_id != wrapper->render_pass_id))
        {
            // Either the handle does not exist, or it has been recycled and now references a different object.
            const auto& inserted = temp_render_passes.insert(std::make_pair(wrapper->render_pass_id, wrapper));

            // Create a temporary object on first encounter.
            if (inserted.second)
            {
                WriteFunctionCall(wrapper->render_pass_create_call_id, wrapper->render_pass_create_parameters.get());
            }
        }
    });

    // Temporary object destruction.
    for (const auto& entry : temp_render_passes)
    {
        const FramebufferWrapper* info = entry.second;
        assert(info != nullptr);
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyRenderPass,
                                     format::ToHandleId(info->render_pass),
                                     info->render_pass_create_parameters.get());
    }
}

void VulkanStateWriter::WritePipelineLayoutState(const VulkanStateTable& state_table)
{
    // TODO: Temporary ds layouts are potentially created and destroyed by both WritePipelineLayoutState and
    // WritePipelineState; track temporary creation across calls to avoid duplicate temporary allocations.
    std::unordered_map<format::HandleId, const DescriptorSetLayoutInfo*> temp_ds_layouts;

    // Perform temporary creations for dependencies that are no longer live, and create the pipeline layout.
    state_table.VisitWrappers([&](const PipelineLayoutWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Check descriptor set layout dependencies.
        auto deps = wrapper->layout_dependencies;
        for (const auto& entry : deps->layouts)
        {
            const DescriptorSetLayoutWrapper* ds_layout_wrapper =
                state_table.GetDescriptorSetLayoutWrapper(format::ToHandleId(entry.handle));
            if ((ds_layout_wrapper == nullptr) || (ds_layout_wrapper->handle_id != entry.handle_id))
            {
                const auto& inserted = temp_ds_layouts.insert(std::make_pair(entry.handle_id, &entry));

                // Create a temporary object on first encounter.
                if (inserted.second)
                {
                    WriteFunctionCall(entry.create_call_id, entry.create_parameters.get());
                }
            }
        }

        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });

    // Destroy any temporary resources that were created.
    for (const auto& entry : temp_ds_layouts)
    {
        const DescriptorSetLayoutInfo* info = entry.second;
        assert(info != nullptr);
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyDescriptorSetLayout,
                                     format::ToHandleId(info->handle),
                                     info->create_parameters.get());
    }
}

void VulkanStateWriter::WritePipelineState(const VulkanStateTable& state_table)
{
    // Multiple pipelines can be created by a single API call, so using a set to filter duplicate pipeline creation.
    // TODO: Some of the pipelines created may have been destroyed, in which case, the current design can create more
    // pipelines than it should, resulting in object leaks or the overwriting of recycled handles.
    std::set<CreateParameters> graphics_pipelines;
    std::set<CreateParameters> compute_pipelines;
    std::set<CreateParameters> ray_tracing_pipelines;

    std::unordered_map<format::HandleId, const ShaderModuleInfo*>        temp_shaders;
    std::unordered_map<format::HandleId, const PipelineWrapper*>         temp_render_passes;
    std::unordered_map<format::HandleId, const PipelineWrapper*>         temp_layouts;
    std::unordered_map<format::HandleId, const DescriptorSetLayoutInfo*> temp_ds_layouts;

    // First pass over pipeline table to sort pipelines by type and determine which dependencies need to be created
    // temporarily.
    state_table.VisitWrappers([&](const PipelineWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Determine type of pipeline.
        if (wrapper->create_call_id == format::ApiCall_vkCreateGraphicsPipelines)
        {
            graphics_pipelines.insert(wrapper->create_parameters);
        }
        else if (wrapper->create_call_id == format::ApiCall_vkCreateComputePipelines)
        {
            compute_pipelines.insert(wrapper->create_parameters);
        }
        else if (wrapper->create_call_id == format::ApiCall_vkCreateRayTracingPipelinesNV)
        {
            ray_tracing_pipelines.insert(wrapper->create_parameters);
        }

        // Check for creation dependencies that no longer exist.
        for (const auto& entry : wrapper->shader_modules)
        {
            const ShaderModuleWrapper* shader_wrapper =
                state_table.GetShaderModuleWrapper(format::ToHandleId(entry.handle));
            if ((shader_wrapper == nullptr) || (shader_wrapper->handle_id != entry.handle_id))
            {
                // Either the handle does not exist, or it has been recycled and now references a different object.
                const auto& inserted = temp_shaders.insert(std::make_pair(entry.handle_id, &entry));

                // Create a temporary object on first encounter.
                if (inserted.second)
                {
                    WriteFunctionCall(entry.create_call_id, entry.create_parameters.get());
                }
            }
        }

        const RenderPassWrapper* render_pass_wrapper =
            state_table.GetRenderPassWrapper(format::ToHandleId(wrapper->render_pass));
        if ((render_pass_wrapper == nullptr) || (render_pass_wrapper->handle_id != wrapper->render_pass_id))
        {
            // Either the handle does not exist, or it has been recycled and now references a different object.
            const auto& inserted = temp_render_passes.insert(std::make_pair(wrapper->render_pass_id, wrapper));

            // Create a temporary object on first encounter.
            if (inserted.second)
            {
                WriteFunctionCall(wrapper->render_pass_create_call_id, wrapper->render_pass_create_parameters.get());
            }
        }

        const PipelineLayoutWrapper* layout_wrapper =
            state_table.GetPipelineLayoutWrapper(format::ToHandleId(wrapper->layout));
        if ((layout_wrapper == nullptr) || (layout_wrapper->handle_id != wrapper->layout_id))
        {
            // Either the handle does not exist, or it has been recycled and now references a different object.
            const auto& inserted = temp_layouts.insert(std::make_pair(wrapper->layout_id, wrapper));

            // Create a temporary object on first encounter.
            if (inserted.second)
            {
                // Check descriptor set layout dependencies.
                auto deps = wrapper->layout_dependencies;
                for (const auto& entry : deps->layouts)
                {
                    const DescriptorSetLayoutWrapper* ds_layout_wrapper =
                        state_table.GetDescriptorSetLayoutWrapper(format::ToHandleId(entry.handle));
                    if ((ds_layout_wrapper == nullptr) || (ds_layout_wrapper->handle_id != entry.handle_id))
                    {
                        const auto& inserted = temp_ds_layouts.insert(std::make_pair(entry.handle_id, &entry));

                        // Create a temporary object on first encounter.
                        if (inserted.second)
                        {
                            WriteFunctionCall(entry.create_call_id, entry.create_parameters.get());
                        }
                    }
                }

                WriteFunctionCall(wrapper->layout_create_call_id, wrapper->layout_create_parameters.get());
            }
        }
    });

    // Pipeline object creation.
    for (const auto& entry : graphics_pipelines)
    {
        WriteFunctionCall(format::ApiCall_vkCreateGraphicsPipelines, entry.get());
    }

    for (const auto& entry : compute_pipelines)
    {
        WriteFunctionCall(format::ApiCall_vkCreateComputePipelines, entry.get());
    }

    for (const auto& entry : compute_pipelines)
    {
        WriteFunctionCall(format::ApiCall_vkCreateRayTracingPipelinesNV, entry.get());
    }

    // Temporary object destruction.
    for (const auto& entry : temp_shaders)
    {
        const ShaderModuleInfo* info = entry.second;
        assert(info != nullptr);
        DestroyTemporaryDeviceObject(
            format::ApiCall_vkDestroyShaderModule, format::ToHandleId(info->handle), info->create_parameters.get());
    }

    for (const auto& entry : temp_render_passes)
    {
        const PipelineWrapper* info = entry.second;
        assert(info != nullptr);
        DestroyTemporaryDeviceObject(
            format::ApiCall_vkDestroyRenderPass, format::ToHandleId(info->render_pass), info->create_parameters.get());
    }

    for (const auto& entry : temp_ds_layouts)
    {
        const DescriptorSetLayoutInfo* info = entry.second;
        assert(info != nullptr);
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyDescriptorSetLayout,
                                     format::ToHandleId(info->handle),
                                     info->create_parameters.get());
    }

    for (const auto& entry : temp_layouts)
    {
        const PipelineWrapper* info = entry.second;
        assert(info != nullptr);
        DestroyTemporaryDeviceObject(
            format::ApiCall_vkDestroyPipelineLayout, format::ToHandleId(info->layout), info->create_parameters.get());
    }
}

void VulkanStateWriter::ProcessBufferMemory(VkDevice                  device,
                                            const BufferSnapshotData& snapshot_data,
                                            const VulkanStateTable&   state_table,
                                            const DeviceTable&        dispatch_table)
{
    if (!snapshot_data.staging_copy_wrappers.empty())
    {
        VkMemoryRequirements staging_memory_requirements;
        uint32_t             staging_memory_type_index = 0;
        VkDeviceMemory       staging_memory            = VK_NULL_HANDLE;
        VkBuffer             staging_buffer            = VK_NULL_HANDLE;

        VkResult result = CreateStagingBuffer(device,
                                              snapshot_data.max_staging_copy_size,
                                              &staging_buffer,
                                              &staging_memory_requirements,
                                              &staging_memory_type_index,
                                              &staging_memory,
                                              state_table,
                                              dispatch_table);

        if (result == VK_SUCCESS)
        {
            if (snapshot_data.num_device_local_buffers > 0)
            {
                // Write calls to staging buffer needed to replay the staging copies to device local memory.
                WriteStagingBufferCreateCommands(device,
                                                 snapshot_data.max_device_local_buffer_size,
                                                 staging_buffer,
                                                 staging_memory_requirements,
                                                 staging_memory_type_index,
                                                 staging_memory);
            }

            for (auto copy_entry : snapshot_data.staging_copy_wrappers)
            {
                uint32_t queue_family_index = copy_entry.first;
                VkQueue  queue              = VK_NULL_HANDLE;

                dispatch_table.GetDeviceQueue(device, queue_family_index, 0, &queue);

                // Create a command pool for the current queue family index.
                VkCommandPool command_pool = GetCommandPool(device, queue_family_index, dispatch_table);

                if (command_pool != VK_NULL_HANDLE)
                {
                    VkCommandBuffer command_buffer = GetCommandBuffer(device, command_pool, dispatch_table);

                    if (command_buffer != VK_NULL_HANDLE)
                    {
                        if (snapshot_data.num_device_local_buffers > 0)
                        {
                            // Write calls to create the command pool and command buffer needed for the staging copies.
                            WriteCommandProcessingCreateCommands(
                                device, queue_family_index, queue, command_pool, command_buffer);
                        }

                        for (auto buffer_entry : copy_entry.second)
                        {
                            VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
                            begin_info.pNext                    = nullptr;
                            begin_info.flags                    = 0;
                            begin_info.pInheritanceInfo         = nullptr;

                            result = dispatch_table.BeginCommandBuffer(command_buffer, &begin_info);

                            if (result == VK_SUCCESS)
                            {
                                const BufferWrapper*       buffer_wrapper = buffer_entry.buffer_wrapper;
                                const DeviceMemoryWrapper* memory_wrapper = buffer_entry.memory_wrapper;

                                VkBufferCopy copy_region;
                                copy_region.srcOffset = 0;
                                copy_region.dstOffset = 0;
                                copy_region.size      = buffer_wrapper->created_size;

                                dispatch_table.CmdCopyBuffer(
                                    command_buffer, buffer_wrapper->handle, staging_buffer, 1, &copy_region);
                                dispatch_table.EndCommandBuffer(command_buffer);

                                result = SubmitCommandBuffer(queue, command_buffer, dispatch_table);

                                if (result == VK_SUCCESS)
                                {
                                    if (buffer_entry.is_host_visible)
                                    {
                                        // Replay does not require a staging copy as the memory has not yet been mapped
                                        // in the replay command stream.
                                        WriteMappedMemoryCopyCommands(device,
                                                                      staging_memory,
                                                                      nullptr,
                                                                      0,
                                                                      buffer_wrapper->created_size,
                                                                      memory_wrapper->handle,
                                                                      buffer_wrapper->bind_offset,
                                                                      buffer_wrapper->created_size,
                                                                      dispatch_table);
                                    }
                                    else
                                    {
                                        // Replay requires a staging copy. Write replay commands to map and write data
                                        // into the temporary staging buffer, then perform the copy.
                                        WriteMappedMemoryCopyCommands(device,
                                                                      staging_memory,
                                                                      nullptr,
                                                                      0,
                                                                      buffer_wrapper->created_size,
                                                                      staging_memory,
                                                                      0,
                                                                      buffer_wrapper->created_size,
                                                                      dispatch_table);

                                        WriteStagingCopyCommands(device,
                                                                 queue,
                                                                 command_buffer,
                                                                 staging_buffer,
                                                                 buffer_wrapper->handle,
                                                                 0,
                                                                 buffer_wrapper->bind_offset,
                                                                 buffer_wrapper->created_size);
                                    }
                                }
                                else
                                {
                                    GFXRECON_LOG_ERROR("Command buffer submission failed when performing a staging "
                                                       "copy while processing trim state");
                                }
                            }
                            else
                            {
                                GFXRECON_LOG_ERROR("Begin command buffer failed when performing a staging copy while "
                                                   "processing trim state");
                            }
                        }

                        if (snapshot_data.num_device_local_buffers > 0)
                        {
                            WriteDestroyDeviceObject(format::ApiCallId::ApiCall_vkDestroyCommandPool,
                                                     format::ToHandleId(device),
                                                     format::ToHandleId(command_pool),
                                                     nullptr);
                        }
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Failed to create a command buffer to process trim state");
                    }

                    dispatch_table.DestroyCommandPool(device, command_pool, nullptr);
                    command_pool = VK_NULL_HANDLE;
                }
                else
                {
                    GFXRECON_LOG_ERROR("Failed to create a command pool to process trim state");
                }
            }

            if (snapshot_data.num_device_local_buffers > 0)
            {
                // Write calls to staging buffer needed to replay the staging copies to device local memory.
                WriteDestroyDeviceObject(format::ApiCallId::ApiCall_vkDestroyBuffer,
                                         format::ToHandleId(device),
                                         format::ToHandleId(staging_buffer),
                                         nullptr);

                WriteDestroyDeviceObject(format::ApiCallId::ApiCall_vkFreeMemory,
                                         format::ToHandleId(device),
                                         format::ToHandleId(staging_memory),
                                         nullptr);
            }

            dispatch_table.DestroyBuffer(device, staging_buffer, nullptr);
            dispatch_table.FreeMemory(device, staging_memory, nullptr);
        }
    }

    for (auto buffer_entry : snapshot_data.map_copy_wrappers)
    {
        const BufferWrapper*       buffer_wrapper = buffer_entry.buffer_wrapper;
        const DeviceMemoryWrapper* memory_wrapper = buffer_entry.memory_wrapper;

        assert((memory_wrapper != nullptr) &&
               ((memory_wrapper->mapped_data == nullptr) || (memory_wrapper->mapped_offset == 0)));

        WriteMappedMemoryCopyCommands(device,
                                      memory_wrapper->handle,
                                      memory_wrapper->mapped_data,
                                      buffer_wrapper->bind_offset,
                                      buffer_wrapper->created_size,
                                      memory_wrapper->handle,
                                      buffer_wrapper->bind_offset,
                                      buffer_wrapper->created_size,
                                      dispatch_table);
    }
}

void VulkanStateWriter::WriteStagingBufferCreateCommands(VkDevice                    device,
                                                         VkDeviceSize                buffer_size,
                                                         VkBuffer                    buffer,
                                                         const VkMemoryRequirements& memory_requirements,
                                                         uint32_t                    memory_type_index,
                                                         VkDeviceMemory              memory)
{
    const VkResult               result    = VK_SUCCESS;
    const VkAllocationCallbacks* allocator = nullptr;

    // Create the staging buffer.
    VkBufferCreateInfo create_info    = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.size                  = buffer_size;
    create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_SRC_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;

    encoder_.EncodeHandleIdValue(device);
    EncodeStructPtr(&encoder_, &create_info);
    EncodeStructPtr(&encoder_, allocator);
    encoder_.EncodeHandleIdPtr(&buffer);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkCreateBuffer, &parameter_stream_);
    parameter_stream_.Reset();

    // Get the buffer memory requirements.
    encoder_.EncodeHandleIdValue(device);
    encoder_.EncodeHandleIdValue(buffer);
    EncodeStructPtr(&encoder_, &memory_requirements);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetBufferMemoryRequirements, &parameter_stream_);
    parameter_stream_.Reset();

    // Allocate the memory for the buffer.
    VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
    alloc_info.pNext                = nullptr;
    alloc_info.allocationSize       = memory_requirements.size;
    alloc_info.memoryTypeIndex      = memory_type_index;

    encoder_.EncodeHandleIdValue(device);
    EncodeStructPtr(&encoder_, &alloc_info);
    EncodeStructPtr(&encoder_, allocator);
    encoder_.EncodeHandleIdPtr(&memory);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkAllocateMemory, &parameter_stream_);
    parameter_stream_.Reset();

    // Bind the buffer to the memory.
    encoder_.EncodeHandleIdValue(device);
    encoder_.EncodeHandleIdValue(buffer);
    encoder_.EncodeHandleIdValue(memory);
    encoder_.EncodeVkDeviceSizeValue(0);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkBindBufferMemory, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteCommandProcessingCreateCommands(VkDevice        device,
                                                             uint32_t        queue_family_index,
                                                             VkQueue         queue,
                                                             VkCommandPool   command_pool,
                                                             VkCommandBuffer command_buffer)
{
    const VkResult               result    = VK_SUCCESS;
    const VkAllocationCallbacks* allocator = nullptr;

    // Retrieve the queue for the queue family index.
    encoder_.EncodeHandleIdValue(device);
    encoder_.EncodeUInt32Value(queue_family_index);
    encoder_.EncodeUInt32Value(0);
    encoder_.EncodeHandleIdPtr(&queue);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetDeviceQueue, &parameter_stream_);
    parameter_stream_.Reset();

    // Create the command pool for the current queue family index.
    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    create_info.pNext                   = nullptr;
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = queue_family_index;

    encoder_.EncodeHandleIdValue(device);
    EncodeStructPtr(&encoder_, &create_info);
    EncodeStructPtr(&encoder_, allocator);
    encoder_.EncodeHandleIdPtr(&command_pool);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkCreateCommandPool, &parameter_stream_);
    parameter_stream_.Reset();

    // Create the command buffer from the pool.
    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.pNext                       = nullptr;
    alloc_info.commandPool                 = command_pool;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;

    encoder_.EncodeHandleIdValue(device);
    EncodeStructPtr(&encoder_, &alloc_info);
    encoder_.EncodeHandleIdArray(&command_buffer, 1);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkAllocateCommandBuffers, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteMappedMemoryCopyCommands(VkDevice           device,
                                                      VkDeviceMemory     source_memory,
                                                      const void*        source_data,
                                                      VkDeviceSize       source_offset,
                                                      VkDeviceSize       source_size,
                                                      VkDeviceMemory     replay_memory,
                                                      VkDeviceSize       replay_offset,
                                                      VkDeviceSize       replay_size,
                                                      const DeviceTable& dispatch_table)
{
    const VkResult result     = VK_SUCCESS;
    bool           need_unmap = false;

    // If the source memory is not mapped, map it.
    if (source_data == nullptr)
    {
        need_unmap = true;

        void* data = nullptr;
        dispatch_table.MapMemory(device, source_memory, source_offset, source_size, 0, &data);

        source_data = data;
    }
    else
    {
        // Mapped memory is expected to have been mapped with an offset of 0, otherwise it would have been copied to a
        // staging buffer. The fill memory command generated for the state snapshot will expect the data pointer to
        // start at the reosurce bind offset, rather than the start of the memory allocation.
        source_data = static_cast<const uint8_t*>(source_data) + source_offset;
    }

    // Map the replay memory.
    encoder_.EncodeHandleIdValue(device);
    encoder_.EncodeHandleIdValue(replay_memory);
    encoder_.EncodeVkDeviceSizeValue(replay_offset);
    encoder_.EncodeVkDeviceSizeValue(replay_size);
    encoder_.EncodeFlagsValue(0);
    encoder_.EncodeVoidPtrPtr(&source_data);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkMapMemory, &parameter_stream_);
    parameter_stream_.Reset();

    // Generate a fill memory command from the source data.
    WriteFillMemoryCmd(replay_memory, 0, replay_size, source_data);

    // Unmap the replay memory.
    encoder_.EncodeHandleIdValue(device);
    encoder_.EncodeHandleIdValue(replay_memory);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkUnmapMemory, &parameter_stream_);
    parameter_stream_.Reset();

    if (need_unmap)
    {
        dispatch_table.UnmapMemory(device, source_memory);
    }
}

void VulkanStateWriter::WriteStagingCopyCommands(VkDevice        device,
                                                 VkQueue         queue,
                                                 VkCommandBuffer command_buffer,
                                                 VkBuffer        source,
                                                 VkBuffer        destination,
                                                 VkDeviceSize    source_offset,
                                                 VkDeviceSize    destination_offset,
                                                 VkDeviceSize    size)
{
    const VkResult result = VK_SUCCESS;

    // Begin the command buffer for the copy.
    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.pNext                    = nullptr;
    begin_info.flags                    = 0;
    begin_info.pInheritanceInfo         = nullptr;

    encoder_.EncodeHandleIdValue(command_buffer);
    EncodeStructPtr(&encoder_, &begin_info);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkBeginCommandBuffer, &parameter_stream_);
    parameter_stream_.Reset();

    // Record the copy command.
    VkBufferCopy copy_region;
    copy_region.srcOffset = source_offset;
    copy_region.dstOffset = destination_offset;
    copy_region.size      = size;

    encoder_.EncodeHandleIdValue(command_buffer);
    encoder_.EncodeHandleIdValue(source);
    encoder_.EncodeHandleIdValue(destination);
    encoder_.EncodeUInt32Value(1);
    EncodeStructArray(&encoder_, &copy_region, 1);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdCopyBuffer, &parameter_stream_);
    parameter_stream_.Reset();

    // End the command buffer.
    encoder_.EncodeHandleIdValue(command_buffer);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkEndCommandBuffer, &parameter_stream_);
    parameter_stream_.Reset();

    // Write queue submission.
    VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = 0;
    submit_info.pWaitSemaphores      = nullptr;
    submit_info.pWaitDstStageMask    = nullptr;
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &command_buffer;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

    encoder_.EncodeHandleIdValue(queue);
    encoder_.EncodeUInt32Value(1);
    EncodeStructArray(&encoder_, &submit_info, 1);
    encoder_.EncodeHandleIdValue<VkFence>(VK_NULL_HANDLE);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkQueueSubmit, &parameter_stream_);
    parameter_stream_.Reset();

    // Write queue wait idle.
    encoder_.EncodeHandleIdValue(queue);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkQueueWaitIdle, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteDestroyDeviceObject(format::ApiCallId            call_id,
                                                 format::HandleId             device_id,
                                                 format::HandleId             object_id,
                                                 const VkAllocationCallbacks* allocator)
{
    encoder_.EncodeHandleIdValue(device_id);
    encoder_.EncodeHandleIdValue(object_id);
    EncodeStructPtr(&encoder_, allocator);

    WriteFunctionCall(call_id, &parameter_stream_);

    parameter_stream_.Reset();
}

void VulkanStateWriter::DestroyTemporaryDeviceObject(format::ApiCallId         call_id,
                                                     format::HandleId          object_id,
                                                     util::MemoryOutputStream* create_parameters)
{
    // TODO: Track allocation callbacks.
    const VkAllocationCallbacks* allocator = nullptr;

    // Extract device from create parameter buffer.
    // TODO: Device children will be stored in the device wrapper, and device handle will be directly available when
    // processing children (no need to extract).
    format::HandleId device_id = *reinterpret_cast<const format::HandleId*>(create_parameters->GetData());

    WriteDestroyDeviceObject(call_id, device_id, object_id, allocator);
}

// TODO: This is the same code used by TraceManager to write function call data. It could be moved to a format utility.
void VulkanStateWriter::WriteFunctionCall(format::ApiCallId call_id, util::MemoryOutputStream* parameter_buffer)
{
    assert(parameter_buffer != nullptr);

    bool                                 not_compressed      = true;
    format::CompressedFunctionCallHeader compressed_header   = {};
    format::FunctionCallHeader           uncompressed_header = {};
    size_t                               uncompressed_size   = parameter_buffer->GetDataSize();
    size_t                               header_size         = 0;
    const void*                          header_pointer      = nullptr;
    size_t                               data_size           = 0;
    const void*                          data_pointer        = nullptr;

    if (compressor_ != nullptr)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &compressed_parameter_buffer_);

        if ((0 < compressed_size) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_parameter_buffer_.data());
            data_size      = compressed_size;
            header_pointer = reinterpret_cast<const void*>(&compressed_header);
            header_size    = sizeof(format::CompressedFunctionCallHeader);

            compressed_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_header.api_call_id       = call_id;
            compressed_header.thread_id         = thread_id_;
            compressed_header.uncompressed_size = uncompressed_size;

            packet_size += sizeof(compressed_header.api_call_id) + sizeof(compressed_header.uncompressed_size) +
                           sizeof(compressed_header.thread_id) + compressed_size;

            compressed_header.block_header.size = packet_size;
            not_compressed                      = false;
        }
    }

    if (not_compressed)
    {
        size_t packet_size = 0;
        data_pointer       = reinterpret_cast<const void*>(parameter_buffer->GetData());
        data_size          = uncompressed_size;
        header_pointer     = reinterpret_cast<const void*>(&uncompressed_header);
        header_size        = sizeof(format::FunctionCallHeader);

        uncompressed_header.block_header.type = format::BlockType::kFunctionCallBlock;
        uncompressed_header.api_call_id       = call_id;
        uncompressed_header.thread_id         = thread_id_;

        packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;

        uncompressed_header.block_header.size = packet_size;
    }

    // Write appropriate function call block header.
    output_stream_->Write(header_pointer, header_size);

    // Write parameter data.
    output_stream_->Write(data_pointer, data_size);
}

// TODO: This is the same code used by TraceManager to write command data. It could be moved to a format utility.
void VulkanStateWriter::WriteFillMemoryCmd(VkDeviceMemory memory,
                                           VkDeviceSize   offset,
                                           VkDeviceSize   size,
                                           const void*    data)
{
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

    format::FillMemoryCommandHeader fill_cmd;
    const uint8_t*                  write_address = (static_cast<const uint8_t*>(data) + offset);
    size_t                          write_size    = static_cast<size_t>(size);

    fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    fill_cmd.meta_header.meta_data_type    = format::MetaDataType::kFillMemoryCommand;
    fill_cmd.thread_id                     = thread_id_;
    fill_cmd.memory_id                     = format::ToHandleId(memory);
    fill_cmd.memory_offset                 = offset;
    fill_cmd.memory_size                   = size;

    if (compressor_ != nullptr)
    {
        size_t compressed_size = compressor_->Compress(write_size, write_address, &compressed_parameter_buffer_);

        if ((compressed_size > 0) && (compressed_size < write_size))
        {
            // We don't have a special header for compressed fill commands because the header always includes
            // the uncompressed size, so we just change the type to indicate the data is compressed.
            fill_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

            write_address = compressed_parameter_buffer_.data();
            write_size    = compressed_size;
        }
    }

    // Calculate size of packet with compressed or uncompressed data size.
    fill_cmd.meta_header.block_header.size = sizeof(fill_cmd.meta_header.meta_data_type) + sizeof(fill_cmd.thread_id) +
                                             sizeof(fill_cmd.memory_id) + sizeof(fill_cmd.memory_offset) +
                                             sizeof(fill_cmd.memory_size) + write_size;

    output_stream_->Write(&fill_cmd, sizeof(fill_cmd));
    output_stream_->Write(write_address, write_size);
}

VkMemoryPropertyFlags
VulkanStateWriter::GetMemoryProperties(VkDevice device, VkDeviceMemory memory, const VulkanStateTable& state_table)
{
    VkMemoryPropertyFlags      flags          = 0;
    const DeviceWrapper*       device_wrapper = state_table.GetDeviceWrapper(format::ToHandleId(device));
    const DeviceMemoryWrapper* memory_wrapper = state_table.GetDeviceMemoryWrapper(format::ToHandleId(memory));

    assert((device_wrapper != nullptr) && (memory_wrapper != nullptr));

    const PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;

    assert(physical_device_wrapper != nullptr);

    if (!physical_device_wrapper->memory_types.empty())
    {
        assert(memory_wrapper->memory_type_index < physical_device_wrapper->memory_types.size());
        flags = physical_device_wrapper->memory_types[memory_wrapper->memory_type_index].propertyFlags;
    }
    else
    {
        // The application has not queried for memory types.
        VkPhysicalDeviceMemoryProperties properties;

        auto entry = instance_tables_->find(GetDispatchKey(physical_device_wrapper->handle));
        if (entry != instance_tables_->end())
        {
            entry->second.GetPhysicalDeviceMemoryProperties(physical_device_wrapper->handle, &properties);
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "Attempting to call vkGetPhysicalDeviceMemoryProperties through an untracked device handle");
        }

        flags = properties.memoryTypes[memory_wrapper->memory_type_index].propertyFlags;
    }

    return flags;
}

uint32_t VulkanStateWriter::FindMemoryTypeIndex(VkDevice                device,
                                                uint32_t                memory_type_bits,
                                                VkMemoryPropertyFlags   memory_property_flags,
                                                const VulkanStateTable& state_table)
{
    uint32_t             index          = std::numeric_limits<uint32_t>::max();
    const DeviceWrapper* device_wrapper = state_table.GetDeviceWrapper(format::ToHandleId(device));

    assert(device_wrapper != nullptr);

    const PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;

    assert(physical_device_wrapper != nullptr);

    if (!physical_device_wrapper->memory_types.empty())
    {
        for (uint32_t i = 0; i < physical_device_wrapper->memory_types.size(); ++i)
        {
            if ((memory_type_bits & (1 << i)) && ((physical_device_wrapper->memory_types[i].propertyFlags &
                                                   memory_property_flags) == memory_property_flags))
            {
                index = i;
                break;
            }
        }
    }
    else
    {
        // The application has not queried for memory types.
        VkPhysicalDeviceMemoryProperties properties;

        auto entry = instance_tables_->find(GetDispatchKey(physical_device_wrapper->handle));
        if (entry != instance_tables_->end())
        {
            entry->second.GetPhysicalDeviceMemoryProperties(physical_device_wrapper->handle, &properties);

            for (uint32_t i = 0; i < properties.memoryTypeCount; ++i)
            {
                if ((memory_type_bits & (1 << i)) &&
                    ((properties.memoryTypes[i].propertyFlags & memory_property_flags) == memory_property_flags))
                {
                    index = i;
                    break;
                }
            }
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "Attempting to call vkGetPhysicalDeviceMemoryProperties through an untracked device handle");
        }
    }

    return index;
}

VkCommandPool
VulkanStateWriter::GetCommandPool(VkDevice device, uint32_t queue_family_index, const DeviceTable& dispatch_table)
{
    VkCommandPool command_pool = VK_NULL_HANDLE;

    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    create_info.pNext                   = nullptr;
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = queue_family_index;

    VkResult result = dispatch_table.CreateCommandPool(device, &create_info, nullptr, &command_pool);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create a command pool for resource memory snapshot");
    }

    return command_pool;
}

VkCommandBuffer
VulkanStateWriter::GetCommandBuffer(VkDevice device, VkCommandPool command_pool, const DeviceTable& dispatch_table)
{
    VkCommandBuffer command_buffer = VK_NULL_HANDLE;

    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.pNext                       = nullptr;
    alloc_info.commandPool                 = command_pool;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;

    VkResult result = dispatch_table.AllocateCommandBuffers(device, &alloc_info, &command_buffer);

    if (result == VK_SUCCESS)
    {
        // Because this command buffer was not allocated through the loader, it must be assigned a dispatch
        // table.
        *reinterpret_cast<void**>(command_buffer) = *reinterpret_cast<void**>(device);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create a command buffer for resource memory snapshot");
    }

    return command_buffer;
}

VkResult
VulkanStateWriter::SubmitCommandBuffer(VkQueue queue, VkCommandBuffer command_buffer, const DeviceTable& dispatch_table)
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

    dispatch_table.QueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);

    return dispatch_table.QueueWaitIdle(queue);
}

VkResult VulkanStateWriter::CreateStagingBuffer(VkDevice                device,
                                                VkDeviceSize            size,
                                                VkBuffer*               buffer,
                                                VkMemoryRequirements*   memory_requirements,
                                                uint32_t*               memory_type_index,
                                                VkDeviceMemory*         memory,
                                                const VulkanStateTable& state_table,
                                                const DeviceTable&      dispatch_table)
{
    assert((buffer != nullptr) && (memory_type_index != nullptr) && (memory_requirements != nullptr) &&
           (memory != nullptr));

    VkBufferCreateInfo create_info    = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.size                  = size;
    create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;

    VkResult result = dispatch_table.CreateBuffer(device, &create_info, nullptr, buffer);
    if (result == VK_SUCCESS)
    {
        dispatch_table.GetBufferMemoryRequirements(device, (*buffer), memory_requirements);

        (*memory_type_index) = FindMemoryTypeIndex(
            device, memory_requirements->memoryTypeBits, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT, state_table);

        VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
        alloc_info.pNext                = nullptr;
        alloc_info.allocationSize       = memory_requirements->size;
        alloc_info.memoryTypeIndex      = (*memory_type_index);

        result = dispatch_table.AllocateMemory(device, &alloc_info, nullptr, memory);
        if (result == VK_SUCCESS)
        {
            dispatch_table.BindBufferMemory(device, (*buffer), (*memory), 0);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to allocate staging buffer memory for resource memory snapshot");
            dispatch_table.DestroyBuffer(device, *buffer, nullptr);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create staging buffer for resource memory snapshot");
    }

    return result;
}

VkImageAspectFlags VulkanStateWriter::GetFormatAspectMask(VkFormat format)
{
    switch (format)
    {
        case VK_FORMAT_D16_UNORM_S8_UINT:
        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT;
        case VK_FORMAT_D16_UNORM:
        case VK_FORMAT_X8_D24_UNORM_PACK32:
        case VK_FORMAT_D32_SFLOAT:
            return VK_IMAGE_ASPECT_DEPTH_BIT;
        case VK_FORMAT_S8_UINT:
            return VK_IMAGE_ASPECT_STENCIL_BIT;
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            return VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT | VK_IMAGE_ASPECT_PLANE_2_BIT;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
            return VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT;
        default:
            return VK_IMAGE_ASPECT_COLOR_BIT;
    }
}

VkFormat VulkanStateWriter::GetImageAspectFormat(VkFormat format, VkImageAspectFlagBits aspect)
{
    switch (format)
    {
        // Per-aspect compatible formats as defined by the VkBufferImageCopy documentation.
        case VK_FORMAT_D16_UNORM_S8_UINT:
            if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
            {
                return VK_FORMAT_D16_UNORM;
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_STENCIL_BIT);
                return VK_FORMAT_S8_UINT;
            }
        case VK_FORMAT_D24_UNORM_S8_UINT:
            if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
            {
                // Effectively the same format (D24 texels packed into a 32-bit word).
                return VK_FORMAT_D24_UNORM_S8_UINT;
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_STENCIL_BIT);
                return VK_FORMAT_S8_UINT;
            }
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
            {
                return VK_FORMAT_D32_SFLOAT;
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_STENCIL_BIT);
                return VK_FORMAT_S8_UINT;
            }
        // Per-aspect/plane compatible formats as defined by the "Plane Format Compatibility Table" from the Vulkan
        // specification.
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            // All planes share the same format.
            return VK_FORMAT_R8_UNORM;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R8_UNORM;
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R8G8_UNORM;
            }
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
            // All planes share the same format.
            return VK_FORMAT_R10X6_UNORM_PACK16;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R10X6_UNORM_PACK16;
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R10X6G10X6_UNORM_2PACK16;
            }
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
            // All planes share the same format.
            return VK_FORMAT_R12X4_UNORM_PACK16;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R12X4_UNORM_PACK16;
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R12X4G12X4_UNORM_2PACK16;
            }
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            // All planes share the same format.
            return VK_FORMAT_R16_UNORM;
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
            if (aspect == VK_IMAGE_ASPECT_PLANE_0_BIT)
            {
                return VK_FORMAT_R16_UNORM;
            }
            else
            {
                assert(aspect == VK_IMAGE_ASPECT_PLANE_1_BIT);
                return VK_FORMAT_R16G16_UNORM;
            }
        default:
            assert((aspect == VK_IMAGE_ASPECT_COLOR_BIT) || (aspect == VK_IMAGE_ASPECT_DEPTH_BIT) ||
                   (aspect == VK_IMAGE_ASPECT_STENCIL_BIT));
            return format;
    }
}

void VulkanStateWriter::GetImageSizes(const ImageWrapper* image_wrapper,
                                      ImageSnapshotEntry* entry,
                                      const DeviceTable&  dispatch_table)
{
    assert((image_wrapper != nullptr) && (entry != nullptr));

    VkImageCreateInfo create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.imageType             = image_wrapper->image_type;
    create_info.format                = GetImageAspectFormat(image_wrapper->format, entry->aspect);
    create_info.extent                = image_wrapper->extent;
    create_info.mipLevels             = 1;
    create_info.arrayLayers           = image_wrapper->array_layers;
    create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling                = image_wrapper->tiling;
    create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;
    create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    VkImage              image = VK_NULL_HANDLE;
    VkMemoryRequirements memory_requirements;

    // Size of first level.
    VkResult result = dispatch_table.CreateImage(image_wrapper->bind_device, &create_info, nullptr, &image);
    if (result == VK_SUCCESS)
    {
        dispatch_table.GetImageMemoryRequirements(image_wrapper->bind_device, image, &memory_requirements);
        entry->resource_size = memory_requirements.size;
        entry->level_sizes.push_back(memory_requirements.size);
        dispatch_table.DestroyImage(image_wrapper->bind_device, image, nullptr);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to determine size of image for resource memory snapshot");
    }

    // Size of additional mip levels.
    for (uint32_t i = 1; i < image_wrapper->mip_levels; ++i)
    {
        create_info.extent.width  = std::max(1u, (create_info.extent.width >> i));
        create_info.extent.height = std::max(1u, (create_info.extent.height >> i));
        create_info.extent.depth  = std::max(1u, (create_info.extent.depth >> i));

        result = dispatch_table.CreateImage(image_wrapper->bind_device, &create_info, nullptr, &image);
        if (result == VK_SUCCESS)
        {
            dispatch_table.GetImageMemoryRequirements(image_wrapper->bind_device, image, &memory_requirements);
            entry->resource_size += memory_requirements.size;
            entry->level_sizes.push_back(memory_requirements.size);
            dispatch_table.DestroyImage(image_wrapper->bind_device, image, nullptr);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to determine size of image for resource memory snapshot");
        }
    }
}

void VulkanStateWriter::UpdateImageSnapshotSizes(VkDeviceSize       size,
                                                 bool               is_host_visible,
                                                 bool               use_staging_copy,
                                                 ImageSnapshotData* snapshot_data)
{
    assert(snapshot_data != nullptr);

    if (use_staging_copy)
    {
        if (!is_host_visible)
        {
            if (snapshot_data->max_device_local_image_size < size)
            {
                snapshot_data->max_device_local_image_size = size;
            }
        }

        if (snapshot_data->max_staging_copy_size < size)
        {
            snapshot_data->max_staging_copy_size = size;
        }
    }
}

void VulkanStateWriter::InsertImageSnapshotEntries(const ImageWrapper*        image_wrapper,
                                                   const DeviceMemoryWrapper* memory_wrapper,
                                                   bool                       is_host_visible,
                                                   bool                       use_staging_copy,
                                                   VkImageAspectFlags         aspect_mask,
                                                   ImageSnapshotList*         insert_list,
                                                   ImageSnapshotData*         snapshot_data,
                                                   const DeviceTable&         dispatch_table)

{
    assert((image_wrapper != nullptr) && (memory_wrapper != nullptr) && (insert_list != nullptr) &&
           (snapshot_data != nullptr));

    ImageSnapshotEntry entry;
    entry.image_wrapper   = image_wrapper;
    entry.memory_wrapper  = memory_wrapper;
    entry.is_host_visible = is_host_visible;

    if (aspect_mask == VK_IMAGE_ASPECT_COLOR_BIT)
    {
        entry.aspect = VK_IMAGE_ASPECT_COLOR_BIT;
        GetImageSizes(image_wrapper, &entry, dispatch_table);
        UpdateImageSnapshotSizes(entry.resource_size, is_host_visible, use_staging_copy, snapshot_data);
        insert_list->emplace_back(entry);
    }
    else
    {
        // Color is not expected to be combined with other aspects.
        assert((aspect_mask & VK_IMAGE_ASPECT_COLOR_BIT) != VK_IMAGE_ASPECT_COLOR_BIT);

        // Need to perform one copy per aspect.
        if ((aspect_mask & VK_IMAGE_ASPECT_DEPTH_BIT) == VK_IMAGE_ASPECT_DEPTH_BIT)
        {
            entry.aspect = VK_IMAGE_ASPECT_DEPTH_BIT;
            GetImageSizes(image_wrapper, &entry, dispatch_table);
            UpdateImageSnapshotSizes(entry.resource_size, is_host_visible, use_staging_copy, snapshot_data);
            insert_list->push_back(entry);
        }

        if ((aspect_mask & VK_IMAGE_ASPECT_STENCIL_BIT) == VK_IMAGE_ASPECT_STENCIL_BIT)
        {
            entry.aspect = VK_IMAGE_ASPECT_STENCIL_BIT;
            GetImageSizes(image_wrapper, &entry, dispatch_table);
            UpdateImageSnapshotSizes(entry.resource_size, is_host_visible, use_staging_copy, snapshot_data);
            insert_list->push_back(entry);
        }

        if ((aspect_mask & VK_IMAGE_ASPECT_PLANE_0_BIT) == VK_IMAGE_ASPECT_PLANE_0_BIT)
        {
            entry.aspect = VK_IMAGE_ASPECT_PLANE_0_BIT;
            GetImageSizes(image_wrapper, &entry, dispatch_table);
            UpdateImageSnapshotSizes(entry.resource_size, is_host_visible, use_staging_copy, snapshot_data);
            insert_list->push_back(entry);
        }

        if ((aspect_mask & VK_IMAGE_ASPECT_PLANE_1_BIT) == VK_IMAGE_ASPECT_PLANE_1_BIT)
        {
            entry.aspect = VK_IMAGE_ASPECT_PLANE_1_BIT;
            GetImageSizes(image_wrapper, &entry, dispatch_table);
            UpdateImageSnapshotSizes(entry.resource_size, is_host_visible, use_staging_copy, snapshot_data);
            insert_list->push_back(entry);
        }

        if ((aspect_mask & VK_IMAGE_ASPECT_PLANE_2_BIT) == VK_IMAGE_ASPECT_PLANE_2_BIT)
        {
            entry.aspect = VK_IMAGE_ASPECT_PLANE_2_BIT;
            GetImageSizes(image_wrapper, &entry, dispatch_table);
            UpdateImageSnapshotSizes(entry.resource_size, is_host_visible, use_staging_copy, snapshot_data);
            insert_list->push_back(entry);
        }
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
