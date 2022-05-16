/*
** Copyright (c) 2018-2020 Valve Corporation
** Copyright (c) 2018-2020 LunarG, Inc.
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

#include "decode/file_processor.h"

#include "decode/decode_allocator.h"
#include "format/format_util.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <numeric>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

FileProcessor::FileProcessor() :
    file_header_{}, file_descriptor_(nullptr), current_frame_number_(0), bytes_read_(0),
    error_state_(kErrorInvalidFileDescriptor), annotation_handler_(nullptr), compressor_(nullptr), api_call_index_(0)
{}

FileProcessor::~FileProcessor()
{
    if (nullptr != compressor_)
    {
        delete compressor_;
        compressor_ = nullptr;
    }

    if (file_descriptor_)
    {
        fclose(file_descriptor_);
    }

    DecodeAllocator::DestroyInstance();
}

void FileProcessor::WaitDecodersIdle()
{
    for (auto decoder : decoders_)
    {
        decoder->WaitIdle();
    }
};

bool FileProcessor::Initialize(const std::string& filename)
{
    bool success = false;

    int32_t result = util::platform::FileOpen(&file_descriptor_, filename.c_str(), "rb");

    if ((result == 0) && (file_descriptor_ != nullptr))
    {
        success = ProcessFileHeader();

        if (success)
        {
            filename_    = filename;
            error_state_ = kErrorNone;
        }
        else
        {
            fclose(file_descriptor_);
            file_descriptor_ = nullptr;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open file %s", filename.c_str());
        error_state_ = kErrorOpeningFile;
    }

    return success;
}

bool FileProcessor::ProcessNextFrame()
{
    bool success = IsFileValid();

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

bool FileProcessor::ProcessAllFrames()
{
    bool success = true;

    while (success)
    {
        success = ProcessNextFrame();
    }

    return (error_state_ == kErrorNone);
}

bool FileProcessor::ProcessFileHeader()
{
    bool success = false;

    if (ReadBytes(&file_header_, sizeof(file_header_)))
    {
        success = format::ValidateFileHeader(file_header_);

        if (success)
        {
            file_options_.resize(file_header_.num_options);

            size_t option_data_size = file_header_.num_options * sizeof(format::FileOptionPair);

            success = ReadBytes(file_options_.data(), option_data_size);

            if (success)
            {
                for (const auto& option : file_options_)
                {
                    switch (option.key)
                    {
                        case format::FileOption::kCompressionType:
                            enabled_options_.compression_type = static_cast<format::CompressionType>(option.value);
                            break;
                        default:
                            GFXRECON_LOG_WARNING("Ignoring unrecognized file header option %u", option.key);
                            break;
                    }
                }

                compressor_ = format::CreateCompressor(enabled_options_.compression_type);

                if ((compressor_ == nullptr) && (enabled_options_.compression_type != format::CompressionType::kNone))
                {
                    GFXRECON_LOG_ERROR("Failed to initialize file compression module (type = %u); replay of "
                                       "compressed data will not be possible",
                                       enabled_options_.compression_type);
                    success      = false;
                    error_state_ = kErrorUnsupportedCompressionType;
                }
            }
        }
        else
        {
            GFXRECON_LOG_ERROR("File header contains invalid four character code");
            error_state_ = kErrorInvalidFourCC;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to read file header");
        error_state_ = kErrorReadingFileHeader;
    }

    return success;
}

bool FileProcessor::ProcessBlocks()
{
    format::BlockHeader block_header;
    bool                success = true;

    while (success)
    {
        success = ReadBlockHeader(&block_header);

        if (success)
        {
            if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kFunctionCallBlock)
            {
                format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

                success = ReadBytes(&api_call_id, sizeof(api_call_id));

                if (success)
                {
                    success = ProcessFunctionCall(block_header, api_call_id);

                    // Break from loop on frame delimiter.
                    if (IsFrameDelimiter(api_call_id))
                    {
                        // Make sure to increment the frame number on the way out.
                        ++current_frame_number_;
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
                format::MetaDataId meta_data_id = format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_None,
                                                                         format::MetaDataType::kUnknownMetaDataType);

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
                    // If there is no annotation handler to process the annotation, we can skip the annotation block.
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
                // assumes that the block header has been successfully read and will print an incomplete block at end
                // of file warning when the file is at EOF without an error. For this case (the normal EOF case) we
                // print nothing at EOF, or print an error message and set the error code directly when not at EOF.
                GFXRECON_LOG_ERROR("Failed to read block header");
                error_state_ = kErrorReadingBlockHeader;
            }
        }
    }

    return success;
}

bool FileProcessor::ReadBlockHeader(format::BlockHeader* block_header)
{
    assert(block_header != nullptr);

    bool success = false;

    if (ReadBytes(block_header, sizeof(*block_header)))
    {
        success = true;
    }

    return success;
}

bool FileProcessor::ReadParameterBuffer(size_t buffer_size)
{
    if (buffer_size > parameter_buffer_.size())
    {
        parameter_buffer_.resize(buffer_size);
    }

    return ReadBytes(parameter_buffer_.data(), buffer_size);
}

bool FileProcessor::ReadCompressedParameterBuffer(size_t  compressed_buffer_size,
                                                  size_t  expected_uncompressed_size,
                                                  size_t* uncompressed_buffer_size)
{
    // This should only be null if initialization failed.
    assert(compressor_ != nullptr);

    if (compressed_buffer_size > compressed_parameter_buffer_.size())
    {
        compressed_parameter_buffer_.resize(compressed_buffer_size);
    }

    if (ReadBytes(compressed_parameter_buffer_.data(), compressed_buffer_size))
    {
        if (parameter_buffer_.size() < expected_uncompressed_size)
        {
            parameter_buffer_.resize(expected_uncompressed_size);
        }

        size_t uncompressed_size = compressor_->Decompress(
            compressed_buffer_size, compressed_parameter_buffer_, expected_uncompressed_size, &parameter_buffer_);
        if ((0 < uncompressed_size) && (uncompressed_size == expected_uncompressed_size))
        {
            *uncompressed_buffer_size = uncompressed_size;
            return true;
        }
    }
    return false;
}

bool FileProcessor::ReadBytes(void* buffer, size_t buffer_size)
{
    size_t bytes_read = util::platform::FileRead(buffer, 1, buffer_size, file_descriptor_);
    bytes_read_ += bytes_read;
    return (bytes_read == buffer_size);
}

bool FileProcessor::SkipBytes(size_t skip_size)
{
    bool success = util::platform::FileSeek(file_descriptor_, skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += skip_size;
    }

    return success;
}

void FileProcessor::HandleBlockReadError(Error error_code, const char* error_message)
{
    // Report incomplete block at end of file as a warning, other I/O errors as an error.
    if (feof(file_descriptor_) && !ferror(file_descriptor_))
    {
        GFXRECON_LOG_WARNING("Incomplete block at end of file");
    }
    else
    {
        GFXRECON_LOG_ERROR("%s", error_message);
        error_state_ = error_code;
    }
}

bool FileProcessor::ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    size_t      parameter_buffer_size = static_cast<size_t>(block_header.size) - sizeof(call_id);
    uint64_t    uncompressed_size     = 0;
    ApiCallInfo call_info             = {};
    call_info.index                   = api_call_index_;
    bool success                      = ReadBytes(&call_info.thread_id, sizeof(call_info.thread_id));

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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsApiCall(call_id))
                {
                    DecodeAllocator::Begin();
                    decoder->DecodeFunctionCall(call_id, call_info, parameter_buffer_.data(), parameter_buffer_size);
                    DecodeAllocator::End();
                }
            }

            ++api_call_index_;
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
    }

    return success;
}

bool FileProcessor::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchFillMemoryCommand(header.thread_id,
                                                           header.memory_id,
                                                           header.memory_offset,
                                                           header.memory_size,
                                                           parameter_buffer_.data());
                    }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchResizeWindowCommand(
                        command.thread_id, command.surface_id, command.width, command.height);
                }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchResizeWindowCommand2(
                        command.thread_id, command.surface_id, command.width, command.height, command.pre_transform);
                }
            }
        }
        else
        {
            HandleBlockReadError(kErrorReadingBlockData, "Failed to read resize window 2 meta-data block");
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

                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchDisplayMessageCommand(header.thread_id, message);
                    }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchCreateHardwareBufferCommand(header.thread_id,
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchSetDevicePropertiesCommand(header.thread_id,
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchSetDeviceMemoryPropertiesCommand(
                            header.thread_id, header.physical_device_id, types, heaps);
                    }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchSetOpaqueAddressCommand(
                        header.thread_id, header.device_id, header.object_id, header.address);
                }
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
        success = success && ReadParameterBuffer(header.data_size);

        if (success)
        {
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchSetRayTracingShaderGroupHandlesCommand(header.thread_id,
                                                                            header.device_id,
                                                                            header.pipeline_id,
                                                                            header.data_size,
                                                                            parameter_buffer_.data());
                }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchSetSwapchainImageStateCommand(header.thread_id,
                                                                       header.device_id,
                                                                       header.swapchain_id,
                                                                       header.last_presented_image,
                                                                       entries);
                    }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchBeginResourceInitCommand(
                        header.thread_id, header.device_id, header.max_resource_size, header.max_copy_size);
                }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchEndResourceInitCommand(header.thread_id, header.device_id);
                }
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
                for (auto decoder : decoders_)
                {
                    if (decoder->SupportsMetaDataId(meta_data_id))
                    {
                        decoder->DispatchInitBufferCommand(header.thread_id,
                                                           header.device_id,
                                                           header.buffer_id,
                                                           header.data_size,
                                                           parameter_buffer_.data());
                    }
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
            for (auto decoder : decoders_)
            {
                if (decoder->SupportsMetaDataId(meta_data_id))
                {
                    decoder->DispatchInitImageCommand(header.thread_id,
                                                      header.device_id,
                                                      header.image_id,
                                                      header.data_size,
                                                      header.aspect,
                                                      header.layout,
                                                      level_sizes,
                                                      parameter_buffer_.data());
                }
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
    else
    {
        // Unrecognized metadata type.
        GFXRECON_LOG_WARNING("Skipping unrecognized meta-data block with type %" PRIu16, meta_data_type);
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);

        success = SkipBytes(static_cast<size_t>(block_header.size) - sizeof(meta_data_id));
    }

    return success;
}

bool FileProcessor::ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type)
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
        }

        for (auto decoder : decoders_)
        {
            if (marker_type == format::kBeginMarker)
            {
                decoder->DispatchStateBeginMarker(frame_number);
            }
            else if (marker_type == format::kEndMarker)
            {
                decoder->DispatchStateEndMarker(frame_number);
            }
            else
            {
                GFXRECON_LOG_WARNING("Skipping unrecognized state marker with type %u", marker_type);
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockData, "Failed to read state marker data");
    }

    return success;
}

bool FileProcessor::ProcessAnnotation(const format::BlockHeader& block_header, format::AnnotationType annotation_type)
{
    bool     success      = false;
    uint32_t label_length = 0;
    uint32_t data_length  = 0;

    success = ReadBytes(&label_length, sizeof(label_length));
    success = success && ReadBytes(&data_length, sizeof(data_length));
    if (success)
    {
        if ((label_length > 0) || (data_length > 0))
        {
            std::string label;
            std::string data;
            auto        total_length = label_length + data_length;

            success = ReadParameterBuffer(total_length);
            if (success)
            {
                if (label_length > 0)
                {
                    auto label_start = parameter_buffer_.begin();
                    label.assign(label_start, std::next(label_start, label_length));
                }

                if (data_length > 0)
                {
                    auto data_start = std::next(parameter_buffer_.begin(), label_length);
                    data.assign(data_start, std::next(data_start, data_length));
                }

                assert(annotation_handler_ != nullptr);
                annotation_handler_->ProcessAnnotation(annotation_type, label, data);
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockData, "Failed to read annotation block");
            }
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read annotation block header");
    }

    return success;
}

bool FileProcessor::IsFrameDelimiter(format::ApiCallId call_id) const
{
    // TODO: IDs of API calls that were treated as frame delimiters by the GFXReconstruct layer should be in the capture
    // file header.
    return (call_id == format::ApiCallId::ApiCall_vkQueuePresentKHR);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
