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
    input_file_(std::make_shared<FileInputStream>()), output_file_(nullptr), bytes_read_(0), bytes_written_(0),
    error_state_(kErrorInvalidFileDescriptor), loading_state_(false), pool_(util::HeapBufferPool::Create())
{}

FileTransformer::~FileTransformer()
{
    // Note: input_file_ is closed by destructor
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

    GFXRECON_ASSERT(input_file_ != nullptr);
    bool open_input = input_file_->Open(input_filename.c_str());

    if (open_input && input_file_->IsOpen())
    {
        int32_t result = util::platform::FileOpen(&output_file_, output_filename.c_str(), "wb");

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
        // We wait until after "ProcessFileHeader" as that is where compressor_ is initialized
        auto err_handler = [this](BlockIOError err, const char* message) { HandleBlockReadError(err, message); };
        block_parser_ =
            std::make_unique<BlockParser>(BlockParser::ErrorHandler{ err_handler }, pool_, compressor_.get());
        success = block_parser_ != nullptr;
        if (success)
        {
            block_parser_->SetDecompressionPolicy(BlockParser::kNever);
        }
        else
        {
            error_state_ = kErrorOpeningFile;
        }
    }

    if (success)
    {
        error_state_ = kErrorNone;
    }
    else
    {
        input_file_->Close();

        if (output_file_ != nullptr)
        {
            fclose(output_file_);
            output_file_ = nullptr;
        }
        block_parser_.reset();
    }

    return success;
}

bool FileTransformer::Initialize(const std::string& input_filename, const std::string& output_filename)
{
    return Initialize(input_filename, output_filename, "");
}

// Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
bool FileTransformer::Process()
{
    bool success = true;

    const char*  label        = format::kAnnotationLabelTransformer;
    const size_t label_length = util::platform::StringLength(label);

    if (!tool_.empty())
    {
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
    }

    block_index_ = 0;
    BlockBuffer block_buffer;

    while (success)
    {
        BlockIOError status = block_parser_->ReadBlockBuffer(input_file_, block_buffer);
        success             = status == kErrorNone;
        if (success)
        {
            // Track bytes read by the parser, since we aren't using ReadBytes here
            bytes_read_ += block_buffer.Size();
            block_parser_->SetBlockIndex(block_index_);
            ParsedBlock parsed_block = block_parser_->ParseBlock(block_buffer);

            // There are four states for a parsed block
            //    kReady and kDeferredDecompress are "Visitable"
            //    kUnknown is an unknown block type, passed through
            //    kInvalid implies !IsValid (and thus !success)
            success = parsed_block.IsValid();
            if (success)
            {
                if (parsed_block.IsVisitable())
                {
                    auto visit_call = [this, &parsed_block](auto&& args) {
                        return this->ProcessNextBlock(parsed_block, *args);
                    };
                    success = std::visit(visit_call, parsed_block.GetArgs());
                }
                else
                {
                    // Unknown block types are passed through unparsed
                    GFXRECON_ASSERT(parsed_block.IsUnknown());
                    success = WriteBytes(parsed_block);
                }
                block_index_++;
            }
        }
    }

    if (!success && (error_state_ == kErrorNone))
    {
        // If a failure occured, but no error code was set, check for a file error.
        if ((input_file_.get() == nullptr) || !input_file_->IsOpen() || (output_file_ == nullptr))
        {
            error_state_ = kErrorInvalidFileDescriptor;
        }
        else if (input_file_->IsError())
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
    bool               success = false;
    format::FileHeader file_header{};

    if (ReadBytes(&file_header, sizeof(file_header)))
    {
        success = format::ValidateFileHeader(file_header);

        if (success)
        {
            file_options_.resize(file_header.num_options);

            size_t option_data_size = file_header.num_options * sizeof(format::FileOptionPair);

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
                success = WriteFileHeader(file_header, file_options_);
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

template <typename Args>
bool FileTransformer::ProcessNextBlock(ParsedBlock& parsed_block, const Args& /* args */)
{
    // Drop the args parameter, as Decompress mutates Args, and we don't want to
    // confuse maintainers (or the compiler) by passing a const Args& that is modified.

    bool success = true;

    // Dispatch to appropriate processing function based on Args type
    if constexpr (std::is_same_v<FunctionCallArgs, Args>)
    {
        success = ProcessFunctionCall(parsed_block);
    }
    else if constexpr (std::is_same_v<MethodCallArgs, Args>)
    {
        success = ProcessMethodCall(parsed_block);
    }
    else if constexpr (std::is_same_v<StateBeginMarkerArgs, Args>)
    {
        success = ProcessStateBeginMarker(parsed_block);
    }
    else if constexpr (std::is_same_v<StateEndMarkerArgs, Args>)
    {
        success = ProcessStateEndMarker(parsed_block);
    }
    else if constexpr (DispatchTraits<Args>::kHasMetaDataId)
    {
        success = ProcessMetaData(parsed_block); // MetaData processing will revisit
    }
    else
    {
        // These block types have no transformation interface defined, pass them through directly
        success = WriteBytes(parsed_block);
    }
    return success;
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

bool FileTransformer::ReadBytes(void* buffer, size_t buffer_size)
{
    if (input_file_->ReadBytes(buffer, buffer_size))
    {
        bytes_read_ += buffer_size;
        return true;
    }
    return false;
}

bool FileTransformer::WriteBytes(const void* buffer, size_t buffer_size)
{
    if (util::platform::FileWrite(buffer, buffer_size, output_file_))
    {
        bytes_written_ += buffer_size;
        return true;
    }
    return false;
}

bool FileTransformer::WriteBytes(const ParsedBlock& parsed_block)
{
    const util::DataSpan& block_span = parsed_block.GetBlockData();
    if (!WriteBytes(block_span.data(), block_span.size()))
    {
        HandleBlockWriteError(kErrorWritingBlockData, "Failed to write passthrough block data");
        return false;
    }
    return true;
}

void FileTransformer::HandleBlockReadError(Error error_code, const char* error_message)
{
    // Report incomplete block at end of file as a warning, other I/O errors as an error.
    if (input_file_->IsEof() && !input_file_->IsError())
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

bool FileTransformer::CreateCompressor(format::CompressionType type, std::unique_ptr<util::Compressor>* compressor)
{
    assert(compressor != nullptr);

    if (type != format::CompressionType::kNone)
    {
        compressor->reset(format::CreateCompressor(type));

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

// Default Behavior for most blocks is pass-through
bool FileTransformer::ProcessFunctionCall(ParsedBlock& parsed_block)
{
    return WriteBytes(parsed_block);
}

bool FileTransformer::ProcessMethodCall(ParsedBlock& parsed_block)
{
    return WriteBytes(parsed_block);
}

// Because of the numerous Args types for MetaDataBlock, any override of ProcessMetaData
// will need to use the visitor pattern to specialize operations on the kHasMetaDataId
// Arg type current in the DispatchArgs variant
bool FileTransformer::ProcessMetaData(ParsedBlock& parsed_block)
{
    return WriteBytes(parsed_block);
}

bool FileTransformer::ProcessStateBeginMarker(ParsedBlock& parsed_block)
{
    loading_state_ = true;
    return WriteBytes(parsed_block);
}

bool FileTransformer::ProcessStateEndMarker(ParsedBlock& parsed_block)
{
    loading_state_ = false;
    return WriteBytes(parsed_block);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
