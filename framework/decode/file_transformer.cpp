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

#include "file_transformer.h"

#include "format/format_util.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

FileTransformer::FileTransformer() :
    file_header_{}, input_file_(nullptr), output_file_(nullptr), bytes_read_(0), bytes_written_(0),
    error_state_(kErrorInvalidFileDescriptor), loading_state_(false)
{}

FileTransformer::~FileTransformer()
{
    if (input_file_ != nullptr)
    {
        fclose(input_file_);
    }

    if (output_file_ != nullptr)
    {
        fclose(output_file_);
    }
}

bool FileTransformer::Initialize(const std::string& input_filename,
                                 const std::string& output_filename,
                                 const std::string& tool)
{
    input_filename_  = input_filename;
    output_filename_ = output_filename;
    tool_            = tool;

    bool success = false;

    int32_t result = util::platform::FileOpen(&input_file_, input_filename.c_str(), "rb");

    if ((result == 0) && (input_file_ != nullptr))
    {
        result = util::platform::FileOpen(&output_file_, output_filename.c_str(), "wb");

        if ((result == 0) && (output_file_ != nullptr))
        {
            success = ProcessFileHeader();
        }
        else
        {
            GFXRECON_LOG_ERROR("Failed to open output file %s", output_filename.c_str());
            error_state_ = kErrorOpeningFile;
        }
    }
    else
    {
        GFXRECON_LOG_ERROR("Failed to open input file %s", input_filename.c_str());
        error_state_ = kErrorOpeningFile;
    }

    if (success)
    {
        error_state_ = kErrorNone;
    }
    else
    {
        if (input_file_ != nullptr)
        {
            fclose(input_file_);
            input_file_ = nullptr;
        }

        if (output_file_ != nullptr)
        {
            fclose(output_file_);
            output_file_ = nullptr;
        }
    }

    return success;
}

// Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
bool FileTransformer::Process()
{
    bool success = true;

    const char*  label        = format::kAnnotationLabelTransformer;
    const size_t label_length = util::platform::StringLength(label);

    std::string data = "";
    data += "{\n";
    data += "  \"input\": " + input_filename_ + ",\n";
    data += "  \"output\": " + output_filename_ + ",\n";
    data += "  \"tool\": " + tool_ + "\n";
    data += "}";
    const size_t data_length = data.size();

    format::AnnotationHeader annotation;
    annotation.block_header.size = format::GetAnnotationBlockBaseSize() + label_length + data_length;
    annotation.block_header.type = format::BlockType::kAnnotation;
    annotation.annotation_type   = format::kJson;
    annotation.label_length      = label_length;
    annotation.data_length       = data_length;
    if (!WriteBytes(&annotation, sizeof(annotation)) || !WriteBytes(label, label_length) ||
        !WriteBytes(data.c_str(), data_length))
    {
        HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write transformer annotation");
        return false;
    }

    block_index_ = 0;
    while (success)
    {
        success = ProcessNextBlock();
        block_index_++;
    }

    if (!success && (error_state_ == kErrorNone))
    {
        // If a failure occured, but no error code was set, check for a file error.
        if ((input_file_ == nullptr) || (output_file_ == nullptr))
        {
            error_state_ = kErrorInvalidFileDescriptor;
        }
        else if (ferror(input_file_))
        {
            error_state_ = kErrorReadingFile;
        }
        else if (ferror(output_file_))
        {
            error_state_ = kErrorWritingFile;
        }
    }

    return (error_state_ == kErrorNone);
}

bool FileTransformer::ProcessFileHeader()
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

                success = CreateCompressor(enabled_options_.compression_type, &compressor_);
            }

            if (success)
            {
                // Write header to output file.
                success = WriteFileHeader(file_header_, file_options_);
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

bool FileTransformer::ProcessNextBlock()
{
    format::BlockHeader block_header;
    bool                success = true;

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
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read function call block header");
            }
        }
        else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMetaDataBlock)
        {
            format::MetaDataId meta_data_id =
                format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_None, format::MetaDataType::kUnknownMetaDataType);

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
        else if (format::RemoveCompressedBlockBit(block_header.type) == format::BlockType::kMethodCallBlock)
        {
            format::ApiCallId api_call_id = format::ApiCallId::ApiCall_Unknown;

            success = ReadBytes(&api_call_id, sizeof(api_call_id));

            if (success)
            {
                success = ProcessMethodCall(block_header, api_call_id, block_index_);
            }
            else
            {
                HandleBlockReadError(kErrorReadingBlockHeader, "Failed to read method call block header");
            }
        }
        else
        {
            // Copy the block to the output file.
            success = WriteBlockHeader(block_header);

            if (success)
            {
                success = CopyBytes(block_header.size);

                if (!success)
                {
                    GFXRECON_LOG_ERROR("Failed to write block data");
                    error_state_ = kErrorWritingBlockData;
                }
            }
        }
    }
    else
    {
        if (!feof(input_file_))
        {
            // If we have not hit a normal EOF condition, report an error reading the block header.
            GFXRECON_LOG_ERROR("Failed to read block header");
            error_state_ = kErrorReadingBlockHeader;
        }
    }

    return success;
}

bool FileTransformer::ReadBlockHeader(format::BlockHeader* block_header)
{
    assert(block_header != nullptr);

    if (ReadBytes(block_header, sizeof(*block_header)))
    {
        return true;
    }

    return false;
}

bool FileTransformer::WriteBlockHeader(const format::BlockHeader& block_header)
{
    if (!WriteBytes(&block_header, sizeof(block_header)))
    {
        GFXRECON_LOG_ERROR("Failed to write block header");
        error_state_ = kErrorWritingBlockHeader;
        return false;
    }

    return true;
}

bool FileTransformer::ReadParameterBuffer(size_t buffer_size)
{
    if (buffer_size > parameter_buffer_.size())
    {
        parameter_buffer_.resize(buffer_size);
    }

    return ReadBytes(parameter_buffer_.data(), buffer_size);
}

bool FileTransformer::ReadCompressedParameterBuffer(size_t  compressed_buffer_size,
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

bool FileTransformer::ReadBytes(void* buffer, size_t buffer_size)
{
    size_t bytes_read = util::platform::FileRead(buffer, 1, buffer_size, input_file_);
    bytes_read_ += bytes_read;
    return (bytes_read == buffer_size);
}

bool FileTransformer::WriteBytes(const void* buffer, size_t buffer_size)
{
    size_t bytes_written = util::platform::FileWrite(buffer, 1, buffer_size, output_file_);
    bytes_written_ += bytes_written;
    return (bytes_written == buffer_size);
}

bool FileTransformer::SkipBytes(uint64_t skip_size)
{
    bool success = util::platform::FileSeek(input_file_, skip_size, util::platform::FileSeekCurrent);

    if (success)
    {
        // These technically count as bytes read/processed.
        bytes_read_ += skip_size;
    }

    return success;
}

bool FileTransformer::CopyBytes(uint64_t copy_size)
{
    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, copy_size);
    if (ReadParameterBuffer(static_cast<size_t>(copy_size)))
    {
        if (WriteBytes(parameter_buffer_.data(), static_cast<size_t>(copy_size)))
        {
            return true;
        }
    }

    return false;
}

void FileTransformer::HandleBlockReadError(Error error_code, const char* error_message)
{
    // Report incomplete block at end of file as a warning, other I/O errors as an error.
    if (feof(input_file_) && !ferror(input_file_))
    {
        GFXRECON_LOG_WARNING("Incomplete block at end of file");
    }
    else
    {
        GFXRECON_LOG_ERROR("%s", error_message);
        error_state_ = error_code;
    }
}

void FileTransformer::HandleBlockWriteError(Error error_code, const char* error_message)
{
    GFXRECON_LOG_ERROR("%s", error_message);
    error_state_ = error_code;
}

void FileTransformer::HandleBlockCopyError(Error error_code, const char* error_message)
{
    if (ferror(output_file_))
    {
        HandleBlockWriteError(error_code, error_message);
    }
    else
    {
        HandleBlockReadError(error_code, error_message);
    }
}

bool FileTransformer::CreateCompressor(format::CompressionType type, std::unique_ptr<util::Compressor>* compressor)
{
    assert(compressor != nullptr);

    if (type != format::CompressionType::kNone)
    {
        (*compressor) = std::unique_ptr<util::Compressor>(format::CreateCompressor(type));

        if ((*compressor) == nullptr)
        {
            GFXRECON_LOG_ERROR("Failed to initialize file compression module (type = %u); processing of "
                               "compressed data will not be possible",
                               type);
            error_state_ = kErrorUnsupportedCompressionType;
            return false;
        }
    }

    return true;
}

bool FileTransformer::WriteFileHeader(const format::FileHeader&                  header,
                                      const std::vector<format::FileOptionPair>& options)
{
    bool success = WriteBytes(&header, sizeof(header));
    success      = success && WriteBytes(options.data(), options.size() * sizeof(format::FileOptionPair));

    if (!success)
    {
        GFXRECON_LOG_ERROR("Failed to write file header");
        error_state_ = kErrorWritingFileHeader;
    }

    return success;
}

bool FileTransformer::ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id)
{
    // Copy block data from old file to new file.
    if (!WriteBlockHeader(block_header))
    {
        return false;
    }

    if (!WriteBytes(&call_id, sizeof(call_id)))
    {
        HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write function call block header");
        return false;
    }

    if (!CopyBytes(block_header.size - sizeof(call_id)))
    {
        HandleBlockCopyError(kErrorCopyingBlockData, "Failed to copy function call block data");
        return false;
    }

    return true;
}

bool FileTransformer::ProcessMethodCall(const format::BlockHeader& block_header,
                                        format::ApiCallId          call_id,
                                        uint64_t                   block_index)
{
    // Copy block data from old file to new file.
    if (!WriteBlockHeader(block_header))
    {
        return false;
    }

    if (!WriteBytes(&call_id, sizeof(call_id)))
    {
        HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write method call block header");
        return false;
    }

    if (!CopyBytes(block_header.size - sizeof(call_id)))
    {
        HandleBlockCopyError(kErrorCopyingBlockData, "Failed to copy method call block data");
        return false;
    }

    return true;
}

bool FileTransformer::ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id)
{
    // Copy block data from old file to new file.
    if (!WriteBlockHeader(block_header))
    {
        return false;
    }

    if (!WriteBytes(&meta_data_id, sizeof(meta_data_id)))
    {
        HandleBlockWriteError(kErrorWritingBlockHeader, "Failed to write meta-data block header");
        return false;
    }

    if (!CopyBytes(block_header.size - sizeof(meta_data_id)))
    {
        HandleBlockCopyError(kErrorCopyingBlockData, "Failed to copy meta-data block data");
        return false;
    }

    return true;
}

bool FileTransformer::ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type)
{
    // Copy marker data from old file to new file.
    uint64_t frame_number = 0;

    if (ReadBytes(&frame_number, sizeof(frame_number)))
    {
        if (marker_type == format::kBeginMarker)
        {
            loading_state_ = true;
        }
        else if (marker_type == format::kEndMarker)
        {
            loading_state_ = false;
        }

        format::Marker marker;
        marker.header       = block_header;
        marker.marker_type  = marker_type;
        marker.frame_number = frame_number;

        if (!WriteBytes(&marker, sizeof(marker)))
        {
            HandleBlockWriteError(kErrorWritingBlockData, "Failed to write state marker data");
            return false;
        }
    }
    else
    {
        HandleBlockWriteError(kErrorReadingBlockData, "Failed to read state marker data");
        return false;
    }

    return true;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
