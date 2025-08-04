/*
 ** Copyright (c) 2019-2025 LunarG, Inc.
 ** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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
#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_info.h"
#include "encode/vulkan_capture_common.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/logging.h"
#include "custom_vulkan_array_size_2d.h"

#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cstdint>
#include <limits>
#include <unordered_map>

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

const uint32_t kDefaultQueueFamilyIndex = 0;

static bool IsMemoryCoherent(VkMemoryPropertyFlags property_flags)
{
    return ((property_flags & VK_MEMORY_PROPERTY_HOST_COHERENT_BIT) == VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
}

static bool IsMemoryReadable(VkMemoryPropertyFlags property_flags)
{
    return ((property_flags & (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT)) ==
            (VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT));
}

static bool IsBufferReadable(VkMemoryPropertyFlags                       property_flags,
                             const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper)
{
    // If a sub-range of host visible memory is mapped, a staging copy will be used to ensure that the entire allocation
    // is accessible for read.
    return (IsMemoryReadable(property_flags) && ((memory_wrapper->mapped_data == nullptr) ||
                                                 ((memory_wrapper->mapped_offset == 0) &&
                                                  ((memory_wrapper->mapped_size == memory_wrapper->allocation_size) ||
                                                   (memory_wrapper->mapped_size == VK_WHOLE_SIZE)))));
}

static bool IsImageReadable(VkMemoryPropertyFlags                       property_flags,
                            const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper,
                            const vulkan_wrappers::ImageWrapper*        image_wrapper)
{
    // If a sub-range of host visible memory is mapped, a staging copy will be used to ensure that the entire allocation
    // is accessible for read.
    return (
        IsMemoryReadable(property_flags) && (image_wrapper->tiling == VK_IMAGE_TILING_LINEAR) &&
        ((memory_wrapper->mapped_data == nullptr) ||
         ((memory_wrapper->mapped_offset == 0) && ((memory_wrapper->mapped_size == memory_wrapper->allocation_size) ||
                                                   (memory_wrapper->mapped_size == VK_WHOLE_SIZE)))));
}

VulkanStateWriter::VulkanStateWriter(util::FileOutputStream*                  output_stream,
                                     util::Compressor*                        compressor,
                                     util::ThreadData*                        thread_data,
                                     std::function<format::HandleId()>        get_unique_id_fn,
                                     util::FileOutputStream*                  asset_file_stream,
                                     const std::string*                       asset_file_name,
                                     VulkanStateWriter::AssetFileOffsetsInfo* asset_file_offsets) :
    output_stream_(output_stream),
    compressor_(compressor), thread_data_(thread_data), encoder_(&parameter_stream_),
    get_unique_id_(std::move(get_unique_id_fn)), asset_file_stream_(asset_file_stream),
    asset_file_offsets_(asset_file_offsets), command_writer_(CommandWriter(thread_data, output_stream, compressor_))
{
    assert(output_stream != nullptr || asset_file_stream != nullptr);

    if (asset_file_name != nullptr)
    {
        asset_file_name_ = *asset_file_name;
    }
}

uint64_t VulkanStateWriter::WriteAssets(const VulkanStateTable& state_table)
{
    blocks_written_ = 0;

    WriteResourceMemoryState(state_table, false);
    WriteDescriptorSetStateWithAssetFile(state_table);

    return blocks_written_;
}

uint64_t VulkanStateWriter::WriteState(const VulkanStateTable& state_table, uint64_t frame_number)
{
    // clang-format off
    blocks_written_ = 0;

    auto started = std::chrono::high_resolution_clock::now();

    format::Marker marker;
    marker.header.size = sizeof(marker.marker_type) + sizeof(marker.frame_number);
    marker.header.type = format::kStateMarkerBlock;
    marker.marker_type = format::kBeginMarker;
    marker.frame_number = frame_number;
    output_stream_->Write(&marker, sizeof(marker));

    // For the Begin Marker meta command
    ++blocks_written_;

    // Instance, device, and queue creation.
    StandardCreateWrite<vulkan_wrappers::InstanceWrapper>(state_table);
    WritePhysicalDeviceState(state_table);
    WriteDeviceState(state_table);
    StandardCreateWrite<vulkan_wrappers::QueueWrapper>(state_table);

    // physical-device / raytracing properties
    WriteRayTracingPropertiesState(state_table);

    // Utility object creation.
    StandardCreateWrite<vulkan_wrappers::DebugReportCallbackEXTWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::DebugUtilsMessengerEXTWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::ValidationCacheEXTWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::DeferredOperationKHRWrapper>(state_table);
    WritePrivateDataSlotState(state_table);

    // Synchronization primitive creation.
    WriteFenceState(state_table);
    WriteEventState(state_table);
    WriteSemaphoreState(state_table);

    // WSI object creation.
    StandardCreateWrite<vulkan_wrappers::DisplayKHRWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::DisplayModeKHRWrapper>(state_table);
    WriteSurfaceKhrState(state_table);
    WriteSwapchainKhrState(state_table);

    // Resource creation.
    WriteBufferState(state_table);
    WriteImageState(state_table);
    WriteDeviceMemoryState(state_table);

    // Bind memory after buffer/image creation and memory allocation. The buffer/image needs to be created before memory
    // allocation for extensions like dedicated allocation that require a valid buffer/image handle at memory allocation.
    WriteResourceMemoryState(state_table, true);

    // Map memory after uploading resource data to buffers and images, which may require mapping resource memory ranges.
    WriteMappedMemoryState(state_table);

    WriteBufferViewState(state_table);

    // Sampler and image view create infos can reference a VkSamplerYcbcrConversion object (through VkSamplerYcbcrConversionInfo
    // in the pnext chain). For that reason dump VkSamplerYcbcrConversion object first.
    StandardCreateWrite<vulkan_wrappers::SamplerYcbcrConversionWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::SamplerWrapper>(state_table);

    WriteImageViewState(state_table);

    // Retrieve buffer-device-addresses
    WriteBufferDeviceAddressState(state_table);

    // Render object creation.
    StandardCreateWrite<vulkan_wrappers::RenderPassWrapper>(state_table);
    WriteFramebufferState(state_table);
    StandardCreateWrite<vulkan_wrappers::ShaderModuleWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::DescriptorSetLayoutWrapper>(state_table);
    WritePipelineLayoutState(state_table);
    WritePipelineCacheState(state_table);
    WritePipelineState(state_table);
    WriteAccelerationStructureKHRState(state_table);
    WriteTlasToBlasDependenciesMetadata(state_table);
    WriteAccelerationStructureStateMetaCommands(state_table);
    StandardCreateWrite<vulkan_wrappers::AccelerationStructureNVWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::ShaderEXTWrapper>(state_table);

    // Descriptor creation.
    StandardCreateWrite<vulkan_wrappers::DescriptorPoolWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(state_table);
    if (asset_file_stream_ != nullptr)
    {
        WriteDescriptorSetStateWithAssetFile(state_table);
    }
    else
    {
        WriteDescriptorSetState(state_table);
    }

    // Query object creation.
    WriteQueryPoolState(state_table);
    StandardCreateWrite<vulkan_wrappers::PerformanceConfigurationINTELWrapper>(state_table);

    StandardCreateWrite<vulkan_wrappers::MicromapEXTWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::OpticalFlowSessionNVWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::VideoSessionKHRWrapper>(state_table);
    StandardCreateWrite<vulkan_wrappers::VideoSessionParametersKHRWrapper>(state_table);

    // Command creation.
    StandardCreateWrite<vulkan_wrappers::CommandPoolWrapper>(state_table);
    WriteCommandBufferState(state_table);
    StandardCreateWrite<vulkan_wrappers::IndirectCommandsLayoutNVWrapper>(state_table);  // TODO: If we intend to support this, we need to reserve command space after creation.
    WriteTrimCommandPool(state_table);

    // Process swapchain image acquire.
    WriteSwapchainImageState(state_table);

    WriteDebugUtilsState(state_table);

    marker.marker_type = format::kEndMarker;
    output_stream_->Write(&marker, sizeof(marker));

    if (asset_file_stream_)
    {
        asset_file_stream_->Flush();
    }

    // For the EndMarker meta command
    ++blocks_written_;

    auto done = std::chrono::high_resolution_clock::now();
    uint32_t time = std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();
    GFXRECON_LOG_INFO("%s() saved in %u ms", __func__, time);

    return blocks_written_;
    // clang-format on
}

void VulkanStateWriter::WritePhysicalDeviceState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;

    state_table.VisitWrappers([&](const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) {
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
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceWrapper* wrapper) {
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
    std::set<util::MemoryOutputStream*>                 processed;
    std::vector<vulkan_wrappers::CommandBufferWrapper*> primary;

    // Because secondaries can reference other secondaries we need to do a first pass over all alive command buffers
    // to detect all invalid secondaries.
    state_table.VisitWrappers([&](vulkan_wrappers::CommandBufferWrapper* wrapper) {
        if (wrapper->level == VK_COMMAND_BUFFER_LEVEL_SECONDARY && !CheckCommandHandles(wrapper, state_table))
        {
            wrapper->state = vulkan_wrappers::CommandBufferWrapper::kInvalid;
        }
    });

    state_table.VisitWrappers([&](vulkan_wrappers::CommandBufferWrapper* wrapper) {
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
    state_table.VisitWrappers([&](const vulkan_wrappers::CommandPoolWrapper* wrapper) {
        assert(wrapper != nullptr);
        if (wrapper->trim_command_pool)
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeFlagsValue(0);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkTrimCommandPool, &parameter_stream_);
            parameter_stream_.Clear();
        }
    });
}

void VulkanStateWriter::WritePrivateDataSlotState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;

    state_table.VisitWrappers([&](const vulkan_wrappers::PrivateDataSlotWrapper* wrapper) {
        assert(wrapper != nullptr);
        if (processed.find(wrapper->create_parameters.get()) == processed.end())
        {
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
            processed.insert(wrapper->create_parameters.get());

            // vkSetPrivateData shouldn't affect rendering. It's not necessary to replay. But it could help as debug
            // info.
            if (wrapper->data != 0)
            {
                const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
                assert(device_wrapper != nullptr);

                encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                encoder_.EncodeEnumValue(wrapper->object_type);
                encoder_.EncodeUInt64Value(wrapper->object_handle);
                encoder_.EncodeHandleIdValue(wrapper->handle_id);
                encoder_.EncodeUInt64Value(wrapper->data);
                encoder_.EncodeEnumValue(VK_SUCCESS);

                WriteFunctionCall(format::ApiCallId::ApiCall_vkSetPrivateData, &parameter_stream_);
                parameter_stream_.Clear();
            }
        }
    });
}

void VulkanStateWriter::WriteFenceState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::FenceWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Check fence signaled state against create info signaled state.
        const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
        bool                                  signaled       = wrapper->created_signaled;

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
    state_table.VisitWrappers([&](const vulkan_wrappers::EventWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write event creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Check and set signaled state if necessary.
        const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
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
    std::unordered_map<const vulkan_wrappers::DeviceWrapper*, std::vector<format::HandleId>> signaled;

    state_table.VisitWrappers([&](const vulkan_wrappers::SemaphoreWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Write semaphore creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        if (wrapper->type == VK_SEMAPHORE_TYPE_TIMELINE)
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            // Query current semaphore value
            uint64_t          semaphore_value;
            format::ApiCallId signal_call_id;
            if (device_wrapper->physical_device->instance_info.api_version >= VK_MAKE_VERSION(1, 2, 0))
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
            const vulkan_wrappers::QueueWrapper* queue_wrapper = entry.first->child_queues.front();
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
    state_table.VisitWrappers([&](const vulkan_wrappers::BufferViewWrapper* wrapper) {
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
    state_table.VisitWrappers([&](const vulkan_wrappers::ImageViewWrapper* wrapper) {
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

    state_table.VisitWrappers([&](const vulkan_wrappers::FramebufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (IsFramebufferValid(wrapper, state_table))
        {
            auto render_pass_wrapper = state_table.GetVulkanRenderPassWrapper(wrapper->render_pass_id);
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
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineLayoutWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Check descriptor set layout dependencies.
        auto deps = wrapper->layout_dependencies;
        for (const auto& entry : deps->layouts)
        {
            auto ds_layout_wrapper = state_table.GetVulkanDescriptorSetLayoutWrapper(entry.handle_id);
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

void VulkanStateWriter::WritePipelineCacheState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineCacheWrapper* wrapper) {
        GFXRECON_ASSERT(wrapper != nullptr);

        // Pipeline cache data can be indirectly changed by pipeline creation command or directly changed by calls like
        // vkMergePipelineCaches. So here we query and write its latest state, not the state when the pipeline cache was
        // created.
        size_t   data_size;
        VkResult result = wrapper->device->layer_table.GetPipelineCacheData(
            wrapper->device->handle, wrapper->handle, &data_size, nullptr);
        GFXRECON_ASSERT(result == VK_SUCCESS);

        if (data_size != 0)
        {
            const_cast<vulkan_wrappers::PipelineCacheWrapper*>(wrapper)->cache_data.resize(data_size);

            result = wrapper->device->layer_table.GetPipelineCacheData(
                wrapper->device->handle,
                wrapper->handle,
                &data_size,
                const_cast<vulkan_wrappers::PipelineCacheWrapper*>(wrapper)->cache_data.data());

            GFXRECON_ASSERT(result == VK_SUCCESS);

            const_cast<vulkan_wrappers::PipelineCacheWrapper*>(wrapper)->create_info.initialDataSize = data_size;
            const_cast<vulkan_wrappers::PipelineCacheWrapper*>(wrapper)->create_info.pInitialData =
                wrapper->cache_data.data();
        }
        else
        {
            const_cast<vulkan_wrappers::PipelineCacheWrapper*>(wrapper)->create_info.initialDataSize = 0;
            const_cast<vulkan_wrappers::PipelineCacheWrapper*>(wrapper)->create_info.pInitialData    = nullptr;
        }

        WriteCreatePipelineCache(wrapper->device->handle_id,
                                 &wrapper->create_info,
                                 nullptr,
                                 const_cast<VkPipelineCache*>(&wrapper->handle),
                                 VK_SUCCESS);
    });
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
    std::unordered_map<format::HandleId, format::HandleId>                temp_deferred_operation_join_command;

    // First pass over pipeline table to sort pipelines by type and determine which dependencies need to be created
    // temporarily.
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineWrapper* wrapper) {
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
                auto render_pass_wrapper =
                    state_table.GetVulkanRenderPassWrapper(wrapper->render_pass_dependency.handle_id);
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

                    // If a raytracing pipeline was created with a deferred operation object, we also need to generate a
                    // deferred operation join command, so the deferred command can finish. These join commands must be
                    // after calling vkCreateRayTracingPipelinesKHR. Here we record these deferred operations and their
                    // related device id to generate the join command later.
                    temp_deferred_operation_join_command[wrapper->deferred_operation.handle_id] = wrapper->device_id;
                }
                // TODO: It shouldn't destroy VkDeferredOperation after vkCreateRayTracingPipelinesKHR because it will
                // run vkDeferredOperationJoinKHR and vkGetDeferredOperationResultKHR after
                // vkCreateRayTracingPipelinesKHR. It needs to find a good way to destroy this VkDeferredOperation.
            }
        }

        // Check for creation dependencies that no longer exist.
        for (const auto& entry : wrapper->shader_module_dependencies)
        {
            auto shader_wrapper = state_table.GetVulkanShaderModuleWrapper(entry.handle_id);
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

        if (wrapper->layout_dependency.handle_id != format::kNullHandleId)
        {
            auto layout_wrapper = state_table.GetVulkanPipelineLayoutWrapper(wrapper->layout_dependency.handle_id);
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
                        auto ds_layout_wrapper = state_table.GetVulkanDescriptorSetLayoutWrapper(entry.handle_id);
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

    for (const auto& entry : temp_deferred_operation_join_command)
    {
        WriteDeferredOperationJoinCommand(entry.second, entry.first);
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

    WriteRayTracingShaderGroupHandlesState(state_table);
}

void VulkanStateWriter::WriteRayTracingShaderGroupHandlesState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->create_call_id == format::ApiCall_vkCreateRayTracingPipelinesKHR)
        {
            auto     device_wrapper = state_table.GetVulkanDeviceWrapper(wrapper->device_id);
            uint32_t data_size      = device_wrapper->property_feature_info.property_shaderGroupHandleSize *
                                 wrapper->num_shader_group_handles;
            std::vector<uint8_t> data(data_size);

            VkResult result = device_wrapper->layer_table.GetRayTracingShaderGroupHandlesKHR(
                device_wrapper->handle, wrapper->handle, 0, wrapper->num_shader_group_handles, data_size, data.data());

            parameter_stream_.Clear();
            encoder_.EncodeHandleIdValue(wrapper->device_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeUInt32Value(0);                                 // firstGroup
            encoder_.EncodeUInt32Value(wrapper->num_shader_group_handles); // groupCount
            encoder_.EncodeSizeTValue(data_size);                          // dataSize
            encoder_.EncodeVoidArray(data.data(), data_size);              // data
            encoder_.EncodeEnumValue(result);                              // result
            WriteFunctionCall(format::ApiCall_vkGetRayTracingShaderGroupHandlesKHR, &parameter_stream_);
            parameter_stream_.Clear();
        }
    });
}

void VulkanStateWriter::WriteDescriptorSetState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;

    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_ds_layouts;

    // First pass over descriptor set table to determine which dependencies need to be created temporarily.
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorSetWrapper* wrapper) {
        assert(wrapper != nullptr);

        auto ds_layout_wrapper =
            state_table.GetVulkanDescriptorSetLayoutWrapper(wrapper->set_layout_dependency.handle_id);
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

    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorSetWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Filter duplicate calls to vkAllocateDescriptorSets for descriptor sets that were allocated by the same API
        // call and reference the same parameter buffer.
        if (processed.find(wrapper->create_parameters.get()) == processed.end())
        {
            // Write descriptor set creation call and add the parameter buffer to the processed set.
            WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
            processed.insert(wrapper->create_parameters.get());
        }

        VkWriteDescriptorSet write = { VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET };
        write.dstSet               = wrapper->handle;

        for (const auto& binding_entry : wrapper->bindings)
        {
            const vulkan_state_info::DescriptorInfo* binding = &binding_entry.second;
            bool                                     active  = false;

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

void VulkanStateWriter::WriteDescriptorSetStateWithAssetFile(const VulkanStateTable& state_table)
{
    assert(asset_file_stream_ != nullptr);

    std::set<util::MemoryOutputStream*> processed;

    std::unordered_map<format::HandleId, const util::MemoryOutputStream*> temp_ds_layouts;

    // First pass over descriptor set table to determine which dependencies need to be created temporarily.
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorSetWrapper* wrapper) {
        assert(wrapper != nullptr);

        auto ds_layout_wrapper =
            state_table.GetVulkanDescriptorSetLayoutWrapper(wrapper->set_layout_dependency.handle_id);
        if (ds_layout_wrapper == nullptr)
        {
            // The object no longer exists, so a temporary object must be created.
            auto        dep_create_parameters = wrapper->set_layout_dependency.create_parameters.get();
            const auto& dep_inserted =
                temp_ds_layouts.insert(std::make_pair(wrapper->set_layout_dependency.handle_id, dep_create_parameters));

            // Create a temporary object on first encounter.
            if (dep_inserted.second)
            {
                if (wrapper->dirty)
                {
                    const int64_t offset                       = asset_file_stream_->GetOffset();
                    (*asset_file_offsets_)[wrapper->handle_id] = offset;
                    WriteFunctionCall(
                        wrapper->set_layout_dependency.create_call_id, dep_create_parameters, asset_file_stream_);
                    if (output_stream_ != nullptr)
                    {
                        WriteExecuteFromFile(asset_file_name_, 1, offset);
                    }
                }
                else
                {
                    if (output_stream_ != nullptr)
                    {
                        assert(asset_file_offsets_->find(wrapper->handle_id) != asset_file_offsets_->end());
                        const int64_t offset = (*asset_file_offsets_)[wrapper->handle_id];
                        WriteExecuteFromFile(asset_file_name_, 1, offset);
                    }
                }

                ++blocks_written_;
            }
        }
    });

    state_table.VisitWrappers([&](vulkan_wrappers::DescriptorSetWrapper* wrapper) {
        assert(wrapper != nullptr);

        uint32_t n_blocks = 0;
        int64_t  offset;
        if (wrapper->dirty)
        {
            offset = asset_file_stream_->GetOffset();
        }
        else
        {
            assert(asset_file_offsets_->find(wrapper->handle_id) != asset_file_offsets_->end());
            offset = (*asset_file_offsets_)[wrapper->handle_id];
        }

        // Filter duplicate calls to vkAllocateDescriptorSets for descriptor sets that were allocated by the same
        // API call and reference the same parameter buffer.
        const auto new_entry = processed.insert(wrapper->create_parameters.get());
        if (new_entry.second)
        {
            if (wrapper->dirty)
            {
                // Write descriptor set creation call and add the parameter buffer to the processed set.
                WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get(), asset_file_stream_);
            }

            ++n_blocks;
        }

        VkWriteDescriptorSet write = { VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET };
        write.dstSet               = wrapper->handle;

        for (const auto& binding_entry : wrapper->bindings)
        {
            const vulkan_state_info::DescriptorInfo* binding = &binding_entry.second;
            bool                                     active  = false;

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
                        if (wrapper->dirty)
                        {
                            WriteDescriptorUpdateCommand(
                                wrapper->device->handle_id, binding, &write, asset_file_stream_);
                        }
                        ++n_blocks;
                    }
                }
                else if (active && (descriptor_type != write.descriptorType))
                {
                    // Mutable descriptor type change within an active write range
                    // End current range
                    write.descriptorCount = i - write.dstArrayElement;
                    if (wrapper->dirty)
                    {
                        WriteDescriptorUpdateCommand(wrapper->device->handle_id, binding, &write, asset_file_stream_);
                    }
                    ++n_blocks;

                    // Start new range
                    write.descriptorType  = descriptor_type;
                    write.dstArrayElement = i;
                }
            }

            // Process final range, when last item in array contained an active write.
            if (active)
            {
                write.descriptorCount = binding->count - write.dstArrayElement;

                if (wrapper->dirty)
                {
                    WriteDescriptorUpdateCommand(wrapper->device->handle_id, binding, &write, asset_file_stream_);
                }
                ++n_blocks;
            }
        }

        // Don't write when n_blocks is zero because it will be translated
        // as execute till the end of file
        if (output_stream_ != nullptr && n_blocks)
        {
            WriteExecuteFromFile(asset_file_name_, n_blocks, offset);
        }

        if (wrapper->dirty)
        {
            wrapper->dirty                             = false;
            (*asset_file_offsets_)[wrapper->handle_id] = offset;
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
    std::unordered_map<const vulkan_wrappers::DeviceWrapper*, std::vector<const vulkan_wrappers::QueryPoolWrapper*>>
                                                                                               device_query_pools;
    std::unordered_map<const vulkan_wrappers::DeviceWrapper*, QueryActivationQueueFamilyTable> device_queries;

    state_table.VisitWrappers([&](const vulkan_wrappers::QueryPoolWrapper* wrapper) {
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
    state_table.VisitWrappers([&](const vulkan_wrappers::SurfaceKHRWrapper* wrapper) {
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
            if (auto capabilities = std::get_if<vulkan_wrappers::SurfaceCapabilities>(&entry.second))
            {
                WriteResizeWindowCmd(wrapper->handle_id,
                                     capabilities->surface_capabilities.currentExtent.width,
                                     capabilities->surface_capabilities.currentExtent.height);
                WriteGetPhysicalDeviceSurfaceCapabilities(entry.first, wrapper->handle_id, *capabilities, state_table);
            }
            else if (auto capabilities2 = std::get_if<vulkan_wrappers::SurfaceCapabilities2>(&entry.second))
            {
                WriteResizeWindowCmd(wrapper->handle_id,
                                     capabilities2->surface_capabilities.surfaceCapabilities.currentExtent.width,
                                     capabilities2->surface_capabilities.surfaceCapabilities.currentExtent.height);
                WriteGetPhysicalDeviceSurfaceCapabilities2(
                    entry.first, wrapper->handle_id, *capabilities2, state_table);
            }
        }

        for (const auto& entry : wrapper->surface_formats)
        {
            if (auto formats = std::get_if<vulkan_wrappers::SurfaceFormats>(&entry.second))
            {
                WriteGetPhysicalDeviceSurfaceFormats(entry.first, wrapper->handle_id, *formats, state_table);
            }
            else if (auto formats2 = std::get_if<vulkan_wrappers::SurfaceFormats2>(&entry.second))
            {
                WriteGetPhysicalDeviceSurfaceFormats2(entry.first, wrapper->handle_id, *formats2, state_table);
            }
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
    state_table.VisitWrappers([&](const vulkan_wrappers::SwapchainKHRWrapper* wrapper) {
        assert(wrapper != nullptr);

        const vulkan_wrappers::SurfaceKHRWrapper* surface_wrapper = wrapper->surface;
        assert(surface_wrapper != nullptr);

        WriteResizeWindowCmd2(
            surface_wrapper->handle_id, wrapper->extent.width, wrapper->extent.height, wrapper->pre_transform);

        // Write swapchain creation call.
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());

        // Write the query for swapchain image count.
        uint32_t image_count = static_cast<uint32_t>(wrapper->child_images.size());

        if (image_count > 0)
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeUInt32Ptr(&image_count, false);
            auto handle_array = std::vector<format::HandleId>(wrapper->child_images.size());
            for (int i = 0; i < wrapper->child_images.size(); ++i)
            {
                handle_array[i] = wrapper->child_images[i]->handle_id;
            }
            encoder_.EncodeHandleIdArray(handle_array.data(), handle_array.size(), false);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkGetSwapchainImagesKHR, &parameter_stream_);
            parameter_stream_.Clear();
        }

        if (wrapper->acquire_full_screen_exclusive_mode)
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkAcquireFullScreenExclusiveModeEXT, &parameter_stream_);
            parameter_stream_.Clear();
        }

        if (wrapper->release_full_screen_exclusive_mode)
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkReleaseFullScreenExclusiveModeEXT, &parameter_stream_);
            parameter_stream_.Clear();
        }

        if (wrapper->using_local_dimming_AMD)
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
            assert(device_wrapper != nullptr);

            const VkResult result = VK_SUCCESS;
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeUInt32Value(wrapper->local_dimming_enable_AMD);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkSetLocalDimmingAMD, &parameter_stream_);
            parameter_stream_.Clear();
        }
    });
}

void VulkanStateWriter::WriteDeviceMemoryState(const VulkanStateTable& state_table)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    std::unordered_map<AHardwareBuffer*, const vulkan_wrappers::DeviceMemoryWrapper*> hardware_buffers;

    // Before writing the device memory allocation calls, generate a list of external memory objects to create.
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceMemoryWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->hardware_buffer != nullptr)
        {
            hardware_buffers.insert(std::make_pair(wrapper->hardware_buffer, wrapper));
        }
    });

    // Write AHB creation commands.
    for (auto hardware_buffer : hardware_buffers)
    {
        const vulkan_wrappers::DeviceMemoryWrapper* wrapper = hardware_buffer.second;
        CommonProcessHardwareBuffer(thread_data_->thread_id_,
                                    wrapper->parent_device,
                                    wrapper->hardware_buffer_memory_id,
                                    wrapper->hardware_buffer,
                                    wrapper->allocation_size,
                                    nullptr,
                                    this);

        ++blocks_written_;
    }
#endif

    // Write device memory allocation calls.
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceMemoryWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->device_id != format::kNullHandleId)
        {
            WriteSetOpaqueAddressCommand(wrapper->device_id, wrapper->handle_id, wrapper->address);
        }

        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

void VulkanStateWriter::WriteBufferDeviceAddressState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::BufferWrapper* wrapper) {
        assert(wrapper != nullptr);
        if ((wrapper->device_id != format::kNullHandleId) && (wrapper->address != 0))
        {
            auto physical_device_wrapper = wrapper->bind_device->physical_device;
            auto call_id = physical_device_wrapper->instance_info.api_version >= VK_MAKE_VERSION(1, 2, 0)
                               ? format::ApiCall_vkGetBufferDeviceAddress
                               : format::ApiCall_vkGetBufferDeviceAddressKHR;

            parameter_stream_.Clear();
            encoder_.EncodeHandleIdValue(wrapper->bind_device->handle_id);
            VkBufferDeviceAddressInfoKHR info{ VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO, nullptr, wrapper->handle };
            EncodeStructPtr(&encoder_, &info);
            encoder_.EncodeVkDeviceAddressValue(wrapper->address);
            WriteFunctionCall(call_id, &parameter_stream_);
            parameter_stream_.Clear();
        }
    });
}

void VulkanStateWriter::WriteBufferState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::BufferWrapper* wrapper) {
        assert(wrapper != nullptr);

        if ((wrapper->device_id != format::kNullHandleId) && (wrapper->opaque_address != 0))
        {
            // If the buffer has a device address, write the 'set opaque address' command before writing the API call to
            // create the buffer.  The address will need to be passed to vkCreateBuffer through the pCreateInfo pNext
            // list.
            WriteSetOpaqueAddressCommand(wrapper->device_id, wrapper->handle_id, wrapper->opaque_address);
        }

        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
    });
}

void VulkanStateWriter::WriteImageState(const VulkanStateTable& state_table)
{
    std::set<util::MemoryOutputStream*> processed;
    state_table.VisitWrappers([&](const vulkan_wrappers::ImageWrapper* image_wrapper) {
        // Skip create call for swapchain images, i.e. vkGetSwapchainImagesKHR
        // This call is already emitted by the state setup for the parent swapchain
        if (image_wrapper->is_swapchain_image)
        {
            return;
        }
        // Filter duplicate entries for calls that create multiple objects, where objects created by the same call
        // all reference the same parameter buffer.
        if (processed.find(image_wrapper->create_parameters.get()) == processed.end())
        {
            WriteFunctionCall(image_wrapper->create_call_id, image_wrapper->create_parameters.get());
            processed.insert(image_wrapper->create_parameters.get());
        }
    });
}

void VulkanStateWriter::BeginAccelerationStructuresSection(format::HandleId device_id, uint64_t max_resource_size)
{
    uint64_t max_staging_copy_size = 0;

    format::BeginResourceInitCommand begin_cmd{};
    begin_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(begin_cmd);
    begin_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    begin_cmd.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kBeginResourceInitCommand);
    begin_cmd.thread_id         = thread_data_->thread_id_;
    begin_cmd.device_id         = device_id;
    begin_cmd.max_resource_size = max_resource_size;
    // Our buffers should not need staging copy as the memory should be host visible and coherent
    begin_cmd.max_copy_size = 0;

    output_stream_->Write(&begin_cmd, sizeof(begin_cmd));
    ++blocks_written_;
}

void VulkanStateWriter::WriteASInputBufferState(ASInputBuffer& buffer)
{
    const VkAllocationCallbacks* alloc_callbacks = nullptr;
    // Issue a new create call, creating the buffer we want, and replacing data
    vulkan_wrappers::DeviceWrapper* device_wrapper = buffer.bind_device;

    VkBufferCreateInfo create_info{ VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO,
                                    nullptr,
                                    {},
                                    buffer.created_size,
                                    buffer.usage,
                                    VK_SHARING_MODE_EXCLUSIVE,
                                    1,
                                    &buffer.queue_family_index };
    device_wrapper->layer_table.CreateBuffer(device_wrapper->handle, &create_info, nullptr, &buffer.handle);

    buffer.handle_id = get_unique_id_();
    // Write down this new call
    parameter_stream_.Clear();
    encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
    EncodeStructPtr(&encoder_, &create_info);
    EncodeStructPtr(&encoder_, alloc_callbacks);
    encoder_.EncodeHandleIdPtr(&buffer.handle_id);
    encoder_.EncodeEnumValue(VK_SUCCESS);
    WriteFunctionCall(format::ApiCallId::ApiCall_vkCreateBuffer, &parameter_stream_);
}

void VulkanStateWriter::WriteASInputMemoryState(ASInputBuffer& buffer)
{
    const VkAllocationCallbacks*    alloc_callbacks = nullptr;
    vulkan_wrappers::DeviceWrapper* device_wrapper  = buffer.bind_device;

    // Write allocate memory call
    VkMemoryAllocateInfo allocate_info{ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO, nullptr };
    allocate_info.allocationSize = buffer.memory_requirements.size;

    VkMemoryAllocateFlagsInfo memory_allocate_flags_info{ VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO, nullptr };
    memory_allocate_flags_info.flags =
        VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT | VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
    allocate_info.pNext = &memory_allocate_flags_info;

    uint32_t              mem_type_index = 0;
    VkMemoryPropertyFlags desired_flags{};
    VkMemoryPropertyFlags found_flags{};
    graphics::FindMemoryTypeIndex(buffer.bind_device->physical_device->memory_properties,
                                  buffer.memory_requirements.memoryTypeBits,
                                  desired_flags,
                                  &mem_type_index,
                                  &found_flags);
    allocate_info.memoryTypeIndex = mem_type_index;
    buffer.bind_memory            = get_unique_id_();

    device_wrapper->layer_table.AllocateMemory(
        device_wrapper->handle, &allocate_info, alloc_callbacks, &buffer.bind_memory_handle);
    device_wrapper->layer_table.BindBufferMemory(device_wrapper->handle, buffer.handle, buffer.bind_memory_handle, 0);

    VkBufferDeviceAddressInfoKHR           buffer_address_info{ VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_KHR,
                                                      nullptr,
                                                      buffer.handle };
    VkDeviceMemoryOpaqueCaptureAddressInfo memory_opaque_address_info{
        VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO, nullptr, buffer.bind_memory_handle
    };

    uint64_t address = 0;
    if (device_wrapper->physical_device->instance_info.api_version >= VK_MAKE_VERSION(1, 2, 0))
    {
        buffer.actual_address =
            device_wrapper->layer_table.GetBufferDeviceAddress(device_wrapper->handle, &buffer_address_info);
        address = device_wrapper->layer_table.GetDeviceMemoryOpaqueCaptureAddress(device_wrapper->handle,
                                                                                  &memory_opaque_address_info);
    }
    else
    {
        buffer.actual_address =
            device_wrapper->layer_table.GetBufferDeviceAddressKHR(device_wrapper->handle, &buffer_address_info);
        address = device_wrapper->layer_table.GetDeviceMemoryOpaqueCaptureAddressKHR(device_wrapper->handle,
                                                                                     &memory_opaque_address_info);
    }

    WriteSetOpaqueAddressCommand(device_wrapper->handle_id, buffer.bind_memory, address);

    parameter_stream_.Clear();
    encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
    EncodeStructPtr(&encoder_, &allocate_info);
    EncodeStructPtr(&encoder_, alloc_callbacks);
    encoder_.EncodeHandleIdPtr(&buffer.bind_memory);
    encoder_.EncodeEnumValue(VK_SUCCESS);
    WriteFunctionCall(format::ApiCallId::ApiCall_vkAllocateMemory, &parameter_stream_);
    parameter_stream_.Clear();

    encoder_.EncodeHandleIdValue(buffer.bind_device->handle_id);
    encoder_.EncodeHandleIdValue(buffer.handle_id);
    encoder_.EncodeHandleIdValue(buffer.bind_memory);
    encoder_.EncodeUInt64Value(0);
    encoder_.EncodeEnumValue(VK_SUCCESS);
    WriteFunctionCall(format::ApiCall_vkBindBufferMemory, &parameter_stream_);
    parameter_stream_.Clear();

    // Manual encoding because tmp objects are not in the state table
    encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
    encoder_.EncodeStructPtrPreamble(&buffer_address_info);
    encoder_.EncodeEnumValue(buffer_address_info.sType);
    EncodePNextStruct(&encoder_, buffer_address_info.pNext);
    encoder_.EncodeHandleIdValue(buffer.handle_id);
    encoder_.EncodeVkDeviceAddressValue(buffer.actual_address);
    auto call_id = device_wrapper->physical_device->instance_info.api_version >= VK_MAKE_VERSION(1, 2, 0)
                       ? format::ApiCall_vkGetBufferDeviceAddress
                       : format::ApiCall_vkGetBufferDeviceAddressKHR;
    WriteFunctionCall(call_id, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::InitializeASInputBuffer(ASInputBuffer& buffer)
{
    parameter_stream_.Clear();

    format::HandleId device_id = buffer.bind_device->handle_id;

    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, buffer.created_size);

    auto                            data_size = static_cast<size_t>(buffer.created_size);
    format::InitBufferCommandHeader upload_cmd{};

    upload_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    upload_cmd.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kInitBufferCommand);
    upload_cmd.thread_id = thread_data_->thread_id_;
    upload_cmd.device_id = device_id;
    upload_cmd.buffer_id = buffer.handle_id;
    upload_cmd.data_size = data_size;

    const uint8_t* bytes = buffer.bytes.data();
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
    ++blocks_written_;
}

void VulkanStateWriter::WriteDestroyASInputBuffer(ASInputBuffer& buffer)
{
    const VkAllocationCallbacks*    callbacks      = nullptr;
    vulkan_wrappers::DeviceWrapper* device_wrapper = buffer.bind_device;

    parameter_stream_.Clear();

    encoder_.EncodeHandleIdValue(buffer.bind_device->handle_id);
    encoder_.EncodeHandleIdValue(buffer.handle_id);
    EncodeStructPtr(&encoder_, callbacks);
    WriteFunctionCall(format::ApiCall_vkDestroyBuffer, &parameter_stream_);
    device_wrapper->layer_table.DestroyBuffer(device_wrapper->handle, buffer.handle, callbacks);

    parameter_stream_.Clear();

    encoder_.EncodeHandleIdValue(buffer.bind_device->handle_id);
    encoder_.EncodeHandleIdValue(buffer.bind_memory);
    EncodeStructPtr(&encoder_, callbacks);
    WriteFunctionCall(format::ApiCall_vkFreeMemory, &parameter_stream_);
    device_wrapper->layer_table.FreeMemory(device_wrapper->handle, buffer.bind_memory_handle, callbacks);

    parameter_stream_.Clear();
}

void VulkanStateWriter::EndAccelerationStructureSection(format::HandleId device_id)
{
    format::EndResourceInitCommand end_cmd{};
    end_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(end_cmd);
    end_cmd.meta_header.block_header.type = format::kMetaDataBlock;
    end_cmd.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kEndResourceInitCommand);
    end_cmd.thread_id = thread_data_->thread_id_;
    end_cmd.device_id = device_id;

    output_stream_->Write(&end_cmd, sizeof(end_cmd));
    ++blocks_written_;
}

void VulkanStateWriter::WriteTlasToBlasDependenciesMetadata(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::AccelerationStructureKHRWrapper* tlas) {
        assert(tlas != nullptr);

        if (!tlas->blas.empty())
        {
            format::ParentToChildDependencyHeader tlas_to_blas{};

            const size_t blas_count                    = tlas->blas.size();
            tlas_to_blas.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
            tlas_to_blas.meta_header.block_header.size =
                format::GetMetaDataBlockBaseSize(tlas_to_blas) + blas_count * sizeof(format::HandleId);
            tlas_to_blas.meta_header.meta_data_id = format::MakeMetaDataId(
                format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kParentToChildDependency);
            tlas_to_blas.thread_id       = thread_data_->thread_id_;
            tlas_to_blas.dependency_type = format::ParentToChildDependencyType::kAccelerationStructuresDependency;
            tlas_to_blas.parent_id       = tlas->handle_id;
            tlas_to_blas.child_count     = static_cast<uint32_t>(blas_count);

            output_stream_->Write(&tlas_to_blas, sizeof(tlas_to_blas));

            for (const auto& blas : tlas->blas)
            {
                output_stream_->Write(&blas->handle_id, sizeof(format::HandleId));
            }

            ++blocks_written_;
        }
    });
}

void VulkanStateWriter::WriteAccelerationStructureStateMetaCommands(const VulkanStateTable& state_table)
{
    struct AccelerationStructureCommands
    {
        std::vector<AccelerationStructureBuildCommandData*>          blas_build;
        std::vector<AccelerationStructureBuildCommandData*>          tlas_build;
        std::vector<AccelerationStructureWritePropertiesCommandData> write_properties;
        std::vector<VkCopyAccelerationStructureInfoKHR>              copy_infos;
    };

    std::unordered_map<format::HandleId, AccelerationStructureCommands> commands;
    size_t                                                              max_resource_size = 0;

    state_table.VisitWrappers([&](vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) {
        assert(wrapper != nullptr);

        auto& per_device_container                                            = commands[wrapper->device->handle_id];
        std::vector<AccelerationStructureBuildCommandData*>* build_container  = nullptr;

        if (wrapper->type == VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR)
        {
            build_container  = &per_device_container.blas_build;
        }
        else if (wrapper->type == VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR)
        {
            build_container  = &per_device_container.tlas_build;
        }

        if (wrapper->latest_build_command_)
        {
            build_container->push_back(&wrapper->latest_build_command_.value());
            for (const auto& [handle_id, buffer] : wrapper->latest_build_command_->input_buffers)
            {
                max_resource_size = std::max(max_resource_size, buffer.bytes.size());
            }
        }

        if (wrapper->latest_copy_command_)
        {
            // filter out stale handles
            auto get_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>;
            if (get_id(wrapper->latest_copy_command_->info.src, false) != 0 &&
                get_id(wrapper->latest_copy_command_->info.dst, false) != 0)
            {
                per_device_container.copy_infos.push_back(wrapper->latest_copy_command_.value().info);
            }
        }

        if (wrapper->latest_write_properties_command_)
        {
            per_device_container.write_properties.push_back(
                { wrapper->latest_write_properties_command_->query_type, wrapper->handle_id });
        }
    });

    for (auto& [device, command] : commands)
    {
        BeginAccelerationStructuresSection(device, max_resource_size);

        for (auto& blas_build : command.blas_build)
        {
            WriteAccelerationStructureBuildState(device, *blas_build);
        }

        for (const auto& cmd_properties : command.write_properties)
        {
            EncodeAccelerationStructureWritePropertiesCommand(device, cmd_properties);
        }

        EncodeAccelerationStructuresCopyMetaCommand(device, command.copy_infos);

        for (auto& tlas_build : command.tlas_build)
        {
            WriteAccelerationStructureBuildState(device, *tlas_build);
        }

        EndAccelerationStructureSection(device);
    }
}

void VulkanStateWriter::WriteAccelerationStructureBuildState(const gfxrecon::format::HandleId&      device,
                                                             AccelerationStructureBuildCommandData& command)
{
    for (auto& [handle_id, buffer] : command.input_buffers)
    {
        if (buffer.destroyed)
        {
            WriteASInputBufferState(buffer);
            WriteASInputMemoryState(buffer);
            InitializeASInputBuffer(buffer);
        }
    }

    UpdateAddresses(command);
    EncodeAccelerationStructureBuildMetaCommand(device, command);
    for (auto& [handle_id, buffer] : command.input_buffers)
    {
        if (buffer.destroyed)
        {
            WriteDestroyASInputBuffer(buffer);
        }
    }
}

void VulkanStateWriter::UpdateAddresses(AccelerationStructureBuildCommandData& command)
{
    if (command.input_buffers.empty())
    {
        return;
    }

    std::unordered_map<VkDeviceAddress, VkDeviceAddress*> addresses_to_replace;
    auto insert_address = [&addresses_to_replace](const VkDeviceAddress& address) {
        addresses_to_replace[address] = const_cast<VkDeviceAddress*>(&address);
    };

    for (uint32_t g = 0; g < command.geometry_info.geometryCount; ++g)
    {
        auto geometry = command.geometry_info.pGeometries != nullptr ? command.geometry_info.pGeometries + g
                                                                     : command.geometry_info.ppGeometries[g];

        switch (geometry->geometryType)
        {
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_TRIANGLES_KHR:
            {
                insert_address(geometry->geometry.triangles.vertexData.deviceAddress);
                insert_address(geometry->geometry.triangles.indexData.deviceAddress);
                insert_address(geometry->geometry.triangles.transformData.deviceAddress);
                break;
            }
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_AABBS_KHR:
            {
                insert_address(geometry->geometry.aabbs.data.deviceAddress);
                break;
            }
            case VkGeometryTypeKHR::VK_GEOMETRY_TYPE_INSTANCES_KHR:
            {
                insert_address(geometry->geometry.instances.data.deviceAddress);
                break;
            }
            case VK_GEOMETRY_TYPE_SPHERES_NV:
            case VK_GEOMETRY_TYPE_LINEAR_SWEPT_SPHERES_NV:
                GFXRECON_LOG_WARNING("Geometry type not supported at " __FILE__ ", line: %d.", __LINE__);
                break;
            case VK_GEOMETRY_TYPE_MAX_ENUM_KHR:
                break;
        }
    }

    for (const auto& [handle_id, buffer] : command.input_buffers)
    {
        if (buffer.destroyed)
        {
            auto it = addresses_to_replace.find(buffer.capture_address);
            if (it != addresses_to_replace.end())
            {
                VkDeviceAddress* address = it->second;
                *address                 = buffer.actual_address;
            }
        }
    }
}

void VulkanStateWriter::EncodeAccelerationStructureBuildMetaCommand(
    format::HandleId device_id, const AccelerationStructureBuildCommandData& command)
{
    using RangeInfoArraySize = encode::ArraySize2D<VkCommandBuffer,
                                                   uint32_t,
                                                   const VkAccelerationStructureBuildGeometryInfoKHR*,
                                                   const VkAccelerationStructureBuildRangeInfoKHR* const*>;

    parameter_stream_.Clear();

    format::VulkanMetaBuildAccelerationStructuresHeader header{};
    header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    header.meta_header.block_header.size = GetMetaDataBlockBaseSize(header);
    header.meta_header.meta_data_id      = format::MakeMetaDataId(
        format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kVulkanBuildAccelerationStructuresCommand);

    encoder_.EncodeHandleIdValue(device_id);

    EncodeStructArray(&encoder_, &command.geometry_info, 1);

    const VkAccelerationStructureBuildRangeInfoKHR* ptr = command.build_range_infos.data();
    EncodeStructArray2D(&encoder_, &ptr, RangeInfoArraySize(VK_NULL_HANDLE, 1, &command.geometry_info, &ptr));

    header.meta_header.block_header.size += parameter_stream_.GetDataSize();
    output_stream_->Write(&header, sizeof(header));
    output_stream_->Write(parameter_stream_.GetData(), parameter_stream_.GetDataSize());
    parameter_stream_.Clear();

    ++blocks_written_;
}

void VulkanStateWriter::EncodeAccelerationStructuresCopyMetaCommand(
    format::HandleId device_id, const std::vector<VkCopyAccelerationStructureInfoKHR>& infos)
{
    parameter_stream_.Clear();

    format::VulkanCopyAccelerationStructuresCommandHeader header{};
    header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    header.meta_header.block_header.size = GetMetaDataBlockBaseSize(header);
    header.meta_header.meta_data_id      = format::MakeMetaDataId(
        format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kVulkanCopyAccelerationStructuresCommand);

    encoder_.EncodeHandleIdValue(device_id);
    EncodeStructArray(&encoder_, infos.data(), infos.size());
    header.meta_header.block_header.size += parameter_stream_.GetDataSize();

    output_stream_->Write(&header, sizeof(header));
    output_stream_->Write(parameter_stream_.GetData(), parameter_stream_.GetDataSize());
    parameter_stream_.Clear();
    ++blocks_written_;
}

void VulkanStateWriter::EncodeAccelerationStructureWritePropertiesCommand(
    format::HandleId device_id, const AccelerationStructureWritePropertiesCommandData& command)
{
    parameter_stream_.Clear();

    format::VulkanWriteAccelerationStructuresPropertiesCommandHeader header{};

    header.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
    header.meta_header.block_header.size = GetMetaDataBlockBaseSize(header);
    header.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan,
                               format::MetaDataType::kVulkanWriteAccelerationStructuresPropertiesCommand);

    encoder_.EncodeHandleIdValue(device_id);
    encoder_.EncodeEnumValue(command.query_type);
    encoder_.EncodeHandleIdValue(command.acceleration_structure);

    header.meta_header.block_header.size += parameter_stream_.GetDataSize();

    output_stream_->Write(&header, sizeof(header));
    output_stream_->Write(parameter_stream_.GetData(), parameter_stream_.GetDataSize());

    parameter_stream_.Clear();

    ++blocks_written_;
}

void VulkanStateWriter::WriteGetAccelerationStructureDeviceAddressKHRCall(
    const VulkanStateTable& state_table, const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper)
{
    parameter_stream_.Clear();
    auto device_wrapper = wrapper->device;
    encoder_.EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device_wrapper->handle);
    VkAccelerationStructureDeviceAddressInfoKHR info{ VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR,
                                                      nullptr,
                                                      wrapper->handle };

    EncodeStructPtr(&encoder_, &info);
    encoder_.EncodeVkDeviceAddressValue(vulkan_wrappers::GetDeviceTable(device_wrapper->handle)
                                            ->GetAccelerationStructureDeviceAddressKHR(device_wrapper->handle, &info));
    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetAccelerationStructureDeviceAddressKHR, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteRayTracingPropertiesState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->ray_tracing_pipeline_properties != std::nullopt)
        {
            parameter_stream_.Clear();
            encoder_.EncodeHandleIdValue(wrapper->handle_id);

            // pNext-chaining
            auto pipeline_props  = *wrapper->ray_tracing_pipeline_properties;
            pipeline_props.pNext = wrapper->acceleration_structure_properties
                                       ? (void*)&wrapper->acceleration_structure_properties.value()
                                       : nullptr;

            VkPhysicalDeviceProperties2 properties2 = {};
            properties2.sType                       = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
            properties2.pNext                       = &pipeline_props;

            EncodeStructPtr(&encoder_, &properties2);
            WriteFunctionCall(format::ApiCall_vkGetPhysicalDeviceProperties2, &parameter_stream_);
            parameter_stream_.Clear();
        }
    });
}

void VulkanStateWriter::WriteAccelerationStructureKHRState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) {
        assert(wrapper != nullptr);

        if ((wrapper->device != nullptr) && (wrapper->address != 0))
        {
            // If the acceleration struct has a device address, write the 'set opaque address' command before writing
            // the API call to create the acceleration struct.  The address will need to be passed to
            // vkCreateAccelerationStructKHR through the VkAccelerationStructureCreateInfoKHR::deviceAddress.
            WriteSetOpaqueAddressCommand(wrapper->device->handle_id, wrapper->handle_id, wrapper->address);
        }
        WriteFunctionCall(wrapper->create_call_id, wrapper->create_parameters.get());
        WriteGetAccelerationStructureDeviceAddressKHRCall(state_table, wrapper);
    });
}

void VulkanStateWriter::WriteDeferredOperationJoinCommand(format::HandleId device_id,
                                                          format::HandleId deferred_operation_id)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(device_id);
    encoder_.EncodeHandleIdValue(deferred_operation_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkDeferredOperationJoinKHR, &parameter_stream_);
    parameter_stream_.Clear();
}

bool VulkanStateWriter::OutputStreamWrite(const void* data, size_t len)
{
    return output_stream_->Write(data, len);
}

void VulkanStateWriter::ProcessBufferMemory(const vulkan_wrappers::DeviceWrapper*  device_wrapper,
                                            const std::vector<BufferSnapshotInfo>& buffer_snapshot_infos,
                                            graphics::VulkanResourcesUtil&         resource_util)
{
    GFXRECON_ASSERT(device_wrapper != nullptr);
    using BufferResource = graphics::VulkanResourcesUtil::BufferResource;

    const graphics::VulkanDeviceTable* device_table = &device_wrapper->layer_table;

    std::vector<BufferResource> buffer_resources;
    buffer_resources.reserve(buffer_snapshot_infos.size());

    auto write_init_buffer_cmd = [this, device_wrapper](const BufferResource& buf, const void* data) {
        if (data != nullptr)
        {

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, buf.size);
            auto*                           bytes     = reinterpret_cast<const uint8_t*>(data);
            auto                            data_size = static_cast<size_t>(buf.size);
            format::InitBufferCommandHeader upload_cmd{};

            upload_cmd.meta_header.block_header.type = format::kMetaDataBlock;
            upload_cmd.meta_header.meta_data_id =
                format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kInitBufferCommand);
            upload_cmd.thread_id = thread_data_->thread_id_;
            upload_cmd.device_id = device_wrapper->handle_id;
            upload_cmd.buffer_id = buf.handle_id;
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
            ++blocks_written_;
        }
        else
        {
            GFXRECON_LOG_ERROR("Trimming state snapshot failed to retrieve memory content for buffer %" PRIu64,
                               buf.handle_id);
        }
    };

    size_t num_staging_bytes = 0;

    for (const auto& snapshot_entry : buffer_snapshot_infos)
    {
        const vulkan_wrappers::BufferWrapper*       buffer_wrapper = snapshot_entry.buffer_wrapper;
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper = snapshot_entry.memory_wrapper;
        GFXRECON_ASSERT(buffer_wrapper != nullptr);

        BufferResource buffer_resource;
        buffer_resource.handle_id          = buffer_wrapper->handle_id;
        buffer_resource.buffer             = buffer_wrapper->handle;
        buffer_resource.size               = buffer_wrapper->size;
        buffer_resource.offset             = 0;
        buffer_resource.queue_family_index = buffer_wrapper->queue_family_index;

        if (snapshot_entry.need_staging_copy)
        {
            buffer_resources.push_back(buffer_resource);
            num_staging_bytes += buffer_resource.size;
        }
        else
        {
            GFXRECON_ASSERT(memory_wrapper != nullptr);
            GFXRECON_ASSERT((memory_wrapper->mapped_data == nullptr) || (memory_wrapper->mapped_offset == 0));
            const uint8_t* bytes  = nullptr;
            VkResult       result = VK_SUCCESS;

            if (memory_wrapper->mapped_data == nullptr)
            {
                void* map_ptr = nullptr;
                result        = device_table->MapMemory(device_wrapper->handle,
                                                 memory_wrapper->handle,
                                                 buffer_wrapper->bind_offset,
                                                 buffer_wrapper->size,
                                                 0,
                                                 &map_ptr);

                if (result == VK_SUCCESS)
                {
                    bytes = reinterpret_cast<const uint8_t*>(map_ptr);
                }
            }
            else
            {
                bytes = reinterpret_cast<const uint8_t*>(memory_wrapper->mapped_data) + buffer_wrapper->bind_offset;
            }

            if ((result == VK_SUCCESS) && !IsMemoryCoherent(snapshot_entry.memory_properties))
            {
                InvalidateMappedMemoryRange(
                    device_wrapper, memory_wrapper->handle, buffer_wrapper->bind_offset, buffer_wrapper->size);
            }

            write_init_buffer_cmd(buffer_resource, bytes);

            if (memory_wrapper->mapped_data == nullptr)
            {
                device_table->UnmapMemory(device_wrapper->handle, memory_wrapper->handle);
            }
        }
    }

    // batch process buffer-downloads requiring staging, use <128MB staging-mem
    size_t staging_buffer_size = std::min<size_t>(128U << 20U, num_staging_bytes);
    resource_util.ReadBufferResources(buffer_resources, write_init_buffer_cmd, staging_buffer_size);
}

void VulkanStateWriter::ProcessBufferMemoryWithAssetFile(const vulkan_wrappers::DeviceWrapper*  device_wrapper,
                                                         const std::vector<BufferSnapshotInfo>& buffer_snapshot_infos,
                                                         graphics::VulkanResourcesUtil&         resource_util)
{
    GFXRECON_ASSERT(device_wrapper != nullptr);
    GFXRECON_ASSERT(asset_file_stream_ != nullptr);

    const graphics::VulkanDeviceTable* device_table = &device_wrapper->layer_table;

    using BufferResource = graphics::VulkanResourcesUtil::BufferResource;
    std::vector<BufferResource> buffer_resources;
    buffer_resources.reserve(buffer_snapshot_infos.size());

    auto write_init_buffer_cmd = [this, device_wrapper](const BufferResource& buffer_resource, const void* data) {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, buffer_resource.size);

        size_t                          data_size = static_cast<size_t>(buffer_resource.size);
        format::InitBufferCommandHeader upload_cmd;
        auto*                           bytes = reinterpret_cast<const uint8_t*>(data);

        upload_cmd.meta_header.block_header.type = format::kMetaDataBlock;
        upload_cmd.meta_header.meta_data_id =
            format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kInitBufferCommand);
        upload_cmd.thread_id = thread_data_->thread_id_;
        upload_cmd.device_id = device_wrapper->handle_id;
        upload_cmd.buffer_id = buffer_resource.handle_id;
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

        const int64_t offset = asset_file_stream_->GetOffset();
        asset_file_stream_->Write(&upload_cmd, sizeof(upload_cmd));
        asset_file_stream_->Write(bytes, data_size);
        (*asset_file_offsets_)[buffer_resource.handle_id] = offset;

        if (output_stream_ != nullptr)
        {
            WriteExecuteFromFile(asset_file_name_, 1, offset);
        }
    };

    size_t num_staging_bytes = 0;

    for (const auto& snapshot_entry : buffer_snapshot_infos)
    {
        vulkan_wrappers::BufferWrapper*             buffer_wrapper = snapshot_entry.buffer_wrapper;
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper = snapshot_entry.memory_wrapper;
        GFXRECON_ASSERT(buffer_wrapper != nullptr);

        if (buffer_wrapper->dirty)
        {
            GFXRECON_ASSERT(memory_wrapper != nullptr);
            buffer_wrapper->dirty = false;

            BufferResource buffer_resource;
            buffer_resource.handle_id          = buffer_wrapper->handle_id;
            buffer_resource.buffer             = buffer_wrapper->handle;
            buffer_resource.size               = buffer_wrapper->size;
            buffer_resource.offset             = 0;
            buffer_resource.queue_family_index = buffer_wrapper->queue_family_index;

            if (snapshot_entry.need_staging_copy)
            {
                buffer_resources.push_back(buffer_resource);
                num_staging_bytes += buffer_resource.size;
            }
            else
            {
                GFXRECON_ASSERT((memory_wrapper->mapped_data == nullptr) || (memory_wrapper->mapped_offset == 0));
                VkResult       result = VK_SUCCESS;
                const uint8_t* bytes  = nullptr;

                if (memory_wrapper->mapped_data == nullptr)
                {
                    void* map_ptr = nullptr;
                    result        = device_table->MapMemory(device_wrapper->handle,
                                                     memory_wrapper->handle,
                                                     buffer_wrapper->bind_offset,
                                                     buffer_wrapper->size,
                                                     0,
                                                     &map_ptr);

                    if (result == VK_SUCCESS)
                    {
                        bytes = reinterpret_cast<const uint8_t*>(map_ptr);
                    }
                }
                else
                {
                    bytes = reinterpret_cast<const uint8_t*>(memory_wrapper->mapped_data) + buffer_wrapper->bind_offset;
                }

                if ((result == VK_SUCCESS) && !IsMemoryCoherent(snapshot_entry.memory_properties))
                {
                    InvalidateMappedMemoryRange(
                        device_wrapper, memory_wrapper->handle, buffer_wrapper->bind_offset, buffer_wrapper->size);
                }

                GFXRECON_ASSERT(bytes);
                if (bytes != nullptr)
                {
                    write_init_buffer_cmd(buffer_resource, bytes);
                }
                else
                {
                    GFXRECON_LOG_ERROR("Trimming state snapshot failed to retrieve memory content for buffer %" PRIu64,
                                       buffer_wrapper->handle_id);
                }

                if (!snapshot_entry.need_staging_copy && memory_wrapper->mapped_data == nullptr)
                {
                    device_table->UnmapMemory(device_wrapper->handle, memory_wrapper->handle);
                }
            }
        }
        else
        {
            if (output_stream_ != nullptr)
            {
                assert(asset_file_offsets_->find(buffer_wrapper->handle_id) != asset_file_offsets_->end());
                const int64_t offset = (*asset_file_offsets_)[buffer_wrapper->handle_id];
                WriteExecuteFromFile(asset_file_name_, 1, offset);
            }
        }
    }

    // batch process buffer-downloads requiring staging, use <128MB staging-mem
    size_t staging_buffer_size = std::min<size_t>(128U << 20U, num_staging_bytes);
    resource_util.ReadBufferResources(buffer_resources, write_init_buffer_cmd, staging_buffer_size);
}

void VulkanStateWriter::ProcessImageMemory(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                                           const std::vector<ImageSnapshotInfo>& image_snapshot_infos,
                                           graphics::VulkanResourcesUtil&        resource_util)
{
    using ImageResource = graphics::VulkanResourcesUtil::ImageResource;
    GFXRECON_ASSERT(device_wrapper != nullptr);

    const graphics::VulkanDeviceTable* device_table = &device_wrapper->layer_table;

    std::vector<ImageResource> image_resources;
    image_resources.reserve(image_snapshot_infos.size());

    auto write_init_image_cmd = [this, device_wrapper](const ImageResource& img, const void* data, size_t num_bytes) {
        if (data != nullptr)
        {
            command_writer_.WriteInitImageCmd(format::ApiFamilyId::ApiFamily_Vulkan,
                                              device_wrapper->handle_id,
                                              img.handle_id,
                                              img.aspect,
                                              img.layout,
                                              img.level_count,
                                              *img.level_sizes,
                                              num_bytes,
                                              data);
            ++blocks_written_;
        }
    };

    size_t num_staging_bytes = 0;

    for (const auto& snapshot_entry : image_snapshot_infos)
    {
        const vulkan_wrappers::ImageWrapper*        image_wrapper  = snapshot_entry.image_wrapper;
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper = snapshot_entry.memory_wrapper;
        const uint8_t*                              bytes          = nullptr;
        std::vector<uint8_t>                        data;

        GFXRECON_ASSERT(
            (image_wrapper != nullptr) &&
            (((image_wrapper->is_swapchain_image || image_wrapper->is_sparse_image) && memory_wrapper == nullptr) ||
             ((!image_wrapper->is_swapchain_image && !image_wrapper->is_sparse_image) && memory_wrapper != nullptr)));

        GFXRECON_ASSERT(snapshot_entry.resource_size > 0);

        ImageResource image_resource        = {};
        image_resource.handle_id            = image_wrapper->handle_id;
        image_resource.image                = image_wrapper->handle;
        image_resource.format               = image_wrapper->format;
        image_resource.type                 = image_wrapper->image_type;
        image_resource.extent               = image_wrapper->extent;
        image_resource.level_count          = image_wrapper->mip_levels;
        image_resource.layer_count          = image_wrapper->array_layers;
        image_resource.tiling               = image_wrapper->tiling;
        image_resource.sample_count         = image_wrapper->samples;
        image_resource.layout               = image_wrapper->current_layout;
        image_resource.queue_family_index   = image_wrapper->queue_family_index;
        image_resource.external_format      = image_wrapper->external_format;
        image_resource.size                 = image_wrapper->size;
        image_resource.resource_size        = snapshot_entry.resource_size;
        image_resource.level_sizes          = &snapshot_entry.level_sizes;
        image_resource.aspect               = snapshot_entry.aspect;
        image_resource.all_layers_per_level = true;

        if (image_wrapper->external_memory_android)
        {
            // No need to process this image memory as its corresponding AHB is processed instead
            continue;
        }

        if (snapshot_entry.need_staging_copy)
        {
            image_resources.emplace_back(image_resource);
            num_staging_bytes += image_resource.resource_size;
        }
        else if (!image_wrapper->is_swapchain_image && !image_wrapper->is_sparse_image)
        {
            assert((memory_wrapper != nullptr) &&
                   ((memory_wrapper->mapped_data == nullptr) || (memory_wrapper->mapped_offset == 0)));

            VkResult result = VK_SUCCESS;

            if (memory_wrapper->mapped_data == nullptr)
            {
                void* map_ptr = nullptr;
                result        = device_table->MapMemory(device_wrapper->handle,
                                                 memory_wrapper->handle,
                                                 image_wrapper->bind_offset,
                                                 snapshot_entry.resource_size,
                                                 0,
                                                 &map_ptr);

                if (result == VK_SUCCESS)
                {
                    bytes = reinterpret_cast<const uint8_t*>(map_ptr);
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

            write_init_image_cmd(image_resource, bytes, snapshot_entry.resource_size);

            if (memory_wrapper->mapped_data == nullptr)
            {
                device_table->UnmapMemory(device_wrapper->handle, memory_wrapper->handle);
            }
        }
    }

    // batch process buffer-downloads requiring staging, use <128MB staging-mem
    size_t staging_buffer_size = std::min<size_t>(128U << 20U, num_staging_bytes);
    resource_util.ReadImageResources(image_resources, write_init_image_cmd, staging_buffer_size);
}

void VulkanStateWriter::ProcessImageMemoryWithAssetFile(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                                                        const std::vector<ImageSnapshotInfo>& image_snapshot_infos,
                                                        graphics::VulkanResourcesUtil&        resource_util)
{
    GFXRECON_ASSERT(device_wrapper != nullptr);
    GFXRECON_ASSERT(asset_file_stream_ != nullptr);
    const graphics::VulkanDeviceTable* device_table = &device_wrapper->layer_table;

    using ImageResource = graphics::VulkanResourcesUtil::ImageResource;
    std::vector<ImageResource> image_resources;
    image_resources.reserve(image_snapshot_infos.size());

    auto write_init_image_cmd = [this, device_wrapper](const ImageResource& img, const void* data, size_t num_bytes) {
        format::InitImageCommandHeader upload_cmd;

        // Packet size without the resource data.
        upload_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(upload_cmd);
        upload_cmd.meta_header.block_header.type = format::kMetaDataBlock;
        upload_cmd.meta_header.meta_data_id =
            format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kInitImageCommand);
        upload_cmd.thread_id = thread_data_->thread_id_;
        upload_cmd.device_id = device_wrapper->handle_id;
        upload_cmd.image_id  = img.handle_id;
        upload_cmd.aspect    = img.aspect;
        upload_cmd.layout    = img.layout;

        if (data != nullptr)
        {
            auto* bytes = reinterpret_cast<const uint8_t*>(data);
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, img.resource_size);

            auto data_size = static_cast<size_t>(num_bytes);

            // Store uncompressed data size in packet.
            upload_cmd.data_size   = data_size;
            upload_cmd.level_count = img.level_count;

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
            GFXRECON_ASSERT(img.level_sizes != nullptr && !img.level_sizes->empty() &&
                            (img.level_sizes->size() == upload_cmd.level_count));
            size_t levels_size = img.level_sizes->size() * sizeof(img.level_sizes->front());

            upload_cmd.meta_header.block_header.size += levels_size + data_size;

            const int64_t offset                  = asset_file_stream_->GetOffset();
            (*asset_file_offsets_)[img.handle_id] = offset;
            asset_file_stream_->Write(&upload_cmd, sizeof(upload_cmd));
            asset_file_stream_->Write(img.level_sizes->data(), levels_size);
            asset_file_stream_->Write(bytes, data_size);

            if (output_stream_ != nullptr)
            {
                WriteExecuteFromFile(asset_file_name_, 1, offset);
            }
        }
        else
        {
            if (output_stream_ != nullptr)
            {
                // Write a packet without resource data; replay must still perform a layout transition at image
                // initialization.
                upload_cmd.data_size   = 0;
                upload_cmd.level_count = 0;

                output_stream_->Write(&upload_cmd, sizeof(upload_cmd));
                ++blocks_written_;
            }
        }
    };

    for (const auto& snapshot_entry : image_snapshot_infos)
    {
        vulkan_wrappers::ImageWrapper*              image_wrapper  = snapshot_entry.image_wrapper;
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper = snapshot_entry.memory_wrapper;
        const uint8_t*                              bytes          = nullptr;

        GFXRECON_ASSERT(image_wrapper != nullptr);

        if (image_wrapper->external_memory_android)
        {
            // No need to process this image memory as its corresponding AHB is processed instead
            continue;
        }

        if (image_wrapper->dirty)
        {
            GFXRECON_ASSERT((image_wrapper->is_swapchain_image && memory_wrapper == nullptr) ||
                            (!image_wrapper->is_swapchain_image && memory_wrapper != nullptr));

            image_wrapper->dirty = false;

            graphics::VulkanResourcesUtil::ImageResource image_resource = {};
            image_resource.handle_id                                    = image_wrapper->handle_id;
            image_resource.image                                        = image_wrapper->handle;
            image_resource.format                                       = image_wrapper->format;
            image_resource.type                                         = image_wrapper->image_type;
            image_resource.extent                                       = image_wrapper->extent;
            image_resource.level_count                                  = image_wrapper->mip_levels;
            image_resource.layer_count                                  = image_wrapper->array_layers;
            image_resource.tiling                                       = image_wrapper->tiling;
            image_resource.sample_count                                 = image_wrapper->samples;
            image_resource.layout                                       = image_wrapper->current_layout;
            image_resource.queue_family_index                           = image_wrapper->queue_family_index;
            image_resource.external_format                              = image_wrapper->external_format;
            image_resource.size                                         = image_wrapper->size;
            image_resource.resource_size                                = snapshot_entry.resource_size;
            image_resource.level_sizes                                  = &snapshot_entry.level_sizes;
            image_resource.aspect                                       = snapshot_entry.aspect;
            image_resource.external_format                              = image_wrapper->external_format;
            image_resource.all_layers_per_level                         = true;

            if (snapshot_entry.need_staging_copy)
            {
                image_resources.push_back(image_resource);
            }
            else if (!image_wrapper->is_swapchain_image)
            {
                GFXRECON_ASSERT((memory_wrapper != nullptr) &&
                                ((memory_wrapper->mapped_data == nullptr) || (memory_wrapper->mapped_offset == 0)));

                VkResult result = VK_SUCCESS;

                if (memory_wrapper->mapped_data == nullptr)
                {
                    void* map_ptr = nullptr;
                    result        = device_table->MapMemory(device_wrapper->handle,
                                                     memory_wrapper->handle,
                                                     image_wrapper->bind_offset,
                                                     snapshot_entry.resource_size,
                                                     0,
                                                     &map_ptr);

                    if (result == VK_SUCCESS)
                    {
                        bytes = reinterpret_cast<const uint8_t*>(map_ptr);
                    }
                }
                else
                {
                    bytes = reinterpret_cast<const uint8_t*>(memory_wrapper->mapped_data) + image_wrapper->bind_offset;
                }

                if ((result == VK_SUCCESS) && !IsMemoryCoherent(snapshot_entry.memory_properties))
                {
                    InvalidateMappedMemoryRange(device_wrapper,
                                                memory_wrapper->handle,
                                                image_wrapper->bind_offset,
                                                snapshot_entry.resource_size);
                }

                write_init_image_cmd(image_resource, bytes, snapshot_entry.resource_size);

                if (memory_wrapper->mapped_data == nullptr)
                {
                    device_table->UnmapMemory(device_wrapper->handle, memory_wrapper->handle);
                }
            }
        }
        else
        {
            if (output_stream_ != nullptr)
            {
                // It is possible that an image could not be dumped in the asset file (i.e. multisampled).
                // We will still clear its flag to false but there won't be an entry in the offsets map
                const auto& asset_file_offset_entry = asset_file_offsets_->find(image_wrapper->handle_id);
                if (asset_file_offset_entry != asset_file_offsets_->end())
                {
                    const int64_t offset = asset_file_offset_entry->second;
                    WriteExecuteFromFile(asset_file_name_, 1, offset);
                }
            }
        }
    }

    // batch process image-downloads requiring staging, use <128MB staging-mem
    constexpr uint32_t staging_buffer_size = 128U << 20U;
    resource_util.ReadImageResources(image_resources, write_init_image_cmd, staging_buffer_size);
}

void VulkanStateWriter::WriteBufferMemoryState(const VulkanStateTable& state_table,
                                               DeviceResourceTables*   resources,
                                               VkDeviceSize*           max_resource_size,
                                               VkDeviceSize*           max_staging_copy_size,
                                               bool                    write_memory_state)
{
    GFXRECON_ASSERT((resources != nullptr) && (max_resource_size != nullptr) && (max_staging_copy_size != nullptr));

    state_table.VisitWrappers([&](vulkan_wrappers::BufferWrapper* wrapper) {
        GFXRECON_ASSERT(wrapper != nullptr);
        if (!wrapper->is_sparse_buffer)
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->bind_device;
            assert(device_wrapper != nullptr);
            // Perform memory binding for non-sparse buffer.
            const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper =
                state_table.GetVulkanDeviceMemoryWrapper(wrapper->bind_memory_id);

            if (memory_wrapper != nullptr)
            {
                if (write_memory_state)
                {
                    // Write memory requirements query before bind command.
                    VkMemoryRequirements               memory_requirements;
                    const graphics::VulkanDeviceTable* device_table = &device_wrapper->layer_table;
                    assert(device_table != nullptr);

                    device_table->GetBufferMemoryRequirements(
                        device_wrapper->handle, wrapper->handle, &memory_requirements);

                    encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                    encoder_.EncodeHandleIdValue(wrapper->handle_id);
                    EncodeStructPtr(&encoder_, &memory_requirements);

                    WriteFunctionCall(format::ApiCall_vkGetBufferMemoryRequirements, &parameter_stream_);
                    parameter_stream_.Clear();

                    // Write memory bind command.
                    if (wrapper->bind_pnext == nullptr)
                    {
                        encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                        encoder_.EncodeHandleIdValue(wrapper->handle_id);
                        encoder_.EncodeHandleIdValue(memory_wrapper->handle_id);
                        encoder_.EncodeUInt64Value(wrapper->bind_offset);
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
                    parameter_stream_.Clear();
                }

                // Group buffers with memory bindings by device for memory snapshot.
                ResourceSnapshotQueueFamilyTable& snapshot_table = (*resources)[device_wrapper];
                ResourceSnapshotInfo&             snapshot_entry = snapshot_table[wrapper->queue_family_index];

                BufferSnapshotInfo snapshot_info;
                snapshot_info.buffer_wrapper    = wrapper;
                snapshot_info.memory_wrapper    = memory_wrapper;
                snapshot_info.memory_properties = GetMemoryProperties(device_wrapper, memory_wrapper);
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
        }
        else
        {
            // Perform memory binding for sparse buffer.
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->bind_device;
            const graphics::VulkanDeviceTable*    device_table   = &device_wrapper->layer_table;
            GFXRECON_ASSERT((device_wrapper != nullptr) && (device_table != nullptr));

            if (write_memory_state)
            {
                // We do not need to use sparse_resource_mutex for the access to the following sparse resource maps, as
                // the writing states operation is included in the trim start handling, which is protected by an
                // exclusive lock. No other API capturing handling occurs concurrently.
                if (wrapper->sparse_memory_bind_map.size() != 0)
                {
                    std::vector<VkSparseMemoryBind> sparse_memory_binds;
                    VkSparseBufferMemoryBindInfo    buffer_memory_bind_info = {};

                    // Write memory requirements query before vkQueueBindSparse command. For sparse buffer, the
                    // alignment of VkMemoryRequirements is the sparse block size in bytes which represents both the
                    // memory alignment requirement and the binding granularity (in bytes) for sparse buffer.
                    VkMemoryRequirements memory_requirements;

                    device_table->GetBufferMemoryRequirements(
                        device_wrapper->handle, wrapper->handle, &memory_requirements);

                    encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                    encoder_.EncodeHandleIdValue(wrapper->handle_id);
                    EncodeStructPtr(&encoder_, &memory_requirements);

                    WriteFunctionCall(format::ApiCall_vkGetBufferMemoryRequirements, &parameter_stream_);
                    parameter_stream_.Clear();

                    const vulkan_wrappers::QueueWrapper* sparse_bind_queue_wrapper =
                        vulkan_wrappers::GetWrapper<vulkan_wrappers::QueueWrapper>(wrapper->sparse_bind_queue);

                    if ((wrapper->sparse_bind_queue != VK_NULL_HANDLE) && (sparse_bind_queue_wrapper != nullptr))
                    {
                        for (auto& item : wrapper->sparse_memory_bind_map)
                        {
                            sparse_memory_binds.push_back(item.second);
                        }

                        buffer_memory_bind_info.buffer    = wrapper->handle;
                        buffer_memory_bind_info.bindCount = sparse_memory_binds.size();
                        buffer_memory_bind_info.pBinds    = sparse_memory_binds.data();

                        VkBindSparseInfo bind_sparse_info{};
                        bind_sparse_info.sType                = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
                        bind_sparse_info.pNext                = nullptr;
                        bind_sparse_info.waitSemaphoreCount   = 0;
                        bind_sparse_info.pWaitSemaphores      = nullptr;
                        bind_sparse_info.bufferBindCount      = 1;
                        bind_sparse_info.pBufferBinds         = &buffer_memory_bind_info;
                        bind_sparse_info.imageOpaqueBindCount = 0;
                        bind_sparse_info.pImageOpaqueBinds    = nullptr;
                        bind_sparse_info.imageBindCount       = 0;
                        bind_sparse_info.pImageBinds          = nullptr;
                        bind_sparse_info.signalSemaphoreCount = 0;
                        bind_sparse_info.pSignalSemaphores    = nullptr;

                        encoder_.EncodeVulkanHandleValue<vulkan_wrappers::QueueWrapper>(wrapper->sparse_bind_queue);
                        encoder_.EncodeUInt32Value(1);
                        EncodeStructArray(&encoder_, &bind_sparse_info, 1);
                        encoder_.EncodeVulkanHandleValue<vulkan_wrappers::FenceWrapper>(VK_NULL_HANDLE);
                        encoder_.EncodeEnumValue(VK_SUCCESS);
                        WriteFunctionCall(format::ApiCall_vkQueueBindSparse, &parameter_stream_);

                        parameter_stream_.Clear();

                        encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                        encoder_.EncodeEnumValue(VK_SUCCESS);

                        WriteFunctionCall(format::ApiCall_vkDeviceWaitIdle, &parameter_stream_);
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING(
                            "Unable to generate vkQueueBindSparse for the sparse buffer (id = %d) due to "
                            "the related sparse bind queue or its wrapper is invalid.",
                            wrapper->handle_id);
                    }
                }
                parameter_stream_.Clear();
            }

            // Group buffers with memory bindings by device for memory snapshot.
            ResourceSnapshotQueueFamilyTable& snapshot_table = (*resources)[device_wrapper];
            ResourceSnapshotInfo&             snapshot_entry = snapshot_table[wrapper->queue_family_index];

            BufferSnapshotInfo snapshot_info;
            snapshot_info.buffer_wrapper = wrapper;
            snapshot_info.memory_wrapper = nullptr;

            // We enforce the memory properties to be `VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT`, and we set
            // `need_staging_copy` to true for sparse buffers. When dumping buffer data, there are two distinct code
            // paths: one involves a staging copy, while the other requires mapping host-visible memory. This latter
            // method requires the buffer to be bound to a single range of a single memory, which is not applicable for
            // sparse buffers. Therefore, we set the two values to use staging copy for dumping sparse buffers.
            snapshot_info.memory_properties = VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;
            snapshot_info.need_staging_copy = true; // Staging copy is needed for sparse buffer.

            if ((*max_resource_size) < wrapper->size)
            {
                (*max_resource_size) = wrapper->size;
            }

            if (snapshot_info.need_staging_copy && ((*max_staging_copy_size) < wrapper->size))
            {
                (*max_staging_copy_size) = wrapper->size;
            }

            snapshot_entry.buffers.emplace_back(snapshot_info);
        }
    });
}

void VulkanStateWriter::WriteImageMemoryState(const VulkanStateTable& state_table,
                                              DeviceResourceTables*   resources,
                                              VkDeviceSize*           max_resource_size,
                                              VkDeviceSize*           max_staging_copy_size,
                                              bool                    write_memory_state)
{
    assert((resources != nullptr) && (max_resource_size != nullptr) && (max_staging_copy_size != nullptr));

    state_table.VisitWrappers([&](vulkan_wrappers::ImageWrapper* wrapper) {
        assert(wrapper != nullptr);

        // Perform memory binding.
        const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper =
            state_table.GetVulkanDeviceMemoryWrapper(wrapper->bind_memory_id);

        if ((wrapper->is_swapchain_image && memory_wrapper == nullptr && wrapper->bind_device != nullptr) ||
            (!wrapper->is_swapchain_image && memory_wrapper != nullptr) ||
            (!wrapper->is_swapchain_image && wrapper->is_sparse_image && wrapper->bind_device != nullptr))
        {
            const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->bind_device;
            assert(device_wrapper != nullptr);

            // Write memory requirements query before bind command.
            if (write_memory_state)
            {
                VkMemoryRequirements               memory_requirements;
                const graphics::VulkanDeviceTable* device_table = &device_wrapper->layer_table;
                assert(device_table != nullptr);

                device_table->GetImageMemoryRequirements(device_wrapper->handle, wrapper->handle, &memory_requirements);

                encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                encoder_.EncodeHandleIdValue(wrapper->handle_id);
                EncodeStructPtr(&encoder_, &memory_requirements);

                WriteFunctionCall(format::ApiCall_vkGetImageMemoryRequirements, &parameter_stream_);
                parameter_stream_.Clear();

                // Write memory bind command.
                if (!wrapper->is_sparse_image)
                {
                    if (wrapper->bind_pnext == nullptr)
                    {
                        encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                        encoder_.EncodeHandleIdValue(wrapper->handle_id);
                        encoder_.EncodeHandleIdValue(memory_wrapper->handle_id);
                        encoder_.EncodeUInt64Value(wrapper->bind_offset);
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
                }
                else
                {
                    const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->bind_device;
                    const graphics::VulkanDeviceTable*    device_table   = &device_wrapper->layer_table;
                    assert((device_wrapper != nullptr) && (device_table != nullptr));

                    const vulkan_wrappers::QueueWrapper* sparse_bind_queue_wrapper =
                        vulkan_wrappers::GetWrapper<vulkan_wrappers::QueueWrapper>(wrapper->sparse_bind_queue);

                    GFXRECON_ASSERT((wrapper->sparse_bind_queue != VK_NULL_HANDLE) &&
                                    (sparse_bind_queue_wrapper != nullptr));

                    if ((wrapper->sparse_opaque_memory_bind_map.size() != 0) ||
                        (wrapper->sparse_subresource_memory_bind_map.size() != 0))
                    {
                        std::vector<VkSparseMemoryBind>   sparse_memory_binds;
                        VkSparseImageOpaqueMemoryBindInfo image_opaque_memory_bind_info = {};

                        for (auto& item : wrapper->sparse_opaque_memory_bind_map)
                        {
                            sparse_memory_binds.push_back(item.second);
                        }

                        image_opaque_memory_bind_info.image     = wrapper->handle;
                        image_opaque_memory_bind_info.bindCount = sparse_memory_binds.size();
                        image_opaque_memory_bind_info.pBinds =
                            (sparse_memory_binds.size() == 0) ? nullptr : sparse_memory_binds.data();

                        std::vector<VkSparseImageMemoryBind> sparse_image_memory_binds;
                        VkSparseImageMemoryBindInfo          image_memory_bind_info = {};

                        for (auto& subresource_bind_map : wrapper->sparse_subresource_memory_bind_map)
                        {
                            auto& offset_3d_to_memory_range_map = subresource_bind_map.second;

                            for (auto& item : offset_3d_to_memory_range_map)
                            {
                                sparse_image_memory_binds.push_back(item.second);
                            }
                        }

                        image_memory_bind_info.image     = wrapper->handle;
                        image_memory_bind_info.bindCount = sparse_image_memory_binds.size();
                        image_memory_bind_info.pBinds =
                            (sparse_image_memory_binds.size() == 0) ? nullptr : sparse_image_memory_binds.data();

                        VkBindSparseInfo bind_sparse_info{};

                        bind_sparse_info.sType                = VK_STRUCTURE_TYPE_BIND_SPARSE_INFO;
                        bind_sparse_info.pNext                = nullptr;
                        bind_sparse_info.waitSemaphoreCount   = 0;
                        bind_sparse_info.pWaitSemaphores      = nullptr;
                        bind_sparse_info.bufferBindCount      = 0;
                        bind_sparse_info.pBufferBinds         = nullptr;
                        bind_sparse_info.imageOpaqueBindCount = (image_opaque_memory_bind_info.bindCount == 0) ? 0 : 1;
                        bind_sparse_info.pImageOpaqueBinds =
                            (image_opaque_memory_bind_info.bindCount == 0) ? nullptr : &image_opaque_memory_bind_info;
                        bind_sparse_info.imageBindCount = (image_memory_bind_info.bindCount == 0) ? 0 : 1;
                        bind_sparse_info.pImageBinds =
                            (image_memory_bind_info.bindCount == 0) ? nullptr : &image_memory_bind_info;
                        bind_sparse_info.signalSemaphoreCount = 0;
                        bind_sparse_info.pSignalSemaphores    = nullptr;

                        encoder_.EncodeVulkanHandleValue<vulkan_wrappers::QueueWrapper>(wrapper->sparse_bind_queue);
                        encoder_.EncodeUInt32Value(1);
                        EncodeStructArray(&encoder_, &bind_sparse_info, 1);
                        encoder_.EncodeVulkanHandleValue<vulkan_wrappers::FenceWrapper>(VK_NULL_HANDLE);
                        encoder_.EncodeEnumValue(VK_SUCCESS);
                        WriteFunctionCall(format::ApiCall_vkQueueBindSparse, &parameter_stream_);

                        parameter_stream_.Clear();

                        encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
                        encoder_.EncodeEnumValue(VK_SUCCESS);

                        WriteFunctionCall(format::ApiCall_vkDeviceWaitIdle, &parameter_stream_);
                    }
                }
                parameter_stream_.Clear();
            }

            VkMemoryPropertyFlags memory_properties = 0;
            if (memory_wrapper != nullptr)
            {
                memory_properties = GetMemoryProperties(device_wrapper, memory_wrapper);
            }

            bool is_transitioned = (wrapper->current_layout != VK_IMAGE_LAYOUT_UNDEFINED) &&
                                   (wrapper->current_layout != VK_IMAGE_LAYOUT_PREINITIALIZED);
            bool is_writable =
                (wrapper->tiling == VK_IMAGE_TILING_LINEAR) &&
                ((memory_properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);

            if (wrapper->is_sparse_image)
            {
                // The process for dumping host-visible image data requires binding the entire image to a single memory
                // range. Since this is not applicable to sparse images, we set is_writable to false.
                is_writable = false;
            }

            // If an image is not host writable and has not been transitioned from the undefined or preinitialized
            // layouts, no data could have been loaded into it and its data will be omitted from the state snapshot.
            if (is_transitioned || is_writable)
            {
                // Group images with memory bindings by device for memory snapshot.
                ResourceSnapshotQueueFamilyTable& snapshot_table = (*resources)[device_wrapper];
                ResourceSnapshotInfo&             snapshot_entry = snapshot_table[wrapper->queue_family_index];
                graphics::VulkanResourcesUtil     resource_util(device_wrapper->handle,
                                                            device_wrapper->physical_device->handle,
                                                            device_wrapper->layer_table,
                                                            *device_wrapper->physical_device->layer_table_ref,
                                                            device_wrapper->physical_device->memory_properties);

                // Sparse images require staging copy for the following process because dumping image data with mapping
                // memory needs binding the entire image to a single memory range. Sparse image opaque binding allows
                // binding to multiple memory objects and various memory ranges.
                bool need_staging_copy =
                    !IsImageReadable(memory_properties, memory_wrapper, wrapper) || wrapper->is_sparse_image;

                std::vector<VkImageAspectFlagBits> aspects;
                bool                               combined_depth_stencil;
                graphics::GetFormatAspects(wrapper->format, &aspects, &combined_depth_stencil);

                for (auto aspect : aspects)
                {
                    ImageSnapshotInfo snapshot_info;

                    snapshot_info.image_wrapper     = wrapper;
                    snapshot_info.memory_wrapper    = memory_wrapper;
                    snapshot_info.memory_properties = memory_properties;
                    snapshot_info.need_staging_copy = need_staging_copy;
                    snapshot_info.aspect            = aspect;

                    if (wrapper->external_format || wrapper->external_memory_android)
                    {
                        // The original external format is not restored at replay time, but RGBA8 is used, meaning the
                        // image size at replay might be different than current size.
                        const VkDeviceSize rgba8_size  = 4;
                        const VkDeviceSize replay_size = wrapper->extent.width * wrapper->extent.height * rgba8_size;
                        *max_staging_copy_size         = std::max(*max_staging_copy_size, replay_size);

                        snapshot_info.resource_size = wrapper->size;
                        snapshot_info.level_sizes.push_back(wrapper->size);
                    }
                    else
                    {
                        snapshot_info.resource_size =
                            resource_util.GetImageResourceSizesOptimal(wrapper->format,
                                                                       wrapper->image_type,
                                                                       wrapper->extent,
                                                                       wrapper->mip_levels,
                                                                       wrapper->array_layers,
                                                                       wrapper->tiling,
                                                                       aspect,
                                                                       nullptr,
                                                                       &snapshot_info.level_sizes,
                                                                       true);
                    }

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
                    if (is_writable && write_memory_state)
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
                                aspect_flags = graphics::GetFormatAspectMask(wrapper->format);
                                WriteImageSubresourceLayouts(wrapper, aspect_flags);
                            }
                        }
                    }
                }
            }
        }
    });
}

void VulkanStateWriter::WriteImageSubresourceLayouts(const vulkan_wrappers::ImageWrapper* image_wrapper,
                                                     VkImageAspectFlags                   aspect_flags)
{
    assert((image_wrapper != nullptr) && (aspect_flags != 0));

    const vulkan_wrappers::DeviceWrapper* device_wrapper = image_wrapper->bind_device;
    const graphics::VulkanDeviceTable*    device_table   = &device_wrapper->layer_table;

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
            parameter_stream_.Clear();
        }
    }
}

void VulkanStateWriter::WriteResourceMemoryState(const VulkanStateTable& state_table, bool write_memory_state)
{
    DeviceResourceTables resources;
    VkDeviceSize         max_resource_size     = 0;
    VkDeviceSize         max_staging_copy_size = 0;

    auto started = std::chrono::high_resolution_clock::now();

    WriteBufferMemoryState(state_table, &resources, &max_resource_size, &max_staging_copy_size, write_memory_state);
    WriteImageMemoryState(state_table, &resources, &max_resource_size, &max_staging_copy_size, write_memory_state);

    // Write resource memory content.
    for (const auto& resource_entry : resources)
    {
        const vulkan_wrappers::DeviceWrapper* device_wrapper = resource_entry.first;
        VkResult                              result         = VK_SUCCESS;

        graphics::VulkanResourcesUtil resource_util(device_wrapper->handle,
                                                    device_wrapper->physical_device->handle,
                                                    device_wrapper->layer_table,
                                                    *device_wrapper->physical_device->layer_table_ref,
                                                    device_wrapper->physical_device->memory_properties);

        if (max_staging_copy_size > 0)
        {
            assert(device_wrapper != nullptr);

            result = resource_util.CreateStagingBuffer(max_staging_copy_size);
        }

        if (result == VK_SUCCESS)
        {
            if (output_stream_ != nullptr)
            {
                format::BeginResourceInitCommand begin_cmd;
                begin_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(begin_cmd);
                begin_cmd.meta_header.block_header.type = format::kMetaDataBlock;
                begin_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
                    format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kBeginResourceInitCommand);
                begin_cmd.thread_id         = thread_data_->thread_id_;
                begin_cmd.device_id         = device_wrapper->handle_id;
                begin_cmd.max_resource_size = max_resource_size;
                begin_cmd.max_copy_size     = max_staging_copy_size;

                output_stream_->Write(&begin_cmd, sizeof(begin_cmd));
                ++blocks_written_;
            }

            for (const auto& queue_family_entry : resource_entry.second)
            {
                if (asset_file_stream_ != nullptr)
                {
                    ProcessBufferMemoryWithAssetFile(device_wrapper, queue_family_entry.second.buffers, resource_util);
                    ProcessImageMemoryWithAssetFile(device_wrapper, queue_family_entry.second.images, resource_util);
                }
                else
                {
                    ProcessBufferMemory(device_wrapper, queue_family_entry.second.buffers, resource_util);
                    ProcessImageMemory(device_wrapper, queue_family_entry.second.images, resource_util);
                }
            }

            if (output_stream_ != nullptr)
            {
                format::EndResourceInitCommand end_cmd;
                end_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(end_cmd);
                end_cmd.meta_header.block_header.type = format::kMetaDataBlock;
                end_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
                    format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kEndResourceInitCommand);
                end_cmd.thread_id = thread_data_->thread_id_;
                end_cmd.device_id = device_wrapper->handle_id;

                output_stream_->Write(&end_cmd, sizeof(end_cmd));
                ++blocks_written_;
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to create a staging buffer to process trim state");
        }
    }

    auto     done = std::chrono::high_resolution_clock::now();
    uint32_t time = std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count();

    GFXRECON_LOG_INFO("%s()  saved in %u ms", __func__, time)
}

void VulkanStateWriter::WriteMappedMemoryState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceMemoryWrapper* wrapper) {
        assert(wrapper != nullptr);

        if (wrapper->mapped_data != nullptr)
        {
            const VkResult result         = VK_SUCCESS;
            const auto     device_wrapper = wrapper->parent_device;

            // Map the replay memory.
            encoder_.EncodeHandleIdValue(device_wrapper->handle_id);
            encoder_.EncodeHandleIdValue(wrapper->handle_id);
            encoder_.EncodeUInt64Value(wrapper->mapped_offset);
            encoder_.EncodeUInt64Value(wrapper->mapped_size);
            encoder_.EncodeFlagsValue(wrapper->mapped_flags);
            encoder_.EncodeVoidPtrPtr(&wrapper->mapped_data);
            encoder_.EncodeEnumValue(result);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkMapMemory, &parameter_stream_);
            parameter_stream_.Clear();
        }
    });
}

void VulkanStateWriter::WriteSwapchainImageState(const VulkanStateTable& state_table)
{
    state_table.VisitWrappers([&](const vulkan_wrappers::SwapchainKHRWrapper* wrapper) {
        assert(wrapper != nullptr && wrapper->device != nullptr);

        const vulkan_wrappers::DeviceWrapper* device_wrapper = wrapper->device;
        size_t image_count = wrapper->child_images.size() > wrapper->image_acquired_info.size()
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
        header.thread_id                = thread_data_->thread_id_;
        header.device_id                = device_wrapper->handle_id;
        header.swapchain_id             = wrapper->handle_id;
        header.last_presented_image     = wrapper->last_presented_image;
        header.image_info_count         = static_cast<uint32_t>(image_count);

        output_stream_->Write(&header, sizeof(header));
        ++blocks_written_;

        for (size_t i = 0; i < image_count; ++i)
        {
            vulkan_wrappers::ImageWrapper* image_wrapper = wrapper->child_images[i];

            info.image_index  = static_cast<uint32_t>(i);
            info.image_id     = image_wrapper->handle_id;
            info.image_layout = image_wrapper->current_layout;

            if (wrapper->image_acquired_info[i].last_presented_queue != VK_NULL_HANDLE)
            {
                auto queue_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::QueueWrapper>(
                    wrapper->image_acquired_info[i].last_presented_queue);
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
                const vulkan_wrappers::SemaphoreWrapper* semaphore_wrapper =
                    state_table.GetVulkanSemaphoreWrapper(wrapper->image_acquired_info[i].acquired_semaphore_id);
                if (semaphore_wrapper != nullptr)
                {
                    info.acquire_semaphore_id = wrapper->image_acquired_info[i].acquired_semaphore_id;
                }
                else
                {
                    info.acquire_semaphore_id = 0;
                }

                const vulkan_wrappers::FenceWrapper* fence_wrapper =
                    state_table.GetVulkanFenceWrapper(wrapper->image_acquired_info[i].acquired_fence_id);
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

void VulkanStateWriter::WritePhysicalDevicePropertiesMetaData(
    const vulkan_wrappers::PhysicalDeviceWrapper* physical_device_wrapper)
{
    // Write the meta-data commands to set physical device properties.
    const graphics::VulkanInstanceTable* instance_table = physical_device_wrapper->layer_table_ref;
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
    parameter_stream_.Clear();

    // Then write the call with the data.
    encoder_.EncodeHandleIdValue(physical_device_id);
    encoder_.EncodeUInt32Ptr(&property_count);
    EncodeStructArray(&encoder_, properties, property_count);

    WriteFunctionCall(call_id, &parameter_stream_);
    parameter_stream_.Clear();
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
    encoder_.EncodeUInt32Ptr(&supported);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceSupportKHR, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfaceCapabilities(
    format::HandleId                            physical_device_id,
    format::HandleId                            surface_id,
    const vulkan_wrappers::SurfaceCapabilities& capabilities,
    const VulkanStateTable&                     state_table)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(physical_device_id);
    encoder_.EncodeHandleIdValue(surface_id);
    EncodeStructPtr(&encoder_, &capabilities.surface_capabilities);
    encoder_.EncodeEnumValue(result);
    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilitiesKHR, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfaceCapabilities2(
    format::HandleId                             physical_device_id,
    format::HandleId                             surface_id,
    const vulkan_wrappers::SurfaceCapabilities2& capabilities,
    const VulkanStateTable&                      state_table)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(physical_device_id);
    EncodeStructPtr(&encoder_, &capabilities.surface_info);
    EncodeStructPtr(&encoder_, &capabilities.surface_capabilities);
    encoder_.EncodeEnumValue(result);
    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceCapabilities2KHR, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfaceFormats(format::HandleId                       physical_device_id,
                                                             format::HandleId                       surface_id,
                                                             const vulkan_wrappers::SurfaceFormats& formats,
                                                             const VulkanStateTable&                state_table)
{
    const VkResult result       = VK_SUCCESS;
    const uint32_t format_count = formats.surface_formats.size();

    // First write the call to retrieve the size.
    encoder_.EncodeHandleIdValue(physical_device_id);
    encoder_.EncodeHandleIdValue(surface_id);
    encoder_.EncodeUInt32Ptr(&format_count);
    EncodeStructArray<VkSurfaceFormatKHR>(&encoder_, nullptr, 0);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR, &parameter_stream_);
    parameter_stream_.Clear();

    // Then write the call with the data.
    encoder_.EncodeHandleIdValue(physical_device_id);
    encoder_.EncodeHandleIdValue(surface_id);
    encoder_.EncodeUInt32Ptr(&format_count);
    EncodeStructArray(&encoder_, formats.surface_formats.data(), format_count);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormatsKHR, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfaceFormats2(format::HandleId physical_device_id,
                                                              format::HandleId surface_id,
                                                              const vulkan_wrappers::SurfaceFormats2& formats,
                                                              const VulkanStateTable&                 state_table)
{
    const VkResult result       = VK_SUCCESS;
    uint32_t       format_count = formats.surface_format_count;

    // First write the call to retrieve the size.
    encoder_.EncodeHandleIdValue(physical_device_id);
    EncodeStructPtr(&encoder_, &formats.surface_info);
    encoder_.EncodeUInt32Ptr(&format_count);
    EncodeStructArray<VkSurfaceFormat2KHR>(&encoder_, nullptr, 0);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR, &parameter_stream_);
    parameter_stream_.Clear();

    // Then write the call with the data.
    encoder_.EncodeHandleIdValue(physical_device_id);
    EncodeStructPtr(&encoder_, &formats.surface_info);
    encoder_.EncodeUInt32Ptr(&format_count);
    EncodeStructArray(&encoder_, formats.surface_formats, format_count);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfaceFormats2KHR, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteGetPhysicalDeviceSurfacePresentModes(
    format::HandleId                            physical_device_id,
    format::HandleId                            surface_id,
    const vulkan_wrappers::SurfacePresentModes& present_modes,
    const VulkanStateTable&                     state_table)
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
        parameter_stream_.Clear();

        // Then write the call with the data.
        encoder_.EncodeHandleIdValue(physical_device_id);
        encoder_.EncodeHandleIdValue(surface_id);
        encoder_.EncodeUInt32Ptr(&mode_count);
        encoder_.EncodeEnumArray(pPresentModes, mode_count);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModesKHR, &parameter_stream_);
        parameter_stream_.Clear();
    }
    else
    {
        VkPhysicalDeviceSurfaceInfo2KHR surface_info2;
        surface_info2.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        surface_info2.pNext   = present_modes.surface_info_pnext;
        auto surface_wrapper  = state_table.GetVulkanSurfaceKHRWrapper(surface_id);
        surface_info2.surface = surface_wrapper->handle;

        // First write the call to retrieve the size.
        encoder_.EncodeHandleIdValue(physical_device_id);
        EncodeStructPtr(&encoder_, &surface_info2);
        encoder_.EncodeUInt32Ptr(&mode_count);
        encoder_.EncodeEnumArray<VkPresentModeKHR>(nullptr, 0);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT, &parameter_stream_);
        parameter_stream_.Clear();

        // Then write the call with the data.
        encoder_.EncodeHandleIdValue(physical_device_id);
        EncodeStructPtr(&encoder_, &surface_info2);
        encoder_.EncodeUInt32Ptr(&mode_count);
        encoder_.EncodeEnumArray(pPresentModes, mode_count);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetPhysicalDeviceSurfacePresentModes2EXT, &parameter_stream_);
        parameter_stream_.Clear();
    }
}

void VulkanStateWriter::WriteGetDeviceGroupSurfacePresentModes(
    format::HandleId                                 device_id,
    format::HandleId                                 surface_id,
    const vulkan_wrappers::GroupSurfacePresentModes& present_modes,
    const VulkanStateTable&                          state_table)
{
    const VkResult result = VK_SUCCESS;

    if (present_modes.surface_info_pnext == nullptr)
    {
        encoder_.EncodeHandleIdValue(device_id);
        encoder_.EncodeHandleIdValue(surface_id);
        encoder_.EncodeFlagsPtr(&present_modes.present_modes);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModesKHR, &parameter_stream_);
        parameter_stream_.Clear();
    }
    else
    {
        VkPhysicalDeviceSurfaceInfo2KHR surface_info2;
        surface_info2.sType   = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR;
        surface_info2.pNext   = present_modes.surface_info_pnext;
        auto surface_wrapper  = state_table.GetVulkanSurfaceKHRWrapper(surface_id);
        surface_info2.surface = surface_wrapper->handle;

        encoder_.EncodeHandleIdValue(device_id);
        EncodeStructPtr(&encoder_, &surface_info2);
        encoder_.EncodeFlagsPtr(&present_modes.present_modes);
        encoder_.EncodeEnumValue(result);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkGetDeviceGroupSurfacePresentModes2EXT, &parameter_stream_);
        parameter_stream_.Clear();
    }
}

void VulkanStateWriter::WriteCommandProcessingCreateCommands(format::HandleId device_id,
                                                             uint32_t         queue_family_index,
                                                             format::HandleId queue_id,
                                                             VkCommandPool    command_pool,
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
    parameter_stream_.Clear();

    // Create the command pool for the current queue family index.
    VkCommandPoolCreateInfo create_info = { VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO };
    create_info.pNext                   = nullptr;
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = queue_family_index;

    encoder_.EncodeHandleIdValue(device_id);
    EncodeStructPtr(&encoder_, &create_info);
    EncodeStructPtr(&encoder_, allocator);
    encoder_.EncodeVulkanHandlePtr<vulkan_wrappers::CommandPoolWrapper>(&command_pool);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkCreateCommandPool, &parameter_stream_);
    parameter_stream_.Clear();

    VkCommandBufferAllocateInfo alloc_info = { VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO };
    alloc_info.pNext                       = nullptr;
    alloc_info.commandPool                 = command_pool;
    alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    alloc_info.commandBufferCount          = 1;

    encoder_.EncodeHandleIdValue(device_id);
    EncodeStructPtr(&encoder_, &alloc_info);
    encoder_.EncodeHandleIdArray(&command_buffer_id, 1);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkAllocateCommandBuffers, &parameter_stream_);
    parameter_stream_.Clear();
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
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteCommandEnd(format::HandleId command_buffer_id)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(command_buffer_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkEndCommandBuffer, &parameter_stream_);
    parameter_stream_.Clear();
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

    encoder_.EncodeVulkanHandleValue<vulkan_wrappers::FenceWrapper>(fence);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkQueueSubmit, &parameter_stream_);
    parameter_stream_.Clear();

    // Write queue wait idle.
    encoder_.EncodeHandleIdValue(queue_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkQueueWaitIdle, &parameter_stream_);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteCommandBufferCommands(vulkan_wrappers::CommandBufferWrapper* wrapper,
                                                   const VulkanStateTable&                state_table)
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
            parameter_stream_.Clear();

            offset += sizeof(size_t) + sizeof(format::ApiCallId) + (*parameter_size);
        }

        assert(offset == data_size);
    }
    else
    {
        wrapper->state = vulkan_wrappers::CommandBufferWrapper::kInvalid;
    }
}

void VulkanStateWriter::WriteDescriptorUpdateCommand(format::HandleId                         device_id,
                                                     const vulkan_state_info::DescriptorInfo* binding,
                                                     VkWriteDescriptorSet*                    write,
                                                     util::FileOutputStream*                  output_stream)
{
    assert((binding != nullptr) && (write != nullptr));

    const VkCopyDescriptorSet* copy = nullptr;

    // scratch-space for a potential pNext-struct
    constexpr size_t max_num_bytes_p_next_data =
        std::max(sizeof(VkWriteDescriptorSetAccelerationStructureKHR), sizeof(VkWriteDescriptorSetInlineUniformBlock));
    std::array<uint8_t, max_num_bytes_p_next_data> p_next_data{};

    write->pBufferInfo      = nullptr;
    write->pImageInfo       = nullptr;
    write->pTexelBufferView = nullptr;
    write->pNext            = nullptr;

    switch (write->descriptorType)
    {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            write->pImageInfo = &binding->images[write->dstArrayElement];
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            write->pImageInfo = &binding->storage_images[write->dstArrayElement];
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            write->pBufferInfo = &binding->buffers[write->dstArrayElement];
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            write->pBufferInfo = &binding->storage_buffers[write->dstArrayElement];
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            write->pTexelBufferView = &binding->uniform_texel_buffer_views[write->dstArrayElement];
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            write->pTexelBufferView = &binding->storage_texel_buffer_views[write->dstArrayElement];
            break;
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            if (binding->inline_uniform_block != nullptr)
            {
                auto& p_next    = *reinterpret_cast<VkWriteDescriptorSetInlineUniformBlock*>(p_next_data.data());
                p_next.sType    = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK;
                p_next.pNext    = nullptr;
                p_next.pData    = binding->inline_uniform_block.get();
                p_next.dataSize = binding->count;
                write->pNext    = &p_next;
            }
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            // TODO
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
        {
            if (binding->acceleration_structures != nullptr)
            {
                auto& p_next = *reinterpret_cast<VkWriteDescriptorSetAccelerationStructureKHR*>(p_next_data.data());
                p_next.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR;
                p_next.pNext = nullptr;
                p_next.accelerationStructureCount = binding->count;
                p_next.pAccelerationStructures    = binding->acceleration_structures.get();
                write->pNext                      = &p_next;
            }
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

    WriteFunctionCall(format::ApiCallId::ApiCall_vkUpdateDescriptorSets, &parameter_stream_, output_stream);
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteQueryPoolReset(
    format::HandleId device_id, const std::vector<const vulkan_wrappers::QueryPoolWrapper*>& query_pool_wrappers)
{
    // Retrieve a queue and create a command buffer for query pool reset.
    WriteCommandProcessingCreateCommands(device_id,
                                         kDefaultQueueFamilyIndex,
                                         vulkan_wrappers::kTempQueueId,
                                         vulkan_wrappers::kTempCommandPool,
                                         vulkan_wrappers::kTempCommandBufferId);

    WriteCommandBegin(vulkan_wrappers::kTempCommandBufferId);

    for (auto wrapper : query_pool_wrappers)
    {
        encoder_.EncodeHandleIdValue(vulkan_wrappers::kTempCommandBufferId);
        encoder_.EncodeHandleIdValue(wrapper->handle_id);
        encoder_.EncodeUInt32Value(0);
        encoder_.EncodeUInt32Value(wrapper->query_count);

        WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdResetQueryPool, &parameter_stream_);
        parameter_stream_.Clear();
    }

    WriteCommandEnd(vulkan_wrappers::kTempCommandBufferId);
    WriteCommandExecution(vulkan_wrappers::kTempQueueId, vulkan_wrappers::kTempCommandBufferId);

    WriteDestroyDeviceObject(
        format::ApiCallId::ApiCall_vkDestroyCommandPool, device_id, vulkan_wrappers::kTempCommandPoolId, nullptr);
}

void VulkanStateWriter::WriteQueryActivation(format::HandleId           device_id,
                                             uint32_t                   queue_family_index,
                                             const QueryActivationList& active_queries)
{
    const VkPipelineStageFlagBits timestamp_stage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;

    // Retrieve a queue and create a command buffer for query activation.
    WriteCommandProcessingCreateCommands(device_id,
                                         queue_family_index,
                                         vulkan_wrappers::kTempQueueId,
                                         vulkan_wrappers::kTempCommandPool,
                                         vulkan_wrappers::kTempCommandBufferId);

    WriteCommandBegin(vulkan_wrappers::kTempCommandBufferId);

    for (auto query_entry : active_queries)
    {
        if (query_entry.type == VK_QUERY_TYPE_TIMESTAMP)
        {
            encoder_.EncodeHandleIdValue(vulkan_wrappers::kTempCommandBufferId);
            encoder_.EncodeEnumValue(timestamp_stage);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdWriteTimestamp, &parameter_stream_);
            parameter_stream_.Clear();
        }
        else if (query_entry.type == VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT)
        {
            encoder_.EncodeHandleIdValue(vulkan_wrappers::kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);
            encoder_.EncodeFlagsValue(query_entry.flags);
            encoder_.EncodeUInt32Value(query_entry.type_index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdBeginQueryIndexedEXT, &parameter_stream_);
            parameter_stream_.Clear();

            encoder_.EncodeHandleIdValue(vulkan_wrappers::kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);
            encoder_.EncodeUInt32Value(query_entry.type_index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdEndQueryIndexedEXT, &parameter_stream_);
            parameter_stream_.Clear();
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
            encoder_.EncodeHandleIdValue(vulkan_wrappers::kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);
            encoder_.EncodeFlagsValue(query_entry.flags);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdBeginQuery, &parameter_stream_);
            parameter_stream_.Clear();

            encoder_.EncodeHandleIdValue(vulkan_wrappers::kTempCommandBufferId);
            encoder_.EncodeHandleIdValue(query_entry.pool_id);
            encoder_.EncodeUInt32Value(query_entry.index);

            WriteFunctionCall(format::ApiCallId::ApiCall_vkCmdEndQuery, &parameter_stream_);
            parameter_stream_.Clear();
        }
    }

    WriteCommandEnd(vulkan_wrappers::kTempCommandBufferId);
    WriteCommandExecution(vulkan_wrappers::kTempQueueId, vulkan_wrappers::kTempCommandBufferId);

    WriteDestroyDeviceObject(
        format::ApiCallId::ApiCall_vkDestroyCommandPool, device_id, vulkan_wrappers::kTempCommandPoolId, nullptr);
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
    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteSetEvent(format::HandleId device_id, format::HandleId event_id)
{
    const VkResult result = VK_SUCCESS;

    encoder_.EncodeHandleIdValue(device_id);
    encoder_.EncodeHandleIdValue(event_id);
    encoder_.EncodeEnumValue(result);

    WriteFunctionCall(format::ApiCallId::ApiCall_vkSetEvent, &parameter_stream_);
    parameter_stream_.Clear();
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
    parameter_stream_.Clear();
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

    parameter_stream_.Clear();
}

void VulkanStateWriter::WriteCreatePipelineCache(format::HandleId                 device_id,
                                                 const VkPipelineCacheCreateInfo* pCreateInfo,
                                                 const VkAllocationCallbacks*     allocator,
                                                 VkPipelineCache*                 pPipelineCache,
                                                 VkResult                         result)
{
    bool              omit_output_data = false;
    format::ApiCallId call_id          = format::ApiCallId::ApiCall_vkCreatePipelineCache;
    encoder_.EncodeHandleIdValue(device_id);
    EncodeStructPtr(&encoder_, pCreateInfo);
    EncodeStructPtr(&encoder_, allocator);
    if (result < 0)
    {
        omit_output_data = true;
    }
    encoder_.EncodeVulkanHandlePtr<vulkan_wrappers::PipelineCacheWrapper>(pPipelineCache, omit_output_data);
    encoder_.EncodeEnumValue(result);
    WriteFunctionCall(call_id, &parameter_stream_);
    parameter_stream_.Clear();
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
void VulkanStateWriter::WriteFunctionCall(format::ApiCallId         call_id,
                                          util::MemoryOutputStream* parameter_buffer,
                                          util::FileOutputStream*   output_stream)
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
            compressed_header.thread_id         = thread_data_->thread_id_;
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
        uncompressed_header.thread_id         = thread_data_->thread_id_;

        packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;

        uncompressed_header.block_header.size = packet_size;
    }

    // Write appropriate function call block header and parameter data
    if (output_stream != nullptr)
    {
        output_stream->Write(header_pointer, header_size);
        output_stream->Write(data_pointer, data_size);
    }
    else
    {
        output_stream_->Write(header_pointer, header_size);
        output_stream_->Write(data_pointer, data_size);
        ++blocks_written_;
    }
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
    fill_cmd.thread_id     = thread_data_->thread_id_;
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

    ++blocks_written_;
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
    resize_cmd.thread_id = thread_data_->thread_id_;

    resize_cmd.surface_id = surface_id;
    resize_cmd.width      = width;
    resize_cmd.height     = height;

    output_stream_->Write(&resize_cmd, sizeof(resize_cmd));

    ++blocks_written_;
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
    resize_cmd2.thread_id = thread_data_->thread_id_;

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

    ++blocks_written_;
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
    properties_cmd.thread_id                     = thread_data_->thread_id_;
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

    ++blocks_written_;
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
    memory_properties_cmd.thread_id          = thread_data_->thread_id_;
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

    ++blocks_written_;
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
    opaque_address_cmd.thread_id = thread_data_->thread_id_;
    opaque_address_cmd.device_id = device_id;
    opaque_address_cmd.object_id = object_id;
    opaque_address_cmd.address   = address;

    output_stream_->Write(&opaque_address_cmd, sizeof(opaque_address_cmd));

    ++blocks_written_;
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
    set_handles_cmd.thread_id   = thread_data_->thread_id_;
    set_handles_cmd.device_id   = device_id;
    set_handles_cmd.pipeline_id = pipeline_id;
    set_handles_cmd.data_size   = data_size;

    output_stream_->Write(&set_handles_cmd, sizeof(set_handles_cmd));
    output_stream_->Write(data, data_size);

    ++blocks_written_;
}

VkMemoryPropertyFlags VulkanStateWriter::GetMemoryProperties(const vulkan_wrappers::DeviceWrapper*       device_wrapper,
                                                             const vulkan_wrappers::DeviceMemoryWrapper* memory_wrapper)
{
    assert((device_wrapper != nullptr) && (memory_wrapper != nullptr));

    VkMemoryPropertyFlags flags = 0;

    const vulkan_wrappers::PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;
    assert(physical_device_wrapper != nullptr);

    const VkPhysicalDeviceMemoryProperties* memory_properties = &physical_device_wrapper->memory_properties;
    assert((memory_properties->memoryTypeCount > 0) &&
           (memory_wrapper->memory_type_index < memory_properties->memoryTypeCount));

    flags = memory_properties->memoryTypes[memory_wrapper->memory_type_index].propertyFlags;

    return flags;
}

void VulkanStateWriter::InvalidateMappedMemoryRange(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                                                    VkDeviceMemory                        memory,
                                                    VkDeviceSize                          offset,
                                                    VkDeviceSize                          size)
{
    assert(device_wrapper != nullptr);

    VkMappedMemoryRange invalidate_range = { VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE };
    invalidate_range.pNext               = nullptr;
    invalidate_range.memory              = memory;
    invalidate_range.offset              = offset;
    invalidate_range.size                = size;

    device_wrapper->layer_table.InvalidateMappedMemoryRanges(device_wrapper->handle, 1, &invalidate_range);
}

void VulkanStateWriter::GetFenceStatus(const vulkan_wrappers::DeviceWrapper* device_wrapper,
                                       VkFence                               fence,
                                       bool*                                 status)
{
    assert(device_wrapper != nullptr);

    VkResult result = device_wrapper->layer_table.GetFenceStatus(device_wrapper->handle, fence);
    (*status)       = (result == VK_SUCCESS);
}

bool VulkanStateWriter::CheckCommandHandles(const vulkan_wrappers::CommandBufferWrapper* wrapper,
                                            const VulkanStateTable&                      state_table)
{
    // Ignore commands that reference destroyed objects.
    for (uint32_t i = 0; i < vulkan_state_info::CommandHandleType::NumHandleTypes; ++i)
    {
        for (auto id : wrapper->command_handles[i])
        {
            if (!CheckCommandHandle(static_cast<vulkan_state_info::CommandHandleType>(i), id, state_table))
            {
                return false;
            }
        }
    }

    return true;
}

bool VulkanStateWriter::CheckCommandHandle(vulkan_state_info::CommandHandleType handle_type,
                                           format::HandleId                     handle_id,
                                           const VulkanStateTable&              state_table)
{
    switch (handle_type)
    {
        case vulkan_state_info::CommandHandleType::BufferHandle:
            return IsBufferValid(handle_id, state_table);
        case vulkan_state_info::CommandHandleType::BufferViewHandle:
            return IsBufferViewValid(handle_id, state_table);
        case vulkan_state_info::CommandHandleType::CommandBufferHandle:
        {
            const vulkan_wrappers::CommandBufferWrapper* wrapper = state_table.GetVulkanCommandBufferWrapper(handle_id);
            return (wrapper != nullptr && wrapper->state == vulkan_wrappers::CommandBufferWrapper::kExecutable);
        }
        case vulkan_state_info::CommandHandleType::DescriptorSetHandle:
            return (state_table.GetVulkanDescriptorSetWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::EventHandle:
            return (state_table.GetVulkanEventWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::FramebufferHandle:
            return IsFramebufferValid(handle_id, state_table);
        case vulkan_state_info::CommandHandleType::ImageHandle:
            return IsImageValid(handle_id, state_table);
        case vulkan_state_info::CommandHandleType::ImageViewHandle:
            return IsImageViewValid(handle_id, state_table);
        case vulkan_state_info::CommandHandleType::PipelineHandle:
            return (state_table.GetVulkanPipelineWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::PipelineLayoutHandle:
            return (state_table.GetVulkanPipelineLayoutWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::QueryPoolHandle:
            return (state_table.GetVulkanQueryPoolWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::RenderPassHandle:
            return (state_table.GetVulkanRenderPassWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::SamplerHandle:
            return (state_table.GetVulkanSamplerWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::AccelerationStructureNVHandle:
            return (state_table.GetVulkanAccelerationStructureNVWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::AccelerationStructureKHRHandle:
            return (state_table.GetVulkanAccelerationStructureKHRWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::IndirectCommandsLayoutNVHandle:
            return (state_table.GetVulkanIndirectCommandsLayoutNVWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::DeferredOperationKHRHandle:
            return (state_table.GetVulkanDeferredOperationKHRWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::MicromapEXTHandle:
            return (state_table.GetVulkanMicromapEXTWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::OpticalFlowSessionNVHandle:
            return (state_table.GetVulkanOpticalFlowSessionNVWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::VideoSessionKHRHandle:
            return (state_table.GetVulkanVideoSessionKHRWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::VideoSessionParametersKHRHandle:
            return (state_table.GetVulkanVideoSessionParametersKHRWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::ShaderEXTHandle:
            return (state_table.GetVulkanShaderEXTWrapper(handle_id) != nullptr);
        case vulkan_state_info::CommandHandleType::DeviceMemoryHandle:
            return (state_table.GetVulkanDeviceMemoryWrapper(handle_id) != nullptr);
        default:
            GFXRECON_LOG_ERROR("State write is skipping unrecognized handle type when checking handles "
                               "referenced by command buffers");
            assert(false);
            return false;
    }
}

bool VulkanStateWriter::CheckDescriptorStatus(const vulkan_state_info::DescriptorInfo* descriptor,
                                              uint32_t                                 index,
                                              const VulkanStateTable&                  state_table,
                                              VkDescriptorType*                        descriptor_type)
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
                if (state_table.GetVulkanSamplerWrapper(descriptor->sampler_ids[index]) != nullptr)
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                if ((descriptor->immutable_samplers ||
                     (state_table.GetVulkanSamplerWrapper(descriptor->sampler_ids[index]) != nullptr)) &&
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
            case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                if (descriptor->inline_uniform_block != nullptr)
                {
                    valid = true;
                }
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                // TODO
                GFXRECON_LOG_WARNING("Descriptor type acceleration structure NV is not currently supported");
                break;
            case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                if (state_table.GetVulkanAccelerationStructureKHRWrapper(descriptor->handle_ids[index]) != nullptr)
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
    auto buffer_wrapper = state_table.GetVulkanBufferWrapper(buffer_id);

    if (buffer_wrapper != nullptr)
    {
        format::HandleId memory_id = buffer_wrapper->bind_memory_id;

        if ((memory_id == 0) || (state_table.GetVulkanDeviceMemoryWrapper(memory_id) != nullptr))
        {
            valid = true;
        }
    }

    return valid;
}

bool VulkanStateWriter::IsBufferViewValid(format::HandleId view_id, const VulkanStateTable& state_table)
{
    bool valid               = false;
    auto buffer_view_wrapper = state_table.GetVulkanBufferViewWrapper(view_id);

    if (buffer_view_wrapper != nullptr)
    {
        valid = IsBufferValid(buffer_view_wrapper->buffer_id, state_table);
    }

    return valid;
}

bool VulkanStateWriter::IsImageValid(format::HandleId image_id, const VulkanStateTable& state_table)
{
    bool valid         = false;
    auto image_wrapper = state_table.GetVulkanImageWrapper(image_id);

    if (image_wrapper != nullptr)
    {
        format::HandleId memory_id = image_wrapper->bind_memory_id;

        if ((memory_id == 0) || (state_table.GetVulkanDeviceMemoryWrapper(memory_id) != nullptr))
        {
            valid = true;
        }
    }

    return valid;
}

bool VulkanStateWriter::IsImageViewValid(format::HandleId view_id, const VulkanStateTable& state_table)
{
    bool valid              = false;
    auto image_view_wrapper = state_table.GetVulkanImageViewWrapper(view_id);

    if (image_view_wrapper != nullptr)
    {
        valid = IsImageValid(image_view_wrapper->image_id, state_table);
    }

    return valid;
}

bool VulkanStateWriter::IsFramebufferValid(format::HandleId framebuffer_id, const VulkanStateTable& state_table)
{
    bool valid               = false;
    auto framebuffer_wrapper = state_table.GetVulkanFramebufferWrapper(framebuffer_id);

    if (framebuffer_wrapper != nullptr)
    {
        valid = IsFramebufferValid(framebuffer_wrapper, state_table);
    }

    return valid;
}

bool VulkanStateWriter::IsFramebufferValid(const vulkan_wrappers::FramebufferWrapper* framebuffer_wrapper,
                                           const VulkanStateTable&                    state_table)
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

void VulkanStateWriter::WriteExecuteFromFile(const std::string& filename, uint32_t n_blocks, int64_t offset)
{
    assert(!filename.empty());

    // Remove path from filename
    std::string  relative_file;
    const size_t last_slash_pos = filename.find_last_of("\\/");
    if (last_slash_pos != std::string::npos)
    {
        relative_file = filename.substr(last_slash_pos + 1);
    }
    else
    {
        relative_file = filename;
    }

    const size_t filename_length = relative_file.length();

    format::ExecuteBlocksFromFile execute_from_file;
    execute_from_file.meta_header.block_header.size =
        format::GetMetaDataBlockBaseSize(execute_from_file) + filename_length;
    execute_from_file.meta_header.block_header.type = format::kMetaDataBlock;
    execute_from_file.meta_header.meta_data_id =
        format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kExecuteBlocksFromFile);
    execute_from_file.thread_id       = thread_data_->thread_id_;
    execute_from_file.n_blocks        = n_blocks;
    execute_from_file.offset          = offset;
    execute_from_file.filename_length = filename_length;

    output_stream_->Write(&execute_from_file, sizeof(execute_from_file));
    output_stream_->Write(relative_file.c_str(), filename_length);

    blocks_written_ += n_blocks + 1;
}

void VulkanStateWriter::WriteDebugUtilsState(const VulkanStateTable& state_table)
{
    auto write_debug_utils_calls = [&](const auto* wrapper) {
        assert(wrapper != nullptr);
        if (wrapper->debug_name_create_parameters)
        {
            WriteFunctionCall(format::ApiCall_vkSetDebugUtilsObjectNameEXT,
                              wrapper->debug_name_create_parameters.get());
        }

        if (wrapper->debug_tag_create_parameters)
        {
            WriteFunctionCall(format::ApiCall_vkSetDebugUtilsObjectTagEXT, wrapper->debug_tag_create_parameters.get());
        }
    };

    // clang-format off
    state_table.VisitWrappers([&](const vulkan_wrappers::InstanceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PhysicalDeviceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::QueueWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SemaphoreWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::CommandBufferWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::FenceWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DeviceMemoryWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::BufferWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ImageWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::EventWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::QueryPoolWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::BufferViewWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ImageViewWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ShaderModuleWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineCacheWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineLayoutWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::RenderPassWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PipelineWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorSetLayoutWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SamplerWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorPoolWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorSetWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::FramebufferWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::CommandPoolWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SamplerYcbcrConversionWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DescriptorUpdateTemplateWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SurfaceKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::SwapchainKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DisplayKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DisplayModeKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DebugReportCallbackEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DebugUtilsMessengerEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::AccelerationStructureKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::ValidationCacheEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PerformanceConfigurationINTELWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::DeferredOperationKHRWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::IndirectCommandsLayoutNVWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::MicromapEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::PrivateDataSlotEXTWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    state_table.VisitWrappers([&](const vulkan_wrappers::AccelerationStructureNVWrapper* wrapper) { write_debug_utils_calls(wrapper); });
    // clang-format on
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
