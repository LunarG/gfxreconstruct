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

#include "encode/vulkan_state_tracker.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"

#include <set>
#include <unordered_map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanStateTracker::VulkanStateTracker() : object_count_(0) {}

VulkanStateTracker::~VulkanStateTracker() {}

uint64_t VulkanStateTracker::WriteState(util::FileOutputStream* output_stream,
                                        format::ThreadId        thread_id,
                                        util::Compressor*       compressor)
{
    std::unique_lock<std::mutex> lock(mutex_);
    std::vector<uint8_t>         compressed_parameter_buffer;
    uint64_t                     bytes_written = 0;

    // clang-format off

    // Instance, device, and queue creation.
    bytes_written += StandardCreateWrite<InstanceWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<PhysicalDeviceWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DeviceWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<QueueWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // Utility object creation.
    bytes_written += StandardCreateWrite<DebugReportCallbackEXTWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DebugUtilsMessengerEXTWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<ValidationCacheEXTWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // Synchronization primitive creation.
    bytes_written += StandardCreateWrite<SemaphoreWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<FenceWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<EventWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // WSI object creation.
    bytes_written += StandardCreateWrite<DisplayKHRWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DisplayModeKHRWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<SurfaceKHRWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<SwapchainKHRWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // Command creation.
    bytes_written += StandardCreateWrite<CommandPoolWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<CommandBufferWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<ObjectTableNVXWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<IndirectCommandsLayoutNVXWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);  // TODO: If we intend to support this, we need to reserve command space after creation.

    // Query object creation.
    bytes_written += StandardCreateWrite<QueryPoolWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<AccelerationStructureNVWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // Resource creation.
    bytes_written += StandardCreateWrite<DeviceMemoryWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<BufferWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<BufferViewWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<ImageWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<ImageViewWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<SamplerWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<SamplerYcbcrConversionWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // Render object creation.
    bytes_written += StandardCreateWrite<RenderPassWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<FramebufferWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<ShaderModuleWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DescriptorSetLayoutWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<PipelineLayoutWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<PipelineCacheWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += WritePipelineState(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // Descriptor creation.
    bytes_written += StandardCreateWrite<DescriptorPoolWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DescriptorUpdateTemplateWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DescriptorSetWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // clang-format on

    return bytes_written;
}

uint64_t VulkanStateTracker::WritePipelineState(util::FileOutputStream* output_stream,
                                                format::ThreadId        thread_id,
                                                util::Compressor*       compressor,
                                                std::vector<uint8_t>*   compressed_parameter_buffer)
{
    uint64_t bytes_written = 0;

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
    state_table_.VisitWrappers([&](PipelineWrapper* wrapper) {
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
            ShaderModuleWrapper* shader_wrapper = state_table_.GetShaderModuleWrapper(format::ToHandleId(entry.handle));
            if ((shader_wrapper == nullptr) || (shader_wrapper->handle_id != entry.handle_id))
            {
                // Either the handle does not exist, or it has been recycled and now references a different object.
                const auto& inserted = temp_shaders.insert(std::make_pair(entry.handle_id, &entry));

                // Create a temporary object on first encounter.
                if (inserted.second)
                {
                    bytes_written += WriteFunctionCall(output_stream,
                                                       thread_id,
                                                       entry.create_call_id,
                                                       entry.create_parameters.get(),
                                                       compressor,
                                                       compressed_parameter_buffer);
                }
            }
        }

        RenderPassWrapper* render_pass_wrapper =
            state_table_.GetRenderPassWrapper(format::ToHandleId(wrapper->render_pass));
        if ((render_pass_wrapper == nullptr) || (render_pass_wrapper->handle_id != wrapper->render_pass_id))
        {
            // Either the handle does not exist, or it has been recycled and now references a different object.
            const auto& inserted = temp_render_passes.insert(std::make_pair(wrapper->render_pass_id, wrapper));

            // Create a temporary object on first encounter.
            if (inserted.second)
            {
                bytes_written += WriteFunctionCall(output_stream,
                                                   thread_id,
                                                   wrapper->render_pass_create_call_id,
                                                   wrapper->render_pass_create_parameters.get(),
                                                   compressor,
                                                   compressed_parameter_buffer);
            }
        }

        PipelineLayoutWrapper* layout_wrapper =
            state_table_.GetPipelineLayoutWrapper(format::ToHandleId(wrapper->layout));
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
                    DescriptorSetLayoutWrapper* ds_layout_wrapper =
                        state_table_.GetDescriptorSetLayoutWrapper(format::ToHandleId(entry.handle));
                    if ((ds_layout_wrapper == nullptr) || (ds_layout_wrapper->handle_id != entry.handle_id))
                    {
                        const auto& inserted = temp_ds_layouts.insert(std::make_pair(entry.handle_id, &entry));

                        // Create a temporary object on first encounter.
                        if (inserted.second)
                        {
                            bytes_written += WriteFunctionCall(output_stream,
                                                               thread_id,
                                                               entry.create_call_id,
                                                               entry.create_parameters.get(),
                                                               compressor,
                                                               compressed_parameter_buffer);
                        }
                    }
                }

                bytes_written += WriteFunctionCall(output_stream,
                                                   thread_id,
                                                   wrapper->layout_create_call_id,
                                                   wrapper->layout_create_parameters.get(),
                                                   compressor,
                                                   compressed_parameter_buffer);
            }
        }
    });

    // Pipeline object creation.
    for (const auto& entry : graphics_pipelines)
    {
        bytes_written += WriteFunctionCall(output_stream,
                                           thread_id,
                                           format::ApiCall_vkCreateGraphicsPipelines,
                                           entry.get(),
                                           compressor,
                                           compressed_parameter_buffer);
    }

    for (const auto& entry : compute_pipelines)
    {
        bytes_written += WriteFunctionCall(output_stream,
                                           thread_id,
                                           format::ApiCall_vkCreateComputePipelines,
                                           entry.get(),
                                           compressor,
                                           compressed_parameter_buffer);
    }

    for (const auto& entry : compute_pipelines)
    {
        bytes_written += WriteFunctionCall(output_stream,
                                           thread_id,
                                           format::ApiCall_vkCreateRayTracingPipelinesNV,
                                           entry.get(),
                                           compressor,
                                           compressed_parameter_buffer);
    }

    // Temporary object destruction.
    for (const auto& entry : temp_shaders)
    {
        const ShaderModuleInfo* info = entry.second;
        assert(info != nullptr);
        bytes_written += DestroyTemporaryDeviceObject(output_stream,
                                                      thread_id,
                                                      format::ApiCall_vkDestroyShaderModule,
                                                      format::ToHandleId(info->handle),
                                                      info->create_parameters.get(),
                                                      compressor,
                                                      compressed_parameter_buffer);
    }

    for (const auto& entry : temp_render_passes)
    {
        const PipelineWrapper* info = entry.second;
        assert(info != nullptr);
        bytes_written += DestroyTemporaryDeviceObject(output_stream,
                                                      thread_id,
                                                      format::ApiCall_vkDestroyRenderPass,
                                                      format::ToHandleId(info->render_pass),
                                                      info->create_parameters.get(),
                                                      compressor,
                                                      compressed_parameter_buffer);
    }

    for (const auto& entry : temp_ds_layouts)
    {
        const DescriptorSetLayoutInfo* info = entry.second;
        assert(info != nullptr);
        bytes_written += DestroyTemporaryDeviceObject(output_stream,
                                                      thread_id,
                                                      format::ApiCall_vkDestroyDescriptorSetLayout,
                                                      format::ToHandleId(info->handle),
                                                      info->create_parameters.get(),
                                                      compressor,
                                                      compressed_parameter_buffer);
    }

    for (const auto& entry : temp_layouts)
    {
        const PipelineWrapper* info = entry.second;
        assert(info != nullptr);
        bytes_written += DestroyTemporaryDeviceObject(output_stream,
                                                      thread_id,
                                                      format::ApiCall_vkDestroyPipelineLayout,
                                                      format::ToHandleId(info->layout),
                                                      info->create_parameters.get(),
                                                      compressor,
                                                      compressed_parameter_buffer);
    }

    return bytes_written;
}

uint64_t VulkanStateTracker::DestroyTemporaryDeviceObject(util::FileOutputStream*   output_stream,
                                                          format::ThreadId          thread_id,
                                                          format::ApiCallId         call_id,
                                                          format::HandleId          handle,
                                                          util::MemoryOutputStream* create_parameters,
                                                          util::Compressor*         compressor,
                                                          std::vector<uint8_t>*     compressed_parameter_buffer)
{
    // TODO: Create one encoder/stream to reuse.
    util::MemoryOutputStream parameter_stream;
    ParameterEncoder         encoder(&parameter_stream);

    // Extract device from create parameter buffer.
    // TODO: Device children will be stored in the device wrapper, and device handle will be directly available when
    // processing children (no need to extract).
    format::HandleId device = *reinterpret_cast<const format::HandleId*>(create_parameters->GetData());
    // TODO: Track allocation callbacks.
    const VkAllocationCallbacks* allocator = nullptr;

    encoder.EncodeHandleIdValue(device);
    encoder.EncodeHandleIdValue(handle);
    EncodeStructPtr(&encoder, allocator);

    return WriteFunctionCall(
        output_stream, thread_id, call_id, &parameter_stream, compressor, compressed_parameter_buffer);
}

uint64_t VulkanStateTracker::WriteFunctionCall(util::FileOutputStream*   output_stream,
                                               format::ThreadId          thread_id,
                                               format::ApiCallId         call_id,
                                               util::MemoryOutputStream* parameter_buffer,
                                               util::Compressor*         compressor,
                                               std::vector<uint8_t>*     compressed_parameter_buffer)
{
    assert((parameter_buffer != nullptr) && (output_stream));

    bool                                 not_compressed      = true;
    format::CompressedFunctionCallHeader compressed_header   = {};
    format::FunctionCallHeader           uncompressed_header = {};
    size_t                               uncompressed_size   = parameter_buffer->GetDataSize();
    size_t                               header_size         = 0;
    const void*                          header_pointer      = nullptr;
    size_t                               data_size           = 0;
    const void*                          data_pointer        = nullptr;

    if (compressor != nullptr)
    {
        assert(compressed_parameter_buffer != nullptr);

        size_t packet_size = 0;
        size_t compressed_size =
            compressor->Compress(uncompressed_size, parameter_buffer->GetData(), compressed_parameter_buffer);

        if ((0 < compressed_size) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_parameter_buffer->data());
            data_size      = compressed_size;
            header_pointer = reinterpret_cast<const void*>(&compressed_header);
            header_size    = sizeof(format::CompressedFunctionCallHeader);

            compressed_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_header.api_call_id       = call_id;
            compressed_header.thread_id         = thread_id;
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
        uncompressed_header.thread_id         = thread_id;

        packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;

        uncompressed_header.block_header.size = packet_size;
    }

    // Write appropriate function call block header.
    uint64_t bytes_written = output_stream->Write(header_pointer, header_size);

    // Write parameter data.
    bytes_written += output_stream->Write(data_pointer, data_size);

    return bytes_written;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
