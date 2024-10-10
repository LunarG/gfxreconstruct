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

bool FileOptimizer::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
{
    format::MetaDataType meta_data_type = format::GetMetaDataType(meta_data_id);
    if (meta_data_type == format::MetaDataType::kInitBufferCommand)
    {
        return FilterInitBufferMetaData(block_header, meta_data_id);
    }
    else if (meta_data_type == format::MetaDataType::kInitImageCommand)
    {
        return FilterInitImageMetaData(block_header, meta_data_id);
    }
    else
    {
        // Copy the meta data block, if it was not filtered.
        return FileTransformer::ProcessMetaData(block_header, meta_data_id);
    }
}

bool FileOptimizer::ProcessMethodCall(const format::BlockHeader& block_header,
                                      format::ApiCallId          api_call_id,
                                      uint64_t                   block_index)
{
    if (api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState ||
        api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState ||
        api_call_id == format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline)
    {
        return FilterMethodCall(block_header, api_call_id, block_index);
    }
    else
    {
        // Copy the method call block, if it was not filtered.
        return FileTransformer::ProcessMethodCall(block_header, api_call_id);
    }
}

bool FileOptimizer::FilterInitBufferMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
{
    GFXRECON_ASSERT(format::GetMetaDataType(meta_data_id) == format::MetaDataType::kInitBufferCommand);

    format::InitBufferCommandHeader header;

    bool success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
    success      = success && ReadBytes(&header.device_id, sizeof(header.device_id));
    success      = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
    success      = success && ReadBytes(&header.data_size, sizeof(header.data_size));

    if (success)
    {
        // Total number of bytes remaining to be read for the current block.
        uint64_t unread_bytes = block_header.size - (sizeof(header) - sizeof(block_header));

        // If the buffer is in the unused list, omit its initialization data from the file.
        if (unreferenced_ids_.find(header.buffer_id) != unreferenced_ids_.end())
        {
            // In its place insert a dummy annotation meta command. This should keep the block index when
            // replaying an optimized trimmed capture in in alignment with the block index calculated
            // at capture time
            const char*       label = format::kAnnotationLabelRemovedResource;
            const std::string data  = "Removed buffer " + std::to_string(header.buffer_id);

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
                HandleBlockWriteError(kErrorReadingBlockHeader, "Failed to write annotation meta-data block");
                return false;
            }

            if (!SkipBytes(unread_bytes))
            {
                HandleBlockReadError(kErrorSeekingFile, "Failed to skip init buffer data meta-data block data");
                return false;
            }
        }
        else
        {
            // Copy the block from the input file to the output file.
            header.meta_header.block_header = block_header;
            header.meta_header.meta_data_id = meta_data_id;

            if (!WriteBytes(&header, sizeof(header)))
            {
                HandleBlockWriteError(kErrorReadingBlockHeader,
                                      "Failed to write init buffer data meta-data block header");
                return false;
            }

            if (!CopyBytes(unread_bytes))
            {
                HandleBlockCopyError(kErrorCopyingBlockData, "Failed to copy init buffer data meta-data block data");
                return false;
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init buffer data meta-data block header");
        return false;
    }

    return true;
}

bool FileOptimizer::FilterInitImageMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
{
    GFXRECON_ASSERT(format::GetMetaDataType(meta_data_id) == format::MetaDataType::kInitImageCommand);

    format::InitImageCommandHeader header;
    std::vector<uint64_t>          level_sizes;

    bool success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
    success      = success && ReadBytes(&header.device_id, sizeof(header.device_id));
    success      = success && ReadBytes(&header.image_id, sizeof(header.image_id));
    success      = success && ReadBytes(&header.data_size, sizeof(header.data_size));
    success      = success && ReadBytes(&header.aspect, sizeof(header.aspect));
    success      = success && ReadBytes(&header.layout, sizeof(header.layout));
    success      = success && ReadBytes(&header.level_count, sizeof(header.level_count));

    if (success)
    {
        // Total number of bytes remaining to be read for the current block.
        uint64_t unread_bytes = block_header.size - (sizeof(header) - sizeof(block_header));

        // If the image is in the unused list, omit its initialization data from the file.
        if (unreferenced_ids_.find(header.image_id) != unreferenced_ids_.end())
        {
            // In its place insert a dummy annotation meta command. This should keep the block index when
            // replaying an optimized trimmed capture in in alignment with the block index calculated
            // at capture time
            const char*       label = format::kAnnotationLabelRemovedResource;
            const std::string data  = "Removed subresource from image " + std::to_string(header.image_id);

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
                HandleBlockWriteError(kErrorReadingBlockHeader, "Failed to write annotation meta-data block");
                return false;
            }

            if (!SkipBytes(unread_bytes))
            {
                HandleBlockReadError(kErrorSeekingFile, "Failed to skip init image data meta-data block data");
                return false;
            }
        }
        else
        {
            // Copy the block from the input file to the output file.
            header.meta_header.block_header = block_header;
            header.meta_header.meta_data_id = meta_data_id;

            if (!WriteBytes(&header, sizeof(header)))
            {
                HandleBlockWriteError(kErrorReadingBlockHeader,
                                      "Failed to write init image data meta-data block header");
                return false;
            }

            if (!CopyBytes(unread_bytes))
            {
                HandleBlockCopyError(kErrorCopyingBlockData, "Failed to copy init image data meta-data block data");
                return false;
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init image data meta-data block header");
        return false;
    }

    return true;
}

bool FileOptimizer::FilterMethodCall(const format::BlockHeader& block_header,
                                     format::ApiCallId          api_call_id,
                                     uint64_t                   block_index)
{
    GFXRECON_ASSERT(api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateGraphicsPipelineState ||
                    api_call_id == format::ApiCallId::ApiCall_ID3D12Device_CreateComputePipelineState ||
                    api_call_id == format::ApiCallId::ApiCall_ID3D12PipelineLibrary_StorePipeline);

    // Total number of bytes remaining to be read for the current block.
    uint64_t unread_bytes = block_header.size - sizeof(format::ApiCallId);

    // If the buffer is in the unused list, omit the call block from the file.
    if (unreferenced_blocks_.find(block_index) != unreferenced_blocks_.end())
    {
        unreferenced_blocks_.erase(block_index);
        if (!SkipBytes(unread_bytes))
        {
            HandleBlockReadError(kErrorSeekingFile, "Failed to skip method call block data");
            return false;
        }
    }
    else
    {
        return FileTransformer::ProcessMethodCall(block_header, api_call_id);
    }

    return true;
}

GFXRECON_END_NAMESPACE(gfxrecon)
