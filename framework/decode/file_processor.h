/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_FILE_PROCESSOR_H
#define GFXRECON_DECODE_FILE_PROCESSOR_H

#include "format/api_call_id.h"
#include "format/format_util.h"
#include "decode/annotation_handler.h"
#include "decode/api_decoder.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/logging.h"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class FileProcessor
{
  public:
    enum Error : int32_t
    {
        kErrorNone                         = 0,
        kErrorInvalidFileDescriptor        = -1,
        kErrorOpeningFile                  = -2,
        kErrorReadingFile                  = -3, // ferror() returned true at start of frame processing.
        kErrorReadingFileHeader            = -4,
        kErrorReadingBlockHeader           = -5,
        kErrorReadingCompressedBlockHeader = -6,
        kErrorReadingBlockData             = -7,
        kErrorReadingCompressedBlockData   = -8,
        kErrorInvalidFourCC                = -9,
        kErrorUnsupportedCompressionType   = -10
    };

    enum BlockProcessReturn : int32_t
    {
        kSuccess = 0,
        kFailure = 1,
        kBreak   = 2,
    };

  public:
    FileProcessor();

    FileProcessor(uint64_t block_limit);

    virtual ~FileProcessor();

    void WaitDecodersIdle();

    void SetAnnotationProcessor(AnnotationHandler* handler) { annotation_handler_ = handler; }

    void AddDecoder(ApiDecoder* decoder) { decoders_.push_back(decoder); }

    void RemoveDecoder(ApiDecoder* decoder)
    {
        decoders_.erase(std::remove(decoders_.begin(), decoders_.end(), decoder), decoders_.end());
    }

    bool Initialize(const std::string& filename);

    // Returns true if there are more frames to process, false if all frames have been processed or an error has
    // occurred.  Use GetErrorState() to determine error condition.
    bool ProcessNextFrame();

    // Returns false if processing failed.  Use GetErrorState() to determine error condition for failure case.
    bool ProcessAllFrames();

    const std::vector<format::FileOptionPair>& GetFileOptions() const { return file_options_; }

    uint64_t GetCurrentFrameNumber() const { return current_frame_number_; }

    uint64_t GetCurrentBlockIndex() const { return block_index_; }

    bool GetLoadingTrimmedState() const { return loading_trimmed_capture_state_; }

    uint64_t GetNumBytesRead() const { return bytes_read_; }

    Error GetErrorState() const { return error_state_; }

    bool EntireFileWasProcessed() const
    {
        if (file_stack_.empty())
        {
            return true;
        }

        const auto file_entry = active_files_.find(file_stack_.front().filename);
        if (file_entry != active_files_.end())
        {
            return (feof(file_entry->second.fd) != 0);
        }
        else
        {
            return false;
        }
    }

    bool UsesFrameMarkers() const { return capture_uses_frame_markers_; }

    void SetPrintBlockInfoFlag(bool enable_print_block_info, int64_t block_index_from, int64_t block_index_to)
    {
        enable_print_block_info_ = enable_print_block_info;
        block_index_from_        = block_index_from;
        block_index_to_          = block_index_to;
    }

    struct ProcessBlockResult
    {
        bool success;
        bool should_break;
    };

    template <format::BlockType BlockId>
    std::string ComposeErrorMsg(const char* error, const char* element)
    {
        using Str    = std::string;
        using Traits = format::BlockTypeTraits<BlockId>;
        static const Str space(" ");
        return Str(error) + space + Traits::BlockTypeName() + space + Str(element);
    }

    template <format::BlockType BlockId>
    std::string BlockReadErrorMsg(const char* element)
    {
        return ComposeErrorMsg<BlockId>("Failed to read", element);
    }

    // NOTE: because of the rules regarding access control for friend declarations
    //       the generic code must be public.  The derived classes can't declare it
    //       a friend, unless it is public.
    //
    //       This doesn't break encapsulation as instantiation still requires the
    //       Derived class to implement the needed interfaces and befriend the Impl
    //       method.
    template <typename Derived>
    bool ProcessBlocksImpl();
    template <typename Derived, format::BlockType BlockId>
    ProcessBlockResult ProcessBlockClause(format::BlockHeader& block_header);

  protected:
    bool ContinueDecoding();

    bool ReadBlockHeader(format::BlockHeader* block_header);

    virtual bool ReadBytes(void* buffer, size_t buffer_size);

    bool SkipBytes(size_t skip_size);

    bool IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type) const;
    bool IsFrameDelimiter(format::ApiCallId call_id) const;
    bool IsFrameDelimiter(format::BlockType block_type, format::ApiCallId call_id) const
    {
        return IsFrameDelimiter(call_id);
    }
    template <typename SubBlockId>
    constexpr bool IsFrameDelimiter(format::BlockType block_type, SubBlockId call_id) const
    {
        return false;
    }

    void HandleBlockReadError(Error error_code, const char* error_message);
    void HandleBlockReadError(Error error_code, const std::string& error_message)
    {
        HandleBlockReadError(error_code, error_message.c_str());
    }

    void PrintBlockInfo() const;

    constexpr bool SkipBlockProcessing() { return false; }
    constexpr bool PreloadRecording() const { return false; }
    template <format::BlockType BlockId, typename SubBlockId>
    constexpr ProcessBlockResult RecordPreloadBlock(format::BlockHeader& block_header, SubBlockId sub_block_id)
    {
        return { true /* success */, false /* not a frame delimiter */ };
    }

    // NOTE: There is no generic implemenation for this class.  A specialization must be defined for
    //       all supported BlockTypes.  Adding a generic will both allow for silent compile time failure
    //       of missing support for the type, and create duplicate functions definitions at link time.
    template <format::BlockType BlockId>
    ProcessBlockResult ProcessOneBlock(const format::BlockHeader&                              block_header,
                                       typename format::BlockTypeTraits<BlockId>::SubBlockType sub_block_id);

  protected:
    uint64_t                 current_frame_number_;
    std::vector<ApiDecoder*> decoders_;
    AnnotationHandler*       annotation_handler_;
    Error                    error_state_;
    uint64_t                 bytes_read_;

    /// @brief Incremented at the end of every block successfully processed.
    uint64_t block_index_;

  protected:
    FILE* GetFileDescriptor()
    {
        assert(!file_stack_.empty());

        if (!file_stack_.empty())
        {
            auto file_entry = active_files_.find(file_stack_.back().filename);
            assert(file_entry != active_files_.end());

            return file_entry->second.fd;
        }
        else
        {
            return nullptr;
        }
    }

  private:
    bool ProcessFileHeader();

    virtual bool ProcessBlocks();

    bool ReadParameterBuffer(size_t buffer_size);

    bool ReadCompressedParameterBuffer(size_t  compressed_buffer_size,
                                       size_t  expected_uncompressed_size,
                                       size_t* uncompressed_buffer_size);

    bool IsFileValid() const
    {
        if (!file_stack_.empty())
        {
            auto file_entry = active_files_.find(file_stack_.back().filename);
            assert(file_entry != active_files_.end());

            return (file_entry->second.fd && !feof(file_entry->second.fd) && !ferror(file_entry->second.fd));
        }
        else
        {
            return false;
        }
    }

    bool OpenFile(const std::string& filename);

    bool SeekActiveFile(const std::string& filename, int64_t offset, util::platform::FileSeekOrigin origin);

    bool SeekActiveFile(int64_t offset, util::platform::FileSeekOrigin origin);

    bool SetActiveFile(const std::string& filename, bool execute_till_eof);

    bool SetActiveFile(const std::string&             filename,
                       int64_t                        offset,
                       util::platform::FileSeekOrigin origin,
                       bool                           execute_till_eof);

    void DecrementRemainingCommands();

    std::string ApplyAbsolutePath(const std::string& file);

  private:
    std::vector<format::FileOptionPair> file_options_;
    format::EnabledOptions              enabled_options_;
    std::vector<uint8_t>                parameter_buffer_;
    std::vector<uint8_t>                compressed_parameter_buffer_;
    util::Compressor*                   compressor_;
    uint64_t                            api_call_index_;
    uint64_t                            block_limit_;
    bool                                capture_uses_frame_markers_;
    uint64_t                            first_frame_;
    bool                                enable_print_block_info_{ false };
    int64_t                             block_index_from_{ 0 };
    int64_t                             block_index_to_{ 0 };
    bool                                loading_trimmed_capture_state_;

    struct ActiveFiles
    {
        ActiveFiles() {}

        ActiveFiles(FILE* fd_) : fd(fd_) {}

        FILE* fd{ nullptr };
    };

    std::unordered_map<std::string, ActiveFiles> active_files_;

    struct ActiveFileContext
    {
        ActiveFileContext(std::string filename_) : filename(std::move(filename_)){};
        ActiveFileContext(std::string filename_, bool execute_till_eof_) :
            filename(std::move(filename_)), execute_till_eof(execute_till_eof_){};

        std::string filename;
        uint32_t    remaining_commands{ 0 };
        bool        execute_till_eof{ false };
    };
    std::deque<ActiveFileContext> file_stack_;

    std::string absolute_path_;

  private:
    ActiveFileContext& GetCurrentFile()
    {
        assert(file_stack_.size());

        return file_stack_.back();
    }
};

template <typename Derived, format::BlockType BlockId>
FileProcessor::ProcessBlockResult FileProcessor::ProcessBlockClause(format::BlockHeader& block_header)
{
    using Traits                    = format::BlockTypeTraits<BlockId>;
    Derived* const     derived_this = static_cast<Derived*>(this);
    ProcessBlockResult result{ false, false };

    // Note: A sub block id's treat unknown as 0. If we really care, add traits for a default value
    //
    auto sub_block_id = typename Traits::SubBlockType(0);

    result.success = ReadBytes(&sub_block_id, sizeof(sub_block_id));

    if (result.success)
    {
        if (derived_this->PreloadRecording())
        {
            result = derived_this->template RecordPreloadBlock<BlockId>(block_header, sub_block_id);
        }
        else
        {
            result = ProcessOneBlock<BlockId>(block_header, sub_block_id);
        }
    }
    else
    {
        HandleBlockReadError(kErrorReadingBlockHeader, BlockReadErrorMsg<BlockId>("header"));
    }
    return result;
}

template <typename Derived>
bool FileProcessor::ProcessBlocksImpl()
{
    format::BlockHeader block_header;
    bool                success = true;

    while (success)
    {
        Derived* const derived_this = static_cast<Derived*>(this);
        PrintBlockInfo();
        success = ContinueDecoding();

        if (success)
        {
            success = ReadBlockHeader(&block_header);

            if (!derived_this->PreloadRecording())
            {
                for (auto decoder : decoders_)
                {
                    decoder->SetCurrentBlockIndex(block_index_);
                }
            }

            if (success)
            {
                ProcessBlockResult result{ false, false };
                const auto         base_block_type = format::RemoveCompressedBlockBit(block_header.type);
                if (derived_this->SkipBlockProcessing())
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                    result.success = SkipBytes(static_cast<size_t>(block_header.size));
                }
                else if (base_block_type == format::BlockType::kFunctionCallBlock)
                {
                    result = ProcessBlockClause<Derived, format::BlockType::kFunctionCallBlock>(block_header);
                }
                else if (base_block_type == format::BlockType::kMethodCallBlock)
                {
                    result = ProcessBlockClause<Derived, format::BlockType::kMethodCallBlock>(block_header);
                }
                else if (base_block_type == format::BlockType::kMetaDataBlock)
                {
                    result = ProcessBlockClause<Derived, format::BlockType::kMetaDataBlock>(block_header);
                }
                else if (base_block_type == format::BlockType::kFrameMarkerBlock)
                {
                    result = ProcessBlockClause<Derived, format::BlockType::kFrameMarkerBlock>(block_header);
                }
                else if (base_block_type == format::BlockType::kStateMarkerBlock)
                {
                    result = ProcessBlockClause<Derived, format::BlockType::kStateMarkerBlock>(block_header);
                }
                else if (base_block_type == format::BlockType::kAnnotation)
                {
                    if (annotation_handler_ != nullptr)
                    {
                        result = ProcessBlockClause<Derived, format::BlockType::kAnnotation>(block_header);
                    }
                    else
                    {
                        // If there is no annotation handler to process the annotation, we can skip the annotation
                        // block.
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                        result.success = SkipBytes(static_cast<size_t>(block_header.size));
                    }
                }
                else
                {
                    // Unrecognized block type.
                    GFXRECON_LOG_WARNING("Skipping unrecognized file block with type %u (frame %u block %" PRIu64 ")",
                                         block_header.type,
                                         current_frame_number_,
                                         block_index_);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, block_header.size);
                    result.success = SkipBytes(static_cast<size_t>(block_header.size));
                }

                success = result.success;
                if (result.should_break)
                {
                    break;
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
                    GFXRECON_LOG_ERROR("Failed to read block header (frame %u block %" PRIu64 ")",
                                       current_frame_number_,
                                       block_index_);
                    error_state_ = kErrorReadingBlockHeader;
                }
                else
                {
                    assert(!file_stack_.empty());

                    ActiveFileContext& current_file = GetCurrentFile();
                    if (current_file.execute_till_eof)
                    {
                        file_stack_.pop_back();
                        success = !file_stack_.empty();
                    }
                }
            }
        }

        if (!derived_this->PreloadRecording())
        {
            ++block_index_;
        }

        DecrementRemainingCommands();
    }

    DecrementRemainingCommands();
    return success;
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_H
