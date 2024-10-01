/*
** Copyright (c) 2022 LunarG, Inc.
** Copyright (c) 2022 Advanced Micro Devices, Inc. All rights reserved.
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

#include "block_skipping_file_processor.h"

#include "decode/decode_allocator.h"
#include "format/format_util.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

void BlockSkippingFileProcessor::SetBlocksToSkip(std::unordered_set<uint64_t> blocks_to_skip)
{
    blocks_to_skip_ = blocks_to_skip;
    blocks_skipped_ = 0;
}

bool BlockSkippingFileProcessor::IsSkippingFinished()
{
    return blocks_skipped_ == blocks_to_skip_.size();
}

bool BlockSkippingFileProcessor::ShouldSkipBlock()
{
    return (!(blocks_to_skip_.empty())) && (blocks_to_skip_.find(block_index_) != blocks_to_skip_.end());
}

bool BlockSkippingFileProcessor::ProcessBlocks()
{
    format::BlockHeader block_header;
    bool                success = true;

    while (success)
    {
        PrintBlockInfo();
        success = ContinueDecoding();

        if (success)
        {
            success = ReadBlockHeader(&block_header);

            for (auto decoder : decoders_)
            {
                decoder->SetCurrentBlockIndex(block_index_);
            }

            if (success)
            {
                if (ShouldSkipBlock())
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                    success = SkipBytes(static_cast<size_t>(block_header.size));
                    blocks_skipped_++;
                }
                else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kFunctionCallBlock)
                {
                    format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                    success = ReadBytes(&api_call_id, sizeof(api_call_id));

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessFunctionCall(block_header, api_call_id, should_break);
                        if (should_break)
                        {
                            break;
                        }
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
                    }
                }
                else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMethodCallBlock)
                {
                    format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                    success = ReadBytes(&api_call_id, sizeof(api_call_id));

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessMethodCall(block_header, api_call_id, should_break);

                        if (should_break)
                        {
                            break;
                        }
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
                    }
                }
                else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMetaDataBlock)
                {
                    format::MetaDataId meta_data_id = format::MakeMetaDataId(
                        format::ApiFamilyId::ApiFamily_None, format::MetaDataType::kUnknownMetaDataType);

                    success = ReadBytes(&meta_data_id, sizeof(meta_data_id));

                    if (success)
                    {
                        success = ProcessMetaData(block_header, meta_data_id);
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read meta-data block header");
                    }
                }
                else if (block_header.type == format::BlockType::kFrameMarkerBlock)
                {
                    format::MarkerType marker_type  = format::MarkerType::kUnknownMarker;
                    uint64_t           frame_number = 0;

                    success = ReadBytes(&marker_type, sizeof(marker_type));

                    if (success)
                    {
                        bool should_break = false;
                        success           = ProcessFrameMarker(block_header, marker_type, should_break);

                        if (should_break)
                        {
                            break;
                        }
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read frame marker header");
                    }
                }
                else if (block_header.type == format::BlockType::kStateMarkerBlock)
                {
                    format::MarkerType marker_type  = format::MarkerType::kUnknownMarker;
                    uint64_t           frame_number = 0;

                    success = ReadBytes(&marker_type, sizeof(marker_type));

                    if (success)
                    {
                        success = ProcessStateMarker(block_header, marker_type);
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read state marker header");
                    }
                }
                else if (block_header.type == format::BlockType::kAnnotation)
                {
                    if (annotation_handler_ != nullptr)
                    {
                        format::AnnotationType annotation_type = format::AnnotationType::kUnknown;

                        success = ReadBytes(&annotation_type, sizeof(annotation_type));

                        if (success)
                        {
                            success = ProcessAnnotation(block_header, annotation_type);
                        }
                        else
                        {
                            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read annotation block header");
                        }
                    }
                    else
                    {
                        // If there is no annotation handler to process the annotation, we can skip the annotation
                        // block.
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                        success = SkipBytes(static_cast<size_t>(block_header.size));
                    }
                }
                else
                {
                    // Unrecognized block type.
                    GFXRECON_LOG_WARNING("Skipping unrecognized file block with type %u", block_header.type);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                    success = SkipBytes(static_cast<size_t>(block_header.size));
                }
            }
            else
            {
                if (!feof(GetFileDescriptor()))
                {
                    // No data has been read for the current block, so we don't use 'HandleBlockReadError' here, as it
                    // assumes that the block header has been successfully read and will print an incomplete block at
                    // end of file warning when the file is at EOF without an error. For this case (the normal EOF case)
                    // we print nothing at EOF, or print an error message and set the error code directly when not at
                    // EOF.
                    GFXRECON_LOG_ERROR("Failed to read block header");
                    error_state_ = kErrorReadingBlockHeader;
                }
            }

            ++block_index_;
        }
    }

    return success;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
