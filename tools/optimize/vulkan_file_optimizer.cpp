/*
** Copyright (c) 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
** Copyright (c) 2020-2026 LunarG, Inc.
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

#include "vulkan_file_optimizer.h"

#include "decode/decode_allocator.h"
#include "decode/file_processor_visitors.h"
#include "format/format.h"

#include <cstring>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

VulkanFileOptimizer::VulkanFileOptimizer(const std::unordered_set<format::HandleId>& unreferenced_ids,
                                         const std::unordered_set<uint64_t>&         unreferenced_blocks,
                                         Modifiers                                   modifiers) :
    FileOptimizer(unreferenced_ids, unreferenced_blocks),
    modifiers_(std::move(modifiers)), working_uncompressed_store_(kWorkingStoreInitialSize)
{}

bool VulkanFileOptimizer::ProcessFunctionCall(decode::ParsedBlock& parsed_block)
{
    auto& args = parsed_block.Get<decode::FunctionCallArgs>();

    // Blocks the base optimizer drops are never offered to the modifiers.
    if (modifiers_.empty() || unreferenced_blocks_.contains(args.call_info.index))
    {
        return FileOptimizer::ProcessFunctionCall(parsed_block);
    }

    if (!parsed_block.Decompress(GetCompressor(), working_uncompressed_store_))
    {
        return false;
    }

    // A copy of the call parameters for the modifiers to read and rewrite.
    encode::ParameterBuffer buffer;
    buffer.Write(args.data, args.data_size);

    return ModifierDispatch(args, parsed_block, buffer);
}

bool VulkanFileOptimizer::ProcessMetaData(decode::ParsedBlock& parsed_block)
{
    if (modifiers_.empty())
    {
        return FileOptimizer::ProcessMetaData(parsed_block);
    }

    // Blocks the base optimizer drops are never offered to the modifiers.
    auto filter_visitor = [this](const auto& store) {
        if constexpr (std::is_same_v<std::decay_t<decltype(store)>, std::monostate>)
        {
            return VisitResult::kNeedsPassthrough;
        }
        else
        {
            return FilterMetaData(*store);
        }
    };

    if (std::visit(filter_visitor, parsed_block.GetArgs()) != kNeedsPassthrough)
    {
        return FileOptimizer::ProcessMetaData(parsed_block);
    }

    if (!parsed_block.Decompress(GetCompressor(), working_uncompressed_store_))
    {
        return false;
    }

    // Meta-data blocks carry no call parameters, but a BlockEdit still needs one to reference.
    encode::ParameterBuffer buffer;

    auto dispatch_visitor = [this, &parsed_block, &buffer](const auto& store) {
        if constexpr (std::is_same_v<std::decay_t<decltype(store)>, std::monostate>)
        {
            return true;
        }
        else if constexpr (decode::DispatchAlternativeTraits<decltype(store)>::kHasMetaDataId)
        {
            return ModifierDispatch(*store, parsed_block, buffer);
        }
        else
        {
            return FileTransformer::WriteBytes(parsed_block);
        }
    };

    return std::visit(dispatch_visitor, parsed_block.GetArgs());
}

template <typename Args>
bool VulkanFileOptimizer::ModifierDispatch(const Args&              args,
                                           decode::ParsedBlock&     parsed_block,
                                           encode::ParameterBuffer& buffer)
{
    BlockEdit block_edit(buffer);

    if (decode::file_processor::DecoderSupportsDispatch(decoder_, args))
    {
        constexpr auto decode_method = decode::DispatchTraits<Args>::kDecoderMethod;

        [[maybe_unused]] decode::DecoderAllocGuard<decode::DispatchTraits<Args>::kHasAllocGuard> alloc_guard{};
        decode::file_processor::SetDecoderApiCallId(decoder_, args);
        auto dispatch_call = [this, decode_method](auto&&... expanded_args) {
            (decoder_.*decode_method)(std::forward<decltype(expanded_args)>(expanded_args)...);
        };

        // Modifiers run one at a time, each seeing the buffer as the previous one left it.
        for (auto& modifier : modifiers_)
        {
            modifier->SetCurrentBlockIndex(GetCurrentBlockIndex());
            modifier->SetCurrentBlockEdit(&block_edit);
            decoder_.AddConsumer(modifier.get());
            std::apply(dispatch_call, args.GetTuple());
            decoder_.RemoveConsumer(modifier.get());
            modifier->SetCurrentBlockEdit(nullptr);
        }
    }

    if (!WriteQueuedCalls(block_edit.Calls(BlockEdit::Position::kBefore)))
    {
        return false;
    }

    if (block_edit.IsBlockDropped())
    {
        // Replace the block with an annotation, so that block indices stay aligned.
        ++num_removed_blocks_;

        bool written = false;
        if constexpr (std::is_same_v<Args, decode::FunctionCallArgs>)
        {
            written = WriteAnnotation(format::kAnnotationLabelRemovedFunctionCall,
                                      "Removed API call: " + std::to_string(static_cast<uint32_t>(args.call_id)));
        }
        else
        {
            written =
                WriteAnnotation(format::kAnnotationLabelRemovedResource,
                                "Removed meta-data block: " + std::to_string(static_cast<uint32_t>(args.meta_data_id)));
        }

        if (!written)
        {
            return false;
        }
    }
    else
    {
        bool written = false;
        if constexpr (std::is_same_v<Args, decode::FunctionCallArgs>)
        {
            // Pass the original block through untouched unless a modifier rewrote its parameters.
            const bool rewritten = (buffer.GetDataSize() != args.data_size) ||
                                   (std::memcmp(buffer.GetData(), args.data, args.data_size) != 0);
            written =
                rewritten
                    ? WriteFunctionCall(args.call_id, args.call_info.thread_id, buffer.GetData(), buffer.GetDataSize())
                    : FileTransformer::WriteBytes(parsed_block);
        }
        else
        {
            written = FileTransformer::WriteBytes(parsed_block);
        }

        if (!written)
        {
            return false;
        }
    }

    return WriteQueuedCalls(block_edit.Calls(BlockEdit::Position::kAfter));
}

bool VulkanFileOptimizer::WriteQueuedCalls(const std::vector<BlockEdit::QueuedCall>& calls)
{
    for (const auto& call : calls)
    {
        switch (call.kind)
        {
            case BlockEdit::CallType::kApiCall:
                if (!WriteFunctionCall(call.call_id, call.thread_id, call.data.data(), call.data.size()))
                {
                    return false;
                }
                break;
            case BlockEdit::CallType::kMetaCommand:
                // Meta-commands use custom structs and are not compressed, so the modifier has
                // already serialised the whole block.
                if (!WriteBytes(call.data.data(), call.data.size()))
                {
                    HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write meta-command data");
                    return false;
                }
                break;
        }
    }
    return true;
}

// TODO: consolidate with the same block writing in framework/encode/vulkan_state_writer.cpp,
// framework/encode/dx12_state_writer.cpp, framework/encode/openxr_state_writer.cpp and
// tools/compress/compression_converter.cpp.
bool VulkanFileOptimizer::WriteFunctionCall(format::ApiCallId call_id,
                                            format::ThreadId  thread_id,
                                            const uint8_t*    data,
                                            size_t            size)
{
    bool                                 not_compressed      = true;
    format::CompressedFunctionCallHeader compressed_header   = {};
    format::FunctionCallHeader           uncompressed_header = {};
    size_t                               uncompressed_size   = size;
    size_t                               header_size         = 0;
    const void*                          header_pointer      = nullptr;
    size_t                               data_size           = 0;
    const void*                          data_pointer        = nullptr;

    util::Compressor*     compressor                  = GetCompressor();
    std::vector<uint8_t>& compressed_parameter_buffer = GetCompressedParameterBuffer();

    if (compressor != nullptr)
    {
        size_t compressed_size = compressor->Compress(uncompressed_size, data, &compressed_parameter_buffer, 0);

        // A compressed block carries an extra uncompressed_size field, so count it against the win.
        if ((0 < compressed_size) &&
            ((compressed_size + sizeof(format::CompressedFunctionCallHeader::uncompressed_size)) < uncompressed_size))
        {
            data_pointer   = compressed_parameter_buffer.data();
            data_size      = compressed_size;
            header_pointer = &compressed_header;
            header_size    = sizeof(format::CompressedFunctionCallHeader);

            compressed_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
            compressed_header.api_call_id       = call_id;
            compressed_header.thread_id         = thread_id;
            compressed_header.uncompressed_size = uncompressed_size;
            compressed_header.block_header.size = sizeof(compressed_header.api_call_id) +
                                                  sizeof(compressed_header.uncompressed_size) +
                                                  sizeof(compressed_header.thread_id) + compressed_size;
            not_compressed = false;
        }
    }

    if (not_compressed)
    {
        data_pointer   = data;
        data_size      = uncompressed_size;
        header_pointer = &uncompressed_header;
        header_size    = sizeof(format::FunctionCallHeader);

        uncompressed_header.block_header.type = format::BlockType::kFunctionCallBlock;
        uncompressed_header.api_call_id       = call_id;
        uncompressed_header.thread_id         = thread_id;
        uncompressed_header.block_header.size =
            sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;
    }

    if (!WriteBytes(header_pointer, header_size) || !WriteBytes(data_pointer, data_size))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write function call data");
        return false;
    }

    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
