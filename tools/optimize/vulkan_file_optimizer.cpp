/*
** Copyright (c) 2020 LunarG, Inc.
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "tools/optimize/vulkan_file_optimizer.h"
#include "framework/format/format_util.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

bool VulkanFileOptimizer::ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    // Regular funciton call processing/compression handling - duplicated in multiple places, TODO: extract, reuse
    size_t              parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t            uncompressed_size     = 0;
    decode::ApiCallInfo call_info{ GetCurrentBlockIndex() };
    bool                success = ReadBytes(&call_info.thread_id, sizeof(call_info.thread_id));

    parameter_buffer_size -= sizeof(call_info.thread_id);

    if (format::IsBlockCompressed(block_header.type))
    {
        parameter_buffer_size -= sizeof(uncompressed_size);
        success = ReadBytes(&uncompressed_size, sizeof(uncompressed_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, uncompressed_size);

            size_t actual_size = 0;
            success            = ReadCompressedParameterBuffer(
                parameter_buffer_size, static_cast<size_t>(uncompressed_size), &actual_size);

            if (success)
            {
                assert(actual_size == uncompressed_size);
                parameter_buffer_size = static_cast<size_t>(uncompressed_size);
            }
            else
            {
                HandleBlockReadError(kErrorReadingCompressedBlockData,
                                     "Failed to read compressed function call block data");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingCompressedBlockHeader,
                                 "Failed to read compressed function call block header");
        }
    }
    else
    {
        success = ReadParameterBuffer(parameter_buffer_size);

        if (!success)
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read function call block data");
        }
    }

    // Separate buffer that holds call parameters to modify
    encode::ParameterBuffer buffer;

    // Initialize our modifiable parameter buffer with the initial data from trace
    // Each modifier will get access to parameter buffer to read and modify
    // The same parameter buffer will be passed to next modifier in chain
    buffer.Write(GetParameterBuffer().data(), parameter_buffer_size);

    // Each modifier can request the call to be removed from the trace
    // This does not affect processing of the current call by other modifiers
    bool delete_current_call = false;

    // This vector owns new call data to be inserted before currently processed call
    std::vector<std::unique_ptr<util::CallModifierBase::NewCallData>> new_pre_calls;

    // This vector owns new call data to be inserted after currently processed call
    std::vector<std::unique_ptr<util::CallModifierBase::NewCallData>> new_post_calls;

    for (auto& modifier : optimization_data_->modifiers)
    {
        modifier->SetParameterBuffer(&buffer);
        decoder.AddConsumer(modifier.get());
        decode::DecodeAllocator::Begin();
        decoder.DecodeFunctionCall(call_id, call_info, buffer.GetData(), buffer.GetDataSize());
        decode::DecodeAllocator::End();
        decoder.RemoveConsumer(modifier.get());
        delete_current_call |= modifier->GetDeleteCurrentCall();
        modifier->AppendPreCalls(new_pre_calls);
        modifier->AppendPostCalls(new_post_calls);
    }

    for (auto& new_call : new_pre_calls)
    {
        WriteFunctionCall(new_call->call_id, new_call->thread_id, &(new_call->parameter_buffer));
    }

    if (!delete_current_call)
    {
        WriteFunctionCall(call_id, call_info.thread_id, &buffer);
    }

    for (auto& new_call : new_post_calls)
    {
        WriteFunctionCall(new_call->call_id, new_call->thread_id, &(new_call->parameter_buffer));
    }

    return success;
}

// TODO: This is the same code used by CaptureManager to write function call data. It could be moved to a format
// utility.
void VulkanFileOptimizer::WriteFunctionCall(format::ApiCallId               call_id,
                                            format::ThreadId                thread_id,
                                            const util::MemoryOutputStream* parameter_buffer)
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

    auto compressor                  = GetCompressor();
    auto compressed_parameter_buffer = GetCompressedParameterBuffer();

    if (compressor != nullptr)
    {
        size_t packet_size = 0;
        size_t compressed_size =
            compressor->Compress(uncompressed_size, parameter_buffer->GetData(), &compressed_parameter_buffer, 0);

        if ((0 < compressed_size) && (compressed_size < uncompressed_size))
        {
            data_pointer   = reinterpret_cast<const void*>(compressed_parameter_buffer.data());
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
    WriteBytes(header_pointer, header_size);

    // Write parameter data.
    WriteBytes(data_pointer, data_size);
}

GFXRECON_END_NAMESPACE(gfxrecon)