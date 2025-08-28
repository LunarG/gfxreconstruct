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
#include "format/format.h"
#include "decode/annotation_handler.h"
#include "decode/api_decoder.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "util/file_input_stream.h"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <memory>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using FileInputStream    = util::FStreamFileInputStream;
using FileInputStreamPtr = std::shared_ptr<FileInputStream>;

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

        return file_stack_.front().active_file->IsEof();
    }

    bool UsesFrameMarkers() const { return capture_uses_frame_markers_; }

    void SetPrintBlockInfoFlag(bool enable_print_block_info, int64_t block_index_from, int64_t block_index_to)
    {
        enable_print_block_info_ = enable_print_block_info;
        block_index_from_        = block_index_from;
        block_index_to_          = block_index_to;
    }

  protected:
    bool ContinueDecoding();

    bool ReadBlockHeader(format::BlockHeader* block_header);

    virtual bool ReadBytes(void* buffer, size_t buffer_size);

    bool SkipBytes(size_t skip_size);

    bool ProcessFunctionCall(const format::BlockHeader& block_header, format::ApiCallId call_id, bool& should_break);

    bool ProcessMethodCall(const format::BlockHeader& block_header, format::ApiCallId call_id, bool& should_break);

    bool ProcessMetaData(const format::BlockHeader& block_header, format::MetaDataId meta_data_id);

    bool IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type) const;

    bool IsFrameDelimiter(format::ApiCallId call_id) const;

    void HandleBlockReadError(Error error_code, const char* error_message);

    bool
    ProcessFrameMarker(const format::BlockHeader& block_header, format::MarkerType marker_type, bool& should_break);

    bool ProcessStateMarker(const format::BlockHeader& block_header, format::MarkerType marker_type);

    bool ProcessAnnotation(const format::BlockHeader& block_header, format::AnnotationType annotation_type);

    void PrintBlockInfo() const;

  protected:
    uint64_t                 current_frame_number_;
    std::vector<ApiDecoder*> decoders_;
    AnnotationHandler*       annotation_handler_;
    Error                    error_state_;
    uint64_t                 bytes_read_;

    /// @brief Incremented at the end of every block successfully processed.
    uint64_t block_index_;

  protected:
    Error CheckFileStatus() const
    {
        if (file_stack_.empty())
        {
            return kErrorInvalidFileDescriptor;
        }
        const auto& active_file = file_stack_.back().active_file;
        // If not EOF, determine reason for invalid state.
        if (!active_file->IsOpen())
        {
            return kErrorInvalidFileDescriptor;
        }
        else if (active_file->IsError())
        {
            return kErrorReadingFile;
        }

        return kErrorNone;
    }

    bool AtEof() const
    {
        if (file_stack_.empty())
        {
            return true;
        }
        return file_stack_.back().active_file->IsEof();
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
            return file_stack_.back().active_file->IsValid();
        }
        else
        {
            return false;
        }
    }

    bool SeekActiveFile(const FileInputStreamPtr& file, int64_t offset, util::platform::FileSeekOrigin origin);

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

    struct ActiveFileContext
    {
        ActiveFileContext(FileInputStreamPtr&& active_file_, bool execute_til_eof_ = false) :
            active_file(std::move(active_file_)), execute_till_eof(execute_til_eof_){};

        FileInputStreamPtr active_file;
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

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_H
