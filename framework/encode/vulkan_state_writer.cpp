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

#include "encode/vulkan_state_writer.h"

#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_state_info.h"
#include "format/format_util.h"
#include "util/logging.h"

#include <algorithm>
#include <cassert>
#include <limits>
#include <unordered_map>

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

const uint32_t kDefaultQueueFamilyIndex = 0;

// Temporary resource IDs for state processing.
const format::HandleId kTempQueueId         = std::numeric_limits<format::HandleId>::max() - 1;
const format::HandleId kTempCommandPoolId   = std::numeric_limits<format::HandleId>::max() - 2;
const format::HandleId kTempCommandBufferId = std::numeric_limits<format::HandleId>::max() - 3;

static bool IsMemoryCoherent(VkMemoryPropertyFlags property_flags)
{
    return ((property_flags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) == VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
}

static bool IsMemoryReadable(VkMemoryPropertyFlags property_flags)
{
    return ((property_flags & (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT)) ==
            (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT));
}

static bool IsBufferReadable(VkMemoryPropertyFlags property_flags, const DeviceMemoryWrapper* memory_wrapper)
{
    // If a sub-range of host visible memory is mapped, a staging copy will be used to ensure that the entire allocation
    // is accessible for read.
    return (IsMemoryReadable(property_flags) && ((memory_wrapper->mapped_data == nullptr) ||
                                                 ((memory_wrapper->mapped_offset == 0) &&
                                                  ((memory_wrapper->mapped_size == memory_wrapper->allocation_size) ||
                                                   (memory_wrapper->mapped_size == VK_WHOLE_SIZE)))));
}

static bool IsImageReadable(VkMemoryPropertyFlags      property_flags,
                            const DeviceMemoryWrapper* memory_wrapper,
                            const ImageWrapper*        image_wrapper)
{
    // If a sub-range of host visible memory is mapped, a staging copy will be used to ensure that the entire allocation
    // is accessible for read.
    return (
        IsMemoryReadable(property_flags) && (image_wrapper->tiling == VK_IMAGE_TILING_LINEAR) &&
        ((memory_wrapper->mapped_data == nullptr) ||
         ((memory_wrapper->mapped_offset == 0) && ((memory_wrapper->mapped_size == memory_wrapper->allocation_size) ||
                                                   (memory_wrapper->mapped_size == VK_WHOLE_SIZE)))));
}

VulkanStateWriter::VulkanStateWriter(util::FileOutputStream* output_stream,
                                     util::Compressor*       compressor,
                                     format::ThreadId        thread_id) :
    output_stream_(output_stream),
    compressor_(compressor), thread_id_(thread_id), encoder_(&parameter_stream_)
{
    assert(output_stream != nullptr);
}

VulkanStateWriter::~VulkanStateWriter() {}

void VulkanStateWriter::WriteState(const VulkanStateTable& state_table, uint64_t frame_number)
{
    // clang-format off

    format::Marker marker;
    marker.header.size = sizeof(marker.marker_type) + sizeof(marker.frame_number);
    marker.header.type = format::kStateMarkerBlock;
    marker.marker_type = format::kBeginMarker;
    marker.frame_number = frame_number;
    output_stream_->Write(&marker, sizeof(marker));

    // Instance, device, and queue creation.
    StandardCreateWrite<InstanceWrapper>(state_table);
    WritePhysicalDeviceState(state_table);
    WriteDeviceState(state_table);
    StandardCreateWrite<QueueWrapper>(state_table);

    // Utility object creation.
    StandardCreateWrite<DebugReportCallbackEXTWrapper>(state_table);
    StandardCreateWrite<DebugUtilsMessengerEXTWrapper>(state_table);
    StandardCreateWrite<ValidationCacheEXTWrapper>(state_table);
    StandardCreateWrite<DeferredOperationKHRWrapper>(state_table);
    WritePrivateDataSlotState(state_table);

    // Synchronization primitive creation.
    WriteFenceState(state_table);
    WriteEventState(state_table);
    WriteSemaphoreState(state_table);

    // WSI object creation.
    StandardCreateWrite<DisplayKHRWrapper>(state_table);
    StandardCreateWrite<DisplayModeKHRWrapper>(state_table);
    WriteSurfaceKhrState(state_table);
    WriteSwapchainKhrState(state_table);

    // Resource creation.
    WriteBufferState(state_table);
    StandardCreateWrite<ImageWrapper>(state_table);
    WriteDeviceMemoryState(state_table);

    // Bind memory after buffer/image creation and memory allocation. The buffer/image needs to be created before memory
    // allocation for extensions like dedicated allocation that require a valid buffer/image handle at memory allocation.
    WriteResourceMemoryState(state_table);

    // Map memory after uploading resource data to buffers and images, which may require mapping resource memory ranges.
    WriteMappedMemoryState(state_table);

    WriteBufferViewState(state_table);
    WriteImageViewState(state_table);
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
    WriteAccelerationStructureKHRState(state_table);
    StandardCreateWrite<AccelerationStructureNVWrapper>(state_table);

    // Descriptor creation.
    StandardCreateWrite<DescriptorPoolWrapper>(state_table);
    StandardCreateWrite<DescriptorUpdateTemplateWrapper>(state_table);
    WriteDescriptorSetState(state_table);

    // Query object creation.
    WriteQueryPoolState(state_table);
    StandardCreateWrite<PerformanceConfigurationINTELWrapper>(state_table);

    StandardCreateWrite<MicromapEXTWrapper>(state_table);
    StandardCreateWrite<OpticalFlowSessionNVWrapper>(state_table);
    StandardCreateWrite<VideoSessionKHRWrapper>(state_table);
    StandardCreateWrite<VideoSessionParametersKHRWrapper>(state_table);

    // Command creation.
    StandardCreateWrite<CommandPoolWrapper>(state_table);
    WriteCommandBufferState(state_table);
    StandardCreateWrite<IndirectCommandsLayoutNVWrapper>(state_table);  // TODO: If we intend to support this, we need to reserve command space after creation.
    WriteTrimCommandPool(state_table);

    // Process swapchain image acquire.
    WriteSwapchainImageState(state_table);

    marker.marker_type = format::kEndMarker;
    output_stream_->Write(&marker, sizeof(marker));

    // clang-format on
}

void VulkanStateWriter::WritePhysicalDeviceState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;

    state_table.VisitWrappers([&](const PhysicalDeviceWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Filter duplicate calls to vkEnumeratePhysicalDevice for phsyical devices that were retrieved by the same API
        // call and reference the same parameter buffer.
        if (processed.find(wrapper->create_parameters.get()) == processed.end())
        {
            // Write command buffer creation call and add the parameter buffer to the processed set.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
            processed.insert(wrapper->create_parameters.get());
        }

        WritePhysicalDevicePropertiesMetaData(wrapper);

        // Write the call to retrieve queue family properties, if the call was previously made by the application.
        if (wrapper->queue_family_properties_call_id != format::ApiCallId::ApiCall_Unknown)
        {
            switch (wrapper->queue_family_properties_call_id)
            {
                case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties:
                    WriteGetPhysicalDeviceQueueFamilyProperties(wrapper->queue_family_properties_call_id,
                                                                wrapper->handle_id,
                                                                wrapper->queue_family_properties_count,
                                                                wrapper->queue_family_properties.get());
                    break;
                case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2:
                case format::ApiCallId::ApiCall_vkGetPhysicalDeviceQueueFamilyProperties2KHR:
                    WriteGetPhysicalDeviceQueueFamilyProperties(wrapper->queue_family_properties_call_id,
                                                                wrapper->handle_id,
                                                                wrapper->queue_family_properties_count,
                                                                wrapper->queue_family_properties2.get());
                    break;
                default:
                    GFXRECON_LOG_ERROR("Omitting queue family properties retrieval API call with unrecognized API call "
                                       "ID from state snapshot");
                    break;
            }
        }
    });
}

void VulkanStateWriter::WriteDeviceState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const DeviceWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write device creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Idle device to ensure all pending work is complete prior to writing state snapshot.
        VkResult result = wrapper->layer_table.DeviceWaitIdle(wrapper->handle);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_WARNING("Device wait idle failed during state snapshot generation");
        }
    });
}

void VulkanStateWriter::WriteCommandBufferState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*>      processed;
    std::vector<const CommandBufferWrapper*> primary;

    state_table.VisitWrappers([&](const CommandBufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Filter duplicate calls to vkAllocateCommandBuffers for command buffers that were allocated by the same API
        // call and reference the same parameter buffer.
        if (processed.find(wrapper->create_parameters.get()) == processed.end())
        {
            // Write command buffer creation call and add the parameter buffer to the processed set.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
            processed.insert(wrapper->create_parameters.get());
        }

        // Defer primary command buffer initialization until after secondary command buffers have been initialized.
        // This is to ensure that any secondary command buffers referenced by calls to vkCmdExecuteCommands, which may
        // have been recorded to a primary command buffer, are initialized before the call to vkCmdExecuteCommands is
        // replayed.
        if (wrapper->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY)
        {
            primary.push_back(wrapper);
        }
        else
        {
            WriteCommandBufferCommands(wrapper, state_table);
        }
    });

    // Initialize the primary command buffers now that secondary command buffer have been initialized.
    for (auto wrapper : primary)
    {
        WriteCommandBufferCommands(wrapper, state_table);
    }
}

void VulkanStateWriter::WriteTrimCommandPool(const VulkanStateTable& state_table)
{
    // vkTrimCommandPool shouldn't affect rendering. It's not necessary to replay. But it could help as debug info.
    state_table.VisitWrappers([&](const CommandPoolWrapper* wrapper) {
        assert(wrapper != nullptr);
        if (wrapper->trim_command_pool)
        {
            const DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeFlagsValue(0);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkTrimCommandPool, &parameter_stream_);
            parameter_stream_.Reset();
        }
    });
}

void VulkanStateWriter::WritePrivateDataSlotState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;

    state_table.VisitWrappers([&](const PrivateDataSlotWrapper* wrapper) {
        assert(wrapper != nullptr);
        if (processed.find(wrapper->create_parameters.get()) == processed.end())
        {
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
            processed.insert(wrapper->create_parameters.get());

            // vkSetPrivateData shouldn't affect rendering. It's not necessary to replay. But it could help as debug
            // info.
            if (wrapper->data != 0)
            {
                const DeviceWrapper* device_wrapper = wrapper->device;
                assert(device_wrapper != nullptr);

                encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                encoder_.EncodeEnumValue(wrapper->object_type);
                encoder_.EncodeUInt64Value(wrapper->object_handle);
                encoder_.EncodeHandleIdValue(wrapper->handle_id);
                encoder_.EncodeUInt64Value(wrapper->data);
                encoder_.EncodeEnumValue(VK_SUCCESS);

                WriteFunctionCall(format::ApiCallId::ApiCall_vkSetPrivateData, &parameter_stream_);
                parameter_stream_.Reset();
            }
        }
    });
}

void VulkanStateWriter::WriteFenceState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const FenceWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Check fence signaled state against create info signaled state.
        const DeviceWrapper* device_wrapper = wrapper->device;
        bool                 signaled       = wrapper->created_signaled;

        GetFenceStatus(device_wrapper, wrapper->handle, &signaled);

        if (signaled == wrapper->created_signaled)
        {
            // Signal states match, so original create parameters can be used.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
        }
        else
        {
            // Signal states are different, so write new creation parameters with the appropriate create info signal
            // flag.
            WriteCreateFence(device_wrapper->handle_id, wrapper->handle_id, signaled);
        }
    });
}

void VulkanStateWriter::WriteEventState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const EventWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write event creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Check and set signaled state if necessary.
        const DeviceWrapper* device_wrapper = wrapper->device;
        assert(device_wrapper != nullptr);

        VkResult result = device_wrapper->layer_table.GetEventStatus(device_wrapper->handle, wrapper->handle);
        if (result == VK_EVENT_SET)
        {
            // Write api call to signal the event.
            WriteSetEvent(device_wrapper->handle_id, wrapper->handle_id);
        }
    });
}

void VulkanStateWriter::WriteSemaphoreState(const VulkanStateTable& state_table)
{
    std::unordered_map<const DeviceWrapper*, std::vector<format::HandleId>> signaled;

    state_table.VisitWrappers([&](const SemaphoreWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write semaphore creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        if (wrapper->type == VK_SEMAPHORE_TYPE_TIMELINE)
        {
            const DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            // Query current semaphore value
            uint64_t          semaphore_value;
            format::ApiCallId signal_call_id;
            if (device_wrapper->physical_device->instance_api_version >= VK_MAKE_VERSION(1, 2, 0))
            {
                device_wrapper->layer_table.GetSemaphoreCounterValue(
                    device_wrapper->handle, wrapper->handle, &semaphore_value);
                signal_call_id = format::ApiCallId::ApiCall_vkSignalSemaphore;
            }
            else
            {
                device_wrapper->layer_table.GetSemaphoreCounterValueKHR(
                    device_wrapper->handle, wrapper->handle, &semaphore_value);
                signal_call_id = format::ApiCallId::ApiCall_vkSignalSemaphoreKHR;
            }

            // Write command to set semaphore value on replay
            if (semaphore_value != 0)
            {
                WriteSignalSemaphoreValue(
                    signal_call_id, device_wrapper->handle_id, wrapper->handle_id, semaphore_value);
            }
        }
        else if (wrapper->signaled)
        {
            signaled[wrapper->device].push_back(wrapper->handle_id);
        }
    });

    if (!signaled.empty())
    {
        for (const auto& entry : signaled)
        {
            // Any queue should be sufficient for signaling the semaphores; queue submit will not include any
            // command buffers.
            const QueueWrapper* queue_wrapper = entry.first->child_queues.front();
            WriteCommandExecution(queue_wrapper->handle_id,
                                  0,
                                  nullptr,
                                  static_cast<uint32_t>(entry.second.size()),
                                  entry.second.data(),
                                  0,
                                  nullptr,
                                  nullptr);
        }
    }
}

void VulkanStateWriter::WriteBufferViewState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const BufferViewWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Omit the current buffer view object if the buffer used to create it no longer exists.
        if (IsBufferValid(wrapper->buffer_id, state_table))
        {
            // Write buffer view creation call.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
        }
    });
}

void VulkanStateWriter::WriteImageViewState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const ImageViewWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Omit the current image view object if the image used to create it no longer exists.
        if (IsImageValid(wrapper->image_id, state_table))
        {
            // Write image view creation call.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
        }
    });
}

void VulkanStateWriter::WriteFramebufferState(const VulkanStateTable& state_table)
{
    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_render_passes;

    state_table.VisitWrappers([&](const FramebufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (IsFramebufferValid(wrapper, state_table))
        {
            auto render_pass_wrapper = state_table.GetRenderPassWrapper(wrapper->render_pass_id);
            if (render_pass_wrapper == nullptr)
            {
                // The object no longer exists, so a temporary object must be created.
                auto        create_parameters = wrapper->render_pass_create_parameters.get();
                const auto& inserted =
                    temp_render_passes.insert(std::make_pair(wrapper->render_pass_id, create_parameters));

                // Create a temporary object on first encounter.
                if (inserted.second)
                {
                    WriteFunctionCall(wrapper->render_pass_create_call_id, create_parameters);
                }
            }

            // Write framebuffer creation call.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
        }
    });

    // Temporary object destruction.
    for (const auto& entry : temp_render_passes)
    {
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyRenderPass, entry.first, entry.second);
    }
}

void VulkanStateWriter::WritePipelineLayoutState(const VulkanStateTable& state_table)
{
    // TODO: Temporary ds layouts are potentially created and destroyed by both WritePipelineLayoutState and
    // WritePipelineState; track temporary creation across calls to avoid duplicate temporary allocations.
    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_ds_layouts;

    // Perform temporary creations for dependencies that are no longer live, and create the pipeline layout.
    state_table.VisitWrappers([&](const PipelineLayoutWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Check descriptor set layout dependencies.
        auto deps = wrapper->layout_dependencies;
        for (const auto& entry : deps->layouts)
        {
            auto ds_layout_wrapper = state_table.GetDescriptorSetLayoutWrapper(entry.handle_id);
            if (ds_layout_wrapper == nullptr)
            {
                // The layout object has been destroyed, so a temporary object must be created.
                auto        create_parameters = entry.create_parameters.get();
                const auto& inserted = temp_ds_layouts.insert(std::make_pair(entry.handle_id, create_parameters));

                // Create a temporary object on first encounter.
                if (inserted.second)
                {
                    WriteFunctionCall(entry.create_call_id, create_parameters);
                }
            }
        }

        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });

    // Destroy any temporary resources that were created.
    for (const auto& entry : temp_ds_layouts)
    {
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyDescriptorSetLayout, entry.first, entry.second);
    }
}

void VulkanStateWriter::WritePipelineState(const VulkanStateTable& state_table)
{
    // Multiple pipelines can be created by a single API call, so using a set to filter duplicate pipeline creation and
    // a vector to store pipeline creation parameters in original order (needed to ensure derivative parent is created
    // before a derivative child).
    // TODO: Some of the pipelines created may have been destroyed, in which case, the current design can create more
    // pipelines than it should, resulting in object leaks or the overwriting of recycled handles.
    std::set<util::MemoryOutputStream*>    processed_graphics_pipelines;
    std::set<util::MemoryOutputStream*>    processed_compute_pipelines;
    std::set<util::MemoryOutputStream*>    processed_ray_tracing_pipelines_nv;
    std::set<util::MemoryOutputStream*>    processed_ray_tracing_pipelines_khr;
    std::vector<util::MemoryOutputStream*> graphics_pipelines;
    std::vector<util::MemoryOutputStream*> compute_pipelines;
    std::vector<util::MemoryOutputStream*> ray_tracing_pipelines_nv;
    std::vector<util::MemoryOutputStream*> ray_tracing_pipelines_khr;

    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_shaders;
    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_render_passes;
    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_layouts;
    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_ds_layouts;
    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_deferred_operations;

    // First pass over pipeline table to sort pipelines by type and determine which dependencies need to be created
    // temporarily.
    state_table.VisitWrappers([&](const PipelineWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Determine type of pipeline.
        if (wrapper->create_call_id == format::ApiCall_vkCreateGraphicsPipelines)
        {
            if (processed_graphics_pipelines.find(wrapper->create_parameters.get()) ==
                processed_graphics_pipelines.end())
            {
                graphics_pipelines.push_back(wrapper->create_parameters.get());
                processed_graphics_pipelines.insert(wrapper->create_parameters.get());
            }
            if (wrapper->render_pass_dependency.create_call_id != format::ApiCallId::ApiCall_Unknown)
            {
                // Check for graphics-specific creation dependencies that no longer exist.
                auto render_pass_wrapper = state_table.GetRenderPassWrapper(wrapper->render_pass_dependency.handle_id);
                if (render_pass_wrapper == nullptr)
                {
                    // The object no longer exists, so a temporary object must be created.
                    auto        create_parameters = wrapper->render_pass_dependency.create_parameters.get();
                    const auto& inserted          = temp_render_passes.insert(
                        std::make_pair(wrapper->render_pass_dependency.handle_id, create_parameters));

                    // Create a temporary object on first encounter.
                    if (inserted.second)
                    {
                        WriteFunctionCall(wrapper->render_pass_dependency.create_call_id, create_parameters);
                    }
                }
            }
        }
        else if (wrapper->create_call_id == format::ApiCall_vkCreateComputePipelines)
        {
            if (processed_compute_pipelines.find(wrapper->create_parameters.get()) == processed_compute_pipelines.end())
            {
                compute_pipelines.push_back(wrapper->create_parameters.get());
                processed_compute_pipelines.insert(wrapper->create_parameters.get());
            }
        }
        else if (wrapper->create_call_id == format::ApiCall_vkCreateRayTracingPipelinesNV)
        {
            if (processed_ray_tracing_pipelines_nv.find(wrapper->create_parameters.get()) ==
                processed_ray_tracing_pipelines_nv.end())
            {
                ray_tracing_pipelines_nv.push_back(wrapper->create_parameters.get());
                processed_ray_tracing_pipelines_nv.insert(wrapper->create_parameters.get());
            }
        }
        else if (wrapper->create_call_id == format::ApiCall_vkCreateRayTracingPipelinesKHR)
        {
            if (wrapper->device_id != format::kNullHandleId)
            {
                WriteSetRayTracingShaderGroupHandlesCommand(wrapper->device_id,
                                                            wrapper->handle_id,
                                                            wrapper->shader_group_handle_data.size(),
                                                            wrapper->shader_group_handle_data.data());
            }

            if (processed_ray_tracing_pipelines_khr.find(wrapper->create_parameters.get()) ==
                processed_ray_tracing_pipelines_khr.end())
            {
                ray_tracing_pipelines_khr.push_back(wrapper->create_parameters.get());
                processed_ray_tracing_pipelines_khr.insert(wrapper->create_parameters.get());
            }

            if (wrapper->deferred_operation.handle_id != format::kNullHandleId)
            {
                auto        create_parameters = wrapper->deferred_operation.create_parameters.get();
                const auto& inserted          = temp_deferred_operations.insert(
                    std::make_pair(wrapper->deferred_operation.handle_id, create_parameters));

                // Create a temporary object on first encounter.
                if (inserted.second)
                {
                    WriteFunctionCall(wrapper->deferred_operation.create_call_id, create_parameters);
                }
                // TODO: It shouldn't destroy VkDeferredOperation after vkCreateRayTracingPipelinesKHR because it will
                // run vkDeferredOperationJoinKHR and vkGetDeferredOperationResultKHR after
                // vkCreateRayTracingPipelinesKHR. It needs to find a good way to destroy this VkDeferredOperation.
            }
        }

        // Check for creation dependencies that no longer exist.
        for (const auto& entry : wrapper->shader_module_dependencies)
        {
            auto shader_wrapper = state_table.GetShaderModuleWrapper(entry.handle_id);
            if (shader_wrapper == nullptr)
            {
                // The object no longer exists, so a temporary object must be created.
                auto        create_parameters = entry.create_parameters.get();
                const auto& inserted          = temp_shaders.insert(std::make_pair(entry.handle_id, create_parameters));

                // Create a temporary object on first encounter.
                if (inserted.second)
                {
                    WriteFunctionCall(entry.create_call_id, create_parameters);
                }
            }
        }

        auto layout_wrapper = state_table.GetPipelineLayoutWrapper(wrapper->layout_dependency.handle_id);
        if (layout_wrapper == nullptr)
        {
            // The object no longer exists, so a temporary object must be created.
            auto        create_parameters = wrapper->layout_dependency.create_parameters.get();
            const auto& inserted =
                temp_layouts.insert(std::make_pair(wrapper->layout_dependency.handle_id, create_parameters));

            // Create a temporary object on first encounter.
            if (inserted.second)
            {
                // Check descriptor set layout dependencies.
                auto deps = wrapper->layout_dependencies;
                for (const auto& entry : deps->layouts)
                {
                    auto ds_layout_wrapper = state_table.GetDescriptorSetLayoutWrapper(entry.handle_id);
                    if (ds_layout_wrapper == nullptr)
                    {
                        // The object no longer exists, so a temporary object must be created.
                        auto        dep_create_parameters = entry.create_parameters.get();
                        const auto& dep_inserted =
                            temp_ds_layouts.insert(std::make_pair(entry.handle_id, dep_create_parameters));

                        // Create a temporary object on first encounter.
                        if (dep_inserted.second)
                        {
                            WriteFunctionCall(entry.create_call_id, dep_create_parameters);
                        }
                    }
                }

                WriteFunctionCall(wrapper->layout_dependency.create_call_id, create_parameters);
            }
        }
    });

    // Pipeline object creation.
    for (const auto& entry : graphics_pipelines)
    {
        WriteFunctionCall(format::ApiCall_vkCreateGraphicsPipelines, entry);
    }

    for (const auto& entry : compute_pipelines)
    {
        WriteFunctionCall(format::ApiCall_vkCreateComputePipelines, entry);
    }

    for (const auto& entry : ray_tracing_pipelines_nv)
    {
        WriteFunctionCall(format::ApiCall_vkCreateRayTracingPipelinesNV, entry);
    }

    for (const auto& entry : ray_tracing_pipelines_khr)
    {
        WriteFunctionCall(format::ApiCall_vkCreateRayTracingPipelinesKHR, entry);
    }

    // Temporary object destruction.
    for (const auto& entry : temp_shaders)
    {
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyShaderModule, entry.first, entry.second);
    }

    for (const auto& entry : temp_render_passes)
    {
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyRenderPass, entry.first, entry.second);
    }

    for (const auto& entry : temp_ds_layouts)
    {
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyDescriptorSetLayout, entry.first, entry.second);
    }

    for (const auto& entry : temp_layouts)
    {
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyPipelineLayout, entry.first, entry.second);
    }
}

void VulkanStateWriter::WriteDescriptorSetState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;

    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_ds_layouts;

    // First pass over descriptor set table to determine which dependencies need to be created temporarily.
    state_table.VisitWrappers([&](const DescriptorSetWrapper* wrapper) {
        assert(wrapper != nullptr);

        auto ds_layout_wrapper = state_table.GetDescriptorSetLayoutWrapper(wrapper->set_layout_dependency.handle_id);
        if (ds_layout_wrapper == nullptr)
        {
            // The object no longer exists, so a temporary object must be created.
            auto        dep_create_parameters = wrapper->set_layout_dependency.create_parameters.get();
            const auto& dep_inserted =
                temp_ds_layouts.insert(std::make_pair(wrapper->set_layout_dependency.handle_id, dep_create_parameters));

            // Create a temporary object on first encounter.
            if (dep_inserted.second)
            {
                WriteFunctionCall(wrapper->set_layout_dependency.create_call_id, dep_create_parameters);
            }
        }
    });

    state_table.VisitWrappers([&](const DescriptorSetWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Filter duplicate calls to vkAllocateDescriptorSets for descriptor sets that were allocated by the same API
        // call and reference the same parameter buffer.
        if (processed.find(wrapper->create_parameters.get()) == processed.end())
        {
            // Write descriptor set creation call and add the parameter buffer to the processed set.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
            processed.insert(wrapper->create_parameters.get());
        }

        // Write descriptor updates. This value will be processed by an EncodeStruct routine that expects all struct
        // member handles to be wrapped handles (either need a const_cast or copy to temporary wrapper here).

        VkWriteDescriptorSet write = { VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET };
        write.dstSet               = wrapper->handle;

        for (const auto& binding_entry : wrapper->bindings)
        {
            const DescriptorInfo* binding = &binding_entry.second;
            bool                  active  = false;

            write.pNext      = binding->write_pnext;
            write.dstBinding = binding_entry.first;

            for (uint32_t i = 0; i < binding->count; ++i)
            {
                VkDescriptorType descriptor_type;
                bool             write_descriptor = CheckDescriptorStatus(binding, i, state_table, &descriptor_type);

                if (active != write_descriptor)
                {
                    if (!active)
                    {
                        // Start of an active descriptor write range.
                        active                = true;
                        write.dstArrayElement = i;
                        write.descriptorType  = descriptor_type;
                    }
                    else
                    {
                        // End of an active descriptor write range.
                        active                = false;
                        write.descriptorCount = i - write.dstArrayElement;
                        WriteDescriptorUpdateCommand(wrapper->device->handle_id, binding, &write);
                    }
                }
                else if (active && (descriptor_type != write.descriptorType))
                {
                    // Mutable descriptor type change within an active write range
                    // End current range
                    write.descriptorCount = i - write.dstArrayElement;
                    WriteDescriptorUpdateCommand(wrapper->device->handle_id, binding, &write);
                    // Start new range
                    write.descriptorType  = descriptor_type;
                    write.dstArrayElement = i;
                }
            }

            // Process final range, when last item in array contained an active write.
            if (active)
            {
                write.descriptorCount = binding->count - write.dstArrayElement;
                WriteDescriptorUpdateCommand(wrapper->device->handle_id, binding, &write);
            }
        }
    });

    // Temporary object destruction.
    for (const auto& entry : temp_ds_layouts)
    {
        DestroyTemporaryDeviceObject(format::ApiCall_vkDestroyDescriptorSetLayout, entry.first, entry.second);
    }
}

void VulkanStateWriter::WriteQueryPoolState(const VulkanStateTable& state_table)
{
    std::unordered_map<const DeviceWrapper*, std::vector<const QueryPoolWrapper*>> device_query_pools;
    std::unordered_map<const DeviceWrapper*, QueryActivationQueueFamilyTable>      device_queries;

    state_table.VisitWrappers([&](const QueryPoolWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write query pool creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Group query pools that need to be reset by device.
        device_query_pools[wrapper->device].push_back(wrapper);

        // Sort pending queries by device and queue family index.
        for (uint32_t i = 0; i < wrapper->pending_queries.size(); ++i)
        {
            const auto& query_entry = wrapper->pending_queries[i];

            if (query_entry.active)
            {
                QueryActivationData activation_data;
                activation_data.pool_id    = wrapper->handle_id;
                activation_data.type       = wrapper->query_type;
                activation_data.flags      = query_entry.flags;
                activation_data.index      = i;
                activation_data.type_index = query_entry.query_type_index;

                auto& queue_family_table = device_queries[wrapper->device];
                queue_family_table[query_entry.queue_family_index].emplace_back(activation_data);
            }
        }
    });

    // Write query pool reset to state snapshot.
    for (const auto& device_entry : device_query_pools)
    {
        WriteQueryPoolReset(device_entry.first->handle_id, device_entry.second);
    }

    // Write query activation to state snapshot.  This will simply begin/end each query so that future calls to
    // vkGetQueryPoolResults will succeed, but will not produce valid query results.
    for (const auto& device_entry : device_queries)
    {
        for (const auto& queue_family_entry : device_entry.second)
        {
            WriteQueryActivation(device_entry.first->handle_id, queue_family_entry.first, queue_family_entry.second);
        }
    }
}

void VulkanStateWriter::WriteSurfaceKhrState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const SurfaceKHRWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write surface creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        for (const auto& entry : wrapper->surface_support)
        {
            for (const auto& queue_entry : entry.second)
            {
                WriteGetPhysicalDeviceSurfaceSupport(
                    entry.first, queue_entry.first, wrapper->handle_id, queue_entry.second);
            }
        }

        for (const auto& entry : wrapper->surface_capabilities)
        {
            WriteResizeWindowCmd(wrapper->handle_id,
                                 entry.second.surface_capabilities.surfaceCapabilities.currentExtent.width,
                                 entry.second.surface_capabilities.surfaceCapabilities.currentExtent.height);
            WriteGetPhysicalDeviceSurfaceCapabilities(entry.first, wrapper->handle_id, entry.second, state_table);
        }

        for (const auto& entry : wrapper->surface_formats)
        {
            WriteGetPhysicalDeviceSurfaceFormats(entry.first, wrapper->handle_id, entry.second, state_table);
        }

        for (const auto& entry : wrapper->surface_present_modes)
        {
            WriteGetPhysicalDeviceSurfacePresentModes(entry.first, wrapper->handle_id, entry.second, state_table);
        }

        for (const auto& entry : wrapper->group_surface_present_modes)
        {
            WriteGetDeviceGroupSurfacePresentModes(entry.first, wrapper->handle_id, entry.second, state_table);
        }
    });
}

void VulkanStateWriter::WriteSwapchainKhrState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const SwapchainKHRWrapper* wrapper) {
        assert(wrapper != nullptr);

        const SurfaceKHRWrapper* surface_wrapper = wrapper->surface;
        assert(surface_wrapper != nullptr);

        WriteResizeWindowCmd2(
            surface_wrapper->handle_id, wrapper->extent.width, wrapper->extent.height, wrapper->pre_transform);

        // Write swapchain creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Write the query for swapchain image count.
        uint32_t image_count = static_cast<uint32_t>(wrapper->child_images.size());

        if (image_count > 0)
        {
            const DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeUInt32Ptr(&image_count, false);
            encoder_.EncodeHandleIdArray(nullptr, 0, false);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR, &parameter_stream_);
            parameter_stream_.Reset();
        }

        if (wrapper->acquire_full_screen_exclusive_mode)
        {
            const DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT, &parameter_stream_);
            parameter_stream_.Reset();
        }

        if (wrapper->release_full_screen_exclusive_mode)
        {
            const DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT, &parameter_stream_);
            parameter_stream_.Reset();
        }

        if (wrapper->using_local_dimming_AMD)
        {
            const DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeVkBool32Value(wrapper->local_dimming_enable_AMD);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkSetLocalDimmingAMD, &parameter_stream_);
            parameter_stream_.Reset();
        }
    });
}

void VulkanStateWriter::WriteDeviceMemoryState(const VulkanStateTable& state_table)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    std::unordered_map<AHardwareBuffer*, const DeviceMemoryWrapper*> hardware_buffers;

    // Before writing the device memory allocation calls, generate a list of external memory objects to create.
    state_table.VisitWrappers([&](const DeviceMemoryWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->hardware_buffer != nullptr)
        {
            hardware_buffers.insert(std::make_pair(wrapper->hardware_buffer, wrapper));
        }
    });

    // Write AHB creation commands.
    for (auto hardware_buffer : hardware_buffers)
    {
        const DeviceMemoryWrapper* wrapper = hardware_buffer.second;
        ProcessHardwareBuffer(wrapper->hardware_buffer_memory_id, wrapper->hardware_buffer, wrapper->allocation_size);
    }
#endif

    // Write device memory allocation calls.
    state_table.VisitWrappers([&](const DeviceMemoryWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->device_id != format::kNullHandleId)
        {
            WriteSetOpaqueAddressCommand(wrapper->device_id, wrapper->handle_id, wrapper->address);
        }

        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

void VulkanStateWriter::WriteBufferState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const BufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        if ((wrapper->device_id != format::kNullHandleId) && (wrapper->address != 0))
        {
            // If the buffer has a device address, write the 'set opaque address' command before writing the API call to
            // create the buffer.  The address will need to be passed to vkCreateBuffer through the pCreateInfo pNext
            // list.
            WriteSetOpaqueAddressCommand(wrapper->device_id, wrapper->handle_id, wrapper->address);
        }

        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

void VulkanStateWriter::WriteAccelerationStructureKHRState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const AccelerationStructureKHRWrapper* wrapper) {
        assert(wrapper != nullptr);

        if ((wrapper->device_id != format::kNullHandleId) && (wrapper->address != 0))
        {
            // If the acceleration struct has a device address, write the 'set opaque address' command before writing
            // the API call to create the acceleration struct.  The address will need to be passed to
            // vkCreateAccelerationStructKHR through the VkAccelerationStructureCreateInfoKHR::deviceAddress.
            WriteSetOpaqueAddressCommand(wrapper->device_id, wrapper->handle_id, wrapper->address);
        }

        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

void VulkanStateWriter::ProcessHardwareBuffer(format::HandleId memory_id,
                                              AHardwareBuffer* hardware_buffer,
                                              VkDeviceSize     allocation_size)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    void* data   = nullptr;
    int   result = -1;

    std::vector<format::HardwareBufferPlaneInfo> plane_info;

    // The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, this
    // could be turned into a run-time check dependent on dlsym returning a valid pointer for
    // AHardwareBuffer_lockPlanes.
#if __ANDROID_API__ >= 29
    AHardwareBuffer_Planes ahb_planes;
    result =
        AHardwareBuffer_lockPlanes(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &ahb_planes);
    if (result == 0)
    {
        data = ahb_planes.planes[0].data;

        for (uint32_t i = 0; i < ahb_planes.planeCount; ++i)
        {
            format::HardwareBufferPlaneInfo ahb_plane_info;
            ahb_plane_info.offset =
                reinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - reinterpret_cast<uint8_t*>(data);
            ahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;
            ahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;
            plane_info.emplace_back(std::move(ahb_plane_info));
        }
    }
    else
    {
        GFXRECON_LOG_WARNING("AHardwareBuffer_lockPlanes failed: AHardwareBuffer_lock will be used instead");
    }
#endif

    if (result != 0)
    {
        result = AHardwareBuffer_lock(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &data);
    }

    if (result == 0)
    {
        WriteCreateHardwareBufferCmd(memory_id, hardware_buffer, plane_info);

        if (data != nullptr)
        {
            WriteFillMemoryCmd(memory_id, 0, allocation_size, data);
        }
        else
        {
            GFXRECON_LOG_WARNING("AHardwareBuffer_lock returned nullptr for data pointer");
        }

        result = AHardwareBuffer_unlock(hardware_buffer, nullptr);
        if (result != 0)
        {
            GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed");
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("AHardwareBuffer_lock failed: hardware buffer data will be omitted from the capture file");
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(memory_id);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanStateWriter::ProcessBufferMemory(const DeviceWrapper*                   device_wrapper,
                                            const std::vector<BufferSnapshotInfo>& buffer_snapshot_info,
                                            uint32_t                               queue_family_index,
                                            VkQueue                                queue,
                                            VkCommandBuffer                        command_buffer,
                                            VkBuffer                               staging_buffer,
                                            VkDeviceMemory                         staging_memory,
                                            bool                                   is_staging_memory_coherent)
{
    assert(device_wrapper != nullptr);

    const DeviceTable* device_table = &device_wrapper->layer_table;

    for (const auto& snapshot_entry : buffer_snapshot_info)
    {
        const BufferWrapper*       buffer_wrapper = snapshot_entry.buffer_wrapper;
        const DeviceMemoryWrapper* memory_wrapper = snapshot_entry.memory_wrapper;
        const uint8_t*             bytes          = nullptr;

        assert((buffer_wrapper != nullptr) && (memory_wrapper != nullptr));

        if (snapshot_entry.need_staging_copy)
        {
            VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
            begin_info.pNext                    = nullptr;
            begin_info.flags                    = 0;
            begin_info.pInheritanceInfo         = nullptr;

            VkResult result = device_table->BeginCommandBuffer(command_buffer, &begin_info);

            if (result == VK_SUCCESS)
            {
                VkBufferCopy copy_region;
                copy_region.srcOffset = 0;
                copy_region.dstOffset = 0;
                copy_region.size      = buffer_wrapper->created_size;

                device_table->CmdCopyBuffer(command_buffer, buffer_wrapper->handle, staging_buffer, 1, &copy_region);
                device_table->EndCommandBuffer(command_buffer);

                result = SubmitCommandBuffer(queue, command_buffer, device_table);
                if (result == VK_SUCCESS)
                {
                    void* data = nullptr;
                    result     = device_table->MapMemory(
                        device_wrapper->handle, staging_memory, 0, buffer_wrapper->created_size, 0, &data);
                    if (result == VK_SUCCESS)
                    {
                        bytes = reinterpret_cast<uint8_t*>(data);

                        if (!is_staging_memory_coherent)
                        {
                            InvalidateMappedMemoryRange(
                                device_wrapper, staging_memory, 0, buffer_wrapper->created_size);
                        }
                    }
                }
            }
        }
        else
        {
            assert((memory_wrapper->mapped_data == nullptr) || (memory_wrapper->mapped_offset == 0));

            VkResult result = VK_SUCCESS;

            if (memory_wrapper->mapped_data == nullptr)
            {
                void* data = nullptr;
                result     = device_table->MapMemory(device_wrapper->handle,
                                                 memory_wrapper->handle,
                                                 buffer_wrapper->bind_offset,
                                                 buffer_wrapper->created_size,
                                                 0,
                                                 &data);
                if (result == VK_SUCCESS)
                {
                    bytes = reinterpret_cast<uint8_t*>(data);
                }
            }
            else
            {
                bytes = reinterpret_cast<const uint8_t*>(memory_wrapper->mapped_data) + buffer_wrapper->bind_offset;
            }

            if ((result == VK_SUCCESS) && !IsMemoryCoherent(snapshot_entry.memory_properties))
            {
                InvalidateMappedMemoryRange(
                    device_wrapper, memory_wrapper->handle, buffer_wrapper->bind_offset, buffer_wrapper->created_size);
            }
        }

        if (bytes != nullptr)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, buffer_wrapper->created_size);

            size_t                          data_size = static_cast<size_t>(buffer_wrapper->created_size);
            format::InitBufferCommandHeader upload_cmd;

            upload_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            upload_cmd.meta_header.meta_data_id =
                format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kInitBufferCommand);
            upload_cmd.thread_id = thread_id_;
            upload_cmd.device_id = device_wrapper->handle_id;
            upload_cmd.buffer_id = buffer_wrapper->handle_id;
            upload_cmd.data_size = data_size;

            if (compressor_ != nullptr)
            {
                size_t compressed_size = compressor_->Compress(data_size, bytes, &compressed_parameter_buffer_, 0);

                if ((compressed_size > 0) && (compressed_size < data_size))
                {
                    upload_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                    bytes     = compressed_parameter_buffer_.data();
                    data_size = compressed_size;
                }
            }

            // Calculate size of packet with compressed or uncompressed data size.
            upload_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(upload_cmd) + data_size;

            output_stream_->Write(&upload_cmd, sizeof(upload_cmd));
            output_stream_->Write(bytes, data_size);

            if (snapshot_entry.need_staging_copy)
            {
                device_table->UnmapMemory(device_wrapper->handle, staging_memory);
            }
            else
            {
                if (memory_wrapper->mapped_data == nullptr)
                {
                    device_table->UnmapMemory(device_wrapper->handle, memory_wrapper->handle);
                }
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Trimming state snapshot failed to retrieve memory content for buffer %" PRIu64,
                               buffer_wrapper->handle_id);
        }
    }
}

void VulkanStateWriter::ProcessImageMemory(const DeviceWrapper*                  device_wrapper,
                                           const std::vector<ImageSnapshotInfo>& image_snapshot_info,
                                           uint32_t                              queue_family_index,
                                           VkQueue                               queue,
                                           VkCommandBuffer                       command_buffer,
                                           VkBuffer                              staging_buffer,
                                           VkDeviceMemory                        staging_memory,
                                           bool                                  is_staging_memory_coherent,
                                           const VulkanStateTable&               state_table)
{
    assert(device_wrapper != nullptr);

    const DeviceTable* device_table = &device_wrapper->layer_table;

    for (const auto& snapshot_entry : image_snapshot_info)
    {
        const ImageWrapper*        image_wrapper  = snapshot_entry.image_wrapper;
        const DeviceMemoryWrapper* memory_wrapper = snapshot_entry.memory_wrapper;
        const uint8_t*             bytes          = nullptr;

        assert((image_wrapper != nullptr) && ((image_wrapper->is_swapchain_image && memory_wrapper == nullptr) ||
                                              (!image_wrapper->is_swapchain_image && memory_wrapper != nullptr)));

        if (snapshot_entry.need_staging_copy)
        {
            VkImage        resolve_image  = VK_NULL_HANDLE;
            VkDeviceMemory resolve_memory = VK_NULL_HANDLE;
            VkResult       result         = VK_SUCCESS;

            if (image_wrapper->samples != VK_SAMPLE_COUNT_1_BIT)
            {
                if (snapshot_entry.aspect == VK_IMAGE_ASPECT_COLOR_BIT)
                {
                    result = ResolveImage(device_wrapper,
                                          image_wrapper,
                                          queue,
                                          command_buffer,
                                          &resolve_image,
                                          &resolve_memory,
                                          state_table);
                }
                else
                {
                    // Omit the image data for depth-stencil images with sample count greater than 1.
                    result = VK_ERROR_FORMAT_NOT_SUPPORTED;
                }
            }

            if (result == VK_SUCCESS)
            {
                VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
                begin_info.pNext                    = nullptr;
                begin_info.flags                    = 0;
                begin_info.pInheritanceInfo         = nullptr;

                result = device_table->BeginCommandBuffer(command_buffer, &begin_info);

                if (result == VK_SUCCESS)
                {
                    VkImage              copy_image = image_wrapper->handle;
                    VkImageMemoryBarrier memory_barrier;
                    VkImageAspectFlags   transition_aspect = snapshot_entry.aspect;

                    if ((transition_aspect == VK_IMAGE_ASPECT_DEPTH_BIT) ||
                        (transition_aspect == VK_IMAGE_ASPECT_STENCIL_BIT))
                    {
                        // Depth and stencil aspects need to be transitioned together, so get full aspect
                        // mask for image.
                        transition_aspect = GetFormatAspectMask(image_wrapper->format);
                    }

                    if (image_wrapper->samples != VK_SAMPLE_COUNT_1_BIT)
                    {
                        copy_image = resolve_image;
                    }
                    else if (image_wrapper->current_layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL)
                    {
                        // Transition image layout to transfer source optimal.
                        memory_barrier.sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                        memory_barrier.pNext                           = nullptr;
                        memory_barrier.srcAccessMask                   = 0;
                        memory_barrier.dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
                        memory_barrier.oldLayout                       = image_wrapper->current_layout;
                        memory_barrier.newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                        memory_barrier.srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                        memory_barrier.dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                        memory_barrier.image                           = image_wrapper->handle;
                        memory_barrier.subresourceRange.aspectMask     = transition_aspect;
                        memory_barrier.subresourceRange.baseMipLevel   = 0;
                        memory_barrier.subresourceRange.levelCount     = image_wrapper->mip_levels;
                        memory_barrier.subresourceRange.baseArrayLayer = 0;
                        memory_barrier.subresourceRange.layerCount     = image_wrapper->array_layers;

                        device_table->CmdPipelineBarrier(command_buffer,
                                                         VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                         VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                         0,
                                                         0,
                                                         nullptr,
                                                         0,
                                                         nullptr,
                                                         1,
                                                         &memory_barrier);
                    }

                    // Create one copy region per mip-level.
                    std::vector<VkBufferImageCopy> copy_regions;

                    VkBufferImageCopy copy_region;
                    copy_region.bufferRowLength                 = 0; // Request tightly packed data.
                    copy_region.bufferImageHeight               = 0; // Request tightly packed data.
                    copy_region.bufferOffset                    = 0;
                    copy_region.imageOffset.x                   = 0;
                    copy_region.imageOffset.y                   = 0;
                    copy_region.imageOffset.z                   = 0;
                    copy_region.imageSubresource.aspectMask     = snapshot_entry.aspect;
                    copy_region.imageSubresource.baseArrayLayer = 0;
                    copy_region.imageSubresource.layerCount     = image_wrapper->array_layers;

                    for (uint32_t i = 0; i < image_wrapper->mip_levels; ++i)
                    {
                        copy_region.imageSubresource.mipLevel = i;
                        copy_region.imageExtent.width         = std::max(1u, (image_wrapper->extent.width >> i));
                        copy_region.imageExtent.height        = std::max(1u, (image_wrapper->extent.height >> i));
                        copy_region.imageExtent.depth         = std::max(1u, (image_wrapper->extent.depth >> i));

                        copy_regions.push_back(copy_region);
                        copy_region.bufferOffset += snapshot_entry.level_sizes[i];
                    }

                    device_table->CmdCopyImageToBuffer(command_buffer,
                                                       copy_image,
                                                       VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                       staging_buffer,
                                                       static_cast<uint32_t>(copy_regions.size()),
                                                       copy_regions.data());

                    if ((image_wrapper->samples == VK_SAMPLE_COUNT_1_BIT) &&
                        (image_wrapper->current_layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                        (image_wrapper->current_layout != VK_IMAGE_LAYOUT_PREINITIALIZED) &&
                        (image_wrapper->current_layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL))
                    {
                        memory_barrier.srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                        memory_barrier.dstAccessMask = 0;
                        memory_barrier.oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                        memory_barrier.newLayout     = image_wrapper->current_layout;

                        device_table->CmdPipelineBarrier(command_buffer,
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

                    device_table->EndCommandBuffer(command_buffer);

                    result = SubmitCommandBuffer(queue, command_buffer, device_table);

                    if (result == VK_SUCCESS)
                    {
                        void* data = nullptr;
                        result     = device_table->MapMemory(
                            device_wrapper->handle, staging_memory, 0, snapshot_entry.resource_size, 0, &data);

                        if (result == VK_SUCCESS)
                        {
                            bytes = reinterpret_cast<uint8_t*>(data);

                            if (!is_staging_memory_coherent)
                            {
                                InvalidateMappedMemoryRange(
                                    device_wrapper, staging_memory, 0, snapshot_entry.resource_size);
                            }
                        }
                    }
                }

                if (image_wrapper->samples != VK_SAMPLE_COUNT_1_BIT)
                {
                    device_table->DestroyImage(device_wrapper->handle, resolve_image, nullptr);
                    device_table->FreeMemory(device_wrapper->handle, resolve_memory, nullptr);
                }
            }
        }
        else if (!image_wrapper->is_swapchain_image)
        {
            assert((memory_wrapper != nullptr) &&
                   ((memory_wrapper->mapped_data == nullptr) || (memory_wrapper->mapped_offset == 0)));

            VkResult result = VK_SUCCESS;

            if (memory_wrapper->mapped_data == nullptr)
            {
                void* data = nullptr;
                result     = device_table->MapMemory(device_wrapper->handle,
                                                 memory_wrapper->handle,
                                                 image_wrapper->bind_offset,
                                                 snapshot_entry.resource_size,
                                                 0,
                                                 &data);
                if (result == VK_SUCCESS)
                {
                    bytes = reinterpret_cast<uint8_t*>(data);
                }
            }
            else
            {
                bytes = reinterpret_cast<const uint8_t*>(memory_wrapper->mapped_data) + image_wrapper->bind_offset;
            }

            if ((result == VK_SUCCESS) && !IsMemoryCoherent(snapshot_entry.memory_properties))
            {
                InvalidateMappedMemoryRange(
                    device_wrapper, memory_wrapper->handle, image_wrapper->bind_offset, snapshot_entry.resource_size);
            }
        }

        if (!image_wrapper->is_swapchain_image)
        {
            format::InitImageCommandHeader upload_cmd;

            // Packet size without the resource data.
            upload_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(upload_cmd);
            upload_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            upload_cmd.meta_header.meta_data_id =
                format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kInitImageCommand);
            upload_cmd.thread_id = thread_id_;
            upload_cmd.device_id = device_wrapper->handle_id;
            upload_cmd.image_id  = image_wrapper->handle_id;
            upload_cmd.aspect    = snapshot_entry.aspect;
            upload_cmd.layout    = image_wrapper->current_layout;

            if (bytes != nullptr)
            {
                GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, snapshot_entry.resource_size);

                size_t data_size = static_cast<size_t>(snapshot_entry.resource_size);

                // Store uncompressed data size in packet.
                upload_cmd.data_size   = data_size;
                upload_cmd.level_count = image_wrapper->mip_levels;

                if (compressor_ != nullptr)
                {
                    size_t compressed_size = compressor_->Compress(data_size, bytes, &compressed_parameter_buffer_, 0);

                    if ((compressed_size > 0) && (compressed_size < data_size))
                    {
                        upload_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                        bytes     = compressed_parameter_buffer_.data();
                        data_size = compressed_size;
                    }
                }

                // Calculate size of packet with compressed or uncompressed data size.
                assert(!snapshot_entry.level_sizes.empty() &&
                       (snapshot_entry.level_sizes.size() == upload_cmd.level_count));
                size_t levels_size = snapshot_entry.level_sizes.size() * sizeof(snapshot_entry.level_sizes[0]);

                upload_cmd.meta_header.block_header.size += levels_size + data_size;

                output_stream_->Write(&upload_cmd, sizeof(upload_cmd));
                output_stream_->Write(snapshot_entry.level_sizes.data(), levels_size);
                output_stream_->Write(bytes, data_size);

                if (snapshot_entry.need_staging_copy)
                {
                    device_table->UnmapMemory(device_wrapper->handle, staging_memory);
                }
                else
                {
                    if (memory_wrapper->mapped_data == nullptr)
                    {
                        device_table->UnmapMemory(device_wrapper->handle, memory_wrapper->handle);
                    }
                }
            }
            else
            {
                // Write a packet without resource data; replay must still perform a layout transition at image
                // initialization.
                upload_cmd.data_size   = 0;
                upload_cmd.level_count = 0;

                output_stream_->Write(&upload_cmd, sizeof(upload_cmd));
            }
        }
    }
}

void VulkanStateWriter::WriteBufferMemoryState(const VulkanStateTable& state_table,
                                               DeviceResourceTables*   resources,
                                               VkDeviceSize*           max_resource_size,
                                               VkDeviceSize*           max_staging_copy_size)
{
    assert((resources != nullptr) && (max_resource_size != nullptr) && (max_staging_copy_size != nullptr));

    state_table.VisitWrappers([&](const BufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Perform memory binding.
        const DeviceMemoryWrapper* memory_wrapper = state_table.GetDeviceMemoryWrapper(wrapper->bind_memory_id);

        if (memory_wrapper != nullptr)
        {
            const DeviceWrapper* device_wrapper = wrapper->bind_device;
            const DeviceTable*   device_table   = &device_wrapper->layer_table;

            assert((device_wrapper != nullptr) && (device_table != nullptr));

            // Write memory requirements query before bind command.
            VkMemoryRequirements memory_requirements;

            device_table->GetBufferMemoryRequirements(device_wrapper->handle, wrapper->handle, &memory_requirements);

            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            EncodeStructPtr(&encoder_, &memory_requirements);

            WriteFunctionCall(format::ApiCall_vkGetBufferMemoryRequirements, &parameter_stream_);
            parameter_stream_.Reset();

            // Write memory bind command.
            if (wrapper->bind_pnext == nullptr)
            {
                encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                encoder_.EncodeHandleIdValue(wrapper->handle_id);
                encoder_.EncodeHandleIdValue(memory_wrapper->handle_id);
                encoder_.EncodeVkDeviceSizeValue(wrapper->bind_offset);
                encoder_.EncodeEnumValue(VK_SUCCESS);

                WriteFunctionCall(format::ApiCall_vkBindBufferMemory, &parameter_stream_);
            }
            else
            {
                encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                encoder_.EncodeUInt32Value(1);

                VkBindBufferMemoryInfo info = {};
                info.sType                  = VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO;
                info.pNext                  = wrapper->bind_pnext;
                info.buffer                 = wrapper->handle;
                info.memory                 = memory_wrapper->handle;
                info.memoryOffset           = wrapper->bind_offset;
                EncodeStructArray(&encoder_, &info, 1);
                encoder_.EncodeEnumValue(VK_SUCCESS);

                WriteFunctionCall(format::ApiCall_vkBindBufferMemory2, &parameter_stream_);
            }
            parameter_stream_.Reset();

            // Group buffers with memory bindings by device for memory snapshot.
            ResourceSnapshotQueueFamilyTable& snapshot_table = (*resources)[device_wrapper];
            ResourceSnapshotInfo&             snapshot_entry = snapshot_table[wrapper->queue_family_index];

            BufferSnapshotInfo snapshot_info;
            snapshot_info.buffer_wrapper    = wrapper;
            snapshot_info.memory_wrapper    = memory_wrapper;
            snapshot_info.memory_properties = GetMemoryProperties(device_wrapper, memory_wrapper, state_table);
            snapshot_info.need_staging_copy = !IsBufferReadable(snapshot_info.memory_properties, memory_wrapper);

            if ((*max_resource_size) < wrapper->created_size)
            {
                (*max_resource_size) = wrapper->created_size;
            }

            if (snapshot_info.need_staging_copy && ((*max_staging_copy_size) < wrapper->created_size))
            {
                (*max_staging_copy_size) = wrapper->created_size;
            }

            snapshot_entry.buffers.emplace_back(snapshot_info);
        }
    });
}

void VulkanStateWriter::WriteImageMemoryState(const VulkanStateTable& state_table,
                                              DeviceResourceTables*   resources,
                                              VkDeviceSize*           max_resource_size,
                                              VkDeviceSize*           max_staging_copy_size)
{
    assert((resources != nullptr) && (max_resource_size != nullptr) && (max_staging_copy_size != nullptr));

    state_table.VisitWrappers([&](const ImageWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Perform memory binding.
        const DeviceMemoryWrapper* memory_wrapper = state_table.GetDeviceMemoryWrapper(wrapper->bind_memory_id);

        if ((wrapper->is_swapchain_image && memory_wrapper == nullptr && wrapper->bind_device != nullptr) ||
            (!wrapper->is_swapchain_image && memory_wrapper != nullptr))
        {
            const DeviceWrapper* device_wrapper = wrapper->bind_device;
            const DeviceTable*   device_table   = &device_wrapper->layer_table;

            assert((device_wrapper != nullptr) && (device_table != nullptr));

            // Write memory requirements query before bind command.
            VkMemoryRequirements memory_requirements;

            device_table->GetImageMemoryRequirements(device_wrapper->handle, wrapper->handle, &memory_requirements);

            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            EncodeStructPtr(&encoder_, &memory_requirements);

            WriteFunctionCall(format::ApiCall_vkGetImageMemoryRequirements, &parameter_stream_);
            parameter_stream_.Reset();

            // Write memory bind command.
            if (wrapper->bind_pnext == nullptr)
            {
                encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                encoder_.EncodeHandleIdValue(wrapper->handle_id);
                encoder_.EncodeHandleIdValue(memory_wrapper->handle_id);
                encoder_.EncodeVkDeviceSizeValue(wrapper->bind_offset);
                encoder_.EncodeEnumValue(VK_SUCCESS);

                WriteFunctionCall(format::ApiCall_vkBindImageMemory, &parameter_stream_);
            }
            else
            {
                encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                encoder_.EncodeUInt32Value(1);

                VkBindImageMemoryInfo info = {};
                info.sType                 = VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO;
                info.pNext                 = wrapper->bind_pnext;
                info.image                 = wrapper->handle;
                info.memory                = memory_wrapper->handle;
                info.memoryOffset          = wrapper->bind_offset;
                EncodeStructArray(&encoder_, &info, 1);
                encoder_.EncodeEnumValue(VK_SUCCESS);

                WriteFunctionCall(format::ApiCall_vkBindImageMemory2, &parameter_stream_);
            }
            parameter_stream_.Reset();

            VkMemoryPropertyFlags memory_properties = 0;
            if (memory_wrapper != nullptr)
            {
                GetMemoryProperties(device_wrapper, memory_wrapper, state_table);
            }

            bool is_transitioned = (wrapper->current_layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                                   (wrapper->current_layout != VK_IMAGE_LAYOUT_PREINITIALIZED);
            bool is_writable =
                (wrapper->tiling == VK_IMAGE_TILING_LINEAR) &&
                ((memory_properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);

            // If an image is not host writable and has not been transitioned from the undefined or preinitialized
            // layouts, no data could have been loaded into it and its data will be omitted from the state snapshot.
            if (is_transitioned || is_writable)
            {
                // Group images with memory bindings by device for memory snapshot.
                ResourceSnapshotQueueFamilyTable& snapshot_table = (*resources)[device_wrapper];
                ResourceSnapshotInfo&             snapshot_entry = snapshot_table[wrapper->queue_family_index];

                bool need_staging_copy = !IsImageReadable(memory_properties, memory_wrapper, wrapper);

                std::vector<VkImageAspectFlagBits> aspects;
                bool                               combined_depth_stencil;
                GetFormatAspects(wrapper->format, &aspects, &combined_depth_stencil);

                for (auto aspect : aspects)
                {
                    ImageSnapshotInfo snapshot_info;

                    snapshot_info.image_wrapper     = wrapper;
                    snapshot_info.memory_wrapper    = memory_wrapper;
                    snapshot_info.memory_properties = memory_properties;
                    snapshot_info.need_staging_copy = need_staging_copy;
                    snapshot_info.aspect            = aspect;

                    GetImageSizes(wrapper, &snapshot_info);

                    if ((*max_resource_size) < snapshot_info.resource_size)
                    {
                        (*max_resource_size) = snapshot_info.resource_size;
                    }

                    if (snapshot_info.need_staging_copy && ((*max_staging_copy_size) < snapshot_info.resource_size))
                    {
                        (*max_staging_copy_size) = snapshot_info.resource_size;
                    }

                    snapshot_entry.images.emplace_back(snapshot_info);

                    // Write image subresource layout queries for linear/host-visible images.
                    if (is_writable)
                    {
                        VkImageAspectFlags aspect_flags = aspect;

                        if (!combined_depth_stencil)
                        {
                            WriteImageSubresourceLayouts(wrapper, aspect_flags);
                        }
                        else
                        {
                            // Specify combined depth-stencil aspect flags for combined depth-stencil formats when
                            // processing the depth aspect, while skipping image subresource layout query for
                            // stencil aspect.
                            if (aspect == VK_IMAGE_ASPECT_DEPTH_BIT)
                            {
                                aspect_flags = GetFormatAspectMask(wrapper->format);
                                WriteImageSubresourceLayouts(wrapper, aspect_flags);
                            }
                        }
                    }
                }
            }
        }
    });
}

void VulkanStateWriter::WriteImageSubresourceLayouts(const ImageWrapper* image_wrapper, VkImageAspectFlags aspect_flags)
{
    assert((image_wrapper != nullptr) && (aspect_flags != 0));

    const DeviceWrapper* device_wrapper = image_wrapper->bind_device;
    const DeviceTable*   device_table   = &device_wrapper->layer_table;

    assert((device_wrapper != nullptr) && (device_table != nullptr));

    for (uint32_t layer = 0; layer < image_wrapper->array_layers; ++layer)
    {
        for (uint32_t level = 0; level < image_wrapper->mip_levels; ++level)
        {
            VkSubresourceLayout layout = {};
            VkImageSubresource  subresource;
            subresource.aspectMask = aspect_flags;
            subresource.mipLevel   = level;
            subresource.arrayLayer = layer;

            device_table->GetImageSubresourceLayout(
                device_wrapper->handle, image_wrapper->handle, &subresource, &layout);

            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(image_wrapper->handle_id);
            EncodeStructPtr(&encoder_, &subresource);
            EncodeStructPtr(&encoder_, &layout);

            WriteFunctionCall(format::ApiCall_vkGetImageSubresourceLayout, &parameter_stream_);
            parameter_stream_.Reset();
        }
    }
}

void VulkanStateWriter::WriteResourceMemoryState(const VulkanStateTable& state_table)
{
    DeviceResourceTables resources;
    VkDeviceSize         max_resource_size     = 0;
    VkDeviceSize         max_staging_copy_size = 0;

    WriteBufferMemoryState(state_table, &resources, &max_resource_size, &max_staging_copy_size);
    WriteImageMemoryState(state_table, &resources, &max_resource_size, &max_staging_copy_size);

    // Write resource memory content.
    for (const auto& resource_entry : resources)
    {
        const DeviceWrapper*  device_wrapper            = resource_entry.first;
        VkBuffer              staging_buffer            = VK_NULL_HANDLE;
        VkDeviceMemory        staging_memory            = VK_NULL_HANDLE;
        VkMemoryPropertyFlags staging_memory_properties = 0;
        VkResult              result                    = VK_SUCCESS;

        if (max_staging_copy_size > 0)
        {
            assert(device_wrapper != nullptr);

            result = CreateStagingBuffer(device_wrapper,
                                         max_staging_copy_size,
                                         &staging_buffer,
                                         &staging_memory,
                                         &staging_memory_properties,
                                         state_table);
        }

        if (result == VK_SUCCESS)
        {
            const DeviceTable* device_table = &device_wrapper->layer_table;

            format::BeginResourceInitCommand begin_cmd;
            begin_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(begin_cmd);
            begin_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            begin_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
                format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kBeginResourceInitCommand);
            begin_cmd.thread_id         = thread_id_;
            begin_cmd.device_id         = device_wrapper->handle_id;
            begin_cmd.max_resource_size = max_resource_size;
            begin_cmd.max_copy_size     = max_staging_copy_size;

            output_stream_->Write(&begin_cmd, sizeof(begin_cmd));

            for (const auto& queue_family_entry : resource_entry.second)
            {
                uint32_t        queue_family_index = queue_family_entry.first;
                VkQueue         queue              = VK_NULL_HANDLE;
                VkCommandPool   command_pool       = VK_NULL_HANDLE;
                VkCommandBuffer command_buffer     = VK_NULL_HANDLE;

                command_pool = GetCommandPool(device_wrapper, queue_family_index);
                if (command_pool != VK_NULL_HANDLE)
                {
                    command_buffer = GetCommandBuffer(device_wrapper, command_pool);

                    if (command_buffer == VK_NULL_HANDLE)
                    {
                        GFXRECON_LOG_ERROR("Failed to create a command buffer to process trim state");
                        device_table->DestroyCommandPool(device_wrapper->handle, command_pool, nullptr);
                        command_pool = VK_NULL_HANDLE;
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR("Failed to create a command pool to process trim state");
                }

                if (command_buffer != VK_NULL_HANDLE)
                {
                    bool is_staging_memory_coherent = IsMemoryCoherent(staging_memory_properties);
                    queue                           = GetQueue(device_wrapper, queue_family_index, 0);

                    ProcessBufferMemory(device_wrapper,
                                        queue_family_entry.second.buffers,
                                        queue_family_index,
                                        queue,
                                        command_buffer,
                                        staging_buffer,
                                        staging_memory,
                                        is_staging_memory_coherent);

                    ProcessImageMemory(device_wrapper,
                                       queue_family_entry.second.images,
                                       queue_family_index,
                                       queue,
                                       command_buffer,
                                       staging_buffer,
                                       staging_memory,
                                       is_staging_memory_coherent,
                                       state_table);

                    device_table->DestroyCommandPool(device_wrapper->handle, command_pool, nullptr);
                }
            }

            format::EndResourceInitCommand end_cmd;
            end_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(end_cmd);
            end_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            end_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan,
                                                                      format::MetaDataType::kEndResourceInitCommand);
            end_cmd.thread_id                     = thread_id_;
            end_cmd.device_id                     = device_wrapper->handle_id;

            output_stream_->Write(&end_cmd, sizeof(end_cmd));

            if (max_staging_copy_size > 0)
            {
                device_table->DestroyBuffer(device_wrapper->handle, staging_buffer, nullptr);
                device_table->FreeMemory(device_wrapper->handle, staging_memory, nullptr);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to create a staging buffer to process trim state");
        }
    }
}

void VulkanStateWriter::WriteMappedMemoryState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const DeviceMemoryWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->mapped_data != nullptr)
        {
            const VkResult result         = VK_SUCCESS;
            const auto     device_wrapper = wrapper->map_device;

            // Map the replay memory.
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeVkDeviceSizeValue(wrapper->mapped_offset);
            encoder_.EncodeVkDeviceSizeValue(wrapper->mapped_size);
            encoder_.EncodeFlagsValue(wrapper->mapped_flags);
            encoder_.EncodeVoidPtrPtr(&wrapper->mapped_data);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkMapMemory, &parameter_stream_);
            parameter_stream_.Reset();
        }
    });
}

void VulkanStateWriter::WriteSwapchainImageState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const SwapchainKHRWrapper* wrapper) {
        assert(wrapper != nullptr && wrapper->device != nullptr);

        const DeviceWrapper* device_wrapper = wrapper->device;
        size_t               image_count    = wrapper->child_images.size() > wrapper->image_acquired_info.size()
                                                  ? wrapper->image_acquired_info.size()
                                                  : wrapper->child_images.size();

        format::SetSwapchainImageStateCommandHeader header;
        format::SwapchainImageStateInfo             info;

        // Initialize standard block header.
        header.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(header) + (image_count * sizeof(info));
        header.meta_header.block_header.type = format::kMetaDataBlock;

        // Initialize block data for set-swapchain-image-state meta-data command.
        header.meta_header.meta_data_id = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan,
                                                                 format::MetaDataType::kSetSwapchainImageStateCommand);
        header.thread_id                = thread_id_;
        header.device_id                = device_wrapper->handle_id;
        header.swapchain_id             = wrapper->handle_id;
        header.last_presented_image     = wrapper->last_presented_image;
        header.image_info_count         = static_cast<uint32_t>(image_count);

        output_stream_->Write(&header, sizeof(header));

        for (size_t i = 0; i < image_count; ++i)
        {
            ImageWrapper* image_wrapper = wrapper->child_images[i];

            info.image_index  = static_cast<uint32_t>(i);
            info.image_id     = image_wrapper->handle_id;
            info.image_layout = image_wrapper->current_layout;

            if (wrapper->image_acquired_info[i].last_presented_queue != VK_NULL_HANDLE)
            {
                auto queue_wrapper = GetWrapper<QueueWrapper>(wrapper->image_acquired_info[i].last_presented_queue);
                info.last_presented_queue_id = queue_wrapper->handle_id;
            }
            else
            {
                // Image has not been presented.
                info.last_presented_queue_id = 0;
            }

            if (wrapper->image_acquired_info[i].is_acquired)
            {
                info.acquired            = 1;
                info.acquire_device_mask = wrapper->image_acquired_info[i].acquired_device_mask;

                // Only provide sync object IDs if the objects have not been destroyed between now and image
                // acquire.
                const SemaphoreWrapper* semaphore_wrapper =
                    state_table.GetSemaphoreWrapper(wrapper->image_acquired_info[i].acquired_semaphore_id);
                if (semaphore_wrapper != nullptr)
                {
                    info.acquire_semaphore_id = wrapper->image_acquired_info[i].acquired_semaphore_id;
                }
                else
                {
                    info.acquire_semaphore_id = 0;
                }

                const FenceWrapper* fence_wrapper =
                    state_table.GetFenceWrapper(wrapper->image_acquired_info[i].acquired_fence_id);
                if (fence_wrapper != nullptr)
                {
                    info.acquire_fence_id = wrapper->image_acquired_info[i].acquired_fence_id;
                }
                else
                {
                    info.acquire_fence_id = 0;
                }
            }
            else
            {
                info.acquired             = 0;
                info.acquire_device_mask  = 0;
                info.acquire_semaphore_id = 0;
                info.acquire_fence_id     = 0;
            }

            output_stream_->Write(&info, sizeof(info));
        }
    });
}

void VulkanStateWriter::WritePhysicalDevicePropertiesMetaData(const PhysicalDeviceWrapper* physical_device_wrapper)
{
    // Write the meta-data commands to set physical device properties.
    const InstanceTable* instance_table = physical_device_wrapper->layer_table_ref;
    assert(instance_table != nullptr);

    format::HandleId           physical_device_id     = physical_device_wrapper->handle_id;
    VkPhysicalDevice           physical_device_handle = physical_device_wrapper->handle;
    uint32_t                   count                  = 0;
    VkPhysicalDeviceProperties properties;

    instance_table->GetPhysicalDeviceProperties(physical_device_handle, &properties);

    WriteSetDevicePropertiesCommand(physical_device_id, properties);
    WriteSetDeviceMemoryPropertiesCommand(physical_device_id, physical_device_wrapper->memory_properties);
}

template <typename T>
void VulkanStateWriter::WriteGetPhysicalDeviceQueueFamilyProperties(format::ApiCallId call_id,
                                                                    format::HandleId  physical_device_id,
                                                                    uint32_t          property_count,
                                                                    T*                properties)
{
    // First write the call to retrieve the size.
    encoder_.EncodeHandleIdValue(physical_device_id);
    encoder_.EncodeUInt32Ptr(&property_count);
    EncodeStructArray<T>(&encoder_, nullptr, 0);

    WriteFunctionCall(call_id, &parameter_stream_);
    parameter_stream_.Reset();

    // Then write the call with the data.
    encoder_.EncodeHandleIdValue(physical_device_id);
    encoder_.EncodeUInt32Ptr(&property_count);
    EncodeStructArray(&encoder_, properties, property_count);

    WriteFunctionCall(call_id, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfaceSupport(format::HandleId physical_device_id,
                                                             uint32_t         queue_family_index,
                                                             format::HandleId surface_id,
                                                             VkBool32         supported)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(physical_device_id);
    encoder_.EncodeUInt32Value(queue_family_index);
    encoder_.EncodeHandleIdValue(surface_id);
    encoder_.EncodeVkBool32Ptr(&supported);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfaceCapabilities(format::HandleId           physical_device_id,
                                                                  format::HandleId           surface_id,
                                                                  const SurfaceCapabilities& capabilities,
                                                                  const VulkanStateTable&    state_table)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(physical_device_id);
    EncodeStructPtr(&encoder_, &capabilities.surface_info);
    EncodeStructPtr(&encoder_, &capabilities.surface_capabilities);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfaceFormats(format::HandleId        physical_device_id,
                                                             format::HandleId        surface_id,
                                                             const SurfaceFormats&   formats,
                                                             const VulkanStateTable& state_table)
{
    const VkResult result = VK_SUCCESS;

    uint32_t format_count = static_cast<uint32_t>(formats.surface_formats.size());

    // First write the call to retrieve the size.
    encoder_.EncodeHandleIdValue(physical_device_id);
    EncodeStructPtr(&encoder_, &formats.surface_info);
    encoder_.EncodeUInt32Ptr(&format_count);
    EncodeStructArray<VkSurfaceFormatKHR>(&encoder_, nullptr, 0);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR, &parameter_stream_);
    parameter_stream_.Reset();

    // Then write the call with the data.
    encoder_.EncodeHandleIdValue(physical_device_id);
    EncodeStructPtr(&encoder_, &formats.surface_info);
    encoder_.EncodeUInt32Ptr(&format_count);
    EncodeStructArray(&encoder_, formats.surface_formats.data(), format_count);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfacePresentModes(format::HandleId           physical_device_id,
                                                                  format::HandleId           surface_id,
                                                                  const SurfacePresentModes& present_modes,
                                                                  const VulkanStateTable&    state_table)
{
    const VkResult          result        = VK_SUCCESS;
    uint32_t                mode_count    = static_cast<uint32_t>(present_modes.present_modes.size());
    const VkPresentModeKHR* pPresentModes = present_modes.present_modes.data();

    if (present_modes.surface_info_pnext == nullptr)
    {
        // First write the call to retrieve the size.
        encoder_.EncodeHandleIdValue(physical_device_id);
        encoder_.EncodeHandleIdValue(surface_id);
        encoder_.EncodeUInt32Ptr(&mode_count);
        encoder_.EncodeEnumArray<VkPresentModeKHR>(nullptr, 0);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR, &parameter_stream_);
        parameter_stream_.Reset();

        // Then write the call with the data.
        encoder_.EncodeHandleIdValue(physical_device_id);
        encoder_.EncodeHandleIdValue(surface_id);
        encoder_.EncodeUInt32Ptr(&mode_count);
        encoder_.EncodeEnumArray(pPresentModes, mode_count);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR, &parameter_stream_);
        parameter_stream_.Reset();
    }
    else
    {
        VkPhysicalDeviceSurfaceInfo2KHR surface_info2;
        surface_info2.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        surface_info2.pNext   = present_modes.surface_info_pnext;
        auto surface_wrapper  = state_table.GetSurfaceKHRWrapper(surface_id);
        surface_info2.surface = surface_wrapper->handle;

        // First write the call to retrieve the size.
        encoder_.EncodeHandleIdValue(physical_device_id);
        EncodeStructPtr(&encoder_, &surface_info2);
        encoder_.EncodeUInt32Ptr(&mode_count);
        encoder_.EncodeEnumArray<VkPresentModeKHR>(nullptr, 0);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT, &parameter_stream_);
        parameter_stream_.Reset();

        // Then write the call with the data.
        encoder_.EncodeHandleIdValue(physical_device_id);
        EncodeStructPtr(&encoder_, &surface_info2);
        encoder_.EncodeUInt32Ptr(&mode_count);
        encoder_.EncodeEnumArray(pPresentModes, mode_count);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT, &parameter_stream_);
        parameter_stream_.Reset();
    }
}

void VulkanStateWriter::WriteGetDeviceGroupSurfacePresentModes(format::HandleId                device_id,
                                                               format::HandleId                surface_id,
                                                               const GroupSurfacePresentModes& present_modes,
                                                               const VulkanStateTable&         state_table)
{
    const VkResult result = VK_SUCCESS;

    if (present_modes.surface_info_pnext == nullptr)
    {
        encoder_.EncodeHandleIdValue(device_id);
        encoder_.EncodeHandleIdValue(surface_id);
        encoder_.EncodeFlagsPtr(&present_modes.present_modes);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR, &parameter_stream_);
        parameter_stream_.Reset();
    }
    else
    {
        VkPhysicalDeviceSurfaceInfo2KHR surface_info2;
        surface_info2.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        surface_info2.pNext   = present_modes.surface_info_pnext;
        auto surface_wrapper  = state_table.GetSurfaceKHRWrapper(surface_id);
        surface_info2.surface = surface_wrapper->handle;

        encoder_.EncodeHandleIdValue(device_id);
        EncodeStructPtr(&encoder_, &surface_info2);
        encoder_.EncodeFlagsPtr(&present_modes.present_modes);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT, &parameter_stream_);
        parameter_stream_.Reset();
    }
}

void VulkanStateWriter::WriteCommandProcessingCreateCommands(format::HandleId device_id,
                                                             uint32_t         queue_family_index,
                                                             format::HandleId queue_id,
                                                             format::HandleId command_pool_id,
                                                             format::HandleId command_buffer_id)
{
    const VkResult               result    = VK_SUCCESS;
    const VkAllocationCallbacks* allocator = nullptr;

    // Retrieve the queue for the queue family index.
    encoder_.EncodeHandleIdValue(device_id);
    encoder_.EncodeUInt32Value(queue_family_index);
    encoder_.EncodeUInt32Value(0);
    encoder_.EncodeHandleIdPtr(&queue_id);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetDeviceQueue, &parameter_stream_);
    parameter_stream_.Reset();

    // Create the command pool for the current queue family index.
    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    create_info.pNext                   = nullptr;
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = queue_family_index;

    encoder_.EncodeHandleIdValue(device_id);
    EncodeStructPtr(&encoder_, &create_info);
    EncodeStructPtr(&encoder_, allocator);
    encoder_.EncodeHandleIdPtr(&command_pool_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkCreateCommandPool, &parameter_stream_);
    parameter_stream_.Reset();

    // Create the command buffer from the pool. Requires a temporary wrapper for EncodeStructPtr, which expects
    // struct members to be wrapped handles.
    CommandPoolWrapper encode_wrapper;
    encode_wrapper.handle_id = command_pool_id;

    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.pNext                       = nullptr;
    alloc_info.commandPool                 = encode_wrapper.handle;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;

    encoder_.EncodeHandleIdValue(device_id);
    EncodeStructPtr(&encoder_, &alloc_info);
    encoder_.EncodeHandleIdArray(&command_buffer_id, 1);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkAllocateCommandBuffers, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteCommandBegin(format::HandleId command_buffer_id)
{
    const VkResult result = VK_SUCCESS;

    VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
    begin_info.pNext                    = nullptr;
    begin_info.flags                    = 0;
    begin_info.pInheritanceInfo         = nullptr;

    encoder_.EncodeHandleIdValue(command_buffer_id);
    EncodeStructPtr(&encoder_, &begin_info);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkBeginCommandBuffer, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteCommandEnd(format::HandleId command_buffer_id)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(command_buffer_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkEndCommandBuffer, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteCommandExecution(format::HandleId            queue_id,
                                              uint32_t                    command_buffer_count,
                                              const format::HandleId*     command_buffer_ids,
                                              uint32_t                    signal_semaphore_count,
                                              const format::HandleId*     signal_semaphore_ids,
                                              uint32_t                    wait_semaphore_count,
                                              const format::HandleId*     wait_semaphore_ids,
                                              const VkPipelineStageFlags* wait_dst_stage_mask)
{
    const VkResult result = VK_SUCCESS;
    const VkFence  fence  = VK_NULL_HANDLE;

    // Write queue submission.
    encoder_.EncodeHandleIdValue(queue_id);
    encoder_.EncodeUInt32Value(1);

    // VkSubmitInfo encoding.
    VkSubmitInfo info = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    encoder_.EncodeStructPtrPreamble(&info);
    encoder_.EncodeEnumValue(info.sType);
    EncodePNextStruct(&encoder_, nullptr);
    encoder_.EncodeUInt32Value(wait_semaphore_count);
    encoder_.EncodeHandleIdArray(wait_semaphore_ids, wait_semaphore_count);
    encoder_.EncodeFlagsArray(wait_dst_stage_mask, wait_semaphore_count);
    encoder_.EncodeUInt32Value(command_buffer_count);
    encoder_.EncodeHandleIdArray(command_buffer_ids, command_buffer_count);
    encoder_.EncodeUInt32Value(signal_semaphore_count);
    encoder_.EncodeHandleIdArray(signal_semaphore_ids, signal_semaphore_count);

    encoder_.EncodeHandleValue<FenceWrapper>(fence);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkQueueSubmit, &parameter_stream_);
    parameter_stream_.Reset();

    // Write queue wait idle.
    encoder_.EncodeHandleIdValue(queue_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkQueueWaitIdle, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteCommandBufferCommands(const CommandBufferWrapper* wrapper,
                                                   const VulkanStateTable&     state_table)
{
    assert(wrapper != nullptr);

    if (CheckCommandHandles(wrapper, state_table))
    {
        // Replay each of the commands that was recorded for the command buffer.
        size_t         offset    = 0;
        size_t         data_size = wrapper->command_data.GetDataSize();
        const uint8_t* data      = wrapper->command_data.GetData();

        while (offset < data_size)
        {
            const size_t*            parameter_size = reinterpret_cast<const size_t*>(&data[offset]);
            const format::ApiCallId* call_id =
                reinterpret_cast<const format::ApiCallId*>(&data[offset] + sizeof(size_t));
            const uint8_t* parameter_data = &data[offset] + (sizeof(size_t) + sizeof(format::ApiCallId));

            parameter_stream_.Write(parameter_data, (*parameter_size));
            WriteFunctionCall((*call_id), &parameter_stream_);
            parameter_stream_.Reset();

            offset += sizeof(size_t) + sizeof(format::ApiCallId) + (*parameter_size);
        }

        assert(offset == data_size);
    }
}

void VulkanStateWriter::WriteDescriptorUpdateCommand(format::HandleId      device_id,
                                                     const DescriptorInfo* binding,
                                                     VkWriteDescriptorSet* write)
{
    assert((binding != nullptr) && (write != nullptr));

    const VkCopyDescriptorSet* copy = nullptr;

    switch (write->descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            write->pBufferInfo      = nullptr;
            write->pImageInfo       = &binding->images[write->dstArrayElement];
            write->pTexelBufferView = nullptr;
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            write->pBufferInfo      = &binding->buffers[write->dstArrayElement];
            write->pImageInfo       = nullptr;
            write->pTexelBufferView = nullptr;
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            write->pBufferInfo      = nullptr;
            write->pImageInfo       = nullptr;
            write->pTexelBufferView = &binding->texel_buffer_views[write->dstArrayElement];
            break;
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
            // TODO
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            // TODO
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
        {
            write->pBufferInfo      = nullptr;
            write->pImageInfo       = nullptr;
            write->pTexelBufferView = nullptr;
        }
        break;
        default:
            GFXRECON_LOG_WARNING("Attempting to initialize descriptor state for unrecognized descriptor type");
            break;
    }

    encoder_.EncodeHandleIdValue(device_id);
    encoder_.EncodeUInt32Value(1);
    EncodeStructArray(&encoder_, write, 1);
    encoder_.EncodeUInt32Value(0);
    EncodeStructArray(&encoder_, copy, 0);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkUpdateDescriptorSets, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteQueryPoolReset(format::HandleId                            device_id,
                                            const std::vector<const QueryPoolWrapper*>& query_pool_wrappers)
{
    // Retrieve a queue and create a command buffer for query pool reset.
    WriteCommandProcessingCreateCommands(
        device_id, kDefaultQueueFamilyIndex, kTempQueueId, kTempCommandPoolId, kTempCommandBufferId);

    WriteCommandBegin(kTempCommandBufferId);

    for (auto wrapper : query_pool_wrappers)
    {
        encoder_.EncodeHandleIdValue(kTempCommandBufferId);
        encoder_.EncodeHandleIdValue(wrapper->handle_id);
        encoder_.EncodeUInt32Value(0);
        encoder_.EncodeUInt32Value(wrapper->query_count);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdResetQueryPool, &parameter_stream_);
        parameter_stream_.Reset();
    }

    WriteCommandEnd(kTempCommandBufferId);
    WriteCommandExecution(kTempQueueId, kTempCommandBufferId);

    WriteDestroyDeviceObject(format::ApiCallId::ApiCall_vkDestroyCommandPool, device_id, kTempCommandPoolId, nullptr);
}

void VulkanStateWriter::WriteQueryActivation(format::HandleId           device_id,
                                             uint32_t                   queue_family_index,
                                             const QueryActivationList& active_queries)
{
    const VkPipelineStageFlagBits timestamp_stage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;

    // Retrieve a queue and create a command buffer for query activation.
    WriteCommandProcessingCreateCommands(
        device_id, queue_family_index, kTempQueueId, kTempCommandPoolId, kTempCommandBufferId);

    WriteCommandBegin(kTempCommandBufferId);

    for (auto query_entry : active_queries)
    {
        if (query_entry.type == VK_QUERY_TYPE_TIMESTAMP)
        {
            encoder_.EncodeHandleIdValue(kTempCommandBufferId);
            encoder_.EncodeEnumValue(timestamp_stage);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp, &parameter_stream_);
            parameter_stream_.Reset();
        }
        else if (query_entry.type == VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT)
        {
            encoder_.EncodeHandleIdValue(kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);
            encoder_.EncodeFlagsValue(query_entry.flags);
            encoder_.EncodeUInt32Value(query_entry.type_index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT, &parameter_stream_);
            parameter_stream_.Reset();

            encoder_.EncodeHandleIdValue(kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);
            encoder_.EncodeUInt32Value(query_entry.type_index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT, &parameter_stream_);
            parameter_stream_.Reset();
        }
        else if (query_entry.type == VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV)
        {
            // TODO
            GFXRECON_LOG_ERROR("Use of VkQueryType::VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV is not "
                               "currently supported when trimming is enabled.");
        }
        else if (query_entry.type == VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR)
        {
            // TODO
            GFXRECON_LOG_ERROR("Use of VkQueryType::VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR is not "
                               "currently supported when trimming is enabled.");
        }
        else
        {
            encoder_.EncodeHandleIdValue(kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);
            encoder_.EncodeFlagsValue(query_entry.flags);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdBeginQuery, &parameter_stream_);
            parameter_stream_.Reset();

            encoder_.EncodeHandleIdValue(kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdEndQuery, &parameter_stream_);
            parameter_stream_.Reset();
        }
    }

    WriteCommandEnd(kTempCommandBufferId);
    WriteCommandExecution(kTempQueueId, kTempCommandBufferId);

    WriteDestroyDeviceObject(format::ApiCallId::ApiCall_vkDestroyCommandPool, device_id, kTempCommandPoolId, nullptr);
}

void VulkanStateWriter::WriteCreateFence(format::HandleId device_id, format::HandleId fence_id, bool signaled)
{
    // TODO: Track pNext values and allocation callback pointer values so the new create parameters match the
    // original parameters (excluding signal state).
    const VkResult               result          = VK_SUCCESS;
    const VkAllocationCallbacks* alloc_callbacks = nullptr;

    VkFenceCreateInfo create_info = { VK_STRUCTURE_TYPE_FENCE_CREATE_INFO };
    create_info.pNext             = nullptr;
    create_info.flags             = 0;

    if (signaled)
    {
        create_info.flags |= VK_FENCE_CREATE_SIGNALED_BIT;
    }

    encoder_.EncodeHandleIdValue(device_id);
    EncodeStructPtr(&encoder_, &create_info);
    EncodeStructPtr(&encoder_, alloc_callbacks);
    encoder_.EncodeHandleIdPtr(&fence_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkCreateFence, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteSetEvent(format::HandleId device_id, format::HandleId event_id)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(device_id);
    encoder_.EncodeHandleIdValue(event_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkSetEvent, &parameter_stream_);
    parameter_stream_.Reset();
}

void VulkanStateWriter::WriteSignalSemaphoreValue(format::ApiCallId api_call_id,
                                                  format::HandleId  device_id,
                                                  format::HandleId  semaphore_id,
                                                  uint64_t          value)
{
    const VkResult result = VK_SUCCESS;

    VkSemaphoreSignalInfo signal_info = { VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO };

    encoder_.EncodeHandleIdValue(device_id);

    encoder_.EncodeStructPtrPreamble(&signal_info);
    encoder_.EncodeEnumValue(signal_info.sType);
    EncodePNextStruct(&encoder_, nullptr);
    encoder_.EncodeHandleIdValue(semaphore_id);
    encoder_.EncodeUInt64Value(value);

    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(api_call_id, &parameter_stream_);
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

void VulkanStateWriter::DestroyTemporaryDeviceObject(format::ApiCallId               call_id,
                                                     format::HandleId                object_id,
                                                     const util::MemoryOutputStream* create_parameters)
{
    // TODO: Track allocation callbacks.
    const VkAllocationCallbacks* allocator = nullptr;

    // Extract device from create parameter buffer.
    // TODO: Device children will be stored in the device wrapper, and device handle will be directly available
    // when processing children (no need to extract).
    format::HandleId device_id = *reinterpret_cast<const format::HandleId*>(create_parameters->GetData());

    WriteDestroyDeviceObject(call_id, device_id, object_id, allocator);
}

// TODO: This is the same code used by CaptureManager to write function call data. It could be moved to a format
// utility.
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
            compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &compressed_parameter_buffer_, 0);

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

// TODO: This is the same code used by CaptureManager to write command data. It could be moved to a format
// utility.
void VulkanStateWriter::WriteFillMemoryCmd(format::HandleId memory_id,
                                           VkDeviceSize     offset,
                                           VkDeviceSize     size,
                                           const void*      data)
{
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

    format::FillMemoryCommandHeader fill_cmd;
    const uint8_t*                  write_address = (static_cast<const uint8_t*>(data) + offset);
    size_t                          write_size    = static_cast<size_t>(size);

    fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    fill_cmd.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kFillMemoryCommand);
    fill_cmd.thread_id     = thread_id_;
    fill_cmd.memory_id     = memory_id;
    fill_cmd.memory_offset = offset;
    fill_cmd.memory_size   = size;

    if (compressor_ != nullptr)
    {
        size_t compressed_size = compressor_->Compress(write_size, write_address, &compressed_parameter_buffer_, 0);

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
    fill_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(fill_cmd) + write_size;

    output_stream_->Write(&fill_cmd, sizeof(fill_cmd));
    output_stream_->Write(write_address, write_size);
}

// TODO: This is the same code used by CaptureManager to write command data. It could be moved to a format
// utility.
void VulkanStateWriter::WriteResizeWindowCmd(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    format::ResizeWindowCommand resize_cmd;
    resize_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    resize_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(resize_cmd);
    resize_cmd.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kResizeWindowCommand);
    resize_cmd.thread_id = thread_id_;

    resize_cmd.surface_id = surface_id;
    resize_cmd.width      = width;
    resize_cmd.height     = height;

    output_stream_->Write(&resize_cmd, sizeof(resize_cmd));
}

// TODO: This is the same code used by CaptureManager to write command data. It could be moved to a format
// utility.
void VulkanStateWriter::WriteResizeWindowCmd2(format::HandleId              surface_id,
                                              uint32_t                      width,
                                              uint32_t                      height,
                                              VkSurfaceTransformFlagBitsKHR pre_transform)
{
    format::ResizeWindowCommand2 resize_cmd2;
    resize_cmd2.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    resize_cmd2.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(resize_cmd2);
    resize_cmd2.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kResizeWindowCommand2);
    resize_cmd2.thread_id = thread_id_;

    resize_cmd2.surface_id = surface_id;
    resize_cmd2.width      = width;
    resize_cmd2.height     = height;

    switch (pre_transform)
    {
        default:
        case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
        case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
            resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform0;
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
            resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform90;
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
            resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform180;
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
            resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform270;
            break;
    }

    output_stream_->Write(&resize_cmd2, sizeof(resize_cmd2));
}

// TODO: This is the same code used by CaptureManager to write command data. It could be moved to a format
// utility.
void VulkanStateWriter::WriteCreateHardwareBufferCmd(format::HandleId memory_id,
                                                     AHardwareBuffer* hardware_buffer,
                                                     const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffer != nullptr);

    format::CreateHardwareBufferCommandHeader create_buffer_cmd;

    create_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    create_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(create_buffer_cmd);
    create_buffer_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
        format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kCreateHardwareBufferCommand);
    create_buffer_cmd.thread_id = thread_id_;
    create_buffer_cmd.memory_id = memory_id;
    create_buffer_cmd.buffer_id = reinterpret_cast<uint64_t>(hardware_buffer);

    // Get AHB description data.
    AHardwareBuffer_Desc ahb_desc = {};
    AHardwareBuffer_describe(hardware_buffer, &ahb_desc);

    create_buffer_cmd.format = ahb_desc.format;
    create_buffer_cmd.width  = ahb_desc.width;
    create_buffer_cmd.height = ahb_desc.height;
    create_buffer_cmd.stride = ahb_desc.stride;
    create_buffer_cmd.usage  = ahb_desc.usage;
    create_buffer_cmd.layers = ahb_desc.layers;

    size_t planes_size = 0;

    if (plane_info.empty())
    {
        create_buffer_cmd.planes = 0;
    }
    else
    {
        create_buffer_cmd.planes = static_cast<uint32_t>(plane_info.size());
        // Update size of packet with compressed or uncompressed data size.
        planes_size = sizeof(plane_info[0]) * plane_info.size();
        create_buffer_cmd.meta_header.block_header.size += planes_size;
    }

    output_stream_->Write(&create_buffer_cmd, sizeof(create_buffer_cmd));

    if (planes_size > 0)
    {
        output_stream_->Write(plane_info.data(), planes_size);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(memory_id);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
    GFXRECON_UNREFERENCED_PARAMETER(plane_info);
#endif
}

void VulkanStateWriter::WriteSetDevicePropertiesCommand(format::HandleId                  physical_device_id,
                                                        const VkPhysicalDeviceProperties& properties)
{
    format::SetDevicePropertiesCommand properties_cmd;

    uint32_t device_name_len = static_cast<uint32_t>(util::platform::StringLength(properties.deviceName));

    properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    properties_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(properties_cmd) + device_name_len;
    properties_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan,
                                                                     format::MetaDataType::kSetDevicePropertiesCommand);
    properties_cmd.thread_id                     = thread_id_;
    properties_cmd.physical_device_id            = physical_device_id;
    properties_cmd.api_version                   = properties.apiVersion;
    properties_cmd.driver_version                = properties.driverVersion;
    properties_cmd.vendor_id                     = properties.vendorID;
    properties_cmd.device_id                     = properties.deviceID;
    properties_cmd.device_type                   = properties.deviceType;
    util::platform::MemoryCopy(
        properties_cmd.pipeline_cache_uuid, format::kUuidSize, properties.pipelineCacheUUID, VK_UUID_SIZE);
    properties_cmd.device_name_len = device_name_len;

    output_stream_->Write(&properties_cmd, sizeof(properties_cmd));
    output_stream_->Write(properties.deviceName, properties_cmd.device_name_len);
}

void VulkanStateWriter::WriteSetDeviceMemoryPropertiesCommand(format::HandleId physical_device_id,
                                                              const VkPhysicalDeviceMemoryProperties& memory_properties)
{
    format::SetDeviceMemoryPropertiesCommand memory_properties_cmd;

    memory_properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    memory_properties_cmd.meta_header.block_header.size =
        format::GetMetaDataBlockBaseSize(memory_properties_cmd) +
        (sizeof(format::DeviceMemoryType) * memory_properties.memoryTypeCount) +
        (sizeof(format::DeviceMemoryHeap) * memory_properties.memoryHeapCount);
    memory_properties_cmd.meta_header.meta_data_id = format::MakeMetaDataId(
        format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetDeviceMemoryPropertiesCommand);
    memory_properties_cmd.thread_id          = thread_id_;
    memory_properties_cmd.physical_device_id = physical_device_id;
    memory_properties_cmd.memory_type_count  = memory_properties.memoryTypeCount;
    memory_properties_cmd.memory_heap_count  = memory_properties.memoryHeapCount;

    output_stream_->Write(&memory_properties_cmd, sizeof(memory_properties_cmd));

    format::DeviceMemoryType type;
    for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
    {
        type.property_flags = memory_properties.memoryTypes[i].propertyFlags;
        type.heap_index     = memory_properties.memoryTypes[i].heapIndex;

        output_stream_->Write(&type, sizeof(type));
    }

    format::DeviceMemoryHeap heap;
    for (uint32_t i = 0; i < memory_properties.memoryHeapCount; ++i)
    {
        heap.size  = memory_properties.memoryHeaps[i].size;
        heap.flags = memory_properties.memoryHeaps[i].flags;

        output_stream_->Write(&heap, sizeof(heap));
    }
}

void VulkanStateWriter::WriteSetOpaqueAddressCommand(format::HandleId device_id,
                                                     format::HandleId object_id,
                                                     uint64_t         address)
{
    format::SetOpaqueAddressCommand opaque_address_cmd;

    opaque_address_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    opaque_address_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(opaque_address_cmd);
    opaque_address_cmd.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetOpaqueAddressCommand);
    opaque_address_cmd.thread_id = thread_id_;
    opaque_address_cmd.device_id = device_id;
    opaque_address_cmd.object_id = object_id;
    opaque_address_cmd.address   = address;

    output_stream_->Write(&opaque_address_cmd, sizeof(opaque_address_cmd));
}

void VulkanStateWriter::WriteSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                                    format::HandleId pipeline_id,
                                                                    size_t           data_size,
                                                                    const void*      data)
{
    format::SetRayTracingShaderGroupHandlesCommandHeader set_handles_cmd;

    set_handles_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    set_handles_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(set_handles_cmd) + data_size;
    set_handles_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
        format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetRayTracingShaderGroupHandlesCommand);
    set_handles_cmd.thread_id   = thread_id_;
    set_handles_cmd.device_id   = device_id;
    set_handles_cmd.pipeline_id = pipeline_id;
    set_handles_cmd.data_size   = data_size;

    output_stream_->Write(&set_handles_cmd, sizeof(set_handles_cmd));
    output_stream_->Write(data, data_size);
}

VkMemoryPropertyFlags VulkanStateWriter::GetMemoryProperties(const DeviceWrapper*       device_wrapper,
                                                             const DeviceMemoryWrapper* memory_wrapper,
                                                             const VulkanStateTable&    state_table)
{
    assert((device_wrapper != nullptr) && (memory_wrapper != nullptr));

    VkMemoryPropertyFlags flags = 0;

    const PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;
    assert(physical_device_wrapper != nullptr);

    const VkPhysicalDeviceMemoryProperties* memory_properties = &physical_device_wrapper->memory_properties;
    assert((memory_properties->memoryTypeCount > 0) &&
           (memory_wrapper->memory_type_index < memory_properties->memoryTypeCount));

    flags = memory_properties->memoryTypes[memory_wrapper->memory_type_index].propertyFlags;

    return flags;
}

bool VulkanStateWriter::FindMemoryTypeIndex(const DeviceWrapper*    device_wrapper,
                                            uint32_t                memory_type_bits,
                                            VkMemoryPropertyFlags   desired_flags,
                                            uint32_t*               found_index,
                                            VkMemoryPropertyFlags*  found_flags,
                                            const VulkanStateTable& state_table) const
{
    assert(device_wrapper != nullptr);

    bool found = false;

    const PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;
    assert(physical_device_wrapper != nullptr);

    const VkPhysicalDeviceMemoryProperties* memory_properties = &physical_device_wrapper->memory_properties;
    assert(memory_properties->memoryTypeCount > 0);

    for (uint32_t i = 0; i < memory_properties->memoryTypeCount; ++i)
    {
        if ((memory_type_bits & (1 << i)) &&
            ((memory_properties->memoryTypes[i].propertyFlags & desired_flags) == desired_flags))
        {
            found = true;

            if (found_index != nullptr)
            {
                (*found_index) = i;
            }

            if (found_flags != nullptr)
            {
                (*found_flags) = memory_properties->memoryTypes[i].propertyFlags;
            }

            break;
        }
    }

    return found;
}

void VulkanStateWriter::InvalidateMappedMemoryRange(const DeviceWrapper* device_wrapper,
                                                    VkDeviceMemory       memory,
                                                    VkDeviceSize         offset,
                                                    VkDeviceSize         size)
{
    assert(device_wrapper != nullptr);

    VkMappedMemoryRange invalidate_range = { VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE };
    invalidate_range.pNext               = nullptr;
    invalidate_range.memory              = memory;
    invalidate_range.offset              = offset;
    invalidate_range.size                = size;

    device_wrapper->layer_table.InvalidateMappedMemoryRanges(device_wrapper->handle, 1, &invalidate_range);
}

void VulkanStateWriter::GetFenceStatus(const DeviceWrapper* device_wrapper, VkFence fence, bool* status)
{
    assert(device_wrapper != nullptr);

    VkResult result = device_wrapper->layer_table.GetFenceStatus(device_wrapper->handle, fence);
    (*status)       = (result == VK_SUCCESS);
}

VkQueue
VulkanStateWriter::GetQueue(const DeviceWrapper* device_wrapper, uint32_t queue_family_index, uint32_t queue_index)
{
    assert(device_wrapper != nullptr);

    VkQueue queue = VK_NULL_HANDLE;

    const auto queue_family_flags = device_wrapper->queue_family_creation_flags.find(queue_family_index);
    assert(queue_family_flags != device_wrapper->queue_family_creation_flags.end());
    if (queue_family_flags->second != 0)
    {
        const VkDeviceQueueInfo2 queue_info = {
            VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2, nullptr, queue_family_flags->second, queue_family_index, queue_index
        };

        device_wrapper->layer_table.GetDeviceQueue2(device_wrapper->handle, &queue_info, &queue);
    }
    else
    {
        device_wrapper->layer_table.GetDeviceQueue(device_wrapper->handle, queue_family_index, queue_index, &queue);
    }

    if (queue != VK_NULL_HANDLE)
    {
        // Because this queue was not allocated through the loader, it must be assigned a dispatch table.
        *reinterpret_cast<void**>(queue) = *reinterpret_cast<void**>(device_wrapper->handle);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to retrieve a queue for resource memory snapshot");
    }

    return queue;
}

VkCommandPool VulkanStateWriter::GetCommandPool(const DeviceWrapper* device_wrapper, uint32_t queue_family_index)
{
    assert(device_wrapper != nullptr);

    VkCommandPool command_pool = VK_NULL_HANDLE;

    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    create_info.pNext                   = nullptr;
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = queue_family_index;

    VkResult result =
        device_wrapper->layer_table.CreateCommandPool(device_wrapper->handle, &create_info, nullptr, &command_pool);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("Failed to create a command pool for resource memory snapshot");
    }

    return command_pool;
}

VkCommandBuffer VulkanStateWriter::GetCommandBuffer(const DeviceWrapper* device_wrapper, VkCommandPool command_pool)
{
    assert(device_wrapper != nullptr);

    VkCommandBuffer command_buffer = VK_NULL_HANDLE;

    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.pNext                       = nullptr;
    alloc_info.commandPool                 = command_pool;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;

    VkResult result =
        device_wrapper->layer_table.AllocateCommandBuffers(device_wrapper->handle, &alloc_info, &command_buffer);

    if (result == VK_SUCCESS)
    {
        // Because this command buffer was not allocated through the loader, it must be assigned a dispatch
        // table.
        *reinterpret_cast<void**>(command_buffer) = *reinterpret_cast<void**>(device_wrapper->handle);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create a command buffer for resource memory snapshot");
    }

    return command_buffer;
}

VkResult
VulkanStateWriter::SubmitCommandBuffer(VkQueue queue, VkCommandBuffer command_buffer, const DeviceTable* device_table)
{
    assert(device_table != nullptr);

    VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
    submit_info.pNext                = nullptr;
    submit_info.waitSemaphoreCount   = 0;
    submit_info.pWaitSemaphores      = nullptr;
    submit_info.pWaitDstStageMask    = nullptr;
    submit_info.commandBufferCount   = 1;
    submit_info.pCommandBuffers      = &command_buffer;
    submit_info.signalSemaphoreCount = 0;
    submit_info.pSignalSemaphores    = nullptr;

    device_table->QueueSubmit(queue, 1, &submit_info, VK_NULL_HANDLE);

    return device_table->QueueWaitIdle(queue);
}

VkResult VulkanStateWriter::CreateStagingBuffer(const DeviceWrapper*    device_wrapper,
                                                VkDeviceSize            size,
                                                VkBuffer*               buffer,
                                                VkDeviceMemory*         memory,
                                                VkMemoryPropertyFlags*  memory_property_flags,
                                                const VulkanStateTable& state_table)
{
    assert((device_wrapper != nullptr) && (buffer != nullptr) && (memory != nullptr));

    const DeviceTable* device_table = &device_wrapper->layer_table;

    VkBufferCreateInfo create_info    = { VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.size                  = size;
    create_info.usage                 = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;

    VkResult result = device_table->CreateBuffer(device_wrapper->handle, &create_info, nullptr, buffer);
    if (result == VK_SUCCESS)
    {
        uint32_t             memory_type_index = std::numeric_limits<uint32_t>::max();
        VkMemoryRequirements memory_requirements;

        device_table->GetBufferMemoryRequirements(device_wrapper->handle, (*buffer), &memory_requirements);

        bool found = FindMemoryTypeIndex(device_wrapper,
                                         memory_requirements.memoryTypeBits,
                                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT,
                                         &memory_type_index,
                                         memory_property_flags,
                                         state_table);
        if (!found)
        {
            // If we are here it is likely that we lack support for HOST_CACHED, fallback to COHERENT
            found = FindMemoryTypeIndex(device_wrapper,
                                        memory_requirements.memoryTypeBits,
                                        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                                        &memory_type_index,
                                        memory_property_flags,
                                        state_table);
        }

        if (found)
        {
            VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
            alloc_info.pNext                = nullptr;
            alloc_info.allocationSize       = memory_requirements.size;
            alloc_info.memoryTypeIndex      = memory_type_index;

            result = device_table->AllocateMemory(device_wrapper->handle, &alloc_info, nullptr, memory);
            if (result == VK_SUCCESS)
            {
                device_table->BindBufferMemory(device_wrapper->handle, (*buffer), (*memory), 0);
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to allocate staging buffer memory for resource memory snapshot");
                device_table->DestroyBuffer(device_wrapper->handle, *buffer, nullptr);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to find a memory type with host visible and host cached or coherent "
                               "properties for resource memory snapshot staging buffer creation");
            result = VK_ERROR_INITIALIZATION_FAILED;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create staging buffer for resource memory snapshot");
    }

    return result;
}

VkResult VulkanStateWriter::ResolveImage(const DeviceWrapper*    device_wrapper,
                                         const ImageWrapper*     image_wrapper,
                                         VkQueue                 queue,
                                         VkCommandBuffer         command_buffer,
                                         VkImage*                resolve_image,
                                         VkDeviceMemory*         resolve_memory,
                                         const VulkanStateTable& state_table)
{
    assert((device_wrapper != nullptr) && (image_wrapper != nullptr) && (resolve_image != nullptr) &&
           (resolve_memory != nullptr) && (image_wrapper->mip_levels == 1));

    const DeviceTable* device_table = &device_wrapper->layer_table;

    VkImage        image  = VK_NULL_HANDLE;
    VkDeviceMemory memory = VK_NULL_HANDLE;

    VkImageCreateInfo create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.imageType             = image_wrapper->image_type;
    create_info.format                = image_wrapper->format;
    create_info.extent                = image_wrapper->extent;
    create_info.mipLevels             = 1;
    create_info.arrayLayers           = image_wrapper->array_layers;
    create_info.samples               = VK_SAMPLE_COUNT_1_BIT;
    create_info.tiling                = VK_IMAGE_TILING_OPTIMAL;
    create_info.usage                 = VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    create_info.queueFamilyIndexCount = 0;
    create_info.pQueueFamilyIndices   = nullptr;
    create_info.initialLayout         = VK_IMAGE_LAYOUT_UNDEFINED;

    VkResult result = device_table->CreateImage(device_wrapper->handle, &create_info, nullptr, &image);
    if (result == VK_SUCCESS)
    {
        uint32_t             memory_type_index = std::numeric_limits<uint32_t>::max();
        VkMemoryRequirements memory_requirements;

        device_table->GetImageMemoryRequirements(device_wrapper->handle, image, &memory_requirements);

        bool found = FindMemoryTypeIndex(device_wrapper,
                                         memory_requirements.memoryTypeBits,
                                         VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                                         &memory_type_index,
                                         nullptr,
                                         state_table);

        if (found)
        {
            VkMemoryAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO };
            alloc_info.pNext                = nullptr;
            alloc_info.allocationSize       = memory_requirements.size;
            alloc_info.memoryTypeIndex      = memory_type_index;

            result = device_table->AllocateMemory(device_wrapper->handle, &alloc_info, nullptr, &memory);
            if (result == VK_SUCCESS)
            {
                device_table->BindImageMemory(device_wrapper->handle, image, memory, 0);

                VkCommandBufferBeginInfo begin_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO };
                begin_info.pNext                    = nullptr;
                begin_info.flags                    = 0;
                begin_info.pInheritanceInfo         = nullptr;

                result = device_table->BeginCommandBuffer(command_buffer, &begin_info);

                if (result == VK_SUCCESS)
                {
                    VkImageAspectFlags aspect_mask = GetFormatAspectMask(image_wrapper->format);

                    uint32_t             num_barriers = 1;
                    VkImageMemoryBarrier memory_barriers[2];

                    // Destination image
                    memory_barriers[0].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                    memory_barriers[0].pNext                           = nullptr;
                    memory_barriers[0].srcAccessMask                   = 0;
                    memory_barriers[0].dstAccessMask                   = VK_ACCESS_TRANSFER_WRITE_BIT;
                    memory_barriers[0].oldLayout                       = VK_IMAGE_LAYOUT_UNDEFINED;
                    memory_barriers[0].newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;
                    memory_barriers[0].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                    memory_barriers[0].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                    memory_barriers[0].image                           = image;
                    memory_barriers[0].subresourceRange.aspectMask     = aspect_mask;
                    memory_barriers[0].subresourceRange.baseMipLevel   = 0;
                    memory_barriers[0].subresourceRange.levelCount     = 1;
                    memory_barriers[0].subresourceRange.baseArrayLayer = 0;
                    memory_barriers[0].subresourceRange.layerCount     = image_wrapper->array_layers;

                    // Multi-sample source image
                    if (image_wrapper->current_layout != VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL)
                    {
                        num_barriers = 2;

                        memory_barriers[1].sType                           = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
                        memory_barriers[1].pNext                           = nullptr;
                        memory_barriers[1].srcAccessMask                   = 0;
                        memory_barriers[1].dstAccessMask                   = VK_ACCESS_TRANSFER_READ_BIT;
                        memory_barriers[1].oldLayout                       = image_wrapper->current_layout;
                        memory_barriers[1].newLayout                       = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                        memory_barriers[1].srcQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                        memory_barriers[1].dstQueueFamilyIndex             = VK_QUEUE_FAMILY_IGNORED;
                        memory_barriers[1].image                           = image_wrapper->handle;
                        memory_barriers[1].subresourceRange.aspectMask     = aspect_mask;
                        memory_barriers[1].subresourceRange.baseMipLevel   = 0;
                        memory_barriers[1].subresourceRange.levelCount     = 1;
                        memory_barriers[1].subresourceRange.baseArrayLayer = 0;
                        memory_barriers[1].subresourceRange.layerCount     = image_wrapper->array_layers;
                    }

                    device_table->CmdPipelineBarrier(command_buffer,
                                                     VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT,
                                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                     0,
                                                     0,
                                                     nullptr,
                                                     0,
                                                     nullptr,
                                                     num_barriers,
                                                     memory_barriers);

                    VkImageResolve region;
                    region.srcSubresource.aspectMask     = aspect_mask;
                    region.srcSubresource.mipLevel       = 0;
                    region.srcSubresource.baseArrayLayer = 0;
                    region.srcSubresource.layerCount     = image_wrapper->array_layers;
                    region.srcOffset.x                   = 0;
                    region.srcOffset.y                   = 0;
                    region.srcOffset.z                   = 0;
                    region.dstSubresource.aspectMask     = aspect_mask;
                    region.dstSubresource.mipLevel       = 0;
                    region.dstSubresource.baseArrayLayer = 0;
                    region.dstSubresource.layerCount     = image_wrapper->array_layers;
                    region.dstOffset.x                   = 0;
                    region.dstOffset.y                   = 0;
                    region.dstOffset.z                   = 0;
                    region.extent.width                  = image_wrapper->extent.width;
                    region.extent.height                 = image_wrapper->extent.height;
                    region.extent.depth                  = image_wrapper->extent.depth;

                    device_table->CmdResolveImage(command_buffer,
                                                  image_wrapper->handle,
                                                  VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                                                  image,
                                                  VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
                                                  1,
                                                  &region);

                    memory_barriers[0].srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
                    memory_barriers[0].dstAccessMask = 0;
                    memory_barriers[0].oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL;

                    // Prepare the resolved image for the next staging copy.
                    memory_barriers[0].newLayout = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;

                    if (num_barriers == 2)
                    {
                        memory_barriers[1].srcAccessMask = VK_ACCESS_TRANSFER_READ_BIT;
                        memory_barriers[1].dstAccessMask = 0;
                        memory_barriers[1].oldLayout     = VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL;
                        memory_barriers[1].newLayout     = image_wrapper->current_layout;
                    }

                    device_table->CmdPipelineBarrier(command_buffer,
                                                     VK_PIPELINE_STAGE_TRANSFER_BIT,
                                                     VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT,
                                                     0,
                                                     0,
                                                     nullptr,
                                                     0,
                                                     nullptr,
                                                     num_barriers,
                                                     memory_barriers);

                    device_table->EndCommandBuffer(command_buffer);

                    result = SubmitCommandBuffer(queue, command_buffer, device_table);

                    if (result == VK_SUCCESS)
                    {
                        (*resolve_image)  = image;
                        (*resolve_memory) = memory;
                    }
                    else
                    {
                        GFXRECON_LOG_ERROR("Failed to resolve multisample image");
                        device_table->DestroyImage(device_wrapper->handle, image, nullptr);
                        device_table->FreeMemory(device_wrapper->handle, memory, nullptr);
                    }
                }
            }
            else
            {
                GFXRECON_LOG_ERROR("Failed to allocate temporary image memory for multisample resolve");
                device_table->DestroyImage(device_wrapper->handle, image, nullptr);
            }
        }
        else
        {
            GFXRECON_LOG_ERROR(
                "Failed to find a device local memory type for multisample resolve temporary image creation");
            result = VK_ERROR_INITIALIZATION_FAILED;
            device_table->DestroyImage(device_wrapper->handle, image, nullptr);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to create temporary image for multisample resolve.");
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
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT:
            return VK_IMAGE_ASPECT_PLANE_0_BIT | VK_IMAGE_ASPECT_PLANE_1_BIT;
        default:
            return VK_IMAGE_ASPECT_COLOR_BIT;
    }
}

void VulkanStateWriter::GetFormatAspects(VkFormat                            format,
                                         std::vector<VkImageAspectFlagBits>* aspects,
                                         bool*                               combined_depth_stencil)
{
    assert((aspects != nullptr) && (combined_depth_stencil != nullptr));

    (*combined_depth_stencil) = false;

    switch (format)
    {
        case VK_FORMAT_D16_UNORM_S8_UINT:
        case VK_FORMAT_D24_UNORM_S8_UINT:
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            aspects->push_back(VK_IMAGE_ASPECT_DEPTH_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_STENCIL_BIT);
            (*combined_depth_stencil) = true;
            break;
        case VK_FORMAT_D16_UNORM:
        case VK_FORMAT_X8_D24_UNORM_PACK32:
        case VK_FORMAT_D32_SFLOAT:
            aspects->push_back(VK_IMAGE_ASPECT_DEPTH_BIT);
            break;
        case VK_FORMAT_S8_UINT:
            aspects->push_back(VK_IMAGE_ASPECT_STENCIL_BIT);
            break;
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
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_0_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_1_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_2_BIT);
            break;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT:
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT:
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_0_BIT);
            aspects->push_back(VK_IMAGE_ASPECT_PLANE_1_BIT);
            break;
        default:
            aspects->push_back(VK_IMAGE_ASPECT_COLOR_BIT);
            break;
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
        // Per-aspect/plane compatible formats as defined by the "Plane Format Compatibility Table" from the
        // Vulkan specification.
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            // All planes share the same format.
            return VK_FORMAT_R8_UNORM;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT:
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
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT:
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
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT:
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
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT:
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

void VulkanStateWriter::GetImageSizes(const ImageWrapper* image_wrapper, ImageSnapshotInfo* info)
{
    assert((image_wrapper != nullptr) && (info != nullptr));

    const DeviceWrapper* device_wrapper = image_wrapper->bind_device;
    assert(device_wrapper != nullptr);

    const DeviceTable* device_table = &device_wrapper->layer_table;

    VkImageCreateInfo create_info     = { VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO };
    create_info.pNext                 = nullptr;
    create_info.flags                 = 0;
    create_info.imageType             = image_wrapper->image_type;
    create_info.format                = GetImageAspectFormat(image_wrapper->format, info->aspect);
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
    VkResult result = device_table->CreateImage(device_wrapper->handle, &create_info, nullptr, &image);
    if (result == VK_SUCCESS)
    {
        device_table->GetImageMemoryRequirements(device_wrapper->handle, image, &memory_requirements);
        info->resource_size = memory_requirements.size;
        info->level_sizes.push_back(memory_requirements.size);
        device_table->DestroyImage(device_wrapper->handle, image, nullptr);
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to determine size of image for resource memory snapshot");
    }

    // Size of additional mip levels.
    for (uint32_t i = 1; i < image_wrapper->mip_levels; ++i)
    {
        create_info.extent.width  = std::max(1u, (image_wrapper->extent.width >> i));
        create_info.extent.height = std::max(1u, (image_wrapper->extent.height >> i));
        create_info.extent.depth  = std::max(1u, (image_wrapper->extent.depth >> i));

        result = device_table->CreateImage(device_wrapper->handle, &create_info, nullptr, &image);
        if (result == VK_SUCCESS)
        {
            device_table->GetImageMemoryRequirements(device_wrapper->handle, image, &memory_requirements);
            info->resource_size += memory_requirements.size;
            info->level_sizes.push_back(memory_requirements.size);
            device_table->DestroyImage(device_wrapper->handle, image, nullptr);
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to determine size of image for resource memory snapshot");
        }
    }
}

bool VulkanStateWriter::CheckCommandHandles(const CommandBufferWrapper* wrapper, const VulkanStateTable& state_table)
{
    // Ignore commands that reference destroyed objects.
    for (uint32_t i = 0; i < CommandHandleType::NumHandleTypes; ++i)
    {
        for (auto id : wrapper->command_handles[i])
        {
            if (!CheckCommandHandle(static_cast<CommandHandleType>(i), id, state_table))
            {
                return false;
            }
        }
    }

    return true;
}

bool VulkanStateWriter::CheckCommandHandle(CommandHandleType       handle_type,
                                           format::HandleId        handle_id,
                                           const VulkanStateTable& state_table)
{
    switch (handle_type)
    {
        case CommandHandleType::BufferHandle:
            return IsBufferValid(handle_id, state_table);
        case CommandHandleType::CommandBufferHandle:
            return (state_table.GetCommandBufferWrapper(handle_id) != nullptr);
        case CommandHandleType::DescriptorSetHandle:
            return (state_table.GetDescriptorSetWrapper(handle_id) != nullptr);
        case CommandHandleType::EventHandle:
            return (state_table.GetEventWrapper(handle_id) != nullptr);
        case CommandHandleType::FramebufferHandle:
            return IsFramebufferValid(handle_id, state_table);
        case CommandHandleType::ImageHandle:
            return IsImageValid(handle_id, state_table);
        case CommandHandleType::ImageViewHandle:
            return IsImageViewValid(handle_id, state_table);
        case CommandHandleType::PipelineHandle:
            return (state_table.GetPipelineWrapper(handle_id) != nullptr);
        case CommandHandleType::PipelineLayoutHandle:
            return (state_table.GetPipelineLayoutWrapper(handle_id) != nullptr);
        case CommandHandleType::QueryPoolHandle:
            return (state_table.GetQueryPoolWrapper(handle_id) != nullptr);
        case CommandHandleType::RenderPassHandle:
            return (state_table.GetRenderPassWrapper(handle_id) != nullptr);
        case CommandHandleType::AccelerationStructureNVHandle:
            return (state_table.GetAccelerationStructureNVWrapper(handle_id) != nullptr);
        case CommandHandleType::AccelerationStructureKHRHandle:
            return (state_table.GetAccelerationStructureKHRWrapper(handle_id) != nullptr);
        case CommandHandleType::IndirectCommandsLayoutNVHandle:
            return (state_table.GetIndirectCommandsLayoutNVWrapper(handle_id) != nullptr);
        case CommandHandleType::DeferredOperationKHRHandle:
            return (state_table.GetDeferredOperationKHRWrapper(handle_id) != nullptr);
        default:
            GFXRECON_LOG_ERROR("State write is skipping unrecognized handle type when checking handles "
                               "referenced by command buffers");
            assert(false);
            return false;
    }
}

bool VulkanStateWriter::CheckDescriptorStatus(const DescriptorInfo*   descriptor,
                                              uint32_t                index,
                                              const VulkanStateTable& state_table,
                                              VkDescriptorType*       descriptor_type)
{
    bool valid = false;

    if (descriptor->type == VK_DESCRIPTOR_TYPE_MUTABLE_VALVE)
    {
        *descriptor_type = descriptor->mutable_type[index];
    }
    else
    {
        *descriptor_type = descriptor->type;
    }

    if (descriptor->written[index])
    {
        // Check for handles that may no longer exist, which indicates that this descriptor is stale and should
        // be ignored, as there is no valid handle to write into it.
        switch (*descriptor_type)
        {
            case VK_DESCRIPTOR_TYPE_SAMPLER:
                if (state_table.GetSamplerWrapper(descriptor->sampler_ids[index]) != nullptr)
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                if ((descriptor->immutable_samplers ||
                     (state_table.GetSamplerWrapper(descriptor->sampler_ids[index]) != nullptr)) &&
                    IsImageViewValid(descriptor->handle_ids[index], state_table))
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                if (IsImageViewValid(descriptor->handle_ids[index], state_table))
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                if (IsBufferValid(descriptor->handle_ids[index], state_table))
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                if (IsBufferViewValid(descriptor->handle_ids[index], state_table))
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT:
                // TODO
                GFXRECON_LOG_WARNING("Descriptor type inline uniform block is not currently supported");
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                // TODO
                GFXRECON_LOG_WARNING("Descriptor type acceleration structure NV is not currently supported");
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                if (state_table.GetAccelerationStructureKHRWrapper(descriptor->handle_ids[index]) != nullptr)
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_MUTABLE_VALVE:
                // Mutable descriptor still in initial state
                break;
            default:
                GFXRECON_LOG_WARNING("Attempting to check descriptor write status for unrecognized descriptor type");
                break;
        }
    }

    return valid;
}

bool VulkanStateWriter::IsBufferValid(format::HandleId buffer_id, const VulkanStateTable& state_table)
{
    bool valid          = false;
    auto buffer_wrapper = state_table.GetBufferWrapper(buffer_id);

    if (buffer_wrapper != nullptr)
    {
        format::HandleId memory_id = buffer_wrapper->bind_memory_id;

        if ((memory_id == 0) || (state_table.GetDeviceMemoryWrapper(memory_id) != nullptr))
        {
            valid = true;
        }
    }

    return valid;
}

bool VulkanStateWriter::IsBufferViewValid(format::HandleId view_id, const VulkanStateTable& state_table)
{
    bool valid               = false;
    auto buffer_view_wrapper = state_table.GetBufferViewWrapper(view_id);

    if (buffer_view_wrapper != nullptr)
    {
        valid = IsBufferValid(buffer_view_wrapper->buffer_id, state_table);
    }

    return valid;
}

bool VulkanStateWriter::IsImageValid(format::HandleId image_id, const VulkanStateTable& state_table)
{
    bool valid         = false;
    auto image_wrapper = state_table.GetImageWrapper(image_id);

    if (image_wrapper != nullptr)
    {
        format::HandleId memory_id = image_wrapper->bind_memory_id;

        if ((memory_id == 0) || (state_table.GetDeviceMemoryWrapper(memory_id) != nullptr))
        {
            valid = true;
        }
    }

    return valid;
}

bool VulkanStateWriter::IsImageViewValid(format::HandleId view_id, const VulkanStateTable& state_table)
{
    bool valid              = false;
    auto image_view_wrapper = state_table.GetImageViewWrapper(view_id);

    if (image_view_wrapper != nullptr)
    {
        valid = IsImageValid(image_view_wrapper->image_id, state_table);
    }

    return valid;
}

bool VulkanStateWriter::IsFramebufferValid(format::HandleId framebuffer_id, const VulkanStateTable& state_table)
{
    bool valid               = false;
    auto framebuffer_wrapper = state_table.GetFramebufferWrapper(framebuffer_id);

    if (framebuffer_wrapper != nullptr)
    {
        valid = IsFramebufferValid(framebuffer_wrapper, state_table);
    }

    return valid;
}

bool VulkanStateWriter::IsFramebufferValid(const FramebufferWrapper* framebuffer_wrapper,
                                           const VulkanStateTable&   state_table)
{
    bool valid = true;

    for (auto view_id : framebuffer_wrapper->image_view_ids)
    {
        if (!IsImageViewValid(view_id, state_table))
        {
            valid = false;
            break;
        }
    }

    return valid;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
