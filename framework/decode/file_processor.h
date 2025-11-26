/*
** Copyright (c) 2018 Valve Corporation
** Copyright (c) 2018-2025 LunarG, Inc.
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
#include "decode/api_payload.h"
#include "decode/block_parser.h"
#include "util/clock_cache.h"
#include "util/compressor.h"
#include "util/defines.h"
#include "decode/decode_allocator.h"
#include "util/logging.h"
#include "util/file_input_stream.h"

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <deque>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <type_traits> // ParsedBlock
#include <unordered_map>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

// TODO: Find a better home for the visitors and utilities
template <bool HasAllocGuard = false>
struct DecoderAllocGuard
{};

template <>
struct DecoderAllocGuard<true>
{
    DecoderAllocGuard& operator=(const DecoderAllocGuard&) = delete;
    DecoderAllocGuard(DecoderAllocGuard&&)                 = delete;
    DecoderAllocGuard& operator=(DecoderAllocGuard&&)      = delete;
    DecoderAllocGuard() { DecodeAllocator::Begin(); }
    ~DecoderAllocGuard() noexcept { DecodeAllocator::End(); }
};

template <typename Args>
static bool DecoderSupportsDispatch(ApiDecoder& decoder, const Args& args)
{
    if constexpr (DispatchTraits<Args>::kHasCallId)
    {
        return decoder.SupportsApiCall(args.call_id);
    }
    else if constexpr (DispatchTraits<Args>::kHasMetaDataId)
    {
        return decoder.SupportsMetaDataId(args.meta_data_id);
    }
    return true;
}

template <typename Args>
static void SetDecoderApiCallId(ApiDecoder& decoder, const Args& args)
{
    if constexpr (DispatchTraits<Args>::kHasCallId)
    {
        decoder.SetCurrentApiCallId(args.call_id);
    }
}

class FileProcessor
{
  public:
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

    BlockReadError GetErrorState() const { return error_state_; }

    bool EntireFileWasProcessed() const
    {
        if (file_stack_.empty())
        {
            return true;
        }

        return file_stack_.front().active_file->IsEof();
    }

    bool UsesFrameMarkers() const { return capture_uses_frame_markers_; }
    bool                      FileSupportsFrameMarkers() const { return file_supports_frame_markers_; }
    const format::FileHeader& GetFileHeader() const { return file_header_; }

    void SetPrintBlockInfoFlag(bool enable_print_block_info, int64_t block_index_from, int64_t block_index_to)
    {
        enable_print_block_info_ = enable_print_block_info;
        block_index_from_        = block_index_from;
        block_index_to_          = block_index_to;
    }

    bool IsFrameDelimiter(format::BlockType block_type, format::MarkerType marker_type) const;
    bool IsFrameDelimiter(format::ApiCallId call_id) const;

    void HandleBlockReadError(BlockReadError error_code, const char* error_message);

    bool ProcessExecuteBlocksFromFile(const ExecuteBlocksFromFileArgs& execute_blocks_info);
    void ProcessStateBeginMarker(const StateBeginMarkerArgs& state_begin);
    void ProcessStateEndMarker(const StateEndMarkerArgs& state_end);
    void ProcessAnnotation(const AnnotationArgs& annotation);

  protected:
    bool DoProcessNextFrame(const std::function<bool()>& block_processor);
    bool ProcessBlocksOneFrame();

    bool ContinueDecoding();

    util::DataSpan ReadSpan(size_t buffer_size);
    bool           ReadBytes(void* buffer, size_t buffer_size);

    bool PeekBytes(void* buffer, size_t buffer_size);
    bool PeekBlockHeader(format::BlockHeader* block_header);

    // Reads block header, from input stream.
    bool ReadBlockBuffer(BlockParser& parser, BlockBuffer& buffer);

    // Gets the block buffer from input stream or preloaded data if available
    virtual bool GetBlockBuffer(BlockParser& parser, BlockBuffer& block_buffer);

    void UpdateEndFrameState();

    // Returns whether the call_id is a frame delimiter and handles frame delimiting logic
    bool ProcessFrameDelimiter(format::ApiCallId call_id);
    bool ProcessFrameDelimiter(const FrameEndMarkerArgs& end_frame);

    void PrintBlockInfo() const;

    bool HandleBlockEof(const char* operation, bool report_frame_and_block);

  protected:
    uint64_t                 current_frame_number_;
    std::vector<ApiDecoder*> decoders_;
    AnnotationHandler*       annotation_handler_;
    BlockReadError           error_state_;
    uint64_t                 bytes_read_;

    /// @brief Incremented at the end of every block successfully processed.
    uint64_t block_index_;

  protected:
    BlockReadError CheckFileStatus() const
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
    class DispatchVisitor
    {
      public:
        template <typename Args>
        void operator()(const Args& args)
        {
            constexpr auto decode_method = DispatchTraits<Args>::kDecoderMethod;
            for (auto decoder : decoders_)
            {
                if (DecoderSupportsDispatch(*decoder, args))
                {
                    [[maybe_unused]] DecoderAllocGuard<DispatchTraits<Args>::kHasAllocGuard> alloc_guard{};
                    SetDecoderApiCallId(*decoder, args);
                    auto dispatch_call = [&decoder, decode_method](auto&&... expanded_args) {
                        (decoder->*decode_method)(std::forward<decltype(expanded_args)>(expanded_args)...);
                    };
                    std::apply(dispatch_call, args.GetTuple());
                }
            }
        }
        void operator()(const AnnotationArgs& annotation)
        {
            if (annotation_handler_)
            {
                auto annotation_call = [this](auto&&... expanded_args) {
                    annotation_handler_->ProcessAnnotation(std::forward<decltype(expanded_args)>(expanded_args)...);
                };
                std::apply(annotation_call, annotation.GetTuple());
            }
        }

        // Avoid unpacking the Arg from it's store in the Arg specific overloads
        template <typename Args>
        void operator()(const DispatchStore<Args>& store)
        {
            this->operator()(*store);
        }

        DispatchVisitor(const std::vector<ApiDecoder*>& decoders, AnnotationHandler* annotation_handler) :
            decoders_(decoders), annotation_handler_(annotation_handler)
        {}

      private:
        const std::vector<ApiDecoder*>& decoders_;
        AnnotationHandler*              annotation_handler_;
    };

    class ProcessVisitor
    {
      public:
        // NOTE: All overloads should set all state, as the caller is *reusing* the Visitor object across a number of
        //       std::visit calls

        // Frame boundary control
        void operator()(const FunctionCallArgs& function_call)
        {
            is_frame_delimiter = file_processor_.ProcessFrameDelimiter(function_call.call_id);
            success            = true;
        }

        void operator()(const MethodCallArgs& method_call)
        {
            is_frame_delimiter = file_processor_.ProcessFrameDelimiter(method_call.call_id);
            success            = true;
        }

        void operator()(const FrameEndMarkerArgs& end_frame)
        {
            // The block and marker type are implied by the Args type
            is_frame_delimiter = file_processor_.ProcessFrameDelimiter(end_frame);
            success            = true;
        }

        // I/O Control
        void operator()(const ExecuteBlocksFromFileArgs& execute_blocks)
        {
            // The block and marker type are implied by the Args type
            is_frame_delimiter = false;
            success            = file_processor_.ProcessExecuteBlocksFromFile(execute_blocks);
        }

        // State Marker control
        void operator()(const StateBeginMarkerArgs& state_begin)
        {
            // The block and marker type are implied by the Args type
            is_frame_delimiter = false;
            success            = true;
            file_processor_.ProcessStateBeginMarker(state_begin);
        }

        void operator()(const StateEndMarkerArgs& state_end)
        {
            // The block and marker type are implied by the Args type
            is_frame_delimiter = false;
            success            = true;
            file_processor_.ProcessStateEndMarker(state_end);
        }

        void operator()(const AnnotationArgs& annotation)
        {
            // The block and marker type are implied by the Command type
            is_frame_delimiter = false;
            success            = true;
            file_processor_.ProcessAnnotation(annotation);
        }

        template <typename Args>
        void operator()(const Args&)
        {
            // The default behavior for a Visit is a successful, non-frame-delimiter
            is_frame_delimiter = false;
            success            = true;
        }

        // Avoid unpacking the Arg from it's store in the Arg specific overloads
        template <typename Args>
        void operator()(const DispatchStore<Args>& store)
        {
            this->operator()(*store);
        }

        bool IsSuccess() const { return success; }
        bool IsFrameDelimiter() const { return is_frame_delimiter; }
        ProcessVisitor(FileProcessor& file_processor) : file_processor_(file_processor) {}

      private:
        bool           is_frame_delimiter = false;
        bool           success            = true;
        FileProcessor& file_processor_;
    };

    bool ProcessFileHeader();
    bool ProcessBlocks();

    // NOTE: These two can't be const as derived class updates state.
    virtual bool SkipBlockProcessing() { return false; } // No block skipping in base class

    bool IsFileValid() const
    {
        if (!file_stack_.empty())
        {
            return file_stack_.back().active_file->IsReady();
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
    std::vector<uint8_t>                uncompressed_buffer_;
    uint64_t                            block_limit_;
    bool                                pending_capture_uses_frame_markers_{ false };
    bool                                capture_uses_frame_markers_{ false };
    bool                                file_supports_frame_markers_{ false };
    uint64_t                            first_frame_;
    bool                                enable_print_block_info_{ false };
    int64_t                             block_index_from_{ 0 };
    int64_t                             block_index_to_{ 0 };
    bool                                loading_trimmed_capture_state_;

    std::string absolute_path_;
    format::FileHeader file_header_;

  protected:
    BufferPool        pool_;
    util::Compressor* compressor_;

    struct ActiveFileContext
    {
        ActiveFileContext(FileInputStreamPtr&& active_file_, bool execute_til_eof_ = false) :
            active_file(std::move(active_file_)), execute_till_eof(execute_til_eof_){};

        FileInputStreamPtr active_file;
        uint32_t    remaining_commands{ 0 };
        bool        execute_till_eof{ false };
    };

    std::deque<ActiveFileContext> file_stack_;

  private:
    ActiveFileContext& GetCurrentFile()
    {
        GFXRECON_ASSERT(file_stack_.size());
        return file_stack_.back();
    }

    struct InputStreamGetKey
    {
        const std::string& operator()(const FileInputStreamPtr& input_stream)
        {
            GFXRECON_ASSERT(input_stream);
            return input_stream->GetFilename();
        }
    };
    using ActiveStreamCache = util::ClockCache<FileInputStreamPtr, 3, std::string, InputStreamGetKey>;
    ActiveStreamCache stream_cache_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_H
