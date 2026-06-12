/*
** Copyright (c) 2018-2026 LunarG, Inc.
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

#ifndef GFXRECON_DECODE_FILE_PROCESSOR_VISITORS_H
#define GFXRECON_DECODE_FILE_PROCESSOR_VISITORS_H

// Implementation header: include only from .cpp files that use DispatchVisitor or ProcessVisitor.
#include "decode/file_processor.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
GFXRECON_BEGIN_NAMESPACE(file_processor)

// Returns true if block_index is within block_limit, or if block_limit is 0 (no limit).
inline bool ContinueBlockLimit(uint64_t block_limit, uint64_t block_index)
{
    return (block_limit == 0) || (block_index <= block_limit);
}

// Free function: checks block limit and/or decoder completion.
// If block_limit > 0, block limit takes priority and decoder completion is never checked.
template <typename CheckPolicy>
inline bool ContinueBlockProcessing(uint64_t block_limit, const DispatchConfig& config, uint64_t block_index)
{
    // Skip invalid block indexes, used in in-band signaling blocks
    if (block_index == ParsedBlock::kInvalidIndex)
    {
        return true;
    }
    if (block_limit > 0)
    {
        if constexpr (CheckPolicy::kCheckBlockLimit)
        {
            return ContinueBlockLimit(block_limit, block_index);
        }
        return true;
    }
    else if constexpr (CheckPolicy::kCheckDecoders)
    {
        bool all_complete = true;
        for (auto decoder : config.decoders)
        {
            // NOTE: MUST NOT short-circuit -- IsComplete() calls may have side effects.
            all_complete &= decoder->IsComplete(block_index);
        }
        return !all_complete;
    }
    return true;
}

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
bool DecoderSupportsDispatch(ApiDecoder& decoder, const Args& args)
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
void SetDecoderApiCallId(ApiDecoder& decoder, const Args& args)
{
    if constexpr (DispatchTraits<Args>::kHasCallId)
    {
        decoder.SetCurrentApiCallId(args.call_id);
    }
}

class DispatchVisitor
{
  public:
    // No valid dispatch args, nothing to do. It is possible to modify in future to support passing down
    // raw block data to some raw block handler if needed
    ProcessBlockState operator()(const std::monostate&) { return ProcessBlockState::kContinue; };

    // Dispatch based on the Args traits.
    template <typename Args>
    ProcessBlockState operator()(const Args* args)
    {
        return DispatchArgs(args);
    }

    // State Marker control
    ProcessBlockState operator()(const StateBeginMarkerArgs* state_begin)
    {
        // The block and marker type are implied by the Args type
        file_processor_.ProcessStateBeginMarker(*state_begin);
        return DispatchArgs(state_begin);
    }

    ProcessBlockState operator()(const StateEndMarkerArgs* state_end)
    {
        // The block and marker type are implied by the Args type
        file_processor_.ProcessStateEndMarker(*state_end);
        return DispatchArgs(state_end);
    }

    ProcessBlockState operator()(const AnnotationArgs* annotation)
    {
        if (config_.annotation_handler)
        {
            auto annotation_call = [this](auto&&... expanded_args) {
                config_.annotation_handler->ProcessAnnotation(std::forward<decltype(expanded_args)>(expanded_args)...);
            };
            std::apply(annotation_call, annotation->GetTuple());
        }
        return ProcessBlockState::kContinue;
    }

    // In-band callback: fires the stored function on the dispatch thread.
    ProcessBlockState operator()(const CallbackArgs* callback_args)
    {
        callback_args->callback();
        return ProcessBlockState::kContinue;
    }

    // Replay frame/error/end control.
    //
    // During replay, this is in-band signaling to allow the dispatch loop to return before end of batch,
    // while still communicating the correct state and error information back to the caller.
    ProcessBlockState operator()(const ProcessBlocksResult* result)
    {
        if (result->state != ProcessBlockState::kContinue)
        {
            // kContinue denotes an "non-result" useful for in-band signaling, and wait control.
            SetReplayResult(*result);
        }
        return result->state;
    }

    DispatchVisitor(FileProcessor& file_processor, const FileProcessor::DispatchConfig& config) :
        file_processor_(file_processor), config_(config)
    {}

    void SetBlockIndex(uint64_t block_index) { block_index_ = block_index; }
    void ResetReplayResult() { replay_result_ = ProcessBlocksResult{}; }
    void SetReplayResult(const ProcessBlocksResult& result) { replay_result_ = result; }

    // Only report status based on the replay_result_, even if in the future we want to allow decoders
    // to set results.
    const ProcessBlocksResult& GetReplayResult() const noexcept { return replay_result_; }
    const ProcessBlockState    GetState() const noexcept { return replay_result_.state; }

  private:
    template <typename Args>
    ProcessBlockState DispatchArgs(const Args* args)
    {
        constexpr auto decode_method = DispatchTraits<Args>::kDecoderMethod;
        for (auto decoder : config_.decoders)
        {
            if (DecoderSupportsDispatch(*decoder, *args))
            {
                [[maybe_unused]] DecoderAllocGuard<DispatchTraits<Args>::kHasAllocGuard> alloc_guard{};
                SetDecoderApiCallId(*decoder, *args);
                GFXRECON_ASSERT(block_index_ != ParsedBlock::kInvalidIndex);
                decoder->SetCurrentBlockIndex(block_index_);
                auto dispatch_call = [&decoder, decode_method](auto&&... expanded_args) {
                    (decoder->*decode_method)(std::forward<decltype(expanded_args)>(expanded_args)...);
                };
                std::apply(dispatch_call, args->GetTuple());
            }
        }
        // NOTE: If future decoders can updata state, this should be updated to forward that information.
        return ProcessBlockState::kContinue;
    }

    FileProcessor&                       file_processor_;
    const FileProcessor::DispatchConfig& config_;
    uint64_t                             block_index_{ 0 };
    ProcessBlocksResult                  replay_result_{};
};

class ProcessVisitor
{
  public:
    // NOTE: All overloads should set all state, as the caller is *reusing* the Visitor object across a number of
    //       std::visit calls

    // Frame boundary control
    void operator()(const FunctionCallArgs* function_call)
    {
        is_frame_delimiter = file_processor_.ProcessFrameDelimiter(function_call->call_id);
        success            = true;
    }

    void operator()(const MethodCallArgs* method_call)
    {
        is_frame_delimiter = file_processor_.ProcessFrameDelimiter(method_call->call_id);
        success            = true;
    }

    void operator()(const FrameEndMarkerArgs* end_frame)
    {
        // The block and marker type are implied by the Args type
        is_frame_delimiter = file_processor_.ProcessFrameDelimiter(*end_frame);
        success            = true;
    }

    // I/O Control
    void operator()(const ExecuteBlocksFromFileArgs* execute_blocks)
    {
        // The block and marker type are implied by the Args type
        is_frame_delimiter = false;
        success            = file_processor_.ProcessExecuteBlocksFromFile(*execute_blocks);
    }

    void operator()(const StateEndMarkerArgs* state_end)
    {
        // The block and marker type are implied by the Args type
        is_frame_delimiter = false;
        success            = true;
        file_processor_.ProcessStateEndMarkerFrameState(*state_end);
    }

    void operator()(const AnnotationArgs* annotation)
    {
        // The block and marker type are implied by the Command type
        is_frame_delimiter = false;
        success            = true;
        file_processor_.ProcessAnnotation(*annotation);
    }

    void operator()(const std::monostate&) { Reset(); }

    template <typename Args>
    void operator()(const Args*)
    {
        Reset();
    }

    bool IsSuccess() const { return success; }
    bool IsFrameDelimiter() const { return is_frame_delimiter; }
    ProcessVisitor(FileProcessor& file_processor) : file_processor_(file_processor) {}
    void Reset()
    {
        is_frame_delimiter = false;
        success            = true;
    }

  private:
    bool           is_frame_delimiter = false;
    bool           success            = true;
    FileProcessor& file_processor_;
};

class SynchronousProcessPolicy
{
  public:
    SynchronousProcessPolicy(FileProcessor& file_processor, DispatchVisitor& dispatch_visitor) :
        file_processor_(file_processor), dispatch_visitor_(dispatch_visitor)
    {}
    bool ContinueBlockProcessing(uint64_t block_index)
    {
        // Various in-band signaling blocks using invalid index, so ignore them.
        if (block_index != ParsedBlock::kInvalidIndex)
        {
            file_processor_.dispatch_block_index_ = block_index;
            return file_processor::ContinueBlockProcessing<ContinueProcessingPolicy::CheckBoth>(
                file_processor_.block_limit_, file_processor_.config_, block_index);
        }
        return true;
    }
    ProcessBlockState Dispatch(uint64_t block_index, ParsedBlock& block)
    {
        dispatch_visitor_.SetBlockIndex(block_index);
        return std::visit(dispatch_visitor_, block.GetArgs());
    }

  private:
    FileProcessor&   file_processor_;
    DispatchVisitor& dispatch_visitor_;
};

class PreloadProcessPolicy
{
  public:
    PreloadProcessPolicy(uint64_t block_limit) : block_limit_(block_limit) {}
    bool ContinueBlockProcessing(uint64_t block_index)
    {
        return file_processor::ContinueBlockLimit(block_limit_, block_index);
    }
    ProcessBlockState Dispatch(uint64_t block_index, ParsedBlock& block) { return ProcessBlockState::kContinue; }

  private:
    uint64_t block_limit_;
};

GFXRECON_END_NAMESPACE(file_processor)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_VISITORS_H
