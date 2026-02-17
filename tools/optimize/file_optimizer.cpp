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

#include <cassert>
#include <string>
#include <format>

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
                        std::format("Removed API call: {}", static_cast<uint32_t>(args.call_id)));

        // success, call is filtered out
        return true;
    }
    return FileTransformer::ProcessFunctionCall(parsed_block);
}

bool FileOptimizer::ProcessMetaData(decode::ParsedBlock& parsed_block)
{
    auto filter_visitor = [this](const auto& store) { return FilterMetaData(*store); };

    VisitResult result = std::visit(filter_visitor, parsed_block.GetArgs());

    if (result == kNeedsPassthrough)
    {
        return FileTransformer::ProcessMetaData(parsed_block);
    }
    return result == kSuccess;
}

bool FileOptimizer::ProcessMethodCall(decode::ParsedBlock& parsed_block)
{
    if (FilterMethodCall(parsed_block.Get<decode::MethodCallArgs>()))
    {
        // success, call is filtered out
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
        return WriteAnnotation(format::kAnnotationLabelRemovedResource,
                               std::format("Removed buffer {}", args.buffer_id))
                   ? kSuccess
                   : kError;
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
        return WriteAnnotation(format::kAnnotationLabelRemovedResource,
                               std::format("Removed subresource from image {}", args.image_id))
                   ? kSuccess
                   : kError;
    }
    return kNeedsPassthrough;
}

// Returns whether or not to filter this MethodCall block or not
bool FileOptimizer::FilterMethodCall(const decode::MethodCallArgs& args)
{
    const format::ApiCallId api_call_id = args.call_id;
    const uint64_t          block_index = args.call_info.index;
    bool                    filter_out  = false;

    // Only a subset of blocks can be filtered out...
    if (api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState ||
        api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState ||
        api_call_id == format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline)
    {
        // If the buffer is in the unused list, omit the call block from the file.
        filter_out = unreferenced_blocks_.contains(block_index);
    }
    return filter_out;
}

bool FileOptimizer::WriteAnnotation(std::string_view label, std::string_view message)
{
    const size_t label_length = label.length();
    const size_t data_length  = message.length();

    format::AnnotationHeader annotation{};
    annotation.block_header.size = format::GetAnnotationBlockBaseSize() + label_length + data_length;
    annotation.block_header.type = format::BlockType::kAnnotation;
    annotation.annotation_type   = format::kText;
    annotation.label_length      = static_cast<uint32_t>(label.length());
    annotation.data_length       = static_cast<uint64_t>(message.length());

    if (!WriteBytes(&annotation, sizeof(annotation)) || !WriteBytes(label.data(), label_length) ||
        !WriteBytes(message.data(), data_length))
    {
        HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write annotation meta-data block");
        return false;
    }
    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
