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

#include <cassert>
#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateWriter::VulkanStateWriter(util::FileOutputStream* output_stream,
                                     util::Compressor*       compressor,
                                     format::ThreadId        thread_id) :
    output_stream_(output_stream),
    compressor_(compressor), thread_id_(thread_id), encoder_(&parameter_stream_)
{
    assert(output_stream != nullptr);
    assert(compressor != nullptr);
}

VulkanStateWriter::~VulkanStateWriter() {}

void VulkanStateWriter::WriteState(const encode::VulkanStateTable& state_table)
{
    // clang-format off

    // Instance, device, and queue creation.
    StandardCreateWrite<InstanceWrapper>(state_table);
    StandardCreateWrite<PhysicalDeviceWrapper>(state_table);
    StandardCreateWrite<DeviceWrapper>(state_table);
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

void VulkanStateWriter::WriteBufferState(const encode::VulkanStateTable& state_table)
{
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
        }
    });
}

void VulkanStateWriter::WriteImageState(const encode::VulkanStateTable& state_table)
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

void VulkanStateWriter::WriteFramebufferState(const encode::VulkanStateTable& state_table)
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

void VulkanStateWriter::WritePipelineLayoutState(const encode::VulkanStateTable& state_table)
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

void VulkanStateWriter::WritePipelineState(const encode::VulkanStateTable& state_table)
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

void VulkanStateWriter::DestroyTemporaryDeviceObject(format::ApiCallId         call_id,
                                                     format::HandleId          handle,
                                                     util::MemoryOutputStream* create_parameters)
{
    // Extract device from create parameter buffer.
    // TODO: Device children will be stored in the device wrapper, and device handle will be directly available when
    // processing children (no need to extract).
    format::HandleId device = *reinterpret_cast<const format::HandleId*>(create_parameters->GetData());
    // TODO: Track allocation callbacks.
    const VkAllocationCallbacks* allocator = nullptr;

    encoder_.EncodeHandleIdValue(device);
    encoder_.EncodeHandleIdValue(handle);
    EncodeStructPtr(&encoder_, allocator);

    WriteFunctionCall(call_id, &parameter_stream_);
}

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

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
