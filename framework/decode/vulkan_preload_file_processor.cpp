/*
** Copyright (c) 2023 LunarG, Inc.
** Copyright (c) 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "decode/vulkan_preload_file_processor.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanPreloadFileProcessor::VulkanPreloadFileProcessor() :
    status_(PreloadStatus::kInactive), vulkan_preload_decoder_(nullptr)
{}

void VulkanPreloadFileProcessor::ReplayPreloadedPackets()
{
    vulkan_preload_replayer_.ReplayPackets(vulkan_preload_decoder_);
}
void VulkanPreloadFileProcessor::PreloadNextFrames(size_t count)
{
    preload_frames_ = count;
    status_         = PreloadStatus::kRecord;
    while (count-- != 0U)
    {
        if (!ProcessNextFrame())
        {
            break;
        }
    }
    status_ = PreloadStatus::kReplay;
}

bool VulkanPreloadFileProcessor::ProcessNextFrame()
{
    bool success = true;
    switch (status_)
    {
        case PreloadStatus::kInactive:
        case PreloadStatus::kRecord:
            success = IsFileValid();
            break;
        case PreloadStatus::kReplay:
            success = (GetErrorState() == Error::kErrorNone);
        default:
            break;
    }

    if (success)
    {
        success = ProcessBlocks();
    }
    else
    {
        // If not EOF, determine reason for invalid state.
        if (file_descriptor_ == nullptr)
        {
            error_state_ = kErrorInvalidFileDescriptor;
        }
        else if (ferror(file_descriptor_))
        {
            error_state_ = kErrorReadingFile;
        }
    }

    return success;
}

bool VulkanPreloadFileProcessor::ProcessBlocks()
{
    format::BlockHeader block_header;
    bool                success = true;

    while (success)
    {
        if (enable_print_block_info_ && ((block_index_from_ < 0 || block_index_to_ < 0) ||
                                         (block_index_from_ <= block_index_ && block_index_to_ >= block_index_)))
        {
            GFXRECON_LOG_INFO(
                "block info: index: %" PRIu64 ", current frame: %" PRIu64 "", block_index_, current_frame_number_);
        }
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
                if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kFunctionCallBlock)
                {
                    format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                    success = ReadBytes(&api_call_id, sizeof(api_call_id));

                    if (success)
                    {
                        bool should_break = false;
                        if (status_ == PreloadStatus::kRecord)
                        {
                            success = ProcessFunctionCall(block_header, api_call_id, should_break);
                        }
                        else
                        {
                            success = FileProcessor::ProcessFunctionCall(block_header, api_call_id, should_break);
                        }

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
                        if (status_ == PreloadStatus::kRecord)
                        {
                            success = ProcessMetaData(block_header, meta_data_id);
                        }
                        else
                        {
                            success = FileProcessor::ProcessMetaData(block_header, meta_data_id);
                        }
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
                        success           = FileProcessor::ProcessFrameMarker(block_header, marker_type, should_break);

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
                        success = FileProcessor::ProcessStateMarker(block_header, marker_type);
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
                            success = FileProcessor::ProcessAnnotation(block_header, annotation_type);
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
                if (!feof(file_descriptor_))
                {
                    // No data has been read for the current block, so we don't use 'HandleBlockReadError' here, as it
                    // assumes that the block header has been successfully read and will print an incomplete block at
                    // end of file warning when the file is at EOF without an error. For this case (the normal EOF case)
                    // we print nothing at EOF, or print an error message and set the error code directly when not at
                    // EOF.
                    GFXRECON_LOG_ERROR("Failed to read block header (frame %u block %" PRIu64 ")",
                                       current_frame_number_,
                                       block_index_);
                    error_state_ = kErrorReadingBlockHeader;
                }
            }
        }

        {
            ++block_index_;
        }
    }

    return success;
}

bool VulkanPreloadFileProcessor::ProcessFunctionCall(const format::BlockHeader& block_header,
                                                     format::ApiCallId          call_id,
                                                     bool&                      should_break)
{
    size_t      parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t    uncompressed_size     = 0;
    ApiCallInfo call_info{ block_index_ };
    bool        success = ReadBytes(&call_info.thread_id, sizeof(call_info.thread_id));

    if (success)
    {
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

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsApiCall(call_id))
            {
                DecodeAllocator::Begin();
                vulkan_preload_decoder_->DecodeFunctionCall(
                    call_id, call_info, parameter_buffer_.data(), parameter_buffer_size);
                DecodeAllocator::End();
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    // Break from loop on frame delimiter.
    if (IsFrameDelimiter(call_id))
    {
        // Make sure to increment the frame number on the way out.
        ++current_frame_number_;
        ++block_index_;
        should_break = true;
    }
    return success;
}

bool VulkanPreloadFileProcessor::ProcessMetaData(const format::BlockHeader& block_header,
                                                 format::MetaDataId         meta_data_id)
{
    bool success = false;

    format::MetaDataType meta_data_type = format::GetMetaDataType(meta_data_id);

    if (meta_data_type == format::MetaDataType::kFillMemoryCommand)
    {
        format::FillMemoryCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success = success && ReadBytes(&header.memory_offset, sizeof(header.memory_offset));
        success = success && ReadBytes(&header.memory_size, sizeof(header.memory_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.memory_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_data_id) -
                                         sizeof(header.thread_id) - sizeof(header.memory_id) -
                                         sizeof(header.memory_offset) - sizeof(header.memory_size);

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.memory_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.memory_size));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchFillMemoryCommand(header.thread_id,
                                                                       header.memory_id,
                                                                       header.memory_offset,
                                                                       header.memory_size,
                                                                       parameter_buffer_.data());
                }
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read fill memory meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData, "Failed to read fill memory meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read fill memory meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kFixDeviceAddressCommand)
    {
        format::FixDeviceAddressCommandHeader header;
        success        = ReadBytes(&header.relation_id, sizeof(header.relation_id));
        success        = ReadBytes(&header.num_of_locations, sizeof(header.num_of_locations));
        auto locations = new format::AddressLocationInfo[header.num_of_locations];
        success        = ReadBytes(locations, header.num_of_locations * sizeof(format::AddressLocationInfo));

        if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
        {
            vulkan_preload_decoder_->DispatchFixDeviceAddresCommand(header, locations);
        }
        delete[] locations;
    }
    else if (meta_data_type == format::MetaDataType::kFillMemoryResourceValueCommand)
    {
        format::FillMemoryResourceValueCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = ReadBytes(&header.resource_value_count, sizeof(header.resource_value_count));

        if (success)
        {
            uint64_t data_size = header.resource_value_count * (sizeof(format::ResourceValueType) + sizeof(uint64_t));
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size   = static_cast<size_t>(block_header.size) - sizeof(meta_data_id) -
                                         sizeof(header.thread_id) - sizeof(header.resource_value_count);
                size_t uncompressed_data = static_cast<size_t>(data_size);
                success = ReadCompressedParameterBuffer(compressed_size, uncompressed_data, &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(data_size));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchFillMemoryResourceValueCommand(header, parameter_buffer_.data());
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read fill memory resource value meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read fill memory resource value meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kResizeWindowCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ResizeWindowCommand command;

        success = ReadBytes(&command.thread_id, sizeof(command.thread_id));
        success = success && ReadBytes(&command.surface_id, sizeof(command.surface_id));
        success = success && ReadBytes(&command.width, sizeof(command.width));
        success = success && ReadBytes(&command.height, sizeof(command.height));

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchResizeWindowCommand(
                    command.thread_id, command.surface_id, command.width, command.height);
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read resize window meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kResizeWindowCommand2)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ResizeWindowCommand2 command;

        success = ReadBytes(&command.thread_id, sizeof(command.thread_id));
        success = success && ReadBytes(&command.surface_id, sizeof(command.surface_id));
        success = success && ReadBytes(&command.width, sizeof(command.width));
        success = success && ReadBytes(&command.height, sizeof(command.height));
        success = success && ReadBytes(&command.pre_transform, sizeof(command.pre_transform));

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchResizeWindowCommand2(
                    command.thread_id, command.surface_id, command.width, command.height, command.pre_transform);
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read resize window 2 meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kExeFileInfoCommand)
    {
        format::ExeFileInfoBlock header;
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));

        success =
            success && ReadBytes(&header.info_record.ProductVersion, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.FileVersion, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.AppVersion,
                                       sizeof(uint32_t) * gfxrecon::util::filepath::kFileVersionSize);
        success = success && ReadBytes(&header.info_record.AppName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.CompanyName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success =
            success && ReadBytes(&header.info_record.FileDescription, gfxrecon::util::filepath::kMaxFilePropertySize);
        success =
            success && ReadBytes(&header.info_record.InternalName, gfxrecon::util::filepath::kMaxFilePropertySize);
        success =
            success && ReadBytes(&header.info_record.OriginalFilename, gfxrecon::util::filepath::kMaxFilePropertySize);
        success = success && ReadBytes(&header.info_record.ProductName, gfxrecon::util::filepath::kMaxFilePropertySize);

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchExeFileInfo(header.thread_id, header);
            }
        }
    }
    else if (meta_data_type == format::MetaDataType::kDriverInfoCommand)
    {
        format::DriverInfoBlock header;
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));

        success = success && ReadBytes(&header.driver_record, gfxrecon::util::filepath::kMaxDriverInfoSize);

        if (success)
        {
            for (auto decoder : decoders_)
            {
                decoder->DispatchDriverInfo(header.thread_id, header);
            }
        }
    }
    else if (meta_data_type == format::MetaDataType::kDisplayMessageCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::DisplayMessageCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));

        if (success)
        {
            uint64_t message_size = block_header.size - sizeof(meta_data_id) - sizeof(header.thread_id);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, message_size);

            success = ReadParameterBuffer(static_cast<size_t>(message_size));

            if (success)
            {
                auto        message_start = parameter_buffer_.begin();
                std::string message(message_start, std::next(message_start, static_cast<size_t>(message_size)));

                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchDisplayMessageCommand(header.thread_id, message);
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read display message meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read display message meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHardwareBufferCommand_deprecated)
    {
        format::CreateHardwareBufferCommandHeader_deprecated header;

        GFXRECON_LOG_WARNING_ONCE(
            "This capture contains a deprecated metacommand to create an AHardwareBuffer.  While still supported, this "
            "metacommand may not correctly represent some state of the captured AHardwareBuffer.");

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
        success = success && ReadBytes(&header.format, sizeof(header.format));
        success = success && ReadBytes(&header.width, sizeof(header.width));
        success = success && ReadBytes(&header.height, sizeof(header.height));
        success = success && ReadBytes(&header.stride, sizeof(header.stride));
        success = success && ReadBytes(&header.usage, sizeof(header.usage));
        success = success && ReadBytes(&header.layers, sizeof(header.layers));
        success = success && ReadBytes(&header.planes, sizeof(header.planes));

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!ReadBytes(&entry, sizeof(entry)))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchCreateHardwareBufferCommand(header.thread_id,
                                                                                 header.memory_id,
                                                                                 header.buffer_id,
                                                                                 header.format,
                                                                                 header.width,
                                                                                 header.height,
                                                                                 header.stride,
                                                                                 header.usage,
                                                                                 header.layers,
                                                                                 entries);
                }
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read create hardware buffer meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHardwareBufferCommand)
    {
        format::CreateHardwareBufferCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.memory_id, sizeof(header.memory_id));
        success = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
        success = success && ReadBytes(&header.format, sizeof(header.format));
        success = success && ReadBytes(&header.width, sizeof(header.width));
        success = success && ReadBytes(&header.height, sizeof(header.height));
        success = success && ReadBytes(&header.stride, sizeof(header.stride));
        success = success && ReadBytes(&header.usage, sizeof(header.usage));
        success = success && ReadBytes(&header.layers, sizeof(header.layers));
        success = success && ReadBytes(&header.planes, sizeof(header.planes));

        if (success)
        {
            std::vector<format::HardwareBufferPlaneInfo> entries;

            for (uint64_t i = 0; i < header.planes; ++i)
            {
                format::HardwareBufferPlaneInfo entry;

                if (!ReadBytes(&entry, sizeof(entry)))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchCreateHardwareBufferCommand(header.thread_id,
                                                                                 header.memory_id,
                                                                                 header.buffer_id,
                                                                                 header.format,
                                                                                 header.width,
                                                                                 header.height,
                                                                                 header.stride,
                                                                                 header.usage,
                                                                                 header.layers,
                                                                                 entries);
                }
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read create hardware buffer meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read create hardware buffer meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kDestroyHardwareBufferCommand)
    {
        format::DestroyHardwareBufferCommand command;

        success = ReadBytes(&command.thread_id, sizeof(command.thread_id));
        success = success && ReadBytes(&command.buffer_id, sizeof(command.buffer_id));

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchDestroyHardwareBufferCommand(command.thread_id, command.buffer_id);
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read destroy hardware buffer meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kCreateHeapAllocationCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::CreateHeapAllocationCommand header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.allocation_id, sizeof(header.allocation_id));
        success = success && ReadBytes(&header.allocation_size, sizeof(header.allocation_size));

        if (success)
        {

            vulkan_preload_decoder_->DispatchCreateHeapAllocationCommand(
                header.thread_id, header.allocation_id, header.allocation_size);
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read create heap allocation meta-data block");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetDevicePropertiesCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetDevicePropertiesCommand header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.physical_device_id, sizeof(header.physical_device_id));
        success = success && ReadBytes(&header.api_version, sizeof(header.api_version));
        success = success && ReadBytes(&header.driver_version, sizeof(header.driver_version));
        success = success && ReadBytes(&header.vendor_id, sizeof(header.vendor_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.device_type, sizeof(header.device_type));
        success = success && ReadBytes(&header.pipeline_cache_uuid, format::kUuidSize);
        success = success && ReadBytes(&header.device_name_len, sizeof(header.device_name_len));

        if (success)
        {
            char device_name[format::kMaxPhysicalDeviceNameSize];

            if (header.device_name_len < format::kMaxPhysicalDeviceNameSize)
            {
                success                             = success && ReadBytes(&device_name, header.device_name_len);
                device_name[header.device_name_len] = '\0';
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchSetDevicePropertiesCommand(header.thread_id,
                                                                                header.physical_device_id,
                                                                                header.api_version,
                                                                                header.driver_version,
                                                                                header.vendor_id,
                                                                                header.device_id,
                                                                                header.device_type,
                                                                                header.pipeline_cache_uuid,
                                                                                device_name);
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read set device memory properties meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set device memory properties meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetDeviceMemoryPropertiesCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetDeviceMemoryPropertiesCommand header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.physical_device_id, sizeof(header.physical_device_id));
        success = success && ReadBytes(&header.memory_type_count, sizeof(header.memory_type_count));
        success = success && ReadBytes(&header.memory_heap_count, sizeof(header.memory_heap_count));

        if (success)
        {
            std::vector<format::DeviceMemoryType> types;
            std::vector<format::DeviceMemoryHeap> heaps;

            for (uint32_t i = 0; i < header.memory_type_count; ++i)
            {
                format::DeviceMemoryType type;

                if (!ReadBytes(&type, sizeof(type)))
                {
                    success = false;
                    break;
                }

                types.emplace_back(std::move(type));
            }

            for (uint32_t i = 0; i < header.memory_heap_count; ++i)
            {
                format::DeviceMemoryHeap heap;

                if (!ReadBytes(&heap, sizeof(heap)))
                {
                    success = false;
                    break;
                }

                heaps.emplace_back(std::move(heap));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchSetDeviceMemoryPropertiesCommand(
                        header.thread_id, header.physical_device_id, types, heaps);
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read set device memory properties meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set device memory properties meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetOpaqueAddressCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetOpaqueAddressCommand header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.object_id, sizeof(header.object_id));
        success = success && ReadBytes(&header.address, sizeof(header.address));

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchSetOpaqueAddressCommand(
                    header.thread_id, header.device_id, header.object_id, header.address);
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read set opaque address meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetRayTracingShaderGroupHandlesCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetRayTracingShaderGroupHandlesCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.pipeline_id, sizeof(header.pipeline_id));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));

        // Read variable size shader group handle data into parameter_buffer_.
        success = success && ReadParameterBuffer(static_cast<size_t>(header.data_size));

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchSetRayTracingShaderGroupHandlesCommand(
                    header.thread_id,
                    header.device_id,
                    header.pipeline_id,
                    static_cast<size_t>(header.data_size),
                    parameter_buffer_.data());
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set ray tracing shader group handles meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kSetSwapchainImageStateCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::SetSwapchainImageStateCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.swapchain_id, sizeof(header.swapchain_id));
        success = success && ReadBytes(&header.last_presented_image, sizeof(header.last_presented_image));
        success = success && ReadBytes(&header.image_info_count, sizeof(header.image_info_count));

        if (success)
        {
            std::vector<format::SwapchainImageStateInfo> entries;

            for (uint32_t i = 0; i < header.image_info_count; ++i)
            {
                format::SwapchainImageStateInfo entry;

                if (!ReadBytes(&entry, sizeof(entry)))
                {
                    success = false;
                    break;
                }

                entries.emplace_back(std::move(entry));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchSetSwapchainImageStateCommand(
                        header.thread_id, header.device_id, header.swapchain_id, header.last_presented_image, entries);
                }
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData,
                                     "Failed to read set swapchain image state meta-data block");
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read set swapchain image state meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kBeginResourceInitCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::BeginResourceInitCommand header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.max_resource_size, sizeof(header.max_resource_size));
        success = success && ReadBytes(&header.max_copy_size, sizeof(header.max_copy_size));

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchBeginResourceInitCommand(
                    header.thread_id, header.device_id, header.max_resource_size, header.max_copy_size);
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read begin resource init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kEndResourceInitCommand)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::EndResourceInitCommand header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchEndResourceInitCommand(header.thread_id, header.device_id);
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read end resource init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitBufferCommand)
    {
        format::InitBufferCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.buffer_id, sizeof(header.buffer_id));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size =
                    static_cast<size_t>(block_header.size) - (sizeof(header) - sizeof(header.meta_header.block_header));

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.data_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.data_size));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchInitBufferCommand(header.thread_id,
                                                                       header.device_id,
                                                                       header.buffer_id,
                                                                       header.data_size,
                                                                       parameter_buffer_.data());
                }
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read init buffer data meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData, "Failed to read init buffer data meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read init buffer data meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitImageCommand)
    {
        format::InitImageCommandHeader header;
        std::vector<uint64_t>          level_sizes;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.image_id, sizeof(header.image_id));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));
        success = success && ReadBytes(&header.aspect, sizeof(header.aspect));
        success = success && ReadBytes(&header.layout, sizeof(header.layout));
        success = success && ReadBytes(&header.level_count, sizeof(header.level_count));

        if (success && (header.level_count > 0))
        {
            level_sizes.resize(header.level_count);
            success = success && ReadBytes(level_sizes.data(), header.level_count * sizeof(level_sizes[0]));
        }

        if (success && (header.data_size > 0))
        {
            assert(header.data_size == std::accumulate(level_sizes.begin(), level_sizes.end(), 0ull));
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size   = static_cast<size_t>(block_header.size) -
                                         (sizeof(header) - sizeof(header.meta_header.block_header)) -
                                         (level_sizes.size() * sizeof(level_sizes[0]));

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.data_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.data_size));
            }
        }

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                vulkan_preload_decoder_->DispatchInitImageCommand(header.thread_id,
                                                                  header.device_id,
                                                                  header.image_id,
                                                                  header.data_size,
                                                                  header.aspect,
                                                                  header.layout,
                                                                  level_sizes,
                                                                  parameter_buffer_.data());
            }
        }
        else
        {
            if (format::IsBlockCompressed(block_header.type))
            {
                HandleBlockReadError(kErrorReadingCompressedBlockData,
                                     "Failed to read init image data meta-data block");
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read init image data meta-data block");
            }
        }
    }
    else if (meta_data_type == format::MetaDataType::kInitSubresourceCommand)
    {
        format::InitSubresourceCommandHeader header;

        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.device_id, sizeof(header.device_id));
        success = success && ReadBytes(&header.resource_id, sizeof(header.resource_id));
        success = success && ReadBytes(&header.subresource, sizeof(header.subresource));
        success = success && ReadBytes(&header.initial_state, sizeof(header.initial_state));
        success = success && ReadBytes(&header.resource_state, sizeof(header.resource_state));
        success = success && ReadBytes(&header.barrier_flags, sizeof(header.barrier_flags));
        success = success && ReadBytes(&header.data_size, sizeof(header.data_size));

        if (success)
        {
            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, header.data_size);

            if (format::IsBlockCompressed(block_header.type))
            {
                size_t uncompressed_size = 0;
                size_t compressed_size =
                    static_cast<size_t>(block_header.size) - (sizeof(header) - sizeof(header.meta_header.block_header));

                success = ReadCompressedParameterBuffer(
                    compressed_size, static_cast<size_t>(header.data_size), &uncompressed_size);
            }
            else
            {
                success = ReadParameterBuffer(static_cast<size_t>(header.data_size));
            }

            if (success)
            {
                if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                {
                    vulkan_preload_decoder_->DispatchInitSubresourceCommand(header, parameter_buffer_.data());
                }
            }
            else
            {
                if (format::IsBlockCompressed(block_header.type))
                {
                    HandleBlockReadError(kErrorReadingCompressedBlockData,
                                         "Failed to read init subresource data meta-data block");
                }
                else
                {
                    HandleBlockReadError(kErrorReadingBlockData,
                                         "Failed to read init subresource data meta-data block");
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read init subresource data meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kParentToChildDependency)
    {
        // This command does not support compression.
        assert(block_header.type != format::BlockType::kCompressedMetaDataBlock);

        format::ParentToChildDependencyHeader header;
        success = ReadBytes(&header.thread_id, sizeof(header.thread_id));
        success = success && ReadBytes(&header.dependency_type, sizeof(header.dependency_type));
        success = success && ReadBytes(&header.parent_id, sizeof(header.parent_id));
        success = success && ReadBytes(&header.child_count, sizeof(header.child_count));

        if (success)
        {
            switch (header.dependency_type)
            {
                case format::kAccelerationStructuresDependency:
                {
                    std::vector<format::HandleId> blases;
                    blases.resize(header.child_count);

                    for (uint32_t i = 0; i < header.child_count; ++i)
                    {
                        success = success && ReadBytes(&blases[i], sizeof(blases[i]));
                    }

                    if (success)
                    {
                        if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
                        {
                            vulkan_preload_decoder_->DispatchSetTlasToBlasDependencyCommand(header.parent_id, blases);
                        }
                    }
                    else
                    {
                        HandleBlockReadError(kErrorReadingBlockHeader,
                                             "Failed to read TLAS to BLAS dependency meta-data block header");
                    }
                }
                break;

                default:
                    success = false;
                    HandleBlockReadError(kErrorReadingBlockHeader,
                                         "Corrupted parent to child dependency meta-data block header");
                    break;
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read parent to child dependency meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanBuildAccelerationStructuresCommand)
    {
        format::VulkanMetaBuildAccelerationStructuresHeader header;
        size_t parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        success                      = ReadParameterBuffer(parameter_buffer_size);

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                DecodeAllocator::Begin();

                vulkan_preload_decoder_->DispatchVulkanAccelerationStructuresBuildMetaCommand(parameter_buffer_.data(),
                                                                                              parameter_buffer_size);

                DecodeAllocator::End();
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockHeader,
                                 "Failed to read acceleration structure init meta-data block header");
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanCopyAccelerationStructuresCommand)
    {
        format::VulkanCopyAccelerationStructuresCommandHeader header;
        size_t parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        success                      = ReadParameterBuffer(parameter_buffer_size);

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                DecodeAllocator::Begin();

                vulkan_preload_decoder_->DispatchVulkanAccelerationStructuresCopyMetaCommand(parameter_buffer_.data(),
                                                                                             parameter_buffer_size);

                DecodeAllocator::End();
            }
        }
    }
    else if (meta_data_type == format::MetaDataType::kVulkanWriteAccelerationStructuresPropertiesCommand)
    {
        format::VulkanCopyAccelerationStructuresCommandHeader header;
        size_t parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(meta_data_id);
        success                      = ReadParameterBuffer(parameter_buffer_size);

        if (success)
        {
            if (vulkan_preload_decoder_->SupportsMetaDataId(meta_data_id))
            {
                DecodeAllocator::Begin();

                vulkan_preload_decoder_->DispatchVulkanAccelerationStructuresWritePropertiesMetaCommand(
                    parameter_buffer_.data(), parameter_buffer_size);

                DecodeAllocator::End();
            }
        }
    }
    else
    {
        if ((meta_data_type == format::MetaDataType::kReserved23) ||
            (meta_data_type == format::MetaDataType::kReserved25))
        {
            // Only log a warning once if the capture file contains blocks that are a "reserved" meta data type.
            GFXRECON_LOG_WARNING_ONCE("This capture file contains meta-data block(s) with reserved type(s) that are "
                                      "not supported. Unsupported meta-data block types will be skipped.");
        }
        else
        {
            // Unrecognized metadata type.
            GFXRECON_LOG_WARNING("Skipping unrecognized meta-data block with type %" PRIu16, meta_data_type);
        }
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
        success = SkipBytes(static_cast<size_t>(block_header.size) - sizeof(meta_data_id));
    }

    return success;
}

bool VulkanPreloadFileProcessor::ProcessStateMarker(const format::BlockHeader& block_header,
                                                    format::MarkerType         marker_type)
{
    uint64_t frame_number = 0;
    bool     success      = ReadBytes(&frame_number, sizeof(frame_number));

    if (success)
    {
        if (marker_type == format::kBeginMarker)
        {
            GFXRECON_LOG_INFO("Loading state for captured frame %" PRId64, frame_number);
        }
        else if (marker_type == format::kEndMarker)
        {
            GFXRECON_LOG_INFO("Finished loading state for captured frame %" PRId64, frame_number);
            first_frame_ = frame_number;
        }

        if (marker_type == format::kBeginMarker)
        {
            vulkan_preload_decoder_->DispatchStateBeginMarker(frame_number);
        }
        else if (marker_type == format::kEndMarker)
        {
            vulkan_preload_decoder_->DispatchStateEndMarker(frame_number);
        }
        else
        {
            GFXRECON_LOG_WARNING("Skipping unrecognized state marker with type %u", marker_type);
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read state marker data");
    }

    return success;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
