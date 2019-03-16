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
    bytes_written += StandardCreateWrite<PipelineWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // Descriptor creation.
    bytes_written += StandardCreateWrite<DescriptorPoolWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DescriptorUpdateTemplateWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);
    bytes_written += StandardCreateWrite<DescriptorSetWrapper>(output_stream, thread_id, compressor, &compressed_parameter_buffer);

    // clang-format on

    return bytes_written;
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
