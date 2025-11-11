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
#include "util/platform.h"

#include <cassert>
#include <string>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

FileOptimizer::FileOptimizer(const std::unordered_set<format::HandleId>& unreferenced_ids) :
    unreferenced_ids_(unreferenced_ids)
{}

FileOptimizer::FileOptimizer(std::unordered_set<format::HandleId>&& unreferenced_ids) :
    unreferenced_ids_(std::move(unreferenced_ids))
{}

void FileOptimizer::SetUnreferencedBlocks(const std::unordered_set<uint64_t>& unreferenced_blocks)
{
    unreferenced_blocks_ = unreferenced_blocks;
}

uint64_t FileOptimizer::GetUnreferencedBlocksSize()
{
    return unreferenced_blocks_.size();
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
    const auto& args       = parsed_block.Get<decode::MethodCallArgs>();
    bool        filter_out = FilterMethodCall(args);

    if (!filter_out)
    {
        // Copy the method call block, if it was not filtered.
        return FileTransformer::ProcessMethodCall(parsed_block);
    }
    return true; // Successful filtering no passthrough write.
}

decode::FileTransformer::VisitResult FileOptimizer::FilterMetaData(const decode::InitBufferArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitBufferCommand);

    // If the buffer is in the unused list, omit its initialization data from the file.
    if (unreferenced_ids_.find(args.buffer_id) != unreferenced_ids_.end())
    {
        // In its place insert a dummy annotation meta command. This should keep the block index when
        // replaying an optimized trimmed capture in in alignment with the block index calculated
        // at capture time
        const char*       label = format::kAnnotationLabelRemovedResource;
        const std::string data  = "Removed buffer " + std::to_string(args.buffer_id);

        const size_t label_length = util::platform::StringLength(label);
        const size_t data_length  = data.length();

        format::AnnotationHeader annotation;
        annotation.block_header.size = format::GetAnnotationBlockBaseSize() + label_length + data_length;
        annotation.block_header.type = format::BlockType::kAnnotation;
        annotation.annotation_type   = format::kText;
        annotation.label_length      = static_cast<uint32_t>(label_length);
        annotation.data_length       = static_cast<uint64_t>(data.length());

        if (!WriteBytes(&annotation, sizeof(annotation)) || !WriteBytes(label, label_length) ||
            !WriteBytes(data.c_str(), data_length))
        {
            HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write annotation meta-data block");
            return kError;
        }
        return kSuccess;
    }

    return kNeedsPassthrough;
}

decode::FileTransformer::VisitResult FileOptimizer::FilterMetaData(const decode::InitImageArgs& args)
{
    GFXRECON_ASSERT(format::GetMetaDataType(args.meta_data_id) == format::MetaDataType::kInitImageCommand);

    // If the image is in the unused list, omit its initialization data from the file.
    if (unreferenced_ids_.find(args.image_id) != unreferenced_ids_.end())
    {
        // In its place insert a dummy annotation meta command. This should keep the block index when
        // replaying an optimized trimmed capture in in alignment with the block index calculated
        // at capture time
        const char*       label = format::kAnnotationLabelRemovedResource;
        const std::string data  = "Removed subresource from image " + std::to_string(args.image_id);

        const size_t label_length = util::platform::StringLength(label);
        const size_t data_length  = data.length();

        format::AnnotationHeader annotation;
        annotation.block_header.size = format::GetAnnotationBlockBaseSize() + label_length + data_length;
        annotation.block_header.type = format::BlockType::kAnnotation;
        annotation.annotation_type   = format::kText;
        annotation.label_length      = static_cast<uint32_t>(label_length);
        annotation.data_length       = static_cast<uint64_t>(data.length());

        if (!WriteBytes(&annotation, sizeof(annotation)) || !WriteBytes(label, label_length) ||
            !WriteBytes(data.c_str(), data_length))
        {
            HandleBlockWriteError(decode::kErrorWritingBlockData, "Failed to write annotation meta-data block");
            return kError;
        }

        return kSuccess;
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
        // NOTE: Erase returns number of items erased, so only > 0 if the block_index is found
        filter_out = (unreferenced_blocks_.erase(block_index) > 0);
    }
    return filter_out;
}

GFXRECON_END_NAMESPACE(gfxrecon)
