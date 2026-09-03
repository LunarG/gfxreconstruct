/*
** Copyright (c) 2020 LunarG, Inc.
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

#include "file_optimizer.h"

#include "format/format.h"
#include "format/format_util.h"
#include "util/logging.h"

#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

FileOptimizer::FileOptimizer(const std::unordered_set<format::HandleId>& unreferenced_ids,
                             const std::unordered_set<uint64_t>&         unreferenced_blocks) :
    unreferenced_ids_(unreferenced_ids),
    unreferenced_blocks_(unreferenced_blocks)
{}

bool FileOptimizer::ProcessFunctionCall(decode::ParsedBlock& parsed_block)
{
    const auto&    args        = parsed_block.Get<decode::FunctionCallArgs>();
    const uint64_t block_index = args.call_info.index;

    if (unreferenced_blocks_.contains(block_index))
    {
        WriteAnnotation(format::kAnnotationLabelRemovedFunctionCall,
                        std::string("Removed API call: ") + std::to_string(static_cast<uint32_t>(args.call_id)));

        // block is filtered out
        ++num_removed_blocks_;
        return true;
    }
    return FileTransformer::ProcessFunctionCall(parsed_block);
}

bool FileOptimizer::ProcessMetaData(decode::ParsedBlock& parsed_block)
{
    auto filter_visitor = [this](const auto& store) {
        if constexpr (std::is_same_v<std::decay_t<decltype(store)>, std::monostate>)
        {
            return VisitResult::kNeedsPassthrough; // Passthrough unknown blocks.
        }
        else
        {
            return FilterMetaData(*store);
        }
    };

    VisitResult result = std::visit(filter_visitor, parsed_block.GetArgs());

    if (result == kNeedsPassthrough)
    {
        return FileTransformer::ProcessMetaData(parsed_block);
    }

    // block is filtered out
    ++num_removed_blocks_;
    return result == kSuccess;
}

bool FileOptimizer::ProcessMethodCall(decode::ParsedBlock& parsed_block)
{
    if (FilterMethodCall(parsed_block.Get<decode::MethodCallArgs>()))
    {
        // block is filtered out
        ++num_removed_blocks_;
        return true;
    }

    // Copy the method call block, if it was not filtered.
    return FileTransformer::ProcessMethodCall(parsed_block);
}

decode::FileTransformer::VisitResult FileOptimizer::FilterMetaData(const decode::InitBufferArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitBufferCommand);

    // If the buffer is in the unused list, omit its initialization data from the file.
    if (unreferenced_ids_.contains(args.buffer_id))
    {
        // In its place insert a dummy annotation meta command. This should keep the block index when
        // replaying an optimized trimmed capture in in alignment with the block index calculated
        // at capture time
        const std::string annotation_string = std::string("Removed kInitBufferCommand for buffer ") +
                                              std::to_string(args.buffer_id) + std::string(" (") +
                                              std::to_string(args.data_size) + std::string(" bytes)");

        return WriteAnnotation(format::kAnnotationLabelRemovedResource, annotation_string) ? kSuccess : kError;
    }
    return kNeedsPassthrough;
}

decode::FileTransformer::VisitResult FileOptimizer::FilterMetaData(const decode::InitImageArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitImageCommand);

    // If the image is in the unused list, omit its initialization data from the file.
    if (unreferenced_ids_.contains(args.image_id))
    {
        // In its place insert a dummy annotation meta command. This should keep the block index when
        // replaying an optimized trimmed capture in in alignment with the block index calculated
        // at capture time
        const std::string annotation_string = std::string("Removed kInitImageCommand for image ") +
                                              std::to_string(args.image_id) + std::string(" (") +
                                              std::to_string(args.data_size) + std::string(" bytes)");

        return WriteAnnotation(format::kAnnotationLabelRemovedResource, annotation_string) ? kSuccess : kError;
    }
    return kNeedsPassthrough;
}

decode::FileTransformer::VisitResult FileOptimizer::FilterMetaData(const decode::InitTensorArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitTensorCommand);

    // If the tensor is in the unused list, omit its initialization data from the file.
    if (unreferenced_ids_.find(args.tensor_id) != unreferenced_ids_.end())
    {
        // In its place insert a dummy annotation meta command. This should keep the block index when
        // replaying an optimized trimmed capture in in alignment with the block index calculated
        // at capture time
        const std::string annotation_string = std::string("Removed kInitTensorCommand for tensor ") +
                                              std::to_string(args.tensor_id) + std::string(" (") +
                                              std::to_string(args.data_size) + std::string(" bytes)");

        return WriteAnnotation(format::kAnnotationLabelRemovedResource, annotation_string) ? kSuccess : kError;
    }
    return kNeedsPassthrough;
}

// Returns whether to filter this MethodCall block or not
bool FileOptimizer::FilterMethodCall(const decode::MethodCallArgs& args) const
{
    const format::ApiCallId api_call_id = args.call_id;
    const uint64_t          block_index = args.call_info.index;

    // Only a subset of blocks can be filtered out...
    if (api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState ||
        api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState ||
        api_call_id == format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline)
    {
        // If the buffer is in the unused list, omit the call block from the file.
        return unreferenced_blocks_.contains(block_index);
    }
    return false;
}

bool FileOptimizer::WriteAnnotation(std::string_view label, std::string_view message)
{
    const size_t label_length = label.length();
    const size_t data_length  = message.length();

    const format::AnnotationHeader annotation = format::MakeAnnotationHeader(format::kText, label_length, data_length);

    if (!WriteBytes(&annotation, sizeof(annotation)) || !WriteBytes(label.data(), label_length) ||
        !WriteBytes(message.data(), data_length))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write annotation meta-data block");
        return false;
    }
    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
