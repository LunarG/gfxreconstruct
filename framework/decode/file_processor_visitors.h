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
        if (annotation_handler_)
        {
            auto annotation_call = [this](auto&&... expanded_args) {
                annotation_handler_->ProcessAnnotation(std::forward<decltype(expanded_args)>(expanded_args)...);
            };
            std::apply(annotation_call, annotation->GetTuple());
        }
        return ProcessBlockState::kContinue;
    }

    // Replay frame/error/end control.
    //
    // During replay, this is in-band signaling to allow the dispatch loop to return before end of batch,
    // while still commuinicating the correct state and error information back to the caller.
    ProcessBlockState operator()(const ProcessBlocksResult* result)
    {
        if (result->state != ProcessBlockState::kContinue)
        {
            // kContinue denotes an "non-result" useful for in-band signaling, and wait control.
            SetReplayResult(*result);
        }
        return result->state;
    }

    DispatchVisitor(FileProcessor&                  file_processor,
                    const std::vector<ApiDecoder*>& decoders,
                    AnnotationHandler*              annotation_handler) :
        file_processor_(file_processor),
        decoders_(decoders), annotation_handler_(annotation_handler)
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
        for (auto decoder : decoders_)
        {
            if (DecoderSupportsDispatch(*decoder, *args))
            {
                [[maybe_unused]] DecoderAllocGuard<DispatchTraits<Args>::kHasAllocGuard> alloc_guard{};
                SetDecoderApiCallId(*decoder, *args);
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

    FileProcessor&                  file_processor_;
    const std::vector<ApiDecoder*>& decoders_;
    AnnotationHandler*              annotation_handler_;
    uint64_t                        block_index_{ 0 };
    ProcessBlocksResult             replay_result_{};
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
    constexpr static bool kUpdateDispatchState = true;
    bool                  ContinueBlockProcessing(uint64_t block_index)
    {
        return file_processor_.ContinueBlockProcessing<ContinueProcessingPolicy::CheckBoth>(block_index);
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
    PreloadProcessPolicy(FileProcessor& file_processor) : file_processor_(file_processor) {}
    constexpr static bool kUpdateDispatchState = false;
    bool                  ContinueBlockProcessing(uint64_t block_index)
    {
        // This is redundant when async processing is enabled, but outside of the
        // timing loop and thus irrelevant.
        return file_processor_.ContinueBlockProcessing<ContinueProcessingPolicy::BlockLimitOnly>(block_index);
    }
    ProcessBlockState Dispatch(uint64_t block_index, ParsedBlock& block) { return ProcessBlockState::kContinue; }

  private:
    FileProcessor& file_processor_;
};

GFXRECON_END_NAMESPACE(file_processor)
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_FILE_PROCESSOR_VISITORS_H
